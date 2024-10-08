%{
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "expression_tree.h"
#include "symbol_table.h"

#include "sequence.h"
extern struct block* allot_block();

struct symbol_table;
extern int yylex();
void yyerror(char*);
extern char* yytext;
extern FILE* yyin;
int lineno = 1;
char error_string[100];

struct block* root = NULL;
struct else_if_helper{
	struct if_statement_node* else_if_begin;
	struct if_statement_node* else_if_end;
};

int nested_for_count = 0;

%}

%union{
	int int_value;	
	float float_value;								
	char* name;									
	struct block* block_ptr;
	struct statement_node* one_statement;		
	struct expression_node* expr;
	struct else_if_helper* aux;
	enum datatype* d_type;
	struct indexes* indexing;
}

%type <indexing> more_indexes;
%token 	<name> ID
%token 	<int_value> INT_NUMBER
%token <float_value> FLOAT_NUMBER;
%type  	<expr> expression
%type 	<expr> l_value;

%type  	<block_ptr> body
%type  	<block_ptr> decl_types
%type  	<block_ptr> declarations
%type  	<block_ptr> declaration_block
%type 	<block_ptr> source_program;
%type <one_statement> array_production;
%type 	<one_statement> if_statement;
%type 	<aux> else_ifs;

%type 	<block_ptr> print_values;

%type 	<one_statement> for_production;
%type <one_statement> while_production;

%type <d_type> DATATYPE;

%start program

%token INT
%token FLOAT
%token BEGIN_DECL END_DECL
%token PROGRAM_BEGIN
%token PROGRAM_END
%token TERMINATOR
%token WRITE
%token IF
%token ELSE
%token FOR
%token WHILE
%token BREAK
%token CONTINUE
%token PLUS_PLUS
%token MINUS_MINUS

/* operators */
%token GREATER_THAN GREATER_THAN_OR_EQUAL_TO LESS_THAN LESS_THAN_OR_EQUAL_TO
/* Binary operator (IS_EQUAL): Isequal (==) 	*/
/* Binary operator (IS_NOT_EQUAL): Isnotequal (!=) 	*/
%token IS_EQUAL IS_NOT_EQUAL

/* operator precedence and associativity (same as C) */
%right '='
%left IS_EQUAL IS_NOT_EQUAL
%left GREATER_THAN GREATER_THAN_OR_EQUAL_TO LESS_THAN LESS_THAN_OR_EQUAL_TO
%left '+' '-'
%left '*' '/' '%'
%left UMINUS PRE_PLUS_PLUS PRE_MINUS_MINUS
%left ACCESS POST_PLUS_PLUS POST_MINUS_MINUS
%left PAREN 

%%


program: 		declaration_block					{
														root = $1;
													}	
|				declaration_block source_program	{
														/* check for NULLS */
														if($1 == NULL) root = $2;
														else if($2 == NULL) root = $1;
														else{
															$1->block_end->next = $2->block_start;
															$2->block_start->prev = $1->block_end;
															$1->block_end = $2->block_end;
															root = $1;
														}
													}
| 				source_program						{
														root = $1;
													}
;

declaration_block: 		BEGIN_DECL declarations END_DECL		{
																	$$ = $2;
																}
| 						BEGIN_DECL END_DECL						{
																	$$ = NULL;
																}
;

declarations: 			DATATYPE decl_types TERMINATOR					{ 	$$ = $2; 
																			struct statement_node* trav = $$->block_start;
																			if(*$1 == INT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = INT_datatype;
																					trav = trav->next;
																				}
																			}else if(*$1 == FLOAT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = FLOAT_datatype;
																					trav = trav->next;
																				}
																			}
																		}
|						declarations DATATYPE decl_types TERMINATOR  	{ 
																			if($1 == NULL){
																				$$ = $3;
																			}else{
																				$1->block_end->next = $3->block_start;
																				$3->block_start->prev = $1->block_end;
																				$1->block_end = $3->block_end;
																				$$ = $1;
																			}
																			struct statement_node* trav = $3->block_start;
																			if(*$2 == INT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = INT_datatype;
																					trav = trav->next;
																				}
																			}else if(*$2 == FLOAT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = FLOAT_datatype;
																					trav = trav->next;
																				}
																			}
																		}
| 						TERMINATOR										{ $$ = NULL; }
|						declarations TERMINATOR							{ $$ = $1;	}
;

decl_types:		ID									{
														$$ = allot_block();
														$$->block_start = allot_statement(DECLARATION, VARIABLE, $1);
														$$->block_end = $$->block_start;
													}
	|		decl_types ',' ID						{
														$1->block_end->next = allot_statement(DECLARATION, VARIABLE, $3);
														$1->block_end->next->prev = $1->block_end->next;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													}
|			array_production						{
														$$ = allot_block();
														$$->block_start = $1;
														$$->block_end = $$->block_start;
													}	
|			decl_types array_production				{
														$1->block_end->next = $2;
														$1->block_end->next->prev = $1->block_end->next;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													}
;

array_production:	ID more_indexes					{
														$$ = allot_statement(DECLARATION, ARRAY, $1, $2);
														// name, indexes
													}
;

DATATYPE: 		INT					{ 
	$$ = (enum datatype*)malloc(sizeof(enum datatype));
	*$$ = INT_datatype; 

}
|				FLOAT				{ 
	$$ = (enum datatype*)malloc(sizeof(enum datatype));
	*$$ = FLOAT_datatype; }
;

source_program : PROGRAM_BEGIN body PROGRAM_END	{$$ = $2;}
|				 PROGRAM_BEGIN  PROGRAM_END		{$$ = NULL;}
;

body: 		BREAK TERMINATOR					{	
													$$ = allot_block();
													$$->block_start = allot_statement(BREAK_STATEMENT);
													$$->block_end = $$->block_start;
												}
| 			body BREAK TERMINATOR				{	
													if($1 == NULL){
														$$ = allot_block();
														$$->block_start = allot_statement(BREAK_STATEMENT);;
														$$->block_end = $$->block_start;
													}else{
														$1->block_end->next = allot_statement(BREAK_STATEMENT);
														$1->block_end->next->prev = $1->block_end;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													
													}
												}
|			CONTINUE TERMINATOR					{	
													$$ = allot_block();
													$$->block_start = allot_statement(CONTINUE_STATEMENT);
													$$->block_end = $$->block_start;
												}
| 			body CONTINUE TERMINATOR			{	
													if($1 == NULL){
														$$ = allot_block();
														$$->block_start = allot_statement(CONTINUE_STATEMENT);;
														$$->block_end = $$->block_start;
													}else{
														$1->block_end->next = allot_statement(CONTINUE_STATEMENT);
														$1->block_end->next->prev = $1->block_end;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													}
												}
|			TERMINATOR							{	$$ = NULL; 	}
|			body TERMINATOR 					{	$$ = $1;	}
|			expression TERMINATOR				{   
													$$ = allot_block();
													$$->block_start = allot_statement(EXPRESSION, $1);
													$$->block_end = $$->block_start;
												}
| 			body expression TERMINATOR			{  	
													if($1 == NULL){
														$$ = allot_block();
														$$->block_start = allot_statement(EXPRESSION, $2);
														$$->block_end = $$->block_start;
													}else{
														$1->block_end->next = allot_statement(EXPRESSION, $2);
														$1->block_end->next->prev = $1->block_end;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													}
												}
| 			WRITE '(' print_values ')' TERMINATOR						{	
																			$$ = $3;
																		}
|			body WRITE '(' print_values ')' TERMINATOR					{  			
																			if($1 == NULL){
																				$$ = $4;
																			}else{
																				$1->block_end->next = $4->block_start;
																				$1->block_end->next->prev = $1->block_end;
																				$1->block_end = $4->block_end;
																				$$ = $1;
																			}
																		}
|			if_statement												{	
																			$$ = allot_block();
																			$$->block_start = $1;
																			$$->block_end = $1;
																		}
| 			body if_statement 											{ 	
																			if($1 == NULL){
																				$$ = allot_block();
																				$$->block_start = $2;
																				$$->block_end = $2;
																			}else{
																				$1->block_end->next = $2;
																				$2->prev = $1->block_end;
																				$1->block_end = $2;
																				$$ = $1;
																			}
																		}
|			for_production												{		
																			$$ = allot_block();
																			$$->block_start = $1;
																			$$->block_end = $1;
																		}
| 			body for_production											{ 	
																			if($1 == NULL){
																				$$ = allot_block();
																				$$->block_start = $2;
																				$$->block_end = $2;
																			}else{
																				$1->block_end->next = $2;
																				$2->prev = $1->block_end;
																				$1->block_end = $2;
																				$$ = $1;
																			}
																		}
|			while_production												{
																			$$ = allot_block();
																			$$->block_start = $1;
																			$$->block_end = $1;
																		}
| 			body while_production 										{
																			if($1 == NULL){
																				$$ = allot_block();
																				$$->block_start = $2;
																				$$->block_end = $2;
																			}else{
																				$1->block_end->next = $2;
																				$2->prev = $1->block_end;
																				$1->block_end = $2;
																				$$ = $1;
																			}
																		}
;


print_values: 		print_values ',' expression					{	
																	$1->block_end->next = allot_statement(PRINT_STATEMENT, $3);
																	$1->block_end->next->prev = $1->block_end;
																	$1->block_end = $1->block_end->next;
																	$$ = $1;
																}
|					expression									{	 	
																	$$ = allot_block();
																	$$->block_start = allot_statement(PRINT_STATEMENT, $1);
																	$$->block_end = $$->block_start;
																}
;



if_statement : 		IF '(' expression ')' '{' body '}' 								{	$$ = allot_statement(IF_STATEMENT, $6, $3); }
|					IF '(' expression ')' '{'  '}' 									{	$$ = allot_statement(IF_STATEMENT, NULL, $3); }
|					IF '(' expression ')' '{' body '}' ELSE '{' body '}'			{	
																						$$ = allot_statement(IF_STATEMENT, $6, $3);
																						$$->if_node->false_node = allot_if_statement_node(ELSE_TYPE, $10);
																					}
|					IF '(' expression ')' '{' body '}' ELSE '{'  '}'				{	
																						$$ = allot_statement(IF_STATEMENT, $6, $3);
																						$$->if_node->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
|					IF '(' expression ')' '{'  '}' ELSE '{' body '}'				{	
																						$$ = allot_statement(IF_STATEMENT, NULL, $3);
																						$$->if_node->false_node = allot_if_statement_node(ELSE_TYPE, $9);
																					}
|					IF '(' expression ')' '{'  '}' ELSE '{'  '}'					{	
																						$$ = allot_statement(IF_STATEMENT, NULL, $3);
																						$$->if_node->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
|					IF '(' expression ')' '{' body '}' else_ifs ELSE '{' body '}'	{
																						$$ = allot_statement(IF_STATEMENT, $6, $3);
																						$$->if_node->false_node = $8->else_if_begin;
																						$8->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, $11);
																					}
|					IF '(' expression ')' '{'  '}' else_ifs ELSE '{' body '}'		{
																						$$ = allot_statement(IF_STATEMENT, NULL, $3);
																						$$->if_node->false_node = $7->else_if_begin;
																						$7->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, $10);
																					}
|					IF '(' expression ')' '{' body '}' else_ifs ELSE '{'  '}'		{
																						$$ = allot_statement(IF_STATEMENT, $6, $3);
																						$$->if_node->false_node = $8->else_if_begin;
																						$8->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
|					IF '(' expression ')' '{' '}' else_ifs ELSE '{'  '}'			{
																						$$ = allot_statement(IF_STATEMENT, NULL, $3);
																						$$->if_node->false_node = $7->else_if_begin;
																						$7->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
|					IF '(' expression ')' '{' body '}' else_ifs 					{
																						$$ = allot_statement(IF_STATEMENT, $6, $3);
																						$$->if_node->false_node = $8->else_if_begin;
																					}	
|					IF '(' expression ')' '{'  '}' else_ifs 						{
																						$$ = allot_statement(IF_STATEMENT, NULL, $3);
																						$$->if_node->false_node = $7->else_if_begin;
																					}	
;

else_ifs : 			ELSE IF '(' expression ')' '{' body '}'							{
																						$$ = (struct else_if_helper*)malloc(sizeof(struct else_if_helper));
																						$$->else_if_begin = allot_if_statement_node(ELSE_IF_TYPE, $7, $4);
																						$$->else_if_end = $$->else_if_begin;
																					}
|					ELSE IF '(' expression ')' '{'  '}'								{
																						$$ = (struct else_if_helper*)malloc(sizeof(struct else_if_helper));
																						$$->else_if_begin = allot_if_statement_node(ELSE_IF_TYPE, NULL, $4);
																						$$->else_if_end = $$->else_if_begin;
																					}
|			   		else_ifs ELSE IF '(' expression ')' '{' body '}'				{	
																						$1->else_if_end->false_node = allot_if_statement_node(ELSE_IF_TYPE, $8, $5);
																						$1->else_if_end = $1->else_if_end->false_node;
																						$$ = $1;	
																					}	
|			   		else_ifs ELSE IF '(' expression ')' '{'  '}'					{	
																						$1->else_if_end->false_node = allot_if_statement_node(ELSE_IF_TYPE, NULL, $5);
																						$1->else_if_end = $1->else_if_end->false_node;
																						$$ = $1;	
																					}	
;

expression : 	'(' expression ')'	%prec PAREN					{ 	$$ = $2; 					}
| 				'-' expression		%prec UMINUS				{	
																	$$ = allot_expression_node(UNARY_MINUS, $2);
																	/* storing expression as right child */
																}
|				l_value '=' expression							{ $$ = allot_expression_node(ASSIGN, $1, $3); }
|				l_value											{ $$ = $1; }
| 				INT_NUMBER										{					
																	$$ = allot_expression_node(NUM, $1);
																}
| 				FLOAT_NUMBER									{					
																	$$ = allot_expression_node(FLOAT_NUM, $1);
																}
|				expression '+' expression 						{	$$ = allot_expression_node(PLUS, $1, $3); 			}
|				expression '-' expression 						{	$$ = allot_expression_node(MINUS, $1, $3);			}
|				expression '*' expression 						{	$$ = allot_expression_node(MUL, $1, $3);			}
|				expression '/' expression 						{	$$ = allot_expression_node(DIV, $1, $3);			}
|				expression '%' expression						{	$$ = allot_expression_node(MOD, $1, $3);			}
|				expression GREATER_THAN expression 				{	$$ = allot_expression_node(GT, $1, $3);				}
|				expression GREATER_THAN_OR_EQUAL_TO expression 	{	$$ = allot_expression_node(GTEQ, $1, $3);			}
|				expression LESS_THAN expression 				{	$$ = allot_expression_node(LT, $1, $3);				}
|				expression LESS_THAN_OR_EQUAL_TO expression 	{	$$ = allot_expression_node(LTEQ, $1, $3);			}
|				expression IS_EQUAL expression 					{	$$ = allot_expression_node(EQEQ, $1, $3);			}
|				expression IS_NOT_EQUAL expression 				{	$$ = allot_expression_node(NTEQ, $1, $3);			}
| 				PLUS_PLUS l_value 	%prec PRE_PLUS_PLUS			{	$$ = allot_expression_node(PRE_INCREMENT, $2); 	}
|				MINUS_MINUS l_value 	%prec PRE_MINUS_MINUS	{	$$ = allot_expression_node(PRE_DECREMENT, $2); 	}
|				l_value PLUS_PLUS 	%prec POST_PLUS_PLUS		{	$$ = allot_expression_node(POST_INCREMENT, $1); }
|				l_value MINUS_MINUS %prec POST_MINUS_MINUS		{	$$ = allot_expression_node(POST_DECREMENT, $1); }
;

l_value:	ID						{ $$ = allot_expression_node(VAR, lookup($1, VARIABLE));			 }
|			ID more_indexes			{ $$ = allot_expression_node(ARRAY_LOC, lookup($1, ARRAY, $2), $2);  }
;


more_indexes: 		'[' expression ']'					{ 
															$$ = (struct indexes*)malloc(sizeof(struct indexes));
															$$->index = $2;
															$$->next = NULL;
														}
|					'[' expression ']' more_indexes 	{
															$$ = (struct indexes*)malloc(sizeof(struct indexes));
															$$->index = $2;
															$$->next = $4;
														}
;


while_production: WHILE '(' expression ')' '{' '}'						{ $$ = allot_statement(WHILE_STATEMENT, $3, NULL); }
|				 WHILE '(' expression ')' '{' body '}'					{ $$ = allot_statement(WHILE_STATEMENT, $3, $6); }
;


for_production :	FOR '(' expression 	TERMINATOR 	expression 	TERMINATOR expression 	')' '{' body	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, $5, $7, $10); }
|					FOR '(' 			TERMINATOR 	expression 	TERMINATOR expression 	')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, $4, $6, $9); }
|					FOR '(' expression 	TERMINATOR  			TERMINATOR expression 	')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, NULL, $6, $9); }
|					FOR '(' expression 	TERMINATOR 	expression 	TERMINATOR 				')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, $5, NULL, $9); }
|					FOR '(' expression 	TERMINATOR 	expression 	TERMINATOR expression 	')' '{' 		'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, $5, $7, NULL); }
|					FOR '(' 			TERMINATOR  			TERMINATOR expression 	')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, NULL, $5, $8); }
|					FOR '(' 			TERMINATOR  expression	TERMINATOR 			 	')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, $4, NULL, $8); }
|					FOR '(' 			TERMINATOR  expression	TERMINATOR expression 	')' '{' 	 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, $4, $6, NULL); }
|					FOR '(' expression 	TERMINATOR 			 	TERMINATOR  			')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, NULL, NULL, $8); }
|					FOR '(' expression 	TERMINATOR 			 	TERMINATOR expression	')' '{' 	 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, NULL, $6, NULL); }
|					FOR '(' expression 	TERMINATOR  expression 	TERMINATOR  			')' '{'  	 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, $5, NULL, NULL); }
|					FOR '(' expression 	TERMINATOR 	 			TERMINATOR  			')' '{' 		'}'	{ 	$$ = allot_statement(FOR_STATEMENT, $3, NULL, NULL, NULL); }
|					FOR '(' 			TERMINATOR	expression 	TERMINATOR  			')' '{' 		'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, $4, NULL, NULL); }
|					FOR '(' 			TERMINATOR  			TERMINATOR expression 	')' '{' 		'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, NULL, $5, NULL); }
|					FOR '(' 			TERMINATOR  			TERMINATOR  			')' '{' body 	'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, NULL, NULL, $7); }
|					FOR '(' 			TERMINATOR  			TERMINATOR 			 	')' '{' 		'}'	{ 	$$ = allot_statement(FOR_STATEMENT, NULL, NULL, NULL, NULL); }
;

%%

int main(int argc, char* argv[]){
	if(argc >= 2){
		FILE* fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("File did not open\n");
			return 1; 	// failure
		}
		yyin = fp;
	}
	yyparse();
	printSymbolTable();
	// printSequence();
	char *tabs = malloc(sizeof(char)); 
	printf("\n--------Syntax tree--------\n");
	print_root(root, tabs);
	return 0;
}	

int yywrap(){
	return 1;
}

void yyerror(char* msg){
//	printf("yytext = %s, Line number = %d, %s\n", yytext, lineno, msg);
	printf("Line number = %d, %s\n", lineno, msg);
	exit(1); // failure
}

// if if else ambigiuity we need to see 
// initializations are not allowed in declaration_block
// how to handle the issue of a body being emty

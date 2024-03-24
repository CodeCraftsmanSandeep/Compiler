%{
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

enum class expression_node_type{
	VAR,
	ARRAY_LOC,
	NUM,
	UNARY_MINUS,
	PLUS,  /* add operator */
	MINUS,
	MUL,
	DIV,
	GT,
	LT,
	GTEQ,
	LTEQ,
	EQEQ, 	/* '==' is equal to  */
	NTEQ,  	/* !=  is not equal to */
	ASSIGN	 	/* '=' assignment */
};

#include "symbol_table.hpp"
#include "expression_tree.hpp"

#include "sequence.hpp"
extern struct block* allot_block();

struct symbol_table;
extern int yylex();
void yyerror(char*);
extern char* yytext;
extern FILE* yyin;
int lineno = 1;
char error_string[100];

// extern enum class statement_type;
// extern enum 	 declaration_type;	

// extern struct block;

struct block* root = allot_block();

%}


%union{
	int int_value;								
	char* name;									
	struct block* block_ptr;
	struct statement_node* one_statement;
	enum class expression_node_type expr_type;			
	struct expression_node* expr;
}


%token <name> ID
%token <int_value> INT_NUMBER
%type  <expr> expression

%type  	<block_ptr> body
%type  	<block_ptr> decl_types
%type  	<block_ptr> declarations
%type  	<block_ptr> declaration_block
%type 	<one_statement> if_statement;
%type 	<one_statement> print_values;
%type 	<one_statement> for_production;


%type <expr_type> OP;
%start program

%token INT
%token BEGIN_DECL END_DECL
%token BEGIN_BODY
%token END_BODY
%token TERMINATOR
%token PRINT_STATEMENT
%token IF
%token ELSE
%token FOR
%token BREAK
%token CONTINUE


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
%left '*' '/'
%nonassoc UMINUS

// need to handle precedence of parenthesis operator, and '[' ']'. How to ??
%%


program: 		declaration_block				{
													/* check for NULLS ?? */
													if($1 != NULL){
														root->block_start = $1->block_start; 
														root->block_end = $1->block_end;
													}
												}	
// |				declaration_block BEGIN body END			{
// 													/* join declaration_block and body_block */
// 													$1->block_end->next = $3->block_start;
// 													$3->block_start->prev = $1->block_end;

// 													root->block_start = $1->block_start;
// 													root->block_end = $3->block_end;
// 												}
// | 				BEGIN body	END						{
// 													root->block_start = $2->block_start; 
// 													root->block_end = $2->block_end;
// 												}
;

declaration_block: 		BEGIN_DECL declarations END_DECL		{
																	$$ = $2;
																}
| 						BEGIN_DECL END_DECL						{
																	$$ = NULL;
																}
;

declarations: 			DATATYPE decl_types TERMINATOR					{ 	$$ = $2; }
|						declarations DATATYPE decl_types TERMINATOR  	{ 
																			if($1 == NULL){
																				$$ = $3;
																			}else{
																				$1->block_end->next = $3->block_start;
																				$3->block_start->prev = $1->block_end;
																				$1->block_end = $3->block_end;
																				$$ = $1;
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
														$1->block_end->next = $1->block_end->next->next;
														$$ = $1;
													}
	|		ID '[' INT_NUMBER ']' 					{
														$$ = allot_block();
															$$->block_start = allot_statement(DECLARATION, ARRAY, $1, $3);
														$$->block_end = $$->block_start;
													}
	| 		decl_types ',' ID '[' INT_NUMBER ']'	{
														$1->block_end->next = allot_statement(DECLARATION, ARRAY, $3, $5);
														$1->block_end->next->prev = $1->block_end->next;
														$1->block_end = $1->block_end->next;
														$$ = $1;
													}
;

DATATYPE: 		INT
;

body: 		expression TERMINATOR				{   
													$$ = allot_block();
													$$->block_start = allot_statement(EXPRESSION, $1);
												}
| 			body expression TERMINATOR			{  					
													$1->block_end->next = allot_statement(EXPRESSION, $2);
													$1->block_end->next->prev = $1->block_end;
													$1->block_end = $1->block_end->next;
													$$ = $1;
												}
|			if_statement						{	
													$$ = allot_block();
													$$->block_start = $1;
													$$->block_end = $1;
												}
| 			body if_statement 					{ 	
													$1->block_end->next = $2;
													$2->prev = $1->block_end;
													$1->block_end = $2;
													$$ = $1;
												}
|			for_production										{ 		}
| 			body for_production									{ 		}
| 			PRINT_STATEMENT '(' print_values ')' TERMINATOR				{	
																			$$ = allot_block();
																			$$->block_start = $3;
																			$$->block_end = $3;
																		}
																		
|			body PRINT_STATEMENT '(' print_values ')' TERMINATOR		{  			
																			$1->block_end->next = $4;
																			$1->block_end->next->prev = $1->block_end;
																			$1->block_end = $1->block_end->next;
																			$$ = $1;
																		}
|			BREAK TERMINATOR					{	
													$$ = allot_block;
													$$->block_start = allot_statement(BREAK_STATEMENT);
													$$->block_end = $$->block_start;
												}
| 			body BREAK TERMINATOR				{	
													$1->block_end->next = allot_statement(BREAK_STATEMENT);
													$1->block_end->next->prev = $1->block_end;
													$1->block_end = $1->block_end->next;
													$$ = $1;
												}
|			CONTINUE TERMINATOR					{	
													$$ = allot_block;
													$$->block_start = allot_statement(CONTINUE_STATEMENT);
													$$->block_end = $$->block_start;
												}
| 			body CONTINUE TERMINATOR			{	
													$1->block_end->next = allot_statement(CONTINUE_STATEMENT);
													$1->block_end->next->prev = $1->block_end;
													$1->block_end = $1->block_end->next;
													$$ = $1;
												}
|			body TERMINATOR 					{	$$ = $1;	}
;

for_production :	FOR '(' expression TERMINATOR expression TERMINATOR expression ')' '{' body '}'	{ 			
													$$ = allot_statement(FOR_STATEMENT, $3, $5, $7, $10);
												}
;

expression : 	'(' expression ')'						{ 	$$ = $2; 					}
| 				'-' expression	%prec UMINUS			{	
															$$ = 
															xpression_node(UNARY_MINUS);
															$$->right = $2; /* storing expression as right child */
														}
| 				expression OP expression				{	
															$$ = allot_expression_node($2);
															$$->left = $1;
															$$->right = $3;
														}
| 				ID '=' expression						{
															$$ = allot_expression_node(ASSIGN);
															$$->left = allot_expression_node(VAR, $1);
															$$->right = $3;
														}
|				ID '[' expression ']' '=' expression 	{
															$$ = allot_expression_node(expression_node_type::ASSIGN);
															$$->left = allot_expression_node(expression_node_type::ARRAY_LOC, $1);
															$$->left->right = $3; /* index expression */
															$$->right = $6;
														}
|				ID '[' expression ']'					{
															$$ = allot_expression_node(expression_node_type::ARRAY_LOC, $1);
															$$->right = $3; /* storing index in right node */
														}
| 				ID										{ 
															$$ = allot_expression_node(expression_node_type::VAR, $1);
														}
| 				INT_NUMBER								{					
															$$ = allot_expression_node(expression_node_type::NUM, $1);
														}			
;

OP : 	'+'								{ 	$$ = expression_node_type::PLUS;	 	}
|	 	'-'								{ 	$$ = expression_node_type::MINUS;	 	}
|		'*'								{ 	$$ = expression_node_type::MUL;  		}
|  	    '/'								{ 	$$ = expression_node_type::DIV;			}
|		GREATER_THAN					{	$$ = expression_node_type::GT;			}
|	 	GREATER_THAN_OR_EQUAL_TO		{	$$ = expression_node_type::GTEQ;		}
|		LESS_THAN						{	$$ = expression_node_type::LT;			}
| 		LESS_THAN_OR_EQUAL_TO			{	$$ = expression_node_type::LTEQ;		}
| 		IS_EQUAL						{	$$ = expression_node_type::EQEQ;		}
| 		IS_NOT_EQUAL					{	$$ = expression_node_type::NOTEQ;		}
;

if_statement : 		IF '(' expression ')' '{' body '}' 							{	$$ = allot_statement(statement_type::IF_STATEMENT, $3, $6);	}
|					IF '(' expression ')' '{' body '}' ELSE '{' body '}'		{	
																					$$ = allot_statement(statement_type::IF_STATEMENT, if_type::IF, $3, $6);
																					$$->if_node->sibling = if_type::ELSE;
																					$$->if_node->else_node = (if_statement*)malloc(sizeof(if_statement));
																					$$->if_node->else_node->body = $10;
																					$$->if_node->else_node->type = if_type::ELSE;
																					$$->if_node->else_node->sibling = if_type::NO_SIBLING;
																				}
|					IF '(' expression ')' '{' body '}' else_ifs ELSE '{' body '}'			
																				{
																					// $$ = allot_statement(statement_type::IF_STATEMENT, if_type::IF, $3, $6);
																					// $$->if_node->sibling = if_type::ELSE_IF;
																					
																					// = (if_statement*)malloc(sizeof(if_statement));
																					// $$->if_node->else_if_node->body = $10;
																					// $$->if_node->else_node->type = if_type::ELSE;
																					// $$->if_node->else_node->sibling = if_type::NO_SIBLING;
																				}
|					IF '(' expression ')' '{' body '}' else_ifs 				{
																				}	
;

else_ifs : 			ELSE IF '(' expression ')' '{' body '}'						{
																					// $$ = (if_statement*)malloc(sizeof(if_statement));
																					// $$->sibling = if_type::NO_SIBLING;
																				}
|			   		else_ifs ELSE IF '(' expression ')' '{' body '}'			{	}
;

print_values: 		print_values ',' expression					{	
																	$1->next = allot_statement(statement_type::EXPRESSION, $3);
																	$1->next->prev = $1->next;
																	$$ = $1;
																}
|					expression									{	 	
																	$$ = allot_statement(statement_type::EXPRESSION, $1);
																}
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
	// printSymbolTable();
	// printSequence();
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
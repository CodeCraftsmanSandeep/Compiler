%{
#include <stdio.h>
#include <stdbool.h>
#include "symbol_table.h"
#include "syntax_tree.h"

struct symbol_table;
extern int yylex();
void yyerror(char*);
extern char* yytext;
extern FILE* yyin;
int lineno = 1;
bool DECLARATION_PHASE = false;
char error_string[100];

%}


%union{
	int int_value;				/* int_value */
	struct symbol_table* symp;		/* symbol table pointer */
	struct syntax_tree_node* syntax_tree;	/* syntax tree pointer */
	struct node* seq;			/* sequence pointer */
}


%token <symp> ID
%token INT
%token <int_value> INT_NUMBER
%type  <syntax_tree> expression
%type  <seq> values
%token BEGIN_DECL END_DECL
%token TERMINATOR
%token PRINT_STATEMENT

%token DOUBLE DOUBLE_NUMBER
%token RETURN
%token IF ELSE
%token INCLUDE
%token ISEQUAL
%token ISNOTEQUAL
%token PLUSPLUS
%token MINUSMINUS


%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%%

program: 		declaration_block body
	| 		body
;

declaration_block: 	begin declarations end
	| 		begin end
;

begin: 			BEGIN_DECL 					{	DECLARATION_PHASE = true;
										char output[100];
										sprintf(output, "Begin of declaration (Line %d)", lineno);
										put_in_sequence(output);
									}
;

end:			END_DECL					{	DECLARATION_PHASE = false;
										char output[100];
										sprintf(output, "End of declaration (Line %d)", lineno);
										put_in_sequence(output);
									}
;


declarations: 		declaration TERMINATOR				{ 					}
	|		declarations declaration TERMINATOR  		{					}
	| 		TERMINATOR
;

declaration: 	        DATATYPE remaining
;

remaining:		ID						{
										char output[200];
										sprintf(output, "\tLine %d : Declaring %s", lineno, $1->name);
										put_in_sequence(output);
									}
	|		remaining ',' ID				{
										char output[200];
										sprintf(output, "\tLine %d : Declaring %s", lineno, $3->name);
										put_in_sequence(output);
									}
;

DATATYPE: 		INT
;
	
body: 			assignment TERMINATOR				{  							}
	| 		body assignment TERMINATOR			{  							}
	| 		expression TERMINATOR				{   					
										char output[100];
										sprintf(output, "Expression (Line %d)", lineno);
										put_in_sequence(output);
										
										seq_node_tail->root = $1;
									}
	| 		body expression TERMINATOR			{  					
										char output[100];
										sprintf(output, "Expression (Line %d)", lineno);
										put_in_sequence(output);
										
										seq_node_tail->root = $2;									
									}	
	| 		print_statement TERMINATOR			{ 							}
	|		body print_statement TERMINATOR			{  							}
	|		body TERMINATOR 				{							}		
;

assignment:		ID '=' expression				{	
										$1->isInitialized = true;
										$1->value = $3->value;
										char output[100];
										sprintf(output, "Assignment(Line %d)", lineno);
										put_in_sequence(output);
										
										struct syntax_tree_node* left_node = allot_syntax_tree_node($1->name, $1->value);
										struct syntax_tree_node* parent = allot_syntax_tree_node("ASSIGN", $1->value);
										parent->left = left_node;
										parent->right = $3;
										
										seq_node_tail->root = parent;
									}
;

expression : 		expression '+' expression			{ 	
										$$ = allot_syntax_tree_node("ADD", $1->value + $3->value);
										$$->left = $1;
										$$->right = $3;								
									}
	|		expression '-' expression			{
										$$ = allot_syntax_tree_node("SUB", $1->value - $3->value);
										$$->left = $1;
										$$->right = $3;
									}
	|		expression '*' expression			{ 	
										$$ = allot_syntax_tree_node("MUL", $1->value * $3->value);
										$$->left = $1;
										$$->right = $3;
									}
	| 		expression '/' expression 			{
										if($3->value == 0){
											yyerror("Runtime error: Division by zero");
											exit(1);
										}else{
											$$ = allot_syntax_tree_node("DIV", $1->value / $3->value);
											$$->left = $1;
											$$->right = $3;
										}
									}
	| 		'(' expression ')'				{ 	$$ = $2; 					}			
	| 		ID						{ 
										$$ = allot_syntax_tree_node($1->name, $1->value);
									}
	| 		INT_NUMBER					{					
										$$ = allot_syntax_tree_node("NUM", $1);
									}
;	

print_statement: 	PRINT_STATEMENT '(' values ')'			{
										char output[100];
										sprintf(output, "Print call (Line %d)", lineno);
										put_in_sequence(output);
										
										seq_node_tail->sub_nodes = $3;
									}
;

values: 		values ',' expression				{ 	printf("%d\n", $3->value);
										$$ = allot_sequence_node("Sub-nodes");
										$$->root = $3;
										$$->prev = $1;
										$1->next = $$;
									}
	|		expression					{ 	printf("%d\n", $1->value);
										$$ = allot_sequence_node("Sub-nodes");
										$$->root = $1;
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
	printSymbolTable();
	printSequence();
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


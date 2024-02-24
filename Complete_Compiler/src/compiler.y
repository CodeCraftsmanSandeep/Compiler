%{
#include <stdio.h>
#include <stdbool.h>
#include "symbol_table.h"

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
}


%token <symp> ID
%token INT
%token <int_value> INT_NUMBER
%type  <int_value> expression
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
;

begin: 			BEGIN_DECL 					{	DECLARATION_PHASE = true;	}
;

end:			END_DECL					{	DECLARATION_PHASE = false;	}
;


declarations: 		declaration TERMINATOR				{ 					}
	|		declaration TERMINATOR declarations		{					}
;

declaration: 		DATATYPE ID				
	| 		DATATYPE ID ',' remaining
;

remaining:		ID
	|		ID ',' remaining
;

DATATYPE: 		INT
;
	
body: 			assignment TERMINATOR				{  	}
	| 		assignment TERMINATOR body			{  	}
	| 		expression TERMINATOR				{   	}
	| 		expression TERMINATOR body			{  	}
	| 		print_statement TERMINATOR			{  	}
	|		print_statement TERMINATOR body			{  	}
;

assignment:		ID '=' expression				{	$1->value = $3;					}
;

expression : 		expression '+' expression			{ 	$$ = $1 + $3;					}
	|		expression '-' expression			{ 	$$ = $1 - $3; 					}
	|		expression '*' expression			{ 	$$ = $1 * $3;					}
	| 		expression '/' expression 			{
										if($3 == 0){
											yyerror("Runtime error: Division by zero");
											exit(1);
										}else{
											$$ = $1 / $3;
										}
																}
	| 		'(' expression ')'				{ 	$$ = $2; 					}			
	| 		ID						{ 	$$ = $1->value;					}
	| 		INT_NUMBER					{	$$ = $1;					}
;	

print_statement: 	PRINT_STATEMENT '(' values ')'
;

values: 		expression					{ 	printf("%d\n", $1); 				}
	|		values ',' expression				{ 	printf("%d\n", $3); 				}
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
	
		
		
	

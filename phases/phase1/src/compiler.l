%{
#include "y.tab.h"
#include <stdbool.h>
struct symbol_table;
extern struct symbol_table* lookup(char*);
extern struct symbol_table* declare_variable(char*);
extern bool DECLARATION_PHASE;
extern void printSymbolTable();
extern int lineno;
%}

%%

"begindecl"					{ return BEGIN_DECL;									}
"enddecl"					{ return END_DECL;									}
"print"						{ return PRINT_STATEMENT;								}
"integer" 					{ return INT; 										}
[-]?[0-9][0-9]*     				{ yylval.int_value = atoi(yytext); return INT_NUMBER; 	        			}
";"						{ return TERMINATOR;							}
"+" 						|
"-" 						|
"*"						|
"/"						{ return yytext[0]; 							}
"=="						{ return ISEQUAL;							}
"!="						{ return ISNOTEQUAL;							}
[a-zA-Z_][a-zA-Z0-9_]*				{  
						  	if(DECLARATION_PHASE)	yylval.symp = declare_variable(yytext);
						  	else yylval.symp = lookup(yytext);
						  	return ID;    						
						}
[\n]						{ lineno++;					}
[ \t]						{	/*ignore*/;				}
.						{ return yytext[0]; 	        		}


%%



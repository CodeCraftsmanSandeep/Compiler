
%{
#include "y.tab.hpp"
struct symbol_table;
extern struct symbol_table* lookup(char*);
extern struct symbol_table* declare_variable(char*);
extern bool DECLARATION_PHASE;
extern int lineno;
extern char* my_text;


%}

%%

"decl"						{ return BEGIN_DECL;		/* need to change */			}
"enddecl"					{ return END_DECL;											}
"begin"						{ return BEGIN_BODY;												}
"end"  						{ return END_BODY;												}
"write"						{ return PRINT_STATEMENT;	/* need to change */			}
"integer" 					{ return INT; 												}
[0-9][0-9]*     			{ yylval.int_value = atoi(yytext); return INT_NUMBER;		}
";"							{ return TERMINATOR;										}
"+" 						|
"-" 						|
"*"							|
"/"							{ return yytext[0]; 										}
">"							{ return GREATER_THAN;										}
">="						{ return GREATER_THAN_OR_EQUAL_TO;							}
"<"							{ return LESS_THAN;											}
"<="						{ return LESS_THAN_OR_EQUAL_TO;								}
"=="						{ return IS_EQUAL;											}
"!="						{ return IS_NOT_EQUAL;										}
"if"						{ return IF;												}
"else"						{ return ELSE;												}
"for"						{ return FOR;												}
"break"						{ return BREAK;												}
"continue"					{ return CONTINUE;											}
[a-zA-Z_][a-zA-Z0-9_]*		{  
								yylval.name = strdup(yytext);
								return ID;    						
							}	
[\n]						{ 
								lineno++;
								/*ignore: nothing returned*/
							}
[ \t]						{	
								/*ignore: nothing returned*/;				
							}
.							{ return yytext[0]; 	        		}

%%


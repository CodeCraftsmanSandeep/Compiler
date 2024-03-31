
%{
#include "y.tab.h"
struct symbol_table;
extern struct symbol_table* lookup(char*);
extern struct symbol_table* declare_variable(char*);
extern int lineno;
extern char* my_text;


%}

%%

"decl"						{ return BEGIN_DECL;		/* need to change */			}
"enddecl"					{ return END_DECL;											}
"begin"						{ return PROGRAM_BEGIN;												}
"end"  						{ return PROGRAM_END;												}
"write"						{ return WRITE;	/* need to change */			}
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
"++"						{ return PLUS_PLUS; 	}
"--"						{ return MINUS_MINUS;	}
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


%{
#include "parser.hpp" // Include parser header file
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUM; }
[+\-\*/]    { return yytext[0]; }
[ \t\n]     ; // Ignore whitespace and newline characters
.           { return yytext[0]; } // Return any other character as is

%%

int yywrap() {
    return 1; // Indicate end of input
}


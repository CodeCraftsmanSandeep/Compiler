#include "parser.hpp" // Include parser header file

extern int yylex(); // Declare lexer function
extern int yylval; // Declare variable for token value

int yyparse(); // Declare parser function

int main() {
    yyparse();
    return 0;
}

// Implement yyerror function if needed
// void yyerror(const char* s) {
//     // Handle parsing errors
// }


%{
#include <iostream>
using namespace std;

extern int yylex();
extern int yylval;

void yyerror(const char* s) {
    cout << "Parser error: " << s << endl;
}

%}

%token NUM
%left '+' '-'
%left '*' '/'

%%

expression : expression '+' expression
           | expression '-' expression
           | expression '*' expression
           | expression '/' expression
           | '(' expression ')'
           | NUM
           ;

%%

int main() {
    yyparse();
    return 0;
}


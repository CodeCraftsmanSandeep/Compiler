# Phase1
Integers arthimetic is performed. A Basic calculator <br/>

# Phase2
As part of this phase, lex and yacc file codes are written to allow the following by the language (currently):
1) 'begindecl' and 'enddecl' are used to declare the variables. (here atmost one declaration block is allowed, and declaration block (if present) should be prsent before any other code).
2) ';' is used as terminator for a statement in the program.
3) body of the program (meaning code other than declaration block) may contain expressions, assignment statements, print function call.
4) Note that print function call arguments contain expressions (or) varaibles.
5) Arthimetic operations like '+', '-', '*', '/' are allowed. Unary minus is also allowed.
6) Current version allow expressions as statement (meaning expression TERMINATOR). (Although there will be no change in neither output nor any variable value)

Ouptut:
1) The following errors are reported:(if any)
	a) Compilation error	: Syntax error.
	b) Compilation error	: Variable declared multiple times.
	c) Compilation error	: Accesing undeclared variable.
	d) Compilation error	: Maximum limit crossed in symbol table. (Motto to add this error is to exhibit that the control we have to allow a program to compile :) ).
	e) Runtime error	: Division by zero.
2) If there are no errors then:
	a) All the contents relevant to print statement are printed, then
	b) Symbol table entries are printed, then
	c) Sequence of statements are printed. (Inorder traversal of abstract syntax tree (AST) for every expression is printed.)






printSymbolTable() function 

Printing the syntax tree ??



output AST of assignment two
1) Print AST of the program
2) print symbol table with value of the variable.


Project:

1) Printing the AST

2) Printing the symbol table entries

3) Adding support for one dimensional array, if-else statement, and for loop.

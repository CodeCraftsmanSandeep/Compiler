As part of this phase, the code are written to support the following the following constructs : <br/>
1) 'begindecl' and 'enddecl' are used to declare the variables. (here atmost one declaration block is allowed, and declaration block (if present) should be prsent before any other code).
2) ';' is used as terminator for a statement in the program.
3) body of the program (meaning code other than declaration block) may contain expressions, assignment statements, print function call.
4) Note that print function call arguments contain expressions (or) varaibles.
5) Arthimetic operations like '+', '-', '*', '/' are allowed. Unary minus is also allowed.
6) Current version allow expressions as statement (meaning expression TERMINATOR). (Although there will be no change in neither output nor any variable value)

Ouptut:
1) The following errors are reported:(if any) <br/>
	a) Compilation error	: Syntax error. <br/>
	b) Compilation error	: Variable declared multiple times. <br/>
	c) Compilation error	: Accesing undeclared variable. <br/>
	d) Compilation error	: Maximum limit crossed in symbol table. (Motto to add this error is that we can throw error when memory usage is exceeded some limit ). <br/>
	e) Runtime error	: Division by zero. <br/>
2) If there are no errors then: <br/>
	a) All the contents relevant to print statement are printed, then <br/>
	b) Symbol table entries are printed, then <br/>
	c) Sequence of statements are printed. (Inorder traversal of abstract syntax tree (AST) for every expression is printed.) <br/>

# phase 1 : Building basic interpreter !! 

As part of this phase, codes are written to support the following constructs : <br/>
1) 'begindecl' and 'enddecl' are used to declare the variables. (here atmost one declaration block is allowed, and declaration block (if present) should be prsent before any other code).
2) ';' is used as terminator for a statement in the program.
3) body of the program (meaning code other than declaration block) may contain expressions, assignment statements, print function call.
4) Note that print function call arguments contain expressions (or) varaibles.
5) Arthimetic operations like '+', '-', '*', '/' are allowed. Unary minus is also allowed.
6) Current version allow expressions as statement (meaning expression TERMINATOR). (Although there will be no change in neither output nor any variable value)

# Ouptut:

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

# Test case : <br/>

test case :
	begindecl 
	  integer b;
	  integer a;
	  integer c;
	enddecl

	a = 10;
	print(a);
	b = 20;
	print(b);
	c = a + b * a - b;
	print(c);
	c = 1;


Output of the above test case: <br/>
	10
	20
	190

	--Symbol table entries--
	variable 'b': 20
	variable 'a': 10
	variable 'c': 1
	--End of symbol table entries--

	--Start of sequence--
	Begin of declaration (Line 1)
		Line 2 : Declaring b
		Line 3 : Declaring a
		Line 4 : Declaring c
	End of declaration (Line 5)
	Assignment(Line 7)
		a ASSIGN NUM 
	Print call (Line 8)
		a 
	Assignment(Line 9)
		b ASSIGN NUM 
	Print call (Line 10)
		b 
	Assignment(Line 11)
		c ASSIGN a ADD b MUL a SUB b 
	Print call (Line 12)
		c 
	Assignment(Line 13)
		c ASSIGN NUM 
	--End of sequence--




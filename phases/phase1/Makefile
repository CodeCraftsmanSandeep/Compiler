all :
	yacc -d	compiler.y
	lex compiler.l 
	gcc lex.yy.c y.tab.c -ll -lm -o a.out

clean:
	rm lex.yy.c y.tab.c y.tab.h a.out

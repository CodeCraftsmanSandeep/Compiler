INCLUDE=-I./include/
all :
	yacc -o bin/y.tab.c -d src/compiler.y -ll 
	lex -o bin/lex.yy.c src/compiler.l 
	gcc ${INCLUDE} bin/lex.yy.c bin/y.tab.c -ll -lm -o bin/compiler.out
	
clean:
	rm bin/lex.yy.c bin/y.tab.c bin/y.tab.h bin/compiler.out

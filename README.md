# SCT - Simple Compiler Tool 
<br/>
This repositry contains compiler I built from scratch. Here after the compiler is called SCT(Simple Compiler Tool).<br/>

Synopsis <br/>
1) What language does SCT support (language specification, constructs) ??
2) What SCT does not support ??
3) What are the possible exentsions to SCT ??
4) How can you use SCT ??

The compiler is built in several phases which I built final compiler SCT.  <br/>
Have a look on phases : <br/>
	1) [phase1](phases/phase1) <br/>
	2) [phase2](phases/phase2) <br/>
	3) [phase3](phases/phase3) <br/>	
	
Each phase contains a detailed description of the constructs supported in respective readme files, test cases to evaluate, source code, include files, Makefile. The description is not repeated here to avoid redundancy which may lead to inconsistency (many times). <br/>

## Structure of each phase
inc repo contains all include files (headers). <br/>
src repo contains source code (compiler.l, compiler.y) <br/>
bin repo is used to generate the output files after make all ([see below](How can you use SCT)) <br/>
Makefile contains all needed commands to compiler (see below) <br/>

## How can you use SCT ??
Use Makefile <br/>
Makefile has all the commands to compile the codes in a phase. <br/>
		INCLUDE=-I./inc/
	all :
		yacc -o bin/y.tab.c -d src/compiler.y -ll 
		lex -o bin/lex.yy.c src/compiler.l 
		gcc ${INCLUDE} bin/lex.yy.c bin/y.tab.c -ll -lm -o bin/compiler.out
		
	clean:
		rm bin/lex.yy.c bin/y.tab.c bin/y.tab.h bin/compiler.out
**$ make all** creates a final executable compiler.out in bin repo. <br/>
**$ make clean removes** the contents generated which are generated in bin repo. <br/>
**$ ./bin/compiler.out will** execute the executable. <br/>




## What language does SCT support (language specification, constructs) ??


## What SCT does not support ??


## What are the possible exentsions to SCT ??





I am happy to receive any comments(if any) related to SCT. <br/>

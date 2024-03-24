all:
	yacc -d -o parser.cpp parser.y
	lex -o lexer.cpp lexer.l	
	g++ lexer.cpp parser.cpp -o program


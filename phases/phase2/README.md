# Phase 2
Phase2 is the extension of SCT developed till phase1 <br/>

What are the extensions introduced ? <br/>
1) Supporting one-dimensional arrays.
2) Supporting following operators:
   1) '>'
   2) '>='
   3) '<'
   4) '<='
   5) '=='
   6) '!='
   7) '%'
3) Supporting if-else statements. <br/>
4) Supporting for loop <br/>
6) supporting read, break, continue statements

NOTE:
1) ; is considered as a valid statement (as in C)
2) A if-else if-else block with single statement must have { } (unlike in C)
3) Having break or continue in inapproproate locations ????????? (how to do this)


# Output
The output of this phase of the compiler is to print symbol table entries and abstract syntax tree. <br/>
Let's have a look at the following test_case : ([test_case6](test_cases/6.prog)) <br/>
	decl
		integer key;
		integer mid, temp;
		integer test, array[test+key*2], i;
		integer start;
		integer result;
	enddecl

	begin
	   	test=0;
	    	for(i=0;i<10;i++) {
			array[test] = test;
			test = test + 1;
			for(i = 0; i < 10; i++){
				continue;
				break;
			}
	    	}
		read(mid, array[0]);
		key=array[5];
		start=1;
		--start;
		++array[5*8+9*10];
		write(-2, -10);
	end

For getting output, use command **$./bin/compiler.out < test_cases/6.prog** <br/>
Output of the above test_case : <br/>

	------Symbol table entries------
		Variable 'key' 
		Variable 'mid' 
		Variable 'temp' 
		Variable 'test' 
		Array		: array (size = ( test ) Add (( key ) Mul ( 2 )))
		Variable 'i' 
		Variable 'start' 
		Variable 'result' 
	------End of symbol table entries------

	--------Syntax tree--------
	Declaration
		Variable	: key
		Variable	: mid
		Variable	: temp
		Variable	: test
		Array		: array (size = ( test ) Add (( key ) Mul ( 2 )) )
		Variable	: i
		Variable	: start
		Variable	: result
	Body
		( test ) Assign ( 0 )
		For
		Expr1: ( i ) Assign ( 0 )
		Expr2: ( i ) Less_than ( 10 )
		Expr3: ( i Post_increment) 
		Body
			( (array[ test ]) ) Assign ( test )
			( test ) Assign (( test ) Add ( 1 ))
			For
			Expr1: ( i ) Assign ( 0 )
			Expr2: ( i ) Less_than ( 10 )
			Expr3: ( i Post_increment) 
			Body
				Continue statement
				Break statement
		READ :  mid 
		READ :  (array[ 0 ]) 
		( key ) Assign ( (array[ 5 ]) )
		( start ) Assign ( 1 )
		(Pre_decrement start ) 
		(Pre_increment (array[(( 5 ) Mul ( 8 )) Add (( 9 ) Mul ( 10 ))]) ) 
		PRINT : (Unary_minus  2 ) 
		PRINT : (Unary_minus  10 ) 

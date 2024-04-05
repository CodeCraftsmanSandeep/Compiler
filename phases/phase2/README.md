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
2) A if block with single statement must have { } (unlike in C)
3) Having break or continue in inapproproate location ????????? (how to do this)

# Doubts 

# Important bug to note!!
I do not want SCT to accept the code similar to c code (int x = - - - 2) in [c](c) which is accepted by c compilers (eg: gcc). <br/>
That is the reason I have introduced new non terminal **unary_expression**. <br/>
I intend that SCT accpets following : <br/>
   1) int x = -100;
   2) int x = - 100;
I intend that SCT dont accept the following : <br/>
   1) int x = -----100;
   2) int x = - - - - 100;
Intutive solutions that did not work : <br/>
   1) If you try doing something like [-]?[0-9][0-9]* in lex file, then statments like int x = - 2; will not be accpeted because of space in between. - and 2 will treated as different lexemes.
   2) If you just try to add '-' expression {$$ = -$2}, this will lead to accpeting **int x = - - - 2**. 

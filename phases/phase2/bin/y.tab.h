/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BIN_Y_TAB_H_INCLUDED
# define YY_YY_BIN_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INT_NUMBER = 259,              /* INT_NUMBER  */
    INT = 260,                     /* INT  */
    BEGIN_DECL = 261,              /* BEGIN_DECL  */
    END_DECL = 262,                /* END_DECL  */
    PROGRAM_BEGIN = 263,           /* PROGRAM_BEGIN  */
    PROGRAM_END = 264,             /* PROGRAM_END  */
    TERMINATOR = 265,              /* TERMINATOR  */
    WRITE = 266,                   /* WRITE  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    FOR = 269,                     /* FOR  */
    BREAK = 270,                   /* BREAK  */
    CONTINUE = 271,                /* CONTINUE  */
    PLUS_PLUS = 272,               /* PLUS_PLUS  */
    MINUS_MINUS = 273,             /* MINUS_MINUS  */
    GREATER_THAN = 274,            /* GREATER_THAN  */
    GREATER_THAN_OR_EQUAL_TO = 275, /* GREATER_THAN_OR_EQUAL_TO  */
    LESS_THAN = 276,               /* LESS_THAN  */
    LESS_THAN_OR_EQUAL_TO = 277,   /* LESS_THAN_OR_EQUAL_TO  */
    IS_EQUAL = 278,                /* IS_EQUAL  */
    IS_NOT_EQUAL = 279,            /* IS_NOT_EQUAL  */
    UMINUS = 280,                  /* UMINUS  */
    PRE_PLUS_PLUS = 281,           /* PRE_PLUS_PLUS  */
    PRE_MINUS_MINUS = 282,         /* PRE_MINUS_MINUS  */
    ACCESS = 283,                  /* ACCESS  */
    POST_PLUS_PLUS = 284,          /* POST_PLUS_PLUS  */
    POST_MINUS_MINUS = 285,        /* POST_MINUS_MINUS  */
    PAREN = 286                    /* PAREN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT_NUMBER 259
#define INT 260
#define BEGIN_DECL 261
#define END_DECL 262
#define PROGRAM_BEGIN 263
#define PROGRAM_END 264
#define TERMINATOR 265
#define WRITE 266
#define IF 267
#define ELSE 268
#define FOR 269
#define BREAK 270
#define CONTINUE 271
#define PLUS_PLUS 272
#define MINUS_MINUS 273
#define GREATER_THAN 274
#define GREATER_THAN_OR_EQUAL_TO 275
#define LESS_THAN 276
#define LESS_THAN_OR_EQUAL_TO 277
#define IS_EQUAL 278
#define IS_NOT_EQUAL 279
#define UMINUS 280
#define PRE_PLUS_PLUS 281
#define PRE_MINUS_MINUS 282
#define ACCESS 283
#define POST_PLUS_PLUS 284
#define POST_MINUS_MINUS 285
#define PAREN 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

	int int_value;								
	char* name;									
	struct block* block_ptr;
	struct statement_node* one_statement;		
	struct expression_node* expr;
	struct else_if_helper* aux;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */

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
    READ = 267,                    /* READ  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    FOR = 270,                     /* FOR  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    PLUS_PLUS = 273,               /* PLUS_PLUS  */
    MINUS_MINUS = 274,             /* MINUS_MINUS  */
    GREATER_THAN = 275,            /* GREATER_THAN  */
    GREATER_THAN_OR_EQUAL_TO = 276, /* GREATER_THAN_OR_EQUAL_TO  */
    LESS_THAN = 277,               /* LESS_THAN  */
    LESS_THAN_OR_EQUAL_TO = 278,   /* LESS_THAN_OR_EQUAL_TO  */
    IS_EQUAL = 279,                /* IS_EQUAL  */
    IS_NOT_EQUAL = 280,            /* IS_NOT_EQUAL  */
    UMINUS = 281,                  /* UMINUS  */
    PRE_PLUS_PLUS = 282,           /* PRE_PLUS_PLUS  */
    PRE_MINUS_MINUS = 283,         /* PRE_MINUS_MINUS  */
    ACCESS = 284,                  /* ACCESS  */
    POST_PLUS_PLUS = 285,          /* POST_PLUS_PLUS  */
    POST_MINUS_MINUS = 286,        /* POST_MINUS_MINUS  */
    PAREN = 287                    /* PAREN  */
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
#define READ 267
#define IF 268
#define ELSE 269
#define FOR 270
#define BREAK 271
#define CONTINUE 272
#define PLUS_PLUS 273
#define MINUS_MINUS 274
#define GREATER_THAN 275
#define GREATER_THAN_OR_EQUAL_TO 276
#define LESS_THAN 277
#define LESS_THAN_OR_EQUAL_TO 278
#define IS_EQUAL 279
#define IS_NOT_EQUAL 280
#define UMINUS 281
#define PRE_PLUS_PLUS 282
#define PRE_MINUS_MINUS 283
#define ACCESS 284
#define POST_PLUS_PLUS 285
#define POST_MINUS_MINUS 286
#define PAREN 287

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

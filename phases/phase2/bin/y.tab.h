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
    INT = 259,                     /* INT  */
    INT_NUMBER = 260,              /* INT_NUMBER  */
    BEGIN_DECL = 261,              /* BEGIN_DECL  */
    END_DECL = 262,                /* END_DECL  */
    TERMINATOR = 263,              /* TERMINATOR  */
    PRINT_STATEMENT = 264,         /* PRINT_STATEMENT  */
    DOUBLE = 265,                  /* DOUBLE  */
    DOUBLE_NUMBER = 266,           /* DOUBLE_NUMBER  */
    RETURN = 267,                  /* RETURN  */
    IF = 268,                      /* IF  */
    ELSE = 269,                    /* ELSE  */
    INCLUDE = 270,                 /* INCLUDE  */
    ISEQUAL = 271,                 /* ISEQUAL  */
    ISNOTEQUAL = 272,              /* ISNOTEQUAL  */
    PLUSPLUS = 273,                /* PLUSPLUS  */
    MINUSMINUS = 274,              /* MINUSMINUS  */
    UMINUS = 275                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INT 259
#define INT_NUMBER 260
#define BEGIN_DECL 261
#define END_DECL 262
#define TERMINATOR 263
#define PRINT_STATEMENT 264
#define DOUBLE 265
#define DOUBLE_NUMBER 266
#define RETURN 267
#define IF 268
#define ELSE 269
#define INCLUDE 270
#define ISEQUAL 271
#define ISNOTEQUAL 272
#define PLUSPLUS 273
#define MINUSMINUS 274
#define UMINUS 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

	int int_value;				/* int_value */
	struct symbol_table* symp;		/* symbol table pointer */


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BIN_Y_TAB_H_INCLUDED  */

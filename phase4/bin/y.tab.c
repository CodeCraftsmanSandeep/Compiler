/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "expression_tree.h"
#include "symbol_table.h"

#include "sequence.h"
extern struct block* allot_block();

struct symbol_table;
extern int yylex();
void yyerror(char*);
extern char* yytext;
extern FILE* yyin;
int lineno = 1;
char error_string[100];

struct block* root = NULL;
struct else_if_helper{
	struct if_statement_node* else_if_begin;
	struct if_statement_node* else_if_end;
};

int nested_for_count = 0;



# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT_NUMBER = 4,                 /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 5,               /* FLOAT_NUMBER  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BEGIN_DECL = 8,                 /* BEGIN_DECL  */
  YYSYMBOL_END_DECL = 9,                   /* END_DECL  */
  YYSYMBOL_PROGRAM_BEGIN = 10,             /* PROGRAM_BEGIN  */
  YYSYMBOL_PROGRAM_END = 11,               /* PROGRAM_END  */
  YYSYMBOL_TERMINATOR = 12,                /* TERMINATOR  */
  YYSYMBOL_WRITE = 13,                     /* WRITE  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_BREAK = 18,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 19,                  /* CONTINUE  */
  YYSYMBOL_PLUS_PLUS = 20,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 21,               /* MINUS_MINUS  */
  YYSYMBOL_GREATER_THAN = 22,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL_TO = 23,  /* GREATER_THAN_OR_EQUAL_TO  */
  YYSYMBOL_LESS_THAN = 24,                 /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL_TO = 25,     /* LESS_THAN_OR_EQUAL_TO  */
  YYSYMBOL_IS_EQUAL = 26,                  /* IS_EQUAL  */
  YYSYMBOL_IS_NOT_EQUAL = 27,              /* IS_NOT_EQUAL  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '%'  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_PRE_PLUS_PLUS = 35,             /* PRE_PLUS_PLUS  */
  YYSYMBOL_PRE_MINUS_MINUS = 36,           /* PRE_MINUS_MINUS  */
  YYSYMBOL_ACCESS = 37,                    /* ACCESS  */
  YYSYMBOL_POST_PLUS_PLUS = 38,            /* POST_PLUS_PLUS  */
  YYSYMBOL_POST_MINUS_MINUS = 39,          /* POST_MINUS_MINUS  */
  YYSYMBOL_PAREN = 40,                     /* PAREN  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_declaration_block = 50,         /* declaration_block  */
  YYSYMBOL_declarations = 51,              /* declarations  */
  YYSYMBOL_decl_types = 52,                /* decl_types  */
  YYSYMBOL_array_production = 53,          /* array_production  */
  YYSYMBOL_DATATYPE = 54,                  /* DATATYPE  */
  YYSYMBOL_source_program = 55,            /* source_program  */
  YYSYMBOL_body = 56,                      /* body  */
  YYSYMBOL_print_values = 57,              /* print_values  */
  YYSYMBOL_if_statement = 58,              /* if_statement  */
  YYSYMBOL_else_ifs = 59,                  /* else_ifs  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_l_value = 61,                   /* l_value  */
  YYSYMBOL_more_indexes = 62,              /* more_indexes  */
  YYSYMBOL_while_production = 63,          /* while_production  */
  YYSYMBOL_for_production = 64             /* for_production  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      42,    43,    31,    29,    41,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    34,    35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   107,   118,   123,   126,   131,   145,   167,
     168,   171,   176,   182,   187,   195,   201,   206,   211,   212,
     215,   220,   233,   238,   250,   251,   252,   257,   269,   272,
     282,   287,   299,   304,   316,   321,   336,   342,   351,   352,
     353,   357,   361,   365,   369,   374,   379,   384,   389,   393,
     399,   404,   409,   414,   421,   422,   426,   427,   428,   431,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   451,   452,   456,   461,   469,
     470,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT_NUMBER",
  "FLOAT_NUMBER", "INT", "FLOAT", "BEGIN_DECL", "END_DECL",
  "PROGRAM_BEGIN", "PROGRAM_END", "TERMINATOR", "WRITE", "IF", "ELSE",
  "FOR", "WHILE", "BREAK", "CONTINUE", "PLUS_PLUS", "MINUS_MINUS",
  "GREATER_THAN", "GREATER_THAN_OR_EQUAL_TO", "LESS_THAN",
  "LESS_THAN_OR_EQUAL_TO", "IS_EQUAL", "IS_NOT_EQUAL", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UMINUS", "PRE_PLUS_PLUS", "PRE_MINUS_MINUS",
  "ACCESS", "POST_PLUS_PLUS", "POST_MINUS_MINUS", "PAREN", "','", "'('",
  "')'", "'{'", "'}'", "'['", "']'", "$accept", "program",
  "declaration_block", "declarations", "decl_types", "array_production",
  "DATATYPE", "source_program", "body", "print_values", "if_statement",
  "else_ifs", "expression", "l_value", "more_indexes", "while_production",
  "for_production", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   145,  1132,     8,    19,   -26,   -26,   -26,   -26,   -26,
     202,    14,   -16,   -26,   -26,   -26,   -26,   -20,    -6,    16,
      34,    62,    63,    83,    83,   104,   104,  1152,   -26,  1202,
     -15,   -26,   -26,   -26,   -26,   -26,   -26,    14,   -16,    11,
     -26,   104,   -26,   104,   104,   123,   104,   -26,   -26,   -26,
     -26,   -26,  1214,   -26,   -26,    50,    85,    86,   -26,  1236,
     -26,   -26,   -26,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   -26,   -26,   104,    12,   -26,   -16,
     -26,    99,   -26,  1176,    41,  1425,  1248,   180,  1270,  1282,
     -26,   104,   -26,   -26,   -26,   100,   100,   100,   100,   294,
     294,     1,     1,   -26,   -26,   -26,  1425,   -26,   -26,   -16,
     104,    91,    67,     7,  1304,  1155,    75,    48,   -26,  1425,
     -26,    51,    78,  1316,    74,  1087,  1338,   248,   106,   125,
     292,   326,    79,   105,  1350,   126,  1365,  1091,   -26,   345,
     -26,    17,   135,   158,   -26,   379,   398,   432,   132,   451,
     138,   144,  1380,   -26,   137,   485,    43,    66,   174,   -26,
     -26,   504,   -26,   538,   557,   -26,   591,   610,   644,   153,
     104,   -26,   663,   160,   697,   716,    69,   -26,   -26,   -26,
     750,   -26,   -26,   769,   -26,   803,   822,  1395,   -26,   104,
     -26,   856,   -26,   875,   909,   -26,   -26,   -26,   -26,   928,
     159,  1410,   -26,   -26,   -26,   962,   -26,   981,   162,   -26,
     -26,  1015,  1034,   -26,   -26,  1068,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,    16,    17,     6,     9,
       0,     0,    75,    58,    59,    19,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      57,    34,    32,     1,     3,     5,    10,     0,    11,     0,
      13,     0,    76,     0,     0,     0,     0,    20,    22,    71,
      72,    55,     0,    18,    25,     0,     0,     0,    31,     0,
      35,    33,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,    15,     0,
       7,     0,    14,     0,     0,    37,     0,     0,     0,     0,
      54,     0,    21,    23,    27,    65,    66,    67,    68,    69,
      70,    60,    61,    62,    63,    64,    56,     8,    12,    77,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    36,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
      29,     0,    49,    38,    96,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,    48,    95,
      94,     0,    93,     0,     0,    92,     0,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,    86,    87,    88,
       0,    89,    90,     0,    91,     0,     0,     0,    42,     0,
      47,     0,    41,     0,     0,    82,    83,    84,    85,     0,
       0,     0,    45,    40,    46,     0,    81,     0,     0,    44,
      51,     0,     0,    50,    53,     0,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -26,   -26,   -26,   -26,   170,    -4,   209,   216,   108,   130,
     -24,    84,   -25,     2,    -8,    32,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    10,    39,    40,    11,     5,    27,    84,
      28,   142,    29,    30,    78,    31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    59,    58,    42,    74,    75,     1,    33,     2,
      12,    13,    14,    76,    79,    79,    83,    38,    85,    86,
      88,    89,    43,    80,   107,    49,    50,    23,    24,     2,
      41,   154,    71,    72,    73,    82,    44,    25,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    26,
     122,   106,    81,    81,    12,    13,    14,   173,    45,    60,
      61,   155,   114,    16,    17,    18,    85,    19,    20,    21,
      22,    23,    24,    82,    47,    48,    46,    12,    13,    14,
     154,    25,   110,   173,   111,   119,    12,   174,   123,   110,
     126,   128,    91,    26,    23,    24,   129,    92,    93,   134,
     136,   118,   108,   120,    25,    59,    58,    12,    13,    14,
     175,   121,   152,   194,    59,    58,    26,   133,   140,   127,
      59,    58,   131,   146,    23,    24,    12,    13,    14,    69,
      70,    71,    72,    73,    25,    87,    59,    58,    59,    58,
     141,    59,    58,    23,    24,   187,    26,    59,    58,   147,
     156,     6,     7,    25,     8,    59,    58,     9,    59,    58,
      59,    58,    60,    61,   201,    26,    59,    58,    59,    58,
     149,    60,    61,   157,    59,    58,   164,    60,    61,   170,
      59,    58,   167,    12,    13,    14,    59,    58,   168,   176,
      59,    58,   113,    60,    61,    60,    61,   186,    60,    61,
      23,    24,   189,   207,    60,    61,   212,    77,     6,     7,
      25,    35,    60,    61,    36,    60,    61,    60,    61,    37,
      34,   117,    26,    60,    61,    60,    61,   158,     0,   130,
       0,    60,    61,     0,     0,   139,     0,    60,    61,   145,
       0,     0,     0,    60,    61,     0,     0,    60,    61,     0,
       0,    12,    13,    14,   161,   163,     0,   166,     0,     0,
      16,    17,    18,   172,    19,    20,    21,    22,    23,    24,
       0,     0,   180,     0,     0,   183,   185,     0,    25,     0,
       0,     0,   191,   193,     0,     0,     0,     0,     0,     0,
      26,     0,     0,   138,   199,    12,    13,    14,     0,     0,
       0,     0,   205,     0,    54,    55,    18,     0,    19,    20,
      56,    57,    23,    24,     0,   211,    63,    64,    65,    66,
     215,     0,    25,    69,    70,    71,    72,    73,     0,    12,
      13,    14,     0,     0,    26,     0,     0,   143,    16,    17,
      18,     0,    19,    20,    21,    22,    23,    24,    12,    13,
      14,     0,     0,     0,     0,     0,    25,    54,    55,    18,
       0,    19,    20,    56,    57,    23,    24,     0,    26,     0,
       0,   144,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,    26,     0,     0,
     153,    54,    55,    18,     0,    19,    20,    56,    57,    23,
      24,    12,    13,    14,     0,     0,     0,     0,     0,    25,
      16,    17,    18,     0,    19,    20,    21,    22,    23,    24,
       0,    26,     0,     0,   159,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
      26,     0,     0,   160,    16,    17,    18,     0,    19,    20,
      21,    22,    23,    24,    12,    13,    14,     0,     0,     0,
       0,     0,    25,    16,    17,    18,     0,    19,    20,    21,
      22,    23,    24,     0,    26,     0,     0,   162,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,    26,     0,     0,   165,    16,    17,    18,
       0,    19,    20,    21,    22,    23,    24,    12,    13,    14,
       0,     0,     0,     0,     0,    25,    54,    55,    18,     0,
      19,    20,    56,    57,    23,    24,     0,    26,     0,     0,
     171,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,    26,     0,     0,   177,
      54,    55,    18,     0,    19,    20,    56,    57,    23,    24,
      12,    13,    14,     0,     0,     0,     0,     0,    25,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,     0,
      26,     0,     0,   178,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,    26,
       0,     0,   179,    54,    55,    18,     0,    19,    20,    56,
      57,    23,    24,    12,    13,    14,     0,     0,     0,     0,
       0,    25,    16,    17,    18,     0,    19,    20,    21,    22,
      23,    24,     0,    26,     0,     0,   181,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       0,     0,    26,     0,     0,   182,    16,    17,    18,     0,
      19,    20,    21,    22,    23,    24,    12,    13,    14,     0,
       0,     0,     0,     0,    25,    54,    55,    18,     0,    19,
      20,    56,    57,    23,    24,     0,    26,     0,     0,   184,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     0,
      12,    13,    14,     0,     0,    26,     0,     0,   188,    16,
      17,    18,     0,    19,    20,    21,    22,    23,    24,    12,
      13,    14,     0,     0,     0,     0,     0,    25,    16,    17,
      18,     0,    19,    20,    21,    22,    23,    24,     0,    26,
       0,     0,   190,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,    12,    13,    14,     0,     0,    26,     0,
       0,   192,    54,    55,    18,     0,    19,    20,    56,    57,
      23,    24,    12,    13,    14,     0,     0,     0,     0,     0,
      25,    54,    55,    18,     0,    19,    20,    56,    57,    23,
      24,     0,    26,     0,     0,   195,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,    26,     0,     0,   196,    54,    55,    18,     0,    19,
      20,    56,    57,    23,    24,    12,    13,    14,     0,     0,
       0,     0,     0,    25,    16,    17,    18,     0,    19,    20,
      21,    22,    23,    24,     0,    26,     0,     0,   197,     0,
       0,     0,    25,     0,     0,     0,     0,     0,     0,    12,
      13,    14,     0,     0,    26,     0,     0,   198,    54,    55,
      18,     0,    19,    20,    56,    57,    23,    24,    12,    13,
      14,     0,     0,     0,     0,     0,    25,    54,    55,    18,
       0,    19,    20,    56,    57,    23,    24,     0,    26,     0,
       0,   202,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,    26,     0,     0,
     203,    16,    17,    18,     0,    19,    20,    21,    22,    23,
      24,    12,    13,    14,     0,     0,     0,     0,     0,    25,
      54,    55,    18,     0,    19,    20,    56,    57,    23,    24,
       0,    26,     0,     0,   204,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
      26,     0,     0,   206,    54,    55,    18,     0,    19,    20,
      56,    57,    23,    24,    12,    13,    14,     0,     0,     0,
       0,     0,    25,    16,    17,    18,     0,    19,    20,    21,
      22,    23,    24,     0,    26,     0,     0,   209,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,    12,    13,
      14,     0,     0,    26,     0,     0,   210,    54,    55,    18,
       0,    19,    20,    56,    57,    23,    24,    12,    13,    14,
       0,     0,     0,     0,     0,    25,    16,    17,    18,     0,
      19,    20,    21,    22,    23,    24,     0,    26,     0,     0,
     213,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,    26,     0,     0,   214,
      54,    55,    18,     0,    19,    20,    56,    57,    23,    24,
      12,    13,    14,     0,    12,    13,    14,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
      26,    23,    24,   216,     0,     0,     0,    25,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    26,
     135,     0,     0,    26,   151,    12,    13,    14,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,    19,    20,
      21,    22,    23,    24,     0,    12,    13,    14,    12,    13,
      14,     0,    25,    53,    54,    55,    18,   125,    19,    20,
      56,    57,    23,    24,    26,    23,    24,     0,     0,     0,
       0,     0,    25,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,    26,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,   109,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    94,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,   115,     0,     0,     0,     0,     0,     0,     0,
       0,   112,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   116,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
     137,     0,     0,     0,     0,     0,     0,     0,     0,   132,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,     0,     0,    63,    64,    65,
      66,    67,    68,   148,    69,    70,    71,    72,    73,     0,
       0,     0,    63,    64,    65,    66,    67,    68,   150,    69,
      70,    71,    72,    73,     0,     0,     0,    63,    64,    65,
      66,    67,    68,   169,    69,    70,    71,    72,    73,     0,
       0,     0,    63,    64,    65,    66,    67,    68,   200,    69,
      70,    71,    72,    73,     0,     0,     0,    63,    64,    65,
      66,    67,    68,   208,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      25,    26,    27,    27,    12,    20,    21,     8,     0,    10,
       3,     4,     5,    28,     3,     3,    41,     3,    43,    44,
      45,    46,    42,    12,    12,    23,    24,    20,    21,    10,
      46,    14,    31,    32,    33,    39,    42,    30,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    42,
      43,    76,    41,    41,     3,     4,     5,    14,    42,    27,
      27,    44,    87,    12,    13,    14,    91,    16,    17,    18,
      19,    20,    21,    77,    12,    12,    42,     3,     4,     5,
      14,    30,    41,    14,    43,   110,     3,    44,   113,    41,
     115,    43,    42,    42,    20,    21,    45,    12,    12,   124,
     125,   109,     3,    12,    30,   130,   130,     3,     4,     5,
      44,    44,   137,    44,   139,   139,    42,    43,    12,    44,
     145,   145,    44,    44,    20,    21,     3,     4,     5,    29,
      30,    31,    32,    33,    30,    12,   161,   161,   163,   163,
      15,   166,   166,    20,    21,   170,    42,   172,   172,    44,
      15,     6,     7,    30,     9,   180,   180,    12,   183,   183,
     185,   185,   130,   130,   189,    42,   191,   191,   193,   193,
      44,   139,   139,    15,   199,   199,    44,   145,   145,    42,
     205,   205,    44,     3,     4,     5,   211,   211,    44,    15,
     215,   215,    12,   161,   161,   163,   163,    44,   166,   166,
      20,    21,    42,    44,   172,   172,    44,    37,     6,     7,
      30,     9,   180,   180,    12,   183,   183,   185,   185,    10,
       4,    91,    42,   191,   191,   193,   193,   143,    -1,   121,
      -1,   199,   199,    -1,    -1,   127,    -1,   205,   205,   131,
      -1,    -1,    -1,   211,   211,    -1,    -1,   215,   215,    -1,
      -1,     3,     4,     5,   146,   147,    -1,   149,    -1,    -1,
      12,    13,    14,   155,    16,    17,    18,    19,    20,    21,
      -1,    -1,   164,    -1,    -1,   167,   168,    -1,    30,    -1,
      -1,    -1,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,   186,     3,     4,     5,    -1,    -1,
      -1,    -1,   194,    -1,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    -1,   207,    22,    23,    24,    25,
     212,    -1,    30,    29,    30,    31,    32,    33,    -1,     3,
       4,     5,    -1,    -1,    42,    -1,    -1,    45,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    30,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    42,    -1,    -1,
      45,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    30,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      42,    -1,    -1,    45,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    30,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    42,    -1,    -1,    45,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    30,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    42,    -1,    -1,    45,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    30,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    42,
      -1,    -1,    45,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    30,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    42,    -1,    -1,    45,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    30,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    42,    -1,    -1,    45,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    30,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,    -1,    42,
      -1,    -1,    45,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    42,    -1,
      -1,    45,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      30,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    42,    -1,    -1,    45,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    30,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    42,    -1,    -1,    45,    12,    13,
      14,    -1,    16,    17,    18,    19,    20,    21,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    30,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    42,    -1,    -1,
      45,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    30,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      42,    -1,    -1,    45,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    30,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    42,    -1,    -1,    45,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    21,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    30,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    42,    -1,    -1,    45,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
       3,     4,     5,    -1,     3,     4,     5,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      42,    20,    21,    45,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    42,    43,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    -1,     3,     4,     5,     3,     4,
       5,    -1,    30,    11,    12,    13,    14,    12,    16,    17,
      18,    19,    20,    21,    42,    20,    21,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    42,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    43,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    43,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    43,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    43,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    43,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    49,    50,    55,     6,     7,     9,    12,
      51,    54,     3,     4,     5,    11,    12,    13,    14,    16,
      17,    18,    19,    20,    21,    30,    42,    56,    58,    60,
      61,    63,    64,     0,    55,     9,    12,    54,     3,    52,
      53,    46,    62,    42,    42,    42,    42,    12,    12,    61,
      61,    60,    60,    11,    12,    13,    18,    19,    58,    60,
      63,    64,    12,    22,    23,    24,    25,    26,    27,    29,
      30,    31,    32,    33,    20,    21,    28,    52,    62,     3,
      12,    41,    53,    60,    57,    60,    60,    12,    60,    60,
      43,    42,    12,    12,    12,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    12,     3,    47,
      41,    43,    43,    12,    60,    12,    43,    57,    62,    60,
      12,    44,    43,    60,    12,    12,    60,    44,    43,    45,
      56,    44,    43,    43,    60,    43,    60,    12,    45,    56,
      12,    15,    59,    45,    45,    56,    44,    44,    43,    44,
      43,    43,    60,    45,    14,    44,    15,    15,    59,    45,
      45,    56,    45,    56,    44,    45,    56,    44,    44,    43,
      42,    45,    56,    14,    44,    44,    15,    45,    45,    45,
      56,    45,    45,    56,    45,    56,    44,    60,    45,    42,
      45,    56,    45,    56,    44,    45,    45,    45,    45,    56,
      43,    60,    45,    45,    45,    56,    45,    44,    43,    45,
      45,    56,    44,    45,    45,    56,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     3,     4,     1,
       2,     1,     3,     1,     2,     2,     1,     1,     3,     2,
       2,     3,     2,     3,     1,     2,     2,     3,     5,     6,
       1,     2,     1,     2,     1,     2,     3,     1,     7,     6,
      11,    10,    10,     9,    12,    11,    11,    10,     8,     7,
       8,     7,     9,     8,     3,     2,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     1,     2,     3,     4,     6,
       7,    11,    10,    10,    10,    10,     9,     9,     9,     9,
       9,     9,     8,     8,     8,     8,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_block  */
                                                                                {
														root = (yyvsp[0].block_ptr);
													}
    break;

  case 3: /* program: declaration_block source_program  */
                                                                        {
														/* check for NULLS */
														if((yyvsp[-1].block_ptr) == NULL) root = (yyvsp[0].block_ptr);
														else if((yyvsp[0].block_ptr) == NULL) root = (yyvsp[-1].block_ptr);
														else{
															(yyvsp[-1].block_ptr)->block_end->next = (yyvsp[0].block_ptr)->block_start;
															(yyvsp[0].block_ptr)->block_start->prev = (yyvsp[-1].block_ptr)->block_end;
															(yyvsp[-1].block_ptr)->block_end = (yyvsp[0].block_ptr)->block_end;
															root = (yyvsp[-1].block_ptr);
														}
													}
    break;

  case 4: /* program: source_program  */
                                                                                        {
														root = (yyvsp[0].block_ptr);
													}
    break;

  case 5: /* declaration_block: BEGIN_DECL declarations END_DECL  */
                                                                                {
																	(yyval.block_ptr) = (yyvsp[-1].block_ptr);
																}
    break;

  case 6: /* declaration_block: BEGIN_DECL END_DECL  */
                                                                                                                {
																	(yyval.block_ptr) = NULL;
																}
    break;

  case 7: /* declarations: DATATYPE decl_types TERMINATOR  */
                                                                                                { 	(yyval.block_ptr) = (yyvsp[-1].block_ptr); 
																			struct statement_node* trav = (yyval.block_ptr)->block_start;
																			if(*(yyvsp[-2].d_type) == INT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = INT_datatype;
																					trav = trav->next;
																				}
																			}else if(*(yyvsp[-2].d_type) == FLOAT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = FLOAT_datatype;
																					trav = trav->next;
																				}
																			}
																		}
    break;

  case 8: /* declarations: declarations DATATYPE decl_types TERMINATOR  */
                                                                                                { 
																			if((yyvsp[-3].block_ptr) == NULL){
																				(yyval.block_ptr) = (yyvsp[-1].block_ptr);
																			}else{
																				(yyvsp[-3].block_ptr)->block_end->next = (yyvsp[-1].block_ptr)->block_start;
																				(yyvsp[-1].block_ptr)->block_start->prev = (yyvsp[-3].block_ptr)->block_end;
																				(yyvsp[-3].block_ptr)->block_end = (yyvsp[-1].block_ptr)->block_end;
																				(yyval.block_ptr) = (yyvsp[-3].block_ptr);
																			}
																			struct statement_node* trav = (yyvsp[-1].block_ptr)->block_start;
																			if(*(yyvsp[-2].d_type) == INT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = INT_datatype;
																					trav = trav->next;
																				}
																			}else if(*(yyvsp[-2].d_type) == FLOAT_datatype){
																				while(trav != NULL){
																					trav->decl_node->type_of_var = FLOAT_datatype;
																					trav = trav->next;
																				}
																			}
																		}
    break;

  case 9: /* declarations: TERMINATOR  */
                                                                                                                                        { (yyval.block_ptr) = NULL; }
    break;

  case 10: /* declarations: declarations TERMINATOR  */
                                                                                                                        { (yyval.block_ptr) = (yyvsp[-1].block_ptr);	}
    break;

  case 11: /* decl_types: ID  */
                                                                                                {
														(yyval.block_ptr) = allot_block();
														(yyval.block_ptr)->block_start = allot_statement(DECLARATION, VARIABLE, (yyvsp[0].name));
														(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
													}
    break;

  case 12: /* decl_types: decl_types ',' ID  */
                                                                                        {
														(yyvsp[-2].block_ptr)->block_end->next = allot_statement(DECLARATION, VARIABLE, (yyvsp[0].name));
														(yyvsp[-2].block_ptr)->block_end->next->prev = (yyvsp[-2].block_ptr)->block_end->next;
														(yyvsp[-2].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end->next;
														(yyval.block_ptr) = (yyvsp[-2].block_ptr);
													}
    break;

  case 13: /* decl_types: array_production  */
                                                                                        {
														(yyval.block_ptr) = allot_block();
														(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
														(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
													}
    break;

  case 14: /* decl_types: decl_types array_production  */
                                                                                {
														(yyvsp[-1].block_ptr)->block_end->next = (yyvsp[0].one_statement);
														(yyvsp[-1].block_ptr)->block_end->next->prev = (yyvsp[-1].block_ptr)->block_end->next;
														(yyvsp[-1].block_ptr)->block_end = (yyvsp[-1].block_ptr)->block_end->next;
														(yyval.block_ptr) = (yyvsp[-1].block_ptr);
													}
    break;

  case 15: /* array_production: ID more_indexes  */
                                                                        {
														(yyval.one_statement) = allot_statement(DECLARATION, ARRAY, (yyvsp[-1].name), (yyvsp[0].indexing));
														// name, indexes
													}
    break;

  case 16: /* DATATYPE: INT  */
                                                                { 
	(yyval.d_type) = (enum datatype*)malloc(sizeof(enum datatype));
	*(yyval.d_type) = INT_datatype; 

}
    break;

  case 17: /* DATATYPE: FLOAT  */
                                                                { 
	(yyval.d_type) = (enum datatype*)malloc(sizeof(enum datatype));
	*(yyval.d_type) = FLOAT_datatype; }
    break;

  case 18: /* source_program: PROGRAM_BEGIN body PROGRAM_END  */
                                                {(yyval.block_ptr) = (yyvsp[-1].block_ptr);}
    break;

  case 19: /* source_program: PROGRAM_BEGIN PROGRAM_END  */
                                                                        {(yyval.block_ptr) = NULL;}
    break;

  case 20: /* body: BREAK TERMINATOR  */
                                                                        {	
													(yyval.block_ptr) = allot_block();
													(yyval.block_ptr)->block_start = allot_statement(BREAK_STATEMENT);
													(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
												}
    break;

  case 21: /* body: body BREAK TERMINATOR  */
                                                                        {	
													if((yyvsp[-2].block_ptr) == NULL){
														(yyval.block_ptr) = allot_block();
														(yyval.block_ptr)->block_start = allot_statement(BREAK_STATEMENT);;
														(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
													}else{
														(yyvsp[-2].block_ptr)->block_end->next = allot_statement(BREAK_STATEMENT);
														(yyvsp[-2].block_ptr)->block_end->next->prev = (yyvsp[-2].block_ptr)->block_end;
														(yyvsp[-2].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end->next;
														(yyval.block_ptr) = (yyvsp[-2].block_ptr);
													
													}
												}
    break;

  case 22: /* body: CONTINUE TERMINATOR  */
                                                                                {	
													(yyval.block_ptr) = allot_block();
													(yyval.block_ptr)->block_start = allot_statement(CONTINUE_STATEMENT);
													(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
												}
    break;

  case 23: /* body: body CONTINUE TERMINATOR  */
                                                                        {	
													if((yyvsp[-2].block_ptr) == NULL){
														(yyval.block_ptr) = allot_block();
														(yyval.block_ptr)->block_start = allot_statement(CONTINUE_STATEMENT);;
														(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
													}else{
														(yyvsp[-2].block_ptr)->block_end->next = allot_statement(CONTINUE_STATEMENT);
														(yyvsp[-2].block_ptr)->block_end->next->prev = (yyvsp[-2].block_ptr)->block_end;
														(yyvsp[-2].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end->next;
														(yyval.block_ptr) = (yyvsp[-2].block_ptr);
													}
												}
    break;

  case 24: /* body: TERMINATOR  */
                                                                                        {	(yyval.block_ptr) = NULL; 	}
    break;

  case 25: /* body: body TERMINATOR  */
                                                                                {	(yyval.block_ptr) = (yyvsp[-1].block_ptr);	}
    break;

  case 26: /* body: expression TERMINATOR  */
                                                                        {   
													(yyval.block_ptr) = allot_block();
													(yyval.block_ptr)->block_start = allot_statement(EXPRESSION, (yyvsp[-1].expr));
													(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
												}
    break;

  case 27: /* body: body expression TERMINATOR  */
                                                                        {  	
													if((yyvsp[-2].block_ptr) == NULL){
														(yyval.block_ptr) = allot_block();
														(yyval.block_ptr)->block_start = allot_statement(EXPRESSION, (yyvsp[-1].expr));
														(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
													}else{
														(yyvsp[-2].block_ptr)->block_end->next = allot_statement(EXPRESSION, (yyvsp[-1].expr));
														(yyvsp[-2].block_ptr)->block_end->next->prev = (yyvsp[-2].block_ptr)->block_end;
														(yyvsp[-2].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end->next;
														(yyval.block_ptr) = (yyvsp[-2].block_ptr);
													}
												}
    break;

  case 28: /* body: WRITE '(' print_values ')' TERMINATOR  */
                                                                                                        {	
																			(yyval.block_ptr) = (yyvsp[-2].block_ptr);
																		}
    break;

  case 29: /* body: body WRITE '(' print_values ')' TERMINATOR  */
                                                                                                        {  			
																			if((yyvsp[-5].block_ptr) == NULL){
																				(yyval.block_ptr) = (yyvsp[-2].block_ptr);
																			}else{
																				(yyvsp[-5].block_ptr)->block_end->next = (yyvsp[-2].block_ptr)->block_start;
																				(yyvsp[-5].block_ptr)->block_end->next->prev = (yyvsp[-5].block_ptr)->block_end;
																				(yyvsp[-5].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end;
																				(yyval.block_ptr) = (yyvsp[-5].block_ptr);
																			}
																		}
    break;

  case 30: /* body: if_statement  */
                                                                                                                                {	
																			(yyval.block_ptr) = allot_block();
																			(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																			(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																		}
    break;

  case 31: /* body: body if_statement  */
                                                                                                                                { 	
																			if((yyvsp[-1].block_ptr) == NULL){
																				(yyval.block_ptr) = allot_block();
																				(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																				(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																			}else{
																				(yyvsp[-1].block_ptr)->block_end->next = (yyvsp[0].one_statement);
																				(yyvsp[0].one_statement)->prev = (yyvsp[-1].block_ptr)->block_end;
																				(yyvsp[-1].block_ptr)->block_end = (yyvsp[0].one_statement);
																				(yyval.block_ptr) = (yyvsp[-1].block_ptr);
																			}
																		}
    break;

  case 32: /* body: for_production  */
                                                                                                                                {		
																			(yyval.block_ptr) = allot_block();
																			(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																			(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																		}
    break;

  case 33: /* body: body for_production  */
                                                                                                                                { 	
																			if((yyvsp[-1].block_ptr) == NULL){
																				(yyval.block_ptr) = allot_block();
																				(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																				(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																			}else{
																				(yyvsp[-1].block_ptr)->block_end->next = (yyvsp[0].one_statement);
																				(yyvsp[0].one_statement)->prev = (yyvsp[-1].block_ptr)->block_end;
																				(yyvsp[-1].block_ptr)->block_end = (yyvsp[0].one_statement);
																				(yyval.block_ptr) = (yyvsp[-1].block_ptr);
																			}
																		}
    break;

  case 34: /* body: while_production  */
                                                                                                                                        {
																			(yyval.block_ptr) = allot_block();
																			(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																			(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																		}
    break;

  case 35: /* body: body while_production  */
                                                                                                                        {
																			if((yyvsp[-1].block_ptr) == NULL){
																				(yyval.block_ptr) = allot_block();
																				(yyval.block_ptr)->block_start = (yyvsp[0].one_statement);
																				(yyval.block_ptr)->block_end = (yyvsp[0].one_statement);
																			}else{
																				(yyvsp[-1].block_ptr)->block_end->next = (yyvsp[0].one_statement);
																				(yyvsp[0].one_statement)->prev = (yyvsp[-1].block_ptr)->block_end;
																				(yyvsp[-1].block_ptr)->block_end = (yyvsp[0].one_statement);
																				(yyval.block_ptr) = (yyvsp[-1].block_ptr);
																			}
																		}
    break;

  case 36: /* print_values: print_values ',' expression  */
                                                                                        {	
																	(yyvsp[-2].block_ptr)->block_end->next = allot_statement(PRINT_STATEMENT, (yyvsp[0].expr));
																	(yyvsp[-2].block_ptr)->block_end->next->prev = (yyvsp[-2].block_ptr)->block_end;
																	(yyvsp[-2].block_ptr)->block_end = (yyvsp[-2].block_ptr)->block_end->next;
																	(yyval.block_ptr) = (yyvsp[-2].block_ptr);
																}
    break;

  case 37: /* print_values: expression  */
                                                                                                                        {	 	
																	(yyval.block_ptr) = allot_block();
																	(yyval.block_ptr)->block_start = allot_statement(PRINT_STATEMENT, (yyvsp[0].expr));
																	(yyval.block_ptr)->block_end = (yyval.block_ptr)->block_start;
																}
    break;

  case 38: /* if_statement: IF '(' expression ')' '{' body '}'  */
                                                                                                                        {	(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-1].block_ptr), (yyvsp[-4].expr)); }
    break;

  case 39: /* if_statement: IF '(' expression ')' '{' '}'  */
                                                                                                                                        {	(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-3].expr)); }
    break;

  case 40: /* if_statement: IF '(' expression ')' '{' body '}' ELSE '{' body '}'  */
                                                                                                                {	
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-5].block_ptr), (yyvsp[-8].expr));
																						(yyval.one_statement)->if_node->false_node = allot_if_statement_node(ELSE_TYPE, (yyvsp[-1].block_ptr));
																					}
    break;

  case 41: /* if_statement: IF '(' expression ')' '{' body '}' ELSE '{' '}'  */
                                                                                                                        {	
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-4].block_ptr), (yyvsp[-7].expr));
																						(yyval.one_statement)->if_node->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
    break;

  case 42: /* if_statement: IF '(' expression ')' '{' '}' ELSE '{' body '}'  */
                                                                                                                        {	
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-7].expr));
																						(yyval.one_statement)->if_node->false_node = allot_if_statement_node(ELSE_TYPE, (yyvsp[-1].block_ptr));
																					}
    break;

  case 43: /* if_statement: IF '(' expression ')' '{' '}' ELSE '{' '}'  */
                                                                                                                        {	
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-6].expr));
																						(yyval.one_statement)->if_node->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
    break;

  case 44: /* if_statement: IF '(' expression ')' '{' body '}' else_ifs ELSE '{' body '}'  */
                                                                                                        {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-6].block_ptr), (yyvsp[-9].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[-4].aux)->else_if_begin;
																						(yyvsp[-4].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, (yyvsp[-1].block_ptr));
																					}
    break;

  case 45: /* if_statement: IF '(' expression ')' '{' '}' else_ifs ELSE '{' body '}'  */
                                                                                                                {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-8].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[-4].aux)->else_if_begin;
																						(yyvsp[-4].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, (yyvsp[-1].block_ptr));
																					}
    break;

  case 46: /* if_statement: IF '(' expression ')' '{' body '}' else_ifs ELSE '{' '}'  */
                                                                                                                {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-5].block_ptr), (yyvsp[-8].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[-3].aux)->else_if_begin;
																						(yyvsp[-3].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
    break;

  case 47: /* if_statement: IF '(' expression ')' '{' '}' else_ifs ELSE '{' '}'  */
                                                                                                                {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-7].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[-3].aux)->else_if_begin;
																						(yyvsp[-3].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_TYPE, NULL);
																					}
    break;

  case 48: /* if_statement: IF '(' expression ')' '{' body '}' else_ifs  */
                                                                                                                        {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, (yyvsp[-2].block_ptr), (yyvsp[-5].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[0].aux)->else_if_begin;
																					}
    break;

  case 49: /* if_statement: IF '(' expression ')' '{' '}' else_ifs  */
                                                                                                                                {
																						(yyval.one_statement) = allot_statement(IF_STATEMENT, NULL, (yyvsp[-4].expr));
																						(yyval.one_statement)->if_node->false_node = (yyvsp[0].aux)->else_if_begin;
																					}
    break;

  case 50: /* else_ifs: ELSE IF '(' expression ')' '{' body '}'  */
                                                                                                                        {
																						(yyval.aux) = (struct else_if_helper*)malloc(sizeof(struct else_if_helper));
																						(yyval.aux)->else_if_begin = allot_if_statement_node(ELSE_IF_TYPE, (yyvsp[-1].block_ptr), (yyvsp[-4].expr));
																						(yyval.aux)->else_if_end = (yyval.aux)->else_if_begin;
																					}
    break;

  case 51: /* else_ifs: ELSE IF '(' expression ')' '{' '}'  */
                                                                                                                                        {
																						(yyval.aux) = (struct else_if_helper*)malloc(sizeof(struct else_if_helper));
																						(yyval.aux)->else_if_begin = allot_if_statement_node(ELSE_IF_TYPE, NULL, (yyvsp[-3].expr));
																						(yyval.aux)->else_if_end = (yyval.aux)->else_if_begin;
																					}
    break;

  case 52: /* else_ifs: else_ifs ELSE IF '(' expression ')' '{' body '}'  */
                                                                                                                        {	
																						(yyvsp[-8].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_IF_TYPE, (yyvsp[-1].block_ptr), (yyvsp[-4].expr));
																						(yyvsp[-8].aux)->else_if_end = (yyvsp[-8].aux)->else_if_end->false_node;
																						(yyval.aux) = (yyvsp[-8].aux);	
																					}
    break;

  case 53: /* else_ifs: else_ifs ELSE IF '(' expression ')' '{' '}'  */
                                                                                                                        {	
																						(yyvsp[-7].aux)->else_if_end->false_node = allot_if_statement_node(ELSE_IF_TYPE, NULL, (yyvsp[-3].expr));
																						(yyvsp[-7].aux)->else_if_end = (yyvsp[-7].aux)->else_if_end->false_node;
																						(yyval.aux) = (yyvsp[-7].aux);	
																					}
    break;

  case 54: /* expression: '(' expression ')'  */
                                                                                        { 	(yyval.expr) = (yyvsp[-1].expr); 					}
    break;

  case 55: /* expression: '-' expression  */
                                                                                                {	
																	(yyval.expr) = allot_expression_node(UNARY_MINUS, (yyvsp[0].expr));
																	/* storing expression as right child */
																}
    break;

  case 56: /* expression: l_value '=' expression  */
                                                                                                        { (yyval.expr) = allot_expression_node(ASSIGN, (yyvsp[-2].expr), (yyvsp[0].expr)); }
    break;

  case 57: /* expression: l_value  */
                                                                                                                        { (yyval.expr) = (yyvsp[0].expr); }
    break;

  case 58: /* expression: INT_NUMBER  */
                                                                                                                        {					
																	(yyval.expr) = allot_expression_node(NUM, (yyvsp[0].int_value));
																}
    break;

  case 59: /* expression: FLOAT_NUMBER  */
                                                                                                                {					
																	(yyval.expr) = allot_expression_node(FLOAT_NUM, (yyvsp[0].float_value));
																}
    break;

  case 60: /* expression: expression '+' expression  */
                                                                                                        {	(yyval.expr) = allot_expression_node(PLUS, (yyvsp[-2].expr), (yyvsp[0].expr)); 			}
    break;

  case 61: /* expression: expression '-' expression  */
                                                                                                        {	(yyval.expr) = allot_expression_node(MINUS, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 62: /* expression: expression '*' expression  */
                                                                                                        {	(yyval.expr) = allot_expression_node(MUL, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 63: /* expression: expression '/' expression  */
                                                                                                        {	(yyval.expr) = allot_expression_node(DIV, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 64: /* expression: expression '%' expression  */
                                                                                                        {	(yyval.expr) = allot_expression_node(MOD, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 65: /* expression: expression GREATER_THAN expression  */
                                                                                                {	(yyval.expr) = allot_expression_node(GT, (yyvsp[-2].expr), (yyvsp[0].expr));				}
    break;

  case 66: /* expression: expression GREATER_THAN_OR_EQUAL_TO expression  */
                                                                                {	(yyval.expr) = allot_expression_node(GTEQ, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 67: /* expression: expression LESS_THAN expression  */
                                                                                                {	(yyval.expr) = allot_expression_node(LT, (yyvsp[-2].expr), (yyvsp[0].expr));				}
    break;

  case 68: /* expression: expression LESS_THAN_OR_EQUAL_TO expression  */
                                                                                {	(yyval.expr) = allot_expression_node(LTEQ, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 69: /* expression: expression IS_EQUAL expression  */
                                                                                                {	(yyval.expr) = allot_expression_node(EQEQ, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 70: /* expression: expression IS_NOT_EQUAL expression  */
                                                                                                {	(yyval.expr) = allot_expression_node(NTEQ, (yyvsp[-2].expr), (yyvsp[0].expr));			}
    break;

  case 71: /* expression: PLUS_PLUS l_value  */
                                                                                                {	(yyval.expr) = allot_expression_node(PRE_INCREMENT, (yyvsp[0].expr)); 	}
    break;

  case 72: /* expression: MINUS_MINUS l_value  */
                                                                                {	(yyval.expr) = allot_expression_node(PRE_DECREMENT, (yyvsp[0].expr)); 	}
    break;

  case 73: /* expression: l_value PLUS_PLUS  */
                                                                                        {	(yyval.expr) = allot_expression_node(POST_INCREMENT, (yyvsp[-1].expr)); }
    break;

  case 74: /* expression: l_value MINUS_MINUS  */
                                                                                        {	(yyval.expr) = allot_expression_node(POST_DECREMENT, (yyvsp[-1].expr)); }
    break;

  case 75: /* l_value: ID  */
                                                                { (yyval.expr) = allot_expression_node(VAR, lookup((yyvsp[0].name), VARIABLE));			 }
    break;

  case 76: /* l_value: ID more_indexes  */
                                                        { (yyval.expr) = allot_expression_node(ARRAY_LOC, lookup((yyvsp[-1].name), ARRAY, (yyvsp[0].indexing)), (yyvsp[0].indexing));  }
    break;

  case 77: /* more_indexes: '[' expression ']'  */
                                                                                { 
															(yyval.indexing) = (struct indexes*)malloc(sizeof(struct indexes));
															(yyval.indexing)->index = (yyvsp[-1].expr);
															(yyval.indexing)->next = NULL;
														}
    break;

  case 78: /* more_indexes: '[' expression ']' more_indexes  */
                                                                                {
															(yyval.indexing) = (struct indexes*)malloc(sizeof(struct indexes));
															(yyval.indexing)->index = (yyvsp[-2].expr);
															(yyval.indexing)->next = (yyvsp[0].indexing);
														}
    break;

  case 79: /* while_production: WHILE '(' expression ')' '{' '}'  */
                                                                                                { (yyval.one_statement) = allot_statement(WHILE_STATEMENT, (yyvsp[-3].expr), NULL); }
    break;

  case 80: /* while_production: WHILE '(' expression ')' '{' body '}'  */
                                                                                                        { (yyval.one_statement) = allot_statement(WHILE_STATEMENT, (yyvsp[-4].expr), (yyvsp[-1].block_ptr)); }
    break;

  case 81: /* for_production: FOR '(' expression TERMINATOR expression TERMINATOR expression ')' '{' body '}'  */
                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-8].expr), (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-1].block_ptr)); }
    break;

  case 82: /* for_production: FOR '(' TERMINATOR expression TERMINATOR expression ')' '{' body '}'  */
                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, (yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-1].block_ptr)); }
    break;

  case 83: /* for_production: FOR '(' expression TERMINATOR TERMINATOR expression ')' '{' body '}'  */
                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-7].expr), NULL, (yyvsp[-4].expr), (yyvsp[-1].block_ptr)); }
    break;

  case 84: /* for_production: FOR '(' expression TERMINATOR expression TERMINATOR ')' '{' body '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-7].expr), (yyvsp[-5].expr), NULL, (yyvsp[-1].block_ptr)); }
    break;

  case 85: /* for_production: FOR '(' expression TERMINATOR expression TERMINATOR expression ')' '{' '}'  */
                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-7].expr), (yyvsp[-5].expr), (yyvsp[-3].expr), NULL); }
    break;

  case 86: /* for_production: FOR '(' TERMINATOR TERMINATOR expression ')' '{' body '}'  */
                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, NULL, (yyvsp[-4].expr), (yyvsp[-1].block_ptr)); }
    break;

  case 87: /* for_production: FOR '(' TERMINATOR expression TERMINATOR ')' '{' body '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, (yyvsp[-5].expr), NULL, (yyvsp[-1].block_ptr)); }
    break;

  case 88: /* for_production: FOR '(' TERMINATOR expression TERMINATOR expression ')' '{' '}'  */
                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, (yyvsp[-5].expr), (yyvsp[-3].expr), NULL); }
    break;

  case 89: /* for_production: FOR '(' expression TERMINATOR TERMINATOR ')' '{' body '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-6].expr), NULL, NULL, (yyvsp[-1].block_ptr)); }
    break;

  case 90: /* for_production: FOR '(' expression TERMINATOR TERMINATOR expression ')' '{' '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-6].expr), NULL, (yyvsp[-3].expr), NULL); }
    break;

  case 91: /* for_production: FOR '(' expression TERMINATOR expression TERMINATOR ')' '{' '}'  */
                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-6].expr), (yyvsp[-4].expr), NULL, NULL); }
    break;

  case 92: /* for_production: FOR '(' expression TERMINATOR TERMINATOR ')' '{' '}'  */
                                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, (yyvsp[-5].expr), NULL, NULL, NULL); }
    break;

  case 93: /* for_production: FOR '(' TERMINATOR expression TERMINATOR ')' '{' '}'  */
                                                                                                                                                                        { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, (yyvsp[-4].expr), NULL, NULL); }
    break;

  case 94: /* for_production: FOR '(' TERMINATOR TERMINATOR expression ')' '{' '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, NULL, (yyvsp[-3].expr), NULL); }
    break;

  case 95: /* for_production: FOR '(' TERMINATOR TERMINATOR ')' '{' body '}'  */
                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, NULL, NULL, (yyvsp[-1].block_ptr)); }
    break;

  case 96: /* for_production: FOR '(' TERMINATOR TERMINATOR ')' '{' '}'  */
                                                                                                                                                                                { 	(yyval.one_statement) = allot_statement(FOR_STATEMENT, NULL, NULL, NULL, NULL); }
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}



int main(int argc, char* argv[]){
	if(argc >= 2){
		FILE* fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("File did not open\n");
			return 1; 	// failure
		}
		yyin = fp;
	}
	yyparse();
	printSymbolTable();
	// printSequence();
	char *tabs = malloc(sizeof(char)); 
	printf("\n--------Syntax tree--------\n");
	print_root(root, tabs);
	return 0;
}	

int yywrap(){
	return 1;
}

void yyerror(char* msg){
//	printf("yytext = %s, Line number = %d, %s\n", yytext, lineno, msg);
	printf("Line number = %d, %s\n", lineno, msg);
	exit(1); // failure
}

// if if else ambigiuity we need to see 
// initializations are not allowed in declaration_block
// how to handle the issue of a body being emty

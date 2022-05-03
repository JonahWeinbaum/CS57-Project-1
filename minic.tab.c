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
#line 1 "minic.y"

  #include "ast_c/ast.h"
  #include "hash/hashtable.h"

  //Yacc Parameters
  extern int yylex(void);
  extern FILE *yyin;
  extern int yy_flex_debug;
  extern void yyerror(char *s) {}

  //Global Variables
  hashtable_t *var_decs;
  hashtable_t *fnc_decs;

  //Root note
  astNode* root;

#line 89 "minic.tab.c"

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

#include "minic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_VOID = 4,                       /* VOID  */
  YYSYMBOL_EXTERN = 5,                     /* EXTERN  */
  YYSYMBOL_RET = 6,                        /* RET  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_ADD = 8,                        /* ADD  */
  YYSYMBOL_SUB = 9,                        /* SUB  */
  YYSYMBOL_MULT = 10,                      /* MULT  */
  YYSYMBOL_DIV = 11,                       /* DIV  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_EQEQ = 15,                      /* EQEQ  */
  YYSYMBOL_GEQ = 16,                       /* GEQ  */
  YYSYMBOL_LEQ = 17,                       /* LEQ  */
  YYSYMBOL_LESS = 18,                      /* LESS  */
  YYSYMBOL_GREAT = 19,                     /* GREAT  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_LBRACK = 21,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 22,                    /* RBRACK  */
  YYSYMBOL_LPAR = 23,                      /* LPAR  */
  YYSYMBOL_RPAR = 24,                      /* RPAR  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NUM = 27,                       /* NUM  */
  YYSYMBOL_NAME = 28,                      /* NAME  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_file = 30,                      /* file  */
  YYSYMBOL_fnc_decs = 31,                  /* fnc_decs  */
  YYSYMBOL_fnc_dec = 32,                   /* fnc_dec  */
  YYSYMBOL_param_decs = 33,                /* param_decs  */
  YYSYMBOL_param_dec = 34,                 /* param_dec  */
  YYSYMBOL_fncs = 35,                      /* fncs  */
  YYSYMBOL_fnc = 36,                       /* fnc  */
  YYSYMBOL_var_decs = 37,                  /* var_decs  */
  YYSYMBOL_var_dec = 38,                   /* var_dec  */
  YYSYMBOL_codeblocks = 39,                /* codeblocks  */
  YYSYMBOL_code = 40,                      /* code  */
  YYSYMBOL_assignment = 41,                /* assignment  */
  YYSYMBOL_expr = 42,                      /* expr  */
  YYSYMBOL_bin_expr = 43,                  /* bin_expr  */
  YYSYMBOL_unr_expr = 44,                  /* unr_expr  */
  YYSYMBOL_fnc_call = 45,                  /* fnc_call  */
  YYSYMBOL_if = 46,                        /* if  */
  YYSYMBOL_else = 47,                      /* else  */
  YYSYMBOL_ifelse = 48,                    /* ifelse  */
  YYSYMBOL_while = 49,                     /* while  */
  YYSYMBOL_params = 50,                    /* params  */
  YYSYMBOL_conditional = 51,               /* conditional  */
  YYSYMBOL_comparator = 52,                /* comparator  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_ret = 54                        /* ret  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   121,   126,   127,   131,   132,   133,   134,
     138,   139,   148,   149,   154,   155,   159,   163,   173,   174,
     178,   183,   184,   188,   189,   190,   191,   192,   193,   199,
     206,   213,   217,   218,   219,   220,   224,   228,   232,   236,
     242,   248,   256,   262,   270,   276,   282,   285,   291,   292,
     302,   308,   309,   310,   311,   312,   313,   318,   319,   323,
     324
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "VOID",
  "EXTERN", "RET", "WHILE", "ADD", "SUB", "MULT", "DIV", "IF", "ELSE",
  "SEMI", "EQEQ", "GEQ", "LEQ", "LESS", "GREAT", "NEQ", "LBRACK", "RBRACK",
  "LPAR", "RPAR", "COMMA", "EQ", "NUM", "NAME", "$accept", "file",
  "fnc_decs", "fnc_dec", "param_decs", "param_dec", "fncs", "fnc",
  "var_decs", "var_dec", "codeblocks", "code", "assignment", "expr",
  "bin_expr", "unr_expr", "fnc_call", "if", "else", "ifelse", "while",
  "params", "conditional", "comparator", "type", "ret", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -29,   -29,     2,    21,    74,   -13,    74,   -29,    44,
      60,   -29,    40,    74,   -29,    46,    76,   -29,    77,    81,
     -29,     1,    90,    28,    91,     1,   -29,    -6,    46,   101,
     119,   -29,   106,   124,   -29,   -29,   -29,   108,   -29,   -29,
      94,   113,    10,    12,   107,   153,     1,     1,   -29,     1,
      33,    -5,     1,   115,   119,   -29,   -29,   122,   -29,     1,
       1,     1,     1,   -29,   116,   -29,   -29,   -29,   -29,     6,
     -29,   111,   -29,    42,   140,   117,    75,   120,   -29,   -29,
     153,    82,   153,   -29,   126,   121,    99,    99,   -29,   -29,
     119,   -29,     2,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,     1,   131,   -29,   132,   -29,     1,   123,   -29,    53,
     -29,   153,   119,   119,   153,   -29,   -29,    89,    96,   -29,
     -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    57,    58,     0,     0,     0,     0,     2,    14,     0,
       0,     1,     0,     3,     4,     0,     0,    15,     0,     0,
       5,    59,     0,     0,     0,     0,    31,    30,     0,     0,
       0,    21,     0,     0,    32,    33,    34,    25,    26,    27,
       0,     0,     0,     0,    30,    60,     0,     0,    40,     0,
       0,     0,     0,     0,     0,    18,    22,     0,    24,     0,
       0,     0,     0,    23,     0,    46,    20,    28,     9,     0,
      10,    12,     8,     0,     0,     0,     0,     0,    35,    42,
      48,     0,    29,    19,     0,    28,    36,    37,    38,    39,
       0,     7,     0,    13,     6,    51,    53,    54,    56,    55,
      52,     0,     0,    41,     0,    43,     0,    28,    16,     0,
      11,    50,     0,     0,    49,    17,    45,     0,     0,    47,
      44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   -29,   -29,    63,   125,    62,   160,    57,   -29,   138,
     -19,   -27,   -29,   -14,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   118,   -29,    -3,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    16,    69,    70,     7,     8,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    65,    38,
      39,    81,    75,   101,     9,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      10,    14,    57,    56,    23,     1,     2,    45,    15,    54,
      23,    50,    40,     1,     2,     1,     2,    51,    25,    79,
      52,    11,    26,    44,    25,    40,    84,    56,    26,    44,
      91,    92,    74,    76,    68,    74,    72,    80,    82,    71,
      71,    59,    60,    61,    62,    86,    87,    88,    89,     1,
       2,    47,    21,    22,    20,    23,    48,    78,    24,    21,
      22,    15,    23,     6,    17,    24,    94,    92,    12,    25,
      17,   109,    18,    26,    27,   116,    25,     1,     2,     3,
      26,    27,    56,    59,    60,    61,    62,   111,    19,    71,
      56,    56,   114,   117,   118,    21,    22,    15,    23,   103,
      42,    24,    21,    22,    43,    23,   105,   106,    24,    61,
      62,   119,    25,    46,    49,    55,    26,    27,   120,    25,
      58,    64,    66,    26,    27,    21,    22,    67,    23,    83,
      51,    24,    59,    60,    61,    62,    85,    90,    63,    93,
     107,   102,    25,   108,   104,   115,    26,    27,    59,    60,
      61,    62,   112,   113,   110,    95,    96,    97,    98,    99,
     100,    59,    60,    61,    62,    13,    53,    77,    73
};

static const yytype_int8 yycheck[] =
{
       3,    14,    30,    30,     9,     3,     4,    21,    21,    28,
       9,    25,    15,     3,     4,     3,     4,    23,    23,    24,
      26,     0,    27,    28,    23,    28,    54,    54,    27,    28,
      24,    25,    46,    47,    24,    49,    24,    51,    52,    42,
      43,     8,     9,    10,    11,    59,    60,    61,    62,     3,
       4,    23,     6,     7,    14,     9,    28,    24,    12,     6,
       7,    21,     9,     0,     7,    12,    24,    25,     5,    23,
      13,    90,    28,    27,    28,    22,    23,     3,     4,     5,
      27,    28,   109,     8,     9,    10,    11,   101,    28,    92,
     117,   118,   106,   112,   113,     6,     7,    21,     9,    24,
      23,    12,     6,     7,    23,     9,    24,    25,    12,    10,
      11,    22,    23,    23,    23,    14,    27,    28,    22,    23,
      14,    13,    28,    27,    28,     6,     7,    14,     9,    14,
      23,    12,     8,     9,    10,    11,    14,    21,    14,    28,
      14,    24,    23,    22,    24,    22,    27,    28,     8,     9,
      10,    11,    21,    21,    92,    15,    16,    17,    18,    19,
      20,     8,     9,    10,    11,     5,    28,    49,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    30,    31,    32,    35,    36,    53,
      53,     0,    32,    35,    14,    21,    32,    36,    28,    28,
      14,     6,     7,     9,    12,    23,    27,    28,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      53,    54,    23,    23,    28,    42,    23,    23,    28,    23,
      42,    23,    26,    38,    39,    14,    40,    54,    14,     8,
       9,    10,    11,    14,    13,    47,    28,    14,    24,    33,
      34,    53,    24,    33,    42,    51,    42,    51,    24,    24,
      42,    50,    42,    14,    54,    14,    42,    42,    42,    42,
      21,    24,    25,    28,    24,    15,    16,    17,    18,    19,
      20,    52,    24,    24,    24,    24,    25,    14,    22,    39,
      34,    42,    21,    21,    42,    22,    22,    39,    39,    22,
      22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    32,    32,    32,    32,
      33,    33,    34,    34,    35,    35,    36,    36,    37,    37,
      38,    39,    39,    40,    40,    40,    40,    40,    40,    41,
      42,    42,    42,    42,    42,    42,    43,    43,    43,    43,
      44,    44,    45,    45,    46,    47,    48,    49,    50,    50,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     6,     5,     5,     4,
       1,     3,     1,     2,     1,     2,     6,     7,     2,     3,
       2,     1,     2,     2,     2,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       2,     4,     3,     4,     7,     4,     2,     7,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2
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
  case 6: /* fnc_dec: EXTERN type NAME LPAR param_decs RPAR  */
#line 131 "minic.y"
                                               {fnc_dec(fnc_decs, (yyvsp[-3].str_val), (yyvsp[-4].type_val), (yyvsp[-1].params_val));}
#line 1215 "minic.tab.c"
    break;

  case 7: /* fnc_dec: type NAME LPAR param_decs RPAR  */
#line 132 "minic.y"
                                               {fnc_dec(fnc_decs, (yyvsp[-3].str_val), (yyvsp[-4].type_val), (yyvsp[-1].params_val));}
#line 1221 "minic.tab.c"
    break;

  case 8: /* fnc_dec: EXTERN type NAME LPAR RPAR  */
#line 133 "minic.y"
                                               {params_t param; fnc_dec(fnc_decs, (yyvsp[-2].str_val), (yyvsp[-3].type_val),  param);}
#line 1227 "minic.tab.c"
    break;

  case 9: /* fnc_dec: type NAME LPAR RPAR  */
#line 134 "minic.y"
                                               {params_t param; fnc_dec(fnc_decs, (yyvsp[-2].str_val), (yyvsp[-3].type_val),  param);}
#line 1233 "minic.tab.c"
    break;

  case 10: /* param_decs: param_dec  */
#line 138 "minic.y"
                                        {(yyval.params_val).params[(yyval.params_val).size++] = (yyvsp[0].type_val);}
#line 1239 "minic.tab.c"
    break;

  case 11: /* param_decs: param_decs COMMA param_dec  */
#line 139 "minic.y"
                                        {
                                          for (int i = 0; i < (yyvsp[-2].params_val).size; i++) {
                                            (yyval.params_val).params[i] = (yyvsp[-2].params_val).params[i];
                                          }
                                          (yyval.params_val).size = (yyvsp[-2].params_val).size;
                                          (yyval.params_val).params[(yyval.params_val).size++] = (yyvsp[0].type_val);
                                        }
#line 1251 "minic.tab.c"
    break;

  case 12: /* param_dec: type  */
#line 148 "minic.y"
                     {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1257 "minic.tab.c"
    break;

  case 13: /* param_dec: type NAME  */
#line 149 "minic.y"
                     {(yyval.type_val) = (yyvsp[-1].type_val); var_dec(var_decs, (yyvsp[0].str_val), (yyvsp[-1].type_val));}
#line 1263 "minic.tab.c"
    break;

  case 20: /* var_dec: type NAME  */
#line 178 "minic.y"
                   { var_dec(var_decs, (yyvsp[0].str_val), (yyvsp[-1].type_val));}
#line 1269 "minic.tab.c"
    break;

  case 29: /* assignment: NAME EQ expr  */
#line 199 "minic.y"
                        {
                          var_dec_check(var_decs, (yyvsp[-2].str_val));
                          createAsgn(createVar((yyvsp[-2].str_val)), (yyvsp[0].expr_val).node);
                        }
#line 1278 "minic.tab.c"
    break;

  case 30: /* expr: NAME  */
#line 206 "minic.y"
            { 
              if (var_dec_check(var_decs, (yyvsp[0].str_val))) 
              {
                (yyval.expr_val).type = *(type_t*)hashtable_find(var_decs, (yyvsp[0].str_val));
              }
              (yyval.expr_val).node = createVar((yyvsp[0].str_val));
            }
#line 1290 "minic.tab.c"
    break;

  case 31: /* expr: NUM  */
#line 213 "minic.y"
            { 
              (yyval.expr_val).type = INT_TYPE;
              (yyval.expr_val).node  = createCnst((yyvsp[0].num_val)); 
            }
#line 1299 "minic.tab.c"
    break;

  case 32: /* expr: bin_expr  */
#line 217 "minic.y"
                { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1305 "minic.tab.c"
    break;

  case 33: /* expr: unr_expr  */
#line 218 "minic.y"
                { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1311 "minic.tab.c"
    break;

  case 34: /* expr: fnc_call  */
#line 219 "minic.y"
                { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1317 "minic.tab.c"
    break;

  case 35: /* expr: LPAR expr RPAR  */
#line 220 "minic.y"
                      { (yyval.expr_val) = (yyvsp[-1].expr_val); }
#line 1323 "minic.tab.c"
    break;

  case 36: /* bin_expr: expr ADD expr  */
#line 224 "minic.y"
                         { type_check((yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type);
                           (yyval.expr_val).type = INT_TYPE;
                           (yyval.expr_val).node = createBExpr((yyvsp[-2].expr_val).node, (yyvsp[0].expr_val).node, (yyvsp[-1].op_val));
                         }
#line 1332 "minic.tab.c"
    break;

  case 37: /* bin_expr: expr SUB expr  */
#line 228 "minic.y"
                         { type_check((yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type);
                           (yyval.expr_val).type = INT_TYPE;
                           (yyval.expr_val).node = createBExpr((yyvsp[-2].expr_val).node, (yyvsp[0].expr_val).node, (yyvsp[-1].op_val));
                         }
#line 1341 "minic.tab.c"
    break;

  case 38: /* bin_expr: expr MULT expr  */
#line 232 "minic.y"
                         { type_check((yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type);
                           (yyval.expr_val).type = INT_TYPE;
                           (yyval.expr_val).node = createBExpr((yyvsp[-2].expr_val).node, (yyvsp[0].expr_val).node, (yyvsp[-1].op_val));
                         }
#line 1350 "minic.tab.c"
    break;

  case 39: /* bin_expr: expr DIV expr  */
#line 236 "minic.y"
                         { type_check((yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type);
                           (yyval.expr_val).type = INT_TYPE;
                           (yyval.expr_val).node = createBExpr((yyvsp[-2].expr_val).node, (yyvsp[0].expr_val).node, (yyvsp[-1].op_val));
                         }
#line 1359 "minic.tab.c"
    break;

  case 40: /* unr_expr: SUB NAME  */
#line 242 "minic.y"
                   { 
                     if (var_dec_check(var_decs, (yyvsp[0].str_val))) {
                       (yyval.expr_val).type = *(type_t*)hashtable_find(var_decs, (yyvsp[0].str_val));
                     }
                     (yyval.expr_val).node = createUExpr(createVar((yyvsp[0].str_val)), (yyvsp[-1].op_val));
                   }
#line 1370 "minic.tab.c"
    break;

  case 41: /* unr_expr: SUB LPAR expr RPAR  */
#line 248 "minic.y"
                             { 
                               (yyval.expr_val).type = (yyvsp[-1].expr_val).type;
                               (yyval.expr_val).node = createUExpr((yyvsp[-1].expr_val).node, (yyvsp[-3].op_val));
                             }
#line 1379 "minic.tab.c"
    break;

  case 42: /* fnc_call: NAME LPAR RPAR  */
#line 256 "minic.y"
                         { params_t params; params.size = 0; 
                           if (fnc_dec_check(fnc_decs, (yyvsp[-2].str_val), params)) {
                            (yyval.expr_val).type = (*(fnc_dec_t*)hashtable_find(fnc_decs, (yyvsp[-2].str_val))).ret_type;
                           }
                           (yyval.expr_val).node = createCall((yyvsp[-2].str_val), NULL);
                         }
#line 1390 "minic.tab.c"
    break;

  case 43: /* fnc_call: NAME LPAR params RPAR  */
#line 262 "minic.y"
                                { if (fnc_dec_check(fnc_decs, (yyvsp[-3].str_val), (yyvsp[-1].params_val))) {
                                    (yyval.expr_val).type = (*(fnc_dec_t*)hashtable_find(fnc_decs, (yyvsp[-3].str_val))).ret_type;
                                  } 
                                  (yyval.expr_val).node = createCall((yyvsp[-3].str_val), NULL);
                                }
#line 1400 "minic.tab.c"
    break;

  case 48: /* params: expr  */
#line 291 "minic.y"
             {(yyval.params_val).params[(yyval.params_val).size++] = (yyvsp[0].expr_val).type;}
#line 1406 "minic.tab.c"
    break;

  case 49: /* params: params COMMA expr  */
#line 292 "minic.y"
                          {
                            for (int i = 0; i < (yyvsp[-2].params_val).size; i++) {
                              (yyval.params_val).params[i] = (yyvsp[-2].params_val).params[i];
                            }
                            (yyval.params_val).size = (yyvsp[-2].params_val).size;
                            (yyval.params_val).params[(yyval.params_val).size++] = (yyvsp[0].expr_val).type;
                          }
#line 1418 "minic.tab.c"
    break;

  case 50: /* conditional: expr comparator expr  */
#line 302 "minic.y"
                                  { type_check((yyvsp[-2].expr_val).type, (yyvsp[0].expr_val).type);
                                    (yyval.expr_val).node = createRExpr((yyvsp[-2].expr_val).node, (yyvsp[0].expr_val).node, (yyvsp[-1].rop_val));
                                  }
#line 1426 "minic.tab.c"
    break;

  case 51: /* comparator: EQEQ  */
#line 308 "minic.y"
                  {(yyval.rop_val) = eq;}
#line 1432 "minic.tab.c"
    break;

  case 52: /* comparator: NEQ  */
#line 309 "minic.y"
                  {(yyval.rop_val) = neq;}
#line 1438 "minic.tab.c"
    break;

  case 53: /* comparator: GEQ  */
#line 310 "minic.y"
                  {(yyval.rop_val) = ge;}
#line 1444 "minic.tab.c"
    break;

  case 54: /* comparator: LEQ  */
#line 311 "minic.y"
                  {(yyval.rop_val) = le;}
#line 1450 "minic.tab.c"
    break;

  case 55: /* comparator: GREAT  */
#line 312 "minic.y"
                  {(yyval.rop_val) = gt;}
#line 1456 "minic.tab.c"
    break;

  case 56: /* comparator: LESS  */
#line 313 "minic.y"
                  {(yyval.rop_val) = lt;}
#line 1462 "minic.tab.c"
    break;

  case 57: /* type: INT  */
#line 318 "minic.y"
           {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1468 "minic.tab.c"
    break;

  case 58: /* type: VOID  */
#line 319 "minic.y"
           {(yyval.type_val) = (yyvsp[0].type_val);}
#line 1474 "minic.tab.c"
    break;


#line 1478 "minic.tab.c"

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

#line 327 "minic.y"


void var_dec(hashtable_t* var_decs, char *var_name, type_t var_type) {
  if (hashtable_find(var_decs, var_name)) {
    fprintf(stderr, "<ERROR> Variable \'%s\' was previously declared.\n", var_name);
    return;
  }
  
  type_t *new_var = (type_t*)malloc(sizeof(type_t));
 *new_var = var_type;
  hashtable_insert(var_decs, var_name, new_var); 
}

bool var_dec_check(hashtable_t* var_decs, char *var_name) {
  if(!(hashtable_find(var_decs, var_name))) { 
    fprintf(stderr, "<ERROR> Variable \'%s\' was not declared.\n", var_name); 
    return false;
  } 
  return true;
}

void fnc_dec(hashtable_t* fnc_decs, char *fnc_name, type_t ret_type, params_t param_list) {
  if (hashtable_find(fnc_decs, fnc_name)) {
    fprintf(stderr, "<ERROR> Function \'%s\' was previously declared.\n", fnc_name);
    return;
  }
  fnc_dec_t *fnc_dec = (fnc_dec_t*)malloc(sizeof(fnc_dec_t));
  fnc_dec->ret_type = ret_type;
  for (int i = 0; i < param_list.size; i++) {
    fnc_dec->param_list.params[i] = param_list.params[i];
  }
  fnc_dec->param_list.size = param_list.size;

  hashtable_insert(fnc_decs, fnc_name, fnc_dec); 
}

bool fnc_dec_check(hashtable_t* fnc_decs, char *fnc_name, params_t params) {
  if(!(hashtable_find(fnc_decs, fnc_name))) { 
    fprintf(stderr, "<ERROR> Function \'%s\' was not declared.\n", fnc_name); 
    return false;
  }  

  bool params_match = true;
  params_t function_params = ((fnc_dec_t*)hashtable_find(fnc_decs, fnc_name))->param_list;
   for (int i = 0; i < function_params.size; i++) {
      if (function_params.params[i] != params.params[i]) {
        params_match = false;
    }
  }

  if (!params_match) {
    fprintf(stderr, "<ERROR> Function parameters in \'%s\' are mismatched.\n", fnc_name); 
    return false;
  }

  return true;
}

bool type_check(type_t expr1, type_t expr2) {
  if (expr1 != INT_TYPE || expr2 != INT_TYPE) {
    fprintf(stderr, "<ERROR> Trying to perform arithmetic or comparison operation on non-integer type.\n");
    return false;
  }
  return true;
}

bool assignment_check(hashtable_t* var_decs, char* var, type_t expr2) {
  if(*(type_t*)hashtable_find(var_decs, var) != expr2) {
    fprintf(stderr, "<ERROR> Left hand side type does not match right hand side of expression.\n");
    return false;
  }
  return true;
}

void varprint(FILE* fp, const char* key, void* item)
{
  fprintf(fp, "%s - %s", key, *(type_t*)item == 0 ? "INT" : "VOID");
}

void fncprint(FILE* fp, const char* key, void* item)
{
  fprintf(fp, "\n%s - ret_type = %s\n Parameters are: \n", key, *(int*)item == 0 ? "INT" : "VOID");
  for (int i = 0; i < (*(fnc_dec_t*)item).param_list.size; i++) {
    fprintf(fp, "   Parameter %d has type %s\n", i, (*(fnc_dec_t*)item).param_list.params[i] == 0 ? "INT" : "VOID"); 
  }
}

int main (int argc, char **argv)
{
        //Turn off bison debugging
        yy_flex_debug = 0;

        //Handle arguments
        ++argv, --argc; /* skip over program name */ 
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" ); 
        else
                yyin = stdin;

        //Hashtable to store function declarations
        fnc_decs = hashtable_new(MAX_VAR_DECS);
        var_decs = hashtable_new(MAX_VAR_DECS);
        root = (astNode*)malloc(sizeof(astNode));

        //Parse input
        yyparse();

        printNode(root, 0);

        return 0;
}
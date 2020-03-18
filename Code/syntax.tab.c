/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "./syntax.y" /* yacc.c:339  */

	#include "lex.yy.c"
	#include "tree.h"
	#define ERROR(line, info) printf("Error type B at Line %d: %s.\n",line, info);setError();

#line 72 "./syntax.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    ID = 260,
    SEMI = 261,
    COMMA = 262,
    TYPE = 263,
    STRUCT = 264,
    RETURN = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    ASSIGNOP = 269,
    OR = 270,
    AND = 271,
    RELOP = 272,
    MINUS = 273,
    PLUS = 274,
    DIV = 275,
    STAR = 276,
    NOT = 277,
    UMINUS = 278,
    DOT = 279,
    LB = 280,
    RB = 281,
    LP = 282,
    RP = 283,
    LC = 284,
    RC = 285,
    LOWER_THAN_ELSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 169 "./syntax.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    24,    24,    31,    35,    40,    45,    49,    54,    56,
      58,    60,    62,    64,    69,    72,    77,    79,    84,    87,
      93,   100,   104,   106,   108,   113,   116,   121,   127,   130,
     136,   138,   140,   142,   147,   153,   158,   163,   168,   171,
     176,   180,   185,   191,   196,   200,   202,   207,   211,   214,
     219,   226,   235,   242,   244,   246,   248,   250,   252,   254,
     256,   258,   260,   265,   269,   274,   279,   284,   287,   292,
     297,   300,   305,   307,   312,   317,   322,   327,   332,   337,
     342,   347,   352,   357,   359,   362,   366,   370,   376,   378,
     381,   386,   392,   394,   397,   402,   405,   408,   411,   417,
     422,   425,   427
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "SEMI", "COMMA",
  "TYPE", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "ASSIGNOP", "OR",
  "AND", "RELOP", "MINUS", "PLUS", "DIV", "STAR", "NOT", "UMINUS", "DOT",
  "LB", "RB", "LP", "RP", "LC", "RC", "LOWER_THAN_ELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     342,   141,   -84,     6,     2,   -84,   342,   226,   -84,    52,
      66,   -84,    92,   199,   130,   360,   148,   186,   -84,   -84,
     -84,   157,   -84,   139,     7,    56,   147,    23,   -84,   100,
      56,   175,    45,   -84,   -84,   178,   211,   119,   119,   -84,
     -84,   -84,   197,   -84,   -84,   -84,   190,    61,   -84,   184,
     214,   236,   225,   -84,   -84,   232,     8,   229,   191,   327,
     174,   254,   262,   -84,   -84,     0,   -84,   -84,   243,   246,
     -84,    93,   159,   -84,   246,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   244,   207,    70,    75,   282,   282,   218,   -84,
     248,    77,   340,   -84,   252,   282,   326,   282,   -84,   252,
     -84,   -84,    14,   -84,   278,   -84,   121,   274,   356,   282,
     234,   282,   245,   173,   173,   256,    95,   -84,   191,   -84,
     -84,   282,   282,   282,   282,   282,   282,   282,   282,   269,
     261,   219,   -84,   413,   225,   413,   413,   -84,   101,   -84,
     371,    24,   -84,   -84,   383,   285,   116,   398,   296,   137,
     -84,   -84,   -84,   -84,   413,   423,   432,   277,   287,   287,
     173,   173,   -84,   -84,   279,   302,   272,   -84,   288,   -84,
     -84,   191,   191,   191,   191,   191,   191,   191,   191,   -84,
     -84,   -84,   275,   -84,   275,   -84,   313,   323,   328,   333,
     -84,   -84,   -84,   -84,   191,   191,   191,   191,   -84,   -84,
     -84,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    18,     0,     0,     2,     0,     0,    19,     0,
      28,    10,     0,     0,     0,    64,    27,     0,    21,     1,
       3,     0,     6,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,    11,    24,     0,     0,    64,    64,     9,
      12,     5,     0,     7,    28,    16,     0,     0,    35,     0,
       0,    38,     0,    17,    15,     0,     0,     0,    45,     0,
       0,     0,    67,    22,    63,     0,    13,    30,     0,     0,
      36,     0,     0,    34,     0,    31,    32,    33,    29,    43,
      97,    98,    96,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,    66,     0,     0,     0,     0,    65,     0,
      23,    20,     0,    39,     0,    37,     0,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,    42,    45,    44,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    72,    97,    73,    71,    68,     0,    90,
     100,     0,    53,    49,     0,     0,     0,     0,     0,     0,
      83,    84,    82,    46,    74,    76,    75,    77,    79,    78,
      81,    80,    95,    94,     0,     0,     0,    88,     0,    89,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    91,     0,   101,   102,    99,    54,    55,    56,    50,
      60,    61,    62,    52,     0,     0,     0,     0,    57,    58,
      59,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   332,   -84,   307,    10,   -84,   -84,   -84,   -29,
     372,   -52,   -84,   193,   -58,    -4,    54,   -84,   -30,   -84,
     -83,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    12,    35,     8,    17,    18,    13,
      14,    50,    51,    89,    90,    91,    36,    37,    61,    62,
      92,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   100,    19,   113,   114,   116,    60,    15,    42,    77,
       7,    16,   133,   135,   136,    68,     7,   103,    71,    44,
      72,    69,   105,   140,    47,   169,   144,   146,   147,   149,
     101,     2,     3,   119,    78,   -26,    32,    49,   154,   155,
     156,   157,   158,   159,   160,   161,    57,   165,   -64,   -64,
     -64,    48,   170,     2,     3,   -64,   -64,     9,   -64,    25,
     153,    44,    68,   -64,   132,    60,    44,   -64,    69,   137,
      60,   109,   -64,    71,   -64,   -64,   111,    26,   118,    49,
      80,    81,    82,   140,    49,   140,    58,    83,    84,    70,
      85,    64,    65,    27,   104,    86,   151,   110,    28,    87,
     -41,     9,   112,    52,    88,    44,    32,   -45,   166,   121,
     122,   123,   124,   125,   126,   127,   128,   173,    31,   129,
     130,   -41,   138,   152,    80,    81,    82,     2,     3,   167,
     121,   122,   123,   124,   125,   126,   127,   128,   177,    86,
     129,   130,     9,    87,   174,    41,    10,    11,    88,   139,
      46,   121,   122,   123,   124,   125,   126,   127,   128,    32,
     104,   129,   130,    39,    25,   178,   -40,   186,   187,   188,
     189,   190,   191,   192,   193,    96,    55,   -25,    56,    59,
     -70,   -70,    26,    44,    31,    68,    32,   -40,    97,    44,
     198,   199,   200,   201,    80,    81,    82,   129,   130,    31,
      29,    83,    84,    66,    85,   -14,    30,    33,   107,    86,
      80,    81,    82,    87,    40,    38,    67,    43,    88,   115,
      32,    80,    81,    82,    31,    86,    94,    21,   183,    87,
     185,    10,    22,    95,    88,   145,    86,    80,    81,    82,
      87,    63,    73,    74,    26,    88,   148,   102,    80,    81,
      82,    75,    86,   131,     2,     3,    87,    44,    76,    79,
      98,    88,   164,    86,    80,    81,    82,    87,    26,    99,
     162,   106,    88,   182,   163,    80,    81,    82,   117,    86,
     142,    52,   166,    87,   150,    80,    81,    82,    88,   184,
      86,    80,    81,    82,    87,   125,   126,   127,   128,    88,
      86,   129,   130,   180,    87,   179,    86,   127,   128,    88,
      87,   129,   130,   172,    23,    88,   121,   122,   123,   124,
     125,   126,   127,   128,   176,   194,   129,   130,   181,   134,
      81,    82,    45,    93,    94,   195,    53,    54,    20,     0,
     196,    95,    -4,     1,    86,   197,   120,     0,    87,     0,
       2,     3,    26,    88,   121,   122,   123,   124,   125,   126,
     127,   128,   143,     0,   129,   130,    34,     0,     2,     3,
     121,   122,   123,   124,   125,   126,   127,   128,   168,    24,
     129,   130,     0,     0,     0,   121,   122,   123,   124,   125,
     126,   127,   128,     0,     0,   129,   130,   121,   122,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,     0,
       0,   171,   121,   122,   123,   124,   125,   126,   127,   128,
       0,     0,   129,   130,     0,     0,   175,   121,   122,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,   123,
     124,   125,   126,   127,   128,     0,     0,   129,   130,   124,
     125,   126,   127,   128,     0,     0,   129,   130
};

static const yytype_int16 yycheck[] =
{
      83,     1,     0,    86,    87,    88,    35,     1,     1,     1,
       0,     5,    95,    96,    97,     1,     6,    69,    47,     5,
      49,     7,    74,   106,     1,     1,   109,   110,   111,   112,
      30,     8,     9,    91,    26,    29,    29,    27,   121,   122,
     123,   124,   125,   126,   127,   128,     1,   130,     3,     4,
       5,    28,    28,     8,     9,    10,    11,     1,    13,     7,
     118,     5,     1,    18,    94,    94,     5,    22,     7,    99,
      99,     1,    27,   102,    29,    30,     1,    25,     1,    69,
       3,     4,     5,   166,    74,   168,    32,    10,    11,    28,
      13,    37,    38,    27,     1,    18,     1,    27,     6,    22,
       7,     1,    27,     3,    27,     5,    29,    30,     7,    14,
      15,    16,    17,    18,    19,    20,    21,     1,    25,    24,
      25,    28,     1,    28,     3,     4,     5,     8,     9,    28,
      14,    15,    16,    17,    18,    19,    20,    21,     1,    18,
      24,    25,     1,    22,    28,     6,     5,     6,    27,    28,
       3,    14,    15,    16,    17,    18,    19,    20,    21,    29,
       1,    24,    25,     6,     7,    28,     7,   171,   172,   173,
     174,   175,   176,   177,   178,     1,     1,    29,     3,     1,
       6,     7,    25,     5,    25,     1,    29,    28,    14,     5,
     194,   195,   196,   197,     3,     4,     5,    24,    25,    25,
       1,    10,    11,     6,    13,     6,     7,    14,     1,    18,
       3,     4,     5,    22,    21,    29,    26,    24,    27,     1,
      29,     3,     4,     5,    25,    18,     7,     1,   166,    22,
     168,     5,     6,    14,    27,     1,    18,     3,     4,     5,
      22,    30,    28,     7,    25,    27,     1,     1,     3,     4,
       5,    26,    18,     1,     8,     9,    22,     5,    26,    30,
       6,    27,     1,    18,     3,     4,     5,    22,    25,     7,
       1,    27,    27,     1,     5,     3,     4,     5,    30,    18,
       6,     3,     7,    22,    28,     3,     4,     5,    27,     1,
      18,     3,     4,     5,    22,    18,    19,    20,    21,    27,
      18,    24,    25,     1,    22,    26,    18,    20,    21,    27,
      22,    24,    25,    28,     7,    27,    14,    15,    16,    17,
      18,    19,    20,    21,    28,    12,    24,    25,    26,     3,
       4,     5,    25,     6,     7,    12,    29,    30,     6,    -1,
      12,    14,     0,     1,    18,    12,     6,    -1,    22,    -1,
       8,     9,    25,    27,    14,    15,    16,    17,    18,    19,
      20,    21,     6,    -1,    24,    25,     6,    -1,     8,     9,
      14,    15,    16,    17,    18,    19,    20,    21,     7,     7,
      24,    25,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    -1,
      -1,    28,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    -1,    -1,    28,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     8,     9,    33,    34,    35,    37,    38,     1,
       5,     6,    36,    41,    42,     1,     5,    39,    40,     0,
      34,     1,     6,    36,    42,     7,    25,    27,     6,     1,
       7,    25,    29,    45,     6,    37,    48,    49,    29,     6,
      45,     6,     1,    45,     5,    36,     3,     1,    28,    37,
      43,    44,     3,    36,    36,     1,     3,     1,    48,     1,
      41,    50,    51,    30,    48,    48,     6,    26,     1,     7,
      28,    41,    41,    28,     7,    26,    26,     1,    26,    30,
       3,     4,     5,    10,    11,    13,    18,    22,    27,    45,
      46,    47,    52,     6,     7,    14,     1,    14,     6,     7,
       1,    30,     1,    43,     1,    43,    27,     1,    52,     1,
      27,     1,    27,    52,    52,     1,    52,    30,     1,    46,
       6,    14,    15,    16,    17,    18,    19,    20,    21,    24,
      25,     1,    50,    52,     3,    52,    52,    50,     1,    28,
      52,    53,     6,     6,    52,     1,    52,    52,     1,    52,
      28,     1,    28,    46,    52,    52,    52,    52,    52,    52,
      52,    52,     1,     5,     1,    52,     7,    28,     7,     1,
      28,    28,    28,     1,    28,    28,    28,     1,    28,    26,
       1,    26,     1,    53,     1,    53,    47,    47,    47,    47,
      47,    47,    47,    47,    12,    12,    12,    12,    47,    47,
      47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    36,    36,    37,    37,
      38,    38,    38,    38,    38,    39,    39,    40,    41,    41,
      41,    41,    41,    41,    42,    42,    42,    43,    43,    43,
      44,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     3,
       2,     3,     3,     4,     1,     3,     3,     3,     1,     1,
       5,     2,     4,     5,     3,     1,     0,     1,     1,     4,
       4,     4,     4,     4,     4,     3,     4,     3,     1,     3,
       2,     2,     4,     3,     2,     0,     3,     2,     1,     3,
       5,     7,     5,     3,     5,     5,     5,     7,     7,     7,
       5,     5,     5,     2,     0,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     4,     4,
       3,     4,     4,     4,     3,     3,     1,     1,     1,     3,
       1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 24 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Program", (yyloc).first_line);
	insert(NULL, (yyval));
	insert((yyval), (yyvsp[0]));
}
#line 1529 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 31 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDefList", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1539 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 35 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = NULL;
}
#line 1547 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 40 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDef", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1558 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDef", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1568 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 49 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDef", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1579 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 54 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid specifier of global variable");
}
#line 1587 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 56 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid global variable");
}
#line 1595 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 58 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid struct");
}
#line 1603 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 60 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid specifier of function");
}
#line 1611 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 62 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid function declaration");
}
#line 1619 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "error detected in function body");
}
#line 1627 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDecList", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1636 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ExtDecList", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1647 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 77 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid declaration of variable");
}
#line 1655 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "missing ',' in variable lists");
}
#line 1663 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Specifier", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1672 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 87 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Specifier", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1681 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 93 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "StructSpecifier", (yyloc).first_line);
	insert((yyval), (yyvsp[-4]));
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1694 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "StructSpecifier", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1704 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid struct definition");
}
#line 1712 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 106 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "missing '}' in struct definition");
}
#line 1720 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 108 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid struct definition");
}
#line 1728 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 113 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "OptTag", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1737 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 116 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = NULL;
}
#line 1745 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Tag", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1754 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "VarDec", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1763 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "VarDec", (yyloc).first_line);
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1775 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 136 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-3]).first_line, "invalid variable declaration");
}
#line 1783 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 138 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "missing '[' in variable declaration");
}
#line 1791 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "Not a integer in '[]'");
}
#line 1799 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 142 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "missing ']' in variable declaration");
}
#line 1807 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 147 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "FunDec", (yyloc).first_line);
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1819 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 153 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "FunDec", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1830 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid variable list of function");
}
#line 1838 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "VarList", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1849 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "VarList", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1858 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 171 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid parameter declaration");
}
#line 1866 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 176 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "ParamDec", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1876 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 180 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid specifier");
}
#line 1884 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "CompSt", (yyloc).first_line);
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1896 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 191 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "missing '}'");
}
#line 1904 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 196 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "StmtList", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1914 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 200 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = NULL;
}
#line 1922 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 202 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid statement");
}
#line 1930 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 207 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1940 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 211 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 1949 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1960 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 219 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[-4]));
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1973 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 226 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[-6]));
	insert((yyval), (yyvsp[-5]));
	insert((yyval), (yyvsp[-4]));
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 1988 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Stmt", (yyloc).first_line);
	insert((yyval), (yyvsp[-4]));
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2001 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid return value");
}
#line 2009 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 244 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-3]).first_line, "missing '('");
}
#line 2017 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 246 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid 'if' condition");
}
#line 2025 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 248 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "missing ')'");
}
#line 2033 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-5]).first_line, "missing '('");
}
#line 2041 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 252 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-4]).first_line, "invalid 'if' condition");
}
#line 2049 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 254 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-3]).first_line, "missing ')'");
}
#line 2057 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 256 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-3]).first_line, "missing '('");
}
#line 2065 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 258 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid 'while' condition");
}
#line 2073 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 260 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "missing ')'");
}
#line 2081 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 265 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "DefList", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2091 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 269 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = NULL;
}
#line 2099 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 274 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Def", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2110 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 279 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid declaration list");
}
#line 2118 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 284 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "DecList", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2127 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 287 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "DecList", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2138 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 292 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid declaration");
}
#line 2146 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 297 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Dec", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2155 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 300 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Dec", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2166 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 305 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid variable declaration");
}
#line 2174 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "missing '='");
}
#line 2182 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 312 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2193 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 317 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2204 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 322 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2215 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 327 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2226 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 332 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2237 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 337 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2248 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 342 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2259 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 347 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2270 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 352 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2281 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 357 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid expression between '(' and ')'");
}
#line 2289 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 359 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "missing ')'");
}
#line 2297 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 362 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2307 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 366 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2317 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 370 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2329 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 376 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid argument");
}
#line 2337 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 378 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "missing ')'");
}
#line 2345 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 381 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2356 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 386 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-3]));
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2368 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 392 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-1]).first_line, "invalid array index");
}
#line 2376 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 394 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "missing ']'");
}
#line 2384 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 397 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2395 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 402 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "invalid struct property name");
}
#line 2403 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 405 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2412 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 408 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2421 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 411 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Exp", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2430 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 417 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Args", (yyloc).first_line);
	insert((yyval), (yyvsp[-2]));
	insert((yyval), (yyvsp[-1]));
	insert((yyval), (yyvsp[0]));
}
#line 2441 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 422 "./syntax.y" /* yacc.c:1646  */
    {
	(yyval) = initNode(NONTERMINAL, "Args", (yyloc).first_line);
	insert((yyval), (yyvsp[0]));
}
#line 2450 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 425 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[-2]).first_line, "invalid argument expression");
}
#line 2458 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 427 "./syntax.y" /* yacc.c:1646  */
    {
	ERROR((yylsp[0]).first_line, "invalid argument");
}
#line 2466 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2470 "./syntax.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 432 "./syntax.y" /* yacc.c:1906  */


yyerror(char* msg) {
	printf("syntax error at Line %d.\n", yylineno);
	setError();
}



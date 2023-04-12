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
#line 7 "PJParser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include <util/string_utils.h>
#include <codegen/codegen.h>
#include <codegen/reg.h>
#include <codegen/symfields.h>
#include <codegen/types.h>
#include "PJParserHeader.h"

#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,yyerror,(char*));
EXTERN(int,yylex,(void));

SymTable globalSymtab;
SymtabStack localSymStack;

static DList instList;
static DList dataList;
char *fileName;

int globalOffset = 0;
int isGlobal = 1;
int jumpPoints = 0;
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

#line 104 "PJParser.c" /* yacc.c:339  */

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
   by #include "PJParser.h".  */
#ifndef YY_YY_PJPARSER_H_INCLUDED
# define YY_YY_PJPARSER_H_INCLUDED
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
    T_AND = 258,
    T_ELSE = 259,
    T_FLOAT = 260,
    T_FOR = 261,
    T_IF = 262,
    T_LONGINT = 263,
    T_BOOLEAN = 264,
    T_PROGRAM = 265,
    T_FUNCTION = 266,
    T_NOT = 267,
    T_OR = 268,
    T_READ = 269,
    T_WHILE = 270,
    T_WRITE = 271,
    T_WRITELN = 272,
    T_BEGIN = 273,
    T_END = 274,
    T_VAR = 275,
    T_DO = 276,
    T_ARRAY = 277,
    T_EXIT = 278,
    T_THEN = 279,
    T_LE = 280,
    T_LT = 281,
    T_GE = 282,
    T_GT = 283,
    T_EQ = 284,
    T_NE = 285,
    T_ASSIGN = 286,
    T_COMMA = 287,
    T_SEMICOLON = 288,
    T_COLON = 289,
    T_LBRACKET = 290,
    T_RBRACKET = 291,
    T_LPAREN = 292,
    T_RPAREN = 293,
    T_PLUS = 294,
    T_TIMES = 295,
    T_IDENTIFIER = 296,
    T_DIV = 297,
    T_STRING = 298,
    T_INTNUM = 299,
    T_FLOATNUM = 300,
    T_MINUS = 301,
    T_DOT = 302,
    T_DOTDOT = 303,
    T_OF = 304,
    T_TRUE = 305,
    T_FALSE = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 105 "PJParser.y" /* yacc.c:355  */

	int   regIndex;
	int	typeId;
	DList	idList;
	char	*name;
 	int   symIndex;
	int 	offset;
	ArrayBounds bounds;
   int     value;

#line 207 "PJParser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PJPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "PJParser.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   134,   139,   148,   149,   155,   166,   175,
     180,   186,   190,   196,   200,   204,   209,   213,   218,   225,
     229,   234,   235,   238,   249,   263,   270,   274,   275,   276,
     277,   278,   279,   282,   287,   292,   298,   310,   318,   326,
     335,   343,   347,   351,   356,   360,   364,   366,   370,   379,
     382,   383,   386,   390,   394,   398,   402,   406,   410,   416,
     420,   424,   428,   434,   436,   440,   444,   449,   453,   457,
     461,   477,   482,   489,   495,   505,   506,   511,   515,   519
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AND", "T_ELSE", "T_FLOAT", "T_FOR",
  "T_IF", "T_LONGINT", "T_BOOLEAN", "T_PROGRAM", "T_FUNCTION", "T_NOT",
  "T_OR", "T_READ", "T_WHILE", "T_WRITE", "T_WRITELN", "T_BEGIN", "T_END",
  "T_VAR", "T_DO", "T_ARRAY", "T_EXIT", "T_THEN", "T_LE", "T_LT", "T_GE",
  "T_GT", "T_EQ", "T_NE", "T_ASSIGN", "T_COMMA", "T_SEMICOLON", "T_COLON",
  "T_LBRACKET", "T_RBRACKET", "T_LPAREN", "T_RPAREN", "T_PLUS", "T_TIMES",
  "T_IDENTIFIER", "T_DIV", "T_STRING", "T_INTNUM", "T_FLOATNUM", "T_MINUS",
  "T_DOT", "T_DOTDOT", "T_OF", "T_TRUE", "T_FALSE", "$accept", "Program",
  "ProgramHeadAndProcedures", "ProgramHead", "Decls", "DeclList",
  "IdentifierList", "Type", "StandardType", "ArrayType", "Dim", "IntConst",
  "Procedures", "ProcedureDecl", "ProcedureHead", "FunctionDecl",
  "ProcedureBody", "Statement", "Assignment", "IfStatement", "TestAndThen",
  "Test", "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "OutputFormat", "WriteToken", "ExitStatement", "CompoundStatement",
  "StatementList", "Expr", "AddExpr", "MulExpr", "Factor", "Variable",
  "Constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -4,   -17,    27,    12,   -93,     0,   -93,     3,     7,    25,
      37,    43,    11,   -93,   -93,   -93,    39,    42,   -93,   -93,
     -93,   -93,    43,   -93,    44,   -93,   -93,   -11,    16,   -93,
      41,   -93,    12,    37,    45,   -93,    43,    43,   -21,   -93,
     -93,    47,   -93,   -93,    81,    84,   125,    10,     1,   -93,
     -93,   -93,    69,    43,    43,    90,   125,    28,   -93,     3,
      43,    78,   -93,    80,   -93,   -93,    45,     5,   -93,    71,
      76,   -93,     3,     3,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    86,    77,    91,     3,
      88,   115,   -93,   125,     4,   -93,    36,    85,    20,   -93,
     -93,   -93,   -93,    10,    10,    10,    10,    10,    10,     1,
       1,     1,   -93,   -93,   -93,   -93,   -93,    43,   -93,   -93,
      92,    87,    96,   -93,   -93,   -93,   102,    20,   -93,   111,
     104,   -93,   -93,   103,   -93,   -93,   -93,   -93,   105,    46,
     -93,   -93,   -93,   -93,   118,   -25,    99,   -93,    46,   114,
      46,   112,     4,   -93,   116,   -93,     4,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    22,     0,     1,     0,     0,     3,
       6,     0,     0,    40,    46,    47,     0,    72,    51,    27,
      28,    29,     0,    30,     0,    31,    32,     0,     0,     2,
       0,    21,     0,     6,     0,     4,     0,     0,    72,    77,
      75,     0,    78,    79,    35,     0,    37,    52,    59,    63,
      67,    68,     0,     0,     0,     0,    39,     0,    49,     0,
       0,     0,    23,     0,    24,     9,     5,     0,    69,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    45,    50,    33,     0,    26,     0,     0,     0,    71,
      70,    34,    36,    55,    56,    57,    58,    53,    54,    60,
      61,    62,    66,    64,    65,    41,    48,     0,    73,    38,
       0,     0,     0,    15,    13,    14,     0,     0,    10,     0,
       0,    11,    12,     0,    44,    43,    42,    25,     0,     0,
       7,    74,     8,    20,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    18,     0,    16,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -93,   131,   -93,   100,    40,   -92,   -93,
      21,    18,   -93,   -93,   -93,   -93,   -93,   -14,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,    79,   -93,   -93,     2,
     -93,   -22,    82,   -19,   -33,    -6,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    35,    66,    67,   130,   131,   132,
     145,   146,     9,    31,    32,    33,    62,    18,    19,    20,
      44,    45,    21,    55,    22,    23,   121,    24,    25,    26,
      27,    46,    47,    48,    49,    50,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    28,   126,    68,    83,     8,     1,   148,    58,   123,
      11,   149,   124,   125,    54,    69,    70,    12,    13,    14,
      15,     7,    59,    80,     5,   123,    16,     6,   124,   125,
       7,    87,    88,    10,    63,    91,    30,    97,    93,    98,
      36,    84,   129,    85,    17,    92,    86,    60,    52,    81,
     112,   113,   114,    28,    29,    36,    82,    34,   101,   102,
     155,   109,   110,   111,   157,    37,    28,    28,    97,    38,
     127,    90,    39,    40,    41,   119,    53,    54,    42,    43,
      37,    57,    61,    28,    38,    72,    65,    39,    40,    41,
     143,    71,   144,    42,    43,   133,    74,    75,    76,    77,
      78,    79,    74,    75,    76,    77,    78,    79,    73,    99,
      17,    89,    94,    95,   100,   116,    74,    75,    76,    77,
      78,    79,   120,   117,   115,   135,   128,   118,    74,    75,
      76,    77,    78,    79,   136,   137,   134,   140,   142,   141,
      74,    75,    76,    77,    78,    79,   139,   150,   154,   120,
      74,    75,    76,    77,    78,    79,   103,   104,   105,   106,
     107,   108,   147,   152,    64,   156,    96,   138,   153,   151,
     122
};

static const yytype_uint8 yycheck[] =
{
      22,     7,    94,    36,     3,     3,    10,    32,    19,     5,
       7,    36,     8,     9,    35,    37,    37,    14,    15,    16,
      17,    18,    33,    13,    41,     5,    23,     0,     8,     9,
      18,    53,    54,    33,    32,    57,    11,    32,    60,    34,
      12,    40,    22,    42,    41,    59,    52,    31,    37,    39,
      83,    84,    85,    59,    47,    12,    46,    20,    72,    73,
     152,    80,    81,    82,   156,    37,    72,    73,    32,    41,
      34,    43,    44,    45,    46,    89,    37,    35,    50,    51,
      37,    37,    41,    89,    41,     4,    41,    44,    45,    46,
      44,    44,    46,    50,    51,   117,    25,    26,    27,    28,
      29,    30,    25,    26,    27,    28,    29,    30,    24,    38,
      41,    21,    34,    33,    38,    38,    25,    26,    27,    28,
      29,    30,    34,    32,    38,    38,    41,    36,    25,    26,
      27,    28,    29,    30,    38,    33,    44,    33,    33,    36,
      25,    26,    27,    28,    29,    30,    35,    48,    36,    34,
      25,    26,    27,    28,    29,    30,    74,    75,    76,    77,
      78,    79,    44,    49,    33,    49,    66,   127,   150,   148,
      91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    53,    54,    55,    41,     0,    18,    81,    64,
      33,     7,    14,    15,    16,    17,    23,    41,    69,    70,
      71,    74,    76,    77,    79,    80,    81,    82,    87,    47,
      11,    65,    66,    67,    20,    56,    12,    37,    41,    44,
      45,    46,    50,    51,    72,    73,    83,    84,    85,    86,
      87,    88,    37,    37,    35,    75,    83,    37,    19,    33,
      31,    41,    68,    81,    56,    41,    57,    58,    86,    83,
      37,    44,     4,    24,    25,    26,    27,    28,    29,    30,
      13,    39,    46,     3,    40,    42,    87,    83,    83,    21,
      43,    83,    69,    83,    34,    33,    58,    32,    34,    38,
      38,    69,    69,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    86,    86,    86,    38,    38,    32,    36,    69,
      34,    78,    78,     5,     8,     9,    60,    34,    41,    22,
      59,    60,    61,    83,    44,    38,    38,    33,    59,    35,
      33,    36,    33,    44,    46,    62,    63,    44,    32,    36,
      48,    62,    49,    63,    36,    60,    49,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    72,    73,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    85,    85,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     4,     2,     0,     4,     5,     1,
       3,     1,     1,     1,     1,     1,     6,     8,     3,     2,
       1,     2,     0,     2,     2,     5,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     2,     3,     1,     4,     1,
       1,     4,     5,     5,     2,     0,     1,     1,     4,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     2,
       3,     3,     1,     4,     6,     1,     2,     1,     1,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 128 "PJParser.y" /* yacc.c:1646  */
    {
			emitProcedureExit(instList);
			emitDataPrologue(dataList);
			emitInstructions(instList);
		}
#line 1423 "PJParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "PJParser.y" /* yacc.c:1646  */
    {
			emitProcedurePrologue(instList,(yyvsp[-1].name));
		}
#line 1431 "PJParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.name) = "main";
			globalSymtab = endScope(localSymStack);
			
			globalOffset = (int)SymGetField(globalSymtab, " ", "offset");
			isGlobal = 0;
		}
#line 1443 "PJParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 149 "PJParser.y" /* yacc.c:1646  */
    {
			
			beginScope(localSymStack);
		}
#line 1452 "PJParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 156 "PJParser.y" /* yacc.c:1646  */
    {
			
			//begin scope
			beginScope(localSymStack);

			//add symbols to the current scope
			dlinkApply1((yyvsp[-3].idList),(DLinkApply1Func)addIdToSymStack, (Generic)(yyvsp[-1].typeId));
			dlinkFreeNodes((yyvsp[-3].idList));
			
		}
#line 1467 "PJParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 167 "PJParser.y" /* yacc.c:1646  */
    {

			//add symbols to the current scope
			dlinkApply1((yyvsp[-3].idList),(DLinkApply1Func)addIdToSymStack, (Generic)(yyvsp[-1].typeId));
			dlinkFreeNodes((yyvsp[-3].idList));			

		}
#line 1479 "PJParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 176 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.idList) = dlinkListAlloc(NULL);
			dlinkAppend((yyval.idList),dlinkNodeAlloc((Generic)(yyvsp[0].name)));
		}
#line 1488 "PJParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 181 "PJParser.y" /* yacc.c:1646  */
    {
			dlinkAppend((yyvsp[-2].idList),dlinkNodeAlloc((Generic)(yyvsp[0].name)));
			(yyval.idList) = (yyvsp[-2].idList);
		}
#line 1497 "PJParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 187 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = (yyvsp[0].typeId);
		}
#line 1505 "PJParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = (yyvsp[0].typeId);
	 	}
#line 1513 "PJParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 197 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = INTEGER_TYPE;
		}
#line 1521 "PJParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 201 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = INTEGER_TYPE;
		}
#line 1529 "PJParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 205 "PJParser.y" /* yacc.c:1646  */
    {
			//$$ = FLOAT_TYPE ;
		}
#line 1537 "PJParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 210 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = newArrayType(1, (yyvsp[-3].bounds).lowerBound, (yyvsp[-3].bounds).upperBound, 0, 0, (yyvsp[0].typeId));
		}
#line 1545 "PJParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.typeId) = newArrayType(1, (yyvsp[-5].bounds).lowerBound, (yyvsp[-5].bounds).upperBound, (yyvsp[-3].bounds).lowerBound, (yyvsp[-3].bounds).upperBound, (yyvsp[0].typeId));
		}
#line 1553 "PJParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 219 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.bounds).lowerBound = (yyvsp[-2].value);
			(yyval.bounds).upperBound = (yyvsp[0].value);
		}
#line 1562 "PJParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.value) = -atoi((yyvsp[0].name));
		}
#line 1570 "PJParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 230 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.value) = atoi((yyvsp[0].name));
		}
#line 1578 "PJParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 238 "PJParser.y" /* yacc.c:1646  */
    {
			//postamble
				//restore callee-saved regs
				//discard local data
				//restore call fp
			//goto return address

			//remove symtab from stack
			endScope(localSymStack);
		}
#line 1593 "PJParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "PJParser.y" /* yacc.c:1646  */
    {
			//preamble
				//extend AR for locals
				//save callee-saved regs
				//find static data area
				//initialize locals
			
			//raise stack by an amount
			raiseStack(instList);

			//add variables to symbol table

    	}
#line 1611 "PJParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 263 "PJParser.y" /* yacc.c:1646  */
    {
			//identifier to function
			emitProcedurePrologue(instList, (yyvsp[-3].name));

			(yyval.name) = (yyvsp[-3].name);
		}
#line 1622 "PJParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 270 "PJParser.y" /* yacc.c:1646  */
    {
			
		}
#line 1630 "PJParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 283 "PJParser.y" /* yacc.c:1646  */
    {
			emitAssignment(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1638 "PJParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 288 "PJParser.y" /* yacc.c:1646  */
    {
			//jump location after else
			emitJumpPoint(instList, (yyvsp[-2].symIndex));
		}
#line 1647 "PJParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 293 "PJParser.y" /* yacc.c:1646  */
    {
			//jump location after else
			emitJumpPoint(instList, (yyvsp[0].symIndex));
		}
#line 1656 "PJParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 299 "PJParser.y" /* yacc.c:1646  */
    {
			//jump after else
			(yyval.symIndex) = jumpPoints;
			emitJump(instList, jumpPoints);
			jumpPoints+=1;

			//jump location of if condition is false
			emitJumpPoint(instList, (yyvsp[-2].symIndex));

		}
#line 1671 "PJParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 311 "PJParser.y" /* yacc.c:1646  */
    {
			//jump if false
			(yyval.symIndex) = jumpPoints;
			emitCJump(instList, (yyvsp[0].regIndex), jumpPoints);
			jumpPoints+=1;
		}
#line 1682 "PJParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 319 "PJParser.y" /* yacc.c:1646  */
    {
			//jump back to start of loop
			emitJump(instList, (yyvsp[-3].symIndex));
			//jumping point for end of loop
			emitJumpPoint(instList, (yyvsp[-2].symIndex));
		}
#line 1693 "PJParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 327 "PJParser.y" /* yacc.c:1646  */
    {
			//test
			//if false jump after
			(yyval.symIndex) = jumpPoints;
        	emitCJump(instList, (yyvsp[0].regIndex), jumpPoints);
        	jumpPoints+=1;
		}
#line 1705 "PJParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 336 "PJParser.y" /* yacc.c:1646  */
    {
			//creating jump point beginning of loop
			(yyval.symIndex) = jumpPoints;
			emitJumpPoint(instList, jumpPoints);
			jumpPoints+=1;
		}
#line 1716 "PJParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 344 "PJParser.y" /* yacc.c:1646  */
    {
			emitReadVariable(instList,dataList,  (yyvsp[-1].regIndex));
		}
#line 1724 "PJParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 348 "PJParser.y" /* yacc.c:1646  */
    {
			emitWriteExpression(instList, dataList, (yyvsp[-4].typeId), (yyvsp[-2].regIndex), (yyvsp[-1].name));
		}
#line 1732 "PJParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 352 "PJParser.y" /* yacc.c:1646  */
    {
			emitWriteString(instList, dataList, (yyvsp[-4].typeId), (yyvsp[-2].name), (yyvsp[-1].name));
		}
#line 1740 "PJParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 357 "PJParser.y" /* yacc.c:1646  */
    {
		   (yyval.name) = (yyvsp[0].name);
		}
#line 1748 "PJParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 360 "PJParser.y" /* yacc.c:1646  */
    {
		   (yyval.name) = NULL;
		}
#line 1756 "PJParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 365 "PJParser.y" /* yacc.c:1646  */
    {(yyval.typeId) = IS_WRITE;}
#line 1762 "PJParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 367 "PJParser.y" /* yacc.c:1646  */
    {(yyval.typeId) = IS_WRITELN;}
#line 1768 "PJParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 371 "PJParser.y" /* yacc.c:1646  */
    {
			//restore callee-saved reg
			//discard local data
			//restore caller's FP
			//jump to return address
			emitProcedureExitWithReturn(instList, (yyvsp[-1].regIndex));
		}
#line 1780 "PJParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 387 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = (yyvsp[0].regIndex);
		}
#line 1788 "PJParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 391 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1796 "PJParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 395 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitNotEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1804 "PJParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 399 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitLessEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1812 "PJParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 403 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitLessThanExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1820 "PJParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 407 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitGreaterEqualExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1828 "PJParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 411 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitGreaterThanExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1836 "PJParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 417 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = (yyvsp[0].regIndex);
		}
#line 1844 "PJParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 421 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitOrExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1852 "PJParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitAddExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1860 "PJParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 429 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitSubtractExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1868 "PJParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 435 "PJParser.y" /* yacc.c:1646  */
    {(yyval.regIndex) =(yyvsp[0].regIndex);}
#line 1874 "PJParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 437 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitMultiplyExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1882 "PJParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 441 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitDivideExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1890 "PJParser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 445 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitAndExpression(instList,(yyvsp[-2].regIndex),(yyvsp[0].regIndex));
		}
#line 1898 "PJParser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 450 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitLoadVariable(instList, (yyvsp[0].regIndex));
		}
#line 1906 "PJParser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 454 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = (yyvsp[0].regIndex);
		}
#line 1914 "PJParser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 458 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = emitNotExpression(instList,(yyvsp[0].regIndex));
		}
#line 1922 "PJParser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 462 "PJParser.y" /* yacc.c:1646  */
    {
			//pre call
				//allocate AR
				//save caller-saved regs
				//evaluate and store params
				//store return address
				//store FP
			//call function
			(yyval.regIndex) = emitCall(instList, (yyvsp[-2].name));
			//post call
				//deallocatate basic AR
				//restore caller-saved registers
				//restore reference???
				//parameters???
		}
#line 1942 "PJParser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 478 "PJParser.y" /* yacc.c:1646  */
    {
			(yyval.regIndex) = (yyvsp[-1].regIndex);
		}
#line 1950 "PJParser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 483 "PJParser.y" /* yacc.c:1646  */
    {
			/*int symIndex = SymQueryIndex(globalSymtab,$1);
			$$ = emitComputeVariableAddress(instList, symIndex);*/
			char *name = (yyvsp[0].name);
			(yyval.regIndex) = emitComputeLocalAddress(instList, (yyvsp[0].name));
		}
#line 1961 "PJParser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 490 "PJParser.y" /* yacc.c:1646  */
    {
	
			(yyval.regIndex) = emitComputeLocalArrayAddress(instList, (yyvsp[-3].name), (yyvsp[-1].regIndex));

		}
#line 1971 "PJParser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 496 "PJParser.y" /* yacc.c:1646  */
    {
			/*int symIndex = SymQueryIndex(globalSymtab,$1);
			$$ = emitCompute2DArrayAddress(instList, symIndex,$3, $5);*/

			//$$ = emitComputeLocalMatrixAddress(instList, $1, $3);

		}
#line 1983 "PJParser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 507 "PJParser.y" /* yacc.c:1646  */
    {   
			char *negstr = nssave(2, "-", (yyvsp[0].name));
			(yyval.regIndex) = emitLoadIntegerConstant(instList,negstr); 
		}
#line 1992 "PJParser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 512 "PJParser.y" /* yacc.c:1646  */
    { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,(yyvsp[0].name)); 
		}
#line 2000 "PJParser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 516 "PJParser.y" /* yacc.c:1646  */
    { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,"1"); 
		}
#line 2008 "PJParser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 520 "PJParser.y" /* yacc.c:1646  */
    { 
			(yyval.regIndex) = emitLoadIntegerConstant(instList,"0"); 
		}
#line 2016 "PJParser.c" /* yacc.c:1646  */
    break;


#line 2020 "PJParser.c" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 525 "PJParser.y" /* yacc.c:1906  */



/********************C ROUTINES *********************************/
void yyerror(char *s)
{
  fprintf(stderr,"%s: line %d, found %s: %s\n",fileName,yylineno,yytext,s);
}

int yywrap() {
	return 1;
}


static void initialize(char* inputFileName) {
	yyin = fopen(inputFileName,"r");
        if (yyin == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }

	
	globalSymtab = SymInit(SYMTABLE_SIZE);
	localSymStack = symtabStackInit();
	beginScope(localSymStack);
	SymInitField(globalSymtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
	initRegisters();
	
	instList = dlinkListAlloc(NULL);
	dataList = dlinkListAlloc(NULL);

}

static void finalize() {

    fclose(stdin);
    fclose(stdout);
    
    SymKillField(globalSymtab,SYMTAB_OFFSET_FIELD);
    SymKill(globalSymtab);
 
    cleanupRegisters();
    
    dlinkFreeNodesAndAtoms(instList);
    dlinkFreeNodesAndAtoms(dataList);

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
	yyparse();
    
	finalize();
  
	return 0;
}
/******************END OF C ROUTINES**********************/

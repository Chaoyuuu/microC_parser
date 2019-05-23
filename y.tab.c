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
#line 4 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int table_depth = 0;
const char *type_f = "function";
const char *type_p = "parameter";
const char *type_v = "variable";

struct Entry{
    struct Entry * entry_next;
    struct Entry * entry_pre;

    int index;
    char name[20];
    char kind[20];
    char type[20];
    int scope;
    char attribute[50];
};

struct Table{
    int table_depth;
    struct Entry * entry_header;
    struct Entry * entry_current;
    struct Table * pre;
};

struct Table *table_header = NULL;
struct Table *table_current = NULL;
struct Table *table_dump = NULL;

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern char syntax_buf[256];
extern int error_flag; //1.redefined 2.undefined
extern int syntax_flag;
extern char error_msg[256];
extern int dump_flag;
extern void yyerror(char *s);

char attri_buf[256];


/* Symbol table function - you can add new function if needed. */
void get_attribute(struct Entry * tmp);
void create_symbol();
void lookup_symbol();
void lookup_function();
void insert_symbol();
void dump_symbol();
void dump_table();


#line 125 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    BOOL = 258,
    FLOAT = 259,
    INT = 260,
    VOID = 261,
    STRING = 262,
    INC_OP = 263,
    DEC_OP = 264,
    GE_OP = 265,
    LE_OP = 266,
    EQ_OP = 267,
    NE_OP = 268,
    AND_OP = 269,
    OR_OP = 270,
    ADD_ASSIGN = 271,
    SUB_ASSIGN = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    TRUE = 276,
    FALSE = 277,
    RETURN = 278,
    PRINT = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    SEMICOLON = 284,
    QUOTA = 285,
    ID = 286,
    I_CONST = 287,
    F_CONST = 288,
    STRING_CONST = 289
  };
#endif
/* Tokens.  */
#define BOOL 258
#define FLOAT 259
#define INT 260
#define VOID 261
#define STRING 262
#define INC_OP 263
#define DEC_OP 264
#define GE_OP 265
#define LE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define AND_OP 269
#define OR_OP 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define TRUE 276
#define FALSE 277
#define RETURN 278
#define PRINT 279
#define IF 280
#define ELSE 281
#define FOR 282
#define WHILE 283
#define SEMICOLON 284
#define QUOTA 285
#define ID 286
#define I_CONST 287
#define F_CONST 288
#define STRING_CONST 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;    //not use
    double f_val; //not use
    char* string; //not use
    char* symbol_name;  //return ID
    char* symbol_type;  //return type

#line 241 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 258 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    42,     2,     2,
      36,    37,    40,    45,    48,    46,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    35,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   108,   109,   113,   114,   115,   116,   117,
     121,   123,   128,   133,   133,   139,   140,   141,   142,   146,
     146,   149,   148,   151,   150,   157,   156,   163,   164,   168,
     169,   173,   174,   178,   179,   183,   184,   188,   189,   193,
     194,   198,   199,   203,   204,   205,   209,   210,   211,   212,
     213,   214,   218,   219,   223,   224,   225,   229,   233,   234,
     235,   236,   237,   238,   241,   246,   246,   249,   249,   254,
     255,   259,   261,   266,   267,   271,   272,   276,   277,   278,
     279,   280,   281,   287,   288,   289,   290,   291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "FLOAT", "INT", "VOID", "STRING",
  "INC_OP", "DEC_OP", "GE_OP", "LE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "TRUE", "FALSE", "RETURN", "PRINT", "IF", "ELSE", "FOR",
  "WHILE", "SEMICOLON", "QUOTA", "ID", "I_CONST", "F_CONST",
  "STRING_CONST", "'='", "'('", "')'", "'{'", "'}'", "'*'", "'/'", "'%'",
  "'>'", "'<'", "'+'", "'-'", "'!'", "','", "$accept", "program", "stat",
  "declaration", "print_func", "compound_stat", "$@1", "expression_stat",
  "selection_statement", "$@2", "$@3", "$@4", "while_statement", "$@5",
  "expression", "logic_expr", "comparison_expr", "add_expr", "mul_expr",
  "postfix_expr", "parenthesis_expr", "postfix_op", "mul_op",
  "relation_op", "addition_op", "logic_op", "assign_expression",
  "assign_op", "return_statement", "function_declaration", "$@6", "$@7",
  "declarator", "identifier_list", "declarator2", "identifier_list2",
  "initializer", "type", YY_NULLPTR
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
     285,   286,   287,   288,   289,    61,    40,    41,   123,   125,
      42,    47,    37,    62,    60,    43,    45,    33,    44
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,  -107,    95,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,   221,   -32,  -107,  -107,    -8,   -17,  -107,  -107,   221,
    -107,  -107,  -107,  -107,  -107,  -107,    32,  -107,   187,   -12,
       5,    63,    36,  -107,    84,  -107,  -107,  -107,  -107,     2,
    -107,   192,    82,     4,     7,    16,    19,   123,    58,    34,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   221,  -107,
    -107,  -107,   221,  -107,  -107,  -107,  -107,  -107,  -107,   221,
    -107,  -107,   221,  -107,  -107,  -107,   221,  -107,  -107,  -107,
     -15,  -107,    37,   221,   221,  -107,   203,    42,  -107,   131,
    -107,    67,    50,     5,    63,    36,  -107,  -107,   221,    74,
      92,   155,   160,  -107,    50,   -16,  -107,  -107,    75,  -107,
     212,    47,    67,  -107,    67,    67,  -107,   221,   221,  -107,
    -107,     8,    91,  -107,  -107,  -107,    50,   165,  -107,   141,
    -107,    67,    93,  -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     1,    85,    84,    83,    87,    86,    80,
      81,     0,     0,    19,    25,     0,    82,    77,    78,     0,
      13,     2,     5,     8,     6,     7,    15,    16,     0,    27,
      29,    31,    33,    35,    37,    28,    18,     9,    39,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    58,    59,    60,    61,    62,    17,    63,     0,    54,
      55,    56,     0,    48,    49,    50,    51,    46,    47,     0,
      52,    53,     0,    43,    44,    45,     0,    41,    42,    38,
      65,    64,     0,     0,     0,    79,     0,     0,    40,     0,
      23,     0,    57,    30,    32,    34,    36,    11,     0,     0,
       0,     0,     0,    74,    76,     0,    68,    14,     0,    22,
       0,     0,     0,    12,     0,     0,    73,     0,     0,    10,
      70,     0,     0,    66,    20,    26,    75,     0,    69,     0,
      72,     0,     0,    24,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,    81,  -107,  -107,  -107,   -90,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,   -11,  -107,    68,    80,    60,    89,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   108,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    21,    22,    23,    24,    48,    25,    26,    43,
      91,   108,    27,    44,    28,    29,    30,    31,    32,    33,
      34,    79,    76,    69,    72,    62,    35,    58,    36,    37,
      99,    46,   112,   121,    87,   105,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,   109,    59,    60,    42,   122,    -4,     1,    47,    -4,
      -4,    -4,    -4,    -4,    97,    63,    64,    65,    66,   -67,
      98,   116,   123,   132,   124,   125,    45,    -4,    -4,    -4,
      -4,    -4,   117,    80,    -4,    61,    -4,    -4,    -4,    -4,
      83,   133,    -4,    84,    -4,   128,    85,    92,    67,    68,
       4,     5,     6,     7,     8,    86,   129,    49,    50,     1,
      90,    -4,    -4,    -4,    -4,    -4,    51,    52,    53,    54,
      55,   106,   101,   102,   100,   104,    73,    74,    75,    -4,
      -4,    -4,    -4,    -4,   120,    57,    -4,   110,    -4,    -4,
      -4,    -4,    77,    78,    -4,     3,    -4,    -4,     4,     5,
       6,     7,     8,     9,    10,    20,   126,   127,    70,    71,
     111,   118,    15,    40,    17,    18,     9,    10,    11,    12,
      13,   113,   130,    14,   134,    15,    16,    17,    18,    89,
      93,    19,    95,    20,     4,     5,     6,     7,     8,    51,
      52,    53,    54,    55,     4,     5,     6,     7,     8,    94,
      82,     0,     9,    10,    11,    12,    13,     0,    57,    14,
      88,    15,    16,    17,    18,    96,     0,    19,     0,    20,
     107,    51,    52,    53,    54,    55,    51,    52,    53,    54,
      55,    51,    52,    53,    54,    55,     0,     0,     0,     0,
      57,     0,   114,     0,     0,    57,     0,   115,     0,     0,
      57,     0,   131,    51,    52,    53,    54,    55,    51,    52,
      53,    54,    55,     0,     0,     0,    56,     0,     0,     0,
       0,    81,    57,     0,     9,    10,     0,    57,    51,    52,
      53,    54,    55,    15,    40,    17,    18,     0,     0,    19,
     103,   119,     9,    10,     0,     0,     0,    57,     0,     0,
       0,    15,    40,    17,    18,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
      11,    91,    14,    15,    36,   111,     0,     1,    19,     3,
       4,     5,     6,     7,    29,    10,    11,    12,    13,    36,
      35,    37,   112,   129,   114,   115,    34,    21,    22,    23,
      24,    25,    48,    31,    28,    47,    30,    31,    32,    33,
      36,   131,    36,    36,    38,    37,    30,    58,    43,    44,
       3,     4,     5,     6,     7,    36,    48,    25,    26,     1,
      26,     3,     4,     5,     6,     7,    16,    17,    18,    19,
      20,    29,    83,    84,    37,    86,    40,    41,    42,    21,
      22,    23,    24,    25,    37,    35,    28,    98,    30,    31,
      32,    33,     8,     9,    36,     0,    38,    39,     3,     4,
       5,     6,     7,    21,    22,    38,   117,   118,    45,    46,
      36,    36,    30,    31,    32,    33,    21,    22,    23,    24,
      25,    29,    31,    28,    31,    30,    31,    32,    33,    48,
      62,    36,    72,    38,     3,     4,     5,     6,     7,    16,
      17,    18,    19,    20,     3,     4,     5,     6,     7,    69,
      42,    -1,    21,    22,    23,    24,    25,    -1,    35,    28,
      37,    30,    31,    32,    33,    76,    -1,    36,    -1,    38,
      39,    16,    17,    18,    19,    20,    16,    17,    18,    19,
      20,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      35,    -1,    37,    -1,    -1,    35,    -1,    37,    -1,    -1,
      35,    -1,    37,    16,    17,    18,    19,    20,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    29,    35,    -1,    21,    22,    -1,    35,    16,    17,
      18,    19,    20,    30,    31,    32,    33,    -1,    -1,    36,
      37,    29,    21,    22,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    50,     0,     3,     4,     5,     6,     7,    21,
      22,    23,    24,    25,    28,    30,    31,    32,    33,    36,
      38,    51,    52,    53,    54,    56,    57,    61,    63,    64,
      65,    66,    67,    68,    69,    75,    77,    78,    85,    86,
      31,    63,    36,    58,    62,    34,    80,    63,    55,    25,
      26,    16,    17,    18,    19,    20,    29,    35,    76,    14,
      15,    47,    74,    10,    11,    12,    13,    43,    44,    72,
      45,    46,    73,    40,    41,    42,    71,     8,     9,    70,
      31,    29,    85,    36,    36,    30,    36,    83,    37,    50,
      26,    59,    63,    65,    66,    67,    68,    29,    35,    79,
      37,    63,    63,    37,    63,    84,    29,    39,    60,    54,
      63,    36,    81,    29,    37,    37,    37,    48,    36,    29,
      37,    82,    86,    54,    54,    54,    63,    63,    37,    48,
      31,    37,    86,    54,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    51,    51,    51,
      52,    52,    53,    55,    54,    56,    56,    56,    56,    58,
      57,    59,    57,    60,    57,    62,    61,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    77,    79,    78,    80,    78,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     1,     1,     1,     1,
       5,     3,     5,     0,     4,     1,     1,     2,     1,     0,
       6,     0,     4,     0,     8,     0,     6,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     0,     5,     0,     4,     3,
       2,     4,     2,     3,     2,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1
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
        case 5:
#line 113 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "compiler_hw2.y" /* yacc.c:1646  */
    { lookup_symbol((yyvsp[-3].symbol_name), 1);  if(error_flag != 1) insert_symbol((yyvsp[-4].symbol_type), (yyvsp[-3].symbol_name), type_v);}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "compiler_hw2.y" /* yacc.c:1646  */
    { lookup_symbol((yyvsp[-1].symbol_name), 1);  if(error_flag != 1) insert_symbol((yyvsp[-2].symbol_type), (yyvsp[-1].symbol_name), type_v);}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "compiler_hw2.y" /* yacc.c:1646  */
    { /* create_symbol(); */}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "compiler_hw2.y" /* yacc.c:1646  */
    { dump_table(); dump_flag = 1;}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 246 "compiler_hw2.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-4].symbol_type), (yyvsp[-3].symbol_name), type_f); }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 249 "compiler_hw2.y" /* yacc.c:1646  */
    { lookup_function((yyvsp[0].symbol_name)); }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 260 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].symbol_type), (yyvsp[0].symbol_name), type_p);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    { insert_symbol((yyvsp[-1].symbol_type), (yyvsp[0].symbol_name), type_p);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "compiler_hw2.y" /* yacc.c:1646  */
    { lookup_symbol((yyvsp[0].symbol_name)); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 287 "compiler_hw2.y" /* yacc.c:1646  */
    { /* $$ = yylval.symbol_type; printf("$$ = %s", $$); */}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 288 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 289 "compiler_hw2.y" /* yacc.c:1646  */
    { /* $$ = yylval.symbol_type; */}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 290 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 291 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1604 "y.tab.c" /* yacc.c:1646  */
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
#line 294 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    create_symbol();
    /*
    table_current = create_symbol();  //global symbol_table
    table_header = table_current;
    */

    yyparse();
    if(syntax_flag != 0){
        // print syntax error msg
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, syntax_buf);
        printf("| %s","syntax error");
        printf("\n|-----------------------------------------------|\n\n");
        return 0;
    } 
    
    dump_table();
    dump_symbol();
    printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    if(!strcmp(s, "syntax error")){
        // printf("in syntax error");
        memset(syntax_buf, 0, sizeof(syntax_buf));
        strcpy(syntax_buf, buf);
        syntax_flag = 1;
        // printf(" btn %s, num = %d",buf, yylineno);
        
        return;
    }

    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s",s);
    printf("\n|-----------------------------------------------|\n\n");
    
}

void create_symbol() {
    //initialize symbol_table
    struct Table * ptr = malloc(sizeof(struct Table));

    ptr->table_depth = table_depth++;   //depth == scope
    ptr->entry_header = NULL;
    ptr->entry_current = ptr->entry_header;
    ptr->pre = table_current;

    table_current = ptr;

    if(table_header == NULL){
        table_header = table_current;
    }

    // printf("\n----in create_symbol, depth = %d, current = %p----\n", ptr->table_depth, table_current);
}

void insert_symbol(char *t, char* n, char* k) {
    
    struct Table *ptr = table_current; 
    struct Entry *e_ptr = malloc(sizeof(struct Entry));
    // printf("\n----in insert_symbol, %s, %s, %s, %d----\n", n, t, k, ptr->table_depth);
    
    if(ptr->entry_header == NULL){
        ptr->entry_header = e_ptr;
        e_ptr->entry_pre = NULL;
        e_ptr->entry_next = NULL;
        e_ptr->index = 0;
    }else{
        e_ptr->entry_pre = ptr->entry_current;
        ptr->entry_current->entry_next = e_ptr; 
        e_ptr->index = (ptr->entry_current->index) + 1;
    }
    
    ptr->entry_current = e_ptr;
    //initialize entry
    e_ptr->entry_next = NULL;
    e_ptr->scope = ptr->table_depth;
    memset(e_ptr->type, 0, sizeof(e_ptr->type));
    memset(e_ptr->kind, 0, sizeof(e_ptr->kind));
    memset(e_ptr->name, 0, sizeof(e_ptr->name));
    memset(e_ptr->attribute, 0, sizeof(e_ptr->attribute));

    strcpy(e_ptr->type, t);
    strcpy(e_ptr->kind, k);
    strcpy(e_ptr->name, n);  

    if(strcmp(k, "function") == 0){
        get_attribute(e_ptr);
    }
 
    // printf("\n++++%d, %s, %s, %s, %d++++\n", e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope);
}

void get_attribute(struct Entry * tmp){
    // get entry_attribute
    
    struct Entry *e_ptr = tmp;   //add function attribute
    struct Table *dump = table_dump;    //find parameter table
    struct Entry *e_dump = dump->entry_header; //find parameter entry

    while(e_dump != NULL){
        if(strcmp(e_dump->kind, "parameter") == 0){
            //put in function attribute
            if(strlen(e_ptr->attribute) != 0){  //attribute is not empty
                strcat(e_ptr->attribute, ", ");
            }
            strcat(e_ptr->attribute, e_dump->type);
        }
        e_dump = e_dump->entry_next;
    }

    // printf("\nin get_attribute = %s\n", e_ptr->attribute);
}

void lookup_symbol(char* name, int flag) {
    // printf("\nin lookup_symbol\n");
    //check semetic_error 

    if(flag == 1){  //check if Redeclared variable
        struct Entry *e_ptr = table_current->entry_header;
        while(e_ptr != NULL){
            if(strcmp(e_ptr->kind, "function") != 0 && strcmp(e_ptr->name, name) == 0){  // Redeclared variable !!!
                memset(error_msg, 0, sizeof(error_msg));
                strcat(error_msg, "Redeclared variable ");
                strcat(error_msg, name);
                error_flag = 1;
                break;
            }
            e_ptr = e_ptr->entry_next;
        }
    }else{      //check if Undeclared variable
        struct Table *ptr = table_current;
        while(ptr != NULL){
            struct Entry *e_ptr = ptr->entry_header;
            while(e_ptr != NULL){
                if(strcmp(e_ptr->kind, "function") != 0 && strcmp(e_ptr->name, name) == 0){ //declared variable
                    return;
                }
                /*
                printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
                   e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope, e_ptr->attribute);
                */
                e_ptr = e_ptr->entry_next;
            }
            ptr = ptr->pre;
        }
        // Undeclared variable !!!
        memset(error_msg, 0, sizeof(error_msg));
        strcat(error_msg, "Undeclared variable ");
        strcat(error_msg, name);
        error_flag = 1;
    }
}

void lookup_function(char *name){
    // printf("\nin lookup_function\n");
    struct Table * ptr = table_current;

    while(ptr != NULL){
        struct Entry * e_ptr = ptr->entry_header;
        while(e_ptr != NULL){
            if(strcmp(e_ptr->kind, "function") == 0 && strcmp(e_ptr->name, name)== 0 ){
                // printf("function declared !!!");
                return;
            }
            e_ptr = e_ptr->entry_next;
        }
        ptr = ptr->pre;
    }

    // printf("\nno declared\n");
    // printf("num = %d, buf = %s\n", yylineno, buf);
    memset(error_msg, 0, sizeof(error_msg));
    strcat(error_msg, "Undeclared function ");
    strcat(error_msg, name);
    error_flag = 1;

}
void dump_table(){
    table_dump = table_current;
    table_current = table_current->pre;
    table_depth --;
}
void dump_symbol() {
    // printf("\n----in dump_symbol\n");
    struct Table *ptr = table_dump;
    
    if(ptr->entry_header == NULL){ 
        //not entry, print nothing and drop the table
        // printf(", depth = %d, current = %p----\n", ptr->table_depth, ptr);
    }else{
        //print symbol_table && delete it
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
            "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        
        struct Entry *e_ptr = ptr->entry_header;
        while(e_ptr != NULL){
            printf("%-10d%-10s%-12s%-10s%-10d",
            e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope);
            if(strlen(e_ptr->attribute) != 0)
                printf("%s", e_ptr->attribute);
            
            printf("\n");
            e_ptr = e_ptr->entry_next;
        }
        printf("\n");
    
    }
}

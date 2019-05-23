/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 66 "compiler_hw2.y" /* yacc.c:1909  */

    int i_val;    //not use
    double f_val; //not use
    char* string; //not use
    char* symbol_name;  //return ID
    char* symbol_type;  //return type

#line 130 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/////////////



/*	Definition section */
%{
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token */
%token BOOL
%token FLOAT
%token INT
%token VOID
%token STRING
%token INC_OP DEC_OP GE_OP LE_OP EQ_OP NE_OP AND_OP OR_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token TRUE FALSE RETURN

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE 
%token ID SEMICOLON QUOTA

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING_CONST

/* Nonterminal with return, which need to sepcify type */
%type <f_val> stat

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat 
    | 
;

stat
    : declaration {}
    | compound_stat {}
    | expression_stat {}
    | print_func {}
;

declaration
    : type ID '=' expression
    | type ID SEMICOLON
;

print_func
    : PRINT '(' initializer ')' SEMICOLON
;

compound_stat
    : '{' '}'
    | '{' expression_stat '}'
    | '{' declaration '}'
    | '{' declaration expression_stat'}'
;

expression_stat
    : function_declaration expression_stat
    | selection_statement expression_stat 
    | while_statement expression_stat 
    | expression expression_stat
    | declaration expression_stat 
    | print_func expression_stat
    | return_statement expression_stat
    |
;

selection_statement
    : IF '(' expression ')' compound_stat selection_statement
    | ELSE compound_stat 
    | IF ELSE '(' expression ')' compound_stat selection_statement
    | 
;

while_statement
    : WHILE '(' expression ')' compound_stat
;


expression
    : expression_end expression_list
;

expression_end
    : initializer
    |
;

expression_list
    : assign_expression
    | relation_expression
    | arithmetic_expression
    | logic_expression
    | SEMICOLON 
    |
;

assign_expression
    : ADD_ASSIGN expression
    | SUB_ASSIGN expression
    | MUL_ASSIGN expression
    | DIV_ASSIGN expression
    | MOD_ASSIGN expression
    | '=' expression
;

relation_expression
    : '>' expression
    | '<' expression
    | GE_OP expression
    | LE_OP expression
    | EQ_OP expression
    | NE_OP expression
;

arithmetic_expression
    : '+' expression
    | '-' expression
    | '*' expression
    | '/' expression
    | '%' expression 
    | INC_OP expression
    | DEC_OP expression
;

logic_expression
    : AND_OP expression
    | OR_OP expression
    | '!' expression
;

return_statement
    : RETURN expression
;


function_declaration
    : type ID declarator compound_stat
    | ID declarator2 SEMICOLON
;

declarator
    : '(' identifier_list ')' declarator
    | '(' ')' declarator
    |
;

identifier_list
    : type ID ',' identifier_list
    | type ID
;

declarator2
    : '(' identifier_list2 ')' 
    | '(' ')'
    |
;

identifier_list2
    : initializer ',' identifier_list2
    | initializer
;

initializer
    : I_CONST
    | F_CONST
    | QUOTA STRING_CONST QUOTA
    | TRUE
    | FALSE
    | ID
;

/* actions can be taken when meet the token or rule */
/* $$ = yylval.val; */
type
    : INT {}
    | FLOAT {}
    | BOOL  {}
    | STRING {}
    | VOID {}
;

%%

/* C code section */
#include "stdio.h"

int main(int argc, char** argv)
{
    yylineno = 0;

    yyparse();
	printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
}

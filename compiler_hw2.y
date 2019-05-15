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
%token <i_val> '('

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
    | function_declaration {}
;

declaration
    : type expression SEMICOLON
    | type ID SEMICOLON
;

print_func
    : PRINT '(' initializer ')' SEMICOLON
;

compound_stat
    : '{' program '}'
;

expression_stat
    : selection_statement 
    | while_statement 
    | expression 
    | return_statement 
;

selection_statement
    : IF '(' expression ')' compound_stat 
    | selection_statement ELSE compound_stat 
    | selection_statement IF ELSE '(' expression ')' compound_stat 
;

while_statement
    : WHILE '(' expression ')' compound_stat
;


expression
    : expression expression_list expression_end 
    | initializer expression_spec SEMICOLON
    | initializer
    | '(' expression ')'
;

expression_spec
    : INC_OP 
    | DEC_OP 
;
expression_end
    : initializer
    | SEMICOLON
;

expression_list
    : assign_expression
    | relation_expression
    | arithmetic_expression
    | logic_expression
;

assign_expression
    : ADD_ASSIGN 
    | SUB_ASSIGN 
    | MUL_ASSIGN 
    | DIV_ASSIGN 
    | MOD_ASSIGN 
    | '=' 
;

relation_expression
    : '>' 
    | '<' 
    | GE_OP 
    | LE_OP 
    | EQ_OP 
    | NE_OP 
;

arithmetic_expression
    : '+' 
    | '-' 
    | '*' 
    | '/' 
    | '%'
;

logic_expression
    : AND_OP 
    | OR_OP 
    | '!' 
;

return_statement
    : RETURN expression SEMICOLON
;


function_declaration
    : type ID declarator compound_stat 
    | ID declarator2 SEMICOLON
;

declarator
    : '(' identifier_list ')' 
    | '(' ')' 
;

identifier_list
    : identifier_list ',' type ID
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

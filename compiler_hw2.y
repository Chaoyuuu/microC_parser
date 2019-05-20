/////////////Downloads new githubS

/*	Definition section */
%{
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

extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int error_flag; //1.redefined 2.undefined
extern char error_msg[256];
extern void yyerror(char *s);


/* Symbol table function - you can add new function if needed. */
void get_attribute();
void create_symbol();
void lookup_symbol();
void lookup_function();
void insert_symbol();
void dump_symbol();

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;    //not use
    double f_val; //not use
    char* string; //not use
    char* symbol_name;  //return ID
    char* symbol_type;  //return type
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
%token SEMICOLON QUOTA ID

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING_CONST 

/* Nonterminal with return, which need to sepcify type */
%type <f_val> stat 
// %type <string> declaration
%type <symbol_type> type
%type <symbol_name> ID

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
    : type ID '=' expression SEMICOLON 
        { lookup_symbol($2, 1); insert_symbol($1, $2, type_v);}
    | type ID SEMICOLON 
        { lookup_symbol($2, 1); insert_symbol($1, $2, type_v);}
;

print_func
    : PRINT '(' initializer ')' SEMICOLON
;

compound_stat
    : 
    '{'     { /* create_symbol(); */} 
    program 
    '}'     { dump_symbol(); }
;

expression_stat
    : selection_statement compound_stat 
    | while_statement 
    | expression SEMICOLON
    | return_statement 
;

selection_statement
    : error ')'
    | IF { create_symbol(); }
      '(' expression ')' 
    | selection_statement 
      ELSE { create_symbol(); } 
    | selection_statement
      IF ELSE { create_symbol(); }
      '(' expression ')' 
;

while_statement
    : WHILE 
        { create_symbol(); }
    '(' expression ')' compound_stat 
;


expression
    : logic_expr
    | assign_expression
;

logic_expr
    : comparison_expr
    | logic_expr logic_op comparison_expr
;

comparison_expr
    : add_expr
    | comparison_expr relation_op add_expr
;

add_expr
    : mul_expr
    | add_expr addition_op mul_expr
;

mul_expr
    : postfix_expr
    | mul_expr mul_op postfix_expr
;

postfix_expr
    : parenthesis_expr
    | parenthesis_expr postfix_op
;

parenthesis_expr
    : initializer
    | '(' expression ')'
;

postfix_op
    : INC_OP 
    | DEC_OP 
;

mul_op
    : '*' 
    | '/' 
    | '%'
;

relation_op
    : '>' 
    | '<' 
    | GE_OP 
    | LE_OP 
    | EQ_OP 
    | NE_OP 
;

addition_op
    : '+' 
    | '-' 
;

logic_op
    : AND_OP 
    | OR_OP 
    | '!' 
;

assign_expression
    : expression assign_op expression 
;

assign_op
    : ADD_ASSIGN 
    | SUB_ASSIGN 
    | MUL_ASSIGN 
    | DIV_ASSIGN 
    | MOD_ASSIGN 
    | '=' 
;
return_statement
    : RETURN expression SEMICOLON
;


function_declaration
    : type ID { create_symbol(); }
      declarator compound_stat 
      { insert_symbol($1, $2, type_f); }
    | ID  { lookup_function($1); }
      declarator2 SEMICOLON 
;

declarator
    : '(' identifier_list ')' 
    | '(' ')' 
;

identifier_list
    : identifier_list ',' type ID 
        { get_attribute($3); insert_symbol($3, $4, type_p);}
    | type ID
        { get_attribute($1); insert_symbol($1, $2, type_p);}
;

declarator2
    : '(' identifier_list2 ')' 
    | '(' ')'
;

identifier_list2
    : identifier_list2 ',' initializer 
    | expression
;

initializer
    : I_CONST 
    | F_CONST
    | QUOTA STRING_CONST QUOTA
    | TRUE
    | FALSE
    | ID { lookup_symbol($1); }
;

/* actions can be taken when meet the token or rule */
/* $$ = yylval.val; */
type
    : INT { /* $$ = yylval.symbol_type; printf("$$ = %s", $$); */}
    | FLOAT {}
    | BOOL  { /* $$ = yylval.symbol_type; */}
    | STRING {}
    | VOID {}
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    create_symbol();
    /*
    table_current = create_symbol();  //global symbol_table
    table_header = table_current;
    */

    printf("1: ");  
    yyparse();
    if(error_flag != 3){
        dump_symbol();
        printf("\nTotal lines: %d \n",yylineno);

    }

    return 0;
}

void yyerror(char *s)
{
    /*
    if(!strcmp(s, "syntax error") && error_flag == 0){
        error_flag = 4;
        return;
    }
    */

    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s", yylineno, buf);
    printf("| %s",s);
    printf("\n|-----------------------------------------------|\n\n");

    return;
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
    //e_ptr->attribute = NULL;

    // printf("\n++++%d, %s, %s, %s, %d++++\n", e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope);
}

void get_attribute(char *t){
    // get entry_attribute
    struct Table *ptr = table_current->pre;
    struct Entry *e_ptr = ptr->entry_current;

    if(strlen(e_ptr->attribute) != 0){
        strcat(e_ptr->attribute, ", ");
    }
    strcat(e_ptr->attribute, t);

    // printf("\nin get_attribute = %s\n", e_ptr->attribute);
}

void lookup_symbol(char* name, int flag) {
    //printf("\nin lookup_symbol\n");
    //check semetic_error 

    if(flag == 1){  //check if Redeclared variable
        struct Entry *e_ptr = table_current->entry_header;
        while(e_ptr != NULL){
            if(!strcmp(e_ptr->name, name)){
                // printf("\nRedeclared variable !!!\n");
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
            // printf("\nthe depth = %d\n", ptr->table_depth);
            struct Entry *e_ptr = ptr->entry_header;
            while(e_ptr != NULL){
                if(!strcmp(e_ptr->name, name)){
                    // printf("OK\n");
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
        // printf("\nUndeclared variable !!!\n");
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
                printf("function declared !!!");
                return;
            }
            e_ptr = e_ptr->entry_next;
        }
        ptr = ptr->pre;
    }

    printf("\nno declared\n");
    memset(error_msg, 0, sizeof(error_msg));
    strcat(error_msg, "Undeclared function ");
    strcat(error_msg, name);
    error_flag = 1;
    
}

void dump_symbol() {
    // printf("\n----in dump_symbol");

    struct Table *ptr = table_current;
    if(ptr->entry_header == NULL){ 
        //not entry, print nothing and drop the table
        // printf(", depth = %d, current = %p----\n", ptr->table_depth, ptr);
    }else{
        //print symbol_table && delete it
        printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
            "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        
        struct Entry *e_ptr = ptr->entry_header;
        while(e_ptr != NULL){
            printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
            e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope, e_ptr->attribute);

            e_ptr = e_ptr->entry_next;
        }
    
    }

    table_current = ptr->pre;
    table_depth --;
}


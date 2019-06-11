/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
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
    // int type;
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

int func_flag = 0;

/* Symbol table function - you can add new function if needed. */
void get_attribute(struct Entry * tmp);
void create_symbol();
void lookup_symbol();
void lookup_function();
void insert_symbol();
void dump_symbol();
void dump_table();

/* expression function */
// Value do_assign();
Value switch_mul_op();
Value switch_addition_op();
Value switch_postfix_op();


//arithmetic
Value mul_arith(Value v1, Value v2);
Value div_arith(Value v1, Value v2);
Value mod_arith(Value v1, Value v2);
Value add_arith(Value v1, Value v2);
Value minus_arith(Value v1, Value v2);



%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    
    Value val;
    Operator op;

}

/* Token */
%token BOOL FLOAT INT VOID STRING
%token INC_OP DEC_OP GE_OP LE_OP EQ_OP NE_OP AND_OP OR_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token TRUE FALSE RETURN 
%token PRINT 
%token IF ELSE FOR WHILE 
%token SEMICOLON QUOTA 

/* Token with return, which need to sepcify type */
%token <val> I_CONST
%token <val> F_CONST
%token <val> STRING_CONST 
%token <val> ID


%type <val> type initializer 
%type <val> expression logic_expr comparison_expr add_expr mul_expr 
%type <val> postfix_expr parenthesis_expr assign_expression 
%type <op>  postfix_op mul_op relation_op addition_op logic_op assign_op 

/* Yacc will start at this nonterminal */
%start program 

/* Grammar section */
%%

program
    : program stat 
    | error
    |
;

stat
    : declaration 
    | compound_stat
    | expression_stat
    | print_func 
    | function_declaration
;

declaration
    : type ID '=' expression SEMICOLON 
        { lookup_symbol($2.id_name, 1); if(error_flag != 1) insert_symbol($1.symbol_type, $2.id_name, type_v); }
    | type ID SEMICOLON 
        { lookup_symbol($2.id_name, 1); if(error_flag != 1) insert_symbol($1.symbol_type, $2.id_name, type_v); }
;

print_func
    : PRINT '(' initializer ')' SEMICOLON
;

compound_stat
    : 
    '{'      
    program 
    '}'     { dump_table(); dump_flag = 1;}
;

expression_stat
    : selection_statement 
    | while_statement 
    | expression SEMICOLON
    | return_statement 
;

selection_statement
    : IF { create_symbol(); }
      '(' expression ')' compound_stat
    | /* selection_statement */
      ELSE { create_symbol(); } compound_stat
    | /* selection_statement */
      ELSE IF{ create_symbol(); }
      '(' expression ')' compound_stat
;

while_statement
    : WHILE                                 
      { create_symbol(); }
     '(' expression ')' compound_stat 
;


expression
    : logic_expr {}
    | assign_expression {}
;

logic_expr
    : comparison_expr                       {}
    | logic_expr logic_op comparison_expr   {}
;

comparison_expr
    : add_expr {}
    | comparison_expr relation_op add_expr {}
;

add_expr
    : mul_expr {}
    | add_expr addition_op mul_expr { $$ = switch_addition_op($1, $2, $3); }
;

mul_expr
    : postfix_expr {}
    | mul_expr mul_op postfix_expr { $$ = switch_mul_op($1, $2, $3); }
;

postfix_expr
    : parenthesis_expr {}
    | parenthesis_expr postfix_op { $$ = switch_postfix_op($1, $2); }
;

parenthesis_expr
    : initializer {}
    | ID { lookup_function($1.id_name, 1); }
      declarator2 {}
    | '(' expression ')' { $$ = $2; }
;

postfix_op
    : INC_OP    { $$ = INC_OPT; }
    | DEC_OP    { $$ = DEC_OPT; }
;

mul_op
    : '*'   { $$ = MUL_OPT; }
    | '/'   { $$ = DIV_OPT; }
    | '%'   { $$ = MOD_OPT; }
;

relation_op
    : '>'   { $$ = MORE_OPT; }
    | '<'   { $$ = LESS_OPT; }
    | GE_OP { $$ = GE_OPT; }
    | LE_OP { $$ = LE_OPT; }
    | EQ_OP { $$ = EQ_OPT; }
    | NE_OP { $$ = NE_OPT; }
;

addition_op
    : '+'   { $$ = ADD_OPT; }
    | '-'   { $$ = MINUS_OPT; }
;

logic_op
    : AND_OP { $$ = AND_OPT; }
    | OR_OP  { $$ = OR_OPT; }
    | '!'    { $$ = NOT_OPT; }
;

assign_expression
    : expression assign_op expression { /* do_assign($1, $2, $3); */ printf("**** %d $d\n", $2);}
;

assign_op
    : ADD_ASSIGN { $$ = ADD_ASSIGN_OPT; }
    | SUB_ASSIGN { $$ = SUB_ASSIGN_OPT; }
    | MUL_ASSIGN { $$ = MUL_ASSIGN_OPT; }
    | DIV_ASSIGN { $$ = DIV_ASSIGN_OPT; }
    | MOD_ASSIGN { $$ = MOD_ASSIGN_OPT; }
    | '='        { $$ = ASSIGN_OPT; }
;
return_statement
    : RETURN expression SEMICOLON
    | RETURN SEMICOLON
;

function_declaration
    : type ID declarator compound_stat 
      { lookup_function($2.id_name, 3); 
        if(func_flag != 1) 
            insert_symbol($1.symbol_type, $2.id_name, type_f);
        func_flag = 0;
      }
    | type ID declarator SEMICOLON
      { dump_table(); 
        lookup_function($2.id_name, 2); 
        if(error_flag != 1) 
            insert_symbol($1.symbol_type, $2.id_name, type_f);
      }
;

declarator
    : '(' { create_symbol(); }
      identifier_list ')'  
    | '(' { create_symbol(); }
      ')'
;

identifier_list
    : identifier_list ',' type ID 
        { insert_symbol($3.symbol_type, $4.id_name, type_p); }
    | type ID
        { insert_symbol($1.symbol_type, $2.id_name, type_p); }
;

declarator2
    : '(' identifier_list2 ')' 
    | '(' ')'
;

identifier_list2
    : identifier_list2 ',' expression 
    | expression
;

initializer
    : I_CONST /*neg_const I_CONST */ { $$ = yylval.val; } 
    | F_CONST /*neg_const F_CONST */ { $$ = yylval.val; }
    | QUOTA STRING_CONST QUOTA { $$ = yylval.val; }
    | TRUE  { }
    | FALSE { }
    | ID { lookup_symbol($1.id_name, 2); $$ = yylval.val; }
;

/* neg_const
    : '-'
    |
; */

/* actions can be taken when meet the token or rule */
/* $$ = yylval.val; */
type
    : INT   { $$ = yylval.val; }
    | FLOAT { $$ = yylval.val; }
    | BOOL  { $$ = yylval.val; }
    | STRING{ $$ = yylval.val; }
    | VOID  { $$ = yylval.val; }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    create_symbol();
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

    printf("\n----in create_symbol, depth = %d, current = %p----\n", ptr->table_depth, table_current);
}

void insert_symbol(Symbol_type t, char* n, char* k) {
   
    struct Table *ptr = table_current; 
    struct Entry *e_ptr = malloc(sizeof(struct Entry));
    
    printf("\n----in insert_symbol, %d, %s, %s, %d----\n", t, n, k, ptr->table_depth);
   
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

    // strcpy(e_ptr->type, t);
    strcpy(e_ptr->kind, k);
    strcpy(e_ptr->name, n);  
    // e_ptr->type = t;

    switch (t){
        case V_Type:
            strcpy(e_ptr->type, "void");
            break;
        case I_Type:
            strcpy(e_ptr->type, "int");
            break;
        case F_Type:
            strcpy(e_ptr->type, "float");
            break;
        case S_Type:
            strcpy(e_ptr->type, "String");
            break;
        case ID_Type:
            strcpy(e_ptr->type, "ID");
            break;
        case B_Type:
            strcpy(e_ptr->type, "bool");
            break;
        default:
            printf("wrong input in type");
            break;
    }

    if(strcmp(k, "function") == 0){
        get_attribute(e_ptr);
    }
 
    printf("\n++++%d, %s, %s, %s, %d++++\n", e_ptr->index, e_ptr->name, e_ptr->kind, e_ptr->type, e_ptr->scope);
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

void lookup_function(char *name, int flag){
    // printf("\nin lookup_function\n");

    struct Table * ptr = table_current;

    if(flag == 1){   //Undeclared function
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
    }else{   //redeclared function
        struct Entry * e_ptr = ptr->entry_header;
        while(e_ptr != NULL){
            if(strcmp(e_ptr->kind, "function") == 0 && strcmp(e_ptr->name, name)== 0){
                // redeclared
                memset(error_msg, 0, sizeof(error_msg));
                strcat(error_msg, "Redeclared function ");
                strcat(error_msg, name); 
                if(flag == 3)
                    func_flag = 1;
                else
                    error_flag = 1;
                return;
            }
            e_ptr = e_ptr->entry_next;
        }    

    }

}
void dump_table(){
    // printf("\n----in dump_table, depth = %d, current = %p----\n", table_current->table_depth, table_current);
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


//expression function
// Value do_assign(Value v1, char *op, Value v2){
//     printf("in do_assign, %s", op);
// }

Value switch_mul_op(Value v1, Operator op, Value v2){
    printf("in switch_mul_op\n");
    
    switch (op){
        case MUL_OPT:
            return mul_arith(v1, v2);            
        case DIV_OPT:
            return div_arith(v1, v2);
        case MOD_OPT:
            // return mod_arirh(v1, v2);
            printf("in MOD_arith\n");
            break;
        default:
            printf("wrong case in mul_arith\n");
            break;
    }

}

Value switch_addition_op(Value v1, Operator op, Value v2){
    printf("in switch_addition_op\n");
    switch (op) {
        case ADD_OPT:
            return add_arith(v1, v2);
        case MINUS_OPT:
            return minus_arith(v1, v2);
        default:
            printf("wrong case in addition_op\n");
            break;
    }
}

Value switch_postfix_op(Value v1, Operator op){
    printf("in switch_postfix_op\n");
    Value tmp;
    tmp.symbol_type = I_Type;
    tmp.i = 1;

    switch (op){
        case INC_OPT:
            return add_arith(v1, tmp);
        case DEC_OPT:
            return minus_arith(v1, tmp);
        default:
            printf("wrong case in postfix_op\n");
            break;
    }
}

//arithmetic function
Value mul_arith(Value v1, Value v2){
    printf("in mul_arith\n");
    Value v_tmp;
    // memset(v_tmp, 0, sizeof(v_tmp));

    if(v1.symbol_type == I_Type && v2.symbol_type == I_Type){
        v_tmp.symbol_type = I_Type;
        v_tmp.i = (v1.i)*(v2.i);
    }else{
        v_tmp.symbol_type = F_Type;
        v_tmp.f = (v1.f)*(v2.f);
    }
    return v_tmp;
}

Value div_arith(Value v1, Value v2){
    printf("in div_arith\n");
    Value v_tmp;

    if(v2.i == 0){
        printf("v2 cannot be zero !!!");
        //yyerror;
        return v1;
    }

    if(v1.symbol_type == I_Type && v2.symbol_type == I_Type){
        v_tmp.symbol_type = I_Type;
        v_tmp.i = (v1.i)/(v2.i);
    }else{
        v_tmp.symbol_type = F_Type;
        v_tmp.f = (v1.f)/(v2.f);
    }
    return v_tmp;
}

Value mod_arith(Value v1, Value v2){
    printf("in mod_arith\n");
    Value v_tmp;

    if(v1.symbol_type == I_Type && v2.symbol_type == I_Type){
        v_tmp.symbol_type = I_Type;
        v_tmp.i = (v1.i)%(v2.i);
        return v_tmp;
    }else{
        printf("v1 v2 need to be I_Type\n");
        //yyerror();
       v_tmp = v1;
    }
    return v_tmp;
}

Value add_arith(Value v1, Value v2){
    printf("in add_arith\n");
    Value v_tmp;

    if(v1.symbol_type == I_Type && v2.symbol_type == I_Type){
        v_tmp.symbol_type = I_Type;
        v_tmp.i = (v1.i)+(v2.i);
    }else{
        v_tmp.symbol_type = F_Type;
        v_tmp.f = (v1.f)+(v2.f);
    }
    return v_tmp;

}

Value minus_arith(Value v1, Value v2){
    printf("in minus_arith\n");
    Value v_tmp;

    if(v1.symbol_type == I_Type && v2.symbol_type == I_Type){
        v_tmp.symbol_type = I_Type;
        v_tmp.i = (v1.i)-(v2.i);
    }else{
        v_tmp.symbol_type = F_Type;
        v_tmp.f = (v1.f)-(v2.f);
    }
    return v_tmp;
}
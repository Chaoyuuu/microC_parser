/* Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"	/* header file generated by bison */
#define BUF_SIZE 256

extern YYSTYPE yylval; //YYSTYPE
extern void yyerror(char *s);
extern void dump_symbol();

char buf[BUF_SIZE];
char error_msg[BUF_SIZE];
char syntax_buf[BUF_SIZE];

/* This macro is used to record code line */
#define CONCAT { strncat(buf, yytext, BUF_SIZE - strlen(buf) - 1); }

int line_num = 1;
int error_flag = 0;
int syntax_flag = 0;
int dump_flag = 0;

%}

/* Define regular expression label */
digit		[0-9]
letter		[a-zA-Z]
integer     {digit}+
float       {digit}+"."{digit}+
id			{letter}+({letter}|{digit})*

%option yylineno

%x COMMENT STRING_STATE

/* Rules section */
%%

 /* Arithmetic */
"+"     { CONCAT; return('+'); }
"-" 	{ CONCAT; return('-'); }
"*" 	{ CONCAT; return('*'); }
"/" 	{ CONCAT; return('/'); }
"%"     { CONCAT; return('%'); }
"++"    { CONCAT; return(INC_OP); }
"--"    { CONCAT; return(DEC_OP); }

 /* Relational */
">"		{ CONCAT; return('>'); }
"<"		{ CONCAT; return('<'); }
">="	{ CONCAT; return(GE_OP); }
"<="	{ CONCAT; return(LE_OP); }
"=="	{ CONCAT; return(EQ_OP); }
"!="	{ CONCAT; return(NE_OP); }

 /* Assignment */
"="		{ CONCAT; return('='); }
"+="	{ CONCAT; return(ADD_ASSIGN); }
"-="	{ CONCAT; return(SUB_ASSIGN); }
"*="	{ CONCAT; return(MUL_ASSIGN); }
"/="	{ CONCAT; return(DIV_ASSIGN); }
"%="	{ CONCAT; return(MOD_ASSIGN); }

 /* Logical */
"&&"	{ CONCAT; return(AND_OP); }
"||"	{ CONCAT; return(OR_OP); }
"!"		{ CONCAT; return('!'); }

 /* Delimiters */
"("		{ CONCAT; return('('); }
")"		{ CONCAT; return(')'); }
"{"		{ CONCAT; return('{'); }
"}"		{ CONCAT; return('}'); }
"["		{ CONCAT; return('['); }
"]"		{ CONCAT; return(']'); }
","		{ CONCAT; return(','); }

 /* Print Keywords */	
"print"		{ CONCAT; return(PRINT);  }

 /* Condition and Loop Keywords */
"if"		{ CONCAT; return(IF); }
"else"		{ CONCAT; return(ELSE); }
"for"		{ CONCAT; return(FOR); }
"while"		{ CONCAT; return(WHILE); }

 /* Declaration Keywords */
"void"		{ CONCAT; yylval.symbol_type = "void"; return(VOID); }
"int"		{ CONCAT; yylval.symbol_type = "int"; return(INT);}
"float"  	{ CONCAT; yylval.symbol_type = "float"; return(FLOAT);}
"string"  	{ CONCAT; yylval.symbol_type = "string"; return(STRING);}
"bool"  	{ CONCAT; yylval.symbol_type = "bool"; return(BOOL);}

 /* boolean Keywords */
"true"      { CONCAT; return(TRUE); }
"false"     { CONCAT; return(FALSE); }

"return"    { CONCAT; return(RETURN); }

 /* String Constant */
\"				        { CONCAT; BEGIN STRING_STATE; return(QUOTA);}
<STRING_STATE>\"		{ CONCAT; BEGIN INITIAL; return(QUOTA);}
<STRING_STATE>[^"]*		{ CONCAT; return(STRING_CONST);}

 /* Number Constant */
{integer}	{ CONCAT; yylval.i_val = atoi(yytext); return(I_CONST); }
{float}	    { CONCAT; return(F_CONST); }

 /* C type Comment */
"/*"				{ CONCAT; BEGIN COMMENT; }
<COMMENT>[^*\n]+	{ CONCAT; }
<COMMENT>\n			{  
                      printf("%d:", line_num);
                      printf(" %s", buf); 
                    printf("\n"); 
                      line_num++; 
                      memset(buf, 0, BUF_SIZE);
                    }
<COMMENT>"*"		{ CONCAT;  }
<COMMENT>"*/"		{ CONCAT; BEGIN INITIAL; }

 /* C++ type Comment */
\/\/.*	{ CONCAT; }

 /* Variable ID */
 {id}       { CONCAT; yylval.symbol_name = strdup(yytext); return(ID); }

 /* others */

[;]         { CONCAT; return(SEMICOLON); }
[\n]        {  printf("%d:", line_num);
               if(strlen(buf) != 0){
                    printf(" %s", buf);
                } 
                printf("\n");

                if(error_flag != 0){
                    yyerror(error_msg);
                    error_flag = 0;
                 }

                //if syntax_error, close parser
                if(syntax_flag != 0){
                    yyterminate();
                } 
    
                if(dump_flag == 1){
                    dump_symbol();
                    dump_flag = 0;
                }

                memset(buf, 0, BUF_SIZE);
                line_num++;
            }
[ \t]		{ CONCAT; } /* Ignore */
[^ \t\n] 	{ CONCAT; } /* Ignore other charactor sets */
<<EOF>>     { 
                yyterminate();}

%%

int yywrap()
{
    return 1 ;
}
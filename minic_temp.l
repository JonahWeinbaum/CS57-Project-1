/* minic.l */

%{
    #include "minic.tab.h"
    #include "ast_c/ast.h"
    #include <stdio.h>
    #include <string.h>
    extern YYSTYPE yylval;

%}

%option warn noyywrap noinput nounput nodefault

INT     "int"
VOID    "void"
EXTERN  "extern"
IF      "if"
ELSE    "else"
RET     "return"
WHILE   "while"
ADD     "+"
SUB     "-"
MULT    "*"
DIV     "/"
SEMI    ";"
EQEQ    "=="
GEQ     ">="
LEQ     "<="
LESS    "<"
GREAT   ">"
NEQ     "!="
LBRACK  "{"
RBRACK  "}"
LPAR    "("
RPAR    ")"
COMMA   ","
EQ      "="
NAME    [a-zA-Z][a-zA-Z0-9_]*
NUM     [0-9][0-9]*
SPACE   [ \t]
NL      [\n\r] 

%%

{INT}                           { printf("INT - %s\n", yytext); yylval.element_val.type = INT_TYPE; return INT; } 
{VOID}                          { printf("VOID - %s\n", yytext); yylval.element_val.type = VOID_TYPE; return VOID; } 
{EXTERN}                        { printf("EXTERN - %s\n", yytext); return EXTERN; }
{RET}                           { printf("RET - %s\n", yytext); return RET; }
{WHILE}                         { printf("WHILE - %s\n", yytext); return WHILE; }
{ADD}                           { printf("ADD - %s\n", yytext);  return ADD; }
{SUB}                           { printf("SUB - %s\n", yytext); return SUB; }
{MULT}                          { printf("MULT - %s\n", yytext); return MULT; }
{DIV}                           { printf("DIV - %s\n", yytext); return DIV; }
{IF}                            { printf("IF - %s\n", yytext); return IF; }
{ELSE}                          { printf("ELSE - %s\n", yytext); return ELSE; }
{SEMI}                          { printf("SEMI - %s\n", yytext); return SEMI; }
{EQEQ}                          { printf("EQEQ - %s\n", yytext); return EQEQ; }
{GEQ}                           { printf("GEQ - %s\n", yytext); return GEQ; }
{LEQ}                           { printf("LEQ - %s\n", yytext); return LEQ; }
{LESS}                          { printf("LESS - %s\n", yytext); return LESS; }
{GREAT}                         { printf("GREAT - %s\n", yytext); return GREAT; }
{NEQ}                           { printf("NEQ - %s\n", yytext); return NEQ; }
{LBRACK}                        { printf("LBRACK - %s\n", yytext); return LBRACK; }
{RBRACK}                        { printf("RBRACK - %s\n", yytext); return RBRACK; }
{LPAR}                          { printf("LPAR - %s\n", yytext); return LPAR; }
{RPAR}                          { printf("RPAR - %s\n", yytext); return RPAR; }
{COMMA}                         { printf("COMMA - %s\n", yytext); return COMMA; }
{EQ}                            { printf("EQ - %s\n", yytext); return EQ; }
{NUM}                           { printf("NUM - %s\n", yytext); yylval.element_val.ASTIntLiteralNode = new ASTIntLiteralNode(atoi(yytext)); return NUM; }
{NAME}                          { printf("NAME - %s\n", yytext); yylval.element_val.name = strdup(yytext); return NAME;}
{SPACE}+                        
{NL}+                          

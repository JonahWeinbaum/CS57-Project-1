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

{INT}                           { yylval.element_val.type = INT_TYPE; return INT; } 
{VOID}                          { yylval.element_val.type = VOID_TYPE; return VOID; } 
{EXTERN}                        { return EXTERN; }
{RET}                           { return RET; }
{WHILE}                         { return WHILE; }
{ADD}                           { return ADD; }
{SUB}                           { return SUB; }
{MULT}                          { return MULT; }
{DIV}                           { return DIV; }
{IF}                            { return IF; }
{ELSE}                          { return ELSE; }
{SEMI}                          { return SEMI; }
{EQEQ}                          { return EQEQ; }
{GEQ}                           { return GEQ; }
{LEQ}                           { return LEQ; }
{LESS}                          { return LESS; }
{GREAT}                         { return GREAT; }
{NEQ}                           { return NEQ; }
{LBRACK}                        { return LBRACK; }
{RBRACK}                        { return RBRACK; }
{LPAR}                          { return LPAR; }
{RPAR}                          { return RPAR; }
{COMMA}                         { return COMMA; }
{EQ}                            { return EQ; }
{NUM}                           { yylval.element_val.ASTIntLiteralNode = new ASTIntLiteralNode(atoi(yytext)); return NUM; }
{NAME}                          { yylval.element_val.name = strdup(yytext); return NAME;}
{SPACE}+                        
{NL}+                          

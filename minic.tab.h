/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "minic_temp.y"

  #define MAX_PARAMS 6
  #define MAX_VAR_DECS 100

  #include "ast_c++/ast.hpp"
  #include "hash/hashtable.h"

  using namespace std;

  typedef enum type {
    INT_TYPE = 0,
    VOID_TYPE = 1
  } type_t;

  typedef struct params {
    type_t params[MAX_PARAMS];
    int size; 
  } params_t;

  typedef struct fnc_dec {
    const char* fnc_name;
    params_t param_list;
    type_t ret_type; 
  } fnc_dec_t;

  //Stores all necessary objects plus a node for
  //each element
  typedef struct object_node {
    ASTAsgnNode *ASTAsgnNode;
    ASTVarNode *ASTVarNode;
    ASTIntLiteralNode *ASTIntLiteralNode;
    ASTBExprNode *ASTBExprNode;
    ASTRExprNode *ASTRExprNode;
    ASTUExprNode *ASTUExprNode;
    ASTRetNode *ASTRetNode;
    ASTExprNode *ASTExprNode; 
    ASTCallNode* ASTCallNode; 

    type_t type;
    char* name;
    fnc_dec_t fnc_dec;
    params_t params;
    r_op_t   rop;
  } type_node_t;


  //Helper Functions
  void var_dec(hashtable_t* var_decs, const char *var_name, type_t var_type);
  bool var_dec_check(hashtable_t* var_decs, const char *var_name);
  void fnc_dec(hashtable_t* fnc_decs, const char *fnc_name, type_t ret_type, params_t param_list);
  bool fnc_dec_check(hashtable_t* fnc_decs, const char *fnc_name, params_t params);
  bool type_check(type_t expr1, type_t expr2);
  bool assignment_check(hashtable_t* var_decs, const char* var, type_t expr2);
  void varprint(FILE* fp, const char* key, void* item);
  void fncprint(FILE* fp, const char* key, void* item);
  string *convertToString(char* a);

#line 107 "minic.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    VOID = 259,                    /* VOID  */
    EXTERN = 260,                  /* EXTERN  */
    RET = 261,                     /* RET  */
    WHILE = 262,                   /* WHILE  */
    ADD = 263,                     /* ADD  */
    SUB = 264,                     /* SUB  */
    MULT = 265,                    /* MULT  */
    DIV = 266,                     /* DIV  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    SEMI = 269,                    /* SEMI  */
    EQEQ = 270,                    /* EQEQ  */
    GEQ = 271,                     /* GEQ  */
    LEQ = 272,                     /* LEQ  */
    LESS = 273,                    /* LESS  */
    GREAT = 274,                   /* GREAT  */
    NEQ = 275,                     /* NEQ  */
    LBRACK = 276,                  /* LBRACK  */
    RBRACK = 277,                  /* RBRACK  */
    LPAR = 278,                    /* LPAR  */
    RPAR = 279,                    /* RPAR  */
    COMMA = 280,                   /* COMMA  */
    EQ = 281,                      /* EQ  */
    NUM = 282,                     /* NUM  */
    NAME = 283                     /* NAME  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 82 "minic_temp.y"

  const char* str_val;
  object_node element_val;

#line 157 "minic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */

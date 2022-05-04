%{
  #include "ast_c++/ast.hpp"
  #include "hash/hashtable.h"
  #include <string.h>
  #include <vector>

  using namespace std;

  //Yacc Parameters
  extern int yylex(void);
  extern FILE *yyin;
  extern int yy_flex_debug;
  void yyerror(char *s) {};

  //Global Variables
  hashtable_t *var_decs;
  hashtable_t *fnc_decs;

  //Root note
  ASTRootNode root = ASTRootNode(nullptr, nullptr, nullptr);
%}

//Data Types
%code requires {
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
}

%union {
  const char* str_val;
  object_node element_val;
}

//Nonterminal Types
%type <element_val> type
%type <element_val> params
%type <element_val> param_decs
%type <element_val> param_dec
%type <element_val> fnc_dec
%type <element_val> expr
%type <element_val> bin_expr
%type <element_val> unr_expr
%type <element_val> assignment
%type <element_val> conditional
%type <element_val> comparator
%type <element_val> fnc_call
%type <element_val> ret




//Tokens
%token <element_val> INT
%token <element_val> VOID
%token EXTERN
%token RET
%token WHILE
%token ADD
%token SUB
%token MULT
%token DIV
%token IF
%token ELSE
%token SEMI
%token EQEQ
%token GEQ
%token LEQ
%token LESS
%token GREAT
%token NEQ
%token LBRACK
%token RBRACK
%token LPAR
%token RPAR
%token COMMA
%token EQ
%token <element_val> NUM
%token <element_val> NAME

//Precedence Rules
%left ADD SUB
%left MULT DIV

%start file

%%

//Start rule
file: 
      fncs          
    | fnc_decs fncs 
    ;

//Function Declaration definitions
fnc_decs:
          fnc_dec SEMI
        | fnc_decs fnc_dec SEMI
        ;

fnc_dec: 
         EXTERN type NAME LPAR param_decs RPAR { $$.fnc_dec.fnc_name = $3.name; fnc_dec(fnc_decs, $3.name, $2.type, $5.params);}
       | type NAME LPAR param_decs RPAR        { $$.fnc_dec.fnc_name = $2.name; fnc_dec(fnc_decs, $2.name, $1.type, $4.params);}
       | EXTERN type NAME LPAR RPAR            { $$.fnc_dec.fnc_name = $3.name; params_t param; fnc_dec(fnc_decs, $3.name, $2.type, param);}
       | type NAME LPAR RPAR                   { $$.fnc_dec.fnc_name = $2.name; params_t param; fnc_dec(fnc_decs, $2.name, $1.type, param);}
       ;

param_decs:
            param_dec                   {$$.params.params[$$.params.size++] = $1.type;}
          | param_decs COMMA param_dec  {
                                          for (int i = 0; i < $1.params.size; i++) {
                                            $$.params.params[i] = $1.params.params[i];
                                          }
                                          $$.params.size = $1.params.size;
                                          $$.params.params[$$.params.size++] = $3.type;
                                        }
          ;
param_dec: 
           type      { $$.type = $1.type; }
         | type NAME { $$.type = $1.type; var_dec(var_decs, $2.name, $1.type); }
         ;

//Function definitions
fncs: 
      fnc
    | fncs fnc
    ;

//TODO Fix params
fnc: 
     fnc_dec LBRACK  
        codeblocks
     RBRACK
   | fnc_dec LBRACK 
        var_decs
        codeblocks
     RBRACK
   ;

//Variable Declaration definitions

var_decs: 
          var_dec SEMI
        | var_decs var_dec SEMI
        ;

var_dec:
         type NAME { var_dec(var_decs, $2.name, $1.type); }
       ; 

//Code allowed inside functions
codeblocks:
            code
          | codeblocks code
          ;
      
code: 
      expr SEMI {$1.ASTExprNode->print();}     
    | assignment SEMI 
    | if              
    | ifelse          
    | while           
    | ret SEMI        
    ; 

//Blocks of code

assignment:
           NAME EQ expr {
                          var_dec_check(var_decs, $1.name);
                          $$.ASTAsgnNode = new ASTAsgnNode(convertToString($1.name), $3.ASTExprNode);
                        }
          ;
            
expr: 
       NAME { 
              if (var_dec_check(var_decs, $1.name)) 
              {
                $$.type = *(type_t*)hashtable_find(var_decs, $1.name);
              } 
              $$.ASTVarNode = new ASTVarNode(convertToString($1.name));
              $$.ASTExprNode = $$.ASTVarNode;
            }
     | NUM  { 
              $$.type = INT_TYPE;
              $$.ASTIntLiteralNode = $1.ASTIntLiteralNode;
              $$.ASTExprNode = $$.ASTIntLiteralNode;
            }
     | bin_expr { $$.ASTExprNode = $1.ASTBExprNode; }
     | unr_expr { $$.ASTExprNode = $1.ASTUExprNode; }
     | fnc_call { $$.ASTExprNode = $1.ASTCallNode; }
     | LPAR expr RPAR { $$.ASTExprNode = $2.ASTExprNode; }
     ;

bin_expr: 
          expr ADD expr  { 
                           type_check($1.type, $3.type);
                           $$.ASTBExprNode = new ASTBExprNode($1.ASTExprNode, $3.ASTExprNode, ADDIT);
                           $$.type = INT_TYPE;
                         }
        | expr SUB expr  { 
                           type_check($1.type, $3.type);
                           $$.ASTBExprNode = new ASTBExprNode($1.ASTExprNode, $3.ASTExprNode, SUBTR);
                           $$.type = INT_TYPE;
                         }
        | expr MULT expr { 
                           type_check($1.type, $3.type);
                           $$.ASTBExprNode = new ASTBExprNode($1.ASTExprNode, $3.ASTExprNode,  MULTI);
                           $$.type = INT_TYPE;
                         }
        | expr DIV expr  { 
                           type_check($1.type, $3.type);
                           $$.ASTBExprNode = new ASTBExprNode($1.ASTExprNode, $3.ASTExprNode, DIVIS);
                           $$.type = INT_TYPE;
                         }
  
//TODO Fix
unr_expr:
          SUB NAME { 
                     if (var_dec_check(var_decs, $2.name)) {
                       $$.type = INT_TYPE;
                     }
                   }
        | SUB LPAR expr RPAR { 
                               $$.type = $3.type;
                               $$.ASTUExprNode = new ASTUExprNode($3.ASTExprNode, NEG);
                             }
        ;

//UPDATE PARAMS SECTION 
fnc_call:
          NAME LPAR RPAR { 
                           params_t params; params.size = 0; 
                           if (fnc_dec_check(fnc_decs, $1.name, params)) {
                            $$.type = (*(fnc_dec_t*)hashtable_find(fnc_decs, $1.name)).ret_type;
                           }
                           $$.ASTCallNode = new ASTCallNode(convertToString($1.name), nullptr);
                         }
        | NAME LPAR params RPAR { 
                                  if (fnc_dec_check(fnc_decs, $1.name, $3.params)) {
                                    $$.type = (*(fnc_dec_t*)hashtable_find(fnc_decs, $1.name)).ret_type;
                                  }
                                  $$.ASTCallNode = new ASTCallNode(convertToString($1.name), nullptr); 
                                }
        ;

if:
    IF LPAR conditional RPAR LBRACK
      codeblocks
    RBRACK
  ;

else: 
      ELSE LBRACK
        codeblocks
      RBRACK            
    ;


ifelse: if else
      ;

while: WHILE LPAR conditional RPAR LBRACK
         codeblocks
       RBRACK                       
     ;

params:
        expr {$$.params.params[$$.params.size++] = $1.type;}
      | params COMMA expr {
                            for (int i = 0; i < $1.params.size; i++) {
                              $$.params.params[i] = $1.params.params[i];
                            }
                            $$.params.size = $1.params.size;
                            $$.params.params[$$.params.size++] = $3.type;
                          }
      ;

conditional:
             expr comparator expr { 
                                    type_check($1.type, $3.type);
                                    $$.ASTRExprNode =new ASTRExprNode($1.ASTExprNode, $3.ASTExprNode, $3.rop);
                                  }
           ;

comparator: 
            EQEQ  { $$.rop = DOUBEQ; } 
          | NEQ   { $$.rop = NOTEQ; } 
          | GEQ   { $$.rop = GREATEQ; } 
          | LEQ   { $$.rop = LESSEQ; } 
          | GREAT { $$.rop = GT; } 
          | LESS  { $$.rop = LT; } 
          ;

//General Use Defintions
type:
      INT  {$$ = $1;}
    | VOID {$$ = $1;}
    ;

ret:
     RET      { $$.ASTRetNode = new ASTRetNode(nullptr); }
   | RET expr { $$.ASTRetNode = new ASTRetNode($2.ASTExprNode); }
   ;

%%

// converts character array
// to string and returns it
string* convertToString(char* a)
{
    int i;
    int size = strlen(a);
    string *s = new string("");
    for (i = 0; i < size; i++) {
        s->push_back(a[i]);
    }
    return s;
}

void var_dec(hashtable_t* var_decs, const char *var_name, type_t var_type) {
  if (hashtable_find(var_decs, var_name)) {
    fprintf(stderr, "<ERROR> Variable \'%s\' was previously declared.\n", var_name);
    return;
  }
  
  type_t *new_var = (type_t*)malloc(sizeof(type_t));
 *new_var = var_type;
  hashtable_insert(var_decs, var_name, new_var); 
}

bool var_dec_check(hashtable_t* var_decs, const char *var_name) {
  if(!(hashtable_find(var_decs, var_name))) { 
    fprintf(stderr, "<ERROR> Variable \'%s\' was not declared.\n", var_name); 
    return false;
  } 
  return true;
}

void fnc_dec(hashtable_t* fnc_decs, const char *fnc_name, type_t ret_type, params_t param_list) {
  if (hashtable_find(fnc_decs, fnc_name)) {
    fprintf(stderr, "<ERROR> Function \'%s\' was previously declared.\n", fnc_name);
    return;
  }
  fnc_dec_t *fnc_dec = (fnc_dec_t*)malloc(sizeof(fnc_dec_t));
  fnc_dec->ret_type = ret_type;
  for (int i = 0; i < param_list.size; i++) {
    fnc_dec->param_list.params[i] = param_list.params[i];
  }
  fnc_dec->param_list.size = param_list.size;

  hashtable_insert(fnc_decs, fnc_name, fnc_dec); 
}

bool fnc_dec_check(hashtable_t* fnc_decs, const char *fnc_name, params_t params) {
  if(!(hashtable_find(fnc_decs, fnc_name))) { 
    fprintf(stderr, "<ERROR> Function \'%s\' was not declared.\n", fnc_name); 
    return false;
  }  

  bool params_match = true;
  params_t function_params = ((fnc_dec_t*)hashtable_find(fnc_decs, fnc_name))->param_list;
   for (int i = 0; i < function_params.size; i++) {
      if (function_params.params[i] != params.params[i]) {
        params_match = false;
    }
  }

  if (!params_match) {
    fprintf(stderr, "<ERROR> Function parameters in \'%s\' are mismatched.\n", fnc_name); 
    return false;
  }

  return true;
}

bool type_check(type_t expr1, type_t expr2) {
  if (expr1 != INT_TYPE || expr2 != INT_TYPE) {
    fprintf(stderr, "<ERROR> Trying to perform arithmetic or comparison operation on non-integer type.\n");
    return false;
  }
  return true;
}

bool assignment_check(hashtable_t* var_decs, const char* var, type_t expr2) {
  if(*(type_t*)hashtable_find(var_decs, var) != expr2) {
    fprintf(stderr, "<ERROR> Left hand side type does not match right hand side of expression.\n");
    return false;
  }
  return true;
}

void varprint(FILE* fp, const char* key, void* item)
{
  fprintf(fp, "%s - %s", key, *(type_t*)item == 0 ? "INT" : "VOID");
}

void fncprint(FILE* fp, const char* key, void* item)
{
  fprintf(fp, "\n%s - ret_type = %s\n Parameters are: \n", key, *(int*)item == 0 ? "INT" : "VOID");
  for (int i = 0; i < (*(fnc_dec_t*)item).param_list.size; i++) {
    fprintf(fp, "   Parameter %d has type %s\n", i, (*(fnc_dec_t*)item).param_list.params[i] == 0 ? "INT" : "VOID"); 
  }
}

int main (int argc, char **argv)
{
        //Turn off bison debugging
        yy_flex_debug = 0;

        //Handle arguments
        ++argv, --argc; /* skip over program name */ 
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" ); 
        else
                yyin = stdin;

        //Hashtable to store function declarations
        fnc_decs = hashtable_new(MAX_VAR_DECS);
        var_decs = hashtable_new(MAX_VAR_DECS);

        //Parse input
        yyparse();

        //Print AST
        // root.print();
        return 0;
}
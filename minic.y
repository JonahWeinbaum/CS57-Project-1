//TODO - Handle Variable Scope w/in Each Function

%{
  #include "ast_c++/ast.hpp"
  #include "hash/hashtable.h"
  #include <string>
  #include <cstring>
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
  ASTRootNode *root = new ASTRootNode(nullptr, nullptr, nullptr);
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
    char *param_names[MAX_PARAMS];
    vector<struct ASTExprNode*> *ASTExprNodes;
    int size; 
  } params_t;

  typedef struct fnc_dec {
    char* fnc_name;
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
    ASTStmtNode *ASTStmtNode;
    ASTIfNode *ASTIfNode;
    ASTWhileNode *ASTWhileNode;
    ASTBlockNode *ASTBlockNode;
    ASTVarDeclNode *ASTVarDeclNode;
    ASTFuncDeclNode *ASTFuncDeclNode; 
    ASTFuncDefNode *ASTFuncDefNode;
    vector<struct ASTDeclNode *> *ASTFuncDeclsNode;
    vector<struct ASTFuncDefNode *> *ASTFuncDefsNode;  
    ASTRootNode *ASTRootNode; 

    type_t type;
    char* name;
    fnc_dec_t fnc_dec;
    params_t params;
    r_op_t   rop;
  } type_node_t;


  //Helper Functions
  void var_dec(hashtable_t* var_decs, char *var_name, type_t var_type);
  bool var_dec_check(hashtable_t* var_decs, char *var_name);
  void fnc_dec(hashtable_t* fnc_decs, char *fnc_name, type_t ret_type, params_t param_list);
  bool fnc_dec_check(hashtable_t* fnc_decs, char *fnc_name, params_t params);
  bool type_check(type_t expr1, type_t expr2);
  bool assignment_check(hashtable_t* var_decs, char* var, type_t expr2);
  void varprint(FILE* fp, char* key, void* item);
  void fncprint(FILE* fp, char* key, void* item);
  void fncdel(void* item);
  string *convertToString(char* str);
  data_type_t convertToType(type_t type);
}

%union {
  char* str_val;
  object_node element_val;
}

%destructor { 
              // free($$.name);
              // for (int i = 0; i < $$.fnc_dec.param_list.size; i++) {
              //     free($$.fnc_dec.param_list.param_names[i]);
              // }
              // free($$.fnc_dec.fnc_name);
            } <element_val>

//Nonterminal Types
%type <element_val> type
%type <element_val> var_dec
%type <element_val> file
%type <element_val> fncs
%type <element_val> fnc
%type <element_val> fnc_dec
%type <element_val> fnc_decs
%type <element_val> params
%type <element_val> param_decs
%type <element_val> param_dec
%type <element_val> codeblocks
%type <element_val> code
%type <element_val> expr
%type <element_val> if
%type <element_val> else
%type <element_val> ifelse
%type <element_val> while
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
      fncs          { $$.ASTRootNode = new ASTRootNode(nullptr, nullptr, $1.ASTFuncDefsNode); root = $$.ASTRootNode; }  
    | fnc_decs fncs { $$.ASTRootNode = new ASTRootNode($1.ASTFuncDeclsNode, nullptr, $2.ASTFuncDefsNode); root = $$.ASTRootNode; }
    ;

//Function Declaration definitions
fnc_decs:
          fnc_dec SEMI          { 
                                  $$.ASTFuncDeclsNode = new vector<ASTDeclNode*>();
                                  $$.ASTFuncDeclsNode->push_back($1.ASTFuncDeclNode);
                                }
        | fnc_decs fnc_dec SEMI {
                                  $1.ASTFuncDeclsNode->push_back($2.ASTFuncDeclNode);
                                  $$.ASTFuncDeclsNode = $1.ASTFuncDeclsNode;
                                }
        ;

fnc_dec: 
         EXTERN type NAME LPAR param_decs RPAR { 
                                                 $$.fnc_dec.fnc_name = strdup($3.name); 
                                                 $$.fnc_dec.ret_type = $2.type; 
                                                 fnc_dec(fnc_decs, $3.name, $2.type, $5.params);
                                                 $$.fnc_dec.param_list = $5.params;
                                                 $$.ASTFuncDeclNode = new ASTFuncDeclNode(true, convertToType($2.type), 
                                                                                          convertToString($3.name), convertToType($5.params.params[0]));
                                               }    
       | type NAME LPAR param_decs RPAR        { 
                                                 $$.fnc_dec.fnc_name = strdup($2.name); 
                                                 $$.fnc_dec.ret_type = $1.type; 
                                                 fnc_dec(fnc_decs, $2.name, $1.type, $4.params);
                                                 $$.fnc_dec.param_list = $4.params;
                                                 $$.ASTFuncDeclNode = new ASTFuncDeclNode(false, convertToType($1.type), 
                                                                                          convertToString($2.name), convertToType($4.params.params[0]));
                                               }   
       | EXTERN type NAME LPAR RPAR            { 
                                                 $$.fnc_dec.fnc_name = strdup($3.name); 
                                                 $$.fnc_dec.ret_type = $2.type; 
                                                 $$.fnc_dec.param_list.params[0] = VOID_TYPE;
                                                 $$.fnc_dec.param_list.param_names[0] = nullptr;
                                                 params_t *param = (params_t*)malloc(sizeof(params_t)); 
                                                 memset(param, 0, sizeof(params_t));
                                                 fnc_dec(fnc_decs, $3.name, $2.type, *param);
                                                 $$.ASTFuncDeclNode = new ASTFuncDeclNode(true, convertToType($2.type), 
                                                                                          convertToString($3.name), VOID_T);
                                                 free(param);
                                               }
       | type NAME LPAR RPAR                   { 
                                                 $$.fnc_dec.fnc_name = strdup($2.name); 
                                                 $$.fnc_dec.ret_type = $1.type; 
                                                 params_t *param = (params_t*)malloc(sizeof(params_t)); 
                                                 memset(param, 0, sizeof(params_t));
                                                 fnc_dec(fnc_decs, $2.name, $1.type, *param);
                                                 $$.ASTFuncDeclNode = new ASTFuncDeclNode(false, convertToType($1.type), 
                                                                                          convertToString($2.name), VOID_T);
                                                 free(param);
                                               }
       ;

param_decs:
            param_dec                   {
                                          $$.params.params[$$.params.size] = $1.type;
                                          $$.params.param_names[$$.params.size++] = $1.name ? strdup($1.name) : NULL;
                                        }
          | param_decs COMMA param_dec  {
                                          for (int i = 0; i < $1.params.size; i++) {
                                            $$.params.params[i] = $1.params.params[i];
                                            $$.params.param_names[i] = $1.params.param_names[i] ? strdup($1.params.param_names[i]): NULL;
                                          
                                          }
                                          $$.params.size = $1.params.size;
                                          $$.params.params[$$.params.size] = $3.type;
                                          $$.params.param_names[$$.params.size++] = $1.name ? strdup($3.name) : NULL;
                                        }
          ;
param_dec: 
           type      { $$.type = $1.type; $$.name = nullptr; }
         | type NAME { 
                       $$.type = $1.type;
                       $$.name = $2.name;
                       var_dec(var_decs, $2.name, $1.type); 
                     }
         ;

//Function definitions
fncs: 
      fnc      { 
                 $$.ASTFuncDefsNode = new vector<ASTFuncDefNode*>(); 
                 $$.ASTFuncDefsNode->push_back($1.ASTFuncDefNode); 
               }
    | fncs fnc { 
                 $1.ASTFuncDefsNode->push_back($2.ASTFuncDefNode); 
                 $$.ASTFuncDefsNode = $1.ASTFuncDefsNode;
               }
    ;

fnc: 
     fnc_dec LBRACK  
        codeblocks 
     RBRACK         {
                      hashtable_delete(var_decs, free);
                      var_decs = hashtable_new(MAX_VAR_DECS);
                      $$.ASTFuncDefNode = new ASTFuncDefNode(convertToType($1.fnc_dec.ret_type), convertToString($1.fnc_dec.fnc_name), 
                                                             convertToType($1.fnc_dec.param_list.params[0]), convertToString($1.fnc_dec.param_list.param_names[0]),
                                                             $3.ASTBlockNode); 
                    }
   ;

//Variable Declaration definitions

var_dec:
         type NAME { 
                     var_dec(var_decs, $2.name, $1.type); 
                     $$.ASTVarDeclNode = new ASTVarDeclNode(false, convertToType($1.type), convertToString($2.name));
                   }
       | EXTERN type NAME {
                            var_dec(var_decs, $3.name, $2.type); 
                            $$.ASTVarDeclNode = new ASTVarDeclNode(true, convertToType($2.type), convertToString($3.name));
                          }
       ; 

//Code allowed inside functions
codeblocks:
            code { 
                   vector<ASTStmtNode*> *stmt_list = new vector<ASTStmtNode*>(); 
                   stmt_list->push_back($1.ASTStmtNode); 
                   $$.ASTBlockNode = new ASTBlockNode(stmt_list);
                 }
          | codeblocks code {
                              $1.ASTBlockNode->stmt_list->push_back($2.ASTStmtNode);
                              $$.ASTBlockNode->stmt_list = $1.ASTBlockNode->stmt_list;
                            }
          ;
      
code: 
      expr SEMI       { $$.ASTStmtNode = $1.ASTExprNode; }  
    | var_dec SEMI    { $$.ASTStmtNode = $1.ASTVarDeclNode; }   
    | assignment SEMI { $$.ASTStmtNode = $1.ASTAsgnNode; }        
    | ifelse          { $$.ASTStmtNode = $1.ASTIfNode; }     
    | while           { $$.ASTStmtNode = $1.ASTWhileNode; }     
    | ret SEMI        { $$.ASTStmtNode = $1.ASTRetNode; }     
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
  
unr_expr:
          SUB NAME { 
                     if (var_dec_check(var_decs, $2.name)) {
                       $$.type = INT_TYPE;
                     }
                     $$.ASTUExprNode = new ASTUExprNode( new ASTVarNode(convertToString($2.name)), NEG);
                   }
        | SUB NUM  {
                     $$.ASTUExprNode = new ASTUExprNode($2.ASTIntLiteralNode, NEG);
                   }
        | SUB LPAR expr RPAR { 
                               $$.type = $3.type;
                               $$.ASTUExprNode = new ASTUExprNode($3.ASTExprNode, NEG);
                             }
        ;

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
                                  $$.ASTCallNode = new ASTCallNode(convertToString($1.name), $3.params.ASTExprNodes->at(0)); 
                                }
        ;

if:
    IF LPAR conditional RPAR LBRACK
      codeblocks
    RBRACK                           { 
                                       $$.ASTExprNode = $3.ASTRExprNode; 
                                       $$.ASTBlockNode = $6.ASTBlockNode; 
                                     }
  ;

else: 
      ELSE LBRACK
        codeblocks
      RBRACK                         { $$.ASTBlockNode = $3.ASTBlockNode; }      
    ;


ifelse: 
          if      { $$.ASTIfNode = new ASTIfNode($1.ASTExprNode, $1.ASTBlockNode, new ASTBlockNode()); }
        | if else { $$.ASTIfNode = new ASTIfNode($1.ASTExprNode, $1.ASTBlockNode, $2.ASTBlockNode); }
      ;

while: WHILE LPAR conditional RPAR LBRACK
         codeblocks
       RBRACK                             { $$.ASTWhileNode = new ASTWhileNode($3.ASTRExprNode, $6.ASTBlockNode); }       
     ;

params:
        expr {
               $$.params.params[$$.params.size++] = $1.type;
               $$.params.ASTExprNodes = new vector<ASTExprNode*>();
               $$.params.ASTExprNodes->push_back($1.ASTExprNode);
             }
      | params COMMA expr {
                            for (int i = 0; i < $1.params.size; i++) {
                              $$.params.params[i] = $1.params.params[i];
                              $$.params.ASTExprNodes->push_back($1.params.ASTExprNodes->at(i));
                            }
                            $$.params.size = $1.params.size;
                            $$.params.params[$$.params.size++] = $3.type;
                            $$.params.ASTExprNodes->push_back($3.ASTExprNode);
                          }
      ;

conditional:
             expr comparator expr { 
                                    type_check($1.type, $3.type);
                                    $$.ASTRExprNode = new ASTRExprNode($1.ASTExprNode, $3.ASTExprNode, $2.rop);
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
string* convertToString(char* str)
{
    if (str == NULL || str == nullptr) { return nullptr; } 
    int i;
    int size = strlen(str);
    string *temp = new string("");
    for (i = 0; i < size; i++) {
        temp->push_back(str[i]);
    }
    return temp;
}

data_type_t convertToType(type_t type)
{
  switch(type) {
    case INT_TYPE: 
      return INT_T;
    case VOID_TYPE:
      return VOID_T;
    default: 
      return VOID_T;
  }

}

void var_dec(hashtable_t* var_decs, char *var_name, type_t var_type) {
  if (hashtable_find(var_decs, var_name)) {
    fprintf(stderr, "<ERROR> Variable \'%s\' was previously declared.\n", var_name);
    return;
  }
  
  type_t *new_var = (type_t*)malloc(sizeof(type_t));
 *new_var = var_type;
  hashtable_insert(var_decs, var_name, new_var); 
}

bool var_dec_check(hashtable_t* var_decs, char *var_name) {
  if(!(hashtable_find(var_decs, var_name))) { 
    fprintf(stderr, "<ERROR> Variable \'%s\' was not declared.\n", var_name); 
    return false;
  } 
  return true;
}

void fnc_dec(hashtable_t* fnc_decs, char *fnc_name, type_t ret_type, params_t param_list) {
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

bool fnc_dec_check(hashtable_t* fnc_decs, char *fnc_name, params_t params) {
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

bool assignment_check(hashtable_t* var_decs, char* var, type_t expr2) {
  if(*(type_t*)hashtable_find(var_decs, var) != expr2) {
    fprintf(stderr, "<ERROR> Left hand side type does not match right hand side of expression.\n");
    return false;
  }
  return true;
}

void varprint(FILE* fp, char* key, void* item)
{
  fprintf(fp, "%s - %s", key, *(type_t*)item == 0 ? "INT" : "VOID");
}

void fncprint(FILE* fp, char* key, void* item)
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

        hashtable_delete(fnc_decs, free);
        hashtable_delete(var_decs, free);

        //Print AST
        root->print();

        delete root;

        return 0;
}
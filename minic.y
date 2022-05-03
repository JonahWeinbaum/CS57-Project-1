%{
  #include "ast_c/ast.h"
  #include "hash/hashtable.h"

  //Yacc Parameters
  extern int yylex(void);
  extern FILE *yyin;
  extern int yy_flex_debug;
  extern void yyerror(char *s) {}

  //Global Variables
  hashtable_t *var_decs;
  hashtable_t *fnc_decs;

  //Root note
  astNode* root;
%}

//Data Types
%code requires {
  #define MAX_PARAMS 6
  #define MAX_VAR_DECS 100

  #include "ast_c/ast.h"
  #include "hash/hashtable.h"

  typedef enum type {
    INT_TYPE = 0,
    VOID_TYPE = 1
  } type_t;

  typedef struct expr {
    type_t type;
    astNode* node;
  } expr_t;

  typedef struct params {
    type_t params[MAX_PARAMS];
    int size; 
  } params_t;

  typedef struct fnc_dec {
    params_t param_list;
    type_t ret_type; 
  } fnc_dec_t;

  //Helper Functions
  void var_dec(hashtable_t* var_decs, char *var_name, type_t var_type);
  bool var_dec_check(hashtable_t* var_decs, char *var_name);
  void fnc_dec(hashtable_t* fnc_decs, char *fnc_name, type_t ret_type, params_t param_list);
  bool fnc_dec_check(hashtable_t* fnc_decs, char *fnc_name, params_t params);
  bool type_check(type_t expr1, type_t expr2);
  bool assignment_check(hashtable_t* var_decs, char* var, type_t expr2);
  void varprint(FILE* fp, const char* key, void* item);
  void fncprint(FILE* fp, const char* key, void* item);
}

%union {
  char* str_val;
  int num_val;
  type_t type_val;
  expr_t expr_val;
  rop_type rop_val;
  op_type op_val;
  params_t params_val;
  fnc_dec_t fnc_dec_val;
}

//Nonterminal Types
%type <type_val> type
%type <expr_val> conditional
%type <expr_val> expr
%type <expr_val> bin_expr
%type <expr_val> unr_expr
%type <rop_val> comparator
%type <params_val> params
%type <params_val> param_decs
%type <type_val> param_dec
%type <fnc_dec_val> fnc_dec
%type <expr_val> fnc_call

//Tokens
%token <type_val> INT
%token <type_val> VOID
%token EXTERN
%token RET
%token WHILE
%token <op_val> ADD
%token <op_val> SUB
%token <op_val> MULT
%token <op_val> DIV
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
%token <num_val> NUM
%token <str_val> NAME

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
         EXTERN type NAME LPAR param_decs RPAR {fnc_dec(fnc_decs, $3, $2, $5);}
       | type NAME LPAR param_decs RPAR        {fnc_dec(fnc_decs, $2, $1, $4);}
       | EXTERN type NAME LPAR RPAR            {params_t param; fnc_dec(fnc_decs, $3, $2,  param);}
       | type NAME LPAR RPAR                   {params_t param; fnc_dec(fnc_decs, $2, $1,  param);}
       ;

param_decs:
            param_dec                   {$$.params[$$.size++] = $1;}
          | param_decs COMMA param_dec  {
                                          for (int i = 0; i < $1.size; i++) {
                                            $$.params[i] = $1.params[i];
                                          }
                                          $$.size = $1.size;
                                          $$.params[$$.size++] = $3;
                                        }
          ;
param_dec: 
           type      {$$ = $1;}
         | type NAME {$$ = $1; var_dec(var_decs, $2, $1);}
         ;

//Function definitions
fncs: 
      fnc
    | fncs fnc
    ;

fnc: 
     fnc_dec LBRACK 
        codeblocks
        ret SEMI
     RBRACK 
   | fnc_dec LBRACK 
        var_decs
        codeblocks
        ret SEMI
     RBRACK 
   ;

//Variable Declaration definitions

var_decs: 
          var_dec SEMI
        | var_decs var_dec SEMI
        ;

var_dec:
         type NAME { var_dec(var_decs, $2, $1);}
       ; 

//Code allowed inside functions
codeblocks:
            code
          | codeblocks code
          ;
      
code: 
      expr SEMI
    | assignment SEMI
    | if
    | ifelse
    | while
    | ret SEMI
    ; 

//Blocks of code

assignment:
           NAME EQ expr {
                          var_dec_check(var_decs, $1);
                          createAsgn(createVar($1), $3.node);
                        }
          ;
            
expr: 
       NAME { 
              if (var_dec_check(var_decs, $1)) 
              {
                $$.type = *(type_t*)hashtable_find(var_decs, $1);
              }
              $$.node = createVar($1);
            }
     | NUM  { 
              $$.type = INT_TYPE;
              $$.node  = createCnst($1); 
            }
     | bin_expr { $$ = $1; }
     | unr_expr { $$ = $1; }
     | fnc_call { $$ = $1; }
     | LPAR expr RPAR { $$ = $2; }
     ;

bin_expr: 
          expr ADD expr  { type_check($1.type, $3.type);
                           $$.type = INT_TYPE;
                           $$.node = createBExpr($1.node, $3.node, $2);
                         }
        | expr SUB expr  { type_check($1.type, $3.type);
                           $$.type = INT_TYPE;
                           $$.node = createBExpr($1.node, $3.node, $2);
                         }
        | expr MULT expr { type_check($1.type, $3.type);
                           $$.type = INT_TYPE;
                           $$.node = createBExpr($1.node, $3.node, $2);
                         }
        | expr DIV expr  { type_check($1.type, $3.type);
                           $$.type = INT_TYPE;
                           $$.node = createBExpr($1.node, $3.node, $2);
                         }
  
unr_expr:
          SUB NAME { 
                     if (var_dec_check(var_decs, $2)) {
                       $$.type = *(type_t*)hashtable_find(var_decs, $2);
                     }
                     $$.node = createUExpr(createVar($2), $1);
                   }
        | SUB LPAR expr RPAR { 
                               $$.type = $3.type;
                               $$.node = createUExpr($3.node, $1);
                             }
        ;

//UPDATE PARAMS SECTION 
fnc_call:
          NAME LPAR RPAR { params_t params; params.size = 0; 
                           if (fnc_dec_check(fnc_decs, $1, params)) {
                            $$.type = (*(fnc_dec_t*)hashtable_find(fnc_decs, $1)).ret_type;
                           }
                           $$.node = createCall($1, NULL);
                         }
        | NAME LPAR params RPAR { if (fnc_dec_check(fnc_decs, $1, $3)) {
                                    $$.type = (*(fnc_dec_t*)hashtable_find(fnc_decs, $1)).ret_type;
                                  } 
                                  $$.node = createCall($1, NULL);
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
        expr {$$.params[$$.size++] = $1.type;}
      | params COMMA expr {
                            for (int i = 0; i < $1.size; i++) {
                              $$.params[i] = $1.params[i];
                            }
                            $$.size = $1.size;
                            $$.params[$$.size++] = $3.type;
                          }
      ;

conditional:
             expr comparator expr { type_check($1.type, $3.type);
                                    $$.node = createRExpr($1.node, $3.node, $2);
                                  }
           ;

comparator: 
            EQEQ  {$$ = eq;}
          | NEQ   {$$ = neq;}
          | GEQ   {$$ = ge;}
          | LEQ   {$$ = le;}
          | GREAT {$$ = gt;}
          | LESS  {$$ = lt;}
          ;

//General Use Defintions
type:
      INT  {$$ = $1;}
    | VOID {$$ = $1;}
    ;

ret:
     RET 
   | RET expr
   ;

%%

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
        root = (astNode*)malloc(sizeof(astNode));

        //Parse input
        yyparse();

        printNode(root, 0);

        return 0;
}
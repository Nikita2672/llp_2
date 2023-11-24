%{
#include <stdio.h>
#include "stdbool.h"
%}
%union{
          char *sval;
          double dval;
          int ival;
          int bval;
          struct AstNode *ast_node;
}
%%

%token TOKEN_FROM TOKEN_JOIN TOKEN_ON TOKEN_WHERE TOKEN_SELECT TOKEN_EQ_OP TOKEN_NE;
%token STATE TOKEN_LE TOKEN_GE TOKEN_LT TOKEN_GT TOKEN_PAR_OPEN TOKEN_PAR_CLOSE TOKEN_OR;
%token TOK_TEMPERATURE TOKEN_AND;
%token NUMBER TOKEN_BOOLEAN;
%token TOK_TARGET TOKEN_QUOTED_STRING TOKEN_DOUBLE TOKEN_INTEGER TOKEN_IDENTIFIER;


commands: /* empty */
        | commands command
        ;

command:
%%

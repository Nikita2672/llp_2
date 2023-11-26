#include <stdio.h>
#include "parser/parser.h"
#include "ast/ast.h"

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}


int main() {
    yyparse();
    printAstTree();
    freeAstTree();
    return 0;
}

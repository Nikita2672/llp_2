#include <stdio.h>
#include "parser.h"

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}


int main() {
    yyparse();
    return 0;
}

#include <stdio.h>
#include "parser.h"
#include "ast.h"
#include "stdbool.h"

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}


int main() {
    struct AstNode *field1 = create_ast_node(FIELD_IDENTIFIER, 0, "Name");
    struct AstNode *field2 = create_ast_node(FIELD_IDENTIFIER, 0, "Surname");
    struct AstNode *comparison1 = create_ast_node(ANT_EQ_OP, 1, field1);
    struct AstNode *comparison2 = create_ast_node(ANT_NE, 1, field2);
    struct AstNode *value1 = create_ast_node(ANT_STRING_LITERAL, 0, "Nikita");
    struct AstNode *value2 = create_ast_node(ANT_STRING_LITERAL, 0, "Ivanov");
    struct AstNode *condition1 = create_ast_node(ANT_CONDITION, 2, comparison1, value1);
    struct AstNode *condition2 = create_ast_node(ANT_CONDITION, 2, comparison2, value2);
    struct AstNode *where = create_ast_node(ANT_WHERE, 2, condition1, condition2);
    struct AstNode *collection = create_ast_node(ANT_FROM_COLLECTION_NAME, 0);
    struct AstNode *from = create_ast_node(ANT_FROM, 1, collection);
    struct AstNode *select = create_ast_node(ANT_SELECT, 2, from, where);

    print_ast_tree(select);

//    yyparse();
    return 0;
}

#include <malloc.h>
#include <stdarg.h>
#include "ast.h"
#include "stdio.h"

const char *getAstNodeTypeName(enum AstNodeType type) {
    if (type < sizeof(AstNodeTypeNames) / sizeof(AstNodeTypeNames[0]) != 0) {
        return AstNodeTypeNames[type];
    } else {
        return "UNKNOWN";
    }
}

static void print_ast_tree_recursive(struct AstNode *node, int depth) {

    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }

    switch (node->type) {
        case ANT_DOUBLE_LITERAL:
            printf(": %f", node->value.double_val);
            break;
        case ANT_INTEGER_LITERAL:
            printf(": %d", node->value.int_val);
            break;
        case ANT_STRING_LITERAL:
            printf(": \"%s\"", node->value.str_val);
            break;
        case ANT_BOOLEAN_LITERAL:
            printf(": %s", node->value.bool_val ? "true" : "false");
        case FIELD_IDENTIFIER:
            printf (": %s", node->value.str_val);
            break;
        default:
            printf(": %s", getAstNodeTypeName(node->type));
            break;
    }

    printf("\n");

    for (int i = 0; i < node->num_children; ++i) {
        print_ast_tree_recursive(node->children[i], depth + 1);
    }
}

struct AstNode *create_ast_node(enum AstNodeType type, int num_children, ...) {
    struct AstNode *node = (struct AstNode *) malloc(sizeof(struct AstNode));
    if (node == NULL) {
        fprintf(stderr, "Failed to allocate memory for AstNode\n");
        return NULL;
    }

    node->type = type;
    node->num_children = num_children;

    node->children = (struct AstNode **) malloc(num_children * sizeof(struct AstNode *));
    if (node->children == NULL) {
        fprintf(stderr, "Failed to allocate memory for AstNode children\n");
        return NULL;
    }

    // Инициализация списка аргументов переменной длины
    va_list args;
    va_start(args, num_children);

    // Заполнение массива дочерних узлов
    for (int i = 0; i < num_children; ++i) {
        node->children[i] = va_arg(args,
                                   struct AstNode*);
    }

    // Установка значения в зависимости от типа узла
    switch (type) {
        case ANT_DOUBLE_LITERAL:
            node->value.double_val = va_arg(args, double);
            break;
        case ANT_INTEGER_LITERAL:
            node->value.int_val = va_arg(args, int);
            break;
        case ANT_STRING_LITERAL:
            node->value.str_val = va_arg(args, char*);
            break;
        case ANT_BOOLEAN_LITERAL:
            node->value.bool_val = va_arg(args, int);
            break;
        case FIELD_IDENTIFIER:
            node->value.str_val = va_arg(args, char *);
        default:
            break;
    }

    va_end(args);

    return node;
}


void print_ast_tree(struct AstNode *root) {
    print_ast_tree_recursive(root, 0);
}
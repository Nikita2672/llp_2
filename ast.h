#ifndef PARSER_AST_H
#define PARSER_AST_H

#include <stdbool.h>

enum AstNodeType {
    ANT_SELECT_QUERY,
    ANT_FROM,
    ANT_FROM_VARNAME,
    ANT_FROM_COLLECTION_NAME,
    ANT_QUERY_BODY,
    ANT_QUERY_BODY_CLAUSES,
    ANT_QUERY_BODY_CLAUSE,
    ANT_WHERE,
    ANT_JOIN,
    ANT_SELECT,
    ANT_UPDATE_QUERY,
    ANT_UPDATE_FIELD,
    ANT_UPDATE_SET,
    ANT_DELETE_QUERY,
    ANT_DELETE_FROM,
    ANT_DELETE_WHERE,
    ANT_INSERT_QUERY,
    ANT_INSERT_INTO,
    ANT_INSERT_VALUES,
    ANT_FIELD_IDENTIFIER,
    ANT_IDENTIFIER,
    ANT_DOUBLE_LITERAL,
    ANT_INTEGER_LITERAL,
    ANT_STRING_LITERAL,
    ANT_BOOLEAN_LITERAL,
    ANT_EQ_OP,
    ANT_NE,
    ANT_LE,
    ANT_GE,
    ANT_LT,
    ANT_GT,
    ANT_AND,
    ANT_OR,
    ANT_NOT,
    ANT_CONDITION,
    FIELD_IDENTIFIER
};

static const char *AstNodeTypeNames[] = {
        "ANT_SELECT_QUERY",
        "ANT_FROM",
        "ANT_FROM_VARNAME",
        "ANT_FROM_COLLECTION_NAME",
        "ANT_QUERY_BODY",
        "ANT_QUERY_BODY_CLAUSES",
        "ANT_QUERY_BODY_CLAUSE",
        "ANT_WHERE",
        "ANT_JOIN",
        "ANT_SELECT",
        "ANT_UPDATE_QUERY",
        "ANT_UPDATE_FIELD",
        "ANT_UPDATE_SET",
        "ANT_DELETE_QUERY",
        "ANT_DELETE_FROM",
        "ANT_DELETE_WHERE",
        "ANT_INSERT_QUERY",
        "ANT_INSERT_INTO",
        "ANT_INSERT_VALUES",
        "ANT_FIELD_IDENTIFIER",
        "ANT_IDENTIFIER",
        "ANT_DOUBLE_LITERAL",
        "ANT_INTEGER_LITERAL",
        "ANT_STRING_LITERAL",
        "ANT_BOOLEAN_LITERAL",
        "ANT_EQ_OP",
        "ANT_NE",
        "ANT_LE",
        "ANT_GE",
        "ANT_LT",
        "ANT_GT",
        "ANT_AND",
        "ANT_OR",
        "ANT_NOT",
        "ANT_CONDITION",
        "FIELD_IDENTIFIER"
};

// Function to get string representation of AstNodeType
const char *getAstNodeTypeName(enum AstNodeType type);

struct AstNode {
    enum AstNodeType type;
    int num_children;
    struct AstNode** children;
    union {
        double double_val;
        int int_val;
        char* str_val;
        bool bool_val;
    } value;
};

struct AstNode* create_ast_node(enum AstNodeType type, int num_children, ...);

// Функции для освобождения памяти узлов AST
void free_ast_node(struct AstNode* node);
void free_ast_tree(struct AstNode* root);

void print_ast_tree(struct AstNode* root);
#endif //PARSER_AST_H

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "parser.h"
    #include "../ast.h"
%}

%%
[ \t]+                  /* игнорируем пробелы и символы табуляции */
\n                      /* игнорируем символ конца строки */

"from"                  return TOKEN_FROM;
"join"                  return TOKEN_JOIN;
"on"                    return TOKEN_ON;
"where"                 return TOKEN_WHERE;
"select"                return TOKEN_SELECT;
"=="                    return TOKEN_EQ_OP;
"!="                    return TOKEN_NE;
"<="                    return TOKEN_LE;
">="                    return TOKEN_GE;
"<"                     return TOKEN_LT;
">"                     return TOKEN_GT;
"("                     return TOKEN_PAR_OPEN;
")"                     return TOKEN_PAR_CLOSE;
"||"                    return TOKEN_OR;
"&&"                    return TOKEN_AND;
"true"                  { yylval.bval = true; return TOKEN_BOOLEAN; }
"false"                 { yylval.bval = false; return TOKEN_BOOLEAN; }

"\\[a-zA-Z]*"           { yylval.sval = strdup(yytext+2); return TOKEN_QUOTED_STRING; }
[1-9][0-9]*\.[0-9]+     { yylval.dval = atof(yytext); return TOKEN_DOUBLE; }
0\.[0-9]+               { yylval.dval = atof(yytext); return TOKEN_DOUBLE; }
[1-9][0-9]*             { yylval.ival = atoi(yytext); return TOKEN_INTEGER; }


[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return TOKEN_IDENTIFIER; }
.                       return yytext[0];
%%
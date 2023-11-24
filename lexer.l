%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "parser.h"
%}

%%

[0-9]+                  {yylval=atoi(yytext); return NUMBER;}
heat                    { return TOK_HEAT; }
on|off                  {yylval=!strcmp(yytext,"on"); return STATE;}
target                  { return TOK_TARGET; }
temperature             { return TOK_TEMPERATURE; }
\n                      /* игнорируем символ конца строки */;
[ \t]+                  /* игнорируем пробелы и символы табуляции */;

%%

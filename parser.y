%{
#include <stdio.h>
%}

%%

%token TOK_HEAT;
%token STATE;
%token TOK_TEMPERATURE;
%token NUMBER;
%token TOK_TARGET;

commands: /* empty */
        | commands command
        ;

command:
        heat_switch
        |
        target_set
        ;

heat_switch:
        TOK_HEAT STATE
        {
            if ($2) {
                printf("\tОбогреватель включен\n");
            } else {
                printf("\tОбогреватель выключен\n");
            }

        };

target_set:
        TOK_TARGET TOK_TEMPERATURE NUMBER
        {
                printf("\tТемпература установлена на %d градусов\n", $3);
        };
%%

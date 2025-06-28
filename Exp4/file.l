%{
#include <stdio.h>
%}

%%
[ \n\t]+ {}
. {fprintf(yyout, "%s", yytext);}
%%

int main(int argc, char **argv) {
    extern FILE *yyin, *yyout;
    yyin = fopen("Input.txt", "r");
    yyout = fopen("Output.txt", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}
int yywrap(void){
    return 1;
}

%{
#include <stdio.h>
%}

%%

[A-Z] { printf("Capital Letters: %s\n", yytext); }
.   ;
\n  ;
%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
int yywrap(void){
    return 1;
}

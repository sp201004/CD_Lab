%{
#include <stdio.h>
int lc=0, sc=0, tc=0, ch=0, wc=0;
%}

%%
[\n] {lc++;}
[\t] {tc++;}
[ ] {sc++;}
. { }
%%

int main(int argc, char **argv) {
    yylex();

    printf("Enter the lines: %d\n", lc);
    printf("Enter the spaces: %d\n", sc);
    printf("Enter the tabs: %d\n", tc);
    return 0;
}
int yywrap(void){
    return 1;
}

%{
#include <stdio.h>
%}

%%

[aeiouAEIOU]  { printf("Vowel: %s\n", yytext); }
[a-zA-Z] { printf("Not a vowel: %s\n", yytext); }
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

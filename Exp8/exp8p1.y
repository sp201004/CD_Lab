%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s) {
    fprintf(stderr, "Invalid string");
}
%}

%token ZERO ONE OTHER
%start S

%%
S: ZERO Rest ZERO   { printf("Valid string: Starts with 0 and ends with 0\n"); }
 | ONE Rest ONE     { printf("Valid string: Starts with 1 and ends with 1\n"); }
 ;

Rest: 
    | Rest ZERO
    | Rest ONE
    | Rest OTHER
    ;
%%

int yylex() {
    char c = getchar();
    switch(c) {
        case '0': return ZERO;
        case '1': return ONE;
        case '\n': return 0;  
        default: return OTHER;
    }
}



int main() {
    printf("Enter a string :\n");
    yyparse();
    return 0;

}
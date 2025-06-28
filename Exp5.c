#include <stdio.h>
#include <string.h>

int main() {
    char op[10];

    printf("Enter an operator: ");
    scanf("%9s", op);

    if (strcmp(op, "+") == 0) {
        printf("Plus\n");
    } else if (strcmp(op, "-") == 0) {
        printf("Minus\n");
    } else if (strcmp(op, "*") == 0) {
        printf("Multiplication\n");
    } else if (strcmp(op, "/") == 0) {
        printf("Division\n");
    } else if (strcmp(op, "%") == 0) {
        printf("Modulus\n");
    } else if (strcmp(op, "=") == 0) {
        printf("Assignment\n");
    } else if (strcmp(op, "==") == 0) {
        printf("Equality\n");
    } else if (strcmp(op, "!=") == 0) {
        printf("Not Equal\n");
    } else if (strcmp(op, ">") == 0) {
        printf("Greater Than\n");
    } else if (strcmp(op, "<") == 0) {
        printf("Less Than\n");
    } else {
        printf("Not a operator\n");
    }

    return 0;
}
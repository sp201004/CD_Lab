#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_star(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != 'a') {
            return false;
        }
        i++;
    }
    return true;
}

bool is_a_b_plus(const char *str) {
    int i = 0;
    while (str[i] == 'a') {
        i++;
    }
    if (str[i] != 'b') {
        return false;
    }
    while (str[i] == 'b') {
        i++;
    }
    return (str[i] == '\0');
}

bool is_abb(const char *str) {
    return (strcmp(str, "abb") == 0);
}

int main() {
    char input[100];

    printf("Enter a String: ");
    if (scanf("%99s", input) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    if (is_a_star(input) || is_a_b_plus(input) || is_abb(input)) {
        printf("The string \"%s\" is accepted under pattern a*, a*b+, or abb.\n", input);
    } else {
        printf("The string \"%s\" is not accepted.\n", input);
    }

    return 0;
}
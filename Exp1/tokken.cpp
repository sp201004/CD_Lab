#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {"int", "float", "if", "else", "return", "for", "while"};
const int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

int isKeyword(const char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) return 1;
    }
    return 0;
}

void detectTokens(const char *program) {
    char token[100];
    int i = 0;
    while (program[i] != '\0') {
        if (isspace(program[i])) { i++; continue; }

        if (isalpha(program[i]) || program[i] == '_') {
            int j = 0;
            while (isalnum(program[i]) || program[i] == '_') token[j++] = program[i++];
            token[j] = '\0';
            printf("%s: %s\n", isKeyword(token) ? "Keyword" : "Identifier", token);
        } else if (isdigit(program[i])) {
            int j = 0;
            while (isdigit(program[i])) token[j++] = program[i++];
            token[j] = '\0';
            printf("Number: %s\n", token);
        } else {
            printf("Symbol: %c\n", program[i++]);
        }
    }
}

int main() {
    char program[1000];
    printf("Enter a program (end with a newline and CTRL+D to stop):\n");
    printf("Program input: ");
    fgets(program, sizeof(program), stdin);
    
    detectTokens(program);
    return 0;
}
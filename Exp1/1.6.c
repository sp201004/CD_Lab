#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100
#define MAX_LINES 1000
#define MAX_WORDS 1000

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_stop_word(char *word, char stop_words[MAX_WORDS][MAX_WORD_LENGTH], int stop_word_count) {
    char lower_word[MAX_WORD_LENGTH];
    strcpy(lower_word, word);
    to_lowercase(lower_word);

    for (int i = 0; i < stop_word_count; i++) {
        char lower_stop_word[MAX_WORD_LENGTH];
        strcpy(lower_stop_word, stop_words[i]);
        to_lowercase(lower_stop_word);

        if (strcmp(lower_word, lower_stop_word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fin, *fout;
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char stop_words[MAX_WORDS][MAX_WORD_LENGTH];
    char processed_lines[MAX_LINES][MAX_LINE_LENGTH];

    int line_count = 0, stop_word_count = 0;

    fin = fopen("story.txt", "r");
    if (fin == NULL) {
        printf("Error opening story.txt.\n");
        return 1;
    }

    while (fgets(lines[line_count], MAX_LINE_LENGTH, fin)) {
        size_t len = strlen(lines[line_count]);
        if (len > 0 && lines[line_count][len - 1] == '\n') {
            lines[line_count][len - 1] = '\0';
        }
        if (len > 1) { 
            line_count++;
        }
    }
    fclose(fin);

    fin = fopen("stop_words.txt", "r");
    if (fin == NULL) {
        printf("Error opening stop_words.txt.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH] = "";
    char c;
    while ((c = fgetc(fin)) != EOF) {
        if (c == ' ' || c == ',' || c == '.' || c == '\n') {
            if (strlen(word) > 0) {
                strcpy(stop_words[stop_word_count++], word);
                word[0] = '\0';
            }
        } else {
            strncat(word, &c, 1);
        }
    }
    if (strlen(word) > 0) {
        strcpy(stop_words[stop_word_count++], word); 
    }
    fclose(fin);

    for (int i = 0; i < line_count; i++) {
        char *token = strtok(lines[i], " ,");
        processed_lines[i][0] = '\0'; 

        while (token != NULL) {
            if (!is_stop_word(token, stop_words, stop_word_count)) {
                strcat(processed_lines[i], token);
                strcat(processed_lines[i], " ");
            }
            token = strtok(NULL, " ,");
        }
    }

    fout = fopen("story_without_stopwords.txt", "w");
    if (fout == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < line_count; i++) {
        fprintf(fout, "%s", processed_lines[i]);
    }
    fclose(fout);

    return 0;
}
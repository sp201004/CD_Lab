#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *fin, *fout;
    char **lines = NULL;
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int total_chars = 0;
    int choice;

    fin = fopen("e1.txt", "r");
    if (fin == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fin) != NULL) {
        lines = realloc(lines, (line_count + 1) * sizeof(char *));
        lines[line_count] = strdup(line);

        total_chars += strlen(line);
        line_count++;
    }
    fclose(fin);

    printf("Select a line you would like to delete:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d %s", i + 1, lines[i]);
    }

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    fout = fopen("new_story.txt", "w");
    if (fout == NULL) {
        perror("Error opening file");
        for (int i = 0; i < line_count; i++) {
            free(lines[i]);
        }
        free(lines);
        return 1;
    }

    for (int i = 0; i < line_count; i++) {
        if (i == choice - 1) continue;
        fputs(lines[i], fout);
        fputc(' ', fout);
    }
    fclose(fout);

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
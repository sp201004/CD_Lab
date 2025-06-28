#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COMMENT_LENGTH 10000

// Function to remove newline characters from a string
void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char comment_buffer[MAX_COMMENT_LENGTH] = "";
    int in_multiline_comment = 0;
    int comment_count = 0;
    
    // Open input file
    input_file = fopen("input.c", "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    
    // Open output file
    output_file = fopen("comments.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        fclose(input_file);
        return 1;
    }
    
    fprintf(output_file, "Extracted Comments from C Program:\n");
    fprintf(output_file, "----------------------------------------\n\n");
    
    // Read the input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *ptr = line;
        int line_length = strlen(line);
        
        while (*ptr != '\0') {
            // Check for multi-line comment start
            if (!in_multiline_comment && ptr[0] == '/' && ptr[1] == '*') {
                in_multiline_comment = 1;
                comment_count++;
                fprintf(output_file, "Comment %d (Multi-line):\n", comment_count);
                fprintf(output_file, "/*");
                ptr += 2;
                continue;
            }
            
            // Check for multi-line comment end
            if (in_multiline_comment && ptr[0] == '*' && ptr[1] == '/') {
                fprintf(output_file, "*/\n\n");
                in_multiline_comment = 0;
                ptr += 2;
                continue;
            }
            
            // Check for single-line comment
            if (!in_multiline_comment && ptr[0] == '/' && ptr[1] == '/') {
                comment_count++;
                fprintf(output_file, "Comment %d (Single-line):\n", comment_count);
                fprintf(output_file, "%s\n", ptr);
                break;
            }
            
            // If we're in a multi-line comment, write the character
            if (in_multiline_comment) {
                fputc(*ptr, output_file);
            }
            
            ptr++;
        }
    }
    
    // Close files
    fclose(input_file);
    fclose(output_file);
    
    printf("Comments have been extracted to comments.txt\n");
    printf("Total comments found: %d\n", comment_count);
    
    return 0;
}
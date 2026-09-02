#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_LINES 100
#define MAX_LENGTH 80


int main() {
    char fname[50];
    char lines[MAX_LINES][MAX_LENGTH];

    printf("Enter the file name: ");
    fgets(fname, sizeof(fname), stdin);


    size_t len = strlen(fname);
    if (len > 0 && fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }


    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error. File not found '%s'\n", fname);
        return 1;
    }


    int line_count = 0;

    while (line_count < MAX_LINES && fgets(lines[line_count], MAX_LENGTH, fptr) != NULL) {
        line_count++;
    }

    fclose(fptr);

    for (int i = 0; i < line_count; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = toupper((unsigned char)  lines[i][j]);
        }
        printf("%s\n", lines[i]);
    }
fptr = fopen(fname, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Error. File could not be opened '%s'\n", fname);
        return 1;
    }

    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], fptr);
    }
    fclose(fptr);
    return 0;

}

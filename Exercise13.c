#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char fname[50];
    int number = 0;
    int count = 0;
    int lowest = 0;
    int highest = 0;


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

    while (fscanf(fptr, "%d", &number) == 1) {
        if (count == 0) {
            lowest = number;
            highest = number;
        } else {
            if (number < lowest ) lowest = number;
            if (number > highest) highest = number;

        }
        count++;

    }

    if (count > 0) {
        printf("Count of numbers: %d\n", count);
        printf("Lowest: %d\n", lowest);
        printf("Highest: %d\n", highest);

    } else {
        printf("No valid number found.\n");
    }

    fclose(fptr);


    return 0;


}

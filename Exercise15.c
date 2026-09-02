#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40
#define MAX_NAME 200
#define MAX_LINE 200
typedef struct menu_item_ {
    char name[MAX_NAME];
    double price;
} menu_item;

int main() {
    char fname[50];
    char line[MAX_LINE];
    menu_item items[MAX_ITEMS];
    int count = 0;



    printf("Enter the file name: ");
    fgets(fname, sizeof(fname), stdin);


    size_t len = strlen(fname);
    if (len > 0 && fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }


    FILE *fptr;
    fptr = fopen(fname, "r");
    if (fptr == NULL) {
        fprintf(stderr, "Error. '%s' not found \n", fname);
        return 1;
    }

    while (count < 40 && fgets(line, sizeof(line), fptr) != NULL ) {


        char *token = strtok(line, ";");

        if (token == NULL) continue;
        strncpy(items[count].name, token, MAX_NAME - 1);
        items[count].name[MAX_NAME - 1] = '\0';

        token = strtok(NULL, ";");
        if (token == NULL) continue;

        items[count].price = atof(token);
        count++;

    }
    fclose(fptr);

    printf("\n%-60s %8s\n", "Item", "Price");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {


    printf("%-60s %8.2f %s\n", items[i].name, items[i].price);
    }
    return 0;

}

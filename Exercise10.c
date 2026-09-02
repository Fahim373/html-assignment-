#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ask user a string
//use fgets to read input and remove linefeed
//program prints length of string and checks if string is "stop"

int main() {
    while (1) {
        char buffer[100];

        printf("Enter a string: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len >0 && buffer[len-1] == '\n') {
                buffer[--len] = '\0';
            }
            printf("You typed: %s \n", buffer);
            printf("The length of your string is: %zu \n", len);

            if (strcmp(buffer, "stop") == 0 ) {
                return 0;

            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <string.h>


//write function (replace_char)/ 2strings => integer

int replace_char (char *str, const char *repl);
int main(void) {
    char text [100];
    char replacement [3];
    size_t len;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) != NULL) {
        len = strlen(text);
        if (len >0 && text[len-1] == '\n') {
            text[--len] = '\0';
        }
        printf("Enter Replacement characters: ");
        if (fgets(replacement, sizeof(replacement), stdin) != NULL) {
            len = strlen(replacement);
            if (len >0 && replacement[len-1] == '\n') {
                replacement[--len] = '\0';
            }
        }

        int count = replace_char (text, replacement);

        if (count > 0) {
            printf("Modified string: %s\n", text);
            printf("Number of replacements: %d\n", count);
        } else {
            printf("No modification happened.");
        }

    }
    return 0;
}

    int replace_char(char *str, const char *repl) {
        if (strlen (repl) < 2) {
            return 0;
        }
        char find = repl[0];
        char replace = repl[1];
        int count = 0;

        for (int i = 0; str [i] != '\0'; i++) {
            if (str[i] == find) {
                str[i] = replace;
                count++;
            }

        }
        return count;
    }



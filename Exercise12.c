#include <stdio.h>
#include <string.h>
//take two param str+word => int (numb words in str)
//use strstr()


int count_words(const char *sentence, const char *word);

int main() {
    char sentence[300];
    char word[100];
    printf("Enter a sentence: \n");

    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        size_t len = strlen(sentence);
        if (len >0 && sentence[len-1] == '\n') {
            sentence[--len] = '\0';
        }
    }

    while (1) {
        printf("Enter a word -type stop to quit-: \n");

        if (fgets(word, sizeof(word), stdin) != NULL) {
            size_t len = strlen(word);
            if (len >0 && word[len-1] == '\n') {
                word[--len] = '\0';
            }

            if (strcmp(word, "stop") == 0) {
                break;
            }

            int count = count_words(sentence, word);
            printf("The word occurs %d times\n", count);

        }

    }
    return 0;
}

        int count_words(const char *sentence, const char *word){
            int count = 0;
            const char *p = sentence;
            const char *found;

            while ((found = strstr(p, word)) != NULL) {
                count++;
                p = found + strlen(word);
            }
            return count;
        }





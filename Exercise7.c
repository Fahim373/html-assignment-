#include <stdio.h>
#include <stdbool.h>


bool read_positive(int *value) {
    int x;
    if (scanf("%d", &x) != 1) {
        while (getchar() != '\n');
        return false;
    }
    if (x>0) {
        *value=x;
        return true;
    }
    return false;
}

int main(void) {
    int guess;
    int fails = 0;
    while (fails < 3) {
        printf("Guess how much money I have!\n");
        printf("Enter a positive number: ");

        if (!read_positive(&guess)) {
            printf("Incorrect input!\n");
            fails++;
            continue;
        }

        printf("You didn't get it right. I have %d euros.\n", guess * 2 + 20);
    }

    printf("I give up! See you later!\n");
    return 0;

}
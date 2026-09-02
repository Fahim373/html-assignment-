#include <stdio.h>

int read_integer(void) {
    int x;
    while (scanf("%d", &x) != 1) {
        while (getchar() != '\n');
        printf("Invalid input, try again\n");
    }
    return x;
}

int read_range(int low, int high) {
    int x;
    while (1) {
        printf("Enter a number between %d and %d: ", low, high);
        x = read_integer();
        if ( x >= low && x<= high ) return x;
        printf("Number not in range, try again.\n");
    }
}

int main() {
    printf("Let's play!\n");
    for (int i = 1; i <= 3; i++) {
        printf("Roll a dice and enter your result.\n");
        int user = read_range(1,6);
        if (user == 6) printf("I got 6. It is a tie!\n");
        else printf("I got %d. I win!\n", user + 1);

    }
    printf("Better luck next time. Bye!\n");
    return 0;
}
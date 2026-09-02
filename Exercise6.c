#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        x= read_integer();
        if (x >= low && x <= high ) return x;
        printf("Number not in range, try again.\n");
    }
}

int roll_dice(int sides) {
    return (rand() % sides) +1;
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("\n1 - Roll D6\n2- Roll D10\n3 - Quit\n");
        choice = read_range(1,3);
        if (choice == 1) printf("You rolled: %d\n", rand() % 6 + 1);
        if (choice == 2) printf("You rolled: %d\n", rand() % 10 + 1);
    } while (choice != 3);
    return 0;
}
#include <stdio.h>

int read_integer(void) {
    int x;
    while (scanf("%d", &x) != 1) {
    while (getchar() != '\n');
    printf("Invalid input, try again\n");
    }
    return x;
}

int main() {
    int num, count = 0, sum = 0;
    while (1) {
        printf("Enter positive numbers or negative to stop:");
        num = read_integer();
        if (num < 0) break;
        sum += num;
        count++;
    }

    if (count > 0) {
        printf("You entered %d numbers. The average is %.3f.\n", count, (double)sum / count);
    }
    else
        printf("No positive numbers were entered\n");
    return 0;

    }


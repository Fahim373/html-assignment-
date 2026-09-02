#include <stdio.h>

//Ex2
int main() {
    float income[12], tax[12];
    float lowRate, highRate, limit;
    float totalIncome = 0;
    printf("Enter tax rate:\n");
    scanf("%f", &lowRate);
    printf("Enter income limit:\n");
    scanf("%f", &limit);
    printf("Enter tax rate for income over the limit:\n");
    scanf("%f", &highRate);


    lowRate /= 100;
    highRate /= 100;

    for (int i = 0; i < 12; i++) {
        do { printf("Enter income for month %d:\n", i+1);
            if (scanf("%f", &income[i]) != 1) {
                while (getchar() != '\n');
                printf("invalid input, try again.\n");
                income[i] = -1;
            }
            } while (income[i] < 0);


    }

    for (int i = 0; i < 12; i++) {
        float monthly = income[i];
        float taxRate;

        if (totalIncome >= limit) {
            taxRate = monthly * highRate;
        } else if (totalIncome + monthly <= limit) {
            taxRate = monthly * lowRate;
        } else {
            float low = limit - totalIncome;
            float high = monthly - low;
            taxRate = low * lowRate + high * highRate;
        }
        tax[i] = taxRate;
        totalIncome += monthly;
    }

    printf("\nMonth\tIncome\tTax\n");
    for (int i = 0; i < 12; i++) {
        printf("%d\t%.2f\t%.2f\n", i+1, income[i], tax[i]);
    }
    return 0;
}

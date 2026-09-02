#include <stdio.h>
//Ex1

int main() {
    float busCost, taxiCost, money;
    int choice;
    printf("Enter price of bus ticket: ");
    scanf("%f", &busCost);

    printf("Enter price of taxi ticket: ");
    scanf("%f", &taxiCost);

    printf("Enter how much money you have: ");
    scanf("%f", &money);

    while (1) {
        if (money < busCost && money < taxiCost) {
            printf("You don´t have enough money for bus or taxi.\n");
            printf("You need to walk. Bye");
            break;
        }

        printf("\nChose what you want to take:\n");
        printf("\n1 - Bus %.2f Euros\n", busCost);
        printf("\n2 - Taxi %.2f Euros\n", taxiCost);


        do {
            printf("Enter your selection: \n");
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');
                printf("invalid input, try again.\n");
                choice = 0;
            }
        } while (choice != 1 && choice != 2);

        if (choice == 1) {
            if (money >= busCost) {
                money = money - busCost; // to reduce money
                printf("You chose the bus.\n");
                printf("You have %.2f \n", money);
            } else {
                printf("You don't have enough money for bus.\n");
            }
        } else if (choice == 2) {
            if (money >= taxiCost) {
                money = money - taxiCost; // to reduce money
                printf("You chose the taxi.\n");
                printf("You have %.2f left \n", money);
            } else {
                printf("You chose the taxi.\n");
                printf("You don't have enough money for taxi.\n");
                printf("You have %.2f left\n", money);
            }
        }
    }
    return 0;
}

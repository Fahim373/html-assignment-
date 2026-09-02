#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int find_first(const unsigned int *array, unsigned int what) {
    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == what) {
            return i; // found
        }
    }
    return -1; //not found
}

int main(void) {
    unsigned int arr[20];

    srand (time(NULL));

    for (int i = 0; i < 19; i++) {
        arr[i] = rand() % 20 + 1;
    }
    arr [19] = 0;

    printf("Array contents: \n");
    for (int i = 0; i < 20; i++) {
        printf("%u ", arr[i]);
    }
    printf("\n");

    unsigned int num;
    while (1) {
        printf("Enter a number to search for (0 to stop): ");
        if (scanf("%d", &num) != 1) {
            while (getchar() != '\n');
            printf("Invalid input, try again.\n");
            continue;
        }
        if (num == 0) break;

        int idx = find_first(arr, num);
        if (idx == -1) printf("Not found.\n");
        else printf("Found at index %d\n", idx);
    }
    return 0;
}
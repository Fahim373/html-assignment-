#include <stdio.h>
//Ex3

int main() {
    int n;
    printf("How many students: ");
    scanf("%d", &n);

    int grades[n];
    for (int i = 0; i < n; i++) {
        grades[i] = -1;
    }

    while (1) {
        int student;
        do {
            printf("Enter student number (1 - %d) or 0 to stop: ", n);
            if (scanf("%d", &student) != 1 ) {
                while (getchar() != '\n');
                printf("Invalid input, try again.\n");
                student = -2;
            }} while (student <0 || student > n);

        if (student == 0) break;
        if (student < 1 || student > n) {
            printf("Invalid student number! \n");
            continue;
        }
        int grade;
        while (1) {
            printf("Enter grade: (0-5) for student %d or -1 to cancel: ", student);
            scanf("%d", &grade);

            if (grade == -1 || (grade >= 0 && grade <= 5)) {
                grades[student - 1 ] = grade;
                break;

            } else {
                printf("Invalid grade! `\n");
            }
        }
    }

    printf("\n student Grade\n");
    for (int i = 0; i < n; i++) {
        if (grades[i] == -1) {
            printf("%-9d N/A\n", i+1);
        } else {
            printf("%-9d %d\n", i+1, grades[i]);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2025"
#define MAX_ATTEMPTS 3
#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    int id;
    int math, physics, english;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    printf("Press Enter to continue...");
    getchar();
    getchar();
}

void showIntroScreen() {
    printf("========================================\n");
    printf("=                                      =\n");
    printf("=            GRADE SYSTEM              =\n");
    for (int i = 0; i < 16; i++) printf("=                                      =\n");
    printf("=          Enter password below        =\n");
    printf("========================================\n");
}

int verifyPassword() {
    char input[10];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter 4-digit password: ");
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            printf("Welcome to the system.\n");
            return 1;
        } else {
            printf("Incorrect password.\n");
            attempts++;
        }
    }
    printf("Too many attempts. Exiting.\n");
    return 0;
}

void showMenu() {
    printf("------------[Grade System]------------\n");
    printf("| a. Enter student grades            |\n");
    printf("| b. Display student grades          |\n");
    printf("| c. Search for student grades       |\n");
    printf("| d. Grade ranking                   |\n");
    printf("| e. Exit system                     |\n");
    printf("--------------------------------------\n");
}

void enterGrades() {
    clearScreen();
    int n;
    while (1) {
        printf("Enter number of students (5-10): ");
        scanf("%d", &n);
        if (n >= 5 && n <= 10) break;
        printf("Invalid number. Try again.\n");
    }

    student_count = n;
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);

        while (1) {
            printf("ID (6-digit): ");
            scanf("%d", &students[i].id);
            if (students[i].id >= 100000 && students[i].id <= 999999) break;
            printf("Invalid ID. Try again.\n");
        }

        while (1) {
            printf("Math score (0-100): ");
            scanf("%d", &students[i].math);
            if (students[i].math >= 0 && students[i].math <= 100) break;
            printf("Invalid score. Try again.\n");
        }

        while (1) {
            printf("Physics score (0-100): ");
            scanf("%d", &students[i].physics);
            if (students[i].physics >= 0 && students[i].physics <= 100) break;
            printf("Invalid score. Try again.\n");
        }

        while (1) {
            printf("English score (0-100): ");
            scanf("%d", &students[i].english);
            if (students[i].english >= 0 && students[i].english <= 100) break;
            printf("Invalid score. Try again.\n");
        }
    }

    printf("Data entry complete.\n");
    pauseScreen();
}

void displayGrades() {
    clearScreen();
    printf("Name       ID       Math  Physics  English  Average\n");
    for (int i = 0; i < student_count; i++) {
        float avg = (students[i].math + students[i].physics + students[i].english) / 3.0f;
        printf("%-10s %06d   %3d     %3d       %3d     %.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               avg);
    }
    pauseScreen();
}

int main() {
    showIntroScreen();
    if (!verifyPassword()) return 0;

    char choice;
    while (1) {
        clearScreen();
        showMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'a' || choice == 'A') {
            enterGrades();
        } else if (choice == 'b' || choice == 'B') {
            displayGrades();
        } else if (choice == 'e' || choice == 'E') {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid option.\n");
            pauseScreen();
        }
    }

    return 0;
}

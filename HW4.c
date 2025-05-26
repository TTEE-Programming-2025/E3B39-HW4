#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2025"
#define MAX_ATTEMPTS 3

void showIntroScreen() {
    printf("********************************************\n");
    printf("1     .----------.                          \n");
    printf("2   .'            `.                        \n");
    printf("3  /   .--------.   \\                       \n");
    printf("4 ;   /          \\   ;                      \n");
    printf("5 |  ;   WELCOME   ;  |                     \n");
    printf("6 ;   \\   TO MY   /   ;                     \n");
    printf("7  \\   `--------'   /                      \n");
    printf("8   `.   PROGRAM  .'                        \n");
    printf("9     `-........-'                          \n");
    printf("10                                           \n");
    printf("11      ( o.o )     (��!)                  \n");
    printf("12                                           \n");
    printf("13      ( owo )     (�A�n!)                \n");
    printf("14                                           \n");
    printf("15      ( ^_^ )     (�ǳƦn�F��?)         \n");
    printf("16                                           \n");
    printf("17      �п�J�z���K�X�H�i�J�t��          \n");
    printf("18                                           \n");
    printf("19 **************************************** \n");
    printf("20                                           \n");
}

int verifyPassword() {
    char input[10];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("�п�J 4 ��ƱK�X�]�� %d �����ա^�G", attempts + 1);
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("�K�X���T�A�w��i�J�t�ΡI\n");
            return 1;
        } else {
            printf("�K�X���~�A�ЦA�դ@���C\n\n");
            attempts++;
        }
    }

    printf("�K�X���~�w�F 3 ���A�t����w�C\n");
    return 0;
}

void showMainMenu() {   
    system("cls"); 

    printf("------------[Grade System]------------\n");
    printf("| a. Enter student grades            |\n");
    printf("| b. Display student grades          |\n");
    printf("| c. Search for student grades       |\n");
    printf("| d. Grade ranking                   |\n");
    printf("| e. Exit system                     |\n");
    printf("--------------------------------------\n");
}

int main() {
    showIntroScreen();

    if (verifyPassword()) {
        showMainMenu();  
    } else {
        printf("�{�������C\n");
    }

    return 0;
}

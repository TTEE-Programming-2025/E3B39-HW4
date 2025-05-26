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
    printf("11      ( o.o )     (嗨!)                  \n");
    printf("12                                           \n");
    printf("13      ( owo )     (你好!)                \n");
    printf("14                                           \n");
    printf("15      ( ^_^ )     (準備好了嗎?)         \n");
    printf("16                                           \n");
    printf("17      請輸入您的密碼以進入系統          \n");
    printf("18                                           \n");
    printf("19 **************************************** \n");
    printf("20                                           \n");
}

int verifyPassword() {
    char input[10];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("請輸入 4 位數密碼（第 %d 次嘗試）：", attempts + 1);
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("密碼正確，歡迎進入系統！\n");
            return 1;
        } else {
            printf("密碼錯誤，請再試一次。\n\n");
            attempts++;
        }
    }

    printf("密碼錯誤已達 3 次，系統鎖定。\n");
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
        printf("程式結束。\n");
    }

    return 0;
}

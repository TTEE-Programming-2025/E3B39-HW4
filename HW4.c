#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 10
#define PASSWORD 2025

typedef struct {
    char name[20];
    int id;
    int math;
    int physics;
    int english;
    float avg;
} Student;

Student students[MAX];
int studentCount = 0;

// 顯示個人風格畫面
void showIntro() {
    system("cls");
    printf("**************************************\n");
    printf("*                                    *\n");
    printf("*          Welcome to My            *\n");
    printf("*        Student Grade System       *\n");
    for (int i = 0; i < 16; i++) {
        printf("*                                    *\n");
    }
    printf("*          Made by [YourName]       *\n");
    printf("**************************************\n");
}

// 驗證密碼
int checkPassword() {
    int input, count = 0;
    while (count < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("密碼正確，歡迎使用！\n");
            return 1;
        } else {
            printf("密碼錯誤，請再試一次。\n");
            count++;
        }
    }
    printf("錯誤次數過多，系統結束。\n");
    return 0;
}

// 顯示主選單
void showMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
}

// 輸入學生成績
void enterGrades() {
    system("cls");
    printf("請輸入學生人數 (5~10)：");
    scanf("%d", &studentCount);
    while (studentCount < 5 || studentCount > 10) {
        printf("人數錯誤，請重新輸入 (5~10)：");
        scanf("%d", &studentCount);
    }

    for (int i = 0; i < studentCount; i++) {
        printf("學生 %d 姓名：", i + 1);
        scanf("%s", students[i].name);

        printf("學生 %d 學號(6位數)：", i + 1);
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("錯誤！請輸入6位數學號：");
            scanf("%d", &students[i].id);
        }

        printf("數學成績：");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("錯誤！請輸入0~100分：");
            scanf("%d", &students[i].math);
        }

        printf("物理成績：");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("錯誤！請輸入0~100分：");
            scanf("%d", &students[i].physics);
        }

        printf("英文成績：");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("錯誤！請輸入0~100分：");
            scanf("%d", &students[i].english);
        }

        students[i].avg = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

// 顯示所有學生成績
void displayGrades() {
    system("cls");
    printf("姓名\t學號\t數學\t物理\t英文\t平均\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].avg);
    }
    printf("請按任意鍵繼續...");
    getch();
    system("cls");
}

// 搜尋學生成績
void searchStudent() {
    char target[20];
    int found = 0;
    system("cls");
    printf("請輸入要查詢的姓名：");
    scanf("%s", target);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, target) == 0) {
            printf("姓名：%s\n學號：%d\n數學：%d\n物理：%d\n英文：%d\n平均：%.1f\n",
                   students[i].name,
                   students[i].id,
                   students[i].math,
                   students[i].physics,
                   students[i].english,
                   students[i].avg);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("查無資料！\n");
    }
    printf("請按任意鍵繼續...");
    getch();
    system("cls");
}

// 排序與顯示排名
void gradeRanking() {
    system("cls");
    Student temp;
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].avg < students[j].avg) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("姓名\t學號\t平均\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    printf("請按任意鍵繼續...");
    getch();
    system("cls");
}

// 離開系統
int exitSystem() {
    char ch;
    while (1) {
        printf("確定離開？(y/n)：");
        ch = getch();
        if (ch == 'y' || ch == 'Y') return 1;
        if (ch == 'n' || ch == 'N') return 0;
    }
}

int main() {
    char choice;

    showIntro();

    if (!checkPassword()) return 0;

    while (1) {
        showMenu();
        printf("請選擇功能：");
        choice = getch();
        switch (choice) {
            case 'a':
                enterGrades();
                break;
            case 'b':
                displayGrades();
                break;
            case 'c':
                searchStudent();
                break;
            case 'd':
                gradeRanking();
                break;
            case 'e':
                if (exitSystem()) return 0;
                system("cls");
                break;
            default:
                printf("\n無效輸入，請重新選擇。\n");
        }
    }
    return 0;
}

/*
心得：
透過這次專案，我熟悉了結構（struct）的使用，以及條件判斷、迴圈與輸入檢查等基本技巧。
也了解如何設計一個完整的互動式系統，處理使用者輸入並提供明確的回饋。
整體來說，這是一個非常實用的 C 語言練習。
*/

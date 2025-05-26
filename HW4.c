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

// ��ܭӤH����e��
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

// ���ұK�X
int checkPassword() {
    int input, count = 0;
    while (count < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input);
        if (input == PASSWORD) {
            printf("�K�X���T�A�w��ϥΡI\n");
            return 1;
        } else {
            printf("�K�X���~�A�ЦA�դ@���C\n");
            count++;
        }
    }
    printf("���~���ƹL�h�A�t�ε����C\n");
    return 0;
}

// ��ܥD���
void showMenu() {
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
}

// ��J�ǥͦ��Z
void enterGrades() {
    system("cls");
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &studentCount);
    while (studentCount < 5 || studentCount > 10) {
        printf("�H�ƿ��~�A�Э��s��J (5~10)�G");
        scanf("%d", &studentCount);
    }

    for (int i = 0; i < studentCount; i++) {
        printf("�ǥ� %d �m�W�G", i + 1);
        scanf("%s", students[i].name);

        printf("�ǥ� %d �Ǹ�(6���)�G", i + 1);
        scanf("%d", &students[i].id);
        while (students[i].id < 100000 || students[i].id > 999999) {
            printf("���~�I�п�J6��ƾǸ��G");
            scanf("%d", &students[i].id);
        }

        printf("�ƾǦ��Z�G");
        scanf("%d", &students[i].math);
        while (students[i].math < 0 || students[i].math > 100) {
            printf("���~�I�п�J0~100���G");
            scanf("%d", &students[i].math);
        }

        printf("���z���Z�G");
        scanf("%d", &students[i].physics);
        while (students[i].physics < 0 || students[i].physics > 100) {
            printf("���~�I�п�J0~100���G");
            scanf("%d", &students[i].physics);
        }

        printf("�^�妨�Z�G");
        scanf("%d", &students[i].english);
        while (students[i].english < 0 || students[i].english > 100) {
            printf("���~�I�п�J0~100���G");
            scanf("%d", &students[i].english);
        }

        students[i].avg = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }
}

// ��ܩҦ��ǥͦ��Z
void displayGrades() {
    system("cls");
    printf("�m�W\t�Ǹ�\t�ƾ�\t���z\t�^��\t����\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].avg);
    }
    printf("�Ы����N���~��...");
    getch();
    system("cls");
}

// �j�M�ǥͦ��Z
void searchStudent() {
    char target[20];
    int found = 0;
    system("cls");
    printf("�п�J�n�d�ߪ��m�W�G");
    scanf("%s", target);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, target) == 0) {
            printf("�m�W�G%s\n�Ǹ��G%d\n�ƾǡG%d\n���z�G%d\n�^��G%d\n�����G%.1f\n",
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
        printf("�d�L��ơI\n");
    }
    printf("�Ы����N���~��...");
    getch();
    system("cls");
}

// �ƧǻP��ܱƦW
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
    printf("�m�W\t�Ǹ�\t����\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].id, students[i].avg);
    }
    printf("�Ы����N���~��...");
    getch();
    system("cls");
}

// ���}�t��
int exitSystem() {
    char ch;
    while (1) {
        printf("�T�w���}�H(y/n)�G");
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
        printf("�п�ܥ\��G");
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
                printf("\n�L�Ŀ�J�A�Э��s��ܡC\n");
        }
    }
    return 0;
}

/*
�߱o�G
�z�L�o���M�סA�ڼ��x�F���c�]struct�^���ϥΡA�H�α���P�_�B�j��P��J�ˬd���򥻧ޥ��C
�]�F�Ѧp��]�p�@�ӧ��㪺���ʦ��t�ΡA�B�z�ϥΪ̿�J�ô��ѩ��T���^�X�C
����ӻ��A�o�O�@�ӫD�`��Ϊ� C �y���m�ߡC
*/

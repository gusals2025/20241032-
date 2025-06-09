#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main() {
    int scores[30];
    int studentNumber = 0;
    double average;
    int option = 0;

    srand((unsigned)time(0));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, 30);
    printf("�б� ��� ����: %.2f\n", average);

    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d�� �л��� ����: %d\n", studentNumber, score);
    }
    else {
        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n");
    }

    printf("\n[�л� ���� ��� �ɼ� ����]\n");
    printf("0: ��ü �л�\n1: ��� �̻�\n2: ��� �̸�\n�ɼ� ����: ");
    scanf_s("%d", &option);

    printScore(scores, 30, average, option);

    return 0;
}

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1;
    }
}

void printScore(int scores[], int size, double average, int option) {
    printf("\n=== �л� ���� ��� ===\n");
    for (int i = 0; i < size; i++) {
        if (option == 0 ||
            (option == 1 && scores[i] >= average) ||
            (option == 2 && scores[i] < average)) {
            printf("%2d�� �л�: %3d��\n", i + 1, scores[i]);
        }
    }
}

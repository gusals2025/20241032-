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
    printf("학급 평균 점수: %.2f\n", average);

    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수: %d\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }

    printf("\n[학생 정보 출력 옵션 선택]\n");
    printf("0: 전체 학생\n1: 평균 이상\n2: 평균 미만\n옵션 선택: ");
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
    printf("\n=== 학생 점수 출력 ===\n");
    for (int i = 0; i < size; i++) {
        if (option == 0 ||
            (option == 1 && scores[i] >= average) ||
            (option == 2 && scores[i] < average)) {
            printf("%2d번 학생: %3d점\n", i + 1, scores[i]);
        }
    }
}

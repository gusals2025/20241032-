#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scores[10];
    int sum = 0;
    double average;

    srand((unsigned int)time(0));

    for (int i = 0; i < 10; i++) {
        scores[i] = rand() % 101;
        sum += scores[i];
    }

    average = sum / 10.0;

    printf("학생 성적 평균: %.2f\n", average);
    return 0;
}

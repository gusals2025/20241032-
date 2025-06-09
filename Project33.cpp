#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printScores(int* scores, int size);

int main() {
    int initialSize = 5;
    int* scores = (int*)malloc(initialSize * sizeof(int));
    int size = initialSize;

    if (scores == NULL) {
        return 1;
    }

    srand((unsigned)time(0));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }

    printScores(scores, size);

    int deleteIndex = 2;
    for (int i = deleteIndex; i < size - 1; i++) {
        scores[i] = scores[i + 1];
    }
    size--;

    printScores(scores, size);

    int newStudents = 2;
    scores = (int*)realloc(scores, (size + newStudents) * sizeof(int));
    if (scores == NULL) {
        return 1;
    }

    for (int i = size; i < size + newStudents; i++) {
        scores[i] = rand() % 101;
    }
    size += newStudents;

    printScores(scores, size);

    free(scores);
    return 0;
}

void printScores(int* scores, int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d번 학생: %3d점\n", i + 1, scores[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char input[MAX + 1];
    char* stack = (char*)malloc(MAX * sizeof(char));
    int top = -1;

    if (stack == NULL) {
        return 1;
    }

    printf("문자열을 입력하세요: ");
    fgets(input, MAX + 1, stdin);
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        stack[++top] = input[i];
    }

    printf("거꾸로 출력된 문자열: ");
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    free(stack);
    return 0;
}

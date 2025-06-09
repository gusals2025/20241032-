#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main() {
    char input[MAX + 1];
    char* stack = (char*)malloc(MAX * sizeof(char));
    int top = -1;
    int valid = 1;

    if (stack == NULL) {
        return 1;
    }

    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {
                valid = 0;
                break;
            }
            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                valid = 0;
                break;
            }
        }
    }

    if (top != -1) {
        valid = 0;
    }

    if (valid) {
        printf("유효한 괄호\n");
    }
    else {
        printf("유효하지 않은 괄호\n");
    }

    free(stack);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_PAGES 50

typedef struct {
    char documentName[50];
    int numPages;
} PrintJob;

typedef struct {
    PrintJob queue[SIZE];
    int front;
    int rear;
} PrintQueue;

void initQueue(PrintQueue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(PrintQueue* q) {
    return q->front == q->rear;
}

bool isFull(PrintQueue* q) {
    return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(PrintQueue* q, char* documentName, int numPages) {
    if (numPages > MAX_PAGES) {
        printf("������ ���� 50���� �ʰ��Ͽ� �۾��� �߰��� �� �����ϴ�.\n");
        return false;
    }

    if (isFull(q)) {
        printf("��⿭�� ���� á���ϴ�. �۾��� �߰��� �� �����ϴ�.\n");
        return false;
    }

    strcpy_s(q->queue[q->rear].documentName, sizeof(q->queue[q->rear].documentName), documentName);
    q->queue[q->rear].numPages = numPages;
    q->rear = (q->rear + 1) % SIZE;
    printf("�۾� '%s' (%d ������)�� ��⿭�� �߰��Ǿ����ϴ�.\n", documentName, numPages);
    return true;
}

PrintJob dequeue(PrintQueue* q) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�. �۾��� �����ϴ�.\n");
        PrintJob emptyJob = { "", 0 };
        return emptyJob;
    }

    PrintJob job = q->queue[q->front];
    q->front = (q->front + 1) % SIZE;
    return job;
}

void printQueue(PrintQueue* q) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�.\n");
        return;
    }

    printf("���� ��� ���� �۾�:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("- %s (%d ������)\n", q->queue[i].documentName, q->queue[i].numPages);
        i = (i + 1) % SIZE;
    }
}

bool cancelJob(PrintQueue* q, const char* targetName) {
    if (isEmpty(q)) {
        printf("��⿭�� ��� �ֽ��ϴ�.\n");
        return false;
    }

    int i = q->front;
    int foundIndex = -1;

    while (i != q->rear) {
        if (strcmp(q->queue[i].documentName, targetName) == 0) {
            foundIndex = i;
            break;
        }
        i = (i + 1) % SIZE;
    }

    if (foundIndex == -1) {
        printf("�ش� ������ �����ϴ�.\n");
        return false;
    }

    while (foundIndex != q->rear) {
        int nextIndex = (foundIndex + 1) % SIZE;
        if (nextIndex == q->rear) break;
        q->queue[foundIndex] = q->queue[nextIndex];
        foundIndex = nextIndex;
    }

    q->rear = (q->rear - 1 + SIZE) % SIZE;
    printf("���� '%s'�� ��⿭���� ���ŵǾ����ϴ�.\n", targetName);
    return true;
}

void clearQueue(PrintQueue* q) {
    q->front = 0;
    q->rear = 0;
    printf("��⿭�� �ʱ�ȭ�Ǿ����ϴ�.\n");
}

int main() {
    PrintQueue q;
    initQueue(&q);

    int choice;
    char documentName[50];
    int numPages;

    while (true) {
        printf("\n1. �۾� �߰�\n2. �۾� ó��\n3. ��⿭ ���\n4. �μ� ���\n5. ��⿭ �ʱ�ȭ\n6. ����\n����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("���� �̸�: ");
            scanf_s("%s", documentName, (unsigned)_countof(documentName));
            printf("������ ��: ");
            scanf_s("%d", &numPages);
            enqueue(&q, documentName, numPages);
            break;
        case 2: {
            PrintJob job = dequeue(&q);
            if (strlen(job.documentName) > 0) {
                printf("�۾� '%s' (%d ������)�� ó�� ���Դϴ�...\n", job.documentName, job.numPages);
            }
            break;
        }
        case 3:
            printQueue(&q);
            break;
        case 4:
            printf("����� ���� �̸�: ");
            scanf_s("%s", documentName, (unsigned)_countof(documentName));
            cancelJob(&q, documentName);
            break;
        case 5:
            clearQueue(&q);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���.\n");
            break;
        }
    }
}

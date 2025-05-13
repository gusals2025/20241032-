#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[20];
    struct Contact* next;
} Contact;

Contact* insertContact(Contact* head, const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if (head == NULL) {
        return newContact;
    }

    Contact* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newContact;
    return head;
}

void searchContact(Contact* head, const char* name) {
    Contact* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("연락처 '%s' 를 찾을 수 없습니다.\n", name);
}

Contact* deleteContact(Contact* head, const char* name) {
    Contact* current = head;
    Contact* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                Contact* temp = current->next;
                free(current);
                return temp;
            }
            else {
                prev->next = current->next;
                free(current);
                return head;
            }
        }
        prev = current;
        current = current->next;
    }

    printf("연락처 '%s' 를 찾을 수 없어 삭제하지 못했습니다.\n", name);
    return head;
}

void printContacts(Contact* head) {
    Contact* current = head;
    printf("==== 전화번호부 ====\n");
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("====================\n");
}

void freeList(Contact* head) {
    Contact* current = head;
    while (current != NULL) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Contact* head = NULL;

    head = insertContact(head, "홍길동", "010-1234-5678");
    head = insertContact(head, "김철수", "010-2345-6789");
    head = insertContact(head, "이영희", "010-3456-7890");

    printContacts(head);

    printf("\n[검색] 김철수:\n");
    searchContact(head, "김철수");

    printf("\n[삭제] 이영희:\n");
    head = deleteContact(head, "이영희");

    printContacts(head);

    freeList(head);
    return 0;
}

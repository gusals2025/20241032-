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
            printf("�̸�: %s, ��ȭ��ȣ: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("����ó '%s' �� ã�� �� �����ϴ�.\n", name);
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

    printf("����ó '%s' �� ã�� �� ���� �������� ���߽��ϴ�.\n", name);
    return head;
}

void printContacts(Contact* head) {
    Contact* current = head;
    printf("==== ��ȭ��ȣ�� ====\n");
    while (current != NULL) {
        printf("�̸�: %s, ��ȭ��ȣ: %s\n", current->name, current->phone);
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

    head = insertContact(head, "ȫ�浿", "010-1234-5678");
    head = insertContact(head, "��ö��", "010-2345-6789");
    head = insertContact(head, "�̿���", "010-3456-7890");

    printContacts(head);

    printf("\n[�˻�] ��ö��:\n");
    searchContact(head, "��ö��");

    printf("\n[����] �̿���:\n");
    head = deleteContact(head, "�̿���");

    printContacts(head);

    freeList(head);
    return 0;
}

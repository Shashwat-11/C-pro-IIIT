#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* node = newNode(data);
    if (head == NULL) {
        return node;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    return head;
}

struct Node* deleteByValue(struct Node* head, int x) {
    if (head == NULL) return head;

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != x) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int bookID;
        scanf("%d", &bookID);
        head = appendNode(head, bookID);
    }

    scanf("%d", &value);

    head = deleteByValue(head, value);
    printList(head);

    return 0;
}

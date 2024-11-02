#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* reverseBetween(struct Node* head, int l, int r) {
    if (!head || l == r) return head;
    
    struct Node* prev = NULL;
    struct Node* current = head;

    for (int i = 1; current && i < l; i++) {
        prev = current;
        current = current->next;
    }

    struct Node* beforeL = prev;
    struct Node* lNode = current;
    
    struct Node* nextNode = NULL;
    prev = NULL;
    for (int i = 0; current && i <= (r - l); i++) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    if (beforeL != NULL) {
        beforeL->next = prev;
    } else {
        head = prev;
    }

    lNode->next = current;

    return head;
}

int main() {
    int n, l, r;
    
    scanf("%d %d %d", &n, &l, &r);
    
    struct Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&head, value);
    }
    
    head = reverseBetween(head, l, r);
    
    printList(head);
    
    return 0;
}


#include"main.h"

void print(struct node * head) {
    while(head != NULL) {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct node *head = NULL;
    struct node *prev = NULL;
    for(int i = 0; i < n; i++) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        scanf("%s", temp->name);
        temp->next = NULL;
        if(head == NULL) {
            head = temp;
            prev = temp;
        } else {
            prev->next = temp;
            prev = temp;
        }
    }
    head = reverseingroups(head);
    print(head);
    for(int i = 0; i < n; i++) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node {
    char name[11];
    struct node *next;
};
struct node * reverseingroups(struct node * head);
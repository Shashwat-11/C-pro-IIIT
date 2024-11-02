#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node {
    int val;
    struct node *next;
};
struct node * sortLL(int len, struct node * head);
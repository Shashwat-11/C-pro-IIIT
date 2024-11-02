/* 
 * Assignment 5 Problem 1
 */
#include<stdio.h>
#include<stdlib.h> 


typedef struct Node{
  int data;
  struct Node* next;
}Node;
Node* arr[100000];
void appendNode(int a,int b)
{
  Node * temp=(Node*)malloc(sizeof(Node));
  Node * prevnext=(Node*)malloc(sizeof(Node));
  Node * newNode = (Node*)malloc(sizeof(Node));

  temp = arr[a];
  prevnext=temp->next;
  temp->next = newNode;
  newNode->data = b;
  newNode->next=prevnext;
  arr[b]=newNode;
  return;
}

int main()
{
  int n;
  Node * head = (Node*)malloc(sizeof(Node));
  head->data=0;
  head->next=NULL;
  arr[0]=head; 
  scanf("%d",&n);
  int a,b;
  for(int i=1;i<n;i++)
  {
    scanf("%d %d",&a,&b); 
    appendNode(a,b);
  }
  while(head!=NULL)
  {
    printf("%d ",head->data);
    head=head->next;
  }
  printf("\n");
  return 0;
} 

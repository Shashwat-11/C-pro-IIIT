/*
 Lab 6D problem 2
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node *createNode(int val)
{
  Node *newNode=(Node*)malloc(sizeof(Node));
  newNode->data=val;
  return newNode;
}

struct Node *appendNode(Node *head,int d)
{ 
  struct Node *node = createNode(d);
  node->next=head;
  return node;
}

struct Node *reverse(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node *addTwoLists(struct Node *num1, struct Node *num2)
{
  int s,c=0;
  Node *sum= NULL;
   
   while((num1!=NULL)||(num2!=NULL)||c!=0)
    {
    s=c;
    if(num1!=NULL)
    {  s=s+num1->data;
       num1=num1->next;
    }
    if(num2!=NULL)
    {  s=s+num2->data;
      num2=num2->next;
    }
    if(s <10)
      c=0;
    if(s>=10)
    {
      c=1;
      s=s-10;
    }
    sum=appendNode(sum,s);
  }

  return sum;
}

int main()
{
    // write your code here
  int n1,d;
   
  Node *head1 = NULL;
  Node *head2 = NULL;
  Node *sum= NULL;
  scanf("%d",&n1);
  char arr1[n1+1];
  if(n1==0)
  {
    head1 = (Node*)malloc(sizeof(Node));
    head1->data=0;
    head1->next=NULL;
  }
  else
  {
    for(int i=0;i<n1+1;i++)
    {
      scanf("%c",&arr1[i]);
    }
  }
  for(int i=1;i<n1+1;i++)
  {
    d=arr1[n1+1-i]-'0';
    head1=appendNode(head1,d);
  }
  int n2;
  scanf("%d",&n2);
  char arr2[n2+1];
  if(n2==0)
  {
    head2 = (Node*)malloc(sizeof(Node));
    head2->data=0;
    head2->next=NULL;
  }
  else
  {
    for(int i=0;i<n2+1;i++)
    {
      scanf("%c",&arr2[i]);
    }
  }
  for(int i=1;i<n2+1;i++)
  {
    d=arr2[n2+1-i]-'0';
    head2=appendNode(head2,d);
  }
  head1=reverse(head1); 
  head2=reverse(head2);
  sum=addTwoLists(head1,head2); 
   while(sum!=NULL)
  {
    printf("%d",sum->data);
    sum=sum->next;
  }
  //printf("\n");


    
    return 0;
} 

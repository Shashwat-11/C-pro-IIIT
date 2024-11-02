#include"main.h"

// Structure of the node of the linked list is:

/*struct node {
    int val;
    struct node *next;
};*/


struct node * sortLL(int n, struct node *head) 
{
  struct node * temphead = (struct node*)malloc(sizeof(struct node));
  struct node * printhead = (struct node*)malloc(sizeof(struct node));

  int temp;
  for(int i=n;i>0;i--)
  {
    temphead=head;
    for(int j=0;j<i-1;j++)
    {
      printhead=head;
/*      while(printhead!=NULL)//printing
      {
        printf("%d ",printhead->val);
        printhead=printhead->next;
      }
      printf("\n");
      printf("selected:%d\n",temphead->val);
*/
      if(temphead->val>temphead->next->val)//sorting
      {
        temp=temphead->val;
        temphead->val=temphead->next->val;
        temphead->next->val=temp;
      }
      temphead=temphead->next;
    }
  }
  return head; 
}

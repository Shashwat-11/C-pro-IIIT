#include"main.h"
/*struct node {
    char name[11];
    struct node *next;
};*/


int size=0,count=0,flag=0;

struct node* temp_head ;

struct node* recursion(struct node* head,int n)
{   
  struct node * pre = (struct node*)malloc(sizeof(struct node));
  struct node * send = (struct node*)malloc(sizeof(struct node));
  struct node * end = (struct node*)malloc(sizeof(struct node));
  struct node * temp = (struct node*)malloc(sizeof(struct node));
  count=count+n;
  if(count==size)
    flag=1;
  if(count>size)
  {
    if(flag==0)
      flag=1;
    else
      return;
   }
  send=head->next;
  end=head;
  for(int i=0;end->next!=NULL&&i<n;i++)
    end=end->next;
  pre=head;
  head=head->next;
  while(head!=end)
  {
    pre->next=head->next;
    temp=end->next;
    end->next=head;
    head->next=temp;
    head=pre->next;
    
  }
  recursion(send,n*2);
}

struct node * reverseingroups(struct node *head)
{
  struct node * temp = (struct node*)malloc(sizeof(struct node));

  temp=head;//size
  while(temp!=NULL)
  {
    size++;
    temp=temp->next;
  }
  if(size==1)//edge case
    return head;
  
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next=head;
   
  struct node * ans = (struct node*)malloc(sizeof(struct node));//pointer to return
  ans=head->next;
 
  //recursion
  recursion(temp,2);
  
  return ans;
  
}

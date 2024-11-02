/* 
 * Assignment 4 Problem 3
 */
#include<stdio.h>
int flag=0;
void sort(int n,int arr[n])
{
  for(int i=0;i<n-1;i++)
  {
   if(arr[i]>arr[i+1])
      break;
    else if(i==n-2)
    {
      for(int j=0;j<n;j++)
      {
        printf("%d ",arr[j]);
      }
      printf("\n");
      flag=1;
      return;
    }
  }
  for(int i=0;i<n-1;i++)
  {
   if(arr[i]<arr[i+1])
      break;
    else if(i==n-2)
    {
      for(int j=0;j<n;j++)
      {
        printf("%d ",arr[n-1-j]);
      }
      printf("\n");
      flag=1;
      return;
    }
  } 
  return;
}

int main(void)
{
  int a = -1000002;
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0; i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int max=arr[0],maxi=0;
  int temp;
  int maxp=a;
  for(int i=0; i<n;i++)
  {
    sort(n,arr);
    if(flag==1)
     return 0;

    maxi=0;
    max=a;
    for(int j=0; j<n-i;j++)
    {
      
      if(arr[j]>max)
      {
        max=arr[j];
        maxi=j;
      }
    }
    if(max==maxp)
    {
      printf("%d\n",-1);
      return 0;
    }
    else
      maxp=max;
    for(int j= maxi; j<n-i-1;j++)
    {
      temp = arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
    }
    
   }
} 

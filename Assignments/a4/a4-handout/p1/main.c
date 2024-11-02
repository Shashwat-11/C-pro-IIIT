// Assignment 4 problem 1

#include<stdio.h>
int m = 1000000007;

int main()
{
  int n;
  scanf("%d",&n);
  int a1=1,a2=1;
  if(n==1)
  {
    printf("%d",1);
    return 1;
  }
  else if(n==2)
  {
    printf("%d",2);
    return 0;
  } 
  int temp; long int a3;
  for(int i =2;i<=n;i++)
  {
    a3 =(a1+a2)%m;
    a1=a2;
    a2=a3;
  }
  printf("%ld\n",a3);
  return 0;
}   

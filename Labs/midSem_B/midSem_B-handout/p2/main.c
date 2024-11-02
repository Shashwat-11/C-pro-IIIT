/* 
 * Lab 4 Problem 2
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  int arr0[n];
  int arr1[n];
  int arr2[n];
  for(int i=0;i<n;i++)
  {
	arr0[i]=-1;
        arr1[i]=-1;
        arr2[i]=-1;
  }
  int j0=0,j1=0,j2=0;
  int a;
  for(int i =0;i<n;i++)  
  {
  	scanf("%d",&a);
	if(a==0)
	{
	  arr0[j0]=0;
	  j0++;
	}
	else if(a==1)
	{
	  arr1[j1]=1;
	  j1++;
	}
	else
	{
	  arr2[j2]=2;
	  j2++;
	}
  }
  int b=arr0[0];
  for(int i=1;i<n&&b!=-1;i++)
  {
	printf("%d ",b);
	b=arr0[i];
	if(i==n-1)
	  printf("%d ",0);
  }
  b=arr1[0];
  for(int i=1;i<n&&b!=-1;i++)
  {
	printf("%d ",b);
	b=arr1[i];
		if(i==n-1)
	  printf("%d ",1);
  }
  b=arr2[0];
  for(int i=1;i<n&&b!=-1;i++)
  {
	printf("%d ",b);
	b=arr2[i];
		if(i==n-1)
	  printf("%d ",2);
  }
    return 0;
} 

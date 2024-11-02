/* 
 * MidSem-B, Problem 3
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  long long int *arr = (long long int*)malloc(n*sizeof(long long int));
  if(arr==NULL)
  {
	  printf("bohot maarunga");
	  return -1;
  }
  for(int i=0;i<n;i++)
  {
	scanf("%lld",arr+i);  
  }
  long long int sum=0;
  for(int i=0;i<n;i++)
  {
	  sum=sum+arr[i];
  }
  printf("Sum of array: %lld \n",sum);
  long long int max=arr[0];
  for(int i=1;i<n;i++)
  {	
	 if(arr[i]>max)
		 max=arr[i];
  }
  printf("Maximum value: %lld \nReversed array: ",max);
  for(int i=0;i<n-1;i++)
  {
  	printf("%lld ",arr[n-1-i]);
  }
  printf("%lld",arr[0]);
  free(arr);
    return 0;
} 

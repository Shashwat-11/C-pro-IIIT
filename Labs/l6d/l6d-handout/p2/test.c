#include<stdio.h>

int main()
{
    int n1;
    scanf("%d",&n1);
    char arr[n1+1];
    arr[n1+1]='\0';
    for(int i=0;i<n1+1;i++)
    {
        scanf("%c",&arr[i]);
    }
    
        printf("0:%c",arr[0]);
    

}
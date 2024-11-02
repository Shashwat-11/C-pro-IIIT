#include <stdio.h>
#include <stdlib.h>
#include "transpose.c"


// Function prototype for transposing the array
// void transposeArray(int *array, int n, int row, int col);

int main() {
    int n; // array size

    // Input the size of the array
    scanf("%d",&n);


    // Todo: Dynamically allocate memory for the array
    int **arr= (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
	  arr[i]=(int*)malloc(n*sizeof(int));
    }
    // Todo: Input the elements of the array
    for(int i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
		scanf("%d",(*(arr+i)+j));
	}
    }

    // Todo: Call the transpose function
    transposeArray(arr, n, 0, 1);

    // Todo: Output the transposed array
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
	{
		printf("%d ",arr[i][j]);
	}
	printf("\n");
    }
	
    // Todo: Free allocated memory
    free(arr); 
    return 0;
}

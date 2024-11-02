// transposeArray.c

#include <stdio.h>

// Function prototype for transposing the array
void transposeArray(int **array, int n, int row, int col)
{
	if(row==n-1)
		return;
	for(int i=col;i<n;i++)
	{
		int temp;
		temp = array[row][i];
		array[row][i]=array[i][row];
		array[i][row]=temp;

	}
	col++;row++;
	transposeArray(array,n,row,col);
	return;
        
}

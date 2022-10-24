#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int** matrixes_operation(int** m1, int** m2, int x, int y, int operation)
{
    int** final_matrix = malloc(y * sizeof(int*));
	for(int i=0; i<y; ++i)
	{	
		int* mini_array = malloc(x * sizeof(int));
		for(int j=0; j<x; ++j)
		{
			switch(operation)
			{
				case 0:
					mini_array[j] = m1[i][j] + m2[i][j];            
					break;
				case 1:
					mini_array[j] = m1[i][j] * m2[i][j];             
					break;
				case 2:
					mini_array[j] = m1[i][j] - m2[i][j]; 
					break;
			}
		}
		final_matrix[i] = mini_array;
	} 

	return final_matrix;
}

int** matrix_transpose(int** m, int x, int y)
{
	int** transposed_matrix = malloc(x * sizeof(int*));
	for(int i=0; i<x; ++i)
	{
		int* mini_array = malloc(y * sizeof(int));
		for(int j=0; j<y; ++j)
		{
			mini_array[j] = m[j][i];
		}
		transposed_matrix[i] = mini_array;

	}
	
	return transposed_matrix;
}



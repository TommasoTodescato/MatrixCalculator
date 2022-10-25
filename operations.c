#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int** matrixes_algebra(int** m1, int** m2, int x, int y, int operation)
{
    int** result = malloc(y * sizeof(int*));
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
		result[i] = mini_array;
	}

	return result;
}

int** matrixes_augmentation(int** base_matrix, int** matrix_to_add, int base_x, int base_y)
{
	int** result = malloc(base_y * sizeof(int*));
	for(int i=0; i<base_y; ++i)
	{
		int** mini_array = malloc(base_x+1 * sizeof(int));
		mini_array[base_x] = matrix_to_add[i][0];
		result[i] = mini_array;
	}

	return result;
}

int** matrix_transpose(int** m, int x, int y)
{
	int** result = malloc(x * sizeof(int*));
	for(int i=0; i<x; ++i)
	{
		int* mini_array = malloc(y * sizeof(int));
		for(int j=0; j<y; ++j)
		{
			mini_array[j] = m[j][i];
		}
		result[i] = mini_array;

	}
	
	return result;
}
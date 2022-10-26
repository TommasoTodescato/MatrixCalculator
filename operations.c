#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int** matrix_algebra(int** m1, int** m2, int x, int y, int operation)
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
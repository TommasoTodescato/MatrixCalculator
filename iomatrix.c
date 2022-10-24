#include <stdlib.h>
#include <stdio.h>
#include "iomatrix.h"

void moveright(int deltaX)
{
    printf("\033[%dC", deltaX);
}

void moveup(int deltaY)
{
    printf("\033[%dA", deltaY);
}

int countdigits(int num)
{
	int count = 0;
	while(num>0)
	{
		num = num/10;
		count++;
	}
	
	return count;
}

int** matrix_make(int x, int y)
{
	printf("\n");
	int** big_array = malloc(y * sizeof(int*));
	int counter = 0;
	for(int i=0; i<y; ++i)
	{
		int* mini_array = malloc(x * sizeof(int));
		printf("| ");
		for(int j=0; j<x; ++j)
		{
			scanf("%d", &mini_array[j]);
			counter = counter + countdigits(mini_array[j]) - 1;
			moveup(1);
			moveright(j*2+4 + counter);
		}
		counter = 0;
		big_array[i] = mini_array;
		printf("|\n");
	}

	return big_array;
}

void matrix_print(int** m, int x, int y)
{
	printf("\n");
	for(int i=0; i<y; ++i)
	{
		printf("|");
		for(int j=0; j<x; ++j)
		{
			printf(" %d", m[i][j]);
		}
		printf(" |\n");
	}
}
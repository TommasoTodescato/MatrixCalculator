#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "iomatrix.h"

//To implement:
//	input more than 2 matrixes
//	matrix augmentation
//	elementary row operations
//	matrix inversion
//	matrix multiplication
//	matrix dot product
//	matrix vector product
//	matrix scalar multiplication
//	https://ee263.stanford.edu/archive/matrix-primer-lect2.pdf

int main()
{
	short int dim_x;
	short int dim_y;
	short int operation;

	printf("Operations\n 0 - Quit\n 1 - Addiction\n 2 - Product\n 3 - Substraction\n 4 - Transpose");
	scanf("%d", &operation);
	
	if(operation==0)
	{
		return 0;
	}

	printf("X Dimension: ");
	scanf("%d", &dim_x);
	printf("Y Dimension: ");
	scanf("%d", &dim_y);

	int** matrix_1 = matrix_make(dim_x, dim_y);    

	if(operation<4)
	{
		int** matrix_2 = matrix_make(dim_x, dim_y);
		int** calculated_matrix = matrix_algebra(matrix_1, matrix_2, dim_x, dim_y, operation);
		matrix_print(calculated_matrix, dim_x, dim_y);
	}
	else if(operation==4)
	{
		int** transposed_matrix = matrix_transpose(matrix_1, dim_x, dim_y);
		matrix_print(transposed_matrix, dim_y, dim_x);
	}
	
	return 0;
}
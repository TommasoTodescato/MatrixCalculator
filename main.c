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
	int dim_x;
	int dim_y;
	int operation;
	
	printf("Operation\n 0 - Addiction\n 1 - Product\n 2 - Substraction\n 3 - Transpose\n");
	scanf("%d", &operation);
	
	printf("X Dimension: ");
	scanf("%d", &dim_x);
	printf("Y Dimension: ");
	scanf("%d", &dim_y);

	int** matrix_1 = matrix_make(dim_x, dim_y);    
	
	if(operation<3)
	{
		int** matrix_2 = matrix_make(dim_x, dim_y);
		int** calculated_matrix = matrixes_algebra(matrix_1, matrix_2, dim_x, dim_y, operation);
		matrix_print(calculated_matrix, dim_x, dim_y);
	}
	else if(operation==3)
	{
		int** transposed_matrix = matrix_transpose(matrix_1, dim_x, dim_y);
		matrix_print(transposed_matrix, dim_y, dim_x);
	}
	else if(operation==4)
	{
		int** matrix_2 = matrix_make(dim_x, dim_y);
		int** matrixes_augmentation(matrix_1, matrix_2, dim_x, dim_y);
		
	}
		
	return 0;
}
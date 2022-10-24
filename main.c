#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "iomatrix.h"

int dim_x;
int dim_y;
int operation;

int main()
{
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
		int** output_matrix = matrixes_operation(matrix_1, matrix_2, dim_x, dim_y, operation);
		
		matrix_print(output_matrix, dim_x, dim_y);
	}else{
		int** prova = matrix_transpose(matrix_1, dim_x, dim_y);
		matrix_print(prova, dim_y, dim_x);
	}
		
	return 0;
}
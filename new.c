#include <stdio.h>
#include <stdlib.h>

int dim_x;
int dim_y;
int operation;

void moveright(int deltaX)
{
    printf("\033[%dC",deltaX);
}
void moveup(int deltaY)
{
    printf("\033[%dA",deltaY);
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


int ** matrix_make(int x, int y)
{
	int ** big_array = malloc(x*y*sizeof(int*));
    int counter = 0;
    printf("\n");
    for(int i=0;i<y;++i)
	{
		int * mini_array = malloc(x*sizeof(int));
		printf("| ");

        for(int j=0;j<x;++j)
		{
			scanf("%d",&mini_array[j]);
            counter = counter + countdigits(mini_array[j]) - 1;
            moveup(1);
            moveright(j*2+4+counter);
		}
        counter = 0;
		big_array[i] = mini_array;
        
        printf("|\n");
    }

	return big_array;
}

int ** matrix_operation(int**m1,int**m2,int x,int y,int operation)
{
	int ** final_matrix = malloc(x*y*sizeof(int*));
    printf("\n");
    for(int i=0;i<y;++i)
	{
		printf("|");	
        int * mini_array = malloc(x*sizeof(int));

        for(int j=0;j<x;++j)
		{
            switch(operation)
            {
			case 0:
                mini_array[j] = m1[i][j]+m2[i][j];            
                break;

            case 1:
                mini_array[j] = m1[i][j]*m2[i][j];             
                break;

            case 2:
                mini_array[j] = m1[i][j]-m2[i][j]; 
                break;
            }
            if(j<x-1)
            {
                printf(" %d",mini_array[j]);
            }else{
                printf(" %d",mini_array[j]);
            }
		}
        final_matrix[i] = mini_array;
        printf(" |\n");
    } 

	return final_matrix;
}


int main()
{

    printf("X Dimension: ");
    scanf("%d",&dim_x);
    printf("Y Dimension: ");
    scanf("%d",&dim_y);

    printf("Operation\n 0 - Add\n 1 - Product\n 2 - Substraction\n");
    scanf("%d",&operation);
    int ** matrix_1 = matrix_make(dim_x,dim_y);    
    int ** matrix_2 = matrix_make(dim_x,dim_y);
	
    int ** matrix_summed = matrix_operation(matrix_1,matrix_2,dim_x,dim_y,operation);

    return 0;
}
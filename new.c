#include <stdio.h>
#include <stdlib.h>

// printf("\033[8;5Hhello");
int dim_x;
int dim_y;

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

//TODO: Putting all on git

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

int ** matrix_sum(int**m1,int**m2,int x, int y)
{
	int ** summed_matrix = malloc(x*y*sizeof(int*));
    printf("\n");
    for(int i=0;i<y;++i)
	{
		printf("|");	
        int * mini_array = malloc(x*sizeof(int));

        for(int j=0;j<x;++j)
		{
			mini_array[j] = m1[i][j]+m2[i][j];
            
            if(j<x-1)
            {
                printf(" %d",mini_array[j]);
            }else{
                printf(" %d",mini_array[j]);
            }
		}
        summed_matrix[i] = mini_array;
        printf(" |\n");
    } 

	return summed_matrix;
}



int main()
{

    printf("X Dimension: ");
    scanf("%d",&dim_x);
    printf("Y Dimension: ");
    scanf("%d",&dim_y);

    int ** matrix_1 = matrix_make(dim_x,dim_y);    
    int ** matrix_2 = matrix_make(dim_x,dim_y);
	
    int ** matrix_summed = matrix_sum(matrix_1,matrix_2,dim_x,dim_y);

    return 0;
}
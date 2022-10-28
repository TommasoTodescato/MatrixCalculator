#ifndef IOMATRIX_H
#define IOMATRIX_H

int** matrix_make(int x, int y);
void matrix_print(int** mtx, int x, int y);

typedef struct Matrix
{
	unsigned short int x;
	unsigned short int y;
	int** mtx;
} matrix;


#endif
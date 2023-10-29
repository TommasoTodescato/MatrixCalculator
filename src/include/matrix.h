#ifndef MATRIX
#define MATRIX

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct matrix
{
	unsigned int x;
	unsigned int y;
	int **arr;
} matrix;

enum operations
{
	QUIT,
	SUM,
	DIF,
	MUL,
	DIV,
	TRANSP
};

matrix m_allocate(unsigned int x, unsigned int y, bool empty);
void m_free(matrix m);

void m_input(matrix m);
void m_print(matrix m);

matrix m_algebra(matrix m1, matrix m2, unsigned int operation);
matrix m_sum(matrix m1, matrix m2);
matrix m_dif(matrix m1, matrix m2);
matrix m_mul(matrix m1, matrix m2);
matrix m_div(matrix m1, matrix m2);
matrix m_transpose(matrix m);

#endif
#include <matrix.h>

// To implement:
//  error handling
//	matrix inversion
//	input more than 2 matrices
//	matrix augmentation
//	elementary row operations
//	matrix dot product
//	https://ee263.stanford.edu/archive/matrix-primer-lect2.pdf

int main()
{
	int rows;
	int cols;
	int operation;

	printf(
		"Operations\n"
		"0 - Quit\n"
		"1 - Addiction\n"
		"2 - Substraction\n"
		"3 - Product\n"
		"4 - Division\n"
		"5 - Transpose\n");

	scanf("%d", &operation);

	if (operation == QUIT) return 0;

	printf("Number of rows (Y): ");
	scanf("%d", &rows);
	printf("Number of columns (X): ");
	scanf("%d", &cols);

	matrix m1 = m_allocate(cols, rows, true);
	matrix m2 = m_allocate(cols, rows, true);
	matrix result = {.arr = NULL, .x = cols, .y = rows};

	m_input(m1);

	switch (operation)
	{
	case SUM:
		printf("+\n");
		m_input(m2);
		result = m_sum(m1, m2);
		break;

	case DIF:
		printf("-\n");
		m_input(m2);
		result = m_dif(m1, m2);
		break;

	case MUL:
		printf("*\n");
		m_input(m2);
		result = m_mul(m1, m2);
		break;

	case DIV:
		printf("/\n");
		m_input(m2);
		result = m_div(m1, m2);
		break;

	case TRANSP:
		result = m_transpose(m1);
		break;
	}
	printf("=\n");
	m_print(result);

	m_free(m1);
	m_free(m2);
	m_free(result);

	return 0;
}
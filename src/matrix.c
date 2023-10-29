#include <matrix.h>

matrix m_allocate(unsigned int x, unsigned int y, bool empty)
{
	int **arr = malloc(y * sizeof(int *));
	for (int r = 0; r < y; ++r)
	{
		int *v;
		if (empty)
			v = calloc(x, sizeof(int));
		else
			v = malloc(x * sizeof(int));

		arr[r] = v;
	}

	matrix m = {.arr = arr, .x = x, .y = y};
	return m;
}

void m_free(matrix m)
{
	if (m.arr == NULL)
		return;
		
	for (int r = 0; r < m.y; ++r)
		free(m.arr[r]);
	free(m.arr);
}
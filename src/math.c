#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>

matrix m_sum(matrix m1, matrix m2)
{
	return m_algebra(m1, m2, SUM);
}

matrix m_dif(matrix m1, matrix m2)
{
	return m_algebra(m1, m2, DIF);
}

matrix m_mul(matrix m1, matrix m2)
{
	return m_algebra(m1, m2, MUL);
}

matrix m_div(matrix m1, matrix m2)
{
	return m_algebra(m1, m2, DIV);
}

matrix m_algebra(matrix m1, matrix m2, unsigned int operation)
{
	matrix result = m_allocate(m1.x, m1.y, false);

	if (m1.x != m2.x || m1.y != m2.y)
	{
		printf("[ERR] Input matrices have different sizes\n"
			   "Returning first operand");
		m_free(result);
		return m1;
	}

	for (int r = 0; r < m1.y; ++r)
	{
		for (int c = 0; c < m1.x; ++c)
		{
			switch (operation)
			{
			case SUM:
				result.arr[r][c] = m1.arr[r][c] + m2.arr[r][c];
				break;
			case DIF:
				result.arr[r][c] = m1.arr[r][c] - m2.arr[r][c];
				break;
			case MUL:
				result.arr[r][c] = m1.arr[r][c] * m2.arr[r][c];
				break;
			case DIV:
				result.arr[r][c] = m1.arr[r][c] / m2.arr[r][c];
				break;
			}
		}
	}

	return result;
}

matrix m_transpose(matrix m)
{
	matrix result = m_allocate(m.y, m.x, false);
	for (int r = 0; r < m.x; ++r)
		for (int c = 0; c < m.y; ++c)
			result.arr[r][c] = m.arr[c][r];

	return result;
}
#include <stdlib.h>
#include <stdio.h>
#include <matrix.h>

void move_right(int deltaX) { printf("\033[%dC", deltaX); }
void move_up(int deltaY) { printf("\033[%dA", deltaY); }

int count_digits(int num)
{
	int count = 0;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}

	return count;
}

void m_input(matrix m)
{
	for (int r = 0; r < m.y; ++r)
	{
		int digits = 0;
		printf("| ");

		for (int c = 0; c < m.x; ++c)
		{
			scanf("%d", &m.arr[r][c]);
			digits += count_digits(m.arr[r][c]) - 1;

			move_up(1);
			move_right(c * 2 + 4 + digits);
		}

		printf("|\n");
	}
}

void m_print(matrix m)
{
	for (int r = 0; r < m.y; ++r)
	{
		printf("|");
		
		for (int c = 0; c < m.x; ++c)
			printf(" %d", m.arr[r][c]);

		printf(" |\n");
	}
}
#ifndef IOMATRIX_H
#define IOMATRIX_H

int countdigits(int num);
void moveup(int deltaY);
void moveright(int deltaX);

int** matrix_make(int x, int y);
void matrix_print(int** m, int x, int y);


#endif
#ifndef OPERATIONS_H
#define OPERATIONS_H

int** matrixes_algebra(int** m1, int** m2, int x, int y, int operation);
int** matrix_transpose(int** m, int x, int y);
int** matrixes_augmentation(int** base_matrix, int** matrix_to_add, int base_x, int base_y);

#endif
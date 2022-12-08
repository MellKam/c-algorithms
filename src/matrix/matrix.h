#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
	int rows;
	int cols;
	float **matrix;
} Matrix;

Matrix *new_matrix(int rows, int cols);
Matrix *input_new_matrix();
void print_matrix(Matrix *matrix);
Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2);

#endif
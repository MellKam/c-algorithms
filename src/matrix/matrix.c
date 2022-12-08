#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
	int rows;
	int cols;
	float **matrix;
} Matrix;

Matrix *new_matrix(int rows, int cols)
{
	float **arr = malloc(sizeof(float) * cols);
	for (int r = 0; r < rows; r++)
	{
		arr[r] = malloc(sizeof(float) * rows);
	}

	Matrix *matrix = malloc(sizeof(Matrix));

	matrix->matrix = arr;
	matrix->cols = cols;
	matrix->rows = rows;

	return matrix;
}

Matrix *input_new_matrix()
{
	int rows, cols;

	printf("Input matrix rows count: ");
	scanf("%d", &rows);

	printf("Input matrix cols count: ");
	scanf("%d", &cols);

	Matrix *matrix = new_matrix(rows, cols);

	for (int r = 0; r < matrix->rows; r++)
	{
		for (int c = 0; c < matrix->cols; c++)
		{
			printf("Enter matrix[%d][%d]: ", r, c);
			scanf("%f", &(matrix->matrix[r][c]));
		}
	}

	return matrix;
}

void print_matrix(Matrix *matrix)
{
	for (int r = 0; r < matrix->rows; r++)
	{
		printf("[ ");
		for (int c = 0; c < matrix->cols; c++)
		{
			printf("%.2f ", matrix->matrix[r][c]);
		}
		printf("]\n");
	}
}

Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2)
{
	if (matrix1->cols != matrix2->rows)
	{
		printf("You cannot multiply this matricies");
		return 0;
	}

	Matrix *result = new_matrix(matrix1->rows, matrix2->cols);

	for (int r1 = 0; r1 < matrix1->rows; r1++)
	{
		for (int c2 = 0; c2 < matrix2->cols; c2++)
		{
			float sum = 0;

			for (int i = 0; i < matrix1->cols; i++)
			{
				sum += matrix1->matrix[r1][i] * matrix2->matrix[i][c2];
			}

			result->matrix[r1][c2] = sum;
		}
	}

	return result;
}
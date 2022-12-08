#include "./matrix/matrix.h"
#include <stdio.h>

void main()
{
	printf("Input first matrix.\n");
	Matrix *m1 = input_new_matrix();
	printf("Input second matrix.\n");
	Matrix *m2 = input_new_matrix();

	Matrix *result = multiply_matrices(m1, m2);

	if (result)
	{
		printf("Result matrix: \n");
		print_matrix(result);

		free(result);
	}

	free(m1);
	free(m2);
}

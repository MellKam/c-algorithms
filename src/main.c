#include "./matrix/matrix.h"

void main()
{
	printf("Input first matrix: ");
	Matrix *m1 = input_new_matrix();
	printf("Input second matrix: ");
	Matrix *m2 = input_new_matrix();

	Matrix *result = multiply_matrices(m1, m2);

	printf("Result matrix: \n");
	print_matrix(result);

	free(m1);
	free(m2);
	free(result);
}

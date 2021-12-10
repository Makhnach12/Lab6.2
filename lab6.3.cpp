#include <iostream>
#include <windows.h>
#include <string>
#include "matrix_operations.h"
#include "checking_operations.h"
using namespace std;

int main()
{
	//размер матрицы
	int matrix_size;
	setlocale(0, "RUS");
	cout << "¬ведите размеры матриц" << endl;
	correct_input_matrix_dimension(matrix_size);
	double** matrix_1 = input_matrix(matrix_size, matrix_size);
	double** matrix_2 = input_matrix(matrix_size, matrix_size);
	matrix_minus_free_number(matrix_1, 4, matrix_size);
	double** minors_determinant = minor_determinant_counter(matrix_1, matrix_size);
	double** matrix_reverse = create_reverse_matrix(matrix_1, matrix_size, minors_determinant);
	double** matrix_answer = matrix_multiply(matrix_reverse, matrix_2, matrix_size);
	cout_matrix(matrix_answer, matrix_size);
	cleaning_matrix(matrix_size, matrix_1);
	cleaning_matrix(matrix_size, matrix_2);
	cleaning_matrix(matrix_size, minors_determinant);
	cleaning_matrix(matrix_size, matrix_reverse);
	cleaning_matrix(matrix_size, matrix_answer);
	system("pause");
	return 0;
}
#include <iostream>
// #include <windows.h>
#include <string>
#include "matrix_operations.hpp"
#include "checking_operations.hpp"
using namespace std;

int main()
{
	//размер матрицы
	int matrix_size;
	// setlocale(0, "RUS");
	cout << "Введите размеры матриц" << endl;
	correct_input_matrix_dimension(matrix_size);
	double** matrix_1 = input_matrix(matrix_size, matrix_size);
	double** matrix_2 = input_matrix(matrix_size, matrix_size);
	//4 - свободный член
    matrix_minus_free_number(matrix_1, 4, matrix_size);
    matrix_multiply_namber(matrix_1, matrix_size, -1);
	double** minors_determinant = minor_determinant_counter(matrix_1, matrix_size); 
	if (determinant_counter(matrix_size, matrix_1) != 0)
	{
		double** matrix_reverse = create_reverse_matrix(matrix_1, matrix_size, minors_determinant);
		double** matrix_answer = matrix_multiply(matrix_reverse, matrix_2, matrix_size);
		cout_matrix(matrix_answer, matrix_size);
		cleaning_matrix(matrix_size, matrix_1);
		cleaning_matrix(matrix_size, matrix_2);
		cleaning_matrix(matrix_size, minors_determinant);
		cleaning_matrix(matrix_size, matrix_reverse);
		cleaning_matrix(matrix_size, matrix_answer);
	}
	else
		cout << "Нет решений" << endl;
	return 0;
}
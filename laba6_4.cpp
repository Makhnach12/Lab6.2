#include <cstdio>
#include "matrix_operations.hpp"
#include "checking_operations.hpp"

int main() {
	int matrix_size = 0;
	printf("Введите размер квадратной матрицы А и В\nОни должны быть одного размера,"
		   " иначе не возможно выполнение программы: ");
	correct_input_matrix_dimension(matrix_size);
	double** matrixA = input_matrix(matrix_size, matrix_size);
	double** matrixB = input_matrix(matrix_size, matrix_size);
	double** matrix_temp = matrix_multiply(matrixA, matrixB, matrix_size);
	matrix_plus_free_number(matrixA, 3, matrix_size);
	printf("Вычисление матрицы A': \n");
	double** matrixA2 = difference_of_functions_f_and_g(matrix_size, matrixA);
	printf("\nВычисление матрицы B': \n");
	double** matrixB2 = difference_of_functions_f_and_g(matrix_size, matrix_temp);

	// Раскоментировать для тестирования второго блока.
	/*
		cleaning_matrix(matrix_size, matrixA2);
		matrixA2 = input_matrix(matrix_size, matrix_size);
	*/
	int ordinal_num_in_line_1, ordinal_num_in_line_2, rank = 1;
	double** matrix_minor = create_matrix(matrix_size, matrix_size);
	first_minor_counter(matrix_size, matrix_size, matrixA2, matrix_minor, ordinal_num_in_line_1, \
		                ordinal_num_in_line_2, rank);
	if (rank != 1)
	    rank = minor_counter_for_rank(matrix_size, matrix_size, ordinal_num_in_line_1, \
	    	                          ordinal_num_in_line_2, matrix_minor, matrixA2);
	printf("\nРанг матрицы A' равен: %d\n\n", rank);

	// Раскоментировать для тестирования третьего блока.
	
		cleaning_matrix(matrix_size, matrixA2);
		cleaning_matrix(matrix_size, matrixB2);
		matrixA2 = input_matrix(matrix_size, matrix_size);
		matrixB2 = input_matrix(matrix_size, matrix_size);
	
	double** answer = create_matrix(matrix_size, matrix_size);
	printf("Решние матричного уравнения 4*X - A'*X = B'\n");
	bool is_answer = equation_solution(matrixA2, matrixB2, matrix_size, answer);
	if (is_answer) cout_matrix(answer, matrix_size);
	else printf("Решений нет\n");

	cleaning_matrix(matrix_size, answer);
	cleaning_matrix(matrix_size, matrix_temp);
	cleaning_matrix(matrix_size, matrix_minor);
	cleaning_matrix(matrix_size, matrixA);
	cleaning_matrix(matrix_size, matrixB);
	cleaning_matrix(matrix_size, matrixA2);
	cleaning_matrix(matrix_size, matrixB2);
	return 0;
}
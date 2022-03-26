#include <iostream>
#include <string>
#include <math.h>
#include "matrix_operations.hpp"
#include "checking_operations.hpp"

//функция для создания матрицы
double** create_matrix(int str_count, int column_count)
{
	double** matrix = new double*[str_count];
	for (int i = 0; i < str_count; i++)
		matrix[i] = new double[column_count];
	return matrix;
}

//функция для ввода квадратной матрицы A
double** input_square_matrix(int str_count)
{
	double** matrix = create_matrix(str_count, str_count);
	for (int i1 = 0; i1 < str_count; i1++)
		for (int i2 = 0; i2 < str_count; i2++)
		{
			printf("A[%d][%d]=", i1, i2);
			correct_input_matrix_members(matrix[i1][i2]);
		}
	return matrix;
}

//функция для ввода данных матрицы А
double** input_matrix(int str_count, int column_count)
{
	double** matrix = create_matrix(str_count, column_count);
	for (int i1 = 0; i1 < str_count; i1++)
		for (int i2 = 0; i2 < column_count; i2++)
		{
			printf("A[%d][%d]=", i1, i2);
			correct_input_matrix_members(matrix[i1][i2]);
		}
	return matrix;
}

//функция произведения матриц
double** matrix_multiply(double** matrix1, double** matrix2, int str_count)
{
	double sum = 0;
	double** increase_of_matrixes = create_matrix(str_count, str_count);
	for (int i1 = 0; i1 < str_count; i1++)
	{
		for (int i2 = 0; i2 < str_count; i2++)
		{
			sum = 0;
			for (int i3 = 0; i3 < str_count; i3++)
				sum += matrix2[i1][i3] * matrix1[i3][i2];
			increase_of_matrixes[i1][i2] = sum;
		}
	}
	return increase_of_matrixes;
}

//функция суммирования матриц
double** sum_of_matrixes(double** matrix1, double** matrix2, int str_count)
{
	double** sum_of_matrixes = create_matrix(str_count, str_count);
	for (int i1 = 0; i1 < str_count; i1++)
		for (int i2 = 0; i2 < str_count; i2++)
			sum_of_matrixes[i1][i2] = matrix1[i1][i2] + matrix2[i1][i2];
	return sum_of_matrixes;
}

//функция расчета разности матриц
double** difference_of_matrixes(double** matrix1, double** matrix2, int str_count)
{
	double** dif_of_matrix = create_matrix(str_count, str_count);
	for (int i1 = 0; i1 < str_count; i1++)
		for (int i2 = 0; i2 < str_count; i2++)
			dif_of_matrix[i1][i2] = matrix1[i1][i2] - matrix2[i1][i2];
	return dif_of_matrix;
}

// Функция копирует матрицу matrix_src в матрицу matrix_dst (размеры матриц должны совпадать).
void copy_matrix(double** matrix_dst, double** matrix_src, int str_count, int column_count) 
{
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++)
			matrix_dst[i][j] = matrix_src[i][j];
}

//функция суммирования матрицы и свободного числа 
void matrix_plus_free_number(double** matrix, int num, int str_count)
{
	for (int i1 = 0; i1 < str_count; i1++)
		matrix[i1][i1] = matrix[i1][i1] + num;
}

//функция нахождения разницы матрицы и свободного числа 
void matrix_minus_free_number(double** matrix, int num, int str_count)
{
	for (int i1 = 0; i1 < str_count; i1++)
		matrix[i1][i1] = matrix[i1][i1] - num;
}

// Функция умножает квадратную матрицу на число.
void matrix_multiply_namber(double** matrix, int matrix_size, int number)
{
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++)
			matrix[i][j] *= number;
	return;
}

//функция очистки двумерных массивов
void cleaning_matrix(int str_count, double** matrix)
{
	for (int i = 0; i < str_count; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = 0;
}

//функция вывода матрицы на экран
void cout_matrix(double** matrix, int str_count)
{
	for (int i1 = 0; i1 < str_count; i1++)
	{
		for (int i2 = 0; i2 < str_count; i2++)
			printf(" %.9f ", matrix[i1][i2]);
		printf("\n");
    }
}

//функция вывода для функции f
void output_of_function_f(double** matrix, int str_count, double*** matrix_sum_of_f)
{
	double** matrix_2nd_degree = matrix_multiply(matrix, matrix, str_count);
	double** matrix_4th_degree = matrix_multiply(matrix_2nd_degree, matrix_2nd_degree, str_count);
	printf("A^4:\n");
	cout_matrix(matrix_4th_degree, str_count);
	printf("A^2:\n");
	cout_matrix(matrix_2nd_degree, str_count);
	*matrix_sum_of_f = sum_of_matrixes(matrix_4th_degree, matrix_2nd_degree, str_count);
	matrix_plus_free_number(*matrix_sum_of_f, 1, str_count);
	printf("A^4+A^2+1=\n");
	cout_matrix(*matrix_sum_of_f, str_count);
	cleaning_matrix(str_count, matrix_2nd_degree);
	cleaning_matrix(str_count, matrix_4th_degree);
}

//функции вывода для функции g
void output_of_function_g(double** matrix, int str_count, double*** matrix_sum_of_g)
{
	double** matrix_3rd_degree = matrix_multiply(matrix, matrix, str_count);
	matrix_3rd_degree = matrix_multiply(matrix_3rd_degree, matrix, str_count);
	printf("A^3:\n");
	cout_matrix(matrix_3rd_degree, str_count);
	printf("A:\n");
	cout_matrix(matrix, str_count);
	*matrix_sum_of_g = sum_of_matrixes(matrix_3rd_degree, matrix, str_count);
	printf("A^3+A=\n");
	cout_matrix(*matrix_sum_of_g, str_count);
	cleaning_matrix(str_count, matrix_3rd_degree);
}

//функция расчета разности между функциями f и g
double** difference_of_functions_f_and_g(int matrix_size, double** matrix)
{
	double** matrix_sum_of_f = new double*[matrix_size];
	double** matrix_sum_of_g = new double*[matrix_size];
	output_of_function_f(matrix, matrix_size, &matrix_sum_of_f);
	output_of_function_g(matrix, matrix_size, &matrix_sum_of_g);
	cout_matrix(matrix_sum_of_f, matrix_size);
	double** matrix_dif_of_f_and_g = difference_of_matrixes(matrix_sum_of_f, matrix_sum_of_g, matrix_size);
	printf("f(A)-g(A)=\n");
	cout_matrix(matrix_dif_of_f_and_g, matrix_size);
	cleaning_matrix(matrix_size, matrix_sum_of_f);
	cleaning_matrix(matrix_size, matrix_sum_of_g);
	return matrix_dif_of_f_and_g;
}

// Получение матрицы без i-й строки и 0-го столбца
void get_new_smaller_matrix(double** matrix, double** new_small_matrix, int i, int j, int matrix_size) {
	int new_i, new_j, flag_i, flag_j;
	flag_i = 0;
	for (new_i = 0; new_i < matrix_size - 1; new_i++) { 
		// проверка индекса строки
		if (new_i == i) flag_i = 1;
		flag_j = 0;
		for (new_j = 0; new_j < matrix_size - 1; new_j++) { 
			// проверка индекса столбца
			if (new_j == j) flag_j = 1;
			new_small_matrix[new_i][new_j] = matrix[new_i + flag_i][new_j + flag_j];
		}
	}
}

//Рекурсивное вычисление определителя
int determinant_counter(int matrix_size, double** matrix) {
	int determinant = 0, dimension_of_new_matrix;
	double** new_smaller_matrix;
	new_smaller_matrix = create_matrix(matrix_size, matrix_size);
	dimension_of_new_matrix = matrix_size - 1;
	if (matrix_size == 1) {
		determinant = matrix[0][0];
		return(determinant);
	}
	if (matrix_size == 2) {
		determinant = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
		return(determinant);
	}
	if (matrix_size > 2) {
		for (int i = 0; i < matrix_size; i++) {
			get_new_smaller_matrix(matrix, new_smaller_matrix, i, 0, matrix_size);
 			determinant = determinant + pow(-1,i) * matrix[i][0] * determinant_counter(dimension_of_new_matrix, new_smaller_matrix);
		}
	}
	cleaning_matrix(dimension_of_new_matrix, new_smaller_matrix);
	return determinant;
}

//функция меняющая выбранные строки местами в матрице
void change_matrix(double** matrix_oroginal, int demеntion_of_matrix,  int st, int num)
{
	double member = 0;
	for (int i = 0; i < demеntion_of_matrix; i++)
	{
		member = matrix_oroginal[st][i];
		matrix_oroginal[st][i] = matrix_oroginal[num][i];
		matrix_oroginal[num][i] = member;
	}
}

//функция высчитывающая первый минор в матрице
double** first_minor_counter(int length_of_matrix, int high_of_matrix, double** matrix_oroginal, double** matrix_minor, int& ordinal_num_in_line_1, int& ordinal_num_in_line_2, int& rank)
{
	ordinal_num_in_line_1 = 0;
	//пока мы не дошли до последней строки
	while (ordinal_num_in_line_1 != high_of_matrix)
	{
		for (ordinal_num_in_line_2 = ordinal_num_in_line_1 + 1; ordinal_num_in_line_2 < high_of_matrix; ordinal_num_in_line_2++)
			for (int i = 0; i < length_of_matrix; i++)
				for (int j = 0; j < length_of_matrix; j++)
					if (i != j)
					{
						//присвоение квадратной матрице подобранных значений 
						matrix_minor[0][0] = matrix_oroginal[ordinal_num_in_line_1][i];
						matrix_minor[0][1] = matrix_oroginal[ordinal_num_in_line_1][j];
						matrix_minor[1][0] = matrix_oroginal[ordinal_num_in_line_2][i];
						matrix_minor[1][1] = matrix_oroginal[ordinal_num_in_line_2][j];
						if (determinant_counter(2, matrix_minor) != 0)
						{
							rank = 2;
							ordinal_num_in_line_1 = i;
							ordinal_num_in_line_2 = j;
							//меняю строки местами чтоб дальше поиск миноров был корректным
							change_matrix(matrix_oroginal, high_of_matrix, ordinal_num_in_line_1, 0);
							change_matrix(matrix_oroginal, high_of_matrix, ordinal_num_in_line_2, 1);
							return matrix_minor;
						}
					}
		ordinal_num_in_line_1++;
	}
	return 0;
}

//функция высчитывающая миноры 3-го и других порядков
int minor_counter_for_rank(int length_of_matrix, int high_of_matrix, int ordinal_num_in_line_1, int ordinal_num_in_line_2, double** matrix_minor, double** matrix_original)
{
	int rank = 2, element_in_line = 0, flag = 0, matrix_size = 3, num=0;
	int* first_line_elements = new int[length_of_matrix];
	first_line_elements[ordinal_num_in_line_1] = 1;
	first_line_elements[ordinal_num_in_line_2] = 1;
	for (int i = 0; i < length_of_matrix; i++)
		if (first_line_elements[i] != 1)
		first_line_elements[i] = 0;
	int count_of_steps = 1;
	if (length_of_matrix == high_of_matrix)
		num = high_of_matrix;
	else 
		num = high_of_matrix - 1;
	//пока не дойдем до последней строчки матрицы
	while (count_of_steps != num)
	{
		//идем по первой строке
		for (int i = 0; i < length_of_matrix; i++)
			if (first_line_elements[i] != 1)
			{
				//заполняем еще один столбец до высоты предыдущего минора
				for (int j = 0; j < matrix_size - 1; j++)
					matrix_minor[j][matrix_size - 1] = matrix_original[j][i];
				//идем по строкам и заполняем строку нового минора
				for (int i2 = matrix_size - 1; i2 < high_of_matrix; i2++)
				{
					//в этом цикле заполняем строку нвого минора до самого последнего значеения справа снизу
					for (int i3 = 0; i3 < length_of_matrix; i3++)
						if (first_line_elements[i3] == 1)
						{
							matrix_minor[matrix_size - 1][element_in_line] = matrix_original[i2][i3];
							element_in_line++;
						}
					//заполняем значение последнего значения(самого правого и самого нижнего) матрицы минора 
					matrix_minor[matrix_size - 1][matrix_size - 1] = matrix_original[i2][i];
					element_in_line = 0;
					if (determinant_counter(matrix_size, matrix_minor) != 0)
					{
						rank++;
						change_matrix(matrix_original, high_of_matrix, i2, matrix_size - 1);
						first_line_elements[i] = 1;
						flag = 1;
						break;
					}
				}
				if (determinant_counter(matrix_size, matrix_minor) != 0)
					break;
			}
		count_of_steps++;
		matrix_size++;
		if (flag == 0)
		{
			delete[]first_line_elements;
			return rank;
		}
		flag = 0;
	}
	delete[]first_line_elements;
	return rank;
}

//функция для подсчета определителей миноров 
double** minor_determinant_counter(double** main_matrix, int matrix_size)
{
	double** minors_determinant = create_matrix(matrix_size, matrix_size);
	double** new_smaller_matrix = create_matrix(matrix_size - 1, matrix_size - 1);
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			get_new_smaller_matrix(main_matrix, new_smaller_matrix, i, j, matrix_size);
			minors_determinant[i][j] = determinant_counter(matrix_size - 1, new_smaller_matrix);
		}
	}
	return minors_determinant;
}

//функция для создания обратной матрицы
double** create_reverse_matrix(double** main_matrix, int matrix_size, double** minors_determinant)
{
	double determinant_of_main_matr = determinant_counter(matrix_size, main_matrix);
	double** reverse_matrix = create_matrix(matrix_size, matrix_size);
	if (matrix_size == 1)
	{
		reverse_matrix[0][0] = 1.0 / determinant_of_main_matr;
		return reverse_matrix;
	}
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++) 
			reverse_matrix[i][j] =  (pow(-1, i + j) * minors_determinant[j][i])/ determinant_of_main_matr;
	// cout_matrix(reverse_matrix, matrix_size);
	return reverse_matrix;
}

// Функция решает матричное уравнения 4*X - A*X = B
bool equation_solution(double** matrixA, double** matrixB, int matrix_size, double** answer)
{
    matrix_minus_free_number(matrixA, 4, matrix_size);
    matrix_multiply_namber(matrixA, matrix_size, -1);
	double** minors_determinant = minor_determinant_counter(matrixA, matrix_size);
	double det_matrix = determinant_counter(matrix_size, matrixA);
	if (det_matrix == 0) {
		return false;
	}
	double** matrix_reverse = create_reverse_matrix(matrixA, matrix_size, minors_determinant);
	double** matrix_temp = matrix_multiply(matrix_reverse, matrixB, matrix_size);
	copy_matrix(answer, matrix_temp, matrix_size, matrix_size);
	cleaning_matrix(matrix_size, minors_determinant);
	cleaning_matrix(matrix_size, matrix_reverse);
	cleaning_matrix(matrix_size, matrix_temp);
	return true;
}

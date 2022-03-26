#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

//функция для создания матрицы
double** create_matrix(int str_count, int column_count);

//функция для ввода матрицы A
double** input_square_matrix(int str_count);

//функция для создания матрицы n*m
double** input_matrix(int str_count, int column_count);

//функция возведения матрицы в квадрат
double** matrix_multiply(double** matrix1, double** matrix2, int str_count);

//функция суммирования матриц
double** sum_of_matrixes(double** matrix1, double** matrix2, int str_count);

//функция суммирования матрицы и свободного числа 
void matrix_plus_free_number(double** matrix, int num, int str_count);

//функция нахождения разницы матрицы и свободного числа 
void matrix_minus_free_number(double** matrix, int num, int str_count);

// Функция умножает квадратную матрицу на число.
void matrix_multiply_namber(double** matrix, int matrix_size, int number);

//функция расчета разности матриц   
double** difference_of_matrixes(double** matrix1, double** matrix2, int str_count);

//функция очистки двумерных массивов
void cleaning_matrix(int str_count, double** matrix);

//функция вывода матрицы на экран
void cout_matrix(double** matrix, int str_count);

//функция вывода для функции f
void output_of_function_f(double** matrix, int str_count);

//функция вывода для функции g
void output_of_function_g(double*** matrix, int str_count);

//функция вывода разности функций f и g
double** difference_of_functions_f_and_g(int str_count, double** matrix);

//функция для подсчета определителя
int determinant_counter(int matrix_size, double** matrix);

//функция для получения минора
void get_new_smaller_matrix(double** matrix, double** new_small_matrix, int i, int j, \
							int matrix_size);

//функция для поиска первого минора
double** first_minor_counter(int length_of_matrix, int high_of_matrix, double** matrix_oroginal, \
							 double** matrix_minor, int& min1, int& min2, int& rank);

//функция для поиска миноров 3-го порядка и более
int minor_counter_for_rank(int length_of_matrix, int high_of_matrix, int min1, int min2, \
						   double** matrix, double** matrix_original);

//функция создания обратной матрицы
double** create_reverse_matrix(double** main_matrix, int matrix_size, double** minors_determinant);

//функция для подсчета определителей миноров
double** minor_determinant_counter(double** main_matrix, int matrix_size);

// Функция решает матричное уравнения 4*X - A*X = B
bool equation_solution(double** matrixA, double** matrixB, int matrix_size, double** answer);
#endif //MATRIX_OPERATIONS_HPP

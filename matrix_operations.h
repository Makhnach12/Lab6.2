#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

//функция для создания матрицы
double** create_matrix(int n, int m);

//функция для ввода матрицы A
double** input_square_matrix(int n);

//функция для создания матрицы n*m
double** input_matrix(int n, int m);

//функция возведения матрицы в квадрат
double** matrix_multiply(double** matrix1, double** matrix2, int n);

//функция суммирования матриц
double** sum_of_matrixes(double** matrix1, double** matrix2, int n);

//функция суммирования матрицы и свободного числа 
double** matrix_plus_free_number(double** matrix, int num, int n);

//функция нахождения разницы матрицы и свободного числа 
double** matrix_minus_free_number(double** matrix, int num, int n);

//функция расчета разности матриц   
double** difference_of_matrixes(double** matrix1, double** matrix2, int n);

//функция очистки двумерных массивов
void cleaning_matrix(int n, double** matrix);

//функция вывода матрицы на экран
void cout_matrix(double** matrix, int n);

//функция вывода для функции f
void output_of_function_f(double** matrix, int n, double** matrix_sum_of_f);

//функция вывода для функции g
void output_of_function_g(double** matrix, int n, double** matrix_sum_of_g);

//функция вывода разности функций f и g
void difference_of_functions_f_and_g(int n, double** matrix);

//функция для подсчета определителя
int determinant_counter(int m, double** mas);

//функция для получения минора
void get_new_smaller_matrix(double** mas, double** p, int i, int j, int m);

//функция для поиска первого минора
double** first_minor_counter(int length_of_matrix, int high_of_matrix, double** matrix_oroginal, double** matrix_minor, int& min1, int& min2, int& rank);

//функция для поиска миноров 3-го порядка и более
int minor_counter_for_rank(int length_of_matrix, int high_of_matrix, int min1, int min2, double** matrix, double** matrix_original);

//функция создания обратной матрицы
double** create_reverse_matrix(double** main_matrix, int matrix_size, double** minors_determinant);

//функция для подсчета определителей миноров
double** minor_determinant_counter(double** main_matrix, int matrix_size);
#endif //MATRIX_OPERATIONS

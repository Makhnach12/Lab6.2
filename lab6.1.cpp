//Лабораторная работа 6.1.18 
//Необходимо найти разность функций f и g
/*
* f(x)=x^4+x^2+1 g(x)=x^3+x f(A)-g(A)
*/
#include <iostream>
// #include <windows.h>
#include <string>
#include "matrix_operations.hpp"
#include "checking_operations.hpp"
using namespace std;

int main()
{
	//размер матрицы
	int dimension_of_matrix;
	// setlocale(0, "RUS");
	cout << "Введите размер квадратной матрицы:" << endl;
	correct_input_matrix_dimension(dimension_of_matrix);
	double** matrix = input_matrix(dimension_of_matrix, dimension_of_matrix);
	difference_of_functions_f_and_g(dimension_of_matrix, matrix);
	cleaning_matrix(dimension_of_matrix, matrix);
	// system("pause");
	return 0;
}
/*
TEST
Введите размер квадратной матрицы:
3
A[0][0]=1
A[0][1]=0
A[0][2]=0
A[1][0]=1
A[1][1]=0
A[1][2]=0
A[2][0]=1
A[2][1]=0
A[2][2]=0
A^4:
1 0 0
1 0 0
1 0 0
A^2:
1 0 0
1 0 0
1 0 0
A^4+A^2+1=
3 0 0
2 1 0
2 0 1
A^3:
1 0 0
1 0 0
1 0 0
A:
1 0 0
1 0 0
1 0 0
A^3+A=
2 0 0
2 0 0
2 0 0
f(A)-g(A)=
1 0 0
0 1 0
0 0 1

Введите размер квадратной матрицы:
2
A[0][0]=1
A[0][1]=1
A[1][0]=1
A[1][1]=1
A^4:
8 8
8 8
A^2:
2 2
2 2
A^4+A^2+1=
11 10
10 11
A^3:
4 4
4 4
A:
1 1
1 1
A^3+A=
5 5
5 5
f(A)-g(A)=
6 5
5 6


*/

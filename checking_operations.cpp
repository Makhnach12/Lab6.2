//CPP файл для функций проверающих введенные значения
#include "checking_operations.hpp"
#include <iostream>	
using namespace std;

//функция проверки введенного размера матрицы
void correct_input_matrix_dimension(int& member)
{
	cin >> member;
	while (cin.fail() || member <= 0)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Вы ввели невозможное значение!\n";
		cin >> member;
	}
}

//функция проверки введенных значений матрицы
void correct_input_matrix_members(double& member) {
	cin >> member;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Вы ввели невозможное значение!\n";
		cin >> member;
	}
}

//функция проверки корректности ввода выосты для матрицы(для метода окаймляющих миноров)
void correct_input_matrix_high(int len, int& member)
{
	cin >> member;
	while (cin.fail() || member <= 0 || len < member)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Вы ввели невозможное значение!\n";
		cin >> member;
	}
}
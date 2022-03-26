#ifndef CHECKING_OPERATIONS_H
#define CHECKING_OPERATIONS_H

//функция проверки введенного размера матрицы
void correct_input_matrix_dimension(int& num);

//функция проверки введенных значений матрицы
void correct_input_matrix_members(double& num);

//функция проверки высоты матрицы для метода окаймляющих миноров
void correct_input_matrix_high(int len, int& member);

#endif//CHEKING_OPERATIONS


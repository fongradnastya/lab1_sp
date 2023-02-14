/*! Запускает дочерний поток программы */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*!
Считывает строку произвольной длины из коноли
\param[out] len полученная длина строки
\return считанная из консоли строка
*/
char* GetString(int *len);

/*!
Вывод матрицы в консоль
\param[in] matrix матрица для вывода
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void PrintMatrix(int** matrix, int size_x, int size_y);

/*!
Вычисляет суммы модулей элементов для каждой строки
\param[in] matrix исходная матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
\param[out] sum вычисленные суммы модулей
*/
void CountModuleSum(int** matrix, int size_x, int size_y, int* sum);

/*!
Вычисляет последовательность индексов строк, 
располагающую строки в порядке убывания
\param[in] array массив сумм элементов строк
\param[in] length длина исходного массива
\param[out] ids вычисленный массив индексов 
*/
void FindMaxId(int* array, int length, int* ids);

/*!
Заполняет строки новой матрицы в порядке 
убывания суммы модулей их элементов
\param[in] matrix исходная матрица
\param[out] new_matrix новая матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void CreateNewMatrix(int** matrix, int** new_matrix, int size_x, int size_y);

/*!
Считывает из консоли значения элементов матрицы
\param[out] matrix матрица считанных значений
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
\return корректно ли прошло считывание
*/
int InputMatrix(int** matrix, int size_x, int size_y){
    printf("Please enter a %d:%d matrix\n", size_x, size_y);
    for(int i = 0; i < size_x; i++){
        printf("%d string: ", i + 1);
        int num;
        for(int j = 0; j < size_y; j++){
            int res = scanf("%d", &num);
            if(res == 1){
                matrix[i][j] = num;
            }
            else return 0;
        }
    }
    return 1;
}

/*!
Считывает из консоли одно целое число
\param[out] val считанное значение
\return код корректности считывания
*/
int InputNumber(int* val);

/*!
Запрашивает у пользователя размер будущей матрицы
\param[out] size считанный размер матрицы
*/
void InputSize(int* size);

/*!
Запускает исполнение оновного функционала программы
\param[in] argc передаваемый числовой код
\param[in] argv[] массив параметров коммандной строки
\return код завершения программы
*/ 
int main(int argc, char* argv[]);

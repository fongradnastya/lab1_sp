/*!
\file
\brief Заголовочный файл с описанием функций

Данный файл содержит в себе определения основных
функций, используемых в программе
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*!
\brief Считывает строку произвольной длины из коноли
\param[out] len полученная длина строки
\return считанная из консоли строка
*/
char* GetString(int *len);

/*!
\brief Вывод матрицы в консоль
\param[in] matrix матрица для вывода
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void PrintMatrix(int** matrix, int size_x, int size_y);

/*!
\brief Вычисляет суммы модулей элементов для каждой строки
\param[in] matrix исходная матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
\param[out] sum вычисленные суммы модулей
*/
void CountModuleSum(int** matrix, int size_x, int size_y, int* sum);

/*!
\brief Вычисляет последовательность индексов строк, располагающую строки в порядке убывания
\param[in] array массив сумм элементов строк
\param[in] length длина исходного массива
\param[out] ids вычисленный массив индексов 
*/
void FindMaxId(int* array, int length, int* ids);

/*!
\brief Заполняет строки новой матрицы в порядке убывания суммы модулей их элементов
\param[in] matrix исходная матрица
\param[out] new_matrix новая матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void CreateNewMatrix(int** matrix, int** new_matrix, int size_x, int size_y);

/*!
\brief Считывает из консоли значения элементов матрицы
\param[out] matrix матрица считанных значений
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
\return корректно ли прошло считывание
*/
int InputMatrix(int** matrix, int size_x, int size_y);

/*!
\brief Считывает из консоли одно целое число
\param[out] val считанное значение
\return код корректности считывания
*/
int InputNumber(int* val);

/*!
\brief Запрашивает у пользователя размер будущей матрицы
\param[out] size считанный размер матрицы
*/
void InputSize(int* size);
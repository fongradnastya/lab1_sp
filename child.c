#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*!
Считывает строку произвольной длины из коноли
\param[out] len полученная длина строки
\return считанная из консоли строка
*/
char* GetString(int *len) {
    *len = 0; // изначально строка пуста
    int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char*) malloc(sizeof(char)); // динамическая пустая строка

    char c = getchar(); // символ для чтения данных

    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n') {
        s[(*len)++] = c; // заносим в строку новый символ

        // если реальный размер больше размера контейнера, то увеличим его размер
        if (*len >= capacity) {
            capacity *= 2; // увеличиваем ёмкость строки в два раза
            s = (char*) realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью
        }

        c = getchar(); // считываем следующий символ
    }

    s[*len] = '\0'; // завершаем строку символом конца строки
    return s;
}
/*!
Вывод матрицы в консоль
\param[in] matrix матрица для вывода
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void PrintMatrix(int** matrix, int size_x, int size_y){
    for(int i = 0; i < size_x; i++){
        for(int j = 0; j < size_y; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*!
Вычисляет суммы модулей элементов для каждой строки
\param[in] matrix исходная матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
\param[out] sum вычисленные суммы модулей
*/
void CountModuleSum(int** matrix, int size_x, int size_y, int* sum){
    for(int i = 0; i < size_x; i++){
        sum[i] = 0;
        for(int j = 0; j < size_y; j++){
            sum[i] += abs(matrix[i][j]);
        }
    }
}

/*!
Вычисляет последовательность индексов строк, 
располагающую строки в порядке убывания
\param[in] array массив сумм элементов строк
\param[in] length длина исходного массива
\param[out] ids вычисленный массив индексов 
*/
void FindMaxId(int* array, int length, int* ids){
    for(int i = 0; i < length; i++){
        int max = 0;
        int id = 0;
        for(int j = 0; j < length; j++){
            if(array[j] > max){
                max = array[j];
                id = j;
            }
        }
        ids[i] = id;
        array[id] = 0;
    }
}

/*!
Заполняет строки новой матрицы в порядке 
убывания суммы модулей их элементов
\param[in] matrix исходная матрица
\param[out] new_matrix новая матрица
\param[in] size_x ширина матрицы
\param[in] size_y высота матрицы
*/
void CreateNewMatrix(int** matrix, int** new_matrix, int size_x, int size_y){
    int sum[size_x];
    CountModuleSum(matrix, size_x, size_y, sum);
    printf("Modules summs: ");
    for(int i = 0; i < size_x; i++){
        printf("%d ", sum[i]);
    }
    printf("\n");
    int ids[size_x];
    FindMaxId(sum, size_x, ids);
    for(int i = 0; i < size_x; i++){
        new_matrix[i] = matrix[ids[i]];
    }
}

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
int InputNumber(int* val){
    int len;
    char* str = GetString(&len);
    for(int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && !(i == 0 && str[0] == '-')) return 0;
    }
    *val = atoi(str);
    return 1;
}

/*!
Запрашивает у пользователя размер будущей матрицы
\param[out] size считанный размер матрицы
*/
void InputSize(int* size){
    int x_size = 0;
    while(x_size < 1) {
        printf("Please, enter x matrix size: ");
        int res = InputNumber(&x_size);
        if(res == 0) printf("Incorrect number format. Please, try again.\n");
        else if(x_size < 1) printf("Size should be positive\n");
    }
    int y_size = 0;
    while(y_size < 1) {
        printf("Please, enter y matrix size: ");
        int res = InputNumber(&y_size);
        if(res == 0) printf("Incorrect number format. Please, try again.\n");
        else if(x_size < 1) printf("Size should be positive\n");
    }
    size[1] = x_size;
    size[0] = y_size;
}

/*!
Запускает исполнение оновного функционала программы
\param[in] argc передаваемый числовой код
\param[in] argv[] массив параметров коммандной строки
\return код завершения программы
*/ 
int main(int argc, char* argv[]) {
    int size [] = {0, 0};
    InputSize(size);
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++){
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
    }
    int res = InputMatrix(matrix, size[0], size[1]);
    if(res){
        printf("Your matrix:\n");
        PrintMatrix(matrix, size[0], size[1]);
        int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
        for(int i = 0; i < size[0]; i++){
            new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
        }
        CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
        printf("New matrix:\n");
        PrintMatrix(new_matrix, size[0], size[1]);

    }
    else{
        printf("Incorrect input. Matrix should consist only of numbers\n");
    }
    for(int i = 0; i < size[0]; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
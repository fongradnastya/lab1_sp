#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


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

void PrintMatrix(int** matrix, int size_x, int size_y){
    for(int i = 0; i < size_x; i++){
        for(int j = 0; j < size_y; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** CreateMatrix(int a, int b){
    int** matrix = (int**) malloc(a * sizeof(int*));
    for(int i = 0; i < a; i++){
        matrix[i] = (int*)malloc(b * sizeof(int));
    }
    return matrix;
}

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

int InputNumber(int* val){
    int len;
    char* str = GetString(&len);
    printf("Str %s\n", str);
    for(int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]) && !(i == 0 && str[0] == '-')) return 0;
    }
    *val = atoi(str);
    return 1;
}

void InputSize(int* size){
    int x_size = 0;
    while(x_size < 1) {
        printf("Please, enter x-size: ");
        InputNumber(&x_size);
    }
    int y_size = 0;
    while(y_size < 1) {
        printf("Please, enter y-size: ");
        InputNumber(&y_size);
    }
    size[1] = x_size;
    size[0] = y_size;
}

int main() {
    int size [] = {0, 0};
    InputSize(size);
    printf("Answer %d %d\n", size[0], size[1]);
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++){
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
    }
    int res = InputMatrix(matrix, size[0], size[1]);
    if(res){
        PrintMatrix(matrix, size[0], size[1]);
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
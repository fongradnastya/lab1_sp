#include <stdio.h>
#include <stdlib.h>


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
}

void PrintMatrix(int ** matrix, int size_x, int size_y){
    for(int i = 0; i < size_y; i++){
        for(int j = 0; j < size_x - 1; j++){
            printf("%d, ", matrix[i][j]);
        }
        printf("%d\n", matrix[i][-1]);
    }
}

void CreateMatrix(int a, int b){
    int** matrix = (int**) malloc(a * sizeof(int*));
    for(int i = 0; i < a; i++){
        matrix[i] = (int*)malloc(b * sizeof(int));
    }
    PrintMatrix(matrix, a, b);
}

void InputMatrix(int size_x, int size_y){

}

int main() {
    int res = 0;
    int a;
    char* str = " ";
    while(str){
        setbuf(stdin, NULL);
        printf("Please, enter a matrix size: ");
        
        res = scanf("%d%s", &a, str);
    }
    CreateMatrix(a, a);
    return 0;
}
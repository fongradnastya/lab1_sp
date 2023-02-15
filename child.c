/*! Запускает дочерний поток программы */

#include"matrix.c"
 
int main(int argc, char* argv[]) 
{
    int size [] = {0, 0};
    InputSize(size);
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++)
    {
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
    }
    int res = InputMatrix(matrix, size[0], size[1]);
    if(res)
    {
        printf("Your matrix:\n");
        PrintMatrix(matrix, size[0], size[1]);
        int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
        for(int i = 0; i < size[0]; i++)
        {
            new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
        }
        CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
        printf("New matrix:\n");
        PrintMatrix(new_matrix, size[0], size[1]);

    }
    else
    {
        printf("Incorrect input. Matrix should consist only of numbers\n");
    }
    for(int i = 0; i < size[0]; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
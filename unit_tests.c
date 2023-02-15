#include <stdlib.h>
#include <CUnit/Basic.h>


void CountModuleSum(int** matrix, int size_x, int size_y, int* sum)
{
    printf("Modules summs: ");
    for(int i = 0; i < size_x; i++)
    {
        sum[i] = 0;
        for(int j = 0; j < size_y; j++)
        {
            sum[i] += abs(matrix[i][j]);
        }
        printf("%d ", sum[i]);
    }
    printf("\n");
}

void FindMaxId(int* array, int length, int* ids)
{
    for(int i = 0; i < length; i++){
        int max = 0;
        int id = 0;
        for(int j = 0; j < length; j++)
        {
            if(array[j] > max)
            {
                max = array[j];
                id = j;
            }
        }
        ids[i] = id;
        array[id] = 0;
    }
}

void CreateNewMatrix(int** matrix, int** new_matrix, int size_x, int size_y)
{
    int sum[size_x];
    CountModuleSum(matrix, size_x, size_y, sum);
    int ids[size_x];
    FindMaxId(sum, size_x, ids);
    for(int i = 0; i < size_x; i++)
    {
        new_matrix[i] = matrix[ids[i]];
    }
}

int CompareMatrix(int** matrix_1, int** matrix_2, int size_x, int size_y)
{
    for(int i = 0; i < size_x; i++)
    {
        for(int j = 0; j < size_y; j++)
        {
            if (matrix_1[i][j] != matrix_2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void FreeMatrix(int** matrix, int* size)
{
    for(int i = 0; i < size[0]; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void Test1(){
    int size[] = {1, 1};
    int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    matrix[0] = (int*)malloc(size[1] * sizeof(int));
    new_matrix[0] = (int*)malloc(size[1] * sizeof(int));
    matrix[0][0] = 2;
    CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
    CU_ASSERT_EQUAL(CompareMatrix(matrix, new_matrix, size[0], size[1]), 1);
}

void Test2(){
    int size[] = {2, 2};
    int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    int** correct = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++)
    {
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
        new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
        correct[i] = (int*)malloc(size[1] * sizeof(int));
    }
    matrix[0][0] = -2;
    matrix[0][1] = -3;
    matrix[1][0] = 4;
    matrix[1][1] = -5;
    correct[0][0] = 4;
    correct[0][1] = -5;
    correct[1][0] = -2;
    correct[1][1] = -3;
    CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
    CU_ASSERT_EQUAL(CompareMatrix(correct, new_matrix, size[0], size[1]), 1);
}

void Test3(){
    int size[] = {2, 2};
    int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    int** correct = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++)
    {
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
        new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
        correct[i] = (int*)malloc(size[1] * sizeof(int));
    }
    matrix[0][0] = 2;
    matrix[0][1] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    correct[0][0] = 4;
    correct[0][1] = 5;
    correct[1][0] = 2;
    correct[1][1] = 3;
    CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
    CU_ASSERT_EQUAL(CompareMatrix(correct, new_matrix, size[0], size[1]), 1);
}

void Test4(){
    int size[] = {2, 3};
    int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    int** correct = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++)
    {
        matrix[i] = (int*)malloc(size[1] * sizeof(int));
        new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
        correct[i] = (int*)malloc(size[1] * sizeof(int));
    }
    matrix[0][0] = 2;
    matrix[0][1] = 3;
    matrix[0][2] = 0;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = -9;

    correct[0][0] = 4;
    correct[0][1] = 5;
    correct[0][2] = -9;
    correct[1][0] = 2;
    correct[1][1] = 3;
    correct[1][2] = 0;
    CreateNewMatrix(matrix, new_matrix, size[0], size[1]);
    CU_ASSERT_EQUAL(CompareMatrix(correct, new_matrix, size[0], size[1]), 1);
}

int main(){
    CU_pSuite suite;
    CU_initialize_registry();
    suite = CU_add_suite("main_suite", NULL, NULL);
    CU_ADD_TEST(suite, Test1);
    CU_ADD_TEST(suite, Test2);
    CU_ADD_TEST(suite, Test3);
    CU_ADD_TEST(suite, Test4);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
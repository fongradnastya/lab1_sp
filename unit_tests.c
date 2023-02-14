#include <stdlib.h>
#include <CUnit/Basic.h>
#include"child.h"

void TestCreateNewMatrix(){
    int size[] = {2, 2};
    int** new_matrix = (int**) malloc(size[0] * sizeof(int*));
    int** matrix = (int**) malloc(size[0] * sizeof(int*));
    for(int i = 0; i < size[0]; i++){
        new_matrix[i] = (int*)malloc(size[1] * sizeof(int));
    }
}

int main(){
    return 0;
}
//
// Created by nmention on 26/09/22.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "math.h"
#include "malloc.h"
#include "matrix.h"



matrix createMatrix(int rows,int col){
    matrix new_matrix;

    new_matrix.rows = rows;
    new_matrix.columns = col;
    new_matrix.data = malloc(new_matrix.columns * new_matrix.rows * sizeof(int));
    return new_matrix;
}

matrix * fillMatrix(matrix* matrix1){
    for (int i = 0; i < matrix1->rows ; ++i) {
        for (int j = 0; j < matrix1->columns; ++j) {
            matrix1->data[i][j]= 0;
        }
    }
}
void printMatrix(matrix* matrix1){
    printf("[");
    for (int i = 0; i < matrix1->rows ; ++i) {
        for (int j = 0; j < matrix1->columns; ++j) {
            printf("%d",matrix1->data[i][j]);
        }
        printf("\n");
    }
    printf("]");
}

int get_size(matrix* matrix1){
    return matrix1->rows * matrix1->columns;
}


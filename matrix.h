//
// Created by nmention on 26/09/22.
//

#ifndef TP_MATRIX_H
#define TP_MATRIX_H
typedef struct matrix{
    int rows;
    int columns;
    int **data;


} matrix;

matrix createMatrix(int rows,int col);
matrix * fillMatrix(matrix* matrix1);
int get_size(matrix* matrix1);
void printMatrix(matrix* matrix1);
#endif //TP_MATRIX_H

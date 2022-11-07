//
// Created by nmention on 26/09/22.
//

#ifndef TP_MATRIX_H
#define TP_MATRIX_H
typedef struct matrix{
    int rows;
    int columns;
    int *data;


} matrix;

matrix createMatrix(int rows,int col);
void fillMatrix(matrix* matrix1);
int get_size(matrix* matrix1);
void printMatrix(matrix* matrix1);
void setValuebyIndex(int index,int value, matrix *matrix1);
void getRow(int row_index, matrix *matrix1);
int binaryToInt(int start, int end, matrix *matrix1);
matrix constrMatrix(int size);
matrix inversMatrix(matrix matrix1);
matrix fillHadamardMatrix(matrix *matrix1);
#endif //TP_MATRIX_H

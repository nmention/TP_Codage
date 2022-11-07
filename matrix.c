//
// Created by nmention on 26/09/22.
//
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"




matrix createMatrix(int rows,int col){
    matrix new_matrix;

    new_matrix.rows = rows;
    new_matrix.columns = col;
    new_matrix.data = malloc(new_matrix.columns * new_matrix.rows * sizeof(int));
    if (new_matrix.data == NULL)
    {

        perror("createMatrix failed to allocate memory");

    }


    return new_matrix;
}

void fillMatrix(matrix* matrix1)
{
    for (int i = 0; i < matrix1->rows ; ++i)
    {
        for (int j = 0; j < matrix1->columns; ++j)
        {
            matrix1->data[i * matrix1->rows + j]= 1;
        }
    }
}
void setValuebyIndex(int index,int value, matrix *matrix1)
{
    matrix1->data[index] = value;
}

void printMatrix(matrix* matrix1)
{

    for (int i = 0; i < matrix1->rows ; ++i)
    {
        printf("[");
        for (int j = 0; j < matrix1->columns; ++j)
        {
            printf(" %d ",matrix1->data[i * matrix1->rows + j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");

}
void getRow(int row_index, matrix *matrix1)
{
    int startRow = 0;
    int temp = 0;
    int cpt = 0;
    char string[matrix1->columns];


    startRow = row_index * matrix1->columns;
    int result = binaryToInt(row_index * matrix1->columns,startRow + matrix1->columns,matrix1);
    printf("%d \n",result);


}

int binaryToInt(int start, int end, matrix *matrix1)
{
    int result = 0;
    int power = 0;
    for (int i = end-1; i >= start ; i--)
    {
        if (matrix1->data[i] == -1)
        {
            result += 0;
        }
        else
        {
            result += (int) (matrix1->data[i] * pow(2,power));
        }
        power++;

    }
    return result;
}
int get_size(matrix* matrix1)
{
    return matrix1->rows * matrix1->columns;
}
matrix constrMatrix(int size)
{
    int nbCol = 0;
    matrix temp;

    for (int i = 0; i < size ; ++i) {
        nbCol = (int)pow(2,i);
        matrix matrix1 = createMatrix(nbCol,nbCol);
        fillMatrix(&matrix1);
        temp = matrix1;
    }
    return temp;
}

matrix inversMatrix(matrix matrix1)
{
    matrix inversedMatrix = createMatrix(matrix1.rows,matrix1.columns);
    inversedMatrix.data = malloc(inversedMatrix.rows * inversedMatrix.columns * sizeof(int));


    for (int i = 0; i < inversedMatrix.rows ; ++i)
    {
        for (int j = 0; j < inversedMatrix.columns; ++j)
        {
            inversedMatrix.data[i * inversedMatrix.rows + j]= -1 * matrix1.data[i * inversedMatrix.rows + j];
        }
    }
    return inversedMatrix;
}

matrix fillHadamardMatrix(matrix *matrix1)

{
    matrix inverse;
    inverse = inversMatrix(*matrix1);
    int nbColRow = 0;
    nbColRow = 2 * matrix1->columns;
    matrix hadamard = createMatrix(nbColRow,nbColRow);
    int indice = 0;
    for (int i = 0; i < hadamard.rows ; ++i)
    {
        for (int j = 0; j < hadamard.columns; ++j)
        {
            if (i < matrix1->rows)
            {
                if (j < matrix1->columns)
                {
                    hadamard.data[i * hadamard.rows + j] = matrix1->data[i * matrix1->rows + j];
                }
                if (j >= matrix1->columns)
                {
                    if (matrix1->columns == 1)
                    {
                        hadamard.data[i * hadamard.rows + j] = matrix1->data[i * matrix1->rows + j/2];
                    }
                    else
                    {
                        hadamard.data[i * hadamard.rows + j] = matrix1->data[i * matrix1->rows + j%2];
                    }

                }

            }
            if (i >= matrix1->rows)
            {
                if (j < matrix1->columns)
                {
                    if (matrix1->columns == 1)
                    {
                        hadamard.data[i * hadamard.rows + j] = matrix1->data[i/2 * matrix1->rows + j];
                    }
                    else
                    {
                        hadamard.data[i * hadamard.rows + j] = matrix1->data[i%2 * matrix1->rows + j];
                    }


                }
                if (j >= matrix1->columns)
                {
                    if (matrix1->columns == 1)
                    {
                        hadamard.data[i * hadamard.rows + j] = inverse.data[i/2 * inverse.rows + j/2];
                    }
                    else
                    {
                        hadamard.data[i * hadamard.rows + j] = inverse.data[i%2 * inverse.rows + j%2];
                    }

                }
            }

        }
    }
    return hadamard;



}


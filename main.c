//
// Created by nmention on 26/09/22.
//
#include <malloc.h>
#include "math.h"
#include "matrix.h"


#include "stdio.h"



int hadamard(int nb_users){
    int matrice[nb_users][nb_users];
    for (int i = 0; i < nb_users; ++i) {
        for (int j = 0; j < nb_users ; ++j) {
            matrice[i][j]=0;
        }
    }
    for (int i = 0; i < nb_users; ++i) {
        for (int j = 0; j < nb_users ; ++j) {
            printf("%d",matrice[i][j]);
        }
        printf("\n");
    }
}

int hadamardTest(int nb) {
    int H0 = 1;

    if (nb == 1){
        H0=-H0;
    }
    int matrice[nb][nb];
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < nb; ++j) {
            matrice[i][j] = H0;

        }
        matrice[nb-1][nb-1] = -H0;
    }
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < nb; ++j) {
            printf("%d ", matrice[i][j]);

        }
        printf("\n");
        int temp = malloc(nb*nb * sizeof(int));

    }
    size_t n = sizeof(matrice);
    printf("%zu",n);
}


int trad(int * msg, int *row){


}
int main(){
    double test = log2(16);
    matrix a = createMatrix(2,2);
    //printf("%lu",sizeof(a));
    /*int size = get_size(&a);
    printf("%d",size);*/
    //printMatrix(&a);


   /* printf("%f",test);
    printf("\n");
    hadamard( 4);*/
    hadamardTest(2);
    /*int hadamard[2][2];
    for (int i = 0; i < 2 ; ++i) {
        for (int j = 0; j < i ; ++j) {
           hadamard[i][j] = 1;
           if ()
        }

    }*/

}
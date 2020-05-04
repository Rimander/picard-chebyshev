#include "matlab.h"
#include <stdio.h>
#include <stdlib.h>


int main() {

    double **mat;
    double **outmat;
    int i, j, filas = 4, colum = 6;

    mat = (double **) calloc(filas, sizeof(double *));
    outmat = (double **) calloc(filas, sizeof(double *));
    for (i = 0; i < filas; i++) {
        mat[i] = (double *) calloc(colum, sizeof(double));
        outmat[i] = (double *) calloc(colum, sizeof(double));
        for (j = 0; j < colum; j++) {
            mat[i][j] = i + j;
        }
    }


    for (i = 0; i < filas; i++) {
        for (j = 0; j < colum; j++) {
            printf(" %f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    fliplr(filas, colum, mat, &outmat);

    for (i = 0; i < filas; i++) {
        for (j = 0; j < colum; j++) {
            printf(" %f ", outmat[i][j]);
        }
        printf("\n");
    }


    double b = 0;
    sum(colum, mat[0], &b);
    printf("\n");
    printf(" %f ", b);
    printf("\n");


    double *bb = (double *) calloc(colum, sizeof(double));

    summatrix(filas, colum, mat, &bb);

    printf("\n");
    for (i = 0; i < colum; i++) {
        printf(" %f ", bb[i]);
    }
    printf("\n");
    printf("\n");


    return 0;
}

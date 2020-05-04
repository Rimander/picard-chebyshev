#include "matlab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    sumarray(colum, mat[0], &b);
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



    int cr = 2;
    int cc = 2;
    double **bbb = (double **) calloc(filas * cr, sizeof(double *));
    for (i = 0; i < filas * cr; i++)
        bbb[i] = (double *) calloc(colum * cr, sizeof(double));

    repmat(filas, colum, mat, cr, cc, &bbb);

    for (i = 0; i < filas * cr; i++) {
        for (j = 0; j < colum * cc; j++) {
            printf(" %f ", bbb[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");


    double *bbbb = (double *) calloc(colum, sizeof(double));

    applyfuntwoargs(pow, 2, mat[1], colum, &bbbb);

    printf("\n");
    for (i = 0; i < colum; i++) {
        printf(" %f ", bbbb[i]);
    }
    printf("\n");
    printf("\n");


    return 0;
}

/**
 * @file matlab.c
 * @author Fermin Jimenez
 */

#include "matlab.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// fliplr
//------------------------------------------------------------------------------
/**
 * Turn the columns, left to right
 *
 *  [1,3,4,2,5] -> [5,2,4,3,1]
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx>  [N x M]
 * @param[inout] <matrix>  [N x M]
 */
//------------------------------------------------------------------------------
void fliplr(int n, int m, double **mtrx, double ***matrix) {

    // Matrix
    double **outMatrix = *matrix;

    int row;
    for (row = 0; row < n; row++) {
        // Row array
        double *rowMatrix = mtrx[row];
        double *rowOutMatrix = outMatrix[row];

        // Start and end position of array
        int start = 0;
        int end = m - 1;

        while (start < end) {
            rowOutMatrix[start] = rowMatrix[end];
            rowOutMatrix[end] = rowMatrix[start];
            start++;
            end--;
        }
    }

}

//------------------------------------------------------------------------------
// create
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[in] <n> number of rows
 * @param[inout] <vec>
 */
//------------------------------------------------------------------------------
void createvector(int n, double **vec) {
    *vec = (double *) calloc(n, sizeof(double));
    if (*vec == NULL) {
        printf("ERROR: no queda memoria dinamica\n");
        exit(1);
    }
}




//------------------------------------------------------------------------------
// free
//------------------------------------------------------------------------------
/**
 * Liberate
 *
 * @param[in] <vec>
 */
//------------------------------------------------------------------------------
void freevector(double *vec) {
    free(vec);
}


//------------------------------------------------------------------------------
// summatrix
//------------------------------------------------------------------------------
/**
 * Sum elements
 *
 * ~~~
 *  sum(3,3, matrix, ...)
 *
 *  1     3     2        11     6     11
 *  4     2     5
 *  6     1     4
 * ~~~
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx> A [N x M]
 * @param[out] <mtrb> B [1 x M]
 */
//------------------------------------------------------------------------------
void summatrix(int n, int m, double **a, double **b) {
    int row;
    int col;
    double *vec = *b;
    for (row = 0; row < n; row++) {
        double *rowMatrix = a[row];
        for (col = 0; col < m; col++) {
            vec[col] += rowMatrix[col];
        }
    }
}



//------------------------------------------------------------------------------
// sum
//------------------------------------------------------------------------------
/**
 * Sum elements
 *
 * ~~~
 *  sum(3,3, matrix, ...)
 *
 *  1     3     2        11     6     11
 *  4     2     5
 *  6     1     4
 * ~~~
 *
 * @param[in] <n> number of items
 * @param[in] <mtrx> A [N x M]
 * @param[out] <mtrb> B [1 x M]
 */
//------------------------------------------------------------------------------
void sumvector(int n, double *a, double *b) {

    int row;
    *b = 0;
    for (row = 0; row < n; row++) {
        *b += a[row];
    }

}

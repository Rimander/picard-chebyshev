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
void createarray(int n, double **vec) {
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
void freearray(double *vec) {
    free(vec);
}


//------------------------------------------------------------------------------
// repmat
//------------------------------------------------------------------------------
/**
 * Generate a  containing c copies of A at the row and column levels.
 *
 * ~~~
 *   repmat(2, 2, matrix, 2, 2, ...)
 *
 *   100  0         100  0    100  0
 *   0    200         0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 * ~~~
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx> A  [N x M]
 * @param[in] <cr> number of row copies
 * @param[in] <cc> number of column copies
 * @param[out] <mtrb> B  [N x M]
 */
//------------------------------------------------------------------------------
void repmat(int n, int m, double **a, int cr, int cc, double ***b) {

    int i, j, row, col;
    double **bMatrix = *b;

    // Number of row copies
    for (i = 0; i < cr; i++) {
        for (row = 0; row < n; row++) {
            double *rowMatrix = a[row];
            double *rowBMatrix = bMatrix[i * n + row];

            // Number of column copies
            for (j = 0; j < cc; j++) {
                for (col = 0; col < m; col++) {
                    rowBMatrix[j * m + col] = rowMatrix[col];
                }
            }
        }
    }
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
void sumarray(int n, double *a, double *b) {

    int row;
    *b = 0;
    for (row = 0; row < n; row++) {
        *b += a[row];
    }
}

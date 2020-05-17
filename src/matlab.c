/**
 * @file matlab.c
 * @author Fermin Jimenez
 */

#include "matlab.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
// fliplr
//------------------------------------------------------------------------------
/**
 * Turn the columns, left to right
 *
 *  [1,3,4,2,5] -> [5,2,4,3,1]
 *
 * @param[in] <m> number of items
 * @param[in] <in>
 * @param[out] <out>
 */
//------------------------------------------------------------------------------
void fliplr(int m, double *in, double **out) {


    double *elementsOut = *out;
    // Start and end position of array
    int start = 0;
    int end = m - 1;

    while (start < end) {
        elementsOut[start] = in[end];
        elementsOut[end] = in[start];
        start++;
        end--;
    }

}

//------------------------------------------------------------------------------
// create
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[in] <n> number of rows
 * @param[out] <out>
 */
//------------------------------------------------------------------------------
void createarray(int n, double **out) {
    *out = (double *) calloc(n, sizeof(double));
    if (*out == NULL) {
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
 * @param[in] <in>
 */
//------------------------------------------------------------------------------
void freearray(double *in) {
    free(in);
}


//------------------------------------------------------------------------------
// create
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[in] <n> number of rows
 * @param[in] <n> number of columns
 * @param[out] <out>
 */
//------------------------------------------------------------------------------
void creatematrix(int n, int m, double ***out) {
    int i;
    *out = (double **) calloc(n, sizeof(double *));
    double **arr = *out;
    for (i = 0; i < n; i++) {
        arr[i] = (double *) calloc(m, sizeof(double));
    }
}



//------------------------------------------------------------------------------
// free
//------------------------------------------------------------------------------
/**
 * Free
 *
 * @param[in] <n> number of rows
 * @param[in] <in>
 */
//------------------------------------------------------------------------------
void freematrix(int n, double **in) {
    int i;
    for (i = 0; i < n; i++) {
        double *rowIn = in[i];
        free(rowIn);
    }
    free(in);
}


//------------------------------------------------------------------------------
// arrtocolum
//------------------------------------------------------------------------------
/**
 * Transform array to matrix column
 *
 * @param[in] <n> items
 * @param[in] <in>
 * @param[out] <out>
 */
//------------------------------------------------------------------------------
void arrtocolum(int n, double *in, double ***out) {
    int i;
    double **matrix = *out;
    for (i = 0; i < n; i++) {
        matrix[i][0] = in[i];
    }
}



//------------------------------------------------------------------------------
// repmatarr
//------------------------------------------------------------------------------
/**
 * Generate a  containing c copies of A at the row and column levels.
 *
 * ~~~
 *   repmat(2, 2, matrix, 3, 2, ...)
 *
 *   100  0         100  0    100  0
 *   0    200         0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 * ~~~
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx> A [M]
 * @param[in] <cr> number multiply row copies
 * @param[in] <cc> number multiply column copies
 * @param[out] <mtrb> B  [N x M]
 */
//------------------------------------------------------------------------------
void repmatarr(int n, int m, double *in, int cr, int cc, double ***out) {

    int i, j, row, col;
    double **bMatrix = *out;

    // Number of row copies
    for (i = 0; i < cr; i++) {
        for (row = 0; row < n; row++) {
            double *rowBMatrix = bMatrix[i * n + row];

            // Number of column copies
            for (j = 0; j < cc; j++) {
                for (col = 0; col < m; col++) {
                    rowBMatrix[j * m + col] = in[col];
                }
            }
        }
    }
}

//------------------------------------------------------------------------------
// repmat
//------------------------------------------------------------------------------
/**
 * Generate a  containing c copies of A at the row and column levels.
 *
 * ~~~
 *   repmat(2, 2, matrix, 3, 2, ...)
 *
 *   100  0         100  0    100  0
 *   0    200         0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 * ~~~
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx> A  [N x M]
 * @param[in] <cr> number multiply row copies
 * @param[in] <cc> number multiply column copies
 * @param[out] <mtrb> B  [N x M]
 */
//------------------------------------------------------------------------------
void repmat(int n, int m, double **in, int cr, int cc, double ***out) {

    int i, j, row, col;
    double **bMatrix = *out;

    // Number of row copies
    for (i = 0; i < cr; i++) {
        for (row = 0; row < n; row++) {
            double *rowMatrix = in[row];
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
void summatrix(int n, int m, double **in, double **out) {
    int row;
    int col;
    double *vec = *out;
    for (row = 0; row < n; row++) {
        double *rowMatrix = in[row];
        for (col = 0; col < m; col++) {
            vec[col] += rowMatrix[col];
        }
    }
}



//------------------------------------------------------------------------------
// printmatrix
//------------------------------------------------------------------------------
/**
 * print elements

 * @param[in] <n> rows
 * @param[in] <m> columns
 * @param[in] <mtrx> A [N x M]
 */
//------------------------------------------------------------------------------
double printmatrix(int n, int m, double **mtrx) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%f\t", mtrx[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



//------------------------------------------------------------------------------
// printarray
//------------------------------------------------------------------------------
/**
 * print elements

 * @param[in] <n> items
 * @param[in] <arr> A [N]
 */
//------------------------------------------------------------------------------
double printarray(int n, double *arr) {
    int i, j;

    for (i = 0; i < n; i++) {
        printf("%5.15lf \t", arr[i]);
    }

    printf("\n");
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
 * @return double sum
 */
//------------------------------------------------------------------------------
double sumarray(int n, double *in) {
    double out = 0;
    int row;
    for (row = 0; row < n; row++) {
        out += in[row];
    }
    return out;
}



//------------------------------------------------------------------------------
// applyfunonearg
//------------------------------------------------------------------------------
/**
 * Apply a function with one argument
 *
 *
 * @param[in] <fp> function
 * @param[in] <in>  [1 x M]
 * @param[in] <m>  number of items
 * @param[out] <out> [1 x M]
 */
//------------------------------------------------------------------------------
void applyfunonearg(double (*fp)(double), double *in, int m, double **out) {
    int i;
    double *outValues = *out;
    for (i = 0; i < m; i++) {
        double value = (*fp)(in[i]);
        outValues[i] = value;
    }
}



//------------------------------------------------------------------------------
// applyfuntwoargs
//------------------------------------------------------------------------------
/**
 * Apply a function with one argument
 *
 *
 * @param[in] <fp> function
 * @param[in] <in>  [1 x M]
 * @param[in] <m>  number of items
 * @param[out] <out> [1 x M]
 */
//------------------------------------------------------------------------------
void applyfuntwoargs(double (*fp)(double, double), double c, double *in, int m, double **out) {
    int i;
    double *outValues = *out;

    for (i = 0; i < m; i++) {
        double value = (*fp)(in[i], c);
        outValues[i] = value;
    }
}


//------------------------------------------------------------------------------
// applyfuntwoargsmatrix
//------------------------------------------------------------------------------
/**
 * Apply a function with one argument matrix
 *
 *
 * @param[in] <fp> function
 * @param[in] <in>  [N x M]
 * @param[in] <n>  number of rows
 * @param[in] <m>  number of columns
 * @param[out] <out> [N x M]
 */
//------------------------------------------------------------------------------
void applyfuntwoargsmatrix(double (*fp)(double, double), double c, double **in, int n, int m, double ***out) {
    int i, j;
    double **aux = *out;

    for (i = 0; i < n; i++) {
        double *row = in[i];
        double *outRow = aux[i];
        for (j = 0; j < m; j++) {
            outRow[j] = (*fp)(row[j], c);
        }
    }
}



//------------------------------------------------------------------------------
// elementgtvalue
//------------------------------------------------------------------------------
/**
 * Element greater than value
 *
 *
 * @param[in] <n>  number of items
 * @param[in] <in>  [N]
 * @param[in] <value>  value
 * @param[out] <out> [N]
 */
//------------------------------------------------------------------------------
void elementgtvalue(int n, double *in, double value, double **out) {
    double *o = *out;
    for (int i = 0; i < n; i++) {
        o[i] = in[i] > value ? 1 : 0;
    }
}



//------------------------------------------------------------------------------
// elementltvalueabs
//------------------------------------------------------------------------------
/**
 * Element less than value with abs
 *
 *
 * @param[in] <n>  number of items
 * @param[in] <in>  [N]
 * @param[in] <value>  value
 * @param[out] <out> [N]
 */
//------------------------------------------------------------------------------
void elementltvalueabs(int n, double *in, double value, double **out) {
    double *o = *out;
    for (int i = 0; i < n; i++) {
        o[i] = abs(in[i]) > value ? 1 : 0;
    }
}



//------------------------------------------------------------------------------
// cross
//------------------------------------------------------------------------------
/**
 * Cross product
 *
 *
 * @param[in] <n>  number of rows
 * @param[in] <b>  number of columns
 * @param[in] <a>  [3 x M]
 * @param[in] <b>  [3 x M]
 * @param[out] <out> [3 x M]
 */
//------------------------------------------------------------------------------
void cross(int n, int m, double **a, double **b, double ***out) {
    double **matrix;
    double *arrA, *arrB;

    matrix = *out;
    createarray(m, &arrA);
    createarray(m, &arrB);

    for (int j = 0; j < m; j++) {

        // Columns
        for (int i = 0; i < n; i++) {
            arrA[i] = a[i][j];
        }

        for (int i = 0; i < n; i++) {
            arrB[i] = b[i][j];
        }

        // Cross Product
        matrix[0][j] = arrA[1] * arrB[2] - arrA[2] * arrB[1];
        matrix[1][j] = arrA[2] * arrB[0] - arrA[0] * arrB[2];
        matrix[2][j] = arrA[0] * arrB[1] - arrA[1] * arrB[0];
    }
}

//------------------------------------------------------------------------------
// any
//------------------------------------------------------------------------------
/**
 * Determine if any array elements are nonzero
 *
 *
 * @param[in] <n>  number of items
 * @param[in] <in>  [N]
 * @return 1 if any element are nonzero, other case 0;
 */
//------------------------------------------------------------------------------
int any(int n, double *in) {
    int anyValue = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 1) {
            anyValue = 1;
        }
    }
    return anyValue;
}
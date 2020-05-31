/**
 * @file matlab.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_MATLAB_H
#define CODIGO_MATLAB_H



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
#include <stdbool.h>

//------------------------------------------------------------------------------
void fliplr(int m, double *in, double **out);



//------------------------------------------------------------------------------
// create
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[in <n> number of rows
 * @param[out] <out>
 */
//------------------------------------------------------------------------------
void createarray(int n, double **out);



//------------------------------------------------------------------------------
// free
//------------------------------------------------------------------------------
/**
 * Free
 *
 * @param[in] <in>
 */
//------------------------------------------------------------------------------
void freearray(double *in);



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
void creatematrix(int n, int m, double ***out);



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
void freematrix(int n, double **in);

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
void arrtocolum(int n, double *in, double ***out);

//------------------------------------------------------------------------------
// repmat
//------------------------------------------------------------------------------
/**
 * Generate a  containing c copies of A at the row and column levels.
 *
 * ~~~
 *   repmat(2, 2, matrix, 2, ...)
 *
 *   100  0         100  0    100  0
 *   0    200         0  200  0    200
 *                  100  0    100  0
 *                    0  200  0    200
 * ~~~
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx> A  [M]
 * @param[in] <cr> number of row copies
 * @param[in] <cc> number of column copies
 * @param[out] <mtrb> B  [N x M]
 */
//------------------------------------------------------------------------------
void repmatarr(int n, int m, double *in, int cr, int cc, double ***out);


//------------------------------------------------------------------------------
// repmat
//------------------------------------------------------------------------------
/**
 * Generate a  containing c copies of A at the row and column levels.
 *
 * ~~~
 *   repmat(2, 2, matrix, 2, ...)
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
void repmat(int n, int m, double **in, int cr, int cc, double ***out);


//------------------------------------------------------------------------------
// column
//------------------------------------------------------------------------------
/**
 * Column
 *
 * @param[in] <n> number of rows
 * @param[in] <c> number of column
 * @param[in] <mtrx> A [N x M]
 * @param[out] <mtrb> B [N]
 */
//------------------------------------------------------------------------------
void column(int n, int c, double **in, double **out);



//------------------------------------------------------------------------------
// productarray
//------------------------------------------------------------------------------
/**
 * productarray
 *
 */
//------------------------------------------------------------------------------
double productarray(int n, double *a, double *b);


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
void summatrix(int n, int m, double **in, double **out);



//------------------------------------------------------------------------------
// sum
//------------------------------------------------------------------------------
/**
 * Sum
 *
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <a> A [N x M]
 * @param[in] <b> B [N x M]
 * @param[out] <mtrb> C [N x M]
 */
//------------------------------------------------------------------------------
void sum(int n, int m, double **a, double **b, double ***out);


//------------------------------------------------------------------------------
// divide
//------------------------------------------------------------------------------
/**
 * divide

 * @param[in] <n> rows
 * @param[in] <m> columns
 * @param[in] <in>  [N]
 * @param[in] <matrix>  [N x M]
 * @param[out] <out>  [N x M]
 */
//------------------------------------------------------------------------------
void divide(int rows, int columns, double *in, double **matrix, double ***out);


//------------------------------------------------------------------------------
// mult
//------------------------------------------------------------------------------
/**
 * mult

 * @param[in] <n> a rows
 * @param[in] <m> a columns
 * @param[in] <nn> b rows
 * @param[in] <mm> b columns
 * @param[in] <a>  [N X M]
 * @param[in] <n>  [NN x MM]
 * @param[out] <out>  [N x MM]
 */
//------------------------------------------------------------------------------
void mult(int n, int m, int nn, int mm, double **a, double **b, double ***out);


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
void printmatrix(int n, int m, double **mtrx);


//------------------------------------------------------------------------------
// printarray
//------------------------------------------------------------------------------
/**
 * print elements

 * @param[in] <n> items
 * @param[in] <arr> A [N]
 */
//------------------------------------------------------------------------------
void printarray(int n, double *arr);


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
double sumarray(int n, double *in);


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
void applyfunonearg(double (*fp)(double), double *in, int m, double **out);


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
void applyfuntwoargs(double (*fp)(double, double), double c, double *in, int m, double **out);



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
void applyfuntwoargsmatrix(double (*fp)(double, double), double c, double **in, int n, int m, double ***out);



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
void elementgtvalue(int n, double *in, double value, double **out);


//------------------------------------------------------------------------------
// elementltvalue
//------------------------------------------------------------------------------
/**
 * Element less than value
 *
 *
 * @param[in] <n>  number of items
 * @param[in] <in>  [N]
 * @param[in] <value>  value
 * @param[out] <out> [N]
 */
//------------------------------------------------------------------------------
void elementltvalue(int n, double *in, double value, double **out);


//------------------------------------------------------------------------------
// elementgtvalueabs
//------------------------------------------------------------------------------
/**
 * Element greater than value with abs
 *
 *
 * @param[in] <n>  number of items
 * @param[in] <in>  [N]
 * @param[in] <value>  value
 * @param[out] <out> [N]
 */
//------------------------------------------------------------------------------
void elementgtvalueabs(int n, double *in, double value, double **out);


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
void elementltvalueabs(int n, double *in, double value, double **out);


//------------------------------------------------------------------------------
// truevalues
//------------------------------------------------------------------------------
/**
 * Element less than value with abs
 *
 *
 * @param[in] <n>  number of rows
 * @param[in] <m>  number of columns
 * @param[in] <in>  [N * M]
 * @param[in] <compare>  [M]
 * @param[out] <out>  [N * M]
 */
//------------------------------------------------------------------------------
void truevalues(int n, int m, double **in, double *compare, double ***out);


//------------------------------------------------------------------------------
// cross
//------------------------------------------------------------------------------
/**
 * Cross product
 *
 *
 * @param[in] <n>  number of rows
 * @param[in] <b>  number of columns
 * @param[in] <a>  [N x M]
 * @param[in] <b>  [N x M]
 * @param[out] <out> [N x M]
 */
//------------------------------------------------------------------------------
void cross(int n, int m, double **a, double **b, double ***out);


//------------------------------------------------------------------------------
// dot
//------------------------------------------------------------------------------
/**
 *
 * @param[in] <n>  number of rows
 * @param[in] <b>  number of columns
 * @param[in] <a>  [3 x M]
 * @param[in] <b>  [3 x M]
 * @param[out] <out> [M]
 */
//------------------------------------------------------------------------------
void dot(int n, int m, double **a, double **b, double **out);


//------------------------------------------------------------------------------
// sign
//------------------------------------------------------------------------------
/**
 *
 * @param[in] <in>  number
 * @return result
 */
//------------------------------------------------------------------------------
int sign(double in);

//------------------------------------------------------------------------------
// times
//------------------------------------------------------------------------------
/**
 *
 * @param[in] <n>  number of rows
 * @param[in] <b>  number of columns
 * @param[in] <in>  [1 x M]
 * @param[in] <matrix>  [N x M]
 * @param[out] <out> [N x M]
 */
//------------------------------------------------------------------------------
void times(int n, int m, double *in, double **matrix, double ***out);

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
int any(int n, double *in);

// TODO: Hacer 3 any, any, any < , any >
#endif //CODIGO_MATLAB_H

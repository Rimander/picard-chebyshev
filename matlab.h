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
 * @param[in] <n> number of rows
 * @param[in] <m> number of cols
 * @param[in] <mtrx>  [N x M]
 * @param[inout] <matrix>  [N x M]
 */
//------------------------------------------------------------------------------
void fliplr(int n, int m, double **mtrx, double ***matrix);



//------------------------------------------------------------------------------
// create
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[inout] <n> number of rows
 * @param[inout] <vec>
 */
//------------------------------------------------------------------------------
void createarray(int n, double **vec);



//------------------------------------------------------------------------------
// free
//------------------------------------------------------------------------------
/**
 * Create
 *
 * @param[inout] <n> number of rows
 * @param[inout] <vec>
 */
//------------------------------------------------------------------------------
void freearray(double *vec);



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
 * @param[in] <c> number of copies
 * @param[out] <nn> number of rows
 * @param[out] <mm> number of cols
 * @param[out] <mtrb> B  [N x M]
 */
//------------------------------------------------------------------------------
void repmat(int n, int m, double **a, int c, int *nn, int *mm, double ***b);



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
void summatrix(int n, int m, double **a, double **b);



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
void sumvector(int n, double *a, double *b);



//------------------------------------------------------------------------------
// any
//------------------------------------------------------------------------------
/**
 * Determine if any elements are nonzero
 *
 */
//------------------------------------------------------------------------------
void any();
// TODO: Hacer 3 any, any, any < , any >
#endif //CODIGO_MATLAB_H

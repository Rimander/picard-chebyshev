/**
 * @file matlab.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_MATLAB_H
#define CODIGO_MATLAB_H



//------------------------------------------------------------------------------
// function fliplr
//------------------------------------------------------------------------------
/**
 * Turn the columns, left to right
 *
 *  [1,3,4,2,5] -> [5,2,4,3,1]
 *
 * @param[inout] <n> number of rows
 * @param[inout] <m> number of cols
 * @param[inout] <mtrx> Vector [N x M]
 */
//------------------------------------------------------------------------------
void fliplr(int *n, int *m, double **mtrx);



//------------------------------------------------------------------------------
// function repmat
//------------------------------------------------------------------------------
/**
 * Generate an array containing c copies of A at the row and column levels.
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
 * @param[in] <mtrx> A Vector [N x M]
 * @param[in] <c> number of copies
 * @param[out] <nn> number of rows
 * @param[out] <mm> number of cols
 * @param[out] <mtrb> B Vector [N x M]
 */
//------------------------------------------------------------------------------
void repmat(int n, int m, double **a, int c, int *nn, int *mm, double **b);


#endif //CODIGO_MATLAB_H

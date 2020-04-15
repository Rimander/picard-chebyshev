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
 * @param[inout] <n> int number of rows
 * @param[inout] <m> int number of cols
 * @param[inout] <mtrx> Vector double [N x M]
 */
//------------------------------------------------------------------------------
void fliplr(int *n, int *m, double **mtrx);



//------------------------------------------------------------------------------
// function repmat
//------------------------------------------------------------------------------
/**
 * Turn the columns, left to right
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
 * @param[in] <n> int number of rows
 * @param[in] <m> int number of cols
 * @param[in] <mtrx> Vector double [N x M]
 * @param[in] <c> number of copies
 * @param[out] <nn> int number of rows
 * @param[out] <mm> int number of cols
 * @param[out] <mtrb> Vector double [N x M]
 */
//------------------------------------------------------------------------------
void repmat(int n, int m, double **mtrx, int c, int *nn, int *mm, double **mtrxb);


#endif //CODIGO_MATLAB_H

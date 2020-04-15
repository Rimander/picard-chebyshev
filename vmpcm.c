/**
 * @file vmpcm.c
 * @author Fermin Jimenez
 */

#include "vmpcm.h"

//------------------------------------------------------------------------------
// VMPCM
//------------------------------------------------------------------------------
/**
 * Generic Function wrapper for the Vectorized Picard Chebyshev Method
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <ode> Reference function TwoBodyForceModel
 * @param[in] <tau> Vector transformed time domain vector [1 x N]
 * @param[inout] <x_guess> Vector - Input initial Guess of solution values for the Picard Chebyshev Method [N x M],
 * Output refined solution meeting the error tolerances defined by errTol
 * @param[in] <omega1> First Omega Term
 * @param[in] <omega2> Second Omega Term
 * @param[in] <errTol> Error Tolerance of solution
 * @param[in] <varargin> Additional inputs which are needed to be passed to the evaluation function ode
 */
//------------------------------------------------------------------------------
void
VMPCM(double *n, double *m, void (*ode)(int, int, double *, double **, double, double *, int *, int *), double **tau,
      double **x_guess,
      double omega1, double omega2,
      double errTol, double varargin) {

}

//------------------------------------------------------------------------------
// ChebyshevPolynomial
//------------------------------------------------------------------------------
/**
 * The Chebyshev polynomial,T, corresponding to degree k
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <k> Vector [N x 1]
 * @param[in]<tau> Vector transformed time domain vector [1 x M]
 * @param[out] <Tk> Vector [N x M]
 * @param[out] <nn> number of rows
 * @param[out] <mm> number of columns
 */
//------------------------------------------------------------------------------
void ChebyshevPolynomial(double *n, double *m, double **k, double **tau, int *nn, int *mm) {

}

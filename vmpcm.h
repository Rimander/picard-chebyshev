/**
 * @file vmpcm.h
 * @author Fermin Jimenez
 */


#ifndef CODIGO_VMPCM_H
#define CODIGO_VMPCM_H

//------------------------------------------------------------------------------
// function VMPCM
//------------------------------------------------------------------------------
/**
 * Generic Function wrapper for the Vectorized Picard Chebyshev Method
 * @param[in] <n> int number of rows
 * @param[in] <m> int number of columns
 * @param[in] <ode> Reference function TwoBodyForceModel
 * @param[in] <tau> Vector double transformed time domain vector [1 x N]
 * @param[inout] <x_guess> Vector double - Input initial Guess of solution values for the Picard Chebyshev Method [N x M],
 * Output refined solution meeting the error tolerances defined by errTol
 * @param[in] <omega1> double First Omega Term
 * @param[in] <omega2> double Second Omega Term
 * @param[in] <errTol> double Error Tolerance of solution
 * @param[in] <varargin> double Additional inputs which are needed to be passed to the evaluation function ode
 */
//------------------------------------------------------------------------------
void
VMPCM(double *n, double *m, void (*ode)(int, int, double *, double **, double, double *, int *, int *), double *tau,
      double **x_guess,
      double omega1, double omega2,
      double errTol, double varargin);

//------------------------------------------------------------------------------
// function ChebyshevPolynomial
//------------------------------------------------------------------------------
/**
 * The Chebyshev polynomial,T, corresponding to degree k
 * @param[in] <n> int number of rows
 * @param[in] <m> int number of columns
 * @param[in] <k> Vector double [N x 1]
 * @param[in] <tau> Vector double transformed time domain vector [1 x M]
 * @param[out] <Tk> Vector double [N x M]
 * @param[out] <nn> int number of rows
 * @param[out] <mm> int number of columns
 */
//------------------------------------------------------------------------------
void ChebyshevPolynomial(double *n, double *m, double **k, double *tau, int *nn, int *mm);

#endif //CODIGO_VMPCM_H

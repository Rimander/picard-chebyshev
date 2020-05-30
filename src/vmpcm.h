/**
 * @file vmpcm.h
 * @author Fermin Jimenez
 */


#ifndef CODIGO_VMPCM_H
#define CODIGO_VMPCM_H

//------------------------------------------------------------------------------
// VMPCM
//------------------------------------------------------------------------------
/**
 * Generic Function wrapper for the ized Picard Chebyshev Method
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <ode> Reference function TwoBodyForceModel
 * @param[in] <tau>  transformed time domain  [1 x N]
 * @param[inout] <x_guess>  - Input initial Guess of solution values for the Picard Chebyshev Method [N x M],
 * Output refined solution meeting the error tolerances defined by errTol
 * @param[in] <omega1> First Omega Term
 * @param[in] <omega2> Second Omega Term
 * @param[in] <errTol> Error Tolerance of solution
 * @param[in] <varargin> Additional inputs which are needed to be passed to the evaluation function ode
 * @param[out] <rvPCM>
 */
//------------------------------------------------------------------------------
void
VMPCM(void (*ode)(int, int, double **, double **, double, double ***), double n, double m, double *tau,
      double **x_guess,
      double omega1, double omega2,
      double errTol, double varargin, double ***rvPCM);

//------------------------------------------------------------------------------
// ChebyshevPolynomial
//------------------------------------------------------------------------------
/**
 * The Chebyshev polynomial,T, corresponding to degree k
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <k>  [N x 1]
 * @param[in] <tau>  transformed time domain  [1 x M]
 * @param[out] <Tk>  [N x M]
 * @param[out] <nn> number of rows
 * @param[out] <mm> number of columns
 */
//------------------------------------------------------------------------------
void ChebyshevPolynomial(double *n, double *m, double **k, double **tau, int *nn, int *mm);

#endif //CODIGO_VMPCM_H

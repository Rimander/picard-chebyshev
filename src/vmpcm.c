/**
 * @file vmpcm.c
 * @author Fermin Jimenez
 */

#include <math.h>
#include "vmpcm.h"
#include "matlab.h"

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
VMPCM(void (*ode)(int, int, double **, double **, double, double ***), int n, int m, double *tau,
      double **x_guess,
      double omega1, double omega2,
      double errTol, double varargin, double ***rvPCM) {

    double **t, **tv1, **auxm;
    double *aux, *v;
    int i, j;

    //tau = tau(:)';

    //N = numel(tau)-1;
    int N = n - 1;

    //err1 = Inf;
    double err1 = INFINITY;

    //err2 = Inf;
    double err2 = INFINITY;

    //Iter = 0;
    int iter = 0;

    //MaxIter = 300;
    int maxIter = 300;

    //%Initialize Constant Matricies up front so we don't have to recompute them
    //%which would slow down the iterative process
    //T = ChebyshevPolynomial((0:N+1)',tau);
    createarray(N + 2, &aux);
    creatematrix(N + 2, N + 1, &t);
    for (i = 0; i < N + 2; i++) {
        aux[i] = i;
    }

    ChebyshevPolynomial(N + 2, N + 1, aux, tau, &t);


    //V = ones(1,length(tau))./N;
    //V(2:end-1) = V(2:end-1).*2;
    createarray(N + 1, &v);
    for (i = 0; i < N + 1; i++) {
        v[i] = 1.0 / N;
        if (i < N && i > 0) {
            v[i] = 2 * v[i];
        }
    }

    //TV1 = bsxfun(@times,T(1:N,:),V);
    creatematrix(N, N + 1, &tv1);
    creatematrix(N, N + 1, &auxm);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N + 1; j++) {
            auxm[i][j] = t[i][j];
        }
    }
    times(N, N + 1, v, auxm, &tv1);


    printmatrix(N, N + 1, tv1);
}


//------------------------------------------------------------------------------
// ChebyshevPolynomial
//------------------------------------------------------------------------------
/**
 * The Chebyshev polynomial,T, corresponding to degree k
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <k>  [N]
 * @param[in]<tau>  transformed time domain  [ M]
 * @param[out] <Tk>  [N x M]
 */
//------------------------------------------------------------------------------
void ChebyshevPolynomial(int n, int m, double *k, double *tau, double ***tK) {
    //%The Chebyshev polynomial,T, corresponding to degree k
    //Tk = cos(bsxfun(@times,k,acos(tau)));
    double **tkMatrix = *tK;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tkMatrix[i][j] = cos(k[i] * acos(tau[j]));
        }
    }
}

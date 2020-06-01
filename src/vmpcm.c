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
VMPCM(void (*ode)(int, int, double *, double **, double, double ***), int n, int m, double *tau,
      double **x_guess,
      double omega1, double omega2,
      double errTol, double varargin, double ***rvPCM) {

    double **f, **beta_r, **beta_k, **new_x, **x_guess_aux;
    double **t, **tv1, **tv2, **tv, **cx, **auxm;
    double *v, *s, *err1, *err2, *aux, *aux2;

    int i, j;

    //tau = tau(:)';

    //N = numel(tau)-1;
    int N = n - 1;

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

    freearray(aux);

    //V = ones(1,length(tau))./N;
    //V(2:end-1) = V(2:end-1).*2;
    createarray(N + 2, &v);
    for (i = 0; i < N + 2; i++) {
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
    freematrix(N, auxm);

    // TV2 = bsxfun(@times,T(3:N+2,:),V);
    creatematrix(N, N + 1, &tv2);
    creatematrix(N, N + 1, &auxm);

    for (i = 2; i < N + 2; i++) {
        for (j = 0; j < N + 1; j++) {
            auxm[i - 2][j] = t[i][j];
        }
    }
    times(N, N + 1, v, auxm, &tv2);
    freematrix(N, auxm);

    //TV = bsxfun(@rdivide,(TV1-TV2),(2.*(1:N))');
    creatematrix(N, N + 1, &auxm);
    creatematrix(N, N + 1, &tv);
    createarray(N + 1, &aux);

    for (j = 0; j < N + 1; j++) {
        aux[j] = 2 * (j + 1);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N + 1; j++) {
            auxm[i][j] = tv1[i][j] - tv2[i][j];
        }
    }

    divide(N, N + 1, aux, auxm, &tv);
    freematrix(N, auxm);
    freearray(aux);

    //TV(end,:) = TV1(end,:)./(2*N)';
    for (j = 0; j < N + 1; j++) {
        tv[N - 1][j] = tv1[N - 1][j] / (2 * N);
    }


    //S = 2.*((-1).^((1:N)+1));
    createarray(N, &s);
    for (i = 0; i < N; i++) {
        s[i] = 2 * pow(-1, (i + 1) + 1);
    }


    //Cx = T(1:N+1,1:N+1)';
    creatematrix(N + 1, N + 1, &cx);
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < N + 1; j++) {
            cx[i][j] = t[j][i];
            if (j == 0) {
                cx[i][j] = cx[i][j] / 2;
            }
        }
    }

    //%--------------------------------------------------------------------------
    //while (any(errTol < err1 ) || any(errTol < err2)) && Iter < MaxIter
    createarray(N + 1, &err1);
    createarray(N + 1, &err2);
    createarray(N + 1, &aux);
    createarray(N + 1, &aux2);
    creatematrix(N + 1, 6, &f);
    for (i = 0; i < N + 1; i++) {
        err1[i] = INFINITY;
        err2[i] = INFINITY;
    }

    elementgtvalue(N + 1, err1, errTol, &aux);
    elementgtvalue(N + 1, err2, errTol, &aux2);

    creatematrix(N + 1, 6, &x_guess_aux);
    for (i = 0; i < N + 1; i++) {
        for (j = 0; j < 6; j++) {
            x_guess_aux[i][j] = x_guess[i][j];
        }

    }
    while (iter < maxIter && (any(N + 1, aux) == 1 || any(N + 1, aux2) == 1)) {

        //Iter = Iter + 1;
        iter = iter + 1;


        //%disp(['-------- Iteration # ',num2str(Iter),' -----------']);
        //input = {omega2.*tau+omega1,x_guess,varargin{:}};

        //input1 = omega2.*tau+omega1
        double *input1;
        createarray(N + 1, &input1);
        for (i = 0; i < N + 1; i++) {
            input1[i] = omega2 * tau[i] + omega1;
        }

        //F = ode(input{:}).*omega2;
        ode(N + 1, 6, input1, x_guess_aux, varargin, &f);
        for (i = 0; i < N + 1; i++) {
            for (j = 0; j < 6; j++) {
                f[i][j] = f[i][j] * omega2;
            }
        }



        //Beta_r = NaN(size(TV,1),size(F,2));
        //Beta_k = NaN(size(TV,1) + 1, size(F,2));
        //x_new = Beta_k;
        creatematrix(N, 6, &beta_r);
        creatematrix(N + 1, 6, &beta_k);
        creatematrix(N + 1, 6, &new_x);


        //%Matrix Multiply
        //Beta_r(:,i) = TV*F(:,i);
        mult(N, N + 1, N + 1, 6, tv, f, &beta_r);


        //Beta_k(:,i) = [S*Beta_r(:,i) + 2.*x_guess(1,i); Beta_r(:,i)];
        //  S*Beta_r(:,i) + 2.*x_guess(1,i)
        for (j = 0; j < N; j++) {
            //S*Beta_r(:,i)
            double *col;
            createarray(N, &col);
            column(N, j, beta_r, &col);
            double tmp = productarray(N, col, s);
            freearray(col);

            beta_k[0][j] = tmp + 2 * x_guess_aux[0][j];
        }



        //  Beta_r(:,i)
        for (i = 1; i < N + 1; i++) {
            for (j = 0; j < 6; j++) {
                beta_k[i][j] = beta_r[i - 1][j];
            }
        }


        //x_new(:,i) = (Cx*Beta_k(:,i));
        mult(N + 1, N + 1, N + 1, 6, cx, beta_k, &new_x);


        //printmatrix(N, 6, x_guess);
        //err2 = err1;
        //err1 = max(abs(x_new - x_guess),[],2);
        //disp(['Max Error Is found to be: ', num2str(max(err1))]);
        //x_guess = x_new;

        for (i = 0; i < N + 1; i++) {
            err2[i] = err1[i];
            err1[i] = fabs(new_x[i][0] - x_guess_aux[i][0]);
            for (j = 0; j < 6; j++) {
                if (err1[i] < fabs(new_x[i][j] - x_guess_aux[i][j]))
                    err1[i] = fabs(new_x[i][j] - x_guess_aux[i][j]);
                x_guess_aux[i][j] = new_x[i][j];
            }

        }
        elementgtvalue(N + 1, err1, errTol, &aux);
        elementgtvalue(N + 1, err2, errTol, &aux2);

        // Free memory
        freearray(input1);
        freematrix(N, beta_r);
        freematrix(N + 1, beta_k);
        freematrix(N + 1, new_x);
    }


    *rvPCM = x_guess_aux;

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

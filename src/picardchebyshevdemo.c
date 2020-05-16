/**
 * @file picardchebyshevdemo.c
 * @author Fermin Jimenez
 */

#include "picardchebyshevdemo.h"
#include "matlab.h"
#include "kepleruniversal.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// PicardChebyshevDemo
//------------------------------------------------------------------------------
/**
 * Demo function used to demonstrate how to use the Picard-Chebyshev method
 * This will propagate an orbit a total of
 * one period and compare the
 * solution to the analytical solution using kepler universal variable
 * propagation.
 * @note PicardChebyshevDemo function - original file picardchebyshevdemo.m
 */
//------------------------------------------------------------------------------
void PicardChebyshevDemo() {
    double **v, **r, **r0m, **v0m;
    double *r0, *v0, *aux, *aux1, *tSpan, *tau, *t;
    double mu, a, vMag, P, NoisePrct, omega1, omega2, errTol;
    int *mm;
    int i, N;


    createarray(3, &aux);

    mu = 398600.4415;

    // r0 = [7000,0,0];
    createarray(3, &r0);
    r0[0] = 7000;
    r0[1] = 0;
    r0[2] = 0;

    // v0 = [0,sqrt(mu./sqrt(sum(r0.^2))),0];
    applyfuntwoargs(pow, 2, r0, 3, &aux);
    createarray(3, &v0);
    v0[0] = 0;
    v0[1] = sqrt(mu / sqrt(sumarray(3, aux)));
    v0[2] = 0;

    // a = sqrt(sum(r0.^2));
    a = sqrt(sumarray(3, aux));

    //vMag = sqrt(sum(v0.^2));
    applyfuntwoargs(pow, 2, v0, 3, &aux);
    vMag = sqrt(sumarray(3, aux));

    // P = 2*pi*sqrt((a^3)/mu);    %period in seconds
    P = 2 * M_PI * sqrt(pow(a, 3) / mu);

    // tSpan = [0 P*2];

    createarray(2, &tSpan);
    tSpan[0] = 0;
    tSpan[1] = P * 2;

    //%Set up the inputs needed to run the Picard-Chebyshev Method
    // N = 50;
    N = 50;

    // NoisePrct = 0.25;
    NoisePrct = 0.25;

    // tau = fliplr(cos((0:N).*pi./N));
    freearray(aux);
    createarray(N + 1, &aux);
    createarray(N + 1, &tau);

    for (i = 0; i < N + 1; i++) {
        aux[i] = i * (M_PI / N);
    }

    applyfunonearg(cos, aux, N + 1, &aux);
    fliplr(N + 1, aux, &tau);


    // omega1 = (tSpan(end)+tSpan(1))/2;
    // omega2 = (tSpan(end)-tSpan(1))/2;

    omega1 = (tSpan[1] + tSpan[0]) / 2;
    omega2 = (tSpan[1] - tSpan[0]) / 2;


    // t = omega2.*tau + omega1;

    createarray(N + 1, &t);
    for (i = 0; i < N + 1; i++) {
        t[i] = (omega2 * tau[i]) + omega1;
    }

    errTol = 1e-6;

    // Run the analytic orbit propagator routine
    // [rA,vA] = keplerUniversal(repmat(r0',[1 length(t)]),repmat(v0',[1 length(t)]),t,mu);

    creatematrix(3, 1, &r);
    creatematrix(3, 1, &v);
    creatematrix(3, N + 1, &r0m);
    creatematrix(3, N + 1, &v0m);

    // Fill r0m
    arrtocolum(3, r0, &r);
    repmat(3, 1, r, 1, N + 1, &r0m);

    // Fill v0m
    arrtocolum(3, v0, &v);
    repmat(3, 1, v, 1, N + 1, &v0m);
    printmatrix(3, N + 1, v0m);

    mm = 0;
    KeplerUniversal(N + 1, r0m, v0m, t, mu, r, v, mm);

    printf("%s", "Fin");
}

//------------------------------------------------------------------------------
// TwoBodyForceModel
//------------------------------------------------------------------------------
/**
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <t>  [1 x N]
 * @param[in] <posvel>  [N x M]
 * @param[in] <mu>
 * @param[out] <eta>  [N x M]
 * @param[out] <nn> number of rows
 * @param[out] <mm> number of columns
 */
void TwoBodyForceModel(int n, int m, double **t, double **posvel, double mu, double *eta, int *nn, int *mm) {

}

//------------------------------------------------------------------------------
// PlotPostionAndVelocity
//------------------------------------------------------------------------------
/**
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <rvPCM>  [N x M]
 * @param[in] <rA>  [N x M]
 * @param[in] <vA>  [N x M]
 * @param[in] <vMag>
 * @param[in] <a>
 * @param[in] <t>  [1 x N]
 * @param[in] <xg>  [N x M]
 */
//------------------------------------------------------------------------------
void PlotPostionAndVelocity(int n, int m, double **rvPCM, double **rA, double **vA, double vMag, double a, double **t,
                            double **xg) {

}
//------------------------------------------------------------------------------
// PlotMagnitudeErrors
//------------------------------------------------------------------------------
/**
 * @param[in] <n> number of rows
 * @param[in] <t>  [1 x N]
 * @param[in] <PosErr>  [N x 1]
 * @param[in] <VelErr>  [N x 1]
 */
//------------------------------------------------------------------------------
void PlotMagnitudeErrors(int n, double **t, double **PosErr, double **VelErr) {

}

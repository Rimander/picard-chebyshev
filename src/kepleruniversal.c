/**
 * @file kepleruniversal.c
 * @author Fermin Jimenez
 */
#include "kepleruniversal.h"
#include "matlab.h"
#include <math.h>
#include <stdbool.h>



//------------------------------------------------------------------------------
// KeplerUniversal
//------------------------------------------------------------------------------
/**
 * Purpose: Most effecient way to propagate any type of two body orbit using kepler's equations.
 *
 * @param[in] <N> number of cols
 * @param[in] <r0> position  in ECI coordinate frame of reference. [3 x M]
 * @param[in] <v0> velocity  in ECI coordinate frame of reference. [3 x M]
 * @param[in] <t> time  in seconds [1 x M]
 * @param[in] <mu> gravitational Constant Defaults to Earth if not specified
 * @param[out] <r> Final position  in ECI [3 x M]
 * @param[out] <v> Final velocity  in ECI [3 x M]
 * @param[out] <mm> number of cols
 *
 * @note keplerUniversal function - original file keplerUniversal.m
 */
//------------------------------------------------------------------------------
void KeplerUniversal(int N, double **r0, double **v0, double *t, double mu, double ***r, double ***v, int *mm) {
    double **h, **aux, **aux1;
    double *v0Mag, *r0Mag, *alpha, *X0, *idx, *hMag, *p, *s, *w, *a, *auxarr;
    int i, j;

    double tol = 1e-9;

    creatematrix(3, N + 1, &aux);
    creatematrix(3, N + 1, &aux1);

    createarray(N + 1, &auxarr);

    //v0Mag = sqrt(sum(v0.^2,1));
    createarray(N + 1, &v0Mag);
    applyfuntwoargsmatrix(pow, 2, v0, 3, N + 1, &aux);
    summatrix(3, N + 1, aux, &v0Mag);
    applyfunonearg(sqrt, v0Mag, N + 1, &v0Mag);

    //r0Mag = sqrt(sum(r0.^2,1));
    createarray(N + 1, &r0Mag);
    applyfuntwoargsmatrix(pow, 2, r0, 3, N + 1, &aux);
    summatrix(3, N + 1, aux, &r0Mag);
    applyfunonearg(sqrt, r0Mag, N + 1, &r0Mag);


    //alpha = -(v0Mag.^2)./mu + 2./r0Mag;
    createarray(N + 1, &alpha);

    for (i = 0; i < N + 1; i++) {
        alpha[i] = -pow(v0Mag[i], 2) / mu + 2 / r0Mag[i];
    }

    //%% Compute initial guess (X0) for Newton's Method
    //X0 = NaN(size(t));
    createarray(N + 1, &X0);


    //%Check if there are any Eliptic/Circular orbits
    //idx = alpha > 0.000001;
    createarray(N + 1, &idx);
    elementgtvalue(N + 1, alpha, 0.000001, &idx);

    //if any(idx)
    //  X0(idx) = sqrt(mu).*t(idx).*alpha(idx);
    //end
    if (any(N + 1, idx) == 1) {
        for (i = 0; i < N + 1; i++) {
            if (idx[i] == 1) {
                X0[i] = sqrt(mu) * t[i] * alpha[i];
            }
        }
    }

    //%Check if there are any Parabolic orbits
    //idx = abs(alpha) < 0.000001;
    elementltvalueabs(N + 1, alpha, 0.000001, &idx);

    //if any(idx)
    if (any(N + 1, idx) == 1) {
        //h = cross(r0(:,idx),v0(:,idx));
        truevalues(3, N + 1, r0, idx, &aux);
        truevalues(3, N + 1, v0, idx, &aux1);

        creatematrix(3, N + 1, &h);
        cross(3, N + 1, aux, aux1, &h);

        //hMag = sqrt(sum(h.^2,1));
        createarray(N + 1, &hMag);
        summatrix(3, N + 1, h, &hMag);
        applyfunonearg(sqrt, hMag, N + 1, &hMag);

        //p = (hMag.^2)./mu;
        createarray(N + 1, &p);
        applyfuntwoargs(pow, 2, hMag, N + 1, &p);
        for (i = 0; i < N + 1; i++) {
            p[i] = p[i] / mu;
        }

        //s = acot(3.*sqrt(mu./(p.^3)).*t(idx))./2;
        createarray(N + 1, &s);
        for (i = 0; i < N + 1; i++) {
            s[i] = (1 / (1 / tan(3 * sqrt(mu / pow(p[i], 3))))) * t[i] / 2;
        }

        //w = atan(tan(s).^(1/3));
        createarray(N + 1, &w);
        for (i = 0; i < N + 1; i++) {
            w[i] = atan(pow(tan(s[i]), 1 / 3));
        }

        //X0(idx) = sqrt(p).*2.*cot(2.*w);
        for (i = 0; i < N + 1; i++) {
            if (idx[i] == 1) {
                w[i] = sqrt(p[i]) * 2 * (1 / tan(2 * w[i]));
            }
        }

        freematrix(3, h);
        freearray(hMag);
        freearray(p);
        freearray(s);
        freearray(w);
    }
    //

    //%Check if there are any Parabolic orbits
    //idx = abs(alpha) < 0.000001;
    elementltvalueabs(N + 1, alpha, -0.000001, &idx);

    //if any(idx)
    if (any(N + 1, idx) == 1) {
        //a = 1./alpha(idx);
        createarray(N + 1, &a);
        for (i = 0; i < N + 1; i++) {
            if (idx[i] == 1) {
                a[i] = 1 / alpha[i];
            }
        }

        //X0(idx) = sign(t(idx)).*sqrt(-a).*...
        //           log(-2.*mu.*alpha(idx).*t(idx)./ ...
        //           (dot(r0(:,idx),v0(:,idx))+sign(t(idx)).*sqrt(-mu.*a).*...
        //           (1-r0Mag(idx).*alpha(idx))));

        // aux - v0
        // aux1 - r0
        for (j = 0; j < N + 1; j++) {

            // Columns
            for (i = 0; i < 3; i++) {
                aux[i][j] = idx[i] == 1 ? v0[i][j] : 0;
                aux1[i][j] = idx[i] == 1 ? r0[i][j] : 0;
            }
        }

        dot(3, N + 1, aux, aux1, &auxarr);

        for (i = 0; i < N + 1; i++) {
            if (idx[i] == 1) {

                double alphaidx = idx[i] == 1 ? alpha[i] : 0;
                double tidx = idx[i] == 1 ? t[i] : 0;
                double r0Magidx = r0Mag[i] == 1 ? t[i] : 0;

                X0[i] = sign(t[i]) * sqrt(-a[i]) * log(-2 * mu * alphaidx * tidx / (auxarr[i] +
                                                                                    sign(tidx) * sqrt(-mu * a[i]) *
                                                                                    (1 - r0Magidx * alphaidx)));

            }
        }

        printarray(N + 1, X0);
        freearray(a);
    }


}

//------------------------------------------------------------------------------
// C2c3
//------------------------------------------------------------------------------
/**
 * @param[in] <m> number of cols
 * @param[in] <psi>  [1 X M]
 * @param[out] <c2>  [1 X M]
 * @param[out] <c3>  [1 X M]
 * @param[out] <mm> number of cols
 *
 * @note c2c3 function - original file keplerUniversal.m
 */
//------------------------------------------------------------------------------
void C2c3(int m, double *psi, double *c2, double *c3, int *mm) {

}
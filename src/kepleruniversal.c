/**
 * @file kepleruniversal.c
 * @author Fermin Jimenez
 */
#include "kepleruniversal.h"
#include "matlab.h"
#include <math.h>
#include <stdbool.h>
#include <float.h>



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
    double *dr0v0Smu, *Smut, *err, *X02, *X03, *psi, *c2, *c3, *Xn, *X0tOmPsiC3, *X02tC2, *rTmp, *f, *g, *fdot, *gdot;

    int i, j;

    double tol = 1e-9;

    double **rReturn = *r;
    double **vReturn = *v;

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
    elementltvalue(N + 1, alpha, -0.000001, &idx);

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

        freearray(a);
    }


    // err = Inf;
    createarray(N + 1, &err);
    for (i = 0; i < N + 1; i++) {
        err[i] = DBL_MAX;
    }

    //dr0v0Smu = dot(r0,v0)./sqrt(mu);
    createarray(N + 1, &dr0v0Smu);
    dot(3, N + 1, r0, v0, &dr0v0Smu);
    for (i = 0; i < N + 1; i++) {
        dr0v0Smu[i] = dr0v0Smu[i] / sqrt(mu);
    }

    //Smut = sqrt(mu).*t;
    createarray(N + 1, &Smut);
    for (i = 0; i < N + 1; i++) {
        Smut[i] = sqrt(mu) * t[i];
    }

    //while any(abs(err) > tol)
    createarray(N + 1, &X02);
    createarray(N + 1, &X03);
    createarray(N + 1, &psi);
    createarray(N + 1, &c2);
    createarray(N + 1, &c3);
    createarray(N + 1, &X0tOmPsiC3);
    createarray(N + 1, &X02tC2);
    createarray(N + 1, &rTmp);
    createarray(N + 1, &Xn);

    elementgtvalueabs(N + 1, err, tol, &auxarr);
    while (any(N + 1, auxarr) == 1) {
        //X02 = X0.^2;
        //X03 = X02.*X0;
        //psi = X02.*alpha;
        //[c2,c3] = c2c3(psi);
        //X0tOmPsiC3 = X0.*(1-psi.*c3);
        //X02tC2 = X02.*c2;
        //r = X02tC2 + dr0v0Smu.*X0tOmPsiC3 + r0Mag.*(1-psi.*c2);
        //Xn = X0 + (Smut-X03.*c3-dr0v0Smu.*X02tC2-r0Mag.*X0tOmPsiC3)./r;
        //err = Xn-X0; X0 = Xn;
        for (i = 0; i < N + 1; i++) {
            X02[i] = pow(X0[i], 2);
            X03[i] = X02[i] * X0[i];
            psi[i] = X02[i] * alpha[i];
            C2c3(psi[i], &c2[i], &c3[i]);
            X0tOmPsiC3[i] = X0[i] * (1 - psi[i] * c3[i]);
            X02tC2[i] = X02[i] * c2[i];
            rTmp[i] = X02tC2[i] + dr0v0Smu[i] * X0tOmPsiC3[i] + r0Mag[i] * (1 - psi[i] * c2[i]);
            Xn[i] = X0[i] + (Smut[i] - X03[i] * c3[i] - dr0v0Smu[i] * X02tC2[i] - r0Mag[i] * X0tOmPsiC3[i]) / rTmp[i];
            err[i] = Xn[i] - X0[i];
            X0[i] = Xn[i];
        }
        elementgtvalueabs(N + 1, err, tol, &auxarr);
    }


    //f = 1 - (Xn.^2).*c2./r0Mag;
    //g = t - (Xn.^3).*c3./sqrt(mu);
    //gdot = 1 - c2.*(Xn.^2)./r;
    //fdot = Xn.*(psi.*c3-1).*sqrt(mu)./(r.*r0Mag);
    createarray(N + 1, &f);
    createarray(N + 1, &fdot);
    createarray(N + 1, &g);
    createarray(N + 1, &gdot);
    for (i = 0; i < N + 1; i++) {
        f[i] = 1 - pow(Xn[i], 2) * c2[i] / r0Mag[i];
        g[i] = t[i] - pow(Xn[i], 3) * c3[i] / sqrt(mu);
        gdot[i] = 1 - c2[i] * pow(Xn[i], 2) / rTmp[i];
        fdot[i] = Xn[i] * (psi[i] * c3[i] - 1) * sqrt(mu) / (rTmp[i] * r0Mag[i]);
    }


    //a = bsxfun(@times,f,r0);
    times(3, N + 1, f, r0, &aux);

    //r = bsxfun(@times,f,r0) + bsxfun(@times,g,v0);
    times(3, N + 1, g, v0, &aux1);
    sum(3, N + 1, aux, aux1, &rReturn);

    //v = bsxfun(@times,fdot,r0) + bsxfun(@times,gdot,v0);
    times(3, N + 1, fdot, r0, &aux);
    times(3, N + 1, gdot, v0, &aux1);
    sum(3, N + 1, aux, aux1, &vReturn);

    freearray(X02);
    freearray(X03);
    freearray(psi);
    freearray(c2);
    freearray(c3);
    freearray(X0tOmPsiC3);
    freearray(X02tC2);
    freearray(rTmp);
    freearray(Xn);
    freearray(f);
    freearray(fdot);
    freearray(g);
    freearray(gdot);
    freearray(v0Mag);
    freearray(r0Mag);

    //%% Ensure Solution Integrity
    //%idx = round((f.*gdot - fdot.*g)./tol).*tol ~= 1; r(:,idx) = NaN; v(:,idx) = NaN;
}

//------------------------------------------------------------------------------
// C2c3
//------------------------------------------------------------------------------
/**
 * @param[in] <psi>
 * @param[out] <c2>
 * @param[out] <c3>
 *
 */
//------------------------------------------------------------------------------
void C2c3(double psi, double *c2, double *c3) {
    if (psi > 1e-6) {
        *c2 = (1 - cos(sqrt(psi))) / psi;
        *c3 = (sqrt(psi) - sin(sqrt(psi))) / sqrt(pow(psi, 3));
    }
    if (psi < -1e-6) {
        *c2 = (1 - cosh(sqrt(-psi))) / psi;
        *c3 = (sinh(sqrt(-psi)) - sqrt(-psi)) / sqrt(pow(-psi, 3));
    }
    if (fabs(psi) <= 1e-6) {
        *c2 = 0.5;
        *c3 = 1 / 6.0;
    }
}
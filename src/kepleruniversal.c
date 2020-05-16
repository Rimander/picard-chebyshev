/**
 * @file kepleruniversal.c
 * @author Fermin Jimenez
 */
#include "kepleruniversal.h"



//------------------------------------------------------------------------------
// KeplerUniversal
//------------------------------------------------------------------------------
/**
 * Purpose: Most effecient way to propagate any type of two body orbit using kepler's equations.
 *
 * @param[in] <m> number of cols
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
void KeplerUniversal(int m, double **r0, double **v0, double *t, double mu, double **r, double **v, int *mm) {
    double *V0Mag;
    double N = 50;

    double tol = 1e-9;

    //v0Mag = sqrt(sum(v0.^2,1));
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
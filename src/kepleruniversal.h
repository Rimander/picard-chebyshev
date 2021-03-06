/**
 * @file kepleruniversal.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_KEPLERUNIVERSAL_H
#define CODIGO_KEPLERUNIVERSAL_H



//------------------------------------------------------------------------------
// KeplerUniversal
//------------------------------------------------------------------------------
/**
 * Purpose: Most effecient way to propagate any type of two body orbit using kepler's equations.
 *
 * @param[in] <N> number of cols
 * @param[in] <r0> position in ECI coordinate frame of reference. [3 x M]
 * @param[in] <v0> velocity in ECI coordinate frame of reference. [3 x M]
 * @param[in] <t> time in seconds [1 x M]
 * @param[in] <mu> gravitational Constant Defaults to Earth if not specified
 * @param[out] <r> Final position in ECI [3 x M]
 * @param[out] <v> Final velocity in ECI [3 x M]
 * @param[out] <mm> number of cols
 *
 * @note keplerUniversal function - original file keplerUniversal.m
 */
//------------------------------------------------------------------------------
void KeplerUniversal(int N, double **r0, double **v0, double *t, double mu, double ***r, double ***v, int *mm);

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
void C2c3(double psi, double *c2, double *c3);

#endif //CODIGO_KEPLERUNIVERSAL_H

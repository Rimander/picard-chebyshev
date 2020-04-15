/**
 * @file kepleruniversal.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_KEPLERUNIVERSAL_H
#define CODIGO_KEPLERUNIVERSAL_H



//------------------------------------------------------------------------------
// function KeplerUniversal
//------------------------------------------------------------------------------
/**
 * Purpose: Most effecient way to propagate any type of two body orbit using kepler's equations.
 *
 * @param[in] <m> int the number of cols
 * @param[in] <r0> position Vector in ECI coordinate frame of reference. [3 x M]
 * @param[in] <v0> velocity Vector in ECI coordinate frame of reference. [3 x M]
 * @param[in] <t> time Vector in seconds [1 x M]
 * @param[in] <mu> gravitational Constant Defaults to Earth if not specified
 * @param[out] <r> Final position vector in ECI [3 x M]
 * @param[out] <v> Final velocity vector in ECI [3 x M]
 * @param[out] <mm> int the number of cols
 *
 * @note keplerUniversal function - original file keplerUniversal.m
 */
//------------------------------------------------------------------------------
void KeplerUniversal(double m, double **r0, double **v0, double *t, double mu, double **r, double **v, double *mm);

//------------------------------------------------------------------------------
// function C2c3
//------------------------------------------------------------------------------
/**
 * @param[in] <m> int the number of cols
 * @param <psi> Vector double [1 X M]
 * @param[out] <c2> Vector double [1 X M]
 * @param[out] <c3> Vector double [1 X M]
 * @param[out] <mm> int the number of cols
 *
 * @note c2c3 function - original file keplerUniversal.m
 */
//------------------------------------------------------------------------------
void C2c3(double m, double psi, double *c2, double *c3, double *mm);

#endif //CODIGO_KEPLERUNIVERSAL_H

/**
 * @file keplerUniversal.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_KEPLERUNIVERSAL_H
#define CODIGO_KEPLERUNIVERSAL_H

/**
 * Purpose: Most effecient way to propagate any type of two body orbit using kepler's equations.
 *
 * @param <r0> position Vector in ECI coordinate frame of reference. [3 x N]
 * @param <v0> velocity Vector in ECI coordinate frame of reference. [3 x N]
 * @param <t> time Vector in seconds [1 x N]
 * @param <mu> gravitational Constant Defaults to Earth if not specified
 * @param <r> output parameter, Final position vector in ECI [3 x N]
 * @param <v> output parameter, Final velocity vector in ECI [3 x N]
 *
 * @note keplerUniversal function - file keplerUniversal.m
 */
void keplerUniversal(double **r0, double **v0, double **t, double mu, double **r, double **v);

/**
 *
 * @param <psi> input psi parameter.
 * @param <c2> output parameter to c2.
 * @param <c3> output parameter to c3.
 *
 * @note c2c3 function - file keplerUniversal.m
 */
void c2c3(double psi, double *c2, double *c3);

#endif //CODIGO_KEPLERUNIVERSAL_H

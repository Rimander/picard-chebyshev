/**
 * @file picardchebyshevdemo.c€
 * @author Fermin Jimenez
 */
#include "picardchebyshevdemo.h"


/**
 * Demo function used to demonstrate how to use the Picard-Chebyshev method
 * This will propagate an orbit a total of one period and compare the
 * solution to the analytical solution using kepler universal variable
 * propagation.
 * @note PicardChebyshevDemo function - original file picardchebyshevdemo.m
 */
void PicardChebyshevDemo() {

}

/**
 * @param <t> Vector double [1 x N]
 * @param <posvel> Vector double [N x M]
 * @param <mu> double
 */
void TwoBodyForceModel(double **t, double **posvel, double mu) {

}

/**
 * @param <rvPCM> Vector double [N x M]
 * @param <rA> Vector double [N x M]
 * @param <vA> Vector double [N x M]
 * @param <vMag> double
 * @param <a> double
 * @param <t> Vector double [1 x N]
 * @param <xg> Vector double [N x M]
 *
 */
void PlotPostionAndVelocity(double **rvPCM, double **rA, double **vA, double vMag, double a, double **t, double **xg) {

}

/**
 * @param <t> Vector double [1 x N]
 * @param <PosErr> Vector double [N x 1]
 * @param <VelErr> Vector double [N x 1]
 */
void PlotMagnitudeErrors(double **t, double **PosErr, double **VelErr) {

}

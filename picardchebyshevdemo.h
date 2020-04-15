/**
 * @file picardchebyshevdemo.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_PICARDCHEBYSHEVDEMO_H
#define CODIGO_PICARDCHEBYSHEVDEMO_H

//------------------------------------------------------------------------------
// function PicardChebyshevDemo
//------------------------------------------------------------------------------
/**
 * Demo function used to demonstrate how to use the Picard-Chebyshev method
 * This will propagate an orbit a total of one period and compare the
 * solution to the analytical solution using kepler universal variable
 * propagation.
 * @note PicardChebyshevDemo function - original file picardchebyshevdemo.m
 */
//------------------------------------------------------------------------------
void PicardChebyshevDemo();

//------------------------------------------------------------------------------
// function TwoBodyForceModel
//------------------------------------------------------------------------------
/**
 * @param[in] <n> int number of rows
 * @param[in] <m> int number of columns
 * @param[in] <t> Vector double [1 x N]
 * @param[in] <posvel> Vector double [N x M]
 * @param[in] <mu> double
 * @param[out] <eta> Vector double [N x M]
 * @param[out] <nn> int number of rows
 * @param[out] <mm> int number of columns
 */
void TwoBodyForceModel(int n, int m, double **t, double **posvel, double mu, double *eta, int *nn, int *mm);

//------------------------------------------------------------------------------
// function PlotPostionAndVelocity
//------------------------------------------------------------------------------
/**
 * @param[in] <n> int number of rows
 * @param[in] <m> int number of columns
 * @param[in] <rvPCM> Vector double [N x M]
 * @param[in] <rA> Vector double [N x M]
 * @param[in] <vA> Vector double [N x M]
 * @param[in] <vMag> double
 * @param[in] <a> double
 * @param[in] <t> Vector double [1 x N]
 * @param[in] <xg> Vector double [N x M]
 */
//------------------------------------------------------------------------------
void PlotPostionAndVelocity(int n, int m, double **rvPCM, double **rA, double **vA, double vMag, double a, double **t,
                            double **xg);
//------------------------------------------------------------------------------
// function PlotMagnitudeErrors
//------------------------------------------------------------------------------
/**
 * @param[in] <n> int number of rows
 * @param[in] <t> Vector double [1 x N]
 * @param[in] <PosErr> Vector double [N x 1]
 * @param[in] <VelErr> Vector double [N x 1]
 */
//------------------------------------------------------------------------------
void PlotMagnitudeErrors(int n, double **t, double **PosErr, double **VelErr);

#endif //CODIGO_PICARDCHEBYSHEVDEMO_H
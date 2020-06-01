/**
 * @file picardchebyshevdemo.h
 * @author Fermin Jimenez
 */

#ifndef CODIGO_PICARDCHEBYSHEVDEMO_H
#define CODIGO_PICARDCHEBYSHEVDEMO_H

//------------------------------------------------------------------------------
// PicardChebyshevDemo
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
// TwoBodyForceModel
//------------------------------------------------------------------------------
/**
 * @param[in] <n> number of rows
 * @param[in] <m> number of columns
 * @param[in] <t>  [N]
 * @param[in] <posvel>  [N x M]
 * @param[in] <mu>
 * @param[out] <eta>  [N x M]
 */
void TwoBodyForceModel(int n, int m, double *t, double **posvel, double mu, double ***eta);

//------------------------------------------------------------------------------
// PlotPostionAndVelocity
//------------------------------------------------------------------------------
/**
 * @param[in] <m> number
 * @param[in] <rvPCM>  [M x 6]
 * @param[in] <rA>  [3 x M]
 * @param[in] <vA>  [3 x M]
 * @param[in] <vMag>
 * @param[in] <a>
 * @param[in] <t>  [M]
 * @param[in] <xg>  [M x 6]
 */
//------------------------------------------------------------------------------
void PlotPostionAndVelocity(int m, double **rvPCM, double **rA, double **vA, double vMag, double a, double *t,
                            double **xg);

//------------------------------------------------------------------------------
// PlotMagnitudeErrors
//------------------------------------------------------------------------------
/**
 * @param[in] <n> number of rows
 * @param[in] <t>  [N]
 * @param[in] <PosErr>  [N]
 * @param[in] <VelErr>  [N]
 */
//------------------------------------------------------------------------------
void PlotMagnitudeErrors(int n, double *t, double *PosErr, double *VelErr);

#endif //CODIGO_PICARDCHEBYSHEVDEMO_H
/* This file is automatically generated. DO NOT EDIT! */

#ifndef _rweone_h
#define _rweone_h


#include <rsf.h>


void rweone_init(
    sf_axis ag_,
    sf_axis at_,
    sf_axis aw_,
    sf_axis ar_,
    int method_,
    bool verb_);
/*< initialize >*/


void rweone_fk(
    float w,
    sf_complex *ddd,
    float *aa,
    float *a0,
    float *b0,
    float *mm,
    int it);
/*< one F-K extrapolation step >*/


void rweone_fx(
    float w,
    sf_complex *ddd,
    float *aa,
    int it);
/*< one F-X extrapolation step >*/


void rweone_xfd_coef(
    float **aa,
    float **bb);
/*< XFD coefficients >*/


void rweone_ffd_coef(
    float **aa,
    float **bb,
    float **a0,
    float **b0);
/*< FFD coefficients >*/


void rweone_psc_coef(
    float **aa,
    float **bb,
    float **a0,
    float **b0);
/*< PSC coefficients >*/


void rweone_phs_old(
    sf_complex *v,
    float w,
    float a0,
    float b0
    );
/*< Fourier-domain phase shift >*/


void rweone_phs(
    sf_complex *v,
    float w,
    float a0,
    float b0
    );
/*< Fourier-domain phase shift >*/


void rweone_ssf(
    sf_complex *v,
    float w,
    float *aa,
    float  a0);
/*< split-step Fourier correction >*/


void rweone_ssh(
    sf_complex *v,
    float w,
    float *aa);
/*< space-domain phase shift >*/


void rweone_fds(
    sf_complex *v,
    float w,
    int it,
    int ir);
/*< finite-differences solver >*/


void rweone_thr(
    sf_complex *a,
    sf_complex *b,
    sf_complex *c,
    sf_complex *v,
    int n);
/*< tridiagonal solver >*/


void rweone_tap_init();
/*< initialize taper >*/


void rweone_tap(sf_complex *v);
/*< apply taper >*/


void rweone_fft_init(int n);
/*< init FFT >*/


void rweone_fft(
    bool inv,
    kiss_fft_cpx *d);
/*< apply FFT >*/


void rweone_mrs_init();
/*< init MRS >*/


void rweone_mrs(
    sf_complex *v,
    sf_complex *d,
    float *m,
    int ir);
/*< combine MRS >*/


void rweone_zoi(
    bool        adj,
    sf_complex *ddd,
    float      *iii);
/*< zero-offset imaging condition >*/


void rweone_spi(
    sf_complex *swf,
    sf_complex *rwf,
    float         *iii);
/*< shot-record imaging condition >*/

#endif
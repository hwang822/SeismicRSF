/* This file is automatically generated. DO NOT EDIT! */

#ifndef _cbanded_h
#define _cbanded_h


#include <rsf.h>


void cbanded_init (int n_in    /* matrix size */, 
		   int band_in /* band width */);
/*< Initialize >*/


void cbanded_const_define (float diag             /* diagonal */, 
			   const sf_complex *offd /* lower off-diagonal */);
/*< set matrix coefficients (constant along diagonals) >*/


void cbanded_define (const float *diag    /* diagonal */, 
		     sf_complex **offd /* lower subdiagonals */);
/*< set matrix coefficients >*/


void cbanded_solve (sf_complex *b);
/*< multiply by inverse (in place) >*/


void cbanded_close (void);
/*< free allocated storage >*/

#endif

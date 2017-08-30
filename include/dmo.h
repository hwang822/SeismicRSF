/* This file is automatically generated. DO NOT EDIT! */

#ifndef _dmo_h
#define _dmo_h


#include <rsf.h>


void dmo_init (float vel1 /* velocity */, 
	       bool inv1  /* inversion flag */, 
	       float t01  /* time orgin */, 
	       float dt1  /* time sampling */, 
	       float dx1  /* midpoint sampling */,
	       int nt1    /* time samples */, 
	       int nx1    /* midpoint samples */, 
	       int mint1  /* minimum time */, 
	       int n1     /* operator sampling */, 
	       int type1  /* amplitude type */);
/*< Initialize >*/


void dmo_set(float h1 /* half-offset */);
/*< set offset >*/


void dmo_close(void);
/*< free allocated storage >*/


void dmo_lop (bool adj, bool add, int n1, int n2, float *dat1, float *dat2);
/*< linear operator >*/

#endif

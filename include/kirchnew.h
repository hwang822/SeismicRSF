/* This file is automatically generated. DO NOT EDIT! */

#ifndef _kirchnew_h
#define _kirchnew_h


#include <rsf.h>


void kirchnew_init (float *vrms_in /* RMS velocity */, 
		    float t0_in    /* time origin */, 
		    float dt_in    /* time sampling */, 
		    float dx_in    /* midpoint sampling */, 
		    int nt_in      /* time samples */, 
		    int nx_in      /* midpoint samples */, 
		    int sw_in      /* branch to compute */,
		    bool ps_in     /* pseudo-unitary weight */,
		    bool hd_in     /* hald-derivative filter */);
/*< Initialize >*/


void kirchnew_close (void);
/*< Free allocated storage >*/


void kirchnew_lop (bool adj, bool add, int nm, int nd, 
		   float *modl, float *data);
/*< Apply >*/

#endif

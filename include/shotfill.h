/* This file is automatically generated. DO NOT EDIT! */

#ifndef _shotfill_h
#define _shotfill_h


#include <rsf.h>


void shotfill_init (int nh_in, float h0, float dh /* half-offset axis */, 
		    float ds                      /* shot sampling */, 
		    float eps1                    /* regularization */);
/*< initialize >*/


void shotfill_close (void);
/*< free allocated storage >*/


void shotfill_define (float w /* log-stretch frequency */);
/*< Fill the shot continuation matrix >*/


void shotprop_define (float w /* log-stretch frequency */);
/*< Fill the shot propagation matrix >*/


void shotfill_apply (const sf_complex *s1, 
		     const sf_complex *s2 /* input shots [nh] */, 
		     sf_complex *s        /* interpolated shot [nh] */);
/*< interpolate a shot gather >*/


void shotprop_apply (const sf_complex *s1 /* input shot [nh] */,  
		     sf_complex *s        /* propagated shot [nh] */);
/*< propagate a shot gather >*/

#endif

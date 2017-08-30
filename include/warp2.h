/* This file is automatically generated. DO NOT EDIT! */

#ifndef _warp2_h
#define _warp2_h


void warp2_init(int n1_in, float o1, float d1,
		int n2_in, float o2, float d2 /* output grid */,
		int nt, int nx_in             /* input  grid */,
		float eps                     /* regularization */);
/*< initialize >*/


void warp2_close(void);
/*< free allocated storage >*/


void warp2(float **slice  /* [nx][nt] input */,
	   float **coord1 /* [nx][nt] coordinates */,
	   float **coord2 /* [nx][nt] coordinates */,
	   float **slice2 /* [n2][n1] output */);
/*< apply warping >*/


void fwarp2(float **slice2 /* [n2][n1] input */,
	    float **coord1 /* [nx][nt] coordinates */,
	    float **coord2 /* [nx][nt] coordinates */,
	    float **slice  /* [nx][nt] output */);
/*< apply forward warping >*/

#endif
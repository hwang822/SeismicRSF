/* This file is automatically generated. DO NOT EDIT! */

#ifndef _grid3_h
#define _grid3_h


typedef struct Grid3* grid3;
/* abstract data type */


grid3 grid3_init (int n1, float o1, float d1 /* first axis */, 
		  int n2, float o2, float d2 /* second axis */,
		  int n3, float o3, float d3 /* third axis */,
		  float *slow2               /* data [n1*n2*n3] */, 
		  int order                  /* interpolation order */);
/*< Initialize 3-D grid. >*/


float grid3_vel(void* par /* grid */, 
		float* xy /* location [3] */);
/*< Extract a value from the grid. >*/


void grid3_vgrad(void* par /* grid */, 
		 float* xy /* location [3] */, 
		 float* grad /* output gradient [3] */);
/*< Extract (1/2 of) gradient values from the grid >*/


int grid3_term (void *par /* grid */, 
		float* xy /* location [3] */);
/*< Termination criterion. Returns 0 if xy (data coordinates)
  are inside the grid >*/


void grid3_close(grid3 grd);
/*< Free internal storage >*/

#endif
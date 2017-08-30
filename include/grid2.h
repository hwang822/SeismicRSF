/* This file is automatically generated. DO NOT EDIT! */

#ifndef _grid2_h
#define _grid2_h


typedef struct Grid2* grid2;
/* abstract data type */


grid2 grid2_init (int n1, float o1, float d1 /* first axis */, 
		  int n2, float o2, float d2 /* second axis */,
		  float *slow2               /* data values [n1*n2] */, 
		  int order                  /* interpolation order */);
/*< Initialize grid object >*/


float grid2_vel(void* par /* grid */, 
		float* xy /* coordinate [2] */);
/*<  Extract a value from the grid >*/


void grid2_vgrad(void* par   /* grid */, 
		 float* xy   /* coordinate [2] */, 
		 float* grad /* output gradient [2] */);
/*< Extract (1/2 of) gradient values from the grid >*/


int grid2_term (void* par /* grid */, 
		float* xy /* location [2] */);
/*< Termination criterion. returns 0 if xy (data coordinates)
  are inside the grid >*/


void grid2_close(grid2 grd);
/*< Free internal storage >*/

#endif
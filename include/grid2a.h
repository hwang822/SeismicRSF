/* This file is automatically generated. DO NOT EDIT! */

#ifndef _grid2a_h
#define _grid2a_h


typedef struct Grid2a* grid2a;
/* abstract data type */


grid2a grid2a_init (int n1, float o1, float d1 /* first axis */, 
		    int n2, float o2, float d2 /* second axis */,
		    float *vz2                 /* vertical velocity squared [n1*n2], gets corrupted */, 
		    float *vx2                 /* horizontal velocity squared [n1*n2], vz2 (isotropic) if NULL */, 
		    float *q                   /* nonellipticity [n1*n2], 1 (elliptic) if NULL */,
		    int order                  /* interpolation order */);
/*< Initialize grid object >*/


void grid2a_rhs(void* par /* grid */, 
		float* xy /* coordinate [4] */,
		float* g);
/*< right-hand side for the ray tracing system >*/


int grid2a_term (void* par /* grid */, 
		 float* xy /* location [2] */);
/*< Termination criterion. returns 0 if xy (data coordinates)
  are inside the grid >*/


void grid2a_close(grid2a grd);
/*< Free internal storage >*/

#endif
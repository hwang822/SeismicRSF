/* This file is automatically generated. DO NOT EDIT! */

#ifndef _grid3a_h
#define _grid3a_h


typedef struct Grid3a* grid3a;
/* abstract data type */


grid3a grid3a_init (int n1, float o1, float d1 /* first axis */, 
		    int n2, float o2, float d2 /* second axis */,
		    int n3, float o3, float d3 /* second axis */,
		    float *vz2                 /* vertical velocity squared [n1*n2*n3], gets corrupted */, 
		    float *vx2                 /* horizontal velocity squared [n1*n2*n3], vz2 (isotropic) if NULL */, 
		    float *q                   /* nonellipticity [n1*n2*n3], 1 (elliptic) if NULL */,
		    int order                  /* interpolation order */);
/*< Initialize grid object >*/


void grid3a_rhs(void* par /* grid */, 
		float* xy /* coordinate [6] */,
		float* g  /* right-hand side [6] */);
/*< right-hand side for the ray tracing system >*/


int grid3a_term (void* par /* grid */, 
		 float* xy /* location [3] */);
/*< Termination criterion. returns 0 if xy (data coordinates)
  are inside the grid >*/


void grid3a_close(grid3a grd);
/*< Free internal storage >*/

#endif
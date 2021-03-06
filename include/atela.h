/* This file is automatically generated. DO NOT EDIT! */

#ifndef _atela_h
#define _atela_h


#include <rsf.h>


int atela_step (int dim     /* dimensionality */, 
				int nt      /* number of ray tracing steps */, 
				float dt    /* step in time */, 
				bool intime /* if step in time (not sigma) */, 
				float* x    /* [dim] point location */, 
				float* p    /* [dim] ray parameter vector */,
				void* par   /* parameters for slowness functions */,
				void (*vgrad)(void*,float*,float*) 
				/* function returning 1/2*(gradient of slowness squared) */, 
				float (*slow2)(void*,float*)
				/* function returning slowness squared */, 
				int (*term)(void*,float*)
				/* function returning 1 if the ray needs to terminate */, 
				float** traj /* [nt+1][dim] - ray trajectory (output) */);
/*< ray tracing 
 Note:
 1. Values of x and p are changed inside the function.
 2. The trajectory traj is stored as follows:
 {z0,y0,z1,y1,z2,y2,...} in 2-D
 {z0,y0,x0,z1,y1,x1,...} in 3-D
 3. Vector p points in the direction of the ray. 
 The length of the vector is not important.
 Example initialization:
 p[0] = cos(a); p[1] = sin(a) in 2-D, a is between 0 and 2*pi radians
 p[0] = cos(b); p[1] = sin(b)*cos(a); p[2] = sin(b)*sin(a) in 3-D
 b is inclination between 0 and   pi radians
 a is azimuth     between 0 and 2*pi radians
 4. The output code for it = atela_step(...)
 it=0 - ray traced to the end without termination
 it>0 - ray terminated
 The total traveltime along the ray is 
 nt*dt if (it = 0); abs(it)*dt otherwise 
 >*/

#endif

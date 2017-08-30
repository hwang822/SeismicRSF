/* This file is automatically generated. DO NOT EDIT! */

#ifndef _taper_h
#define _taper_h


void taper2_init(int n2_, int n1_ /* cube dimensions */,
		 int m2_, int m1_ /* taper lengths */,
		 bool b2_, bool b1_);
/*< 2-D initialize >*/


void taper2_close(void);
/*< 2-D free allocated storage >*/


void taper3_init(
    int n3_, 
    int n2_, 
    int n1_ /* cube dimensions */,
    int m3_, 
    int m2_, 
    int m1_ /* taper lengths */,
    bool b3_,
    bool b2_,
    bool b1_);
/*< 3-D initialize >*/


void taper3_close(void);
/*< 2-D free allocated storage >*/


void taper2(sf_complex** tt  /* [n2][n1] tapered array (in and out) */);
/*< 2-D taper >*/


void taper3(sf_complex*** tt /* [n3][n2][n1] tapered array (inout) */);
/*< 3-D taper >*/

#endif
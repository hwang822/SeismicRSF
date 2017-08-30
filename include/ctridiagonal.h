/* This file is automatically generated. DO NOT EDIT! */

#ifndef _ctridiagonal_h
#define _ctridiagonal_h


#include <rsf.h>


typedef struct CTris *ctris;
/* abstract data type */


ctris ctridiagonal_init (int n);
/*< Initialize a solver object for n by n tridiagonal matrix >*/


void ctridiagonal_define (ctris slv, sf_complex* diag, sf_complex* offd);
/*< Fill the matrix with diagonal and off-diagonal elements.
...
The matrix is symmetric but not necessarily self-adjoint.
 >*/


void ctridiagonal_const_define (ctris slv, 
				sf_complex diag, sf_complex offd);
/*< Fill the matrix with constant diagonal and off-diagonal elements.
...
The matrix is symmetric but not necessarily self-adjoint.
>*/


void ctridiagonal_solve (ctris slv, sf_complex* b);
/*< Invert in-place. The right-hand side b is replaced with the solution. >*/


void ctridiagonal_close (ctris slv);
/*< Free allocated storage >*/

#endif

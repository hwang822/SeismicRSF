/* 3-D zero-offset modeling/migration with extended split-step
To be deprecated in favor of zomig3 */

/*
  Copyright (C) 2006 Colorado School of Mines
  Copyright (C) 2004 University of Texas at Austin

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <rsf.h>
#include "zomig.h"

int main (int argc, char *argv[])
{
    const char *mode;     /* mode of operation */
    bool verb;            /* verbosity */
    bool incore;          /* in core execution */
    bool inv;             /* forward or adjoint */
    bool causal;          /* causal/anti-causal flag */
    bool twoway;          /* two-way traveltime */
    float eps;            /* dip filter constant */  
    int   nrmax;          /* number of reference velocities */
    float dtmax;          /* time error */
    int   pmx,pmy;        /* padding in the k domain */
    int   tmx,tmy;        /* boundary taper size */

    sf_axis az,amx,amy,aw,alx,aly,ae;

    int n,nz,nw;
    float dw,ow;

    sf_file Fs=NULL;    /*  slowness file S(nlx,nly,nz   ) */
    sf_file Fi=NULL;    /*     image file R(nmx,nmy,nz   ) */
    sf_file Fd=NULL;    /*      data file D(nmx,nmy,   nw) */
    sf_file Fw=NULL; 

    sf_fslice slow=NULL,imag=NULL,data=NULL,wfld=NULL;

    /*------------------------------------------------------------*/
    sf_init(argc,argv);

    /* default mode is migration/modeling */
    if (NULL == (mode = sf_getstring("mode"))) mode = "m";

    if (!sf_getbool(  "verb",&verb  ))  verb = false; /* verbosity flag */
    if (!sf_getbool("incore",&incore))incore =  true; /* in core execution */
    if (!sf_getfloat(  "eps",&eps   ))   eps =  0.01; /* stability parameter */
    if (!sf_getbool(   "inv",&inv   ))   inv = false; /* y=modeling; n=migration */
    if (!sf_getbool("causal",&causal)) causal= false; /* y=causal; n=anti-causal */
    if (!sf_getbool("twoway",&twoway)) twoway=  true; /* two-way traveltime */
    if (!sf_getint(  "nrmax",&nrmax )) nrmax =     1; /* maximum references */
    if (!sf_getfloat("dtmax",&dtmax )) dtmax = 0.004; /* time error */
    if (!sf_getint(    "pmx",&pmx   ))   pmx =     0; /* padding on x */
    if (!sf_getint(    "pmy",&pmy   ))   pmy =     0; /* padding on y*/
    if (!sf_getint(    "tmx",&tmx   ))   tmx =     0; /* taper on x*/
    if (!sf_getint(    "tmy",&tmy   ))   tmy =     0; /* taper on y */

    /* slowness parameters */
    Fs  = sf_input ("slo");
    alx = sf_iaxa(Fs,1); sf_setlabel(alx,"lx");
    aly = sf_iaxa(Fs,2); sf_setlabel(aly,"ly");
    az  = sf_iaxa(Fs,3); sf_setlabel(az ,"z" );

    n = sf_n(alx)*sf_n(aly);
    nz = sf_n(az);

    slow = sf_fslice_init(n,nz,sizeof(float));
    sf_fslice_load(Fs,slow,SF_FLOAT);
    
    switch(mode[0]) {
	case 'w': /* save wavefield */
	    Fd = sf_input ( "in");
	    Fw = sf_output("out"); sf_settype(Fw,SF_COMPLEX);
	    if (SF_COMPLEX !=sf_gettype(Fd)) sf_error("Need complex data");
 
	    amx = sf_iaxa(Fd,1); sf_setlabel(amx,"mx"); sf_oaxa(Fw,amx,1);
	    amy = sf_iaxa(Fd,2); sf_setlabel(amy,"my"); sf_oaxa(Fw,amy,2);
	    ;                                           sf_oaxa(Fw,az ,3);
	    aw  = sf_iaxa(Fd,3); sf_setlabel(aw ,"w" ); sf_oaxa(Fw,aw ,4);
	    ae  = sf_maxa(1,0,1);

	    n = sf_n(amx)*sf_n(amy);
	    nw = sf_n(aw);

	    data = sf_fslice_init(n,   nw,sizeof(sf_complex));
	    wfld = sf_fslice_init(n,nz*nw,sizeof(sf_complex));

	    sf_fslice_load(Fd,data,SF_COMPLEX);
	    break;
	case 'd':
	    if (inv) { /*   upward continuation */
		Fw = sf_input ( "in");
		Fd = sf_output("out"); sf_settype(Fd,SF_COMPLEX);
		if (SF_COMPLEX !=sf_gettype(Fw)) sf_error("Need complex data");

		amx = sf_iaxa(Fw,1); sf_setlabel(amx,"mx"); sf_oaxa(Fd,amx,1);
		amy = sf_iaxa(Fw,2); sf_setlabel(amy,"my"); sf_oaxa(Fd,amy,2);
		aw  = sf_iaxa(Fw,3); sf_setlabel(aw , "w"); sf_oaxa(Fd,aw ,3);
		ae  = sf_iaxa(Fw,4); sf_setlabel(ae , "e"); sf_oaxa(Fd,ae ,4);

		n = sf_n(amx)*sf_n(amy);
		nw = sf_n(aw)*sf_n(ae);

		data = sf_fslice_init(n,nw,sizeof(sf_complex));
		wfld = sf_fslice_init(n,nw,sizeof(sf_complex));

		sf_fslice_load(Fw,wfld,SF_COMPLEX);
	    } else {   /* downward continuation */
		Fd = sf_input ( "in");
		Fw = sf_output("out"); sf_settype(Fw,SF_COMPLEX);
		if (SF_COMPLEX !=sf_gettype(Fd)) sf_error("Need complex data");
		

		amx = sf_iaxa(Fd,1); sf_setlabel(amx,"mx"); sf_oaxa(Fw,amx,1);
		amy = sf_iaxa(Fd,2); sf_setlabel(amy,"my"); sf_oaxa(Fw,amy,2);
		aw  = sf_iaxa(Fd,3); sf_setlabel(aw , "w"); sf_oaxa(Fw,aw ,3);
		ae  = sf_iaxa(Fd,4); sf_setlabel(ae , "e"); sf_oaxa(Fw,ae ,4);

		n = sf_n(amx)*sf_n(amy);
		nw = sf_n(aw)*sf_n(ae);

		data = sf_fslice_init(n,nw,sizeof(sf_complex));
		wfld = sf_fslice_init(n,nw,sizeof(sf_complex));

		sf_fslice_load(Fd,data,SF_COMPLEX);
	    }
	    break;
	case 'm':
	default:
	    if (inv) { /* modeling */
		Fi = sf_input ( "in");
		Fd = sf_output("out"); sf_settype(Fd,SF_COMPLEX);
		if (SF_FLOAT !=sf_gettype(Fi)) sf_error("Need float image");
		
		if (!sf_getint  ("nw",&nw)) sf_error ("Need nw=");
		if (!sf_getfloat("dw",&dw)) sf_error ("Need dw=");
		if (!sf_getfloat("ow",&ow)) ow=0.;
		aw = sf_maxa(nw,ow,dw); 
		sf_setlabel(aw,"w"); 
		sf_setunit(aw,"1/s"); /* default */
		ae = sf_maxa(1,0,1);

		amx = sf_iaxa(Fi,1); sf_setlabel(amx,"mx"); sf_oaxa(Fd,amx,1);
		amy = sf_iaxa(Fi,2); sf_setlabel(amy,"my"); sf_oaxa(Fd,amy,2);
		az  = sf_iaxa(Fi,3); sf_setlabel(az , "z"); sf_oaxa(Fd,aw ,3);

		n = sf_n(amx)*sf_n(amy);

		data = sf_fslice_init(n,nw,sizeof(sf_complex));
		imag = sf_fslice_init(n,nz,sizeof(float));

		sf_fslice_load(Fi,imag,SF_FLOAT);	
		
	    } else { /* migration */
		Fd = sf_input ( "in");
		Fi = sf_output("out"); sf_settype(Fi,SF_FLOAT);
		if (SF_COMPLEX !=sf_gettype(Fd)) sf_error("Need complex data");
		
		amx = sf_iaxa(Fd,1); sf_setlabel(amx,"mx"); sf_oaxa(Fi,amx,1);
		amy = sf_iaxa(Fd,2); sf_setlabel(amy,"my"); sf_oaxa(Fi,amy,2);
		aw  = sf_iaxa(Fd,3); sf_setlabel(aw , "w"); sf_oaxa(Fi,az ,3);
		ae  = sf_maxa(1,0,1); 

		n = sf_n(amx)*sf_n(amy);
		nw = sf_n(aw);

		data = sf_fslice_init(n,nw,sizeof(sf_complex));
		imag = sf_fslice_init(n,nz,sizeof(float));
	    
		sf_fslice_load(Fd,data,SF_COMPLEX);
	    }
	    break;
    }
    /*------------------------------------------------------------*/
    
    zomig_init(verb,incore,eps,twoway,dtmax,
	       az,aw,ae,
	       amx,amy,
	       alx,aly,
	       tmx,tmy,
	       pmx,pmy,
	       nrmax,slow);

    switch(mode[0]) {
	case 'w':
	    zowfl(inv,causal,data,wfld);
	    break;
	case 'd':
	    zodtm(inv,causal,data,wfld);
	    break;
	case 'm':
	default:
	    zomig_aloc();
	    zomig(inv,       data,imag);
	    zomig_free();
	    break;
    }

    zomig_close();

    /*------------------------------------------------------------*/
    switch(mode[0]) {
	case 'w':
	    sf_fslice_dump(Fw,wfld,SF_COMPLEX);
	    sf_fslice_close(data);
	    sf_fslice_close(wfld);
	    break;
	case 'd':
	    if(inv) sf_fslice_dump(Fd,data,SF_COMPLEX);
	    else    sf_fslice_dump(Fw,wfld,SF_COMPLEX);    
	    sf_fslice_close(data);
	    sf_fslice_close(wfld);
	    break;
	case 'm':
	    if(inv) sf_fslice_dump(Fd,data,SF_COMPLEX);
	    else    sf_fslice_dump(Fi,imag,SF_FLOAT);
	    sf_fslice_close(data);
	    sf_fslice_close(imag);
	default:
	    break;
    }
    sf_fslice_close(slow);
    

    exit (0);
}

/* 	$Id: Mzomig.c 7537 2011-07-28 06:13:30Z sfomel $	 */

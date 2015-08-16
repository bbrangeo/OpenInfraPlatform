/*+=====================================================================

  crd            Funktionen zur Geo-Koordinatenumwandlung       crddef.h

  COPYRIGHT (C) 1999 interactive instruments GmbH Bonn

/*+---------------------------------------------------------------------
BASIS - LIBRARY ---------------------------------------------- ERROR LOG


-*/
#include "system.h"
#include "crd.h"

#include <math.h>
#define PI    3.14159265358979323846
#define PI_OVER_2         (PI/2.0e0)
#define RAD   (PI/180.)
#define DEG   (180./PI)
#define AWGS  6378137.             /*Halbachsen des WGS-Ellipsoids */
#define BWGS  6356752.31425
#define ABES  6377397.15508        /*Halbachsen des Bessel-Ellipsoids (DHDN) */
#define BBES  6356078.96290
#define AGRS  6378137.             /*Halbachsen des GRS-Ellipsoids */
#define BGRS  6356752.3141
#define EQW84   6.694379988635E-3   /* EQW84= (AWGS*AWGS - BWGS*BWGS)/(AWGS*AWGS) */
                                           /* (WGS84-Ellipsoid)  */
#define EQBESA  6.674372231152E-3  /* EQBESA= (ABES*ABES - BBES*BBES)/(ABES*ABES) */
                                           /* (Bessel-Ellipsoid, Quadrat d. ersten numer. Exzentrizität) */
#define EQBESB  6.719218798516E-3  /* EQBESB= (ABES*ABES - BBES*BBES)/(BBES*BBES) */
                                           /* (Bessel-Ellipsoid, Quadrat d. zweiten numer. Exzentrizität) */
#define EQGRSA	6.6943800355E-3

#define EQGRSB	6.7394967883E-3

#define sqr(x)  ((x)*(x))

#define SPHSN(Latitude) ((double) (SemiMajorAxis / sqrt( 1.e0 - E * pow(sin(Latitude), 2))))

#define SPHTMD(Latitude) ((double) (TranMerc_ap * Latitude \
- TranMerc_bp * sin(2.e0 * Latitude) + TranMerc_cp * sin(4.e0 * Latitude) \
- TranMerc_dp * sin(6.e0 * Latitude) + TranMerc_ep * sin(8.e0 * Latitude) ) )

#define SPHSR(Latitude) ((double) (SemiMajorAxis * (1.e0 - E) / \
pow(DENOM(Latitude), 3)))

#define DENOM(Latitude) ((double) (sqrt(1.e0 - E * pow(sin(Latitude),2))))

#define EQBESC	6398786.849
#define EQBESE2	6.7192188E-3


/*    {radius of curvature at the pole} : Extended = 6398786.849; */
/*      E2 = 0.6768657997291Q-02    /* eccentricity squared  */
/*      AE = 0.63782064Q07          /* reference spheroid    */

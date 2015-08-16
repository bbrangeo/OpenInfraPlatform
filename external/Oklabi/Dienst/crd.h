/*+---------------------------------------------------------------------
BASIS - LIBRARY ---------------------------------------------- ERROR LOG
-*/
/*+=====================================================================

  crd            coordinate conversions....                        crd.h

  COPYRIGHT (C) 1999-2003 interactive instruments GmbH Bonn

-*/

#ifndef crdHFILE

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct crd_GK
{
	double rechts;				/*														  = Ausgabe	*/
	double hoch;				/*														  = Ausgabe */
	int streifen;               /* Meridianstreifen, auf den die Koordinate bezogen wurde = Eingabe */
}
	crd_GK;

typedef struct crd_UTM
{
	double rechts;				/*														  = Ausgabe	*/
	double hoch;				/*														  = Ausgabe */
	int    zone;                /* Meridianstreifen, auf den die Koordinate bezogen wurde = Eingabe */
}
	crd_UTM;

typedef struct crd_GEOK
{
	double laenge;
	double breite;
	double hoehe;
}
	crd_GEOK;

typedef struct crd_XYKO
{
	double x;
	double y;
}
	crd_XYKO;

typedef struct crd_DGK
{
	int rechts;
	int hoch;
}
	crd_DGK;

typedef struct p_HELMERT
{
double tX, tY, tZ, rX, rY, rZ, S;
int inverse;
}
	p_transParams;

typedef struct p_TRANMERCPARAMS
{
/* Ellipsoid Parameters */
double TranMerc_a;
double TranMerc_f;
double TranMerc_es;							/* Eccentricity squared */
double TranMerc_ebs;						/* Second Eccentricity squared */

/* Transverse_Mercator projection Parameters */
double TranMerc_Origin_Lat;					/* Latitude of origin in radians */
double TranMerc_Origin_Long;		        /* Longitude of origin in radians */
double TranMerc_False_Northing;			    /* False northing in meters */
double TranMerc_False_Easting;			    /* False easting in meters */
double TranMerc_Scale_Factor;				/* Scale factor  */

/* Isometeric to geodetic latitude parameters */
double TranMerc_ap;
double TranMerc_bp;
double TranMerc_cp;
double TranMerc_dp;
double TranMerc_ep;
}
	p_tranMercParams;

typedef struct CRD
{
double X, Y, Z;
}
	CRD;

#ifdef ANSI
/* crdGform.c * Formatumwandlungen */
	double crdFgdag(double graddez);
	double crdFaggd(double gradalt);
	double crdFgdmd(double graddez);
	double crdFmdgd(double grmindez);
	double crdFagmd(double gradalt);
	double crdFmdag(double grmindez);

/* crdGeogr.c * Transformation Geographischer Koordinaten */
	int crdTgpgw(crd_GEOK, crd_GEOK *);
	int crdTgwgp(crd_GEOK, crd_GEOK *);
	int crdTgpge(crd_GEOK, crd_GEOK *);
	int crdTgegp(crd_GEOK, crd_GEOK *);
    
/* crdGK.c    * Transformation Gauß-Krüger-Koordinaten    */
	int crdTgpgk(crd_GEOK, crd_GK *);
	int crdTgkgp(crd_GK,   crd_GEOK *);

/* crdUTM.c   * Transformation UTM-Koordinaten            */
	int crdTgeut(crd_GEOK, crd_UTM *);
	int crdTutge(crd_UTM,  crd_GEOK *);

/* crdAmersfoort.c * Transformation Amersfoort-Koordinaten*/
	int crdTgeaf(crd_GEOK, crd_XYKO *);
	int crdTafge(crd_XYKO, crd_GEOK *);

/* crdSoldb.c * Transformation Soldner-Koordinaten Baden  */
	int crdTsbgk(crd_XYKO, crd_GK *);
	int crdTgksb(crd_GK,   crd_XYKO *);

/* crdSoldw.c * Transformation Soldner-Koordinaten Württemberg */
	int crdTswgk(crd_XYKO, crd_GK *);
	int crdTgksw(crd_GK,   crd_XYKO *);

/* crdSoldx.c * Transformation Soldner-Koordinaten Köln und evtl. weitere */
	int crdTskgk(crd_XYKO, crd_GK *);
	int crdTgksk(crd_GK,   crd_XYKO *);

/* crdSonst.c * Umwandlung diverser Koordinaten durch Transformation über Drittsystem */
	int crdUgpsb(crd_GEOK, crd_XYKO *);
	int crdUgpsw(crd_GEOK, crd_XYKO *);
	int crdUsbgp(crd_XYKO, crd_GEOK *);
	int crdUswgp(crd_XYKO, crd_GEOK *);
	int crdUsbgw(crd_XYKO, crd_GEOK *);
	int crdUswgw(crd_XYKO, crd_GEOK *);
	int crdUgwsb(crd_GEOK, crd_XYKO *);
	int crdUgwsw(crd_GEOK, crd_XYKO *);
    int crdUsbsw(crd_XYKO, crd_XYKO *);
	int crdUswsb(crd_XYKO, crd_XYKO *);
	int crdUgkgw(crd_GK,   crd_GEOK *);
	int crdUgwgk(crd_GEOK, crd_GK   *);
	int crdUgkut(crd_GK,   crd_UTM  *);
	int crdUutgk(crd_UTM,  crd_GK  *);
	int crdUskgp(crd_XYKO, crd_GEOK *);
	int crdUskgw(crd_XYKO, crd_GEOK *);
	int crdUgpsk(crd_GEOK, crd_XYKO *);
	int crdUgwsk(crd_GEOK, crd_XYKO *);
/* crdBtk25.c * Berechnung der Blattnummer TK 25/50/100 aus dez. Geogr. Koord. (Potsdam) */
	int crdBtkgp(int,      crd_GEOK *);
	int crdBgptk(crd_GEOK, int, int *);
/* crdBdgk5.c * Berechnung der Blattnummer DGK 5 aus Gauß-Krüger-Koordinaten */
	int crdBgkdg(crd_GK,   crd_DGK *);
	int crdBdggk(crd_DGK,  crd_GK *);
/* crdBfb15.c * Berechnung d. Blattnummer d. Bad. Flurkarte 1:1.500 aus bad. Soldner-Koordinaten */
	int crdBsbfb(crd_XYKO, long *);
	int crdBfbsb(long,     crd_XYKO *);
/* crdBfw25.c * Berechnung d. Blattnummer d. Württ. Flurkarte 1:2.500 aus württ. Soldner-Koordinaten */
	int crdBswfw(crd_XYKO, long *);
	int crdBfwsw(long,     crd_XYKO *);
/* crdBfk.c * Berechnung d. Blattnummer d. Kölner Flurkarte aus Kölner Soldner-Koordinaten */
	int crdBskfk(crd_XYKO, char *);
	int crdBfksk(char *,   crd_XYKO *);

	// SE_RT90 <-> ETRS89
	int crdTrtTetrs(crd_GEOK, crd_GEOK *);
	int crdTetrsTrt(crd_GEOK etrs, crd_GEOK *);


#else
/* crdGform.c * Formatumwandlungen */
//	double crdFgdag();
//	double crdFaggd();
//	double crdFgdmd();
//	double crdFmdgd();
//	double crdFagmd();
//	double crdFmdag();

/* crdSE_RT90.cpp * Transformation SE_RT90-Koordinaten */
	//int crdTgrge();
	//int crdTgegp();


/* crdGeogr.c * Transformation Geographischer Koordinaten */
	int crdTgpgw();
	int crdTgwgp();
	int crdTgegw();
	int crdTgwge();
/* crdGK.c    * Transformation Gauß-Krüger-Koordinaten    */
	int crdTgpgk();
	int crdTgkgp();
/* crdUTM.c   * Transformation UTM-Koordinaten            */
	int crdTgeut();
	int crdTutge();
/* crdAmersfoort.c * Transformation Amersfoort-Koordinaten*/
	int crdTgeaf();
	int crdTafge();
/* crdSoldb.c * Transformation Soldner-Koordinaten Baden  */
	int crdTsbgk();
	int crdTgksb();
/* crdSoldw.c * Transformation Soldner-Koordinaten Württtemberg */
	int crdTswgk();
	int crdTgksw();
/* crdSoldx.c * Transformation Soldner-Koordinaten Köln und evtl. weitere */
	int crdTskgk();
	int crdTgksk();
/* crdSonst.c * Umwandlung diverser Koordinaten durch Transformation über Drittsystem */
	int crdUgpsb();
	int crdUgpsw();
	int crdUgwsb();
	int crdUgwsw();
    int crdUsbsw();
	int crdUswsb();
	int crdUgkgw();
	int crdUgwgk();
	int crdUsbgp();
	int crdUswgp();
	int crdUsbgw();
	int crdUswgw();
	int crdUskgp();
	int crdUskgw();
	int crdUgpsk();
	int crdUgwsk();
/* crdBtk25.c * Berechnung der Blattnummer TK 25/50/100 aus dez. Geogr. Koord. (Potsdam) */
	int crdBtkgp();
	int crdBgptk();
/* crdBdgk5.c * Berechnung der Blattnummer DGK 5 aus Gauß-Krüger-Koordinaten */
	int crdBgkdg();
	int crdBdggk();
/* crdBfb15.c * Berechnung d. Blattnummer d. Bad. Flurkarte 1:1.500 aus bad. Soldner-Koordinaten */
	int crdBsbfb();
	int crdBfbsb();
/* crdBfw25.c * Berechnung d. Blattnummer d. Württ. Flurkarte 1:2.500 aus württ. Soldner-Koordinaten */
	int crdBswfw();
	int crdBfwsw();
/* crdBfk.c * Berechnung d. Blattnummer d. Kölner Flurkarte aus Kölner Soldner-Koordinaten */
	int crdBskfk();
	int crdBfksk();
#endif
	

#ifdef __cplusplus
}
#endif

#define crdHFILE

#endif

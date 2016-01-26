/*****************************************************************************
* $Id: J_Transformierer.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2014, Bundesanstalt f�r Stra�enwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen f�r die Software und die zugeh�rigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erkl�rungen zum Gew�hrleistungsausschlu� und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2013-11-18 Transformierer eingef�hrt
* 
****************************************************************************/
#ifndef DEFJ_Transformierer
#define DEFJ_Transformierer

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Transformierer.h"

namespace Oklabi
{
	typedef bool (CALLBACK* pTransformiere)(void*, void*, const char*, const char*, Koordinate&, eKoordRefSys);
	typedef bool (CALLBACK* pTransformerSRS)(void*, void*, const char*, const char*, eKoordRefSys);
	class OKLABIUTIL_API J_Transformierer : public Transformierer, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Transformierer(void* JNIEnv, void* JOBJECT);
		~J_Transformierer();
		static void Registriere();
	public:
		static Transformierer* Erzeuge(void* JNIEnv, void* JOBJECT);
		Text                   GibKlassenname() const;
		Text                   GibBeschreibung() const;
		bool                   Transformiere(Koordinate&, eKoordRefSys) const;
		bool                   IstUnterstuetzt(eKoordRefSys) const;
	private:
		bool                   IstLatLong(eKoordRefSys) const;
		bool                   IstEastingNorthing(eKoordRefSys) const;
	public:
		pTransformiere         m_pCallbackTransform;
		pTransformerSRS        m_pCallbackSRS;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Transformierer

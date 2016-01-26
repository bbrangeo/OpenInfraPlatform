/*****************************************************************************
* $Id: J_Transformierer.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2014, Bundesanstalt für Straßenwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen für die Software und die zugehörigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erklärungen zum Gewährleistungsausschluß und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2013-11-18 Transformierer eingeführt
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

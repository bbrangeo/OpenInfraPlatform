/*****************************************************************************
* $Id: HttpEingabe.h 2013-01-24 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2011-2013, Bundesanstalt für Straßenwesen
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
* 2011-05-10 Eingabe-Objekt für Http-Get
* 2011-05-31 Unterstützung für Http-Post
* 2011-10-14 Schnittstelle überarbeitet
* 2012-07-27 Interface umbenannt
* 2012-10-18 Formale Verbesserungen
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFHttpEingabe
#define DEFHttpEingabe

#include "OklabiKern.h"
#include "DateiEingabe.h"

namespace Oklabi
{
	class OKLABI_API HttpEingabe : public Eingabe
	{
	private:
		HttpEingabe();
		~HttpEingabe();
		bool Initialisiere() const;
		static Text ExecuteHttpGetRequest( const Text& agent, Text url, const Text& user, const Text& pass, 
			const Text& request, Text& responseFile );
		static Text ExecuteHttpPostRequest( const Text& agent, Text url, const Text& user, const Text& pass, 
			const Text& request, const Text& payload, Text& responseFile );
		static Text getTmpName();
		mutable DateiEingabe* m_pFile;
		Text m_strURL;
		Text m_strRequest;
		Text m_strPayload;
		Text m_strUser;
		Text m_strPass;
		mutable Text m_strMessage;
		mutable bool m_bPost;
		mutable bool m_bInit;
		mutable bool m_bFail;
	public:
		static Eingabe* Erzeuge();
		Text GibPfadname() const;
		Text GibKlassenname() const;
		Text GibBeschreibung() const;
		void Oeffne();
		void Schliesse();
		int LiesZeichen();
		size_t GibAnzahl();
		size_t GibZeilen();
		bool IstBeendet();
		void SetzeKodierung(eKodierung);
		bool IstGueltig();
		void ZumAnfang();

		void SetzeURL(const Text&);
		void SetzeRequest(const Text&);
		void SetzePayload(const Text&);
		void SetzeUser(const Text&);
		void SetzePassword(const Text&);
		void SetzePostRequest(bool);
		Text GibURL() const;
		Text GibRequest() const;
		Text GibPayload() const;
		Text GibUser() const;
		Text GibPassword() const;
		Text GibFehlermeldung() const;
		bool GibPostRequest() const;

	};
}// End of namespace Oklabi

#endif	// DEFHttpEingabe

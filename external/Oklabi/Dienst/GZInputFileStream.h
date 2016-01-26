/*****************************************************************************
* $Id: GZInputFileStream.h 2011-11-11 11:11:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt für Straßenwesen
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
* 2010-11-24 Komprimierte XML-Dateien lesen
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
#ifndef GZInputFileStream_H
#define	GZInputFileStream_H

#include "zlib.h"

namespace XercesXML
{
	class GZInputFileStream
	{
		public:
			GZInputFileStream();
			GZInputFileStream(const char*);
			virtual ~GZInputFileStream();
			
			size_t readToBuffer(char*, size_t);
			
			bool reachedEOF() const;
			bool isOpen() const;
			void openFile(const char*);
			void closeFile();
			
		protected:

			gzFile m_pZipFile;
			int    m_nCount;
			int    m_nLastError;
			bool   m_bEnd;
			
			GZInputFileStream(const GZInputFileStream&);
			GZInputFileStream& operator=(const GZInputFileStream&);
	};
} // namespace XercesXML
#endif	// GZInputFileStream_H

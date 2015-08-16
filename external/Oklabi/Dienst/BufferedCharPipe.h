// BufferedCharPipe.h

//==============================================================================
//
// Synchronisiertes Schreiben und Lesen von Zeichen �ber einen Puffer
//
// Der Zeichenpuffer besitzt eine bei der Konstruktion vorgegebene Gr��e. Es 
// k�nenn durch einen Thread Zeichen darin abgelegt werden und durch einen 
// zweiten Zeichen daraus gelesen werden. Lesen und Schreiben blockieren, wenn 
// der Puffer leer bzw. voll ist.
//
//==============================================================================

#ifndef SYNC_BUFFEREDCHARPIPE_H
#define SYNC_BUFFEREDCHARPIPE_H

#include "SyncClasses.h"

namespace Sync
{
	class BufferedCharPipe
	{
	public:
		// Ctor
		BufferedCharPipe( size_t maxbuf );

		// Dtor
		~BufferedCharPipe();

		// Schreiben
		void write( size_t nch, char ch[] );

		// Ende des Schreibens anzeigen
		void eod();

		// Lesen
		size_t read( size_t maxch, char ch[] );

	private:
		// Zeiger auf den Puffer
		char* m_pBuffer;

		// Zyklische Zeiger, L�nge und F�llstand
		size_t m_iw;	// Index des n�chsten zu schreibenden Zeichens
		size_t m_ir;	// Index des n�chsten zu lesenden Zeichens
		size_t m_nchr;	// Zahl der aktuell im Puffer befindlichen Zeichen
		const size_t m_maxchr;	// Puffergr��e

		// EOD-Anzeige
		bool m_eod;
		size_t m_ieod;

		// Kritischer Bereich zur Sicherung der Zeiger und des Puffers
		CriticalRegion m_critreg;

		// Semaphoren zum Bewarten der Leer- und Voll-Ereignisse
		Semaphore m_emptySem;
		Semaphore m_fullSem;
	};
}

#endif

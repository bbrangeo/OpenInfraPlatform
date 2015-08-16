/*****************************************************************************
* $Id: SyncClasses.h 2012-12-17 15:00:00 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 2011-08-05 Formale Anpassungen für CYGWIN
* 2012-02-07 Lock Konflikt bei großer Anzahl von Threads
* 2012-12-17 Implementierung nach Microsoft-Empfehlung
* 
****************************************************************************/

//==============================================================================
//
// Dieser File definiert und implementiert Objekte zur Synchronisierung von 
// Threads.
//
// Die CriticalRegion-Klasse implementiert Systemvariablen fuer sogenannte
// "Kritische Bereiche". Jede Instanz eines CriticalRegion-Objekts entspricht
// einer gegen gleichzeitige Benutzung durch andere Threads des Serverprozesses
// abzusichernden Ressource. Die Operationen enter() und leave() begrenzen die
// Bereiche bei der Verwendung.
//
// Eine Vereinfachung der Verwendung ergibt sich durch die zusaetzliche Klasse
// CriticalRegionOwnership. Die Objekte dieser Klasse werden mit einem 
// CriticalRegion-Objekt konstruiert und setzen im Konstruktor automatisch
// enter() und im Destruktor leave() ab. Wird also eine solche Ownership-
// Variable am Anfang eines Blocks erklaert (storage class auto), so wird der 
// Block als Ganzes zum Kritischen Bereich. Dies beruecksichtigt auch automatisch
// Exceptions, die evtl. innerhalb des Kritischen Bereichs geworfen aber nicht 
// gefangen werden.
//
// Die Klasse SimpleLock implementiert wie CriticalRegion eine Systemvariable 
// fuer "kritische Bereiche". Im Unterschied zur CriticalRegion-Klasse wird 
// jedoch bei der Operation enter() ein Argument angegeben, das bestimmt, ob der 
// Bereich durch mehrere Threads gleichzeitig benutzt werden darf (Share) oder 
// nur durch einen alleine (Exclusive). Die operation leave() beendet beide
// Modi der Synchronisierung durch ein SimpleLock.
//
// Die Semaphore-Klasse implementiert das klassische Konzept der Semaphoren.
// Bei der Erzeugung eines Semaphoren-Objekts wird ein aktueller und ein 
// maximaler Zaehler angegeben, welcher die Zahl der von der Semaphore 
// verwalteten Ressourcen definiert. Der aktuelle Zaehler eines Semaphoren-
// Objekts drueckt die Zahl der Threads aus, die eine von der Semaphore 
// verwaltete Ressource (zusaetzlich zu den aktuellen Nutzungen) gleichzeitig 
// nutzen koennen.
// Die Operation enter() verlangt eine weitere Nutzung (und verringert den
// Zaehler um 1) und die Operation leave() gibt die Nutzung auf (und erhoeht
// den Zaehler entsprechend). Logischerweise blockiert enter(), wenn der Zaehler
// dabei auf Null vorgefunden wird.
//
//==============================================================================

#ifndef SYNC_SYNCCLASSES_H
#define SYNC_SYNCCLASSES_H

#if defined(WIN32) || defined(CYGWIN)
#include <windows.h>
#include <set>
#endif
#ifdef GENERIC_LINUX
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string>
#include "Exceptions.h"
#endif

namespace Sync
{

	//--------------------------------------------------------------------------
	//								CriticalRegion
	//--------------------------------------------------------------------------

	class CriticalRegion
	{
	public:
		// Ctor, besorgt sich die Systemressource
		inline CriticalRegion() //throw() 
		{
#if defined(WIN32) || defined(CYGWIN)
			InitializeCriticalSection( &m_critSect );
#endif
#ifdef GENERIC_LINUX
			m_critSect = makeMutex();
#endif
		}

		// Dtor, gibt die Systemressource frei
		inline ~CriticalRegion() //throw()
		{
#if defined(WIN32) || defined(CYGWIN)
			DeleteCriticalSection( &m_critSect );
#endif
#ifdef GENERIC_LINUX
			closeMutex(m_critSect);
#endif
		}

		// Eigentumsanspruch anmelden - Beginn des kritischen Bereichs
		inline void enter() //throw()
		{
#if defined(WIN32) || defined(CYGWIN)
			EnterCriticalSection( &m_critSect );
#endif
#ifdef GENERIC_LINUX
			lockMutex(m_critSect);
#endif
		}

		// Eigentum aufgeben - Ende des kritischen Bereichs
		inline void leave() //throw()
		{
#if defined(WIN32) || defined(CYGWIN)
			LeaveCriticalSection( &m_critSect );
#endif
#ifdef GENERIC_LINUX
			unlockMutex(m_critSect);
#endif
		}

	private:
		// Das System-Objekt
#if defined(WIN32) || defined(CYGWIN)
		CRITICAL_SECTION m_critSect;
#endif
#ifdef GENERIC_LINUX
		pthread_mutex_t* m_critSect;
		static pthread_mutex_t* makeMutex();
		static void closeMutex(pthread_mutex_t*);
		static void lockMutex(pthread_mutex_t*);
		static void unlockMutex(pthread_mutex_t*);
#endif
	};

	class CriticalRegionOwnership
	{
	public:
		// Ctor, meldet Eigentumsanspruch an
		inline CriticalRegionOwnership( CriticalRegion& cr ) : m_cr( cr )
		{ 
			m_cr.enter();
		}
		// Dtor, Eigentum aufgeben
		inline ~CriticalRegionOwnership()
		{ 
			m_cr.leave();
		}
	private:
		// Zeiger auf das bei Konstruktion angegeben CriticalRegion-Objekt
		CriticalRegion& m_cr;
	};

	//--------------------------------------------------------------------------
	//								Semaphore
	//--------------------------------------------------------------------------

	class Semaphore
	{
	public:
		// Ctor, besorgt sich die Systemressource. Angegeben wird ein 
		// Initialwert fuer den Wert der Semaphore und ein maximaler Wert, der 
		// fuer die Zahl der insgesamt verwalteten Ressourcen steht.
		inline Semaphore( int initcnt, int maxcnt  )  
		{
#if defined(WIN32) || defined(CYGWIN)
			m_semaphore = CreateSemaphore( NULL, initcnt, maxcnt, NULL );
#endif
#ifdef GENERIC_LINUX
			sem_init( &m_semaphore, 0, initcnt );
#endif
		}
		// Dtor, gibt die Systemressource frei
		inline ~Semaphore()
		{
#if defined(WIN32) || defined(CYGWIN)
			CloseHandle( &m_semaphore );
#endif
#ifdef GENERIC_LINUX
			sem_destroy( &m_semaphore );
#endif
		}

		// Nutzungsanspruch anmelden 
		inline void enter()
		{
#if defined(WIN32) || defined(CYGWIN)
			WaitForSingleObject( &m_semaphore, INFINITE );
#endif
#ifdef GENERIC_LINUX
			sem_wait( &m_semaphore );
#endif
		}

		// Nutzungsanspruch aufgeben 
		inline void leave()
		{
#if defined(WIN32) || defined(CYGWIN)
			ReleaseSemaphore( m_semaphore, 1, NULL );
#endif
#ifdef GENERIC_LINUX
			sem_post( &m_semaphore );
#endif
		}

	private:
		// Das System-Objekt
#if defined(WIN32) || defined(CYGWIN)
		HANDLE m_semaphore;
#endif
#ifdef GENERIC_LINUX
		sem_t m_semaphore;
#endif
	};

	class SemaphoreOwnership
	{
	public:
		// Ctor, meldet Nutzungsanspruch an
		inline SemaphoreOwnership( Semaphore& sem ) : m_sem( sem )
		{ 
			m_sem.enter();
		}
		// Dtor, Nutzungsanspruch aufgeben
		inline ~SemaphoreOwnership()
		{ 
			m_sem.leave();
		}
	private:
		// Zeiger auf das bei Konstruktion angegebene Semaphore-Objekt
		Semaphore& m_sem;
	};

	//--------------------------------------------------------------------------
	//								SimpleLock
	//--------------------------------------------------------------------------

	class SimpleLock : private CriticalRegion
	{
	public:
		// Enum zur Unterscheidung von Share/Exclusive
		enum Mode 
		{
			Share,		// Bereich kann gleichzeitig benutzt werden
			Exclusive	// Nur einer Darf Bereich benutzen
		};

		// Ctor, besorgt sich alle Systemressourcen und initialisiert
		SimpleLock() /*throw()*/;

		// Dtor, gibt die Systemressourcen frei
		~SimpleLock() /*throw()*/;

		// Beginn des kritischen Bereichs mit Angabe des Modus
		void enter( Mode mode ) /*throw()*/;

		// Ende des kritischen Bereichs mit Modus
		void leave() /*throw()*/;

	private:
#if defined(WIN32) || defined(CYGWIN)

		HANDLE hReaderEvent;
		HANDLE hMutex;
		HANDLE hWriterMutex;
		volatile LONG iCounter;

		CRITICAL_SECTION m_cs;


		/*
		volatile LONG m_writer;
		volatile LONG m_reader;
		volatile LONG m_waiting;
		
		CRITICAL_SECTION m_cs; 
		HANDLE m_safewrite; 
		HANDLE m_saferead;
		*/

		std::set<DWORD> m_set;
#endif
#ifdef GENERIC_LINUX
	   pthread_rwlock_t* m_rwl;
#endif
	};

	class SimpleLockOwnership
	{
	public:
		// Ctor, meldet Eigentumsanspruch an
		inline SimpleLockOwnership( 
			SimpleLock& cr, SimpleLock::Mode mode ) : m_cr( cr )
		{ 
			m_cr.enter( mode );
		}
		// Dtor, Eigentum aufgeben
		inline ~SimpleLockOwnership()
		{ 
			m_cr.leave();
		}
	private:
		// Zeiger auf das bei Konstruktion angegeben SimpleLock-Objekt
		SimpleLock& m_cr;
	};

#ifdef GENERIC_LINUX
	// Basisklasse aller Server-Exceptions
	class SyncException : public structured_exception
	{
	public:
		// Es gibt keinen Default-Konstruktor!
		SyncException( const std::string& loc, const std::string& msg,
			const char* pId, int nS=0, const char** pS=0, bool copy=false )
			: structured_exception("SyncException", false,
			  "Sync", pId, nS, pS, copy), m_Msg( msg ) {}
		~SyncException() NOTHROW {}
	protected:
		std::string m_Msg;
	};

	// Fehler bei Mutex-Beschaffung
	class GetMutexConflict : public SyncException 
	{
	public:
		GetMutexConflict()
			: SyncException("", "", "GetMutexConflict") {}
		GetMutexConflict( const std::string& msg )
			: SyncException("", msg, "GetMutexConflict") {}
		~GetMutexConflict() NOTHROW {}
		const char* what() const NOTHROW;
	};

	// Fehler bei Mutex-Befreiung
	class FreeMutexConflict : public SyncException 
	{
	public:
		FreeMutexConflict()
			: SyncException("", "", "FreeMutexConflict") {}
		FreeMutexConflict( const std::string& msg )
			: SyncException("", msg, "FreeMutexConflict") {}
		~FreeMutexConflict() NOTHROW {}
		const char* what() const NOTHROW;
	};

	// Fehler bei Mutex-Lock
	class LockMutexConflict : public SyncException 
	{
	public:
		LockMutexConflict()
			: SyncException("", "", "LockMutexConflict") {}
		LockMutexConflict( const std::string& msg )
			: SyncException("", msg, "LockMutexConflict") {}
		~LockMutexConflict() NOTHROW {}
		const char* what() const NOTHROW;
	};

	// Fehler bei Mutex-Unlock
	class UnlockMutexConflict : public SyncException 
	{
	public:
		UnlockMutexConflict()
			: SyncException("", "", "UnlockMutexConflict") {}
		UnlockMutexConflict( const std::string& msg )
			: SyncException("", msg, "UnlockMutexConflict") {}
		~UnlockMutexConflict() NOTHROW {}
		const char* what() const NOTHROW;
	};
#endif
}

#endif

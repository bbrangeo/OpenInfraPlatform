/*****************************************************************************
* $Id: Exceptions.h 2010-11-19 15:00:00 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 2010-07-12 Funktionen zur Schaltbarkeit von stack trace statisch
* 2010-11-19 stack trace unter Linux hat memory leaks
* 
****************************************************************************/
#ifndef Structured_exception_H
#define Structured_exception_H

#if defined(WIN32) && !defined(CYGWIN)
#include "eh.h"
#include "windows.h"
#define NOTHROW
#elif !defined(CYGWIN)
#define NOTHROW throw()
#else
#include "windows.h"
#define NOTHROW throw()
#endif
#include "Services.h"
#include <exception>
#include "msg.h"

#ifdef GENERIC_LINUX
#include <signal.h>
#endif

class structured_exception : public std::exception
{
public:
	structured_exception(const char* str, bool trace = true,
		const char* pNS = "exception", const char* pId = "default", 
		int nSubs = 0, const char** pSubs = 0, bool copy = false) NOTHROW;
#if defined(WIN32) && !defined(CYGWIN)
	structured_exception(unsigned int const code, EXCEPTION_POINTERS const &info,
		const char* str, bool trace = true) NOTHROW;
#endif
	structured_exception( const structured_exception& exc ) NOTHROW;
	structured_exception& operator=(const structured_exception &) NOTHROW;
	virtual ~structured_exception() NOTHROW;
	static int install() NOTHROW;
	void const *where() const NOTHROW;
	unsigned int code() const NOTHROW;
	static bool StackTraceEnabled() NOTHROW;
	static bool EnableStackTrace(const bool mode) NOTHROW;
	const char *trace() const NOTHROW;
#if defined(GENERIC_LINUX) || defined(CYGWIN) 
	const char* what() const NOTHROW;
#endif
	virtual const char* message() const;
	const char* message(msg::Message* pMsg) const;
	const char* getNamespace() const;
	const char* getId() const;
	const unsigned int getSubstitutions(const char** const) const;
	const void setSubstitutions(unsigned int, const char**);
	static void DoStackTrace(LPTSTR szString, DWORD dwSize, DWORD dwNumSkip, DWORD& dwStrSize);
#ifdef GENERIC_LINUX
	static void DoStackTrace(int signum, siginfo_t* info, void*ptr,
		LPTSTR szString, DWORD dwSize, DWORD dwNumSkip, DWORD& dwStrSize);
#endif
	static void cleanup();

private:
#if defined(WIN32) && !defined(CYGWIN)
	static void exception_translator(unsigned code, EXCEPTION_POINTERS *info);
#endif

	static bool m_bStackTrace;

	void const *m_pAddress;
	unsigned int m_nCode;
	char* m_pTraceString;
#if defined(GENERIC_LINUX) || defined(CYGWIN) 
	int m_nDscLng;
	char* m_pDescription;
#endif
	DWORD m_nTraceSize;

private:
	// Hooks for backtrace
	void backtrace();
	// Hooks for message handler
	void copySubstitutions();
	void freeSubstitutions();
	const char* m_pNS;
	const char* m_pId;
	unsigned int m_nSubs;
	const char** m_pSubs;
	char** m_pSubsCopy;
	bool m_bCopy;
};
#endif // Structured_exception_H

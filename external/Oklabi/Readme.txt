Version 1.3.0.10   Diese Archive richtet sich an Nutzer der nativen C++ Schnittstelle.
Die Archive enthalten die DLL- und LIB-Dateien f�r Windows unterschieden nach verschiedenen Versionen der Entwicklungsumgebung sowie f�r 32 und 64 Bit Plattformen.
Bitte beachten Sie: Zur Zeit werden die Microsoft-Entwicklungsumgebungen Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 und Visual Studio 2013 unterst�tzt. Die Headerdateien sind unabh�ngig von der Version der Entwicklungsumgebung und liegen in mehreren Verzeichnissen im Ordner Bibliothek und stehen auch zum Download bereit. Beachten Sie auch, dass bei Benutzung der Bibliotheken die Laufzeitumgebungen gegebenenfalls aktualisiert werden m�ssen. Die ben�tigten Redistributable Pakete f�r Visual Studio finden Sie auf dieser Seite und bei Microsoft.
Bei den Compiler-Einstellungen f�r die Codegenerierung richten Sie bitte folgende Parameter ein:

Enable C++ Exceptions: Yes With SEH Exceptions (/EHa)
Runtime Library: Multi-threaded DLL (/MD)
Die Pr�prozessor-Variable _DEBUG darf nicht gesetzt sein, verwenden Sie statt dessen bitte NDEBUG.

64 Bit, Visual Studio 2013
Bugfix vom 25. Juli 2014
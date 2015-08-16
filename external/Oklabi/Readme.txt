Version 1.3.0.10   Diese Archive richtet sich an Nutzer der nativen C++ Schnittstelle.
Die Archive enthalten die DLL- und LIB-Dateien für Windows unterschieden nach verschiedenen Versionen der Entwicklungsumgebung sowie für 32 und 64 Bit Plattformen.
Bitte beachten Sie: Zur Zeit werden die Microsoft-Entwicklungsumgebungen Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 und Visual Studio 2013 unterstützt. Die Headerdateien sind unabhängig von der Version der Entwicklungsumgebung und liegen in mehreren Verzeichnissen im Ordner Bibliothek und stehen auch zum Download bereit. Beachten Sie auch, dass bei Benutzung der Bibliotheken die Laufzeitumgebungen gegebenenfalls aktualisiert werden müssen. Die benötigten Redistributable Pakete für Visual Studio finden Sie auf dieser Seite und bei Microsoft.
Bei den Compiler-Einstellungen für die Codegenerierung richten Sie bitte folgende Parameter ein:

Enable C++ Exceptions: Yes With SEH Exceptions (/EHa)
Runtime Library: Multi-threaded DLL (/MD)
Die Präprozessor-Variable _DEBUG darf nicht gesetzt sein, verwenden Sie statt dessen bitte NDEBUG.

64 Bit, Visual Studio 2013
Bugfix vom 25. Juli 2014
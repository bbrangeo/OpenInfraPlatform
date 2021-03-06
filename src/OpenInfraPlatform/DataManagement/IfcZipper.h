/*! \verbatim
*  \copyright      Copyright (c) 2015 Technische Universit�t M�nchen
*                  Chair of Computational Modeling and Simulation. All rights reserved.
*  \author         Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief          This file is part of the TUM Open Infra Platform.
*  \endverbatim
*/

#ifndef OpenInfraPlatform_DataManagement_IfcZipper
#define OpenInfraPlatform_DataManagement_IfcZipper

#include <QThread>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

#define DEFL 0
#define INFL 1


#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif

struct zh_time {
	unsigned short seconds : 5;
	unsigned short minutes : 6;
	unsigned short hours : 5;
};

struct zh_date {
	unsigned short day : 5;
	unsigned short month : 4;
	unsigned short year : 7;
};

union u_time {
	zh_time f_time;
	quint16 b_time;
};

union u_date {
	zh_date f_date;
	quint16 b_date;
};

struct localzipheader {
	quint32 signature;
	quint16 version;
	quint16 gpBitFlag;
	quint16 method;
	u_time lmodTime;
	u_date lmodDate;
	quint32 crc32;
	quint32 compSize;
	quint32 uncompSize;
	quint16 fileNameLength;
	quint16 xfieldLength;	
};

struct CentralDirectoryRecord {
	quint32 signature;	
	char versionNeeded[2];
	quint16 version;
	quint16 gpBitFlag;
	quint16 method;
	u_time lmodTime;
	u_date lmodDate;
	quint32 crc32;
	quint32 compSize;
	quint32 uncompSize;
	quint16 fileNameLength;
	quint16 xfieldLength;
	quint16 fileCommLength;
	quint16 diskStart;
	quint16 internalAttributes;
	quint32 externalAttributes;
	quint32 offset;
};

struct EndOfCentralDirectoryRecord {
	quint32 signature;
	quint16 diskNumber;
	quint16 cdrDisk;
	quint16 diskEntries;
	quint16 totalEntries;
	quint32 cdrSize;
	quint32 offset;
	quint16 commLength;
};



namespace OpenInfraPlatform {
	namespace DataManagement {
		
		class IfcZipper : public QThread {
			Q_OBJECT
		public:
			z_stream zstream;
			QString tempName;
			QString filename;
			std::ifstream ifs;
			std::ofstream ofs;
			bool mode;
			Q_SIGNAL void fileDeleted();
			Q_SLOT int removeFile();
			IfcZipper(QObject* parent, QString path,QString tempName, bool operation);
			virtual ~IfcZipper();
			void run() Q_DECL_OVERRIDE;
			int createLocalFileHeader(localzipheader* header,Byte* inBuffer,uLong inFileSize);
			int writeLocalFileHeader(localzipheader* header);
			int createCentralDirectoryRecord(localzipheader* header, CentralDirectoryRecord* cdr);
			int writeCentralDirectory(CentralDirectoryRecord* cdr);
			int createEndOfCentralDirectoryRecord(EndOfCentralDirectoryRecord* eocdr, CentralDirectoryRecord* cdr);
			int writeEndOfCentralDirectoryRecord(EndOfCentralDirectoryRecord* eocdr);
			void parseLocalFileHeader(localzipheader* header);
			void init(localzipheader* header);
		};
	}
}

#endif
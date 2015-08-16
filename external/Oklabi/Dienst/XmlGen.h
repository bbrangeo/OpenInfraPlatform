/*****************************************************************************
* $Id: XmlGen.h 2010-04-30 15:00:00 vogelsang $
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
* 
****************************************************************************/
// XmlGen.h

//==============================================================================
//
// This file contain helper classes for the generation of XML-strings.
//
//==============================================================================

#ifndef XMLGEN_H
#define XMLGEN_H

#ifdef CYGWIN
#undef max
#undef min
#endif
#include <vector>
#include <map>
#include <string>
#include <fstream>

#ifdef GENERIC_LINUX
#include "./Socket/ServerSocket.h"
#endif

//#define NO_XMLSTRINGCONTENT

namespace XmlGen
{

	// -------------------------------------------------------------------------
	// ------------------------------ Exceptions -------------------------------
	// -------------------------------------------------------------------------

	class Exception
	{
	public:
		Exception() {};
		Exception(const std::string& what): m_what(what) {};

		virtual std::string what() const = 0;
		
	private:
		std::string m_what;

		friend class Unexpected;
	};

	class Unexpected: public Exception
	{
	public:
		Unexpected() {};
		Unexpected(const std::string& what): Exception(what) {};

		std::string what() const 
			{ return "UnexpectedException: " + m_what; }
	};


	// -------------------------------------------------------------------------
	// ----------------------------- XmlTagString ------------------------------
	// -------------------------------------------------------------------------

	class XmlTagString
	{
	public:
		// Ctor initializing an XmlTagString from std::string
		XmlTagString( const std::string& rhs );

		// Copy Ctor
		XmlTagString( const XmlTagString& rhs );

		// Dtor
		~XmlTagString();

		// Assignment operator
		XmlTagString& operator=( const XmlTagString& rhs );

		// Accessing the contained C-string
		const char* c_str() const;

		// Length inquiry
		unsigned size() const;
	
	private:
		// The string (<16 chars kept inline, else by pointer)
		char m_string[16];
	};


	// -------------------------------------------------------------------------
	// --------------------------- XmlStringContent ----------------------------
	// -------------------------------------------------------------------------
	class XmlStringContent
	{
	public:
		typedef unsigned sizetype;

		//class OutOfRange {};

		~XmlStringContent();
		XmlStringContent(): m_contentType(Zero) {};
		
		const char* operator[](sizetype pos) const;
		unsigned sizeAt(sizetype pos) const;

		void push_back(const char* pChar );

		unsigned size() const;

		void clear();


	private:
		enum ContentType { Zero, One_direct, One_extern, More };

		ContentType m_contentType;
		char m_content[13];
	
		typedef std::vector<std::string> StrVector;
		typedef std::vector<std::string>* StrVectorPtr;

		void deleteExternData();
	};



	// -------------------------------------------------------------------------
	// -------------------------------- XmlTag ---------------------------------
	// -------------------------------------------------------------------------

	class XmlTag;

	// Abstract superclass for XmlTags on Heap and in File
	class _XmlTag
	{
	public:
		// C'tor
		_XmlTag(): m_pFather( NULL ) {};

		// virtual D'tor
		virtual ~_XmlTag() {};

		// Get SubType
		virtual bool isTagAsFile() const = 0;

		// Father-Relation
		XmlTag* getFather() const { return m_pFather; }

		// Output
		virtual void getString( std::string& ret, int indent, char white, 
			int indbase, char ignore ) const = 0;

		virtual void writeToFileStream(std::ostream& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const = 0;

#ifdef GENERIC_LINUX
		virtual void writeToSocket(ServerSocket& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const = 0;
#endif
		
	private:
		XmlTag* m_pFather;

		// Is there any Content/Attribute
		virtual bool hasContentOrAttribute() const = 0;

		friend class XmlTag;
	};


	// XmlTags on Heap
	class XmlHeap;
	class XmlTag: public _XmlTag
	{
	public:
		// Operator new (standard)
		void* operator new( size_t );

		// Operator delete
		void operator delete( void* p );

		// Operator new, placement in XmlHeap storage
		void* operator new( size_t, XmlHeap* pHeap );

		// Operator delete, placement variant
		void operator delete( void* p, XmlHeap* pHeap );


		// Ctor: Default (tag name will be empty)
		inline XmlTag() 
			: m_tag( "" ), m_count( 0 ), m_noEmptyOutput( false ),
			  m_pHeap(NULL) 
			{}

		// Ctor: Simple Tag-Object
		inline XmlTag( 
			const std::string& tag, XmlHeap* pHeap=NULL ) 
			: m_tag( tag ), m_count( 0 ), m_noEmptyOutput( false ),
			m_pHeap( pHeap )
			{}

		// Ctor: Tag-Object with string content
		inline XmlTag( 
			const std::string& tag, const std::string& cont, 
			XmlHeap* pHeap=NULL ) 
			: m_tag( tag ), m_count( 0 ), m_noEmptyOutput( false ),
			m_pHeap( pHeap )
			{ appContent( cont ); }

		// Ctor: Tag-Object as a copy of another Tag-Object
		// No deep copy! Only the Tag Name is copied.
		inline XmlTag( const XmlTag& tag )
			: m_tag( tag.m_tag ), m_noEmptyOutput( false ),
			m_pHeap( tag.m_pHeap )
			{}

		// Dtor: Rid Owned References
		~XmlTag();

		bool isTagAsFile() const { return false; }

		// Initialize tag name
		inline void init( const std::string& tag )
		{
			m_tag = tag;
			m_count = 0;
		}

		// Reset tag name
		inline void setTagname( const std::string& tag )
		{
			m_tag = tag;
		}

		// Set an attribute
		void setAttr( const std::string& name, const std::string& value,
			bool isSignificantForEmptiness=true);

		// Append string content
		void appContent( const std::string& cont );
		void appContent( char* cont );

		// Clear Content
		void clearContent();

		// Append embedded externally Owned Tag-Reference
		void appRefContent( XmlTag* pXml ) /*throw (Unexpected)*/;

		// Append embedded Owned Tag-Reference
		void appOwnedContent( XmlTag* pXml ) /*throw (Unexpected)*/;

		// XmlTag is complete, no further appending 
		// (There is no reset! Tag-Pointer will be deleted.)
		void markTagComplete(int indent=0, char white='\t', int indbase=0, 
			char ignore=0) /*throw (Unexpected)*/;

		// Mark Tag: no output, if there is no Content (or attribute)
		void noEmptyOutput(bool val) { m_noEmptyOutput = val; }

		// Report the string representation of a Tag-Object
		std::string getString( 
			int indent=0, char white='\t', int indbase=0, char ignore=0 ) const;

		// Non-string-copying variant of the function above
		void getString( 
			std::string& result, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const;

		// Output to FileStream
		void writeToFileStream(std::ostream& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const;

		void getNestedContent( std::ostream& ofs,
			int indent, char white, int indbase, char ignore=0 ) const;

#ifdef GENERIC_LINUX
		// Output to Socket
		void writeToSocket(ServerSocket& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const;

		void getNestedContent( ServerSocket& ofs,
			int indent, char white, int indbase, char ignore=0 ) const;
#endif

		// Create nested content
		std::string getNestedContent( 
			int indent, char white, int indbase, char ignore=0 ) const;

		// Non-string-copying variant of the function above
		void getNestedContent( 
			std::string& cont, int indent, char white, int indbase, char ignore=0 ) const;

		// Xml-Comments
		void setComment(const std::string& comment) { m_comment = comment; };
		void addComment(const std::string& comment);
		std::string getComment() const { return m_comment; };

		// Create string representation so far, then dispose of the owned 
		// content
		void partialString( int indent=0, char white='\t', int indbase=0 );

		// Output the string representation of a Tag-Object to File 
		void writeToFile( const std::string file ) const;

		// Check if the tag has content
		inline bool isEmpty()
			{ return ( m_NestedTags.size() == 0 ); }

		// Return count of content (elements and string content)
		inline size_t getContentCount()
			{ return m_NestedTags.size(); }

		// Inquire the heap a tag belongs to
		inline XmlHeap* getHeap() const { return (XmlHeap*)m_pHeap; };

		// Inquire tag name
		std::string getTagname() const { return m_tag.c_str(); }

	private:

		// Set the free queue pointer
		inline void setFreePtr( XmlTag* pTag ) const { m_pHeap = pTag; };

		// Get the free queue pointer
		inline XmlTag* getFreePtr() const { return (XmlTag*)m_pHeap; };

		// Dispose of owned content
		void dispose();

		// Notify Father about a Child must be stored in XmlHeap-Filestream
		void callbackTagComplete(XmlTag* pSon, const std::string& strSon);

		// Owned-by count
		mutable int m_count;

		// The tag
		XmlTagString m_tag;

		// Attributes
		struct AttrValueType
		{
			std::string value;
			bool isSignificantForEmptiness;

			AttrValueType(): isSignificantForEmptiness(true) {};
			AttrValueType(const std::string& val, bool flag)
				: value(val), isSignificantForEmptiness(flag) {};
		};
		typedef std::map<std::string,AttrValueType> AttributeMapType;
		AttributeMapType m_attr;


		// Nested Tags with Owned-Property
		struct NestedTagsType
		{
			_XmlTag*		m_pXml;
			bool			m_owned;

			NestedTagsType(): m_pXml(NULL), m_owned(false) {};
			NestedTagsType(XmlTag* pXml, bool owned): m_pXml(pXml), m_owned(owned) {};
		};
		std::vector<NestedTagsType> m_NestedTags;


		// Nested text content
#ifdef NO_XMLSTRINGCONTENT
		std::vector<std::string> m_content;
#else
		XmlStringContent m_content;
#endif

	
		// Xml-Comment
		std::string m_comment;

		// Partial content
		std::string m_strPartial;

		// Ignore Tag, if it is empty
		bool m_noEmptyOutput;
		
		// Is there any Content/Attribute
		bool hasContentOrAttribute() const;

		// Pointer to Heap or next element in free queue
		mutable void* m_pHeap;	


		friend class XmlHeap;
		friend class NestedTagVector;
	};


	// XmlTags stored in File (see XmlHeap)
	class XmlTagAsFile: public _XmlTag
	{
	public:

		XmlTagAsFile(bool hasContentOrAttribute)
			: m_pHeap(NULL), m_hasContentOrAttribute(hasContentOrAttribute) {};

		bool isTagAsFile() const { return true; };

		void getString( std::string& ret, int indent, char white, int indbase,
			char ignore ) const;

		void writeToFileStream(std::ostream& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const;

#ifdef GENERIC_LINUX
		void writeToSocket(ServerSocket& ofs, int indent=0, 
			char white='\t', int indbase=0, char ignore=0 ) const;
#endif

		std::streampos from;
		std::streampos to;

		// Is there any Content/Attribute
		bool hasContentOrAttribute() const { return m_hasContentOrAttribute; }
		bool m_hasContentOrAttribute;

		XmlHeap* m_pHeap;

	};

	// -------------------------------------------------------------------------
	// ------------------------------- XmlHeap ---------------------------------
	// -------------------------------------------------------------------------

	class XmlHeap
	{
		friend class XmlTag;
		friend class XmlTagAsFile;

	public:
		// Ctor
		XmlHeap(): m_pFree(NULL), m_pFStream(NULL) {};

		// Dtor: Automatically deletes all tags still allocated
		~XmlHeap();

		// Use XmlHeap for storing XmlTags in a temporary file
		void createFileHeap() /*throw (Unexpected)*/;

		// Check, if this Heap uses temp File for storing XmlTags
		bool isFileHeap() const { return m_pFStream != NULL;}

	private:
		// Allocate a new XmlTag from the free queue
		XmlTag* alloc();

		// Put an XmlTag on the free queue
		void free( const XmlTag* pTag );

		// Type of allocation vector element
		typedef std::pair<unsigned,XmlTag*> SizedChunkType;

		// Allocation vector
		std::vector<SizedChunkType> m_vChunks;

		// The free queue head
		XmlTag* m_pFree;

		// Initial chunk size
		static unsigned startChunkSize;

		// Tags can be stored in temporary file
		std::fstream* m_pFStream;
		std::string m_strFStreamFilename;

		// for debugging
#ifdef _DEBUG
		static unsigned long debugAllocCount;
#endif
	};
}



#endif

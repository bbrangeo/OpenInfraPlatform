/*****************************************************************************
* $Id: msg.h 2011-11-17 15:00:00 vogelsang $
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
* 2011-11-17 Formale Verbesserungen
* 
****************************************************************************/
// msg.h

//==============================================================================
//
// Message Handling Subsystem - msg
// 
// External Interface Declarations
//
// The Message Handling Subsystem consists of a few classes that make it easy 
// to generate meaningful messages out of applications. Messages are created
// in the form of simple files, which belong to the application environment.
// These files contain the text of the messages, accompanied by a language
// designation, a severty code, and a key that is combined from a namespace and
// an identifier. The text part may contain substitition points, where the
// application can insert run-time text by means of the msg interfaces.
//
// The msg files are processed (compiled) by means of a utility named MHL. The
// output of that operation is one .cpp file per original msg file, which - if
// cpp'ed and linked together with the application - installs the proper message
// database in the application by using static initialization.
//
// The interface is defined in namespace "msg". Its main classes are ...
//
// MessageHandler
// One base MessageHandler is created at startup time. It contains all messages
// which have been statically bound to the application image by the process 
// explained above. You get a pointer to that base instance by means of
//
//		msg::MessageHandler::object()
//
// MessageHandlers offer a few modal controls for the selection of messages
// (example: language preference) and let you associate with them up to two 
// MessageCannel objects which are responsible for transporting messages 
// to their designated destinations.
// From a MessageHandler you can query a Message object by means of its keys
// (namespace and identifier). That Message object you can subsequently feed
// into the output channel pipeline be issuing one of the "write..." interface
// functions.
// 
// Message
// Message objects are small, temporary objects, which are designed to be 
// created on the fly. They address the material in the MessageHandler's 
// message table and offer an interface to make the appropriate substitutions 
// against the message text. Typically Message objects are created on the fly
// like in ...
//
//		pMHandler->writeMessage1( 
//			pMHandler->getMessage( "oklabi", "NoSuchClass" ), classname ) );
//
//
// MessageChannel
// MessageChannel objects are very much in the scope of the application. I.e.
// the application environment defines how the message output stream shall be
// processed. This is done by deriving from MessageChannel and by associating
// these derived objects with the MessageHandler. Overridable methods in the
// MessageChannel give you a good control over what is to happen in case of
// a message of a certain severity level. You can also choose to throw 
// application specific exceptions instead of logging messages or you can do 
// both things.
// Standard implementations include MessageChannels that output messages to
// alert windows.
//
//==============================================================================

#ifndef MSG_H
#define MSG_H

#include "MsgPackaging.h"

#ifdef WIN32
#ifndef MSGLIB
#ifdef MSG_EXPORTS
#	define $IFMSG __declspec(dllexport)
#else
#	define $IFMSG __declspec(dllimport)
#endif
#else
#	define $IFMSG
#endif

#pragma warning( disable : 4290 )

#endif

#if defined(GENERIC_LINUX) || defined(CYGWIN)
#define $IFMSG
#endif

namespace msg
{

	class MessageChannel;
	class MessageHandler;
	struct MTE;

	// =========================================================================
	// Aux Types

	enum SeverityLevel
	{
		SLInfo		= 0,	// Information only, no error
		SLWarning	= 1,	// May-be wrong
		SLError		= 2,	// True error
		SLAbort		= 3		// The hell broke loose, throw an exception
	};

#define LANG_COUNT 3
	enum Language
	{
		LANnone = 0,		// No language
							// LAN + ISO 639 2-letter language code
		LANen = 1,			// English
		LANde = 2			// German
	};

	class LanguageList
	{
	public:
		friend class MessageHandler;
		// Ctor: List of 1 Language
		$IFMSG LanguageList( Language lng ) : m_lang1( lng ), m_lang2( LANnone ) {}

		// Ctor: List of 2 Languages
		$IFMSG LanguageList( Language lng1, Language lng2 ) 
			: m_lang1( lng1 ), m_lang2( lng2 ) {}

		// Find out precision of matching a language against list
		$IFMSG int match( Language lng ) const 
		{ 
			if( lng==m_lang1 ) return 0; 
			else if( lng==m_lang2 ) return 1;
			return -1;
		}

	private:
		Language m_lang1;
		Language m_lang2;
	};

	// =========================================================================
	// Errors

	class MessageExists
	{
	public:
		MessageExists(const char* pNS, const char* pId) : m_pNS(pNS), m_pId(pId) {};
		const char* GetNamespace() { return m_pNS; };
		const char* GetId() { return m_pId; };
	private:
		const char* m_pNS;
		const char* m_pId;
	};

	class MessageNotFound
	{
	public:
		MessageNotFound(const char* pNS, const char* pId) : m_pNS(pNS), m_pId(pId) {};
		const char* GetNamespace() { return m_pNS; };
		const char* GetId() { return m_pId; };
	private:
		const char* m_pNS;
		const char* m_pId;
	};

	class LanguageInvalid
	{
	public:
		LanguageInvalid(short lng) : m_nValue(lng) {};
		const short& GetValue() { return m_nValue; };
	private:
		short m_nValue;
	};

	class MessageHandlerError
	{
	public:
		MessageHandlerError() : m_pError("MessageHandler corrupted.") {};
		const char* GetError() { return m_pError; };
	private:
		const char* m_pError;
	};

	// =========================================================================
	// Message
	//
	// An instance of the Message class can be either retrieved from a Message-
	// Handler or created directly with the required attributes. Substitution
	// points contained in the message can be substituted one by one by type 
	// specific interfaces. Use an appropriate variant of 
	// MessageHandler::writeMessage() for outputting a particular Message.

	class Message
	{
	public:
		// Option Selection for the output of Boolean values
		enum BoolOption
		{
			truefalse,		// true or false
			yesno			// yes or no
		};

	public:
		friend class MessageHandler;
		// Ctor: Set up text message
		$IFMSG Message( 
			const char* pNS, const char* pId, 
			SeverityLevel sl, Language lng, const char* pTxt );

		// Ctor: Construct from MessageHandler
		$IFMSG Message( const MessageHandler* pMH, const char* pNS, const char* pId )
			/*throw (MessageNotFound)*/;

		// Ctor: As above + indicate the quality of language matching.
		$IFMSG Message( 
			const MessageHandler* pMH, 
			const char* pNS, const char* pId, int& lmq )
			/*throw (MessageNotFound)*/;

		// Dtor: Free resources
		$IFMSG ~Message();

		// Substitution ...
		$IFMSG bool substitute( size_t ipos, const char* pString );
		$IFMSG bool substitute( size_t ipos, int value );
		$IFMSG bool substitute( size_t ipos, double value, int nfract=-1 );
		$IFMSG bool substitute( 
			size_t ipos, bool value, BoolOption boop = truefalse );

		// Attribute Getters ...
		$IFMSG const char* getNamespace() const { return m_pNS; };
		$IFMSG const char* getIdentifier() const { return m_pId; };
		$IFMSG SeverityLevel getSeverityLevel() const { return m_eSL; };
		$IFMSG Language getLanguage() const { return m_eLang; };
		$IFMSG const char* getText() const { return m_pTxt; };

		// Retrieve Substituted Message ...
		$IFMSG const char* getMessage() const;

		// Clear Message Text Buffer ...
		$IFMSG void clear();
		$IFMSG void clean();

	private:
		// Private Initializator: Set up text message
		static Message* initMessage( Message* pMsg,
			const char* pNS, const char* pId, 
			SeverityLevel sl, Language lng, const char* pTxt, bool copy );
		// Private Ctor
		Message( 
			const char* pNS, const char* pId, 
			SeverityLevel sl, Language lng, const char* pTxt, bool copy );

		bool findSubstitutionPosition( const size_t& nSub,
			size_t& start, size_t& stop );

		const char* translateOption( const Language& lng, const bool& value,
			const BoolOption& boop ) const;

		// Message properties
		const char* m_pNS;
		const char* m_pId;
		const char* m_pTxt;
		SeverityLevel m_eSL;
		Language m_eLang;
		bool m_bCopy;
		char* m_pNSC;
		char* m_pIdC;
		char* m_pTxtC;

		// Message buffer with substitions
		mutable char* m_pBuffer;
		mutable char* m_pTemplate;
		mutable size_t m_nBufLng;
	};

	// =========================================================================
	// MessageChannel
	//
	// A MessageCannel stands for a logical channel that outputs messages. The 
	// MessageHandler invokes a MessageChannel in virtual interfaces, which are
	// designed to be overwritten in application specific MessageChannel 
	// classes.

	class MessageChannel
	{
		friend class MessageHandler;
	public:
		$IFMSG MessageChannel();
		$IFMSG MessageChannel( const MessageChannel& mch );
		virtual ~MessageChannel();

	protected:
		// Output the Message
		$IFMSG virtual void onMessage( const Message& msg );

		// Additional processing when the message is output 
		$IFMSG virtual void onMessageDone( const Message& msg );
	};

	// =========================================================================
	// FormattingMessageChannel
	//
	// FormattingMessageChannels are MessageChannels that allow to control a 
	// certain amount of formatting of the output message string. 


	class FormattingMessageChannel : public MessageChannel
	{
		friend class MessageHandler;

	public:
		$IFMSG FormattingMessageChannel();
		$IFMSG FormattingMessageChannel( const FormattingMessageChannel& mch );
		$IFMSG ~FormattingMessageChannel();

		// Output the Message
		$IFMSG void onMessage( const Message& msg );

		// Additional processing when the message is output 
		$IFMSG void onMessageDone( const Message& msg );

		// Set Formatting margins
		$IFMSG void setLeftMargin( int lm ) { m_left = lm; };
		$IFMSG int getLeftMargin() const { return m_left; };
		$IFMSG void setRightMargin( int rm ) { m_rite = rm; };
		$IFMSG int getRightMargin() const { return m_rite; };
		$IFMSG void setIndent( int ind ) { m_indent = ind; };
		$IFMSG int getIndent() const { return m_indent; };

		// Format for Id-text-header
		$IFMSG void setTextHeaderFormat( const char* pH ) { m_pHead = pH; };
		$IFMSG const char* getTextHeaderFormat() const { return m_pHead; };

	protected:
		// Output a message line
		void onMessageLine( bool first, bool last, const char* line );
	
	private:
		int	m_left;				// Left margin counted from 0
		int m_rite;				// Right margin counted from 0
		int m_indent;			// Indentation of first line (<0 if left)
		const char* m_pHead;	// Format-string for message-header
	};

	// =========================================================================
	// MessageHandler
	//
	// A MessageHandler is addressed to select and output Messages via up to two
	// MessageCannels. Selection and output is controlled by modal attributes.
	// 'SeverityLevel' controls the output behaviour. Messages of the severity 
	// specified or lower are suppressed. 'LanguageList' controls the selection
	// behaviour in that languages are preferred in the given order.
	// The association of MessageChannels can be loose in which case the 
	// application has to control the lifetime of the MessageChannel objects or 
	// tight in which case these objects are owned by the MessageHandler which
	// controls their lifes then.
	// ...

	class MessageHandler
	{
		friend struct MTE;

	public:
		// Ctor: Stand-alone MessageHandler
		$IFMSG MessageHandler();

		// Ctor: MessageHandler referencing explicit base MessageHandler
		$IFMSG MessageHandler( const MessageHandler* pMH );

		// Dtor: Give up resources
		$IFMSG  ~MessageHandler();

		// Get Static Main Message Handler
		$IFMSG static MessageHandler* object();

		// Modal Controls ...

		// Severity level. Lowest security level being routed to the associated
		// MessageChannels
		$IFMSG void setSeverityLevel( SeverityLevel sl );
		$IFMSG SeverityLevel getSeverityLevel() const;

		// Languages
		$IFMSG void setLanguageList( LanguageList lngl ) /*throw (LanguageInvalid)*/;
		$IFMSG LanguageList getLanguageList() const;

		// Primary channel
		$IFMSG void setMessageChannel( MessageChannel* mch, bool beOwner=true );
		$IFMSG const MessageChannel* getMessageChannel() const { return m_pMsgChannel1; };
		$IFMSG bool getMessageChannelOwnership() const { return m_bOwnChannel1; };

		// Secondary channel
		$IFMSG void setMessageChannel2( MessageChannel* mch, bool beOwner=true );
		$IFMSG const MessageChannel* getMessageChannel2() const { return m_pMsgChannel2; };
		$IFMSG bool getMessageChannel2Ownership() const { return m_bOwnChannel2; };

		// Message Retrieval ...

		// Message object from the keys. 
		$IFMSG Message* getMessage( const char* pNS, const char* pId ) const;
		
		// As above + indicate the quality of language matching.
		$IFMSG Message* getMessage( const char* pNS, const char* pId, int& lmq ) const;

		// Message object for "message not found"
		$IFMSG Message* getMessageNotFound() const;

		// Message Output ...

		$IFMSG void writeMessage( Message& ms );
		$IFMSG void writeMessage1( Message&, const char* pSub );
		$IFMSG void writeMessage2( Message&, const char* pSub1, const char* pSub2 );
		$IFMSG void writeMessage3( Message&, const char* pSub1, const char* pSub2,
			const char* pSub3 );
		$IFMSG void writeMessage4( Message&, const char* pSub1, const char* pSub2,
			const char* pSub3, const char* pSub4 );
		$IFMSG void writeMessageN( Message&, unsigned nSub, const char* pSub[] );

	private:
		// Static Main Message Handler
		static MessageHandler* m_pMainMessageHandler;

		// Severity Level
		SeverityLevel m_eSevLevel;

		// Language List
		LanguageList m_LangList;

		// Message Channel 1 und 2
		MessageChannel* m_pMsgChannel1;
		MessageChannel* m_pMsgChannel2;
		bool m_bOwnChannel1;
		bool m_bOwnChannel2;

		// Static Initialization and Finalization
		void addMTE( MTE*, bool noOverwrite=true )
			/*throw ( MessageExists, LanguageInvalid )*/;

		static void finalize();

		// Hash Table
		class HashTable
		{
		public:

			Language m_Language;
			unsigned int m_nMTESize;
			unsigned int m_nMTEElmt;
			MTE** m_pMTETable;

			// Ctor
			HashTable( HashTable*, unsigned int, Language lng );

			// Dtor
			~HashTable();

			// Hash Function for Message Table Elements
			unsigned int hashMTE( MTE* );
			unsigned int hashMTE( const char* pNS, const char* pId );

			// Hash Table Size for a given No of Elements
			unsigned int hashTableSize( unsigned nel );

			// Insert MTE into Hash Table
			void insertIntoHashTable( MTE* pMTE, MTE* pExi=0, MTE* pPre=0 )
				/*throw (MessageHandlerError)*/;

			// Look up MTE in Hash Table
			MTE* findInHashTable( const char* pNS, const char* pId, MTE*& pPre );

			// Resize Hash Table and reinsert all MTE
			HashTable* resizeHashTable();
		};
		HashTable* m_pTables[LANG_COUNT];	// Array with tables of messages
	};
}

#include "msgdef.h"

#endif

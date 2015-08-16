/* Change-Log: 
* 
* 
*/ 
#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEFOklabiBucketStore
#define DEFOklabiBucketStore

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <string>
#include <list>

#include "OklabiMemoryChunk.h"
#include "OklabiMemoryChunkStore.h"
#include "OklabiKern.h"

namespace Oklabi
{
const UINT64 topSet64(((UINT64)1) << 63);
const UINT64 allSet64((UINT64)(-1));
const unsigned int topSet32(0x80000000);
const unsigned int allSet32(0xFFFFFFFF);

class OklabiBucketStore
{
public:
	OklabiBucketStore(size_t size);
	~OklabiBucketStore();

	void* getBucket() /*throw ( BadAlloc )*/;
	void* getBucket( size_t ) /*throw ( BadAlloc )*/;
	void* getBucket( double size ) /*throw ( BadAlloc )*/ { return getBucket((size_t)size); };
	void freeBucket( void* ) /*throw (NotPresent)*/;
	void freeBucket( void* , size_t);
	void freeBucket( void* p, double size ) { freeBucket(p, (size_t)size); };
	size_t getSize(); // Bucketsize (Byte)

private:
	typedef unsigned char Byte;
	static const unsigned sizWord;
	static const double d;
	size_t m_noAdminWords;	// #Words for Admin-Entries at Begin of Chunk
	size_t m_uSize;			// Bucketsize (Byte)
	
	size_t getNoBuckets( OklabiMemoryChunk* pXMChunk);
	size_t getOffsStart( OklabiMemoryChunk* pXMChunk );
	
	// Read Free-Bit at npos of Chunk
	bool getBit(OklabiMemoryChunk* pXMChunk, size_t npos) /*throw (OutOfBounds)*/;
	// Set  Free-Bit at npos of Chunk
	void setBit(OklabiMemoryChunk* pXMChunk, size_t npos, bool bit) /*throw (OutOfBounds)*/;

	void* getBucket(OklabiMemoryChunk* pXMChunk, size_t npos) /*throw (OutOfBounds)*/;
	size_t FindFreeBucket(OklabiMemoryChunk* pChunk);
	void* getWordAt(OklabiMemoryChunk* pXMChunk, size_t index) /*throw (OutOfBounds)*/;
	
	std::list<OklabiMemoryChunk*> listAssociatedChunks;
	OklabiMemoryChunk* GetNewChunk(size_t minSiz=0) /*throw (CannotCreate)*/;	// get another Chunk

	bool chunkIsEmpty(OklabiMemoryChunk* pXMChunk);

	void cleanup();
};

class OutOfBounds
{
public: OutOfBounds() {};
		~OutOfBounds() {};
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif

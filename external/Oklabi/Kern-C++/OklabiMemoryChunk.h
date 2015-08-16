#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEFOklabiMemoryChunk
#define DEFOklabiMemoryChunk

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiMemoryChunkStore.h"
#include "OklabiRoot.h"

namespace Oklabi
{

class OklabiMemoryChunkStore;

class OklabiMemoryChunk : OklabiRoot
{
	friend class OklabiMemoryChunkStore;
	friend class OklabiBucketStore;
	friend class OklabiHeapStore;
public:
	~OklabiMemoryChunk();
	inline size_t getSize() { return m_size; }
	inline void* getBaseAddr() const	{ return m_pMem; }

private:
	OklabiMemoryChunk( bool& fInPageFile, size_t minSiz = 0 ) /*throw( CannotCreate )*/;

private:
	void*	m_pMem;
	HANDLE	m_hFMap;
	HANDLE	m_hFile;
	bool	m_fInPageFile;

protected:
	size_t m_size;						// Size of this Chunk
	static const size_t	stdChunkSize;	// Default Size of Chunk

};

class CannotCreate
{
public: CannotCreate() {};
		~CannotCreate() {};
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif


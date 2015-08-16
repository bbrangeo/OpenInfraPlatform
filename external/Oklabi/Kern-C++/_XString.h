#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XString
#define DEF_XString

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

//===================================================================================
// - empty String is indicated by m_pBuckets == NULL
//
// - Bucket-Layout
//   - if only one Bucket is used (up to BUCKETSIZE-sizeof(size_t) Elements): first in 
//     the Bucket we have the size; all others Elements following
//   - otherwise: Bucket contains size, followed by last Bucket Adress, followed by
//     the Next-Pointer; then the string-Elements follow
//===================================================================================

#include <string>
#include "OklabiBucketStore.h"
#include "_XContainer.h"
#include "Text.h"

namespace Oklabi
{
class OKLABI_API _XString: public _XContainer
{
	friend class _XStringIteratorContainer;
	friend class _XStringSet;
	friend class _XStringList;

public:
	typedef char			value_type;
	
	_XString();
	~_XString();

	_XString& operator=(const value_type *s);
	_XString& operator=(const int& val);
	_XString& operator=(const Text& rhs);

	bool operator==(const _XString& rhs) const;
	bool operator==(const Text& rhs) const;
	bool operator==(const value_type *s) const;
	friend OKLABI_API bool operator==(const value_type *s, const _XString& rhs);
	bool operator!=(const _XString& rhs) const { return !operator==(rhs); };

	bool operator<(const _XString& rhs) const;

	Text str() const;
	size_t c_str(char* buff, const size_t maxbufflen) const;

	size_t size() const;
	void erase();
	bool empty();

private:
	static const size_t BUCKETSIZE;
	static const size_t Next;

	_XString( const value_type *s );
	void		XFree();
	void*		getLastBucket() const;
	void*		getSecondBucket() const;
	void*		getNextBucket(const void*) const;
	bool		compareBuckets(const void*, const void*, size_t = BUCKETSIZE) const;
	bool		compareFirstBuckets(const void*, const void*) const;

protected:
	void* m_pBuckets;
	static size_t	XSize( const value_type* s );

	class char_iterator
	{
		friend class _XString;
	public:
		bool end();
		bool next(unsigned char&, bool bAdv = true);
	private:
		char_iterator(const _XString& str);
		const _XString* pString;
		void* pCurrBucket;
		void* pLastBucket;
		size_t nSize;
		size_t nPos;
		size_t nLastSize;
		bool bStep;
	};
	friend class char_iterator;

};
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif

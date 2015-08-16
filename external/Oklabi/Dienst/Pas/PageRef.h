#ifndef NO_INCLUDES
#include "system.h"
#include "pas.h"
#include "Exceptions.h"
#else
typedef struct pas_FILE *
     pas_FID;
#endif
#include <set>
class PageNotAccessible
: public structured_exception
{
public:
	PageNotAccessible();
};
typedef	int page;
class PageContext;
class PageRef
{
public: 
	friend class PageContext;
	static unsigned short getSize();
	static void  getStatistics( double&, unsigned int& );
	PageRef( );
	PageRef( unsigned long );
	~PageRef( );
	PageRef& operator=( const PageRef& p );
	bool operator==( const PageRef& p ) const;
	bool operator!=( const PageRef& p ) const;
	bool operator<( const PageRef& p ) const;
	bool operator!( ) const;
	page* allocate( const PageContext* pCtx, size_t size );
	void  deallocate( const PageContext* pCtx, page* pPage );
	page* access( const PageContext* pCtx ) const;
	page* accessFrame( const PageContext* pCtx, page* pPage );
	void deaccess( const PageContext* pCtx, page* pPage ) const;
	void  lock( const PageContext* pCtx, page* pPage );
	void  unlock( const PageContext* pCtx, page* pPage ) const;
	void  setReUseExit( const PageContext* pCtx, page* pPage, void (*ptr)(void*) );
	void  setLogExit( const PageContext* pCtx, void (*ptr)(char*), bool bMod );
	long  getRef( ) const;
	unsigned long  getRef( const PageContext* pCtx, page* pPage ) const;
	void  setWrittenTo( const PageContext* pCtx, page* pPage );
	void  setWorkingSetLimit( const PageContext* pCtx, unsigned nLimit );
protected:
	mutable long		m_pageRef;
};
class PageContext
{
	friend class PageRef;
public:
	PageContext(const char* pName, size_t = 1500);
	PageContext(const PageContext& p);
	PageContext& operator=(const PageContext& p);
	~PageContext();
	void setCleanup(void (*ptr)(void*));
	void setReUseExit( void (*ptr)(void*) );
	void Close();
	void Cleanup();
private:
	pas_FID                   m_fid;
	bool                      m_bClosed;
	mutable std::set<PageRef> m_setLocked;
	size_t                    m_nOffset;
	size_t                    m_nPages;
	void                      (*m_pCleanup)(void*);
	bool                      m_bRundown;
	void                      (*m_pReUseExit)(void*);
};

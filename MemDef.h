#ifndef __MEMDEF_H__
#define __MEMDEF_H__

#define  SAFE_DELETE(ptr)	\
	if ( ptr )			\
	{					\
	delete ptr;		\
	ptr = NULL;		\
	}

#endif // __MEMDEF_H__
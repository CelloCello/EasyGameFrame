#pragma once
#include "SystemTime.h"

/*
 *	自己包裝的log
 */

class HGE;

class GLog
{
public:
	GLog(void);
	~GLog(void);

	static void Print(const char* fmt, ... );

	static HGE* m_Hge;
};

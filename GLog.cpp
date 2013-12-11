#include ".\glog.h"
#include "hge.h"
#include <stdio.h>
#include <stdarg.h>

HGE* GLog::m_Hge = NULL;
GLog::GLog(void)
{
}

GLog::~GLog(void)
{
}
//--------------------------------------------------------------------------------------------------
void GLog::Print(const char* fmt, ... )
{
	char temp[1024];
	va_list argptr;
	va_start( argptr, fmt );
	vsprintf( temp, fmt, argptr );
	va_end(argptr);

	char tempAll_[50];
	SystemTime::GetNowStr(tempAll_);
	::strcat(tempAll_,temp);

	m_Hge->System_Log(tempAll_);
}
//--------------------------------------------------------------------------------------------------
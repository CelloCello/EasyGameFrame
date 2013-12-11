#ifndef _SYSTEMTIME_H_
#define _SYSTEMTIME_H_


/********************************************************************************
時間相關的
**********************************************************************************/
//#include <sql.h>
//#include <sqlext.h>
//#include <sqltypes.h>
//#include <windows.h>
#include <wtypes.h>
#include <time.h>


class PreciseTimer
{
public:
	enum TimerState
	{
		TIMER_RUNNING,
		TIMER_STOPPED,
	};

	float _fTime;
	TimerState _eState;
	LARGE_INTEGER _PerformanceCount;

public:
	PreciseTimer();
	// 啟動計時器
	float Start();
	// 停止計時器，回傳經過時間
	float Stop();
	// 重啟
	void  Restart();

	// 過了幾毫秒
	float GetTime_MS();
	// 過了幾秒
	float GetTime_Second();
	float GetTime() { return GetTime_Second(); }
};


class SystemTime
{
private:
	static PreciseTimer _Timer;
public:
	// 程式啟動後過了幾毫秒
	inline static float FromProcessStart_MS()
	{
		return _Timer.GetTime_MS();
	}
	// 程式啟動後過了幾秒
	inline static float FromProcessStart_S()
	{
		return _Timer.GetTime_Second();
	}
	// 機器啟動後過了幾毫秒
	inline static DWORD FromMachineStart_MS()
	{
		return ::GetTickCount();
	}	

	//取得目前時間
	static inline char *GetNowStr(char *buf)
	{
		time_t		ltime;
		struct tm*	tmnow;

		time( &ltime );
		tmnow = ::localtime( &ltime);

		wsprintf(buf,"%02d:%02d:%02d ",tmnow->tm_hour,tmnow->tm_min,tmnow->tm_sec);
		return(buf);
	}

	// 當前世界時間 ::time(0)
	inline static long From19700101_S()
	{
		return (long)::time(0);
	}
	//inline static long From19700101_S(char* buf)
	//{
	//	TIMESTAMP_STRUCT temp_;
	//	char buffer_[10];

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf,4);
	//	temp_.year = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf+5,4);
	//	temp_.month = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf+8,4);
	//	temp_.day = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf+11,4);
	//	temp_.hour = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf+14,4);
	//	temp_.minute = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,buf+17,4);
	//	temp_.second = atoi(buffer_);

	//	return ConvertTimeStampToLong(temp_);		
	//}	

	inline static char* GetCharTime(char* buf)
	{
		//DWORD now_ = From19700101_S();
		//tm tDate_;
		//::_localtime32_s(&tDate_, (__time32_t*)&now_);
		//::wsprintfA(buf, "%04d/%02d/%02d %02d:%02d:%02d", tDate_.tm_year + 1900, tDate_.tm_mon + 1, tDate_.tm_mday, tDate_.tm_hour, tDate_.tm_min, tDate_.tm_sec);
		//return buf;
	}
	inline static char* GetCharTime(char* buf,DWORD now)
	{
		//tm tDate_;
		//::_localtime32_s(&tDate_, (__time32_t*)&now);
		//::wsprintfA(buf, "%04d/%02d/%02d %02d:%02d:%02d", tDate_.tm_year + 1900, tDate_.tm_mon + 1, tDate_.tm_mday, tDate_.tm_hour, tDate_.tm_min, tDate_.tm_sec);
		//return buf;
	}
	inline static char* GetFileCharTime(char* buf)
	{
		//DWORD now_ = From19700101_S();
		//tm tDate_;
		//::_localtime32_s(&tDate_, (__time32_t*)&now_);
		//::wsprintfA(buf, "%04d%02d%02d_%02d%02d%02d", tDate_.tm_year + 1900, tDate_.tm_mon + 1, tDate_.tm_mday, tDate_.tm_hour, tDate_.tm_min, tDate_.tm_sec);
		//return buf;
	}
	inline static char* GetFileCharTime(char* buf,DWORD now)
	{
		//tm tDate_;
		//::_localtime32_s(&tDate_, (__time32_t*)&now);
		//::wsprintfA(buf, "%04d%02d%02d_%02d%02d%02d", tDate_.tm_year + 1900, tDate_.tm_mon + 1, tDate_.tm_mday, tDate_.tm_hour, tDate_.tm_min, tDate_.tm_sec);
		//return buf;
	}

	inline static void GetTmTime(tm& buf,DWORD now)
	{
		//::_localtime32_s(&buf, (__time32_t*)&now);
		
	}
	inline static void GetTmTime(tm& buf)
	{
		//DWORD now_ = From19700101_S();
		//::_localtime32_s(&buf, (__time32_t*)&now_);
	}



	//// 從過去某個時間到現在過了多久
	//inline static long RemainTimeLong(char *src)
	//{
	//	long temp_ = long(::time(0)) - ConvertCharTimeToLong(src);
	//	if(temp_ > 0)
	//		return temp_*1000;
	//	else
	//		return 0;
	//}



	//inline static long ConvertCharTimeToLong(char *src)
	//{
	//	//2000/11/11 23:23:23
	//	TIMESTAMP_STRUCT temp_;
	//	char buffer_[10];

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src,4);
	//	temp_.year = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src+5,4);
	//	temp_.month = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src+8,4);
	//	temp_.day = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src+11,4);
	//	temp_.hour = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src+14,4);
	//	temp_.minute = atoi(buffer_);

	//	ZeroMemory(buffer_,sizeof(buffer_));
	//	CopyMemory(buffer_,src+17,4);
	//	temp_.second = atoi(buffer_);

	//	return ConvertTimeStampToLong(temp_);
	//}

	//inline static long ConvertTimeStampToLong(TIMESTAMP_STRUCT& tDate)
	//{
	//	tm tDate_;
	//	tDate_.tm_year	= tDate.year - 1900;
	//	tDate_.tm_mon	= tDate.month - 1;
	//	tDate_.tm_mday	= tDate.day;
	//	tDate_.tm_hour	= tDate.hour;
	//	tDate_.tm_min	= tDate.minute;
	//	tDate_.tm_sec	= tDate.second;
	//	return long(::mktime(&tDate_));
	//}

	// 年：月(1~12)
	inline static long ConvertTMToLong(tm tDate)
	{
		tDate.tm_year	= tDate.tm_year - 1900;
		tDate.tm_mon	= tDate.tm_mon - 1;
		return long(::mktime(&tDate));
	}


	// 配合 pushEvent 使用 interval 單位：秒
	// 從 tDate 累加 interval 直到超過當前時間
	inline static long ConvertNextStartTick(tm& tDate,long interval)
	{
		long next_ = ConvertTMToLong(tDate);
		long now_ = From19700101_S();

		if(next_<now_)
		{
			if(interval <= 0)
				next_ = now_;
			else
			{
				while(next_<=now_)
					next_ += interval;
			}
			return (next_-now_)*1000;
		}
		else
		{
			return (next_-now_)*1000;
		}

	}

	//// 配合 pushEvent 使用 interval 單位：秒
	//// 從 time(ex:2000/11/11 23:23:23) 累加 interval 直到超過當前時間
	//inline static long ConvertNextStartTick(char* time,long interval)
	//{
	//	long next_ = ConvertCharTimeToLong(time);
	//	long now_ = From19700101_S();

	//	if(next_<now_)
	//	{
	//		if(interval <= 0)
	//			next_ = now_;
	//		else
	//		{
	//			while(next_<=now_)
	//				next_ += interval;
	//		}
	//		return (next_-now_)*1000;
	//	}
	//	else
	//	{
	//		return (next_-now_)*1000;
	//	}

	//}
};



#endif

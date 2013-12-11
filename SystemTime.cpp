//#include "stdafx.h"
#include "SystemTime.h"


PreciseTimer SystemTime::_Timer;


PreciseTimer::PreciseTimer(void)
{
	Restart();
}

float PreciseTimer::Start(void)
{
	_eState = TIMER_RUNNING;
	QueryPerformanceCounter(&_PerformanceCount);
	return _fTime;
}

float PreciseTimer::Stop(void)
{
	_eState = TIMER_STOPPED;

	LARGE_INTEGER pcount;
	QueryPerformanceCounter(&pcount);

	LARGE_INTEGER counter_frequency;
	QueryPerformanceFrequency(&counter_frequency);

	LARGE_INTEGER count_diff;
	count_diff.QuadPart = pcount.QuadPart - _PerformanceCount.QuadPart;
	float time_diff = (float) count_diff.QuadPart / (float) counter_frequency.QuadPart;

	_fTime += time_diff;

	return _fTime;
}

void PreciseTimer::Restart(void)
{
	_eState = TIMER_RUNNING;
	_fTime = 0;
	QueryPerformanceCounter(&_PerformanceCount);
}

float PreciseTimer::GetTime_MS(void)
{
	return GetTime_Second() * 1000.0f;
}

float PreciseTimer::GetTime_Second(void)
{
	if ( _eState==TIMER_RUNNING )
	{
		LARGE_INTEGER pcount;
		QueryPerformanceCounter(&pcount);

		LARGE_INTEGER counter_frequency;
		QueryPerformanceFrequency(&counter_frequency);

		LARGE_INTEGER count_diff;
		count_diff.QuadPart = pcount.QuadPart - _PerformanceCount.QuadPart;
		float time_diff = (float) count_diff.QuadPart / (float) counter_frequency.QuadPart;

		return time_diff;
	}
	else
	{
		return _fTime;
	}
}



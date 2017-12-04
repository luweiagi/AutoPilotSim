#include "timer.h"
#include <stdint.h>
#include <windows.h>

uint32_t millis(void)
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER time;

	QueryPerformanceFrequency(&nFreq);//获得当前的计数频率,即每秒进行多少次计数
	QueryPerformanceCounter(&time);//获取当前计数次数
	uint32_t time_millis = (uint32_t)(((double)time.QuadPart / (double)nFreq.QuadPart) * 1000);

	return time_millis;
}

uint32_t micros(void)
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER time;

	QueryPerformanceFrequency(&nFreq);//获得当前的计数频率,即每秒进行多少次计数
	QueryPerformanceCounter(&time);//获取当前计数次数
	uint32_t time_micros = (uint32_t)(((double)time.QuadPart / (double)nFreq.QuadPart) * 1000000);

	return time_micros;
}
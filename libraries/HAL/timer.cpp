#include "timer.h"
#include <stdint.h>
#include <windows.h>

uint32_t millis(void)
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER time;

	QueryPerformanceFrequency(&nFreq);//��õ�ǰ�ļ���Ƶ��,��ÿ����ж��ٴμ���
	QueryPerformanceCounter(&time);//��ȡ��ǰ��������
	uint32_t time_millis = (uint32_t)(((double)time.QuadPart / (double)nFreq.QuadPart) * 1000);

	return time_millis;
}

uint32_t micros(void)
{
	LARGE_INTEGER nFreq;
	LARGE_INTEGER time;

	QueryPerformanceFrequency(&nFreq);//��õ�ǰ�ļ���Ƶ��,��ÿ����ж��ٴμ���
	QueryPerformanceCounter(&time);//��ȡ��ǰ��������
	uint32_t time_micros = (uint32_t)(((double)time.QuadPart / (double)nFreq.QuadPart) * 1000000);

	return time_micros;
}
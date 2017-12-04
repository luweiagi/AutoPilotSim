
#include "Maths.h"

template <typename T>
float safe_sqrt(const T v)
{
	float ret = sqrtf(static_cast<float>(v));
	if (isnan(ret)) 
	{
		return 0;
	}
	return ret;
}

template float safe_sqrt<int>(const int v);
template float safe_sqrt<short>(const short v);
template float safe_sqrt<float>(const float v);
template float safe_sqrt<double>(const double v);

float constrain_float(float value, float min, float max)
{
	if (value < min)
	{
		value = min;
	}
	else if(value > max)
	{
		value = max;
	}
	return value;
}

#pragma once
#include <math.h>
#include <cmath>
#include <limits>
#include <stdint.h>



// @brief: Check whether a float is zero
template <typename T>
inline bool is_zero(const T fVal1) 
{
	return (fabsf(static_cast<float>(fVal1)) < FLT_EPSILON);
}


template <typename T>
float safe_sqrt(const T v);



float constrain_float(float value, float min, float max);

template<typename T>
float sq(const T val)
{
	return powf(static_cast<float>(val), 2);
}


#if defined(HAVE_CMATH_ISFINITE) && defined(NEED_CMATH_ISFINITE_STD_NAMESPACE)
using std::isfinite;
#endif

#if defined(HAVE_CMATH_ISINF) && defined(NEED_CMATH_ISINF_STD_NAMESPACE)
using std::isinf;
#endif

#if defined(HAVE_CMATH_ISNAN) && defined(NEED_CMATH_ISNAN_STD_NAMESPACE)
using std::isnan;
#endif

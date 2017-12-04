#include "CopterAttitudeControl.h"
#include "../Maths/Maths.h"

// Proportional controller with piecewise sqrt sections to constrain second derivative
float CopterAttitudeControl::sqrt_controller(float error, float p, float second_ord_lim)
{
	if (second_ord_lim < 0.0f || is_zero(second_ord_lim) || is_zero(p)) {
		return error*p;
	}

	float linear_dist = second_ord_lim / sq(p);

	if (error > linear_dist) {
		return safe_sqrt(2.0f*second_ord_lim*(error - (linear_dist / 2.0f)));
	}
	else if (error < -linear_dist) {
		return -safe_sqrt(2.0f*second_ord_lim*(-error - (linear_dist / 2.0f)));
	}
	else {
		return error*p;
	}
}


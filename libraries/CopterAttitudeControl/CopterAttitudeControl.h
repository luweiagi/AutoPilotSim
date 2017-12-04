#pragma once

class CopterAttitudeControl
{
public:
	CopterAttitudeControl():
		_KpPos(1.0f/3.0f)
	{
		;
	}

	float getKpPos(void) { return _KpPos; }

	// Proportional controller with piecewise sqrt sections to constrain second derivative
	static float sqrt_controller(float error, float p, float second_ord_lim);

private:
	float _KpPos;
};
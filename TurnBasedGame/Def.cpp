#include "Def.h"



Def::Def()
{
	
}


Def::~Def()
{
}

float Def::Clamp(float value, float min, float max)
{
	value = value < min ? min : value;
	value = value > max ? max : value;
	return value;
}

float Def::Min(float value, float min)
{
	return value < min ? min : value;
}

float Def::Max(float value, float max)
{
	return value > max ? max : value;
}

float Def::Lerp(float value, float goal, float procent)
{
	return 0.0f;
}

float Def::SQRT2(const float aX)
{
	const float xhalf = 0.5f*aX;

	union // get bits for floating value
	{
		float x;
		int i;
	} u;

	u.x = aX;
	u.i = SQRT_MAGIC_F - (u.i >> 1);  // gives initial guess y0

	return aX * u.x*(1.5f - xhalf * u.x*u.x); // Newton step, repeating increases accuracy 
}

float Def::DtoR(const float aD)
{
	return aD / (180 / PI);
}

float Def::RtoD(const float aR)
{
	return aR * (180 * PI);
}

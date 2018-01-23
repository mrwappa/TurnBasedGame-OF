#ifndef DEF_H
#define DEF_H

#define and &&
#define or ||
#define MB_LEFT 0
#define MB_MIDDLE 1
#define MB_RIGHT 2
#define	SQRT_MAGIC_F 0x5f3759df 
#define M_PI 3.141592653589793238462643383279
#define PI 3.14159265358979323846 
#endif // !DEF_H


static class Def
{
public:
	Def();
	~Def();

	//Quickt
	static float Clamp(float value, float min, float max);
	static float Min(float value, float min);
	static float Max(float value, float max);
	static float Lerp(float value, float goal, float procent);
	static float SQRT2(const float aX);
	static float DtoR(const float aD);
	static float RtoD(const float aR);

};


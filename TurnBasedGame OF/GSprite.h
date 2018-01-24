#ifndef SPRITE_H
#define SPRITE_H

#include "ofImage.h"
#include "Def.h"
#include "ofGraphics.h"


class GSprite
{
public:
	GSprite();
	~GSprite();

	void Draw(float aX, float aY, float aXScale, float aYScale, float aAngle, float aDepth, float aAlpha, ofColor aColor, float aAnimationSpeed);

	//Modifiers
#pragma region
	void SetTexture(std::string aFileName, int aNrOfFrames);

#pragma endregion
private:
	ofImage myImage;

	float myDepth;
	float myWidth;
	float myHeight;
	float myTextureWidth;
	float myTextureHeight;

	float myNrOfFrames;
	float myAnimationIndex;
	float myAnimationSpeed;
	float myAnimationCounter;
};
#endif // !GSPRITE_H
#include "Sprite.h"


Sprite::Sprite()
{
	
}


Sprite::~Sprite()
{
}

void Sprite::Draw(float aX, float aY, float aXScale, float aYScale, float aAngle, float aDepth, float aAlpha, ofColor aColor, float aAnimationSpeed)
{
	myWidth = myTextureWidth * aXScale;
	myHeight = myTextureHeight * aYScale;
	myImage.resize(myWidth, myHeight);

	myAnimationSpeed = Def::Clamp(aAnimationSpeed,0,1);
	if (myAnimationSpeed > 0)
	{
		myAnimationCounter += myAnimationSpeed;
		if (myAnimationCounter >= 1)
		{
			myAnimationIndex++;
			myAnimationCounter--;
			if (myAnimationIndex >= myNrOfFrames)
			{
				myAnimationIndex = 0;
			}
		}
	}
	myImage.setColor(aColor);
	myImage.setAnchorPoint(myTextureWidth / myNrOfFrames / 2, myTextureHeight / 2);
	ofRotate(aAngle);
	myImage.draw(aX, aY, aDepth);
}

void Sprite::SetTexture(std::string aFileName, int aNrOfFrames)
{
	myNrOfFrames = aNrOfFrames;
	myImage.loadImage(aFileName);
	myTextureWidth = myImage.getWidth();
	myTextureHeight = myImage.getHeight();
}

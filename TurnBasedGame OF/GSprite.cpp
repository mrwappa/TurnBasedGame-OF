#include "GSprite.h"


GSprite::GSprite()
{
	myAnimationCounter = 0;
	myAnimationIndex = 0;
	myAnimationSpeed = 0;
}


GSprite::~GSprite()
{
}

void GSprite::Draw(float aX, float aY, float aXScale, float aYScale, float aAngle, float aDepth, float aAlpha, ofColor aColor, float aAnimationSpeed)
{

	myWidth = myTextureWidth * aXScale;
	myHeight = myTextureHeight * aYScale;
	myImage.crop(0, 0, myWidth/2, myTextureHeight);
	myImage.resize(myWidth, myHeight);

	myAnimationSpeed = Def::Clamp(aAnimationSpeed, 0, 1);
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

	//myImage.crop(myAnimationIndex * myTextureWidth / myNrOfFrames, 0, myTextureWidth / myNrOfFrames, myTextureHeight);
	myImage.setColor(ofColor(aColor.r, aColor.g, aColor.b, aAlpha * 255));
	myImage.setAnchorPoint(myTextureWidth / myNrOfFrames / 2, myTextureHeight / 2);
	ofRotate(aAngle);
	myImage.draw(aX, aY, aDepth);

}

void GSprite::SetTexture(std::string aFileName, int aNrOfFrames)
{
	myImage.load(aFileName);
	myNrOfFrames = aNrOfFrames;

	myTextureWidth = myImage.getWidth();
	myTextureHeight = myImage.getHeight();
	int aspec = myTextureWidth / myTextureHeight;
	

}

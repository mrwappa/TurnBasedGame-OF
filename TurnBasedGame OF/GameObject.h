#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>
#include "GrowingArray.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "ofAppBaseWindow.h"
#include "GSprite.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	static std::map<std::string, GrowingArray<GameObject*>*> SuperList;
	static std::map<std::string, GrowingArray<GameObject*>*> ClassHierarchy;

	void AddInstance(GameObject* aGameObject);
	void DestroyInstance(GameObject* aGameObject);

	//Init,Update,Draw
	virtual void BeginUpdate();
	virtual void Update();
	virtual void EndUpdate();
	virtual void Draw();
	virtual void DrawGUI();

	bool KeyboardCheck(int aKey);
	bool KeyboardCheckPressed(int aKey);
	bool KeyboardCheckRelease(int aKey);
	bool KeyboardCheckReleased(int aKey);
	bool MouseCheck(int aButton);
	bool MouseCheckPressed(int aButton);
	bool MouseCheckRelease(int aButton);
	bool MouseCheckReleased(int aButton);

	bool MouseWheelUp();
	bool MouseWheelDown();

	int GameMouseX();
	int GameMouseY();
	int GUIMouseX();
	int GUIMouseY();

protected:
	float myX;
	float myY;
	float myDepth;
	float myAngle;
	float myXScale;
	float myYScale;
	float myAlpha;

	GSprite mySprite;
	ofColor myColor;
	float myAnimationSpeed;

	bool myActive;

private:
	static GrowingArray<GameObject*>* GrArrayPtr;
};
#endif // !GAMEOBJECT_H
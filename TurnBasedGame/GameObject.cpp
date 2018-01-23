#include "GameObject.h"


std::map<std::string, GrowingArray<GameObject*>*> GameObject::SuperList;
std::map<std::string, GrowingArray<GameObject*>*> GameObject::ClassHierarchy;
GrowingArray<GameObject*>* GameObject::GrArrayPtr;

GameObject::GameObject()
{
	myActive = true;
	myDepth = 0;
	myAngle = 0;
	myXScale = 1;
	myYScale = 1;
	myAlpha = 1;

	myColor = ofColor::white;
	myAnimationSpeed = 0;
	myActive = true;
	
	AddInstance(this);

	GrArrayPtr = nullptr;

	
}


GameObject::~GameObject()
{
}

void GameObject::AddInstance(GameObject * aGameObject)
{
	//check if key doesnt exist
	if (SuperList.count(typeid(aGameObject).name()) == 0)
	{
		SuperList[typeid(aGameObject).name()] = new GrowingArray<GameObject*>;
	}
	GrArrayPtr = SuperList.at(typeid(aGameObject).name());
	GrArrayPtr->Add(aGameObject);
	GrArrayPtr = nullptr;
}

void GameObject::DestroyInstance(GameObject * aGameObject)
{
	GrArrayPtr = SuperList.at(typeid(aGameObject).name());
	GrArrayPtr->DeleteCyclic(aGameObject);
	GrArrayPtr = nullptr;
}

//Init,Update,Draw
void GameObject::BeginUpdate()
{
}

void GameObject::Update()
{
}

void GameObject::EndUpdate()
{
}

void GameObject::Draw()
{
	mySprite.Draw(myX, myY, myXScale, myYScale, myAngle, myDepth, myAlpha, myColor, myAnimationSpeed);
}

void GameObject::DrawGUI()
{
}

bool GameObject::KeyboardCheck(int aKey)
{
	return InputHandler::Keys[aKey] > 0;
}

bool GameObject::KeyboardCheckPressed(int aKey)
{
	return InputHandler::Keys[aKey] == 2;
}

bool GameObject::KeyboardCheckRelease(int aKey)
{
	return InputHandler::Keys[aKey] == 0;
}

bool GameObject::KeyboardCheckReleased(int aKey)
{
	return InputHandler::Keys[aKey] == -1;
}

bool GameObject::MouseCheck(int aButton)
{
	return InputHandler::Mouse[aButton] > 0;
}

bool GameObject::MouseCheckPressed(int aButton)
{
	return InputHandler::Mouse[aButton] == 2;
}

bool GameObject::MouseCheckRelease(int aButton)
{
	return InputHandler::Mouse[aButton] == 0;
}

bool GameObject::MouseCheckReleased(int aButton)
{
	return InputHandler::Mouse[aButton] == -1;
}

bool GameObject::MouseWheelUp()
{
	return InputHandler::ScrollWheel[0];
}

bool GameObject::MouseWheelDown()
{
	return InputHandler::ScrollWheel[1];
}

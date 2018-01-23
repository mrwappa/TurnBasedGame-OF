#include "GameObject.h"


std::map<std::string, GrowingArray<GameObject*>*> GameObject::SuperList;
std::map<std::string, GrowingArray<GameObject*>*> GameObject::ClassHierarchy;

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
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
}

void GameObject::DrawGUI()
{
}

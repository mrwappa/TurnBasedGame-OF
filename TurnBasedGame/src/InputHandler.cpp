#include "InputHandler.h"

bool InputHandler::KeyPress[8196];
int InputHandler::Keys[8196];
bool InputHandler::MousePress[8196];
int InputHandler::Mouse[8196];
bool InputHandler::ScrollWheel[2];

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

void InputHandler::Update()
{
	for (int i = 0; i < 127; i++)
	{
		Keys[i] = Keys[i] > 0 ? -1 : 0;
		if (KeyPress[i])
		{
			Keys[i] += 2;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		Mouse[i] = Mouse[i] > 0 ? -1 : 0;
		if (MousePress[i])
		{
			Mouse[i] += 2;
		}
	}

}

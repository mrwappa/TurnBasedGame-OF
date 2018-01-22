#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void Update();

	static bool KeyPress[8196];
	static int Keys[8196];
	static bool MousePress[8196];
	static int Mouse[8196];
};
#endif // !INPUTHANDLE_H
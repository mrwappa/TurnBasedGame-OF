#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(float aX, float aY);
	~Player();
	
	void Update();
	void Draw();
};
#endif // !PLAYER_H
#pragma once

#include "rect.h"

class Player
{
public:
	Player();
	~Player();

	bool checkCollidedWith(const rect& other);

private:
	rect collisionBox;
};

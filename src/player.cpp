#include "include/player.h"

Player::Player()
{
}

Player::~Player()
{
}

bool Player::checkCollidedWith(const rect& other)
{
	return intersects(collisionBox, other);
}

#pragma once
#include "../sprite.h"

class CollisionManager
{
public:
	static void resolveCollision(Sprite& first, const Sprite& other);
	//static void resolveCollision(TileMap& map, GameObject& first);
	//static void resolveCollision(GameObject& first, TileMap& map);
};
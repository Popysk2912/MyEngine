#pragma once
#include "Randomizer.h"
#include "glm/glm.hpp"

#include "Engine/Managers/ResourceManager.h"
#include "Engine/sprite.h"
#include "Engine/spriteRenderer.h"

class Tile
{
private:
	Sprite sprite;
    Sprite flagSprite;
    Texture2D texture;
	Texture2D flagTexture;
	Texture2D hiddenTexture;

	glm::vec2 position;

	bool hidden = true;
	bool flagged = false;
	int num;

public:
	Tile(float x, float y, float offset_X, float offset_Y);
	void setImage();

	bool isOpen() const;
	bool isFlagged() const;

	void flag();
	void open();

	int getNum() const;
	void setNum(int num);
	
	void draw(SpriteRenderer& renderer);
};
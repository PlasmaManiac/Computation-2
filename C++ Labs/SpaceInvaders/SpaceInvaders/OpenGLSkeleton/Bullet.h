#pragma once
#include "drawtools.h"
#include "GameObjects.h"
using GameList = std::list<GameObjects*>;
class bullet : public GameObjects
{
public:

	bullet(int x, int y, bool enemy, PointI* window);
	//checks for colision with either the player or enemy ships
	bool checkCollision(GameList* checklist) override;
	//updates the position of the bullet
	void update(float dT) override;
	void draw() const override;
	void print() const override;
	void shoot() override;

private:
	// the width of the bullet
	int _width;
	// the length of the bullet
	int _length;
};
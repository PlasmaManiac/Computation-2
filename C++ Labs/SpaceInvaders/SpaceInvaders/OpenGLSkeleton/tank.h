#pragma once
#include "drawtools.h"
#include "GameObjects.h"
#include "Interface.h"
#include <SFML\Audio.hpp>

using GameList = std::list<GameObjects*>;

class tank : public GameObjects
{
public:
	tank(int x, DrawList* dlist, GameList* glist, PointI* window, interface* inter);

	//the x position of the tank
	int _x;
	int _y;

	int lives;
	//checks for collision
	bool checkCollision(GameList* checklist) override;

	//updates the position of the tank
	void update(float dt) override;
	// renders/draws the tank
	void draw() const override;
	// shoots a bullet
	void shoot() override;
	void attackReset(int value);
	void print() const override;

	static bool _right;
	static bool _left;
	static bool _shoot;
	static bool _ready;
	bool _color;

	DrawList* _dlist;
	GameList* _glist;
	interface* _inter;

	sf::SoundBuffer shootbuffer;
	sf::Sound fire;

	sf::SoundBuffer deathbuffer;
	sf::Sound death;

private:

};
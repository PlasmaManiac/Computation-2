#pragma once

#include "alien.h"
#include "GameObjects.h"
#include "drawlist.h"
#include "Interface.h"

#include <SFML/Audio.hpp> 

using GameList = std::list<GameObjects*>;
using pointI = Point<int>;

class AlienSwarm
{
public:
	AlienSwarm(int size, pointI* _window, DrawList* _drawList, GameList* _gameList, interface* score);
	int _size;
	int* _score;
	float _speed;
	bool _ready;
	bool _shooting;

	pointI* _window;
	interface* _interface;
	GameList* _alienList;
	DrawList* _drawList;
	GameList* _gameList;

	sf::SoundBuffer buffer;
	sf::Sound death;

	void populate(int size);
	void moveDown(bool side);
	void shoot(int randAlien);
	void clear();
private:
};
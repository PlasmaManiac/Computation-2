#pragma once

#include "alien.h"
#include "GameObjects.h"
#include "drawlist.h"
#include "Interface.h"
#include <SFML/Audio.hpp>
#include <iostream>

using GameList = std::list<GameObjects*>;
using namespace std;

AlienSwarm::AlienSwarm(int size, pointI* window, DrawList* drawList, GameList* gameList, interface* interface)
{
	_window = window;
	_size = size;
	_speed = 0.18;
	_ready = false;
	_shooting = false;
	_drawList = drawList;
	_gameList = gameList;
	_interface = interface;
	_alienList = new GameList;

	buffer.loadFromFile("SI_Destroy.wav");
	death.setBuffer(buffer);
}


void AlienSwarm::populate(int size)
{
	_size = size;
	_ready = true;

	if (_alienList->size() != 0)
		return;

	float windowX = ((float)_window->x());
	float windowY = ((float)_window->y());

	int perRow = (windowX/2.0) / 100;
	int rows = _size / perRow;

	for (int y = 0; y < rows; y++ )
	{
		for (int x = 0; x < perRow; x++)
		{
			alien* newAlien = new alien((x * 100), (windowY*3/4 - 80*y), _speed, _window, this, _gameList);

			_alienList->push_back(newAlien);
			_drawList->push_back(newAlien);
			_gameList->push_back(newAlien);
		}
	}
}

void AlienSwarm::moveDown(bool side)
{
	for (auto alien = _alienList->begin(); alien != _alienList->end(); alien++)
	{
		(*alien)->_pos.y() -= 20;
		(*alien)->_speed = -1 * (*alien)->_speed;

		if (side)
			(*alien)->_pos.x() = (*alien)->_pos.x() - _size - 1;
		else
			(*alien)->_pos.x() = (*alien)->_pos.x() + _size + 1;
	}
}

void AlienSwarm::shoot(int randAlien)
{
	auto shooter = _alienList->begin(); 
	for (int i = 1; i < randAlien; i++)
		shooter++;
	 (*shooter)->shoot();
}

void AlienSwarm::clear()
{
	_ready = false;
	_shooting = false;
	for (auto alien = _alienList->begin(); alien != _alienList->end();)
	{
		delete (*alien);
		_drawList->remove((*alien));
		_gameList->remove((*alien));
		alien = _alienList->erase(alien);
	}
}
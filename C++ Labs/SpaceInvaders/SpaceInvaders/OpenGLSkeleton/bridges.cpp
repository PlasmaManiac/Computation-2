#pragma once
#include "Bridges.h"
#include "drawtools.h"
#include "GameObjects.h"
#include "glut.h"

bridge::bridge(pointI* window, DrawList* drawList, GameList* gameList, int place)
{
	_window = window;
	_drawList = drawList;
	_gameList = gameList;
	_brickList = new GameList;
	_place = place;

	_pos = {_window->x() *( 1 + 7*place)/16, 200};

	create();
}


brick::brick(PointI* pos, PointI* window, bridge* bridge, GameList* gList, DrawList* dList)
{
	_pos = *pos;
	_size = 10;
	_drawList = dList;
	_gameList = gList;
	_bridge = bridge;
}
void brick::draw() const
{
	float _x = _pos.x();
	float _y = _pos.y();

	glBegin(GL_TRIANGLE_STRIP); // Start drawing a triangle strip primitive
	// The first triangle
	glColor3f(0.1f, 0.8f, 0.1f);

	glVertex2f(_x, _y + _size); // The top left corner
	glVertex2f(_x + _size, _y + _size); // The top rightcorner

	glVertex2f(_x, _y); // The top right corner
	// The end of the second triangle
	glVertex2f(_x + _size, _y); // The bottom right corner
	//glVertex2f(0, 0); // The bottom left corner

	glEnd();
}

void brick::shoot()
{
}
void brick::print() const
{

}
void brick::update(float dt)
{
	//_pos.updatePos(_window->x(), _window->y());
}

bool brick::checkCollision(GameList* checklist)
{
	if (_delete)
	{
		_bridge->_brickList->remove(this);
		return true;
	}
	for (auto gObject = checklist->begin(); gObject != checklist->end(); gObject++)
	{
		if ((_pos.x() >= (*gObject)->_pos.x()) && (_pos.x() <= (*gObject)->_pos.x() + (*gObject)->_size))
		{
			if ((_pos.y() < (*gObject)->_pos.y() + (*gObject)->_size) && ((_pos.y()) > (*gObject)->_pos.y()))
			{
				//Collided
				(*gObject)->_delete = true;
				return true;
			}
		}
		return false;
	}
}

void bridge::updatePos()
{
	_pos = { _window->x() *(1 + 6 * _place) / 16, 200 };
	clear();
	create();
}

void bridge::clear()
{
	for (auto brick = _brickList->begin(); brick != _brickList->end();)
	{
		delete (*brick);
		_drawList->remove((*brick));
		_gameList->remove((*brick));
		brick = _brickList->erase(brick);
	}
}

void bridge::create()
{
	for (int row = 0; row < 10; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			PointI* brickPos = new PointI(_pos.x() + column * 10, _pos.y() + row * 10);
			brick* newBrick = new brick(brickPos, _window, this, _gameList, _drawList);

			_drawList->push_back(newBrick);
			_gameList->push_back(newBrick);
			_brickList->push_back(newBrick);
		}
	}
}
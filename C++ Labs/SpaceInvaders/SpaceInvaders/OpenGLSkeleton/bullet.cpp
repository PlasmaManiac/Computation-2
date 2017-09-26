#include "bullet.h"
#include "glut.h"
#include "drawlist.h"

#include <iostream>

using PointF = Point<float>;
using GameList = std::list<GameObjects*>;

bullet::bullet(int x, int y, bool enemy, PointI* window)
{
	_pos = PointI(x, y);
	_window = window;
	//whether or not it is an enemy bullet
	_enemy = enemy;
	// the color of the bullet
	if (!enemy)
		_color = Color(0, 1, 0);
	else
		_color = Color(1, 0, 0);
	_speed = 0.5;
	// the width of the bullet
	_width = 50;
	// the length of the bullet
	_length = 10;
	_enemy = enemy;
	_size = _width;
};

void bullet::draw() const
{
	// Set the width of the line
	glLineWidth(_width);

	glBegin(GL_LINES); // Start drawing mode

	// Set color
	glColor3f(_color.r(), _color.g(), _color.b());

	// Draw from the start position in _begin
	glVertex2f(_pos.x(),_pos.y());

	// Draw to the end position in _end
	glVertex2f(_pos.x(), _pos.y() + _length);

	glEnd();
}

void bullet::update(float dT)
{
	if (_enemy)
		_pos.y() += dT *-_speed;
	else
		_pos.y() += dT * _speed;	

}
bool bullet::checkCollision(GameList* checklist)
{
	if (_delete)
	{
		return true;
	}

	if (_pos.y() > _window->y() || _pos.y() < 0)
	{
		return true;
	}
	if (_pos.x() >_window->x())
	{
		return true;
	}

	for (auto gObject = checklist->begin(); gObject != checklist->end(); gObject++)
	{
		if (_enemy != (*gObject)->_enemy)
		{
			if ((_pos.x() >= (*gObject)->_pos.x() ) && (_pos.x() <= (*gObject)->_pos.x() + (*gObject)->_size))
			{
				if ((_pos.y() < (*gObject)->_pos.y() + (*gObject)->_size) && ((_pos.y()) > (*gObject)->_pos.y()))
				{
					//Collided
					(*gObject)->_delete = true;
					return true;
				}
			}
		}
	}
	return false;
}
void bullet::print() const
{}

void bullet::shoot() 
{}


// I am Luke.
// I am Stupid.
// Thanks for your time.
// I just wasted 40 minuts of my brothers time.
// GOODBYE
// NOT LIKE THIS
//KEEPO

#include "alien.h"
#include "glut.h"
#include "drawlist.h"
#include "AlienSwarm.h"
#include "Bullet.h"
using PointF = Point<float>;

alien::alien(int x, int y, float speed, PointI* window, AlienSwarm* swarm, GameList* gList)
{
	_pos = PointI(x, y);
	_swarm = swarm;
	_window = window;
	// the color of the alien
	_color = Color(1, 0, 0);
	_speed = speed;
	// the size of the alien
	_size = 40;
	_gList = gList;
	_dlist = swarm->_drawList;
	_enemy = true;
};

void alien::draw() const
{
	glBegin(GL_TRIANGLE_STRIP); // Start drawing a triangle strip primitive
	// The first triangle
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(_pos.x(), _pos.y() + _size); // The top left corner
	glVertex2f(_pos.x() + _size, _pos.y() + _size); // The top rightcorner

	glVertex2f(_pos.x(), _pos.y()); // The top right corner
	// The end of the second triangle
	glVertex2f(_pos.x() + _size, _pos.y()); // The bottom right corner
	//glVertex2f(0, 0); // The bottom left corner

	glEnd();
}

void alien::update(float dT)
{
	if ((_pos.x() + _size) > _window->x())
	{
		//_speed = -_speed;
		//_pos.x() = _window->x() - _size - 1;
		//_pos.y() -= _size;
		_swarm->moveDown(true);
	}
	else if (_pos.x() < 0)
	{
		//_speed = -_speed;
		//_pos.x() = 0 + _size + 1;
		//_pos.y() -= _size;
		_swarm->moveDown(false);
	}
	else
		_pos.x() += dT *_speed;

}
bool alien::checkCollision(GameList* checklist)
{
	if (_delete)
	{
		if (_swarm->_interface->_sfx.onOff != 0)
		_swarm->death.play();
		_swarm->_interface->updateScore();
		_swarm->_alienList->remove(this);
		return true;
	}
	return false;
}

void alien::shoot()
{
	bullet* newBullet = new bullet(_pos.x() + _size / 2, _pos.y() - _size - 1, true, _window);
	_dlist->push_back(newBullet);
	_gList->push_back(newBullet);
}

void alien::print() const{

}
#include "tank.h"
#include "bullet.h"
#include "glut.h"
#include "drawlist.h"
#include "GameObjects.h"
#include "Interface.h"
#include <iostream>

bool tank::_right;
bool tank::_left;
bool tank::_shoot;
bool tank::_ready;
using GameList = std::list<GameObjects*>;
static GLuint texName;

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];


tank::tank(int x, DrawList* dlist, GameList* glist, PointI* window, interface* inter)
{
	_pos = { x, 0 };
	_x = x;
	_y = 0;
	_speed = 0.80;
	lives = 3;
	_size = 100;

	_dlist = dlist;
	_glist = glist;

	_window = window;
	_enemy = false;
	_color = false;

	dlist->push_front(this);
	glist->push_front(this);
	_inter = inter;
	
	if (!shootbuffer.loadFromFile("SI_Fire.wav"))
		std::cout << "couldn't open file" << endl;
	fire.setBuffer(shootbuffer);

	if (!deathbuffer.loadFromFile("SI_Die.wav"))
		std::cout << "couldn't open file" << endl;
	death.setBuffer(deathbuffer);

	_ready = true;



}

void tank::draw() const
{
	
	glBegin(GL_TRIANGLE_STRIP); // Start drawing a triangle strip primitive
	// The first triangle
	
		
	if ( _inter->_state == 3)
	{
			glColor3f(1.0f, 0, 0.2f);
	}
	else
		glColor3f(0.1f, 0.8f, 0.1f);

	glVertex2f(_x, _y + _size); // The top left corner
	glVertex2f(_x + _size, _y + _size); // The top rightcorner

	glVertex2f(_x, _y); // The top right corner
	// The end of the second triangle
	glVertex2f(_x + _size, _y); // The bottom right corner
	//glVertex2f(0, 0); // The bottom left corner

	glEnd();
	

	}

void tank::update(float dT){
	if (_right)
		_x += dT *_speed;
	else if (_left)
		_x += dT *-_speed;

	if ((_x + _size) >= _window->x())
	{
		_x = _window->x() - _size;
	}

	if (_x <= 0)
	{
		_x = 0;
	}

	_pos.updatePos(_x, _y);

	if (_shoot)
		shoot();
}

void tank::shoot()
{
	if (_ready)
	{
		bullet* newBullet = new bullet(_x + _size / 2, _y + _size, false, _window);
		_dlist->push_back(newBullet);
		_glist->push_back(newBullet);
		_ready = false;
		if (_inter->_sfx.onOff != 0)
		fire.play();
	}
}

void tank::print() const{

}

void tank::attackReset(int value)
{
	_ready = true;
}
bool tank::checkCollision(GameList* checklist) {
	if (_delete){
		lives--;
		if (lives == 0)
		{
			_inter->_state = 6;
		}
		else
		{	
			_inter->_state = 3;
		}
		_delete = false;
		_inter->updateLives(&this->lives);
		if (_inter->_sfx.onOff != 0)
		death.play();

	}
	return false;
}


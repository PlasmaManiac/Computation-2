#pragma once
#include "drawtools.h"
#include <string>
using namespace std;


struct menuItem
{
	string _text;
	PointI* _window;
	int _listPos;
	int _width;
	int _height;
	int _state;
	int onOff;
};

class interface : public Drawable
{
public:
	interface(PointI* window,  DrawList* dList, int* _level);

	int intScore;
	int* intLives;
	int _x;
	int _y;
	int _state; //0 menu, 1 settings, 2 quit, 3 death, 4 start, 5 game playing, 6 failture, 7 win
	int _countdown;
	int* _level;
	unsigned long prevClick;


	string _score;
	string _lives;
	menuItem _play;
	menuItem _options;
	menuItem _exit;
	menuItem* items[6];
	menuItem _return;
	menuItem _music;
	menuItem _sfx;

	DrawList* _dList;
	Text* scoreText;
	Text* livesDisplay;
	PointI* _window;

	void updateScore();
	void updateLives(int* lives);
	void drawMenu() const;
	void updatePos();

	void mouseClick(int x, int y);
	void drawBox(menuItem option) const;
	void draw() const override;
	void print() const override;
};
#pragma once
#include "drawtools.h"
#include "Interface.h"
#include "tank.h"
#include "glut.h"
#include <iostream>

using namespace std;


interface::interface(PointI* window, DrawList* dList, int* level)
{
	intScore = 0;
	intLives =  new int(3);
	_window = window;
	_dList = dList;
	_level = level;
	_state = 0;
	_countdown = 4;

	prevClick = clock();

	_play = {"Start Game", _window, 3, 100, 50, 8,2};
	items[0] = &_play;
	_options = {"Settings", _window, 2, 100, 50, 1,2};
	items[1] = &_options;
	_exit = {"Exit", _window, 1, 100, 50, 2,2};
	items[2] = &_exit;

	_return = { "Return", _window, 1, 100, 50, 0 ,2};
	items[3] = &_return;
	_music	= { "Music: ", _window, 2, 100, 50, 21,1 };
	items[4] = &_music;
	_sfx	= { "SFX: ", _window, 3, 100, 50, 22,1 };
	items[5] = &_sfx;



	_score = "Current score: " + to_string(intScore);
	_lives = "Lives: " + to_string(*intLives);

	scoreText	 = new Text(_score, { 1, 1, 1 }, { window->x() * 1 / 10, window->y() * 5 / 6 });
	livesDisplay = new Text(_lives, { 1, 1, 1 }, { window->x() * 8 / 10, window->y() * 5 / 6 });
	
	_dList->push_back(scoreText);
	_dList->push_back(livesDisplay);
}

void interface::updateScore()
{
	intScore = intScore + 5 + 5**_level;
	_score = "Current score: " + to_string(intScore);
	scoreText->updateStr(&_score);
}

void interface::updateLives(int* lives)
{
	_lives = "Lives: " + to_string(*lives);
	livesDisplay->updateStr(&_lives);
}

void interface::updatePos()
{
	PointI* stPOS = new PointI(_window->x() * 1.0 / 10.0, _window->y() * 5.0 / 6.0);
	PointI* ldPOS = new PointI(_window->x() * 8.0 / 10.0, _window->y() * 5.0 / 6.0);
	scoreText->updatePos(stPOS);
	livesDisplay->updatePos(ldPOS);
}

void interface::draw() const
{
	switch (_state)
	{
	case 0: //menu
		drawMenu();
		break;
	case 1: //settings
		drawMenu();
		break;
	case 2: //quit
		exit(1);
		break;
	case 3: //death
		break;
	case 4://starting
	{
			   string gsString = "Level "+ to_string(*_level) +" starting in: " + to_string(_countdown);
			   Text gStart =Text(gsString, { 1, 1, 1 }, { _window->x() / 2, _window->y() / 2 - 50 });
			   gStart.draw();

			   break;
	}
	case 5://playing
		scoreText->draw();

		livesDisplay->draw();
		break;
	case 11:
	case 6://lose
	{
			   string gsString = "You Have Lost: Restarting from level 1";
			   Text gStart = Text(gsString, { 1, 1, 1 }, { _window->x() / 2, _window->y() / 2 - 50 });
			   gStart.draw();

			   break;
	}
	case 10:
	case 7://win

		string gsString = "YOU WIN!!\n STARTING NEXT LEVEL";
		Text gStart = Text(gsString, { 1, 1, 1 }, { _window->x() / 2, _window->y() / 2 - 50 });

		gStart.draw();


		break;
	}
}

void interface::mouseClick(int x, int y)
{
	unsigned long diff = clock() - prevClick;
	prevClick = clock();
	
	if (diff < 100)
		return;

	int i= 0;
	if (_state == 0)
		i = 0;
	if (_state == 1)
		i = 3;

	int j = i + 3;
	for (; i < j; i++)
	{
		if ((x > items[i]->_window->x() / 2 - 100) && (x < items[i]->_window->x() / 2 + 100))
		{
			if ((y < (items[i]->_window->y() * (1 + items[i]->_listPos)/6 + items[i]->_height)) && y > (items[i]->_window->y() * (1 + items[i]->_listPos) / 6 - items[i]->_height))
			{
				_state = items[i]->_state;
				return;
			}
		}
	}
	
}

void interface::drawBox(menuItem option) const
{
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2d(option._window->x() / 2 - 100, option._window->y() * (1 + option._listPos) / 6 - 50);
	glVertex2d(option._window->x() / 2 - 100, option._window->y() * (1 + option._listPos) / 6 + 50);
	glVertex2d(option._window->x() / 2 + 100, option._window->y() * (1 + option._listPos) / 6 + 50);
	glVertex2d(option._window->x() / 2 + 100, option._window->y() * (1 + option._listPos) / 6 - 50);

	glEnd();

	glRasterPos2f(option._window->x() / 2 - 50, option._window->y()* (1 + option._listPos) / 6 - option._height / 2 + 15);
	glColor3f(1.0f, 1.0f, 1.0f);

	for (char c : option._text) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
	if (option.onOff == 1)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	}
	else if (option.onOff == 0)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	}
}
void interface::print() const
{

}

void interface::drawMenu() const
{
	if (_state == 0)
	{
		drawBox(_play);
		drawBox(_options);
		drawBox(_exit);
	}
	if (_state == 1)
	{
		drawBox(_return);
		drawBox(_sfx); 		
		drawBox(_music); 
	}
}
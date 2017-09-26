#pragma once
#include "drawtools.h"
#include "GameObjects.h"

using GameList = std::list<GameObjects*>;
using pointI = Point<int>;

class bridge 
{
public:
	bridge(pointI* window, DrawList* drawList, GameList* gameList, int place);

	GameList* _brickList;
	GameList* _gameList;
	DrawList* _drawList;

	pointI* _window;
	pointI _pos;

	int _place;

	void updatePos();
	void clear();
	void create();
};



class brick : public GameObjects
{
public:
	brick(PointI* pos, PointI* window, bridge* bridge, GameList* gList, DrawList* dList);

	DrawList* _drawList;
	GameList* _gameList;
	bridge* _bridge;
	void update(float dt) override;
	void draw() const override;
	void print() const override;
	void shoot() override;
	bool checkCollision(GameList* checklist) override;
};
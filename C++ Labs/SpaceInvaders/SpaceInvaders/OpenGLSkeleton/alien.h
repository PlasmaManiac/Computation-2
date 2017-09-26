#pragma once
#include "drawtools.h"
#include "GameObjects.h"
#include "AlienSwarm.h"

class alien : public GameObjects
{
public:
	alien(int x, int y, float speed, PointI* window, AlienSwarm* swarm, GameList* gList);

	AlienSwarm* _swarm;
	GameList* _gList;
	DrawList* _dlist;

	sf::Sound death;

	int reloadTime;

	//checks for colision with either the player or enemy ships
	bool checkCollision(GameList* checklist) override;

	//updates the position of the 
	void update(float dT) override;

	//overiding the drawable functions
	void draw() const override;
	void print() const override; // only has an empty function
	void shoot() override;

private:
};
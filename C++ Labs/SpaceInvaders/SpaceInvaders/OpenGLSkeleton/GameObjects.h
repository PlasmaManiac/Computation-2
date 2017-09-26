#pragma once
#include "drawlist.h"
class GameObjects;

typedef std::list<GameObjects*> GameList;

class GameObjects : public Drawable
{
public:
	// Construct a GameObject without a name
	GameObjects() = default;

	// Construct a GameObject with a given name
	GameObjects(const std::string& name);

	// Defaulted (empty) virtual destructor
	virtual ~GameObjects() = default;
	//Virtual functions
	virtual void draw() const = 0;
	virtual void update(float dt) = 0;
	virtual bool checkCollision(GameList* checklist) = 0;
	virtual void shoot() = 0;
	//Position
	PointI _pos;
	//Color 
	Color _color;
	//Postion that stores the SIZE of the current window.
	PointI* _window;
	//Speed of the game object
	float _speed;
	//whether or not it must be deleted upon the next frame
	bool _delete = false;
	//Player or enemy variable
	bool _enemy;
	//the size of the object
	int _size;
	const std::string& name() const;
	private:
};
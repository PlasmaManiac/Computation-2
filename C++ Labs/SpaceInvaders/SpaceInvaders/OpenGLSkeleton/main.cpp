////////////////////////////////////////////////////////////
//
// File: main.cpp
// Author: Peter Koek (based on version by Sven Goossens)
// Purpose:
//      A skeleton for the final assignment
//      Without modifications, this should draw 2 pixels on the screen
//
///////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <time.h>
#include <stdio.h>     
#include <stdlib.h> 

#include <SFML/Audio.hpp> 

#include "glut.h"           // glut header file. Never include glut before stdlib.h!
#include "Bullet.h"
#include "alien.h"
#include "tank.h"
#include "Interface.h"
#include "Bridges.h"

#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that

#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff

using namespace std;
using GameList = std::list<GameObjects*>;

sf::Music venus;

// Put your global variables here
string keytext;
int mousex;
int mousey;

static int x = 0;
static int y = 0;
int specialKey = 0;
int changex = 0;
int changey = 0;

bool fired = false;
bool populated = false;
bool death = false;

bool music = true;
bool sfx = true;
bool firstFrame = true;

int level = 1;

chrono::steady_clock::time_point tick;
float dT = 0;

DrawList drawList;
GameList gameObjects;
GameList aliens;
PointI* window = new PointI(windowHeight, windowWidth);

interface* inter = new interface(window, &drawList, &level);
tank player(windowWidth / 2, &drawList, &gameObjects, window, inter);
AlienSwarm swarm = { 30, window, &drawList, &gameObjects, inter };

//bridge* bridge3 = new bridge(window, &drawList, &gameObjects, 0);
//bridge* bridge1 = new bridge(window, &drawList, &gameObjects, 1);
//bridge* bridge2 = new bridge(window, &drawList, &gameObjects, 2);

using PointF = Point<float>;
using PointI = Point<int>;

void textDraw(string word, int x, int y)
{
	glRasterPos2f(x, y);

	for (char& c : word) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}

void readEDIF(const std::string& filename)
{
	string command;
	ifstream fp;


	// Open the file
	fp.open(filename, ios::in);

	if (!fp.is_open()) {
		cerr << "Cannot open file \"" << filename << "\"" << endl;
		return;
	}
	else
	{
		cout << "file opened succesfully";
	}


	while (!fp.eof()) {
		fp >> command;
		cout << "reading command" << endl;
		if (command == ".line"){
			float linedata[8];

			fp >> linedata[0] >> linedata[1] >> linedata[2] >> linedata[3]
				>> linedata[4] >> linedata[5] >> linedata[6] >> linedata[7];


			PointF end = PointF(linedata[2], linedata[3]);
			PointF start = PointF(linedata[0], linedata[1]);
			Color newColor = Color(linedata[4], linedata[5], linedata[6]);
			Line* newLine = new Line(start, end, newColor, linedata[7]);

			drawList.push_front(newLine);
		}
		else if (command == ".drawing")
		{
			string title;
			getline(fp, title);
			title = title.substr(2, title.size() - 3);
			const char * c = title.c_str();
			glutSetWindowTitle(c);
		}
		else if (command == ".pixel")
		{
			string pixels;
			getline(fp, pixels);
			stringstream ss(pixels);

			float pixeldata[5];
			ss >> pixeldata[0] >> pixeldata[1] >> pixeldata[2] >> pixeldata[3]
				>> pixeldata[4] >> pixeldata[5];

			PointF position = PointF(pixeldata[0], pixeldata[1]);
			Color newColor = Color(pixeldata[2], pixeldata[3], pixeldata[4]);

			Pixel* newPixel = new Pixel(position, newColor);
			drawList.push_front(newPixel);
		}
		else if (command == ".text")
		{
			float textdata[5];
			string phrase;

			fp >> textdata[0] >> textdata[1] >> textdata[2] >> textdata[3]
				>> textdata[4];
			getline(fp, phrase);
			phrase = phrase.substr(2, phrase.size() - 3);

			Color newColor = Color(textdata[2], textdata[3], textdata[4]);
			PointI position(textdata[0], textdata[1]);
			Text* newText = new Text(phrase, newColor, position);
			drawList.push_front(newText);
		}
	}
	// Close the file
	fp.close();

	glutPostRedisplay();
}

void keyfunc(unsigned char key, int x, int y)
{
	char c = key;
	mousex = x;
	mousey = windowHeight - y;
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);

	glutPostRedisplay();
}

void specialKeyFunc(int key, int x, int y)
{
	specialKey = key;
	mousex = x;
	mousey = windowHeight - y;
	//cout << "pressed" << endl;
	switch (key)
	{
	case 100:// left arrow	
		player._left = true;
		break;
	case 101: // up arrow
		changey = 10;
		changex = 0;
		player._shoot = true;
		if (player._ready == false)
			glutTimerFunc(50, alarm, 123);
		break;
	case 102:// right arrow
		player._right = true;
		break;
	case 103:// down arrow PAUSE
		inter->_state = 0;
		swarm._ready = false;
		swarm._shooting = false;
		break;
	}

	glutPostRedisplay();
}
void specialRelease(int key, int x, int y)
{
	if (key == 102){
		player._right = false;
	}
	if (key == 100)
	{
		player._left = false;
	}
	if (key == 101){

		player._shoot = false;
		cout << "game list: " << gameObjects.size() << endl;
		cout << "draw List: " << drawList.size() << endl;
		cout << "aliens: " << swarm._alienList->size() << endl;

	}
	cout << "released " << key << endl; //its ok if you cant get it to work. this is extra stuff. You shook your mouse in frustration // confusion what version did you download *facepalm*? what are you compiling for? ok j
}

void mouseClick(int button, int state, int x, int y)
{
	inter->mouseClick(x, window->y() - y);
}
//---------------------------------------------------------------------------
// void init(void)
// This function is called when glut is initialized. Use it to initialize
// variables and setup things that have to be done BEFORE the actual
// picture is drawn.

void init()
{
	// Create a display window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    // Double buffering, RGB format
	glutInitWindowSize(windowWidth, windowHeight);  // 1024 x 500 pixel window
	glutInitWindowPosition(0, 0);                    // Window appears in the top-left corner of the screen
	glutCreateWindow(windowTitle);                  // Create window with title

	// Register callbacks
	glutDisplayFunc(display);                       // Main display function
	glutReshapeFunc(reshape);                       // Reshape function, called when the window resizes
	glutKeyboardFunc(keyfunc);
	glutSpecialFunc(specialKeyFunc);
	glutSpecialUpFunc(specialRelease);
	glutMouseFunc(mouseClick);

	// Ignores repeated key inputs from windows
	glutIgnoreKeyRepeat(1);

	// Set the background color.
	// The color is in the (red, green, blue, alpha) format (RGBA)
	// Color values range from 0.0f to 1.0f.
	// E.g. glClearColor(1.0, 0.0, 0.0, 1.0); results in a red background.
	glClearColor(0.0, 0.0, 0.0, 0.0);               // Set background color to white

	// The following funtions setup the view of the screen.
	// OpenGL actually creates a 3D world, which is displayed trough a
	// viewport (the glut window). The way pixels are projected onto
	// this viewport is setup here.
	// Keep them like this if you don't need fancy options
	glMatrixMode(GL_PROJECTION);    // Next lines will adjust the projection matrix
	glLoadIdentity();               // Reset projection matrix to the identity matrix

	// Set the size of the viewport (drawing grid) in pixels
	// We are looking at the rectangle from (0,0) to (windowWidth,windowHeight)
	gluOrtho2D(0, windowWidth, 0, windowHeight);


	if (!venus.openFromFile("Venus.ogg"))
	{
		std::cout << "Error audio not found" << endl;
	}
	else
		venus.play();


	glMatrixMode(GL_MODELVIEW);

}



//---------------------------------------------------------------------------
// void alarm(int alarmnumber)
// Demonstration of a timer callback. alarmnumber is used to distinguish
// between different timers.

void alarm(int alarmNumber)
{
	if (alarmNumber == 123) //Alarm used to reset the ability for the player to shoot
	{
		player._ready = true;
		cout << "ready" << endl;
	}
	if (alarmNumber == 150) //Alarm used to redraw the frame
	{
		glutPostRedisplay();
		glutTimerFunc(4, alarm, 150);
	}
	if (alarmNumber == 111)
	{
		if (swarm._alienList->size() != 0 && swarm._ready)
		{
			swarm.shoot(rand() % swarm._alienList->size());
			glutTimerFunc(1000, alarm, 111);
		}
	}

	if (alarmNumber == 50)
	{
		inter->_countdown -= 1;
		if (inter->_countdown == 0)
		{
			swarm.clear();
			swarm.populate(5 + 5*level);
			if (!swarm._shooting)
			{
				glutTimerFunc(1000, alarm, 111);
				swarm._shooting = true;
			}inter->_state = 5;
			inter->_countdown = 4;

			//bridge1->updatePos();
			//bridge2->updatePos();
			//bridge3->updatePos();
			
			death = false;
		}
		else
		{
			inter->_state = 4;
			glutTimerFunc(1000, alarm, 50);

		}
	}
	if (alarmNumber == 12)
	{
		level++;
		inter->_state = 4;
		glutTimerFunc(1, alarm, 50);
	}
}

//---------------------------------------------------------------------------
// void reshape(int w, int h)
// Handle window resizing (reshaping) events
// The reshape callback is called when the window is resized or moved
// In the current implementation, the drawing grid is extended or truncated 
// when the window is reshaped

void reshape(int w, int h)
{
	delete window;
	window = new PointI(w, h);

	//bridge1->updatePos();
	//bridge2->updatePos();
	//bridge3->updatePos();

	inter->updatePos();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

//---------------------------------------------------------------------------
// void display(void)
// The main display callback. This callback is called when the screen has
// to be redrawn. This is when:
// - The screen first becomes active
// - The screen is resized
// - You call glutPostRedisplay()

void display()
{
	//dT = (float)(chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - tick).count() / 1000);
	dT = 10;
	if (firstFrame)
	{
		glutTimerFunc(15, alarm, 150);
		firstFrame = false;
	}
	tick = chrono::steady_clock::now();

	glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer

	inter->draw();

	switch (inter->_state)
	{
	case 2: //quit
		return;
		break;
	case 3: //death
		if (!death)
		{
			swarm._ready = false;
			inter->intScore =-10;
			inter->updateScore();
			glutTimerFunc(1500, alarm, 50);
			death = true;
		}
		while (inter->_state == 3)
		{
			for (auto drawable = drawList.begin(); drawable != drawList.end(); ++drawable)
			{
				(*drawable)->draw();
			}
			break;
		}
		
	case 4: //game start
		
		break;
	case 5: //Game playing
		for (auto drawable = drawList.begin(); drawable != drawList.end(); ++drawable)
		{
			(*drawable)->draw();
		}
		//Itterating through the gameObjects list to update them and check for collision and erase if necessary
		for (auto gObject = gameObjects.begin(); gObject != gameObjects.end();)
		{
			(*gObject)->update(dT);

			if ((*gObject)->checkCollision(&gameObjects))
			{
				delete (*gObject);
				drawList.remove((*gObject));
				gObject = gameObjects.erase(gObject);
			}
			else
				++gObject;
		}
		if (swarm._alienList->size() == 0)
		{
			inter->_state = 7;
		}
		break;

	case 6: // failure
		level = 1;
		glutTimerFunc(1000, alarm, 50);
		player.lives = 3;
		inter->updateLives(&player.lives);
		inter->_state = 11;
		break;
	case 7: // win
		glutTimerFunc(5000, alarm, 12);
		inter->_state = 10;
		break;
	case 8: //first start
		swarm.populate(5 + 5*level);
		inter->_state = 5;
		if (!swarm._shooting)
		{
			glutTimerFunc(dT, alarm, 111);
			swarm._shooting = true;
		}		
		
		break;

	case 21:
		music = !music;
		inter->_state = 1;
		if (music)
			inter->_music.onOff = 1;
		else
			inter->_music.onOff = 0;

		break;
	case 22:
		sfx = !sfx;
		inter->_state = 1;

		if (sfx)
			inter->_sfx.onOff = 1;
		else
			inter->_sfx.onOff = 0;
		break;

		// Visualize the drawing commands
	}
	
	if (!music)
		venus.setVolume(0);
	else 
		venus.setVolume(50);
	glFlush();            // Execute all commands waiting to be executed
	glutSwapBuffers();    // Swap the backbuffer and frontbuffer
}

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	/* initialize random seed: */
	srand(time(NULL));
	// Inialize GLUT
	glutInit(&argc, argv);
	// Initialize your program
	init();

	// Enter the main application loop
	// While in the main loop, your registered callbacks will be called
	cout << "Starting GLUT main loop..." << endl;
	glutMainLoop();
	return EXIT_SUCCESS;



}
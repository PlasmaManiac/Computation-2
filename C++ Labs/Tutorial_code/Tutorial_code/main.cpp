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
#include "glut.h"           // glut header file. Never include glut before stdlib.h!

#define _USE_MATH_DEFINES   // Signal math.h that we would like defines like M_PI
#include <math.h>           // Might come in usefull for cosine functions and stuff like that

#include "main.h"           // Function declarations and some definitions
#include "drawtools.h"      // contains all you need to draw stuff

using namespace std;

// Put your global variables here
string keytext;
int mousex;
int mousey;

DrawList drawList;
using PointF = Point<float>;
using PointI = Point<int>;


void textDraw(string word, int x, int y)
{
	glRasterPos2f(x, y);

	for (char& c : word) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	}
}


static bool pressed = false;
static int x_1;
static int y_1;


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
static int x = 0;
static int y = 0;

void renderPrimitive(int changex, int changey) {
	glBegin(GL_TRIANGLE_STRIP); // Start drawing a triangle strip primitive
	// The first triangle

	x = x + changex;
	y = y + changey;
	glVertex2f(x, changey + 200); // The bottom left corner
	glVertex2f(x + 200, changey + 200); // The top left corner
	glVertex2f(x, changey); // The top right corner
	// The end of the second triangle
	glVertex2f(x + 200, changey); // The bottom right corner
	//glVertex2f(0, 0); // The bottom left corner
	glEnd();
	glFlush();
}
void keyfunc(unsigned char key, int x, int y)
{

	char c = key;
	mousex = x;
	mousey = windowHeight - y;
	keytext = string{ c } +", " + to_string(x) + ", " + to_string(y);

	if (true){
		PointF end = PointF(mousex, mousey);
		PointF start = PointF(x_1, y_1);

		Color newColor;

		switch (c)
		{
		case 'g':
			newColor = Color(0, 1, 0);
			break;
		case 'r':
			newColor = Color(1, 0, 0);
			break;
		case 'b':
			newColor = Color(0, 0, 1);
			break;
		case 'w':
			renderPrimitive(0, 10);
			break;
		case 'a':
			renderPrimitive(-10, 0);
			break;
		case 's':
			renderPrimitive(0, -10);
			break;
		case 'd ':
			renderPrimitive(10, 0);
			break;
		default:
			newColor = Color();
			break;
		}

		float linewidth = 10;

		Line* newLine = new Line(start, end, newColor, linewidth);

		pressed = false;

		drawList.push_front(newLine);
	}
	else
	{
		x_1 = mousex;
		y_1 = mousey;
		pressed = true;
	}

	glutPostRedisplay();
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
	// Example Timer functions
	// You might want to remove these after you are done testing with them
	glutTimerFunc(1000, alarm, 112);
	glutTimerFunc(1500, alarm, 1);
	glutTimerFunc(2000, alarm, 2);

	// Set the background color.
	// The color is in the (red, green, blue, alpha) format (RGBA)
	// Color values range from 0.0f to 1.0f.
	// E.g. glClearColor(1.0, 0.0, 0.0, 1.0); results in a red background.
	glClearColor(1.0, 1.0, 1.0, 1.0);               // Set background color to white

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

	glMatrixMode(GL_MODELVIEW);

	PointF position = { 512, 384 };
	Color color = { 0.2f, 1, 0.2f };
	Pixel* pixel = new Pixel{ position, color };
	drawList.push_back(pixel); pixel->print();

}



//---------------------------------------------------------------------------
// void alarm(int alarmnumber)
// Demonstration of a timer callback. alarmnumber is used to distinguish
// between different timers.

void alarm(int alarmNumber)
{
	if (alarmNumber == 112) {
		cout << "Ring Ring!!! This was alarm 112!" << endl;
		cout << "Next alarm will ring in 100 ms." << endl;

		// Register another timer with a different number that triggers after 100 ms
		glutTimerFunc(100, alarm, 1337);
	}
	else {
		cout << "Ring Ring!!! Alarm with alarmnumber " << alarmNumber << " called!" << endl;
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
	glClear(GL_COLOR_BUFFER_BIT);   // clear the backbuffer
	glLineWidth(25);
	glBegin(GL_LINES);             // Start a new drawing block for drawing points

	/*
	// Draw points here
	// The point (0,0) corresponds to the lower left corner.

	// The following lines will draw the point (100, 200) in red
	glColor3f(1.0, 0.0, 0.0);   // Set color
	glVertex2f(100, 200);       // Set position



	// The following lines will draw the point (200, 400) in blue1
	// Alternative approach to the abov:ed
	Color color = { 0.0f, 0.0f, 1.0f }; // A color (see drawtools.h)
	glColor3fv(color.data());           // Set color from array
	PointF point = { 200, 400 };        // A two dimensional point (see drawtools.h)
	glVertex2fv(point.data());          // Set position from array
	*/
	glEnd(); // End of the drawing block

	//Drawing text
	//textDraw(keytext, mousex, mousey);

	//Itterating through the drawlist
	for (Drawable* drawable : drawList)
	{
		drawable->draw();
	}

	renderPrimitive(x, y);

	// Visualize the drawing commands
	glFlush();            // Execute all commands waiting to be executed
	glutSwapBuffers();    // Swap the backbuffer and frontbuffer

}

//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	cout << "Enter EDIF++ filename: ";
	string filename;
	cin >> filename;


	// Inialize GLUT
	glutInit(&argc, argv);

	// Initialize your program
	init();

	// Enter the main application loop
	// While in the main loop, your registered callbacks will be called
	cout << "Starting GLUT main loop..." << endl;
	if (filename != "n"){ readEDIF(filename); }
	glutMainLoop();




	return EXIT_SUCCESS;
}
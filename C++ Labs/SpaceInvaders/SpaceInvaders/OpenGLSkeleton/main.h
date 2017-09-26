#ifndef MAIN_H
#define MAIN_H

// Global constants (ONLY const)
const int windowWidth = 1024;
int windowHeight = 768;
const char* windowTitle = "Space Invaders - Luke H. Martin";

// Function declarations
int main(int argc, char* argv[]);
void init();
void keyfunc(unsigned char key, int x, int y);

// Place your glut callback declarations here:
void reshape(int w, int h);
void display();
void alarm(int alarmnumber);
#endif
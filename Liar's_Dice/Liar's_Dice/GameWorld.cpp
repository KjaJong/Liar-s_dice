#include "GameWorld.h"
#include <GL/freeglut.h>
#include <iostream>

int screenWidth = 1200;
int screenHeight = 800;

GameWorld::GameWorld()
{
}


GameWorld::~GameWorld()
{
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //escape
			exit(0);

	default:
		std::cout << "Key not recognized" << std::endl;
		break;
	}
}

void display()
{
	glClearColor(0.5f, 0.5f, 0.7f, 1.0f); //Background colour, now purple
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Sets the matrix for the projection. By calling you are setting (in order): The field of view, the aspect ratio of the
	//screen, the distance to the near plane (always < 0) and the distance to the far plane.
	//Load identity always loads the matrix mode, and should always be called after glMatrixMode.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, screenWidth / (float)screenHeight, 0.1f, 50.0f);


	//Sets matrix for the modelview. The first three values set the x, y and z position for the eye. The next three do the same for
	//the center of the view (screen?) and the last three set the same for the head (which is to say, now the head is straight up).
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		0, 0, 0,
		0, 0, 0,
		8, 1, 0);

	glutSwapBuffers();
}

int lastKnownTime = 0;
void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (float)(currentTime - lastKnownTime);
	lastKnownTime = currentTime;

	glutPostRedisplay();
}

void GameWorld::startGlut(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInit(&argc, argv);
	glutCreateWindow("ComputerGraphics wk1");

	//All function bound to glut
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);

	//Now initalise all used openGl modules
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Last call, this starts all processes.
	glutMainLoop();
}

void GameWorld::animateRollDice(Player player)
{

}

void GameWorld::animateSpotOn(bool isSpotOn)
{

}

void GameWorld::animteCallBluff(bool isBluff)
{

}



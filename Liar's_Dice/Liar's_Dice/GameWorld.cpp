#include "GameWorld.h"
#include <Windows.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/glu.h>
#include <math.h>
#include "ObjModel.h"
#include <list>
#include <iostream>
#include <concrt.h>

# define M_PI 3.14159265358979323846

int screenWidth = 1200;
int screenHeight = 800;

void animateRollDice();

//Variables needed for dice animations
std::vector<int> rotation;
std::vector<int> rotateTo;
std::vector<int> numbers;
std::vector<int> position;
bool startAnimation = false;
bool wait = false;
bool revealed = false;
double cupheight = -0.35;
std::vector<std::pair<int, ObjModel*> > models;

void animate(std::vector<int>);
void displayDice();

void display(void)
{
	glClearColor(0.6f, 0.6f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glRotatef(rotation, 0, 1, 1);
	//glRotatef(rotation, 1, 0, 0); //1

	displayDice();

	glutSwapBuffers();
}

void reshape(GLint width, GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, width / (float)height, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void initGraphics(void)
{
	glEnable(GL_DEPTH_TEST);

	//models.push_back(std::pair<int, ObjModel*>(75, new ObjModel("models/car/honda_jazz.obj")));
	//models.push_back(std::pair<int, ObjModel*>(5, new ObjModel("models/auto/auto.obj")));
	//models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/bloemetje/PrimRoseP.obj")));
	//models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/cube/cube-textures.obj")));
	//models.push_back(std::pair<int, ObjModel*>(35, new ObjModel("models/ship/shipA_OBJ.obj")));
	//models.push_back(std::pair<int, ObjModel*>(3, new ObjModel("models/steve/steve.obj")));
	//models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/cup/cup.obj")));
	//models.push_back(std::pair<int, ObjModel*>(10, new ObjModel("models/3D-Model/3d-model.obj")));
	models.push_back(std::pair<int, ObjModel*>(10, new ObjModel("models/DiceOBJ/DiceLowpoly.obj")));
	//models.push_back(std::pair<int, ObjModel*>(100, new ObjModel("models/male/male.obj")));
	models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/cup/cup.obj")));

}

void MouseButton(int button, int state, int x, int y)
{

}

void MouseMotion(int x, int y)
{

}



void IdleFunc(void)
{
	if (startAnimation == true) {
		if (revealed == true) {
			if (numbers.size() > 0) {
				for (unsigned int i = 0; i < numbers.size(); i++) {
					if (rotation.at(i) < rotateTo.at(i) + 1 && rotateTo.at(i) > 0) {
						wait = true;
						rotation.at(i)++;
					}
					else {
						if (rotation.at(i) > rotateTo.at(i) - 1 && 0 > rotateTo.at(i)) {
							wait = true;
							rotation.at(i)--;
						}
					}
				}
				if (wait) {
					Concurrency::wait(5);
					wait = false;
				}
			}
		}
		else {
			if (cupheight > -0.58) {
				cupheight = cupheight - 0.0025;
				Concurrency::wait(10);
			}
			else {
				revealed = true;
			}
		}
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:             // ESCAPE key
		exit(0);
		break;
	case '[':
		break;
	case ']':
		if (numbers.size() < 5) {
			numbers.push_back(4);
			numbers.push_back(3);
			numbers.push_back(2);
			numbers.push_back(1);
			numbers.push_back(5);
		}
		animateRollDice();
		break;
	case 'o':
		std::cout << "Test";
		break;
	}
	glutPostRedisplay();
}

//void animate(std::vector<int> numbers) {
//	//Reset everything
//	cupheight = -0.35;
//	revealed = false;
//	for (int i = 0; i < rotation.size(); i++) {
//		rotation.at(i) = 0;
//	}
//
//	startAnimation = true;
//}

GameWorld::GameWorld()
{
}


GameWorld::~GameWorld()
{
}



void GameWorld::startGlut(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1280, 800);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT example");
	// Initialize OpenGL graphics state
	initGraphics();
	// Register callbacks:
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutIdleFunc(IdleFunc);
	// Turn the flow of control over to GLUT

	position.push_back(0);
	position.push_back(-8);
	position.push_back(8);
	position.push_back(-16);
	position.push_back(16);

	for (int i = 0; i < 5; i++) {
		rotateTo.push_back(0);
		rotation.push_back(0);
	}

	glutMainLoop();
}

void GameWorld::animateRaise(vector<int> dice)
{
	//TODO animte to new bid

	//rotation += 45.0f;

}

void GameWorld::animateRollDice(Player player)
{
	//TODO hugo code
	//Reset everything
	cupheight = -0.35;
	revealed = false;
	for (int i = 0; i < rotation.size(); i++) {
		rotation.at(i) = 0;
	}
	numbers = player.getDice();
	startAnimation = true;
}

//For testing purposes only
void animateRollDice()
{
	if (numbers.size() > 0) {
		//TODO hugo code
		//Reset everything
		cupheight = -0.35;
		revealed = false;
		for (int i = 0; i < rotation.size(); i++) {
			rotation.at(i) = 0;
		}
		startAnimation = true;
	}
}

void displayDice() {
	glPushMatrix();
	gluLookAt(0, models[1].first*1.1, models[1].first * 2, 0, 0, 0, 0, 1, 0);
	glScalef(22, 22, 22);
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, cupheight, 0.2);
	models[1].second->draw();
	glPopMatrix();
	if (numbers.size() > 0) {
		for (unsigned int i = 0; i < numbers.size(); i++) {
			glPushMatrix();
			gluLookAt(0, models[0].first*1.1, models[0].first * 2, position.at(i), 0, 0, 0, 1, 0);
			if (startAnimation == true) {
				if (numbers.at(i) == 1) {
					rotateTo.at(i) = 180;
					glRotatef(rotation.at(i), 1, 0, 0); //1
				}
				if (numbers.at(i) == 2) {
					rotateTo.at(i) = 90;
					glRotatef(rotation.at(i), 1, 0, 0);	//2
				}
				if (numbers.at(i) == 3) {
					rotateTo.at(i) = 90;
					glRotatef(rotation.at(i), 0, 0, 1);	//3
				}
				if (numbers.at(i) == 4) {
					rotateTo.at(i) = -90;
					glRotatef(rotation.at(i), 0, 0, 1); //4
				}
				if (numbers.at(i) == 5) {
					rotateTo.at(i) = -90;
					glRotatef(rotation.at(i), 1, 0, 0); //5
				}
				if (numbers.at(i) == 6) {
					//Literally, do nothing. It's already on 6.
				}
			}
			models[0].second->draw();
			glPopMatrix();
		}
	}
}

void GameWorld::animateSpotOn(bool isSpotOn)
{
	//TODO lift dice cup
	//TODO compare 
	//TODO results
}

void GameWorld::animteCallBluff(bool isBluff)
{
	//TODO lift dice cup
	//TODO compare 
	//TODO results
}



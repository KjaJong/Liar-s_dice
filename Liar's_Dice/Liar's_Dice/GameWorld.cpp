#include "GameWorld.h"
#include <GL/freeglut.h>
#include <iostream>
#include "ObjModel.h"

# define M_PI 3.14159265358979323846

int screenWidth = 1200;
int screenHeight = 800;

//Variables needed for dice animations
std::vector<int> rotation;
std::vector<int> rotateTo;
std::vector<int> numbers;
std::vector<int> position;
bool startAnimation = false;
bool wait = false;
bool revealed = false;
double cupheight = -0.35;

//float rotation = 0;
std::vector<std::pair<int, ObjModel*> > models;
int currentModel = 4;


struct Camera {
	float posX = 0;
	float posY = 0;
	float rotX = 0;
	float rotY = 0;
} camera;

bool keys[255];

GameWorld::GameWorld()
{
}


GameWorld::~GameWorld()
{
}


void keyboard(unsigned char key, int x, int y)
{

	keys[key] = true;
	switch (key)
	{
		case 27: //escape
			exit(0);

	default:
		std::cout << "Key not recognized (key value: " << key << ")" << std::endl;
		break;
	}
}

void keyboardUp(unsigned char key, int x, int y) 
{
	keys[key] = false;
}

void move(float angle, float fac) {
	camera.posX += cos((camera.rotY + angle) / 180 * M_PI) * fac;
	camera.posY += sin((camera.rotY + angle) / 180 * M_PI) * fac;
}

void mousePasiveMotion(int x, int y) 
{
	int dx = x - screenWidth / 2;
	int dy = y - screenHeight / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 100 && abs(dy) < 100) {
		camera.rotY += dx / 10.0f;
		camera.rotX += dy / 10.0f;
		glutWarpPointer(screenWidth / 2, screenHeight / 2);
	}
}

void initModels(void)
{
	glEnable(GL_DEPTH_TEST);

	models.push_back(std::pair<int, ObjModel*>(10, new ObjModel("models/DiceOBJ/DiceLowpoly.obj")));
	models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/cup/cup.obj")));
	models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/player/xmasguy.obj")));
	models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/table/table.obj")));
	//models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/robot/full_rigged_robot.obj")));
	//models.push_back(std::pair<int, ObjModel*>(10, new ObjModel("models/woman/woman.obj")));
	models.push_back(std::pair<int, ObjModel*>(100, new ObjModel("models/man/3D-model.obj")));
	models[4].second->scalef = 0.01f;
	//models[4].second->rotatef = 45;
	models[4].second->translatef = -50.0f;

}

void display()
{
	glClearColor(0.5f, 0.5f, 0.7f, 1.0f); //Background colour, now purple
	//glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Sets the matrix for the projection. By calling you are setting (in order): The field of view, the aspect ratio of the
	//screen, the distance to the near plane (always < 0) and the distance to the far plane.
	//Load identity always loads the matrix mode, and should always be called after glMatrixMode.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, screenWidth / (float)screenHeight, 0.1f, 5000.0f);


	//Sets matrix for the modelview. The first three values set the x, y and z position for the eye. The next three do the same for
	//the center of the view (screen?) and the last three set the same for the head (which is to say, now the head is straight up).
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glTranslatef(camera.posX, 0, camera.posY);

	/*gluLookAt(
	0, models[currentModel].first*1.1, models[currentModel].first * 2, 
	0, 0, 0, 
	0, 1, 0);*/
	gluLookAt(
	0,0,5,
	0,0,0,
	0,1,0);


	//glRotatef(rotation, 0, 1, 0);
	models[currentModel].second->draw();
	
	glutSwapBuffers();
}

int lastKnownTime = 0;
void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = (float)(currentTime - lastKnownTime);
	lastKnownTime = currentTime;
	
	//Wheeee!!!


	const float speed = 0.1f;
	if (keys['a']) move(0, deltaTime*speed);
	if (keys['d']) move(180, deltaTime*speed);
	if (keys['w']) move(90, deltaTime*speed);
	if (keys['s']) move(270, deltaTime*speed);
	if (keys['q']) camera.posY += deltaTime*speed;
	if (keys['e']) camera.posY -= deltaTime*speed;
	
	glutPostRedisplay();
}

void GameWorld::startGlut(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInit(&argc, argv);
	glutCreateWindow("Liar's dice");

	initModels();
	
	//All function bound to glut
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutPassiveMotionFunc(mousePasiveMotion);

	//Now initalise all used openGl modules
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Initialize everything needed for the dice
	position.push_back(0);
	position.push_back(-8);
	position.push_back(8);
	position.push_back(-16);
	position.push_back(16);

	for (int i = 0; i < 5; i++) {
		rotateTo.push_back(0);
		rotation.push_back(0);
	}

	//Last call, this starts all processes.
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

	startAnimation = true;
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



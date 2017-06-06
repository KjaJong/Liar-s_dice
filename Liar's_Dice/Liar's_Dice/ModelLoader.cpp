#include <Windows.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/glu.h>
#include <math.h>
#include "ObjModel.h"
#include <list>

float rotation = 0;
std::vector<std::pair<int, ObjModel*> > models;
int currentModel = 0;

void display(void)
{
	glClearColor(0.6f, 0.6f, 0.9f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, models[currentModel].first*1.1, models[currentModel].first * 2, 0,0, 0, 0, 1,0);

	glRotatef(rotation, 0, 1, 0);
	models[currentModel].second->draw();


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

	//models.push_back(std::pair<int, ObjModel*>(1, new ObjModel("models/cup/cup.obj")));
	models.push_back(std::pair<int, ObjModel*>(10, new ObjModel("models/DiceOBJ/DiceLowpoly.obj")));
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
	rotation += 0.25f;
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
		currentModel = (currentModel + models.size() - 1) % models.size();
		break;
	case ']':
		currentModel = (currentModel + 1) % models.size();
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1024, 768);
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
	glutMainLoop();
	return 0;
}
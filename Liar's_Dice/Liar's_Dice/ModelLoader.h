#pragma once

#include <Windows.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include <gl/glu.h>
#include <math.h>
#include "ObjModel.h"
#include <list>

class ModelLoader 
{
	public:

	private:
		float rotation = 0;
		std::vector<std::pair<int, ObjModel*> > models;
		int currentModel = 0;

		void display(void);
		void reshape(GLint, GLint);
		void initGraphics(void);
		void MouseButton(int, int, int, int);
		void MouseMotion(int, int);
		void IdleFunc(void);
		void Keyboard(unsigned char , int, int);
		int main(int, char*);
};
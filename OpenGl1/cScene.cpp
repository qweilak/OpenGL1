#include "cScene.h"
#include <gl/glut.h>

cScene::cScene()
{
	alfa = 0.0f;
}


cScene::~cScene()
{
}


void cScene::Render()
{
	
	glTranslatef(0.5f, 0.5f, 0);
	glPushMatrix();	
		glRotatef(alfa, 0.0f, 0.0f, 1.0f);
		glBegin(GL_TRIANGLES);	
			glColor3f(0.25f, 0.25f, 0.0f);
			glVertex3f(-0.25f, -0.25f, 0.0f);
			glVertex3f(0.25f, -0.25f, 0.0f);
			glVertex3f(0.0f, 0.25f, 0.0f);
		glEnd();
		
	glPopMatrix();

	alfa += .5f;
}

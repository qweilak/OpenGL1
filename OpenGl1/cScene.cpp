#include "cScene.h"
#include <gl/glut.h>
#include <cmath>
cScene::cScene()
{
	alfa = 0.0f;
	beta = 1.0f;
}


cScene::~cScene()
{
}


void cScene::Render()
{
	
	glTranslatef(0.15f, 0.5f, -2.0f);
	glPushMatrix();	
		glRotatef(alfa, 0.0f, 0.0f, 1.0f);
		glBegin(GL_TRIANGLES);	
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(-0.1f, -0.033f, 0.0f);
			glVertex3f(0.1f, -0.033f, 0.0f);
			glVertex3f(0.0f, 0.133f, 0.0f);
		glEnd();
	glPopMatrix();

	glTranslatef(0.3f, 0.0f, 0);
	
	glPushMatrix();
		glScalef(beta, beta , 0.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(-0.1f, -0.033f, 0.0f);
		glVertex3f(0.1f, -0.033f, 0.0f);
		glVertex3f(0.0f, 0.133f, 0.0f);
	glEnd();

	glPopMatrix();

	glTranslatef(0.75f, 0.1f, 0);

	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -alfa / 100);
	glBegin(GL_QUAD_STRIP);

		glColor3f(1.0f, 0.0f, 1.0f);

		glVertex3f(-0.3f, 0.0f, 0.0f);
		glVertex3f(-0.3f, -0.15f, 0.0f);
		glVertex3f(-0.45f, 0.0f, 0.0f);		
		glVertex3f(-0.45f, -0.15f, 0.0f);
		glVertex3f(-0.45f, 0.0f, -1.0f);
		glVertex3f(-0.45f, -0.15f, -1.0f);
	glEnd();

	glPopMatrix();
	alfa += .5f;
	beta = cos(alfa / 10);
	if (beta < 0)
		beta *= -1;
}

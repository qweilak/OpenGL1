#include <gl/glut.h>
#include "cScene.h"
//Delete console
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")


cScene Scene;
bool persp;

void init() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, 0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
} 

//Rendering
void Render(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	Scene.Render();

	glutSwapBuffers();					//Swap makes rendering visible
}

void SpecialKeys(int key, int x, int y) {
	
	switch (key)
	{
	case GLUT_KEY_F2:            
		
		persp = (!persp);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		if (persp)	
			gluPerspective(60, 640.0f / 480.0f, 1.5, 10.0); 
		else		
			glOrtho(0.0, 1.0, 0.0, 1.0, 0, 3.0);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		break;

	case GLUT_KEY_F3:	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;

	case GLUT_KEY_F4:	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;

	case GLUT_KEY_F5:	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;
	}
	glutPostRedisplay();
	
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:	exit(0);
		break;
	}
}

void GameLoop() {
	int t1, t2;
	t1 = glutGet(GLUT_ELAPSED_TIME);
	Render();
	do {
		t2 = glutGet(GLUT_ELAPSED_TIME);
	} while (t2 - t1<20);							//1000/20=50fps
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangles");

	init();
	glutDisplayFunc(Render);
	glutKeyboardFunc(Keyboard);						// keyboard handler
	glutSpecialFunc(SpecialKeys);					// special keys handler
	glutIdleFunc(Render);
	glutMainLoop();

	return 0;
}
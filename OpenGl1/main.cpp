#include <gl/glut.h>
#include "cScene.h"
//Delete console
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")


cScene Scene;


void init() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
} 

//Rendering
void render(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	Scene.Render();

	glutSwapBuffers();					//Swap makes rendering visible
}

void GameLoop() {

	render();
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(768, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangles");

	init();
	glutDisplayFunc(render);

	glutIdleFunc(render);
	glutMainLoop();

	return 0;
}
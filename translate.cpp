# if 0
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<iostream> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;
// function to initialize 
void myInit(void)
{
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// making picture color green (in RGB mode), as middle argument is 1.0                                                                                                                                                                                      
	glColor3f(0.0, 1.0, 0.0);

	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420);
}

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(2, 2, 2);
	glBegin(GL_POINTS);
	//float x, y, i;
	
	for(int i=-780;i<420;i++)
	{
		glVertex2i(i,0);
		glVertex2i(0,i);

	}
	glEnd();
	glFlush();
}

void render(void) {
	displ();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	// Giving name to window 
	glutCreateWindow("Line Drawing");
	myInit();

	glutDisplayFunc(render);
	glutMainLoop();
}

#endif
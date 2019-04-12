
#if 0
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

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

void displ(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(2, 2, 2);
	glBegin(GL_POINTS);
	//float x, y, i;
	int X0 = 0, Y0 = 0, X1 = 50, Y1 = 40;
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int p0 = 2 * dy - dx;
	printf("%d %d\n", X0, Y0);
	glVertex2i(X0, Y0);
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	
	for (int i = 0; i < steps; i++)
	{
		if (p0 < 0)
		{
			X0 = X0 + 1;
			printf("%d %d\n", X0, Y0);
			glVertex2i(X0, Y0);
			p0 = p0 + 2 * dy;
		}
		else
		{
			X0 = X0 + 1;
			Y0 = Y0 + 1;
			printf("%d %d\n", X0, Y0);
			glVertex2i(X0, Y0);
			p0 = p0 + 2 * dy-2*dx;
		}
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
	glutCreateWindow("Circle Drawing");
	myInit();

	glutDisplayFunc(render);
	glutMainLoop();
}
#endif
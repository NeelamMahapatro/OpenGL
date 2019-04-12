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

void displ(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(2, 2, 2);
	glBegin(GL_POINTS);
	//float x, y, i;
	int X0, Y0, X1, Y1 ,t;
	int x0,y0,x1,y1;
	cout<<"Enter the points X0,Y0  and X1,Y1: ";
	cin>>x0>>y0>>x1>>y1;
	
	X0 = abs(x0);
	Y0 = abs(y0);
	X1 = abs(x1);
	Y1 = abs(y1);
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int p0 = 2 * dx - dy;
	//printf("%d %d\n", X0, Y0);
	glVertex2i(X0, Y0);
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	for (int i = 0; i < steps; i++)
	{
		if (p0 < 0)
		{
			//X0 = X0 + 1;
			//printf("%d %d\n", X0, Y0);
		
			Y0 = Y0 + 1;
			if(x0>0 && y0>0)
			glVertex2i(X0, Y0);
			else if(x0>0 && y0<0)
			glVertex2i(X0, -Y0);
			else if(x0<0 && y0<0)
			glVertex2i(-X0, -Y0);
			else if(x0<0 && y0>0)
			glVertex2i(-X0, Y0);

			p0 = p0 + 2 * dx;
		}
		else
		{
			X0 = X0 + 1;
			
			Y0 = Y0 + 1;
			
		//	printf("%d %d\n", X0, Y0);
			if(x0>0 && y0>0)
			glVertex2i(X0, Y0);
			else if(x0>0 && y0<0)
			glVertex2i(X0, -Y0);
			else if(x0<0 && y0<0)
			glVertex2i(-X0, -Y0);
			else if(x0<0 && y0>0)
			glVertex2i(-X0, Y0);

			p0 = p0 + 2 * dx - 2 * dy;
		}
	}

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
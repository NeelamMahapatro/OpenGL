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
	gluOrtho2D(-100, 100, -50, 50);
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	double a1, a2, r;
	cin >> a1 >> a2 >> r;
	glColor3f(0.0, 1.0, 1.0);
	int x = r*cos(a1), y = r*sin(a1);
	glVertex2f(x, y);
	glVertex2f(x,-y);
	glVertex2f(y, x);
	glVertex2f(-y, x);
	int p = 1-r;
	while (x > y)
	{
		y++;
		if (p <= 0)
			p = p + 2 * y + 1;
		else
		{
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
		//if (x < y)
		//	break;
		glVertex2f(x, y);
	/*	glVertex2f(-x , y );
		glVertex2f(x ,-y );
		glVertex2f(-x , -y );
		glVertex2f(y, x );
		glVertex2f(-y , x );
		glVertex2f(y, -x );
		glVertex2f(-y , -x );
		*/
	}
		for(int i=-100;i<100;i++)
		{
		glVertex2i(i,0);
		glVertex2i(0,i);
		}

	

	
	glEnd();
	glFlush();
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
	

	glutDisplayFunc(display1);
	glutMainLoop();
	return(0);
}

#endif
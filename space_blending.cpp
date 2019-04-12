#if 0
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,X2,Y2,X3,Y3;

void planecurvedraw()
{
	double x, y;
  glColor3f(1, 1, 1);
  glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{
		double h1 = (-4.5)*(i*i*i) + (9*i*i) + (-5.5)*(i) + 1;
		double h2 = (13.5)*(i*i*i) + (-22.5)*(i*i) + (9)*(i);
		double h3 = (-13.5)*(i*i*i) + (18*i*i) + (-4.5)*(i);
		double h4 = (4.5)*(i*i*i) + (-4.5)*(i*i) + (i);

		glVertex2d(i,h1);
		glVertex2d(i,h2);
		glVertex2d(i,h3);
		glVertex2d(i,h4);
	}
  glEnd();
}
void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
	glVertex2i(-2,0);
	glVertex2i(2,0);
	glVertex2i(0,-2);
	glVertex2i(0,2);
  glEnd();
  planecurvedraw();  
}
void display() 
{  
  draw();
  glFlush();
} 

int main(int argc, char** argv) 
{
 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("SPACE CURVE BlENDING FUNCTIONS");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif 
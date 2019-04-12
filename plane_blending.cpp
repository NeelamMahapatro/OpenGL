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
		double h1 = (2*i*i) - 3*(i) + 1;
		double h2 = -4 *(i*i) + (4*i);
		double h3 = 2*(i*i)-i;
		
		glVertex2d(i,h1);
		glVertex2d(i,h2);
		glVertex2d(i,h3);
	}
  glEnd();
}
void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
	glVertex2i(-100,0);
	glVertex2i(100,0);
	glVertex2i(0,-100);
	glVertex2i(0,100);
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
  glutCreateWindow("PLANE CURVE BlENDING FUNCTIONS");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif 
#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;

void hermit_curve()
{	
  glColor3f(1, 1, 1);
  
  glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{
		double h1 = (2)*(i*i*i) + (-3*i*i) + 1;
		double h2 = (-2)*(i*i*i) + (3)*(i*i) ;
		double h3 = (1)*(i*i*i) + (-2)*(i*i) +1*i ;
		double h4 = (1)*(i*i*i) + (-1)*(i*i);

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
  hermit_curve();  
}
void display() 
{  
  srand(time(0));
  draw();
  glFlush();
} 


int main(int argc, char** argv) 
{  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("HERMITE CURVE");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif
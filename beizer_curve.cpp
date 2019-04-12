#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,Z1, Z2,X2,Y2, X3, Y3, Z3;

void hermit_curve()
{
	double x, y, z;
  //glColor3f(1, 1, 1);
  X1 = rand()%200-50;
  Y1 = rand()%200-50;
  
  
  X2 = rand()%200-50;
  Y2 = rand()%200-50;

  X3 = rand()%200-50;
  Y3 = rand()%200-50;
  
 
  glBegin(GL_POINTS);
	for(double u=0; u<=1; u += 0.01)
	{		
		x = X1 * (1-u)*(1-u) + 2*X2*(1-u)*u + X3 * u*u;
		y = Y1 * (1-u)*(1-u) + 2*Y2*(1-u)*u + Y3 * u*u;
		glVertex2d(x,y);
	}
  glEnd();
}
void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
	glVertex2i(-300,0);
	glVertex2i(300,0);
	glVertex2i(0,-300);
	glVertex2i(0,300);
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
{  /*
  cout<<"Enter first point (X1, Y1)"<<endl;
  cin>>X1>>Y1;
   cout<<"Enter first point (X2, Y2)"<<endl;
  cin>>X2>>Y2;
   cout<<"Enter first point (X3, Y3)"<<endl;
  cin>>X3>>Y3;
  */
 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("BEIZER QUADRATIC");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0);
  
  while(1)
	  display();
  //glutDisplayFunc(display);
  //glutMainLoop();
}
#endif
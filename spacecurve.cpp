#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,X2,Y2,X3,Y3, X4, Y4;

void planecurvedraw()
{
	double x, y;
  glColor3f(1, 1, 1);
  X1 = rand()%200-100;
  Y1 = rand()%200-100;

  X2 = rand()%200-100;
  Y2 = rand()%200-100;

  X3 = rand()%200-100;
  Y3 = rand()%200-100;
  X4 = rand()%200-100;
  Y4 = rand()%200-100;

  glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{
		double h1 = (-9/2)*(i*i*i) + (9*i*i) + (-11/2)*(i) + 1;
		double h2 = (27/2)*(i*i*i) + (-45/2)*(i*i) + (9)*(i);
		double h3 = (-27/2)*(i*i*i) + (18*i*i) + (-9/2)*(i);
		double h4 = (9/2)*(i*i*i) + (-9/2)*(i*i) + (i);

		x = (h1*X1) + (h2*X2) + (h3*X3) +  (h4*X4);
		y = (h1*Y1) + (h2*Y2) + (h3*Y3) + (h4*Y4);

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
  planecurvedraw();  
}
void display() 
{  
  srand(time(0));
  draw();
  glFlush();
} 


int main(int argc, char** argv) 
{
	/*
  cout<<"Enter 1st point p0 (x0, y0)"<<endl;
  cin>>X1>>Y1;
  cout<<"Enter 2nd point p1 (x1/3, y1/3)"<<endl;
  cin>>X2>>Y2;
  cout<<"Enter 3rd point p2 (x2/3, y2/3)"<<endl;
  cin>>X3>>Y3;
  cout<<"Enter 4th point p2 (x1, y1)"<<endl;
  cin>>X4>>Y4;
  */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("SPACE CURVE");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0);
  while(1)
  {
		display();
  }
  //glutDisplayFunc(display);
  //glutMainLoop();
}
#endif 
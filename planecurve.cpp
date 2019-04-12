#if 0
#include <time.h>
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
  //Sleep(500);
  X1 = rand()%100-50;
  Y1 = rand()%100-50;

  X2 = rand()%100-50;
  Y2 = rand()%100-50;

  X3 = rand()%100-50;
  Y3 = rand()%100-50;

  glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{
		double h1 = (2*i*i) - 3*(i) + 1;
		double h2 = -4 *(i*i) + (4*i);
		double h3 = 2*(i*i)-i;
		
		x = (h1*X1) + (h2*X2) + (h3*X3);
		y = (h1*Y1) + (h2*Y2) + (h3*Y3);

		glVertex2d(x,y);
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
  srand(time(0));
  draw();
  glFlush();
} 

int main(int argc, char** argv) 
{
  /*cout<<"Enter 1st point p0 (x0, y0)"<<endl;
  cin>>X1>>Y1;
  cout<<"Enter 2nd point p1 (x1/2, y1/2)"<<endl;
  cin>>X2>>Y2;
  cout<<"Enter 3rd point p2 (x1, y1)"<<endl;
  cin>>X3>>Y3;
  */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("PLANE CURVE");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
  while(1)
  {
		display();
  }
 // glutDisplayFunc(display);
  //glutMainLoop();
}
#endif 
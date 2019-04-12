#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,Z1, Z2,X2,Y2,v1, v2, alpha1, beta1, alpha2, beta2, gama1, gama2;
double pi=3.1416;
float r=1, g=1, b=1;
int a=1,b1=0,c=0;
void hermit_curve()
{
	double x, y, z;
  //glColor3f(1, 1, 1);
  X1 = rand()%200;
  Y1 = rand()%200;
  Z1 = rand()%200;
  
  X2 = rand()%200;
  Y2 = rand()%200;
  Z2 = rand()%200;
  alpha1 = rand()%360;
  alpha2 = rand()%360;
  beta1 = rand()%360;
  beta2 = rand()%360;
  alpha1 = (2*pi*alpha1)/360;
  alpha2 = (2*pi*alpha2)/360;
  beta1 = (2*pi*beta1)/360;
  beta2 = (2*pi*beta2)/360;
  gama1 = acos(sqrt(1-(cos(alpha1)*cos(alpha1))-(cos(beta1)*cos(beta1)) ));
  gama2 = acos(sqrt(1-(cos(alpha2)*cos(alpha2))-(cos(beta2)*cos(beta2)) ));
  //glColor3f(r-0.1, g-0.1, b-0.1);
  if(a==1)
  {
	  r-=0.1;
	  glColor3f(r-0.1, g, b);
	  b1=1;
	  a=0;
	 
  }
  else if(b1==1)
  {
	  g=g-0.1;
	  glColor3f(r, g-0.1, b);
	  c=1;
	  b1=0;
	  
  }
  else  
  {
	  b=b-0.1;
	  glColor3f(r, g, b);
	  a=1;
	  c=0;	  
  }
  glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{
		double h1 = (2)*(i*i*i) + (-3*i*i) + 1;
		double h2 = (-2)*(i*i*i) + (3)*(i*i) ;
		double h3 = (1)*(i*i*i) + (-2)*(i*i) +1*i ;
		double h4 = (1)*(i*i*i) + (-1)*(i*i);

		x = (h1*X1) + (h2*X2) + (h3*v1*cos(alpha1)) +  (h4*v2*cos(alpha2));
		y = (h1*Y1) + (h2*Y2) + (h3*v1*cos(beta1)) +  (h4*v2*cos(beta2));
		z = (h1*Y1) + (h2*Y2) + (h3*v1*cos(gama1)) +  (h4*v2*cos(gama2));
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
{  
  cout<<"Enter magnitude of first vector"<<endl;
  cin>>v1;
  cout<<"Enter magnitude of second vector"<<endl;
  cin>>v2;
 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("HERMITE CURVE");
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
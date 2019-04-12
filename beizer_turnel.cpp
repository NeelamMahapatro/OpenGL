#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,Z1, X2,Y2,Z2, X3, Y3,Z3, X4, Y4, Z4;
double P1,Q1,R1, P2,Q2, R2,P3, Q3,R3, P4, Q4, R4;

void hermit_curve()
{
	double x1, y1,z1, x2, y2,z2;
   
	/*X1=-50; Y1=50;
	X2= -25; Y2 = 100;
	X3= 0; Y3=0;
	X4=50; Y4 = 50;*/
	  X1 = rand()%200-50;
	  Y1 = rand()%200-50;
  
  
	  X2 = rand()%200-50;
	  Y2 = rand()%200-50;

	  X3 = rand()%200-50;
	  Y3 = rand()%200-50;

	  X4 = rand()%200-50;
	  Y4 = rand()%200-50;

	P1=X1; Q1 = -Y1;
	P2=X2; Q1 = -Y2;
	P3=X3; Q1 = -Y3;
	P4=X4; Q1 = -Y4;

	glBegin(GL_POINTS);
	for(double u=0; u<=1; u += 0.01)
	{		
		x1 = X1 * (1-u)*(1-u)*(1-u) + 3*X2*(1-u)*(1-u)*u + 3*X3*(1-u)*u*u + X4*u*u*u;
		y1 = Y1 * (1-u)*(1-u)*(1-u) + 3*Y2*(1-u)*(1-u)*u + 3*Y3*(1-u)*u*u + Y4*u*u*u;
		//z1 = Z1 * (1-u)*(1-u)*(1-u) + 3*Z2*(1-u)*(1-u)*u + 3*Z3*(1-u)*u*u + Z4*u*u*u;
		
		//x2 = P1 * (1-u)*(1-u)*(1-u) + 3*P2*(1-u)*(1-u)*u + 3*P3*(1-u)*u*u + P4*u*u*u;
		//y2 = Q1 * (1-u)*(1-u)*(1-u) + 3*Q2*(1-u)*(1-u)*u + 3*Q3*(1-u)*u*u + Q4*u*u*u;
		//z2 = R1 * (1-u)*(1-u)*(1-u) + 3*R2*(1-u)*(1-u)*u + 3*R3*(1-u)*u*u + R4*u*u*u;
		x2 = x1;
		y2 = -y1;
		
		
			glVertex2d(x1,y1);
			glVertex2d(x2,y2);
		
		double xc = x1;
		double r = (2*y1)/2;
		double yc = y2+r;
		double pk, xk=0, yk=r;
		pk = 1-r;
		glVertex2d(xk+xc,yk+yc);
		while(xk < yk)
		{
			if(pk <= 0)
			{
				pk = pk+2*xk+3;
				xk = xk+1;			
			}
			else
			{
				pk = pk+2*(xk-yk)+5;
				yk = yk-1;
				xk = xk+1;
			}
			glVertex2d(xk+xc,yk+yc);
			glVertex2d(xk+xc,-yk+yc);
			glVertex2d(-xk+xc,yk+yc);
			glVertex2d(-xk+xc,-yk+yc);
			glVertex2d(yk+xc,xk+yc);
			glVertex2d(yk+xc,-xk+yc);
			glVertex2d(-yk+xc,xk+yc);
			glVertex2d(-yk+xc,-xk+yc);		
		}	
		
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
	/*
  cout<<"Enter first point (X1, Y1) for 1st curve"<<endl;
  cin>>X1>>Y1;
   cout<<"Enter second point (X2, Y2) for 1st curve"<<endl;
  cin>>X2>>Y2;
   cout<<"Enter third point (X3, Y3) for 1st curve"<<endl;
  cin>>X3>>Y3;
   cout<<"Enter fourth point (X4, Y4) for 1st curve"<<endl;
  cin>>X4>>Y4;

  cout<<"Enter first point (P1, Q1) for 2nd curve"<<endl;
  cin>>P1>>Q1;
   cout<<"Enter second point (P2, Q2) for 2nd curve"<<endl;
  cin>>P2>>Q2;
   cout<<"Enter third point (P3, Q3) for 2nd curve"<<endl;
  cin>>P3>>Q3;
   cout<<"Enter fourth point (P4, Q4) for 2nd curve"<<endl;
  cin>>P4>>Q4;*/

  
 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("BEIZER TURNEL");
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
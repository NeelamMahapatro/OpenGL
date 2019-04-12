#if 0
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
double X1,Y1,Z1, Z2,X2,Y2,v1, v2, alpha1, beta1, alpha2, beta2, gama1, gama2;
double P1,Q1,R1, R2,P2,Q2;
double pi=3.1416;

void hermit_curve()
{
	
	double x1, y1,z1, x2, y2,z2;
   
	/*X1=-50; Y1=50;
	X2= -25; Y2 = 100;
	X3= 0; Y3=0;
	X4=50; Y4 = 50;*/
  X1 = rand()%200;
  Y1 = rand()%200;
  Z1 = rand()%200;
  
  X2 = rand()%200;
  Y2 = rand()%200;
  Z2 = rand()%200;

  alpha1 = rand()%360;
  alpha2 = rand()%360;
  beta1 = rand()%180;
  beta2 = rand()%180;
  alpha1 = (2*pi*alpha1)/360;
  alpha2 = (2*pi*alpha2)/360;
  beta1 = (2*pi*beta1)/360;
  beta2 = (2*pi*beta2)/360;
  gama1 = acos(sqrt(1-(cos(alpha1)*cos(alpha1))-(cos(beta1)*cos(beta1)) ));
  gama2 = acos(sqrt(1-(cos(alpha2)*cos(alpha2))-(cos(beta2)*cos(beta2)) ));


	P1=X1; Q1 = -Y1;
	P2=X2; Q2 = -Y2;
	

	glBegin(GL_POINTS);
	for(double i=0; i<=1; i += 0.01)
	{		
		double h1 = (2)*(i*i*i) + (-3*i*i) + 1;
		double h2 = (-2)*(i*i*i) + (3)*(i*i) ;
		double h3 = (1)*(i*i*i) + (-2)*(i*i) +1*i ;
		double h4 = (1)*(i*i*i) + (-1)*(i*i);

		x1 = (h1*X1) + (h2*X2) + (h3*v1*cos(alpha1)) +  (h4*v2*cos(alpha2));
		y1 = (h1*Y1) + (h2*Y2) + (h3*v1*cos(beta1)) +  (h4*v2*cos(beta2));
		z1 = (h1*Y1) + (h2*Y2) + (h3*v1*cos(gama1)) +  (h4*v2*cos(gama2));

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
	
 cout<<"Enter magnitude of first vector"<<endl;
  cin>>v1;
  cout<<"Enter magnitude of second vector"<<endl;
  cin>>v2;
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
  glutCreateWindow("HERMITE TURNEL");
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
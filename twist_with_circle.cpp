#if 0
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
int width, height;
int r, xc, yc,D;

void rectangle()
{
		double w = (double)width;
		double h = (double)height;

		for(double i=-w/2; i<= w/2; i+=0.1)
		{
			for(double j= -h/2; j <= h/2; j+=0.1)
			{
				if(i >= -w/2 && i <= (-w/2)+(w/7) )
					glColor3f(1, 1, 1);
				else if( i > (-w/2)+(w/7) && i <= (-w/2)+(2*w/7))
					glColor3f(1, 1, 0);
				else if( i > (-w/2)+(2*w/7) && i <= (-w/2)+(3*w/7))
					glColor3f(1, 0, 1);
				else if( i > (-w/2)+(3*w/7) && i <= (-w/2)+(4*w/7))
					glColor3f(1, 0, 0);
				else if( i > (-w/2)+(4*w/7) && i <= (-w/2)+(5*w/7))
					glColor3f(0, 1, 1);
				else if( i > (-w/2)+(5*w/7) && i <= (-w/2)+(6*w/7))
					glColor3f(0, 1, 0);
				else if( i > (-w/2)+(6*w/7) && i <= (-w/2)+(7*w/7))
					glColor3f(0, 0, 1);

				double id, jd;
				double d = sqrt((double)(i-xc)*(i-xc)+(double)(j-yc)*(j-yc));
				if(d < r)
				{
					id = i+( D*(1-(d/ r))*( (i-xc)/r ) );
					jd = j+( D*(1-(d/ r))*( (j-yc)/r ) ); 
					glBegin(GL_POINTS);
					   glVertex2f(id,jd);
					glEnd();
				}
				else
				{
					glBegin(GL_POINTS);
					   glVertex2f(i,j);
					glEnd();
				}
			}
		}
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
  rectangle();  
}
void display() 
{  
  draw();
  glFlush();
} 
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(EXIT_SUCCESS);
}

int main(int argc, char** argv) 
{
	xc=0; yc=0;
  cout<<"Enter width and height of rectangle"<<endl;
  cin>>width>>height;
  cout<<"Enter radius of circle"<<endl;
  cin>>r;
  cout<<"Provide value of density"<<endl;
  cin>>D;
   cout<<"Provide center of circle"<<endl;
  cin>>xc>>yc;
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("RECTANGLE WITH CIRCLE");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif 
#if 0
#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;
double X1, Y1, X2, Y2, X3, Y3, X4, Y4;
double x_t, y_t;
void hermit_curve()
{
	
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	for(double u=0; u<=1; u=u+0.01)
	{
		double h1 = (1-u)*(1-u)*(1-u);
		double h2 = 3*u*(1-u)*(1-u);
		double h3 = 3*u*u*(1-u);
  		double h4 = u*u*u;

		double x = (h1*X1)+(h2*X2)+(h3*X3)+(h4*X4);
		double y = (h1*Y1)+(h2*Y2)+(h3*Y3)+(h4*Y4);
		//cout<<x<<" "<<y<<endl;		
		glVertex2d(x,y);
	}
	glEnd();
	glBegin(GL_LINES);
		glVertex2d(X1,Y1);
		glVertex2d(X2,Y2);
	glEnd();
	glBegin(GL_LINES);
		glVertex2d(X2,Y2);
		glVertex2d(X3,Y3);
	glEnd();
	glBegin(GL_LINES);
		glVertex2d(X3,Y3);
		glVertex2d(X4,Y4);
	glEnd();

	
}
void mouseClicks(int button, int state, int x, int y) 
{
	
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
   		x_t=x;
        y_t=y;
        cout<<"x_t: "<<x<<" | y_t: "<<y<<endl;
    }
	double d1, d2, d3, d4;
	d1 = sqrt(pow((x_t-X1),2) + pow((y_t-Y1),2));
	d2 = sqrt(pow((x_t-X2),2) + pow((y_t-Y2),2));
	d3 = sqrt(pow((x_t-X3),2) + pow((y_t-Y3),2));
	d4 = sqrt(pow((x_t-X4),2) + pow((y_t-Y4),2));
	if(d1 <= d2 && d1 <=d3 && d1 <= d4)
	{	
		X1=x_t; Y1 = y_t;
	}
	else if(d2 <= d1 && d2 <= d3 && d2 <= d4)
	{	
		X2=x_t; Y2 = y_t;
	}
	else if(d3 <= d1 && d3 <= d2 && d3 <= d4)
	{	
		X3=x_t; Y3 = y_t;
	}
	else
	{	
		X4=x_t; Y4 = y_t;
	}
   /* if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
    {
   		X3=x;
        Y3=y;
        cout<<"X3: "<<x<<" | Y3: "<<y<<endl;
    }*/
}
void displayMe(void)
{
    srand(time(0)); 
    glLoadIdentity();
    
    gluOrtho2D(-600, 600, -600,600);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
		 glVertex2d(-600,0);
		 glVertex2d(600,0);
		 glVertex2d(0,-600);
		 glVertex2d(0,600);
	glEnd();
        hermit_curve();
    glutPostRedisplay();
    glFlush();
}
 
int main(int argc, char** argv)
{
    /*cout<<"Enter 1st point"<<endl;
    cin>>X1>>Y1;
	cout<<"Enter 2nd point"<<endl;
    cin>>X2>>Y2;
	cout<<"Enter Derivative of point 1"<<endl;
    cin>>X3>>Y3;
    cout<<"Enter Derivative of point 2"<<endl;
    cin>>X4>>Y4;*/
	X1 = 10; Y1 = 100;
	X2 = 50; Y2 = 200;
	X3 = 150; Y3 = 200;
	X4 = 200; Y4 = 100;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glMatrixMode(GL_PROJECTION);
    glutInitWindowSize(800, 800);
    //glutInitWindowPosition(100, 100);
    glutCreateWindow("HERMIT Curve");
    glutDisplayFunc(displayMe);
    glutMouseFunc(mouseClicks);
    glutMainLoop();
    return 0;
}
#endif
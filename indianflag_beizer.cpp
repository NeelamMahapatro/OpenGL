#if 1
#include <time.h>
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
vector<pair <int, int> > v;

void draw_pixel(double X1, double Y1)
{
	glBegin(GL_POINTS);
		glVertex2d(X1, Y1);
	glEnd();
}
void bresen_line()
{
	int step = v.size()/24;

	
		cout<<v.size()<<endl;
		glBegin(GL_LINES);
	for(int i=0; i<v.size(); i+=7)
	{		
			glVertex2f(340, 360);
			glVertex2f(v[i].first, v[i].second);
	}
	glEnd();
	
}
void bezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, float r, float g, float b)
{
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	for (float i = 0; i <= 1; i = i + 0.001)
	{
		double x = (1 - i)*(1 - i)*(1 - i)*(float)x1 + 3 * i * (1 - i)*(1 - i)*(float)x2 + 3 * i * i * (1 - i)*(float)x3 + i * i * i * (float)x4;
		double y = (1 - i)*(1 - i)*(1 - i)*(float)y1 + 3 * i * (1 - i)*(1 - i)*(float)y2 + 3 * i * i * (1 - i)*(float)y3 + i * i * i * (float)y4;
		glVertex2d(x, y);
	}
	glEnd();
}
void circle(double xc, double yc, double r)
{
	    double pk, xk=0, yk=r;
		pk = 1-r;
		//glBegin(GL_POINTS);
		glColor3f(0, 0, 1);
		draw_pixel(xk+xc,yk+yc);
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
			draw_pixel(xk+xc,yk+yc);
			draw_pixel(xk+xc,-yk+yc);
			draw_pixel(-xk+xc,yk+yc);			
			draw_pixel(-xk+xc,-yk+yc);
			draw_pixel(yk+xc,xk+yc);			
			draw_pixel(yk+xc,-xk+yc);
			draw_pixel(-yk+xc,xk+yc);			
			draw_pixel(-yk+xc,-xk+yc);

			v.push_back(make_pair(xk+xc,yk+yc));
			v.push_back(make_pair(yk+xc,xk+yc));
			
			v.push_back(make_pair(yk+xc,-xk+yc));
			v.push_back(make_pair(xk+xc,-yk+yc));

			v.push_back(make_pair(-xk+xc,yk+yc));
			v.push_back(make_pair(-yk+xc,xk+yc));

			v.push_back(make_pair(-yk+xc,-xk+yc));
			v.push_back(make_pair(-xk+xc,-yk+yc));
			
		}	
		//glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	int t = 100;
	int x1 = 60, x2 = 200, x3 = 419, x4 = 591, y1 = 198, y2 = 352, y3 = 87, y4 = 223;
	int tm = 0, k=0;
	while (1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		int x;
		if ((tm / 200) % 2)
		{
			if ((tm / 100) % 2)
			{
				x = (tm % 100) - 100;
			}
			else
			{
				x = -(tm % 100);
			}
		}
		else
		{
			if ((tm / 100) % 2)
			{
				x = 100 - (tm % 100);
			}
			else
			{
				x = tm % 100;
			}
		}

		for (int i = 0; i < t; i++)
		{
			bezier(x1, y1 + i, x2, y2 + i + x, x3, y3 + i - x, x4 - int(0.15 * x), y4 + i, 0.5, 1.0, 0.0);
		}
		for (int i = t; i < 2 * t; i++)
		{
			bezier(x1, y1 + i, x2, y2 + i + x, x3, y3 + i - x, x4 - int(0.15 * x), y4 + i, 1.0, 1.0, 1.0);
		}
		for (int i = 2 * t; i < 3 * t; i++)
		{
			bezier(x1, y1 + i, x2, y2 + i + x, x3, y3 + i - x, x4 - int(0.15 * x), y4 + i, 1.0, 0.5, 0.2);
		}
		tm = tm + 5;
		if(k %4 == 0)
			circle(340+6, 360+5, 50);
		else if(k %4 == 1)
			circle(340+8, 360+4, 50);
		else if(k %4 == 2)
			circle(340+6, 360+9, 50);
		else if(k %4 == 3)
			circle(340+7, 360+4, 50); 

		k++;
		bresen_line();
		v.clear();
		Sleep(1);
		glFlush();
	}
	//bezier_curve(60, 198, 200, 352, 419, 87, 591, 223, 1.0, 0.5, 0.0);
	glFlush();
}

void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);                    
	glColor3f(0.0, 0.0, 0.0);                           
	glViewport(0, 0, 1000, 720);                         
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200, 1000, -200, 1000);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set color model
	glutInitWindowSize(700, 700);                        //set window size
	glutInitWindowPosition(0, 0);                         //set initial window position
	glutCreateWindow("WAVING INDIAN FLAG");                        //set window title
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}
#endif
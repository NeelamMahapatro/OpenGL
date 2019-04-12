#if 0
#include<iostream>
using namespace std;
#include<GL/glut.h> 
#include<math.h>  
// function to initialize 
void myInit(void)
{
        // making background color black as first 
        // 3 arguments all are 0.0 
        glClearColor(0.0, 0.0, 0.0, 1.0);

        // making picture color green (in RGB mode), as middle argument is 1.0 
        glColor3f(0.0, 1.0, 0.0);

        // breadth of picture boundary is 1 pixel 
        glPointSize(1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // setting window dimension in X- and Y- direction 
        gluOrtho2D(-780, 780, -420, 420);
}
void setPixel(int x,int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void circlePlotPoints(int x,int y,int xmx,int ymx,int xmn,int ymn )
{
	glBegin(GL_POINTS);

	for(int i=-780;i<780;i++)
	{
		glVertex2i(0,i);
		glVertex2i(i,0);
	}
	glEnd();
	if(x<xmx&&y<ymx&&x>xmn&&y>ymn)
		setPixel(x,y);
	if(-x<xmx&&y<ymx&&-x>xmn&&y>ymn)
		setPixel(-x,y);
	//if(x<xmx&&-y<ymx&&x>xmn&&-y>ymn)
		//setPixel(x,-y);
	//if(-x<xmx&&-y<ymx&&-x>xmn&&-y>ymn)
		//setPixel(-x,-y);
	if(y<xmx&&x<ymx&&y>xmn&&x>ymn)
		setPixel(y,x);
	if(-y<xmx&&x<ymx&&-y>xmn&&x>ymn)
		setPixel(-y,x);
	//if(y<xmx&&-x<ymx&&y>xmn&&-x>ymn)
		//setPixel(y,-x);
	//if(-y<xmx&&-x<ymx&&-y>xmn&&-x>ymn)
		//setPixel(-y,-x);
}
void display()
{
    double a,b,r; 
	cin>>a>>b>>r;
	int xmx=r*cos(a),xmn=r*cos(a+b);
	int ymx=r*sin(a+b),ymn=r*sin(a);
	cout<<xmx<<" "<<xmn<<" "<<ymx<<"  "<<ymn<<endl;
    int p=1-r;
	int x=0,y=r;
	circlePlotPoints(x,y,xmx,ymx,xmn,ymn);
	while(x<y)
	{
		x++;
		if(p<0)
			p+=2*x+1;
		else
		{
			y--;
			p+=2*(x-y)+1;
		}
		circlePlotPoints(x,y,max(xmx,xmn),max(ymx,ymn),min(xmn,xmx),min(ymx,ymn));
	}
	glFlush();
}


int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

        // giving window size in X- and Y- direction 
        glutInitWindowSize(700, 600);
        glutInitWindowPosition(0, 0);

        // Giving name to window 
        glutCreateWindow("MidPoint Circle Algorithm");
        myInit();

        glutDisplayFunc(display);
        glutMainLoop();
}

#endif
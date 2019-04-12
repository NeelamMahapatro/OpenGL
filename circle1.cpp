# if 0
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<iostream> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
using namespace std;

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
	gluOrtho2D(-100, 100, -50, 50);
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int xc, yc, r;
	int arr[1000][2];
	int k=0;
	cin >> xc >> yc >> r;
	glColor3f(0.0, 1.0, 1.0);
	int x = r, y = 0;
	glVertex2f(x + xc, y + yc);
	glVertex2f(x + xc, -y + yc);
	glVertex2f(y + xc, x + yc);
	glVertex2f(-y + xc, x + yc);
	
	int p = 1 - r;
	while (x > y)
	{
		y++;
		if (p <= 0)
			p = p + 2 * y + 1;
		else
		{
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
		if (x < y)
			break;
		glVertex2f(x + xc, y + yc);
		arr[k][0] = x + xc;
		arr[k][1] = y+yc;
		glVertex2f(-x + xc, y + yc);
		arr[k+1][0] = -x + xc;
		arr[k+1][1] = y+yc;
		glVertex2f(x + xc,-y + yc);
		arr[k+2][0] = x + xc;
		arr[k+2][1] = -y+yc;
		glVertex2f(-x + xc, -y + yc);
		arr[k+3][0] = -x + xc;
		arr[k+3][1] = -y+yc;
		glVertex2f(y + xc, x + yc);
		arr[k+4][0] = y + xc;
		arr[k+4][1] = x + yc;
		glVertex2f(-y + xc, x + yc);
		arr[k+5][0] = -y + xc;
		arr[k+5][1] = x + yc;
		glVertex2f(y+ xc, -x + yc);
		arr[k+6][0] = y + xc;
		arr[k+6][1] = -x + yc;
		glVertex2f(-y + xc, -x + yc);
		arr[k+7][0] = -y + xc;
		arr[k+7][1] = -x + yc;

		k=k+8;
	}

	float brr[1000][2];
	k=0;
	for(int i=-r;i<r;i++)
	{
		glVertex2f(i,0);
		brr[k][0]=i;
		brr[k][1]=0;
	//	glVertex2f(i*cos(pi/4)-i*sin(pi/4)+10, 10);
		glVertex2f(0,i);
	//	glVertex2f(10, i*sin(pi/4)+i*cos(pi/4)+10);
		brr[k+1][0]=0;
		brr[k+1][1]=i;
		k=k+2;
	}
	
	for(int i=0;i<1000;i++)
	{
		
			brr[i][0]= brr[i][0]*cos(3.14/4) -  brr[i][0]*sin(3.14/4) +10  ;
			brr[i][1]= brr[i][1]*sin(3.14/4) +  brr[i][1]*cos(3.14/4) +10  ;
			glVertex2f(brr[i][0], brr[i][1]);
	}
	int j=5;
	while(j>0)
	{
		for(int i=0;i<1000;i++)
		{
		
			arr[i][0]+= 10;
			arr[i][1]+= 10;
			glVertex2f(arr[i][0], arr[i][1]);
			
		}
		j=j--;
		
	}

//	Sleep(10);
	
	glEnd();
	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	// Giving name to window 
	glutCreateWindow("Circle Drawing");
	myInit();
	

	glutDisplayFunc(display1);
	glutMainLoop();
	return(0);
}

#endif
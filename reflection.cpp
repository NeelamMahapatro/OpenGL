#if 0
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
float pi=3.1416;
float m, c ,angle=0;
float tx=1;
int x, y, x2,y2,px,py;
float temp[3][3]={{0,0,0},{0,0,0},{0,0,0}};
float mat1[][3]=
		{ {1,0,0},
		{0,1,c},
		{0,0,1} };
float mat2[][3]=
		{ {(float)cos(atan(m)),-(float)sin(atan(m)),0},
		{(float)sin(atan(m)),(float)cos(atan(m)),0},
		{0,0,1} };
float mat3[][3]=
		{ {1,0,0},
		{0,-1,0},
		{0,0,1} };
float mat4[][3]=
		{ {(float)cos(atan(m)),(float)sin(atan(m)),0},
		{-(float)sin(atan(m)),(float)cos(atan(m)),0},
		{0,0,1} };
float mat5[][3]=
		{ {1,0,0},
		{0,1,-c},
		{0,0,1} };

void multiply(float mat1[3][3], float mat2[3][3])
{	 
	 float sum;
	 for ( int i = 0 ; i <= 2 ; i++ )
     {
        for ( int j = 0 ; j <= 2 ; j++ )
        {
         sum = 0;
         for ( int k = 0 ; k <=2 ; k++ )
             sum = sum + mat1 [i][k] * mat2[k][j];
         temp[i][j] = sum ;
        }
    }
	
}
void update() 
{ 
	multiply(mat1, mat2);
	multiply(temp, mat3);
	multiply(temp, mat4);
	multiply(temp, mat5);
} 

struct point
{
	float x,y,z;
	point(float x,float y,float z)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
};
void breson(int X0, int Y0, int X1, int Y1)
{
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int p0 = 2 * dx - dy;
	//printf("%d %d\n", X0, Y0);
	glBegin(GL_POINTS);
	glVertex2i(X0, Y0);
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	for (int i = 0; i < steps; i++)
	{
		if (p0 < 0)
		{
			//X0 = X0 + 1;
			//printf("%d %d\n", X0, Y0);
		
			Y0 = Y0 + 1;
			
			glVertex2i(X0, Y0);
			p0 = p0 + 2 * dx;
		}
		else
		{
			X0 = X0 + 1;
			
			Y0 = Y0 + 1;
			
		//	printf("%d %d\n", X0, Y0);
			glVertex2i(X0, Y0);
			p0 = p0 + 2 * dx - 2 * dy;
		}
	}

	for(int i=-780;i<420;i++)
	{
		glVertex2i(i,0);
		glVertex2i(0,i);

	}
	glEnd();
}
point getUpdate_vector(point p)
{
	float x=p.x,y=p.y,z=p.z;
	
	float cu_mat[]={x,y,z,1};
	
	float res[4];
	
    for (int i = 0; i < 3; i++) 
    {
            res[i] = 0; 
            for (int k = 0; k < 3; k++) 
                res[i] += temp[i][k] *  
                             cu_mat[k];
    }
	
	point pf=point(res[0],res[1],res[2]);
	return pf;
}

void draw()
{
  point p1(0,0,0),p2(0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);

  p1.x = px;
  p1.y = py;
  glColor3f(1, 0, 0);
  breson(x,y,x2,y2);

  glBegin(GL_POINTS);
    glVertex3f(p1.x, p1.y, p1.z);
	p2=getUpdate_vector(p1);
	glVertex3f(p2.x, p2.y, p2.z);
  glEnd();
  
}

void display() 
{
  update();
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
  cout<<"Enter 1st point"<<endl;
  cin>>x>>y;

  cout<<"Enter 2nd point"<<endl;
  cin>>x2>>y2;

  cout<<"Enter the point"<<endl;
  cin>>px>>py;

  m = (y2-y)/(x2-x);
  c = y - m*x;
  //cout<<c<<endl;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Reflection");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif 
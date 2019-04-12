#if 0
#include <GL/glut.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
using namespace std;
float pi=3.1416;
float m, c ,angle=0;
float mxangle = 45; 
float r = sqrt(pow(width/2,2) + pow(height/2,2));
float tx=1;
int width, height;

float mat[][4]=
		{ {(float)cos(angle),-(float)sin(angle),0,0},
		{(float)sin(angle),(float)cos(angle),0,0},
		{0,0,1,0},
		{0,0,0,1}};
int rec1[][3];
int rec2[][3];
int rec3[][3];
int rec4[][3];
void update() 
{ 
	/*multiply(mat1, mat2);
	multiply(temp, mat3);
	multiply(temp, mat4);
	multiply(temp, mat5);
	*/
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
void rectangle()
{
		int count=0;
	    glColor3f(1,1,0);
		
		for(int i=-(width/2); i<=-(width)/4; i++)
		{
			for(int j=-(height/2); j<=height/2; j++)
			{
				rec1[count][0] = i;
				rec1[count][1] = j;
			}
			count++;
		}
		
		count=0;
		for(int i=-(width/4); i<=0; i++)
		{
			
			for(int j=-(height/2); j<=height/2; j++)
			{
				rec2[count][0] = i;
				rec2[count][1] = j;
			}
			count++;
			
		}
		count=0;
		for(int i=0; i<=width/4; i++)
		{
			
			for(int j=-(height/2); j<=height/2; j++)
			{
			    rec3[count][0] = i;
				rec3[count][1] = j;
			}
			count++;
		}
		count=0;
		for(int i=width/4; i<=width/2; i++)
		{
			
			for(int j=-(height/2); j<=height/2; j++)
			{
			    rec4[count][0] = i;
				rec4[count][1] = j;
			}
			count++;
		}
	
}
point getUpdate_vector(point p)
{
	float x=p.x,y=p.y,z=p.z;
	
	float cu_mat[]={x,y,z,1};
	
	float res[4];
	
    for (int i = 0; i < 4; i++) 
    {
            res[i] = 0; 
            for (int k = 0; k < 4; k++) 
                res[i] += mat[i][k] * cu_mat[k];
    }
	
	point pf=point(res[0],res[1],res[2]);
	return pf;
}

void draw()
{
  point p1(0,0,0),p2(0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1, 1, 1);
  rectangle();

  
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
  cout<<"Enter width and height"<<endl;
  cin>>width>>height;
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 800);
  glutCreateWindow("TWISTING");
  glMatrixMode(GL_PROJECTION);
  glPointSize(1.0f);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
  glutDisplayFunc(display);
  glutMainLoop();
}
#endif 
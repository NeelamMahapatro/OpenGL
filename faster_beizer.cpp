#if 0
#include<iostream> 
#include<GL/glut.h> 
#include<math.h> 
#include<time.h>
#define pi 3.142857 

using namespace std;

void myInit (void) 
{	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	glColor3f(0.0, 1.0, 0.0); 
	
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	gluOrtho2D(-200, 200, -200, 200); 
} 

void display (void) 
{ 
	srand(time(0));
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POINTS); 
	glColor3f(1,1,1);
	for(float i=-200;i<=200;i+=0.001){
		glVertex2f(i,0);
		glVertex2f(0,i);
	}
	glEnd();
	float p[4][2];
	cout<<"Enter value of A "<<endl;
	cin>>p[0][0]>>p[0][1];
	
	cout<<"Enter value of B "<<endl;
	cin>>p[1][0]>>p[1][1];
	
	cout<<"Enter value of C "<<endl;
	cin>>p[2][0]>>p[2][1];

	cout<<"Enter value of D "<<endl;
	cin>>p[3][0]>>p[3][1];
	
	float x_c=p[0][0],y_c=p[0][1],dddf_x=0,dddf_y=0,ddf_x=0,ddf_y=0,df_x=0,df_y=0;
	
	df_x=3*(p[1][0]-p[0][0])*0.01+(3*(p[0][0]-2*p[1][0]+p[2][0]))*pow(0.01,2)
		+(3*(p[1][0]-p[2][0])-p[0][0]+p[3][0])*pow(0.01,3);
	df_y=3*(p[1][1]-p[0][1])*0.01+(3*(p[0][1]-2*p[1][1]+p[2][1]))*pow(0.01,2)
		+(3*(p[1][1]-p[2][1])-p[0][1]+p[3][1])*pow(0.01,3);
	
	ddf_x=2*(3*(p[0][0]-2*p[1][0]+p[2][0]))*pow(0.01,2)
		+6*(3*(p[1][0]-p[2][0])-p[0][0]+p[3][0])*pow(0.01,3);
	ddf_y=2*(3*(p[0][1]-2*p[1][1]+p[2][1]))*pow(0.01,2)
		+6*(3*(p[1][1]-p[2][1])-p[0][1]+p[3][1])*pow(0.01,3);
	
	dddf_x=6*(3*(p[1][0]-p[2][0])-p[0][0]+p[3][0])*pow(0.01,3);
	dddf_y=6*(3*(p[1][1]-p[2][1])-p[0][1]+p[3][1])*pow(0.01,3);
	
	glBegin(GL_POINTS);
	for(float u=0;u<=1;u+=0.01){
		glVertex2f(x_c,y_c);
		ddf_x+=dddf_x;
		ddf_y+=dddf_y;
		df_x+=ddf_x;
		df_y+=ddf_y;
		x_c+=df_x;
		y_c+=df_y;				
	}
	glVertex2f(x_c,y_c);
	
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 	
	glutInitWindowSize(800,800); 
	glutInitWindowPosition(0, 0); 
	
	glutCreateWindow("Faster Beizer!!!"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 
#endif

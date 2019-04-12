/*
// C program to demonstrate 
// drawing a circle using 
// OpenGL 

#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(1.0, 0.0, 0.0); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} 


void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 

	glBegin(GL_POLYGON);
	  glColor3f(1.0,1.0,0.0);
	  glVertex3f(0.5f,0.5f,0.5f);
	  glVertex3f(0.6f,0.5f,0.7f);
	  glVertex3f(0.8f,0.5f,0.9f);
	glEnd();
	glBegin(GL_QUADS);
	  glColor3f(1.0,0.0,0.0);
	  glVertex2f(-150,100);
	  glVertex2f(150,100);
	  glVertex2f(150,100/3);
	  glVertex2f(-150,100/3);
	glEnd();

	glBegin(GL_QUADS);
	  glColor3f(1.0,0.0,0.0);
	  glVertex2f(-150,100);
	  glVertex2f(150,100);
	  glVertex2f(150,100/3);
	glVertex2f(-150,100/3);
	glEnd();
	glBegin(GL_QUADS);
	  glColor3f(0.0,1.0,0.0);
	  glVertex2f(-150,100/3);
	  glVertex2f(150,100/3);
	  glVertex2f(-150,-100/3);
	glVertex2f(150,-100/3);
	glEnd();

	glBegin(GL_QUADS);
	  glColor3f(0.0,1.0,0.0);
	  glVertex2f(-150,-100);
	  glVertex2f(150,-100);
	  glVertex2f(-150,-100/3);
	glVertex2f(150,-100/3);
	glEnd();
	

	
	
	
	
	
	
	
	

	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(-150, 0); 
	
	// Giving name to window 
	glutCreateWindow("Flag Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
}

*/
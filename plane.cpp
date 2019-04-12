#if 0

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display();
void specialKeys();

double rotate_y = 0;
double rotate_x = 0;
void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	 glTranslatef( -0.4, 0, 0);      // Not included
	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included

	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// Other Transformations
	glScalef(.5,.5,.5);          // Not included

	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);     glVertex3f(2, 0, -1);      // P1 is red
	glColor3f(.0, 1.0, 0.0);      glVertex3f(2, 1, -2);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(1, 1, -1);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(1, 0, 0);      // P4 is purple
	
	glEnd();

	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 0.0, 0.0);     glVertex3f(2, 0, -1);      // P1 is red
	glColor3f(1.0, 1.0, 0.0);     glVertex3f(2, 1, -3);      // P2 is green
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(1, 1, -2);      // P3 is blue
	glColor3f(1.0, 0.0, 0.0);     glVertex3f(1, 0, 0);      // P4 is purple

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);     glVertex3f(1, 0, 0);      // P1 is red
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(2, -1, -1);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(0, 1, 1);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(.5, 2, 0);      // P4 is purple

	glEnd();

	glFlush();
	glutSwapBuffers();

}
void specialKeys(int key, int x, int y) {

	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	glutPostRedisplay();

}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Plane");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}

#endif
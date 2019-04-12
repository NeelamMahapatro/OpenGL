# if 0

#include<Windows.h>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<iostream> 

using namespace std;
// function to initialize 
float a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3;
void myInit (void) 
{ 

         glClearColor(0.0, 0.0, 0.0, 1.0);   
        glMatrixMode(GL_DEPTH_TEST); 
        glLoadIdentity();
        gluPerspective(0,0,0,0);
        glOrtho(1000.0, 1000.0, 1000.0, 1000.0, 1000.0 ,1000.0); 
        //glViewport(20, 30, 1000, 500);
} 

void display()
{ 
	glScalef(.5,.5,.5);
        glClear(GL_COLOR_BUFFER_BIT); 
        glBegin(GL_QUADS); 
        glColor3f(1,0,1);
        glVertex3f(0,0,-d1/c1);
        glVertex3f(0,-d1/b1,0);
        glVertex3f(-d1/a1,0,0);
        glVertex3f(0,1,-(d1+b1)/c1);

        glColor3f(1,1,0);
        glVertex3f(0,0,-d2/c2);
        glVertex3f(0,-d2/b2,0);
        glVertex3f(-d2/a2,0,0);
        glVertex3f(0,1,-(d2+b2)/c2);
        
        glColor3f(0,1,1);
        glVertex3f(0,0,-d3/c3);
        glVertex3f(0,-d3/b3,0);
        glVertex3f(-d3/a3,0,0);
        glVertex3f(0,1,-(d3+b3)/c3);
        
        glEnd();
        glFlush(); 
} 

int main (int argc, char** argv) 
{ 
        cout<<"Enter the 1st plane\n"; 
        cin>>a1>>b1>>c1>>d1;
        cout<<"Enter the 2nd plane\n"; 
        cin>>a2>>b2>>c2>>d2;
        cout<<"Enter the 3rd plane\n"; 
        cin>>a3>>b3>>c3>>d3;
        glutInit(&argc, argv); 
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
        
        // giving window size in X- and Y- direction 
        glutInitWindowSize(250, 250); 
        glutInitWindowPosition(0,0); 
        
        // Giving name to window 
        glutCreateWindow("Rectangle drawing"); 
        myInit(); 
        
        glutDisplayFunc(display); 
        glutMainLoop(); 
        return 0;
}

#endif
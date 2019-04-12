#if 0
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <iostream>
#define pi 3.1429

void myInit(){
        
        // background is black since rgb is 000 and blending is on;1
    glClearColor(0.0, 0.0, 0.0, 1.0);    
        
        // breadth of picture boundary is 1 pixel
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        
    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}
void display(){
        
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
                glPointSize(0.01);
        float xc,yc,i,m=1,j;
        
       for(i=0;i<2*pi;i+=0.001){
                   xc=i*50;
                   yc=20*sin(i);
                   for(j=0;j<50;j++){
                           glColor3f(0,1,0);
                           yc+=1;
                           glVertex2f(xc,yc);
                   }
                    for(j=0;j<50;j++){
                           glColor3f(1,1,1);
                           yc+=1;
                           glVertex2f(xc,yc);
                   }
                    for(j=0;j<50;j++){
                           glColor3f(1,0.6,0);
                           yc+=1;
                           glVertex2f(xc,yc);
                   }
           }
           xc=pi*50;
           yc=30*sin(pi) +75;
           glColor3f(0,0,1);
           glVertex2f(xc,yc);
           for(i=0;i<2*pi;i+=(float)0.001){
                        glColor3f(0,0,1);
                        xc =pi*50+ 25*cos(i);
                        yc =30*sin(pi) +75+ 25*sin(i);
                        
                        glVertex2f(xc,yc);
                }
        glEnd();
        glFlush();
        
}
int main(int argc, char** argv){
        glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        
        //window dimensions!!!
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(0, 0);
            
    
    glutCreateWindow("My Screen!!!");
    myInit();
        
    glutDisplayFunc(display);
        glutMainLoop();
}
#endif


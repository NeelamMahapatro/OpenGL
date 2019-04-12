#if 0
#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
GLdouble X1, Y1, X2, Y2, x1, y2, r;
int c;
#define pi 3.14

void draw(double X, double Y)
{
        glBegin(GL_POINTS);
        glColor3f(0.0, 1.0, 0.0);
			glScalef(2, 2, 2);
        glVertex2i(x1 + X, Y + y2);

        glEnd();
}
void dda(int X1, int Y1, int X2, int Y2)
{
        //cout << "C is" << c << endl;
        cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
        int sum;
        double a, b, e, d;
        double rad = pi / 180;

        a = X1; b = Y1; e = X2; d = Y2;

        //cout << a << "" << b << "" << c << "" << d << endl;
        X1 = a*cos(c * 45 * rad) - Y1*sin(c * 45 * rad);
        Y1 = a*sin(c * 45 * rad) + Y1*cos(c * 45 * rad);
        X2 = e*cos(c * 45 * rad) - Y2*sin(c * 45 * rad);
        Y2 = e*sin(c * 45 * rad) + Y2*cos(c * 45 * rad);



        X1 = X1 + x1;
        X2 = X2 + x1;
        Y1 = Y1 + y2;
        Y2 = Y2 + y2;

        cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
        //X1 = a; Y1 = b; X2 = c; Y2 = d;

        GLdouble dx = X2 - X1, dy = Y2 - Y1, steps;                // calculate diff betn line end points
        float xInc, yInc, x = X1, y = Y1;
        steps = (abs(dx)>abs(dy)) ? abs(dx) : abs(dy);        //max diff is length
        xInc = dx / (float)steps;
        yInc = dy / (float)steps;
        //glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(x, y);                                        //plot initial point
        for (int k = 0; k<steps; k++)
        {
                x += xInc;                                                //decide next incremented x co-ord
                y += yInc;


                glVertex2f(x, y);                                         //plot each incremented  point till length

        }
        glEnd();
        glFlush();
}
void circle()
{

        GLdouble p0, p, X, Y;
        p0 = 1 - r;
        p = p0;
        X = 0;
        Y = r;
        draw(X, Y);
        draw(X, -Y);
        draw(-X, Y);
        draw(-X, -Y);
        draw(Y, X);
        draw(Y, -X);
        draw(-Y, X);
        draw(-Y, -X);

        while (X<Y)
        {
                if (p <= 0)
                {

                        p = p + (2 * X) + 3;
                        X = X + 1;
                }
                else
                {

                        p = p + (2 * X) + 5 - (2 * Y);
                        X = X + 1;
                        Y = Y - 1;

                }
                draw(X, Y);
                draw(X, -Y);
                draw(-X, Y);
                draw(-X, -Y);
                draw(Y, X);
                draw(Y, -X);
                draw(-Y, X);
                draw(-Y, -X);


        }
        glFlush();
        dda(0, r, 0, -r);
        dda(-r, 0, r, 0);
        Sleep(1000);
        x1 = x1 + r;




}
void display()
{
	for(int i=-100;i<100;i++)
	{
		 glVertex2i(i, 0);
		  glVertex2i(0, i);
	}
        for (int i = 0; i < 10; i++){
                glClear(GL_COLOR_BUFFER_BIT);
                circle();
                c++;
        }

}
void Init()
{
        glClearColor(0.0, 0.0, 0.0, 1);
        glColor3f(0.0, 0.1, 0.0);
        glViewport(0, 0, 640, 480);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100.0, 100.0, -100.0, 100);
}
int main(int argc, char **argv)
{
        cout << "\nEnter Centre( X1 , Y1):";
        cin >> x1 >> y2;
        cout << "\nEnter the Radius:";
        cin >> r;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1366, 768);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Rotation");
        Init();
        
        glutDisplayFunc(display);
        
        glutMainLoop();
        return 0;
}
#endif
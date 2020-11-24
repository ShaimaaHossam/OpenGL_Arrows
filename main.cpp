#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <string>
#endif

#include <stdlib.h>
int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int centerX = logWidth/2;
int centerY = logHeight/2;
int alphaX, alphaY = 0;
int sqWid = 20;
int right=0; int left=0; int up=0; int down =0;
int score = 0;
char* s;



void specKeyboard(int key, int x, int y)
{
if(key==GLUT_KEY_UP)
{

up=1; down=0; left=0; right=0;
}
if(key== GLUT_KEY_DOWN)
{

up=0; down=1; left=0; right=0;
}
if(key== GLUT_KEY_LEFT)
{

up=0; down=0; left=1; right=0;
}
if(key== GLUT_KEY_RIGHT)
{

up=0; down=0; left=0; right=1;
}


glutPostRedisplay();
}



void display(void){
      glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex2f(centerX-sqWid/2, centerY-sqWid/2);
glVertex2f(centerX+sqWid/2, centerY-sqWid/2);
glVertex2f(centerX+sqWid/2, centerY+sqWid/2);
glVertex2f(centerX-sqWid/2, centerY+sqWid/2);
glEnd();

if(right ==1){
        \
glBegin(GL_POLYGON);
glVertex2f(60,70);
glVertex2f(60,30);
glVertex2f(70,50);
glEnd();
}
if(left ==1){

glBegin(GL_POLYGON);
glVertex2f(40,70);
glVertex2f(40,30);
glVertex2f(30,50);
glEnd();
}
if(up ==1){

glBegin(GL_POLYGON);
glVertex2f(70,60);
glVertex2f(30,60);
glVertex2f(50,70);
glEnd();
}
if(down ==1){

glBegin(GL_POLYGON);
glVertex2f(70,40);
glVertex2f(30,40);
glVertex2f(50,30);
glEnd();
}



glutSwapBuffers();
      glFlush();

}
void init(){
      glClearColor(1.0,1.0,1.0,1.0);
      glMatrixMode(GL_PROJECTION);
      gluOrtho2D(0.0,logWidth,0.0,logHeight);

}
int main(int argc, char* argv[]){

      glutInit( &argc, argv);
      glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowPosition( 100, 100);
      glutInitWindowSize( phyWidth, phyHeight);
      glutCreateWindow( "quiz");
      init();
      glutDisplayFunc(display);
      glutSpecialFunc(specKeyboard);
      glutMainLoop();
}

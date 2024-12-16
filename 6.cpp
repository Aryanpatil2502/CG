//C6

//Installation for OpenGl Linux- 
//sudo apt-get update
//sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev libx11-dev
//sudo apt install plocate
//locate libGL.so
//g++ OpenGL.cpp -o cube -L/lib/x86_64-linux-gnu -lGL -lGLU -lglut

//For Running the File- g++ OpenGL.cpp -o cube -lGL -lGLU -lglut
//./cube


#include<GL/glut.h>

void mydisplay()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glLoadIdentity();  //resets modelview matrix
   
glTranslatef(0.0,0.0,-5.0);
//glScalef(1.0,0.5,1.0);
glRotatef(20.0,1.0,0.0,0.0);
//glRotatef(-65.0,1.0,0.0,0.0);
 
  
   
   glBegin(GL_QUADS);
   //front (red)
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    
    //back (green)
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    
    //right (blue)
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    
    //left (yellow)
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    
    //top (cyan)
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    
    //bottom (magenta)
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
   
   glEnd();
   
   glFlush();
}

void init()
{
  glClearColor(0.0,0.0,0.0,1.0);
  glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();  //resets projection matrix
  gluPerspective(60,1,2.0,50.0);
 //glOrtho(-5,5,-5,5,-5,5);
   glMatrixMode(GL_MODELVIEW);  
  
}


int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow("3D transformations");
  glutDisplayFunc(mydisplay);
 glutReshapeFunc(reshape);
  init();
  glutMainLoop();
}



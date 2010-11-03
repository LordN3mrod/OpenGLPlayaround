#include "glwidgettest2.h"

GLWidgetTest2::GLWidgetTest2(QWidget *parent) :
    GLWidget(parent), MaxX(100.0), MaxZ(100.0)

{
}

void GLWidgetTest2::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, (double)w/h, -50 , 50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 50, -50, 0,0,0, 0,1,0);
}

void GLWidgetTest2::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    DrawScene();
    glFlush();
}

void GLWidgetTest2::DrawScene()
{
    glBegin(GL_POLYGON);
    glColor3ub(245,245,220);//beige
    glVertex3d(-10, 0, -10);
    glVertex3d(-10, 0,  10);
    glVertex3d( 10, 0,  10);
    glVertex3d( 10, 0, -10);
    glEnd();
}

void GLWidgetTest2::initializeGL()
{
    qglClearColor(Qt::black);
}


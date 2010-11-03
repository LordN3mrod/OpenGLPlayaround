#include "glwidgettest1.h"

GLWidgetTest1::GLWidgetTest1(QWidget *parent) :
    GLWidget(parent)
{
}

void GLWidgetTest1::initializeGL()
{
    qglClearColor(Qt::black);
}

void GLWidgetTest1::DrawTetrahedron()
{
    static float deg1 = 0;
    static float deg2 = 0;
    static float deg3 = 0;
    const float d1 = 1;
    const float d2 = 0.4;
    const float d3 = 1.4;

    glPushMatrix();
    glRotatef(deg3, 1, 2, 3.5);
    glRotatef(deg1, 0, 1, 0);
    glRotatef(deg2, 1,0,0);

    deg1 += d1;
    deg2 += d2;
    deg3 += d3;

    if(deg1 >= 360.0)
        deg1 -= 360.0;

    if(deg2 >= 360.0)
        deg2 -= 360.0;

    static Point3F v1 = {-0.5,-0.5,-0.5};
    static Point3F v2 = { 0  ,-0.5, 0.5};
    static Point3F v3 = { 0.5,-0.5,-0.5};
    static Point3F v4 = { 0,   0.5, 0  };

    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
    {
        qglColor(Qt::red);
        glVertex3fv(v3);
        qglColor(Qt::green);
        glVertex3fv(v2);
        qglColor(Qt::white);
        glVertex3fv(v1);

        qglColor(Qt::white);
        glVertex3fv(v1);
        qglColor(Qt::green);
        glVertex3fv(v2);
        qglColor(Qt::blue);
        glVertex3fv(v4);

        qglColor(Qt::blue);
        glVertex3fv(v4);
        qglColor(Qt::red);
        glVertex3fv(v3);
        qglColor(Qt::white);
        glVertex3fv(v1);

        qglColor(Qt::green);
        glVertex3fv(v2);
        qglColor(Qt::red);
        glVertex3fv(v3);
        qglColor(Qt::blue);
        glVertex3fv(v4);
    } glEnd();
    glPopMatrix();
    glDisable(GL_CULL_FACE);

    update();
}


void GLWidgetTest1::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0001,1.0001, -1.0001,1.0001, -1.0001,1.0001);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void GLWidgetTest1::DrawBorder()
{
    qglColor(Qt::blue);

    glPushAttrib(GL_LINE_BIT);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(-1,-1);
        glVertex2f(-1,1);
        glVertex2f(1,1);
        glVertex2f(1,-1);
    }glEnd();

    glPopAttrib();
}

void GLWidgetTest1::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawTetrahedron();
    DrawBorder();

}


#include "glwidget.h"
#include <QtGui>
#include <cmath>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

}


void GLWidget::toggleFullScreen()
{
    if(isFullScreen())
    {
        showNormal();
    }
    else
    {
        showFullScreen();
    }
}

void GLWidget::mouseDoubleClickEvent(QMouseEvent*)
{
    toggleFullScreen();
}


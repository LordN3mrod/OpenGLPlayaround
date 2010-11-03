#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void toggleFullScreen();

protected:

    void mouseDoubleClickEvent(QMouseEvent*);

    typedef GLfloat Point3F[3];
};

#endif // GLWIDGET_H

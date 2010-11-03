#ifndef GLWIDGETTEST2_H
#define GLWIDGETTEST2_H

#include <glwidget.h>

class GLWidgetTest2 : public GLWidget
{
    Q_OBJECT
public:
    explicit GLWidgetTest2(QWidget *parent = 0);

protected:
    void resizeGL(int w, int h);
    void paintGL();
    void initializeGL();

    void DrawScene();

private:
    double MaxX;
    double MaxZ;
};

#endif // GLWIDGETTEST2_H

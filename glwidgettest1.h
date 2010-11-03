#ifndef GLWIDGETTEST1_H
#define GLWIDGETTEST1_H

#include "glwidget.h"

class GLWidgetTest1 : public GLWidget
{
public:
 explicit GLWidgetTest1(QWidget *parent = 0);

protected:
 void initializeGL();
 void resizeGL(int w, int h);
 void paintGL();

 void DrawTetrahedron();
 void DrawBorder();
};

#endif // GLWIDGETTEST1_H

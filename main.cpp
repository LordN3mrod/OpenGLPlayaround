#include <QApplication>
#include "glwidget.h"
#include "glwidgettest1.h"
#include "glwidgettest2.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    GLWidget* w = new GLWidgetTest2;
    w->showNormal();

    return app.exec();
}

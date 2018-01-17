#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>

class OpenGLWidget : public QOpenGLWidget
{

    Q_OBJECT
	
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

};

#endif 
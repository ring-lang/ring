/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include "ringqt.h"
#include <QOpenGLWidget>

extern "C" {
#include "ring.h"
}

class OpenGLWidget : public QOpenGLWidget
{

    Q_OBJECT

public:

    OpenGLWidget(QWidget *parent,VM *pVM);
    ~OpenGLWidget();

    VM *pVM;
    List *pParaList;
    char cInitEvent[RINGQT_EVENT_SIZE];
    char cPaintEvent[RINGQT_EVENT_SIZE];
    char cResizeEvent[RINGQT_EVENT_SIZE];
    void geteventparameters(void) ;
    void setInitEvent(const char *cStr);
    const char *getInitEvent(void);
    void setPaintEvent(const char *cStr);
    const char *getPaintEvent(void);
    void setResizeEvent(const char *cStr);
    const char *getResizeEvent(void);
		
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

};

#endif 
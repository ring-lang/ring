/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
#include "ring.h"
}

#include <QOpenGLWidget>
#include "openglwidget.h"

void OpenGLWidget::initializeGL()
{
}

void OpenGLWidget::paintGL()
{
}

void OpenGLWidget::resizeGL(int width, int height)
{
}

OpenGLWidget::OpenGLWidget(QWidget *parent,VM *pVM)  : QOpenGLWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cInitEvent,"");
}

OpenGLWidget::~OpenGLWidget()
{
	ring_list_delete(this->pParaList);
}

void OpenGLWidget::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}

void OpenGLWidget::setInitEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cInitEvent,cStr);
}

const char *OpenGLWidget::getInitEvent(void)
{
	return this->cInitEvent;
}

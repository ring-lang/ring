/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
#include "ring.h"
}

#include <QOpenGLWidget>
#include "openglwidget.h"

void OpenGLWidget::initializeGL()
{
	if (strcmp(this->cInitEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cInitEvent);
}

void OpenGLWidget::paintGL()
{
	if (strcmp(this->cPaintEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cPaintEvent);
}

void OpenGLWidget::resizeGL(int width, int height)
{
	if (strcmp(this->cResizeEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cResizeEvent);
}

OpenGLWidget::OpenGLWidget(QWidget *parent,VM *pVM)  : QOpenGLWidget(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->cInitEvent,"");
	strcpy(this->cPaintEvent,"");
	strcpy(this->cResizeEvent,"");
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

void OpenGLWidget::setPaintEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cPaintEvent,cStr);
}

const char *OpenGLWidget::getPaintEvent(void)
{
	return this->cPaintEvent;
}

void OpenGLWidget::setResizeEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cResizeEvent,cStr);
}

const char *OpenGLWidget::getResizeEvent(void)
{
	return this->cResizeEvent;
}

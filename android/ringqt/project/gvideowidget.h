
/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVIDEOWIDGET_H
#define GVIDEOWIDGET_H
#include <QApplication>
#include <QVideoWidget>
extern "C" {
#include "ring.h"
}

class GVideoWidget : public QVideoWidget
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cbrightnessChangedEvent[100];
    char ccontrastChangedEvent[100];
    char cfullScreenChangedEvent[100];
    char chueChangedEvent[100];
    char csaturationChangedEvent[100];


    GVideoWidget(QWidget *parent,VM *pVM );

    ~GVideoWidget();

    void geteventparameters(void) ;

    void setbrightnessChangedEvent(const char *cStr);
    void setcontrastChangedEvent(const char *cStr);
    void setfullScreenChangedEvent(const char *cStr);
    void sethueChangedEvent(const char *cStr);
    void setsaturationChangedEvent(const char *cStr);


    const char *getbrightnessChangedEvent(void);
    const char *getcontrastChangedEvent(void);
    const char *getfullScreenChangedEvent(void);
    const char *gethueChangedEvent(void);
    const char *getsaturationChangedEvent(void);


  public slots:

    void brightnessChangedSlot();
    void contrastChangedSlot();
    void fullScreenChangedSlot();
    void hueChangedSlot();
    void saturationChangedSlot();

};

#endif


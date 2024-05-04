
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GVIDEOWIDGET_H
#define GVIDEOWIDGET_H
#include "ringqt.h"
#include <QVideoWidget>

extern "C" {
#include "ring.h"
}

class GVideoWidget : public QVideoWidget
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbrightnessChangedEvent[RINGQT_EVENT_SIZE];
    char ccontrastChangedEvent[RINGQT_EVENT_SIZE];
    char cfullScreenChangedEvent[RINGQT_EVENT_SIZE];
    char chueChangedEvent[RINGQT_EVENT_SIZE];
    char csaturationChangedEvent[RINGQT_EVENT_SIZE];


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


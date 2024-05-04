
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSERIALPORT_H
#define GSERIALPORT_H
#include "ringqt.h"
#include <QSerialPort>

extern "C" {
#include "ring.h"
}

class GSerialPort : public QSerialPort
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char cbaudRateChangedEvent[RINGQT_EVENT_SIZE];
    char cbreakEnabledChangedEvent[RINGQT_EVENT_SIZE];
    char cdataBitsChangedEvent[RINGQT_EVENT_SIZE];
    char cdataTerminalReadyChangedEvent[RINGQT_EVENT_SIZE];
    char cerrorEvent[RINGQT_EVENT_SIZE];
    char cflowControlChangedEvent[RINGQT_EVENT_SIZE];
    char cparityChangedEvent[RINGQT_EVENT_SIZE];
    char crequestToSendChangedEvent[RINGQT_EVENT_SIZE];
    char cstopBitsChangedEvent[RINGQT_EVENT_SIZE];


    GSerialPort(QObject *parent,VM *pVM );

    ~GSerialPort();

    void geteventparameters(void) ;

    void setbaudRateChangedEvent(const char *cStr);
    void setbreakEnabledChangedEvent(const char *cStr);
    void setdataBitsChangedEvent(const char *cStr);
    void setdataTerminalReadyChangedEvent(const char *cStr);
    void seterrorEvent(const char *cStr);
    void setflowControlChangedEvent(const char *cStr);
    void setparityChangedEvent(const char *cStr);
    void setrequestToSendChangedEvent(const char *cStr);
    void setstopBitsChangedEvent(const char *cStr);


    const char *getbaudRateChangedEvent(void);
    const char *getbreakEnabledChangedEvent(void);
    const char *getdataBitsChangedEvent(void);
    const char *getdataTerminalReadyChangedEvent(void);
    const char *geterrorEvent(void);
    const char *getflowControlChangedEvent(void);
    const char *getparityChangedEvent(void);
    const char *getrequestToSendChangedEvent(void);
    const char *getstopBitsChangedEvent(void);


  public slots:

    void baudRateChangedSlot();
    void breakEnabledChangedSlot();
    void dataBitsChangedSlot();
    void dataTerminalReadyChangedSlot();
    void errorSlot();
    void flowControlChangedSlot();
    void parityChangedSlot();
    void requestToSendChangedSlot();
    void stopBitsChangedSlot();



};

#endif



/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GSERIALPORT_H
#define GSERIALPORT_H
#include <QApplication>
#include <QSerialPort>
extern "C" {
#include "ring.h"
}

class GSerialPort : public QSerialPort
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

    char cbaudRateChangedEvent[200];
    char cbreakEnabledChangedEvent[200];
    char cdataBitsChangedEvent[200];
    char cdataTerminalReadyChangedEvent[200];
    char cerrorEvent[200];
    char cflowControlChangedEvent[200];
    char cparityChangedEvent[200];
    char crequestToSendChangedEvent[200];
    char cstopBitsChangedEvent[200];


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


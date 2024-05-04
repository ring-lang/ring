
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef GWEBENGINEPAGE_H
#define GWEBENGINEPAGE_H
#include "ringqt.h"
#include <QWebEnginePage>

extern "C" {
#include "ring.h"
}

class GWebEnginePage : public QWebEnginePage
{

  Q_OBJECT

  public:

    struct VM *pVM;

    struct List *pParaList;

    char caudioMutedChangedEvent[RINGQT_EVENT_SIZE];
    char cauthenticationRequiredEvent[RINGQT_EVENT_SIZE];
    char ccontentsSizeChangedEvent[RINGQT_EVENT_SIZE];
    char cfeaturePermissionRequestCanceledEvent[RINGQT_EVENT_SIZE];
    char cfeaturePermissionRequestedEvent[RINGQT_EVENT_SIZE];
    char cfindTextFinishedEvent[RINGQT_EVENT_SIZE];
    char cfullScreenRequestedEvent[RINGQT_EVENT_SIZE];
    char cgeometryChangeRequestedEvent[RINGQT_EVENT_SIZE];
    char ciconChangedEvent[RINGQT_EVENT_SIZE];
    char ciconUrlChangedEvent[RINGQT_EVENT_SIZE];
    char clinkHoveredEvent[RINGQT_EVENT_SIZE];
    char cloadFinishedEvent[RINGQT_EVENT_SIZE];
    char cloadProgressEvent[RINGQT_EVENT_SIZE];
    char cloadStartedEvent[RINGQT_EVENT_SIZE];
    char cpdfPrintingFinishedEvent[RINGQT_EVENT_SIZE];
    char cprintRequestedEvent[RINGQT_EVENT_SIZE];
    char cproxyAuthenticationRequiredEvent[RINGQT_EVENT_SIZE];
    char cquotaRequestedEvent[RINGQT_EVENT_SIZE];
    char crecentlyAudibleChangedEvent[RINGQT_EVENT_SIZE];
    char crecommendedStateChangedEvent[RINGQT_EVENT_SIZE];
    char cregisterProtocolHandlerRequestedEvent[RINGQT_EVENT_SIZE];
    char cscrollPositionChangedEvent[RINGQT_EVENT_SIZE];
    char cselectClientCertificateEvent[RINGQT_EVENT_SIZE];
    char cselectionChangedEvent[RINGQT_EVENT_SIZE];
    char ctitleChangedEvent[RINGQT_EVENT_SIZE];
    char curlChangedEvent[RINGQT_EVENT_SIZE];
    char cvisibleChangedEvent[RINGQT_EVENT_SIZE];
    char cwindowCloseRequestedEvent[RINGQT_EVENT_SIZE];


    GWebEnginePage(QObject * parent,VM *pVM );

    ~GWebEnginePage();

    void geteventparameters(void) ;

    void setaudioMutedChangedEvent(const char *cStr);
    void setauthenticationRequiredEvent(const char *cStr);
    void setcontentsSizeChangedEvent(const char *cStr);
    void setfeaturePermissionRequestCanceledEvent(const char *cStr);
    void setfeaturePermissionRequestedEvent(const char *cStr);
    void setfindTextFinishedEvent(const char *cStr);
    void setfullScreenRequestedEvent(const char *cStr);
    void setgeometryChangeRequestedEvent(const char *cStr);
    void seticonChangedEvent(const char *cStr);
    void seticonUrlChangedEvent(const char *cStr);
    void setlinkHoveredEvent(const char *cStr);
    void setloadFinishedEvent(const char *cStr);
    void setloadProgressEvent(const char *cStr);
    void setloadStartedEvent(const char *cStr);
    void setpdfPrintingFinishedEvent(const char *cStr);
    void setprintRequestedEvent(const char *cStr);
    void setproxyAuthenticationRequiredEvent(const char *cStr);
    void setquotaRequestedEvent(const char *cStr);
    void setrecentlyAudibleChangedEvent(const char *cStr);
    void setrecommendedStateChangedEvent(const char *cStr);
    void setregisterProtocolHandlerRequestedEvent(const char *cStr);
    void setscrollPositionChangedEvent(const char *cStr);
    void setselectClientCertificateEvent(const char *cStr);
    void setselectionChangedEvent(const char *cStr);
    void settitleChangedEvent(const char *cStr);
    void seturlChangedEvent(const char *cStr);
    void setvisibleChangedEvent(const char *cStr);
    void setwindowCloseRequestedEvent(const char *cStr);


    const char *getaudioMutedChangedEvent(void);
    const char *getauthenticationRequiredEvent(void);
    const char *getcontentsSizeChangedEvent(void);
    const char *getfeaturePermissionRequestCanceledEvent(void);
    const char *getfeaturePermissionRequestedEvent(void);
    const char *getfindTextFinishedEvent(void);
    const char *getfullScreenRequestedEvent(void);
    const char *getgeometryChangeRequestedEvent(void);
    const char *geticonChangedEvent(void);
    const char *geticonUrlChangedEvent(void);
    const char *getlinkHoveredEvent(void);
    const char *getloadFinishedEvent(void);
    const char *getloadProgressEvent(void);
    const char *getloadStartedEvent(void);
    const char *getpdfPrintingFinishedEvent(void);
    const char *getprintRequestedEvent(void);
    const char *getproxyAuthenticationRequiredEvent(void);
    const char *getquotaRequestedEvent(void);
    const char *getrecentlyAudibleChangedEvent(void);
    const char *getrecommendedStateChangedEvent(void);
    const char *getregisterProtocolHandlerRequestedEvent(void);
    const char *getscrollPositionChangedEvent(void);
    const char *getselectClientCertificateEvent(void);
    const char *getselectionChangedEvent(void);
    const char *gettitleChangedEvent(void);
    const char *geturlChangedEvent(void);
    const char *getvisibleChangedEvent(void);
    const char *getwindowCloseRequestedEvent(void);


  public slots:

    void audioMutedChangedSlot();
    void authenticationRequiredSlot();
    void contentsSizeChangedSlot();
    void featurePermissionRequestCanceledSlot();
    void featurePermissionRequestedSlot();
    void findTextFinishedSlot();
    void fullScreenRequestedSlot();
    void geometryChangeRequestedSlot();
    void iconChangedSlot();
    void iconUrlChangedSlot();
    void linkHoveredSlot();
    void loadFinishedSlot();
    void loadProgressSlot();
    void loadStartedSlot();
    void pdfPrintingFinishedSlot();
    void printRequestedSlot();
    void proxyAuthenticationRequiredSlot();
    void quotaRequestedSlot();
    void recentlyAudibleChangedSlot();
    void recommendedStateChangedSlot();
    void registerProtocolHandlerRequestedSlot();
    void scrollPositionChangedSlot();
    void selectClientCertificateSlot();
    void selectionChangedSlot();
    void titleChangedSlot();
    void urlChangedSlot();
    void visibleChangedSlot();
    void windowCloseRequestedSlot();



};

#endif


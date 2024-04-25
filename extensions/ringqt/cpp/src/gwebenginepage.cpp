
/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "gwebenginepage.h"

GWebEnginePage::GWebEnginePage(QObject * parent,VM *pVM)  : QWebEnginePage(parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
	strcpy(this->caudioMutedChangedEvent,"");
	strcpy(this->cauthenticationRequiredEvent,"");
	strcpy(this->ccontentsSizeChangedEvent,"");
	strcpy(this->cfeaturePermissionRequestCanceledEvent,"");
	strcpy(this->cfeaturePermissionRequestedEvent,"");
	strcpy(this->cfindTextFinishedEvent,"");
	strcpy(this->cfullScreenRequestedEvent,"");
	strcpy(this->cgeometryChangeRequestedEvent,"");
	strcpy(this->ciconChangedEvent,"");
	strcpy(this->ciconUrlChangedEvent,"");
	strcpy(this->clinkHoveredEvent,"");
	strcpy(this->cloadFinishedEvent,"");
	strcpy(this->cloadProgressEvent,"");
	strcpy(this->cloadStartedEvent,"");
	strcpy(this->cpdfPrintingFinishedEvent,"");
	strcpy(this->cprintRequestedEvent,"");
	strcpy(this->cproxyAuthenticationRequiredEvent,"");
	strcpy(this->cquotaRequestedEvent,"");
	strcpy(this->crecentlyAudibleChangedEvent,"");
	strcpy(this->crecommendedStateChangedEvent,"");
	strcpy(this->cregisterProtocolHandlerRequestedEvent,"");
	strcpy(this->cscrollPositionChangedEvent,"");
	strcpy(this->cselectClientCertificateEvent,"");
	strcpy(this->cselectionChangedEvent,"");
	strcpy(this->ctitleChangedEvent,"");
	strcpy(this->curlChangedEvent,"");
	strcpy(this->cvisibleChangedEvent,"");
	strcpy(this->cwindowCloseRequestedEvent,"");

	QObject::connect(this, SIGNAL(audioMutedChanged(bool)),this, SLOT(audioMutedChangedSlot()));
	QObject::connect(this, SIGNAL(authenticationRequired(const QUrl,QAuthenticator *)),this, SLOT(authenticationRequiredSlot()));
	QObject::connect(this, SIGNAL(contentsSizeChanged(const QSizeF)),this, SLOT(contentsSizeChangedSlot()));
	QObject::connect(this, SIGNAL(featurePermissionRequestCanceled(const QUrl,QWebEnginePage::Feature)),this, SLOT(featurePermissionRequestCanceledSlot()));
	QObject::connect(this, SIGNAL(featurePermissionRequested(const QUrl,QWebEnginePage::Feature)),this, SLOT(featurePermissionRequestedSlot()));
	QObject::connect(this, SIGNAL(findTextFinished(const QWebEngineFindTextResult)),this, SLOT(findTextFinishedSlot()));
	QObject::connect(this, SIGNAL(fullScreenRequested(QWebEngineFullScreenRequest)),this, SLOT(fullScreenRequestedSlot()));
	QObject::connect(this, SIGNAL(geometryChangeRequested(const QRect)),this, SLOT(geometryChangeRequestedSlot()));
	QObject::connect(this, SIGNAL(iconChanged(const QIcon)),this, SLOT(iconChangedSlot()));
	QObject::connect(this, SIGNAL(iconUrlChanged(const QUrl)),this, SLOT(iconUrlChangedSlot()));
	QObject::connect(this, SIGNAL(linkHovered(const QString)),this, SLOT(linkHoveredSlot()));
	QObject::connect(this, SIGNAL(loadFinished(bool)),this, SLOT(loadFinishedSlot()));
	QObject::connect(this, SIGNAL(loadProgress(int)),this, SLOT(loadProgressSlot()));
	QObject::connect(this, SIGNAL(loadStarted()),this, SLOT(loadStartedSlot()));
	QObject::connect(this, SIGNAL(pdfPrintingFinished(const QString,bool)),this, SLOT(pdfPrintingFinishedSlot()));
	QObject::connect(this, SIGNAL(printRequested()),this, SLOT(printRequestedSlot()));
	QObject::connect(this, SIGNAL(proxyAuthenticationRequired(const QUrl,QAuthenticator *,const QString)),this, SLOT(proxyAuthenticationRequiredSlot()));
	QObject::connect(this, SIGNAL(quotaRequested(QWebEngineQuotaRequest)),this, SLOT(quotaRequestedSlot()));
	QObject::connect(this, SIGNAL(recentlyAudibleChanged(bool)),this, SLOT(recentlyAudibleChangedSlot()));
	QObject::connect(this, SIGNAL(recommendedStateChanged(QWebEnginePage::LifecycleState)),this, SLOT(recommendedStateChangedSlot()));
	QObject::connect(this, SIGNAL(registerProtocolHandlerRequested(QWebEngineRegisterProtocolHandlerRequest)),this, SLOT(registerProtocolHandlerRequestedSlot()));
	QObject::connect(this, SIGNAL(scrollPositionChanged(const QPointF)),this, SLOT(scrollPositionChangedSlot()));
	QObject::connect(this, SIGNAL(selectClientCertificate(QWebEngineClientCertificateSelection)),this, SLOT(selectClientCertificateSlot()));
	QObject::connect(this, SIGNAL(selectionChanged()),this, SLOT(selectionChangedSlot()));
	QObject::connect(this, SIGNAL(titleChanged(const QString)),this, SLOT(titleChangedSlot()));
	QObject::connect(this, SIGNAL(urlChanged(const QUrl)),this, SLOT(urlChangedSlot()));
	QObject::connect(this, SIGNAL(visibleChanged(bool)),this, SLOT(visibleChangedSlot()));
	QObject::connect(this, SIGNAL(windowCloseRequested()),this, SLOT(windowCloseRequestedSlot()));

}

GWebEnginePage::~GWebEnginePage()
{
	ring_list_delete(this->pParaList);
}

void GWebEnginePage::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


 
void GWebEnginePage::setaudioMutedChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->caudioMutedChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setauthenticationRequiredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cauthenticationRequiredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setcontentsSizeChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ccontentsSizeChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setfeaturePermissionRequestCanceledEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfeaturePermissionRequestCanceledEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setfeaturePermissionRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfeaturePermissionRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setfindTextFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfindTextFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setfullScreenRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cfullScreenRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setgeometryChangeRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cgeometryChangeRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::seticonChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ciconChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::seticonUrlChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ciconUrlChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setlinkHoveredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->clinkHoveredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setloadFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloadFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setloadProgressEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloadProgressEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setloadStartedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cloadStartedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setpdfPrintingFinishedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cpdfPrintingFinishedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setprintRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cprintRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setproxyAuthenticationRequiredEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cproxyAuthenticationRequiredEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setquotaRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cquotaRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setrecentlyAudibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crecentlyAudibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setrecommendedStateChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->crecommendedStateChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setregisterProtocolHandlerRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cregisterProtocolHandlerRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setscrollPositionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cscrollPositionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setselectClientCertificateEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cselectClientCertificateEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setselectionChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cselectionChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::settitleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->ctitleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::seturlChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->curlChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setvisibleChangedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cvisibleChangedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

void GWebEnginePage::setwindowCloseRequestedEvent(const char *cStr)
{
	if ( strlen(cStr) < RINGQT_EVENT_SIZE )
		strcpy(this->cwindowCloseRequestedEvent,cStr);
	else {
		printf("\nEvent Code: %s\n",cStr);
		ring_vm_error(this->pVM,RINGQT_EVENT_SIZE_ERROR);
	}
}

 
const char *GWebEnginePage::getaudioMutedChangedEvent(void)
{
	return this->caudioMutedChangedEvent;
}

const char *GWebEnginePage::getauthenticationRequiredEvent(void)
{
	return this->cauthenticationRequiredEvent;
}

const char *GWebEnginePage::getcontentsSizeChangedEvent(void)
{
	return this->ccontentsSizeChangedEvent;
}

const char *GWebEnginePage::getfeaturePermissionRequestCanceledEvent(void)
{
	return this->cfeaturePermissionRequestCanceledEvent;
}

const char *GWebEnginePage::getfeaturePermissionRequestedEvent(void)
{
	return this->cfeaturePermissionRequestedEvent;
}

const char *GWebEnginePage::getfindTextFinishedEvent(void)
{
	return this->cfindTextFinishedEvent;
}

const char *GWebEnginePage::getfullScreenRequestedEvent(void)
{
	return this->cfullScreenRequestedEvent;
}

const char *GWebEnginePage::getgeometryChangeRequestedEvent(void)
{
	return this->cgeometryChangeRequestedEvent;
}

const char *GWebEnginePage::geticonChangedEvent(void)
{
	return this->ciconChangedEvent;
}

const char *GWebEnginePage::geticonUrlChangedEvent(void)
{
	return this->ciconUrlChangedEvent;
}

const char *GWebEnginePage::getlinkHoveredEvent(void)
{
	return this->clinkHoveredEvent;
}

const char *GWebEnginePage::getloadFinishedEvent(void)
{
	return this->cloadFinishedEvent;
}

const char *GWebEnginePage::getloadProgressEvent(void)
{
	return this->cloadProgressEvent;
}

const char *GWebEnginePage::getloadStartedEvent(void)
{
	return this->cloadStartedEvent;
}

const char *GWebEnginePage::getpdfPrintingFinishedEvent(void)
{
	return this->cpdfPrintingFinishedEvent;
}

const char *GWebEnginePage::getprintRequestedEvent(void)
{
	return this->cprintRequestedEvent;
}

const char *GWebEnginePage::getproxyAuthenticationRequiredEvent(void)
{
	return this->cproxyAuthenticationRequiredEvent;
}

const char *GWebEnginePage::getquotaRequestedEvent(void)
{
	return this->cquotaRequestedEvent;
}

const char *GWebEnginePage::getrecentlyAudibleChangedEvent(void)
{
	return this->crecentlyAudibleChangedEvent;
}

const char *GWebEnginePage::getrecommendedStateChangedEvent(void)
{
	return this->crecommendedStateChangedEvent;
}

const char *GWebEnginePage::getregisterProtocolHandlerRequestedEvent(void)
{
	return this->cregisterProtocolHandlerRequestedEvent;
}

const char *GWebEnginePage::getscrollPositionChangedEvent(void)
{
	return this->cscrollPositionChangedEvent;
}

const char *GWebEnginePage::getselectClientCertificateEvent(void)
{
	return this->cselectClientCertificateEvent;
}

const char *GWebEnginePage::getselectionChangedEvent(void)
{
	return this->cselectionChangedEvent;
}

const char *GWebEnginePage::gettitleChangedEvent(void)
{
	return this->ctitleChangedEvent;
}

const char *GWebEnginePage::geturlChangedEvent(void)
{
	return this->curlChangedEvent;
}

const char *GWebEnginePage::getvisibleChangedEvent(void)
{
	return this->cvisibleChangedEvent;
}

const char *GWebEnginePage::getwindowCloseRequestedEvent(void)
{
	return this->cwindowCloseRequestedEvent;
}


void GWebEnginePage::audioMutedChangedSlot()
{
	if (strcmp(this->caudioMutedChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->caudioMutedChangedEvent);
}

void GWebEnginePage::authenticationRequiredSlot()
{
	if (strcmp(this->cauthenticationRequiredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cauthenticationRequiredEvent);
}

void GWebEnginePage::contentsSizeChangedSlot()
{
	if (strcmp(this->ccontentsSizeChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ccontentsSizeChangedEvent);
}

void GWebEnginePage::featurePermissionRequestCanceledSlot()
{
	if (strcmp(this->cfeaturePermissionRequestCanceledEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfeaturePermissionRequestCanceledEvent);
}

void GWebEnginePage::featurePermissionRequestedSlot()
{
	if (strcmp(this->cfeaturePermissionRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfeaturePermissionRequestedEvent);
}

void GWebEnginePage::findTextFinishedSlot()
{
	if (strcmp(this->cfindTextFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfindTextFinishedEvent);
}

void GWebEnginePage::fullScreenRequestedSlot()
{
	if (strcmp(this->cfullScreenRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cfullScreenRequestedEvent);
}

void GWebEnginePage::geometryChangeRequestedSlot()
{
	if (strcmp(this->cgeometryChangeRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cgeometryChangeRequestedEvent);
}

void GWebEnginePage::iconChangedSlot()
{
	if (strcmp(this->ciconChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ciconChangedEvent);
}

void GWebEnginePage::iconUrlChangedSlot()
{
	if (strcmp(this->ciconUrlChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ciconUrlChangedEvent);
}

void GWebEnginePage::linkHoveredSlot()
{
	if (strcmp(this->clinkHoveredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->clinkHoveredEvent);
}

void GWebEnginePage::loadFinishedSlot()
{
	if (strcmp(this->cloadFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadFinishedEvent);
}

void GWebEnginePage::loadProgressSlot()
{
	if (strcmp(this->cloadProgressEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadProgressEvent);
}

void GWebEnginePage::loadStartedSlot()
{
	if (strcmp(this->cloadStartedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cloadStartedEvent);
}

void GWebEnginePage::pdfPrintingFinishedSlot()
{
	if (strcmp(this->cpdfPrintingFinishedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cpdfPrintingFinishedEvent);
}

void GWebEnginePage::printRequestedSlot()
{
	if (strcmp(this->cprintRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cprintRequestedEvent);
}

void GWebEnginePage::proxyAuthenticationRequiredSlot()
{
	if (strcmp(this->cproxyAuthenticationRequiredEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cproxyAuthenticationRequiredEvent);
}

void GWebEnginePage::quotaRequestedSlot()
{
	if (strcmp(this->cquotaRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cquotaRequestedEvent);
}

void GWebEnginePage::recentlyAudibleChangedSlot()
{
	if (strcmp(this->crecentlyAudibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crecentlyAudibleChangedEvent);
}

void GWebEnginePage::recommendedStateChangedSlot()
{
	if (strcmp(this->crecommendedStateChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->crecommendedStateChangedEvent);
}

void GWebEnginePage::registerProtocolHandlerRequestedSlot()
{
	if (strcmp(this->cregisterProtocolHandlerRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cregisterProtocolHandlerRequestedEvent);
}

void GWebEnginePage::scrollPositionChangedSlot()
{
	if (strcmp(this->cscrollPositionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cscrollPositionChangedEvent);
}

void GWebEnginePage::selectClientCertificateSlot()
{
	if (strcmp(this->cselectClientCertificateEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectClientCertificateEvent);
}

void GWebEnginePage::selectionChangedSlot()
{
	if (strcmp(this->cselectionChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cselectionChangedEvent);
}

void GWebEnginePage::titleChangedSlot()
{
	if (strcmp(this->ctitleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->ctitleChangedEvent);
}

void GWebEnginePage::urlChangedSlot()
{
	if (strcmp(this->curlChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->curlChangedEvent);
}

void GWebEnginePage::visibleChangedSlot()
{
	if (strcmp(this->cvisibleChangedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cvisibleChangedEvent);
}

void GWebEnginePage::windowCloseRequestedSlot()
{
	if (strcmp(this->cwindowCloseRequestedEvent,"")==0)
		return ;

	ring_vm_runcode(this->pVM,this->cwindowCloseRequestedEvent);
}


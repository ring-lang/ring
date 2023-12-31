/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */

extern "C" {
	#include "ring.h"
}

#include "gtimer.h"
#include "giodevice.h"
#include "gprocess.h"
#include "gthread.h"
#include <QtCore>
























extern "C" {

	RING_API void ring_qt_start(RingState *pRingState);

	RING_LIBINIT
	{
		new QCoreApplication(pRingState->argc,pRingState->argv);
	   	ring_qt_start(pRingState) ;
	}

}

// Functions Prototype - Functions used to Free Memory 

	void ring_QObject_freefunc(void *pState,void *pPointer);
	void ring_QSize_freefunc(void *pState,void *pPointer);
	void ring_QDir_freefunc(void *pState,void *pPointer);
	void ring_QUrl_freefunc(void *pState,void *pPointer);
	void ring_QEvent_freefunc(void *pState,void *pPointer);
	void ring_QTimer_freefunc(void *pState,void *pPointer);
	void ring_QByteArray_freefunc(void *pState,void *pPointer);
	void ring_QIODevice_freefunc(void *pState,void *pPointer);
	void ring_QFileInfo_freefunc(void *pState,void *pPointer);
	void ring_QStringList_freefunc(void *pState,void *pPointer);
	void ring_QRect_freefunc(void *pState,void *pPointer);
	void ring_QTime_freefunc(void *pState,void *pPointer);
	void ring_QDate_freefunc(void *pState,void *pPointer);
	void ring_QTextCodec_freefunc(void *pState,void *pPointer);
	void ring_QVariant_freefunc(void *pState,void *pPointer);
	void ring_QVariant2_freefunc(void *pState,void *pPointer);
	void ring_QVariant3_freefunc(void *pState,void *pPointer);
	void ring_QVariant4_freefunc(void *pState,void *pPointer);
	void ring_QVariant5_freefunc(void *pState,void *pPointer);
	void ring_QVariantInt_freefunc(void *pState,void *pPointer);
	void ring_QVariantFloat_freefunc(void *pState,void *pPointer);
	void ring_QVariantDouble_freefunc(void *pState,void *pPointer);
	void ring_QVariantString_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamReader_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamWriter_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamNotationDeclaration_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamNamespaceDeclaration_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamEntityDeclaration_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamEntityResolver_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamAttributes_freefunc(void *pState,void *pPointer);
	void ring_QXmlStreamAttribute_freefunc(void *pState,void *pPointer);
	void ring_QRegularExpression_freefunc(void *pState,void *pPointer);
	void ring_QRegularExpressionMatch_freefunc(void *pState,void *pPointer);
	void ring_QRegularExpressionMatchIterator_freefunc(void *pState,void *pPointer);
	void ring_QJsonArray_freefunc(void *pState,void *pPointer);
	void ring_QJsonDocument_freefunc(void *pState,void *pPointer);
	void ring_QJsonObject_freefunc(void *pState,void *pPointer);
	void ring_QJsonParseError_freefunc(void *pState,void *pPointer);
	void ring_QJsonValue_freefunc(void *pState,void *pPointer);
	void ring_QPointF_freefunc(void *pState,void *pPointer);
	void ring_QPoint_freefunc(void *pState,void *pPointer);
	void ring_QString2_freefunc(void *pState,void *pPointer);
	void ring_QStringRef_freefunc(void *pState,void *pPointer);
	void ring_QBuffer_freefunc(void *pState,void *pPointer);
	void ring_QDateTime_freefunc(void *pState,void *pPointer);
	void ring_QCoreApplication_freefunc(void *pState,void *pPointer);
	void ring_QFile_freefunc(void *pState,void *pPointer);
	void ring_QFile2_freefunc(void *pState,void *pPointer);
	void ring_QFileDevice_freefunc(void *pState,void *pPointer);
	void ring_QStandardPaths_freefunc(void *pState,void *pPointer);
	void ring_QMimeData_freefunc(void *pState,void *pPointer);
	void ring_QChar_freefunc(void *pState,void *pPointer);
	void ring_QChildEvent_freefunc(void *pState,void *pPointer);
	void ring_QTextStream_freefunc(void *pState,void *pPointer);
	void ring_QTextStream2_freefunc(void *pState,void *pPointer);
	void ring_QTextStream3_freefunc(void *pState,void *pPointer);
	void ring_QTextStream4_freefunc(void *pState,void *pPointer);
	void ring_QTextStream5_freefunc(void *pState,void *pPointer);
	void ring_QLocale_freefunc(void *pState,void *pPointer);
	void ring_QThread_freefunc(void *pState,void *pPointer);
	void ring_QThreadPool_freefunc(void *pState,void *pPointer);
	void ring_QProcess_freefunc(void *pState,void *pPointer);
	void ring_QUuid_freefunc(void *pState,void *pPointer);
	void ring_QMutex_freefunc(void *pState,void *pPointer);
	void ring_QMutexLocker_freefunc(void *pState,void *pPointer);

// End of Functions Prototype - Functions used to Free Memory 


RING_FUNC(ring_QObject_blockSignals)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->blockSignals( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QObject_children)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	{
		QObjectList *pValue ; 
		pValue = (QObjectList *) RING_API_MALLOC(sizeof(QObjectList)) ;
		*pValue = pObject->children();
		RING_API_RETMANAGEDCPOINTER(pValue,"QObjectList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QObject_dumpObjectInfo)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->dumpObjectInfo();
}


RING_FUNC(ring_QObject_dumpObjectTree)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->dumpObjectTree();
}


RING_FUNC(ring_QObject_inherits)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->inherits(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QObject_installEventFilter)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->installEventFilter((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_isWidgetType)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETNUMBER(pObject->isWidgetType());
}


RING_FUNC(ring_QObject_killTimer)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->killTimer( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QObject_moveToThread)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveToThread((QThread *) RING_API_GETCPOINTER(2,"QThread"));
}


RING_FUNC(ring_QObject_objectName)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETSTRING(pObject->objectName().toStdString().c_str());
}


RING_FUNC(ring_QObject_parent)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETCPOINTER(pObject->parent(),"QObject");
}


RING_FUNC(ring_QObject_property)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->property(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QObject_removeEventFilter)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeEventFilter((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_setObjectName)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setObjectName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QObject_setParent)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setParent((QObject *) RING_API_GETCPOINTER(2,"QObject"));
}


RING_FUNC(ring_QObject_setProperty)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),* (QVariant *) RING_API_GETCPOINTER(3,"QVariant")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QVariant"));
}


RING_FUNC(ring_QObject_setProperty_2)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_3)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (float) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_4)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (double) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_5)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QObject_setProperty_int)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_float)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (float) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_double)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2), (double) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QObject_setProperty_string)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setProperty(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QObject_signalsBlocked)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETNUMBER(pObject->signalsBlocked());
}


RING_FUNC(ring_QObject_startTimer)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startTimer( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QObject_thread)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	RING_API_RETCPOINTER(pObject->thread(),"QThread");
}


RING_FUNC(ring_QObject_deleteLater)
{
	QObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
	pObject->deleteLater();
}


RING_FUNC(ring_QDir_absoluteFilePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->absoluteFilePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_absolutePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->absolutePath().toStdString().c_str());
}


RING_FUNC(ring_QDir_canonicalPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->canonicalPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_cd)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->cd(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_cdUp)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->cdUp());
}


RING_FUNC(ring_QDir_count)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QDir_dirName)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->dirName().toStdString().c_str());
}


RING_FUNC(ring_QDir_entryInfoList)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->entryInfoList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"), (QDir::Filters )  (int) RING_API_GETNUMBER(3), (QDir::SortFlags )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_entryInfoList_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->entryInfoList( (QDir::Filters )  (int) RING_API_GETNUMBER(2), (QDir::SortFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_entryList)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->entryList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"), (QDir::Filters )  (int) RING_API_GETNUMBER(3), (QDir::SortFlags )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_entryList_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->entryList( (QDir::Filters )  (int) RING_API_GETNUMBER(2), (QDir::SortFlags )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_exists)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->exists(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_exists_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QDir_filePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->filePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_filter)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->filter());
}


RING_FUNC(ring_QDir_isAbsolute)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isAbsolute());
}


RING_FUNC(ring_QDir_isReadable)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QDir_isRelative)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QDir_isRoot)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->isRoot());
}


RING_FUNC(ring_QDir_makeAbsolute)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->makeAbsolute());
}


RING_FUNC(ring_QDir_mkdir)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mkdir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_mkpath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mkpath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_nameFilters)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->nameFilters();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_path)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->path().toStdString().c_str());
}


RING_FUNC(ring_QDir_refresh)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->refresh();
}


RING_FUNC(ring_QDir_relativeFilePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->relativeFilePath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_remove)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_removeRecursively)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->removeRecursively());
}


RING_FUNC(ring_QDir_rename)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QDir_rmdir)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rmdir(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_rmpath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rmpath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_setFilter)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFilter( (QDir::Filters )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDir_setNameFilters)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->setNameFilters(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QDir_setPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QDir_setSorting)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSorting( (QDir::SortFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDir_sorting)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETNUMBER(pObject->sorting());
}


RING_FUNC(ring_QDir_swap)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	pObject->swap(* (QDir  *) RING_API_GETCPOINTER(2,"QDir"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDir"));
}


RING_FUNC(ring_QDir_addSearchPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addSearchPath(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QDir_cleanPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->cleanPath(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_current)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->current();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_currentPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->currentPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_drives)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QFileInfoList *pValue ; 
		pValue = (QFileInfoList *) RING_API_MALLOC(sizeof(QFileInfoList)) ;
		*pValue = pObject->drives();
		RING_API_RETMANAGEDCPOINTER(pValue,"QFileInfoList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QDir_fromNativeSeparators)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fromNativeSeparators(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDir_home)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->home();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_homePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->homePath().toStdString().c_str());
}


RING_FUNC(ring_QDir_isAbsolutePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isAbsolutePath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_isRelativePath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isRelativePath(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_match)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->match(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QDir_match_2)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->match(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"),RING_API_GETSTRING(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QDir_root)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->root();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_rootPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->rootPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_searchPaths)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->searchPaths(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QDir_separator)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->separator();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QDir_setCurrent)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setCurrent(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QDir_setSearchPaths)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSearchPaths(RING_API_GETSTRING(2),* (QStringList  *) RING_API_GETCPOINTER(3,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QDir_temp)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->temp();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QDir_tempPath)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	RING_API_RETSTRING(pObject->tempPath().toStdString().c_str());
}


RING_FUNC(ring_QDir_toNativeSeparators)
{
	QDir *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toNativeSeparators(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_authority)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->authority( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_clear)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	pObject->clear();
}


RING_FUNC(ring_QUrl_errorString)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QUrl_fileName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fileName( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_fragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fragment( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_hasFragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->hasFragment());
}


RING_FUNC(ring_QUrl_hasQuery)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->hasQuery());
}


RING_FUNC(ring_QUrl_host)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->host( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_isEmpty)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QUrl_isLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isLocalFile());
}


RING_FUNC(ring_QUrl_isParentOf)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isParentOf(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QUrl_isRelative)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QUrl_isValid)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QUrl_password)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->password( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_path)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->path( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_port)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->port( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QUrl_query)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->query( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_resolved)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->resolved(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QUrl_scheme)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->scheme().toStdString().c_str());
}


RING_FUNC(ring_QUrl_setAuthority)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAuthority(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setFragment)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFragment(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setHost)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHost(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPassword)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPassword(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPath)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPath(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setPort)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPort( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QUrl_setQuery)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setQuery(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setScheme)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setScheme(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QUrl_setUrl)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUrl(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setUserInfo)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUserInfo(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_setUserName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setUserName(RING_API_GETSTRING(2), (QUrl::ParsingMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QUrl_swap)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	pObject->swap(* (QUrl *) RING_API_GETCPOINTER(2,"QUrl"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QUrl"));
}


RING_FUNC(ring_QUrl_toLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	RING_API_RETSTRING(pObject->toLocalFile().toStdString().c_str());
}


RING_FUNC(ring_QUrl_userInfo)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->userInfo( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_userName)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->userName( (QUrl::ComponentFormattingOption )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QUrl_fromLocalFile)
{
	QUrl *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->fromLocalFile(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QEvent_accept)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	pObject->accept();
}


RING_FUNC(ring_QEvent_ignore)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	pObject->ignore();
}


RING_FUNC(ring_QEvent_isAccepted)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->isAccepted());
}


RING_FUNC(ring_QEvent_setAccepted)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAccepted( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QEvent_spontaneous)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->spontaneous());
}


RING_FUNC(ring_QEvent_type)
{
	QEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QTimer_interval)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->interval());
}


RING_FUNC(ring_QTimer_isActive)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->isActive());
}


RING_FUNC(ring_QTimer_isSingleShot)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->isSingleShot());
}


RING_FUNC(ring_QTimer_setInterval)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setInterval( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTimer_setSingleShot)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setSingleShot( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTimer_timerId)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETNUMBER(pObject->timerId());
}


RING_FUNC(ring_QTimer_start)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	pObject->start();
}


RING_FUNC(ring_QTimer_stop)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	pObject->stop();
}


RING_FUNC(ring_QTimer_settimeoutEvent)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->settimeoutEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTimer_gettimeoutEvent)
{
	GTimer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GTimer *) RING_API_GETCPOINTER(1,"QTimer");
	RING_API_RETSTRING(pObject->gettimeoutEvent());
}


RING_FUNC(ring_QByteArray_append)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->append(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_append_2)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->append(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_at)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->at( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QByteArray_capacity)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->capacity());
}


RING_FUNC(ring_QByteArray_chop)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->chop( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_clear)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->clear();
}


RING_FUNC(ring_QByteArray_constData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETSTRING(pObject->constData());
}


RING_FUNC(ring_QByteArray_contains)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_count)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->count(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_data)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETSTRING(pObject->data());
}


RING_FUNC(ring_QByteArray_endsWith)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_fill)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fill( (char ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_indexOf)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_insert)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->insert( (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_isEmpty)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QByteArray_isNull)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QByteArray_lastIndexOf)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_left)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->left( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_leftJustified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->leftJustified( (int ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_length)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QByteArray_mid)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->mid( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_prepend)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->prepend(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_push_back)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_back(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QByteArray_push_front)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_front(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QByteArray_remove)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->remove( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_repeated)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->repeated( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_2)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (QByteArray  *) RING_API_GETCPOINTER(4,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_3)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_4)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_5)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_6)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_7)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_8)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(* (const QByteArray  *) RING_API_GETCPOINTER(2,"const QByteArray"),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_9)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(* (const QByteArray  *) RING_API_GETCPOINTER(2,"const QByteArray"),RING_API_GETSTRING(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_10)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace(RING_API_GETSTRING(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_replace_11)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->replace( (char ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_reserve)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->reserve( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_resize)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->resize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_right)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->right( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_rightJustified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->rightJustified( (int ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_setNum)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->setNum( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_setRawData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->setRawData(RING_API_GETSTRING(2), (uint ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_simplified)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->simplified();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_size)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QByteArray_squeeze)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->squeeze();
}


RING_FUNC(ring_QByteArray_startsWith)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QByteArray_swap)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	pObject->swap(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QByteArray_toBase64)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toBase64();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toDouble)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QByteArray_toFloat)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QByteArray_toHex)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toHex();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toInt)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		long *pValue ; 
		pValue = (long *) RING_API_MALLOC(sizeof(long)) ;
		*pValue = pObject->toLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toLongLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toLower)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLower();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toPercentEncoding)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toPercentEncoding(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"),* (QByteArray *) RING_API_GETCPOINTER(3,"QByteArray"), (char ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_toShort)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		short *pValue ; 
		pValue = (short *) RING_API_MALLOC(sizeof(short)) ;
		*pValue = pObject->toShort((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"short",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QByteArray_toUInt)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toULong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toULong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toULongLong)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toULongLong((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toUShort)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUShort((bool *) RING_API_GETCPOINTER(2,"bool"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QByteArray_toUpper)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toUpper();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_trimmed)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->trimmed();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_truncate)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->truncate( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QByteArray_fromBase64)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromBase64(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromHex)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromHex(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromPercentEncoding)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromPercentEncoding(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"), (char ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_fromRawData)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->fromRawData(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QByteArray_number)
{
	QByteArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->number( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QIODevice_errorString)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QIODevice_getChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->getChar(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QIODevice_isOpen)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isOpen());
}


RING_FUNC(ring_QIODevice_isReadable)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QIODevice_isTextModeEnabled)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isTextModeEnabled());
}


RING_FUNC(ring_QIODevice_isWritable)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->isWritable());
}


RING_FUNC(ring_QIODevice_openMode)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->openMode());
}


RING_FUNC(ring_QIODevice_peek)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->peek(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_putChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->putChar( (char ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_read)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->read(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_readAll)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAll();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QIODevice_readLine)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->readLine(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_setTextModeEnabled)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTextModeEnabled( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QIODevice_ungetChar)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->ungetChar( (char ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QIODevice_write)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->write(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QIODevice_atEnd)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->atEnd());
}


RING_FUNC(ring_QIODevice_canReadLine)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->canReadLine());
}


RING_FUNC(ring_QIODevice_close)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	pObject->close();
}


RING_FUNC(ring_QIODevice_open)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_pos)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->pos());
}


RING_FUNC(ring_QIODevice_seek)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->seek( (qint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QIODevice_size)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QIODevice_setaboutToCloseEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setaboutToCloseEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setbytesWrittenEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setbytesWrittenEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setreadChannelFinishedEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadChannelFinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_setreadyReadEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QIODevice_getaboutToCloseEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getaboutToCloseEvent());
}


RING_FUNC(ring_QIODevice_getbytesWrittenEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getbytesWrittenEvent());
}


RING_FUNC(ring_QIODevice_getreadChannelFinishedEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getreadChannelFinishedEvent());
}


RING_FUNC(ring_QIODevice_getreadyReadEvent)
{
	GIODevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GIODevice *) RING_API_GETCPOINTER(1,"QIODevice");
	RING_API_RETSTRING(pObject->getreadyReadEvent());
}


RING_FUNC(ring_QFileInfo_absoluteDir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->absoluteDir();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_absoluteFilePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->absoluteFilePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_absolutePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->absolutePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_baseName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->baseName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_bundleName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->bundleName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_caching)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->caching());
}


RING_FUNC(ring_QFileInfo_canonicalFilePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->canonicalFilePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_canonicalPath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->canonicalPath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_completeBaseName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->completeBaseName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_completeSuffix)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->completeSuffix().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_dir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDir *pValue ; 
		pValue = new QDir() ;
		*pValue = pObject->dir();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDir",ring_QDir_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_exists)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QFileInfo_fileName)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->fileName().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_filePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->filePath().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_group)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->group().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_groupId)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->groupId());
}


RING_FUNC(ring_QFileInfo_isAbsolute)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isAbsolute());
}


RING_FUNC(ring_QFileInfo_isBundle)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isBundle());
}


RING_FUNC(ring_QFileInfo_isDir)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isDir());
}


RING_FUNC(ring_QFileInfo_isExecutable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isExecutable());
}


RING_FUNC(ring_QFileInfo_isFile)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isFile());
}


RING_FUNC(ring_QFileInfo_isHidden)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isHidden());
}


RING_FUNC(ring_QFileInfo_isNativePath)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isNativePath());
}


RING_FUNC(ring_QFileInfo_isReadable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isReadable());
}


RING_FUNC(ring_QFileInfo_isRelative)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isRelative());
}


RING_FUNC(ring_QFileInfo_isRoot)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isRoot());
}


RING_FUNC(ring_QFileInfo_isSymLink)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isSymLink());
}


RING_FUNC(ring_QFileInfo_isWritable)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->isWritable());
}


RING_FUNC(ring_QFileInfo_lastModified)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->lastModified();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_lastRead)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->lastRead();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QFileInfo_makeAbsolute)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->makeAbsolute());
}


RING_FUNC(ring_QFileInfo_owner)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->owner().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_ownerId)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->ownerId());
}


RING_FUNC(ring_QFileInfo_path)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->path().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_permission)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->permission( (QFileDevice::Permission )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileInfo_permissions)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->permissions());
}


RING_FUNC(ring_QFileInfo_refresh)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	pObject->refresh();
}


RING_FUNC(ring_QFileInfo_setCaching)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCaching( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QFileInfo_setFile)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFile(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFileInfo_size)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QFileInfo_suffix)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->suffix().toStdString().c_str());
}


RING_FUNC(ring_QFileInfo_swap)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	pObject->swap(* (QFileInfo *) RING_API_GETCPOINTER(2,"QFileInfo"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QFileInfo"));
}


RING_FUNC(ring_QFileInfo_symLinkTarget)
{
	QFileInfo *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
	RING_API_RETSTRING(pObject->symLinkTarget().toStdString().c_str());
}


RING_FUNC(ring_QStringList_join)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->join(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_sort)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->sort();
}


RING_FUNC(ring_QStringList_removeDuplicates)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->removeDuplicates());
}


RING_FUNC(ring_QStringList_filter)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->filter(RING_API_GETSTRING(2), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStringList_replaceInStrings)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->replaceInStrings(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStringList_append)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->append(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_at)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->at( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->back().toStdString().c_str());
}


RING_FUNC(ring_QStringList_clear)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->clear();
}


RING_FUNC(ring_QStringList_contains)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_count)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QStringList_empty)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QStringList_endsWith)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_first)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->first().toStdString().c_str());
}


RING_FUNC(ring_QStringList_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->front().toStdString().c_str());
}


RING_FUNC(ring_QStringList_indexOf)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringList_insert)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insert( (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QStringList_isEmpty)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QStringList_last)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->last().toStdString().c_str());
}


RING_FUNC(ring_QStringList_lastIndexOf)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringList_length)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QStringList_move)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->move( (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QStringList_pop_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->pop_back();
}


RING_FUNC(ring_QStringList_pop_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->pop_front();
}


RING_FUNC(ring_QStringList_prepend)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->prepend(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_push_back)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_back(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_push_front)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->push_front(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QStringList_removeAll)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeAll(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_removeAt)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeAt( (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QStringList_removeFirst)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->removeFirst();
}


RING_FUNC(ring_QStringList_removeLast)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	pObject->removeLast();
}


RING_FUNC(ring_QStringList_removeOne)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeOne(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_replace)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->replace( (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QStringList_reserve)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->reserve( (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QStringList_size)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QStringList_startsWith)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringList_takeAt)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->takeAt( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QStringList_takeFirst)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->takeFirst().toStdString().c_str());
}


RING_FUNC(ring_QStringList_takeLast)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	RING_API_RETSTRING(pObject->takeLast().toStdString().c_str());
}


RING_FUNC(ring_QStringList_value)
{
	QStringList *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->value( (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QRect_adjust)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->adjust( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_QRect_adjusted)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->adjusted( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QRect_bottom)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->bottom());
}


RING_FUNC(ring_QRect_bottomLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->bottomLeft();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QRect_bottomRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->bottomRight();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QRect_center)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->center();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QRect_contains)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QRect_getCoords)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->getCoords(RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_QRect_getRect)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->getRect(RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_QRect_height)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->height());
}


RING_FUNC(ring_QRect_intersected)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->intersected(* (QRect *) RING_API_GETCPOINTER(2,"QRect"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QRect_intersects)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->intersects(* (QRect *) RING_API_GETCPOINTER(2,"QRect")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
}


RING_FUNC(ring_QRect_isEmpty)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QRect_isNull)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QRect_isValid)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QRect_left)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->left());
}


RING_FUNC(ring_QRect_moveBottom)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveBottom( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_moveBottomLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->moveBottomLeft(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_moveBottomRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->moveBottomRight(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_moveCenter)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->moveCenter(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_moveLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveLeft( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_moveRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveRight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_moveTo)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveTo( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QRect_moveTop)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->moveTop( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_moveTopLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->moveTopLeft(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_moveTopRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->moveTopRight(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_normalized)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->normalized();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QRect_right)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->right());
}


RING_FUNC(ring_QRect_setBottom)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setBottom( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setBottomLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->setBottomLeft(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_setBottomRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->setBottomRight(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_setCoords)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCoords( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_QRect_setHeight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHeight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setLeft( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setRect)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setRect( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_QRect_setRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setRight( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setSize)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->setSize(* (QSize *) RING_API_GETCPOINTER(2,"QSize"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QSize"));
}


RING_FUNC(ring_QRect_setTop)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTop( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setTopLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->setTopLeft(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_setTopRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	pObject->setTopRight(* (QPoint *) RING_API_GETCPOINTER(2,"QPoint"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QPoint"));
}


RING_FUNC(ring_QRect_setWidth)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWidth( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setX)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setX( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_setY)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setY( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRect_size)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->size();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QRect_top)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->top());
}


RING_FUNC(ring_QRect_topLeft)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->topLeft();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QRect_topRight)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->topRight();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QRect_translate)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->translate( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QRect_translated)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->translated( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QRect_united)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->united(* (QRect *) RING_API_GETCPOINTER(2,"QRect"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRect"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QRect_width)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->width());
}


RING_FUNC(ring_QRect_x)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->x());
}


RING_FUNC(ring_QRect_y)
{
	QRect *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
	RING_API_RETNUMBER(pObject->y());
}


RING_FUNC(ring_QTime_addMSecs)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->addMSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_addSecs)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->addSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_hour)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->hour());
}


RING_FUNC(ring_QTime_isNull)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QTime_isValid)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QTime_minute)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->minute());
}


RING_FUNC(ring_QTime_msec)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msec());
}


RING_FUNC(ring_QTime_msecsSinceStartOfDay)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msecsSinceStartOfDay());
}


RING_FUNC(ring_QTime_msecsTo)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->msecsTo(* (QTime *) RING_API_GETCPOINTER(2,"QTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QTime_second)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->second());
}


RING_FUNC(ring_QTime_secsTo)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	RING_API_RETNUMBER(pObject->secsTo(* (QTime *) RING_API_GETCPOINTER(2,"QTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QTime_setHMS)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setHMS( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_QTime_toString)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QTime_currentTime)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->currentTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_fromMSecsSinceStartOfDay)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->fromMSecsSinceStartOfDay( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QTime_fromString)
{
	QTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QDate_addDays)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addDays( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_addMonths)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addMonths( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_addYears)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->addYears( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_day)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->day());
}


RING_FUNC(ring_QDate_dayOfWeek)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->dayOfWeek());
}


RING_FUNC(ring_QDate_dayOfYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->dayOfYear());
}


RING_FUNC(ring_QDate_daysInMonth)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysInMonth());
}


RING_FUNC(ring_QDate_daysInYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysInYear());
}


RING_FUNC(ring_QDate_daysTo)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->daysTo(* (QDate *) RING_API_GETCPOINTER(2,"QDate")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QDate_getDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->getDate(RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_QDate_isNull)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QDate_isValid)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QDate_month)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->month());
}


RING_FUNC(ring_QDate_setDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setDate( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QDate_toJulianDay)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->toJulianDay());
}


RING_FUNC(ring_QDate_toString)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDate_weekNumber)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->weekNumber(RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_QDate_year)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	RING_API_RETNUMBER(pObject->year());
}


RING_FUNC(ring_QDate_currentDate)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->currentDate();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_fromJulianDay)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->fromJulianDay( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_fromString)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDate_isLeapYear)
{
	QDate *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLeapYear( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QTextCodec_codecForName)
{
	RING_API_RETCPOINTER( QTextCodec::codecForName(RING_API_GETSTRING(1)) , "QTextCodec");
}

RING_FUNC(ring_QTextCodec_setCodecForLocale)
{
	 QTextCodec::setCodecForLocale( (QTextCodec *) RING_API_GETCPOINTER(1,"QTextCodec"));
}


RING_FUNC(ring_QVariant_canConvert)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->canConvert( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVariant_clear)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	pObject->clear();
}


RING_FUNC(ring_QVariant_convert)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->convert( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QVariant_isNull)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QVariant_isValid)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QVariant_swap)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	pObject->swap(* (QVariant *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QVariant_toBitArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QBitArray *pValue ; 
		pValue = (QBitArray *) RING_API_MALLOC(sizeof(QBitArray)) ;
		*pValue = pObject->toBitArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QBitArray",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toBool)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->toBool());
}


RING_FUNC(ring_QVariant_toByteArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toByteArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QVariant_toChar)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toChar();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDate)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->toDate();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDateTime)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toDateTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QVariant_toDouble)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toEasingCurve)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QEasingCurve *pValue ; 
		pValue = (QEasingCurve *) RING_API_MALLOC(sizeof(QEasingCurve)) ;
		*pValue = pObject->toEasingCurve();
		RING_API_RETMANAGEDCPOINTER(pValue,"QEasingCurve",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toFloat)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toInt)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toJsonArray)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toJsonArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonDocument)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->toJsonDocument();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonObject)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toJsonObject();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QVariant_toJsonValue)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->toJsonValue();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QVariant_toLine)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLine *pValue ; 
		pValue = (QLine *) RING_API_MALLOC(sizeof(QLine)) ;
		*pValue = pObject->toLine();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLine",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toLineF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLineF *pValue ; 
		pValue = (QLineF *) RING_API_MALLOC(sizeof(QLineF)) ;
		*pValue = pObject->toLineF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLineF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toLocale)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->toLocale();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QVariant_toLongLong)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong((bool *) RING_API_GETCPOINTER(2,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toModelIndex)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QModelIndex *pValue ; 
		pValue = (QModelIndex *) RING_API_MALLOC(sizeof(QModelIndex)) ;
		*pValue = pObject->toModelIndex();
		RING_API_RETMANAGEDCPOINTER(pValue,"QModelIndex",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toPoint)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->toPoint();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QVariant_toPointF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QPointF *pValue ; 
		pValue = new QPointF() ;
		*pValue = pObject->toPointF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPointF",ring_QPointF_freefunc);
	}
}


RING_FUNC(ring_QVariant_toReal)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toReal((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toRect)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRect *pValue ; 
		pValue = new QRect() ;
		*pValue = pObject->toRect();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRect",ring_QRect_freefunc);
	}
}


RING_FUNC(ring_QVariant_toRectF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRectF *pValue ; 
		pValue = (QRectF *) RING_API_MALLOC(sizeof(QRectF)) ;
		*pValue = pObject->toRectF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRectF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toRegExp)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRegExp *pValue ; 
		pValue = (QRegExp *) RING_API_MALLOC(sizeof(QRegExp)) ;
		*pValue = pObject->toRegExp();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegExp",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toRegularExpression)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QRegularExpression *pValue ; 
		pValue = new QRegularExpression() ;
		*pValue = pObject->toRegularExpression();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpression",ring_QRegularExpression_freefunc);
	}
}


RING_FUNC(ring_QVariant_toSize)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QSize *pValue ; 
		pValue = new QSize() ;
		*pValue = pObject->toSize();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSize",ring_QSize_freefunc);
	}
}


RING_FUNC(ring_QVariant_toSizeF)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QSizeF *pValue ; 
		pValue = (QSizeF *) RING_API_MALLOC(sizeof(QSizeF)) ;
		*pValue = pObject->toSizeF();
		RING_API_RETMANAGEDCPOINTER(pValue,"QSizeF",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toStringList)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->toStringList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QVariant_toTime)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QVariant_toUInt)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt((bool *) RING_API_GETCPOINTER(2,"bool")));
}


RING_FUNC(ring_QVariant_toULongLong)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qulonglong *pValue ; 
		pValue = (qulonglong *) RING_API_MALLOC(sizeof(qulonglong)) ;
		*pValue = pObject->toULongLong((bool *) RING_API_GETCPOINTER(2,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qulonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QVariant_toUrl)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QUrl *pValue ; 
		pValue = new QUrl() ;
		*pValue = pObject->toUrl();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUrl",ring_QUrl_freefunc);
	}
}


RING_FUNC(ring_QVariant_toUuid)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	{
		QUuid *pValue ; 
		pValue = new QUuid() ;
		*pValue = pObject->toUuid();
		RING_API_RETMANAGEDCPOINTER(pValue,"QUuid",ring_QUuid_freefunc);
	}
}


RING_FUNC(ring_QVariant_type)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->type());
}


RING_FUNC(ring_QVariant_typeName)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETSTRING(pObject->typeName());
}


RING_FUNC(ring_QVariant_userType)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETNUMBER(pObject->userType());
}


RING_FUNC(ring_QVariant_toString)
{
	QVariant *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QXmlStreamReader_addData)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	pObject->addData(* (QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QXmlStreamReader_addData_2)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addData(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamReader_addData_3)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addData(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamReader_addExtraNamespaceDeclaration)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	pObject->addExtraNamespaceDeclaration(* (QXmlStreamNamespaceDeclaration *) RING_API_GETCPOINTER(2,"QXmlStreamNamespaceDeclaration"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QXmlStreamNamespaceDeclaration"));
}


RING_FUNC(ring_QXmlStreamReader_addExtraNamespaceDeclarations)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	pObject->addExtraNamespaceDeclarations(* (QXmlStreamNamespaceDeclarations *) RING_API_GETCPOINTER(2,"QXmlStreamNamespaceDeclarations"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QXmlStreamNamespaceDeclarations"));
}


RING_FUNC(ring_QXmlStreamReader_atEnd)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->atEnd());
}


RING_FUNC(ring_QXmlStreamReader_attributes)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QXmlStreamAttributes *pValue ; 
		pValue = new QXmlStreamAttributes() ;
		*pValue = pObject->attributes();
		RING_API_RETMANAGEDCPOINTER(pValue,"QXmlStreamAttributes",ring_QXmlStreamAttributes_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_characterOffset)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->characterOffset());
}


RING_FUNC(ring_QXmlStreamReader_clear)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	pObject->clear();
}


RING_FUNC(ring_QXmlStreamReader_columnNumber)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->columnNumber());
}


RING_FUNC(ring_QXmlStreamReader_device)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETCPOINTER(pObject->device(),"QIODevice");
}


RING_FUNC(ring_QXmlStreamReader_documentEncoding)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->documentEncoding();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_documentVersion)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->documentVersion();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_dtdName)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->dtdName();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_dtdPublicId)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->dtdPublicId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_dtdSystemId)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->dtdSystemId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_entityDeclarations)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QXmlStreamEntityDeclarations *pValue ; 
		pValue = (QXmlStreamEntityDeclarations *) RING_API_MALLOC(sizeof(QXmlStreamEntityDeclarations)) ;
		*pValue = pObject->entityDeclarations();
		RING_API_RETMANAGEDCPOINTER(pValue,"QXmlStreamEntityDeclarations",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QXmlStreamReader_entityResolver)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETCPOINTER(pObject->entityResolver(),"QXmlStreamEntityResolver");
}


RING_FUNC(ring_QXmlStreamReader_error)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QXmlStreamReader_errorString)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QXmlStreamReader_hasError)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->hasError());
}


RING_FUNC(ring_QXmlStreamReader_isCDATA)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isCDATA());
}


RING_FUNC(ring_QXmlStreamReader_isCharacters)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isCharacters());
}


RING_FUNC(ring_QXmlStreamReader_isComment)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isComment());
}


RING_FUNC(ring_QXmlStreamReader_isDTD)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isDTD());
}


RING_FUNC(ring_QXmlStreamReader_isEndDocument)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isEndDocument());
}


RING_FUNC(ring_QXmlStreamReader_isEndElement)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isEndElement());
}


RING_FUNC(ring_QXmlStreamReader_isEntityReference)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isEntityReference());
}


RING_FUNC(ring_QXmlStreamReader_isProcessingInstruction)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isProcessingInstruction());
}


RING_FUNC(ring_QXmlStreamReader_isStandaloneDocument)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isStandaloneDocument());
}


RING_FUNC(ring_QXmlStreamReader_isStartDocument)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isStartDocument());
}


RING_FUNC(ring_QXmlStreamReader_isStartElement)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isStartElement());
}


RING_FUNC(ring_QXmlStreamReader_isWhitespace)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->isWhitespace());
}


RING_FUNC(ring_QXmlStreamReader_lineNumber)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->lineNumber());
}


RING_FUNC(ring_QXmlStreamReader_name)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->name();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_namespaceDeclarations)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QXmlStreamNamespaceDeclarations *pValue ; 
		pValue = (QXmlStreamNamespaceDeclarations *) RING_API_MALLOC(sizeof(QXmlStreamNamespaceDeclarations)) ;
		*pValue = pObject->namespaceDeclarations();
		RING_API_RETMANAGEDCPOINTER(pValue,"QXmlStreamNamespaceDeclarations",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QXmlStreamReader_namespaceProcessing)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->namespaceProcessing());
}


RING_FUNC(ring_QXmlStreamReader_namespaceUri)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->namespaceUri();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_notationDeclarations)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QXmlStreamNotationDeclarations *pValue ; 
		pValue = (QXmlStreamNotationDeclarations *) RING_API_MALLOC(sizeof(QXmlStreamNotationDeclarations)) ;
		*pValue = pObject->notationDeclarations();
		RING_API_RETMANAGEDCPOINTER(pValue,"QXmlStreamNotationDeclarations",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QXmlStreamReader_prefix)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->prefix();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_processingInstructionData)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->processingInstructionData();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_processingInstructionTarget)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->processingInstructionTarget();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_qualifiedName)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->qualifiedName();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_raiseError)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->raiseError(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamReader_readElementText)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->readElementText( (QXmlStreamReader::ReadElementTextBehaviour)  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QXmlStreamReader_readNext)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->readNext());
}


RING_FUNC(ring_QXmlStreamReader_readNextStartElement)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->readNextStartElement());
}


RING_FUNC(ring_QXmlStreamReader_setDevice)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDevice((QIODevice *) RING_API_GETCPOINTER(2,"QIODevice"));
}


RING_FUNC(ring_QXmlStreamReader_setEntityResolver)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEntityResolver((QXmlStreamEntityResolver *) RING_API_GETCPOINTER(2,"QXmlStreamEntityResolver"));
}


RING_FUNC(ring_QXmlStreamReader_setNamespaceProcessing)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNamespaceProcessing( (bool) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QXmlStreamReader_skipCurrentElement)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	pObject->skipCurrentElement();
}


RING_FUNC(ring_QXmlStreamReader_text)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->text();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamReader_tokenString)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETSTRING(pObject->tokenString().toStdString().c_str());
}


RING_FUNC(ring_QXmlStreamReader_tokenType)
{
	QXmlStreamReader *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
	RING_API_RETNUMBER(pObject->tokenType());
}


RING_FUNC(ring_QXmlStreamWriter_autoFormatting)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	RING_API_RETNUMBER(pObject->autoFormatting());
}


RING_FUNC(ring_QXmlStreamWriter_autoFormattingIndent)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	RING_API_RETNUMBER(pObject->autoFormattingIndent());
}


RING_FUNC(ring_QXmlStreamWriter_codec)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	RING_API_RETCPOINTER(pObject->codec(),"QTextCodec");
}


RING_FUNC(ring_QXmlStreamWriter_device)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	RING_API_RETCPOINTER(pObject->device(),"QIODevice");
}


RING_FUNC(ring_QXmlStreamWriter_hasError)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	RING_API_RETNUMBER(pObject->hasError());
}


RING_FUNC(ring_QXmlStreamWriter_setAutoFormatting)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAutoFormatting( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QXmlStreamWriter_setAutoFormattingIndent)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAutoFormattingIndent( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QXmlStreamWriter_setCodec)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCodec((QTextCodec *) RING_API_GETCPOINTER(2,"QTextCodec"));
}


RING_FUNC(ring_QXmlStreamWriter_setCodec_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCodec(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_setDevice)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDevice((QIODevice *) RING_API_GETCPOINTER(2,"QIODevice"));
}


RING_FUNC(ring_QXmlStreamWriter_writeAttribute)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeAttribute(RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_QXmlStreamWriter_writeAttribute_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeAttribute(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeAttribute_3)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeAttribute(* (QXmlStreamAttribute *) RING_API_GETCPOINTER(2,"QXmlStreamAttribute"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QXmlStreamAttribute"));
}


RING_FUNC(ring_QXmlStreamWriter_writeAttributes)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeAttributes(* (QXmlStreamAttributes *) RING_API_GETCPOINTER(2,"QXmlStreamAttributes"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QXmlStreamAttributes"));
}


RING_FUNC(ring_QXmlStreamWriter_writeCDATA)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeCDATA(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeCharacters)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeCharacters(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeComment)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeComment(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeCurrentToken)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeCurrentToken(* (QXmlStreamReader  *) RING_API_GETCPOINTER(2,"QXmlStreamReader"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QXmlStreamReader"));
}


RING_FUNC(ring_QXmlStreamWriter_writeDTD)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeDTD(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeDefaultNamespace)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeDefaultNamespace(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeEmptyElement)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeEmptyElement(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeEmptyElement_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeEmptyElement(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeEndDocument)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeEndDocument();
}


RING_FUNC(ring_QXmlStreamWriter_writeEndElement)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeEndElement();
}


RING_FUNC(ring_QXmlStreamWriter_writeEntityReference)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeEntityReference(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeNamespace)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeNamespace(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeProcessingInstruction)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeProcessingInstruction(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeStartDocument)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeStartDocument(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeStartDocument_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeStartDocument(RING_API_GETSTRING(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeStartDocument_3)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	pObject->writeStartDocument();
}


RING_FUNC(ring_QXmlStreamWriter_writeStartElement)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeStartElement(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamWriter_writeStartElement_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeStartElement(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QXmlStreamWriter_writeTextElement)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeTextElement(RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_QXmlStreamWriter_writeTextElement_2)
{
	QXmlStreamWriter *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->writeTextElement(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamNotationDeclaration_name)
{
	QXmlStreamNotationDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamNotationDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNotationDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->name();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamNotationDeclaration_publicId)
{
	QXmlStreamNotationDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamNotationDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNotationDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->publicId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamNotationDeclaration_systemId)
{
	QXmlStreamNotationDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamNotationDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNotationDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->systemId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamNamespaceDeclaration_namespaceUri)
{
	QXmlStreamNamespaceDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamNamespaceDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNamespaceDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->namespaceUri();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamNamespaceDeclaration_prefix)
{
	QXmlStreamNamespaceDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamNamespaceDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNamespaceDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->prefix();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamEntityDeclaration_name)
{
	QXmlStreamEntityDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->name();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamEntityDeclaration_notationName)
{
	QXmlStreamEntityDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->notationName();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamEntityDeclaration_publicId)
{
	QXmlStreamEntityDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->publicId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamEntityDeclaration_systemId)
{
	QXmlStreamEntityDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->systemId();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamEntityDeclaration_value)
{
	QXmlStreamEntityDeclaration *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttributes_append)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->append(RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_QXmlStreamAttributes_append_2)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->append(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_QXmlStreamAttributes_hasAttribute)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasAttribute(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QXmlStreamAttributes_hasAttribute_2)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	RING_API_RETNUMBER(pObject->hasAttribute(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QXmlStreamAttributes_hasAttribute_3)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasAttribute(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QXmlStreamAttributes_value)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttributes_value_2)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value(RING_API_GETSTRING(2),* (QLatin1String  *) RING_API_GETCPOINTER(3,"QLatin1String"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QLatin1String"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttributes_value_3)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"),* (QLatin1String  *) RING_API_GETCPOINTER(3,"QLatin1String"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QLatin1String"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttributes_value_4)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttributes_value_5)
{
	QXmlStreamAttributes *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttribute_isDefault)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	RING_API_RETNUMBER(pObject->isDefault());
}


RING_FUNC(ring_QXmlStreamAttribute_name)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->name();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttribute_namespaceUri)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->namespaceUri();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttribute_prefix)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->prefix();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttribute_qualifiedName)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->qualifiedName();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QXmlStreamAttribute_value)
{
	QXmlStreamAttribute *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->value();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QRegularExpression_captureCount)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETNUMBER(pObject->captureCount());
}


RING_FUNC(ring_QRegularExpression_errorString)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QRegularExpression_globalMatch)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRegularExpressionMatchIterator *pValue ; 
		pValue = new QRegularExpressionMatchIterator() ;
		*pValue = pObject->globalMatch(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (QRegularExpression::MatchType )  (int) RING_API_GETNUMBER(4), (QRegularExpression::MatchOptions )  (int) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpressionMatchIterator",ring_QRegularExpressionMatchIterator_freefunc);
	}
}


RING_FUNC(ring_QRegularExpression_isValid)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QRegularExpression_match)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QRegularExpressionMatch *pValue ; 
		pValue = new QRegularExpressionMatch() ;
		*pValue = pObject->match(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (QRegularExpression::MatchType )  (int) RING_API_GETNUMBER(4), (QRegularExpression::MatchOptions )  (int) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpressionMatch",ring_QRegularExpressionMatch_freefunc);
	}
}


RING_FUNC(ring_QRegularExpression_namedCaptureGroups)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->namedCaptureGroups();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QRegularExpression_pattern)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETSTRING(pObject->pattern().toStdString().c_str());
}


RING_FUNC(ring_QRegularExpression_patternErrorOffset)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETNUMBER(pObject->patternErrorOffset());
}


RING_FUNC(ring_QRegularExpression_patternOptions)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	RING_API_RETNUMBER(pObject->patternOptions());
}


RING_FUNC(ring_QRegularExpression_setPattern)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPattern(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QRegularExpression_setPatternOptions)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPatternOptions( (QRegularExpression::PatternOptions )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QRegularExpression_swap)
{
	QRegularExpression *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
	pObject->swap(* (QRegularExpression   *) RING_API_GETCPOINTER(2,"QRegularExpression"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpression"));
}


RING_FUNC(ring_QRegularExpressionMatch_captured)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->captured( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QRegularExpressionMatch_captured_2)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETSTRING(pObject->captured(* (const QString   *) RING_API_GETCPOINTER(2,"const QString")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QString"));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedEnd)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->capturedEnd( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedEnd_2)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->capturedEnd(* (const QString   *) RING_API_GETCPOINTER(2,"const QString")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QString"));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedLength)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->capturedLength( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedLength_2)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->capturedLength(* (const QString   *) RING_API_GETCPOINTER(2,"const QString")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QString"));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedRef)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->capturedRef( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatch_capturedRef_2)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->capturedRef(* (const QString   *) RING_API_GETCPOINTER(2,"const QString"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QString"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatch_capturedStart)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->capturedStart( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedStart_2)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->capturedStart(* (const QString   *) RING_API_GETCPOINTER(2,"const QString")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QString"));
}


RING_FUNC(ring_QRegularExpressionMatch_capturedTexts)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->capturedTexts();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatch_hasMatch)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->hasMatch());
}


RING_FUNC(ring_QRegularExpressionMatch_hasPartialMatch)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->hasPartialMatch());
}


RING_FUNC(ring_QRegularExpressionMatch_isValid)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QRegularExpressionMatch_lastCapturedIndex)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->lastCapturedIndex());
}


RING_FUNC(ring_QRegularExpressionMatch_matchOptions)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->matchOptions());
}


RING_FUNC(ring_QRegularExpressionMatch_matchType)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	RING_API_RETNUMBER(pObject->matchType());
}


RING_FUNC(ring_QRegularExpressionMatch_regularExpression)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	{
		QRegularExpression *pValue ; 
		pValue = new QRegularExpression() ;
		*pValue = pObject->regularExpression();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpression",ring_QRegularExpression_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatch_swap)
{
	QRegularExpressionMatch *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
	pObject->swap(* (QRegularExpressionMatch   *) RING_API_GETCPOINTER(2,"QRegularExpressionMatch"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpressionMatch"));
}


RING_FUNC(ring_QRegularExpressionMatchIterator_hasNext)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	RING_API_RETNUMBER(pObject->hasNext());
}


RING_FUNC(ring_QRegularExpressionMatchIterator_isValid)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QRegularExpressionMatchIterator_matchOptions)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	RING_API_RETNUMBER(pObject->matchOptions());
}


RING_FUNC(ring_QRegularExpressionMatchIterator_matchType)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	RING_API_RETNUMBER(pObject->matchType());
}


RING_FUNC(ring_QRegularExpressionMatchIterator_next)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	{
		QRegularExpressionMatch *pValue ; 
		pValue = new QRegularExpressionMatch() ;
		*pValue = pObject->next();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpressionMatch",ring_QRegularExpressionMatch_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatchIterator_peekNext)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	{
		QRegularExpressionMatch *pValue ; 
		pValue = new QRegularExpressionMatch() ;
		*pValue = pObject->peekNext();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpressionMatch",ring_QRegularExpressionMatch_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatchIterator_regularExpression)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	{
		QRegularExpression *pValue ; 
		pValue = new QRegularExpression() ;
		*pValue = pObject->regularExpression();
		RING_API_RETMANAGEDCPOINTER(pValue,"QRegularExpression",ring_QRegularExpression_freefunc);
	}
}


RING_FUNC(ring_QRegularExpressionMatchIterator_swap)
{
	QRegularExpressionMatchIterator *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
	pObject->swap(* (QRegularExpressionMatchIterator  *) RING_API_GETCPOINTER(2,"QRegularExpressionMatchIterator"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpressionMatchIterator"));
}


RING_FUNC(ring_QJsonArray_append)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->append(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_at)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->at( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_contains)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->contains(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_count)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QJsonArray_empty)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QJsonArray_first)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->first();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_insert)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->insert( (int ) RING_API_GETNUMBER(2),* (QJsonValue   *) RING_API_GETCPOINTER(3,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_isEmpty)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonArray_last)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->last();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_pop_back)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->pop_back();
}


RING_FUNC(ring_QJsonArray_pop_front)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->pop_front();
}


RING_FUNC(ring_QJsonArray_prepend)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->prepend(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_push_back)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->push_back(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_push_front)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->push_front(* (QJsonValue   *) RING_API_GETCPOINTER(2,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_removeAt)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeAt( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QJsonArray_removeFirst)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->removeFirst();
}


RING_FUNC(ring_QJsonArray_removeLast)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	pObject->removeLast();
}


RING_FUNC(ring_QJsonArray_replace)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->replace( (int ) RING_API_GETNUMBER(2),* (QJsonValue   *) RING_API_GETCPOINTER(3,"QJsonValue"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QJsonValue"));
}


RING_FUNC(ring_QJsonArray_size)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QJsonArray_takeAt)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->takeAt( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_toVariantList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QVariantList *pValue ; 
		pValue = (QVariantList *) RING_API_MALLOC(sizeof(QVariantList)) ;
		*pValue = pObject->toVariantList();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariantList",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonArray_fromStringList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->fromStringList(* (QStringList   *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonArray_fromVariantList)
{
	QJsonArray *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->fromVariantList(* (QVariantList   *) RING_API_GETCPOINTER(2,"QVariantList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariantList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_array)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->array();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_isArray)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isArray());
}


RING_FUNC(ring_QJsonDocument_isEmpty)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonDocument_isNull)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QJsonDocument_isObject)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	RING_API_RETNUMBER(pObject->isObject());
}


RING_FUNC(ring_QJsonDocument_object)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->object();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_setArray)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	pObject->setArray(* (QJsonArray   *) RING_API_GETCPOINTER(2,"QJsonArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonArray"));
}


RING_FUNC(ring_QJsonDocument_setObject)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	pObject->setObject(* (QJsonObject   *) RING_API_GETCPOINTER(2,"QJsonObject"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonObject"));
}


RING_FUNC(ring_QJsonDocument_toJson)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toJson( (QJsonDocument::JsonFormat )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_toVariant)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->toVariant();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_fromJson)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->fromJson(* (QByteArray   *) RING_API_GETCPOINTER(2,"QByteArray"),(QJsonParseError *) RING_API_GETCPOINTER(3,"QJsonParseError"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QJsonDocument_fromVariant)
{
	QJsonDocument *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
	{
		QJsonDocument *pValue ; 
		pValue = new QJsonDocument() ;
		*pValue = pObject->fromVariant(* (QVariant   *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonDocument",ring_QJsonDocument_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_contains)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QJsonObject_count)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QJsonObject_empty)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->empty());
}


RING_FUNC(ring_QJsonObject_isEmpty)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QJsonObject_keys)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->keys();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_length)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QJsonObject_remove)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->remove(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QJsonObject_size)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QJsonObject_take)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->take(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_toVariantMap)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QVariantMap *pValue ; 
		pValue = (QVariantMap *) RING_API_MALLOC(sizeof(QVariantMap)) ;
		*pValue = pObject->toVariantMap();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariantMap",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonObject_value)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->value(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QJsonObject_fromVariantMap)
{
	QJsonObject *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->fromVariantMap(* (QVariantMap   *) RING_API_GETCPOINTER(2,"QVariantMap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariantMap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonParseError_errorString)
{
	QJsonParseError *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonParseError *) RING_API_GETCPOINTER(1,"QJsonParseError");
	RING_API_RETSTRING(pObject->errorString().toStdString().c_str());
}


RING_FUNC(ring_QJsonValue_isArray)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isArray());
}


RING_FUNC(ring_QJsonValue_isBool)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isBool());
}


RING_FUNC(ring_QJsonValue_isDouble)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isDouble());
}


RING_FUNC(ring_QJsonValue_isNull)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QJsonValue_isObject)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isObject());
}


RING_FUNC(ring_QJsonValue_isString)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isString());
}


RING_FUNC(ring_QJsonValue_isUndefined)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	RING_API_RETNUMBER(pObject->isUndefined());
}


RING_FUNC(ring_QJsonValue_toArray)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toArray(* (QJsonArray   *) RING_API_GETCPOINTER(2,"QJsonArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonArray"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toArray_2)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonArray *pValue ; 
		pValue = new QJsonArray() ;
		*pValue = pObject->toArray();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonArray",ring_QJsonArray_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toBool)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toBool( (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toDouble)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble( (double ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toInt)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QJsonValue_toObject)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toObject(* (QJsonObject   *) RING_API_GETCPOINTER(2,"QJsonObject"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QJsonObject"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toObject_2)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonObject *pValue ; 
		pValue = new QJsonObject() ;
		*pValue = pObject->toObject();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonObject",ring_QJsonObject_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_toString)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QJsonValue_toVariant)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->toVariant();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QJsonValue_type)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonValue::Type *pValue ; 
		pValue = (QJsonValue::Type *) RING_API_MALLOC(sizeof(QJsonValue::Type)) ;
		*pValue = pObject->type();
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue::Type",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QJsonValue_fromVariant)
{
	QJsonValue *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
	{
		QJsonValue *pValue ; 
		pValue = new QJsonValue() ;
		*pValue = pObject->fromVariant(* (QVariant   *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QJsonValue",ring_QJsonValue_freefunc);
	}
}


RING_FUNC(ring_QPointF_isNull)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QPointF_manhattanLength)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->manhattanLength());
}


RING_FUNC(ring_QPointF_rx)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->rx());
}


RING_FUNC(ring_QPointF_ry)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->ry());
}


RING_FUNC(ring_QPointF_setX)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setX( (qreal ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QPointF_setY)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setY( (qreal ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QPointF_toPoint)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	{
		QPoint *pValue ; 
		pValue = new QPoint() ;
		*pValue = pObject->toPoint();
		RING_API_RETMANAGEDCPOINTER(pValue,"QPoint",ring_QPoint_freefunc);
	}
}


RING_FUNC(ring_QPointF_x)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->x());
}


RING_FUNC(ring_QPointF_y)
{
	QPointF *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
	RING_API_RETNUMBER(pObject->y());
}


RING_FUNC(ring_QPoint_isNull)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QPoint_manhattanLength)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->manhattanLength());
}


RING_FUNC(ring_QPoint_rx)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->rx());
}


RING_FUNC(ring_QPoint_ry)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->ry());
}


RING_FUNC(ring_QPoint_setX)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setX( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QPoint_setY)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setY( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QPoint_x)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->x());
}


RING_FUNC(ring_QPoint_y)
{
	QPoint *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
	RING_API_RETNUMBER(pObject->y());
}


RING_FUNC(ring_QString2_split)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(RING_API_GETSTRING(2), (QString::SplitBehavior )  (int) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_split_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (QString::SplitBehavior )  (int) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_split_3)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(* (QRegExp   *) RING_API_GETCPOINTER(2,"QRegExp"), (QString::SplitBehavior )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegExp"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_split_4)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->split(* (QRegularExpression   *) RING_API_GETCPOINTER(2,"QRegularExpression"), (QString::SplitBehavior )  (int) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpression"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QString2_append)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->append(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_append_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->append(* (QChar  *) RING_API_GETCPOINTER(2,"QChar")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QString2_toUtf8)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toUtf8();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_toLatin1)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLatin1();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_toLocal8Bit)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLocal8Bit();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QString2_unicode)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETCPOINTER(pObject->unicode(),"QChar");
}


RING_FUNC(ring_QString2_number)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->number( (ulong ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_count)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QString2_left)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->left( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_mid)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->mid( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_right)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->right( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_compare)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_contains)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_indexOf)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QString2_lastIndexOf)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QString2_insert)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->insert( (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)).toStdString().c_str());
}


RING_FUNC(ring_QString2_isRightToLeft)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->isRightToLeft());
}


RING_FUNC(ring_QString2_repeated)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->repeated( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QString2_replace)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->replace( (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)).toStdString().c_str());
}


RING_FUNC(ring_QString2_replace_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->replace(RING_API_GETSTRING(2),RING_API_GETSTRING(3), (Qt::CaseSensitivity)  (int) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QString2_startsWith)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_endsWith)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QString2_toHtmlEscaped)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->toHtmlEscaped().toStdString().c_str());
}


RING_FUNC(ring_QString2_clear)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	pObject->clear();
}


RING_FUNC(ring_QString2_isNull)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QString2_resize)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->resize( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QString2_fill)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->fill(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QString2_localeAwareCompare)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->localeAwareCompare(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QString2_leftJustified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->leftJustified( (int ) RING_API_GETNUMBER(2),* (QChar  *) RING_API_GETCPOINTER(3,"QChar"), (bool ) RING_API_GETNUMBER(4)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QString2_rightJustified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->rightJustified( (int ) RING_API_GETNUMBER(2),* (QChar  *) RING_API_GETCPOINTER(3,"QChar"), (bool ) RING_API_GETNUMBER(4)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QString2_section_1)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_section_2)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_section_3)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(* (QRegExp  *) RING_API_GETCPOINTER(2,"QRegExp"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegExp"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_section_4)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->section(* (QRegularExpression  *) RING_API_GETCPOINTER(2,"QRegularExpression"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (QString::SectionFlags  *) RING_API_GETCPOINTER(5,"QString::SectionFlags")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QRegularExpression"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"QString::SectionFlags"));
}


RING_FUNC(ring_QString2_simplified)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->simplified().toStdString().c_str());
}


RING_FUNC(ring_QString2_toCaseFolded)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->toCaseFolded().toStdString().c_str());
}


RING_FUNC(ring_QString2_trimmed)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	RING_API_RETSTRING(pObject->trimmed().toStdString().c_str());
}


RING_FUNC(ring_QString2_truncate)
{
	QString *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QString *) RING_API_GETCPOINTER(1,"QString2");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->truncate( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QStringRef_appendTo)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringRef *pValue ; 
		pValue = new QStringRef() ;
		*pValue = pObject->appendTo((QString *) RING_API_GETCPOINTER(2,"QString"));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringRef",ring_QStringRef_freefunc);
	}
}


RING_FUNC(ring_QStringRef_at)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->at( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QStringRef_clear)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	pObject->clear();
}


RING_FUNC(ring_QStringRef_compare_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_compare_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_constData)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETCPOINTER(pObject->constData(),"QChar");
}


RING_FUNC(ring_QStringRef_contains)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringRef_contains_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_contains_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_contains_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->contains(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_count)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->count());
}


RING_FUNC(ring_QStringRef_count_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->count(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringRef_count_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->count(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_count_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->count(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_data)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETCPOINTER(pObject->data(),"QChar");
}


RING_FUNC(ring_QStringRef_endsWith)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringRef_endsWith_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_endsWith_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_endsWith_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->endsWith(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_indexOf)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QStringRef_indexOf_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_indexOf_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_indexOf_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->indexOf(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_isEmpty)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->isEmpty());
}


RING_FUNC(ring_QStringRef_isNull)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QStringRef_lastIndexOf)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QStringRef_lastIndexOf_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_lastIndexOf_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_lastIndexOf_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lastIndexOf(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (int ) RING_API_GETNUMBER(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_length)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->length());
}


RING_FUNC(ring_QStringRef_localeAwareCompare)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->localeAwareCompare(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QStringRef_localeAwareCompare_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->localeAwareCompare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_position)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->position());
}


RING_FUNC(ring_QStringRef_size)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->size());
}


RING_FUNC(ring_QStringRef_startsWith)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(RING_API_GETSTRING(2), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QStringRef_startsWith_2)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(* (QLatin1String  *) RING_API_GETCPOINTER(2,"QLatin1String"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_startsWith_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_startsWith_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->startsWith(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QStringRef_string)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETCPOINTER(pObject->string(),"QString");
}


RING_FUNC(ring_QStringRef_toLatin1)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLatin1();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QStringRef_toLocal8Bit)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toLocal8Bit();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QStringRef_toString)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QStringRef_toUcs4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	{
		QVector<uint> *pValue ; 
		pValue = (QVector<uint> *) RING_API_MALLOC(sizeof(QVector<uint>)) ;
		*pValue = pObject->toUcs4();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVector<uint>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QStringRef_toUtf8)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->toUtf8();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QStringRef_unicode)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETCPOINTER(pObject->unicode(),"QChar");
}


RING_FUNC(ring_QStringRef_compare_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),RING_API_GETSTRING(3), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_compare_5)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),* (QStringRef  *) RING_API_GETCPOINTER(3,"QStringRef"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringRef"));
}


RING_FUNC(ring_QStringRef_compare_6)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->compare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),* (QLatin1String  *) RING_API_GETCPOINTER(3,"QLatin1String"), (Qt::CaseSensitivity )  (int) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QLatin1String"));
}


RING_FUNC(ring_QStringRef_localeAwareCompare_3)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->localeAwareCompare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),RING_API_GETSTRING(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QStringRef_localeAwareCompare_4)
{
	QStringRef *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
	RING_API_RETNUMBER(pObject->localeAwareCompare(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),* (QStringRef  *) RING_API_GETCPOINTER(3,"QStringRef")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringRef"));
}


RING_FUNC(ring_QBuffer_buffer)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->buffer();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QBuffer_data)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->data();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QBuffer_setBuffer)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setBuffer((QByteArray *) RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QBuffer_setData)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	pObject->setData(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QBuffer_setData_2)
{
	QBuffer *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setData(RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QDateTime_addDays)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addDays( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addMSecs)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addMSecs( (qint64 ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addMonths)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addMonths( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addSecs)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addSecs( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_addYears)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->addYears( (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_date)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDate *pValue ; 
		pValue = new QDate() ;
		*pValue = pObject->date();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDate",ring_QDate_freefunc);
	}
}


RING_FUNC(ring_QDateTime_daysTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->daysTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_isNull)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QDateTime_isValid)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->isValid());
}


RING_FUNC(ring_QDateTime_msecsTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->msecsTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_secsTo)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->secsTo(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QDateTime_setDate)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	pObject->setDate(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QDateTime_setMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMSecsSinceEpoch( (qint64 ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDateTime_setTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	pObject->setTime(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QDateTime_setTimeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setTimeSpec( (Qt::TimeSpec )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QDateTime_time)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->time();
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_timeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->timeSpec());
}


RING_FUNC(ring_QDateTime_toLocalTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toLocalTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_toMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->toMSecsSinceEpoch());
}


RING_FUNC(ring_QDateTime_toString)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QDateTime_toString_2)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (Qt::DateFormat )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QDateTime_toTimeSpec)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toTimeSpec( (Qt::TimeSpec )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_toUTC)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->toUTC();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentDateTime)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->currentDateTime();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentDateTimeUtc)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->currentDateTimeUtc();
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_currentMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	RING_API_RETNUMBER(pObject->currentMSecsSinceEpoch());
}


RING_FUNC(ring_QDateTime_fromMSecsSinceEpoch)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromMSecsSinceEpoch( (qint64 ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_fromString)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2), (Qt::DateFormat )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QDateTime_fromString_2)
{
	QDateTime *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QDateTime *pValue ; 
		pValue = new QDateTime() ;
		*pValue = pObject->fromString(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QDateTime",ring_QDateTime_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_installNativeEventFilter)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->installNativeEventFilter((QAbstractNativeEventFilter *) RING_API_GETCPOINTER(2,"QAbstractNativeEventFilter"));
}


RING_FUNC(ring_QCoreApplication_removeNativeEventFilter)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeNativeEventFilter((QAbstractNativeEventFilter *) RING_API_GETCPOINTER(2,"QAbstractNativeEventFilter"));
}


RING_FUNC(ring_QCoreApplication_quit)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	pObject->quit();
}


RING_FUNC(ring_QCoreApplication_addLibraryPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->addLibraryPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_applicationDirPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationDirPath().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationFilePath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationFilePath().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationName().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_applicationPid)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->applicationPid());
}


RING_FUNC(ring_QCoreApplication_applicationVersion)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->applicationVersion().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_arguments)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->arguments();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_closingDown)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->closingDown());
}


RING_FUNC(ring_QCoreApplication_eventDispatcher)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETCPOINTER(pObject->eventDispatcher(),"QAbstractEventDispatcher");
}


RING_FUNC(ring_QCoreApplication_exec)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->exec());
}


RING_FUNC(ring_QCoreApplication_exit)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->exit( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_installTranslator)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->installTranslator((QTranslator *) RING_API_GETCPOINTER(2,"QTranslator")));
}


RING_FUNC(ring_QCoreApplication_instance)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETCPOINTER(pObject->instance(),"QCoreApplication");
}


RING_FUNC(ring_QCoreApplication_isQuitLockEnabled)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->isQuitLockEnabled());
}


RING_FUNC(ring_QCoreApplication_libraryPaths)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->libraryPaths();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QCoreApplication_organizationDomain)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->organizationDomain().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_organizationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETSTRING(pObject->organizationName().toStdString().c_str());
}


RING_FUNC(ring_QCoreApplication_postEvent)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->postEvent((QObject *) RING_API_GETCPOINTER(2,"QObject"),(QEvent *) RING_API_GETCPOINTER(3,"QEvent"), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_QCoreApplication_processEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->processEvents( (QEventLoop::ProcessEventsFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_processEvents_2)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->processEvents( (QEventLoop::ProcessEventsFlags )  (int) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_removeLibraryPath)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeLibraryPath(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_removePostedEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removePostedEvents((QObject *) RING_API_GETCPOINTER(2,"QObject"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_removeTranslator)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->removeTranslator((QTranslator *) RING_API_GETCPOINTER(2,"QTranslator")));
}


RING_FUNC(ring_QCoreApplication_sendEvent)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->sendEvent((QObject *) RING_API_GETCPOINTER(2,"QObject"),(QEvent *) RING_API_GETCPOINTER(3,"QEvent")));
}


RING_FUNC(ring_QCoreApplication_sendPostedEvents)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->sendPostedEvents((QObject *) RING_API_GETCPOINTER(2,"QObject"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_setApplicationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setApplicationName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setApplicationVersion)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setApplicationVersion(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setAttribute)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAttribute( (Qt::ApplicationAttribute )  (int) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QCoreApplication_setEventDispatcher)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEventDispatcher((QAbstractEventDispatcher *) RING_API_GETCPOINTER(2,"QAbstractEventDispatcher"));
}


RING_FUNC(ring_QCoreApplication_setLibraryPaths)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	pObject->setLibraryPaths(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QCoreApplication_setOrganizationDomain)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOrganizationDomain(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setOrganizationName)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setOrganizationName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QCoreApplication_setQuitLockEnabled)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setQuitLockEnabled( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QCoreApplication_startingUp)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	RING_API_RETNUMBER(pObject->startingUp());
}


RING_FUNC(ring_QCoreApplication_testAttribute)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->testAttribute( (Qt::ApplicationAttribute )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QCoreApplication_translate)
{
	QCoreApplication *pObject ;
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QCoreApplication *) RING_API_GETCPOINTER(1,"QCoreApplication");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->translate(RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5)).toStdString().c_str());
}


RING_FUNC(ring_QFile_copy)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->copy(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_exists)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETNUMBER(pObject->exists());
}


RING_FUNC(ring_QFile_link)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->link(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_open)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open((FILE *) RING_API_GETCPOINTER(2,"FILE"), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3), (QFile::FileHandleFlags )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QFile_open_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (int ) RING_API_GETNUMBER(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3), (QFile::FileHandleFlags )  (int) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_QFile_open_3)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->open( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFile_remove)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETNUMBER(pObject->remove());
}


RING_FUNC(ring_QFile_rename)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_setFileName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFileName(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QFile_symLinkTarget)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETSTRING(pObject->symLinkTarget().toStdString().c_str());
}


RING_FUNC(ring_QFile_copy_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->copy(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_decodeName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	RING_API_RETSTRING(pObject->decodeName(* (QByteArray  *) RING_API_GETCPOINTER(2,"QByteArray")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QByteArray"));
}


RING_FUNC(ring_QFile_decodeName_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->decodeName(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QFile_encodeName)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->encodeName(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QFile_exists_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->exists(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_link_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->link(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_permissions)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->permissions(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_remove_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->remove(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QFile_rename_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->rename(RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_QFile_resize)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->resize(RING_API_GETSTRING(2), (qint64 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QFile_setPermissions)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setPermissions(RING_API_GETSTRING(2), (QFile::Permissions )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QFile_symLinkTarget_2)
{
	QFile *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->symLinkTarget(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QFileDevice_error)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QFileDevice_flush)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->flush());
}


RING_FUNC(ring_QFileDevice_handle)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->handle());
}


RING_FUNC(ring_QFileDevice_map)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(pObject->map( (qint64 ) RING_API_GETNUMBER(2), (qint64 ) RING_API_GETNUMBER(3), (QFileDevice::MemoryMapFlags )  (int) RING_API_GETNUMBER(4)),"uchar");
}


RING_FUNC(ring_QFileDevice_permissions)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETNUMBER(pObject->permissions());
}


RING_FUNC(ring_QFileDevice_resize)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->resize( (qint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileDevice_fileName)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	RING_API_RETSTRING(pObject->fileName().toStdString().c_str());
}


RING_FUNC(ring_QFileDevice_setPermissions)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->setPermissions( (QFileDevice::Permissions )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QFileDevice_unmap)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->unmap((uchar *) RING_API_GETCPOINTER(2,"uchar")));
}


RING_FUNC(ring_QFileDevice_unsetError)
{
	QFileDevice *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QFileDevice *) RING_API_GETCPOINTER(1,"QFileDevice");
	pObject->unsetError();
}


RING_FUNC(ring_QStandardPaths_displayName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::displayName( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1)).toStdString().c_str());
}


RING_FUNC(ring_QStandardPaths_findExecutable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::findExecutable(RING_API_GETSTRING(1),* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QStandardPaths_locate)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::locate( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (QStandardPaths::LocateOptions )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QStandardPaths_locateAll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = QStandardPaths::locateAll( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1),RING_API_GETSTRING(2), (QStandardPaths::LocateOptions )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStandardPaths_setTestModeEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QStandardPaths::setTestModeEnabled( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_QStandardPaths_standardLocations)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = QStandardPaths::standardLocations( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QStandardPaths_writableLocation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(QStandardPaths::writableLocation( (QStandardPaths::StandardLocation )  (int) RING_API_GETNUMBER(1)).toStdString().c_str());
}


RING_FUNC(ring_QMimeData_clear)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->clear();
}


RING_FUNC(ring_QMimeData_colorData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->colorData();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QMimeData_data)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->data(RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QMimeData_formats)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->formats();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QMimeData_hasColor)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasColor());
}


RING_FUNC(ring_QMimeData_hasFormat)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasFormat(RING_API_GETSTRING(2)));
}


RING_FUNC(ring_QMimeData_hasHtml)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasHtml());
}


RING_FUNC(ring_QMimeData_hasImage)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasImage());
}


RING_FUNC(ring_QMimeData_hasText)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasText());
}


RING_FUNC(ring_QMimeData_hasUrls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETNUMBER(pObject->hasUrls());
}


RING_FUNC(ring_QMimeData_html)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETSTRING(pObject->html().toStdString().c_str());
}


RING_FUNC(ring_QMimeData_imageData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QVariant *pValue ; 
		pValue = new QVariant() ;
		*pValue = pObject->imageData();
		RING_API_RETMANAGEDCPOINTER(pValue,"QVariant",ring_QVariant_freefunc);
	}
}


RING_FUNC(ring_QMimeData_removeFormat)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->removeFormat(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setColorData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setColorData(* (QVariant  *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QMimeData_setData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setData(RING_API_GETSTRING(2),* (QByteArray  *) RING_API_GETCPOINTER(3,"QByteArray"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QByteArray"));
}


RING_FUNC(ring_QMimeData_setHtml)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setHtml(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setImageData)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setImageData(* (QVariant  *) RING_API_GETCPOINTER(2,"QVariant"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QVariant"));
}


RING_FUNC(ring_QMimeData_setText)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setText(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QMimeData_setUrls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	pObject->setUrls(* (QList<QUrl>  *) RING_API_GETCPOINTER(2,"QList<QUrl>"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QList<QUrl>"));
}


RING_FUNC(ring_QMimeData_text)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	RING_API_RETSTRING(pObject->text().toStdString().c_str());
}


RING_FUNC(ring_QMimeData_urls)
{
	QMimeData *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
	{
		QList<QUrl> *pValue ; 
		pValue = (QList<QUrl> *) RING_API_MALLOC(sizeof(QList<QUrl>)) ;
		*pValue = pObject->urls();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QUrl>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_category)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->category());
}


RING_FUNC(ring_QChar_cell)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		uchar *pValue ; 
		pValue = (uchar *) RING_API_MALLOC(sizeof(uchar)) ;
		*pValue = pObject->cell();
		RING_API_RETMANAGEDCPOINTER(pValue,"uchar",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_combiningClass)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->combiningClass());
}


RING_FUNC(ring_QChar_decomposition)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETSTRING(pObject->decomposition().toStdString().c_str());
}


RING_FUNC(ring_QChar_decompositionTag)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->decompositionTag());
}


RING_FUNC(ring_QChar_digitValue)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->digitValue());
}


RING_FUNC(ring_QChar_direction)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->direction());
}


RING_FUNC(ring_QChar_hasMirrored)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->hasMirrored());
}


RING_FUNC(ring_QChar_isDigit)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isDigit());
}


RING_FUNC(ring_QChar_isHighSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isHighSurrogate());
}


RING_FUNC(ring_QChar_isLetter)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLetter());
}


RING_FUNC(ring_QChar_isLetterOrNumber)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLetterOrNumber());
}


RING_FUNC(ring_QChar_isLowSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLowSurrogate());
}


RING_FUNC(ring_QChar_isLower)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isLower());
}


RING_FUNC(ring_QChar_isMark)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isMark());
}


RING_FUNC(ring_QChar_isNonCharacter)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNonCharacter());
}


RING_FUNC(ring_QChar_isNull)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNull());
}


RING_FUNC(ring_QChar_isNumber)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isNumber());
}


RING_FUNC(ring_QChar_isPrint)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isPrint());
}


RING_FUNC(ring_QChar_isPunct)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isPunct());
}


RING_FUNC(ring_QChar_isSpace)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSpace());
}


RING_FUNC(ring_QChar_isSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSurrogate());
}


RING_FUNC(ring_QChar_isSymbol)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isSymbol());
}


RING_FUNC(ring_QChar_isTitleCase)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isTitleCase());
}


RING_FUNC(ring_QChar_isUpper)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->isUpper());
}


RING_FUNC(ring_QChar_mirroredChar)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->mirroredChar();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_row)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		uchar *pValue ; 
		pValue = (uchar *) RING_API_MALLOC(sizeof(uchar)) ;
		*pValue = pObject->row();
		RING_API_RETMANAGEDCPOINTER(pValue,"uchar",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QChar_script)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->script());
}


RING_FUNC(ring_QChar_toCaseFolded)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toCaseFolded();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toLatin1)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->toLatin1());
}


RING_FUNC(ring_QChar_toLower)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toLower();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toTitleCase)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toTitleCase();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_toUpper)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->toUpper();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_unicode)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicode());
}


RING_FUNC(ring_QChar_unicode_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicode());
}


RING_FUNC(ring_QChar_unicodeVersion)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->unicodeVersion());
}


RING_FUNC(ring_QChar_category_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->category( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_combiningClass_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->combiningClass( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_currentUnicodeVersion)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->currentUnicodeVersion());
}


RING_FUNC(ring_QChar_decomposition_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->decomposition( (uint ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QChar_decompositionTag_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->decompositionTag( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_digitValue_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->digitValue( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_direction_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->direction( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_fromLatin1)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->fromLatin1( (char ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QChar_hasMirrored_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->hasMirrored( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_highSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->highSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isDigit_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isDigit( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isHighSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isHighSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLetter_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLetter( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLetterOrNumber_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLetterOrNumber( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLowSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLowSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isLower_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isLower( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isMark_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isMark( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isNonCharacter_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isNonCharacter( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isNumber_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isNumber( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isPrint_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isPrint( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isPunct_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isPunct( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSpace_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSpace( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSurrogate_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isSymbol_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isSymbol( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isTitleCase_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isTitleCase( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_isUpper_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->isUpper( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_lowSurrogate)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->lowSurrogate( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_mirroredChar_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->mirroredChar( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_requiresSurrogates)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->requiresSurrogates( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_script_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->script( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_surrogateToUcs4)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->surrogateToUcs4( (ushort ) RING_API_GETNUMBER(2), (ushort ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_QChar_surrogateToUcs4_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	RING_API_RETNUMBER(pObject->surrogateToUcs4(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"),* (QChar  *) RING_API_GETCPOINTER(3,"QChar")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QChar"));
}


RING_FUNC(ring_QChar_toCaseFolded_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toCaseFolded( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toLower_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toLower( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toTitleCase_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toTitleCase( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_toUpper_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUpper( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChar_unicodeVersion_2)
{
	QChar *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->unicodeVersion( (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QChildEvent_added)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->added());
}


RING_FUNC(ring_QChildEvent_child)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETCPOINTER(pObject->child(),"QObject");
}


RING_FUNC(ring_QChildEvent_polished)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->polished());
}


RING_FUNC(ring_QChildEvent_removed)
{
	QChildEvent *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
	RING_API_RETNUMBER(pObject->removed());
}


RING_FUNC(ring_QTextStream_atEnd)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->atEnd());
}


RING_FUNC(ring_QTextStream_autoDetectUnicode)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->autoDetectUnicode());
}


RING_FUNC(ring_QTextStream_codec)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETCPOINTER(pObject->codec(),"QTextCodec");
}


RING_FUNC(ring_QTextStream_device)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETCPOINTER(pObject->device(),"QIODevice");
}


RING_FUNC(ring_QTextStream_fieldAlignment)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->fieldAlignment());
}


RING_FUNC(ring_QTextStream_fieldWidth)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->fieldWidth());
}


RING_FUNC(ring_QTextStream_flush)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->flush();
}


RING_FUNC(ring_QTextStream_generateByteOrderMark)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->generateByteOrderMark());
}


RING_FUNC(ring_QTextStream_integerBase)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->integerBase());
}


RING_FUNC(ring_QTextStream_locale)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->locale();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QTextStream_numberFlags)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->numberFlags());
}


RING_FUNC(ring_QTextStream_padChar)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->padChar();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QTextStream_pos)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->pos());
}


RING_FUNC(ring_QTextStream_read)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->read( (qint64 ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QTextStream_readAll)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETSTRING(pObject->readAll().toStdString().c_str());
}


RING_FUNC(ring_QTextStream_readLine)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->readLine( (qint64 ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QTextStream_realNumberNotation)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->realNumberNotation());
}


RING_FUNC(ring_QTextStream_realNumberPrecision)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->realNumberPrecision());
}


RING_FUNC(ring_QTextStream_reset)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->reset();
}


RING_FUNC(ring_QTextStream_resetStatus)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->resetStatus();
}


RING_FUNC(ring_QTextStream_seek)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->seek( (qint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QTextStream_setAutoDetectUnicode)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setAutoDetectUnicode( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setCodec)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCodec((QTextCodec *) RING_API_GETCPOINTER(2,"QTextCodec"));
}


RING_FUNC(ring_QTextStream_setCodec_2)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setCodec(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QTextStream_setDevice)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setDevice((QIODevice *) RING_API_GETCPOINTER(2,"QIODevice"));
}


RING_FUNC(ring_QTextStream_setFieldAlignment)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFieldAlignment( (QTextStream::FieldAlignment )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setFieldWidth)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFieldWidth( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setGenerateByteOrderMark)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setGenerateByteOrderMark( (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setIntegerBase)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setIntegerBase( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setLocale)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->setLocale(* (QLocale  *) RING_API_GETCPOINTER(2,"QLocale"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLocale"));
}


RING_FUNC(ring_QTextStream_setNumberFlags)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNumberFlags( (QTextStream::NumberFlags )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setPadChar)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->setPadChar(* (QChar  *) RING_API_GETCPOINTER(2,"QChar"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QChar"));
}


RING_FUNC(ring_QTextStream_setRealNumberNotation)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setRealNumberNotation( (QTextStream::RealNumberNotation )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setRealNumberPrecision)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setRealNumberPrecision( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setStatus)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStatus( (QTextStream::Status )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QTextStream_setString)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setString((QString *) RING_API_GETCPOINTER(2,"QString"), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QTextStream_skipWhiteSpace)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	pObject->skipWhiteSpace();
}


RING_FUNC(ring_QTextStream_status)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETNUMBER(pObject->status());
}


RING_FUNC(ring_QTextStream_string)
{
	QTextStream *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
	RING_API_RETCPOINTER(pObject->string(),"QString");
}


RING_FUNC(ring_QLocale_amText)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->amText().toStdString().c_str());
}


RING_FUNC(ring_QLocale_bcp47Name)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->bcp47Name().toStdString().c_str());
}


RING_FUNC(ring_QLocale_country)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->country());
}


RING_FUNC(ring_QLocale_createSeparatedList)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->createSeparatedList(* (QStringList  *) RING_API_GETCPOINTER(2,"QStringList")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QLocale_currencySymbol)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->currencySymbol( (QLocale::CurrencySymbolFormat )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dateFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dateFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dateTimeFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dateTimeFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_dayName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->dayName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_decimalPoint)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->decimalPoint();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_exponential)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->exponential();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_firstDayOfWeek)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		Qt::DayOfWeek *pValue ; 
		pValue = (Qt::DayOfWeek *) RING_API_MALLOC(sizeof(Qt::DayOfWeek)) ;
		*pValue = pObject->firstDayOfWeek();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::DayOfWeek",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_groupSeparator)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->groupSeparator();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_language)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->language());
}


RING_FUNC(ring_QLocale_measurementSystem)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->measurementSystem());
}


RING_FUNC(ring_QLocale_monthName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->monthName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_name)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->name().toStdString().c_str());
}


RING_FUNC(ring_QLocale_nativeCountryName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->nativeCountryName().toStdString().c_str());
}


RING_FUNC(ring_QLocale_nativeLanguageName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->nativeLanguageName().toStdString().c_str());
}


RING_FUNC(ring_QLocale_negativeSign)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->negativeSign();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_numberOptions)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->numberOptions());
}


RING_FUNC(ring_QLocale_percent)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->percent();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_pmText)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->pmText().toStdString().c_str());
}


RING_FUNC(ring_QLocale_positiveSign)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->positiveSign();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_quoteString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->quoteString(RING_API_GETSTRING(2), (QLocale::QuotationStyle )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_quoteString_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->quoteString(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"), (QLocale::QuotationStyle )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_script)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->script());
}


RING_FUNC(ring_QLocale_setNumberOptions)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setNumberOptions( (QLocale::NumberOptions )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QLocale_standaloneDayName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->standaloneDayName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_standaloneMonthName)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->standaloneMonthName( (int ) RING_API_GETNUMBER(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_textDirection)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETNUMBER(pObject->textDirection());
}


RING_FUNC(ring_QLocale_timeFormat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->timeFormat( (QLocale::FormatType )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toDouble)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toDouble_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toDouble(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_toFloat)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toFloat_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toFloat(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_toInt)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toInt_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toInt(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_toLongLong)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toLongLong_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qlonglong *pValue ; 
		pValue = (qlonglong *) RING_API_MALLOC(sizeof(qlonglong)) ;
		*pValue = pObject->toLongLong(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qlonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toLower)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toLower(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toShort)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		short *pValue ; 
		pValue = (short *) RING_API_MALLOC(sizeof(short)) ;
		*pValue = pObject->toShort(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"short",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toShort_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		short *pValue ; 
		pValue = (short *) RING_API_MALLOC(sizeof(short)) ;
		*pValue = pObject->toShort(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
		RING_API_RETMANAGEDCPOINTER(pValue,"short",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (qlonglong  *) RING_API_GETCPOINTER(2,"qlonglong")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qlonglong"));
}


RING_FUNC(ring_QLocale_toString_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (qulonglong  *) RING_API_GETCPOINTER(2,"qulonglong")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"qulonglong"));
}


RING_FUNC(ring_QLocale_toString_4)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	RING_API_RETSTRING(pObject->toString(* (short  *) RING_API_GETCPOINTER(2,"short")).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"short"));
}


RING_FUNC(ring_QLocale_toString_5)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (ushort ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_6)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (int ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_7)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (uint ) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_8)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (double ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_9)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString( (float ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_toString_10)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QLocale_toString_11)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QLocale_toString_12)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime"),RING_API_GETSTRING(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QLocale_toString_13)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDate  *) RING_API_GETCPOINTER(2,"QDate"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDate"));
}


RING_FUNC(ring_QLocale_toString_14)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QTime  *) RING_API_GETCPOINTER(2,"QTime"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QTime"));
}


RING_FUNC(ring_QLocale_toString_15)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toString(* (QDateTime  *) RING_API_GETCPOINTER(2,"QDateTime"), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3)).toStdString().c_str());
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QDateTime"));
}


RING_FUNC(ring_QLocale_toTime)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime(RING_API_GETSTRING(2), (QLocale::FormatType )  (int) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QLocale_toTime_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QTime *pValue ; 
		pValue = new QTime() ;
		*pValue = pObject->toTime(RING_API_GETSTRING(2),RING_API_GETSTRING(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"QTime",ring_QTime_freefunc);
	}
}


RING_FUNC(ring_QLocale_toUInt)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toUInt_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUInt(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_toULongLong)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qulonglong *pValue ; 
		pValue = (qulonglong *) RING_API_MALLOC(sizeof(qulonglong)) ;
		*pValue = pObject->toULongLong(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qulonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toULongLong_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		qulonglong *pValue ; 
		pValue = (qulonglong *) RING_API_MALLOC(sizeof(qulonglong)) ;
		*pValue = pObject->toULongLong(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
		RING_API_RETMANAGEDCPOINTER(pValue,"qulonglong",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_toUShort)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUShort(RING_API_GETSTRING(2),(bool *) RING_API_GETCPOINTER(3,"bool")));
}


RING_FUNC(ring_QLocale_toUShort_2)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->toUShort(* (QStringRef  *) RING_API_GETCPOINTER(2,"QStringRef"),(bool *) RING_API_GETCPOINTER(3,"bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringRef"));
}


RING_FUNC(ring_QLocale_toUpper)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->toUpper(RING_API_GETSTRING(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_uiLanguages)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->uiLanguages();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QLocale_weekdays)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QList<Qt::DayOfWeek> *pValue ; 
		pValue = (QList<Qt::DayOfWeek> *) RING_API_MALLOC(sizeof(QList<Qt::DayOfWeek>)) ;
		*pValue = pObject->weekdays();
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<Qt::DayOfWeek>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_zeroDigit)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QChar *pValue ; 
		pValue = new QChar() ;
		*pValue = pObject->zeroDigit();
		RING_API_RETMANAGEDCPOINTER(pValue,"QChar",ring_QChar_freefunc);
	}
}


RING_FUNC(ring_QLocale_c)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->c();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QLocale_countryToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->countryToString( (QLocale::Country )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_languageToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->languageToString( (QLocale::Language )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_matchingLocales)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		QList<QLocale> *pValue ; 
		pValue = (QList<QLocale> *) RING_API_MALLOC(sizeof(QList<QLocale>)) ;
		*pValue = pObject->matchingLocales( (QLocale::Language )  (int) RING_API_GETNUMBER(2), (QLocale::Script )  (int) RING_API_GETNUMBER(3), (QLocale::Country )  (int) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"QList<QLocale>",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QLocale_scriptToString)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pObject->scriptToString( (QLocale::Script )  (int) RING_API_GETNUMBER(2)).toStdString().c_str());
}


RING_FUNC(ring_QLocale_setDefault)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	pObject->setDefault(* (QLocale  *) RING_API_GETCPOINTER(2,"QLocale"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QLocale"));
}


RING_FUNC(ring_QLocale_system)
{
	QLocale *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
	{
		QLocale *pValue ; 
		pValue = new QLocale() ;
		*pValue = pObject->system();
		RING_API_RETMANAGEDCPOINTER(pValue,"QLocale",ring_QLocale_freefunc);
	}
}


RING_FUNC(ring_QThread_eventDispatcher)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETCPOINTER(pObject->eventDispatcher(),"QAbstractEventDispatcher");
}


RING_FUNC(ring_QThread_exit)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->exit( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_isFinished)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isFinished());
}


RING_FUNC(ring_QThread_isInterruptionRequested)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isInterruptionRequested());
}


RING_FUNC(ring_QThread_isRunning)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->isRunning());
}


RING_FUNC(ring_QThread_priority)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->priority());
}


RING_FUNC(ring_QThread_requestInterruption)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->requestInterruption();
}


RING_FUNC(ring_QThread_setEventDispatcher)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setEventDispatcher((QAbstractEventDispatcher *) RING_API_GETCPOINTER(2,"QAbstractEventDispatcher"));
}


RING_FUNC(ring_QThread_setPriority)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setPriority( (QThread::Priority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_setStackSize)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStackSize( (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_stackSize)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->stackSize());
}


RING_FUNC(ring_QThread_wait)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->wait(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_quit)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->quit();
}


RING_FUNC(ring_QThread_start)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start( (QThread::Priority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThread_terminate)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->terminate();
}


RING_FUNC(ring_QThread_currentThread)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETCPOINTER(pObject->currentThread(),"QThread");
}


RING_FUNC(ring_QThread_currentThreadId)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	{
		Qt::HANDLE *pValue ; 
		pValue = (Qt::HANDLE *) RING_API_MALLOC(sizeof(Qt::HANDLE)) ;
		*pValue = pObject->currentThreadId();
		RING_API_RETMANAGEDCPOINTER(pValue,"Qt::HANDLE",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QThread_idealThreadCount)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETNUMBER(pObject->idealThreadCount());
}


RING_FUNC(ring_QThread_msleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->msleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_sleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->sleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_usleep)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->usleep(* (unsigned long  *) RING_API_GETCPOINTER(2,"unsigned long"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unsigned long"));
}


RING_FUNC(ring_QThread_yieldCurrentThread)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	pObject->yieldCurrentThread();
}


RING_FUNC(ring_QThread_setStartedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStartedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QThread_setFinishedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setFinishedEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QThread_getStartedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETSTRING(pObject->getStartedEvent());
}


RING_FUNC(ring_QThread_getFinishedEvent)
{
	GThread *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GThread *) RING_API_GETCPOINTER(1,"QThread");
	RING_API_RETSTRING(pObject->getFinishedEvent());
}


RING_FUNC(ring_QThreadPool_activeThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->activeThreadCount());
}


RING_FUNC(ring_QThreadPool_clear)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->clear();
}


RING_FUNC(ring_QThreadPool_expiryTimeout)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->expiryTimeout());
}


RING_FUNC(ring_QThreadPool_maxThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETNUMBER(pObject->maxThreadCount());
}


RING_FUNC(ring_QThreadPool_releaseThread)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->releaseThread();
}


RING_FUNC(ring_QThreadPool_reserveThread)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	pObject->reserveThread();
}


RING_FUNC(ring_QThreadPool_setExpiryTimeout)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setExpiryTimeout( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThreadPool_setMaxThreadCount)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setMaxThreadCount( (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QThreadPool_start)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start((QRunnable *) RING_API_GETCPOINTER(2,"QRunnable"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QThreadPool_tryStart)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->tryStart((QRunnable *) RING_API_GETCPOINTER(2,"QRunnable")));
}


RING_FUNC(ring_QThreadPool_waitForDone)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForDone( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QThreadPool_globalInstance)
{
	QThreadPool *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
	RING_API_RETCPOINTER(pObject->globalInstance(),"QThreadPool");
}


RING_FUNC(ring_QProcess_arguments)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QStringList *pValue ; 
		pValue = new QStringList() ;
		*pValue = pObject->arguments();
		RING_API_RETMANAGEDCPOINTER(pValue,"QStringList",ring_QStringList_freefunc);
	}
}


RING_FUNC(ring_QProcess_closeReadChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->closeReadChannel( (QProcess::ProcessChannel )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_closeWriteChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->closeWriteChannel();
}


RING_FUNC(ring_QProcess_error)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->error());
}


RING_FUNC(ring_QProcess_exitCode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->exitCode());
}


RING_FUNC(ring_QProcess_exitStatus)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->exitStatus());
}


RING_FUNC(ring_QProcess_inputChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->inputChannelMode());
}


RING_FUNC(ring_QProcess_processChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->processChannelMode());
}


RING_FUNC(ring_QProcess_processEnvironment)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QProcessEnvironment *pValue ; 
		pValue = (QProcessEnvironment *) RING_API_MALLOC(sizeof(QProcessEnvironment)) ;
		*pValue = pObject->processEnvironment();
		RING_API_RETMANAGEDCPOINTER(pValue,"QProcessEnvironment",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_QProcess_program)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->program().toStdString().c_str());
}


RING_FUNC(ring_QProcess_readAllStandardError)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAllStandardError();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QProcess_readAllStandardOutput)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	{
		QByteArray *pValue ; 
		pValue = new QByteArray() ;
		*pValue = pObject->readAllStandardOutput();
		RING_API_RETMANAGEDCPOINTER(pValue,"QByteArray",ring_QByteArray_freefunc);
	}
}


RING_FUNC(ring_QProcess_readChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->readChannel());
}


RING_FUNC(ring_QProcess_setArguments)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->setArguments(* (QStringList   *) RING_API_GETCPOINTER(2,"QStringList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QStringList"));
}


RING_FUNC(ring_QProcess_setInputChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setInputChannelMode( (QProcess::InputChannelMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setProcessChannelMode)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setProcessChannelMode( (QProcess::ProcessChannelMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setProcessEnvironment)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->setProcessEnvironment(* (QProcessEnvironment   *) RING_API_GETCPOINTER(2,"QProcessEnvironment"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"QProcessEnvironment"));
}


RING_FUNC(ring_QProcess_setProgram)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setProgram(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setReadChannel)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setReadChannel( (QProcess::ProcessChannel )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_setStandardErrorFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardErrorFile(RING_API_GETSTRING(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QProcess_setStandardInputFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardInputFile(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setStandardOutputFile)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardOutputFile(RING_API_GETSTRING(2), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_QProcess_setStandardOutputProcess)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setStandardOutputProcess((QProcess *) RING_API_GETCPOINTER(2,"QProcess"));
}


RING_FUNC(ring_QProcess_setWorkingDirectory)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setWorkingDirectory(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_start)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start(RING_API_GETSTRING(2),* (QStringList   *) RING_API_GETCPOINTER(3,"QStringList"), (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"QStringList"));
}


RING_FUNC(ring_QProcess_start_3)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->start( (QIODevice::OpenMode )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_QProcess_state)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETNUMBER(pObject->state());
}


RING_FUNC(ring_QProcess_waitForFinished)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForFinished( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QProcess_waitForStarted)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pObject->waitForStarted( (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_QProcess_workingDirectory)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->workingDirectory().toStdString().c_str());
}


RING_FUNC(ring_QProcess_kill)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->kill();
}


RING_FUNC(ring_QProcess_terminate)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	pObject->terminate();
}


RING_FUNC(ring_QProcess_setreadyReadStandardErrorEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadStandardErrorEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_setreadyReadStandardOutputEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject->setreadyReadStandardOutputEvent(RING_API_GETSTRING(2));
}


RING_FUNC(ring_QProcess_getreadyReadStandardErrorEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->getreadyReadStandardErrorEvent());
}


RING_FUNC(ring_QProcess_getreadyReadStandardOutputEvent)
{
	GProcess *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (GProcess *) RING_API_GETCPOINTER(1,"QProcess");
	RING_API_RETSTRING(pObject->getreadyReadStandardOutputEvent());
}


RING_FUNC(ring_QUuid_toString)
{
	QUuid *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QUuid *) RING_API_GETCPOINTER(1,"QUuid");
	RING_API_RETSTRING(pObject->toString().toStdString().c_str());
}


RING_FUNC(ring_QMutex_isRecursive)
{
	QMutex *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
	RING_API_RETNUMBER(pObject->isRecursive());
}


RING_FUNC(ring_QMutex_lock)
{
	QMutex *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
	pObject->lock();
}


RING_FUNC(ring_QMutex_unlock)
{
	QMutex *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
	pObject->unlock();
}


RING_FUNC(ring_QMutexLocker_mutex)
{
	QMutexLocker *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker *) RING_API_GETCPOINTER(1,"QMutexLocker");
	RING_API_RETCPOINTER(pObject->mutex(),"QMutex");
}


RING_FUNC(ring_QMutexLocker_relock)
{
	QMutexLocker *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker *) RING_API_GETCPOINTER(1,"QMutexLocker");
	pObject->relock();
}


RING_FUNC(ring_QMutexLocker_unlock)
{
	QMutexLocker *pObject ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pObject = (QMutexLocker *) RING_API_GETCPOINTER(1,"QMutexLocker");
	pObject->unlock();
}

RING_FUNC(ring_QObject_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QObject *pObject = new QObject();
	RING_API_RETCPOINTER(pObject,"QObject");
}

RING_FUNC(ring_QSize_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QSize *pObject = new QSize((int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
	RING_API_RETMANAGEDCPOINTER(pObject,"QSize",ring_QSize_freefunc);
}

RING_FUNC(ring_QDir_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDir *pObject = new QDir();
	RING_API_RETMANAGEDCPOINTER(pObject,"QDir",ring_QDir_freefunc);
}

RING_FUNC(ring_QUrl_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QUrl *pObject = new QUrl(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QUrl");
}

RING_FUNC(ring_QEvent_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QEvent *pObject = new QEvent((QEvent::Type )  (int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QEvent");
}

RING_FUNC(ring_QTimer_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GTimer *pObject = new GTimer((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QTimer");
}

RING_FUNC(ring_QByteArray_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QByteArray *pObject = new QByteArray();
	RING_API_RETCPOINTER(pObject,"QByteArray");
}

RING_FUNC(ring_QFileInfo_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QFileInfo *pObject = new QFileInfo();
	RING_API_RETCPOINTER(pObject,"QFileInfo");
}

RING_FUNC(ring_QStringList_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QStringList *pObject = new QStringList();
	RING_API_RETMANAGEDCPOINTER(pObject,"QStringList",ring_QStringList_freefunc);
}

RING_FUNC(ring_QRect_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QRect *pObject = new QRect();
	RING_API_RETCPOINTER(pObject,"QRect");
}

RING_FUNC(ring_QTime_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QTime *pObject = new QTime();
	RING_API_RETCPOINTER(pObject,"QTime");
}

RING_FUNC(ring_QDate_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDate *pObject = new QDate();
	RING_API_RETCPOINTER(pObject,"QDate");
}

RING_FUNC(ring_QVariant_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QVariant *pObject = new QVariant();
	RING_API_RETCPOINTER(pObject,"QVariant");
}

RING_FUNC(ring_QVariant2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant2");
}

RING_FUNC(ring_QVariant3_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((float) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant3");
}

RING_FUNC(ring_QVariant4_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((double) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariant4");
}

RING_FUNC(ring_QVariant5_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QVariant5");
}

RING_FUNC(ring_QVariantInt_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantInt");
}

RING_FUNC(ring_QVariantFloat_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((float) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantFloat");
}

RING_FUNC(ring_QVariantDouble_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant((double) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QVariantDouble");
}

RING_FUNC(ring_QVariantString_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QVariant *pObject = new QVariant(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QVariantString");
}

RING_FUNC(ring_QXmlStreamReader_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamReader *pObject = new QXmlStreamReader();
	RING_API_RETCPOINTER(pObject,"QXmlStreamReader");
}

RING_FUNC(ring_QXmlStreamWriter_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamWriter *pObject = new QXmlStreamWriter();
	RING_API_RETCPOINTER(pObject,"QXmlStreamWriter");
}

RING_FUNC(ring_QXmlStreamNotationDeclaration_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamNotationDeclaration *pObject = new QXmlStreamNotationDeclaration();
	RING_API_RETCPOINTER(pObject,"QXmlStreamNotationDeclaration");
}

RING_FUNC(ring_QXmlStreamNamespaceDeclaration_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamNamespaceDeclaration *pObject = new QXmlStreamNamespaceDeclaration();
	RING_API_RETCPOINTER(pObject,"QXmlStreamNamespaceDeclaration");
}

RING_FUNC(ring_QXmlStreamEntityDeclaration_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamEntityDeclaration *pObject = new QXmlStreamEntityDeclaration();
	RING_API_RETCPOINTER(pObject,"QXmlStreamEntityDeclaration");
}

RING_FUNC(ring_QXmlStreamEntityResolver_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamEntityResolver *pObject = new QXmlStreamEntityResolver();
	RING_API_RETCPOINTER(pObject,"QXmlStreamEntityResolver");
}

RING_FUNC(ring_QXmlStreamAttributes_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamAttributes *pObject = new QXmlStreamAttributes();
	RING_API_RETCPOINTER(pObject,"QXmlStreamAttributes");
}

RING_FUNC(ring_QXmlStreamAttribute_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QXmlStreamAttribute *pObject = new QXmlStreamAttribute();
	RING_API_RETCPOINTER(pObject,"QXmlStreamAttribute");
}

RING_FUNC(ring_QRegularExpression_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QRegularExpression *pObject = new QRegularExpression();
	RING_API_RETCPOINTER(pObject,"QRegularExpression");
}

RING_FUNC(ring_QRegularExpressionMatch_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QRegularExpressionMatch *pObject = new QRegularExpressionMatch();
	RING_API_RETCPOINTER(pObject,"QRegularExpressionMatch");
}

RING_FUNC(ring_QRegularExpressionMatchIterator_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QRegularExpressionMatchIterator *pObject = new QRegularExpressionMatchIterator();
	RING_API_RETCPOINTER(pObject,"QRegularExpressionMatchIterator");
}

RING_FUNC(ring_QJsonArray_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonArray *pObject = new QJsonArray();
	RING_API_RETCPOINTER(pObject,"QJsonArray");
}

RING_FUNC(ring_QJsonDocument_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonDocument *pObject = new QJsonDocument();
	RING_API_RETCPOINTER(pObject,"QJsonDocument");
}

RING_FUNC(ring_QJsonObject_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonObject *pObject = new QJsonObject();
	RING_API_RETCPOINTER(pObject,"QJsonObject");
}

RING_FUNC(ring_QJsonParseError_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonParseError *pObject = new QJsonParseError();
	RING_API_RETCPOINTER(pObject,"QJsonParseError");
}

RING_FUNC(ring_QJsonValue_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QJsonValue *pObject = new QJsonValue();
	RING_API_RETCPOINTER(pObject,"QJsonValue");
}

RING_FUNC(ring_QPointF_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QPointF *pObject = new QPointF();
	RING_API_RETCPOINTER(pObject,"QPointF");
}

RING_FUNC(ring_QPoint_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QPoint *pObject = new QPoint();
	RING_API_RETCPOINTER(pObject,"QPoint");
}

RING_FUNC(ring_QString2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QString *pObject = new QString();
	RING_API_RETMANAGEDCPOINTER(pObject,"QString2",ring_QString2_freefunc);
}

RING_FUNC(ring_QStringRef_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QStringRef *pObject = new QStringRef();
	RING_API_RETCPOINTER(pObject,"QStringRef");
}

RING_FUNC(ring_QBuffer_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QBuffer *pObject = new QBuffer((QObject *) RING_API_GETCPOINTER(1,"QObject"));
	RING_API_RETCPOINTER(pObject,"QBuffer");
}

RING_FUNC(ring_QDateTime_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QDateTime *pObject = new QDateTime();
	RING_API_RETCPOINTER(pObject,"QDateTime");
}

RING_FUNC(ring_QFile_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QFile *pObject = new QFile();
	RING_API_RETCPOINTER(pObject,"QFile");
}

RING_FUNC(ring_QFile2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QFile *pObject = new QFile(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QFile2");
}

RING_FUNC(ring_QMimeData_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QMimeData *pObject = new QMimeData();
	RING_API_RETCPOINTER(pObject,"QMimeData");
}

RING_FUNC(ring_QChar_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QChar *pObject = new QChar((int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QChar");
}

RING_FUNC(ring_QChildEvent_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QChildEvent *pObject = new QChildEvent((QEvent::Type)  (int) RING_API_GETNUMBER(1),(QObject *) RING_API_GETCPOINTER(2,"QObject"));
	RING_API_RETCPOINTER(pObject,"QChildEvent");
}

RING_FUNC(ring_QTextStream_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QTextStream *pObject = new QTextStream();
	RING_API_RETCPOINTER(pObject,"QTextStream");
}

RING_FUNC(ring_QTextStream2_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QTextStream *pObject = new QTextStream((QIODevice *) RING_API_GETCPOINTER(1,"QIODevice"));
	RING_API_RETCPOINTER(pObject,"QTextStream2");
}

RING_FUNC(ring_QTextStream3_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QTextStream *pObject = new QTextStream((FILE *) RING_API_GETCPOINTER(1,"FILE"), (QIODevice::OpenMode)  (int) RING_API_GETNUMBER(2));
	RING_API_RETCPOINTER(pObject,"QTextStream3");
}

RING_FUNC(ring_QTextStream4_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QTextStream *pObject = new QTextStream((QString *) RING_API_GETCPOINTER(1,"QString"), (QIODevice::OpenMode)  (int) RING_API_GETNUMBER(2));
	RING_API_RETCPOINTER(pObject,"QTextStream4");
}

RING_FUNC(ring_QTextStream5_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QTextStream *pObject = new QTextStream((QByteArray *) RING_API_GETCPOINTER(1,"QByteArray"), (QIODevice::OpenMode)  (int) RING_API_GETNUMBER(2));
	RING_API_RETCPOINTER(pObject,"QTextStream5");
}

RING_FUNC(ring_QLocale_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QLocale *pObject = new QLocale(RING_API_GETSTRING(1));
	RING_API_RETCPOINTER(pObject,"QLocale");
}

RING_FUNC(ring_QThread_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GThread *pObject = new GThread((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QThread");
}

RING_FUNC(ring_QThreadPool_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QThreadPool *pObject = new QThreadPool();
	RING_API_RETCPOINTER(pObject,"QThreadPool");
}

RING_FUNC(ring_QProcess_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	GProcess *pObject = new GProcess((QObject *) RING_API_GETCPOINTER(1,"QObject"), (VM *) pPointer);
	RING_API_RETCPOINTER(pObject,"QProcess");
}

RING_FUNC(ring_QUuid_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	QUuid *pObject = new QUuid();
	RING_API_RETCPOINTER(pObject,"QUuid");
}

RING_FUNC(ring_QMutex_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QMutex *pObject = new QMutex((QMutex::RecursionMode)  (int) RING_API_GETNUMBER(1));
	RING_API_RETCPOINTER(pObject,"QMutex");
}

RING_FUNC(ring_QMutexLocker_new)
{
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	QMutexLocker *pObject = new QMutexLocker((QMutex *) RING_API_GETCPOINTER(1,"QMutex"));
	RING_API_RETCPOINTER(pObject,"QMutexLocker");
}

RING_FUNC(ring_QObject_delete)
{
	QObject *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QObject *) RING_API_GETCPOINTER(1,"QObject");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QSize_delete)
{
	QSize *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QSize *) RING_API_GETCPOINTER(1,"QSize");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDir_delete)
{
	QDir *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDir *) RING_API_GETCPOINTER(1,"QDir");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QUrl_delete)
{
	QUrl *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QUrl *) RING_API_GETCPOINTER(1,"QUrl");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QEvent_delete)
{
	QEvent *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QEvent *) RING_API_GETCPOINTER(1,"QEvent");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTimer_delete)
{
	GTimer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GTimer *) RING_API_GETCPOINTER(1,"GTimer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QByteArray_delete)
{
	QByteArray *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QByteArray *) RING_API_GETCPOINTER(1,"QByteArray");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFileInfo_delete)
{
	QFileInfo *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFileInfo *) RING_API_GETCPOINTER(1,"QFileInfo");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QStringList_delete)
{
	QStringList *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QStringList *) RING_API_GETCPOINTER(1,"QStringList");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QRect_delete)
{
	QRect *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QRect *) RING_API_GETCPOINTER(1,"QRect");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTime_delete)
{
	QTime *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTime *) RING_API_GETCPOINTER(1,"QTime");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDate_delete)
{
	QDate *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDate *) RING_API_GETCPOINTER(1,"QDate");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant2_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant3_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant4_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariant5_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantInt_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantFloat_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantDouble_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QVariantString_delete)
{
	QVariant *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QVariant *) RING_API_GETCPOINTER(1,"QVariant");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamReader_delete)
{
	QXmlStreamReader *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamReader *) RING_API_GETCPOINTER(1,"QXmlStreamReader");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamWriter_delete)
{
	QXmlStreamWriter *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamWriter *) RING_API_GETCPOINTER(1,"QXmlStreamWriter");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamNotationDeclaration_delete)
{
	QXmlStreamNotationDeclaration *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamNotationDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNotationDeclaration");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamNamespaceDeclaration_delete)
{
	QXmlStreamNamespaceDeclaration *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamNamespaceDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamNamespaceDeclaration");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamEntityDeclaration_delete)
{
	QXmlStreamEntityDeclaration *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamEntityDeclaration *) RING_API_GETCPOINTER(1,"QXmlStreamEntityDeclaration");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamEntityResolver_delete)
{
	QXmlStreamEntityResolver *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamEntityResolver *) RING_API_GETCPOINTER(1,"QXmlStreamEntityResolver");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamAttributes_delete)
{
	QXmlStreamAttributes *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamAttributes *) RING_API_GETCPOINTER(1,"QXmlStreamAttributes");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QXmlStreamAttribute_delete)
{
	QXmlStreamAttribute *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QXmlStreamAttribute *) RING_API_GETCPOINTER(1,"QXmlStreamAttribute");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QRegularExpression_delete)
{
	QRegularExpression *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QRegularExpression *) RING_API_GETCPOINTER(1,"QRegularExpression");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QRegularExpressionMatch_delete)
{
	QRegularExpressionMatch *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QRegularExpressionMatch *) RING_API_GETCPOINTER(1,"QRegularExpressionMatch");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QRegularExpressionMatchIterator_delete)
{
	QRegularExpressionMatchIterator *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QRegularExpressionMatchIterator *) RING_API_GETCPOINTER(1,"QRegularExpressionMatchIterator");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonArray_delete)
{
	QJsonArray *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonArray *) RING_API_GETCPOINTER(1,"QJsonArray");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonDocument_delete)
{
	QJsonDocument *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonDocument *) RING_API_GETCPOINTER(1,"QJsonDocument");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonObject_delete)
{
	QJsonObject *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonObject *) RING_API_GETCPOINTER(1,"QJsonObject");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonParseError_delete)
{
	QJsonParseError *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonParseError *) RING_API_GETCPOINTER(1,"QJsonParseError");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QJsonValue_delete)
{
	QJsonValue *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QJsonValue *) RING_API_GETCPOINTER(1,"QJsonValue");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QPointF_delete)
{
	QPointF *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QPointF *) RING_API_GETCPOINTER(1,"QPointF");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QPoint_delete)
{
	QPoint *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QPoint *) RING_API_GETCPOINTER(1,"QPoint");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QString2_delete)
{
	QString *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QString *) RING_API_GETCPOINTER(1,"QString");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QStringRef_delete)
{
	QStringRef *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QStringRef *) RING_API_GETCPOINTER(1,"QStringRef");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QBuffer_delete)
{
	QBuffer *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QBuffer *) RING_API_GETCPOINTER(1,"QBuffer");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QDateTime_delete)
{
	QDateTime *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QDateTime *) RING_API_GETCPOINTER(1,"QDateTime");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFile_delete)
{
	QFile *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QFile2_delete)
{
	QFile *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QFile *) RING_API_GETCPOINTER(1,"QFile");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QMimeData_delete)
{
	QMimeData *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QMimeData *) RING_API_GETCPOINTER(1,"QMimeData");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QChar_delete)
{
	QChar *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QChar *) RING_API_GETCPOINTER(1,"QChar");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QChildEvent_delete)
{
	QChildEvent *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QChildEvent *) RING_API_GETCPOINTER(1,"QChildEvent");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTextStream_delete)
{
	QTextStream *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTextStream2_delete)
{
	QTextStream *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTextStream3_delete)
{
	QTextStream *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTextStream4_delete)
{
	QTextStream *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QTextStream5_delete)
{
	QTextStream *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QTextStream *) RING_API_GETCPOINTER(1,"QTextStream");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QLocale_delete)
{
	QLocale *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QLocale *) RING_API_GETCPOINTER(1,"QLocale");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QThread_delete)
{
	GThread *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GThread *) RING_API_GETCPOINTER(1,"GThread");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QThreadPool_delete)
{
	QThreadPool *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QThreadPool *) RING_API_GETCPOINTER(1,"QThreadPool");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QProcess_delete)
{
	GProcess *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (GProcess *) RING_API_GETCPOINTER(1,"GProcess");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QUuid_delete)
{
	QUuid *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QUuid *) RING_API_GETCPOINTER(1,"QUuid");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QMutex_delete)
{
	QMutex *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QMutex *) RING_API_GETCPOINTER(1,"QMutex");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_QMutexLocker_delete)
{
	QMutexLocker *pObject ; 
	RING_API_IGNORECPOINTERTYPE ;
	if ( RING_API_PARACOUNT != 1 )
	{
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISCPOINTER(1) )
	{
		pObject = (QMutexLocker *) RING_API_GETCPOINTER(1,"QMutexLocker");
		delete pObject ;
		RING_API_SETNULLPOINTER(1);
	}
}

void ring_QObject_freefunc(void *pState,void *pPointer)
{
	QObject *pObject ; 
	pObject = (QObject *) pPointer;
	delete pObject ;
}

void ring_QSize_freefunc(void *pState,void *pPointer)
{
	QSize *pObject ; 
	pObject = (QSize *) pPointer;
	delete pObject ;
}

void ring_QDir_freefunc(void *pState,void *pPointer)
{
	QDir *pObject ; 
	pObject = (QDir *) pPointer;
	delete pObject ;
}

void ring_QUrl_freefunc(void *pState,void *pPointer)
{
	QUrl *pObject ; 
	pObject = (QUrl *) pPointer;
	delete pObject ;
}

void ring_QEvent_freefunc(void *pState,void *pPointer)
{
	QEvent *pObject ; 
	pObject = (QEvent *) pPointer;
	delete pObject ;
}

void ring_QTimer_freefunc(void *pState,void *pPointer)
{
	GTimer *pObject ; 
	pObject = (GTimer *) pPointer;
	delete pObject ;
}

void ring_QByteArray_freefunc(void *pState,void *pPointer)
{
	QByteArray *pObject ; 
	pObject = (QByteArray *) pPointer;
	delete pObject ;
}

void ring_QFileInfo_freefunc(void *pState,void *pPointer)
{
	QFileInfo *pObject ; 
	pObject = (QFileInfo *) pPointer;
	delete pObject ;
}

void ring_QStringList_freefunc(void *pState,void *pPointer)
{
	QStringList *pObject ; 
	pObject = (QStringList *) pPointer;
	delete pObject ;
}

void ring_QRect_freefunc(void *pState,void *pPointer)
{
	QRect *pObject ; 
	pObject = (QRect *) pPointer;
	delete pObject ;
}

void ring_QTime_freefunc(void *pState,void *pPointer)
{
	QTime *pObject ; 
	pObject = (QTime *) pPointer;
	delete pObject ;
}

void ring_QDate_freefunc(void *pState,void *pPointer)
{
	QDate *pObject ; 
	pObject = (QDate *) pPointer;
	delete pObject ;
}

void ring_QVariant_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant2_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant3_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant4_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariant5_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantInt_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantFloat_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantDouble_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QVariantString_freefunc(void *pState,void *pPointer)
{
	QVariant *pObject ; 
	pObject = (QVariant *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamReader_freefunc(void *pState,void *pPointer)
{
	QXmlStreamReader *pObject ; 
	pObject = (QXmlStreamReader *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamWriter_freefunc(void *pState,void *pPointer)
{
	QXmlStreamWriter *pObject ; 
	pObject = (QXmlStreamWriter *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamNotationDeclaration_freefunc(void *pState,void *pPointer)
{
	QXmlStreamNotationDeclaration *pObject ; 
	pObject = (QXmlStreamNotationDeclaration *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamNamespaceDeclaration_freefunc(void *pState,void *pPointer)
{
	QXmlStreamNamespaceDeclaration *pObject ; 
	pObject = (QXmlStreamNamespaceDeclaration *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamEntityDeclaration_freefunc(void *pState,void *pPointer)
{
	QXmlStreamEntityDeclaration *pObject ; 
	pObject = (QXmlStreamEntityDeclaration *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamEntityResolver_freefunc(void *pState,void *pPointer)
{
	QXmlStreamEntityResolver *pObject ; 
	pObject = (QXmlStreamEntityResolver *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamAttributes_freefunc(void *pState,void *pPointer)
{
	QXmlStreamAttributes *pObject ; 
	pObject = (QXmlStreamAttributes *) pPointer;
	delete pObject ;
}

void ring_QXmlStreamAttribute_freefunc(void *pState,void *pPointer)
{
	QXmlStreamAttribute *pObject ; 
	pObject = (QXmlStreamAttribute *) pPointer;
	delete pObject ;
}

void ring_QRegularExpression_freefunc(void *pState,void *pPointer)
{
	QRegularExpression *pObject ; 
	pObject = (QRegularExpression *) pPointer;
	delete pObject ;
}

void ring_QRegularExpressionMatch_freefunc(void *pState,void *pPointer)
{
	QRegularExpressionMatch *pObject ; 
	pObject = (QRegularExpressionMatch *) pPointer;
	delete pObject ;
}

void ring_QRegularExpressionMatchIterator_freefunc(void *pState,void *pPointer)
{
	QRegularExpressionMatchIterator *pObject ; 
	pObject = (QRegularExpressionMatchIterator *) pPointer;
	delete pObject ;
}

void ring_QJsonArray_freefunc(void *pState,void *pPointer)
{
	QJsonArray *pObject ; 
	pObject = (QJsonArray *) pPointer;
	delete pObject ;
}

void ring_QJsonDocument_freefunc(void *pState,void *pPointer)
{
	QJsonDocument *pObject ; 
	pObject = (QJsonDocument *) pPointer;
	delete pObject ;
}

void ring_QJsonObject_freefunc(void *pState,void *pPointer)
{
	QJsonObject *pObject ; 
	pObject = (QJsonObject *) pPointer;
	delete pObject ;
}

void ring_QJsonParseError_freefunc(void *pState,void *pPointer)
{
	QJsonParseError *pObject ; 
	pObject = (QJsonParseError *) pPointer;
	delete pObject ;
}

void ring_QJsonValue_freefunc(void *pState,void *pPointer)
{
	QJsonValue *pObject ; 
	pObject = (QJsonValue *) pPointer;
	delete pObject ;
}

void ring_QPointF_freefunc(void *pState,void *pPointer)
{
	QPointF *pObject ; 
	pObject = (QPointF *) pPointer;
	delete pObject ;
}

void ring_QPoint_freefunc(void *pState,void *pPointer)
{
	QPoint *pObject ; 
	pObject = (QPoint *) pPointer;
	delete pObject ;
}

void ring_QString2_freefunc(void *pState,void *pPointer)
{
	QString *pObject ; 
	pObject = (QString *) pPointer;
	delete pObject ;
}

void ring_QStringRef_freefunc(void *pState,void *pPointer)
{
	QStringRef *pObject ; 
	pObject = (QStringRef *) pPointer;
	delete pObject ;
}

void ring_QBuffer_freefunc(void *pState,void *pPointer)
{
	QBuffer *pObject ; 
	pObject = (QBuffer *) pPointer;
	delete pObject ;
}

void ring_QDateTime_freefunc(void *pState,void *pPointer)
{
	QDateTime *pObject ; 
	pObject = (QDateTime *) pPointer;
	delete pObject ;
}

void ring_QFile_freefunc(void *pState,void *pPointer)
{
	QFile *pObject ; 
	pObject = (QFile *) pPointer;
	delete pObject ;
}

void ring_QFile2_freefunc(void *pState,void *pPointer)
{
	QFile *pObject ; 
	pObject = (QFile *) pPointer;
	delete pObject ;
}

void ring_QMimeData_freefunc(void *pState,void *pPointer)
{
	QMimeData *pObject ; 
	pObject = (QMimeData *) pPointer;
	delete pObject ;
}

void ring_QChar_freefunc(void *pState,void *pPointer)
{
	QChar *pObject ; 
	pObject = (QChar *) pPointer;
	delete pObject ;
}

void ring_QChildEvent_freefunc(void *pState,void *pPointer)
{
	QChildEvent *pObject ; 
	pObject = (QChildEvent *) pPointer;
	delete pObject ;
}

void ring_QTextStream_freefunc(void *pState,void *pPointer)
{
	QTextStream *pObject ; 
	pObject = (QTextStream *) pPointer;
	delete pObject ;
}

void ring_QTextStream2_freefunc(void *pState,void *pPointer)
{
	QTextStream *pObject ; 
	pObject = (QTextStream *) pPointer;
	delete pObject ;
}

void ring_QTextStream3_freefunc(void *pState,void *pPointer)
{
	QTextStream *pObject ; 
	pObject = (QTextStream *) pPointer;
	delete pObject ;
}

void ring_QTextStream4_freefunc(void *pState,void *pPointer)
{
	QTextStream *pObject ; 
	pObject = (QTextStream *) pPointer;
	delete pObject ;
}

void ring_QTextStream5_freefunc(void *pState,void *pPointer)
{
	QTextStream *pObject ; 
	pObject = (QTextStream *) pPointer;
	delete pObject ;
}

void ring_QLocale_freefunc(void *pState,void *pPointer)
{
	QLocale *pObject ; 
	pObject = (QLocale *) pPointer;
	delete pObject ;
}

void ring_QThread_freefunc(void *pState,void *pPointer)
{
	GThread *pObject ; 
	pObject = (GThread *) pPointer;
	delete pObject ;
}

void ring_QThreadPool_freefunc(void *pState,void *pPointer)
{
	QThreadPool *pObject ; 
	pObject = (QThreadPool *) pPointer;
	delete pObject ;
}

void ring_QProcess_freefunc(void *pState,void *pPointer)
{
	GProcess *pObject ; 
	pObject = (GProcess *) pPointer;
	delete pObject ;
}

void ring_QUuid_freefunc(void *pState,void *pPointer)
{
	QUuid *pObject ; 
	pObject = (QUuid *) pPointer;
	delete pObject ;
}

void ring_QMutex_freefunc(void *pState,void *pPointer)
{
	QMutex *pObject ; 
	pObject = (QMutex *) pPointer;
	delete pObject ;
}

void ring_QMutexLocker_freefunc(void *pState,void *pPointer)
{
	QMutexLocker *pObject ; 
	pObject = (QMutexLocker *) pPointer;
	delete pObject ;
}

RING_API void ring_qt_start(RingState *pRingState)
{
	RING_API_REGISTER("qobject_blocksignals",ring_QObject_blockSignals);
	RING_API_REGISTER("qobject_children",ring_QObject_children);
	RING_API_REGISTER("qobject_dumpobjectinfo",ring_QObject_dumpObjectInfo);
	RING_API_REGISTER("qobject_dumpobjecttree",ring_QObject_dumpObjectTree);
	RING_API_REGISTER("qobject_inherits",ring_QObject_inherits);
	RING_API_REGISTER("qobject_installeventfilter",ring_QObject_installEventFilter);
	RING_API_REGISTER("qobject_iswidgettype",ring_QObject_isWidgetType);
	RING_API_REGISTER("qobject_killtimer",ring_QObject_killTimer);
	RING_API_REGISTER("qobject_movetothread",ring_QObject_moveToThread);
	RING_API_REGISTER("qobject_objectname",ring_QObject_objectName);
	RING_API_REGISTER("qobject_parent",ring_QObject_parent);
	RING_API_REGISTER("qobject_property",ring_QObject_property);
	RING_API_REGISTER("qobject_removeeventfilter",ring_QObject_removeEventFilter);
	RING_API_REGISTER("qobject_setobjectname",ring_QObject_setObjectName);
	RING_API_REGISTER("qobject_setparent",ring_QObject_setParent);
	RING_API_REGISTER("qobject_setproperty",ring_QObject_setProperty);
	RING_API_REGISTER("qobject_setproperty_2",ring_QObject_setProperty_2);
	RING_API_REGISTER("qobject_setproperty_3",ring_QObject_setProperty_3);
	RING_API_REGISTER("qobject_setproperty_4",ring_QObject_setProperty_4);
	RING_API_REGISTER("qobject_setproperty_5",ring_QObject_setProperty_5);
	RING_API_REGISTER("qobject_setproperty_int",ring_QObject_setProperty_int);
	RING_API_REGISTER("qobject_setproperty_float",ring_QObject_setProperty_float);
	RING_API_REGISTER("qobject_setproperty_double",ring_QObject_setProperty_double);
	RING_API_REGISTER("qobject_setproperty_string",ring_QObject_setProperty_string);
	RING_API_REGISTER("qobject_signalsblocked",ring_QObject_signalsBlocked);
	RING_API_REGISTER("qobject_starttimer",ring_QObject_startTimer);
	RING_API_REGISTER("qobject_thread",ring_QObject_thread);
	RING_API_REGISTER("qobject_deletelater",ring_QObject_deleteLater);
	RING_API_REGISTER("qdir_absolutefilepath",ring_QDir_absoluteFilePath);
	RING_API_REGISTER("qdir_absolutepath",ring_QDir_absolutePath);
	RING_API_REGISTER("qdir_canonicalpath",ring_QDir_canonicalPath);
	RING_API_REGISTER("qdir_cd",ring_QDir_cd);
	RING_API_REGISTER("qdir_cdup",ring_QDir_cdUp);
	RING_API_REGISTER("qdir_count",ring_QDir_count);
	RING_API_REGISTER("qdir_dirname",ring_QDir_dirName);
	RING_API_REGISTER("qdir_entryinfolist",ring_QDir_entryInfoList);
	RING_API_REGISTER("qdir_entryinfolist_2",ring_QDir_entryInfoList_2);
	RING_API_REGISTER("qdir_entrylist",ring_QDir_entryList);
	RING_API_REGISTER("qdir_entrylist_2",ring_QDir_entryList_2);
	RING_API_REGISTER("qdir_exists",ring_QDir_exists);
	RING_API_REGISTER("qdir_exists_2",ring_QDir_exists_2);
	RING_API_REGISTER("qdir_filepath",ring_QDir_filePath);
	RING_API_REGISTER("qdir_filter",ring_QDir_filter);
	RING_API_REGISTER("qdir_isabsolute",ring_QDir_isAbsolute);
	RING_API_REGISTER("qdir_isreadable",ring_QDir_isReadable);
	RING_API_REGISTER("qdir_isrelative",ring_QDir_isRelative);
	RING_API_REGISTER("qdir_isroot",ring_QDir_isRoot);
	RING_API_REGISTER("qdir_makeabsolute",ring_QDir_makeAbsolute);
	RING_API_REGISTER("qdir_mkdir",ring_QDir_mkdir);
	RING_API_REGISTER("qdir_mkpath",ring_QDir_mkpath);
	RING_API_REGISTER("qdir_namefilters",ring_QDir_nameFilters);
	RING_API_REGISTER("qdir_path",ring_QDir_path);
	RING_API_REGISTER("qdir_refresh",ring_QDir_refresh);
	RING_API_REGISTER("qdir_relativefilepath",ring_QDir_relativeFilePath);
	RING_API_REGISTER("qdir_remove",ring_QDir_remove);
	RING_API_REGISTER("qdir_removerecursively",ring_QDir_removeRecursively);
	RING_API_REGISTER("qdir_rename",ring_QDir_rename);
	RING_API_REGISTER("qdir_rmdir",ring_QDir_rmdir);
	RING_API_REGISTER("qdir_rmpath",ring_QDir_rmpath);
	RING_API_REGISTER("qdir_setfilter",ring_QDir_setFilter);
	RING_API_REGISTER("qdir_setnamefilters",ring_QDir_setNameFilters);
	RING_API_REGISTER("qdir_setpath",ring_QDir_setPath);
	RING_API_REGISTER("qdir_setsorting",ring_QDir_setSorting);
	RING_API_REGISTER("qdir_sorting",ring_QDir_sorting);
	RING_API_REGISTER("qdir_swap",ring_QDir_swap);
	RING_API_REGISTER("qdir_addsearchpath",ring_QDir_addSearchPath);
	RING_API_REGISTER("qdir_cleanpath",ring_QDir_cleanPath);
	RING_API_REGISTER("qdir_current",ring_QDir_current);
	RING_API_REGISTER("qdir_currentpath",ring_QDir_currentPath);
	RING_API_REGISTER("qdir_drives",ring_QDir_drives);
	RING_API_REGISTER("qdir_fromnativeseparators",ring_QDir_fromNativeSeparators);
	RING_API_REGISTER("qdir_home",ring_QDir_home);
	RING_API_REGISTER("qdir_homepath",ring_QDir_homePath);
	RING_API_REGISTER("qdir_isabsolutepath",ring_QDir_isAbsolutePath);
	RING_API_REGISTER("qdir_isrelativepath",ring_QDir_isRelativePath);
	RING_API_REGISTER("qdir_match",ring_QDir_match);
	RING_API_REGISTER("qdir_match_2",ring_QDir_match_2);
	RING_API_REGISTER("qdir_root",ring_QDir_root);
	RING_API_REGISTER("qdir_rootpath",ring_QDir_rootPath);
	RING_API_REGISTER("qdir_searchpaths",ring_QDir_searchPaths);
	RING_API_REGISTER("qdir_separator",ring_QDir_separator);
	RING_API_REGISTER("qdir_setcurrent",ring_QDir_setCurrent);
	RING_API_REGISTER("qdir_setsearchpaths",ring_QDir_setSearchPaths);
	RING_API_REGISTER("qdir_temp",ring_QDir_temp);
	RING_API_REGISTER("qdir_temppath",ring_QDir_tempPath);
	RING_API_REGISTER("qdir_tonativeseparators",ring_QDir_toNativeSeparators);
	RING_API_REGISTER("qurl_authority",ring_QUrl_authority);
	RING_API_REGISTER("qurl_clear",ring_QUrl_clear);
	RING_API_REGISTER("qurl_errorstring",ring_QUrl_errorString);
	RING_API_REGISTER("qurl_filename",ring_QUrl_fileName);
	RING_API_REGISTER("qurl_fragment",ring_QUrl_fragment);
	RING_API_REGISTER("qurl_hasfragment",ring_QUrl_hasFragment);
	RING_API_REGISTER("qurl_hasquery",ring_QUrl_hasQuery);
	RING_API_REGISTER("qurl_host",ring_QUrl_host);
	RING_API_REGISTER("qurl_isempty",ring_QUrl_isEmpty);
	RING_API_REGISTER("qurl_islocalfile",ring_QUrl_isLocalFile);
	RING_API_REGISTER("qurl_isparentof",ring_QUrl_isParentOf);
	RING_API_REGISTER("qurl_isrelative",ring_QUrl_isRelative);
	RING_API_REGISTER("qurl_isvalid",ring_QUrl_isValid);
	RING_API_REGISTER("qurl_password",ring_QUrl_password);
	RING_API_REGISTER("qurl_path",ring_QUrl_path);
	RING_API_REGISTER("qurl_port",ring_QUrl_port);
	RING_API_REGISTER("qurl_query",ring_QUrl_query);
	RING_API_REGISTER("qurl_resolved",ring_QUrl_resolved);
	RING_API_REGISTER("qurl_scheme",ring_QUrl_scheme);
	RING_API_REGISTER("qurl_setauthority",ring_QUrl_setAuthority);
	RING_API_REGISTER("qurl_setfragment",ring_QUrl_setFragment);
	RING_API_REGISTER("qurl_sethost",ring_QUrl_setHost);
	RING_API_REGISTER("qurl_setpassword",ring_QUrl_setPassword);
	RING_API_REGISTER("qurl_setpath",ring_QUrl_setPath);
	RING_API_REGISTER("qurl_setport",ring_QUrl_setPort);
	RING_API_REGISTER("qurl_setquery",ring_QUrl_setQuery);
	RING_API_REGISTER("qurl_setscheme",ring_QUrl_setScheme);
	RING_API_REGISTER("qurl_seturl",ring_QUrl_setUrl);
	RING_API_REGISTER("qurl_setuserinfo",ring_QUrl_setUserInfo);
	RING_API_REGISTER("qurl_setusername",ring_QUrl_setUserName);
	RING_API_REGISTER("qurl_swap",ring_QUrl_swap);
	RING_API_REGISTER("qurl_tolocalfile",ring_QUrl_toLocalFile);
	RING_API_REGISTER("qurl_userinfo",ring_QUrl_userInfo);
	RING_API_REGISTER("qurl_username",ring_QUrl_userName);
	RING_API_REGISTER("qurl_fromlocalfile",ring_QUrl_fromLocalFile);
	RING_API_REGISTER("qevent_accept",ring_QEvent_accept);
	RING_API_REGISTER("qevent_ignore",ring_QEvent_ignore);
	RING_API_REGISTER("qevent_isaccepted",ring_QEvent_isAccepted);
	RING_API_REGISTER("qevent_setaccepted",ring_QEvent_setAccepted);
	RING_API_REGISTER("qevent_spontaneous",ring_QEvent_spontaneous);
	RING_API_REGISTER("qevent_type",ring_QEvent_type);
	RING_API_REGISTER("qtimer_interval",ring_QTimer_interval);
	RING_API_REGISTER("qtimer_isactive",ring_QTimer_isActive);
	RING_API_REGISTER("qtimer_issingleshot",ring_QTimer_isSingleShot);
	RING_API_REGISTER("qtimer_setinterval",ring_QTimer_setInterval);
	RING_API_REGISTER("qtimer_setsingleshot",ring_QTimer_setSingleShot);
	RING_API_REGISTER("qtimer_timerid",ring_QTimer_timerId);
	RING_API_REGISTER("qtimer_start",ring_QTimer_start);
	RING_API_REGISTER("qtimer_stop",ring_QTimer_stop);
	RING_API_REGISTER("qtimer_settimeoutevent",ring_QTimer_settimeoutEvent);
	RING_API_REGISTER("qtimer_gettimeoutevent",ring_QTimer_gettimeoutEvent);
	RING_API_REGISTER("qbytearray_append",ring_QByteArray_append);
	RING_API_REGISTER("qbytearray_append_2",ring_QByteArray_append_2);
	RING_API_REGISTER("qbytearray_at",ring_QByteArray_at);
	RING_API_REGISTER("qbytearray_capacity",ring_QByteArray_capacity);
	RING_API_REGISTER("qbytearray_chop",ring_QByteArray_chop);
	RING_API_REGISTER("qbytearray_clear",ring_QByteArray_clear);
	RING_API_REGISTER("qbytearray_constdata",ring_QByteArray_constData);
	RING_API_REGISTER("qbytearray_contains",ring_QByteArray_contains);
	RING_API_REGISTER("qbytearray_count",ring_QByteArray_count);
	RING_API_REGISTER("qbytearray_data",ring_QByteArray_data);
	RING_API_REGISTER("qbytearray_endswith",ring_QByteArray_endsWith);
	RING_API_REGISTER("qbytearray_fill",ring_QByteArray_fill);
	RING_API_REGISTER("qbytearray_indexof",ring_QByteArray_indexOf);
	RING_API_REGISTER("qbytearray_insert",ring_QByteArray_insert);
	RING_API_REGISTER("qbytearray_isempty",ring_QByteArray_isEmpty);
	RING_API_REGISTER("qbytearray_isnull",ring_QByteArray_isNull);
	RING_API_REGISTER("qbytearray_lastindexof",ring_QByteArray_lastIndexOf);
	RING_API_REGISTER("qbytearray_left",ring_QByteArray_left);
	RING_API_REGISTER("qbytearray_leftjustified",ring_QByteArray_leftJustified);
	RING_API_REGISTER("qbytearray_length",ring_QByteArray_length);
	RING_API_REGISTER("qbytearray_mid",ring_QByteArray_mid);
	RING_API_REGISTER("qbytearray_prepend",ring_QByteArray_prepend);
	RING_API_REGISTER("qbytearray_push_back",ring_QByteArray_push_back);
	RING_API_REGISTER("qbytearray_push_front",ring_QByteArray_push_front);
	RING_API_REGISTER("qbytearray_remove",ring_QByteArray_remove);
	RING_API_REGISTER("qbytearray_repeated",ring_QByteArray_repeated);
	RING_API_REGISTER("qbytearray_replace",ring_QByteArray_replace);
	RING_API_REGISTER("qbytearray_replace_2",ring_QByteArray_replace_2);
	RING_API_REGISTER("qbytearray_replace_3",ring_QByteArray_replace_3);
	RING_API_REGISTER("qbytearray_replace_4",ring_QByteArray_replace_4);
	RING_API_REGISTER("qbytearray_replace_5",ring_QByteArray_replace_5);
	RING_API_REGISTER("qbytearray_replace_6",ring_QByteArray_replace_6);
	RING_API_REGISTER("qbytearray_replace_7",ring_QByteArray_replace_7);
	RING_API_REGISTER("qbytearray_replace_8",ring_QByteArray_replace_8);
	RING_API_REGISTER("qbytearray_replace_9",ring_QByteArray_replace_9);
	RING_API_REGISTER("qbytearray_replace_10",ring_QByteArray_replace_10);
	RING_API_REGISTER("qbytearray_replace_11",ring_QByteArray_replace_11);
	RING_API_REGISTER("qbytearray_reserve",ring_QByteArray_reserve);
	RING_API_REGISTER("qbytearray_resize",ring_QByteArray_resize);
	RING_API_REGISTER("qbytearray_right",ring_QByteArray_right);
	RING_API_REGISTER("qbytearray_rightjustified",ring_QByteArray_rightJustified);
	RING_API_REGISTER("qbytearray_setnum",ring_QByteArray_setNum);
	RING_API_REGISTER("qbytearray_setrawdata",ring_QByteArray_setRawData);
	RING_API_REGISTER("qbytearray_simplified",ring_QByteArray_simplified);
	RING_API_REGISTER("qbytearray_size",ring_QByteArray_size);
	RING_API_REGISTER("qbytearray_squeeze",ring_QByteArray_squeeze);
	RING_API_REGISTER("qbytearray_startswith",ring_QByteArray_startsWith);
	RING_API_REGISTER("qbytearray_swap",ring_QByteArray_swap);
	RING_API_REGISTER("qbytearray_tobase64",ring_QByteArray_toBase64);
	RING_API_REGISTER("qbytearray_todouble",ring_QByteArray_toDouble);
	RING_API_REGISTER("qbytearray_tofloat",ring_QByteArray_toFloat);
	RING_API_REGISTER("qbytearray_tohex",ring_QByteArray_toHex);
	RING_API_REGISTER("qbytearray_toint",ring_QByteArray_toInt);
	RING_API_REGISTER("qbytearray_tolong",ring_QByteArray_toLong);
	RING_API_REGISTER("qbytearray_tolonglong",ring_QByteArray_toLongLong);
	RING_API_REGISTER("qbytearray_tolower",ring_QByteArray_toLower);
	RING_API_REGISTER("qbytearray_topercentencoding",ring_QByteArray_toPercentEncoding);
	RING_API_REGISTER("qbytearray_toshort",ring_QByteArray_toShort);
	RING_API_REGISTER("qbytearray_touint",ring_QByteArray_toUInt);
	RING_API_REGISTER("qbytearray_toulong",ring_QByteArray_toULong);
	RING_API_REGISTER("qbytearray_toulonglong",ring_QByteArray_toULongLong);
	RING_API_REGISTER("qbytearray_toushort",ring_QByteArray_toUShort);
	RING_API_REGISTER("qbytearray_toupper",ring_QByteArray_toUpper);
	RING_API_REGISTER("qbytearray_trimmed",ring_QByteArray_trimmed);
	RING_API_REGISTER("qbytearray_truncate",ring_QByteArray_truncate);
	RING_API_REGISTER("qbytearray_frombase64",ring_QByteArray_fromBase64);
	RING_API_REGISTER("qbytearray_fromhex",ring_QByteArray_fromHex);
	RING_API_REGISTER("qbytearray_frompercentencoding",ring_QByteArray_fromPercentEncoding);
	RING_API_REGISTER("qbytearray_fromrawdata",ring_QByteArray_fromRawData);
	RING_API_REGISTER("qbytearray_number",ring_QByteArray_number);
	RING_API_REGISTER("qiodevice_errorstring",ring_QIODevice_errorString);
	RING_API_REGISTER("qiodevice_getchar",ring_QIODevice_getChar);
	RING_API_REGISTER("qiodevice_isopen",ring_QIODevice_isOpen);
	RING_API_REGISTER("qiodevice_isreadable",ring_QIODevice_isReadable);
	RING_API_REGISTER("qiodevice_istextmodeenabled",ring_QIODevice_isTextModeEnabled);
	RING_API_REGISTER("qiodevice_iswritable",ring_QIODevice_isWritable);
	RING_API_REGISTER("qiodevice_openmode",ring_QIODevice_openMode);
	RING_API_REGISTER("qiodevice_peek",ring_QIODevice_peek);
	RING_API_REGISTER("qiodevice_putchar",ring_QIODevice_putChar);
	RING_API_REGISTER("qiodevice_read",ring_QIODevice_read);
	RING_API_REGISTER("qiodevice_readall",ring_QIODevice_readAll);
	RING_API_REGISTER("qiodevice_readline",ring_QIODevice_readLine);
	RING_API_REGISTER("qiodevice_settextmodeenabled",ring_QIODevice_setTextModeEnabled);
	RING_API_REGISTER("qiodevice_ungetchar",ring_QIODevice_ungetChar);
	RING_API_REGISTER("qiodevice_write",ring_QIODevice_write);
	RING_API_REGISTER("qiodevice_atend",ring_QIODevice_atEnd);
	RING_API_REGISTER("qiodevice_canreadline",ring_QIODevice_canReadLine);
	RING_API_REGISTER("qiodevice_close",ring_QIODevice_close);
	RING_API_REGISTER("qiodevice_open",ring_QIODevice_open);
	RING_API_REGISTER("qiodevice_pos",ring_QIODevice_pos);
	RING_API_REGISTER("qiodevice_seek",ring_QIODevice_seek);
	RING_API_REGISTER("qiodevice_size",ring_QIODevice_size);
	RING_API_REGISTER("qiodevice_setabouttocloseevent",ring_QIODevice_setaboutToCloseEvent);
	RING_API_REGISTER("qiodevice_setbyteswrittenevent",ring_QIODevice_setbytesWrittenEvent);
	RING_API_REGISTER("qiodevice_setreadchannelfinishedevent",ring_QIODevice_setreadChannelFinishedEvent);
	RING_API_REGISTER("qiodevice_setreadyreadevent",ring_QIODevice_setreadyReadEvent);
	RING_API_REGISTER("qiodevice_getabouttocloseevent",ring_QIODevice_getaboutToCloseEvent);
	RING_API_REGISTER("qiodevice_getbyteswrittenevent",ring_QIODevice_getbytesWrittenEvent);
	RING_API_REGISTER("qiodevice_getreadchannelfinishedevent",ring_QIODevice_getreadChannelFinishedEvent);
	RING_API_REGISTER("qiodevice_getreadyreadevent",ring_QIODevice_getreadyReadEvent);
	RING_API_REGISTER("qfileinfo_absolutedir",ring_QFileInfo_absoluteDir);
	RING_API_REGISTER("qfileinfo_absolutefilepath",ring_QFileInfo_absoluteFilePath);
	RING_API_REGISTER("qfileinfo_absolutepath",ring_QFileInfo_absolutePath);
	RING_API_REGISTER("qfileinfo_basename",ring_QFileInfo_baseName);
	RING_API_REGISTER("qfileinfo_bundlename",ring_QFileInfo_bundleName);
	RING_API_REGISTER("qfileinfo_caching",ring_QFileInfo_caching);
	RING_API_REGISTER("qfileinfo_canonicalfilepath",ring_QFileInfo_canonicalFilePath);
	RING_API_REGISTER("qfileinfo_canonicalpath",ring_QFileInfo_canonicalPath);
	RING_API_REGISTER("qfileinfo_completebasename",ring_QFileInfo_completeBaseName);
	RING_API_REGISTER("qfileinfo_completesuffix",ring_QFileInfo_completeSuffix);
	RING_API_REGISTER("qfileinfo_dir",ring_QFileInfo_dir);
	RING_API_REGISTER("qfileinfo_exists",ring_QFileInfo_exists);
	RING_API_REGISTER("qfileinfo_filename",ring_QFileInfo_fileName);
	RING_API_REGISTER("qfileinfo_filepath",ring_QFileInfo_filePath);
	RING_API_REGISTER("qfileinfo_group",ring_QFileInfo_group);
	RING_API_REGISTER("qfileinfo_groupid",ring_QFileInfo_groupId);
	RING_API_REGISTER("qfileinfo_isabsolute",ring_QFileInfo_isAbsolute);
	RING_API_REGISTER("qfileinfo_isbundle",ring_QFileInfo_isBundle);
	RING_API_REGISTER("qfileinfo_isdir",ring_QFileInfo_isDir);
	RING_API_REGISTER("qfileinfo_isexecutable",ring_QFileInfo_isExecutable);
	RING_API_REGISTER("qfileinfo_isfile",ring_QFileInfo_isFile);
	RING_API_REGISTER("qfileinfo_ishidden",ring_QFileInfo_isHidden);
	RING_API_REGISTER("qfileinfo_isnativepath",ring_QFileInfo_isNativePath);
	RING_API_REGISTER("qfileinfo_isreadable",ring_QFileInfo_isReadable);
	RING_API_REGISTER("qfileinfo_isrelative",ring_QFileInfo_isRelative);
	RING_API_REGISTER("qfileinfo_isroot",ring_QFileInfo_isRoot);
	RING_API_REGISTER("qfileinfo_issymlink",ring_QFileInfo_isSymLink);
	RING_API_REGISTER("qfileinfo_iswritable",ring_QFileInfo_isWritable);
	RING_API_REGISTER("qfileinfo_lastmodified",ring_QFileInfo_lastModified);
	RING_API_REGISTER("qfileinfo_lastread",ring_QFileInfo_lastRead);
	RING_API_REGISTER("qfileinfo_makeabsolute",ring_QFileInfo_makeAbsolute);
	RING_API_REGISTER("qfileinfo_owner",ring_QFileInfo_owner);
	RING_API_REGISTER("qfileinfo_ownerid",ring_QFileInfo_ownerId);
	RING_API_REGISTER("qfileinfo_path",ring_QFileInfo_path);
	RING_API_REGISTER("qfileinfo_permission",ring_QFileInfo_permission);
	RING_API_REGISTER("qfileinfo_permissions",ring_QFileInfo_permissions);
	RING_API_REGISTER("qfileinfo_refresh",ring_QFileInfo_refresh);
	RING_API_REGISTER("qfileinfo_setcaching",ring_QFileInfo_setCaching);
	RING_API_REGISTER("qfileinfo_setfile",ring_QFileInfo_setFile);
	RING_API_REGISTER("qfileinfo_size",ring_QFileInfo_size);
	RING_API_REGISTER("qfileinfo_suffix",ring_QFileInfo_suffix);
	RING_API_REGISTER("qfileinfo_swap",ring_QFileInfo_swap);
	RING_API_REGISTER("qfileinfo_symlinktarget",ring_QFileInfo_symLinkTarget);
	RING_API_REGISTER("qstringlist_join",ring_QStringList_join);
	RING_API_REGISTER("qstringlist_sort",ring_QStringList_sort);
	RING_API_REGISTER("qstringlist_removeduplicates",ring_QStringList_removeDuplicates);
	RING_API_REGISTER("qstringlist_filter",ring_QStringList_filter);
	RING_API_REGISTER("qstringlist_replaceinstrings",ring_QStringList_replaceInStrings);
	RING_API_REGISTER("qstringlist_append",ring_QStringList_append);
	RING_API_REGISTER("qstringlist_at",ring_QStringList_at);
	RING_API_REGISTER("qstringlist_back",ring_QStringList_back);
	RING_API_REGISTER("qstringlist_clear",ring_QStringList_clear);
	RING_API_REGISTER("qstringlist_contains",ring_QStringList_contains);
	RING_API_REGISTER("qstringlist_count",ring_QStringList_count);
	RING_API_REGISTER("qstringlist_empty",ring_QStringList_empty);
	RING_API_REGISTER("qstringlist_endswith",ring_QStringList_endsWith);
	RING_API_REGISTER("qstringlist_first",ring_QStringList_first);
	RING_API_REGISTER("qstringlist_front",ring_QStringList_front);
	RING_API_REGISTER("qstringlist_indexof",ring_QStringList_indexOf);
	RING_API_REGISTER("qstringlist_insert",ring_QStringList_insert);
	RING_API_REGISTER("qstringlist_isempty",ring_QStringList_isEmpty);
	RING_API_REGISTER("qstringlist_last",ring_QStringList_last);
	RING_API_REGISTER("qstringlist_lastindexof",ring_QStringList_lastIndexOf);
	RING_API_REGISTER("qstringlist_length",ring_QStringList_length);
	RING_API_REGISTER("qstringlist_move",ring_QStringList_move);
	RING_API_REGISTER("qstringlist_pop_back",ring_QStringList_pop_back);
	RING_API_REGISTER("qstringlist_pop_front",ring_QStringList_pop_front);
	RING_API_REGISTER("qstringlist_prepend",ring_QStringList_prepend);
	RING_API_REGISTER("qstringlist_push_back",ring_QStringList_push_back);
	RING_API_REGISTER("qstringlist_push_front",ring_QStringList_push_front);
	RING_API_REGISTER("qstringlist_removeall",ring_QStringList_removeAll);
	RING_API_REGISTER("qstringlist_removeat",ring_QStringList_removeAt);
	RING_API_REGISTER("qstringlist_removefirst",ring_QStringList_removeFirst);
	RING_API_REGISTER("qstringlist_removelast",ring_QStringList_removeLast);
	RING_API_REGISTER("qstringlist_removeone",ring_QStringList_removeOne);
	RING_API_REGISTER("qstringlist_replace",ring_QStringList_replace);
	RING_API_REGISTER("qstringlist_reserve",ring_QStringList_reserve);
	RING_API_REGISTER("qstringlist_size",ring_QStringList_size);
	RING_API_REGISTER("qstringlist_startswith",ring_QStringList_startsWith);
	RING_API_REGISTER("qstringlist_takeat",ring_QStringList_takeAt);
	RING_API_REGISTER("qstringlist_takefirst",ring_QStringList_takeFirst);
	RING_API_REGISTER("qstringlist_takelast",ring_QStringList_takeLast);
	RING_API_REGISTER("qstringlist_value",ring_QStringList_value);
	RING_API_REGISTER("qrect_adjust",ring_QRect_adjust);
	RING_API_REGISTER("qrect_adjusted",ring_QRect_adjusted);
	RING_API_REGISTER("qrect_bottom",ring_QRect_bottom);
	RING_API_REGISTER("qrect_bottomleft",ring_QRect_bottomLeft);
	RING_API_REGISTER("qrect_bottomright",ring_QRect_bottomRight);
	RING_API_REGISTER("qrect_center",ring_QRect_center);
	RING_API_REGISTER("qrect_contains",ring_QRect_contains);
	RING_API_REGISTER("qrect_getcoords",ring_QRect_getCoords);
	RING_API_REGISTER("qrect_getrect",ring_QRect_getRect);
	RING_API_REGISTER("qrect_height",ring_QRect_height);
	RING_API_REGISTER("qrect_intersected",ring_QRect_intersected);
	RING_API_REGISTER("qrect_intersects",ring_QRect_intersects);
	RING_API_REGISTER("qrect_isempty",ring_QRect_isEmpty);
	RING_API_REGISTER("qrect_isnull",ring_QRect_isNull);
	RING_API_REGISTER("qrect_isvalid",ring_QRect_isValid);
	RING_API_REGISTER("qrect_left",ring_QRect_left);
	RING_API_REGISTER("qrect_movebottom",ring_QRect_moveBottom);
	RING_API_REGISTER("qrect_movebottomleft",ring_QRect_moveBottomLeft);
	RING_API_REGISTER("qrect_movebottomright",ring_QRect_moveBottomRight);
	RING_API_REGISTER("qrect_movecenter",ring_QRect_moveCenter);
	RING_API_REGISTER("qrect_moveleft",ring_QRect_moveLeft);
	RING_API_REGISTER("qrect_moveright",ring_QRect_moveRight);
	RING_API_REGISTER("qrect_moveto",ring_QRect_moveTo);
	RING_API_REGISTER("qrect_movetop",ring_QRect_moveTop);
	RING_API_REGISTER("qrect_movetopleft",ring_QRect_moveTopLeft);
	RING_API_REGISTER("qrect_movetopright",ring_QRect_moveTopRight);
	RING_API_REGISTER("qrect_normalized",ring_QRect_normalized);
	RING_API_REGISTER("qrect_right",ring_QRect_right);
	RING_API_REGISTER("qrect_setbottom",ring_QRect_setBottom);
	RING_API_REGISTER("qrect_setbottomleft",ring_QRect_setBottomLeft);
	RING_API_REGISTER("qrect_setbottomright",ring_QRect_setBottomRight);
	RING_API_REGISTER("qrect_setcoords",ring_QRect_setCoords);
	RING_API_REGISTER("qrect_setheight",ring_QRect_setHeight);
	RING_API_REGISTER("qrect_setleft",ring_QRect_setLeft);
	RING_API_REGISTER("qrect_setrect",ring_QRect_setRect);
	RING_API_REGISTER("qrect_setright",ring_QRect_setRight);
	RING_API_REGISTER("qrect_setsize",ring_QRect_setSize);
	RING_API_REGISTER("qrect_settop",ring_QRect_setTop);
	RING_API_REGISTER("qrect_settopleft",ring_QRect_setTopLeft);
	RING_API_REGISTER("qrect_settopright",ring_QRect_setTopRight);
	RING_API_REGISTER("qrect_setwidth",ring_QRect_setWidth);
	RING_API_REGISTER("qrect_setx",ring_QRect_setX);
	RING_API_REGISTER("qrect_sety",ring_QRect_setY);
	RING_API_REGISTER("qrect_size",ring_QRect_size);
	RING_API_REGISTER("qrect_top",ring_QRect_top);
	RING_API_REGISTER("qrect_topleft",ring_QRect_topLeft);
	RING_API_REGISTER("qrect_topright",ring_QRect_topRight);
	RING_API_REGISTER("qrect_translate",ring_QRect_translate);
	RING_API_REGISTER("qrect_translated",ring_QRect_translated);
	RING_API_REGISTER("qrect_united",ring_QRect_united);
	RING_API_REGISTER("qrect_width",ring_QRect_width);
	RING_API_REGISTER("qrect_x",ring_QRect_x);
	RING_API_REGISTER("qrect_y",ring_QRect_y);
	RING_API_REGISTER("qtime_addmsecs",ring_QTime_addMSecs);
	RING_API_REGISTER("qtime_addsecs",ring_QTime_addSecs);
	RING_API_REGISTER("qtime_hour",ring_QTime_hour);
	RING_API_REGISTER("qtime_isnull",ring_QTime_isNull);
	RING_API_REGISTER("qtime_isvalid",ring_QTime_isValid);
	RING_API_REGISTER("qtime_minute",ring_QTime_minute);
	RING_API_REGISTER("qtime_msec",ring_QTime_msec);
	RING_API_REGISTER("qtime_msecssincestartofday",ring_QTime_msecsSinceStartOfDay);
	RING_API_REGISTER("qtime_msecsto",ring_QTime_msecsTo);
	RING_API_REGISTER("qtime_second",ring_QTime_second);
	RING_API_REGISTER("qtime_secsto",ring_QTime_secsTo);
	RING_API_REGISTER("qtime_sethms",ring_QTime_setHMS);
	RING_API_REGISTER("qtime_tostring",ring_QTime_toString);
	RING_API_REGISTER("qtime_currenttime",ring_QTime_currentTime);
	RING_API_REGISTER("qtime_frommsecssincestartofday",ring_QTime_fromMSecsSinceStartOfDay);
	RING_API_REGISTER("qtime_fromstring",ring_QTime_fromString);
	RING_API_REGISTER("qdate_adddays",ring_QDate_addDays);
	RING_API_REGISTER("qdate_addmonths",ring_QDate_addMonths);
	RING_API_REGISTER("qdate_addyears",ring_QDate_addYears);
	RING_API_REGISTER("qdate_day",ring_QDate_day);
	RING_API_REGISTER("qdate_dayofweek",ring_QDate_dayOfWeek);
	RING_API_REGISTER("qdate_dayofyear",ring_QDate_dayOfYear);
	RING_API_REGISTER("qdate_daysinmonth",ring_QDate_daysInMonth);
	RING_API_REGISTER("qdate_daysinyear",ring_QDate_daysInYear);
	RING_API_REGISTER("qdate_daysto",ring_QDate_daysTo);
	RING_API_REGISTER("qdate_getdate",ring_QDate_getDate);
	RING_API_REGISTER("qdate_isnull",ring_QDate_isNull);
	RING_API_REGISTER("qdate_isvalid",ring_QDate_isValid);
	RING_API_REGISTER("qdate_month",ring_QDate_month);
	RING_API_REGISTER("qdate_setdate",ring_QDate_setDate);
	RING_API_REGISTER("qdate_tojulianday",ring_QDate_toJulianDay);
	RING_API_REGISTER("qdate_tostring",ring_QDate_toString);
	RING_API_REGISTER("qdate_weeknumber",ring_QDate_weekNumber);
	RING_API_REGISTER("qdate_year",ring_QDate_year);
	RING_API_REGISTER("qdate_currentdate",ring_QDate_currentDate);
	RING_API_REGISTER("qdate_fromjulianday",ring_QDate_fromJulianDay);
	RING_API_REGISTER("qdate_fromstring",ring_QDate_fromString);
	RING_API_REGISTER("qdate_isleapyear",ring_QDate_isLeapYear);
	RING_API_REGISTER("qtextcodec_codecforname",ring_QTextCodec_codecForName);
	RING_API_REGISTER("qtextcodec_setcodecforlocale",ring_QTextCodec_setCodecForLocale);
	RING_API_REGISTER("qvariant_canconvert",ring_QVariant_canConvert);
	RING_API_REGISTER("qvariant_clear",ring_QVariant_clear);
	RING_API_REGISTER("qvariant_convert",ring_QVariant_convert);
	RING_API_REGISTER("qvariant_isnull",ring_QVariant_isNull);
	RING_API_REGISTER("qvariant_isvalid",ring_QVariant_isValid);
	RING_API_REGISTER("qvariant_swap",ring_QVariant_swap);
	RING_API_REGISTER("qvariant_tobitarray",ring_QVariant_toBitArray);
	RING_API_REGISTER("qvariant_tobool",ring_QVariant_toBool);
	RING_API_REGISTER("qvariant_tobytearray",ring_QVariant_toByteArray);
	RING_API_REGISTER("qvariant_tochar",ring_QVariant_toChar);
	RING_API_REGISTER("qvariant_todate",ring_QVariant_toDate);
	RING_API_REGISTER("qvariant_todatetime",ring_QVariant_toDateTime);
	RING_API_REGISTER("qvariant_todouble",ring_QVariant_toDouble);
	RING_API_REGISTER("qvariant_toeasingcurve",ring_QVariant_toEasingCurve);
	RING_API_REGISTER("qvariant_tofloat",ring_QVariant_toFloat);
	RING_API_REGISTER("qvariant_toint",ring_QVariant_toInt);
	RING_API_REGISTER("qvariant_tojsonarray",ring_QVariant_toJsonArray);
	RING_API_REGISTER("qvariant_tojsondocument",ring_QVariant_toJsonDocument);
	RING_API_REGISTER("qvariant_tojsonobject",ring_QVariant_toJsonObject);
	RING_API_REGISTER("qvariant_tojsonvalue",ring_QVariant_toJsonValue);
	RING_API_REGISTER("qvariant_toline",ring_QVariant_toLine);
	RING_API_REGISTER("qvariant_tolinef",ring_QVariant_toLineF);
	RING_API_REGISTER("qvariant_tolocale",ring_QVariant_toLocale);
	RING_API_REGISTER("qvariant_tolonglong",ring_QVariant_toLongLong);
	RING_API_REGISTER("qvariant_tomodelindex",ring_QVariant_toModelIndex);
	RING_API_REGISTER("qvariant_topoint",ring_QVariant_toPoint);
	RING_API_REGISTER("qvariant_topointf",ring_QVariant_toPointF);
	RING_API_REGISTER("qvariant_toreal",ring_QVariant_toReal);
	RING_API_REGISTER("qvariant_torect",ring_QVariant_toRect);
	RING_API_REGISTER("qvariant_torectf",ring_QVariant_toRectF);
	RING_API_REGISTER("qvariant_toregexp",ring_QVariant_toRegExp);
	RING_API_REGISTER("qvariant_toregularexpression",ring_QVariant_toRegularExpression);
	RING_API_REGISTER("qvariant_tosize",ring_QVariant_toSize);
	RING_API_REGISTER("qvariant_tosizef",ring_QVariant_toSizeF);
	RING_API_REGISTER("qvariant_tostringlist",ring_QVariant_toStringList);
	RING_API_REGISTER("qvariant_totime",ring_QVariant_toTime);
	RING_API_REGISTER("qvariant_touint",ring_QVariant_toUInt);
	RING_API_REGISTER("qvariant_toulonglong",ring_QVariant_toULongLong);
	RING_API_REGISTER("qvariant_tourl",ring_QVariant_toUrl);
	RING_API_REGISTER("qvariant_touuid",ring_QVariant_toUuid);
	RING_API_REGISTER("qvariant_type",ring_QVariant_type);
	RING_API_REGISTER("qvariant_typename",ring_QVariant_typeName);
	RING_API_REGISTER("qvariant_usertype",ring_QVariant_userType);
	RING_API_REGISTER("qvariant_tostring",ring_QVariant_toString);
	RING_API_REGISTER("qxmlstreamreader_adddata",ring_QXmlStreamReader_addData);
	RING_API_REGISTER("qxmlstreamreader_adddata_2",ring_QXmlStreamReader_addData_2);
	RING_API_REGISTER("qxmlstreamreader_adddata_3",ring_QXmlStreamReader_addData_3);
	RING_API_REGISTER("qxmlstreamreader_addextranamespacedeclaration",ring_QXmlStreamReader_addExtraNamespaceDeclaration);
	RING_API_REGISTER("qxmlstreamreader_addextranamespacedeclarations",ring_QXmlStreamReader_addExtraNamespaceDeclarations);
	RING_API_REGISTER("qxmlstreamreader_atend",ring_QXmlStreamReader_atEnd);
	RING_API_REGISTER("qxmlstreamreader_attributes",ring_QXmlStreamReader_attributes);
	RING_API_REGISTER("qxmlstreamreader_characteroffset",ring_QXmlStreamReader_characterOffset);
	RING_API_REGISTER("qxmlstreamreader_clear",ring_QXmlStreamReader_clear);
	RING_API_REGISTER("qxmlstreamreader_columnnumber",ring_QXmlStreamReader_columnNumber);
	RING_API_REGISTER("qxmlstreamreader_device",ring_QXmlStreamReader_device);
	RING_API_REGISTER("qxmlstreamreader_documentencoding",ring_QXmlStreamReader_documentEncoding);
	RING_API_REGISTER("qxmlstreamreader_documentversion",ring_QXmlStreamReader_documentVersion);
	RING_API_REGISTER("qxmlstreamreader_dtdname",ring_QXmlStreamReader_dtdName);
	RING_API_REGISTER("qxmlstreamreader_dtdpublicid",ring_QXmlStreamReader_dtdPublicId);
	RING_API_REGISTER("qxmlstreamreader_dtdsystemid",ring_QXmlStreamReader_dtdSystemId);
	RING_API_REGISTER("qxmlstreamreader_entitydeclarations",ring_QXmlStreamReader_entityDeclarations);
	RING_API_REGISTER("qxmlstreamreader_entityresolver",ring_QXmlStreamReader_entityResolver);
	RING_API_REGISTER("qxmlstreamreader_error",ring_QXmlStreamReader_error);
	RING_API_REGISTER("qxmlstreamreader_errorstring",ring_QXmlStreamReader_errorString);
	RING_API_REGISTER("qxmlstreamreader_haserror",ring_QXmlStreamReader_hasError);
	RING_API_REGISTER("qxmlstreamreader_iscdata",ring_QXmlStreamReader_isCDATA);
	RING_API_REGISTER("qxmlstreamreader_ischaracters",ring_QXmlStreamReader_isCharacters);
	RING_API_REGISTER("qxmlstreamreader_iscomment",ring_QXmlStreamReader_isComment);
	RING_API_REGISTER("qxmlstreamreader_isdtd",ring_QXmlStreamReader_isDTD);
	RING_API_REGISTER("qxmlstreamreader_isenddocument",ring_QXmlStreamReader_isEndDocument);
	RING_API_REGISTER("qxmlstreamreader_isendelement",ring_QXmlStreamReader_isEndElement);
	RING_API_REGISTER("qxmlstreamreader_isentityreference",ring_QXmlStreamReader_isEntityReference);
	RING_API_REGISTER("qxmlstreamreader_isprocessinginstruction",ring_QXmlStreamReader_isProcessingInstruction);
	RING_API_REGISTER("qxmlstreamreader_isstandalonedocument",ring_QXmlStreamReader_isStandaloneDocument);
	RING_API_REGISTER("qxmlstreamreader_isstartdocument",ring_QXmlStreamReader_isStartDocument);
	RING_API_REGISTER("qxmlstreamreader_isstartelement",ring_QXmlStreamReader_isStartElement);
	RING_API_REGISTER("qxmlstreamreader_iswhitespace",ring_QXmlStreamReader_isWhitespace);
	RING_API_REGISTER("qxmlstreamreader_linenumber",ring_QXmlStreamReader_lineNumber);
	RING_API_REGISTER("qxmlstreamreader_name",ring_QXmlStreamReader_name);
	RING_API_REGISTER("qxmlstreamreader_namespacedeclarations",ring_QXmlStreamReader_namespaceDeclarations);
	RING_API_REGISTER("qxmlstreamreader_namespaceprocessing",ring_QXmlStreamReader_namespaceProcessing);
	RING_API_REGISTER("qxmlstreamreader_namespaceuri",ring_QXmlStreamReader_namespaceUri);
	RING_API_REGISTER("qxmlstreamreader_notationdeclarations",ring_QXmlStreamReader_notationDeclarations);
	RING_API_REGISTER("qxmlstreamreader_prefix",ring_QXmlStreamReader_prefix);
	RING_API_REGISTER("qxmlstreamreader_processinginstructiondata",ring_QXmlStreamReader_processingInstructionData);
	RING_API_REGISTER("qxmlstreamreader_processinginstructiontarget",ring_QXmlStreamReader_processingInstructionTarget);
	RING_API_REGISTER("qxmlstreamreader_qualifiedname",ring_QXmlStreamReader_qualifiedName);
	RING_API_REGISTER("qxmlstreamreader_raiseerror",ring_QXmlStreamReader_raiseError);
	RING_API_REGISTER("qxmlstreamreader_readelementtext",ring_QXmlStreamReader_readElementText);
	RING_API_REGISTER("qxmlstreamreader_readnext",ring_QXmlStreamReader_readNext);
	RING_API_REGISTER("qxmlstreamreader_readnextstartelement",ring_QXmlStreamReader_readNextStartElement);
	RING_API_REGISTER("qxmlstreamreader_setdevice",ring_QXmlStreamReader_setDevice);
	RING_API_REGISTER("qxmlstreamreader_setentityresolver",ring_QXmlStreamReader_setEntityResolver);
	RING_API_REGISTER("qxmlstreamreader_setnamespaceprocessing",ring_QXmlStreamReader_setNamespaceProcessing);
	RING_API_REGISTER("qxmlstreamreader_skipcurrentelement",ring_QXmlStreamReader_skipCurrentElement);
	RING_API_REGISTER("qxmlstreamreader_text",ring_QXmlStreamReader_text);
	RING_API_REGISTER("qxmlstreamreader_tokenstring",ring_QXmlStreamReader_tokenString);
	RING_API_REGISTER("qxmlstreamreader_tokentype",ring_QXmlStreamReader_tokenType);
	RING_API_REGISTER("qxmlstreamwriter_autoformatting",ring_QXmlStreamWriter_autoFormatting);
	RING_API_REGISTER("qxmlstreamwriter_autoformattingindent",ring_QXmlStreamWriter_autoFormattingIndent);
	RING_API_REGISTER("qxmlstreamwriter_codec",ring_QXmlStreamWriter_codec);
	RING_API_REGISTER("qxmlstreamwriter_device",ring_QXmlStreamWriter_device);
	RING_API_REGISTER("qxmlstreamwriter_haserror",ring_QXmlStreamWriter_hasError);
	RING_API_REGISTER("qxmlstreamwriter_setautoformatting",ring_QXmlStreamWriter_setAutoFormatting);
	RING_API_REGISTER("qxmlstreamwriter_setautoformattingindent",ring_QXmlStreamWriter_setAutoFormattingIndent);
	RING_API_REGISTER("qxmlstreamwriter_setcodec",ring_QXmlStreamWriter_setCodec);
	RING_API_REGISTER("qxmlstreamwriter_setcodec_2",ring_QXmlStreamWriter_setCodec_2);
	RING_API_REGISTER("qxmlstreamwriter_setdevice",ring_QXmlStreamWriter_setDevice);
	RING_API_REGISTER("qxmlstreamwriter_writeattribute",ring_QXmlStreamWriter_writeAttribute);
	RING_API_REGISTER("qxmlstreamwriter_writeattribute_2",ring_QXmlStreamWriter_writeAttribute_2);
	RING_API_REGISTER("qxmlstreamwriter_writeattribute_3",ring_QXmlStreamWriter_writeAttribute_3);
	RING_API_REGISTER("qxmlstreamwriter_writeattributes",ring_QXmlStreamWriter_writeAttributes);
	RING_API_REGISTER("qxmlstreamwriter_writecdata",ring_QXmlStreamWriter_writeCDATA);
	RING_API_REGISTER("qxmlstreamwriter_writecharacters",ring_QXmlStreamWriter_writeCharacters);
	RING_API_REGISTER("qxmlstreamwriter_writecomment",ring_QXmlStreamWriter_writeComment);
	RING_API_REGISTER("qxmlstreamwriter_writecurrenttoken",ring_QXmlStreamWriter_writeCurrentToken);
	RING_API_REGISTER("qxmlstreamwriter_writedtd",ring_QXmlStreamWriter_writeDTD);
	RING_API_REGISTER("qxmlstreamwriter_writedefaultnamespace",ring_QXmlStreamWriter_writeDefaultNamespace);
	RING_API_REGISTER("qxmlstreamwriter_writeemptyelement",ring_QXmlStreamWriter_writeEmptyElement);
	RING_API_REGISTER("qxmlstreamwriter_writeemptyelement_2",ring_QXmlStreamWriter_writeEmptyElement_2);
	RING_API_REGISTER("qxmlstreamwriter_writeenddocument",ring_QXmlStreamWriter_writeEndDocument);
	RING_API_REGISTER("qxmlstreamwriter_writeendelement",ring_QXmlStreamWriter_writeEndElement);
	RING_API_REGISTER("qxmlstreamwriter_writeentityreference",ring_QXmlStreamWriter_writeEntityReference);
	RING_API_REGISTER("qxmlstreamwriter_writenamespace",ring_QXmlStreamWriter_writeNamespace);
	RING_API_REGISTER("qxmlstreamwriter_writeprocessinginstruction",ring_QXmlStreamWriter_writeProcessingInstruction);
	RING_API_REGISTER("qxmlstreamwriter_writestartdocument",ring_QXmlStreamWriter_writeStartDocument);
	RING_API_REGISTER("qxmlstreamwriter_writestartdocument_2",ring_QXmlStreamWriter_writeStartDocument_2);
	RING_API_REGISTER("qxmlstreamwriter_writestartdocument_3",ring_QXmlStreamWriter_writeStartDocument_3);
	RING_API_REGISTER("qxmlstreamwriter_writestartelement",ring_QXmlStreamWriter_writeStartElement);
	RING_API_REGISTER("qxmlstreamwriter_writestartelement_2",ring_QXmlStreamWriter_writeStartElement_2);
	RING_API_REGISTER("qxmlstreamwriter_writetextelement",ring_QXmlStreamWriter_writeTextElement);
	RING_API_REGISTER("qxmlstreamwriter_writetextelement_2",ring_QXmlStreamWriter_writeTextElement_2);
	RING_API_REGISTER("qxmlstreamnotationdeclaration_name",ring_QXmlStreamNotationDeclaration_name);
	RING_API_REGISTER("qxmlstreamnotationdeclaration_publicid",ring_QXmlStreamNotationDeclaration_publicId);
	RING_API_REGISTER("qxmlstreamnotationdeclaration_systemid",ring_QXmlStreamNotationDeclaration_systemId);
	RING_API_REGISTER("qxmlstreamnamespacedeclaration_namespaceuri",ring_QXmlStreamNamespaceDeclaration_namespaceUri);
	RING_API_REGISTER("qxmlstreamnamespacedeclaration_prefix",ring_QXmlStreamNamespaceDeclaration_prefix);
	RING_API_REGISTER("qxmlstreamentitydeclaration_name",ring_QXmlStreamEntityDeclaration_name);
	RING_API_REGISTER("qxmlstreamentitydeclaration_notationname",ring_QXmlStreamEntityDeclaration_notationName);
	RING_API_REGISTER("qxmlstreamentitydeclaration_publicid",ring_QXmlStreamEntityDeclaration_publicId);
	RING_API_REGISTER("qxmlstreamentitydeclaration_systemid",ring_QXmlStreamEntityDeclaration_systemId);
	RING_API_REGISTER("qxmlstreamentitydeclaration_value",ring_QXmlStreamEntityDeclaration_value);
	RING_API_REGISTER("qxmlstreamattributes_append",ring_QXmlStreamAttributes_append);
	RING_API_REGISTER("qxmlstreamattributes_append_2",ring_QXmlStreamAttributes_append_2);
	RING_API_REGISTER("qxmlstreamattributes_hasattribute",ring_QXmlStreamAttributes_hasAttribute);
	RING_API_REGISTER("qxmlstreamattributes_hasattribute_2",ring_QXmlStreamAttributes_hasAttribute_2);
	RING_API_REGISTER("qxmlstreamattributes_hasattribute_3",ring_QXmlStreamAttributes_hasAttribute_3);
	RING_API_REGISTER("qxmlstreamattributes_value",ring_QXmlStreamAttributes_value);
	RING_API_REGISTER("qxmlstreamattributes_value_2",ring_QXmlStreamAttributes_value_2);
	RING_API_REGISTER("qxmlstreamattributes_value_3",ring_QXmlStreamAttributes_value_3);
	RING_API_REGISTER("qxmlstreamattributes_value_4",ring_QXmlStreamAttributes_value_4);
	RING_API_REGISTER("qxmlstreamattributes_value_5",ring_QXmlStreamAttributes_value_5);
	RING_API_REGISTER("qxmlstreamattribute_isdefault",ring_QXmlStreamAttribute_isDefault);
	RING_API_REGISTER("qxmlstreamattribute_name",ring_QXmlStreamAttribute_name);
	RING_API_REGISTER("qxmlstreamattribute_namespaceuri",ring_QXmlStreamAttribute_namespaceUri);
	RING_API_REGISTER("qxmlstreamattribute_prefix",ring_QXmlStreamAttribute_prefix);
	RING_API_REGISTER("qxmlstreamattribute_qualifiedname",ring_QXmlStreamAttribute_qualifiedName);
	RING_API_REGISTER("qxmlstreamattribute_value",ring_QXmlStreamAttribute_value);
	RING_API_REGISTER("qregularexpression_capturecount",ring_QRegularExpression_captureCount);
	RING_API_REGISTER("qregularexpression_errorstring",ring_QRegularExpression_errorString);
	RING_API_REGISTER("qregularexpression_globalmatch",ring_QRegularExpression_globalMatch);
	RING_API_REGISTER("qregularexpression_isvalid",ring_QRegularExpression_isValid);
	RING_API_REGISTER("qregularexpression_match",ring_QRegularExpression_match);
	RING_API_REGISTER("qregularexpression_namedcapturegroups",ring_QRegularExpression_namedCaptureGroups);
	RING_API_REGISTER("qregularexpression_pattern",ring_QRegularExpression_pattern);
	RING_API_REGISTER("qregularexpression_patternerroroffset",ring_QRegularExpression_patternErrorOffset);
	RING_API_REGISTER("qregularexpression_patternoptions",ring_QRegularExpression_patternOptions);
	RING_API_REGISTER("qregularexpression_setpattern",ring_QRegularExpression_setPattern);
	RING_API_REGISTER("qregularexpression_setpatternoptions",ring_QRegularExpression_setPatternOptions);
	RING_API_REGISTER("qregularexpression_swap",ring_QRegularExpression_swap);
	RING_API_REGISTER("qregularexpressionmatch_captured",ring_QRegularExpressionMatch_captured);
	RING_API_REGISTER("qregularexpressionmatch_captured_2",ring_QRegularExpressionMatch_captured_2);
	RING_API_REGISTER("qregularexpressionmatch_capturedend",ring_QRegularExpressionMatch_capturedEnd);
	RING_API_REGISTER("qregularexpressionmatch_capturedend_2",ring_QRegularExpressionMatch_capturedEnd_2);
	RING_API_REGISTER("qregularexpressionmatch_capturedlength",ring_QRegularExpressionMatch_capturedLength);
	RING_API_REGISTER("qregularexpressionmatch_capturedlength_2",ring_QRegularExpressionMatch_capturedLength_2);
	RING_API_REGISTER("qregularexpressionmatch_capturedref",ring_QRegularExpressionMatch_capturedRef);
	RING_API_REGISTER("qregularexpressionmatch_capturedref_2",ring_QRegularExpressionMatch_capturedRef_2);
	RING_API_REGISTER("qregularexpressionmatch_capturedstart",ring_QRegularExpressionMatch_capturedStart);
	RING_API_REGISTER("qregularexpressionmatch_capturedstart_2",ring_QRegularExpressionMatch_capturedStart_2);
	RING_API_REGISTER("qregularexpressionmatch_capturedtexts",ring_QRegularExpressionMatch_capturedTexts);
	RING_API_REGISTER("qregularexpressionmatch_hasmatch",ring_QRegularExpressionMatch_hasMatch);
	RING_API_REGISTER("qregularexpressionmatch_haspartialmatch",ring_QRegularExpressionMatch_hasPartialMatch);
	RING_API_REGISTER("qregularexpressionmatch_isvalid",ring_QRegularExpressionMatch_isValid);
	RING_API_REGISTER("qregularexpressionmatch_lastcapturedindex",ring_QRegularExpressionMatch_lastCapturedIndex);
	RING_API_REGISTER("qregularexpressionmatch_matchoptions",ring_QRegularExpressionMatch_matchOptions);
	RING_API_REGISTER("qregularexpressionmatch_matchtype",ring_QRegularExpressionMatch_matchType);
	RING_API_REGISTER("qregularexpressionmatch_regularexpression",ring_QRegularExpressionMatch_regularExpression);
	RING_API_REGISTER("qregularexpressionmatch_swap",ring_QRegularExpressionMatch_swap);
	RING_API_REGISTER("qregularexpressionmatchiterator_hasnext",ring_QRegularExpressionMatchIterator_hasNext);
	RING_API_REGISTER("qregularexpressionmatchiterator_isvalid",ring_QRegularExpressionMatchIterator_isValid);
	RING_API_REGISTER("qregularexpressionmatchiterator_matchoptions",ring_QRegularExpressionMatchIterator_matchOptions);
	RING_API_REGISTER("qregularexpressionmatchiterator_matchtype",ring_QRegularExpressionMatchIterator_matchType);
	RING_API_REGISTER("qregularexpressionmatchiterator_next",ring_QRegularExpressionMatchIterator_next);
	RING_API_REGISTER("qregularexpressionmatchiterator_peeknext",ring_QRegularExpressionMatchIterator_peekNext);
	RING_API_REGISTER("qregularexpressionmatchiterator_regularexpression",ring_QRegularExpressionMatchIterator_regularExpression);
	RING_API_REGISTER("qregularexpressionmatchiterator_swap",ring_QRegularExpressionMatchIterator_swap);
	RING_API_REGISTER("qjsonarray_append",ring_QJsonArray_append);
	RING_API_REGISTER("qjsonarray_at",ring_QJsonArray_at);
	RING_API_REGISTER("qjsonarray_contains",ring_QJsonArray_contains);
	RING_API_REGISTER("qjsonarray_count",ring_QJsonArray_count);
	RING_API_REGISTER("qjsonarray_empty",ring_QJsonArray_empty);
	RING_API_REGISTER("qjsonarray_first",ring_QJsonArray_first);
	RING_API_REGISTER("qjsonarray_insert",ring_QJsonArray_insert);
	RING_API_REGISTER("qjsonarray_isempty",ring_QJsonArray_isEmpty);
	RING_API_REGISTER("qjsonarray_last",ring_QJsonArray_last);
	RING_API_REGISTER("qjsonarray_pop_back",ring_QJsonArray_pop_back);
	RING_API_REGISTER("qjsonarray_pop_front",ring_QJsonArray_pop_front);
	RING_API_REGISTER("qjsonarray_prepend",ring_QJsonArray_prepend);
	RING_API_REGISTER("qjsonarray_push_back",ring_QJsonArray_push_back);
	RING_API_REGISTER("qjsonarray_push_front",ring_QJsonArray_push_front);
	RING_API_REGISTER("qjsonarray_removeat",ring_QJsonArray_removeAt);
	RING_API_REGISTER("qjsonarray_removefirst",ring_QJsonArray_removeFirst);
	RING_API_REGISTER("qjsonarray_removelast",ring_QJsonArray_removeLast);
	RING_API_REGISTER("qjsonarray_replace",ring_QJsonArray_replace);
	RING_API_REGISTER("qjsonarray_size",ring_QJsonArray_size);
	RING_API_REGISTER("qjsonarray_takeat",ring_QJsonArray_takeAt);
	RING_API_REGISTER("qjsonarray_tovariantlist",ring_QJsonArray_toVariantList);
	RING_API_REGISTER("qjsonarray_fromstringlist",ring_QJsonArray_fromStringList);
	RING_API_REGISTER("qjsonarray_fromvariantlist",ring_QJsonArray_fromVariantList);
	RING_API_REGISTER("qjsondocument_array",ring_QJsonDocument_array);
	RING_API_REGISTER("qjsondocument_isarray",ring_QJsonDocument_isArray);
	RING_API_REGISTER("qjsondocument_isempty",ring_QJsonDocument_isEmpty);
	RING_API_REGISTER("qjsondocument_isnull",ring_QJsonDocument_isNull);
	RING_API_REGISTER("qjsondocument_isobject",ring_QJsonDocument_isObject);
	RING_API_REGISTER("qjsondocument_object",ring_QJsonDocument_object);
	RING_API_REGISTER("qjsondocument_setarray",ring_QJsonDocument_setArray);
	RING_API_REGISTER("qjsondocument_setobject",ring_QJsonDocument_setObject);
	RING_API_REGISTER("qjsondocument_tojson",ring_QJsonDocument_toJson);
	RING_API_REGISTER("qjsondocument_tovariant",ring_QJsonDocument_toVariant);
	RING_API_REGISTER("qjsondocument_fromjson",ring_QJsonDocument_fromJson);
	RING_API_REGISTER("qjsondocument_fromvariant",ring_QJsonDocument_fromVariant);
	RING_API_REGISTER("qjsonobject_contains",ring_QJsonObject_contains);
	RING_API_REGISTER("qjsonobject_count",ring_QJsonObject_count);
	RING_API_REGISTER("qjsonobject_empty",ring_QJsonObject_empty);
	RING_API_REGISTER("qjsonobject_isempty",ring_QJsonObject_isEmpty);
	RING_API_REGISTER("qjsonobject_keys",ring_QJsonObject_keys);
	RING_API_REGISTER("qjsonobject_length",ring_QJsonObject_length);
	RING_API_REGISTER("qjsonobject_remove",ring_QJsonObject_remove);
	RING_API_REGISTER("qjsonobject_size",ring_QJsonObject_size);
	RING_API_REGISTER("qjsonobject_take",ring_QJsonObject_take);
	RING_API_REGISTER("qjsonobject_tovariantmap",ring_QJsonObject_toVariantMap);
	RING_API_REGISTER("qjsonobject_value",ring_QJsonObject_value);
	RING_API_REGISTER("qjsonobject_fromvariantmap",ring_QJsonObject_fromVariantMap);
	RING_API_REGISTER("qjsonparseerror_errorstring",ring_QJsonParseError_errorString);
	RING_API_REGISTER("qjsonvalue_isarray",ring_QJsonValue_isArray);
	RING_API_REGISTER("qjsonvalue_isbool",ring_QJsonValue_isBool);
	RING_API_REGISTER("qjsonvalue_isdouble",ring_QJsonValue_isDouble);
	RING_API_REGISTER("qjsonvalue_isnull",ring_QJsonValue_isNull);
	RING_API_REGISTER("qjsonvalue_isobject",ring_QJsonValue_isObject);
	RING_API_REGISTER("qjsonvalue_isstring",ring_QJsonValue_isString);
	RING_API_REGISTER("qjsonvalue_isundefined",ring_QJsonValue_isUndefined);
	RING_API_REGISTER("qjsonvalue_toarray",ring_QJsonValue_toArray);
	RING_API_REGISTER("qjsonvalue_toarray_2",ring_QJsonValue_toArray_2);
	RING_API_REGISTER("qjsonvalue_tobool",ring_QJsonValue_toBool);
	RING_API_REGISTER("qjsonvalue_todouble",ring_QJsonValue_toDouble);
	RING_API_REGISTER("qjsonvalue_toint",ring_QJsonValue_toInt);
	RING_API_REGISTER("qjsonvalue_toobject",ring_QJsonValue_toObject);
	RING_API_REGISTER("qjsonvalue_toobject_2",ring_QJsonValue_toObject_2);
	RING_API_REGISTER("qjsonvalue_tostring",ring_QJsonValue_toString);
	RING_API_REGISTER("qjsonvalue_tovariant",ring_QJsonValue_toVariant);
	RING_API_REGISTER("qjsonvalue_type",ring_QJsonValue_type);
	RING_API_REGISTER("qjsonvalue_fromvariant",ring_QJsonValue_fromVariant);
	RING_API_REGISTER("qpointf_isnull",ring_QPointF_isNull);
	RING_API_REGISTER("qpointf_manhattanlength",ring_QPointF_manhattanLength);
	RING_API_REGISTER("qpointf_rx",ring_QPointF_rx);
	RING_API_REGISTER("qpointf_ry",ring_QPointF_ry);
	RING_API_REGISTER("qpointf_setx",ring_QPointF_setX);
	RING_API_REGISTER("qpointf_sety",ring_QPointF_setY);
	RING_API_REGISTER("qpointf_topoint",ring_QPointF_toPoint);
	RING_API_REGISTER("qpointf_x",ring_QPointF_x);
	RING_API_REGISTER("qpointf_y",ring_QPointF_y);
	RING_API_REGISTER("qpoint_isnull",ring_QPoint_isNull);
	RING_API_REGISTER("qpoint_manhattanlength",ring_QPoint_manhattanLength);
	RING_API_REGISTER("qpoint_rx",ring_QPoint_rx);
	RING_API_REGISTER("qpoint_ry",ring_QPoint_ry);
	RING_API_REGISTER("qpoint_setx",ring_QPoint_setX);
	RING_API_REGISTER("qpoint_sety",ring_QPoint_setY);
	RING_API_REGISTER("qpoint_x",ring_QPoint_x);
	RING_API_REGISTER("qpoint_y",ring_QPoint_y);
	RING_API_REGISTER("qstring2_split",ring_QString2_split);
	RING_API_REGISTER("qstring2_split_2",ring_QString2_split_2);
	RING_API_REGISTER("qstring2_split_3",ring_QString2_split_3);
	RING_API_REGISTER("qstring2_split_4",ring_QString2_split_4);
	RING_API_REGISTER("qstring2_append",ring_QString2_append);
	RING_API_REGISTER("qstring2_append_2",ring_QString2_append_2);
	RING_API_REGISTER("qstring2_toutf8",ring_QString2_toUtf8);
	RING_API_REGISTER("qstring2_tolatin1",ring_QString2_toLatin1);
	RING_API_REGISTER("qstring2_tolocal8bit",ring_QString2_toLocal8Bit);
	RING_API_REGISTER("qstring2_unicode",ring_QString2_unicode);
	RING_API_REGISTER("qstring2_number",ring_QString2_number);
	RING_API_REGISTER("qstring2_count",ring_QString2_count);
	RING_API_REGISTER("qstring2_left",ring_QString2_left);
	RING_API_REGISTER("qstring2_mid",ring_QString2_mid);
	RING_API_REGISTER("qstring2_right",ring_QString2_right);
	RING_API_REGISTER("qstring2_compare",ring_QString2_compare);
	RING_API_REGISTER("qstring2_contains",ring_QString2_contains);
	RING_API_REGISTER("qstring2_indexof",ring_QString2_indexOf);
	RING_API_REGISTER("qstring2_lastindexof",ring_QString2_lastIndexOf);
	RING_API_REGISTER("qstring2_insert",ring_QString2_insert);
	RING_API_REGISTER("qstring2_isrighttoleft",ring_QString2_isRightToLeft);
	RING_API_REGISTER("qstring2_repeated",ring_QString2_repeated);
	RING_API_REGISTER("qstring2_replace",ring_QString2_replace);
	RING_API_REGISTER("qstring2_replace_2",ring_QString2_replace_2);
	RING_API_REGISTER("qstring2_startswith",ring_QString2_startsWith);
	RING_API_REGISTER("qstring2_endswith",ring_QString2_endsWith);
	RING_API_REGISTER("qstring2_tohtmlescaped",ring_QString2_toHtmlEscaped);
	RING_API_REGISTER("qstring2_clear",ring_QString2_clear);
	RING_API_REGISTER("qstring2_isnull",ring_QString2_isNull);
	RING_API_REGISTER("qstring2_resize",ring_QString2_resize);
	RING_API_REGISTER("qstring2_fill",ring_QString2_fill);
	RING_API_REGISTER("qstring2_localeawarecompare",ring_QString2_localeAwareCompare);
	RING_API_REGISTER("qstring2_leftjustified",ring_QString2_leftJustified);
	RING_API_REGISTER("qstring2_rightjustified",ring_QString2_rightJustified);
	RING_API_REGISTER("qstring2_section_1",ring_QString2_section_1);
	RING_API_REGISTER("qstring2_section_2",ring_QString2_section_2);
	RING_API_REGISTER("qstring2_section_3",ring_QString2_section_3);
	RING_API_REGISTER("qstring2_section_4",ring_QString2_section_4);
	RING_API_REGISTER("qstring2_simplified",ring_QString2_simplified);
	RING_API_REGISTER("qstring2_tocasefolded",ring_QString2_toCaseFolded);
	RING_API_REGISTER("qstring2_trimmed",ring_QString2_trimmed);
	RING_API_REGISTER("qstring2_truncate",ring_QString2_truncate);
	RING_API_REGISTER("qstringref_appendto",ring_QStringRef_appendTo);
	RING_API_REGISTER("qstringref_at",ring_QStringRef_at);
	RING_API_REGISTER("qstringref_clear",ring_QStringRef_clear);
	RING_API_REGISTER("qstringref_compare_2",ring_QStringRef_compare_2);
	RING_API_REGISTER("qstringref_compare_3",ring_QStringRef_compare_3);
	RING_API_REGISTER("qstringref_constdata",ring_QStringRef_constData);
	RING_API_REGISTER("qstringref_contains",ring_QStringRef_contains);
	RING_API_REGISTER("qstringref_contains_2",ring_QStringRef_contains_2);
	RING_API_REGISTER("qstringref_contains_3",ring_QStringRef_contains_3);
	RING_API_REGISTER("qstringref_contains_4",ring_QStringRef_contains_4);
	RING_API_REGISTER("qstringref_count",ring_QStringRef_count);
	RING_API_REGISTER("qstringref_count_2",ring_QStringRef_count_2);
	RING_API_REGISTER("qstringref_count_3",ring_QStringRef_count_3);
	RING_API_REGISTER("qstringref_count_4",ring_QStringRef_count_4);
	RING_API_REGISTER("qstringref_data",ring_QStringRef_data);
	RING_API_REGISTER("qstringref_endswith",ring_QStringRef_endsWith);
	RING_API_REGISTER("qstringref_endswith_2",ring_QStringRef_endsWith_2);
	RING_API_REGISTER("qstringref_endswith_3",ring_QStringRef_endsWith_3);
	RING_API_REGISTER("qstringref_endswith_4",ring_QStringRef_endsWith_4);
	RING_API_REGISTER("qstringref_indexof",ring_QStringRef_indexOf);
	RING_API_REGISTER("qstringref_indexof_2",ring_QStringRef_indexOf_2);
	RING_API_REGISTER("qstringref_indexof_3",ring_QStringRef_indexOf_3);
	RING_API_REGISTER("qstringref_indexof_4",ring_QStringRef_indexOf_4);
	RING_API_REGISTER("qstringref_isempty",ring_QStringRef_isEmpty);
	RING_API_REGISTER("qstringref_isnull",ring_QStringRef_isNull);
	RING_API_REGISTER("qstringref_lastindexof",ring_QStringRef_lastIndexOf);
	RING_API_REGISTER("qstringref_lastindexof_2",ring_QStringRef_lastIndexOf_2);
	RING_API_REGISTER("qstringref_lastindexof_3",ring_QStringRef_lastIndexOf_3);
	RING_API_REGISTER("qstringref_lastindexof_4",ring_QStringRef_lastIndexOf_4);
	RING_API_REGISTER("qstringref_length",ring_QStringRef_length);
	RING_API_REGISTER("qstringref_localeawarecompare",ring_QStringRef_localeAwareCompare);
	RING_API_REGISTER("qstringref_localeawarecompare_2",ring_QStringRef_localeAwareCompare_2);
	RING_API_REGISTER("qstringref_position",ring_QStringRef_position);
	RING_API_REGISTER("qstringref_size",ring_QStringRef_size);
	RING_API_REGISTER("qstringref_startswith",ring_QStringRef_startsWith);
	RING_API_REGISTER("qstringref_startswith_2",ring_QStringRef_startsWith_2);
	RING_API_REGISTER("qstringref_startswith_3",ring_QStringRef_startsWith_3);
	RING_API_REGISTER("qstringref_startswith_4",ring_QStringRef_startsWith_4);
	RING_API_REGISTER("qstringref_string",ring_QStringRef_string);
	RING_API_REGISTER("qstringref_tolatin1",ring_QStringRef_toLatin1);
	RING_API_REGISTER("qstringref_tolocal8bit",ring_QStringRef_toLocal8Bit);
	RING_API_REGISTER("qstringref_tostring",ring_QStringRef_toString);
	RING_API_REGISTER("qstringref_toucs4",ring_QStringRef_toUcs4);
	RING_API_REGISTER("qstringref_toutf8",ring_QStringRef_toUtf8);
	RING_API_REGISTER("qstringref_unicode",ring_QStringRef_unicode);
	RING_API_REGISTER("qstringref_compare_4",ring_QStringRef_compare_4);
	RING_API_REGISTER("qstringref_compare_5",ring_QStringRef_compare_5);
	RING_API_REGISTER("qstringref_compare_6",ring_QStringRef_compare_6);
	RING_API_REGISTER("qstringref_localeawarecompare_3",ring_QStringRef_localeAwareCompare_3);
	RING_API_REGISTER("qstringref_localeawarecompare_4",ring_QStringRef_localeAwareCompare_4);
	RING_API_REGISTER("qbuffer_buffer",ring_QBuffer_buffer);
	RING_API_REGISTER("qbuffer_data",ring_QBuffer_data);
	RING_API_REGISTER("qbuffer_setbuffer",ring_QBuffer_setBuffer);
	RING_API_REGISTER("qbuffer_setdata",ring_QBuffer_setData);
	RING_API_REGISTER("qbuffer_setdata_2",ring_QBuffer_setData_2);
	RING_API_REGISTER("qdatetime_adddays",ring_QDateTime_addDays);
	RING_API_REGISTER("qdatetime_addmsecs",ring_QDateTime_addMSecs);
	RING_API_REGISTER("qdatetime_addmonths",ring_QDateTime_addMonths);
	RING_API_REGISTER("qdatetime_addsecs",ring_QDateTime_addSecs);
	RING_API_REGISTER("qdatetime_addyears",ring_QDateTime_addYears);
	RING_API_REGISTER("qdatetime_date",ring_QDateTime_date);
	RING_API_REGISTER("qdatetime_daysto",ring_QDateTime_daysTo);
	RING_API_REGISTER("qdatetime_isnull",ring_QDateTime_isNull);
	RING_API_REGISTER("qdatetime_isvalid",ring_QDateTime_isValid);
	RING_API_REGISTER("qdatetime_msecsto",ring_QDateTime_msecsTo);
	RING_API_REGISTER("qdatetime_secsto",ring_QDateTime_secsTo);
	RING_API_REGISTER("qdatetime_setdate",ring_QDateTime_setDate);
	RING_API_REGISTER("qdatetime_setmsecssinceepoch",ring_QDateTime_setMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_settime",ring_QDateTime_setTime);
	RING_API_REGISTER("qdatetime_settimespec",ring_QDateTime_setTimeSpec);
	RING_API_REGISTER("qdatetime_time",ring_QDateTime_time);
	RING_API_REGISTER("qdatetime_timespec",ring_QDateTime_timeSpec);
	RING_API_REGISTER("qdatetime_tolocaltime",ring_QDateTime_toLocalTime);
	RING_API_REGISTER("qdatetime_tomsecssinceepoch",ring_QDateTime_toMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_tostring",ring_QDateTime_toString);
	RING_API_REGISTER("qdatetime_tostring_2",ring_QDateTime_toString_2);
	RING_API_REGISTER("qdatetime_totimespec",ring_QDateTime_toTimeSpec);
	RING_API_REGISTER("qdatetime_toutc",ring_QDateTime_toUTC);
	RING_API_REGISTER("qdatetime_currentdatetime",ring_QDateTime_currentDateTime);
	RING_API_REGISTER("qdatetime_currentdatetimeutc",ring_QDateTime_currentDateTimeUtc);
	RING_API_REGISTER("qdatetime_currentmsecssinceepoch",ring_QDateTime_currentMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_frommsecssinceepoch",ring_QDateTime_fromMSecsSinceEpoch);
	RING_API_REGISTER("qdatetime_fromstring",ring_QDateTime_fromString);
	RING_API_REGISTER("qdatetime_fromstring_2",ring_QDateTime_fromString_2);
	RING_API_REGISTER("qcoreapplication_installnativeeventfilter",ring_QCoreApplication_installNativeEventFilter);
	RING_API_REGISTER("qcoreapplication_removenativeeventfilter",ring_QCoreApplication_removeNativeEventFilter);
	RING_API_REGISTER("qcoreapplication_quit",ring_QCoreApplication_quit);
	RING_API_REGISTER("qcoreapplication_addlibrarypath",ring_QCoreApplication_addLibraryPath);
	RING_API_REGISTER("qcoreapplication_applicationdirpath",ring_QCoreApplication_applicationDirPath);
	RING_API_REGISTER("qcoreapplication_applicationfilepath",ring_QCoreApplication_applicationFilePath);
	RING_API_REGISTER("qcoreapplication_applicationname",ring_QCoreApplication_applicationName);
	RING_API_REGISTER("qcoreapplication_applicationpid",ring_QCoreApplication_applicationPid);
	RING_API_REGISTER("qcoreapplication_applicationversion",ring_QCoreApplication_applicationVersion);
	RING_API_REGISTER("qcoreapplication_arguments",ring_QCoreApplication_arguments);
	RING_API_REGISTER("qcoreapplication_closingdown",ring_QCoreApplication_closingDown);
	RING_API_REGISTER("qcoreapplication_eventdispatcher",ring_QCoreApplication_eventDispatcher);
	RING_API_REGISTER("qcoreapplication_exec",ring_QCoreApplication_exec);
	RING_API_REGISTER("qcoreapplication_exit",ring_QCoreApplication_exit);
	RING_API_REGISTER("qcoreapplication_installtranslator",ring_QCoreApplication_installTranslator);
	RING_API_REGISTER("qcoreapplication_instance",ring_QCoreApplication_instance);
	RING_API_REGISTER("qcoreapplication_isquitlockenabled",ring_QCoreApplication_isQuitLockEnabled);
	RING_API_REGISTER("qcoreapplication_librarypaths",ring_QCoreApplication_libraryPaths);
	RING_API_REGISTER("qcoreapplication_organizationdomain",ring_QCoreApplication_organizationDomain);
	RING_API_REGISTER("qcoreapplication_organizationname",ring_QCoreApplication_organizationName);
	RING_API_REGISTER("qcoreapplication_postevent",ring_QCoreApplication_postEvent);
	RING_API_REGISTER("qcoreapplication_processevents",ring_QCoreApplication_processEvents);
	RING_API_REGISTER("qcoreapplication_processevents_2",ring_QCoreApplication_processEvents_2);
	RING_API_REGISTER("qcoreapplication_removelibrarypath",ring_QCoreApplication_removeLibraryPath);
	RING_API_REGISTER("qcoreapplication_removepostedevents",ring_QCoreApplication_removePostedEvents);
	RING_API_REGISTER("qcoreapplication_removetranslator",ring_QCoreApplication_removeTranslator);
	RING_API_REGISTER("qcoreapplication_sendevent",ring_QCoreApplication_sendEvent);
	RING_API_REGISTER("qcoreapplication_sendpostedevents",ring_QCoreApplication_sendPostedEvents);
	RING_API_REGISTER("qcoreapplication_setapplicationname",ring_QCoreApplication_setApplicationName);
	RING_API_REGISTER("qcoreapplication_setapplicationversion",ring_QCoreApplication_setApplicationVersion);
	RING_API_REGISTER("qcoreapplication_setattribute",ring_QCoreApplication_setAttribute);
	RING_API_REGISTER("qcoreapplication_seteventdispatcher",ring_QCoreApplication_setEventDispatcher);
	RING_API_REGISTER("qcoreapplication_setlibrarypaths",ring_QCoreApplication_setLibraryPaths);
	RING_API_REGISTER("qcoreapplication_setorganizationdomain",ring_QCoreApplication_setOrganizationDomain);
	RING_API_REGISTER("qcoreapplication_setorganizationname",ring_QCoreApplication_setOrganizationName);
	RING_API_REGISTER("qcoreapplication_setquitlockenabled",ring_QCoreApplication_setQuitLockEnabled);
	RING_API_REGISTER("qcoreapplication_startingup",ring_QCoreApplication_startingUp);
	RING_API_REGISTER("qcoreapplication_testattribute",ring_QCoreApplication_testAttribute);
	RING_API_REGISTER("qcoreapplication_translate",ring_QCoreApplication_translate);
	RING_API_REGISTER("qfile_copy",ring_QFile_copy);
	RING_API_REGISTER("qfile_exists",ring_QFile_exists);
	RING_API_REGISTER("qfile_link",ring_QFile_link);
	RING_API_REGISTER("qfile_open",ring_QFile_open);
	RING_API_REGISTER("qfile_open_2",ring_QFile_open_2);
	RING_API_REGISTER("qfile_open_3",ring_QFile_open_3);
	RING_API_REGISTER("qfile_remove",ring_QFile_remove);
	RING_API_REGISTER("qfile_rename",ring_QFile_rename);
	RING_API_REGISTER("qfile_setfilename",ring_QFile_setFileName);
	RING_API_REGISTER("qfile_symlinktarget",ring_QFile_symLinkTarget);
	RING_API_REGISTER("qfile_copy_2",ring_QFile_copy_2);
	RING_API_REGISTER("qfile_decodename",ring_QFile_decodeName);
	RING_API_REGISTER("qfile_decodename_2",ring_QFile_decodeName_2);
	RING_API_REGISTER("qfile_encodename",ring_QFile_encodeName);
	RING_API_REGISTER("qfile_exists_2",ring_QFile_exists_2);
	RING_API_REGISTER("qfile_link_2",ring_QFile_link_2);
	RING_API_REGISTER("qfile_permissions",ring_QFile_permissions);
	RING_API_REGISTER("qfile_remove_2",ring_QFile_remove_2);
	RING_API_REGISTER("qfile_rename_2",ring_QFile_rename_2);
	RING_API_REGISTER("qfile_resize",ring_QFile_resize);
	RING_API_REGISTER("qfile_setpermissions",ring_QFile_setPermissions);
	RING_API_REGISTER("qfile_symlinktarget_2",ring_QFile_symLinkTarget_2);
	RING_API_REGISTER("qfiledevice_error",ring_QFileDevice_error);
	RING_API_REGISTER("qfiledevice_flush",ring_QFileDevice_flush);
	RING_API_REGISTER("qfiledevice_handle",ring_QFileDevice_handle);
	RING_API_REGISTER("qfiledevice_map",ring_QFileDevice_map);
	RING_API_REGISTER("qfiledevice_permissions",ring_QFileDevice_permissions);
	RING_API_REGISTER("qfiledevice_resize",ring_QFileDevice_resize);
	RING_API_REGISTER("qfiledevice_filename",ring_QFileDevice_fileName);
	RING_API_REGISTER("qfiledevice_setpermissions",ring_QFileDevice_setPermissions);
	RING_API_REGISTER("qfiledevice_unmap",ring_QFileDevice_unmap);
	RING_API_REGISTER("qfiledevice_unseterror",ring_QFileDevice_unsetError);
	RING_API_REGISTER("qstandardpaths_displayname",ring_QStandardPaths_displayName);
	RING_API_REGISTER("qstandardpaths_findexecutable",ring_QStandardPaths_findExecutable);
	RING_API_REGISTER("qstandardpaths_locate",ring_QStandardPaths_locate);
	RING_API_REGISTER("qstandardpaths_locateall",ring_QStandardPaths_locateAll);
	RING_API_REGISTER("qstandardpaths_settestmodeenabled",ring_QStandardPaths_setTestModeEnabled);
	RING_API_REGISTER("qstandardpaths_standardlocations",ring_QStandardPaths_standardLocations);
	RING_API_REGISTER("qstandardpaths_writablelocation",ring_QStandardPaths_writableLocation);
	RING_API_REGISTER("qmimedata_clear",ring_QMimeData_clear);
	RING_API_REGISTER("qmimedata_colordata",ring_QMimeData_colorData);
	RING_API_REGISTER("qmimedata_data",ring_QMimeData_data);
	RING_API_REGISTER("qmimedata_formats",ring_QMimeData_formats);
	RING_API_REGISTER("qmimedata_hascolor",ring_QMimeData_hasColor);
	RING_API_REGISTER("qmimedata_hasformat",ring_QMimeData_hasFormat);
	RING_API_REGISTER("qmimedata_hashtml",ring_QMimeData_hasHtml);
	RING_API_REGISTER("qmimedata_hasimage",ring_QMimeData_hasImage);
	RING_API_REGISTER("qmimedata_hastext",ring_QMimeData_hasText);
	RING_API_REGISTER("qmimedata_hasurls",ring_QMimeData_hasUrls);
	RING_API_REGISTER("qmimedata_html",ring_QMimeData_html);
	RING_API_REGISTER("qmimedata_imagedata",ring_QMimeData_imageData);
	RING_API_REGISTER("qmimedata_removeformat",ring_QMimeData_removeFormat);
	RING_API_REGISTER("qmimedata_setcolordata",ring_QMimeData_setColorData);
	RING_API_REGISTER("qmimedata_setdata",ring_QMimeData_setData);
	RING_API_REGISTER("qmimedata_sethtml",ring_QMimeData_setHtml);
	RING_API_REGISTER("qmimedata_setimagedata",ring_QMimeData_setImageData);
	RING_API_REGISTER("qmimedata_settext",ring_QMimeData_setText);
	RING_API_REGISTER("qmimedata_seturls",ring_QMimeData_setUrls);
	RING_API_REGISTER("qmimedata_text",ring_QMimeData_text);
	RING_API_REGISTER("qmimedata_urls",ring_QMimeData_urls);
	RING_API_REGISTER("qchar_category",ring_QChar_category);
	RING_API_REGISTER("qchar_cell",ring_QChar_cell);
	RING_API_REGISTER("qchar_combiningclass",ring_QChar_combiningClass);
	RING_API_REGISTER("qchar_decomposition",ring_QChar_decomposition);
	RING_API_REGISTER("qchar_decompositiontag",ring_QChar_decompositionTag);
	RING_API_REGISTER("qchar_digitvalue",ring_QChar_digitValue);
	RING_API_REGISTER("qchar_direction",ring_QChar_direction);
	RING_API_REGISTER("qchar_hasmirrored",ring_QChar_hasMirrored);
	RING_API_REGISTER("qchar_isdigit",ring_QChar_isDigit);
	RING_API_REGISTER("qchar_ishighsurrogate",ring_QChar_isHighSurrogate);
	RING_API_REGISTER("qchar_isletter",ring_QChar_isLetter);
	RING_API_REGISTER("qchar_isletterornumber",ring_QChar_isLetterOrNumber);
	RING_API_REGISTER("qchar_islowsurrogate",ring_QChar_isLowSurrogate);
	RING_API_REGISTER("qchar_islower",ring_QChar_isLower);
	RING_API_REGISTER("qchar_ismark",ring_QChar_isMark);
	RING_API_REGISTER("qchar_isnoncharacter",ring_QChar_isNonCharacter);
	RING_API_REGISTER("qchar_isnull",ring_QChar_isNull);
	RING_API_REGISTER("qchar_isnumber",ring_QChar_isNumber);
	RING_API_REGISTER("qchar_isprint",ring_QChar_isPrint);
	RING_API_REGISTER("qchar_ispunct",ring_QChar_isPunct);
	RING_API_REGISTER("qchar_isspace",ring_QChar_isSpace);
	RING_API_REGISTER("qchar_issurrogate",ring_QChar_isSurrogate);
	RING_API_REGISTER("qchar_issymbol",ring_QChar_isSymbol);
	RING_API_REGISTER("qchar_istitlecase",ring_QChar_isTitleCase);
	RING_API_REGISTER("qchar_isupper",ring_QChar_isUpper);
	RING_API_REGISTER("qchar_mirroredchar",ring_QChar_mirroredChar);
	RING_API_REGISTER("qchar_row",ring_QChar_row);
	RING_API_REGISTER("qchar_script",ring_QChar_script);
	RING_API_REGISTER("qchar_tocasefolded",ring_QChar_toCaseFolded);
	RING_API_REGISTER("qchar_tolatin1",ring_QChar_toLatin1);
	RING_API_REGISTER("qchar_tolower",ring_QChar_toLower);
	RING_API_REGISTER("qchar_totitlecase",ring_QChar_toTitleCase);
	RING_API_REGISTER("qchar_toupper",ring_QChar_toUpper);
	RING_API_REGISTER("qchar_unicode",ring_QChar_unicode);
	RING_API_REGISTER("qchar_unicode_2",ring_QChar_unicode_2);
	RING_API_REGISTER("qchar_unicodeversion",ring_QChar_unicodeVersion);
	RING_API_REGISTER("qchar_category_2",ring_QChar_category_2);
	RING_API_REGISTER("qchar_combiningclass_2",ring_QChar_combiningClass_2);
	RING_API_REGISTER("qchar_currentunicodeversion",ring_QChar_currentUnicodeVersion);
	RING_API_REGISTER("qchar_decomposition_2",ring_QChar_decomposition_2);
	RING_API_REGISTER("qchar_decompositiontag_2",ring_QChar_decompositionTag_2);
	RING_API_REGISTER("qchar_digitvalue_2",ring_QChar_digitValue_2);
	RING_API_REGISTER("qchar_direction_2",ring_QChar_direction_2);
	RING_API_REGISTER("qchar_fromlatin1",ring_QChar_fromLatin1);
	RING_API_REGISTER("qchar_hasmirrored_2",ring_QChar_hasMirrored_2);
	RING_API_REGISTER("qchar_highsurrogate",ring_QChar_highSurrogate);
	RING_API_REGISTER("qchar_isdigit_2",ring_QChar_isDigit_2);
	RING_API_REGISTER("qchar_ishighsurrogate_2",ring_QChar_isHighSurrogate_2);
	RING_API_REGISTER("qchar_isletter_2",ring_QChar_isLetter_2);
	RING_API_REGISTER("qchar_isletterornumber_2",ring_QChar_isLetterOrNumber_2);
	RING_API_REGISTER("qchar_islowsurrogate_2",ring_QChar_isLowSurrogate_2);
	RING_API_REGISTER("qchar_islower_2",ring_QChar_isLower_2);
	RING_API_REGISTER("qchar_ismark_2",ring_QChar_isMark_2);
	RING_API_REGISTER("qchar_isnoncharacter_2",ring_QChar_isNonCharacter_2);
	RING_API_REGISTER("qchar_isnumber_2",ring_QChar_isNumber_2);
	RING_API_REGISTER("qchar_isprint_2",ring_QChar_isPrint_2);
	RING_API_REGISTER("qchar_ispunct_2",ring_QChar_isPunct_2);
	RING_API_REGISTER("qchar_isspace_2",ring_QChar_isSpace_2);
	RING_API_REGISTER("qchar_issurrogate_2",ring_QChar_isSurrogate_2);
	RING_API_REGISTER("qchar_issymbol_2",ring_QChar_isSymbol_2);
	RING_API_REGISTER("qchar_istitlecase_2",ring_QChar_isTitleCase_2);
	RING_API_REGISTER("qchar_isupper_2",ring_QChar_isUpper_2);
	RING_API_REGISTER("qchar_lowsurrogate",ring_QChar_lowSurrogate);
	RING_API_REGISTER("qchar_mirroredchar_2",ring_QChar_mirroredChar_2);
	RING_API_REGISTER("qchar_requiressurrogates",ring_QChar_requiresSurrogates);
	RING_API_REGISTER("qchar_script_2",ring_QChar_script_2);
	RING_API_REGISTER("qchar_surrogatetoucs4",ring_QChar_surrogateToUcs4);
	RING_API_REGISTER("qchar_surrogatetoucs4_2",ring_QChar_surrogateToUcs4_2);
	RING_API_REGISTER("qchar_tocasefolded_2",ring_QChar_toCaseFolded_2);
	RING_API_REGISTER("qchar_tolower_2",ring_QChar_toLower_2);
	RING_API_REGISTER("qchar_totitlecase_2",ring_QChar_toTitleCase_2);
	RING_API_REGISTER("qchar_toupper_2",ring_QChar_toUpper_2);
	RING_API_REGISTER("qchar_unicodeversion_2",ring_QChar_unicodeVersion_2);
	RING_API_REGISTER("qchildevent_added",ring_QChildEvent_added);
	RING_API_REGISTER("qchildevent_child",ring_QChildEvent_child);
	RING_API_REGISTER("qchildevent_polished",ring_QChildEvent_polished);
	RING_API_REGISTER("qchildevent_removed",ring_QChildEvent_removed);
	RING_API_REGISTER("qtextstream_atend",ring_QTextStream_atEnd);
	RING_API_REGISTER("qtextstream_autodetectunicode",ring_QTextStream_autoDetectUnicode);
	RING_API_REGISTER("qtextstream_codec",ring_QTextStream_codec);
	RING_API_REGISTER("qtextstream_device",ring_QTextStream_device);
	RING_API_REGISTER("qtextstream_fieldalignment",ring_QTextStream_fieldAlignment);
	RING_API_REGISTER("qtextstream_fieldwidth",ring_QTextStream_fieldWidth);
	RING_API_REGISTER("qtextstream_flush",ring_QTextStream_flush);
	RING_API_REGISTER("qtextstream_generatebyteordermark",ring_QTextStream_generateByteOrderMark);
	RING_API_REGISTER("qtextstream_integerbase",ring_QTextStream_integerBase);
	RING_API_REGISTER("qtextstream_locale",ring_QTextStream_locale);
	RING_API_REGISTER("qtextstream_numberflags",ring_QTextStream_numberFlags);
	RING_API_REGISTER("qtextstream_padchar",ring_QTextStream_padChar);
	RING_API_REGISTER("qtextstream_pos",ring_QTextStream_pos);
	RING_API_REGISTER("qtextstream_read",ring_QTextStream_read);
	RING_API_REGISTER("qtextstream_readall",ring_QTextStream_readAll);
	RING_API_REGISTER("qtextstream_readline",ring_QTextStream_readLine);
	RING_API_REGISTER("qtextstream_realnumbernotation",ring_QTextStream_realNumberNotation);
	RING_API_REGISTER("qtextstream_realnumberprecision",ring_QTextStream_realNumberPrecision);
	RING_API_REGISTER("qtextstream_reset",ring_QTextStream_reset);
	RING_API_REGISTER("qtextstream_resetstatus",ring_QTextStream_resetStatus);
	RING_API_REGISTER("qtextstream_seek",ring_QTextStream_seek);
	RING_API_REGISTER("qtextstream_setautodetectunicode",ring_QTextStream_setAutoDetectUnicode);
	RING_API_REGISTER("qtextstream_setcodec",ring_QTextStream_setCodec);
	RING_API_REGISTER("qtextstream_setcodec_2",ring_QTextStream_setCodec_2);
	RING_API_REGISTER("qtextstream_setdevice",ring_QTextStream_setDevice);
	RING_API_REGISTER("qtextstream_setfieldalignment",ring_QTextStream_setFieldAlignment);
	RING_API_REGISTER("qtextstream_setfieldwidth",ring_QTextStream_setFieldWidth);
	RING_API_REGISTER("qtextstream_setgeneratebyteordermark",ring_QTextStream_setGenerateByteOrderMark);
	RING_API_REGISTER("qtextstream_setintegerbase",ring_QTextStream_setIntegerBase);
	RING_API_REGISTER("qtextstream_setlocale",ring_QTextStream_setLocale);
	RING_API_REGISTER("qtextstream_setnumberflags",ring_QTextStream_setNumberFlags);
	RING_API_REGISTER("qtextstream_setpadchar",ring_QTextStream_setPadChar);
	RING_API_REGISTER("qtextstream_setrealnumbernotation",ring_QTextStream_setRealNumberNotation);
	RING_API_REGISTER("qtextstream_setrealnumberprecision",ring_QTextStream_setRealNumberPrecision);
	RING_API_REGISTER("qtextstream_setstatus",ring_QTextStream_setStatus);
	RING_API_REGISTER("qtextstream_setstring",ring_QTextStream_setString);
	RING_API_REGISTER("qtextstream_skipwhitespace",ring_QTextStream_skipWhiteSpace);
	RING_API_REGISTER("qtextstream_status",ring_QTextStream_status);
	RING_API_REGISTER("qtextstream_string",ring_QTextStream_string);
	RING_API_REGISTER("qlocale_amtext",ring_QLocale_amText);
	RING_API_REGISTER("qlocale_bcp47name",ring_QLocale_bcp47Name);
	RING_API_REGISTER("qlocale_country",ring_QLocale_country);
	RING_API_REGISTER("qlocale_createseparatedlist",ring_QLocale_createSeparatedList);
	RING_API_REGISTER("qlocale_currencysymbol",ring_QLocale_currencySymbol);
	RING_API_REGISTER("qlocale_dateformat",ring_QLocale_dateFormat);
	RING_API_REGISTER("qlocale_datetimeformat",ring_QLocale_dateTimeFormat);
	RING_API_REGISTER("qlocale_dayname",ring_QLocale_dayName);
	RING_API_REGISTER("qlocale_decimalpoint",ring_QLocale_decimalPoint);
	RING_API_REGISTER("qlocale_exponential",ring_QLocale_exponential);
	RING_API_REGISTER("qlocale_firstdayofweek",ring_QLocale_firstDayOfWeek);
	RING_API_REGISTER("qlocale_groupseparator",ring_QLocale_groupSeparator);
	RING_API_REGISTER("qlocale_language",ring_QLocale_language);
	RING_API_REGISTER("qlocale_measurementsystem",ring_QLocale_measurementSystem);
	RING_API_REGISTER("qlocale_monthname",ring_QLocale_monthName);
	RING_API_REGISTER("qlocale_name",ring_QLocale_name);
	RING_API_REGISTER("qlocale_nativecountryname",ring_QLocale_nativeCountryName);
	RING_API_REGISTER("qlocale_nativelanguagename",ring_QLocale_nativeLanguageName);
	RING_API_REGISTER("qlocale_negativesign",ring_QLocale_negativeSign);
	RING_API_REGISTER("qlocale_numberoptions",ring_QLocale_numberOptions);
	RING_API_REGISTER("qlocale_percent",ring_QLocale_percent);
	RING_API_REGISTER("qlocale_pmtext",ring_QLocale_pmText);
	RING_API_REGISTER("qlocale_positivesign",ring_QLocale_positiveSign);
	RING_API_REGISTER("qlocale_quotestring",ring_QLocale_quoteString);
	RING_API_REGISTER("qlocale_quotestring_2",ring_QLocale_quoteString_2);
	RING_API_REGISTER("qlocale_script",ring_QLocale_script);
	RING_API_REGISTER("qlocale_setnumberoptions",ring_QLocale_setNumberOptions);
	RING_API_REGISTER("qlocale_standalonedayname",ring_QLocale_standaloneDayName);
	RING_API_REGISTER("qlocale_standalonemonthname",ring_QLocale_standaloneMonthName);
	RING_API_REGISTER("qlocale_textdirection",ring_QLocale_textDirection);
	RING_API_REGISTER("qlocale_timeformat",ring_QLocale_timeFormat);
	RING_API_REGISTER("qlocale_todouble",ring_QLocale_toDouble);
	RING_API_REGISTER("qlocale_todouble_2",ring_QLocale_toDouble_2);
	RING_API_REGISTER("qlocale_tofloat",ring_QLocale_toFloat);
	RING_API_REGISTER("qlocale_tofloat_2",ring_QLocale_toFloat_2);
	RING_API_REGISTER("qlocale_toint",ring_QLocale_toInt);
	RING_API_REGISTER("qlocale_toint_2",ring_QLocale_toInt_2);
	RING_API_REGISTER("qlocale_tolonglong",ring_QLocale_toLongLong);
	RING_API_REGISTER("qlocale_tolonglong_2",ring_QLocale_toLongLong_2);
	RING_API_REGISTER("qlocale_tolower",ring_QLocale_toLower);
	RING_API_REGISTER("qlocale_toshort",ring_QLocale_toShort);
	RING_API_REGISTER("qlocale_toshort_2",ring_QLocale_toShort_2);
	RING_API_REGISTER("qlocale_tostring",ring_QLocale_toString);
	RING_API_REGISTER("qlocale_tostring_2",ring_QLocale_toString_2);
	RING_API_REGISTER("qlocale_tostring_4",ring_QLocale_toString_4);
	RING_API_REGISTER("qlocale_tostring_5",ring_QLocale_toString_5);
	RING_API_REGISTER("qlocale_tostring_6",ring_QLocale_toString_6);
	RING_API_REGISTER("qlocale_tostring_7",ring_QLocale_toString_7);
	RING_API_REGISTER("qlocale_tostring_8",ring_QLocale_toString_8);
	RING_API_REGISTER("qlocale_tostring_9",ring_QLocale_toString_9);
	RING_API_REGISTER("qlocale_tostring_10",ring_QLocale_toString_10);
	RING_API_REGISTER("qlocale_tostring_11",ring_QLocale_toString_11);
	RING_API_REGISTER("qlocale_tostring_12",ring_QLocale_toString_12);
	RING_API_REGISTER("qlocale_tostring_13",ring_QLocale_toString_13);
	RING_API_REGISTER("qlocale_tostring_14",ring_QLocale_toString_14);
	RING_API_REGISTER("qlocale_tostring_15",ring_QLocale_toString_15);
	RING_API_REGISTER("qlocale_totime",ring_QLocale_toTime);
	RING_API_REGISTER("qlocale_totime_2",ring_QLocale_toTime_2);
	RING_API_REGISTER("qlocale_touint",ring_QLocale_toUInt);
	RING_API_REGISTER("qlocale_touint_2",ring_QLocale_toUInt_2);
	RING_API_REGISTER("qlocale_toulonglong",ring_QLocale_toULongLong);
	RING_API_REGISTER("qlocale_toulonglong_2",ring_QLocale_toULongLong_2);
	RING_API_REGISTER("qlocale_toushort",ring_QLocale_toUShort);
	RING_API_REGISTER("qlocale_toushort_2",ring_QLocale_toUShort_2);
	RING_API_REGISTER("qlocale_toupper",ring_QLocale_toUpper);
	RING_API_REGISTER("qlocale_uilanguages",ring_QLocale_uiLanguages);
	RING_API_REGISTER("qlocale_weekdays",ring_QLocale_weekdays);
	RING_API_REGISTER("qlocale_zerodigit",ring_QLocale_zeroDigit);
	RING_API_REGISTER("qlocale_c",ring_QLocale_c);
	RING_API_REGISTER("qlocale_countrytostring",ring_QLocale_countryToString);
	RING_API_REGISTER("qlocale_languagetostring",ring_QLocale_languageToString);
	RING_API_REGISTER("qlocale_matchinglocales",ring_QLocale_matchingLocales);
	RING_API_REGISTER("qlocale_scripttostring",ring_QLocale_scriptToString);
	RING_API_REGISTER("qlocale_setdefault",ring_QLocale_setDefault);
	RING_API_REGISTER("qlocale_system",ring_QLocale_system);
	RING_API_REGISTER("qthread_eventdispatcher",ring_QThread_eventDispatcher);
	RING_API_REGISTER("qthread_exit",ring_QThread_exit);
	RING_API_REGISTER("qthread_isfinished",ring_QThread_isFinished);
	RING_API_REGISTER("qthread_isinterruptionrequested",ring_QThread_isInterruptionRequested);
	RING_API_REGISTER("qthread_isrunning",ring_QThread_isRunning);
	RING_API_REGISTER("qthread_priority",ring_QThread_priority);
	RING_API_REGISTER("qthread_requestinterruption",ring_QThread_requestInterruption);
	RING_API_REGISTER("qthread_seteventdispatcher",ring_QThread_setEventDispatcher);
	RING_API_REGISTER("qthread_setpriority",ring_QThread_setPriority);
	RING_API_REGISTER("qthread_setstacksize",ring_QThread_setStackSize);
	RING_API_REGISTER("qthread_stacksize",ring_QThread_stackSize);
	RING_API_REGISTER("qthread_wait",ring_QThread_wait);
	RING_API_REGISTER("qthread_quit",ring_QThread_quit);
	RING_API_REGISTER("qthread_start",ring_QThread_start);
	RING_API_REGISTER("qthread_terminate",ring_QThread_terminate);
	RING_API_REGISTER("qthread_currentthread",ring_QThread_currentThread);
	RING_API_REGISTER("qthread_currentthreadid",ring_QThread_currentThreadId);
	RING_API_REGISTER("qthread_idealthreadcount",ring_QThread_idealThreadCount);
	RING_API_REGISTER("qthread_msleep",ring_QThread_msleep);
	RING_API_REGISTER("qthread_sleep",ring_QThread_sleep);
	RING_API_REGISTER("qthread_usleep",ring_QThread_usleep);
	RING_API_REGISTER("qthread_yieldcurrentthread",ring_QThread_yieldCurrentThread);
	RING_API_REGISTER("qthread_setstartedevent",ring_QThread_setStartedEvent);
	RING_API_REGISTER("qthread_setfinishedevent",ring_QThread_setFinishedEvent);
	RING_API_REGISTER("qthread_getstartedevent",ring_QThread_getStartedEvent);
	RING_API_REGISTER("qthread_getfinishedevent",ring_QThread_getFinishedEvent);
	RING_API_REGISTER("qthreadpool_activethreadcount",ring_QThreadPool_activeThreadCount);
	RING_API_REGISTER("qthreadpool_clear",ring_QThreadPool_clear);
	RING_API_REGISTER("qthreadpool_expirytimeout",ring_QThreadPool_expiryTimeout);
	RING_API_REGISTER("qthreadpool_maxthreadcount",ring_QThreadPool_maxThreadCount);
	RING_API_REGISTER("qthreadpool_releasethread",ring_QThreadPool_releaseThread);
	RING_API_REGISTER("qthreadpool_reservethread",ring_QThreadPool_reserveThread);
	RING_API_REGISTER("qthreadpool_setexpirytimeout",ring_QThreadPool_setExpiryTimeout);
	RING_API_REGISTER("qthreadpool_setmaxthreadcount",ring_QThreadPool_setMaxThreadCount);
	RING_API_REGISTER("qthreadpool_start",ring_QThreadPool_start);
	RING_API_REGISTER("qthreadpool_trystart",ring_QThreadPool_tryStart);
	RING_API_REGISTER("qthreadpool_waitfordone",ring_QThreadPool_waitForDone);
	RING_API_REGISTER("qthreadpool_globalinstance",ring_QThreadPool_globalInstance);
	RING_API_REGISTER("qprocess_arguments",ring_QProcess_arguments);
	RING_API_REGISTER("qprocess_closereadchannel",ring_QProcess_closeReadChannel);
	RING_API_REGISTER("qprocess_closewritechannel",ring_QProcess_closeWriteChannel);
	RING_API_REGISTER("qprocess_error",ring_QProcess_error);
	RING_API_REGISTER("qprocess_exitcode",ring_QProcess_exitCode);
	RING_API_REGISTER("qprocess_exitstatus",ring_QProcess_exitStatus);
	RING_API_REGISTER("qprocess_inputchannelmode",ring_QProcess_inputChannelMode);
	RING_API_REGISTER("qprocess_processchannelmode",ring_QProcess_processChannelMode);
	RING_API_REGISTER("qprocess_processenvironment",ring_QProcess_processEnvironment);
	RING_API_REGISTER("qprocess_program",ring_QProcess_program);
	RING_API_REGISTER("qprocess_readallstandarderror",ring_QProcess_readAllStandardError);
	RING_API_REGISTER("qprocess_readallstandardoutput",ring_QProcess_readAllStandardOutput);
	RING_API_REGISTER("qprocess_readchannel",ring_QProcess_readChannel);
	RING_API_REGISTER("qprocess_setarguments",ring_QProcess_setArguments);
	RING_API_REGISTER("qprocess_setinputchannelmode",ring_QProcess_setInputChannelMode);
	RING_API_REGISTER("qprocess_setprocesschannelmode",ring_QProcess_setProcessChannelMode);
	RING_API_REGISTER("qprocess_setprocessenvironment",ring_QProcess_setProcessEnvironment);
	RING_API_REGISTER("qprocess_setprogram",ring_QProcess_setProgram);
	RING_API_REGISTER("qprocess_setreadchannel",ring_QProcess_setReadChannel);
	RING_API_REGISTER("qprocess_setstandarderrorfile",ring_QProcess_setStandardErrorFile);
	RING_API_REGISTER("qprocess_setstandardinputfile",ring_QProcess_setStandardInputFile);
	RING_API_REGISTER("qprocess_setstandardoutputfile",ring_QProcess_setStandardOutputFile);
	RING_API_REGISTER("qprocess_setstandardoutputprocess",ring_QProcess_setStandardOutputProcess);
	RING_API_REGISTER("qprocess_setworkingdirectory",ring_QProcess_setWorkingDirectory);
	RING_API_REGISTER("qprocess_start",ring_QProcess_start);
	RING_API_REGISTER("qprocess_start_3",ring_QProcess_start_3);
	RING_API_REGISTER("qprocess_state",ring_QProcess_state);
	RING_API_REGISTER("qprocess_waitforfinished",ring_QProcess_waitForFinished);
	RING_API_REGISTER("qprocess_waitforstarted",ring_QProcess_waitForStarted);
	RING_API_REGISTER("qprocess_workingdirectory",ring_QProcess_workingDirectory);
	RING_API_REGISTER("qprocess_kill",ring_QProcess_kill);
	RING_API_REGISTER("qprocess_terminate",ring_QProcess_terminate);
	RING_API_REGISTER("qprocess_setreadyreadstandarderrorevent",ring_QProcess_setreadyReadStandardErrorEvent);
	RING_API_REGISTER("qprocess_setreadyreadstandardoutputevent",ring_QProcess_setreadyReadStandardOutputEvent);
	RING_API_REGISTER("qprocess_getreadyreadstandarderrorevent",ring_QProcess_getreadyReadStandardErrorEvent);
	RING_API_REGISTER("qprocess_getreadyreadstandardoutputevent",ring_QProcess_getreadyReadStandardOutputEvent);
	RING_API_REGISTER("quuid_tostring",ring_QUuid_toString);
	RING_API_REGISTER("qmutex_isrecursive",ring_QMutex_isRecursive);
	RING_API_REGISTER("qmutex_lock",ring_QMutex_lock);
	RING_API_REGISTER("qmutex_unlock",ring_QMutex_unlock);
	RING_API_REGISTER("qmutexlocker_mutex",ring_QMutexLocker_mutex);
	RING_API_REGISTER("qmutexlocker_relock",ring_QMutexLocker_relock);
	RING_API_REGISTER("qmutexlocker_unlock",ring_QMutexLocker_unlock);
	RING_API_REGISTER("qobject_new",ring_QObject_new);
	RING_API_REGISTER("qsize_new",ring_QSize_new);
	RING_API_REGISTER("qdir_new",ring_QDir_new);
	RING_API_REGISTER("qurl_new",ring_QUrl_new);
	RING_API_REGISTER("qevent_new",ring_QEvent_new);
	RING_API_REGISTER("qtimer_new",ring_QTimer_new);
	RING_API_REGISTER("qbytearray_new",ring_QByteArray_new);
	RING_API_REGISTER("qfileinfo_new",ring_QFileInfo_new);
	RING_API_REGISTER("qstringlist_new",ring_QStringList_new);
	RING_API_REGISTER("qrect_new",ring_QRect_new);
	RING_API_REGISTER("qtime_new",ring_QTime_new);
	RING_API_REGISTER("qdate_new",ring_QDate_new);
	RING_API_REGISTER("qvariant_new",ring_QVariant_new);
	RING_API_REGISTER("qvariant2_new",ring_QVariant2_new);
	RING_API_REGISTER("qvariant3_new",ring_QVariant3_new);
	RING_API_REGISTER("qvariant4_new",ring_QVariant4_new);
	RING_API_REGISTER("qvariant5_new",ring_QVariant5_new);
	RING_API_REGISTER("qvariantint_new",ring_QVariantInt_new);
	RING_API_REGISTER("qvariantfloat_new",ring_QVariantFloat_new);
	RING_API_REGISTER("qvariantdouble_new",ring_QVariantDouble_new);
	RING_API_REGISTER("qvariantstring_new",ring_QVariantString_new);
	RING_API_REGISTER("qxmlstreamreader_new",ring_QXmlStreamReader_new);
	RING_API_REGISTER("qxmlstreamwriter_new",ring_QXmlStreamWriter_new);
	RING_API_REGISTER("qxmlstreamnotationdeclaration_new",ring_QXmlStreamNotationDeclaration_new);
	RING_API_REGISTER("qxmlstreamnamespacedeclaration_new",ring_QXmlStreamNamespaceDeclaration_new);
	RING_API_REGISTER("qxmlstreamentitydeclaration_new",ring_QXmlStreamEntityDeclaration_new);
	RING_API_REGISTER("qxmlstreamentityresolver_new",ring_QXmlStreamEntityResolver_new);
	RING_API_REGISTER("qxmlstreamattributes_new",ring_QXmlStreamAttributes_new);
	RING_API_REGISTER("qxmlstreamattribute_new",ring_QXmlStreamAttribute_new);
	RING_API_REGISTER("qregularexpression_new",ring_QRegularExpression_new);
	RING_API_REGISTER("qregularexpressionmatch_new",ring_QRegularExpressionMatch_new);
	RING_API_REGISTER("qregularexpressionmatchiterator_new",ring_QRegularExpressionMatchIterator_new);
	RING_API_REGISTER("qjsonarray_new",ring_QJsonArray_new);
	RING_API_REGISTER("qjsondocument_new",ring_QJsonDocument_new);
	RING_API_REGISTER("qjsonobject_new",ring_QJsonObject_new);
	RING_API_REGISTER("qjsonparseerror_new",ring_QJsonParseError_new);
	RING_API_REGISTER("qjsonvalue_new",ring_QJsonValue_new);
	RING_API_REGISTER("qpointf_new",ring_QPointF_new);
	RING_API_REGISTER("qpoint_new",ring_QPoint_new);
	RING_API_REGISTER("qstring2_new",ring_QString2_new);
	RING_API_REGISTER("qstringref_new",ring_QStringRef_new);
	RING_API_REGISTER("qbuffer_new",ring_QBuffer_new);
	RING_API_REGISTER("qdatetime_new",ring_QDateTime_new);
	RING_API_REGISTER("qfile_new",ring_QFile_new);
	RING_API_REGISTER("qfile2_new",ring_QFile2_new);
	RING_API_REGISTER("qmimedata_new",ring_QMimeData_new);
	RING_API_REGISTER("qchar_new",ring_QChar_new);
	RING_API_REGISTER("qchildevent_new",ring_QChildEvent_new);
	RING_API_REGISTER("qtextstream_new",ring_QTextStream_new);
	RING_API_REGISTER("qtextstream2_new",ring_QTextStream2_new);
	RING_API_REGISTER("qtextstream3_new",ring_QTextStream3_new);
	RING_API_REGISTER("qtextstream4_new",ring_QTextStream4_new);
	RING_API_REGISTER("qtextstream5_new",ring_QTextStream5_new);
	RING_API_REGISTER("qlocale_new",ring_QLocale_new);
	RING_API_REGISTER("qthread_new",ring_QThread_new);
	RING_API_REGISTER("qthreadpool_new",ring_QThreadPool_new);
	RING_API_REGISTER("qprocess_new",ring_QProcess_new);
	RING_API_REGISTER("quuid_new",ring_QUuid_new);
	RING_API_REGISTER("qmutex_new",ring_QMutex_new);
	RING_API_REGISTER("qmutexlocker_new",ring_QMutexLocker_new);
	RING_API_REGISTER("qobject_delete",ring_QObject_delete);
	RING_API_REGISTER("qsize_delete",ring_QSize_delete);
	RING_API_REGISTER("qdir_delete",ring_QDir_delete);
	RING_API_REGISTER("qurl_delete",ring_QUrl_delete);
	RING_API_REGISTER("qevent_delete",ring_QEvent_delete);
	RING_API_REGISTER("qtimer_delete",ring_QTimer_delete);
	RING_API_REGISTER("qbytearray_delete",ring_QByteArray_delete);
	RING_API_REGISTER("qfileinfo_delete",ring_QFileInfo_delete);
	RING_API_REGISTER("qstringlist_delete",ring_QStringList_delete);
	RING_API_REGISTER("qrect_delete",ring_QRect_delete);
	RING_API_REGISTER("qtime_delete",ring_QTime_delete);
	RING_API_REGISTER("qdate_delete",ring_QDate_delete);
	RING_API_REGISTER("qvariant_delete",ring_QVariant_delete);
	RING_API_REGISTER("qvariant2_delete",ring_QVariant2_delete);
	RING_API_REGISTER("qvariant3_delete",ring_QVariant3_delete);
	RING_API_REGISTER("qvariant4_delete",ring_QVariant4_delete);
	RING_API_REGISTER("qvariant5_delete",ring_QVariant5_delete);
	RING_API_REGISTER("qvariantint_delete",ring_QVariantInt_delete);
	RING_API_REGISTER("qvariantfloat_delete",ring_QVariantFloat_delete);
	RING_API_REGISTER("qvariantdouble_delete",ring_QVariantDouble_delete);
	RING_API_REGISTER("qvariantstring_delete",ring_QVariantString_delete);
	RING_API_REGISTER("qxmlstreamreader_delete",ring_QXmlStreamReader_delete);
	RING_API_REGISTER("qxmlstreamwriter_delete",ring_QXmlStreamWriter_delete);
	RING_API_REGISTER("qxmlstreamnotationdeclaration_delete",ring_QXmlStreamNotationDeclaration_delete);
	RING_API_REGISTER("qxmlstreamnamespacedeclaration_delete",ring_QXmlStreamNamespaceDeclaration_delete);
	RING_API_REGISTER("qxmlstreamentitydeclaration_delete",ring_QXmlStreamEntityDeclaration_delete);
	RING_API_REGISTER("qxmlstreamentityresolver_delete",ring_QXmlStreamEntityResolver_delete);
	RING_API_REGISTER("qxmlstreamattributes_delete",ring_QXmlStreamAttributes_delete);
	RING_API_REGISTER("qxmlstreamattribute_delete",ring_QXmlStreamAttribute_delete);
	RING_API_REGISTER("qregularexpression_delete",ring_QRegularExpression_delete);
	RING_API_REGISTER("qregularexpressionmatch_delete",ring_QRegularExpressionMatch_delete);
	RING_API_REGISTER("qregularexpressionmatchiterator_delete",ring_QRegularExpressionMatchIterator_delete);
	RING_API_REGISTER("qjsonarray_delete",ring_QJsonArray_delete);
	RING_API_REGISTER("qjsondocument_delete",ring_QJsonDocument_delete);
	RING_API_REGISTER("qjsonobject_delete",ring_QJsonObject_delete);
	RING_API_REGISTER("qjsonparseerror_delete",ring_QJsonParseError_delete);
	RING_API_REGISTER("qjsonvalue_delete",ring_QJsonValue_delete);
	RING_API_REGISTER("qpointf_delete",ring_QPointF_delete);
	RING_API_REGISTER("qpoint_delete",ring_QPoint_delete);
	RING_API_REGISTER("qstring2_delete",ring_QString2_delete);
	RING_API_REGISTER("qstringref_delete",ring_QStringRef_delete);
	RING_API_REGISTER("qbuffer_delete",ring_QBuffer_delete);
	RING_API_REGISTER("qdatetime_delete",ring_QDateTime_delete);
	RING_API_REGISTER("qfile_delete",ring_QFile_delete);
	RING_API_REGISTER("qfile2_delete",ring_QFile2_delete);
	RING_API_REGISTER("qmimedata_delete",ring_QMimeData_delete);
	RING_API_REGISTER("qchar_delete",ring_QChar_delete);
	RING_API_REGISTER("qchildevent_delete",ring_QChildEvent_delete);
	RING_API_REGISTER("qtextstream_delete",ring_QTextStream_delete);
	RING_API_REGISTER("qtextstream2_delete",ring_QTextStream2_delete);
	RING_API_REGISTER("qtextstream3_delete",ring_QTextStream3_delete);
	RING_API_REGISTER("qtextstream4_delete",ring_QTextStream4_delete);
	RING_API_REGISTER("qtextstream5_delete",ring_QTextStream5_delete);
	RING_API_REGISTER("qlocale_delete",ring_QLocale_delete);
	RING_API_REGISTER("qthread_delete",ring_QThread_delete);
	RING_API_REGISTER("qthreadpool_delete",ring_QThreadPool_delete);
	RING_API_REGISTER("qprocess_delete",ring_QProcess_delete);
	RING_API_REGISTER("quuid_delete",ring_QUuid_delete);
	RING_API_REGISTER("qmutex_delete",ring_QMutex_delete);
	RING_API_REGISTER("qmutexlocker_delete",ring_QMutexLocker_delete);
}

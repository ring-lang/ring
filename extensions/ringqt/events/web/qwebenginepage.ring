aClasses + [
		:name = "GWebEnginePage" ,
		:realname = "QWebEnginePage" ,
		:headerfile = "",
		:initpara = "QObject * ",
		:initparaparent = "",
		:events = [
				[ 	:signal = "audioMutedChanged(bool)" ,
					:slot = "audioMutedChangedSlot()" ,
					:event = "audioMutedChanged"
				],
				[ 	:signal = "authenticationRequired(const QUrl,QAuthenticator *)" ,
					:slot = "authenticationRequiredSlot()" ,
					:event = "authenticationRequired"
				],
				[ 	:signal = "contentsSizeChanged(const QSizeF)" ,
					:slot = "contentsSizeChangedSlot()" ,
					:event = "contentsSizeChanged"
				],
				[ 	:signal = "featurePermissionRequestCanceled(const QUrl,QWebEnginePage::Feature)" ,
					:slot = "featurePermissionRequestCanceledSlot()" ,
					:event = "featurePermissionRequestCanceled"
				],
				[ 	:signal = "featurePermissionRequested(const QUrl,QWebEnginePage::Feature)" ,
					:slot = "featurePermissionRequestedSlot()" ,
					:event = "featurePermissionRequested"
				],
				[ 	:signal = "findTextFinished(const QWebEngineFindTextResult)" ,
					:slot = "findTextFinishedSlot()" ,
					:event = "findTextFinished"
				],
				[ 	:signal = "fullScreenRequested(QWebEngineFullScreenRequest)" ,
					:slot = "fullScreenRequestedSlot()" ,
					:event = "fullScreenRequested"
				],
				[ 	:signal = "geometryChangeRequested(const QRect)" ,
					:slot = "geometryChangeRequestedSlot()" ,
					:event = "geometryChangeRequested"
				],
				[ 	:signal = "iconChanged(const QIcon)" ,
					:slot = "iconChangedSlot()" ,
					:event = "iconChanged"
				],
				[ 	:signal = "iconUrlChanged(const QUrl)" ,
					:slot = "iconUrlChangedSlot()" ,
					:event = "iconUrlChanged"
				],
//				[ 	:signal = "lifecycleStateChanged(QWebEnginePage::LifecycleState)" ,
//					:slot = "lifecycleStateChangedSlot()" ,
//					:event = "lifecycleStateChanged"
//				],
				[ 	:signal = "linkHovered(const QString)" ,
					:slot = "linkHoveredSlot()" ,
					:event = "linkHovered"
				],
				[ 	:signal = "loadFinished(bool)" ,
					:slot = "loadFinishedSlot()" ,
					:event = "loadFinished"
				],
				[ 	:signal = "loadProgress(int)" ,
					:slot = "loadProgressSlot()" ,
					:event = "loadProgress"
				],
				[ 	:signal = "loadStarted()" ,
					:slot = "loadStartedSlot()" ,
					:event = "loadStarted"
				],
				[ 	:signal = "pdfPrintingFinished(const QString,bool)" ,
					:slot = "pdfPrintingFinishedSlot()" ,
					:event = "pdfPrintingFinished"
				],
				[ 	:signal = "printRequested()" ,
					:slot = "printRequestedSlot()" ,
					:event = "printRequested"
				],
				[ 	:signal = "proxyAuthenticationRequired(const QUrl,QAuthenticator *,const QString)" ,
					:slot = "proxyAuthenticationRequiredSlot()" ,
					:event = "proxyAuthenticationRequired"
				],
				[ 	:signal = "quotaRequested(QWebEngineQuotaRequest)" ,
					:slot = "quotaRequestedSlot()" ,
					:event = "quotaRequested"
				],
				[ 	:signal = "recentlyAudibleChanged(bool)" ,
					:slot = "recentlyAudibleChangedSlot()" ,
					:event = "recentlyAudibleChanged"
				],
				[ 	:signal = "recommendedStateChanged(QWebEnginePage::LifecycleState)" ,
					:slot = "recommendedStateChangedSlot()" ,
					:event = "recommendedStateChanged"
				],
				[ 	:signal = "registerProtocolHandlerRequested(QWebEngineRegisterProtocolHandlerRequest)" ,
					:slot = "registerProtocolHandlerRequestedSlot()" ,
					:event = "registerProtocolHandlerRequested"
				],
				[ 	:signal = "renderProcessPidChanged(qint64)" ,
					:slot = "renderProcessPidChangedSlot()" ,
					:event = "renderProcessPidChanged"
				],
				[ 	:signal = "renderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus,int)" ,
					:slot = "renderProcessTerminatedSlot()" ,
					:event = "renderProcessTerminated"
				],
				[ 	:signal = "scrollPositionChanged(const QPointF)" ,
					:slot = "scrollPositionChangedSlot()" ,
					:event = "scrollPositionChanged"
				],
				[ 	:signal = "selectClientCertificate(QWebEngineClientCertificateSelection)" ,
					:slot = "selectClientCertificateSlot()" ,
					:event = "selectClientCertificate"
				],
				[ 	:signal = "selectionChanged()" ,
					:slot = "selectionChangedSlot()" ,
					:event = "selectionChanged"
				],
				[ 	:signal = "titleChanged(const QString)" ,
					:slot = "titleChangedSlot()" ,
					:event = "titleChanged"
				],
				[ 	:signal = "urlChanged(const QUrl)" ,
					:slot = "urlChangedSlot()" ,
					:event = "urlChanged"
				],
				[ 	:signal = "visibleChanged(bool)" ,
					:slot = "visibleChangedSlot()" ,
					:event = "visibleChanged"
				],
				[ 	:signal = "windowCloseRequested()" ,
					:slot = "windowCloseRequestedSlot()" ,
					:event = "windowCloseRequested"
				]
		]
	]
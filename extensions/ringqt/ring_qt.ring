
Func GetObjectPointerFromRingObject pObj
     if isobject(pObj)
	if isattribute(pObj,'pObject')
		return pObj.pObject
	else 
		raise('Error, The parameter is not a GUI object!')
	ok
     ok	
     return pObj		

Class QApp from QGuiApplication
	Func exec 
		return QApp_exec()

	Func quit 
		return QApp_quit()

	Func processEvents 
		return QApp_processEvents()

	Func styleWindows 
		return QApp_styleWindows()

	Func styleWindowsVista 
		return QApp_styleWindowsVista()

	Func styleFusion 
		return QApp_styleFusion()

	Func styleFusionBlack 
		return QApp_styleFusionBlack()

	Func styleFusionCustom P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12
		return QApp_styleFusionCustom(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7),GetObjectPointerFromRingObject(P8),GetObjectPointerFromRingObject(P9),GetObjectPointerFromRingObject(P10),GetObjectPointerFromRingObject(P11),GetObjectPointerFromRingObject(P12))

	Func closeAllWindows 
		return QApp_closeAllWindows()

	Func keyboardModifiers 
		return QApp_keyboardModifiers()

Class QDesktopServices
	Func openUrl P1
		return QDesktopServices_openUrl(GetObjectPointerFromRingObject(P1))

	Func setUrlHandler P1,P2,P3
		return QDesktopServices_setUrlHandler(P1,GetObjectPointerFromRingObject(P2),P3)

	Func unsetUrlHandler P1
		return QDesktopServices_unsetUrlHandler(P1)

Class QTest
	Func qsleep P1
		return QTest_qsleep(P1)

Class QObject

	pObject

	Func init 
		pObject = QObject_new()
		return self

	Func delete
		pObject = QObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func blockSignals P1
		return QObject_blockSignals(pObject,P1)

	Func children 
		return QObject_children(pObject)

	Func dumpObjectInfo 
		return QObject_dumpObjectInfo(pObject)

	Func dumpObjectTree 
		return QObject_dumpObjectTree(pObject)

	Func inherits P1
		return QObject_inherits(pObject,P1)

	Func installEventFilter P1
		return QObject_installEventFilter(pObject,GetObjectPointerFromRingObject(P1))

	Func isWidgetType 
		return QObject_isWidgetType(pObject)

	Func killTimer P1
		return QObject_killTimer(pObject,P1)

	Func moveToThread P1
		return QObject_moveToThread(pObject,GetObjectPointerFromRingObject(P1))

	Func objectName 
		return QObject_objectName(pObject)

	Func parent 
		pTempObj = new QObject
		pTempObj.pObject = QObject_parent(pObject)
		return pTempObj

	Func property P1
		pTempObj = new QVariant
		pTempObj.pObject = QObject_property(pObject,P1)
		return pTempObj

	Func removeEventFilter P1
		return QObject_removeEventFilter(pObject,GetObjectPointerFromRingObject(P1))

	Func setObjectName P1
		return QObject_setObjectName(pObject,P1)

	Func setParent P1
		return QObject_setParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setProperty P1,P2
		return QObject_setProperty(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func signalsBlocked 
		return QObject_signalsBlocked(pObject)

	Func startTimer P1
		return QObject_startTimer(pObject,P1)

	Func thread 
		pTempObj = new QThread
		pTempObj.pObject = QObject_thread(pObject)
		return pTempObj

	Func deleteLater 
		return QObject_deleteLater(pObject)

Class QWidget from QObject

	pObject

	Func init 
		pObject = QWidget_new()
		return self

	Func delete
		pObject = QWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func acceptDrops 
		return QWidget_acceptDrops(pObject)

	Func accessibleDescription 
		return QWidget_accessibleDescription(pObject)

	Func accessibleName 
		return QWidget_accessibleName(pObject)

	Func activateWindow 
		return QWidget_activateWindow(pObject)

	Func addAction P1
		return QWidget_addAction(pObject,GetObjectPointerFromRingObject(P1))

	Func adjustSize 
		return QWidget_adjustSize(pObject)

	Func autoFillBackground 
		return QWidget_autoFillBackground(pObject)

	Func backgroundRole 
		return QWidget_backgroundRole(pObject)

	Func baseSize 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_baseSize(pObject)
		return pTempObj

	Func childAt P1,P2
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_childAt(pObject,P1,P2)
		return pTempObj

	Func childrenRect 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_childrenRect(pObject)
		return pTempObj

	Func childrenRegion 
		pTempObj = new QRegion
		pTempObj.pObject = QWidget_childrenRegion(pObject)
		return pTempObj

	Func clearFocus 
		return QWidget_clearFocus(pObject)

	Func clearMask 
		return QWidget_clearMask(pObject)

	Func contentsMargins 
		return QWidget_contentsMargins(pObject)

	Func contentsRect 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_contentsRect(pObject)
		return pTempObj

	Func contextMenuPolicy 
		return QWidget_contextMenuPolicy(pObject)

	Func cursor 
		pTempObj = new QCursor
		pTempObj.pObject = QWidget_cursor(pObject)
		return pTempObj

	Func effectiveWinId 
		return QWidget_effectiveWinId(pObject)

	Func ensurePolished 
		return QWidget_ensurePolished(pObject)

	Func focusPolicy 
		return QWidget_focusPolicy(pObject)

	Func focusProxy 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_focusProxy(pObject)
		return pTempObj

	Func focusWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_focusWidget(pObject)
		return pTempObj

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QWidget_font(pObject)
		return pTempObj

	Func fontInfo 
		return QWidget_fontInfo(pObject)

	Func foregroundRole 
		return QWidget_foregroundRole(pObject)

	Func frameGeometry 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_frameGeometry(pObject)
		return pTempObj

	Func frameSize 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_frameSize(pObject)
		return pTempObj

	Func geometry 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_geometry(pObject)
		return pTempObj

	Func getContentsMargins P1,P2,P3,P4
		return QWidget_getContentsMargins(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func grab P1
		pTempObj = new QPixmap
		pTempObj.pObject = QWidget_grab(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func grabGesture P1,P2
		return QWidget_grabGesture(pObject,P1,P2)

	Func grabKeyboard 
		return QWidget_grabKeyboard(pObject)

	Func grabMouse 
		return QWidget_grabMouse(pObject)

	Func grabShortcut P1,P2
		return QWidget_grabShortcut(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func graphicsEffect 
		return QWidget_graphicsEffect(pObject)

	Func graphicsProxyWidget 
		return QWidget_graphicsProxyWidget(pObject)

	Func hasFocus 
		return QWidget_hasFocus(pObject)

	Func hasMouseTracking 
		return QWidget_hasMouseTracking(pObject)

	Func height 
		return QWidget_height(pObject)

	Func heightForWidth P1
		return QWidget_heightForWidth(pObject,P1)

	Func inputMethodHints 
		return QWidget_inputMethodHints(pObject)

	Func inputMethodQuery P1
		pTempObj = new QVariant
		pTempObj.pObject = QWidget_inputMethodQuery(pObject,P1)
		return pTempObj

	Func insertAction P1,P2
		return QWidget_insertAction(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func isActiveWindow 
		return QWidget_isActiveWindow(pObject)

	Func isAncestorOf P1
		return QWidget_isAncestorOf(pObject,GetObjectPointerFromRingObject(P1))

	Func isEnabled 
		return QWidget_isEnabled(pObject)

	Func isEnabledTo P1
		return QWidget_isEnabledTo(pObject,GetObjectPointerFromRingObject(P1))

	Func isFullScreen 
		return QWidget_isFullScreen(pObject)

	Func isHidden 
		return QWidget_isHidden(pObject)

	Func isMaximized 
		return QWidget_isMaximized(pObject)

	Func isMinimized 
		return QWidget_isMinimized(pObject)

	Func isModal 
		return QWidget_isModal(pObject)

	Func isVisible 
		return QWidget_isVisible(pObject)

	Func isVisibleTo P1
		return QWidget_isVisibleTo(pObject,GetObjectPointerFromRingObject(P1))

	Func isWindow 
		return QWidget_isWindow(pObject)

	Func isWindowModified 
		return QWidget_isWindowModified(pObject)

	Func layout 
		pTempObj = new QLayout
		pTempObj.pObject = QWidget_layout(pObject)
		return pTempObj

	Func layoutDirection 
		return QWidget_layoutDirection(pObject)

	Func locale 
		return QWidget_locale(pObject)

	Func mapFrom P1,P2
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapFrom(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func mapFromGlobal P1
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapFromGlobal(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapFromParent P1
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapFromParent(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapTo P1,P2
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapTo(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func mapToGlobal P1
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapToGlobal(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapToParent P1
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_mapToParent(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mask 
		pTempObj = new QRegion
		pTempObj.pObject = QWidget_mask(pObject)
		return pTempObj

	Func maximumHeight 
		return QWidget_maximumHeight(pObject)

	Func maximumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_maximumSize(pObject)
		return pTempObj

	Func maximumWidth 
		return QWidget_maximumWidth(pObject)

	Func minimumHeight 
		return QWidget_minimumHeight(pObject)

	Func minimumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_minimumSize(pObject)
		return pTempObj

	Func minimumWidth 
		return QWidget_minimumWidth(pObject)

	Func move P1,P2
		return QWidget_move(pObject,P1,P2)

	Func nativeParentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_nativeParentWidget(pObject)
		return pTempObj

	Func nextInFocusChain 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_nextInFocusChain(pObject)
		return pTempObj

	Func normalGeometry 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_normalGeometry(pObject)
		return pTempObj

	Func overrideWindowFlags P1
		return QWidget_overrideWindowFlags(pObject,P1)

	Func palette 
		return QWidget_palette(pObject)

	Func parentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_parentWidget(pObject)
		return pTempObj

	Func pos 
		pTempObj = new QPoint
		pTempObj.pObject = QWidget_pos(pObject)
		return pTempObj

	Func previousInFocusChain 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_previousInFocusChain(pObject)
		return pTempObj

	Func rect 
		pTempObj = new QRect
		pTempObj.pObject = QWidget_rect(pObject)
		return pTempObj

	Func releaseKeyboard 
		return QWidget_releaseKeyboard(pObject)

	Func releaseMouse 
		return QWidget_releaseMouse(pObject)

	Func releaseShortcut P1
		return QWidget_releaseShortcut(pObject,P1)

	Func removeAction P1
		return QWidget_removeAction(pObject,GetObjectPointerFromRingObject(P1))

	Func render P1,P2,P3,P4
		return QWidget_render(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),P4)

	Func repaint 
		return QWidget_repaint(pObject)

	Func resize P1,P2
		return QWidget_resize(pObject,P1,P2)

	Func restoreGeometry P1
		return QWidget_restoreGeometry(pObject,GetObjectPointerFromRingObject(P1))

	Func saveGeometry 
		pTempObj = new QByteArray
		pTempObj.pObject = QWidget_saveGeometry(pObject)
		return pTempObj

	Func scroll P1,P2
		return QWidget_scroll(pObject,P1,P2)

	Func setAcceptDrops P1
		return QWidget_setAcceptDrops(pObject,P1)

	Func setAccessibleDescription P1
		return QWidget_setAccessibleDescription(pObject,P1)

	Func setAccessibleName P1
		return QWidget_setAccessibleName(pObject,P1)

	Func setAttribute P1,P2
		return QWidget_setAttribute(pObject,P1,P2)

	Func setAutoFillBackground P1
		return QWidget_setAutoFillBackground(pObject,P1)

	Func setBackgroundRole P1
		return QWidget_setBackgroundRole(pObject,P1)

	Func setBaseSize P1,P2
		return QWidget_setBaseSize(pObject,P1,P2)

	Func setContentsMargins P1,P2,P3,P4
		return QWidget_setContentsMargins(pObject,P1,P2,P3,P4)

	Func setContextMenuPolicy P1
		return QWidget_setContextMenuPolicy(pObject,P1)

	Func setCursor P1
		return QWidget_setCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setFixedHeight P1
		return QWidget_setFixedHeight(pObject,P1)

	Func setFixedSize P1,P2
		return QWidget_setFixedSize(pObject,P1,P2)

	Func setFixedWidth P1
		return QWidget_setFixedWidth(pObject,P1)

	Func setFocus P1
		return QWidget_setFocus(pObject,P1)

	Func setFocusPolicy P1
		return QWidget_setFocusPolicy(pObject,P1)

	Func setFocusProxy P1
		return QWidget_setFocusProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setFont P1
		return QWidget_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setForegroundRole P1
		return QWidget_setForegroundRole(pObject,P1)

	Func setGeometry P1,P2,P3,P4
		return QWidget_setGeometry(pObject,P1,P2,P3,P4)

	Func setGraphicsEffect P1
		return QWidget_setGraphicsEffect(pObject,GetObjectPointerFromRingObject(P1))

	Func setInputMethodHints P1
		return QWidget_setInputMethodHints(pObject,P1)

	Func setLayout P1
		return QWidget_setLayout(pObject,GetObjectPointerFromRingObject(P1))

	Func setLayoutDirection P1
		return QWidget_setLayoutDirection(pObject,P1)

	Func setLocale P1
		return QWidget_setLocale(pObject,GetObjectPointerFromRingObject(P1))

	Func setMask P1
		return QWidget_setMask(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaximumHeight P1
		return QWidget_setMaximumHeight(pObject,P1)

	Func setMaximumSize P1,P2
		return QWidget_setMaximumSize(pObject,P1,P2)

	Func setMaximumWidth P1
		return QWidget_setMaximumWidth(pObject,P1)

	Func setMinimumHeight P1
		return QWidget_setMinimumHeight(pObject,P1)

	Func setMinimumSize P1,P2
		return QWidget_setMinimumSize(pObject,P1,P2)

	Func setMinimumWidth P1
		return QWidget_setMinimumWidth(pObject,P1)

	Func setMouseTracking P1
		return QWidget_setMouseTracking(pObject,P1)

	Func setPalette P1
		return QWidget_setPalette(pObject,GetObjectPointerFromRingObject(P1))

	Func setParent P1
		return QWidget_setParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setShortcutAutoRepeat P1,P2
		return QWidget_setShortcutAutoRepeat(pObject,P1,P2)

	Func setShortcutEnabled P1,P2
		return QWidget_setShortcutEnabled(pObject,P1,P2)

	Func setSizeIncrement P1,P2
		return QWidget_setSizeIncrement(pObject,P1,P2)

	Func setSizePolicy P1,P2
		return QWidget_setSizePolicy(pObject,P1,P2)

	Func setStatusTip P1
		return QWidget_setStatusTip(pObject,P1)

	Func setStyle P1
		return QWidget_setStyle(pObject,GetObjectPointerFromRingObject(P1))

	Func setToolTip P1
		return QWidget_setToolTip(pObject,P1)

	Func setUpdatesEnabled P1
		return QWidget_setUpdatesEnabled(pObject,P1)

	Func setWhatsThis P1
		return QWidget_setWhatsThis(pObject,P1)

	Func setWindowFilePath P1
		return QWidget_setWindowFilePath(pObject,P1)

	Func setWindowFlags P1
		return QWidget_setWindowFlags(pObject,P1)

	Func setWindowIcon P1
		return QWidget_setWindowIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setWindowIconText P1
		return QWidget_setWindowIconText(pObject,P1)

	Func setWindowModality P1
		return QWidget_setWindowModality(pObject,P1)

	Func setWindowOpacity P1
		return QWidget_setWindowOpacity(pObject,P1)

	Func setWindowRole P1
		return QWidget_setWindowRole(pObject,P1)

	Func setWindowState P1
		return QWidget_setWindowState(pObject,P1)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_size(pObject)
		return pTempObj

	Func sizeIncrement 
		pTempObj = new QSize
		pTempObj.pObject = QWidget_sizeIncrement(pObject)
		return pTempObj

	Func sizePolicy 
		return QWidget_sizePolicy(pObject)

	Func stackUnder P1
		return QWidget_stackUnder(pObject,GetObjectPointerFromRingObject(P1))

	Func statusTip 
		return QWidget_statusTip(pObject)

	Func style 
		return QWidget_style(pObject)

	Func styleSheet 
		return QWidget_styleSheet(pObject)

	Func testAttribute P1
		return QWidget_testAttribute(pObject,P1)

	Func toolTip 
		return QWidget_toolTip(pObject)

	Func underMouse 
		return QWidget_underMouse(pObject)

	Func ungrabGesture P1
		return QWidget_ungrabGesture(pObject,P1)

	Func unsetCursor 
		return QWidget_unsetCursor(pObject)

	Func unsetLayoutDirection 
		return QWidget_unsetLayoutDirection(pObject)

	Func unsetLocale 
		return QWidget_unsetLocale(pObject)

	Func update P1,P2,P3,P4
		return QWidget_update(pObject,P1,P2,P3,P4)

	Func updateGeometry 
		return QWidget_updateGeometry(pObject)

	Func updatesEnabled 
		return QWidget_updatesEnabled(pObject)

	Func visibleRegion 
		pTempObj = new QRegion
		pTempObj.pObject = QWidget_visibleRegion(pObject)
		return pTempObj

	Func whatsThis 
		return QWidget_whatsThis(pObject)

	Func width 
		return QWidget_width(pObject)

	Func winId 
		return QWidget_winId(pObject)

	Func window 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_window(pObject)
		return pTempObj

	Func windowFilePath 
		return QWidget_windowFilePath(pObject)

	Func windowFlags 
		return QWidget_windowFlags(pObject)

	Func windowHandle 
		pTempObj = new QWindow
		pTempObj.pObject = QWidget_windowHandle(pObject)
		return pTempObj

	Func windowIcon 
		pTempObj = new QIcon
		pTempObj.pObject = QWidget_windowIcon(pObject)
		return pTempObj

	Func windowIconText 
		return QWidget_windowIconText(pObject)

	Func windowModality 
		return QWidget_windowModality(pObject)

	Func windowOpacity 
		return QWidget_windowOpacity(pObject)

	Func windowRole 
		return QWidget_windowRole(pObject)

	Func windowState 
		return QWidget_windowState(pObject)

	Func windowTitle 
		return QWidget_windowTitle(pObject)

	Func windowType 
		return QWidget_windowType(pObject)

	Func x 
		return QWidget_x(pObject)

	Func y 
		return QWidget_y(pObject)

	Func close 
		return QWidget_close(pObject)

	Func hide 
		return QWidget_hide(pObject)

	Func lower 
		return QWidget_lower(pObject)

	Func raise 
		return QWidget_raise(pObject)

	Func setDisabled P1
		return QWidget_setDisabled(pObject,P1)

	Func setEnabled P1
		return QWidget_setEnabled(pObject,P1)

	Func setHidden P1
		return QWidget_setHidden(pObject,P1)

	Func setStyleSheet P1
		return QWidget_setStyleSheet(pObject,P1)

	Func setWindowModified P1
		return QWidget_setWindowModified(pObject,P1)

	Func setWindowTitle P1
		return QWidget_setWindowTitle(pObject,P1)

	Func show 
		return QWidget_show(pObject)

	Func showFullScreen 
		return QWidget_showFullScreen(pObject)

	Func showMaximized 
		return QWidget_showMaximized(pObject)

	Func showMinimized 
		return QWidget_showMinimized(pObject)

	Func showNormal 
		return QWidget_showNormal(pObject)

	Func find P1
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_find(pObject,P1)
		return pTempObj

	Func keyboardGrabber 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_keyboardGrabber(pObject)
		return pTempObj

	Func mouseGrabber 
		pTempObj = new QWidget
		pTempObj.pObject = QWidget_mouseGrabber(pObject)
		return pTempObj

	Func setTabOrder P1,P2
		return QWidget_setTabOrder(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

Class QLabel from QWidget

	pObject

	Func init P1
		pObject = QLabel_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QLabel_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alignment 
		return QLabel_alignment(pObject)

	Func buddy 
		pTempObj = new QWidget
		pTempObj.pObject = QLabel_buddy(pObject)
		return pTempObj

	Func hasScaledContents 
		return QLabel_hasScaledContents(pObject)

	Func hasSelectedText 
		return QLabel_hasSelectedText(pObject)

	Func indent 
		return QLabel_indent(pObject)

	Func margin 
		return QLabel_margin(pObject)

	Func movie 
		return QLabel_movie(pObject)

	Func openExternalLinks 
		return QLabel_openExternalLinks(pObject)

	Func picture 
		pTempObj = new QPicture
		pTempObj.pObject = QLabel_picture(pObject)
		return pTempObj

	Func pixmap 
		pTempObj = new QPixmap
		pTempObj.pObject = QLabel_pixmap(pObject)
		return pTempObj

	Func selectedText 
		return QLabel_selectedText(pObject)

	Func selectionStart 
		return QLabel_selectionStart(pObject)

	Func setAlignment P1
		return QLabel_setAlignment(pObject,P1)

	Func setBuddy P1
		return QLabel_setBuddy(pObject,GetObjectPointerFromRingObject(P1))

	Func setIndent P1
		return QLabel_setIndent(pObject,P1)

	Func setMargin P1
		return QLabel_setMargin(pObject,P1)

	Func setOpenExternalLinks P1
		return QLabel_setOpenExternalLinks(pObject,P1)

	Func setScaledContents P1
		return QLabel_setScaledContents(pObject,P1)

	Func setSelection P1,P2
		return QLabel_setSelection(pObject,P1,P2)

	Func setTextFormat P1
		return QLabel_setTextFormat(pObject,P1)

	Func setTextInteractionFlags P1
		return QLabel_setTextInteractionFlags(pObject,P1)

	Func setWordWrap P1
		return QLabel_setWordWrap(pObject,P1)

	Func text 
		return QLabel_text(pObject)

	Func textFormat 
		return QLabel_textFormat(pObject)

	Func textInteractionFlags 
		return QLabel_textInteractionFlags(pObject)

	Func wordWrap 
		return QLabel_wordWrap(pObject)

	Func clear 
		return QLabel_clear(pObject)

	Func setMovie P1
		return QLabel_setMovie(pObject,GetObjectPointerFromRingObject(P1))

	Func setNum P1
		return QLabel_setNum(pObject,P1)

	Func setPicture P1
		return QLabel_setPicture(pObject,GetObjectPointerFromRingObject(P1))

	Func setPixmap P1
		return QLabel_setPixmap(pObject,GetObjectPointerFromRingObject(P1))

	Func setText P1
		return QLabel_setText(pObject,P1)

Class QPushButton from QAbstractButton

	pObject

	Func init P1
		pObject = QPushButton_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QPushButton_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setText P1
		return QPushButton_setText(pObject,P1)

	Func setClickEvent P1
		return QPushButton_setClickEvent(pObject,P1)

	Func setIcon P1
		return QPushButton_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setIconSize P1
		return QPushButton_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func getClickEvent 
		return QPushButton_getClickEvent(pObject)

Class QBitmap from QPixmap

	pObject

	Func init 
		pObject = QBitmap_new()
		return self

	Func delete
		pObject = QBitmap_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QBitmap_clear(pObject)

	Func swap P1
		return QBitmap_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func transformed P1
		pTempObj = new QBitmap
		pTempObj.pObject = QBitmap_transformed(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromData P1,P2,P3
		pTempObj = new QBitmap
		pTempObj.pObject = QBitmap_fromData(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func fromImage P1,P2
		pTempObj = new QBitmap
		pTempObj.pObject = QBitmap_fromImage(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

Class QPixmap

	pObject

	Func init P1
		pObject = QPixmap_new(P1)
		return self

	Func delete
		pObject = QPixmap_delete(pObject)

	Func ObjectPointer
		return pObject

	Func copy P1,P2,P3,P4
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_copy(pObject,P1,P2,P3,P4)
		return pTempObj

	Func scaled P1,P2,P3,P4
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaled(pObject,P1,P2,P3,P4)
		return pTempObj

	Func width 
		return QPixmap_width(pObject)

	Func height 
		return QPixmap_height(pObject)

	Func createMaskFromColor P1,P2
		pTempObj = new QBitmap
		pTempObj.pObject = QPixmap_createMaskFromColor(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func mask 
		pTempObj = new QBitmap
		pTempObj.pObject = QPixmap_mask(pObject)
		return pTempObj

	Func setMask P1
		return QPixmap_setMask(pObject,GetObjectPointerFromRingObject(P1))

	Func fill P1
		return QPixmap_fill(pObject,GetObjectPointerFromRingObject(P1))

	Func fromImage P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImage(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func loadpixmap P1,P2,P3
		return QPixmap_load(pObject,P1,P2,P3)

	Func cacheKey 
		return QPixmap_cacheKey(pObject)

	Func convertFromImage P1,P2
		return QPixmap_convertFromImage(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func copy_2 P1
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_copy_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func createHeuristicMask P1
		pTempObj = new QBitmap
		pTempObj.pObject = QPixmap_createHeuristicMask(pObject,P1)
		return pTempObj

	Func depth 
		return QPixmap_depth(pObject)

	Func detach 
		return QPixmap_detach(pObject)

	Func devicePixelRatio 
		return QPixmap_devicePixelRatio(pObject)

	Func hasAlpha 
		return QPixmap_hasAlpha(pObject)

	Func hasAlphaChannel 
		return QPixmap_hasAlphaChannel(pObject)

	Func isNull 
		return QPixmap_isNull(pObject)

	Func isQBitmap 
		return QPixmap_isQBitmap(pObject)

	Func loadFromData P1,P2,P3,P4
		return QPixmap_loadFromData(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3,P4)

	Func loadFromData_2 P1,P2,P3
		return QPixmap_loadFromData_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func rect 
		pTempObj = new QRect
		pTempObj.pObject = QPixmap_rect(pObject)
		return pTempObj

	Func save P1,P2,P3
		return QPixmap_save(pObject,P1,P2,P3)

	Func save_2 P1,P2,P3
		return QPixmap_save_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func scaled_2 P1,P2,P3
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaled_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func scaledToHeight P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaledToHeight(pObject,P1,P2)
		return pTempObj

	Func scaledToWidth P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_scaledToWidth(pObject,P1,P2)
		return pTempObj

	Func scroll P1,P2,P3,P4,P5,P6,P7
		return QPixmap_scroll(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func scroll_2 P1,P2,P3,P4
		return QPixmap_scroll_2(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func setDevicePixelRatio P1
		return QPixmap_setDevicePixelRatio(pObject,P1)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QPixmap_size(pObject)
		return pTempObj

	Func swap P1
		return QPixmap_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toImage 
		pTempObj = new QImage
		pTempObj.pObject = QPixmap_toImage(pObject)
		return pTempObj

	Func transformed P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_transformed(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func transformed_2 P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_transformed_2(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func defaultDepth 
		return QPixmap_defaultDepth(pObject)

	Func fromImage_2 P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImage_2(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func fromImageReader P1,P2
		pTempObj = new QPixmap
		pTempObj.pObject = QPixmap_fromImageReader(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func trueMatrix P1,P2,P3
		return QPixmap_trueMatrix(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func trueMatrix_2 P1,P2,P3
		return QPixmap_trueMatrix_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

Class QLineEdit from QWidget

	pObject

	Func init P1
		pObject = QLineEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QLineEdit_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alignment 
		return QLineEdit_alignment(pObject)

	Func backspace 
		return QLineEdit_backspace(pObject)

	Func completer 
		pTempObj = new QCompleter
		pTempObj.pObject = QLineEdit_completer(pObject)
		return pTempObj

	Func createStandardContextMenu 
		pTempObj = new QMenu
		pTempObj.pObject = QLineEdit_createStandardContextMenu(pObject)
		return pTempObj

	Func cursorBackward P1,P2
		return QLineEdit_cursorBackward(pObject,P1,P2)

	Func cursorForward P1,P2
		return QLineEdit_cursorForward(pObject,P1,P2)

	Func cursorMoveStyle 
		return QLineEdit_cursorMoveStyle(pObject)

	Func cursorPosition 
		return QLineEdit_cursorPosition(pObject)

	Func cursorPositionAt P1
		return QLineEdit_cursorPositionAt(pObject,GetObjectPointerFromRingObject(P1))

	Func cursorWordBackward P1
		return QLineEdit_cursorWordBackward(pObject,P1)

	Func cursorWordForward P1
		return QLineEdit_cursorWordForward(pObject,P1)

	Func del 
		return QLineEdit_del(pObject)

	Func deselect 
		return QLineEdit_deselect(pObject)

	Func displayText 
		return QLineEdit_displayText(pObject)

	Func dragEnabled 
		return QLineEdit_dragEnabled(pObject)

	Func echoMode 
		return QLineEdit_echoMode(pObject)

	Func endtext P1
		return QLineEdit_end(pObject,P1)

	Func getTextMargins P1,P2,P3,P4
		return QLineEdit_getTextMargins(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func hasAcceptableInput 
		return QLineEdit_hasAcceptableInput(pObject)

	Func hasFrame 
		return QLineEdit_hasFrame(pObject)

	Func hasSelectedText 
		return QLineEdit_hasSelectedText(pObject)

	Func home P1
		return QLineEdit_home(pObject,P1)

	Func inputMask 
		return QLineEdit_inputMask(pObject)

	Func insert P1
		return QLineEdit_insert(pObject,P1)

	Func isModified 
		return QLineEdit_isModified(pObject)

	Func isReadOnly 
		return QLineEdit_isReadOnly(pObject)

	Func isRedoAvailable 
		return QLineEdit_isRedoAvailable(pObject)

	Func isUndoAvailable 
		return QLineEdit_isUndoAvailable(pObject)

	Func maxLength 
		return QLineEdit_maxLength(pObject)

	Func placeholderText 
		return QLineEdit_placeholderText(pObject)

	Func selectedText 
		return QLineEdit_selectedText(pObject)

	Func selectionStart 
		return QLineEdit_selectionStart(pObject)

	Func setAlignment P1
		return QLineEdit_setAlignment(pObject,P1)

	Func setCompleter P1
		return QLineEdit_setCompleter(pObject,GetObjectPointerFromRingObject(P1))

	Func setCursorMoveStyle P1
		return QLineEdit_setCursorMoveStyle(pObject,P1)

	Func setCursorPosition P1
		return QLineEdit_setCursorPosition(pObject,P1)

	Func setDragEnabled P1
		return QLineEdit_setDragEnabled(pObject,P1)

	Func setEchoMode P1
		return QLineEdit_setEchoMode(pObject,P1)

	Func setFrame P1
		return QLineEdit_setFrame(pObject,P1)

	Func setInputMask P1
		return QLineEdit_setInputMask(pObject,P1)

	Func setMaxLength P1
		return QLineEdit_setMaxLength(pObject,P1)

	Func setModified P1
		return QLineEdit_setModified(pObject,P1)

	Func setPlaceholderText P1
		return QLineEdit_setPlaceholderText(pObject,P1)

	Func setReadOnly P1
		return QLineEdit_setReadOnly(pObject,P1)

	Func setSelection P1,P2
		return QLineEdit_setSelection(pObject,P1,P2)

	Func setTextMargins P1,P2,P3,P4
		return QLineEdit_setTextMargins(pObject,P1,P2,P3,P4)

	Func setValidator P1
		return QLineEdit_setValidator(pObject,GetObjectPointerFromRingObject(P1))

	Func text 
		return QLineEdit_text(pObject)

	Func textMargins 
		return QLineEdit_textMargins(pObject)

	Func validator 
		return QLineEdit_validator(pObject)

	Func clear 
		return QLineEdit_clear(pObject)

	Func copy 
		return QLineEdit_copy(pObject)

	Func cut 
		return QLineEdit_cut(pObject)

	Func paste 
		return QLineEdit_paste(pObject)

	Func redo 
		return QLineEdit_redo(pObject)

	Func selectAll 
		return QLineEdit_selectAll(pObject)

	Func setText P1
		return QLineEdit_setText(pObject,P1)

	Func undo 
		return QLineEdit_undo(pObject)

	Func setTextChangedEvent P1
		return QLineEdit_setTextChangedEvent(pObject,P1)

	Func setcursorPositionChangedEvent P1
		return QLineEdit_setcursorPositionChangedEvent(pObject,P1)

	Func seteditingFinishedEvent P1
		return QLineEdit_seteditingFinishedEvent(pObject,P1)

	Func setreturnPressedEvent P1
		return QLineEdit_setreturnPressedEvent(pObject,P1)

	Func setselectionChangedEvent P1
		return QLineEdit_setselectionChangedEvent(pObject,P1)

	Func settextEditedEvent P1
		return QLineEdit_settextEditedEvent(pObject,P1)

	Func getTextChangedEvent 
		return QLineEdit_getTextChangedEvent(pObject)

	Func getcursorPositionChangedEvent 
		return QLineEdit_getcursorPositionChangedEvent(pObject)

	Func geteditingFinishedEvent 
		return QLineEdit_geteditingFinishedEvent(pObject)

	Func getreturnPressedEvent 
		return QLineEdit_getreturnPressedEvent(pObject)

	Func getselectionChangedEvent 
		return QLineEdit_getselectionChangedEvent(pObject)

	Func gettextEditedEvent 
		return QLineEdit_gettextEditedEvent(pObject)

Class QVBoxLayout from QBoxLayout

	pObject

	Func init 
		pObject = QVBoxLayout_new()
		return self

	Func delete
		pObject = QVBoxLayout_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addWidget P1
		return QVBoxLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func addLayout P1
		return QVBoxLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1))

Class QHBoxLayout from QBoxLayout

	pObject

	Func init 
		pObject = QHBoxLayout_new()
		return self

	Func delete
		pObject = QHBoxLayout_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addWidget P1
		return QHBoxLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func addLayout P1
		return QHBoxLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1))

Class QTextEdit from QAbstractScrollArea

	pObject

	Func init P1
		pObject = QTextEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTextEdit_delete(pObject)

	Func ObjectPointer
		return pObject

	Func acceptRichText 
		return QTextEdit_acceptRichText(pObject)

	Func alignment 
		return QTextEdit_alignment(pObject)

	Func anchorAt P1
		return QTextEdit_anchorAt(pObject,GetObjectPointerFromRingObject(P1))

	Func canPaste 
		return QTextEdit_canPaste(pObject)

	Func currentCharFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QTextEdit_currentCharFormat(pObject)
		return pTempObj

	Func currentFont 
		pTempObj = new QFont
		pTempObj.pObject = QTextEdit_currentFont(pObject)
		return pTempObj

	Func cursorForPosition P1
		pTempObj = new QTextCursor
		pTempObj.pObject = QTextEdit_cursorForPosition(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func cursorRect 
		pTempObj = new QRect
		pTempObj.pObject = QTextEdit_cursorRect(pObject)
		return pTempObj

	Func cursorWidth 
		return QTextEdit_cursorWidth(pObject)

	Func document 
		pTempObj = new QTextDocument
		pTempObj.pObject = QTextEdit_document(pObject)
		return pTempObj

	Func documentTitle 
		return QTextEdit_documentTitle(pObject)

	Func ensureCursorVisible 
		return QTextEdit_ensureCursorVisible(pObject)

	Func find P1,P2
		return QTextEdit_find(pObject,P1,P2)

	Func fontFamily 
		return QTextEdit_fontFamily(pObject)

	Func fontItalic 
		return QTextEdit_fontItalic(pObject)

	Func fontPointSize 
		return QTextEdit_fontPointSize(pObject)

	Func fontUnderline 
		return QTextEdit_fontUnderline(pObject)

	Func fontWeight 
		return QTextEdit_fontWeight(pObject)

	Func isReadOnly 
		return QTextEdit_isReadOnly(pObject)

	Func isUndoRedoEnabled 
		return QTextEdit_isUndoRedoEnabled(pObject)

	Func lineWrapColumnOrWidth 
		return QTextEdit_lineWrapColumnOrWidth(pObject)

	Func loadResource P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QTextEdit_loadResource(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func mergeCurrentCharFormat P1
		return QTextEdit_mergeCurrentCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func moveCursor P1,P2
		return QTextEdit_moveCursor(pObject,P1,P2)

	Func overwriteMode 
		return QTextEdit_overwriteMode(pObject)

	Func print P1
		return QTextEdit_print(pObject,GetObjectPointerFromRingObject(P1))

	Func setAcceptRichText P1
		return QTextEdit_setAcceptRichText(pObject,P1)

	Func setCurrentCharFormat P1
		return QTextEdit_setCurrentCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setCursorWidth P1
		return QTextEdit_setCursorWidth(pObject,P1)

	Func setDocument P1
		return QTextEdit_setDocument(pObject,GetObjectPointerFromRingObject(P1))

	Func setDocumentTitle P1
		return QTextEdit_setDocumentTitle(pObject,P1)

	Func setLineWrapColumnOrWidth P1
		return QTextEdit_setLineWrapColumnOrWidth(pObject,P1)

	Func setLineWrapMode P1
		return QTextEdit_setLineWrapMode(pObject,P1)

	Func setOverwriteMode P1
		return QTextEdit_setOverwriteMode(pObject,P1)

	Func setReadOnly P1
		return QTextEdit_setReadOnly(pObject,P1)

	Func setTabChangesFocus P1
		return QTextEdit_setTabChangesFocus(pObject,P1)

	Func setTabStopWidth P1
		return QTextEdit_setTabStopWidth(pObject,P1)

	Func setTextCursor P1
		return QTextEdit_setTextCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setTextInteractionFlags P1
		return QTextEdit_setTextInteractionFlags(pObject,P1)

	Func setUndoRedoEnabled P1
		return QTextEdit_setUndoRedoEnabled(pObject,P1)

	Func setWordWrapMode P1
		return QTextEdit_setWordWrapMode(pObject,P1)

	Func tabChangesFocus 
		return QTextEdit_tabChangesFocus(pObject)

	Func tabStopWidth 
		return QTextEdit_tabStopWidth(pObject)

	Func textBackgroundColor 
		pTempObj = new QColor
		pTempObj.pObject = QTextEdit_textBackgroundColor(pObject)
		return pTempObj

	Func textColor 
		pTempObj = new QColor
		pTempObj.pObject = QTextEdit_textColor(pObject)
		return pTempObj

	Func textCursor 
		pTempObj = new QTextCursor
		pTempObj.pObject = QTextEdit_textCursor(pObject)
		return pTempObj

	Func textInteractionFlags 
		return QTextEdit_textInteractionFlags(pObject)

	Func toHtml 
		return QTextEdit_toHtml(pObject)

	Func toPlainText 
		return QTextEdit_toPlainText(pObject)

	Func wordWrapMode 
		return QTextEdit_wordWrapMode(pObject)

	Func append P1
		return QTextEdit_append(pObject,P1)

	Func clear 
		return QTextEdit_clear(pObject)

	Func copy 
		return QTextEdit_copy(pObject)

	Func cut 
		return QTextEdit_cut(pObject)

	Func insertHtml P1
		return QTextEdit_insertHtml(pObject,P1)

	Func insertPlainText P1
		return QTextEdit_insertPlainText(pObject,P1)

	Func paste 
		return QTextEdit_paste(pObject)

	Func redo 
		return QTextEdit_redo(pObject)

	Func scrollToAnchor P1
		return QTextEdit_scrollToAnchor(pObject,P1)

	Func selectAll 
		return QTextEdit_selectAll(pObject)

	Func setAlignment P1
		return QTextEdit_setAlignment(pObject,P1)

	Func setCurrentFont P1
		return QTextEdit_setCurrentFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setFontFamily P1
		return QTextEdit_setFontFamily(pObject,P1)

	Func setFontItalic P1
		return QTextEdit_setFontItalic(pObject,P1)

	Func setFontPointSize P1
		return QTextEdit_setFontPointSize(pObject,P1)

	Func setFontUnderline P1
		return QTextEdit_setFontUnderline(pObject,P1)

	Func setFontWeight P1
		return QTextEdit_setFontWeight(pObject,P1)

	Func setHtml P1
		return QTextEdit_setHtml(pObject,P1)

	Func setPlainText P1
		return QTextEdit_setPlainText(pObject,P1)

	Func setText P1
		return QTextEdit_setText(pObject,P1)

	Func setTextBackgroundColor P1
		return QTextEdit_setTextBackgroundColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setTextColor P1
		return QTextEdit_setTextColor(pObject,GetObjectPointerFromRingObject(P1))

	Func undo 
		return QTextEdit_undo(pObject)

	Func zoomIn P1
		return QTextEdit_zoomIn(pObject,P1)

	Func zoomOut P1
		return QTextEdit_zoomOut(pObject,P1)

	Func setcopyAvailableEvent P1
		return QTextEdit_setcopyAvailableEvent(pObject,P1)

	Func setcurrentCharFormatChangedEvent P1
		return QTextEdit_setcurrentCharFormatChangedEvent(pObject,P1)

	Func setcursorPositionChangedEvent P1
		return QTextEdit_setcursorPositionChangedEvent(pObject,P1)

	Func setredoAvailableEvent P1
		return QTextEdit_setredoAvailableEvent(pObject,P1)

	Func setselectionChangedEvent P1
		return QTextEdit_setselectionChangedEvent(pObject,P1)

	Func settextChangedEvent P1
		return QTextEdit_settextChangedEvent(pObject,P1)

	Func setundoAvailableEvent P1
		return QTextEdit_setundoAvailableEvent(pObject,P1)

	Func getcopyAvailableEvent 
		return QTextEdit_getcopyAvailableEvent(pObject)

	Func getcurrentCharFormatChangedEvent 
		return QTextEdit_getcurrentCharFormatChangedEvent(pObject)

	Func getcursorPositionChangedEvent 
		return QTextEdit_getcursorPositionChangedEvent(pObject)

	Func getredoAvailableEvent 
		return QTextEdit_getredoAvailableEvent(pObject)

	Func getselectionChangedEvent 
		return QTextEdit_getselectionChangedEvent(pObject)

	Func gettextChangedEvent 
		return QTextEdit_gettextChangedEvent(pObject)

	Func getundoAvailableEvent 
		return QTextEdit_getundoAvailableEvent(pObject)

	Func cyanline 
		return QTextEdit_cyanline(pObject)

	Func setactivelinecolor P1
		return QTextEdit_setactivelinecolor(pObject,GetObjectPointerFromRingObject(P1))

Class QListWidget from QListView

	pObject

	Func init P1
		pObject = QListWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QListWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addItem P1
		return QListWidget_addItem(pObject,P1)

	Func count 
		return QListWidget_count(pObject)

	Func currentRow 
		return QListWidget_currentRow(pObject)

	Func editItem P1
		return QListWidget_editItem(pObject,GetObjectPointerFromRingObject(P1))

	Func insertItem P1,P2
		return QListWidget_insertItem(pObject,P1,P2)

	Func isSortingEnabled 
		return QListWidget_isSortingEnabled(pObject)

	Func item P1
		pTempObj = new QListWidgetItem
		pTempObj.pObject = QListWidget_item(pObject,P1)
		return pTempObj

	Func itemAt P1,P2
		pTempObj = new QListWidgetItem
		pTempObj.pObject = QListWidget_itemAt(pObject,P1,P2)
		return pTempObj

	Func itemWidget P1
		pTempObj = new QWidget
		pTempObj.pObject = QListWidget_itemWidget(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func openPersistentEditor P1
		return QListWidget_openPersistentEditor(pObject,GetObjectPointerFromRingObject(P1))

	Func removeItemWidget P1
		return QListWidget_removeItemWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func row P1
		return QListWidget_row(pObject,GetObjectPointerFromRingObject(P1))

	Func setCurrentItem P1,P2
		return QListWidget_setCurrentItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setCurrentRow P1,P2
		return QListWidget_setCurrentRow(pObject,P1,P2)

	Func setItemWidget P1,P2
		return QListWidget_setItemWidget(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setSortingEnabled P1
		return QListWidget_setSortingEnabled(pObject,P1)

	Func sortItems P1
		return QListWidget_sortItems(pObject,P1)

	Func takeItem P1
		pTempObj = new QListWidgetItem
		pTempObj.pObject = QListWidget_takeItem(pObject,P1)
		return pTempObj

	Func visualItemRect P1
		pTempObj = new QRect
		pTempObj.pObject = QListWidget_visualItemRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func clear 
		return QListWidget_clear(pObject)

	Func scrollToItem P1,P2
		return QListWidget_scrollToItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setcurrentItemChangedEvent P1
		return QListWidget_setcurrentItemChangedEvent(pObject,P1)

	Func setcurrentRowChangedEvent P1
		return QListWidget_setcurrentRowChangedEvent(pObject,P1)

	Func setcurrentTextChangedEvent P1
		return QListWidget_setcurrentTextChangedEvent(pObject,P1)

	Func setitemActivatedEvent P1
		return QListWidget_setitemActivatedEvent(pObject,P1)

	Func setitemChangedEvent P1
		return QListWidget_setitemChangedEvent(pObject,P1)

	Func setitemClickedEvent P1
		return QListWidget_setitemClickedEvent(pObject,P1)

	Func setitemDoubleClickedEvent P1
		return QListWidget_setitemDoubleClickedEvent(pObject,P1)

	Func setitemEnteredEvent P1
		return QListWidget_setitemEnteredEvent(pObject,P1)

	Func setitemPressedEvent P1
		return QListWidget_setitemPressedEvent(pObject,P1)

	Func setitemSelectionChangedEvent P1
		return QListWidget_setitemSelectionChangedEvent(pObject,P1)

	Func getcurrentItemChangedEvent 
		return QListWidget_getcurrentItemChangedEvent(pObject)

	Func getcurrentRowChangedEvent 
		return QListWidget_getcurrentRowChangedEvent(pObject)

	Func getcurrentTextChangedEvent 
		return QListWidget_getcurrentTextChangedEvent(pObject)

	Func getitemActivatedEvent 
		return QListWidget_getitemActivatedEvent(pObject)

	Func getitemChangedEvent 
		return QListWidget_getitemChangedEvent(pObject)

	Func getitemClickedEvent 
		return QListWidget_getitemClickedEvent(pObject)

	Func getitemDoubleClickedEvent 
		return QListWidget_getitemDoubleClickedEvent(pObject)

	Func getitemEnteredEvent 
		return QListWidget_getitemEnteredEvent(pObject)

	Func getitemPressedEvent 
		return QListWidget_getitemPressedEvent(pObject)

	Func getitemSelectionChangedEvent 
		return QListWidget_getitemSelectionChangedEvent(pObject)

Class QTreeView from QAbstractItemView

	pObject

	Func init P1
		pObject = QTreeView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTreeView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allColumnsShowFocus 
		return QTreeView_allColumnsShowFocus(pObject)

	Func autoExpandDelay 
		return QTreeView_autoExpandDelay(pObject)

	Func columnAt P1
		return QTreeView_columnAt(pObject,P1)

	Func columnViewportPosition P1
		return QTreeView_columnViewportPosition(pObject,P1)

	Func columnWidth P1
		return QTreeView_columnWidth(pObject,P1)

	Func expandsOnDoubleClick 
		return QTreeView_expandsOnDoubleClick(pObject)

	Func header 
		pTempObj = new QHeaderView
		pTempObj.pObject = QTreeView_header(pObject)
		return pTempObj

	Func indentation 
		return QTreeView_indentation(pObject)

	Func indexAbove P1
		return QTreeView_indexAbove(pObject,GetObjectPointerFromRingObject(P1))

	Func indexBelow P1
		return QTreeView_indexBelow(pObject,GetObjectPointerFromRingObject(P1))

	Func isAnimated 
		return QTreeView_isAnimated(pObject)

	Func isColumnHidden P1
		return QTreeView_isColumnHidden(pObject,P1)

	Func isExpanded P1
		return QTreeView_isExpanded(pObject,GetObjectPointerFromRingObject(P1))

	Func isFirstColumnSpanned P1,P2
		return QTreeView_isFirstColumnSpanned(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isHeaderHidden 
		return QTreeView_isHeaderHidden(pObject)

	Func isRowHidden P1,P2
		return QTreeView_isRowHidden(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isSortingEnabled 
		return QTreeView_isSortingEnabled(pObject)

	Func itemsExpandable 
		return QTreeView_itemsExpandable(pObject)

	Func rootIsDecorated 
		return QTreeView_rootIsDecorated(pObject)

	Func setAllColumnsShowFocus P1
		return QTreeView_setAllColumnsShowFocus(pObject,P1)

	Func setAnimated P1
		return QTreeView_setAnimated(pObject,P1)

	Func setAutoExpandDelay P1
		return QTreeView_setAutoExpandDelay(pObject,P1)

	Func setColumnHidden P1,P2
		return QTreeView_setColumnHidden(pObject,P1,P2)

	Func setColumnWidth P1,P2
		return QTreeView_setColumnWidth(pObject,P1,P2)

	Func setExpanded P1,P2
		return QTreeView_setExpanded(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setExpandsOnDoubleClick P1
		return QTreeView_setExpandsOnDoubleClick(pObject,P1)

	Func setFirstColumnSpanned P1,P2,P3
		return QTreeView_setFirstColumnSpanned(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setHeader P1
		return QTreeView_setHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func setHeaderHidden P1
		return QTreeView_setHeaderHidden(pObject,P1)

	Func setIndentation P1
		return QTreeView_setIndentation(pObject,P1)

	Func setItemsExpandable P1
		return QTreeView_setItemsExpandable(pObject,P1)

	Func setRootIsDecorated P1
		return QTreeView_setRootIsDecorated(pObject,P1)

	Func setRowHidden P1,P2,P3
		return QTreeView_setRowHidden(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setSortingEnabled P1
		return QTreeView_setSortingEnabled(pObject,P1)

	Func setUniformRowHeights P1
		return QTreeView_setUniformRowHeights(pObject,P1)

	Func setWordWrap P1
		return QTreeView_setWordWrap(pObject,P1)

	Func sortByColumn P1,P2
		return QTreeView_sortByColumn(pObject,P1,P2)

	Func uniformRowHeights 
		return QTreeView_uniformRowHeights(pObject)

	Func wordWrap 
		return QTreeView_wordWrap(pObject)

	Func dataChanged P1,P2
		return QTreeView_dataChanged(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func indexAt P1
		return QTreeView_indexAt(pObject,GetObjectPointerFromRingObject(P1))

	Func keyboardSearch P1
		return QTreeView_keyboardSearch(pObject,P1)

	Func reset 
		return QTreeView_reset(pObject)

	Func scrollTo P1,P2
		return QTreeView_scrollTo(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func selectAll 
		return QTreeView_selectAll(pObject)

	Func setModel P1
		return QTreeView_setModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setRootIndex P1
		return QTreeView_setRootIndex(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelectionModel P1
		return QTreeView_setSelectionModel(pObject,GetObjectPointerFromRingObject(P1))

	Func visualRect P1
		pTempObj = new QRect
		pTempObj.pObject = QTreeView_visualRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func collapse P1
		return QTreeView_collapse(pObject,GetObjectPointerFromRingObject(P1))

	Func collapseAll 
		return QTreeView_collapseAll(pObject)

	Func expand P1
		return QTreeView_expand(pObject,GetObjectPointerFromRingObject(P1))

	Func expandAll 
		return QTreeView_expandAll(pObject)

	Func expandToDepth P1
		return QTreeView_expandToDepth(pObject,P1)

	Func hideColumn P1
		return QTreeView_hideColumn(pObject,P1)

	Func resizeColumnToContents P1
		return QTreeView_resizeColumnToContents(pObject,P1)

	Func showColumn P1
		return QTreeView_showColumn(pObject,P1)

	Func setcollapsedEvent P1
		return QTreeView_setcollapsedEvent(pObject,P1)

	Func setexpandedEvent P1
		return QTreeView_setexpandedEvent(pObject,P1)

	Func setactivatedEvent P1
		return QTreeView_setactivatedEvent(pObject,P1)

	Func setclickedEvent P1
		return QTreeView_setclickedEvent(pObject,P1)

	Func setdoubleClickedEvent P1
		return QTreeView_setdoubleClickedEvent(pObject,P1)

	Func setenteredEvent P1
		return QTreeView_setenteredEvent(pObject,P1)

	Func setpressedEvent P1
		return QTreeView_setpressedEvent(pObject,P1)

	Func setviewportEnteredEvent P1
		return QTreeView_setviewportEnteredEvent(pObject,P1)

	Func getcollapsedEvent 
		return QTreeView_getcollapsedEvent(pObject)

	Func getexpandedEvent 
		return QTreeView_getexpandedEvent(pObject)

	Func getactivatedEvent 
		return QTreeView_getactivatedEvent(pObject)

	Func getclickedEvent 
		return QTreeView_getclickedEvent(pObject)

	Func getdoubleClickedEvent 
		return QTreeView_getdoubleClickedEvent(pObject)

	Func getenteredEvent 
		return QTreeView_getenteredEvent(pObject)

	Func getpressedEvent 
		return QTreeView_getpressedEvent(pObject)

	Func getviewportEnteredEvent 
		return QTreeView_getviewportEnteredEvent(pObject)

Class QDir

	pObject

	Func init 
		pObject = QDir_new()
		return self

	Func delete
		pObject = QDir_delete(pObject)

	Func ObjectPointer
		return pObject

	Func absoluteFilePath P1
		return QDir_absoluteFilePath(pObject,P1)

	Func absolutePath 
		return QDir_absolutePath(pObject)

	Func canonicalPath 
		return QDir_canonicalPath(pObject)

	Func cd P1
		return QDir_cd(pObject,P1)

	Func cdUp 
		return QDir_cdUp(pObject)

	Func count 
		return QDir_count(pObject)

	Func dirName 
		return QDir_dirName(pObject)

	Func entryInfoList P1,P2,P3
		return QDir_entryInfoList(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func entryInfoList_2 P1,P2
		return QDir_entryInfoList_2(pObject,P1,P2)

	Func entryList P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QDir_entryList(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func entryList_2 P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QDir_entryList_2(pObject,P1,P2)
		return pTempObj

	Func exists P1
		return QDir_exists(pObject,P1)

	Func exists_2 
		return QDir_exists_2(pObject)

	Func filePath P1
		return QDir_filePath(pObject,P1)

	Func filter 
		return QDir_filter(pObject)

	Func isAbsolute 
		return QDir_isAbsolute(pObject)

	Func isReadable 
		return QDir_isReadable(pObject)

	Func isRelative 
		return QDir_isRelative(pObject)

	Func isRoot 
		return QDir_isRoot(pObject)

	Func makeAbsolute 
		return QDir_makeAbsolute(pObject)

	Func mkdir P1
		return QDir_mkdir(pObject,P1)

	Func mkpath P1
		return QDir_mkpath(pObject,P1)

	Func nameFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QDir_nameFilters(pObject)
		return pTempObj

	Func path 
		return QDir_path(pObject)

	Func refresh 
		return QDir_refresh(pObject)

	Func relativeFilePath P1
		return QDir_relativeFilePath(pObject,P1)

	Func remove P1
		return QDir_remove(pObject,P1)

	Func removeRecursively 
		return QDir_removeRecursively(pObject)

	Func rename P1,P2
		return QDir_rename(pObject,P1,P2)

	Func rmdir P1
		return QDir_rmdir(pObject,P1)

	Func rmpath P1
		return QDir_rmpath(pObject,P1)

	Func setFilter P1
		return QDir_setFilter(pObject,P1)

	Func setNameFilters P1
		return QDir_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setPath P1
		return QDir_setPath(pObject,P1)

	Func setSorting P1
		return QDir_setSorting(pObject,P1)

	Func sorting 
		return QDir_sorting(pObject)

	Func swap P1
		return QDir_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func addSearchPath P1,P2
		return QDir_addSearchPath(pObject,P1,P2)

	Func cleanPath P1
		return QDir_cleanPath(pObject,P1)

	Func current 
		pTempObj = new QDir
		pTempObj.pObject = QDir_current(pObject)
		return pTempObj

	Func currentPath 
		return QDir_currentPath(pObject)

	Func drives 
		return QDir_drives(pObject)

	Func fromNativeSeparators P1
		return QDir_fromNativeSeparators(pObject,P1)

	Func home 
		pTempObj = new QDir
		pTempObj.pObject = QDir_home(pObject)
		return pTempObj

	Func homePath 
		return QDir_homePath(pObject)

	Func isAbsolutePath P1
		return QDir_isAbsolutePath(pObject,P1)

	Func isRelativePath P1
		return QDir_isRelativePath(pObject,P1)

	Func match P1,P2
		return QDir_match(pObject,P1,P2)

	Func match_2 P1,P2
		return QDir_match_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func root 
		pTempObj = new QDir
		pTempObj.pObject = QDir_root(pObject)
		return pTempObj

	Func rootPath 
		return QDir_rootPath(pObject)

	Func searchPaths P1
		pTempObj = new QStringList
		pTempObj.pObject = QDir_searchPaths(pObject,P1)
		return pTempObj

	Func separator 
		return QDir_separator(pObject)

	Func setCurrent P1
		return QDir_setCurrent(pObject,P1)

	Func setSearchPaths P1,P2
		return QDir_setSearchPaths(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func temp 
		pTempObj = new QDir
		pTempObj.pObject = QDir_temp(pObject)
		return pTempObj

	Func tempPath 
		return QDir_tempPath(pObject)

	Func toNativeSeparators P1
		return QDir_toNativeSeparators(pObject,P1)

Class QFileSystemModel

	pObject

	Func init 
		pObject = QFileSystemModel_new()
		return self

	Func delete
		pObject = QFileSystemModel_delete(pObject)

	Func ObjectPointer
		return pObject

	Func fileIcon P1
		pTempObj = new QIcon
		pTempObj.pObject = QFileSystemModel_fileIcon(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fileInfo P1
		pTempObj = new QFileInfo
		pTempObj.pObject = QFileSystemModel_fileInfo(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fileName P1
		return QFileSystemModel_fileName(pObject,GetObjectPointerFromRingObject(P1))

	Func filePath P1
		return QFileSystemModel_filePath(pObject,GetObjectPointerFromRingObject(P1))

	Func filter 
		return QFileSystemModel_filter(pObject)

	Func iconProvider 
		return QFileSystemModel_iconProvider(pObject)

	Func index P1,P2
		return QFileSystemModel_index(pObject,P1,P2)

	Func isDir P1
		return QFileSystemModel_isDir(pObject,GetObjectPointerFromRingObject(P1))

	Func isReadOnly 
		return QFileSystemModel_isReadOnly(pObject)

	Func lastModified P1
		pTempObj = new QDateTime
		pTempObj.pObject = QFileSystemModel_lastModified(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mkdir P1,P2
		return QFileSystemModel_mkdir(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func myComputer P1
		pTempObj = new QVariant
		pTempObj.pObject = QFileSystemModel_myComputer(pObject,P1)
		return pTempObj

	Func nameFilterDisables 
		return QFileSystemModel_nameFilterDisables(pObject)

	Func nameFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QFileSystemModel_nameFilters(pObject)
		return pTempObj

	Func permissions P1
		return QFileSystemModel_permissions(pObject,GetObjectPointerFromRingObject(P1))

	Func remove P1
		return QFileSystemModel_remove(pObject,GetObjectPointerFromRingObject(P1))

	Func resolveSymlinks 
		return QFileSystemModel_resolveSymlinks(pObject)

	Func rmdir P1
		return QFileSystemModel_rmdir(pObject,GetObjectPointerFromRingObject(P1))

	Func rootDirectory 
		pTempObj = new QDir
		pTempObj.pObject = QFileSystemModel_rootDirectory(pObject)
		return pTempObj

	Func rootPath 
		return QFileSystemModel_rootPath(pObject)

	Func setFilter P1
		return QFileSystemModel_setFilter(pObject,P1)

	Func setIconProvider P1
		return QFileSystemModel_setIconProvider(pObject,GetObjectPointerFromRingObject(P1))

	Func setNameFilterDisables P1
		return QFileSystemModel_setNameFilterDisables(pObject,P1)

	Func setNameFilters P1
		return QFileSystemModel_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setReadOnly P1
		return QFileSystemModel_setReadOnly(pObject,P1)

	Func setResolveSymlinks P1
		return QFileSystemModel_setResolveSymlinks(pObject,P1)

	Func setRootPath P1
		return QFileSystemModel_setRootPath(pObject,P1)

	Func size P1
		return QFileSystemModel_size(pObject,GetObjectPointerFromRingObject(P1))

	Func type P1
		return QFileSystemModel_type(pObject,GetObjectPointerFromRingObject(P1))

	Func canFetchMore P1
		return QFileSystemModel_canFetchMore(pObject,GetObjectPointerFromRingObject(P1))

	Func columnCount 
		return QFileSystemModel_columnCount(pObject)

	Func data P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QFileSystemModel_data(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func dropMimeData P1,P2,P3,P4,P5
		return QFileSystemModel_dropMimeData(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,GetObjectPointerFromRingObject(P5))

	Func fetchMore P1
		return QFileSystemModel_fetchMore(pObject,GetObjectPointerFromRingObject(P1))

	Func flags P1
		return QFileSystemModel_flags(pObject,GetObjectPointerFromRingObject(P1))

	Func hasChildren P1
		return QFileSystemModel_hasChildren(pObject,GetObjectPointerFromRingObject(P1))

	Func headerData P1,P2,P3
		pTempObj = new QVariant
		pTempObj.pObject = QFileSystemModel_headerData(pObject,P1,P2,P3)
		return pTempObj

	Func mimeData P1
		return QFileSystemModel_mimeData(pObject,GetObjectPointerFromRingObject(P1))

	Func mimeTypes 
		pTempObj = new QStringList
		pTempObj.pObject = QFileSystemModel_mimeTypes(pObject)
		return pTempObj

	Func parent P1
		return QFileSystemModel_parent(pObject,GetObjectPointerFromRingObject(P1))

	Func rowCount P1
		return QFileSystemModel_rowCount(pObject,GetObjectPointerFromRingObject(P1))

	Func setData P1,P2,P3
		return QFileSystemModel_setData(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func sort P1,P2
		return QFileSystemModel_sort(pObject,P1,P2)

	Func supportedDropActions 
		return QFileSystemModel_supportedDropActions(pObject)

Class QTreeWidget from QTreeView

	pObject

	Func init P1
		pObject = QTreeWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTreeWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addTopLevelItem P1
		return QTreeWidget_addTopLevelItem(pObject,GetObjectPointerFromRingObject(P1))

	Func closePersistentEditor P1,P2
		return QTreeWidget_closePersistentEditor(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func columnCount 
		return QTreeWidget_columnCount(pObject)

	Func currentColumn 
		return QTreeWidget_currentColumn(pObject)

	Func currentItem 
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_currentItem(pObject)
		return pTempObj

	Func editItem P1,P2
		return QTreeWidget_editItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func headerItem 
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_headerItem(pObject)
		return pTempObj

	Func indexOfTopLevelItem P1
		return QTreeWidget_indexOfTopLevelItem(pObject,GetObjectPointerFromRingObject(P1))

	Func insertTopLevelItem P1,P2
		return QTreeWidget_insertTopLevelItem(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func invisibleRootItem 
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_invisibleRootItem(pObject)
		return pTempObj

	Func isFirstItemColumnSpanned P1
		return QTreeWidget_isFirstItemColumnSpanned(pObject,GetObjectPointerFromRingObject(P1))

	Func itemAbove P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_itemAbove(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func itemAt P1,P2
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_itemAt(pObject,P1,P2)
		return pTempObj

	Func itemBelow P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_itemBelow(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func itemWidget P1,P2
		pTempObj = new QWidget
		pTempObj.pObject = QTreeWidget_itemWidget(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func openPersistentEditor P1,P2
		return QTreeWidget_openPersistentEditor(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func removeItemWidget P1,P2
		return QTreeWidget_removeItemWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setColumnCount P1
		return QTreeWidget_setColumnCount(pObject,P1)

	Func setCurrentItem P1,P2
		return QTreeWidget_setCurrentItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setFirstItemColumnSpanned P1,P2
		return QTreeWidget_setFirstItemColumnSpanned(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setHeaderItem P1
		return QTreeWidget_setHeaderItem(pObject,GetObjectPointerFromRingObject(P1))

	Func setHeaderLabel P1
		return QTreeWidget_setHeaderLabel(pObject,P1)

	Func setHeaderLabels P1
		return QTreeWidget_setHeaderLabels(pObject,GetObjectPointerFromRingObject(P1))

	Func setItemWidget P1,P2,P3
		return QTreeWidget_setItemWidget(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3))

	Func sortColumn 
		return QTreeWidget_sortColumn(pObject)

	Func sortItems P1,P2
		return QTreeWidget_sortItems(pObject,P1,P2)

	Func takeTopLevelItem P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_takeTopLevelItem(pObject,P1)
		return pTempObj

	Func topLevelItem P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidget_topLevelItem(pObject,P1)
		return pTempObj

	Func topLevelItemCount 
		return QTreeWidget_topLevelItemCount(pObject)

	Func visualItemRect P1
		pTempObj = new QRect
		pTempObj.pObject = QTreeWidget_visualItemRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setSelectionModel P1
		return QTreeWidget_setSelectionModel(pObject,GetObjectPointerFromRingObject(P1))

	Func clear 
		return QTreeWidget_clear(pObject)

	Func collapseItem P1
		return QTreeWidget_collapseItem(pObject,GetObjectPointerFromRingObject(P1))

	Func expandItem P1
		return QTreeWidget_expandItem(pObject,GetObjectPointerFromRingObject(P1))

	Func scrollToItem P1,P2
		return QTreeWidget_scrollToItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setcollapsedEvent P1
		return QTreeWidget_setcollapsedEvent(pObject,P1)

	Func setexpandedEvent P1
		return QTreeWidget_setexpandedEvent(pObject,P1)

	Func setactivatedEvent P1
		return QTreeWidget_setactivatedEvent(pObject,P1)

	Func setclickedEvent P1
		return QTreeWidget_setclickedEvent(pObject,P1)

	Func setdoubleClickedEvent P1
		return QTreeWidget_setdoubleClickedEvent(pObject,P1)

	Func setenteredEvent P1
		return QTreeWidget_setenteredEvent(pObject,P1)

	Func setpressedEvent P1
		return QTreeWidget_setpressedEvent(pObject,P1)

	Func setviewportEnteredEvent P1
		return QTreeWidget_setviewportEnteredEvent(pObject,P1)

	Func setcurrentItemChangedEvent P1
		return QTreeWidget_setcurrentItemChangedEvent(pObject,P1)

	Func setitemActivatedEvent P1
		return QTreeWidget_setitemActivatedEvent(pObject,P1)

	Func setitemChangedEvent P1
		return QTreeWidget_setitemChangedEvent(pObject,P1)

	Func setitemClickedEvent P1
		return QTreeWidget_setitemClickedEvent(pObject,P1)

	Func setitemCollapsedEvent P1
		return QTreeWidget_setitemCollapsedEvent(pObject,P1)

	Func setitemDoubleClickedEvent P1
		return QTreeWidget_setitemDoubleClickedEvent(pObject,P1)

	Func setitemEnteredEvent P1
		return QTreeWidget_setitemEnteredEvent(pObject,P1)

	Func setitemExpandedEvent P1
		return QTreeWidget_setitemExpandedEvent(pObject,P1)

	Func setitemPressedEvent P1
		return QTreeWidget_setitemPressedEvent(pObject,P1)

	Func setitemSelectionChangedEvent P1
		return QTreeWidget_setitemSelectionChangedEvent(pObject,P1)

	Func getcollapsedEvent 
		return QTreeWidget_getcollapsedEvent(pObject)

	Func getexpandedEvent 
		return QTreeWidget_getexpandedEvent(pObject)

	Func getactivatedEvent 
		return QTreeWidget_getactivatedEvent(pObject)

	Func getclickedEvent 
		return QTreeWidget_getclickedEvent(pObject)

	Func getdoubleClickedEvent 
		return QTreeWidget_getdoubleClickedEvent(pObject)

	Func getenteredEvent 
		return QTreeWidget_getenteredEvent(pObject)

	Func getpressedEvent 
		return QTreeWidget_getpressedEvent(pObject)

	Func getviewportEnteredEvent 
		return QTreeWidget_getviewportEnteredEvent(pObject)

	Func getcurrentItemChangedEvent 
		return QTreeWidget_getcurrentItemChangedEvent(pObject)

	Func getitemActivatedEvent 
		return QTreeWidget_getitemActivatedEvent(pObject)

	Func getitemChangedEvent 
		return QTreeWidget_getitemChangedEvent(pObject)

	Func getitemClickedEvent 
		return QTreeWidget_getitemClickedEvent(pObject)

	Func getitemCollapsedEvent 
		return QTreeWidget_getitemCollapsedEvent(pObject)

	Func getitemDoubleClickedEvent 
		return QTreeWidget_getitemDoubleClickedEvent(pObject)

	Func getitemEnteredEvent 
		return QTreeWidget_getitemEnteredEvent(pObject)

	Func getitemExpandedEvent 
		return QTreeWidget_getitemExpandedEvent(pObject)

	Func getitemPressedEvent 
		return QTreeWidget_getitemPressedEvent(pObject)

	Func getitemSelectionChangedEvent 
		return QTreeWidget_getitemSelectionChangedEvent(pObject)

Class QTreeWidgetItem

	pObject

	Func init 
		pObject = QTreeWidgetItem_new()
		return self

	Func delete
		pObject = QTreeWidgetItem_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addChild P1
		return QTreeWidgetItem_addChild(pObject,GetObjectPointerFromRingObject(P1))

	Func background P1
		pTempObj = new QBrush
		pTempObj.pObject = QTreeWidgetItem_background(pObject,P1)
		return pTempObj

	Func checkState P1
		return QTreeWidgetItem_checkState(pObject,P1)

	Func child P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidgetItem_child(pObject,P1)
		return pTempObj

	Func childCount 
		return QTreeWidgetItem_childCount(pObject)

	Func childIndicatorPolicy 
		return QTreeWidgetItem_childIndicatorPolicy(pObject)

	Func clone 
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidgetItem_clone(pObject)
		return pTempObj

	Func columnCount 
		return QTreeWidgetItem_columnCount(pObject)

	Func data P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QTreeWidgetItem_data(pObject,P1,P2)
		return pTempObj

	Func flags 
		return QTreeWidgetItem_flags(pObject)

	Func font P1
		pTempObj = new QFont
		pTempObj.pObject = QTreeWidgetItem_font(pObject,P1)
		return pTempObj

	Func foreground P1
		pTempObj = new QBrush
		pTempObj.pObject = QTreeWidgetItem_foreground(pObject,P1)
		return pTempObj

	Func icon P1
		pTempObj = new QIcon
		pTempObj.pObject = QTreeWidgetItem_icon(pObject,P1)
		return pTempObj

	Func indexOfChild P1
		return QTreeWidgetItem_indexOfChild(pObject,GetObjectPointerFromRingObject(P1))

	Func insertChild P1,P2
		return QTreeWidgetItem_insertChild(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isDisabled 
		return QTreeWidgetItem_isDisabled(pObject)

	Func isExpanded 
		return QTreeWidgetItem_isExpanded(pObject)

	Func isFirstColumnSpanned 
		return QTreeWidgetItem_isFirstColumnSpanned(pObject)

	Func isHidden 
		return QTreeWidgetItem_isHidden(pObject)

	Func isSelected 
		return QTreeWidgetItem_isSelected(pObject)

	Func parent 
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidgetItem_parent(pObject)
		return pTempObj

	Func read P1
		return QTreeWidgetItem_read(pObject,GetObjectPointerFromRingObject(P1))

	Func removeChild P1
		return QTreeWidgetItem_removeChild(pObject,GetObjectPointerFromRingObject(P1))

	Func setBackground P1,P2
		return QTreeWidgetItem_setBackground(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setCheckState P1,P2
		return QTreeWidgetItem_setCheckState(pObject,P1,P2)

	Func setChildIndicatorPolicy P1
		return QTreeWidgetItem_setChildIndicatorPolicy(pObject,P1)

	Func setData P1,P2,P3
		return QTreeWidgetItem_setData(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func setDisabled P1
		return QTreeWidgetItem_setDisabled(pObject,P1)

	Func setExpanded P1
		return QTreeWidgetItem_setExpanded(pObject,P1)

	Func setFirstColumnSpanned P1
		return QTreeWidgetItem_setFirstColumnSpanned(pObject,P1)

	Func setFlags P1
		return QTreeWidgetItem_setFlags(pObject,P1)

	Func setFont P1,P2
		return QTreeWidgetItem_setFont(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setForeground P1,P2
		return QTreeWidgetItem_setForeground(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHidden P1
		return QTreeWidgetItem_setHidden(pObject,P1)

	Func setIcon P1,P2
		return QTreeWidgetItem_setIcon(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setSelected P1
		return QTreeWidgetItem_setSelected(pObject,P1)

	Func setSizeHint P1,P2
		return QTreeWidgetItem_setSizeHint(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setStatusTip P1,P2
		return QTreeWidgetItem_setStatusTip(pObject,P1,P2)

	Func setText P1,P2
		return QTreeWidgetItem_setText(pObject,P1,P2)

	Func setTextAlignment P1,P2
		return QTreeWidgetItem_setTextAlignment(pObject,P1,P2)

	Func setToolTip P1,P2
		return QTreeWidgetItem_setToolTip(pObject,P1,P2)

	Func setWhatsThis P1,P2
		return QTreeWidgetItem_setWhatsThis(pObject,P1,P2)

	Func sizeHint P1
		pTempObj = new QSize
		pTempObj.pObject = QTreeWidgetItem_sizeHint(pObject,P1)
		return pTempObj

	Func sortChildren P1,P2
		return QTreeWidgetItem_sortChildren(pObject,P1,P2)

	Func statusTip P1
		return QTreeWidgetItem_statusTip(pObject,P1)

	Func takeChild P1
		pTempObj = new QTreeWidgetItem
		pTempObj.pObject = QTreeWidgetItem_takeChild(pObject,P1)
		return pTempObj

	Func text P1
		return QTreeWidgetItem_text(pObject,P1)

	Func textAlignment P1
		return QTreeWidgetItem_textAlignment(pObject,P1)

	Func toolTip P1
		return QTreeWidgetItem_toolTip(pObject,P1)

	Func treeWidget 
		pTempObj = new QTreeWidget
		pTempObj.pObject = QTreeWidgetItem_treeWidget(pObject)
		return pTempObj

	Func type 
		return QTreeWidgetItem_type(pObject)

	Func whatsThis P1
		return QTreeWidgetItem_whatsThis(pObject,P1)

	Func write P1
		return QTreeWidgetItem_write(pObject,GetObjectPointerFromRingObject(P1))

Class QComboBox from QWidget

	pObject

	Func init P1
		pObject = QComboBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QComboBox_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addItem P1,P2
		return QComboBox_addItem(pObject,P1,P2)

	Func completer 
		pTempObj = new QCompleter
		pTempObj.pObject = QComboBox_completer(pObject)
		return pTempObj

	Func count 
		return QComboBox_count(pObject)

	Func currentIndex 
		return QComboBox_currentIndex(pObject)

	Func currentText 
		return QComboBox_currentText(pObject)

	Func duplicatesEnabled 
		return QComboBox_duplicatesEnabled(pObject)

	Func findData P1,P2,P3
		return QComboBox_findData(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func findText P1,P2
		return QComboBox_findText(pObject,P1,P2)

	Func hasFrame 
		return QComboBox_hasFrame(pObject)

	Func hidePopup 
		return QComboBox_hidePopup(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QComboBox_iconSize(pObject)
		return pTempObj

	Func insertItem P1,P2,P3
		return QComboBox_insertItem(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func insertSeparator P1
		return QComboBox_insertSeparator(pObject,P1)

	Func isEditable 
		return QComboBox_isEditable(pObject)

	Func itemData P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QComboBox_itemData(pObject,P1,P2)
		return pTempObj

	Func itemDelegate 
		return QComboBox_itemDelegate(pObject)

	Func itemIcon P1
		pTempObj = new QIcon
		pTempObj.pObject = QComboBox_itemIcon(pObject,P1)
		return pTempObj

	Func itemText P1
		return QComboBox_itemText(pObject,P1)

	Func lineEdit 
		pTempObj = new QLineEdit
		pTempObj.pObject = QComboBox_lineEdit(pObject)
		return pTempObj

	Func maxCount 
		return QComboBox_maxCount(pObject)

	Func maxVisibleItems 
		return QComboBox_maxVisibleItems(pObject)

	Func minimumContentsLength 
		return QComboBox_minimumContentsLength(pObject)

	Func model 
		return QComboBox_model(pObject)

	Func modelColumn 
		return QComboBox_modelColumn(pObject)

	Func removeItem P1
		return QComboBox_removeItem(pObject,P1)

	Func rootModelIndex 
		return QComboBox_rootModelIndex(pObject)

	Func setCompleter P1
		return QComboBox_setCompleter(pObject,GetObjectPointerFromRingObject(P1))

	Func setDuplicatesEnabled P1
		return QComboBox_setDuplicatesEnabled(pObject,P1)

	Func setEditable P1
		return QComboBox_setEditable(pObject,P1)

	Func setFrame P1
		return QComboBox_setFrame(pObject,P1)

	Func setIconSize P1
		return QComboBox_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setItemData P1,P2,P3
		return QComboBox_setItemData(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setItemDelegate P1
		return QComboBox_setItemDelegate(pObject,GetObjectPointerFromRingObject(P1))

	Func setItemIcon P1,P2
		return QComboBox_setItemIcon(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setItemText P1,P2
		return QComboBox_setItemText(pObject,P1,P2)

	Func setLineEdit P1
		return QComboBox_setLineEdit(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaxCount P1
		return QComboBox_setMaxCount(pObject,P1)

	Func setMaxVisibleItems P1
		return QComboBox_setMaxVisibleItems(pObject,P1)

	Func setMinimumContentsLength P1
		return QComboBox_setMinimumContentsLength(pObject,P1)

	Func setModel P1
		return QComboBox_setModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setModelColumn P1
		return QComboBox_setModelColumn(pObject,P1)

	Func setRootModelIndex P1
		return QComboBox_setRootModelIndex(pObject,GetObjectPointerFromRingObject(P1))

	Func setValidator P1
		return QComboBox_setValidator(pObject,GetObjectPointerFromRingObject(P1))

	Func setView P1
		return QComboBox_setView(pObject,GetObjectPointerFromRingObject(P1))

	Func showPopup 
		return QComboBox_showPopup(pObject)

	Func validator 
		return QComboBox_validator(pObject)

	Func view 
		pTempObj = new QAbstractItemView
		pTempObj.pObject = QComboBox_view(pObject)
		return pTempObj

	Func clear 
		return QComboBox_clear(pObject)

	Func clearEditText 
		return QComboBox_clearEditText(pObject)

	Func setCurrentIndex P1
		return QComboBox_setCurrentIndex(pObject,P1)

	Func setEditText P1
		return QComboBox_setEditText(pObject,P1)

	Func setactivatedEvent P1
		return QComboBox_setactivatedEvent(pObject,P1)

	Func setcurrentIndexChangedEvent P1
		return QComboBox_setcurrentIndexChangedEvent(pObject,P1)

	Func seteditTextChangedEvent P1
		return QComboBox_seteditTextChangedEvent(pObject,P1)

	Func sethighlightedEvent P1
		return QComboBox_sethighlightedEvent(pObject,P1)

	Func getactivatedEvent 
		return QComboBox_getactivatedEvent(pObject)

	Func getcurrentIndexChangedEvent 
		return QComboBox_getcurrentIndexChangedEvent(pObject)

	Func geteditTextChangedEvent 
		return QComboBox_geteditTextChangedEvent(pObject)

	Func gethighlightedEvent 
		return QComboBox_gethighlightedEvent(pObject)

Class QMenuBar from QWidget

	pObject

	Func init P1
		pObject = QMenuBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMenuBar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func actionAt P1
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_actionAt(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func actionGeometry P1
		pTempObj = new QRect
		pTempObj.pObject = QMenuBar_actionGeometry(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func activeAction 
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_activeAction(pObject)
		return pTempObj

	Func addAction P1
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_addAction(pObject,P1)
		return pTempObj

	Func addMenu P1
		pTempObj = new QMenu
		pTempObj.pObject = QMenuBar_addMenu(pObject,P1)
		return pTempObj

	Func addSeparator 
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_addSeparator(pObject)
		return pTempObj

	Func clear 
		return QMenuBar_clear(pObject)

	Func cornerWidget P1
		pTempObj = new QWidget
		pTempObj.pObject = QMenuBar_cornerWidget(pObject,P1)
		return pTempObj

	Func insertMenu P1,P2
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_insertMenu(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func insertSeparator P1
		pTempObj = new QAction
		pTempObj.pObject = QMenuBar_insertSeparator(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func isDefaultUp 
		return QMenuBar_isDefaultUp(pObject)

	Func isNativeMenuBar 
		return QMenuBar_isNativeMenuBar(pObject)

	Func setActiveAction P1
		return QMenuBar_setActiveAction(pObject,GetObjectPointerFromRingObject(P1))

	Func setCornerWidget P1,P2
		return QMenuBar_setCornerWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setDefaultUp P1
		return QMenuBar_setDefaultUp(pObject,P1)

	Func setNativeMenuBar P1
		return QMenuBar_setNativeMenuBar(pObject,P1)

Class QMenu from QWidget

	pObject

	Func init P1
		pObject = QMenu_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMenu_delete(pObject)

	Func ObjectPointer
		return pObject

	Func actionAt P1
		pTempObj = new QAction
		pTempObj.pObject = QMenu_actionAt(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func actionGeometry P1
		pTempObj = new QRect
		pTempObj.pObject = QMenu_actionGeometry(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func activeAction 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_activeAction(pObject)
		return pTempObj

	Func addAction P1
		return QMenu_addAction(pObject,GetObjectPointerFromRingObject(P1))

	Func addMenu P1
		pTempObj = new QMenu
		pTempObj.pObject = QMenu_addMenu(pObject,P1)
		return pTempObj

	Func addSeparator 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_addSeparator(pObject)
		return pTempObj

	Func clear 
		return QMenu_clear(pObject)

	Func defaultAction 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_defaultAction(pObject)
		return pTempObj

	Func exec P1
		pTempObj = new QAction
		pTempObj.pObject = QMenu_exec(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func exec_2 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_exec_2(pObject)
		return pTempObj

	Func exec_3 P1,P2
		pTempObj = new QAction
		pTempObj.pObject = QMenu_exec_3(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func hideTearOffMenu 
		return QMenu_hideTearOffMenu(pObject)

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QMenu_icon(pObject)
		return pTempObj

	Func insertMenu P1,P2
		pTempObj = new QAction
		pTempObj.pObject = QMenu_insertMenu(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func insertSeparator P1
		pTempObj = new QAction
		pTempObj.pObject = QMenu_insertSeparator(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func isEmpty 
		return QMenu_isEmpty(pObject)

	Func isTearOffEnabled 
		return QMenu_isTearOffEnabled(pObject)

	Func isTearOffMenuVisible 
		return QMenu_isTearOffMenuVisible(pObject)

	Func menuAction 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_menuAction(pObject)
		return pTempObj

	Func popup P1,P2
		return QMenu_popup(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func separatorsCollapsible 
		return QMenu_separatorsCollapsible(pObject)

	Func setActiveAction P1
		return QMenu_setActiveAction(pObject,GetObjectPointerFromRingObject(P1))

	Func setDefaultAction P1
		return QMenu_setDefaultAction(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QMenu_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setSeparatorsCollapsible P1
		return QMenu_setSeparatorsCollapsible(pObject,P1)

	Func setTearOffEnabled P1
		return QMenu_setTearOffEnabled(pObject,P1)

	Func setTitle P1
		return QMenu_setTitle(pObject,P1)

	Func title 
		return QMenu_title(pObject)

Class QToolBar from QWidget

	pObject

	Func init P1
		pObject = QToolBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QToolBar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func actionAt P1,P2
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_actionAt(pObject,P1,P2)
		return pTempObj

	Func addAction P1
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_addAction(pObject,P1)
		return pTempObj

	Func addSeparator 
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_addSeparator(pObject)
		return pTempObj

	Func addWidget P1
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_addWidget(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func allowedAreas 
		return QToolBar_allowedAreas(pObject)

	Func clear 
		return QToolBar_clear(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QToolBar_iconSize(pObject)
		return pTempObj

	Func insertSeparator P1
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_insertSeparator(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func insertWidget P1,P2
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_insertWidget(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func isAreaAllowed P1
		return QToolBar_isAreaAllowed(pObject,P1)

	Func isFloatable 
		return QToolBar_isFloatable(pObject)

	Func isFloating 
		return QToolBar_isFloating(pObject)

	Func isMovable 
		return QToolBar_isMovable(pObject)

	Func orientation 
		return QToolBar_orientation(pObject)

	Func setAllowedAreas P1
		return QToolBar_setAllowedAreas(pObject,P1)

	Func setFloatable P1
		return QToolBar_setFloatable(pObject,P1)

	Func setMovable P1
		return QToolBar_setMovable(pObject,P1)

	Func setOrientation P1
		return QToolBar_setOrientation(pObject,P1)

	Func toggleViewAction 
		pTempObj = new QAction
		pTempObj.pObject = QToolBar_toggleViewAction(pObject)
		return pTempObj

	Func toolButtonStyle 
		return QToolBar_toolButtonStyle(pObject)

	Func widgetForAction P1
		pTempObj = new QWidget
		pTempObj.pObject = QToolBar_widgetForAction(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setIconSize P1
		return QToolBar_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setToolButtonStyle P1
		return QToolBar_setToolButtonStyle(pObject,P1)

Class QMainWindow from QWidget

	pObject

	Func init 
		pObject = QMainWindow_new()
		return self

	Func delete
		pObject = QMainWindow_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addDockWidget P1,P2,P3
		return QMainWindow_addDockWidget(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func addToolBar P1
		pTempObj = new QToolBar
		pTempObj.pObject = QMainWindow_addToolBar(pObject,P1)
		return pTempObj

	Func addToolBar_2 P1,P2
		return QMainWindow_addToolBar_2(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func addToolBarBreak P1
		return QMainWindow_addToolBarBreak(pObject,P1)

	Func centralWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QMainWindow_centralWidget(pObject)
		return pTempObj

	Func corner P1
		return QMainWindow_corner(pObject,P1)

	Func createPopupMenu 
		pTempObj = new QMenu
		pTempObj.pObject = QMainWindow_createPopupMenu(pObject)
		return pTempObj

	Func dockOptions 
		return QMainWindow_dockOptions(pObject)

	Func dockWidgetArea P1
		return QMainWindow_dockWidgetArea(pObject,GetObjectPointerFromRingObject(P1))

	Func documentMode 
		return QMainWindow_documentMode(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QMainWindow_iconSize(pObject)
		return pTempObj

	Func insertToolBar P1,P2
		return QMainWindow_insertToolBar(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func insertToolBarBreak P1
		return QMainWindow_insertToolBarBreak(pObject,GetObjectPointerFromRingObject(P1))

	Func isAnimated 
		return QMainWindow_isAnimated(pObject)

	Func isDockNestingEnabled 
		return QMainWindow_isDockNestingEnabled(pObject)

	Func menuBar 
		pTempObj = new QMenuBar
		pTempObj.pObject = QMainWindow_menuBar(pObject)
		return pTempObj

	Func menuWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QMainWindow_menuWidget(pObject)
		return pTempObj

	Func removeDockWidget P1
		return QMainWindow_removeDockWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func removeToolBar P1
		return QMainWindow_removeToolBar(pObject,GetObjectPointerFromRingObject(P1))

	Func removeToolBarBreak P1
		return QMainWindow_removeToolBarBreak(pObject,GetObjectPointerFromRingObject(P1))

	Func restoreDockWidget P1
		return QMainWindow_restoreDockWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func restoreState P1,P2
		return QMainWindow_restoreState(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func saveState P1
		pTempObj = new QByteArray
		pTempObj.pObject = QMainWindow_saveState(pObject,P1)
		return pTempObj

	Func setCentralWidget P1
		return QMainWindow_setCentralWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setCorner P1,P2
		return QMainWindow_setCorner(pObject,P1,P2)

	Func setDockOptions P1
		return QMainWindow_setDockOptions(pObject,P1)

	Func setDocumentMode P1
		return QMainWindow_setDocumentMode(pObject,P1)

	Func setIconSize P1
		return QMainWindow_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setMenuBar P1
		return QMainWindow_setMenuBar(pObject,GetObjectPointerFromRingObject(P1))

	Func setMenuWidget P1
		return QMainWindow_setMenuWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setStatusBar P1
		return QMainWindow_setStatusBar(pObject,GetObjectPointerFromRingObject(P1))

	Func setTabPosition P1,P2
		return QMainWindow_setTabPosition(pObject,P1,P2)

	Func setTabShape P1
		return QMainWindow_setTabShape(pObject,P1)

	Func setToolButtonStyle P1
		return QMainWindow_setToolButtonStyle(pObject,P1)

	Func setUnifiedTitleAndToolBarOnMac P1
		return QMainWindow_setUnifiedTitleAndToolBarOnMac(pObject,P1)

	Func splitDockWidget P1,P2,P3
		return QMainWindow_splitDockWidget(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func statusBar 
		pTempObj = new QStatusBar
		pTempObj.pObject = QMainWindow_statusBar(pObject)
		return pTempObj

	Func tabPosition P1
		return QMainWindow_tabPosition(pObject,P1)

	Func tabShape 
		return QMainWindow_tabShape(pObject)

	Func tabifyDockWidget P1,P2
		return QMainWindow_tabifyDockWidget(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toolBarArea P1
		return QMainWindow_toolBarArea(pObject,GetObjectPointerFromRingObject(P1))

	Func toolBarBreak P1
		return QMainWindow_toolBarBreak(pObject,GetObjectPointerFromRingObject(P1))

	Func toolButtonStyle 
		return QMainWindow_toolButtonStyle(pObject)

	Func unifiedTitleAndToolBarOnMac 
		return QMainWindow_unifiedTitleAndToolBarOnMac(pObject)

Class QStatusBar from QWidget

	pObject

	Func init P1
		pObject = QStatusBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QStatusBar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addPermanentWidget P1,P2
		return QStatusBar_addPermanentWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func addWidget P1,P2
		return QStatusBar_addWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func currentMessage 
		return QStatusBar_currentMessage(pObject)

	Func insertPermanentWidget P1,P2,P3
		return QStatusBar_insertPermanentWidget(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func insertWidget P1,P2,P3
		return QStatusBar_insertWidget(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func isSizeGripEnabled 
		return QStatusBar_isSizeGripEnabled(pObject)

	Func removeWidget P1
		return QStatusBar_removeWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setSizeGripEnabled P1
		return QStatusBar_setSizeGripEnabled(pObject,P1)

	Func clearMessage 
		return QStatusBar_clearMessage(pObject)

	Func showMessage P1,P2
		return QStatusBar_showMessage(pObject,P1,P2)

Class QDockWidget from QWidget

	pObject

	Func init P1,P2
		pObject = QDockWidget_new(GetObjectPointerFromRingObject(P1),P2)
		return self

	Func delete
		pObject = QDockWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allowedAreas 
		return QDockWidget_allowedAreas(pObject)

	Func features 
		return QDockWidget_features(pObject)

	Func isAreaAllowed P1
		return QDockWidget_isAreaAllowed(pObject,P1)

	Func isFloating 
		return QDockWidget_isFloating(pObject)

	Func setAllowedAreas P1
		return QDockWidget_setAllowedAreas(pObject,P1)

	Func setFeatures P1
		return QDockWidget_setFeatures(pObject,P1)

	Func setFloating P1
		return QDockWidget_setFloating(pObject,P1)

	Func setTitleBarWidget P1
		return QDockWidget_setTitleBarWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidget P1
		return QDockWidget_setWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func titleBarWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QDockWidget_titleBarWidget(pObject)
		return pTempObj

	Func toggleViewAction 
		pTempObj = new QAction
		pTempObj.pObject = QDockWidget_toggleViewAction(pObject)
		return pTempObj

	Func widget 
		pTempObj = new QWidget
		pTempObj.pObject = QDockWidget_widget(pObject)
		return pTempObj

	Func allowedAreasChanged P1
		return QDockWidget_allowedAreasChanged(pObject,P1)

	Func dockLocationChanged P1
		return QDockWidget_dockLocationChanged(pObject,P1)

	Func featuresChanged P1
		return QDockWidget_featuresChanged(pObject,P1)

	Func topLevelChanged P1
		return QDockWidget_topLevelChanged(pObject,P1)

	Func visibilityChanged P1
		return QDockWidget_visibilityChanged(pObject,P1)

	Func setallowedAreasChangedEvent P1
		return QDockWidget_setallowedAreasChangedEvent(pObject,P1)

	Func setdockLocationChangedEvent P1
		return QDockWidget_setdockLocationChangedEvent(pObject,P1)

	Func setfeaturesChangedEvent P1
		return QDockWidget_setfeaturesChangedEvent(pObject,P1)

	Func settopLevelChangedEvent P1
		return QDockWidget_settopLevelChangedEvent(pObject,P1)

	Func setvisibilityChangedEvent P1
		return QDockWidget_setvisibilityChangedEvent(pObject,P1)

	Func getallowedAreasChangedEvent 
		return QDockWidget_getallowedAreasChangedEvent(pObject)

	Func getdockLocationChangedEvent 
		return QDockWidget_getdockLocationChangedEvent(pObject)

	Func getfeaturesChangedEvent 
		return QDockWidget_getfeaturesChangedEvent(pObject)

	Func gettopLevelChangedEvent 
		return QDockWidget_gettopLevelChangedEvent(pObject)

	Func getvisibilityChangedEvent 
		return QDockWidget_getvisibilityChangedEvent(pObject)

Class QTabWidget from QWidget

	pObject

	Func init P1
		pObject = QTabWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTabWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addTab P1,P2
		return QTabWidget_addTab(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func clear 
		return QTabWidget_clear(pObject)

	Func cornerWidget P1
		pTempObj = new QWidget
		pTempObj.pObject = QTabWidget_cornerWidget(pObject,P1)
		return pTempObj

	Func count 
		return QTabWidget_count(pObject)

	Func currentIndex 
		return QTabWidget_currentIndex(pObject)

	Func currentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QTabWidget_currentWidget(pObject)
		return pTempObj

	Func documentMode 
		return QTabWidget_documentMode(pObject)

	Func elideMode 
		return QTabWidget_elideMode(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QTabWidget_iconSize(pObject)
		return pTempObj

	Func indexOf P1
		return QTabWidget_indexOf(pObject,GetObjectPointerFromRingObject(P1))

	Func insertTab P1,P2,P3
		return QTabWidget_insertTab(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func isMovable 
		return QTabWidget_isMovable(pObject)

	Func isTabEnabled P1
		return QTabWidget_isTabEnabled(pObject,P1)

	Func removeTab P1
		return QTabWidget_removeTab(pObject,P1)

	Func setCornerWidget P1,P2
		return QTabWidget_setCornerWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setDocumentMode P1
		return QTabWidget_setDocumentMode(pObject,P1)

	Func setElideMode P1
		return QTabWidget_setElideMode(pObject,P1)

	Func setIconSize P1
		return QTabWidget_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setMovable P1
		return QTabWidget_setMovable(pObject,P1)

	Func setTabEnabled P1,P2
		return QTabWidget_setTabEnabled(pObject,P1,P2)

	Func setTabIcon P1,P2
		return QTabWidget_setTabIcon(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setTabText P1,P2
		return QTabWidget_setTabText(pObject,P1,P2)

	Func setTabToolTip P1,P2
		return QTabWidget_setTabToolTip(pObject,P1,P2)

	Func setTabWhatsThis P1,P2
		return QTabWidget_setTabWhatsThis(pObject,P1,P2)

	Func setTabsClosable P1
		return QTabWidget_setTabsClosable(pObject,P1)

	Func setUsesScrollButtons P1
		return QTabWidget_setUsesScrollButtons(pObject,P1)

	Func tabIcon P1
		pTempObj = new QIcon
		pTempObj.pObject = QTabWidget_tabIcon(pObject,P1)
		return pTempObj

	Func tabText P1
		return QTabWidget_tabText(pObject,P1)

	Func tabToolTip P1
		return QTabWidget_tabToolTip(pObject,P1)

	Func tabWhatsThis P1
		return QTabWidget_tabWhatsThis(pObject,P1)

	Func tabsClosable 
		return QTabWidget_tabsClosable(pObject)

	Func usesScrollButtons 
		return QTabWidget_usesScrollButtons(pObject)

	Func widget P1
		pTempObj = new QWidget
		pTempObj.pObject = QTabWidget_widget(pObject,P1)
		return pTempObj

	Func heightForWidth P1
		return QTabWidget_heightForWidth(pObject,P1)

	Func minimumSizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QTabWidget_minimumSizeHint(pObject)
		return pTempObj

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QTabWidget_sizeHint(pObject)
		return pTempObj

	Func setCurrentIndex P1
		return QTabWidget_setCurrentIndex(pObject,P1)

	Func setCurrentWidget P1
		return QTabWidget_setCurrentWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setcurrentChangedEvent P1
		return QTabWidget_setcurrentChangedEvent(pObject,P1)

	Func settabCloseRequestedEvent P1
		return QTabWidget_settabCloseRequestedEvent(pObject,P1)

	Func getcurrentChangedEvent 
		return QTabWidget_getcurrentChangedEvent(pObject)

	Func gettabCloseRequestedEvent 
		return QTabWidget_gettabCloseRequestedEvent(pObject)

Class QTableWidgetItem

	pObject

	Func init P1
		pObject = QTableWidgetItem_new(P1)
		return self

	Func delete
		pObject = QTableWidgetItem_delete(pObject)

	Func ObjectPointer
		return pObject

	Func background 
		pTempObj = new QBrush
		pTempObj.pObject = QTableWidgetItem_background(pObject)
		return pTempObj

	Func checkState 
		return QTableWidgetItem_checkState(pObject)

	Func clone 
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidgetItem_clone(pObject)
		return pTempObj

	Func column 
		return QTableWidgetItem_column(pObject)

	Func data P1
		pTempObj = new QVariant
		pTempObj.pObject = QTableWidgetItem_data(pObject,P1)
		return pTempObj

	Func flags 
		return QTableWidgetItem_flags(pObject)

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QTableWidgetItem_font(pObject)
		return pTempObj

	Func foreground 
		pTempObj = new QBrush
		pTempObj.pObject = QTableWidgetItem_foreground(pObject)
		return pTempObj

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QTableWidgetItem_icon(pObject)
		return pTempObj

	Func isSelected 
		return QTableWidgetItem_isSelected(pObject)

	Func read P1
		return QTableWidgetItem_read(pObject,GetObjectPointerFromRingObject(P1))

	Func row 
		return QTableWidgetItem_row(pObject)

	Func setBackground P1
		return QTableWidgetItem_setBackground(pObject,GetObjectPointerFromRingObject(P1))

	Func setCheckState P1
		return QTableWidgetItem_setCheckState(pObject,P1)

	Func setData P1,P2
		return QTableWidgetItem_setData(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setFlags P1
		return QTableWidgetItem_setFlags(pObject,P1)

	Func setFont P1
		return QTableWidgetItem_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setForeground P1
		return QTableWidgetItem_setForeground(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QTableWidgetItem_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelected P1
		return QTableWidgetItem_setSelected(pObject,P1)

	Func setSizeHint P1
		return QTableWidgetItem_setSizeHint(pObject,GetObjectPointerFromRingObject(P1))

	Func setStatusTip P1
		return QTableWidgetItem_setStatusTip(pObject,P1)

	Func setText P1
		return QTableWidgetItem_setText(pObject,P1)

	Func setTextAlignment P1
		return QTableWidgetItem_setTextAlignment(pObject,P1)

	Func setToolTip P1
		return QTableWidgetItem_setToolTip(pObject,P1)

	Func setWhatsThis P1
		return QTableWidgetItem_setWhatsThis(pObject,P1)

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QTableWidgetItem_sizeHint(pObject)
		return pTempObj

	Func statusTip 
		return QTableWidgetItem_statusTip(pObject)

	Func tableWidget 
		pTempObj = new QTableWidget
		pTempObj.pObject = QTableWidgetItem_tableWidget(pObject)
		return pTempObj

	Func text 
		return QTableWidgetItem_text(pObject)

	Func textAlignment 
		return QTableWidgetItem_textAlignment(pObject)

	Func toolTip 
		return QTableWidgetItem_toolTip(pObject)

	Func type 
		return QTableWidgetItem_type(pObject)

	Func whatsThis 
		return QTableWidgetItem_whatsThis(pObject)

	Func write P1
		return QTableWidgetItem_write(pObject,GetObjectPointerFromRingObject(P1))

Class QFrame from QWidget

	pObject

	Func init P1,P2
		pObject = QFrame_new(GetObjectPointerFromRingObject(P1),P2)
		return self

	Func delete
		pObject = QFrame_delete(pObject)

	Func ObjectPointer
		return pObject

	Func frameRect 
		pTempObj = new QRect
		pTempObj.pObject = QFrame_frameRect(pObject)
		return pTempObj

	Func frameShadow 
		return QFrame_frameShadow(pObject)

	Func frameShape 
		return QFrame_frameShape(pObject)

	Func frameStyle 
		return QFrame_frameStyle(pObject)

	Func frameWidth 
		return QFrame_frameWidth(pObject)

	Func lineWidth 
		return QFrame_lineWidth(pObject)

	Func midLineWidth 
		return QFrame_midLineWidth(pObject)

	Func setFrameRect P1
		return QFrame_setFrameRect(pObject,GetObjectPointerFromRingObject(P1))

	Func setFrameShadow P1
		return QFrame_setFrameShadow(pObject,P1)

	Func setFrameShape P1
		return QFrame_setFrameShape(pObject,P1)

	Func setFrameStyle P1
		return QFrame_setFrameStyle(pObject,P1)

	Func setLineWidth P1
		return QFrame_setLineWidth(pObject,P1)

	Func setMidLineWidth P1
		return QFrame_setMidLineWidth(pObject,P1)

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QFrame_sizeHint(pObject)
		return pTempObj

Class QAbstractScrollArea from QFrame

	pObject

	Func init P1
		pObject = QAbstractScrollArea_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractScrollArea_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addScrollBarWidget P1,P2
		return QAbstractScrollArea_addScrollBarWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func cornerWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QAbstractScrollArea_cornerWidget(pObject)
		return pTempObj

	Func horizontalScrollBar 
		pTempObj = new QScrollBar
		pTempObj.pObject = QAbstractScrollArea_horizontalScrollBar(pObject)
		return pTempObj

	Func horizontalScrollBarPolicy 
		return QAbstractScrollArea_horizontalScrollBarPolicy(pObject)

	Func maximumViewportSize 
		pTempObj = new QSize
		pTempObj.pObject = QAbstractScrollArea_maximumViewportSize(pObject)
		return pTempObj

	Func scrollBarWidgets P1
		return QAbstractScrollArea_scrollBarWidgets(pObject,P1)

	Func setCornerWidget P1
		return QAbstractScrollArea_setCornerWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setHorizontalScrollBar P1
		return QAbstractScrollArea_setHorizontalScrollBar(pObject,GetObjectPointerFromRingObject(P1))

	Func setHorizontalScrollBarPolicy P1
		return QAbstractScrollArea_setHorizontalScrollBarPolicy(pObject,P1)

	Func setVerticalScrollBar P1
		return QAbstractScrollArea_setVerticalScrollBar(pObject,GetObjectPointerFromRingObject(P1))

	Func setVerticalScrollBarPolicy P1
		return QAbstractScrollArea_setVerticalScrollBarPolicy(pObject,P1)

	Func setViewport P1
		return QAbstractScrollArea_setViewport(pObject,GetObjectPointerFromRingObject(P1))

	Func verticalScrollBar 
		pTempObj = new QScrollBar
		pTempObj.pObject = QAbstractScrollArea_verticalScrollBar(pObject)
		return pTempObj

	Func verticalScrollBarPolicy 
		return QAbstractScrollArea_verticalScrollBarPolicy(pObject)

	Func viewport 
		pTempObj = new QWidget
		pTempObj.pObject = QAbstractScrollArea_viewport(pObject)
		return pTempObj

Class QAbstractItemView from QAbstractScrollArea

	pObject

	Func init P1
		pObject = QAbstractItemView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractItemView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alternatingRowColors 
		return QAbstractItemView_alternatingRowColors(pObject)

	Func autoScrollMargin 
		return QAbstractItemView_autoScrollMargin(pObject)

	Func closePersistentEditor P1
		return QAbstractItemView_closePersistentEditor(pObject,GetObjectPointerFromRingObject(P1))

	Func currentIndex 
		return QAbstractItemView_currentIndex(pObject)

	Func defaultDropAction 
		return QAbstractItemView_defaultDropAction(pObject)

	Func dragDropMode 
		return QAbstractItemView_dragDropMode(pObject)

	Func dragDropOverwriteMode 
		return QAbstractItemView_dragDropOverwriteMode(pObject)

	Func dragEnabled 
		return QAbstractItemView_dragEnabled(pObject)

	Func editTriggers 
		return QAbstractItemView_editTriggers(pObject)

	Func hasAutoScroll 
		return QAbstractItemView_hasAutoScroll(pObject)

	Func horizontalScrollMode 
		return QAbstractItemView_horizontalScrollMode(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QAbstractItemView_iconSize(pObject)
		return pTempObj

	Func indexAt P1
		return QAbstractItemView_indexAt(pObject,GetObjectPointerFromRingObject(P1))

	Func indexWidget P1
		pTempObj = new QWidget
		pTempObj.pObject = QAbstractItemView_indexWidget(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func itemDelegate P1
		return QAbstractItemView_itemDelegate(pObject,GetObjectPointerFromRingObject(P1))

	Func itemDelegateForColumn P1
		return QAbstractItemView_itemDelegateForColumn(pObject,P1)

	Func itemDelegateForRow P1
		return QAbstractItemView_itemDelegateForRow(pObject,P1)

	Func keyboardSearch P1
		return QAbstractItemView_keyboardSearch(pObject,P1)

	Func model 
		return QAbstractItemView_model(pObject)

	Func openPersistentEditor P1
		return QAbstractItemView_openPersistentEditor(pObject,GetObjectPointerFromRingObject(P1))

	Func rootIndex 
		return QAbstractItemView_rootIndex(pObject)

	Func scrollTo P1,P2
		return QAbstractItemView_scrollTo(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func selectionBehavior 
		return QAbstractItemView_selectionBehavior(pObject)

	Func selectionMode 
		return QAbstractItemView_selectionMode(pObject)

	Func selectionModel 
		return QAbstractItemView_selectionModel(pObject)

	Func setAlternatingRowColors P1
		return QAbstractItemView_setAlternatingRowColors(pObject,P1)

	Func setAutoScroll P1
		return QAbstractItemView_setAutoScroll(pObject,P1)

	Func setAutoScrollMargin P1
		return QAbstractItemView_setAutoScrollMargin(pObject,P1)

	Func setDefaultDropAction P1
		return QAbstractItemView_setDefaultDropAction(pObject,P1)

	Func setDragDropMode P1
		return QAbstractItemView_setDragDropMode(pObject,P1)

	Func setDragDropOverwriteMode P1
		return QAbstractItemView_setDragDropOverwriteMode(pObject,P1)

	Func setDragEnabled P1
		return QAbstractItemView_setDragEnabled(pObject,P1)

	Func setDropIndicatorShown P1
		return QAbstractItemView_setDropIndicatorShown(pObject,P1)

	Func setEditTriggers P1
		return QAbstractItemView_setEditTriggers(pObject,P1)

	Func setHorizontalScrollMode P1
		return QAbstractItemView_setHorizontalScrollMode(pObject,P1)

	Func setIconSize P1
		return QAbstractItemView_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setIndexWidget P1,P2
		return QAbstractItemView_setIndexWidget(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setItemDelegate P1
		return QAbstractItemView_setItemDelegate(pObject,GetObjectPointerFromRingObject(P1))

	Func setItemDelegateForColumn P1,P2
		return QAbstractItemView_setItemDelegateForColumn(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setItemDelegateForRow P1,P2
		return QAbstractItemView_setItemDelegateForRow(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setModel P1
		return QAbstractItemView_setModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelectionBehavior P1
		return QAbstractItemView_setSelectionBehavior(pObject,P1)

	Func setSelectionMode P1
		return QAbstractItemView_setSelectionMode(pObject,P1)

	Func setSelectionModel P1
		return QAbstractItemView_setSelectionModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setTabKeyNavigation P1
		return QAbstractItemView_setTabKeyNavigation(pObject,P1)

	Func setTextElideMode P1
		return QAbstractItemView_setTextElideMode(pObject,P1)

	Func setVerticalScrollMode P1
		return QAbstractItemView_setVerticalScrollMode(pObject,P1)

	Func showDropIndicator 
		return QAbstractItemView_showDropIndicator(pObject)

	Func sizeHintForColumn P1
		return QAbstractItemView_sizeHintForColumn(pObject,P1)

	Func sizeHintForIndex P1
		pTempObj = new QSize
		pTempObj.pObject = QAbstractItemView_sizeHintForIndex(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func sizeHintForRow P1
		return QAbstractItemView_sizeHintForRow(pObject,P1)

	Func tabKeyNavigation 
		return QAbstractItemView_tabKeyNavigation(pObject)

	Func textElideMode 
		return QAbstractItemView_textElideMode(pObject)

	Func verticalScrollMode 
		return QAbstractItemView_verticalScrollMode(pObject)

	Func visualRect P1
		pTempObj = new QRect
		pTempObj.pObject = QAbstractItemView_visualRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func clearSelection 
		return QAbstractItemView_clearSelection(pObject)

	Func edit P1
		return QAbstractItemView_edit(pObject,GetObjectPointerFromRingObject(P1))

	Func scrollToBottom 
		return QAbstractItemView_scrollToBottom(pObject)

	Func scrollToTop 
		return QAbstractItemView_scrollToTop(pObject)

	Func setCurrentIndex P1
		return QAbstractItemView_setCurrentIndex(pObject,GetObjectPointerFromRingObject(P1))

	Func update P1
		return QAbstractItemView_update(pObject,GetObjectPointerFromRingObject(P1))

Class QTableView from QAbstractItemView

	pObject

	Func init P1
		pObject = QTableView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTableView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clearSpans 
		return QTableView_clearSpans(pObject)

	Func columnAt P1
		return QTableView_columnAt(pObject,P1)

	Func columnSpan P1,P2
		return QTableView_columnSpan(pObject,P1,P2)

	Func columnViewportPosition P1
		return QTableView_columnViewportPosition(pObject,P1)

	Func columnWidth P1
		return QTableView_columnWidth(pObject,P1)

	Func gridStyle 
		return QTableView_gridStyle(pObject)

	Func horizontalHeader 
		pTempObj = new QHeaderView
		pTempObj.pObject = QTableView_horizontalHeader(pObject)
		return pTempObj

	Func isColumnHidden P1
		return QTableView_isColumnHidden(pObject,P1)

	Func isCornerButtonEnabled 
		return QTableView_isCornerButtonEnabled(pObject)

	Func isRowHidden P1
		return QTableView_isRowHidden(pObject,P1)

	Func isSortingEnabled 
		return QTableView_isSortingEnabled(pObject)

	Func rowAt P1
		return QTableView_rowAt(pObject,P1)

	Func rowHeight P1
		return QTableView_rowHeight(pObject,P1)

	Func rowSpan P1,P2
		return QTableView_rowSpan(pObject,P1,P2)

	Func rowViewportPosition P1
		return QTableView_rowViewportPosition(pObject,P1)

	Func setColumnHidden P1,P2
		return QTableView_setColumnHidden(pObject,P1,P2)

	Func setColumnWidth P1,P2
		return QTableView_setColumnWidth(pObject,P1,P2)

	Func setCornerButtonEnabled P1
		return QTableView_setCornerButtonEnabled(pObject,P1)

	Func setGridStyle P1
		return QTableView_setGridStyle(pObject,P1)

	Func setHorizontalHeader P1
		return QTableView_setHorizontalHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func setRowHeight P1,P2
		return QTableView_setRowHeight(pObject,P1,P2)

	Func setRowHidden P1,P2
		return QTableView_setRowHidden(pObject,P1,P2)

	Func setSortingEnabled P1
		return QTableView_setSortingEnabled(pObject,P1)

	Func setSpan P1,P2,P3,P4
		return QTableView_setSpan(pObject,P1,P2,P3,P4)

	Func setVerticalHeader P1
		return QTableView_setVerticalHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func setWordWrap P1
		return QTableView_setWordWrap(pObject,P1)

	Func showGrid 
		return QTableView_showGrid(pObject)

	Func sortByColumn P1,P2
		return QTableView_sortByColumn(pObject,P1,P2)

	Func verticalHeader 
		pTempObj = new QHeaderView
		pTempObj.pObject = QTableView_verticalHeader(pObject)
		return pTempObj

	Func wordWrap 
		return QTableView_wordWrap(pObject)

	Func hideColumn P1
		return QTableView_hideColumn(pObject,P1)

	Func hideRow P1
		return QTableView_hideRow(pObject,P1)

	Func resizeColumnToContents P1
		return QTableView_resizeColumnToContents(pObject,P1)

	Func resizeColumnsToContents 
		return QTableView_resizeColumnsToContents(pObject)

	Func resizeRowToContents P1
		return QTableView_resizeRowToContents(pObject,P1)

	Func resizeRowsToContents 
		return QTableView_resizeRowsToContents(pObject)

	Func selectColumn P1
		return QTableView_selectColumn(pObject,P1)

	Func selectRow P1
		return QTableView_selectRow(pObject,P1)

	Func setShowGrid P1
		return QTableView_setShowGrid(pObject,P1)

	Func showColumn P1
		return QTableView_showColumn(pObject,P1)

	Func showRow P1
		return QTableView_showRow(pObject,P1)

Class QTableWidget from QTableView

	pObject

	Func init P1
		pObject = QTableWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTableWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func cellWidget P1,P2
		pTempObj = new QWidget
		pTempObj.pObject = QTableWidget_cellWidget(pObject,P1,P2)
		return pTempObj

	Func closePersistentEditor P1
		return QTableWidget_closePersistentEditor(pObject,GetObjectPointerFromRingObject(P1))

	Func column P1
		return QTableWidget_column(pObject,GetObjectPointerFromRingObject(P1))

	Func columnCount 
		return QTableWidget_columnCount(pObject)

	Func currentColumn 
		return QTableWidget_currentColumn(pObject)

	Func currentItem 
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_currentItem(pObject)
		return pTempObj

	Func currentRow 
		return QTableWidget_currentRow(pObject)

	Func editItem P1
		return QTableWidget_editItem(pObject,GetObjectPointerFromRingObject(P1))

	Func horizontalHeaderItem P1
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_horizontalHeaderItem(pObject,P1)
		return pTempObj

	Func item P1,P2
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_item(pObject,P1,P2)
		return pTempObj

	Func itemAt P1,P2
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_itemAt(pObject,P1,P2)
		return pTempObj

	Func itemPrototype 
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_itemPrototype(pObject)
		return pTempObj

	Func openPersistentEditor P1
		return QTableWidget_openPersistentEditor(pObject,GetObjectPointerFromRingObject(P1))

	Func removeCellWidget P1,P2
		return QTableWidget_removeCellWidget(pObject,P1,P2)

	Func row P1
		return QTableWidget_row(pObject,GetObjectPointerFromRingObject(P1))

	Func rowCount 
		return QTableWidget_rowCount(pObject)

	Func selectedItems 
		return QTableWidget_selectedItems(pObject)

	Func selectedRanges 
		return QTableWidget_selectedRanges(pObject)

	Func setCellWidget P1,P2,P3
		return QTableWidget_setCellWidget(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func setColumnCount P1
		return QTableWidget_setColumnCount(pObject,P1)

	Func setCurrentCell P1,P2
		return QTableWidget_setCurrentCell(pObject,P1,P2)

	Func setCurrentItem P1
		return QTableWidget_setCurrentItem(pObject,GetObjectPointerFromRingObject(P1))

	Func setHorizontalHeaderItem P1,P2
		return QTableWidget_setHorizontalHeaderItem(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHorizontalHeaderLabels P1
		return QTableWidget_setHorizontalHeaderLabels(pObject,GetObjectPointerFromRingObject(P1))

	Func setItem P1,P2,P3
		return QTableWidget_setItem(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func setItemPrototype P1
		return QTableWidget_setItemPrototype(pObject,GetObjectPointerFromRingObject(P1))

	Func setRowCount P1
		return QTableWidget_setRowCount(pObject,P1)

	Func setVerticalHeaderItem P1,P2
		return QTableWidget_setVerticalHeaderItem(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func sortItems P1,P2
		return QTableWidget_sortItems(pObject,P1,P2)

	Func takeHorizontalHeaderItem P1
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_takeHorizontalHeaderItem(pObject,P1)
		return pTempObj

	Func takeItem P1,P2
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_takeItem(pObject,P1,P2)
		return pTempObj

	Func takeVerticalHeaderItem P1
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_takeVerticalHeaderItem(pObject,P1)
		return pTempObj

	Func verticalHeaderItem P1
		pTempObj = new QTableWidgetItem
		pTempObj.pObject = QTableWidget_verticalHeaderItem(pObject,P1)
		return pTempObj

	Func visualColumn P1
		return QTableWidget_visualColumn(pObject,P1)

	Func visualItemRect P1
		pTempObj = new QRect
		pTempObj.pObject = QTableWidget_visualItemRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func visualRow P1
		return QTableWidget_visualRow(pObject,P1)

	Func clear 
		return QTableWidget_clear(pObject)

	Func clearContents 
		return QTableWidget_clearContents(pObject)

	Func insertColumn P1
		return QTableWidget_insertColumn(pObject,P1)

	Func insertRow P1
		return QTableWidget_insertRow(pObject,P1)

	Func removeColumn P1
		return QTableWidget_removeColumn(pObject,P1)

	Func removeRow P1
		return QTableWidget_removeRow(pObject,P1)

	Func scrollToItem P1,P2
		return QTableWidget_scrollToItem(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setcellActivatedEvent P1
		return QTableWidget_setcellActivatedEvent(pObject,P1)

	Func setcellChangedEvent P1
		return QTableWidget_setcellChangedEvent(pObject,P1)

	Func setcellClickedEvent P1
		return QTableWidget_setcellClickedEvent(pObject,P1)

	Func setcellDoubleClickedEvent P1
		return QTableWidget_setcellDoubleClickedEvent(pObject,P1)

	Func setcellEnteredEvent P1
		return QTableWidget_setcellEnteredEvent(pObject,P1)

	Func setcellPressedEvent P1
		return QTableWidget_setcellPressedEvent(pObject,P1)

	Func setcurrentCellChangedEvent P1
		return QTableWidget_setcurrentCellChangedEvent(pObject,P1)

	Func setcurrentItemChangedEvent P1
		return QTableWidget_setcurrentItemChangedEvent(pObject,P1)

	Func setitemActivatedEvent P1
		return QTableWidget_setitemActivatedEvent(pObject,P1)

	Func setitemChangedEvent P1
		return QTableWidget_setitemChangedEvent(pObject,P1)

	Func setitemClickedEvent P1
		return QTableWidget_setitemClickedEvent(pObject,P1)

	Func setitemDoubleClickedEvent P1
		return QTableWidget_setitemDoubleClickedEvent(pObject,P1)

	Func setitemEnteredEvent P1
		return QTableWidget_setitemEnteredEvent(pObject,P1)

	Func setitemPressedEvent P1
		return QTableWidget_setitemPressedEvent(pObject,P1)

	Func setitemSelectionChangedEvent P1
		return QTableWidget_setitemSelectionChangedEvent(pObject,P1)

	Func getcellActivatedEvent 
		return QTableWidget_getcellActivatedEvent(pObject)

	Func getcellChangedEvent 
		return QTableWidget_getcellChangedEvent(pObject)

	Func getcellClickedEvent 
		return QTableWidget_getcellClickedEvent(pObject)

	Func getcellDoubleClickedEvent 
		return QTableWidget_getcellDoubleClickedEvent(pObject)

	Func getcellEnteredEvent 
		return QTableWidget_getcellEnteredEvent(pObject)

	Func getcellPressedEvent 
		return QTableWidget_getcellPressedEvent(pObject)

	Func getcurrentCellChangedEvent 
		return QTableWidget_getcurrentCellChangedEvent(pObject)

	Func getcurrentItemChangedEvent 
		return QTableWidget_getcurrentItemChangedEvent(pObject)

	Func getitemActivatedEvent 
		return QTableWidget_getitemActivatedEvent(pObject)

	Func getitemChangedEvent 
		return QTableWidget_getitemChangedEvent(pObject)

	Func getitemClickedEvent 
		return QTableWidget_getitemClickedEvent(pObject)

	Func getitemDoubleClickedEvent 
		return QTableWidget_getitemDoubleClickedEvent(pObject)

	Func getitemEnteredEvent 
		return QTableWidget_getitemEnteredEvent(pObject)

	Func getitemPressedEvent 
		return QTableWidget_getitemPressedEvent(pObject)

	Func getitemSelectionChangedEvent 
		return QTableWidget_getitemSelectionChangedEvent(pObject)

Class QProgressBar from QWidget

	pObject

	Func init P1
		pObject = QProgressBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QProgressBar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alignment 
		return QProgressBar_alignment(pObject)

	Func format 
		return QProgressBar_format(pObject)

	Func invertedAppearance 
		return QProgressBar_invertedAppearance(pObject)

	Func isTextVisible 
		return QProgressBar_isTextVisible(pObject)

	Func maximum 
		return QProgressBar_maximum(pObject)

	Func minimum 
		return QProgressBar_minimum(pObject)

	Func orientation 
		return QProgressBar_orientation(pObject)

	Func resetFormat 
		return QProgressBar_resetFormat(pObject)

	Func setAlignment P1
		return QProgressBar_setAlignment(pObject,P1)

	Func setFormat P1
		return QProgressBar_setFormat(pObject,P1)

	Func setInvertedAppearance P1
		return QProgressBar_setInvertedAppearance(pObject,P1)

	Func setTextDirection P1
		return QProgressBar_setTextDirection(pObject,P1)

	Func setTextVisible P1
		return QProgressBar_setTextVisible(pObject,P1)

	Func text 
		return QProgressBar_text(pObject)

	Func textDirection 
		return QProgressBar_textDirection(pObject)

	Func value 
		return QProgressBar_value(pObject)

	Func reset 
		return QProgressBar_reset(pObject)

	Func setMaximum P1
		return QProgressBar_setMaximum(pObject,P1)

	Func setMinimum P1
		return QProgressBar_setMinimum(pObject,P1)

	Func setOrientation P1
		return QProgressBar_setOrientation(pObject,P1)

	Func setRange P1,P2
		return QProgressBar_setRange(pObject,P1,P2)

	Func setValue P1
		return QProgressBar_setValue(pObject,P1)

	Func setvalueChangedEvent P1
		return QProgressBar_setvalueChangedEvent(pObject,P1)

	Func getvalueChangedEvent 
		return QProgressBar_getvalueChangedEvent(pObject)

Class QSpinBox from QWidget

	pObject

	Func init P1
		pObject = QSpinBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSpinBox_delete(pObject)

	Func ObjectPointer
		return pObject

	Func cleanText 
		return QSpinBox_cleanText(pObject)

	Func displayIntegerBase 
		return QSpinBox_displayIntegerBase(pObject)

	Func maximum 
		return QSpinBox_maximum(pObject)

	Func minimum 
		return QSpinBox_minimum(pObject)

	Func prefix 
		return QSpinBox_prefix(pObject)

	Func setDisplayIntegerBase P1
		return QSpinBox_setDisplayIntegerBase(pObject,P1)

	Func setMaximum P1
		return QSpinBox_setMaximum(pObject,P1)

	Func setMinimum P1
		return QSpinBox_setMinimum(pObject,P1)

	Func setPrefix P1
		return QSpinBox_setPrefix(pObject,P1)

	Func setRange P1,P2
		return QSpinBox_setRange(pObject,P1,P2)

	Func setSingleStep P1
		return QSpinBox_setSingleStep(pObject,P1)

	Func setSuffix P1
		return QSpinBox_setSuffix(pObject,P1)

	Func singleStep 
		return QSpinBox_singleStep(pObject)

	Func suffix 
		return QSpinBox_suffix(pObject)

	Func value 
		return QSpinBox_value(pObject)

	Func setValue P1
		return QSpinBox_setValue(pObject,P1)

	Func setvalueChangedEvent P1
		return QSpinBox_setvalueChangedEvent(pObject,P1)

	Func getvalueChangedEvent 
		return QSpinBox_getvalueChangedEvent(pObject)

Class QAbstractSlider from QWidget

	pObject

	Func init P1
		pObject = QAbstractSlider_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractSlider_delete(pObject)

	Func ObjectPointer
		return pObject

	Func hasTracking 
		return QAbstractSlider_hasTracking(pObject)

	Func invertedAppearance 
		return QAbstractSlider_invertedAppearance(pObject)

	Func invertedControls 
		return QAbstractSlider_invertedControls(pObject)

	Func isSliderDown 
		return QAbstractSlider_isSliderDown(pObject)

	Func maximum 
		return QAbstractSlider_maximum(pObject)

	Func minimum 
		return QAbstractSlider_minimum(pObject)

	Func orientation 
		return QAbstractSlider_orientation(pObject)

	Func pageStep 
		return QAbstractSlider_pageStep(pObject)

	Func setInvertedAppearance P1
		return QAbstractSlider_setInvertedAppearance(pObject,P1)

	Func setInvertedControls P1
		return QAbstractSlider_setInvertedControls(pObject,P1)

	Func setMaximum P1
		return QAbstractSlider_setMaximum(pObject,P1)

	Func setMinimum P1
		return QAbstractSlider_setMinimum(pObject,P1)

	Func setPageStep P1
		return QAbstractSlider_setPageStep(pObject,P1)

	Func setSingleStep P1
		return QAbstractSlider_setSingleStep(pObject,P1)

	Func setSliderDown P1
		return QAbstractSlider_setSliderDown(pObject,P1)

	Func setSliderPosition P1
		return QAbstractSlider_setSliderPosition(pObject,P1)

	Func setTracking P1
		return QAbstractSlider_setTracking(pObject,P1)

	Func singleStep 
		return QAbstractSlider_singleStep(pObject)

	Func sliderPosition 
		return QAbstractSlider_sliderPosition(pObject)

	Func triggerAction P1
		return QAbstractSlider_triggerAction(pObject,P1)

	Func value 
		return QAbstractSlider_value(pObject)

	Func setOrientation P1
		return QAbstractSlider_setOrientation(pObject,P1)

	Func setRange P1,P2
		return QAbstractSlider_setRange(pObject,P1,P2)

	Func setValue P1
		return QAbstractSlider_setValue(pObject,P1)

Class QSlider from QAbstractSlider

	pObject

	Func init P1
		pObject = QSlider_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSlider_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setTickInterval P1
		return QSlider_setTickInterval(pObject,P1)

	Func setTickPosition P1
		return QSlider_setTickPosition(pObject,P1)

	Func tickInterval 
		return QSlider_tickInterval(pObject)

	Func tickPosition 
		return QSlider_tickPosition(pObject)

	Func minimumSizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QSlider_minimumSizeHint(pObject)
		return pTempObj

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QSlider_sizeHint(pObject)
		return pTempObj

	Func setactionTriggeredEvent P1
		return QSlider_setactionTriggeredEvent(pObject,P1)

	Func setrangeChangedEvent P1
		return QSlider_setrangeChangedEvent(pObject,P1)

	Func setsliderMovedEvent P1
		return QSlider_setsliderMovedEvent(pObject,P1)

	Func setsliderPressedEvent P1
		return QSlider_setsliderPressedEvent(pObject,P1)

	Func setsliderReleasedEvent P1
		return QSlider_setsliderReleasedEvent(pObject,P1)

	Func setvalueChangedEvent P1
		return QSlider_setvalueChangedEvent(pObject,P1)

	Func getactionTriggeredEvent 
		return QSlider_getactionTriggeredEvent(pObject)

	Func getrangeChangedEvent 
		return QSlider_getrangeChangedEvent(pObject)

	Func getsliderMovedEvent 
		return QSlider_getsliderMovedEvent(pObject)

	Func getsliderPressedEvent 
		return QSlider_getsliderPressedEvent(pObject)

	Func getsliderReleasedEvent 
		return QSlider_getsliderReleasedEvent(pObject)

	Func getvalueChangedEvent 
		return QSlider_getvalueChangedEvent(pObject)

Class QDateTimeEdit from QAbstractSpinBox

	pObject

	Func init P1
		pObject = QDateTimeEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDateTimeEdit_delete(pObject)

	Func ObjectPointer
		return pObject

	Func calendarPopup 
		return QDateTimeEdit_calendarPopup(pObject)

	Func calendarWidget 
		pTempObj = new QCalendarWidget
		pTempObj.pObject = QDateTimeEdit_calendarWidget(pObject)
		return pTempObj

	Func clearMaximumDate 
		return QDateTimeEdit_clearMaximumDate(pObject)

	Func clearMaximumDateTime 
		return QDateTimeEdit_clearMaximumDateTime(pObject)

	Func clearMaximumTime 
		return QDateTimeEdit_clearMaximumTime(pObject)

	Func clearMinimumDate 
		return QDateTimeEdit_clearMinimumDate(pObject)

	Func clearMinimumDateTime 
		return QDateTimeEdit_clearMinimumDateTime(pObject)

	Func clearMinimumTime 
		return QDateTimeEdit_clearMinimumTime(pObject)

	Func currentSection 
		return QDateTimeEdit_currentSection(pObject)

	Func currentSectionIndex 
		return QDateTimeEdit_currentSectionIndex(pObject)

	Func date 
		pTempObj = new QDate
		pTempObj.pObject = QDateTimeEdit_date(pObject)
		return pTempObj

	Func dateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTimeEdit_dateTime(pObject)
		return pTempObj

	Func displayFormat 
		return QDateTimeEdit_displayFormat(pObject)

	Func displayedSections 
		return QDateTimeEdit_displayedSections(pObject)

	Func maximumDate 
		pTempObj = new QDate
		pTempObj.pObject = QDateTimeEdit_maximumDate(pObject)
		return pTempObj

	Func maximumDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTimeEdit_maximumDateTime(pObject)
		return pTempObj

	Func maximumTime 
		pTempObj = new QTime
		pTempObj.pObject = QDateTimeEdit_maximumTime(pObject)
		return pTempObj

	Func minimumDate 
		pTempObj = new QDate
		pTempObj.pObject = QDateTimeEdit_minimumDate(pObject)
		return pTempObj

	Func minimumDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTimeEdit_minimumDateTime(pObject)
		return pTempObj

	Func minimumTime 
		pTempObj = new QTime
		pTempObj.pObject = QDateTimeEdit_minimumTime(pObject)
		return pTempObj

	Func sectionAt P1
		return QDateTimeEdit_sectionAt(pObject,P1)

	Func sectionCount 
		return QDateTimeEdit_sectionCount(pObject)

	Func sectionText P1
		return QDateTimeEdit_sectionText(pObject,P1)

	Func setCalendarPopup P1
		return QDateTimeEdit_setCalendarPopup(pObject,P1)

	Func setCalendarWidget P1
		return QDateTimeEdit_setCalendarWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setCurrentSection P1
		return QDateTimeEdit_setCurrentSection(pObject,P1)

	Func setCurrentSectionIndex P1
		return QDateTimeEdit_setCurrentSectionIndex(pObject,P1)

	Func setDateRange P1,P2
		return QDateTimeEdit_setDateRange(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setDateTimeRange P1,P2
		return QDateTimeEdit_setDateTimeRange(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setDisplayFormat P1
		return QDateTimeEdit_setDisplayFormat(pObject,P1)

	Func setMaximumDate P1
		return QDateTimeEdit_setMaximumDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaximumDateTime P1
		return QDateTimeEdit_setMaximumDateTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaximumTime P1
		return QDateTimeEdit_setMaximumTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumDate P1
		return QDateTimeEdit_setMinimumDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumDateTime P1
		return QDateTimeEdit_setMinimumDateTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumTime P1
		return QDateTimeEdit_setMinimumTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelectedSection P1
		return QDateTimeEdit_setSelectedSection(pObject,P1)

	Func setTimeRange P1,P2
		return QDateTimeEdit_setTimeRange(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setTimeSpec P1
		return QDateTimeEdit_setTimeSpec(pObject,P1)

	Func time 
		pTempObj = new QTime
		pTempObj.pObject = QDateTimeEdit_time(pObject)
		return pTempObj

	Func timeSpec 
		return QDateTimeEdit_timeSpec(pObject)

	Func setDate P1
		return QDateTimeEdit_setDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setDateTime P1
		return QDateTimeEdit_setDateTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setTime P1
		return QDateTimeEdit_setTime(pObject,GetObjectPointerFromRingObject(P1))

Class QAbstractSpinBox from QWidget

	pObject

	Func init P1
		pObject = QAbstractSpinBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractSpinBox_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alignment 
		return QAbstractSpinBox_alignment(pObject)

	Func buttonSymbols 
		return QAbstractSpinBox_buttonSymbols(pObject)

	Func correctionMode 
		return QAbstractSpinBox_correctionMode(pObject)

	Func hasAcceptableInput 
		return QAbstractSpinBox_hasAcceptableInput(pObject)

	Func hasFrame 
		return QAbstractSpinBox_hasFrame(pObject)

	Func interpretText 
		return QAbstractSpinBox_interpretText(pObject)

	Func isAccelerated 
		return QAbstractSpinBox_isAccelerated(pObject)

	Func isReadOnly 
		return QAbstractSpinBox_isReadOnly(pObject)

	Func keyboardTracking 
		return QAbstractSpinBox_keyboardTracking(pObject)

	Func setAccelerated P1
		return QAbstractSpinBox_setAccelerated(pObject,P1)

	Func setAlignment P1
		return QAbstractSpinBox_setAlignment(pObject,P1)

	Func setButtonSymbols P1
		return QAbstractSpinBox_setButtonSymbols(pObject,P1)

	Func setCorrectionMode P1
		return QAbstractSpinBox_setCorrectionMode(pObject,P1)

	Func setFrame P1
		return QAbstractSpinBox_setFrame(pObject,P1)

	Func setKeyboardTracking P1
		return QAbstractSpinBox_setKeyboardTracking(pObject,P1)

	Func setReadOnly P1
		return QAbstractSpinBox_setReadOnly(pObject,P1)

	Func setSpecialValueText P1
		return QAbstractSpinBox_setSpecialValueText(pObject,P1)

	Func setWrapping P1
		return QAbstractSpinBox_setWrapping(pObject,P1)

	Func specialValueText 
		return QAbstractSpinBox_specialValueText(pObject)

	Func stepBy P1
		return QAbstractSpinBox_stepBy(pObject,P1)

	Func text 
		return QAbstractSpinBox_text(pObject)

	Func wrapping 
		return QAbstractSpinBox_wrapping(pObject)

	Func clear 
		return QAbstractSpinBox_clear(pObject)

	Func selectAll 
		return QAbstractSpinBox_selectAll(pObject)

	Func stepDown 
		return QAbstractSpinBox_stepDown(pObject)

	Func stepUp 
		return QAbstractSpinBox_stepUp(pObject)

Class QDial from QAbstractSlider

	pObject

	Func init P1
		pObject = QDial_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDial_delete(pObject)

	Func ObjectPointer
		return pObject

	Func notchSize 
		return QDial_notchSize(pObject)

	Func notchTarget 
		return QDial_notchTarget(pObject)

	Func notchesVisible 
		return QDial_notchesVisible(pObject)

	Func setNotchTarget P1
		return QDial_setNotchTarget(pObject,P1)

	Func wrapping 
		return QDial_wrapping(pObject)

	Func minimumSizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QDial_minimumSizeHint(pObject)
		return pTempObj

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QDial_sizeHint(pObject)
		return pTempObj

	Func setNotchesVisible P1
		return QDial_setNotchesVisible(pObject,P1)

	Func setWrapping P1
		return QDial_setWrapping(pObject,P1)

	Func setactionTriggeredEvent P1
		return QDial_setactionTriggeredEvent(pObject,P1)

	Func setrangeChangedEvent P1
		return QDial_setrangeChangedEvent(pObject,P1)

	Func setsliderMovedEvent P1
		return QDial_setsliderMovedEvent(pObject,P1)

	Func setsliderPressedEvent P1
		return QDial_setsliderPressedEvent(pObject,P1)

	Func setsliderReleasedEvent P1
		return QDial_setsliderReleasedEvent(pObject,P1)

	Func setvalueChangedEvent P1
		return QDial_setvalueChangedEvent(pObject,P1)

	Func getactionTriggeredEvent 
		return QDial_getactionTriggeredEvent(pObject)

	Func getrangeChangedEvent 
		return QDial_getrangeChangedEvent(pObject)

	Func getsliderMovedEvent 
		return QDial_getsliderMovedEvent(pObject)

	Func getsliderPressedEvent 
		return QDial_getsliderPressedEvent(pObject)

	Func getsliderReleasedEvent 
		return QDial_getsliderReleasedEvent(pObject)

	Func getvalueChangedEvent 
		return QDial_getvalueChangedEvent(pObject)

Class QWebView from QWidget

	pObject

	Func init P1
		pObject = QWebView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QWebView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func hasSelection 
		return QWebView_hasSelection(pObject)

	Func history 
		return QWebView_history(pObject)

	Func loadpage P1
		return QWebView_load(pObject,GetObjectPointerFromRingObject(P1))

	Func page 
		return QWebView_page(pObject)

	Func pageAction P1
		pTempObj = new QAction
		pTempObj.pObject = QWebView_pageAction(pObject,P1)
		return pTempObj

	Func selectedText 
		return QWebView_selectedText(pObject)

	Func setContent P1,P2,P3
		return QWebView_setContent(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3))

	Func setHtml P1,P2
		return QWebView_setHtml(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setPage P1
		return QWebView_setPage(pObject,GetObjectPointerFromRingObject(P1))

	Func setUrl P1
		return QWebView_setUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func setZoomFactor P1
		return QWebView_setZoomFactor(pObject,P1)

	Func settings 
		return QWebView_settings(pObject)

	Func title 
		return QWebView_title(pObject)

	Func triggerPageAction P1,P2
		return QWebView_triggerPageAction(pObject,P1,P2)

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QWebView_url(pObject)
		return pTempObj

	Func zoomFactor 
		return QWebView_zoomFactor(pObject)

	Func back 
		return QWebView_back(pObject)

	Func forward 
		return QWebView_forward(pObject)

	Func print P1
		return QWebView_print(pObject,GetObjectPointerFromRingObject(P1))

	Func reload 
		return QWebView_reload(pObject)

	Func stop 
		return QWebView_stop(pObject)

	Func setloadFinishedEvent P1
		return QWebView_setloadFinishedEvent(pObject,P1)

	Func setloadProgressEvent P1
		return QWebView_setloadProgressEvent(pObject,P1)

	Func setloadStartedEvent P1
		return QWebView_setloadStartedEvent(pObject,P1)

	Func setselectionChangedEvent P1
		return QWebView_setselectionChangedEvent(pObject,P1)

	Func settitleChangedEvent P1
		return QWebView_settitleChangedEvent(pObject,P1)

	Func seturlChangedEvent P1
		return QWebView_seturlChangedEvent(pObject,P1)

	Func getloadFinishedEvent 
		return QWebView_getloadFinishedEvent(pObject)

	Func getloadProgressEvent 
		return QWebView_getloadProgressEvent(pObject)

	Func getloadStartedEvent 
		return QWebView_getloadStartedEvent(pObject)

	Func getselectionChangedEvent 
		return QWebView_getselectionChangedEvent(pObject)

	Func gettitleChangedEvent 
		return QWebView_gettitleChangedEvent(pObject)

	Func geturlChangedEvent 
		return QWebView_geturlChangedEvent(pObject)

Class QUrl

	pObject

	Func init P1
		pObject = QUrl_new(P1)
		return self

	Func delete
		pObject = QUrl_delete(pObject)

	Func ObjectPointer
		return pObject

	Func authority P1
		return QUrl_authority(pObject,P1)

	Func clear 
		return QUrl_clear(pObject)

	Func errorString 
		return QUrl_errorString(pObject)

	Func fileName P1
		return QUrl_fileName(pObject,P1)

	Func fragment P1
		return QUrl_fragment(pObject,P1)

	Func hasFragment 
		return QUrl_hasFragment(pObject)

	Func hasQuery 
		return QUrl_hasQuery(pObject)

	Func host P1
		return QUrl_host(pObject,P1)

	Func isEmpty 
		return QUrl_isEmpty(pObject)

	Func isLocalFile 
		return QUrl_isLocalFile(pObject)

	Func isParentOf P1
		return QUrl_isParentOf(pObject,GetObjectPointerFromRingObject(P1))

	Func isRelative 
		return QUrl_isRelative(pObject)

	Func isValid 
		return QUrl_isValid(pObject)

	Func password P1
		return QUrl_password(pObject,P1)

	Func path P1
		return QUrl_path(pObject,P1)

	Func port P1
		return QUrl_port(pObject,P1)

	Func query P1
		return QUrl_query(pObject,P1)

	Func resolved P1
		pTempObj = new QUrl
		pTempObj.pObject = QUrl_resolved(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func scheme 
		return QUrl_scheme(pObject)

	Func setAuthority P1,P2
		return QUrl_setAuthority(pObject,P1,P2)

	Func setFragment P1,P2
		return QUrl_setFragment(pObject,P1,P2)

	Func setHost P1,P2
		return QUrl_setHost(pObject,P1,P2)

	Func setPassword P1,P2
		return QUrl_setPassword(pObject,P1,P2)

	Func setPath P1,P2
		return QUrl_setPath(pObject,P1,P2)

	Func setPort P1
		return QUrl_setPort(pObject,P1)

	Func setQuery P1,P2
		return QUrl_setQuery(pObject,P1,P2)

	Func setScheme P1
		return QUrl_setScheme(pObject,P1)

	Func setUrl P1,P2
		return QUrl_setUrl(pObject,P1,P2)

	Func setUserInfo P1,P2
		return QUrl_setUserInfo(pObject,P1,P2)

	Func setUserName P1,P2
		return QUrl_setUserName(pObject,P1,P2)

	Func swap P1
		return QUrl_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toLocalFile 
		return QUrl_toLocalFile(pObject)

	Func topLevelDomain P1
		return QUrl_topLevelDomain(pObject,P1)

	Func userInfo P1
		return QUrl_userInfo(pObject,P1)

	Func userName P1
		return QUrl_userName(pObject,P1)

	Func fromLocalFile P1
		pTempObj = new QUrl
		pTempObj.pObject = QUrl_fromLocalFile(pObject,P1)
		return pTempObj

Class QCheckBox from QAbstractButton

	pObject

	Func init P1
		pObject = QCheckBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QCheckBox_delete(pObject)

	Func ObjectPointer
		return pObject

	Func checkState 
		return QCheckBox_checkState(pObject)

	Func isTristate 
		return QCheckBox_isTristate(pObject)

	Func setCheckState P1
		return QCheckBox_setCheckState(pObject,P1)

	Func setTristate P1
		return QCheckBox_setTristate(pObject,P1)

	Func minimumSizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QCheckBox_minimumSizeHint(pObject)
		return pTempObj

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QCheckBox_sizeHint(pObject)
		return pTempObj

	Func setstateChangedEvent P1
		return QCheckBox_setstateChangedEvent(pObject,P1)

	Func setclickedEvent P1
		return QCheckBox_setclickedEvent(pObject,P1)

	Func setpressedEvent P1
		return QCheckBox_setpressedEvent(pObject,P1)

	Func setreleasedEvent P1
		return QCheckBox_setreleasedEvent(pObject,P1)

	Func settoggledEvent P1
		return QCheckBox_settoggledEvent(pObject,P1)

	Func getstateChangedEvent 
		return QCheckBox_getstateChangedEvent(pObject)

	Func getclickedEvent 
		return QCheckBox_getclickedEvent(pObject)

	Func getpressedEvent 
		return QCheckBox_getpressedEvent(pObject)

	Func getreleasedEvent 
		return QCheckBox_getreleasedEvent(pObject)

	Func gettoggledEvent 
		return QCheckBox_gettoggledEvent(pObject)

Class QAbstractButton from QWidget

	pObject

	Func init P1
		pObject = QAbstractButton_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractButton_delete(pObject)

	Func ObjectPointer
		return pObject

	Func autoExclusive 
		return QAbstractButton_autoExclusive(pObject)

	Func autoRepeat 
		return QAbstractButton_autoRepeat(pObject)

	Func autoRepeatDelay 
		return QAbstractButton_autoRepeatDelay(pObject)

	Func autoRepeatInterval 
		return QAbstractButton_autoRepeatInterval(pObject)

	Func group 
		pTempObj = new QButtonGroup
		pTempObj.pObject = QAbstractButton_group(pObject)
		return pTempObj

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QAbstractButton_icon(pObject)
		return pTempObj

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QAbstractButton_iconSize(pObject)
		return pTempObj

	Func isCheckable 
		return QAbstractButton_isCheckable(pObject)

	Func isChecked 
		return QAbstractButton_isChecked(pObject)

	Func isDown 
		return QAbstractButton_isDown(pObject)

	Func setAutoExclusive P1
		return QAbstractButton_setAutoExclusive(pObject,P1)

	Func setAutoRepeat P1
		return QAbstractButton_setAutoRepeat(pObject,P1)

	Func setAutoRepeatDelay P1
		return QAbstractButton_setAutoRepeatDelay(pObject,P1)

	Func setAutoRepeatInterval P1
		return QAbstractButton_setAutoRepeatInterval(pObject,P1)

	Func setCheckable P1
		return QAbstractButton_setCheckable(pObject,P1)

	Func setDown P1
		return QAbstractButton_setDown(pObject,P1)

	Func setIcon P1
		return QAbstractButton_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setShortcut P1
		return QAbstractButton_setShortcut(pObject,GetObjectPointerFromRingObject(P1))

	Func setText P1
		return QAbstractButton_setText(pObject,P1)

	Func shortcut 
		pTempObj = new QKeySequence
		pTempObj.pObject = QAbstractButton_shortcut(pObject)
		return pTempObj

	Func text 
		return QAbstractButton_text(pObject)

	Func animateClick P1
		return QAbstractButton_animateClick(pObject,P1)

	Func click 
		return QAbstractButton_click(pObject)

	Func setChecked P1
		return QAbstractButton_setChecked(pObject,P1)

	Func setIconSize P1
		return QAbstractButton_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func toggle 
		return QAbstractButton_toggle(pObject)

Class QRadioButton from QAbstractButton

	pObject

	Func init P1
		pObject = QRadioButton_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QRadioButton_delete(pObject)

	Func ObjectPointer
		return pObject

	Func minimumSizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QRadioButton_minimumSizeHint(pObject)
		return pTempObj

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QRadioButton_sizeHint(pObject)
		return pTempObj

	Func setclickedEvent P1
		return QRadioButton_setclickedEvent(pObject,P1)

	Func setpressedEvent P1
		return QRadioButton_setpressedEvent(pObject,P1)

	Func setreleasedEvent P1
		return QRadioButton_setreleasedEvent(pObject,P1)

	Func settoggledEvent P1
		return QRadioButton_settoggledEvent(pObject,P1)

	Func getclickedEvent 
		return QRadioButton_getclickedEvent(pObject)

	Func getpressedEvent 
		return QRadioButton_getpressedEvent(pObject)

	Func getreleasedEvent 
		return QRadioButton_getreleasedEvent(pObject)

	Func gettoggledEvent 
		return QRadioButton_gettoggledEvent(pObject)

Class QButtonGroup

	pObject

	Func init P1
		pObject = QButtonGroup_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QButtonGroup_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addButton P1,P2
		return QButtonGroup_addButton(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func button P1
		pTempObj = new QAbstractButton
		pTempObj.pObject = QButtonGroup_button(pObject,P1)
		return pTempObj

	Func checkedButton 
		pTempObj = new QAbstractButton
		pTempObj.pObject = QButtonGroup_checkedButton(pObject)
		return pTempObj

	Func checkedId 
		return QButtonGroup_checkedId(pObject)

	Func exclusive 
		return QButtonGroup_exclusive(pObject)

	Func id P1
		return QButtonGroup_id(pObject,GetObjectPointerFromRingObject(P1))

	Func removeButton P1
		return QButtonGroup_removeButton(pObject,GetObjectPointerFromRingObject(P1))

	Func setExclusive P1
		return QButtonGroup_setExclusive(pObject,P1)

	Func setId P1,P2
		return QButtonGroup_setId(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setbuttonClickedEvent P1
		return QButtonGroup_setbuttonClickedEvent(pObject,P1)

	Func setbuttonPressedEvent P1
		return QButtonGroup_setbuttonPressedEvent(pObject,P1)

	Func setbuttonReleasedEvent P1
		return QButtonGroup_setbuttonReleasedEvent(pObject,P1)

	Func getbuttonClickedEvent 
		return QButtonGroup_getbuttonClickedEvent(pObject)

	Func getbuttonPressedEvent 
		return QButtonGroup_getbuttonPressedEvent(pObject)

	Func getbuttonReleasedEvent 
		return QButtonGroup_getbuttonReleasedEvent(pObject)

Class QMediaPlayer

	pObject

	Func init 
		pObject = QMediaPlayer_new()
		return self

	Func delete
		pObject = QMediaPlayer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bufferStatus 
		return QMediaPlayer_bufferStatus(pObject)

	Func currentMedia 
		return QMediaPlayer_currentMedia(pObject)

	Func currentNetworkConfiguration 
		return QMediaPlayer_currentNetworkConfiguration(pObject)

	Func duration 
		return QMediaPlayer_duration(pObject)

	Func error 
		return QMediaPlayer_error(pObject)

	Func errorString 
		return QMediaPlayer_errorString(pObject)

	Func isAudioAvailable 
		return QMediaPlayer_isAudioAvailable(pObject)

	Func isMuted 
		return QMediaPlayer_isMuted(pObject)

	Func isSeekable 
		return QMediaPlayer_isSeekable(pObject)

	Func isVideoAvailable 
		return QMediaPlayer_isVideoAvailable(pObject)

	Func media 
		return QMediaPlayer_media(pObject)

	Func mediaStatus 
		return QMediaPlayer_mediaStatus(pObject)

	Func mediaStream 
		pTempObj = new QIODevice
		pTempObj.pObject = QMediaPlayer_mediaStream(pObject)
		return pTempObj

	Func playbackRate 
		return QMediaPlayer_playbackRate(pObject)

	Func playlist 
		pTempObj = new QMediaPlaylist
		pTempObj.pObject = QMediaPlayer_playlist(pObject)
		return pTempObj

	Func position 
		return QMediaPlayer_position(pObject)

	Func setVideoOutput P1
		return QMediaPlayer_setVideoOutput(pObject,GetObjectPointerFromRingObject(P1))

	Func state 
		return QMediaPlayer_state(pObject)

	Func volume 
		return QMediaPlayer_volume(pObject)

	Func pause 
		return QMediaPlayer_pause(pObject)

	Func play 
		return QMediaPlayer_play(pObject)

	Func setMedia P1
		return QMediaPlayer_setMedia(pObject,GetObjectPointerFromRingObject(P1))

	Func setMuted P1
		return QMediaPlayer_setMuted(pObject,P1)

	Func setPlaybackRate P1
		return QMediaPlayer_setPlaybackRate(pObject,P1)

	Func setPlaylist P1
		return QMediaPlayer_setPlaylist(pObject,GetObjectPointerFromRingObject(P1))

	Func setPosition P1
		return QMediaPlayer_setPosition(pObject,P1)

	Func setVolume P1
		return QMediaPlayer_setVolume(pObject,P1)

	Func stop 
		return QMediaPlayer_stop(pObject)

Class QMediaPlaylist

	pObject

	Func init 
		pObject = QMediaPlaylist_new()
		return self

	Func delete
		pObject = QMediaPlaylist_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addMedia P1
		return QMediaPlaylist_addMedia(pObject,GetObjectPointerFromRingObject(P1))

	Func clear 
		return QMediaPlaylist_clear(pObject)

	Func currentIndex 
		return QMediaPlaylist_currentIndex(pObject)

	Func currentMedia 
		return QMediaPlaylist_currentMedia(pObject)

	Func error 
		return QMediaPlaylist_error(pObject)

	Func errorString 
		return QMediaPlaylist_errorString(pObject)

	Func insertMedia P1,P2
		return QMediaPlaylist_insertMedia(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isEmpty 
		return QMediaPlaylist_isEmpty(pObject)

	Func isReadOnly 
		return QMediaPlaylist_isReadOnly(pObject)

	Func loadfile P1,P2
		return QMediaPlaylist_load(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func media P1
		return QMediaPlaylist_media(pObject,P1)

	Func mediaCount 
		return QMediaPlaylist_mediaCount(pObject)

	Func nextIndex P1
		return QMediaPlaylist_nextIndex(pObject,P1)

	Func playbackMode 
		return QMediaPlaylist_playbackMode(pObject)

	Func previousIndex P1
		return QMediaPlaylist_previousIndex(pObject,P1)

	Func removeMedia P1,P2
		return QMediaPlaylist_removeMedia(pObject,P1,P2)

	Func save P1,P2
		return QMediaPlaylist_save(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setPlaybackMode P1
		return QMediaPlaylist_setPlaybackMode(pObject,P1)

	Func movenext 
		return QMediaPlaylist_next(pObject)

	Func previous 
		return QMediaPlaylist_previous(pObject)

	Func setCurrentIndex P1
		return QMediaPlaylist_setCurrentIndex(pObject,P1)

	Func shuffle 
		return QMediaPlaylist_shuffle(pObject)

Class QVideoWidget from QWidget

	pObject

	Func init P1
		pObject = QVideoWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QVideoWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func aspectRatioMode 
		return QVideoWidget_aspectRatioMode(pObject)

	Func brightness 
		return QVideoWidget_brightness(pObject)

	Func contrast 
		return QVideoWidget_contrast(pObject)

	Func hue 
		return QVideoWidget_hue(pObject)

	Func isFullScreen 
		return QVideoWidget_isFullScreen(pObject)

	Func saturation 
		return QVideoWidget_saturation(pObject)

	Func setAspectRatioMode P1
		return QVideoWidget_setAspectRatioMode(pObject,P1)

	Func setBrightness P1
		return QVideoWidget_setBrightness(pObject,P1)

	Func setContrast P1
		return QVideoWidget_setContrast(pObject,P1)

	Func setFullScreen P1
		return QVideoWidget_setFullScreen(pObject,P1)

	Func setHue P1
		return QVideoWidget_setHue(pObject,P1)

	Func setSaturation P1
		return QVideoWidget_setSaturation(pObject,P1)

	Func setbrightnessChangedEvent P1
		return QVideoWidget_setbrightnessChangedEvent(pObject,P1)

	Func setcontrastChangedEvent P1
		return QVideoWidget_setcontrastChangedEvent(pObject,P1)

	Func setfullScreenChangedEvent P1
		return QVideoWidget_setfullScreenChangedEvent(pObject,P1)

	Func sethueChangedEvent P1
		return QVideoWidget_sethueChangedEvent(pObject,P1)

	Func setsaturationChangedEvent P1
		return QVideoWidget_setsaturationChangedEvent(pObject,P1)

	Func getbrightnessChangedEvent 
		return QVideoWidget_getbrightnessChangedEvent(pObject)

	Func getcontrastChangedEvent 
		return QVideoWidget_getcontrastChangedEvent(pObject)

	Func getfullScreenChangedEvent 
		return QVideoWidget_getfullScreenChangedEvent(pObject)

	Func gethueChangedEvent 
		return QVideoWidget_gethueChangedEvent(pObject)

	Func getsaturationChangedEvent 
		return QVideoWidget_getsaturationChangedEvent(pObject)

Class QAction

	pObject

	Func init P1
		pObject = QAction_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAction_delete(pObject)

	Func ObjectPointer
		return pObject

	Func actionGroup 
		return QAction_actionGroup(pObject)

	Func activate P1
		return QAction_activate(pObject,P1)

	Func autoRepeat 
		return QAction_autoRepeat(pObject)

	Func data 
		pTempObj = new QVariant
		pTempObj.pObject = QAction_data(pObject)
		return pTempObj

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QAction_font(pObject)
		return pTempObj

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QAction_icon(pObject)
		return pTempObj

	Func iconText 
		return QAction_iconText(pObject)

	Func isCheckable 
		return QAction_isCheckable(pObject)

	Func isChecked 
		return QAction_isChecked(pObject)

	Func isEnabled 
		return QAction_isEnabled(pObject)

	Func isIconVisibleInMenu 
		return QAction_isIconVisibleInMenu(pObject)

	Func isSeparator 
		return QAction_isSeparator(pObject)

	Func isVisible 
		return QAction_isVisible(pObject)

	Func menu 
		pTempObj = new QMenu
		pTempObj.pObject = QAction_menu(pObject)
		return pTempObj

	Func menuRole 
		return QAction_menuRole(pObject)

	Func parentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QAction_parentWidget(pObject)
		return pTempObj

	Func priority 
		return QAction_priority(pObject)

	Func setActionGroup P1
		return QAction_setActionGroup(pObject,GetObjectPointerFromRingObject(P1))

	Func setAutoRepeat P1
		return QAction_setAutoRepeat(pObject,P1)

	Func setCheckable P1
		return QAction_setCheckable(pObject,P1)

	Func setData P1
		return QAction_setData(pObject,GetObjectPointerFromRingObject(P1))

	Func setFont P1
		return QAction_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QAction_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setIconText P1
		return QAction_setIconText(pObject,P1)

	Func setIconVisibleInMenu P1
		return QAction_setIconVisibleInMenu(pObject,P1)

	Func setMenu P1
		return QAction_setMenu(pObject,GetObjectPointerFromRingObject(P1))

	Func setMenuRole P1
		return QAction_setMenuRole(pObject,P1)

	Func setPriority P1
		return QAction_setPriority(pObject,P1)

	Func setSeparator P1
		return QAction_setSeparator(pObject,P1)

	Func setShortcut P1
		return QAction_setShortcut(pObject,GetObjectPointerFromRingObject(P1))

	Func setShortcutContext P1
		return QAction_setShortcutContext(pObject,P1)

	Func setShortcuts P1
		return QAction_setShortcuts(pObject,P1)

	Func setStatusTip P1
		return QAction_setStatusTip(pObject,P1)

	Func setText P1
		return QAction_setText(pObject,P1)

	Func setToolTip P1
		return QAction_setToolTip(pObject,P1)

	Func setWhatsThis P1
		return QAction_setWhatsThis(pObject,P1)

	Func shortcut 
		pTempObj = new QKeySequence
		pTempObj.pObject = QAction_shortcut(pObject)
		return pTempObj

	Func shortcutContext 
		return QAction_shortcutContext(pObject)

	Func showStatusText P1
		return QAction_showStatusText(pObject,GetObjectPointerFromRingObject(P1))

	Func statusTip 
		return QAction_statusTip(pObject)

	Func text 
		return QAction_text(pObject)

	Func toolTip 
		return QAction_toolTip(pObject)

	Func whatsThis 
		return QAction_whatsThis(pObject)

	Func hover 
		return QAction_hover(pObject)

	Func setChecked P1
		return QAction_setChecked(pObject,P1)

	Func setDisabled P1
		return QAction_setDisabled(pObject,P1)

	Func setEnabled P1
		return QAction_setEnabled(pObject,P1)

	Func setVisible P1
		return QAction_setVisible(pObject,P1)

	Func toggle 
		return QAction_toggle(pObject)

	Func trigger 
		return QAction_trigger(pObject)

	Func setClickEvent P1
		return QAction_setClickEvent(pObject,P1)

	Func getClickEvent 
		return QAction_getClickEvent(pObject)

Class QEvent

	pObject

	Func init P1
		pObject = QEvent_new(P1)
		return self

	Func delete
		pObject = QEvent_delete(pObject)

	Func ObjectPointer
		return pObject

	Func accept 
		return QEvent_accept(pObject)

	Func ignore 
		return QEvent_ignore(pObject)

	Func isAccepted 
		return QEvent_isAccepted(pObject)

	Func setAccepted P1
		return QEvent_setAccepted(pObject,P1)

	Func spontaneous 
		return QEvent_spontaneous(pObject)

	Func type 
		return QEvent_type(pObject)

Class QMessageBox from QDialog

	pObject

	Func init P1
		pObject = QMessageBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMessageBox_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addButton P1,P2
		return QMessageBox_addButton(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func button P1
		pTempObj = new QAbstractButton
		pTempObj.pObject = QMessageBox_button(pObject,P1)
		return pTempObj

	Func buttonRole P1
		return QMessageBox_buttonRole(pObject,GetObjectPointerFromRingObject(P1))

	Func clickedButton 
		pTempObj = new QAbstractButton
		pTempObj.pObject = QMessageBox_clickedButton(pObject)
		return pTempObj

	Func defaultButton 
		pTempObj = new QPushButton
		pTempObj.pObject = QMessageBox_defaultButton(pObject)
		return pTempObj

	Func detailedText 
		return QMessageBox_detailedText(pObject)

	Func escapeButton 
		pTempObj = new QAbstractButton
		pTempObj.pObject = QMessageBox_escapeButton(pObject)
		return pTempObj

	Func iconPixmap 
		pTempObj = new QPixmap
		pTempObj.pObject = QMessageBox_iconPixmap(pObject)
		return pTempObj

	Func informativeText 
		return QMessageBox_informativeText(pObject)

	Func open P1,P2
		return QMessageBox_open(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func removeButton P1
		return QMessageBox_removeButton(pObject,GetObjectPointerFromRingObject(P1))

	Func setDefaultButton P1
		return QMessageBox_setDefaultButton(pObject,GetObjectPointerFromRingObject(P1))

	Func setDetailedText P1
		return QMessageBox_setDetailedText(pObject,P1)

	Func setEscapeButton P1
		return QMessageBox_setEscapeButton(pObject,GetObjectPointerFromRingObject(P1))

	Func setIconPixmap P1
		return QMessageBox_setIconPixmap(pObject,GetObjectPointerFromRingObject(P1))

	Func setInformativeText P1
		return QMessageBox_setInformativeText(pObject,P1)

	Func setStandardButtons P1
		return QMessageBox_setStandardButtons(pObject,P1)

	Func setText P1
		return QMessageBox_setText(pObject,P1)

	Func setTextFormat P1
		return QMessageBox_setTextFormat(pObject,P1)

	Func setWindowModality P1
		return QMessageBox_setWindowModality(pObject,P1)

	Func setWindowTitle P1
		return QMessageBox_setWindowTitle(pObject,P1)

	Func standardButton P1
		return QMessageBox_standardButton(pObject,GetObjectPointerFromRingObject(P1))

	Func standardButtons 
		return QMessageBox_standardButtons(pObject)

	Func text 
		return QMessageBox_text(pObject)

	Func textFormat 
		return QMessageBox_textFormat(pObject)

	Func exec 
		return QMessageBox_exec(pObject)

	Func about P1,P2,P3
		return QMessageBox_about(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func aboutQt P1,P2
		return QMessageBox_aboutQt(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func critical P1,P2,P3,P4,P5
		return QMessageBox_critical(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5)

	Func information P1,P2,P3,P4,P5
		return QMessageBox_information(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5)

	Func question P1,P2,P3,P4,P5
		return QMessageBox_question(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5)

	Func warning P1,P2,P3,P4,P5
		return QMessageBox_warning(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5)

Class QTimer

	pObject

	Func init P1
		pObject = QTimer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTimer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func interval 
		return QTimer_interval(pObject)

	Func isActive 
		return QTimer_isActive(pObject)

	Func isSingleShot 
		return QTimer_isSingleShot(pObject)

	Func setInterval P1
		return QTimer_setInterval(pObject,P1)

	Func setSingleShot P1
		return QTimer_setSingleShot(pObject,P1)

	Func timerId 
		return QTimer_timerId(pObject)

	Func start 
		return QTimer_start(pObject)

	Func stop 
		return QTimer_stop(pObject)

	Func settimeoutEvent P1
		return QTimer_settimeoutEvent(pObject,P1)

	Func gettimeoutEvent 
		return QTimer_gettimeoutEvent(pObject)

Class QFileDialog from QWidget

	pObject

	Func init P1
		pObject = QFileDialog_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QFileDialog_delete(pObject)

	Func ObjectPointer
		return pObject

	Func acceptMode 
		return QFileDialog_acceptMode(pObject)

	Func defaultSuffix 
		return QFileDialog_defaultSuffix(pObject)

	Func directory 
		pTempObj = new QDir
		pTempObj.pObject = QFileDialog_directory(pObject)
		return pTempObj

	Func directoryUrl 
		pTempObj = new QUrl
		pTempObj.pObject = QFileDialog_directoryUrl(pObject)
		return pTempObj

	Func fileMode 
		return QFileDialog_fileMode(pObject)

	Func filter 
		return QFileDialog_filter(pObject)

	Func history 
		pTempObj = new QStringList
		pTempObj.pObject = QFileDialog_history(pObject)
		return pTempObj

	Func iconProvider 
		return QFileDialog_iconProvider(pObject)

	Func itemDelegate 
		return QFileDialog_itemDelegate(pObject)

	Func labelText P1
		return QFileDialog_labelText(pObject,P1)

	Func mimeTypeFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QFileDialog_mimeTypeFilters(pObject)
		return pTempObj

	Func nameFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QFileDialog_nameFilters(pObject)
		return pTempObj

	Func open P1,P2
		return QFileDialog_open(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func options 
		return QFileDialog_options(pObject)

	Func proxyModel 
		return QFileDialog_proxyModel(pObject)

	Func restoreState P1
		return QFileDialog_restoreState(pObject,GetObjectPointerFromRingObject(P1))

	Func saveState 
		pTempObj = new QByteArray
		pTempObj.pObject = QFileDialog_saveState(pObject)
		return pTempObj

	Func selectFile P1
		return QFileDialog_selectFile(pObject,P1)

	Func selectMimeTypeFilter P1
		return QFileDialog_selectMimeTypeFilter(pObject,P1)

	Func selectNameFilter P1
		return QFileDialog_selectNameFilter(pObject,P1)

	Func selectUrl P1
		return QFileDialog_selectUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func selectedFiles 
		pTempObj = new QStringList
		pTempObj.pObject = QFileDialog_selectedFiles(pObject)
		return pTempObj

	Func selectedNameFilter 
		return QFileDialog_selectedNameFilter(pObject)

	Func setAcceptMode P1
		return QFileDialog_setAcceptMode(pObject,P1)

	Func setDefaultSuffix P1
		return QFileDialog_setDefaultSuffix(pObject,P1)

	Func setDirectory P1
		return QFileDialog_setDirectory(pObject,P1)

	Func setDirectoryUrl P1
		return QFileDialog_setDirectoryUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func setFileMode P1
		return QFileDialog_setFileMode(pObject,P1)

	Func setFilter P1
		return QFileDialog_setFilter(pObject,P1)

	Func setHistory P1
		return QFileDialog_setHistory(pObject,GetObjectPointerFromRingObject(P1))

	Func setIconProvider P1
		return QFileDialog_setIconProvider(pObject,GetObjectPointerFromRingObject(P1))

	Func setItemDelegate P1
		return QFileDialog_setItemDelegate(pObject,GetObjectPointerFromRingObject(P1))

	Func setLabelText P1,P2
		return QFileDialog_setLabelText(pObject,P1,P2)

	Func setMimeTypeFilters P1
		return QFileDialog_setMimeTypeFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setNameFilter P1
		return QFileDialog_setNameFilter(pObject,P1)

	Func setNameFilters P1
		return QFileDialog_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setOption P1,P2
		return QFileDialog_setOption(pObject,P1,P2)

	Func setOptions P1
		return QFileDialog_setOptions(pObject,P1)

	Func setProxyModel P1
		return QFileDialog_setProxyModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setViewMode P1
		return QFileDialog_setViewMode(pObject,P1)

	Func testOption P1
		return QFileDialog_testOption(pObject,P1)

	Func viewMode 
		return QFileDialog_viewMode(pObject)

	Func getExistingDirectory P1,P2,P3,P4
		return QFileDialog_getExistingDirectory(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func getExistingDirectoryUrl P1,P2,P3,P4,P5
		pTempObj = new QUrl
		pTempObj.pObject = QFileDialog_getExistingDirectoryUrl(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3),P4,GetObjectPointerFromRingObject(P5))
		return pTempObj

	Func getOpenFileName P1,P2,P3,P4
		return QFileDialog_getOpenFileName(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func getOpenFileUrl P1,P2,P3,P4,P5,P6,P7
		pTempObj = new QUrl
		pTempObj.pObject = QFileDialog_getOpenFileUrl(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3),P4,GetObjectPointerFromRingObject(P5),P6,GetObjectPointerFromRingObject(P7))
		return pTempObj

	Func getSaveFileName P1,P2,P3,P4
		return QFileDialog_getSaveFileName(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func getSaveFileUrl P1,P2,P3,P4,P5,P6,P7
		pTempObj = new QUrl
		pTempObj.pObject = QFileDialog_getSaveFileUrl(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3),P4,GetObjectPointerFromRingObject(P5),P6,GetObjectPointerFromRingObject(P7))
		return pTempObj

Class QPainter

	pObject

	Func init 
		pObject = QPainter_new()
		return self

	Func delete
		pObject = QPainter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func background 
		pTempObj = new QBrush
		pTempObj.pObject = QPainter_background(pObject)
		return pTempObj

	Func backgroundMode 
		return QPainter_backgroundMode(pObject)

	Func begin P1
		return QPainter_begin(pObject,GetObjectPointerFromRingObject(P1))

	Func beginNativePainting 
		return QPainter_beginNativePainting(pObject)

	Func boundingRect P1,P2,P3,P4,P5,P6
		pTempObj = new QRect
		pTempObj.pObject = QPainter_boundingRect(pObject,P1,P2,P3,P4,P5,P6)
		return pTempObj

	Func brush 
		pTempObj = new QBrush
		pTempObj.pObject = QPainter_brush(pObject)
		return pTempObj

	Func brushOrigin 
		pTempObj = new QPoint
		pTempObj.pObject = QPainter_brushOrigin(pObject)
		return pTempObj

	Func clipBoundingRect 
		return QPainter_clipBoundingRect(pObject)

	Func clipPath 
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainter_clipPath(pObject)
		return pTempObj

	Func clipRegion 
		pTempObj = new QRegion
		pTempObj.pObject = QPainter_clipRegion(pObject)
		return pTempObj

	Func combinedTransform 
		return QPainter_combinedTransform(pObject)

	Func compositionMode 
		return QPainter_compositionMode(pObject)

	Func device 
		pTempObj = new QPaintDevice
		pTempObj.pObject = QPainter_device(pObject)
		return pTempObj

	Func deviceTransform 
		return QPainter_deviceTransform(pObject)

	Func drawArc P1,P2,P3,P4,P5,P6
		return QPainter_drawArc(pObject,P1,P2,P3,P4,P5,P6)

	Func drawChord P1,P2,P3,P4,P5,P6
		return QPainter_drawChord(pObject,P1,P2,P3,P4,P5,P6)

	Func drawConvexPolygon P1,P2
		return QPainter_drawConvexPolygon(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawEllipse P1,P2,P3,P4
		return QPainter_drawEllipse(pObject,P1,P2,P3,P4)

	Func drawGlyphRun P1,P2
		return QPainter_drawGlyphRun(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func drawImage P1,P2,P3
		return QPainter_drawImage(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func drawLine P1,P2,P3,P4
		return QPainter_drawLine(pObject,P1,P2,P3,P4)

	Func drawLines P1,P2
		return QPainter_drawLines(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawPath P1
		return QPainter_drawPath(pObject,GetObjectPointerFromRingObject(P1))

	Func drawPicture P1,P2,P3
		return QPainter_drawPicture(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func drawPie P1,P2,P3,P4,P5,P6
		return QPainter_drawPie(pObject,P1,P2,P3,P4,P5,P6)

	Func drawPixmap P1,P2,P3
		return QPainter_drawPixmap(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func drawPoint P1,P2
		return QPainter_drawPoint(pObject,P1,P2)

	Func drawPoints P1,P2
		return QPainter_drawPoints(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawPolyline P1,P2
		return QPainter_drawPolyline(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawRect P1,P2,P3,P4
		return QPainter_drawRect(pObject,P1,P2,P3,P4)

	Func drawRects P1,P2
		return QPainter_drawRects(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawRoundedRect P1,P2,P3,P4,P5,P6,P7
		return QPainter_drawRoundedRect(pObject,P1,P2,P3,P4,P5,P6,P7)

	Func drawStaticText P1,P2,P3
		return QPainter_drawStaticText(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func drawText P1,P2,P3
		return QPainter_drawText(pObject,P1,P2,P3)

	Func drawTiledPixmap P1,P2,P3,P4,P5,P6,P7
		return QPainter_drawTiledPixmap(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5),P6,P7)

	Func endpaint 
		return QPainter_end(pObject)

	Func endNativePainting 
		return QPainter_endNativePainting(pObject)

	Func eraseRect P1,P2,P3,P4
		return QPainter_eraseRect(pObject,P1,P2,P3,P4)

	Func fillPath P1,P2
		return QPainter_fillPath(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func fillRect P1,P2,P3,P4,P5
		return QPainter_fillRect(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5))

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QPainter_font(pObject)
		return pTempObj

	Func fontInfo 
		return QPainter_fontInfo(pObject)

	Func hasClipping 
		return QPainter_hasClipping(pObject)

	Func initFrom P1
		return QPainter_initFrom(pObject,GetObjectPointerFromRingObject(P1))

	Func isActive 
		return QPainter_isActive(pObject)

	Func layoutDirection 
		return QPainter_layoutDirection(pObject)

	Func opacity 
		return QPainter_opacity(pObject)

	Func paintEngine 
		return QPainter_paintEngine(pObject)

	Func pen 
		pTempObj = new QPen
		pTempObj.pObject = QPainter_pen(pObject)
		return pTempObj

	Func renderHints 
		return QPainter_renderHints(pObject)

	Func resetTransform 
		return QPainter_resetTransform(pObject)

	Func restore 
		return QPainter_restore(pObject)

	Func rotate P1
		return QPainter_rotate(pObject,P1)

	Func save 
		return QPainter_save(pObject)

	Func scale P1,P2
		return QPainter_scale(pObject,P1,P2)

	Func setBackground P1
		return QPainter_setBackground(pObject,GetObjectPointerFromRingObject(P1))

	Func setBackgroundMode P1
		return QPainter_setBackgroundMode(pObject,P1)

	Func setBrush P1
		return QPainter_setBrush(pObject,GetObjectPointerFromRingObject(P1))

	Func setBrushOrigin P1,P2
		return QPainter_setBrushOrigin(pObject,P1,P2)

	Func setClipPath P1,P2
		return QPainter_setClipPath(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setClipRect P1,P2,P3,P4,P5
		return QPainter_setClipRect(pObject,P1,P2,P3,P4,P5)

	Func setClipRegion P1,P2
		return QPainter_setClipRegion(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setClipping P1
		return QPainter_setClipping(pObject,P1)

	Func setCompositionMode P1
		return QPainter_setCompositionMode(pObject,P1)

	Func setFont P1
		return QPainter_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setLayoutDirection P1
		return QPainter_setLayoutDirection(pObject,P1)

	Func setOpacity P1
		return QPainter_setOpacity(pObject,P1)

	Func setPen P1
		return QPainter_setPen(pObject,GetObjectPointerFromRingObject(P1))

	Func setRenderHint P1,P2
		return QPainter_setRenderHint(pObject,P1,P2)

	Func setTransform P1,P2
		return QPainter_setTransform(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setViewTransformEnabled P1
		return QPainter_setViewTransformEnabled(pObject,P1)

	Func setViewport P1,P2,P3,P4
		return QPainter_setViewport(pObject,P1,P2,P3,P4)

	Func setWindow P1,P2,P3,P4
		return QPainter_setWindow(pObject,P1,P2,P3,P4)

	Func setWorldMatrixEnabled P1
		return QPainter_setWorldMatrixEnabled(pObject,P1)

	Func setWorldTransform P1,P2
		return QPainter_setWorldTransform(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func shear P1,P2
		return QPainter_shear(pObject,P1,P2)

	Func strokePath P1,P2
		return QPainter_strokePath(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func testRenderHint P1
		return QPainter_testRenderHint(pObject,P1)

	Func transform 
		return QPainter_transform(pObject)

	Func translate P1,P2
		return QPainter_translate(pObject,P1,P2)

	Func viewTransformEnabled 
		return QPainter_viewTransformEnabled(pObject)

	Func viewport 
		pTempObj = new QRect
		pTempObj.pObject = QPainter_viewport(pObject)
		return pTempObj

	Func window 
		pTempObj = new QRect
		pTempObj.pObject = QPainter_window(pObject)
		return pTempObj

	Func worldMatrixEnabled 
		return QPainter_worldMatrixEnabled(pObject)

	Func worldTransform 
		return QPainter_worldTransform(pObject)

	Func drawPolygon P1,P2
		return QPainter_drawPolygon(pObject,GetObjectPointerFromRingObject(P1),P2)

Class QPicture

	pObject

	Func init 
		pObject = QPicture_new()
		return self

	Func delete
		pObject = QPicture_delete(pObject)

	Func ObjectPointer
		return pObject

	Func boundingRect 
		pTempObj = new QRect
		pTempObj.pObject = QPicture_boundingRect(pObject)
		return pTempObj

	Func data 
		return QPicture_data(pObject)

	Func isNull 
		return QPicture_isNull(pObject)

	Func loadfile P1,P2
		return QPicture_load(pObject,P1,P2)

	Func play P1
		return QPicture_play(pObject,GetObjectPointerFromRingObject(P1))

	Func save P1,P2
		return QPicture_save(pObject,P1,P2)

	Func setBoundingRect P1
		return QPicture_setBoundingRect(pObject,GetObjectPointerFromRingObject(P1))

	Func size 
		return QPicture_size(pObject)

	Func swap P1
		return QPicture_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QPen

	pObject

	Func init 
		pObject = QPen_new()
		return self

	Func delete
		pObject = QPen_delete(pObject)

	Func ObjectPointer
		return pObject

	Func brush 
		pTempObj = new QBrush
		pTempObj.pObject = QPen_brush(pObject)
		return pTempObj

	Func capStyle 
		return QPen_capStyle(pObject)

	Func color 
		pTempObj = new QColor
		pTempObj.pObject = QPen_color(pObject)
		return pTempObj

	Func dashOffset 
		return QPen_dashOffset(pObject)

	Func isCosmetic 
		return QPen_isCosmetic(pObject)

	Func isSolid 
		return QPen_isSolid(pObject)

	Func joinStyle 
		return QPen_joinStyle(pObject)

	Func miterLimit 
		return QPen_miterLimit(pObject)

	Func setBrush P1
		return QPen_setBrush(pObject,GetObjectPointerFromRingObject(P1))

	Func setCapStyle P1
		return QPen_setCapStyle(pObject,P1)

	Func setColor P1
		return QPen_setColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setCosmetic P1
		return QPen_setCosmetic(pObject,P1)

	Func setDashOffset P1
		return QPen_setDashOffset(pObject,P1)

	Func setJoinStyle P1
		return QPen_setJoinStyle(pObject,P1)

	Func setMiterLimit P1
		return QPen_setMiterLimit(pObject,P1)

	Func setStyle P1
		return QPen_setStyle(pObject,P1)

	Func setWidth P1
		return QPen_setWidth(pObject,P1)

	Func setWidthF P1
		return QPen_setWidthF(pObject,P1)

	Func style 
		return QPen_style(pObject)

	Func swap P1
		return QPen_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func width 
		return QPen_width(pObject)

	Func widthF 
		return QPen_widthF(pObject)

Class QColor

	pObject

	Func init 
		pObject = QColor_new()
		return self

	Func delete
		pObject = QColor_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alpha 
		return QColor_alpha(pObject)

	Func alphaF 
		return QColor_alphaF(pObject)

	Func black 
		return QColor_black(pObject)

	Func blackF 
		return QColor_blackF(pObject)

	Func blue 
		return QColor_blue(pObject)

	Func blueF 
		return QColor_blueF(pObject)

	Func convertTo P1
		pTempObj = new QColor
		pTempObj.pObject = QColor_convertTo(pObject,P1)
		return pTempObj

	Func cyan 
		return QColor_cyan(pObject)

	Func cyanF 
		return QColor_cyanF(pObject)

	Func darker P1
		pTempObj = new QColor
		pTempObj.pObject = QColor_darker(pObject,P1)
		return pTempObj

	Func getCmyk P1,P2,P3,P4,P5
		return QColor_getCmyk(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func getCmykF P1,P2,P3,P4,P5
		return QColor_getCmykF(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func getHsl P1,P2,P3,P4
		return QColor_getHsl(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getHslF P1,P2,P3,P4
		return QColor_getHslF(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getHsv P1,P2,P3,P4
		return QColor_getHsv(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getHsvF P1,P2,P3,P4
		return QColor_getHsvF(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getRgb P1,P2,P3,P4
		return QColor_getRgb(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getRgbF P1,P2,P3,P4
		return QColor_getRgbF(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func green 
		return QColor_green(pObject)

	Func greenF 
		return QColor_greenF(pObject)

	Func hslHue 
		return QColor_hslHue(pObject)

	Func hslHueF 
		return QColor_hslHueF(pObject)

	Func hslSaturation 
		return QColor_hslSaturation(pObject)

	Func hslSaturationF 
		return QColor_hslSaturationF(pObject)

	Func hsvHue 
		return QColor_hsvHue(pObject)

	Func hsvHueF 
		return QColor_hsvHueF(pObject)

	Func hsvSaturation 
		return QColor_hsvSaturation(pObject)

	Func hsvSaturationF 
		return QColor_hsvSaturationF(pObject)

	Func hue 
		return QColor_hue(pObject)

	Func hueF 
		return QColor_hueF(pObject)

	Func isValid 
		return QColor_isValid(pObject)

	Func lighter P1
		pTempObj = new QColor
		pTempObj.pObject = QColor_lighter(pObject,P1)
		return pTempObj

	Func lightness 
		return QColor_lightness(pObject)

	Func lightnessF 
		return QColor_lightnessF(pObject)

	Func magenta 
		return QColor_magenta(pObject)

	Func magentaF 
		return QColor_magentaF(pObject)

	Func name 
		return QColor_name(pObject)

	Func red 
		return QColor_red(pObject)

	Func redF 
		return QColor_redF(pObject)

	Func rgb 
		return QColor_rgb(pObject)

	Func rgba 
		return QColor_rgba(pObject)

	Func saturation 
		return QColor_saturation(pObject)

	Func saturationF 
		return QColor_saturationF(pObject)

	Func setAlpha P1
		return QColor_setAlpha(pObject,P1)

	Func setAlphaF P1
		return QColor_setAlphaF(pObject,P1)

	Func setBlue P1
		return QColor_setBlue(pObject,P1)

	Func setBlueF P1
		return QColor_setBlueF(pObject,P1)

	Func setCmyk P1,P2,P3,P4,P5
		return QColor_setCmyk(pObject,P1,P2,P3,P4,P5)

	Func setCmykF P1,P2,P3,P4,P5
		return QColor_setCmykF(pObject,P1,P2,P3,P4,P5)

	Func setGreen P1
		return QColor_setGreen(pObject,P1)

	Func setGreenF P1
		return QColor_setGreenF(pObject,P1)

	Func setHsl P1,P2,P3,P4
		return QColor_setHsl(pObject,P1,P2,P3,P4)

	Func setHslF P1,P2,P3,P4
		return QColor_setHslF(pObject,P1,P2,P3,P4)

	Func setHsv P1,P2,P3,P4
		return QColor_setHsv(pObject,P1,P2,P3,P4)

	Func setHsvF P1,P2,P3,P4
		return QColor_setHsvF(pObject,P1,P2,P3,P4)

	Func setNamedColor P1
		return QColor_setNamedColor(pObject,P1)

	Func setRed P1
		return QColor_setRed(pObject,P1)

	Func setRedF P1
		return QColor_setRedF(pObject,P1)

	Func setRgb P1,P2,P3,P4
		return QColor_setRgb(pObject,P1,P2,P3,P4)

	Func setRgbF P1,P2,P3,P4
		return QColor_setRgbF(pObject,P1,P2,P3,P4)

	Func setRgba P1
		return QColor_setRgba(pObject,GetObjectPointerFromRingObject(P1))

	Func spec 
		return QColor_spec(pObject)

	Func toCmyk 
		pTempObj = new QColor
		pTempObj.pObject = QColor_toCmyk(pObject)
		return pTempObj

	Func toHsl 
		pTempObj = new QColor
		pTempObj.pObject = QColor_toHsl(pObject)
		return pTempObj

	Func toHsv 
		pTempObj = new QColor
		pTempObj.pObject = QColor_toHsv(pObject)
		return pTempObj

	Func toRgb 
		pTempObj = new QColor
		pTempObj.pObject = QColor_toRgb(pObject)
		return pTempObj

	Func value 
		return QColor_value(pObject)

	Func valueF 
		return QColor_valueF(pObject)

	Func yellow 
		return QColor_yellow(pObject)

	Func yellowF 
		return QColor_yellowF(pObject)

	Func colorNames 
		pTempObj = new QStringList
		pTempObj.pObject = QColor_colorNames(pObject)
		return pTempObj

	Func fromCmyk P1,P2,P3,P4,P5
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromCmyk(pObject,P1,P2,P3,P4,P5)
		return pTempObj

	Func fromCmykF P1,P2,P3,P4,P5
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromCmykF(pObject,P1,P2,P3,P4,P5)
		return pTempObj

	Func fromHsl P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromHsl(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromHslF P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromHslF(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromHsv P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromHsv(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromHsvF P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromHsvF(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromRgb P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromRgb(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromRgbF P1,P2,P3,P4
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromRgbF(pObject,P1,P2,P3,P4)
		return pTempObj

	Func fromRgba P1
		pTempObj = new QColor
		pTempObj.pObject = QColor_fromRgba(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func isValidColor P1
		return QColor_isValidColor(pObject,P1)

Class QPrinter

	pObject

	Func init P1
		pObject = QPrinter_new(P1)
		return self

	Func delete
		pObject = QPrinter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func abort 
		return QPrinter_abort(pObject)

	Func collateCopies 
		return QPrinter_collateCopies(pObject)

	Func colorMode 
		return QPrinter_colorMode(pObject)

	Func copyCount 
		return QPrinter_copyCount(pObject)

	Func creator 
		return QPrinter_creator(pObject)

	Func docName 
		return QPrinter_docName(pObject)

	Func duplex 
		return QPrinter_duplex(pObject)

	Func fontEmbeddingEnabled 
		return QPrinter_fontEmbeddingEnabled(pObject)

	Func fromPage 
		return QPrinter_fromPage(pObject)

	Func fullPage 
		return QPrinter_fullPage(pObject)

	Func isValid 
		return QPrinter_isValid(pObject)

	Func outputFileName 
		return QPrinter_outputFileName(pObject)

	Func outputFormat 
		return QPrinter_outputFormat(pObject)

	Func pageOrder 
		return QPrinter_pageOrder(pObject)

	Func pageRect P1
		return QPrinter_pageRect(pObject,P1)

	Func paperRect P1
		return QPrinter_paperRect(pObject,P1)

	Func paperSource 
		return QPrinter_paperSource(pObject)

	Func printEngine 
		return QPrinter_printEngine(pObject)

	Func printProgram 
		return QPrinter_printProgram(pObject)

	Func printRange 
		return QPrinter_printRange(pObject)

	Func printerName 
		return QPrinter_printerName(pObject)

	Func printerSelectionOption 
		return QPrinter_printerSelectionOption(pObject)

	Func printerState 
		return QPrinter_printerState(pObject)

	Func resolution 
		return QPrinter_resolution(pObject)

	Func setCollateCopies P1
		return QPrinter_setCollateCopies(pObject,P1)

	Func setColorMode P1
		return QPrinter_setColorMode(pObject,P1)

	Func setCopyCount P1
		return QPrinter_setCopyCount(pObject,P1)

	Func setCreator P1
		return QPrinter_setCreator(pObject,P1)

	Func setDocName P1
		return QPrinter_setDocName(pObject,P1)

	Func setDuplex P1
		return QPrinter_setDuplex(pObject,P1)

	Func setFontEmbeddingEnabled P1
		return QPrinter_setFontEmbeddingEnabled(pObject,P1)

	Func setFromTo P1,P2
		return QPrinter_setFromTo(pObject,P1,P2)

	Func setFullPage P1
		return QPrinter_setFullPage(pObject,P1)

	Func setOutputFileName P1
		return QPrinter_setOutputFileName(pObject,P1)

	Func setOutputFormat P1
		return QPrinter_setOutputFormat(pObject,P1)

	Func setPageOrder P1
		return QPrinter_setPageOrder(pObject,P1)

	Func setPaperSource P1
		return QPrinter_setPaperSource(pObject,P1)

	Func setPrintProgram P1
		return QPrinter_setPrintProgram(pObject,P1)

	Func setPrintRange P1
		return QPrinter_setPrintRange(pObject,P1)

	Func setPrinterName P1
		return QPrinter_setPrinterName(pObject,P1)

	Func setPrinterSelectionOption P1
		return QPrinter_setPrinterSelectionOption(pObject,P1)

	Func setResolution P1
		return QPrinter_setResolution(pObject,P1)

	Func supportsMultipleCopies 
		return QPrinter_supportsMultipleCopies(pObject)

	Func toPage 
		return QPrinter_toPage(pObject)

	Func newPage 
		return QPrinter_newPage(pObject)

	Func paintEngine 
		return QPrinter_paintEngine(pObject)

	Func setPageSizeMM P1
		return QPrinter_setPageSizeMM(pObject,GetObjectPointerFromRingObject(P1))

Class QFont

	pObject

	Func init P1,P2,P3,P4
		pObject = QFont_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QFont_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bold 
		return QFont_bold(pObject)

	Func capitalization 
		return QFont_capitalization(pObject)

	Func defaultFamily 
		return QFont_defaultFamily(pObject)

	Func exactMatch 
		return QFont_exactMatch(pObject)

	Func family 
		return QFont_family(pObject)

	Func fixedPitch 
		return QFont_fixedPitch(pObject)

	Func fromString P1
		return QFont_fromString(pObject,P1)

	Func hintingPreference 
		return QFont_hintingPreference(pObject)

	Func isCopyOf P1
		return QFont_isCopyOf(pObject,GetObjectPointerFromRingObject(P1))

	Func italic 
		return QFont_italic(pObject)

	Func kerning 
		return QFont_kerning(pObject)

	Func key 
		return QFont_key(pObject)

	Func lastResortFamily 
		return QFont_lastResortFamily(pObject)

	Func lastResortFont 
		return QFont_lastResortFont(pObject)

	Func letterSpacing 
		return QFont_letterSpacing(pObject)

	Func letterSpacingType 
		return QFont_letterSpacingType(pObject)

	Func overline 
		return QFont_overline(pObject)

	Func pixelSize 
		return QFont_pixelSize(pObject)

	Func pointSize 
		return QFont_pointSize(pObject)

	Func pointSizeF 
		return QFont_pointSizeF(pObject)

	Func rawMode 
		return QFont_rawMode(pObject)

	Func rawName 
		return QFont_rawName(pObject)

	Func resolve P1
		pTempObj = new QFont
		pTempObj.pObject = QFont_resolve(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setBold P1
		return QFont_setBold(pObject,P1)

	Func setCapitalization P1
		return QFont_setCapitalization(pObject,P1)

	Func setFamily P1
		return QFont_setFamily(pObject,P1)

	Func setFixedPitch P1
		return QFont_setFixedPitch(pObject,P1)

	Func setHintingPreference P1
		return QFont_setHintingPreference(pObject,P1)

	Func setItalic P1
		return QFont_setItalic(pObject,P1)

	Func setKerning P1
		return QFont_setKerning(pObject,P1)

	Func setLetterSpacing P1,P2
		return QFont_setLetterSpacing(pObject,P1,P2)

	Func setOverline P1
		return QFont_setOverline(pObject,P1)

	Func setPixelSize P1
		return QFont_setPixelSize(pObject,P1)

	Func setPointSize P1
		return QFont_setPointSize(pObject,P1)

	Func setPointSizeF P1
		return QFont_setPointSizeF(pObject,P1)

	Func setRawMode P1
		return QFont_setRawMode(pObject,P1)

	Func setRawName P1
		return QFont_setRawName(pObject,P1)

	Func setStretch P1
		return QFont_setStretch(pObject,P1)

	Func setStrikeOut P1
		return QFont_setStrikeOut(pObject,P1)

	Func setStyle P1
		return QFont_setStyle(pObject,P1)

	Func setStyleHint P1,P2
		return QFont_setStyleHint(pObject,P1,P2)

	Func setStyleName P1
		return QFont_setStyleName(pObject,P1)

	Func setStyleStrategy P1
		return QFont_setStyleStrategy(pObject,P1)

	Func setUnderline P1
		return QFont_setUnderline(pObject,P1)

	Func setWeight P1
		return QFont_setWeight(pObject,P1)

	Func setWordSpacing P1
		return QFont_setWordSpacing(pObject,P1)

	Func stretch 
		return QFont_stretch(pObject)

	Func strikeOut 
		return QFont_strikeOut(pObject)

	Func style 
		return QFont_style(pObject)

	Func styleHint 
		return QFont_styleHint(pObject)

	Func styleName 
		return QFont_styleName(pObject)

	Func styleStrategy 
		return QFont_styleStrategy(pObject)

	Func toString 
		return QFont_toString(pObject)

	Func underline 
		return QFont_underline(pObject)

	Func weight 
		return QFont_weight(pObject)

	Func wordSpacing 
		return QFont_wordSpacing(pObject)

	Func insertSubstitution P1,P2
		return QFont_insertSubstitution(pObject,P1,P2)

	Func insertSubstitutions P1,P2
		return QFont_insertSubstitutions(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func substitute P1
		return QFont_substitute(pObject,P1)

	Func substitutes P1
		pTempObj = new QStringList
		pTempObj.pObject = QFont_substitutes(pObject,P1)
		return pTempObj

	Func substitutions 
		pTempObj = new QStringList
		pTempObj.pObject = QFont_substitutions(pObject)
		return pTempObj

Class QBrush

	pObject

	Func init 
		pObject = QBrush_new()
		return self

	Func delete
		pObject = QBrush_delete(pObject)

	Func ObjectPointer
		return pObject

	Func color 
		pTempObj = new QColor
		pTempObj.pObject = QBrush_color(pObject)
		return pTempObj

	Func gradient 
		pTempObj = new QGradient
		pTempObj.pObject = QBrush_gradient(pObject)
		return pTempObj

	Func isOpaque 
		return QBrush_isOpaque(pObject)

	Func matrix 
		return QBrush_matrix(pObject)

	Func setColor P1
		return QBrush_setColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setMatrix P1
		return QBrush_setMatrix(pObject,GetObjectPointerFromRingObject(P1))

	Func setStyle P1
		return QBrush_setStyle(pObject,P1)

	Func setTexture P1
		return QBrush_setTexture(pObject,GetObjectPointerFromRingObject(P1))

	Func setTextureImage P1
		return QBrush_setTextureImage(pObject,GetObjectPointerFromRingObject(P1))

	Func setTransform P1
		return QBrush_setTransform(pObject,GetObjectPointerFromRingObject(P1))

	Func style 
		return QBrush_style(pObject)

	Func swap P1
		return QBrush_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func texture 
		pTempObj = new QPixmap
		pTempObj.pObject = QBrush_texture(pObject)
		return pTempObj

	Func textureImage 
		pTempObj = new QImage
		pTempObj.pObject = QBrush_textureImage(pObject)
		return pTempObj

	Func transform 
		return QBrush_transform(pObject)

Class QByteArray

	pObject

	Func init 
		pObject = QByteArray_new()
		return self

	Func delete
		pObject = QByteArray_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_append(pObject,P1)
		return pTempObj

	Func at P1
		return QByteArray_at(pObject,P1)

	Func capacity 
		return QByteArray_capacity(pObject)

	Func chop P1
		return QByteArray_chop(pObject,P1)

	Func clear 
		return QByteArray_clear(pObject)

	Func constData 
		return QByteArray_constData(pObject)

	Func contains P1
		return QByteArray_contains(pObject,P1)

	Func count P1
		return QByteArray_count(pObject,P1)

	Func data 
		return QByteArray_data(pObject)

	Func endsWith P1
		return QByteArray_endsWith(pObject,P1)

	Func fill P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fill(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func indexOf P1,P2
		return QByteArray_indexOf(pObject,P1,P2)

	Func insert P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_insert(pObject,P1,P2,P3)
		return pTempObj

	Func isEmpty 
		return QByteArray_isEmpty(pObject)

	Func isNull 
		return QByteArray_isNull(pObject)

	Func lastIndexOf P1,P2
		return QByteArray_lastIndexOf(pObject,P1,P2)

	Func left P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_left(pObject,P1)
		return pTempObj

	Func leftJustified P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_leftJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func length 
		return QByteArray_length(pObject)

	Func mid P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_mid(pObject,P1,P2)
		return pTempObj

	Func prepend P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_prepend(pObject,P1,P2)
		return pTempObj

	Func push_back P1
		return QByteArray_push_back(pObject,P1)

	Func push_front P1
		return QByteArray_push_front(pObject,P1)

	Func remove P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_remove(pObject,P1,P2)
		return pTempObj

	Func repeated P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_repeated(pObject,P1)
		return pTempObj

	Func replace P1,P2,P3,P4
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace(pObject,P1,P2,P3,P4)
		return pTempObj

	Func reserve P1
		return QByteArray_reserve(pObject,P1)

	Func resize P1
		return QByteArray_resize(pObject,P1)

	Func right P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_right(pObject,P1)
		return pTempObj

	Func rightJustified P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_rightJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func setNum P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setNum(pObject,P1,P2)
		return pTempObj

	Func setRawData P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setRawData(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func simplified 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_simplified(pObject)
		return pTempObj

	Func size 
		return QByteArray_size(pObject)

	Func squeeze 
		return QByteArray_squeeze(pObject)

	Func startsWith P1
		return QByteArray_startsWith(pObject,P1)

	Func swap P1
		return QByteArray_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toBase64 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toBase64(pObject)
		return pTempObj

	Func toDouble P1
		return QByteArray_toDouble(pObject,GetObjectPointerFromRingObject(P1))

	Func toFloat P1
		return QByteArray_toFloat(pObject,GetObjectPointerFromRingObject(P1))

	Func toHex 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toHex(pObject)
		return pTempObj

	Func toInt P1,P2
		return QByteArray_toInt(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLong P1,P2
		return QByteArray_toLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLongLong P1,P2
		return QByteArray_toLongLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toLower 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toLower(pObject)
		return pTempObj

	Func toPercentEncoding P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func toShort P1,P2
		return QByteArray_toShort(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUInt P1,P2
		return QByteArray_toUInt(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toULong P1,P2
		return QByteArray_toULong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toULongLong P1,P2
		return QByteArray_toULongLong(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUShort P1,P2
		return QByteArray_toUShort(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toUpper 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_toUpper(pObject)
		return pTempObj

	Func trimmed 
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_trimmed(pObject)
		return pTempObj

	Func truncate P1
		return QByteArray_truncate(pObject,P1)

	Func fromBase64 P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromBase64(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromHex P1
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromHex(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromPercentEncoding P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func fromRawData P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_fromRawData(pObject,P1,P2)
		return pTempObj

	Func number P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_number(pObject,P1,P2)
		return pTempObj

Class QIODevice from QObject

	pObject

	Func init 
		pObject = QIODevice_new()
		return self

	Func delete
		pObject = QIODevice_delete(pObject)

	Func ObjectPointer
		return pObject

	Func errorString 
		return QIODevice_errorString(pObject)

	Func getChar P1
		return QIODevice_getChar(pObject,P1)

	Func isOpen 
		return QIODevice_isOpen(pObject)

	Func isReadable 
		return QIODevice_isReadable(pObject)

	Func isTextModeEnabled 
		return QIODevice_isTextModeEnabled(pObject)

	Func isWritable 
		return QIODevice_isWritable(pObject)

	Func openMode 
		return QIODevice_openMode(pObject)

	Func peek P1,P2
		return QIODevice_peek(pObject,P1,P2)

	Func putChar P1
		return QIODevice_putChar(pObject,GetObjectPointerFromRingObject(P1))

	Func read P1,P2
		return QIODevice_read(pObject,P1,P2)

	Func readAll 
		pTempObj = new QByteArray
		pTempObj.pObject = QIODevice_readAll(pObject)
		return pTempObj

	Func readLine P1,P2
		return QIODevice_readLine(pObject,P1,P2)

	Func setTextModeEnabled P1
		return QIODevice_setTextModeEnabled(pObject,P1)

	Func ungetChar P1
		return QIODevice_ungetChar(pObject,GetObjectPointerFromRingObject(P1))

	Func write P1,P2
		return QIODevice_write(pObject,P1,P2)

	Func atEnd 
		return QIODevice_atEnd(pObject)

	Func canReadLine 
		return QIODevice_canReadLine(pObject)

	Func close 
		return QIODevice_close(pObject)

	Func open P1
		return QIODevice_open(pObject,P1)

	Func pos 
		return QIODevice_pos(pObject)

	Func seek P1
		return QIODevice_seek(pObject,P1)

	Func size 
		return QIODevice_size(pObject)

	Func setaboutToCloseEvent P1
		return QIODevice_setaboutToCloseEvent(pObject,P1)

	Func setbytesWrittenEvent P1
		return QIODevice_setbytesWrittenEvent(pObject,P1)

	Func setreadChannelFinishedEvent P1
		return QIODevice_setreadChannelFinishedEvent(pObject,P1)

	Func setreadyReadEvent P1
		return QIODevice_setreadyReadEvent(pObject,P1)

	Func getaboutToCloseEvent 
		return QIODevice_getaboutToCloseEvent(pObject)

	Func getbytesWrittenEvent 
		return QIODevice_getbytesWrittenEvent(pObject)

	Func getreadChannelFinishedEvent 
		return QIODevice_getreadChannelFinishedEvent(pObject)

	Func getreadyReadEvent 
		return QIODevice_getreadyReadEvent(pObject)

Class QAbstractSocket from QIODevice

	pObject

	Func init 
		pObject = QAbstractSocket_new()
		return self

	Func delete
		pObject = QAbstractSocket_delete(pObject)

	Func ObjectPointer
		return pObject

	Func abort 
		return QAbstractSocket_abort(pObject)

	Func bind P1,P2,P3
		return QAbstractSocket_bind(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func connectToHost P1,P2,P3,P4
		return QAbstractSocket_connectToHost(pObject,P1,P2,P3,P4)

	Func disconnectFromHost 
		return QAbstractSocket_disconnectFromHost(pObject)

	Func error 
		return QAbstractSocket_error(pObject)

	Func flush 
		return QAbstractSocket_flush(pObject)

	Func isValid 
		return QAbstractSocket_isValid(pObject)

	Func localAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QAbstractSocket_localAddress(pObject)
		return pTempObj

	Func localPort 
		return QAbstractSocket_localPort(pObject)

	Func pauseMode 
		return QAbstractSocket_pauseMode(pObject)

	Func peerAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QAbstractSocket_peerAddress(pObject)
		return pTempObj

	Func peerName 
		return QAbstractSocket_peerName(pObject)

	Func peerPort 
		return QAbstractSocket_peerPort(pObject)

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QAbstractSocket_proxy(pObject)
		return pTempObj

	Func readBufferSize 
		return QAbstractSocket_readBufferSize(pObject)

	Func resume 
		return QAbstractSocket_resume(pObject)

	Func setPauseMode P1
		return QAbstractSocket_setPauseMode(pObject,P1)

	Func setProxy P1
		return QAbstractSocket_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setReadBufferSize P1
		return QAbstractSocket_setReadBufferSize(pObject,P1)

	Func setSocketDescriptor P1,P2,P3
		return QAbstractSocket_setSocketDescriptor(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func setSocketOption P1,P2
		return QAbstractSocket_setSocketOption(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func socketDescriptor 
		return QAbstractSocket_socketDescriptor(pObject)

	Func socketOption P1
		pTempObj = new QVariant
		pTempObj.pObject = QAbstractSocket_socketOption(pObject,P1)
		return pTempObj

	Func socketType 
		return QAbstractSocket_socketType(pObject)

	Func state 
		return QAbstractSocket_state(pObject)

	Func waitForConnected P1
		return QAbstractSocket_waitForConnected(pObject,P1)

	Func waitForDisconnected P1
		return QAbstractSocket_waitForDisconnected(pObject,P1)

	Func atEnd 
		return QAbstractSocket_atEnd(pObject)

	Func bytesAvailable 
		return QAbstractSocket_bytesAvailable(pObject)

	Func bytesToWrite 
		return QAbstractSocket_bytesToWrite(pObject)

	Func canReadLine 
		return QAbstractSocket_canReadLine(pObject)

	Func close 
		return QAbstractSocket_close(pObject)

	Func isSequential 
		return QAbstractSocket_isSequential(pObject)

	Func waitForBytesWritten P1
		return QAbstractSocket_waitForBytesWritten(pObject,P1)

	Func waitForReadyRead P1
		return QAbstractSocket_waitForReadyRead(pObject,P1)

	Func setconnectedEvent P1
		return QAbstractSocket_setconnectedEvent(pObject,P1)

	Func setdisconnectedEvent P1
		return QAbstractSocket_setdisconnectedEvent(pObject,P1)

	Func seterrorEvent P1
		return QAbstractSocket_seterrorEvent(pObject,P1)

	Func sethostFoundEvent P1
		return QAbstractSocket_sethostFoundEvent(pObject,P1)

	Func setproxyAuthenticationRequiredEvent P1
		return QAbstractSocket_setproxyAuthenticationRequiredEvent(pObject,P1)

	Func setstateChangedEvent P1
		return QAbstractSocket_setstateChangedEvent(pObject,P1)

	Func getconnectedEvent 
		return QAbstractSocket_getconnectedEvent(pObject)

	Func getdisconnectedEvent 
		return QAbstractSocket_getdisconnectedEvent(pObject)

	Func geterrorEvent 
		return QAbstractSocket_geterrorEvent(pObject)

	Func gethostFoundEvent 
		return QAbstractSocket_gethostFoundEvent(pObject)

	Func getproxyAuthenticationRequiredEvent 
		return QAbstractSocket_getproxyAuthenticationRequiredEvent(pObject)

	Func getstateChangedEvent 
		return QAbstractSocket_getstateChangedEvent(pObject)

Class QNetworkProxy

	pObject

	Func init 
		pObject = QNetworkProxy_new()
		return self

	Func delete
		pObject = QNetworkProxy_delete(pObject)

	Func ObjectPointer
		return pObject

	Func capabilities 
		return QNetworkProxy_capabilities(pObject)

	Func hasRawHeader P1
		return QNetworkProxy_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkProxy_header(pObject,P1)
		return pTempObj

	Func hostName 
		return QNetworkProxy_hostName(pObject)

	Func isCachingProxy 
		return QNetworkProxy_isCachingProxy(pObject)

	Func isTransparentProxy 
		return QNetworkProxy_isTransparentProxy(pObject)

	Func password 
		return QNetworkProxy_password(pObject)

	Func port 
		return QNetworkProxy_port(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkProxy_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setCapabilities P1
		return QNetworkProxy_setCapabilities(pObject,P1)

	Func setHeader P1,P2
		return QNetworkProxy_setHeader(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHostName P1
		return QNetworkProxy_setHostName(pObject,P1)

	Func setPassword P1
		return QNetworkProxy_setPassword(pObject,P1)

	Func setPort P1
		return QNetworkProxy_setPort(pObject,P1)

	Func setRawHeader P1,P2
		return QNetworkProxy_setRawHeader(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setType P1
		return QNetworkProxy_setType(pObject,P1)

	Func setUser P1
		return QNetworkProxy_setUser(pObject,P1)

	Func swap P1
		return QNetworkProxy_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func type 
		return QNetworkProxy_type(pObject)

	Func user 
		return QNetworkProxy_user(pObject)

	Func applicationProxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QNetworkProxy_applicationProxy(pObject)
		return pTempObj

	Func setApplicationProxy P1
		return QNetworkProxy_setApplicationProxy(pObject,GetObjectPointerFromRingObject(P1))

Class QTcpSocket from QAbstractSocket

	pObject

	Func init P1
		pObject = QTcpSocket_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTcpSocket_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setconnectedEvent P1
		return QTcpSocket_setconnectedEvent(pObject,P1)

	Func setdisconnectedEvent P1
		return QTcpSocket_setdisconnectedEvent(pObject,P1)

	Func seterrorEvent P1
		return QTcpSocket_seterrorEvent(pObject,P1)

	Func sethostFoundEvent P1
		return QTcpSocket_sethostFoundEvent(pObject,P1)

	Func setproxyAuthenticationRequiredEvent P1
		return QTcpSocket_setproxyAuthenticationRequiredEvent(pObject,P1)

	Func setstateChangedEvent P1
		return QTcpSocket_setstateChangedEvent(pObject,P1)

	Func setaboutToCloseEvent P1
		return QTcpSocket_setaboutToCloseEvent(pObject,P1)

	Func setbytesWrittenEvent P1
		return QTcpSocket_setbytesWrittenEvent(pObject,P1)

	Func setreadChannelFinishedEvent P1
		return QTcpSocket_setreadChannelFinishedEvent(pObject,P1)

	Func setreadyReadEvent P1
		return QTcpSocket_setreadyReadEvent(pObject,P1)

	Func getconnectedEvent 
		return QTcpSocket_getconnectedEvent(pObject)

	Func getdisconnectedEvent 
		return QTcpSocket_getdisconnectedEvent(pObject)

	Func geterrorEvent 
		return QTcpSocket_geterrorEvent(pObject)

	Func gethostFoundEvent 
		return QTcpSocket_gethostFoundEvent(pObject)

	Func getproxyAuthenticationRequiredEvent 
		return QTcpSocket_getproxyAuthenticationRequiredEvent(pObject)

	Func getstateChangedEvent 
		return QTcpSocket_getstateChangedEvent(pObject)

	Func getaboutToCloseEvent 
		return QTcpSocket_getaboutToCloseEvent(pObject)

	Func getbytesWrittenEvent 
		return QTcpSocket_getbytesWrittenEvent(pObject)

	Func getreadChannelFinishedEvent 
		return QTcpSocket_getreadChannelFinishedEvent(pObject)

	Func getreadyReadEvent 
		return QTcpSocket_getreadyReadEvent(pObject)

Class QTcpServer

	pObject

	Func init P1
		pObject = QTcpServer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTcpServer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func close 
		return QTcpServer_close(pObject)

	Func errorString 
		return QTcpServer_errorString(pObject)

	Func hasPendingConnections 
		return QTcpServer_hasPendingConnections(pObject)

	Func isListening 
		return QTcpServer_isListening(pObject)

	Func listen P1,P2
		return QTcpServer_listen(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func maxPendingConnections 
		return QTcpServer_maxPendingConnections(pObject)

	Func nextPendingConnection 
		pTempObj = new QTcpSocket
		pTempObj.pObject = QTcpServer_nextPendingConnection(pObject)
		return pTempObj

	Func pauseAccepting 
		return QTcpServer_pauseAccepting(pObject)

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QTcpServer_proxy(pObject)
		return pTempObj

	Func resumeAccepting 
		return QTcpServer_resumeAccepting(pObject)

	Func serverAddress 
		pTempObj = new QHostAddress
		pTempObj.pObject = QTcpServer_serverAddress(pObject)
		return pTempObj

	Func serverError 
		return QTcpServer_serverError(pObject)

	Func serverPort 
		return QTcpServer_serverPort(pObject)

	Func setMaxPendingConnections P1
		return QTcpServer_setMaxPendingConnections(pObject,P1)

	Func setProxy P1
		return QTcpServer_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setSocketDescriptor P1
		return QTcpServer_setSocketDescriptor(pObject,GetObjectPointerFromRingObject(P1))

	Func socketDescriptor 
		return QTcpServer_socketDescriptor(pObject)

	Func waitForNewConnection P1,P2
		return QTcpServer_waitForNewConnection(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setacceptErrorEvent P1
		return QTcpServer_setacceptErrorEvent(pObject,P1)

	Func setnewConnectionEvent P1
		return QTcpServer_setnewConnectionEvent(pObject,P1)

	Func getacceptErrorEvent 
		return QTcpServer_getacceptErrorEvent(pObject)

	Func getnewConnectionEvent 
		return QTcpServer_getnewConnectionEvent(pObject)

Class QHostAddress

	pObject

	Func init 
		pObject = QHostAddress_new()
		return self

	Func delete
		pObject = QHostAddress_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QHostAddress_clear(pObject)

	Func isInSubnet P1,P2
		return QHostAddress_isInSubnet(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func isNull 
		return QHostAddress_isNull(pObject)

	Func protocol 
		return QHostAddress_protocol(pObject)

	Func scopeId 
		return QHostAddress_scopeId(pObject)

	Func setAddress P1
		return QHostAddress_setAddress(pObject,P1)

	Func toIPv4Address 
		return QHostAddress_toIPv4Address(pObject)

	Func toIPv6Address 
		return QHostAddress_toIPv6Address(pObject)

	Func toString 
		return QHostAddress_toString(pObject)

Class QHostInfo

	pObject

	Func init 
		pObject = QHostInfo_new()
		return self

	Func delete
		pObject = QHostInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func error 
		return QHostInfo_error(pObject)

	Func errorString 
		return QHostInfo_errorString(pObject)

	Func hostName 
		return QHostInfo_hostName(pObject)

	Func lookupId 
		return QHostInfo_lookupId(pObject)

	Func setError P1
		return QHostInfo_setError(pObject,P1)

	Func setErrorString P1
		return QHostInfo_setErrorString(pObject,P1)

	Func setHostName P1
		return QHostInfo_setHostName(pObject,P1)

	Func setLookupId P1
		return QHostInfo_setLookupId(pObject,P1)

	Func abortHostLookup P1
		return QHostInfo_abortHostLookup(pObject,P1)

	Func fromName P1
		pTempObj = new QHostInfo
		pTempObj.pObject = QHostInfo_fromName(pObject,P1)
		return pTempObj

	Func localDomainName 
		return QHostInfo_localDomainName(pObject)

	Func localHostName 
		return QHostInfo_localHostName(pObject)

Class QFileInfo

	pObject

	Func init 
		pObject = QFileInfo_new()
		return self

	Func delete
		pObject = QFileInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func absoluteDir 
		pTempObj = new QDir
		pTempObj.pObject = QFileInfo_absoluteDir(pObject)
		return pTempObj

	Func absoluteFilePath 
		return QFileInfo_absoluteFilePath(pObject)

	Func absolutePath 
		return QFileInfo_absolutePath(pObject)

	Func baseName 
		return QFileInfo_baseName(pObject)

	Func bundleName 
		return QFileInfo_bundleName(pObject)

	Func caching 
		return QFileInfo_caching(pObject)

	Func canonicalFilePath 
		return QFileInfo_canonicalFilePath(pObject)

	Func canonicalPath 
		return QFileInfo_canonicalPath(pObject)

	Func completeBaseName 
		return QFileInfo_completeBaseName(pObject)

	Func completeSuffix 
		return QFileInfo_completeSuffix(pObject)

	Func created 
		pTempObj = new QDateTime
		pTempObj.pObject = QFileInfo_created(pObject)
		return pTempObj

	Func dir 
		pTempObj = new QDir
		pTempObj.pObject = QFileInfo_dir(pObject)
		return pTempObj

	Func exists 
		return QFileInfo_exists(pObject)

	Func fileName 
		return QFileInfo_fileName(pObject)

	Func filePath 
		return QFileInfo_filePath(pObject)

	Func group 
		return QFileInfo_group(pObject)

	Func groupId 
		return QFileInfo_groupId(pObject)

	Func isAbsolute 
		return QFileInfo_isAbsolute(pObject)

	Func isBundle 
		return QFileInfo_isBundle(pObject)

	Func isDir 
		return QFileInfo_isDir(pObject)

	Func isExecutable 
		return QFileInfo_isExecutable(pObject)

	Func isFile 
		return QFileInfo_isFile(pObject)

	Func isHidden 
		return QFileInfo_isHidden(pObject)

	Func isNativePath 
		return QFileInfo_isNativePath(pObject)

	Func isReadable 
		return QFileInfo_isReadable(pObject)

	Func isRelative 
		return QFileInfo_isRelative(pObject)

	Func isRoot 
		return QFileInfo_isRoot(pObject)

	Func isSymLink 
		return QFileInfo_isSymLink(pObject)

	Func isWritable 
		return QFileInfo_isWritable(pObject)

	Func lastModified 
		pTempObj = new QDateTime
		pTempObj.pObject = QFileInfo_lastModified(pObject)
		return pTempObj

	Func lastRead 
		pTempObj = new QDateTime
		pTempObj.pObject = QFileInfo_lastRead(pObject)
		return pTempObj

	Func makeAbsolute 
		return QFileInfo_makeAbsolute(pObject)

	Func owner 
		return QFileInfo_owner(pObject)

	Func ownerId 
		return QFileInfo_ownerId(pObject)

	Func path 
		return QFileInfo_path(pObject)

	Func permission P1
		return QFileInfo_permission(pObject,P1)

	Func permissions 
		return QFileInfo_permissions(pObject)

	Func refresh 
		return QFileInfo_refresh(pObject)

	Func setCaching P1
		return QFileInfo_setCaching(pObject,P1)

	Func setFile P1
		return QFileInfo_setFile(pObject,P1)

	Func size 
		return QFileInfo_size(pObject)

	Func suffix 
		return QFileInfo_suffix(pObject)

	Func swap P1
		return QFileInfo_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func symLinkTarget 
		return QFileInfo_symLinkTarget(pObject)

Class QDirModel

	pObject

	Func init 
		pObject = QDirModel_new()
		return self

	Func delete
		pObject = QDirModel_delete(pObject)

	Func ObjectPointer
		return pObject

	Func fileIcon P1
		pTempObj = new QIcon
		pTempObj.pObject = QDirModel_fileIcon(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fileInfo P1
		pTempObj = new QFileInfo
		pTempObj.pObject = QDirModel_fileInfo(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fileName P1
		return QDirModel_fileName(pObject,GetObjectPointerFromRingObject(P1))

	Func filePath P1
		return QDirModel_filePath(pObject,GetObjectPointerFromRingObject(P1))

	Func filter 
		return QDirModel_filter(pObject)

	Func iconProvider 
		return QDirModel_iconProvider(pObject)

	Func index P1,P2
		return QDirModel_index(pObject,P1,P2)

	Func isDir P1
		return QDirModel_isDir(pObject,GetObjectPointerFromRingObject(P1))

	Func isReadOnly 
		return QDirModel_isReadOnly(pObject)

	Func lazyChildCount 
		return QDirModel_lazyChildCount(pObject)

	Func mkdir P1,P2
		return QDirModel_mkdir(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func nameFilters 
		pTempObj = new QStringList
		pTempObj.pObject = QDirModel_nameFilters(pObject)
		return pTempObj

	Func remove P1
		return QDirModel_remove(pObject,GetObjectPointerFromRingObject(P1))

	Func resolveSymlinks 
		return QDirModel_resolveSymlinks(pObject)

	Func rmdir P1
		return QDirModel_rmdir(pObject,GetObjectPointerFromRingObject(P1))

	Func setFilter P1
		return QDirModel_setFilter(pObject,P1)

	Func setIconProvider P1
		return QDirModel_setIconProvider(pObject,GetObjectPointerFromRingObject(P1))

	Func setLazyChildCount P1
		return QDirModel_setLazyChildCount(pObject,P1)

	Func setNameFilters P1
		return QDirModel_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

	Func setReadOnly P1
		return QDirModel_setReadOnly(pObject,P1)

	Func setResolveSymlinks P1
		return QDirModel_setResolveSymlinks(pObject,P1)

	Func setSorting P1
		return QDirModel_setSorting(pObject,P1)

	Func sorting 
		return QDirModel_sorting(pObject)

	Func refresh P1
		return QDirModel_refresh(pObject,GetObjectPointerFromRingObject(P1))

Class QFontDialog from QDialog

	pObject

	Func init 
		pObject = QFontDialog_new()
		return self

	Func delete
		pObject = QFontDialog_delete(pObject)

	Func ObjectPointer
		return pObject

	Func currentFont 
		pTempObj = new QFont
		pTempObj.pObject = QFontDialog_currentFont(pObject)
		return pTempObj

	Func open P1,P2
		return QFontDialog_open(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func options 
		return QFontDialog_options(pObject)

	Func selectedFont 
		pTempObj = new QFont
		pTempObj.pObject = QFontDialog_selectedFont(pObject)
		return pTempObj

	Func setCurrentFont P1
		return QFontDialog_setCurrentFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setOption P1,P2
		return QFontDialog_setOption(pObject,P1,P2)

	Func setOptions P1
		return QFontDialog_setOptions(pObject,P1)

	Func testOption P1
		return QFontDialog_testOption(pObject,P1)

	Func getfont 
		return QFontDialog_getfont(pObject)

Class QDialog from QWidget

	pObject

	Func init P1
		pObject = QDialog_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDialog_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isSizeGripEnabled 
		return QDialog_isSizeGripEnabled(pObject)

	Func result 
		return QDialog_result(pObject)

	Func setModal P1
		return QDialog_setModal(pObject,P1)

	Func setResult P1
		return QDialog_setResult(pObject,P1)

	Func setSizeGripEnabled P1
		return QDialog_setSizeGripEnabled(pObject,P1)

	Func accept 
		return QDialog_accept(pObject)

	Func donedialog P1
		return QDialog_done(pObject,P1)

	Func exec 
		return QDialog_exec(pObject)

	Func open 
		return QDialog_open(pObject)

	Func reject 
		return QDialog_reject(pObject)

Class QTextCursor

	pObject

	Func init 
		pObject = QTextCursor_new()
		return self

	Func delete
		pObject = QTextCursor_delete(pObject)

	Func ObjectPointer
		return pObject

	Func anchor 
		return QTextCursor_anchor(pObject)

	Func atBlockEnd 
		return QTextCursor_atBlockEnd(pObject)

	Func atBlockStart 
		return QTextCursor_atBlockStart(pObject)

	Func atEnd 
		return QTextCursor_atEnd(pObject)

	Func atStart 
		return QTextCursor_atStart(pObject)

	Func beginEditBlock 
		return QTextCursor_beginEditBlock(pObject)

	Func block 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextCursor_block(pObject)
		return pTempObj

	Func blockCharFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QTextCursor_blockCharFormat(pObject)
		return pTempObj

	Func blockFormat 
		return QTextCursor_blockFormat(pObject)

	Func blockNumber 
		return QTextCursor_blockNumber(pObject)

	Func charFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QTextCursor_charFormat(pObject)
		return pTempObj

	Func clearSelection 
		return QTextCursor_clearSelection(pObject)

	Func columnNumber 
		return QTextCursor_columnNumber(pObject)

	Func createList P1
		return QTextCursor_createList(pObject,GetObjectPointerFromRingObject(P1))

	Func currentFrame 
		return QTextCursor_currentFrame(pObject)

	Func currentList 
		return QTextCursor_currentList(pObject)

	Func currentTable 
		return QTextCursor_currentTable(pObject)

	Func deleteChar 
		return QTextCursor_deleteChar(pObject)

	Func deletePreviousChar 
		return QTextCursor_deletePreviousChar(pObject)

	Func document 
		pTempObj = new QTextDocument
		pTempObj.pObject = QTextCursor_document(pObject)
		return pTempObj

	Func endEditBlock 
		return QTextCursor_endEditBlock(pObject)

	Func hasComplexSelection 
		return QTextCursor_hasComplexSelection(pObject)

	Func hasSelection 
		return QTextCursor_hasSelection(pObject)

	Func insertBlock 
		return QTextCursor_insertBlock(pObject)

	Func insertFragment P1
		return QTextCursor_insertFragment(pObject,GetObjectPointerFromRingObject(P1))

	Func insertFrame P1
		return QTextCursor_insertFrame(pObject,GetObjectPointerFromRingObject(P1))

	Func insertHtml P1
		return QTextCursor_insertHtml(pObject,P1)

	Func insertImage P1
		return QTextCursor_insertImage(pObject,GetObjectPointerFromRingObject(P1))

	Func insertList P1
		return QTextCursor_insertList(pObject,GetObjectPointerFromRingObject(P1))

	Func insertTable P1,P2,P3
		return QTextCursor_insertTable(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func insertText P1
		return QTextCursor_insertText(pObject,P1)

	Func insertText_2 P1,P2
		return QTextCursor_insertText_2(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isCopyOf P1
		return QTextCursor_isCopyOf(pObject,GetObjectPointerFromRingObject(P1))

	Func isNull 
		return QTextCursor_isNull(pObject)

	Func joinPreviousEditBlock 
		return QTextCursor_joinPreviousEditBlock(pObject)

	Func keepPositionOnInsert 
		return QTextCursor_keepPositionOnInsert(pObject)

	Func mergeBlockCharFormat P1
		return QTextCursor_mergeBlockCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func mergeBlockFormat P1
		return QTextCursor_mergeBlockFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func mergeCharFormat P1
		return QTextCursor_mergeCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func movePosition P1,P2,P3
		return QTextCursor_movePosition(pObject,P1,P2,P3)

	Func position 
		return QTextCursor_position(pObject)

	Func positionInBlock 
		return QTextCursor_positionInBlock(pObject)

	Func removeSelectedText 
		return QTextCursor_removeSelectedText(pObject)

	Func select P1
		return QTextCursor_select(pObject,P1)

	Func selectedTableCells P1,P2,P3,P4
		return QTextCursor_selectedTableCells(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func selectedText 
		return QTextCursor_selectedText(pObject)

	Func selection 
		return QTextCursor_selection(pObject)

	Func selectionEnd 
		return QTextCursor_selectionEnd(pObject)

	Func selectionStart 
		return QTextCursor_selectionStart(pObject)

	Func setBlockCharFormat P1
		return QTextCursor_setBlockCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setBlockFormat P1
		return QTextCursor_setBlockFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setCharFormat P1
		return QTextCursor_setCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setKeepPositionOnInsert P1
		return QTextCursor_setKeepPositionOnInsert(pObject,P1)

	Func setPosition P1,P2
		return QTextCursor_setPosition(pObject,P1,P2)

	Func setVerticalMovementX P1
		return QTextCursor_setVerticalMovementX(pObject,P1)

	Func setVisualNavigation P1
		return QTextCursor_setVisualNavigation(pObject,P1)

	Func verticalMovementX 
		return QTextCursor_verticalMovementX(pObject)

	Func visualNavigation 
		return QTextCursor_visualNavigation(pObject)

Class QColorDialog from QDialog

	pObject

	Func init 
		pObject = QColorDialog_new()
		return self

	Func delete
		pObject = QColorDialog_delete(pObject)

	Func ObjectPointer
		return pObject

	Func currentColor 
		pTempObj = new QColor
		pTempObj.pObject = QColorDialog_currentColor(pObject)
		return pTempObj

	Func open 
		return QColorDialog_open(pObject)

	Func options 
		return QColorDialog_options(pObject)

	Func selectedColor 
		pTempObj = new QColor
		pTempObj.pObject = QColorDialog_selectedColor(pObject)
		return pTempObj

	Func setCurrentColor P1
		return QColorDialog_setCurrentColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setOption P1,P2
		return QColorDialog_setOption(pObject,P1,P2)

	Func setOptions P1
		return QColorDialog_setOptions(pObject,P1)

	Func testOption P1
		return QColorDialog_testOption(pObject,P1)

	Func customColor P1
		pTempObj = new QColor
		pTempObj.pObject = QColorDialog_customColor(pObject,P1)
		return pTempObj

	Func customCount 
		return QColorDialog_customCount(pObject)

	Func setCustomColor P1,P2
		return QColorDialog_setCustomColor(pObject,P1,P2)

	Func setStandardColor P1,P2
		return QColorDialog_setStandardColor(pObject,P1,P2)

	Func getcolor 
		return QColorDialog_getcolor(pObject)

Class QStringList

	pObject

	Func init 
		pObject = QStringList_new()
		return self

	Func delete
		pObject = QStringList_delete(pObject)

	Func ObjectPointer
		return pObject

	Func join P1
		return QStringList_join(pObject,P1)

	Func sort 
		return QStringList_sort(pObject)

	Func removeDuplicates 
		return QStringList_removeDuplicates(pObject)

	Func filter P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QStringList_filter(pObject,P1,P2)
		return pTempObj

	Func replaceInStrings P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QStringList_replaceInStrings(pObject,P1,P2,P3)
		return pTempObj

	Func append P1
		return QStringList_append(pObject,P1)

	Func at P1
		return QStringList_at(pObject,P1)

	Func back 
		return QStringList_back(pObject)

	Func clear 
		return QStringList_clear(pObject)

	Func contains P1
		return QStringList_contains(pObject,P1)

	Func count 
		return QStringList_count(pObject)

	Func empty 
		return QStringList_empty(pObject)

	Func endsWith P1
		return QStringList_endsWith(pObject,P1)

	Func first 
		return QStringList_first(pObject)

	Func front 
		return QStringList_front(pObject)

	Func indexOf P1,P2
		return QStringList_indexOf(pObject,P1,P2)

	Func insert P1,P2
		return QStringList_insert(pObject,P1,P2)

	Func isEmpty 
		return QStringList_isEmpty(pObject)

	Func last 
		return QStringList_last(pObject)

	Func lastIndexOf P1,P2
		return QStringList_lastIndexOf(pObject,P1,P2)

	Func length 
		return QStringList_length(pObject)

	Func move P1,P2
		return QStringList_move(pObject,P1,P2)

	Func pop_back 
		return QStringList_pop_back(pObject)

	Func pop_front 
		return QStringList_pop_front(pObject)

	Func prepend P1
		return QStringList_prepend(pObject,P1)

	Func push_back P1
		return QStringList_push_back(pObject,P1)

	Func push_front P1
		return QStringList_push_front(pObject,P1)

	Func removeAll P1
		return QStringList_removeAll(pObject,P1)

	Func removeAt P1
		return QStringList_removeAt(pObject,P1)

	Func removeFirst 
		return QStringList_removeFirst(pObject)

	Func removeLast 
		return QStringList_removeLast(pObject)

	Func removeOne P1
		return QStringList_removeOne(pObject,P1)

	Func replace P1,P2
		return QStringList_replace(pObject,P1,P2)

	Func reserve P1
		return QStringList_reserve(pObject,P1)

	Func size 
		return QStringList_size(pObject)

	Func startsWith P1
		return QStringList_startsWith(pObject,P1)

	Func swap P1,P2
		return QStringList_swap(pObject,P1,P2)

	Func takeAt P1
		return QStringList_takeAt(pObject,P1)

	Func takeFirst 
		return QStringList_takeFirst(pObject)

	Func takeLast 
		return QStringList_takeLast(pObject)

	Func value P1
		return QStringList_value(pObject,P1)

Class QLCDNumber from QFrame

	pObject

	Func init P1
		pObject = QLCDNumber_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QLCDNumber_delete(pObject)

	Func ObjectPointer
		return pObject

	Func checkOverflow P1
		return QLCDNumber_checkOverflow(pObject,P1)

	Func digitCount 
		return QLCDNumber_digitCount(pObject)

	Func intValue 
		return QLCDNumber_intValue(pObject)

	Func mode 
		return QLCDNumber_mode(pObject)

	Func segmentStyle 
		return QLCDNumber_segmentStyle(pObject)

	Func setDigitCount P1
		return QLCDNumber_setDigitCount(pObject,P1)

	Func setMode P1
		return QLCDNumber_setMode(pObject,P1)

	Func setSegmentStyle P1
		return QLCDNumber_setSegmentStyle(pObject,P1)

	Func smallDecimalPoint 
		return QLCDNumber_smallDecimalPoint(pObject)

	Func value 
		return QLCDNumber_value(pObject)

	Func display P1
		return QLCDNumber_display(pObject,P1)

	Func setBinMode 
		return QLCDNumber_setBinMode(pObject)

	Func setDecMode 
		return QLCDNumber_setDecMode(pObject)

	Func setHexMode 
		return QLCDNumber_setHexMode(pObject)

	Func setOctMode 
		return QLCDNumber_setOctMode(pObject)

	Func setSmallDecimalPoint P1
		return QLCDNumber_setSmallDecimalPoint(pObject,P1)

Class QInputDialog from QDialog

	pObject

	Func init P1
		pObject = QInputDialog_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QInputDialog_delete(pObject)

	Func ObjectPointer
		return pObject

	Func cancelButtonText 
		return QInputDialog_cancelButtonText(pObject)

	Func comboBoxItems 
		pTempObj = new QStringList
		pTempObj.pObject = QInputDialog_comboBoxItems(pObject)
		return pTempObj

	Func doubleDecimals 
		return QInputDialog_doubleDecimals(pObject)

	Func doubleMaximum 
		return QInputDialog_doubleMaximum(pObject)

	Func doubleMinimum 
		return QInputDialog_doubleMinimum(pObject)

	Func doubleValue 
		return QInputDialog_doubleValue(pObject)

	Func inputMode 
		return QInputDialog_inputMode(pObject)

	Func intMaximum 
		return QInputDialog_intMaximum(pObject)

	Func intMinimum 
		return QInputDialog_intMinimum(pObject)

	Func intStep 
		return QInputDialog_intStep(pObject)

	Func intValue 
		return QInputDialog_intValue(pObject)

	Func isComboBoxEditable 
		return QInputDialog_isComboBoxEditable(pObject)

	Func labelText 
		return QInputDialog_labelText(pObject)

	Func okButtonText 
		return QInputDialog_okButtonText(pObject)

	Func open P1,P2
		return QInputDialog_open(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func options 
		return QInputDialog_options(pObject)

	Func setCancelButtonText P1
		return QInputDialog_setCancelButtonText(pObject,P1)

	Func setComboBoxEditable P1
		return QInputDialog_setComboBoxEditable(pObject,P1)

	Func setComboBoxItems P1
		return QInputDialog_setComboBoxItems(pObject,GetObjectPointerFromRingObject(P1))

	Func setDoubleDecimals P1
		return QInputDialog_setDoubleDecimals(pObject,P1)

	Func setDoubleMaximum P1
		return QInputDialog_setDoubleMaximum(pObject,P1)

	Func setDoubleMinimum P1
		return QInputDialog_setDoubleMinimum(pObject,P1)

	Func setDoubleRange P1,P2
		return QInputDialog_setDoubleRange(pObject,P1,P2)

	Func setDoubleValue P1
		return QInputDialog_setDoubleValue(pObject,P1)

	Func setInputMode P1
		return QInputDialog_setInputMode(pObject,P1)

	Func setIntMaximum P1
		return QInputDialog_setIntMaximum(pObject,P1)

	Func setIntMinimum P1
		return QInputDialog_setIntMinimum(pObject,P1)

	Func setIntRange P1,P2
		return QInputDialog_setIntRange(pObject,P1,P2)

	Func setIntStep P1
		return QInputDialog_setIntStep(pObject,P1)

	Func setIntValue P1
		return QInputDialog_setIntValue(pObject,P1)

	Func setLabelText P1
		return QInputDialog_setLabelText(pObject,P1)

	Func setOkButtonText P1
		return QInputDialog_setOkButtonText(pObject,P1)

	Func setOption P1,P2
		return QInputDialog_setOption(pObject,P1,P2)

	Func setOptions P1
		return QInputDialog_setOptions(pObject,P1)

	Func setTextEchoMode P1
		return QInputDialog_setTextEchoMode(pObject,P1)

	Func setTextValue P1
		return QInputDialog_setTextValue(pObject,P1)

	Func testOption P1
		return QInputDialog_testOption(pObject,P1)

	Func textEchoMode 
		return QInputDialog_textEchoMode(pObject)

	Func textValue 
		return QInputDialog_textValue(pObject)

	Func getDouble P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QInputDialog_getDouble(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8),P9)

	Func getInt P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QInputDialog_getInt(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8),P9)

Class QAllEvents from QWidget

	pObject

	Func init P1
		pObject = QAllEvents_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAllEvents_delete(pObject)

	Func ObjectPointer
		return pObject

	Func accept 
		return QAllEvents_accept(pObject)

	Func ignore 
		return QAllEvents_ignore(pObject)

	Func getKeyCode 
		return QAllEvents_getKeyCode(pObject)

	Func getKeyText 
		return QAllEvents_getKeyText(pObject)

	Func getModifiers 
		return QAllEvents_getModifiers(pObject)

	Func getx 
		return QAllEvents_getx(pObject)

	Func gety 
		return QAllEvents_gety(pObject)

	Func getglobalx 
		return QAllEvents_getglobalx(pObject)

	Func getglobaly 
		return QAllEvents_getglobaly(pObject)

	Func getbutton 
		return QAllEvents_getbutton(pObject)

	Func getbuttons 
		return QAllEvents_getbuttons(pObject)

	Func setKeyPressEvent P1
		return QAllEvents_setKeyPressEvent(pObject,P1)

	Func setMouseButtonPressEvent P1
		return QAllEvents_setMouseButtonPressEvent(pObject,P1)

	Func setMouseButtonReleaseEvent P1
		return QAllEvents_setMouseButtonReleaseEvent(pObject,P1)

	Func setMouseButtonDblClickEvent P1
		return QAllEvents_setMouseButtonDblClickEvent(pObject,P1)

	Func setMouseMoveEvent P1
		return QAllEvents_setMouseMoveEvent(pObject,P1)

	Func setCloseEvent P1
		return QAllEvents_setCloseEvent(pObject,P1)

	Func setContextMenuEvent P1
		return QAllEvents_setContextMenuEvent(pObject,P1)

	Func setDragEnterEvent P1
		return QAllEvents_setDragEnterEvent(pObject,P1)

	Func setDragLeaveEvent P1
		return QAllEvents_setDragLeaveEvent(pObject,P1)

	Func setDragMoveEvent P1
		return QAllEvents_setDragMoveEvent(pObject,P1)

	Func setDropEvent P1
		return QAllEvents_setDropEvent(pObject,P1)

	Func setEnterEvent P1
		return QAllEvents_setEnterEvent(pObject,P1)

	Func setFocusInEvent P1
		return QAllEvents_setFocusInEvent(pObject,P1)

	Func setFocusOutEvent P1
		return QAllEvents_setFocusOutEvent(pObject,P1)

	Func setKeyReleaseEvent P1
		return QAllEvents_setKeyReleaseEvent(pObject,P1)

	Func setLeaveEvent P1
		return QAllEvents_setLeaveEvent(pObject,P1)

	Func setNonClientAreaMouseButtonDblClickEvent P1
		return QAllEvents_setNonClientAreaMouseButtonDblClickEvent(pObject,P1)

	Func setNonClientAreaMouseButtonPressEvent P1
		return QAllEvents_setNonClientAreaMouseButtonPressEvent(pObject,P1)

	Func setNonClientAreaMouseButtonReleaseEvent P1
		return QAllEvents_setNonClientAreaMouseButtonReleaseEvent(pObject,P1)

	Func setNonClientAreaMouseMoveEvent P1
		return QAllEvents_setNonClientAreaMouseMoveEvent(pObject,P1)

	Func setMoveEvent P1
		return QAllEvents_setMoveEvent(pObject,P1)

	Func setResizeEvent P1
		return QAllEvents_setResizeEvent(pObject,P1)

	Func setWindowActivateEvent P1
		return QAllEvents_setWindowActivateEvent(pObject,P1)

	Func setWindowBlockedEvent P1
		return QAllEvents_setWindowBlockedEvent(pObject,P1)

	Func setWindowDeactivateEvent P1
		return QAllEvents_setWindowDeactivateEvent(pObject,P1)

	Func setWindowStateChangeEvent P1
		return QAllEvents_setWindowStateChangeEvent(pObject,P1)

	Func setWindowUnblockedEvent P1
		return QAllEvents_setWindowUnblockedEvent(pObject,P1)

	Func setPaintEvent P1
		return QAllEvents_setPaintEvent(pObject,P1)

	Func getKeyPressEvent 
		return QAllEvents_getKeyPressEvent(pObject)

	Func getMouseButtonPressEvent 
		return QAllEvents_getMouseButtonPressEvent(pObject)

	Func getMouseButtonReleaseEvent 
		return QAllEvents_getMouseButtonReleaseEvent(pObject)

	Func getMouseButtonDblClickEvent 
		return QAllEvents_getMouseButtonDblClickEvent(pObject)

	Func getMouseMoveEvent 
		return QAllEvents_getMouseMoveEvent(pObject)

	Func getCloseEvent 
		return QAllEvents_getCloseEvent(pObject)

	Func getContextMenuEvent 
		return QAllEvents_getContextMenuEvent(pObject)

	Func getDragEnterEvent 
		return QAllEvents_getDragEnterEvent(pObject)

	Func getDragLeaveEvent 
		return QAllEvents_getDragLeaveEvent(pObject)

	Func getDragMoveEvent 
		return QAllEvents_getDragMoveEvent(pObject)

	Func getDropEvent 
		return QAllEvents_getDropEvent(pObject)

	Func getEnterEvent 
		return QAllEvents_getEnterEvent(pObject)

	Func getFocusInEvent 
		return QAllEvents_getFocusInEvent(pObject)

	Func getFocusOutEvent 
		return QAllEvents_getFocusOutEvent(pObject)

	Func getKeyReleaseEvent 
		return QAllEvents_getKeyReleaseEvent(pObject)

	Func getLeaveEvent 
		return QAllEvents_getLeaveEvent(pObject)

	Func getNonClientAreaMouseButtonDblClickEvent 
		return QAllEvents_getNonClientAreaMouseButtonDblClickEvent(pObject)

	Func getNonClientAreaMouseButtonPressEvent 
		return QAllEvents_getNonClientAreaMouseButtonPressEvent(pObject)

	Func getNonClientAreaMouseButtonReleaseEvent 
		return QAllEvents_getNonClientAreaMouseButtonReleaseEvent(pObject)

	Func getNonClientAreaMouseMoveEvent 
		return QAllEvents_getNonClientAreaMouseMoveEvent(pObject)

	Func getMoveEvent 
		return QAllEvents_getMoveEvent(pObject)

	Func getResizeEvent 
		return QAllEvents_getResizeEvent(pObject)

	Func getWindowActivateEvent 
		return QAllEvents_getWindowActivateEvent(pObject)

	Func getWindowBlockedEvent 
		return QAllEvents_getWindowBlockedEvent(pObject)

	Func getWindowDeactivateEvent 
		return QAllEvents_getWindowDeactivateEvent(pObject)

	Func getWindowStateChangeEvent 
		return QAllEvents_getWindowStateChangeEvent(pObject)

	Func getWindowUnblockedEvent 
		return QAllEvents_getWindowUnblockedEvent(pObject)

	Func getPaintEvent 
		return QAllEvents_getPaintEvent(pObject)

	Func setEventOutput P1
		return QAllEvents_setEventOutput(pObject,P1)

	Func getParentObject 
		pTempObj = new QObject
		pTempObj.pObject = QAllEvents_getParentObject(pObject)
		return pTempObj

	Func getParentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QAllEvents_getParentWidget(pObject)
		return pTempObj

	Func setKeyPressFunc P1
		return QAllEvents_setKeyPressFunc(pObject,P1)

	Func setMouseButtonPressFunc P1
		return QAllEvents_setMouseButtonPressFunc(pObject,P1)

	Func setMouseButtonReleaseFunc P1
		return QAllEvents_setMouseButtonReleaseFunc(pObject,P1)

	Func setMouseButtonDblClickFunc P1
		return QAllEvents_setMouseButtonDblClickFunc(pObject,P1)

	Func setMouseMoveFunc P1
		return QAllEvents_setMouseMoveFunc(pObject,P1)

	Func setCloseFunc P1
		return QAllEvents_setCloseFunc(pObject,P1)

	Func setContextMenuFunc P1
		return QAllEvents_setContextMenuFunc(pObject,P1)

	Func setDragEnterFunc P1
		return QAllEvents_setDragEnterFunc(pObject,P1)

	Func setDragLeaveFunc P1
		return QAllEvents_setDragLeaveFunc(pObject,P1)

	Func setDragMoveFunc P1
		return QAllEvents_setDragMoveFunc(pObject,P1)

	Func setDropFunc P1
		return QAllEvents_setDropFunc(pObject,P1)

	Func setEnterFunc P1
		return QAllEvents_setEnterFunc(pObject,P1)

	Func setFocusInFunc P1
		return QAllEvents_setFocusInFunc(pObject,P1)

	Func setFocusOutFunc P1
		return QAllEvents_setFocusOutFunc(pObject,P1)

	Func setKeyReleaseFunc P1
		return QAllEvents_setKeyReleaseFunc(pObject,P1)

	Func setLeaveFunc P1
		return QAllEvents_setLeaveFunc(pObject,P1)

	Func setNonClientAreaMouseButtonDblClickFunc P1
		return QAllEvents_setNonClientAreaMouseButtonDblClickFunc(pObject,P1)

	Func setNonClientAreaMouseButtonPressFunc P1
		return QAllEvents_setNonClientAreaMouseButtonPressFunc(pObject,P1)

	Func setNonClientAreaMouseButtonReleaseFunc P1
		return QAllEvents_setNonClientAreaMouseButtonReleaseFunc(pObject,P1)

	Func setNonClientAreaMouseMoveFunc P1
		return QAllEvents_setNonClientAreaMouseMoveFunc(pObject,P1)

	Func setMoveFunc P1
		return QAllEvents_setMoveFunc(pObject,P1)

	Func setResizeFunc P1
		return QAllEvents_setResizeFunc(pObject,P1)

	Func setWindowActivateFunc P1
		return QAllEvents_setWindowActivateFunc(pObject,P1)

	Func setWindowBlockedFunc P1
		return QAllEvents_setWindowBlockedFunc(pObject,P1)

	Func setWindowDeactivateFunc P1
		return QAllEvents_setWindowDeactivateFunc(pObject,P1)

	Func setWindowStateChangeFunc P1
		return QAllEvents_setWindowStateChangeFunc(pObject,P1)

	Func setWindowUnblockedFunc P1
		return QAllEvents_setWindowUnblockedFunc(pObject,P1)

	Func setPaintFunc P1
		return QAllEvents_setPaintFunc(pObject,P1)

	Func getKeyPressFunc 
		return QAllEvents_getKeyPressFunc(pObject)

	Func getMouseButtonPressFunc 
		return QAllEvents_getMouseButtonPressFunc(pObject)

	Func getMouseButtonReleaseFunc 
		return QAllEvents_getMouseButtonReleaseFunc(pObject)

	Func getMouseButtonDblClickFunc 
		return QAllEvents_getMouseButtonDblClickFunc(pObject)

	Func getMouseMoveFunc 
		return QAllEvents_getMouseMoveFunc(pObject)

	Func getCloseFunc 
		return QAllEvents_getCloseFunc(pObject)

	Func getContextMenuFunc 
		return QAllEvents_getContextMenuFunc(pObject)

	Func getDragEnterFunc 
		return QAllEvents_getDragEnterFunc(pObject)

	Func getDragLeaveFunc 
		return QAllEvents_getDragLeaveFunc(pObject)

	Func getDragMoveFunc 
		return QAllEvents_getDragMoveFunc(pObject)

	Func getDropFunc 
		return QAllEvents_getDropFunc(pObject)

	Func getEnterFunc 
		return QAllEvents_getEnterFunc(pObject)

	Func getFocusInFunc 
		return QAllEvents_getFocusInFunc(pObject)

	Func getFocusOutFunc 
		return QAllEvents_getFocusOutFunc(pObject)

	Func getKeyReleaseFunc 
		return QAllEvents_getKeyReleaseFunc(pObject)

	Func getLeaveFunc 
		return QAllEvents_getLeaveFunc(pObject)

	Func getNonClientAreaMouseButtonDblClickFunc 
		return QAllEvents_getNonClientAreaMouseButtonDblClickFunc(pObject)

	Func getNonClientAreaMouseButtonPressFunc 
		return QAllEvents_getNonClientAreaMouseButtonPressFunc(pObject)

	Func getNonClientAreaMouseButtonReleaseFunc 
		return QAllEvents_getNonClientAreaMouseButtonReleaseFunc(pObject)

	Func getNonClientAreaMouseMoveFunc 
		return QAllEvents_getNonClientAreaMouseMoveFunc(pObject)

	Func getMoveFunc 
		return QAllEvents_getMoveFunc(pObject)

	Func getResizeFunc 
		return QAllEvents_getResizeFunc(pObject)

	Func getWindowActivateFunc 
		return QAllEvents_getWindowActivateFunc(pObject)

	Func getWindowBlockedFunc 
		return QAllEvents_getWindowBlockedFunc(pObject)

	Func getWindowDeactivateFunc 
		return QAllEvents_getWindowDeactivateFunc(pObject)

	Func getWindowStateChangeFunc 
		return QAllEvents_getWindowStateChangeFunc(pObject)

	Func getWindowUnblockedFunc 
		return QAllEvents_getWindowUnblockedFunc(pObject)

	Func getPaintFunc 
		return QAllEvents_getPaintFunc(pObject)

Class QDesktopWidget from QWidget

	pObject

	Func init 
		pObject = QDesktopWidget_new()
		return self

	Func delete
		pObject = QDesktopWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func availableGeometry P1
		pTempObj = new QRect
		pTempObj.pObject = QDesktopWidget_availableGeometry(pObject,P1)
		return pTempObj

	Func isVirtualDesktop 
		return QDesktopWidget_isVirtualDesktop(pObject)

	Func primaryScreen 
		return QDesktopWidget_primaryScreen(pObject)

	Func screen P1
		pTempObj = new QWidget
		pTempObj.pObject = QDesktopWidget_screen(pObject,P1)
		return pTempObj

	Func screenCount 
		return QDesktopWidget_screenCount(pObject)

	Func screenGeometry P1
		pTempObj = new QRect
		pTempObj.pObject = QDesktopWidget_screenGeometry(pObject,P1)
		return pTempObj

	Func screenNumber P1
		return QDesktopWidget_screenNumber(pObject,GetObjectPointerFromRingObject(P1))

Class QRect

	pObject

	Func init 
		pObject = QRect_new()
		return self

	Func delete
		pObject = QRect_delete(pObject)

	Func ObjectPointer
		return pObject

	Func adjust P1,P2,P3,P4
		return QRect_adjust(pObject,P1,P2,P3,P4)

	Func adjusted P1,P2,P3,P4
		pTempObj = new QRect
		pTempObj.pObject = QRect_adjusted(pObject,P1,P2,P3,P4)
		return pTempObj

	Func bottom 
		return QRect_bottom(pObject)

	Func bottomLeft 
		pTempObj = new QPoint
		pTempObj.pObject = QRect_bottomLeft(pObject)
		return pTempObj

	Func bottomRight 
		pTempObj = new QPoint
		pTempObj.pObject = QRect_bottomRight(pObject)
		return pTempObj

	Func center 
		pTempObj = new QPoint
		pTempObj.pObject = QRect_center(pObject)
		return pTempObj

	Func contains P1,P2,P3
		return QRect_contains(pObject,P1,P2,P3)

	Func getCoords P1,P2,P3,P4
		return QRect_getCoords(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getRect P1,P2,P3,P4
		return QRect_getRect(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func height 
		return QRect_height(pObject)

	Func intersected P1
		pTempObj = new QRect
		pTempObj.pObject = QRect_intersected(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func intersects P1
		return QRect_intersects(pObject,GetObjectPointerFromRingObject(P1))

	Func isEmpty 
		return QRect_isEmpty(pObject)

	Func isNull 
		return QRect_isNull(pObject)

	Func isValid 
		return QRect_isValid(pObject)

	Func left 
		return QRect_left(pObject)

	Func moveBottom P1
		return QRect_moveBottom(pObject,P1)

	Func moveBottomLeft P1
		return QRect_moveBottomLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func moveBottomRight P1
		return QRect_moveBottomRight(pObject,GetObjectPointerFromRingObject(P1))

	Func moveCenter P1
		return QRect_moveCenter(pObject,GetObjectPointerFromRingObject(P1))

	Func moveLeft P1
		return QRect_moveLeft(pObject,P1)

	Func moveRight P1
		return QRect_moveRight(pObject,P1)

	Func moveTo P1,P2
		return QRect_moveTo(pObject,P1,P2)

	Func moveTop P1
		return QRect_moveTop(pObject,P1)

	Func moveTopLeft P1
		return QRect_moveTopLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func moveTopRight P1
		return QRect_moveTopRight(pObject,GetObjectPointerFromRingObject(P1))

	Func normalized 
		pTempObj = new QRect
		pTempObj.pObject = QRect_normalized(pObject)
		return pTempObj

	Func right 
		return QRect_right(pObject)

	Func setBottom P1
		return QRect_setBottom(pObject,P1)

	Func setBottomLeft P1
		return QRect_setBottomLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func setBottomRight P1
		return QRect_setBottomRight(pObject,GetObjectPointerFromRingObject(P1))

	Func setCoords P1,P2,P3,P4
		return QRect_setCoords(pObject,P1,P2,P3,P4)

	Func setHeight P1
		return QRect_setHeight(pObject,P1)

	Func setLeft P1
		return QRect_setLeft(pObject,P1)

	Func setRect P1,P2,P3,P4
		return QRect_setRect(pObject,P1,P2,P3,P4)

	Func setRight P1
		return QRect_setRight(pObject,P1)

	Func setSize P1
		return QRect_setSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setTop P1
		return QRect_setTop(pObject,P1)

	Func setTopLeft P1
		return QRect_setTopLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func setTopRight P1
		return QRect_setTopRight(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidth P1
		return QRect_setWidth(pObject,P1)

	Func setX P1
		return QRect_setX(pObject,P1)

	Func setY P1
		return QRect_setY(pObject,P1)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QRect_size(pObject)
		return pTempObj

	Func top 
		return QRect_top(pObject)

	Func topLeft 
		pTempObj = new QPoint
		pTempObj.pObject = QRect_topLeft(pObject)
		return pTempObj

	Func topRight 
		pTempObj = new QPoint
		pTempObj.pObject = QRect_topRight(pObject)
		return pTempObj

	Func translate P1,P2
		return QRect_translate(pObject,P1,P2)

	Func translated P1,P2
		pTempObj = new QRect
		pTempObj.pObject = QRect_translated(pObject,P1,P2)
		return pTempObj

	Func united P1
		pTempObj = new QRect
		pTempObj.pObject = QRect_united(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func width 
		return QRect_width(pObject)

	Func x 
		return QRect_x(pObject)

	Func y 
		return QRect_y(pObject)

Class QTextDocument from QObject

	pObject

	Func init 
		pObject = QTextDocument_new()
		return self

	Func delete
		pObject = QTextDocument_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addResource P1,P2,P3
		return QTextDocument_addResource(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func adjustSize 
		return QTextDocument_adjustSize(pObject)

	Func allFormats 
		return QTextDocument_allFormats(pObject)

	Func availableRedoSteps 
		return QTextDocument_availableRedoSteps(pObject)

	Func availableUndoSteps 
		return QTextDocument_availableUndoSteps(pObject)

	Func begin 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_begin(pObject)
		return pTempObj

	Func blockCount 
		return QTextDocument_blockCount(pObject)

	Func characterAt P1
		return QTextDocument_characterAt(pObject,P1)

	Func characterCount 
		return QTextDocument_characterCount(pObject)

	Func clearUndoRedoStacks P1
		return QTextDocument_clearUndoRedoStacks(pObject,P1)

	Func clone P1
		pTempObj = new QTextDocument
		pTempObj.pObject = QTextDocument_clone(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func defaultCursorMoveStyle 
		return QTextDocument_defaultCursorMoveStyle(pObject)

	Func defaultFont 
		pTempObj = new QFont
		pTempObj.pObject = QTextDocument_defaultFont(pObject)
		return pTempObj

	Func defaultStyleSheet 
		return QTextDocument_defaultStyleSheet(pObject)

	Func defaultTextOption 
		return QTextDocument_defaultTextOption(pObject)

	Func documentLayout 
		return QTextDocument_documentLayout(pObject)

	Func documentMargin 
		return QTextDocument_documentMargin(pObject)

	Func drawContents P1,P2
		return QTextDocument_drawContents(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func enddoc 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_end(pObject)
		return pTempObj

	Func find P1,P2,P3
		pTempObj = new QTextCursor
		pTempObj.pObject = QTextDocument_find(pObject,P1,GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func findBlock P1
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_findBlock(pObject,P1)
		return pTempObj

	Func findBlockByLineNumber P1
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_findBlockByLineNumber(pObject,P1)
		return pTempObj

	Func findBlockByNumber P1
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_findBlockByNumber(pObject,P1)
		return pTempObj

	Func firstBlock 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_firstBlock(pObject)
		return pTempObj

	Func idealWidth 
		return QTextDocument_idealWidth(pObject)

	Func indentWidth 
		return QTextDocument_indentWidth(pObject)

	Func isEmpty 
		return QTextDocument_isEmpty(pObject)

	Func isModified 
		return QTextDocument_isModified(pObject)

	Func isRedoAvailable 
		return QTextDocument_isRedoAvailable(pObject)

	Func isUndoAvailable 
		return QTextDocument_isUndoAvailable(pObject)

	Func isUndoRedoEnabled 
		return QTextDocument_isUndoRedoEnabled(pObject)

	Func lastBlock 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextDocument_lastBlock(pObject)
		return pTempObj

	Func lineCount 
		return QTextDocument_lineCount(pObject)

	Func markContentsDirty P1,P2
		return QTextDocument_markContentsDirty(pObject,P1,P2)

	Func maximumBlockCount 
		return QTextDocument_maximumBlockCount(pObject)

	Func metaInformation P1
		return QTextDocument_metaInformation(pObject,P1)

	Func object P1
		return QTextDocument_object(pObject,P1)

	Func objectForFormat P1
		return QTextDocument_objectForFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func pageCount 
		return QTextDocument_pageCount(pObject)

	Func pageSize 
		return QTextDocument_pageSize(pObject)

	Func print P1
		return QTextDocument_print(pObject,GetObjectPointerFromRingObject(P1))

	Func redo P1
		return QTextDocument_redo(pObject,GetObjectPointerFromRingObject(P1))

	Func resource P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QTextDocument_resource(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func revision 
		return QTextDocument_revision(pObject)

	Func rootFrame 
		return QTextDocument_rootFrame(pObject)

	Func setDefaultCursorMoveStyle P1
		return QTextDocument_setDefaultCursorMoveStyle(pObject,P1)

	Func setDefaultFont P1
		return QTextDocument_setDefaultFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setDefaultStyleSheet P1
		return QTextDocument_setDefaultStyleSheet(pObject,P1)

	Func setDefaultTextOption P1
		return QTextDocument_setDefaultTextOption(pObject,GetObjectPointerFromRingObject(P1))

	Func setDocumentLayout P1
		return QTextDocument_setDocumentLayout(pObject,GetObjectPointerFromRingObject(P1))

	Func setDocumentMargin P1
		return QTextDocument_setDocumentMargin(pObject,P1)

	Func setHtml P1
		return QTextDocument_setHtml(pObject,P1)

	Func setIndentWidth P1
		return QTextDocument_setIndentWidth(pObject,P1)

	Func setMaximumBlockCount P1
		return QTextDocument_setMaximumBlockCount(pObject,P1)

	Func setMetaInformation P1,P2
		return QTextDocument_setMetaInformation(pObject,P1,P2)

	Func setPageSize P1
		return QTextDocument_setPageSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setPlainText P1
		return QTextDocument_setPlainText(pObject,P1)

	Func setTextWidth P1
		return QTextDocument_setTextWidth(pObject,P1)

	Func setUndoRedoEnabled P1
		return QTextDocument_setUndoRedoEnabled(pObject,P1)

	Func setUseDesignMetrics P1
		return QTextDocument_setUseDesignMetrics(pObject,P1)

	Func size 
		return QTextDocument_size(pObject)

	Func textWidth 
		return QTextDocument_textWidth(pObject)

	Func toHtml P1
		return QTextDocument_toHtml(pObject,GetObjectPointerFromRingObject(P1))

	Func toPlainText 
		return QTextDocument_toPlainText(pObject)

	Func undo P1
		return QTextDocument_undo(pObject,GetObjectPointerFromRingObject(P1))

	Func useDesignMetrics 
		return QTextDocument_useDesignMetrics(pObject)

	Func setModified P1
		return QTextDocument_setModified(pObject,P1)

Class QTextBlock

	pObject

	Func init 
		pObject = QTextBlock_new()
		return self

	Func delete
		pObject = QTextBlock_delete(pObject)

	Func ObjectPointer
		return pObject

	Func blockFormat 
		return QTextBlock_blockFormat(pObject)

	Func blockFormatIndex 
		return QTextBlock_blockFormatIndex(pObject)

	Func blockNumber 
		return QTextBlock_blockNumber(pObject)

	Func charFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QTextBlock_charFormat(pObject)
		return pTempObj

	Func charFormatIndex 
		return QTextBlock_charFormatIndex(pObject)

	Func clearLayout 
		return QTextBlock_clearLayout(pObject)

	Func contains P1
		return QTextBlock_contains(pObject,P1)

	Func document 
		pTempObj = new QTextDocument
		pTempObj.pObject = QTextBlock_document(pObject)
		return pTempObj

	Func firstLineNumber 
		return QTextBlock_firstLineNumber(pObject)

	Func isValid 
		return QTextBlock_isValid(pObject)

	Func isVisible 
		return QTextBlock_isVisible(pObject)

	Func layout 
		return QTextBlock_layout(pObject)

	Func length 
		return QTextBlock_length(pObject)

	Func lineCount 
		return QTextBlock_lineCount(pObject)

	Func nextblock 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextBlock_next(pObject)
		return pTempObj

	Func position 
		return QTextBlock_position(pObject)

	Func previous 
		pTempObj = new QTextBlock
		pTempObj.pObject = QTextBlock_previous(pObject)
		return pTempObj

	Func revision 
		return QTextBlock_revision(pObject)

	Func setLineCount P1
		return QTextBlock_setLineCount(pObject,P1)

	Func setRevision P1
		return QTextBlock_setRevision(pObject,P1)

	Func setUserData P1
		return QTextBlock_setUserData(pObject,GetObjectPointerFromRingObject(P1))

	Func setUserState P1
		return QTextBlock_setUserState(pObject,P1)

	Func setVisible P1
		return QTextBlock_setVisible(pObject,P1)

	Func text 
		return QTextBlock_text(pObject)

	Func textDirection 
		return QTextBlock_textDirection(pObject)

	Func textList 
		return QTextBlock_textList(pObject)

	Func userData 
		return QTextBlock_userData(pObject)

	Func userState 
		return QTextBlock_userState(pObject)

Class QTime

	pObject

	Func init 
		pObject = QTime_new()
		return self

	Func delete
		pObject = QTime_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addMSecs P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_addMSecs(pObject,P1)
		return pTempObj

	Func addSecs P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_addSecs(pObject,P1)
		return pTempObj

	Func elapsed 
		return QTime_elapsed(pObject)

	Func hour 
		return QTime_hour(pObject)

	Func isNull 
		return QTime_isNull(pObject)

	Func isValid 
		return QTime_isValid(pObject)

	Func minute 
		return QTime_minute(pObject)

	Func msec 
		return QTime_msec(pObject)

	Func msecsSinceStartOfDay 
		return QTime_msecsSinceStartOfDay(pObject)

	Func msecsTo P1
		return QTime_msecsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func restart 
		return QTime_restart(pObject)

	Func second 
		return QTime_second(pObject)

	Func secsTo P1
		return QTime_secsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func setHMS P1,P2,P3,P4
		return QTime_setHMS(pObject,P1,P2,P3,P4)

	Func start 
		return QTime_start(pObject)

	Func toString P1
		return QTime_toString(pObject,P1)

	Func currentTime 
		pTempObj = new QTime
		pTempObj.pObject = QTime_currentTime(pObject)
		return pTempObj

	Func fromMSecsSinceStartOfDay P1
		pTempObj = new QTime
		pTempObj.pObject = QTime_fromMSecsSinceStartOfDay(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QTime_fromString(pObject,P1,P2)
		return pTempObj

Class QListWidgetItem

	pObject

	Func init 
		pObject = QListWidgetItem_new()
		return self

	Func delete
		pObject = QListWidgetItem_delete(pObject)

	Func ObjectPointer
		return pObject

	Func background 
		pTempObj = new QBrush
		pTempObj.pObject = QListWidgetItem_background(pObject)
		return pTempObj

	Func checkState 
		return QListWidgetItem_checkState(pObject)

	Func flags 
		return QListWidgetItem_flags(pObject)

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QListWidgetItem_font(pObject)
		return pTempObj

	Func foreground 
		pTempObj = new QBrush
		pTempObj.pObject = QListWidgetItem_foreground(pObject)
		return pTempObj

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QListWidgetItem_icon(pObject)
		return pTempObj

	Func isHidden 
		return QListWidgetItem_isHidden(pObject)

	Func isSelected 
		return QListWidgetItem_isSelected(pObject)

	Func listWidget 
		pTempObj = new QListWidget
		pTempObj.pObject = QListWidgetItem_listWidget(pObject)
		return pTempObj

	Func setBackground P1
		return QListWidgetItem_setBackground(pObject,GetObjectPointerFromRingObject(P1))

	Func setCheckState P1
		return QListWidgetItem_setCheckState(pObject,P1)

	Func setFlags P1
		return QListWidgetItem_setFlags(pObject,P1)

	Func setFont P1
		return QListWidgetItem_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setForeground P1
		return QListWidgetItem_setForeground(pObject,GetObjectPointerFromRingObject(P1))

	Func setHidden P1
		return QListWidgetItem_setHidden(pObject,P1)

	Func setIcon P1
		return QListWidgetItem_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelected P1
		return QListWidgetItem_setSelected(pObject,P1)

	Func setSizeHint P1
		return QListWidgetItem_setSizeHint(pObject,GetObjectPointerFromRingObject(P1))

	Func setStatusTip P1
		return QListWidgetItem_setStatusTip(pObject,P1)

	Func setText P1
		return QListWidgetItem_setText(pObject,P1)

	Func setTextAlignment P1
		return QListWidgetItem_setTextAlignment(pObject,P1)

	Func setToolTip P1
		return QListWidgetItem_setToolTip(pObject,P1)

	Func setWhatsThis P1
		return QListWidgetItem_setWhatsThis(pObject,P1)

	Func sizeHint 
		pTempObj = new QSize
		pTempObj.pObject = QListWidgetItem_sizeHint(pObject)
		return pTempObj

	Func statusTip 
		return QListWidgetItem_statusTip(pObject)

	Func text 
		return QListWidgetItem_text(pObject)

	Func textAlignment 
		return QListWidgetItem_textAlignment(pObject)

	Func toolTip 
		return QListWidgetItem_toolTip(pObject)

	Func type 
		return QListWidgetItem_type(pObject)

	Func whatsThis 
		return QListWidgetItem_whatsThis(pObject)

Class QSystemTrayIcon

	pObject

	Func init 
		pObject = QSystemTrayIcon_new()
		return self

	Func delete
		pObject = QSystemTrayIcon_delete(pObject)

	Func ObjectPointer
		return pObject

	Func contextMenu 
		pTempObj = new QMenu
		pTempObj.pObject = QSystemTrayIcon_contextMenu(pObject)
		return pTempObj

	Func geometry 
		pTempObj = new QRect
		pTempObj.pObject = QSystemTrayIcon_geometry(pObject)
		return pTempObj

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QSystemTrayIcon_icon(pObject)
		return pTempObj

	Func isVisible 
		return QSystemTrayIcon_isVisible(pObject)

	Func setContextMenu P1
		return QSystemTrayIcon_setContextMenu(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QSystemTrayIcon_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setToolTip P1
		return QSystemTrayIcon_setToolTip(pObject,P1)

	Func toolTip 
		return QSystemTrayIcon_toolTip(pObject)

	Func hide 
		return QSystemTrayIcon_hide(pObject)

	Func setVisible P1
		return QSystemTrayIcon_setVisible(pObject,P1)

	Func show 
		return QSystemTrayIcon_show(pObject)

	Func showMessage P1,P2,P3,P4
		return QSystemTrayIcon_showMessage(pObject,P1,P2,P3,P4)

	Func isSystemTrayAvailable 
		return QSystemTrayIcon_isSystemTrayAvailable(pObject)

	Func supportsMessages 
		return QSystemTrayIcon_supportsMessages(pObject)

Class QDate

	pObject

	Func init 
		pObject = QDate_new()
		return self

	Func delete
		pObject = QDate_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addDays P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addDays(pObject,P1)
		return pTempObj

	Func addMonths P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addMonths(pObject,P1)
		return pTempObj

	Func addYears P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_addYears(pObject,P1)
		return pTempObj

	Func day 
		return QDate_day(pObject)

	Func dayOfWeek 
		return QDate_dayOfWeek(pObject)

	Func dayOfYear 
		return QDate_dayOfYear(pObject)

	Func daysInMonth 
		return QDate_daysInMonth(pObject)

	Func daysInYear 
		return QDate_daysInYear(pObject)

	Func daysTo P1
		return QDate_daysTo(pObject,GetObjectPointerFromRingObject(P1))

	Func getDate P1,P2,P3
		return QDate_getDate(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func isNull 
		return QDate_isNull(pObject)

	Func isValid 
		return QDate_isValid(pObject)

	Func month 
		return QDate_month(pObject)

	Func setDate P1,P2,P3
		return QDate_setDate(pObject,P1,P2,P3)

	Func toJulianDay 
		return QDate_toJulianDay(pObject)

	Func toString P1
		return QDate_toString(pObject,P1)

	Func weekNumber P1
		return QDate_weekNumber(pObject,GetObjectPointerFromRingObject(P1))

	Func year 
		return QDate_year(pObject)

	Func currentDate 
		pTempObj = new QDate
		pTempObj.pObject = QDate_currentDate(pObject)
		return pTempObj

	Func fromJulianDay P1
		pTempObj = new QDate
		pTempObj.pObject = QDate_fromJulianDay(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QDate
		pTempObj.pObject = QDate_fromString(pObject,P1,P2)
		return pTempObj

	Func isLeapYear P1
		return QDate_isLeapYear(pObject,P1)

	Func longDayName P1
		return QDate_longDayName(pObject,P1)

	Func longMonthName P1
		return QDate_longMonthName(pObject,P1)

	Func shortDayName P1
		return QDate_shortDayName(pObject,P1)

	Func shortMonthName P1
		return QDate_shortMonthName(pObject,P1)

Class QTextCodec
	Func codecForName P1
		return QTextCodec_codecForName(P1)

	Func setCodecForLocale P1
		return QTextCodec_setCodecForLocale(GetObjectPointerFromRingObject(P1))

Class QSqlDatabase

	pObject

	Func init 
		pObject = QSqlDatabase_new()
		return self

	Func delete
		pObject = QSqlDatabase_delete(pObject)

	Func ObjectPointer
		return pObject

	Func close 
		return QSqlDatabase_close(pObject)

	Func commit 
		return QSqlDatabase_commit(pObject)

	Func connectOptions 
		return QSqlDatabase_connectOptions(pObject)

	Func connectionName 
		return QSqlDatabase_connectionName(pObject)

	Func databaseName 
		return QSqlDatabase_databaseName(pObject)

	Func driver 
		pTempObj = new QSqlDriver
		pTempObj.pObject = QSqlDatabase_driver(pObject)
		return pTempObj

	Func driverName 
		return QSqlDatabase_driverName(pObject)

	Func exec P1
		pTempObj = new QSqlQuery
		pTempObj.pObject = QSqlDatabase_exec(pObject,P1)
		return pTempObj

	Func hostName 
		return QSqlDatabase_hostName(pObject)

	Func isOpen 
		return QSqlDatabase_isOpen(pObject)

	Func isOpenError 
		return QSqlDatabase_isOpenError(pObject)

	Func isValid 
		return QSqlDatabase_isValid(pObject)

	Func lastError 
		pTempObj = new QSqlError
		pTempObj.pObject = QSqlDatabase_lastError(pObject)
		return pTempObj

	Func numericalPrecisionPolicy 
		return QSqlDatabase_numericalPrecisionPolicy(pObject)

	Func open 
		return QSqlDatabase_open(pObject)

	Func password 
		return QSqlDatabase_password(pObject)

	Func port 
		return QSqlDatabase_port(pObject)

	Func primaryIndex P1
		pTempObj = new QSqlIndex
		pTempObj.pObject = QSqlDatabase_primaryIndex(pObject,P1)
		return pTempObj

	Func record P1
		pTempObj = new QSqlRecord
		pTempObj.pObject = QSqlDatabase_record(pObject,P1)
		return pTempObj

	Func rollback 
		return QSqlDatabase_rollback(pObject)

	Func setConnectOptions P1
		return QSqlDatabase_setConnectOptions(pObject,P1)

	Func setDatabaseName P1
		return QSqlDatabase_setDatabaseName(pObject,P1)

	Func setHostName P1
		return QSqlDatabase_setHostName(pObject,P1)

	Func setNumericalPrecisionPolicy P1
		return QSqlDatabase_setNumericalPrecisionPolicy(pObject,P1)

	Func setPassword P1
		return QSqlDatabase_setPassword(pObject,P1)

	Func setPort P1
		return QSqlDatabase_setPort(pObject,P1)

	Func setUserName P1
		return QSqlDatabase_setUserName(pObject,P1)

	Func tables P1
		pTempObj = new QStringList
		pTempObj.pObject = QSqlDatabase_tables(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func transaction 
		return QSqlDatabase_transaction(pObject)

	Func userName 
		return QSqlDatabase_userName(pObject)

	Func addDatabase P1
		pTempObj = new QSqlDatabase
		pTempObj.pObject = QSqlDatabase_addDatabase(pObject,P1)
		return pTempObj

	Func cloneDatabase P1,P2
		pTempObj = new QSqlDatabase
		pTempObj.pObject = QSqlDatabase_cloneDatabase(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func connectionNames 
		pTempObj = new QStringList
		pTempObj.pObject = QSqlDatabase_connectionNames(pObject)
		return pTempObj

	Func contains P1
		return QSqlDatabase_contains(pObject,P1)

	Func database P1,P2
		pTempObj = new QSqlDatabase
		pTempObj.pObject = QSqlDatabase_database(pObject,P1,P2)
		return pTempObj

	Func drivers 
		pTempObj = new QStringList
		pTempObj.pObject = QSqlDatabase_drivers(pObject)
		return pTempObj

	Func isDriverAvailable P1
		return QSqlDatabase_isDriverAvailable(pObject,P1)

	Func registerSqlDriver P1,P2
		return QSqlDatabase_registerSqlDriver(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func removeDatabase P1
		return QSqlDatabase_removeDatabase(pObject,P1)

Class QSqlDriver

	pObject

	Func init 
		pObject = QSqlDriver_new()
		return self

	Func delete
		pObject = QSqlDriver_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isOpenError 
		return QSqlDriver_isOpenError(pObject)

	Func lastError 
		pTempObj = new QSqlError
		pTempObj.pObject = QSqlDriver_lastError(pObject)
		return pTempObj

	Func numericalPrecisionPolicy 
		return QSqlDriver_numericalPrecisionPolicy(pObject)

	Func setNumericalPrecisionPolicy P1
		return QSqlDriver_setNumericalPrecisionPolicy(pObject,P1)

Class QSqlQuery

	pObject

	Func init 
		pObject = QSqlQuery_new()
		return self

	Func delete
		pObject = QSqlQuery_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addBindValue P1,P2
		return QSqlQuery_addBindValue(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func at 
		return QSqlQuery_at(pObject)

	Func bindValue P1,P2,P3
		return QSqlQuery_bindValue(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func boundValue P1
		pTempObj = new QVariant
		pTempObj.pObject = QSqlQuery_boundValue(pObject,P1)
		return pTempObj

	Func clear 
		return QSqlQuery_clear(pObject)

	Func driver 
		pTempObj = new QSqlDriver
		pTempObj.pObject = QSqlQuery_driver(pObject)
		return pTempObj

	Func exec P1
		return QSqlQuery_exec(pObject,P1)

	Func exec_2 
		return QSqlQuery_exec_2(pObject)

	Func execBatch P1
		return QSqlQuery_execBatch(pObject,P1)

	Func executedQuery 
		return QSqlQuery_executedQuery(pObject)

	Func finish 
		return QSqlQuery_finish(pObject)

	Func first 
		return QSqlQuery_first(pObject)

	Func isActive 
		return QSqlQuery_isActive(pObject)

	Func isForwardOnly 
		return QSqlQuery_isForwardOnly(pObject)

	Func isNull P1
		return QSqlQuery_isNull(pObject,P1)

	Func isSelect 
		return QSqlQuery_isSelect(pObject)

	Func isValid 
		return QSqlQuery_isValid(pObject)

	Func last 
		return QSqlQuery_last(pObject)

	Func lastError 
		pTempObj = new QSqlError
		pTempObj.pObject = QSqlQuery_lastError(pObject)
		return pTempObj

	Func lastInsertId 
		pTempObj = new QVariant
		pTempObj.pObject = QSqlQuery_lastInsertId(pObject)
		return pTempObj

	Func lastQuery 
		return QSqlQuery_lastQuery(pObject)

	Func movenext 
		return QSqlQuery_next(pObject)

	Func nextResult 
		return QSqlQuery_nextResult(pObject)

	Func numRowsAffected 
		return QSqlQuery_numRowsAffected(pObject)

	Func numericalPrecisionPolicy 
		return QSqlQuery_numericalPrecisionPolicy(pObject)

	Func prepare P1
		return QSqlQuery_prepare(pObject,P1)

	Func previous 
		return QSqlQuery_previous(pObject)

	Func record 
		pTempObj = new QSqlRecord
		pTempObj.pObject = QSqlQuery_record(pObject)
		return pTempObj

	Func result 
		return QSqlQuery_result(pObject)

	Func seek P1,P2
		return QSqlQuery_seek(pObject,P1,P2)

	Func setForwardOnly P1
		return QSqlQuery_setForwardOnly(pObject,P1)

	Func setNumericalPrecisionPolicy P1
		return QSqlQuery_setNumericalPrecisionPolicy(pObject,P1)

	Func size 
		return QSqlQuery_size(pObject)

	Func value P1
		pTempObj = new QVariant
		pTempObj.pObject = QSqlQuery_value(pObject,P1)
		return pTempObj

Class QSqlError

	pObject

	Func init P1,P2,P3
		pObject = QSqlError_new(P1,P2,P3)
		return self

	Func delete
		pObject = QSqlError_delete(pObject)

	Func ObjectPointer
		return pObject

	Func databaseText 
		return QSqlError_databaseText(pObject)

	Func driverText 
		return QSqlError_driverText(pObject)

	Func isValid 
		return QSqlError_isValid(pObject)

	Func number 
		return QSqlError_number(pObject)

	Func setDatabaseText P1
		return QSqlError_setDatabaseText(pObject,P1)

	Func setDriverText P1
		return QSqlError_setDriverText(pObject,P1)

	Func setNumber P1
		return QSqlError_setNumber(pObject,P1)

	Func setType P1
		return QSqlError_setType(pObject,P1)

	Func text 
		return QSqlError_text(pObject)

	Func type 
		return QSqlError_type(pObject)

Class QSqlIndex from QSqlRecord

	pObject

	Func init P1,P2
		pObject = QSqlIndex_new(P1,P2)
		return self

	Func delete
		pObject = QSqlIndex_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1,P2
		return QSqlIndex_append(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func cursorName 
		return QSqlIndex_cursorName(pObject)

	Func isDescending P1
		return QSqlIndex_isDescending(pObject,P1)

	Func name 
		return QSqlIndex_name(pObject)

	Func setCursorName P1
		return QSqlIndex_setCursorName(pObject,P1)

	Func setDescending P1,P2
		return QSqlIndex_setDescending(pObject,P1,P2)

	Func setName P1
		return QSqlIndex_setName(pObject,P1)

Class QSqlRecord

	pObject

	Func init 
		pObject = QSqlRecord_new()
		return self

	Func delete
		pObject = QSqlRecord_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		return QSqlRecord_append(pObject,GetObjectPointerFromRingObject(P1))

	Func clear 
		return QSqlRecord_clear(pObject)

	Func clearValues 
		return QSqlRecord_clearValues(pObject)

	Func contains P1
		return QSqlRecord_contains(pObject,P1)

	Func count 
		return QSqlRecord_count(pObject)

	Func field P1
		pTempObj = new QSqlField
		pTempObj.pObject = QSqlRecord_field(pObject,P1)
		return pTempObj

	Func fieldName P1
		return QSqlRecord_fieldName(pObject,P1)

	Func indexOf P1
		return QSqlRecord_indexOf(pObject,P1)

	Func insert P1,P2
		return QSqlRecord_insert(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isEmpty 
		return QSqlRecord_isEmpty(pObject)

	Func isGenerated P1
		return QSqlRecord_isGenerated(pObject,P1)

	Func isNull P1
		return QSqlRecord_isNull(pObject,P1)

	Func remove P1
		return QSqlRecord_remove(pObject,P1)

	Func replace P1,P2
		return QSqlRecord_replace(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setGenerated P1,P2
		return QSqlRecord_setGenerated(pObject,P1,P2)

	Func setNull P1
		return QSqlRecord_setNull(pObject,P1)

	Func setValue P1,P2
		return QSqlRecord_setValue(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func value P1
		pTempObj = new QVariant
		pTempObj.pObject = QSqlRecord_value(pObject,P1)
		return pTempObj

Class QSqlField

	pObject

	Func init P1,P2
		pObject = QSqlField_new(P1,P2)
		return self

	Func delete
		pObject = QSqlField_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QSqlField_clear(pObject)

	Func defaultValue 
		pTempObj = new QVariant
		pTempObj.pObject = QSqlField_defaultValue(pObject)
		return pTempObj

	Func isAutoValue 
		return QSqlField_isAutoValue(pObject)

	Func isGenerated 
		return QSqlField_isGenerated(pObject)

	Func isNull 
		return QSqlField_isNull(pObject)

	Func isReadOnly 
		return QSqlField_isReadOnly(pObject)

	Func isValid 
		return QSqlField_isValid(pObject)

	Func length 
		return QSqlField_length(pObject)

	Func name 
		return QSqlField_name(pObject)

	Func precision 
		return QSqlField_precision(pObject)

	Func requiredStatus 
		return QSqlField_requiredStatus(pObject)

	Func setAutoValue P1
		return QSqlField_setAutoValue(pObject,P1)

	Func setDefaultValue P1
		return QSqlField_setDefaultValue(pObject,GetObjectPointerFromRingObject(P1))

	Func setGenerated P1
		return QSqlField_setGenerated(pObject,P1)

	Func setLength P1
		return QSqlField_setLength(pObject,P1)

	Func setName P1
		return QSqlField_setName(pObject,P1)

	Func setPrecision P1
		return QSqlField_setPrecision(pObject,P1)

	Func setReadOnly P1
		return QSqlField_setReadOnly(pObject,P1)

	Func setRequired P1
		return QSqlField_setRequired(pObject,P1)

	Func setRequiredStatus P1
		return QSqlField_setRequiredStatus(pObject,P1)

	Func setType P1
		return QSqlField_setType(pObject,P1)

	Func setValue P1
		return QSqlField_setValue(pObject,GetObjectPointerFromRingObject(P1))

	Func type 
		return QSqlField_type(pObject)

	Func value 
		pTempObj = new QVariant
		pTempObj.pObject = QSqlField_value(pObject)
		return pTempObj

Class QVariant

	pObject

	Func init 
		pObject = QVariant_new()
		return self

	Func delete
		pObject = QVariant_delete(pObject)

	Func ObjectPointer
		return pObject

	Func canConvert P1
		return QVariant_canConvert(pObject,P1)

	Func clear 
		return QVariant_clear(pObject)

	Func convert P1
		return QVariant_convert(pObject,P1)

	Func isNull 
		return QVariant_isNull(pObject)

	Func isValid 
		return QVariant_isValid(pObject)

	Func swap P1
		return QVariant_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toBitArray 
		return QVariant_toBitArray(pObject)

	Func toBool 
		return QVariant_toBool(pObject)

	Func toByteArray 
		pTempObj = new QByteArray
		pTempObj.pObject = QVariant_toByteArray(pObject)
		return pTempObj

	Func toChar 
		return QVariant_toChar(pObject)

	Func toDate 
		pTempObj = new QDate
		pTempObj.pObject = QVariant_toDate(pObject)
		return pTempObj

	Func toDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QVariant_toDateTime(pObject)
		return pTempObj

	Func toDouble P1
		return QVariant_toDouble(pObject,GetObjectPointerFromRingObject(P1))

	Func toEasingCurve 
		return QVariant_toEasingCurve(pObject)

	Func toFloat P1
		return QVariant_toFloat(pObject,GetObjectPointerFromRingObject(P1))

	Func toInt P1
		return QVariant_toInt(pObject,GetObjectPointerFromRingObject(P1))

	Func toJsonArray 
		pTempObj = new QJsonArray
		pTempObj.pObject = QVariant_toJsonArray(pObject)
		return pTempObj

	Func toJsonDocument 
		pTempObj = new QJsonDocument
		pTempObj.pObject = QVariant_toJsonDocument(pObject)
		return pTempObj

	Func toJsonObject 
		pTempObj = new QJsonObject
		pTempObj.pObject = QVariant_toJsonObject(pObject)
		return pTempObj

	Func toJsonValue 
		pTempObj = new QJsonValue
		pTempObj.pObject = QVariant_toJsonValue(pObject)
		return pTempObj

	Func toLine 
		return QVariant_toLine(pObject)

	Func toLineF 
		return QVariant_toLineF(pObject)

	Func toLocale 
		return QVariant_toLocale(pObject)

	Func toLongLong P1
		return QVariant_toLongLong(pObject,GetObjectPointerFromRingObject(P1))

	Func toModelIndex 
		return QVariant_toModelIndex(pObject)

	Func toPoint 
		pTempObj = new QPoint
		pTempObj.pObject = QVariant_toPoint(pObject)
		return pTempObj

	Func toPointF 
		pTempObj = new QPointF
		pTempObj.pObject = QVariant_toPointF(pObject)
		return pTempObj

	Func toReal P1
		return QVariant_toReal(pObject,GetObjectPointerFromRingObject(P1))

	Func toRect 
		pTempObj = new QRect
		pTempObj.pObject = QVariant_toRect(pObject)
		return pTempObj

	Func toRectF 
		return QVariant_toRectF(pObject)

	Func toRegExp 
		return QVariant_toRegExp(pObject)

	Func toRegularExpression 
		pTempObj = new QRegularExpression
		pTempObj.pObject = QVariant_toRegularExpression(pObject)
		return pTempObj

	Func toSize 
		pTempObj = new QSize
		pTempObj.pObject = QVariant_toSize(pObject)
		return pTempObj

	Func toSizeF 
		return QVariant_toSizeF(pObject)

	Func toStringList 
		pTempObj = new QStringList
		pTempObj.pObject = QVariant_toStringList(pObject)
		return pTempObj

	Func toTime 
		pTempObj = new QTime
		pTempObj.pObject = QVariant_toTime(pObject)
		return pTempObj

	Func toUInt P1
		return QVariant_toUInt(pObject,GetObjectPointerFromRingObject(P1))

	Func toULongLong P1
		return QVariant_toULongLong(pObject,GetObjectPointerFromRingObject(P1))

	Func toUrl 
		pTempObj = new QUrl
		pTempObj.pObject = QVariant_toUrl(pObject)
		return pTempObj

	Func toUuid 
		pTempObj = new QUuid
		pTempObj.pObject = QVariant_toUuid(pObject)
		return pTempObj

	Func type 
		return QVariant_type(pObject)

	Func typeName 
		return QVariant_typeName(pObject)

	Func userType 
		return QVariant_userType(pObject)

	Func toString 
		return QVariant_toString(pObject)

Class QNetworkRequest

	pObject

	Func init P1
		pObject = QNetworkRequest_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QNetworkRequest_delete(pObject)

	Func ObjectPointer
		return pObject

	Func attribute P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkRequest_attribute(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func hasRawHeader P1
		return QNetworkRequest_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkRequest_header(pObject,P1)
		return pTempObj

	Func originatingObject 
		pTempObj = new QObject
		pTempObj.pObject = QNetworkRequest_originatingObject(pObject)
		return pTempObj

	Func priority 
		return QNetworkRequest_priority(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkRequest_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setAttribute P1,P2
		return QNetworkRequest_setAttribute(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHeader P1,P2
		return QNetworkRequest_setHeader(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setOriginatingObject P1
		return QNetworkRequest_setOriginatingObject(pObject,GetObjectPointerFromRingObject(P1))

	Func setPriority P1
		return QNetworkRequest_setPriority(pObject,P1)

	Func setRawHeader P1,P2
		return QNetworkRequest_setRawHeader(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setUrl P1
		return QNetworkRequest_setUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func swap P1
		return QNetworkRequest_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QNetworkRequest_url(pObject)
		return pTempObj

Class QNetworkAccessManager from QObject

	pObject

	Func init P1
		pObject = QNetworkAccessManager_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QNetworkAccessManager_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setfinishedEvent P1
		return QNetworkAccessManager_setfinishedEvent(pObject,P1)

	Func getfinishedEvent 
		return QNetworkAccessManager_getfinishedEvent(pObject)

	Func activeConfiguration 
		return QNetworkAccessManager_activeConfiguration(pObject)

	Func cache 
		return QNetworkAccessManager_cache(pObject)

	Func clearAccessCache 
		return QNetworkAccessManager_clearAccessCache(pObject)

	Func configuration 
		return QNetworkAccessManager_configuration(pObject)

	Func connectToHost P1,P2
		return QNetworkAccessManager_connectToHost(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func cookieJar 
		return QNetworkAccessManager_cookieJar(pObject)

	Func deleteResource P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_deleteResource(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func getvalue P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_get(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func head P1
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_head(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func networkAccessible 
		return QNetworkAccessManager_networkAccessible(pObject)

	Func post P1,P2
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_post(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func proxy 
		pTempObj = new QNetworkProxy
		pTempObj.pObject = QNetworkAccessManager_proxy(pObject)
		return pTempObj

	Func proxyFactory 
		return QNetworkAccessManager_proxyFactory(pObject)

	Func putvalue P1,P2
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_put(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func sendCustomRequest P1,P2,P3
		pTempObj = new QNetworkReply
		pTempObj.pObject = QNetworkAccessManager_sendCustomRequest(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func setCache P1
		return QNetworkAccessManager_setCache(pObject,GetObjectPointerFromRingObject(P1))

	Func setConfiguration P1
		return QNetworkAccessManager_setConfiguration(pObject,GetObjectPointerFromRingObject(P1))

	Func setCookieJar P1
		return QNetworkAccessManager_setCookieJar(pObject,GetObjectPointerFromRingObject(P1))

	Func setNetworkAccessible P1
		return QNetworkAccessManager_setNetworkAccessible(pObject,P1)

	Func setProxy P1
		return QNetworkAccessManager_setProxy(pObject,GetObjectPointerFromRingObject(P1))

	Func setProxyFactory P1
		return QNetworkAccessManager_setProxyFactory(pObject,GetObjectPointerFromRingObject(P1))

	Func supportedSchemes 
		pTempObj = new QStringList
		pTempObj.pObject = QNetworkAccessManager_supportedSchemes(pObject)
		return pTempObj

	Func geteventparameters 
		return QNetworkAccessManager_geteventparameters(pObject)

Class QNetworkReply from QIODevice

	pObject

	Func init 
		pObject = QNetworkReply_new()
		return self

	Func delete
		pObject = QNetworkReply_delete(pObject)

	Func ObjectPointer
		return pObject

	Func attribute P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkReply_attribute(pObject,P1)
		return pTempObj

	Func error 
		return QNetworkReply_error(pObject)

	Func hasRawHeader P1
		return QNetworkReply_hasRawHeader(pObject,GetObjectPointerFromRingObject(P1))

	Func header P1
		pTempObj = new QVariant
		pTempObj.pObject = QNetworkReply_header(pObject,P1)
		return pTempObj

	Func isFinished 
		return QNetworkReply_isFinished(pObject)

	Func isRunning 
		return QNetworkReply_isRunning(pObject)

	Func manager 
		pTempObj = new QNetworkAccessManager
		pTempObj.pObject = QNetworkReply_manager(pObject)
		return pTempObj

	Func operation 
		return QNetworkReply_operation(pObject)

	Func rawHeader P1
		pTempObj = new QByteArray
		pTempObj.pObject = QNetworkReply_rawHeader(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func readBufferSize 
		return QNetworkReply_readBufferSize(pObject)

	Func request 
		pTempObj = new QNetworkRequest
		pTempObj.pObject = QNetworkReply_request(pObject)
		return pTempObj

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QNetworkReply_url(pObject)
		return pTempObj

Class QPainterPath

	pObject

	Func init 
		pObject = QPainterPath_new()
		return self

	Func delete
		pObject = QPainterPath_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addEllipse P1,P2,P3,P4
		return QPainterPath_addEllipse(pObject,P1,P2,P3,P4)

	Func addPath P1
		return QPainterPath_addPath(pObject,GetObjectPointerFromRingObject(P1))

	Func addPolygon P1
		return QPainterPath_addPolygon(pObject,GetObjectPointerFromRingObject(P1))

	Func addRect P1,P2,P3,P4
		return QPainterPath_addRect(pObject,P1,P2,P3,P4)

	Func addRegion P1
		return QPainterPath_addRegion(pObject,GetObjectPointerFromRingObject(P1))

	Func addRoundedRect P1,P2,P3,P4,P5,P6,P7
		return QPainterPath_addRoundedRect(pObject,P1,P2,P3,P4,P5,P6,P7)

	Func addText P1,P2,P3,P4
		return QPainterPath_addText(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4)

	Func angleAtPercent P1
		return QPainterPath_angleAtPercent(pObject,P1)

	Func arcMoveTo P1,P2,P3,P4,P5
		return QPainterPath_arcMoveTo(pObject,P1,P2,P3,P4,P5)

	Func arcTo P1,P2,P3,P4,P5,P6
		return QPainterPath_arcTo(pObject,P1,P2,P3,P4,P5,P6)

	Func boundingRect 
		return QPainterPath_boundingRect(pObject)

	Func closeSubpath 
		return QPainterPath_closeSubpath(pObject)

	Func connectPath P1
		return QPainterPath_connectPath(pObject,GetObjectPointerFromRingObject(P1))

	Func contains P1
		return QPainterPath_contains(pObject,GetObjectPointerFromRingObject(P1))

	Func controlPointRect 
		return QPainterPath_controlPointRect(pObject)

	Func cubicTo P1,P2,P3,P4,P5,P6
		return QPainterPath_cubicTo(pObject,P1,P2,P3,P4,P5,P6)

	Func currentPosition 
		pTempObj = new QPointF
		pTempObj.pObject = QPainterPath_currentPosition(pObject)
		return pTempObj

	Func elementAt P1
		return QPainterPath_elementAt(pObject,P1)

	Func elementCount 
		return QPainterPath_elementCount(pObject)

	Func fillRule 
		return QPainterPath_fillRule(pObject)

	Func intersected P1
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_intersected(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func intersects P1
		return QPainterPath_intersects(pObject,GetObjectPointerFromRingObject(P1))

	Func isEmpty 
		return QPainterPath_isEmpty(pObject)

	Func length 
		return QPainterPath_length(pObject)

	Func lineTo P1,P2
		return QPainterPath_lineTo(pObject,P1,P2)

	Func moveTo P1,P2
		return QPainterPath_moveTo(pObject,P1,P2)

	Func percentAtLength P1
		return QPainterPath_percentAtLength(pObject,P1)

	Func pointAtPercent P1
		pTempObj = new QPointF
		pTempObj.pObject = QPainterPath_pointAtPercent(pObject,P1)
		return pTempObj

	Func quadTo P1,P2,P3,P4
		return QPainterPath_quadTo(pObject,P1,P2,P3,P4)

	Func setElementPositionAt P1,P2,P3
		return QPainterPath_setElementPositionAt(pObject,P1,P2,P3)

	Func setFillRule P1
		return QPainterPath_setFillRule(pObject,P1)

	Func simplified 
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_simplified(pObject)
		return pTempObj

	Func slopeAtPercent P1
		return QPainterPath_slopeAtPercent(pObject,P1)

	Func subtracted P1
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_subtracted(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func swap P1
		return QPainterPath_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func toFillPolygon P1
		return QPainterPath_toFillPolygon(pObject,GetObjectPointerFromRingObject(P1))

	Func toReversed 
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_toReversed(pObject)
		return pTempObj

	Func translate P1,P2
		return QPainterPath_translate(pObject,P1,P2)

	Func translated P1,P2
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_translated(pObject,P1,P2)
		return pTempObj

	Func united P1
		pTempObj = new QPainterPath
		pTempObj.pObject = QPainterPath_united(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QImage

	pObject

	Func init 
		pObject = QImage_new()
		return self

	Func delete
		pObject = QImage_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allGray 
		return QImage_allGray(pObject)

	Func bitPlaneCount 
		return QImage_bitPlaneCount(pObject)

	Func bits 
		return QImage_bits(pObject)

	Func byteCount 
		return QImage_byteCount(pObject)

	Func bytesPerLine 
		return QImage_bytesPerLine(pObject)

	Func cacheKey 
		return QImage_cacheKey(pObject)

	Func color P1
		return QImage_color(pObject,P1)

	Func colorCount 
		return QImage_colorCount(pObject)

	Func constBits 
		return QImage_constBits(pObject)

	Func constScanLine P1
		return QImage_constScanLine(pObject,P1)

	Func convertToFormat P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_convertToFormat(pObject,P1,P2)
		return pTempObj

	Func copy P1,P2,P3,P4
		pTempObj = new QImage
		pTempObj.pObject = QImage_copy(pObject,P1,P2,P3,P4)
		return pTempObj

	Func createAlphaMask P1
		pTempObj = new QImage
		pTempObj.pObject = QImage_createAlphaMask(pObject,P1)
		return pTempObj

	Func createHeuristicMask P1
		pTempObj = new QImage
		pTempObj.pObject = QImage_createHeuristicMask(pObject,P1)
		return pTempObj

	Func createMaskFromColor P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_createMaskFromColor(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func depth 
		return QImage_depth(pObject)

	Func dotsPerMeterX 
		return QImage_dotsPerMeterX(pObject)

	Func dotsPerMeterY 
		return QImage_dotsPerMeterY(pObject)

	Func fill P1
		return QImage_fill(pObject,GetObjectPointerFromRingObject(P1))

	Func format 
		return QImage_format(pObject)

	Func hasAlphaChannel 
		return QImage_hasAlphaChannel(pObject)

	Func height 
		return QImage_height(pObject)

	Func invertPixels P1
		return QImage_invertPixels(pObject,P1)

	Func isGrayscale 
		return QImage_isGrayscale(pObject)

	Func isNull 
		return QImage_isNull(pObject)

	Func loadimage P1,P2
		return QImage_load(pObject,P1,P2)

	Func loadFromData P1,P2
		return QImage_loadFromData(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func mirrored P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_mirrored(pObject,P1,P2)
		return pTempObj

	Func offset 
		pTempObj = new QPoint
		pTempObj.pObject = QImage_offset(pObject)
		return pTempObj

	Func pixel P1,P2
		return QImage_pixel(pObject,P1,P2)

	Func pixelIndex P1,P2
		return QImage_pixelIndex(pObject,P1,P2)

	Func rect 
		pTempObj = new QRect
		pTempObj.pObject = QImage_rect(pObject)
		return pTempObj

	Func rgbSwapped 
		pTempObj = new QImage
		pTempObj.pObject = QImage_rgbSwapped(pObject)
		return pTempObj

	Func save P1,P2,P3
		return QImage_save(pObject,P1,P2,P3)

	Func scaled P1,P2,P3,P4
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaled(pObject,P1,P2,P3,P4)
		return pTempObj

	Func scaledToHeight P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaledToHeight(pObject,P1,P2)
		return pTempObj

	Func scaledToWidth P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_scaledToWidth(pObject,P1,P2)
		return pTempObj

	Func scanLine P1
		return QImage_scanLine(pObject,P1)

	Func setColor P1,P2
		return QImage_setColor(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setColorCount P1
		return QImage_setColorCount(pObject,P1)

	Func setDotsPerMeterX P1
		return QImage_setDotsPerMeterX(pObject,P1)

	Func setDotsPerMeterY P1
		return QImage_setDotsPerMeterY(pObject,P1)

	Func setOffset P1
		return QImage_setOffset(pObject,GetObjectPointerFromRingObject(P1))

	Func setPixel P1,P2,P3
		return QImage_setPixel(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func setText P1,P2
		return QImage_setText(pObject,P1,P2)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QImage_size(pObject)
		return pTempObj

	Func swap P1
		return QImage_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func text P1
		return QImage_text(pObject,P1)

	Func textKeys 
		pTempObj = new QStringList
		pTempObj.pObject = QImage_textKeys(pObject)
		return pTempObj

	Func transformed P1,P2
		pTempObj = new QImage
		pTempObj.pObject = QImage_transformed(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func valid P1,P2
		return QImage_valid(pObject,P1,P2)

	Func width 
		return QImage_width(pObject)

Class RingCodeHighlighter

	pObject

	Func init P1
		pObject = RingCodeHighlighter_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = RingCodeHighlighter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setColors P1,P2,P3,P4,P5
		return RingCodeHighlighter_setColors(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func setKeywordsBold P1
		return RingCodeHighlighter_setKeywordsBold(pObject,P1)

Class QXmlStreamReader

	pObject

	Func init 
		pObject = QXmlStreamReader_new()
		return self

	Func delete
		pObject = QXmlStreamReader_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addData P1
		return QXmlStreamReader_addData(pObject,GetObjectPointerFromRingObject(P1))

	Func addData_2 P1
		return QXmlStreamReader_addData_2(pObject,P1)

	Func addData_3 P1
		return QXmlStreamReader_addData_3(pObject,P1)

	Func addExtraNamespaceDeclaration P1
		return QXmlStreamReader_addExtraNamespaceDeclaration(pObject,GetObjectPointerFromRingObject(P1))

	Func addExtraNamespaceDeclarations P1
		return QXmlStreamReader_addExtraNamespaceDeclarations(pObject,GetObjectPointerFromRingObject(P1))

	Func atEnd 
		return QXmlStreamReader_atEnd(pObject)

	Func attributes 
		pTempObj = new QXmlStreamAttributes
		pTempObj.pObject = QXmlStreamReader_attributes(pObject)
		return pTempObj

	Func characterOffset 
		return QXmlStreamReader_characterOffset(pObject)

	Func clear 
		return QXmlStreamReader_clear(pObject)

	Func columnNumber 
		return QXmlStreamReader_columnNumber(pObject)

	Func device 
		pTempObj = new QIODevice
		pTempObj.pObject = QXmlStreamReader_device(pObject)
		return pTempObj

	Func documentEncoding 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_documentEncoding(pObject)
		return pTempObj

	Func documentVersion 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_documentVersion(pObject)
		return pTempObj

	Func dtdName 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_dtdName(pObject)
		return pTempObj

	Func dtdPublicId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_dtdPublicId(pObject)
		return pTempObj

	Func dtdSystemId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_dtdSystemId(pObject)
		return pTempObj

	Func entityDeclarations 
		return QXmlStreamReader_entityDeclarations(pObject)

	Func entityResolver 
		pTempObj = new QXmlStreamEntityResolver
		pTempObj.pObject = QXmlStreamReader_entityResolver(pObject)
		return pTempObj

	Func error 
		return QXmlStreamReader_error(pObject)

	Func errorString 
		return QXmlStreamReader_errorString(pObject)

	Func hasError 
		return QXmlStreamReader_hasError(pObject)

	Func isCDATA 
		return QXmlStreamReader_isCDATA(pObject)

	Func isCharacters 
		return QXmlStreamReader_isCharacters(pObject)

	Func isComment 
		return QXmlStreamReader_isComment(pObject)

	Func isDTD 
		return QXmlStreamReader_isDTD(pObject)

	Func isEndDocument 
		return QXmlStreamReader_isEndDocument(pObject)

	Func isEndElement 
		return QXmlStreamReader_isEndElement(pObject)

	Func isEntityReference 
		return QXmlStreamReader_isEntityReference(pObject)

	Func isProcessingInstruction 
		return QXmlStreamReader_isProcessingInstruction(pObject)

	Func isStandaloneDocument 
		return QXmlStreamReader_isStandaloneDocument(pObject)

	Func isStartDocument 
		return QXmlStreamReader_isStartDocument(pObject)

	Func isStartElement 
		return QXmlStreamReader_isStartElement(pObject)

	Func isWhitespace 
		return QXmlStreamReader_isWhitespace(pObject)

	Func lineNumber 
		return QXmlStreamReader_lineNumber(pObject)

	Func name 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_name(pObject)
		return pTempObj

	Func namespaceDeclarations 
		return QXmlStreamReader_namespaceDeclarations(pObject)

	Func namespaceProcessing 
		return QXmlStreamReader_namespaceProcessing(pObject)

	Func namespaceUri 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_namespaceUri(pObject)
		return pTempObj

	Func notationDeclarations 
		return QXmlStreamReader_notationDeclarations(pObject)

	Func prefix 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_prefix(pObject)
		return pTempObj

	Func processingInstructionData 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_processingInstructionData(pObject)
		return pTempObj

	Func processingInstructionTarget 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_processingInstructionTarget(pObject)
		return pTempObj

	Func qualifiedName 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_qualifiedName(pObject)
		return pTempObj

	Func raiseError P1
		return QXmlStreamReader_raiseError(pObject,P1)

	Func readElementText P1
		return QXmlStreamReader_readElementText(pObject,P1)

	Func readNext 
		return QXmlStreamReader_readNext(pObject)

	Func readNextStartElement 
		return QXmlStreamReader_readNextStartElement(pObject)

	Func setDevice P1
		return QXmlStreamReader_setDevice(pObject,GetObjectPointerFromRingObject(P1))

	Func setEntityResolver P1
		return QXmlStreamReader_setEntityResolver(pObject,GetObjectPointerFromRingObject(P1))

	Func setNamespaceProcessing P1
		return QXmlStreamReader_setNamespaceProcessing(pObject,P1)

	Func skipCurrentElement 
		return QXmlStreamReader_skipCurrentElement(pObject)

	Func text 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamReader_text(pObject)
		return pTempObj

	Func tokenString 
		return QXmlStreamReader_tokenString(pObject)

	Func tokenType 
		return QXmlStreamReader_tokenType(pObject)

Class QXmlStreamWriter

	pObject

	Func init 
		pObject = QXmlStreamWriter_new()
		return self

	Func delete
		pObject = QXmlStreamWriter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func autoFormatting 
		return QXmlStreamWriter_autoFormatting(pObject)

	Func autoFormattingIndent 
		return QXmlStreamWriter_autoFormattingIndent(pObject)

	Func codec 
		return QXmlStreamWriter_codec(pObject)

	Func device 
		pTempObj = new QIODevice
		pTempObj.pObject = QXmlStreamWriter_device(pObject)
		return pTempObj

	Func hasError 
		return QXmlStreamWriter_hasError(pObject)

	Func setAutoFormatting P1
		return QXmlStreamWriter_setAutoFormatting(pObject,P1)

	Func setAutoFormattingIndent P1
		return QXmlStreamWriter_setAutoFormattingIndent(pObject,P1)

	Func setCodec P1
		return QXmlStreamWriter_setCodec(pObject,GetObjectPointerFromRingObject(P1))

	Func setCodec_2 P1
		return QXmlStreamWriter_setCodec_2(pObject,P1)

	Func setDevice P1
		return QXmlStreamWriter_setDevice(pObject,GetObjectPointerFromRingObject(P1))

	Func writeAttribute P1,P2,P3
		return QXmlStreamWriter_writeAttribute(pObject,P1,P2,P3)

	Func writeAttribute_2 P1,P2
		return QXmlStreamWriter_writeAttribute_2(pObject,P1,P2)

	Func writeAttribute_3 P1
		return QXmlStreamWriter_writeAttribute_3(pObject,GetObjectPointerFromRingObject(P1))

	Func writeAttributes P1
		return QXmlStreamWriter_writeAttributes(pObject,GetObjectPointerFromRingObject(P1))

	Func writeCDATA P1
		return QXmlStreamWriter_writeCDATA(pObject,P1)

	Func writeCharacters P1
		return QXmlStreamWriter_writeCharacters(pObject,P1)

	Func writeComment P1
		return QXmlStreamWriter_writeComment(pObject,P1)

	Func writeCurrentToken P1
		return QXmlStreamWriter_writeCurrentToken(pObject,GetObjectPointerFromRingObject(P1))

	Func writeDTD P1
		return QXmlStreamWriter_writeDTD(pObject,P1)

	Func writeDefaultNamespace P1
		return QXmlStreamWriter_writeDefaultNamespace(pObject,P1)

	Func writeEmptyElement P1,P2
		return QXmlStreamWriter_writeEmptyElement(pObject,P1,P2)

	Func writeEmptyElement_2 P1
		return QXmlStreamWriter_writeEmptyElement_2(pObject,P1)

	Func writeEndDocument 
		return QXmlStreamWriter_writeEndDocument(pObject)

	Func writeEndElement 
		return QXmlStreamWriter_writeEndElement(pObject)

	Func writeEntityReference P1
		return QXmlStreamWriter_writeEntityReference(pObject,P1)

	Func writeNamespace P1,P2
		return QXmlStreamWriter_writeNamespace(pObject,P1,P2)

	Func writeProcessingInstruction P1,P2
		return QXmlStreamWriter_writeProcessingInstruction(pObject,P1,P2)

	Func writeStartDocument P1
		return QXmlStreamWriter_writeStartDocument(pObject,P1)

	Func writeStartDocument_2 P1,P2
		return QXmlStreamWriter_writeStartDocument_2(pObject,P1,P2)

	Func writeStartDocument_3 
		return QXmlStreamWriter_writeStartDocument_3(pObject)

	Func writeStartElement P1,P2
		return QXmlStreamWriter_writeStartElement(pObject,P1,P2)

	Func writeStartElement_2 P1
		return QXmlStreamWriter_writeStartElement_2(pObject,P1)

	Func writeTextElement P1,P2,P3
		return QXmlStreamWriter_writeTextElement(pObject,P1,P2,P3)

	Func writeTextElement_2 P1,P2
		return QXmlStreamWriter_writeTextElement_2(pObject,P1,P2)

Class QXmlStreamNotationDeclaration

	pObject

	Func init 
		pObject = QXmlStreamNotationDeclaration_new()
		return self

	Func delete
		pObject = QXmlStreamNotationDeclaration_delete(pObject)

	Func ObjectPointer
		return pObject

	Func name 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamNotationDeclaration_name(pObject)
		return pTempObj

	Func publicId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamNotationDeclaration_publicId(pObject)
		return pTempObj

	Func systemId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamNotationDeclaration_systemId(pObject)
		return pTempObj

Class QXmlStreamNamespaceDeclaration

	pObject

	Func init 
		pObject = QXmlStreamNamespaceDeclaration_new()
		return self

	Func delete
		pObject = QXmlStreamNamespaceDeclaration_delete(pObject)

	Func ObjectPointer
		return pObject

	Func namespaceUri 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamNamespaceDeclaration_namespaceUri(pObject)
		return pTempObj

	Func prefix 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamNamespaceDeclaration_prefix(pObject)
		return pTempObj

Class QXmlStreamEntityDeclaration

	pObject

	Func init 
		pObject = QXmlStreamEntityDeclaration_new()
		return self

	Func delete
		pObject = QXmlStreamEntityDeclaration_delete(pObject)

	Func ObjectPointer
		return pObject

	Func name 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamEntityDeclaration_name(pObject)
		return pTempObj

	Func notationName 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamEntityDeclaration_notationName(pObject)
		return pTempObj

	Func publicId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamEntityDeclaration_publicId(pObject)
		return pTempObj

	Func systemId 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamEntityDeclaration_systemId(pObject)
		return pTempObj

	Func value 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamEntityDeclaration_value(pObject)
		return pTempObj

Class QXmlStreamAttributes

	pObject

	Func init 
		pObject = QXmlStreamAttributes_new()
		return self

	Func delete
		pObject = QXmlStreamAttributes_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1,P2,P3
		return QXmlStreamAttributes_append(pObject,P1,P2,P3)

	Func append_2 P1,P2
		return QXmlStreamAttributes_append_2(pObject,P1,P2)

	Func hasAttribute P1
		return QXmlStreamAttributes_hasAttribute(pObject,P1)

	Func hasAttribute_2 P1
		return QXmlStreamAttributes_hasAttribute_2(pObject,GetObjectPointerFromRingObject(P1))

	Func hasAttribute_3 P1,P2
		return QXmlStreamAttributes_hasAttribute_3(pObject,P1,P2)

	Func value P1,P2
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttributes_value(pObject,P1,P2)
		return pTempObj

	Func value_2 P1,P2
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttributes_value_2(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func value_3 P1,P2
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttributes_value_3(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func value_4 P1
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttributes_value_4(pObject,P1)
		return pTempObj

	Func value_5 P1
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttributes_value_5(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QXmlStreamAttribute

	pObject

	Func init 
		pObject = QXmlStreamAttribute_new()
		return self

	Func delete
		pObject = QXmlStreamAttribute_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isDefault 
		return QXmlStreamAttribute_isDefault(pObject)

	Func name 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttribute_name(pObject)
		return pTempObj

	Func namespaceUri 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttribute_namespaceUri(pObject)
		return pTempObj

	Func prefix 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttribute_prefix(pObject)
		return pTempObj

	Func qualifiedName 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttribute_qualifiedName(pObject)
		return pTempObj

	Func value 
		pTempObj = new QStringRef
		pTempObj.pObject = QXmlStreamAttribute_value(pObject)
		return pTempObj

Class QThread from QObject

	pObject

	Func init P1
		pObject = QThread_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QThread_delete(pObject)

	Func ObjectPointer
		return pObject

	Func eventDispatcher 
		return QThread_eventDispatcher(pObject)

	Func exitfromthread P1
		return QThread_exit(pObject,P1)

	Func isFinished 
		return QThread_isFinished(pObject)

	Func isInterruptionRequested 
		return QThread_isInterruptionRequested(pObject)

	Func isRunning 
		return QThread_isRunning(pObject)

	Func priority 
		return QThread_priority(pObject)

	Func requestInterruption 
		return QThread_requestInterruption(pObject)

	Func setEventDispatcher P1
		return QThread_setEventDispatcher(pObject,GetObjectPointerFromRingObject(P1))

	Func setPriority P1
		return QThread_setPriority(pObject,P1)

	Func setStackSize P1
		return QThread_setStackSize(pObject,GetObjectPointerFromRingObject(P1))

	Func stackSize 
		return QThread_stackSize(pObject)

	Func wait P1
		return QThread_wait(pObject,GetObjectPointerFromRingObject(P1))

	Func quit 
		return QThread_quit(pObject)

	Func start P1
		return QThread_start(pObject,P1)

	Func terminate 
		return QThread_terminate(pObject)

	Func currentThread 
		pTempObj = new QThread
		pTempObj.pObject = QThread_currentThread(pObject)
		return pTempObj

	Func currentThreadId 
		return QThread_currentThreadId(pObject)

	Func idealThreadCount 
		return QThread_idealThreadCount(pObject)

	Func msleep P1
		return QThread_msleep(pObject,GetObjectPointerFromRingObject(P1))

	Func sleep P1
		return QThread_sleep(pObject,GetObjectPointerFromRingObject(P1))

	Func usleep P1
		return QThread_usleep(pObject,GetObjectPointerFromRingObject(P1))

	Func yieldCurrentThread 
		return QThread_yieldCurrentThread(pObject)

	Func setStartedEvent P1
		return QThread_setStartedEvent(pObject,P1)

	Func setFinishedEvent P1
		return QThread_setFinishedEvent(pObject,P1)

	Func getStartedEvent 
		return QThread_getStartedEvent(pObject)

	Func getFinishedEvent 
		return QThread_getFinishedEvent(pObject)

Class QThreadPool from QObject

	pObject

	Func init 
		pObject = QThreadPool_new()
		return self

	Func delete
		pObject = QThreadPool_delete(pObject)

	Func ObjectPointer
		return pObject

	Func activeThreadCount 
		return QThreadPool_activeThreadCount(pObject)

	Func clear 
		return QThreadPool_clear(pObject)

	Func expiryTimeout 
		return QThreadPool_expiryTimeout(pObject)

	Func maxThreadCount 
		return QThreadPool_maxThreadCount(pObject)

	Func releaseThread 
		return QThreadPool_releaseThread(pObject)

	Func reserveThread 
		return QThreadPool_reserveThread(pObject)

	Func setExpiryTimeout P1
		return QThreadPool_setExpiryTimeout(pObject,P1)

	Func setMaxThreadCount P1
		return QThreadPool_setMaxThreadCount(pObject,P1)

	Func start P1,P2
		return QThreadPool_start(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func tryStart P1
		return QThreadPool_tryStart(pObject,GetObjectPointerFromRingObject(P1))

	Func waitForDone P1
		return QThreadPool_waitForDone(pObject,P1)

	Func globalInstance 
		pTempObj = new QThreadPool
		pTempObj.pObject = QThreadPool_globalInstance(pObject)
		return pTempObj

Class QRegularExpression

	pObject

	Func init 
		pObject = QRegularExpression_new()
		return self

	Func delete
		pObject = QRegularExpression_delete(pObject)

	Func ObjectPointer
		return pObject

	Func captureCount 
		return QRegularExpression_captureCount(pObject)

	Func errorString 
		return QRegularExpression_errorString(pObject)

	Func globalMatch P1,P2,P3,P4
		pTempObj = new QRegularExpressionMatchIterator
		pTempObj.pObject = QRegularExpression_globalMatch(pObject,P1,P2,P3,P4)
		return pTempObj

	Func isValid 
		return QRegularExpression_isValid(pObject)

	Func match P1,P2,P3,P4
		pTempObj = new QRegularExpressionMatch
		pTempObj.pObject = QRegularExpression_match(pObject,P1,P2,P3,P4)
		return pTempObj

	Func namedCaptureGroups 
		pTempObj = new QStringList
		pTempObj.pObject = QRegularExpression_namedCaptureGroups(pObject)
		return pTempObj

	Func pattern 
		return QRegularExpression_pattern(pObject)

	Func patternErrorOffset 
		return QRegularExpression_patternErrorOffset(pObject)

	Func patternOptions 
		return QRegularExpression_patternOptions(pObject)

	Func setPattern P1
		return QRegularExpression_setPattern(pObject,P1)

	Func setPatternOptions P1
		return QRegularExpression_setPatternOptions(pObject,P1)

	Func swap P1
		return QRegularExpression_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QRegularExpressionMatch

	pObject

	Func init 
		pObject = QRegularExpressionMatch_new()
		return self

	Func delete
		pObject = QRegularExpressionMatch_delete(pObject)

	Func ObjectPointer
		return pObject

	Func captured P1
		return QRegularExpressionMatch_captured(pObject,P1)

	Func captured_2 P1
		return QRegularExpressionMatch_captured_2(pObject,GetObjectPointerFromRingObject(P1))

	Func capturedEnd P1
		return QRegularExpressionMatch_capturedEnd(pObject,P1)

	Func capturedEnd_2 P1
		return QRegularExpressionMatch_capturedEnd_2(pObject,GetObjectPointerFromRingObject(P1))

	Func capturedLength P1
		return QRegularExpressionMatch_capturedLength(pObject,P1)

	Func capturedLength_2 P1
		return QRegularExpressionMatch_capturedLength_2(pObject,GetObjectPointerFromRingObject(P1))

	Func capturedRef P1
		pTempObj = new QStringRef
		pTempObj.pObject = QRegularExpressionMatch_capturedRef(pObject,P1)
		return pTempObj

	Func capturedRef_2 P1
		pTempObj = new QStringRef
		pTempObj.pObject = QRegularExpressionMatch_capturedRef_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func capturedStart P1
		return QRegularExpressionMatch_capturedStart(pObject,P1)

	Func capturedStart_2 P1
		return QRegularExpressionMatch_capturedStart_2(pObject,GetObjectPointerFromRingObject(P1))

	Func capturedTexts 
		pTempObj = new QStringList
		pTempObj.pObject = QRegularExpressionMatch_capturedTexts(pObject)
		return pTempObj

	Func hasMatch 
		return QRegularExpressionMatch_hasMatch(pObject)

	Func hasPartialMatch 
		return QRegularExpressionMatch_hasPartialMatch(pObject)

	Func isValid 
		return QRegularExpressionMatch_isValid(pObject)

	Func lastCapturedIndex 
		return QRegularExpressionMatch_lastCapturedIndex(pObject)

	Func matchOptions 
		return QRegularExpressionMatch_matchOptions(pObject)

	Func matchType 
		return QRegularExpressionMatch_matchType(pObject)

	Func regularExpression 
		pTempObj = new QRegularExpression
		pTempObj.pObject = QRegularExpressionMatch_regularExpression(pObject)
		return pTempObj

	Func swap P1
		return QRegularExpressionMatch_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QRegularExpressionMatchIterator

	pObject

	Func init 
		pObject = QRegularExpressionMatchIterator_new()
		return self

	Func delete
		pObject = QRegularExpressionMatchIterator_delete(pObject)

	Func ObjectPointer
		return pObject

	Func hasNext 
		return QRegularExpressionMatchIterator_hasNext(pObject)

	Func isValid 
		return QRegularExpressionMatchIterator_isValid(pObject)

	Func matchOptions 
		return QRegularExpressionMatchIterator_matchOptions(pObject)

	Func matchType 
		return QRegularExpressionMatchIterator_matchType(pObject)

	Func nextitem 
		pTempObj = new QRegularExpressionMatch
		pTempObj.pObject = QRegularExpressionMatchIterator_next(pObject)
		return pTempObj

	Func peekNext 
		pTempObj = new QRegularExpressionMatch
		pTempObj.pObject = QRegularExpressionMatchIterator_peekNext(pObject)
		return pTempObj

	Func regularExpression 
		pTempObj = new QRegularExpression
		pTempObj.pObject = QRegularExpressionMatchIterator_regularExpression(pObject)
		return pTempObj

	Func swap P1
		return QRegularExpressionMatchIterator_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QJsonArray

	pObject

	Func init 
		pObject = QJsonArray_new()
		return self

	Func delete
		pObject = QJsonArray_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		return QJsonArray_append(pObject,GetObjectPointerFromRingObject(P1))

	Func at P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_at(pObject,P1)
		return pTempObj

	Func contains P1
		return QJsonArray_contains(pObject,GetObjectPointerFromRingObject(P1))

	Func count 
		return QJsonArray_count(pObject)

	Func empty 
		return QJsonArray_empty(pObject)

	Func first 
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_first(pObject)
		return pTempObj

	Func insert P1,P2
		return QJsonArray_insert(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isEmpty 
		return QJsonArray_isEmpty(pObject)

	Func last 
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_last(pObject)
		return pTempObj

	Func pop_back 
		return QJsonArray_pop_back(pObject)

	Func pop_front 
		return QJsonArray_pop_front(pObject)

	Func prepend P1
		return QJsonArray_prepend(pObject,GetObjectPointerFromRingObject(P1))

	Func push_back P1
		return QJsonArray_push_back(pObject,GetObjectPointerFromRingObject(P1))

	Func push_front P1
		return QJsonArray_push_front(pObject,GetObjectPointerFromRingObject(P1))

	Func removeAt P1
		return QJsonArray_removeAt(pObject,P1)

	Func removeFirst 
		return QJsonArray_removeFirst(pObject)

	Func removeLast 
		return QJsonArray_removeLast(pObject)

	Func replace P1,P2
		return QJsonArray_replace(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func size 
		return QJsonArray_size(pObject)

	Func takeAt P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonArray_takeAt(pObject,P1)
		return pTempObj

	Func toVariantList 
		return QJsonArray_toVariantList(pObject)

	Func fromStringList P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonArray_fromStringList(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func fromVariantList P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonArray_fromVariantList(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonDocument

	pObject

	Func init 
		pObject = QJsonDocument_new()
		return self

	Func delete
		pObject = QJsonDocument_delete(pObject)

	Func ObjectPointer
		return pObject

	Func array 
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonDocument_array(pObject)
		return pTempObj

	Func isArray 
		return QJsonDocument_isArray(pObject)

	Func isEmpty 
		return QJsonDocument_isEmpty(pObject)

	Func isNull 
		return QJsonDocument_isNull(pObject)

	Func isObject 
		return QJsonDocument_isObject(pObject)

	Func object 
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonDocument_object(pObject)
		return pTempObj

	Func rawData P1
		return QJsonDocument_rawData(pObject,GetObjectPointerFromRingObject(P1))

	Func setArray P1
		return QJsonDocument_setArray(pObject,GetObjectPointerFromRingObject(P1))

	Func setObject P1
		return QJsonDocument_setObject(pObject,GetObjectPointerFromRingObject(P1))

	Func toBinaryData 
		pTempObj = new QByteArray
		pTempObj.pObject = QJsonDocument_toBinaryData(pObject)
		return pTempObj

	Func toJson P1
		pTempObj = new QByteArray
		pTempObj.pObject = QJsonDocument_toJson(pObject,P1)
		return pTempObj

	Func toVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QJsonDocument_toVariant(pObject)
		return pTempObj

	Func fromBinaryData P1,P2
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromBinaryData(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func fromJson P1,P2
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromJson(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func fromRawData P1,P2,P3
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromRawData(pObject,P1,P2,P3)
		return pTempObj

	Func fromVariant P1
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromVariant(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonObject

	pObject

	Func init 
		pObject = QJsonObject_new()
		return self

	Func delete
		pObject = QJsonObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func contains P1
		return QJsonObject_contains(pObject,P1)

	Func count 
		return QJsonObject_count(pObject)

	Func empty 
		return QJsonObject_empty(pObject)

	Func isEmpty 
		return QJsonObject_isEmpty(pObject)

	Func keys 
		pTempObj = new QStringList
		pTempObj.pObject = QJsonObject_keys(pObject)
		return pTempObj

	Func length 
		return QJsonObject_length(pObject)

	Func remove P1
		return QJsonObject_remove(pObject,P1)

	Func size 
		return QJsonObject_size(pObject)

	Func take P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonObject_take(pObject,P1)
		return pTempObj

	Func toVariantMap 
		return QJsonObject_toVariantMap(pObject)

	Func value P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonObject_value(pObject,P1)
		return pTempObj

	Func fromVariantMap P1
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonObject_fromVariantMap(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QJsonParseError

	pObject

	Func init 
		pObject = QJsonParseError_new()
		return self

	Func delete
		pObject = QJsonParseError_delete(pObject)

	Func ObjectPointer
		return pObject

	Func errorString 
		return QJsonParseError_errorString(pObject)

Class QJsonValue

	pObject

	Func init 
		pObject = QJsonValue_new()
		return self

	Func delete
		pObject = QJsonValue_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isArray 
		return QJsonValue_isArray(pObject)

	Func isBool 
		return QJsonValue_isBool(pObject)

	Func isDouble 
		return QJsonValue_isDouble(pObject)

	Func isNull 
		return QJsonValue_isNull(pObject)

	Func isObject 
		return QJsonValue_isObject(pObject)

	Func isString 
		return QJsonValue_isString(pObject)

	Func isUndefined 
		return QJsonValue_isUndefined(pObject)

	Func toArray P1
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonValue_toArray(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func toArray_2 
		pTempObj = new QJsonArray
		pTempObj.pObject = QJsonValue_toArray_2(pObject)
		return pTempObj

	Func toBool P1
		return QJsonValue_toBool(pObject,P1)

	Func toDouble P1
		return QJsonValue_toDouble(pObject,P1)

	Func toInt P1
		return QJsonValue_toInt(pObject,P1)

	Func toObject P1
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonValue_toObject(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func toObject_2 
		pTempObj = new QJsonObject
		pTempObj.pObject = QJsonValue_toObject_2(pObject)
		return pTempObj

	Func toString P1
		return QJsonValue_toString(pObject,P1)

	Func toVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QJsonValue_toVariant(pObject)
		return pTempObj

	Func type 
		return QJsonValue_type(pObject)

	Func fromVariant P1
		pTempObj = new QJsonValue
		pTempObj.pObject = QJsonValue_fromVariant(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QPlainTextEdit from QAbstractScrollArea

	pObject

	Func init P1
		pObject = QPlainTextEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QPlainTextEdit_delete(pObject)

	Func ObjectPointer
		return pObject

	Func anchorAt P1
		return QPlainTextEdit_anchorAt(pObject,GetObjectPointerFromRingObject(P1))

	Func backgroundVisible 
		return QPlainTextEdit_backgroundVisible(pObject)

	Func blockCount 
		return QPlainTextEdit_blockCount(pObject)

	Func canPaste 
		return QPlainTextEdit_canPaste(pObject)

	Func centerOnScroll 
		return QPlainTextEdit_centerOnScroll(pObject)

	Func createStandardContextMenu 
		pTempObj = new QMenu
		pTempObj.pObject = QPlainTextEdit_createStandardContextMenu(pObject)
		return pTempObj

	Func currentCharFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QPlainTextEdit_currentCharFormat(pObject)
		return pTempObj

	Func cursorForPosition P1
		pTempObj = new QTextCursor
		pTempObj.pObject = QPlainTextEdit_cursorForPosition(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func cursorRect P1
		pTempObj = new QRect
		pTempObj.pObject = QPlainTextEdit_cursorRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func cursorRect_2 
		pTempObj = new QRect
		pTempObj.pObject = QPlainTextEdit_cursorRect_2(pObject)
		return pTempObj

	Func cursorWidth 
		return QPlainTextEdit_cursorWidth(pObject)

	Func document 
		pTempObj = new QTextDocument
		pTempObj.pObject = QPlainTextEdit_document(pObject)
		return pTempObj

	Func documentTitle 
		return QPlainTextEdit_documentTitle(pObject)

	Func ensureCursorVisible 
		return QPlainTextEdit_ensureCursorVisible(pObject)

	Func extraSelections 
		return QPlainTextEdit_extraSelections(pObject)

	Func find P1,P2
		return QPlainTextEdit_find(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isReadOnly 
		return QPlainTextEdit_isReadOnly(pObject)

	Func isUndoRedoEnabled 
		return QPlainTextEdit_isUndoRedoEnabled(pObject)

	Func lineWrapMode 
		return QPlainTextEdit_lineWrapMode(pObject)

	Func maximumBlockCount 
		return QPlainTextEdit_maximumBlockCount(pObject)

	Func mergeCurrentCharFormat P1
		return QPlainTextEdit_mergeCurrentCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func moveCursor P1,P2
		return QPlainTextEdit_moveCursor(pObject,P1,P2)

	Func overwriteMode 
		return QPlainTextEdit_overwriteMode(pObject)

	Func print P1
		return QPlainTextEdit_print(pObject,GetObjectPointerFromRingObject(P1))

	Func setBackgroundVisible P1
		return QPlainTextEdit_setBackgroundVisible(pObject,P1)

	Func setCenterOnScroll P1
		return QPlainTextEdit_setCenterOnScroll(pObject,P1)

	Func setCurrentCharFormat P1
		return QPlainTextEdit_setCurrentCharFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setCursorWidth P1
		return QPlainTextEdit_setCursorWidth(pObject,P1)

	Func setDocument P1
		return QPlainTextEdit_setDocument(pObject,GetObjectPointerFromRingObject(P1))

	Func setDocumentTitle P1
		return QPlainTextEdit_setDocumentTitle(pObject,P1)

	Func setExtraSelections P1
		return QPlainTextEdit_setExtraSelections(pObject,GetObjectPointerFromRingObject(P1))

	Func setLineWrapMode P1
		return QPlainTextEdit_setLineWrapMode(pObject,P1)

	Func setMaximumBlockCount P1
		return QPlainTextEdit_setMaximumBlockCount(pObject,P1)

	Func setOverwriteMode P1
		return QPlainTextEdit_setOverwriteMode(pObject,P1)

	Func setReadOnly P1
		return QPlainTextEdit_setReadOnly(pObject,P1)

	Func setTabChangesFocus P1
		return QPlainTextEdit_setTabChangesFocus(pObject,P1)

	Func setTabStopWidth P1
		return QPlainTextEdit_setTabStopWidth(pObject,P1)

	Func setTextCursor P1
		return QPlainTextEdit_setTextCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setTextInteractionFlags P1
		return QPlainTextEdit_setTextInteractionFlags(pObject,GetObjectPointerFromRingObject(P1))

	Func setUndoRedoEnabled P1
		return QPlainTextEdit_setUndoRedoEnabled(pObject,P1)

	Func setWordWrapMode P1
		return QPlainTextEdit_setWordWrapMode(pObject,P1)

	Func tabChangesFocus 
		return QPlainTextEdit_tabChangesFocus(pObject)

	Func tabStopWidth 
		return QPlainTextEdit_tabStopWidth(pObject)

	Func textCursor 
		pTempObj = new QTextCursor
		pTempObj.pObject = QPlainTextEdit_textCursor(pObject)
		return pTempObj

	Func textInteractionFlags 
		return QPlainTextEdit_textInteractionFlags(pObject)

	Func toPlainText 
		return QPlainTextEdit_toPlainText(pObject)

	Func wordWrapMode 
		return QPlainTextEdit_wordWrapMode(pObject)

	Func appendHtml P1
		return QPlainTextEdit_appendHtml(pObject,P1)

	Func appendPlainText P1
		return QPlainTextEdit_appendPlainText(pObject,P1)

	Func centerCursor 
		return QPlainTextEdit_centerCursor(pObject)

	Func clear 
		return QPlainTextEdit_clear(pObject)

	Func copy 
		return QPlainTextEdit_copy(pObject)

	Func cut 
		return QPlainTextEdit_cut(pObject)

	Func insertPlainText P1
		return QPlainTextEdit_insertPlainText(pObject,P1)

	Func paste 
		return QPlainTextEdit_paste(pObject)

	Func redo 
		return QPlainTextEdit_redo(pObject)

	Func selectAll 
		return QPlainTextEdit_selectAll(pObject)

	Func setPlainText P1
		return QPlainTextEdit_setPlainText(pObject,P1)

	Func undo 
		return QPlainTextEdit_undo(pObject)

	Func zoomIn P1
		return QPlainTextEdit_zoomIn(pObject,P1)

	Func zoomOut P1
		return QPlainTextEdit_zoomOut(pObject,P1)

	Func setblockCountChangedEvent P1
		return QPlainTextEdit_setblockCountChangedEvent(pObject,P1)

	Func setcopyAvailableEvent P1
		return QPlainTextEdit_setcopyAvailableEvent(pObject,P1)

	Func setcursorPositionChangedEvent P1
		return QPlainTextEdit_setcursorPositionChangedEvent(pObject,P1)

	Func setmodificationChangedEvent P1
		return QPlainTextEdit_setmodificationChangedEvent(pObject,P1)

	Func setredoAvailableEvent P1
		return QPlainTextEdit_setredoAvailableEvent(pObject,P1)

	Func setselectionChangedEvent P1
		return QPlainTextEdit_setselectionChangedEvent(pObject,P1)

	Func settextChangedEvent P1
		return QPlainTextEdit_settextChangedEvent(pObject,P1)

	Func setundoAvailableEvent P1
		return QPlainTextEdit_setundoAvailableEvent(pObject,P1)

	Func setupdateRequestEvent P1
		return QPlainTextEdit_setupdateRequestEvent(pObject,P1)

	Func getblockCountChangedEvent 
		return QPlainTextEdit_getblockCountChangedEvent(pObject)

	Func getcopyAvailableEvent 
		return QPlainTextEdit_getcopyAvailableEvent(pObject)

	Func getcursorPositionChangedEvent 
		return QPlainTextEdit_getcursorPositionChangedEvent(pObject)

	Func getmodificationChangedEvent 
		return QPlainTextEdit_getmodificationChangedEvent(pObject)

	Func getredoAvailableEvent 
		return QPlainTextEdit_getredoAvailableEvent(pObject)

	Func getselectionChangedEvent 
		return QPlainTextEdit_getselectionChangedEvent(pObject)

	Func gettextChangedEvent 
		return QPlainTextEdit_gettextChangedEvent(pObject)

	Func getundoAvailableEvent 
		return QPlainTextEdit_getundoAvailableEvent(pObject)

	Func getupdateRequestEvent 
		return QPlainTextEdit_getupdateRequestEvent(pObject)

	Func cyanline 
		return QPlainTextEdit_cyanline(pObject)

	Func setactivelinecolor P1
		return QPlainTextEdit_setactivelinecolor(pObject,GetObjectPointerFromRingObject(P1))

Class CodeEditor from QPlainTextEdit

	pObject

	Func init P1
		pObject = CodeEditor_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = CodeEditor_delete(pObject)

	Func ObjectPointer
		return pObject

	Func setCompleter P1
		return CodeEditor_setCompleter(pObject,GetObjectPointerFromRingObject(P1))

	Func completer 
		pTempObj = new QCompleter
		pTempObj.pObject = CodeEditor_completer(pObject)
		return pTempObj

	Func setLineNumbersAreaColor P1
		return CodeEditor_setLineNumbersAreaColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setLineNumbersAreaBackColor P1
		return CodeEditor_setLineNumbersAreaBackColor(pObject,GetObjectPointerFromRingObject(P1))

Class QGridLayout

	pObject

	Func init 
		pObject = QGridLayout_new()
		return self

	Func delete
		pObject = QGridLayout_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addItem P1,P2,P3,P4,P5,P6
		return QGridLayout_addItem(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5,P6)

	Func addLayout P1,P2,P3,P4
		return QGridLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func addLayout_2 P1,P2,P3,P4,P5,P6
		return QGridLayout_addLayout_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5,P6)

	Func addWidget P1,P2,P3,P4
		return QGridLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4)

	Func addWidget_2 P1,P2,P3,P4,P5,P6
		return QGridLayout_addWidget_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,P5,P6)

	Func cellRect P1,P2
		pTempObj = new QRect
		pTempObj.pObject = QGridLayout_cellRect(pObject,P1,P2)
		return pTempObj

	Func columnCount 
		return QGridLayout_columnCount(pObject)

	Func columnMinimumWidth P1
		return QGridLayout_columnMinimumWidth(pObject,P1)

	Func columnStretch P1
		return QGridLayout_columnStretch(pObject,P1)

	Func getItemPosition P1,P2,P3,P4,P5
		return QGridLayout_getItemPosition(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func horizontalSpacing 
		return QGridLayout_horizontalSpacing(pObject)

	Func itemAtPosition P1,P2
		return QGridLayout_itemAtPosition(pObject,P1,P2)

	Func originCorner 
		return QGridLayout_originCorner(pObject)

	Func rowCount 
		return QGridLayout_rowCount(pObject)

	Func rowMinimumHeight P1
		return QGridLayout_rowMinimumHeight(pObject,P1)

	Func rowStretch P1
		return QGridLayout_rowStretch(pObject,P1)

	Func setColumnMinimumWidth P1,P2
		return QGridLayout_setColumnMinimumWidth(pObject,P1,P2)

	Func setColumnStretch P1,P2
		return QGridLayout_setColumnStretch(pObject,P1,P2)

	Func setHorizontalSpacing P1
		return QGridLayout_setHorizontalSpacing(pObject,P1)

	Func setOriginCorner P1
		return QGridLayout_setOriginCorner(pObject,P1)

	Func setRowMinimumHeight P1,P2
		return QGridLayout_setRowMinimumHeight(pObject,P1,P2)

	Func setRowStretch P1,P2
		return QGridLayout_setRowStretch(pObject,P1,P2)

	Func setSpacing P1
		return QGridLayout_setSpacing(pObject,P1)

	Func setVerticalSpacing P1
		return QGridLayout_setVerticalSpacing(pObject,P1)

	Func spacing 
		return QGridLayout_spacing(pObject)

	Func verticalSpacing 
		return QGridLayout_verticalSpacing(pObject)

Class QTextCharFormat

	pObject

	Func init 
		pObject = QTextCharFormat_new()
		return self

	Func delete
		pObject = QTextCharFormat_delete(pObject)

	Func ObjectPointer
		return pObject

	Func anchorHref 
		return QTextCharFormat_anchorHref(pObject)

	Func anchorNames 
		pTempObj = new QStringList
		pTempObj.pObject = QTextCharFormat_anchorNames(pObject)
		return pTempObj

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QTextCharFormat_font(pObject)
		return pTempObj

	Func fontCapitalization 
		return QTextCharFormat_fontCapitalization(pObject)

	Func fontFamily 
		return QTextCharFormat_fontFamily(pObject)

	Func fontFixedPitch 
		return QTextCharFormat_fontFixedPitch(pObject)

	Func fontHintingPreference 
		return QTextCharFormat_fontHintingPreference(pObject)

	Func fontItalic 
		return QTextCharFormat_fontItalic(pObject)

	Func fontKerning 
		return QTextCharFormat_fontKerning(pObject)

	Func fontLetterSpacing 
		return QTextCharFormat_fontLetterSpacing(pObject)

	Func fontLetterSpacingType 
		return QTextCharFormat_fontLetterSpacingType(pObject)

	Func fontOverline 
		return QTextCharFormat_fontOverline(pObject)

	Func fontPointSize 
		return QTextCharFormat_fontPointSize(pObject)

	Func fontStretch 
		return QTextCharFormat_fontStretch(pObject)

	Func fontStrikeOut 
		return QTextCharFormat_fontStrikeOut(pObject)

	Func fontStyleHint 
		return QTextCharFormat_fontStyleHint(pObject)

	Func fontStyleStrategy 
		return QTextCharFormat_fontStyleStrategy(pObject)

	Func fontUnderline 
		return QTextCharFormat_fontUnderline(pObject)

	Func fontWeight 
		return QTextCharFormat_fontWeight(pObject)

	Func fontWordSpacing 
		return QTextCharFormat_fontWordSpacing(pObject)

	Func isAnchor 
		return QTextCharFormat_isAnchor(pObject)

	Func isValid 
		return QTextCharFormat_isValid(pObject)

	Func setAnchor P1
		return QTextCharFormat_setAnchor(pObject,P1)

	Func setAnchorHref P1
		return QTextCharFormat_setAnchorHref(pObject,P1)

	Func setAnchorNames P1
		return QTextCharFormat_setAnchorNames(pObject,GetObjectPointerFromRingObject(P1))

	Func setFont_2 P1
		return QTextCharFormat_setFont_2(pObject,GetObjectPointerFromRingObject(P1))

	Func setFontCapitalization P1
		return QTextCharFormat_setFontCapitalization(pObject,P1)

	Func setFontFamily P1
		return QTextCharFormat_setFontFamily(pObject,P1)

	Func setFontFixedPitch P1
		return QTextCharFormat_setFontFixedPitch(pObject,P1)

	Func setFontHintingPreference P1
		return QTextCharFormat_setFontHintingPreference(pObject,P1)

	Func setFontItalic P1
		return QTextCharFormat_setFontItalic(pObject,P1)

	Func setFontKerning P1
		return QTextCharFormat_setFontKerning(pObject,P1)

	Func setFontLetterSpacing P1
		return QTextCharFormat_setFontLetterSpacing(pObject,P1)

	Func setFontLetterSpacingType P1
		return QTextCharFormat_setFontLetterSpacingType(pObject,P1)

	Func setFontOverline P1
		return QTextCharFormat_setFontOverline(pObject,P1)

	Func setFontPointSize P1
		return QTextCharFormat_setFontPointSize(pObject,P1)

	Func setFontStretch P1
		return QTextCharFormat_setFontStretch(pObject,P1)

	Func setFontStrikeOut P1
		return QTextCharFormat_setFontStrikeOut(pObject,P1)

	Func setFontStyleHint P1,P2
		return QTextCharFormat_setFontStyleHint(pObject,P1,P2)

	Func setFontStyleStrategy P1
		return QTextCharFormat_setFontStyleStrategy(pObject,P1)

	Func setFontUnderline P1
		return QTextCharFormat_setFontUnderline(pObject,P1)

	Func setFontWeight P1
		return QTextCharFormat_setFontWeight(pObject,P1)

	Func setFontWordSpacing P1
		return QTextCharFormat_setFontWordSpacing(pObject,P1)

	Func setTextOutline P1
		return QTextCharFormat_setTextOutline(pObject,GetObjectPointerFromRingObject(P1))

	Func setToolTip P1
		return QTextCharFormat_setToolTip(pObject,P1)

	Func setUnderlineColor P1
		return QTextCharFormat_setUnderlineColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setUnderlineStyle P1
		return QTextCharFormat_setUnderlineStyle(pObject,P1)

	Func setVerticalAlignment P1
		return QTextCharFormat_setVerticalAlignment(pObject,P1)

	Func textOutline 
		pTempObj = new QPen
		pTempObj.pObject = QTextCharFormat_textOutline(pObject)
		return pTempObj

	Func toolTip 
		return QTextCharFormat_toolTip(pObject)

	Func underlineColor 
		pTempObj = new QColor
		pTempObj.pObject = QTextCharFormat_underlineColor(pObject)
		return pTempObj

	Func underlineStyle 
		return QTextCharFormat_underlineStyle(pObject)

	Func verticalAlignment 
		return QTextCharFormat_verticalAlignment(pObject)

Class QGraphicsVideoItem

	pObject

	Func init 
		pObject = QGraphicsVideoItem_new()
		return self

	Func delete
		pObject = QGraphicsVideoItem_delete(pObject)

	Func ObjectPointer
		return pObject

	Func aspectRatioMode 
		return QGraphicsVideoItem_aspectRatioMode(pObject)

	Func nativeSize 
		return QGraphicsVideoItem_nativeSize(pObject)

	Func offset 
		pTempObj = new QPointF
		pTempObj.pObject = QGraphicsVideoItem_offset(pObject)
		return pTempObj

	Func setAspectRatioMode P1
		return QGraphicsVideoItem_setAspectRatioMode(pObject,P1)

	Func setOffset P1
		return QGraphicsVideoItem_setOffset(pObject,GetObjectPointerFromRingObject(P1))

	Func setSize P1
		return QGraphicsVideoItem_setSize(pObject,GetObjectPointerFromRingObject(P1))

	Func size 
		return QGraphicsVideoItem_size(pObject)

Class QCamera from QMediaObject

	pObject

	Func init 
		pObject = QCamera_new()
		return self

	Func delete
		pObject = QCamera_delete(pObject)

	Func ObjectPointer
		return pObject

	Func captureMode 
		return QCamera_captureMode(pObject)

	Func error 
		return QCamera_error(pObject)

	Func errorString 
		return QCamera_errorString(pObject)

	Func exposure 
		return QCamera_exposure(pObject)

	Func focus 
		return QCamera_focus(pObject)

	Func imageProcessing 
		return QCamera_imageProcessing(pObject)

	Func isCaptureModeSupported P1
		return QCamera_isCaptureModeSupported(pObject,P1)

	Func lockStatus 
		return QCamera_lockStatus(pObject)

	Func lockStatus_2 P1
		return QCamera_lockStatus_2(pObject,P1)

	Func requestedLocks 
		return QCamera_requestedLocks(pObject)

	Func setViewfinder P1
		return QCamera_setViewfinder(pObject,GetObjectPointerFromRingObject(P1))

	Func setViewfinder_2 P1
		return QCamera_setViewfinder_2(pObject,GetObjectPointerFromRingObject(P1))

	Func setViewfinder_3 P1
		return QCamera_setViewfinder_3(pObject,GetObjectPointerFromRingObject(P1))

	Func state 
		return QCamera_state(pObject)

	Func status 
		return QCamera_status(pObject)

	Func supportedLocks 
		return QCamera_supportedLocks(pObject)

	Func loadcamera 
		return QCamera_load(pObject)

	Func searchAndLock 
		return QCamera_searchAndLock(pObject)

	Func searchAndLock_2 P1
		return QCamera_searchAndLock_2(pObject,P1)

	Func setCaptureMode P1
		return QCamera_setCaptureMode(pObject,P1)

	Func start 
		return QCamera_start(pObject)

	Func stop 
		return QCamera_stop(pObject)

	Func unload 
		return QCamera_unload(pObject)

	Func unlock 
		return QCamera_unlock(pObject)

	Func unlock_2 P1
		return QCamera_unlock_2(pObject,P1)

Class QCameraImageCapture

	pObject

	Func init P1
		pObject = QCameraImageCapture_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QCameraImageCapture_delete(pObject)

	Func ObjectPointer
		return pObject

	Func availability 
		return QCameraImageCapture_availability(pObject)

	Func bufferFormat 
		return QCameraImageCapture_bufferFormat(pObject)

	Func captureDestination 
		return QCameraImageCapture_captureDestination(pObject)

	Func encodingSettings 
		return QCameraImageCapture_encodingSettings(pObject)

	Func error 
		return QCameraImageCapture_error(pObject)

	Func errorString 
		return QCameraImageCapture_errorString(pObject)

	Func imageCodecDescription P1
		return QCameraImageCapture_imageCodecDescription(pObject,P1)

	Func isAvailable 
		return QCameraImageCapture_isAvailable(pObject)

	Func isCaptureDestinationSupported P1
		return QCameraImageCapture_isCaptureDestinationSupported(pObject,P1)

	Func isReadyForCapture 
		return QCameraImageCapture_isReadyForCapture(pObject)

	Func setBufferFormat P1
		return QCameraImageCapture_setBufferFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setCaptureDestination P1
		return QCameraImageCapture_setCaptureDestination(pObject,P1)

	Func setEncodingSettings P1
		return QCameraImageCapture_setEncodingSettings(pObject,GetObjectPointerFromRingObject(P1))

	Func supportedBufferFormats 
		return QCameraImageCapture_supportedBufferFormats(pObject)

	Func supportedImageCodecs 
		pTempObj = new QStringList
		pTempObj.pObject = QCameraImageCapture_supportedImageCodecs(pObject)
		return pTempObj

	Func supportedResolutions P1,P2
		return QCameraImageCapture_supportedResolutions(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func cancelCapture 
		return QCameraImageCapture_cancelCapture(pObject)

	Func capture P1
		return QCameraImageCapture_capture(pObject,P1)

Class QMediaObject from QWidget

	pObject

	Func init 
		pObject = QMediaObject_new()
		return self

	Func delete
		pObject = QMediaObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func availableMetaData 
		pTempObj = new QStringList
		pTempObj.pObject = QMediaObject_availableMetaData(pObject)
		return pTempObj

	Func isMetaDataAvailable 
		return QMediaObject_isMetaDataAvailable(pObject)

	Func metaData P1
		pTempObj = new QVariant
		pTempObj.pObject = QMediaObject_metaData(pObject,P1)
		return pTempObj

	Func notifyInterval 
		return QMediaObject_notifyInterval(pObject)

	Func setNotifyInterval P1
		return QMediaObject_setNotifyInterval(pObject,P1)

Class QHeaderView from QAbstractItemView

	pObject

	Func init P1,P2
		pObject = QHeaderView_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QHeaderView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func cascadingSectionResizes 
		return QHeaderView_cascadingSectionResizes(pObject)

	Func count 
		return QHeaderView_count(pObject)

	Func defaultAlignment 
		return QHeaderView_defaultAlignment(pObject)

	Func defaultSectionSize 
		return QHeaderView_defaultSectionSize(pObject)

	Func hiddenSectionCount 
		return QHeaderView_hiddenSectionCount(pObject)

	Func hideSection P1
		return QHeaderView_hideSection(pObject,P1)

	Func highlightSections 
		return QHeaderView_highlightSections(pObject)

	Func isSectionHidden P1
		return QHeaderView_isSectionHidden(pObject,P1)

	Func isSortIndicatorShown 
		return QHeaderView_isSortIndicatorShown(pObject)

	Func length 
		return QHeaderView_length(pObject)

	Func logicalIndex P1
		return QHeaderView_logicalIndex(pObject,P1)

	Func logicalIndexAt P1
		return QHeaderView_logicalIndexAt(pObject,P1)

	Func logicalIndexAt_2 P1,P2
		return QHeaderView_logicalIndexAt_2(pObject,P1,P2)

	Func logicalIndexAt_3 P1
		return QHeaderView_logicalIndexAt_3(pObject,GetObjectPointerFromRingObject(P1))

	Func maximumSectionSize 
		return QHeaderView_maximumSectionSize(pObject)

	Func minimumSectionSize_2 
		return QHeaderView_minimumSectionSize_2(pObject)

	Func moveSection P1,P2
		return QHeaderView_moveSection(pObject,P1,P2)

	Func offset 
		return QHeaderView_offset(pObject)

	Func orientation 
		return QHeaderView_orientation(pObject)

	Func resizeContentsPrecision 
		return QHeaderView_resizeContentsPrecision(pObject)

	Func resizeSection P1,P2
		return QHeaderView_resizeSection(pObject,P1,P2)

	Func resizeSections P1
		return QHeaderView_resizeSections(pObject,P1)

	Func restoreState P1
		return QHeaderView_restoreState(pObject,GetObjectPointerFromRingObject(P1))

	Func saveState 
		pTempObj = new QByteArray
		pTempObj.pObject = QHeaderView_saveState(pObject)
		return pTempObj

	Func sectionPosition P1
		return QHeaderView_sectionPosition(pObject,P1)

	Func sectionResizeMode P1
		return QHeaderView_sectionResizeMode(pObject,P1)

	Func sectionSize P1
		return QHeaderView_sectionSize(pObject,P1)

	Func sectionSizeHint P1
		return QHeaderView_sectionSizeHint(pObject,P1)

	Func sectionViewportPosition P1
		return QHeaderView_sectionViewportPosition(pObject,P1)

	Func sectionsClickable 
		return QHeaderView_sectionsClickable(pObject)

	Func sectionsHidden 
		return QHeaderView_sectionsHidden(pObject)

	Func sectionsMovable 
		return QHeaderView_sectionsMovable(pObject)

	Func sectionsMoved 
		return QHeaderView_sectionsMoved(pObject)

	Func setCascadingSectionResizes P1
		return QHeaderView_setCascadingSectionResizes(pObject,P1)

	Func setDefaultAlignment P1
		return QHeaderView_setDefaultAlignment(pObject,P1)

	Func setDefaultSectionSize P1
		return QHeaderView_setDefaultSectionSize(pObject,P1)

	Func setHighlightSections P1
		return QHeaderView_setHighlightSections(pObject,P1)

	Func setMaximumSectionSize P1
		return QHeaderView_setMaximumSectionSize(pObject,P1)

	Func setMinimumSectionSize P1
		return QHeaderView_setMinimumSectionSize(pObject,P1)

	Func setResizeContentsPrecision P1
		return QHeaderView_setResizeContentsPrecision(pObject,P1)

	Func setSectionHidden P1,P2
		return QHeaderView_setSectionHidden(pObject,P1,P2)

	Func setSectionResizeMode P1
		return QHeaderView_setSectionResizeMode(pObject,P1)

	Func setSectionResizeMode_2 P1,P2
		return QHeaderView_setSectionResizeMode_2(pObject,P1,P2)

	Func setSectionsClickable P1
		return QHeaderView_setSectionsClickable(pObject,P1)

	Func setSectionsMovable P1
		return QHeaderView_setSectionsMovable(pObject,P1)

	Func setSortIndicator P1,P2
		return QHeaderView_setSortIndicator(pObject,P1,P2)

	Func setSortIndicatorShown P1
		return QHeaderView_setSortIndicatorShown(pObject,P1)

	Func setStretchLastSection P1
		return QHeaderView_setStretchLastSection(pObject,P1)

	Func showSection P1
		return QHeaderView_showSection(pObject,P1)

	Func sortIndicatorOrder 
		return QHeaderView_sortIndicatorOrder(pObject)

	Func sortIndicatorSection 
		return QHeaderView_sortIndicatorSection(pObject)

	Func stretchLastSection 
		return QHeaderView_stretchLastSection(pObject)

	Func stretchSectionCount 
		return QHeaderView_stretchSectionCount(pObject)

	Func swapSections P1,P2
		return QHeaderView_swapSections(pObject,P1,P2)

	Func visualIndex P1
		return QHeaderView_visualIndex(pObject,P1)

	Func visualIndexAt P1
		return QHeaderView_visualIndexAt(pObject,P1)

	Func headerDataChanged P1,P2,P3
		return QHeaderView_headerDataChanged(pObject,P1,P2,P3)

	Func setOffset P1
		return QHeaderView_setOffset(pObject,P1)

	Func setOffsetToLastSection 
		return QHeaderView_setOffsetToLastSection(pObject)

	Func setOffsetToSectionPosition P1
		return QHeaderView_setOffsetToSectionPosition(pObject,P1)

	Func setgeometriesChangedEvent P1
		return QHeaderView_setgeometriesChangedEvent(pObject,P1)

	Func setsectionClickedEvent P1
		return QHeaderView_setsectionClickedEvent(pObject,P1)

	Func setsectionCountChangedEvent P1
		return QHeaderView_setsectionCountChangedEvent(pObject,P1)

	Func setsectionDoubleClickedEvent P1
		return QHeaderView_setsectionDoubleClickedEvent(pObject,P1)

	Func setsectionEnteredEvent P1
		return QHeaderView_setsectionEnteredEvent(pObject,P1)

	Func setsectionHandleDoubleClickedEvent P1
		return QHeaderView_setsectionHandleDoubleClickedEvent(pObject,P1)

	Func setsectionMovedEvent P1
		return QHeaderView_setsectionMovedEvent(pObject,P1)

	Func setsectionPressedEvent P1
		return QHeaderView_setsectionPressedEvent(pObject,P1)

	Func setsectionResizedEvent P1
		return QHeaderView_setsectionResizedEvent(pObject,P1)

	Func setsortIndicatorChangedEvent P1
		return QHeaderView_setsortIndicatorChangedEvent(pObject,P1)

	Func getgeometriesChangedEvent 
		return QHeaderView_getgeometriesChangedEvent(pObject)

	Func getsectionClickedEvent 
		return QHeaderView_getsectionClickedEvent(pObject)

	Func getsectionCountChangedEvent 
		return QHeaderView_getsectionCountChangedEvent(pObject)

	Func getsectionDoubleClickedEvent 
		return QHeaderView_getsectionDoubleClickedEvent(pObject)

	Func getsectionEnteredEvent 
		return QHeaderView_getsectionEnteredEvent(pObject)

	Func getsectionHandleDoubleClickedEvent 
		return QHeaderView_getsectionHandleDoubleClickedEvent(pObject)

	Func getsectionMovedEvent 
		return QHeaderView_getsectionMovedEvent(pObject)

	Func getsectionPressedEvent 
		return QHeaderView_getsectionPressedEvent(pObject)

	Func getsectionResizedEvent 
		return QHeaderView_getsectionResizedEvent(pObject)

	Func getsortIndicatorChangedEvent 
		return QHeaderView_getsortIndicatorChangedEvent(pObject)

	Func geteventparameters 
		return QHeaderView_geteventparameters(pObject)

Class QFontMetrics

	pObject

	Func init P1
		pObject = QFontMetrics_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QFontMetrics_delete(pObject)

	Func ObjectPointer
		return pObject

	Func ascent 
		return QFontMetrics_ascent(pObject)

	Func averageCharWidth 
		return QFontMetrics_averageCharWidth(pObject)

	Func boundingRect P1
		pTempObj = new QRect
		pTempObj.pObject = QFontMetrics_boundingRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func boundingRect_2 P1
		pTempObj = new QRect
		pTempObj.pObject = QFontMetrics_boundingRect_2(pObject,P1)
		return pTempObj

	Func boundingRect_3 P1,P2,P3,P4,P5,P6,P7,P8
		pTempObj = new QRect
		pTempObj.pObject = QFontMetrics_boundingRect_3(pObject,P1,P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8))
		return pTempObj

	Func boundingRect_4 P1,P2,P3,P4,P5
		pTempObj = new QRect
		pTempObj.pObject = QFontMetrics_boundingRect_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3,P4,GetObjectPointerFromRingObject(P5))
		return pTempObj

	Func descent 
		return QFontMetrics_descent(pObject)

	Func elidedText P1,P2,P3,P4
		return QFontMetrics_elidedText(pObject,P1,P2,P3,P4)

	Func height 
		return QFontMetrics_height(pObject)

	Func inFont P1
		return QFontMetrics_inFont(pObject,GetObjectPointerFromRingObject(P1))

	Func inFontUcs4 P1
		return QFontMetrics_inFontUcs4(pObject,GetObjectPointerFromRingObject(P1))

	Func leading 
		return QFontMetrics_leading(pObject)

	Func leftBearing P1
		return QFontMetrics_leftBearing(pObject,GetObjectPointerFromRingObject(P1))

	Func lineSpacing 
		return QFontMetrics_lineSpacing(pObject)

	Func lineWidth 
		return QFontMetrics_lineWidth(pObject)

	Func maxWidth 
		return QFontMetrics_maxWidth(pObject)

	Func minLeftBearing 
		return QFontMetrics_minLeftBearing(pObject)

	Func minRightBearing 
		return QFontMetrics_minRightBearing(pObject)

	Func overlinePos 
		return QFontMetrics_overlinePos(pObject)

	Func rightBearing P1
		return QFontMetrics_rightBearing(pObject,GetObjectPointerFromRingObject(P1))

	Func size P1,P2,P3,P4
		pTempObj = new QSize
		pTempObj.pObject = QFontMetrics_size(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))
		return pTempObj

	Func strikeOutPos 
		return QFontMetrics_strikeOutPos(pObject)

	Func tightBoundingRect P1
		pTempObj = new QRect
		pTempObj.pObject = QFontMetrics_tightBoundingRect(pObject,P1)
		return pTempObj

	Func underlinePos 
		return QFontMetrics_underlinePos(pObject)

	Func width P1,P2
		return QFontMetrics_width(pObject,P1,P2)

	Func width_2 P1
		return QFontMetrics_width_2(pObject,GetObjectPointerFromRingObject(P1))

	Func xHeight 
		return QFontMetrics_xHeight(pObject)

Class QSplashScreen from QWidget

	pObject

	Func init P1
		pObject = QSplashScreen_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSplashScreen_delete(pObject)

	Func ObjectPointer
		return pObject

	Func finish P1
		return QSplashScreen_finish(pObject,GetObjectPointerFromRingObject(P1))

	Func pixmap 
		pTempObj = new QPixmap
		pTempObj.pObject = QSplashScreen_pixmap(pObject)
		return pTempObj

	Func repaint 
		return QSplashScreen_repaint(pObject)

	Func setPixmap P1
		return QSplashScreen_setPixmap(pObject,GetObjectPointerFromRingObject(P1))

	Func clearMessage 
		return QSplashScreen_clearMessage(pObject)

	Func showMessage P1,P2,P3
		return QSplashScreen_showMessage(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

Class QBoxLayout from QLayout

	pObject

	Func init P1,P2
		pObject = QBoxLayout_new(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QBoxLayout_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addLayout P1,P2
		return QBoxLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func addSpacerItem P1
		return QBoxLayout_addSpacerItem(pObject,GetObjectPointerFromRingObject(P1))

	Func addSpacing P1
		return QBoxLayout_addSpacing(pObject,P1)

	Func addStretch P1
		return QBoxLayout_addStretch(pObject,P1)

	Func addStrut P1
		return QBoxLayout_addStrut(pObject,P1)

	Func addWidget P1,P2,P3
		return QBoxLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func direction 
		return QBoxLayout_direction(pObject)

	Func insertLayout P1,P2,P3
		return QBoxLayout_insertLayout(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func insertSpacerItem P1,P2
		return QBoxLayout_insertSpacerItem(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func insertSpacing P1,P2
		return QBoxLayout_insertSpacing(pObject,P1,P2)

	Func insertStretch P1,P2
		return QBoxLayout_insertStretch(pObject,P1,P2)

	Func insertWidget P1,P2,P3,P4
		return QBoxLayout_insertWidget(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setDirection P1
		return QBoxLayout_setDirection(pObject,GetObjectPointerFromRingObject(P1))

	Func setSpacing P1
		return QBoxLayout_setSpacing(pObject,P1)

	Func setStretch P1,P2
		return QBoxLayout_setStretch(pObject,P1,P2)

	Func setStretchFactor P1,P2
		return QBoxLayout_setStretchFactor(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setStretchFactor_2 P1,P2
		return QBoxLayout_setStretchFactor_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func spacing 
		return QBoxLayout_spacing(pObject)

	Func stretch P1
		return QBoxLayout_stretch(pObject,P1)

Class QLayout from QObject

	pObject

	Func init P1
		pObject = QLayout_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QLayout_delete(pObject)

	Func ObjectPointer
		return pObject

	Func activate 
		return QLayout_activate(pObject)

	Func addWidget P1
		return QLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func contentsMargins 
		return QLayout_contentsMargins(pObject)

	Func contentsRect 
		pTempObj = new QRect
		pTempObj.pObject = QLayout_contentsRect(pObject)
		return pTempObj

	Func getContentsMargins P1,P2,P3,P4
		return QLayout_getContentsMargins(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func isEnabled 
		return QLayout_isEnabled(pObject)

	Func menuBar 
		pTempObj = new QWidget
		pTempObj.pObject = QLayout_menuBar(pObject)
		return pTempObj

	Func parentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QLayout_parentWidget(pObject)
		return pTempObj

	Func removeItem P1
		return QLayout_removeItem(pObject,GetObjectPointerFromRingObject(P1))

	Func removeWidget P1
		return QLayout_removeWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setAlignment P1,P2
		return QLayout_setAlignment(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setAlignment_2 P1
		return QLayout_setAlignment_2(pObject,P1)

	Func setAlignment_3 P1,P2
		return QLayout_setAlignment_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setContentsMargins P1,P2,P3,P4
		return QLayout_setContentsMargins(pObject,P1,P2,P3,P4)

	Func setContentsMargins_2 P1
		return QLayout_setContentsMargins_2(pObject,GetObjectPointerFromRingObject(P1))

	Func setEnabled P1
		return QLayout_setEnabled(pObject,P1)

	Func setMenuBar P1
		return QLayout_setMenuBar(pObject,GetObjectPointerFromRingObject(P1))

	Func setSizeConstraint P1
		return QLayout_setSizeConstraint(pObject,P1)

	Func setSpacing P1
		return QLayout_setSpacing(pObject,P1)

	Func sizeConstraint 
		return QLayout_sizeConstraint(pObject)

	Func spacing 
		return QLayout_spacing(pObject)

	Func update 
		return QLayout_update(pObject)

	Func closestAcceptableSize P1,P2
		pTempObj = new QSize
		pTempObj.pObject = QLayout_closestAcceptableSize(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

Class QLinearGradient from QGradient

	pObject

	Func init 
		pObject = QLinearGradient_new()
		return self

	Func delete
		pObject = QLinearGradient_delete(pObject)

	Func ObjectPointer
		return pObject

	Func finalStop 
		pTempObj = new QPointF
		pTempObj.pObject = QLinearGradient_finalStop(pObject)
		return pTempObj

	Func setFinalStop P1
		return QLinearGradient_setFinalStop(pObject,GetObjectPointerFromRingObject(P1))

	Func setFinalStop_2 P1,P2
		return QLinearGradient_setFinalStop_2(pObject,P1,P2)

	Func setStart P1
		return QLinearGradient_setStart(pObject,GetObjectPointerFromRingObject(P1))

	Func setStart_2 P1,P2
		return QLinearGradient_setStart_2(pObject,P1,P2)

	Func start 
		pTempObj = new QPointF
		pTempObj.pObject = QLinearGradient_start(pObject)
		return pTempObj

Class QGradient

	pObject

	Func init 
		pObject = QGradient_new()
		return self

	Func delete
		pObject = QGradient_delete(pObject)

	Func ObjectPointer
		return pObject

	Func coordinateMode 
		return QGradient_coordinateMode(pObject)

	Func setColorAt P1,P2
		return QGradient_setColorAt(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setCoordinateMode P1
		return QGradient_setCoordinateMode(pObject,P1)

	Func setSpread P1
		return QGradient_setSpread(pObject,P1)

	Func setStops P1
		return QGradient_setStops(pObject,GetObjectPointerFromRingObject(P1))

	Func spread 
		return QGradient_spread(pObject)

	Func stops 
		return QGradient_stops(pObject)

	Func type 
		return QGradient_type(pObject)

Class QPointF

	pObject

	Func init 
		pObject = QPointF_new()
		return self

	Func delete
		pObject = QPointF_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isNull 
		return QPointF_isNull(pObject)

	Func manhattanLength 
		return QPointF_manhattanLength(pObject)

	Func rx 
		return QPointF_rx(pObject)

	Func ry 
		return QPointF_ry(pObject)

	Func setX P1
		return QPointF_setX(pObject,P1)

	Func setY P1
		return QPointF_setY(pObject,P1)

	Func toPoint 
		pTempObj = new QPoint
		pTempObj.pObject = QPointF_toPoint(pObject)
		return pTempObj

	Func x 
		return QPointF_x(pObject)

	Func y 
		return QPointF_y(pObject)

Class QPoint

	pObject

	Func init 
		pObject = QPoint_new()
		return self

	Func delete
		pObject = QPoint_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isNull 
		return QPoint_isNull(pObject)

	Func manhattanLength 
		return QPoint_manhattanLength(pObject)

	Func rx 
		return QPoint_rx(pObject)

	Func ry 
		return QPoint_ry(pObject)

	Func setX P1
		return QPoint_setX(pObject,P1)

	Func setY P1
		return QPoint_setY(pObject,P1)

	Func x 
		return QPoint_x(pObject)

	Func y 
		return QPoint_y(pObject)

Class QScrollArea from QAbstractScrollArea

	pObject

	Func init P1
		pObject = QScrollArea_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QScrollArea_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alignment 
		return QScrollArea_alignment(pObject)

	Func ensureVisible P1,P2,P3,P4
		return QScrollArea_ensureVisible(pObject,P1,P2,P3,P4)

	Func ensureWidgetVisible P1,P2,P3
		return QScrollArea_ensureWidgetVisible(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func setAlignment P1
		return QScrollArea_setAlignment(pObject,P1)

	Func setWidget P1
		return QScrollArea_setWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidgetResizable P1
		return QScrollArea_setWidgetResizable(pObject,P1)

	Func takeWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QScrollArea_takeWidget(pObject)
		return pTempObj

	Func widget 
		pTempObj = new QWidget
		pTempObj.pObject = QScrollArea_widget(pObject)
		return pTempObj

	Func widgetResizable 
		return QScrollArea_widgetResizable(pObject)

Class QSplitter from QFrame

	pObject

	Func init P1
		pObject = QSplitter_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSplitter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addWidget P1
		return QSplitter_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func childrenCollapsible 
		return QSplitter_childrenCollapsible(pObject)

	Func count 
		return QSplitter_count(pObject)

	Func getRange P1,P2,P3
		return QSplitter_getRange(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func handle P1
		return QSplitter_handle(pObject,P1)

	Func handleWidth 
		return QSplitter_handleWidth(pObject)

	Func indexOf P1
		return QSplitter_indexOf(pObject,GetObjectPointerFromRingObject(P1))

	Func insertWidget P1,P2
		return QSplitter_insertWidget(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func isCollapsible P1
		return QSplitter_isCollapsible(pObject,P1)

	Func opaqueResize 
		return QSplitter_opaqueResize(pObject)

	Func orientation 
		return QSplitter_orientation(pObject)

	Func refresh 
		return QSplitter_refresh(pObject)

	Func restoreState P1
		return QSplitter_restoreState(pObject,GetObjectPointerFromRingObject(P1))

	Func saveState 
		pTempObj = new QByteArray
		pTempObj.pObject = QSplitter_saveState(pObject)
		return pTempObj

	Func setChildrenCollapsible P1
		return QSplitter_setChildrenCollapsible(pObject,P1)

	Func setCollapsible P1,P2
		return QSplitter_setCollapsible(pObject,P1,P2)

	Func setHandleWidth P1
		return QSplitter_setHandleWidth(pObject,P1)

	Func setOpaqueResize P1
		return QSplitter_setOpaqueResize(pObject,P1)

	Func setOrientation P1
		return QSplitter_setOrientation(pObject,P1)

	Func setSizes P1
		return QSplitter_setSizes(pObject,GetObjectPointerFromRingObject(P1))

	Func setStretchFactor P1,P2
		return QSplitter_setStretchFactor(pObject,P1,P2)

	Func sizes 
		return QSplitter_sizes(pObject)

	Func widget P1
		pTempObj = new QWidget
		pTempObj.pObject = QSplitter_widget(pObject,P1)
		return pTempObj

Class QCompleter from QObject

	pObject

	Func init P1
		pObject = QCompleter_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QCompleter_delete(pObject)

	Func ObjectPointer
		return pObject

	Func caseSensitivity 
		return QCompleter_caseSensitivity(pObject)

	Func completionColumn 
		return QCompleter_completionColumn(pObject)

	Func completionCount 
		return QCompleter_completionCount(pObject)

	Func completionMode 
		return QCompleter_completionMode(pObject)

	Func completionModel 
		return QCompleter_completionModel(pObject)

	Func completionPrefix 
		return QCompleter_completionPrefix(pObject)

	Func completionRole 
		return QCompleter_completionRole(pObject)

	Func currentCompletion 
		return QCompleter_currentCompletion(pObject)

	Func currentIndex 
		return QCompleter_currentIndex(pObject)

	Func currentRow 
		return QCompleter_currentRow(pObject)

	Func filterMode 
		return QCompleter_filterMode(pObject)

	Func maxVisibleItems 
		return QCompleter_maxVisibleItems(pObject)

	Func model 
		return QCompleter_model(pObject)

	Func modelSorting 
		return QCompleter_modelSorting(pObject)

	Func popup 
		pTempObj = new QAbstractItemView
		pTempObj.pObject = QCompleter_popup(pObject)
		return pTempObj

	Func setCaseSensitivity P1
		return QCompleter_setCaseSensitivity(pObject,P1)

	Func setCompletionColumn P1
		return QCompleter_setCompletionColumn(pObject,P1)

	Func setCompletionMode P1
		return QCompleter_setCompletionMode(pObject,P1)

	Func setCompletionRole P1
		return QCompleter_setCompletionRole(pObject,P1)

	Func setCurrentRow P1
		return QCompleter_setCurrentRow(pObject,P1)

	Func setFilterMode P1
		return QCompleter_setFilterMode(pObject,P1)

	Func setMaxVisibleItems P1
		return QCompleter_setMaxVisibleItems(pObject,P1)

	Func setModel P1
		return QCompleter_setModel(pObject,GetObjectPointerFromRingObject(P1))

	Func setModelSorting P1
		return QCompleter_setModelSorting(pObject,P1)

	Func setPopup P1
		return QCompleter_setPopup(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidget P1
		return QCompleter_setWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func widget 
		pTempObj = new QWidget
		pTempObj.pObject = QCompleter_widget(pObject)
		return pTempObj

	Func wrapAround 
		return QCompleter_wrapAround(pObject)

	Func complete P1
		return QCompleter_complete(pObject,GetObjectPointerFromRingObject(P1))

	Func setCompletionPrefix P1
		return QCompleter_setCompletionPrefix(pObject,P1)

	Func setWrapAround P1
		return QCompleter_setWrapAround(pObject,P1)

Class QString2

	pObject

	Func init 
		pObject = QString2_new()
		return self

	Func delete
		pObject = QString2_delete(pObject)

	Func ObjectPointer
		return pObject

	Func append P1
		return QString2_append(pObject,P1)

	Func split P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split(pObject,P1,P2,P3)
		return pTempObj

	Func split_2 P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)
		return pTempObj

	Func split_3 P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split_3(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func split_4 P1,P2
		pTempObj = new QStringList
		pTempObj.pObject = QString2_split_4(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

Class QProcess from QIODevice

	pObject

	Func init P1
		pObject = QProcess_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QProcess_delete(pObject)

	Func ObjectPointer
		return pObject

	Func arguments 
		pTempObj = new QStringList
		pTempObj.pObject = QProcess_arguments(pObject)
		return pTempObj

	Func closeReadChannel P1
		return QProcess_closeReadChannel(pObject,P1)

	Func closeWriteChannel 
		return QProcess_closeWriteChannel(pObject)

	Func error 
		return QProcess_error(pObject)

	Func exitCode 
		return QProcess_exitCode(pObject)

	Func exitStatus 
		return QProcess_exitStatus(pObject)

	Func inputChannelMode 
		return QProcess_inputChannelMode(pObject)

	Func processChannelMode 
		return QProcess_processChannelMode(pObject)

	Func processEnvironment 
		return QProcess_processEnvironment(pObject)

	Func program 
		return QProcess_program(pObject)

	Func readAllStandardError 
		pTempObj = new QByteArray
		pTempObj.pObject = QProcess_readAllStandardError(pObject)
		return pTempObj

	Func readAllStandardOutput 
		pTempObj = new QByteArray
		pTempObj.pObject = QProcess_readAllStandardOutput(pObject)
		return pTempObj

	Func readChannel 
		return QProcess_readChannel(pObject)

	Func setArguments P1
		return QProcess_setArguments(pObject,GetObjectPointerFromRingObject(P1))

	Func setInputChannelMode P1
		return QProcess_setInputChannelMode(pObject,P1)

	Func setProcessChannelMode P1
		return QProcess_setProcessChannelMode(pObject,P1)

	Func setProcessEnvironment P1
		return QProcess_setProcessEnvironment(pObject,GetObjectPointerFromRingObject(P1))

	Func setProgram P1
		return QProcess_setProgram(pObject,P1)

	Func setReadChannel P1
		return QProcess_setReadChannel(pObject,P1)

	Func setStandardErrorFile P1,P2
		return QProcess_setStandardErrorFile(pObject,P1,P2)

	Func setStandardInputFile P1
		return QProcess_setStandardInputFile(pObject,P1)

	Func setStandardOutputFile P1,P2
		return QProcess_setStandardOutputFile(pObject,P1,P2)

	Func setStandardOutputProcess P1
		return QProcess_setStandardOutputProcess(pObject,GetObjectPointerFromRingObject(P1))

	Func setWorkingDirectory P1
		return QProcess_setWorkingDirectory(pObject,P1)

	Func start P1,P2,P3
		return QProcess_start(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func start_2 P1,P2
		return QProcess_start_2(pObject,P1,P2)

	Func start_3 P1
		return QProcess_start_3(pObject,P1)

	Func state 
		return QProcess_state(pObject)

	Func waitForFinished P1
		return QProcess_waitForFinished(pObject,P1)

	Func waitForStarted P1
		return QProcess_waitForStarted(pObject,P1)

	Func workingDirectory 
		return QProcess_workingDirectory(pObject)

	Func kill 
		return QProcess_kill(pObject)

	Func terminate 
		return QProcess_terminate(pObject)

	Func setreadyReadStandardErrorEvent P1
		return QProcess_setreadyReadStandardErrorEvent(pObject,P1)

	Func setreadyReadStandardOutputEvent P1
		return QProcess_setreadyReadStandardOutputEvent(pObject,P1)

	Func getreadyReadStandardErrorEvent 
		return QProcess_getreadyReadStandardErrorEvent(pObject)

	Func getreadyReadStandardOutputEvent 
		return QProcess_getreadyReadStandardOutputEvent(pObject)

Class QMdiArea from QAbstractScrollArea

	pObject

	Func init P1
		pObject = QMdiArea_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMdiArea_delete(pObject)

	Func ObjectPointer
		return pObject

	Func activationOrder 
		return QMdiArea_activationOrder(pObject)

	Func activeSubWindow 
		pTempObj = new QMdiSubWindow
		pTempObj.pObject = QMdiArea_activeSubWindow(pObject)
		return pTempObj

	Func addSubWindow P1,P2
		pTempObj = new QMdiSubWindow
		pTempObj.pObject = QMdiArea_addSubWindow(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func background 
		pTempObj = new QBrush
		pTempObj.pObject = QMdiArea_background(pObject)
		return pTempObj

	Func currentSubWindow 
		pTempObj = new QMdiSubWindow
		pTempObj.pObject = QMdiArea_currentSubWindow(pObject)
		return pTempObj

	Func documentMode 
		return QMdiArea_documentMode(pObject)

	Func removeSubWindow P1
		return QMdiArea_removeSubWindow(pObject,GetObjectPointerFromRingObject(P1))

	Func setActivationOrder P1
		return QMdiArea_setActivationOrder(pObject,P1)

	Func setBackground P1
		return QMdiArea_setBackground(pObject,GetObjectPointerFromRingObject(P1))

	Func setDocumentMode P1
		return QMdiArea_setDocumentMode(pObject,P1)

	Func setOption P1,P2
		return QMdiArea_setOption(pObject,P1,P2)

	Func setTabPosition P1
		return QMdiArea_setTabPosition(pObject,P1)

	Func setTabShape P1
		return QMdiArea_setTabShape(pObject,P1)

	Func setTabsClosable P1
		return QMdiArea_setTabsClosable(pObject,P1)

	Func setTabsMovable P1
		return QMdiArea_setTabsMovable(pObject,P1)

	Func setViewMode P1
		return QMdiArea_setViewMode(pObject,P1)

	Func subWindowList P1
		return QMdiArea_subWindowList(pObject,P1)

	Func tabPosition 
		return QMdiArea_tabPosition(pObject)

	Func tabShape 
		return QMdiArea_tabShape(pObject)

	Func tabsClosable 
		return QMdiArea_tabsClosable(pObject)

	Func tabsMovable 
		return QMdiArea_tabsMovable(pObject)

	Func testOption P1
		return QMdiArea_testOption(pObject,P1)

	Func viewMode 
		return QMdiArea_viewMode(pObject)

	Func activateNextSubWindow 
		return QMdiArea_activateNextSubWindow(pObject)

	Func activatePreviousSubWindow 
		return QMdiArea_activatePreviousSubWindow(pObject)

	Func cascadeSubWindows 
		return QMdiArea_cascadeSubWindows(pObject)

	Func closeActiveSubWindow 
		return QMdiArea_closeActiveSubWindow(pObject)

	Func closeAllSubWindows 
		return QMdiArea_closeAllSubWindows(pObject)

	Func setActiveSubWindow P1
		return QMdiArea_setActiveSubWindow(pObject,GetObjectPointerFromRingObject(P1))

	Func tileSubWindows 
		return QMdiArea_tileSubWindows(pObject)

Class QMdiSubWindow from QWidget

	pObject

	Func init P1
		pObject = QMdiSubWindow_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMdiSubWindow_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isShaded 
		return QMdiSubWindow_isShaded(pObject)

	Func keyboardPageStep 
		return QMdiSubWindow_keyboardPageStep(pObject)

	Func keyboardSingleStep 
		return QMdiSubWindow_keyboardSingleStep(pObject)

	Func mdiArea 
		pTempObj = new QMdiArea
		pTempObj.pObject = QMdiSubWindow_mdiArea(pObject)
		return pTempObj

	Func setKeyboardPageStep P1
		return QMdiSubWindow_setKeyboardPageStep(pObject,P1)

	Func setKeyboardSingleStep P1
		return QMdiSubWindow_setKeyboardSingleStep(pObject,P1)

	Func setOption P1,P2
		return QMdiSubWindow_setOption(pObject,P1,P2)

	Func setSystemMenu P1
		return QMdiSubWindow_setSystemMenu(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidget P1
		return QMdiSubWindow_setWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func systemMenu 
		pTempObj = new QMenu
		pTempObj.pObject = QMdiSubWindow_systemMenu(pObject)
		return pTempObj

	Func testOption P1
		return QMdiSubWindow_testOption(pObject,P1)

	Func widget 
		pTempObj = new QWidget
		pTempObj.pObject = QMdiSubWindow_widget(pObject)
		return pTempObj

	Func showShaded 
		return QMdiSubWindow_showShaded(pObject)

	Func showSystemMenu 
		return QMdiSubWindow_showSystemMenu(pObject)

Class QCursor

	pObject

	Func init 
		pObject = QCursor_new()
		return self

	Func delete
		pObject = QCursor_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bitmap 
		pTempObj = new QBitmap
		pTempObj.pObject = QCursor_bitmap(pObject)
		return pTempObj

	Func hotSpot 
		pTempObj = new QPoint
		pTempObj.pObject = QCursor_hotSpot(pObject)
		return pTempObj

	Func mask 
		pTempObj = new QBitmap
		pTempObj.pObject = QCursor_mask(pObject)
		return pTempObj

	Func pixmap 
		pTempObj = new QPixmap
		pTempObj.pObject = QCursor_pixmap(pObject)
		return pTempObj

	Func setShape P1
		return QCursor_setShape(pObject,P1)

	Func shape 
		return QCursor_shape(pObject)

	Func pos 
		pTempObj = new QPoint
		pTempObj.pObject = QCursor_pos(pObject)
		return pTempObj

	Func pos_2 P1
		pTempObj = new QPoint
		pTempObj.pObject = QCursor_pos_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setPos P1,P2
		return QCursor_setPos(pObject,P1,P2)

	Func setPos_2 P1,P2,P3
		return QCursor_setPos_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func setPos_3 P1
		return QCursor_setPos_3(pObject,GetObjectPointerFromRingObject(P1))

	Func setPos_4 P1,P2
		return QCursor_setPos_4(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

Class QListView from QAbstractItemView

	pObject

	Func init P1
		pObject = QListView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QListView_delete(pObject)

	Func ObjectPointer
		return pObject

	Func batchSize 
		return QListView_batchSize(pObject)

	Func clearPropertyFlags 
		return QListView_clearPropertyFlags(pObject)

	Func flow 
		return QListView_flow(pObject)

	Func gridSize 
		pTempObj = new QSize
		pTempObj.pObject = QListView_gridSize(pObject)
		return pTempObj

	Func isRowHidden P1
		return QListView_isRowHidden(pObject,P1)

	Func isSelectionRectVisible 
		return QListView_isSelectionRectVisible(pObject)

	Func isWrapping 
		return QListView_isWrapping(pObject)

	Func layoutMode 
		return QListView_layoutMode(pObject)

	Func modelColumn 
		return QListView_modelColumn(pObject)

	Func movement 
		return QListView_movement(pObject)

	Func resizeMode 
		return QListView_resizeMode(pObject)

	Func setBatchSize P1
		return QListView_setBatchSize(pObject,P1)

	Func setFlow P1
		return QListView_setFlow(pObject,P1)

	Func setGridSize P1
		return QListView_setGridSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setLayoutMode P1
		return QListView_setLayoutMode(pObject,P1)

	Func setModelColumn P1
		return QListView_setModelColumn(pObject,P1)

	Func setMovement P1
		return QListView_setMovement(pObject,P1)

	Func setResizeMode P1
		return QListView_setResizeMode(pObject,P1)

	Func setRowHidden P1,P2
		return QListView_setRowHidden(pObject,P1,P2)

	Func setSelectionRectVisible P1
		return QListView_setSelectionRectVisible(pObject,P1)

	Func setSpacing P1
		return QListView_setSpacing(pObject,P1)

	Func setUniformItemSizes P1
		return QListView_setUniformItemSizes(pObject,P1)

	Func setViewMode P1
		return QListView_setViewMode(pObject,P1)

	Func setWordWrap P1
		return QListView_setWordWrap(pObject,P1)

	Func setWrapping P1
		return QListView_setWrapping(pObject,P1)

	Func spacing 
		return QListView_spacing(pObject)

	Func uniformItemSizes 
		return QListView_uniformItemSizes(pObject)

	Func viewMode 
		return QListView_viewMode(pObject)

	Func wordWrap 
		return QListView_wordWrap(pObject)

Class QAxBase from QObject

	pObject

	Func init P1
		pObject = QAxBase_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAxBase_delete(pObject)

	Func ObjectPointer
		return pObject

	Func asVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QAxBase_asVariant(pObject)
		return pTempObj

	Func control 
		return QAxBase_control(pObject)

	Func disableClassInfo 
		return QAxBase_disableClassInfo(pObject)

	Func disableEventSink 
		return QAxBase_disableEventSink(pObject)

	Func disableMetaObject 
		return QAxBase_disableMetaObject(pObject)

	Func dynamicCall P1
		pTempObj = new QVariant
		pTempObj.pObject = QAxBase_dynamicCall(pObject,P1)
		return pTempObj

	Func dynamicCall_2 P1,P2
		pTempObj = new QVariant
		pTempObj.pObject = QAxBase_dynamicCall_2(pObject,P1,P2)
		return pTempObj

	Func generateDocumentation 
		return QAxBase_generateDocumentation(pObject)

	Func isNull 
		return QAxBase_isNull(pObject)

	Func querySubObject P1
		pTempObj = new QAxObject
		pTempObj.pObject = QAxBase_querySubObject(pObject,P1)
		return pTempObj

	Func setControl P1
		return QAxBase_setControl(pObject,P1)

	Func verbs 
		pTempObj = new QStringList
		pTempObj.pObject = QAxBase_verbs(pObject)
		return pTempObj

Class QUuid

	pObject

	Func init 
		pObject = QUuid_new()
		return self

	Func delete
		pObject = QUuid_delete(pObject)

	Func ObjectPointer
		return pObject

	Func toString 
		return QUuid_toString(pObject)

Class QToolButton from QAbstractButton

	pObject

	Func init P1
		pObject = QToolButton_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QToolButton_delete(pObject)

	Func ObjectPointer
		return pObject

	Func arrowType 
		return QToolButton_arrowType(pObject)

	Func autoRaise 
		return QToolButton_autoRaise(pObject)

	Func defaultAction 
		pTempObj = new QAction
		pTempObj.pObject = QToolButton_defaultAction(pObject)
		return pTempObj

	Func menu 
		pTempObj = new QMenu
		pTempObj.pObject = QToolButton_menu(pObject)
		return pTempObj

	Func popupMode 
		return QToolButton_popupMode(pObject)

	Func setArrowType P1
		return QToolButton_setArrowType(pObject,GetObjectPointerFromRingObject(P1))

	Func setAutoRaise P1
		return QToolButton_setAutoRaise(pObject,P1)

	Func setMenu P1
		return QToolButton_setMenu(pObject,GetObjectPointerFromRingObject(P1))

	Func setPopupMode P1
		return QToolButton_setPopupMode(pObject,P1)

	Func toolButtonStyle 
		return QToolButton_toolButtonStyle(pObject)

	Func setDefaultAction P1
		return QToolButton_setDefaultAction(pObject,GetObjectPointerFromRingObject(P1))

	Func setToolButtonStyle P1
		return QToolButton_setToolButtonStyle(pObject,P1)

	Func showMenu 
		return QToolButton_showMenu(pObject)

	Func settriggeredEvent P1
		return QToolButton_settriggeredEvent(pObject,P1)

	Func gettriggeredEvent 
		return QToolButton_gettriggeredEvent(pObject)

	Func setClickEvent P1
		return QToolButton_setClickEvent(pObject,P1)

	Func getClickEvent 
		return QToolButton_getClickEvent(pObject)

Class QSerialPort from QIODevice

	pObject

	Func init P1
		pObject = QSerialPort_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSerialPort_delete(pObject)

	Func ObjectPointer
		return pObject

	Func baudRate P1
		return QSerialPort_baudRate(pObject,P1)

	Func clear P1
		return QSerialPort_clear(pObject,P1)

	Func clearError 
		return QSerialPort_clearError(pObject)

	Func dataBits 
		return QSerialPort_dataBits(pObject)

	Func error 
		return QSerialPort_error(pObject)

	Func flowControl 
		return QSerialPort_flowControl(pObject)

	Func flush 
		return QSerialPort_flush(pObject)

	Func handle 
		return QSerialPort_handle(pObject)

	Func isDataTerminalReady 
		return QSerialPort_isDataTerminalReady(pObject)

	Func isRequestToSend 
		return QSerialPort_isRequestToSend(pObject)

	Func parity 
		return QSerialPort_parity(pObject)

	Func pinoutSignals 
		return QSerialPort_pinoutSignals(pObject)

	Func portName 
		return QSerialPort_portName(pObject)

	Func readBufferSize 
		return QSerialPort_readBufferSize(pObject)

	Func setBaudRate P1,P2
		return QSerialPort_setBaudRate(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setBreakEnabled P1
		return QSerialPort_setBreakEnabled(pObject,P1)

	Func setDataBits P1
		return QSerialPort_setDataBits(pObject,P1)

	Func setDataTerminalReady P1
		return QSerialPort_setDataTerminalReady(pObject,P1)

	Func setFlowControl P1
		return QSerialPort_setFlowControl(pObject,P1)

	Func setParity P1
		return QSerialPort_setParity(pObject,P1)

	Func setPort P1
		return QSerialPort_setPort(pObject,GetObjectPointerFromRingObject(P1))

	Func setPortName P1
		return QSerialPort_setPortName(pObject,P1)

	Func setReadBufferSize P1
		return QSerialPort_setReadBufferSize(pObject,P1)

	Func setRequestToSend P1
		return QSerialPort_setRequestToSend(pObject,P1)

	Func setStopBits P1
		return QSerialPort_setStopBits(pObject,P1)

	Func stopBits 
		return QSerialPort_stopBits(pObject)

	Func setbaudRateChangedEvent P1
		return QSerialPort_setbaudRateChangedEvent(pObject,P1)

	Func setbreakEnabledChangedEvent P1
		return QSerialPort_setbreakEnabledChangedEvent(pObject,P1)

	Func setdataBitsChangedEvent P1
		return QSerialPort_setdataBitsChangedEvent(pObject,P1)

	Func setdataTerminalReadyChangedEvent P1
		return QSerialPort_setdataTerminalReadyChangedEvent(pObject,P1)

	Func seterrorEvent P1
		return QSerialPort_seterrorEvent(pObject,P1)

	Func setflowControlChangedEvent P1
		return QSerialPort_setflowControlChangedEvent(pObject,P1)

	Func setparityChangedEvent P1
		return QSerialPort_setparityChangedEvent(pObject,P1)

	Func setrequestToSendChangedEvent P1
		return QSerialPort_setrequestToSendChangedEvent(pObject,P1)

	Func setstopBitsChangedEvent P1
		return QSerialPort_setstopBitsChangedEvent(pObject,P1)

	Func getbaudRateChangedEvent 
		return QSerialPort_getbaudRateChangedEvent(pObject)

	Func getbreakEnabledChangedEvent 
		return QSerialPort_getbreakEnabledChangedEvent(pObject)

	Func getdataBitsChangedEvent 
		return QSerialPort_getdataBitsChangedEvent(pObject)

	Func getdataTerminalReadyChangedEvent 
		return QSerialPort_getdataTerminalReadyChangedEvent(pObject)

	Func geterrorEvent 
		return QSerialPort_geterrorEvent(pObject)

	Func getflowControlChangedEvent 
		return QSerialPort_getflowControlChangedEvent(pObject)

	Func getparityChangedEvent 
		return QSerialPort_getparityChangedEvent(pObject)

	Func getrequestToSendChangedEvent 
		return QSerialPort_getrequestToSendChangedEvent(pObject)

	Func getstopBitsChangedEvent 
		return QSerialPort_getstopBitsChangedEvent(pObject)

Class QSerialPortInfo

	pObject

	Func init 
		pObject = QSerialPortInfo_new()
		return self

	Func delete
		pObject = QSerialPortInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func description 
		return QSerialPortInfo_description(pObject)

	Func hasProductIdentifier 
		return QSerialPortInfo_hasProductIdentifier(pObject)

	Func hasVendorIdentifier 
		return QSerialPortInfo_hasVendorIdentifier(pObject)

	Func isBusy 
		return QSerialPortInfo_isBusy(pObject)

	Func isNull 
		return QSerialPortInfo_isNull(pObject)

	Func manufacturer 
		return QSerialPortInfo_manufacturer(pObject)

	Func portName 
		return QSerialPortInfo_portName(pObject)

	Func productIdentifier 
		return QSerialPortInfo_productIdentifier(pObject)

	Func swap P1
		return QSerialPortInfo_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func systemLocation 
		return QSerialPortInfo_systemLocation(pObject)

	Func vendorIdentifier 
		return QSerialPortInfo_vendorIdentifier(pObject)

Class QStringRef

	pObject

	Func init 
		pObject = QStringRef_new()
		return self

	Func delete
		pObject = QStringRef_delete(pObject)

	Func ObjectPointer
		return pObject

	Func appendTo P1
		pTempObj = new QStringRef
		pTempObj.pObject = QStringRef_appendTo(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func at P1
		return QStringRef_at(pObject,P1)

	Func clear 
		return QStringRef_clear(pObject)

	Func compare_2 P1,P2
		return QStringRef_compare_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func compare_3 P1,P2
		return QStringRef_compare_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func constData 
		return QStringRef_constData(pObject)

	Func contains P1,P2
		return QStringRef_contains(pObject,P1,P2)

	Func contains_2 P1,P2
		return QStringRef_contains_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func contains_3 P1,P2
		return QStringRef_contains_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func contains_4 P1,P2
		return QStringRef_contains_4(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func count 
		return QStringRef_count(pObject)

	Func count_2 P1,P2
		return QStringRef_count_2(pObject,P1,P2)

	Func count_3 P1,P2
		return QStringRef_count_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func count_4 P1,P2
		return QStringRef_count_4(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func data 
		return QStringRef_data(pObject)

	Func endsWith P1,P2
		return QStringRef_endsWith(pObject,P1,P2)

	Func endsWith_2 P1,P2
		return QStringRef_endsWith_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func endsWith_3 P1,P2
		return QStringRef_endsWith_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func endsWith_4 P1,P2
		return QStringRef_endsWith_4(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func indexOf P1,P2,P3
		return QStringRef_indexOf(pObject,P1,P2,P3)

	Func indexOf_2 P1,P2,P3
		return QStringRef_indexOf_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func indexOf_3 P1,P2,P3
		return QStringRef_indexOf_3(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func indexOf_4 P1,P2,P3
		return QStringRef_indexOf_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func isEmpty 
		return QStringRef_isEmpty(pObject)

	Func isNull 
		return QStringRef_isNull(pObject)

	Func lastIndexOf P1,P2,P3
		return QStringRef_lastIndexOf(pObject,P1,P2,P3)

	Func lastIndexOf_2 P1,P2,P3
		return QStringRef_lastIndexOf_2(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func lastIndexOf_3 P1,P2,P3
		return QStringRef_lastIndexOf_3(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func lastIndexOf_4 P1,P2,P3
		return QStringRef_lastIndexOf_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func length 
		return QStringRef_length(pObject)

	Func localeAwareCompare P1
		return QStringRef_localeAwareCompare(pObject,P1)

	Func localeAwareCompare_2 P1
		return QStringRef_localeAwareCompare_2(pObject,GetObjectPointerFromRingObject(P1))

	Func position 
		return QStringRef_position(pObject)

	Func size 
		return QStringRef_size(pObject)

	Func startsWith P1,P2
		return QStringRef_startsWith(pObject,P1,P2)

	Func startsWith_2 P1,P2
		return QStringRef_startsWith_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func startsWith_3 P1,P2
		return QStringRef_startsWith_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func startsWith_4 P1,P2
		return QStringRef_startsWith_4(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func string 
		return QStringRef_string(pObject)

	Func toLatin1 
		pTempObj = new QByteArray
		pTempObj.pObject = QStringRef_toLatin1(pObject)
		return pTempObj

	Func toLocal8Bit 
		pTempObj = new QByteArray
		pTempObj.pObject = QStringRef_toLocal8Bit(pObject)
		return pTempObj

	Func toString 
		return QStringRef_toString(pObject)

	Func toUcs4 
		return QStringRef_toUcs4(pObject)

	Func toUtf8 
		pTempObj = new QByteArray
		pTempObj.pObject = QStringRef_toUtf8(pObject)
		return pTempObj

	Func unicode 
		return QStringRef_unicode(pObject)

	Func compare_4 P1,P2,P3
		return QStringRef_compare_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func compare_5 P1,P2,P3
		return QStringRef_compare_5(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func compare_6 P1,P2,P3
		return QStringRef_compare_6(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func localeAwareCompare_3 P1,P2
		return QStringRef_localeAwareCompare_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func localeAwareCompare_4 P1,P2
		return QStringRef_localeAwareCompare_4(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

Class QMutex

	pObject

	Func init P1
		pObject = QMutex_new(P1)
		return self

	Func delete
		pObject = QMutex_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isRecursive 
		return QMutex_isRecursive(pObject)

	Func lock 
		return QMutex_lock(pObject)

	Func unlock 
		return QMutex_unlock(pObject)

Class QMutexLocker

	pObject

	Func init P1
		pObject = QMutexLocker_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMutexLocker_delete(pObject)

	Func ObjectPointer
		return pObject

	Func mutex 
		pTempObj = new QMutex
		pTempObj.pObject = QMutexLocker_mutex(pObject)
		return pTempObj

	Func relock 
		return QMutexLocker_relock(pObject)

	Func unlock 
		return QMutexLocker_unlock(pObject)

Class QBuffer from QIODevice

	pObject

	Func init P1
		pObject = QBuffer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QBuffer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func buffer 
		pTempObj = new QByteArray
		pTempObj.pObject = QBuffer_buffer(pObject)
		return pTempObj

	Func data 
		pTempObj = new QByteArray
		pTempObj.pObject = QBuffer_data(pObject)
		return pTempObj

	Func setBuffer P1
		return QBuffer_setBuffer(pObject,GetObjectPointerFromRingObject(P1))

	Func setData P1
		return QBuffer_setData(pObject,GetObjectPointerFromRingObject(P1))

	Func setData_2 P1,P2
		return QBuffer_setData_2(pObject,P1,P2)

Class QBluetoothAddress

	pObject

	Func init 
		pObject = QBluetoothAddress_new()
		return self

	Func delete
		pObject = QBluetoothAddress_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QBluetoothAddress_clear(pObject)

	Func isNull 
		return QBluetoothAddress_isNull(pObject)

	Func toString 
		return QBluetoothAddress_toString(pObject)

	Func toUInt64 
		return QBluetoothAddress_toUInt64(pObject)

Class QBluetoothDeviceDiscoveryAgent

	pObject

	Func init P1
		pObject = QBluetoothDeviceDiscoveryAgent_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QBluetoothDeviceDiscoveryAgent_delete(pObject)

	Func ObjectPointer
		return pObject

	Func discoveredDevices 
		return QBluetoothDeviceDiscoveryAgent_discoveredDevices(pObject)

	Func error 
		return QBluetoothDeviceDiscoveryAgent_error(pObject)

	Func errorString 
		return QBluetoothDeviceDiscoveryAgent_errorString(pObject)

	Func inquiryType 
		return QBluetoothDeviceDiscoveryAgent_inquiryType(pObject)

	Func isActive 
		return QBluetoothDeviceDiscoveryAgent_isActive(pObject)

	Func setInquiryType P1
		return QBluetoothDeviceDiscoveryAgent_setInquiryType(pObject,P1)

	Func start 
		return QBluetoothDeviceDiscoveryAgent_start(pObject)

	Func stop 
		return QBluetoothDeviceDiscoveryAgent_stop(pObject)

	Func setcanceledEvent P1
		return QBluetoothDeviceDiscoveryAgent_setcanceledEvent(pObject,P1)

	Func setdeviceDiscoveredEvent P1
		return QBluetoothDeviceDiscoveryAgent_setdeviceDiscoveredEvent(pObject,P1)

	Func seterrorEvent P1
		return QBluetoothDeviceDiscoveryAgent_seterrorEvent(pObject,P1)

	Func setfinishedEvent P1
		return QBluetoothDeviceDiscoveryAgent_setfinishedEvent(pObject,P1)

	Func getcanceledEvent 
		return QBluetoothDeviceDiscoveryAgent_getcanceledEvent(pObject)

	Func getdeviceDiscoveredEvent 
		return QBluetoothDeviceDiscoveryAgent_getdeviceDiscoveredEvent(pObject)

	Func geterrorEvent 
		return QBluetoothDeviceDiscoveryAgent_geterrorEvent(pObject)

	Func getfinishedEvent 
		return QBluetoothDeviceDiscoveryAgent_getfinishedEvent(pObject)

Class QBluetoothDeviceInfo

	pObject

	Func init 
		pObject = QBluetoothDeviceInfo_new()
		return self

	Func delete
		pObject = QBluetoothDeviceInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func address 
		pTempObj = new QBluetoothAddress
		pTempObj.pObject = QBluetoothDeviceInfo_address(pObject)
		return pTempObj

	Func isCached 
		return QBluetoothDeviceInfo_isCached(pObject)

	Func isValid 
		return QBluetoothDeviceInfo_isValid(pObject)

	Func majorDeviceClass 
		return QBluetoothDeviceInfo_majorDeviceClass(pObject)

	Func minorDeviceClass 
		return QBluetoothDeviceInfo_minorDeviceClass(pObject)

	Func name 
		return QBluetoothDeviceInfo_name(pObject)

	Func rssi 
		return QBluetoothDeviceInfo_rssi(pObject)

	Func serviceClasses 
		return QBluetoothDeviceInfo_serviceClasses(pObject)

	Func serviceUuids P1
		return QBluetoothDeviceInfo_serviceUuids(pObject,GetObjectPointerFromRingObject(P1))

	Func serviceUuidsCompleteness 
		return QBluetoothDeviceInfo_serviceUuidsCompleteness(pObject)

	Func setCached P1
		return QBluetoothDeviceInfo_setCached(pObject,P1)

	Func setRssi P1
		return QBluetoothDeviceInfo_setRssi(pObject,GetObjectPointerFromRingObject(P1))

	Func setServiceUuids P1,P2
		return QBluetoothDeviceInfo_setServiceUuids(pObject,GetObjectPointerFromRingObject(P1),P2)

Class QBluetoothHostInfo

	pObject

	Func init 
		pObject = QBluetoothHostInfo_new()
		return self

	Func delete
		pObject = QBluetoothHostInfo_delete(pObject)

	Func ObjectPointer
		return pObject

	Func address 
		pTempObj = new QBluetoothAddress
		pTempObj.pObject = QBluetoothHostInfo_address(pObject)
		return pTempObj

	Func name 
		return QBluetoothHostInfo_name(pObject)

	Func setAddress P1
		return QBluetoothHostInfo_setAddress(pObject,GetObjectPointerFromRingObject(P1))

	Func setName P1
		return QBluetoothHostInfo_setName(pObject,P1)

Class QBluetoothLocalDevice

	pObject

	Func init P1
		pObject = QBluetoothLocalDevice_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QBluetoothLocalDevice_delete(pObject)

	Func ObjectPointer
		return pObject

	Func address 
		pTempObj = new QBluetoothAddress
		pTempObj.pObject = QBluetoothLocalDevice_address(pObject)
		return pTempObj

Class QDateTime

	pObject

	Func init 
		pObject = QDateTime_new()
		return self

	Func delete
		pObject = QDateTime_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addDays P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addDays(pObject,P1)
		return pTempObj

	Func addMSecs P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addMSecs(pObject,P1)
		return pTempObj

	Func addMonths P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addMonths(pObject,P1)
		return pTempObj

	Func addSecs P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addSecs(pObject,P1)
		return pTempObj

	Func addYears P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_addYears(pObject,P1)
		return pTempObj

	Func date 
		pTempObj = new QDate
		pTempObj.pObject = QDateTime_date(pObject)
		return pTempObj

	Func daysTo P1
		return QDateTime_daysTo(pObject,GetObjectPointerFromRingObject(P1))

	Func isNull 
		return QDateTime_isNull(pObject)

	Func isValid 
		return QDateTime_isValid(pObject)

	Func msecsTo P1
		return QDateTime_msecsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func secsTo P1
		return QDateTime_secsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func setDate P1
		return QDateTime_setDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setMSecsSinceEpoch P1
		return QDateTime_setMSecsSinceEpoch(pObject,P1)

	Func setTime P1
		return QDateTime_setTime(pObject,GetObjectPointerFromRingObject(P1))

	Func setTimeSpec P1
		return QDateTime_setTimeSpec(pObject,P1)

	Func setTime_t P1
		return QDateTime_setTime_t(pObject,GetObjectPointerFromRingObject(P1))

	Func time 
		pTempObj = new QTime
		pTempObj.pObject = QDateTime_time(pObject)
		return pTempObj

	Func timeSpec 
		return QDateTime_timeSpec(pObject)

	Func toLocalTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toLocalTime(pObject)
		return pTempObj

	Func toMSecsSinceEpoch 
		return QDateTime_toMSecsSinceEpoch(pObject)

	Func toString P1
		return QDateTime_toString(pObject,P1)

	Func toString_2 P1
		return QDateTime_toString_2(pObject,P1)

	Func toTimeSpec P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toTimeSpec(pObject,P1)
		return pTempObj

	Func toTime_t 
		return QDateTime_toTime_t(pObject)

	Func toUTC 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_toUTC(pObject)
		return pTempObj

	Func currentDateTime 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_currentDateTime(pObject)
		return pTempObj

	Func currentDateTimeUtc 
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_currentDateTimeUtc(pObject)
		return pTempObj

	Func currentMSecsSinceEpoch 
		return QDateTime_currentMSecsSinceEpoch(pObject)

	Func fromMSecsSinceEpoch P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromMSecsSinceEpoch(pObject,P1)
		return pTempObj

	Func fromString P1,P2
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromString(pObject,P1,P2)
		return pTempObj

	Func fromString_2 P1,P2
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromString_2(pObject,P1,P2)
		return pTempObj

	Func fromTime_t P1
		pTempObj = new QDateTime
		pTempObj.pObject = QDateTime_fromTime_t(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QScreen

	pObject

	Func init P1
		pObject = QScreen_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QScreen_delete(pObject)

	Func ObjectPointer
		return pObject

	Func angleBetween P1,P2
		return QScreen_angleBetween(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func availableGeometry 
		pTempObj = new QRect
		pTempObj.pObject = QScreen_availableGeometry(pObject)
		return pTempObj

	Func availableSize 
		pTempObj = new QSize
		pTempObj.pObject = QScreen_availableSize(pObject)
		return pTempObj

	Func availableVirtualGeometry 
		pTempObj = new QRect
		pTempObj.pObject = QScreen_availableVirtualGeometry(pObject)
		return pTempObj

	Func availableVirtualSize 
		pTempObj = new QSize
		pTempObj.pObject = QScreen_availableVirtualSize(pObject)
		return pTempObj

	Func depth 
		return QScreen_depth(pObject)

	Func devicePixelRatio 
		return QScreen_devicePixelRatio(pObject)

	Func geometry 
		pTempObj = new QRect
		pTempObj.pObject = QScreen_geometry(pObject)
		return pTempObj

	Func grabWindow P1,P2,P3,P4,P5
		pTempObj = new QPixmap
		pTempObj.pObject = QScreen_grabWindow(pObject,P1,P2,P3,P4,P5)
		return pTempObj

	Func grabWindow_2 P1
		pTempObj = new QPixmap
		pTempObj.pObject = QScreen_grabWindow_2(pObject,P1)
		return pTempObj

	Func handle 
		return QScreen_handle(pObject)

	Func isLandscape P1
		return QScreen_isLandscape(pObject,GetObjectPointerFromRingObject(P1))

	Func isPortrait P1
		return QScreen_isPortrait(pObject,GetObjectPointerFromRingObject(P1))

	Func logicalDotsPerInch 
		return QScreen_logicalDotsPerInch(pObject)

	Func logicalDotsPerInchX 
		return QScreen_logicalDotsPerInchX(pObject)

	Func logicalDotsPerInchY 
		return QScreen_logicalDotsPerInchY(pObject)

	Func mapBetween P1,P2,P3
		pTempObj = new QRect
		pTempObj.pObject = QScreen_mapBetween(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func name 
		return QScreen_name(pObject)

	Func nativeOrientation 
		return QScreen_nativeOrientation(pObject)

	Func orientation 
		return QScreen_orientation(pObject)

	Func orientationUpdateMask 
		return QScreen_orientationUpdateMask(pObject)

	Func physicalDotsPerInch 
		return QScreen_physicalDotsPerInch(pObject)

	Func physicalDotsPerInchX 
		return QScreen_physicalDotsPerInchX(pObject)

	Func physicalDotsPerInchY 
		return QScreen_physicalDotsPerInchY(pObject)

	Func physicalSize 
		return QScreen_physicalSize(pObject)

	Func primaryOrientation 
		return QScreen_primaryOrientation(pObject)

	Func refreshRate 
		return QScreen_refreshRate(pObject)

	Func setOrientationUpdateMask P1
		return QScreen_setOrientationUpdateMask(pObject,GetObjectPointerFromRingObject(P1))

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QScreen_size(pObject)
		return pTempObj

	Func transformBetween P1,P2,P3
		return QScreen_transformBetween(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

Class QWindow from QObject

	pObject

	Func init P1
		pObject = QWindow_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QWindow_delete(pObject)

	Func ObjectPointer
		return pObject

	Func baseSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_baseSize(pObject)
		return pTempObj

	Func contentOrientation 
		return QWindow_contentOrientation(pObject)

	Func create 
		return QWindow_create(pObject)

	Func cursor 
		pTempObj = new QCursor
		pTempObj.pObject = QWindow_cursor(pObject)
		return pTempObj

	Func destroy 
		return QWindow_destroy(pObject)

	Func devicePixelRatio 
		return QWindow_devicePixelRatio(pObject)

	Func filePath 
		return QWindow_filePath(pObject)

	Func flags 
		return QWindow_flags(pObject)

	Func focusObject 
		pTempObj = new QObject
		pTempObj.pObject = QWindow_focusObject(pObject)
		return pTempObj

	Func frameGeometry 
		pTempObj = new QRect
		pTempObj.pObject = QWindow_frameGeometry(pObject)
		return pTempObj

	Func frameMargins 
		return QWindow_frameMargins(pObject)

	Func framePosition 
		pTempObj = new QPoint
		pTempObj.pObject = QWindow_framePosition(pObject)
		return pTempObj

	Func geometry 
		pTempObj = new QRect
		pTempObj.pObject = QWindow_geometry(pObject)
		return pTempObj

	Func height 
		return QWindow_height(pObject)

	Func icon 
		pTempObj = new QIcon
		pTempObj.pObject = QWindow_icon(pObject)
		return pTempObj

	Func isActive 
		return QWindow_isActive(pObject)

	Func isAncestorOf P1,P2
		return QWindow_isAncestorOf(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func isExposed 
		return QWindow_isExposed(pObject)

	Func isModal 
		return QWindow_isModal(pObject)

	Func isTopLevel 
		return QWindow_isTopLevel(pObject)

	Func isVisible 
		return QWindow_isVisible(pObject)

	Func mapFromGlobal P1
		pTempObj = new QPoint
		pTempObj.pObject = QWindow_mapFromGlobal(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapToGlobal P1
		pTempObj = new QPoint
		pTempObj.pObject = QWindow_mapToGlobal(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mask 
		pTempObj = new QRegion
		pTempObj.pObject = QWindow_mask(pObject)
		return pTempObj

	Func maximumHeight 
		return QWindow_maximumHeight(pObject)

	Func maximumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_maximumSize(pObject)
		return pTempObj

	Func maximumWidth 
		return QWindow_maximumWidth(pObject)

	Func minimumHeight 
		return QWindow_minimumHeight(pObject)

	Func minimumSize 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_minimumSize(pObject)
		return pTempObj

	Func minimumWidth 
		return QWindow_minimumWidth(pObject)

	Func modality 
		return QWindow_modality(pObject)

	Func opacity 
		return QWindow_opacity(pObject)

	Func position 
		pTempObj = new QPoint
		pTempObj.pObject = QWindow_position(pObject)
		return pTempObj

	Func reportContentOrientationChange P1
		return QWindow_reportContentOrientationChange(pObject,GetObjectPointerFromRingObject(P1))

	Func requestedFormat 
		pTempObj = new QSurfaceFormat
		pTempObj.pObject = QWindow_requestedFormat(pObject)
		return pTempObj

	Func resize P1
		return QWindow_resize(pObject,GetObjectPointerFromRingObject(P1))

	Func resize_2 P1,P2
		return QWindow_resize_2(pObject,P1,P2)

	Func screen 
		pTempObj = new QScreen
		pTempObj.pObject = QWindow_screen(pObject)
		return pTempObj

	Func setBaseSize P1
		return QWindow_setBaseSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setCursor P1
		return QWindow_setCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setFilePath P1
		return QWindow_setFilePath(pObject,P1)

	Func setFlags P1
		return QWindow_setFlags(pObject,P1)

	Func setFormat P1
		return QWindow_setFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setFramePosition P1
		return QWindow_setFramePosition(pObject,GetObjectPointerFromRingObject(P1))

	Func setGeometry P1,P2,P3,P4
		return QWindow_setGeometry(pObject,P1,P2,P3,P4)

	Func setGeometry_2 P1
		return QWindow_setGeometry_2(pObject,GetObjectPointerFromRingObject(P1))

	Func setIcon P1
		return QWindow_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setKeyboardGrabEnabled P1
		return QWindow_setKeyboardGrabEnabled(pObject,P1)

	Func setMask P1
		return QWindow_setMask(pObject,GetObjectPointerFromRingObject(P1))

	Func setMaximumSize P1
		return QWindow_setMaximumSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumSize P1
		return QWindow_setMinimumSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setModality P1
		return QWindow_setModality(pObject,P1)

	Func setMouseGrabEnabled P1
		return QWindow_setMouseGrabEnabled(pObject,P1)

	Func setOpacity P1
		return QWindow_setOpacity(pObject,P1)

	Func setParent P1
		return QWindow_setParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setPosition P1
		return QWindow_setPosition(pObject,GetObjectPointerFromRingObject(P1))

	Func setPosition_2 P1,P2
		return QWindow_setPosition_2(pObject,P1,P2)

	Func setScreen P1
		return QWindow_setScreen(pObject,GetObjectPointerFromRingObject(P1))

	Func setSizeIncrement P1
		return QWindow_setSizeIncrement(pObject,GetObjectPointerFromRingObject(P1))

	Func setTransientParent P1
		return QWindow_setTransientParent(pObject,GetObjectPointerFromRingObject(P1))

	Func setVisibility P1
		return QWindow_setVisibility(pObject,P1)

	Func setWindowState P1
		return QWindow_setWindowState(pObject,P1)

	Func sizeIncrement 
		pTempObj = new QSize
		pTempObj.pObject = QWindow_sizeIncrement(pObject)
		return pTempObj

	Func title 
		return QWindow_title(pObject)

	Func transientParent 
		pTempObj = new QWindow
		pTempObj.pObject = QWindow_transientParent(pObject)
		return pTempObj

	Func type 
		return QWindow_type(pObject)

	Func unsetCursor 
		return QWindow_unsetCursor(pObject)

	Func visibility 
		return QWindow_visibility(pObject)

	Func width 
		return QWindow_width(pObject)

	Func winId 
		return QWindow_winId(pObject)

	Func windowState 
		return QWindow_windowState(pObject)

	Func x 
		return QWindow_x(pObject)

	Func y 
		return QWindow_y(pObject)

	Func alert P1
		return QWindow_alert(pObject,P1)

	Func close 
		return QWindow_close(pObject)

	Func hide 
		return QWindow_hide(pObject)

	Func lower 
		return QWindow_lower(pObject)

	Func raise 
		return QWindow_raise(pObject)

	Func requestActivate 
		return QWindow_requestActivate(pObject)

	Func setHeight P1
		return QWindow_setHeight(pObject,P1)

	Func setMaximumHeight P1
		return QWindow_setMaximumHeight(pObject,P1)

	Func setMaximumWidth P1
		return QWindow_setMaximumWidth(pObject,P1)

	Func setMinimumHeight P1
		return QWindow_setMinimumHeight(pObject,P1)

	Func setMinimumWidth P1
		return QWindow_setMinimumWidth(pObject,P1)

	Func setTitle P1
		return QWindow_setTitle(pObject,P1)

	Func setVisible P1
		return QWindow_setVisible(pObject,P1)

	Func setWidth P1
		return QWindow_setWidth(pObject,P1)

	Func setX P1
		return QWindow_setX(pObject,P1)

	Func setY P1
		return QWindow_setY(pObject,P1)

	Func show 
		return QWindow_show(pObject)

	Func showFullScreen 
		return QWindow_showFullScreen(pObject)

	Func showMaximized 
		return QWindow_showMaximized(pObject)

	Func showMinimized 
		return QWindow_showMinimized(pObject)

	Func showNormal 
		return QWindow_showNormal(pObject)

	Func fromWinId P1
		pTempObj = new QWindow
		pTempObj.pObject = QWindow_fromWinId(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func setactiveChangedEvent P1
		return QWindow_setactiveChangedEvent(pObject,P1)

	Func setcontentOrientationChangedEvent P1
		return QWindow_setcontentOrientationChangedEvent(pObject,P1)

	Func setfocusObjectChangedEvent P1
		return QWindow_setfocusObjectChangedEvent(pObject,P1)

	Func setheightChangedEvent P1
		return QWindow_setheightChangedEvent(pObject,P1)

	Func setmaximumHeightChangedEvent P1
		return QWindow_setmaximumHeightChangedEvent(pObject,P1)

	Func setmaximumWidthChangedEvent P1
		return QWindow_setmaximumWidthChangedEvent(pObject,P1)

	Func setminimumHeightChangedEvent P1
		return QWindow_setminimumHeightChangedEvent(pObject,P1)

	Func setminimumWidthChangedEvent P1
		return QWindow_setminimumWidthChangedEvent(pObject,P1)

	Func setmodalityChangedEvent P1
		return QWindow_setmodalityChangedEvent(pObject,P1)

	Func setopacityChangedEvent P1
		return QWindow_setopacityChangedEvent(pObject,P1)

	Func setscreenChangedEvent P1
		return QWindow_setscreenChangedEvent(pObject,P1)

	Func setvisibilityChangedEvent P1
		return QWindow_setvisibilityChangedEvent(pObject,P1)

	Func setvisibleChangedEvent P1
		return QWindow_setvisibleChangedEvent(pObject,P1)

	Func setwidthChangedEvent P1
		return QWindow_setwidthChangedEvent(pObject,P1)

	Func setwindowStateChangedEvent P1
		return QWindow_setwindowStateChangedEvent(pObject,P1)

	Func setwindowTitleChangedEvent P1
		return QWindow_setwindowTitleChangedEvent(pObject,P1)

	Func setxChangedEvent P1
		return QWindow_setxChangedEvent(pObject,P1)

	Func setyChangedEvent P1
		return QWindow_setyChangedEvent(pObject,P1)

	Func getactiveChangedEvent 
		return QWindow_getactiveChangedEvent(pObject)

	Func getcontentOrientationChangedEvent 
		return QWindow_getcontentOrientationChangedEvent(pObject)

	Func getfocusObjectChangedEvent 
		return QWindow_getfocusObjectChangedEvent(pObject)

	Func getheightChangedEvent 
		return QWindow_getheightChangedEvent(pObject)

	Func getmaximumHeightChangedEvent 
		return QWindow_getmaximumHeightChangedEvent(pObject)

	Func getmaximumWidthChangedEvent 
		return QWindow_getmaximumWidthChangedEvent(pObject)

	Func getminimumHeightChangedEvent 
		return QWindow_getminimumHeightChangedEvent(pObject)

	Func getminimumWidthChangedEvent 
		return QWindow_getminimumWidthChangedEvent(pObject)

	Func getmodalityChangedEvent 
		return QWindow_getmodalityChangedEvent(pObject)

	Func getopacityChangedEvent 
		return QWindow_getopacityChangedEvent(pObject)

	Func getscreenChangedEvent 
		return QWindow_getscreenChangedEvent(pObject)

	Func getvisibilityChangedEvent 
		return QWindow_getvisibilityChangedEvent(pObject)

	Func getvisibleChangedEvent 
		return QWindow_getvisibleChangedEvent(pObject)

	Func getwidthChangedEvent 
		return QWindow_getwidthChangedEvent(pObject)

	Func getwindowStateChangedEvent 
		return QWindow_getwindowStateChangedEvent(pObject)

	Func getwindowTitleChangedEvent 
		return QWindow_getwindowTitleChangedEvent(pObject)

	Func getxChangedEvent 
		return QWindow_getxChangedEvent(pObject)

	Func getyChangedEvent 
		return QWindow_getyChangedEvent(pObject)

Class QGuiApplication from QCoreApplication

	pObject

	Func init P1,P2
		pObject = QGuiApplication_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QGuiApplication_delete(pObject)

	Func ObjectPointer
		return pObject

	Func devicePixelRatio 
		return QGuiApplication_devicePixelRatio(pObject)

	Func isSavingSession 
		return QGuiApplication_isSavingSession(pObject)

	Func isSessionRestored 
		return QGuiApplication_isSessionRestored(pObject)

	Func sessionId 
		return QGuiApplication_sessionId(pObject)

	Func sessionKey 
		return QGuiApplication_sessionKey(pObject)

	Func allWindows 
		return QGuiApplication_allWindows(pObject)

	Func applicationDisplayName 
		return QGuiApplication_applicationDisplayName(pObject)

	Func applicationState 
		return QGuiApplication_applicationState(pObject)

	Func changeOverrideCursor P1
		return QGuiApplication_changeOverrideCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func clipboard 
		return QGuiApplication_clipboard(pObject)

	Func desktopSettingsAware 
		return QGuiApplication_desktopSettingsAware(pObject)

	Func exec 
		return QGuiApplication_exec(pObject)

	Func focusObject 
		pTempObj = new QObject
		pTempObj.pObject = QGuiApplication_focusObject(pObject)
		return pTempObj

	Func focusWindow 
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_focusWindow(pObject)
		return pTempObj

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QGuiApplication_font(pObject)
		return pTempObj

	Func inputMethod 
		return QGuiApplication_inputMethod(pObject)

	Func isLeftToRight 
		return QGuiApplication_isLeftToRight(pObject)

	Func isRightToLeft 
		return QGuiApplication_isRightToLeft(pObject)

	Func keyboardModifiers 
		return QGuiApplication_keyboardModifiers(pObject)

	Func layoutDirection 
		return QGuiApplication_layoutDirection(pObject)

	Func modalWindow 
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_modalWindow(pObject)
		return pTempObj

	Func mouseButtons 
		return QGuiApplication_mouseButtons(pObject)

	Func overrideCursor 
		pTempObj = new QCursor
		pTempObj.pObject = QGuiApplication_overrideCursor(pObject)
		return pTempObj

	Func palette 
		return QGuiApplication_palette(pObject)

	Func platformName 
		return QGuiApplication_platformName(pObject)

	Func platformNativeInterface 
		return QGuiApplication_platformNativeInterface(pObject)

	Func primaryScreen 
		pTempObj = new QScreen
		pTempObj.pObject = QGuiApplication_primaryScreen(pObject)
		return pTempObj

	Func queryKeyboardModifiers 
		return QGuiApplication_queryKeyboardModifiers(pObject)

	Func quitOnLastWindowClosed 
		return QGuiApplication_quitOnLastWindowClosed(pObject)

	Func restoreOverrideCursor 
		return QGuiApplication_restoreOverrideCursor(pObject)

	Func screens 
		return QGuiApplication_screens(pObject)

	Func setApplicationDisplayName P1
		return QGuiApplication_setApplicationDisplayName(pObject,P1)

	Func setDesktopSettingsAware P1
		return QGuiApplication_setDesktopSettingsAware(pObject,P1)

	Func setFont P1
		return QGuiApplication_setFont(pObject,GetObjectPointerFromRingObject(P1))

	Func setLayoutDirection P1
		return QGuiApplication_setLayoutDirection(pObject,P1)

	Func setOverrideCursor P1
		return QGuiApplication_setOverrideCursor(pObject,GetObjectPointerFromRingObject(P1))

	Func setPalette P1
		return QGuiApplication_setPalette(pObject,GetObjectPointerFromRingObject(P1))

	Func setQuitOnLastWindowClosed P1
		return QGuiApplication_setQuitOnLastWindowClosed(pObject,P1)

	Func styleHints 
		return QGuiApplication_styleHints(pObject)

	Func sync 
		return QGuiApplication_sync(pObject)

	Func topLevelAt P1
		pTempObj = new QWindow
		pTempObj.pObject = QGuiApplication_topLevelAt(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func topLevelWindows 
		return QGuiApplication_topLevelWindows(pObject)

	Func setapplicationDisplayNameChangedEvent P1
		return QGuiApplication_setapplicationDisplayNameChangedEvent(pObject,P1)

	Func setapplicationStateChangedEvent P1
		return QGuiApplication_setapplicationStateChangedEvent(pObject,P1)

	Func setcommitDataRequestEvent P1
		return QGuiApplication_setcommitDataRequestEvent(pObject,P1)

	Func setfocusObjectChangedEvent P1
		return QGuiApplication_setfocusObjectChangedEvent(pObject,P1)

	Func setfocusWindowChangedEvent P1
		return QGuiApplication_setfocusWindowChangedEvent(pObject,P1)

	Func setfontDatabaseChangedEvent P1
		return QGuiApplication_setfontDatabaseChangedEvent(pObject,P1)

	Func setlastWindowClosedEvent P1
		return QGuiApplication_setlastWindowClosedEvent(pObject,P1)

	Func setlayoutDirectionChangedEvent P1
		return QGuiApplication_setlayoutDirectionChangedEvent(pObject,P1)

	Func setpaletteChangedEvent P1
		return QGuiApplication_setpaletteChangedEvent(pObject,P1)

	Func setprimaryScreenChangedEvent P1
		return QGuiApplication_setprimaryScreenChangedEvent(pObject,P1)

	Func setsaveStateRequestEvent P1
		return QGuiApplication_setsaveStateRequestEvent(pObject,P1)

	Func setscreenAddedEvent P1
		return QGuiApplication_setscreenAddedEvent(pObject,P1)

	Func setscreenRemovedEvent P1
		return QGuiApplication_setscreenRemovedEvent(pObject,P1)

	Func getapplicationDisplayNameChangedEvent 
		return QGuiApplication_getapplicationDisplayNameChangedEvent(pObject)

	Func getapplicationStateChangedEvent 
		return QGuiApplication_getapplicationStateChangedEvent(pObject)

	Func getcommitDataRequestEvent 
		return QGuiApplication_getcommitDataRequestEvent(pObject)

	Func getfocusObjectChangedEvent 
		return QGuiApplication_getfocusObjectChangedEvent(pObject)

	Func getfocusWindowChangedEvent 
		return QGuiApplication_getfocusWindowChangedEvent(pObject)

	Func getfontDatabaseChangedEvent 
		return QGuiApplication_getfontDatabaseChangedEvent(pObject)

	Func getlastWindowClosedEvent 
		return QGuiApplication_getlastWindowClosedEvent(pObject)

	Func getlayoutDirectionChangedEvent 
		return QGuiApplication_getlayoutDirectionChangedEvent(pObject)

	Func getpaletteChangedEvent 
		return QGuiApplication_getpaletteChangedEvent(pObject)

	Func getprimaryScreenChangedEvent 
		return QGuiApplication_getprimaryScreenChangedEvent(pObject)

	Func getsaveStateRequestEvent 
		return QGuiApplication_getsaveStateRequestEvent(pObject)

	Func getscreenAddedEvent 
		return QGuiApplication_getscreenAddedEvent(pObject)

	Func getscreenRemovedEvent 
		return QGuiApplication_getscreenRemovedEvent(pObject)

Class QCoreApplication from QObject
	Func installNativeEventFilter P1
		return QCoreApplication_installNativeEventFilter(GetObjectPointerFromRingObject(P1))

	Func removeNativeEventFilter P1
		return QCoreApplication_removeNativeEventFilter(GetObjectPointerFromRingObject(P1))

	Func quit 
		return QCoreApplication_quit()

	Func addLibraryPath P1
		return QCoreApplication_addLibraryPath(P1)

	Func applicationDirPath 
		return QCoreApplication_applicationDirPath()

	Func applicationFilePath 
		return QCoreApplication_applicationFilePath()

	Func applicationName 
		return QCoreApplication_applicationName()

	Func applicationPid 
		return QCoreApplication_applicationPid()

	Func applicationVersion 
		return QCoreApplication_applicationVersion()

	Func arguments 
		pTempObj = new QStringList
		pTempObj.pObject = QCoreApplication_arguments()
		return pTempObj

	Func closingDown 
		return QCoreApplication_closingDown()

	Func eventDispatcher 
		return QCoreApplication_eventDispatcher()

	Func exec 
		return QCoreApplication_exec()

	Func exitfromapplication P1
		return QCoreApplication_exit(P1)

	Func installTranslator P1
		return QCoreApplication_installTranslator(GetObjectPointerFromRingObject(P1))

	Func instance 
		return QCoreApplication_instance()

	Func isQuitLockEnabled 
		return QCoreApplication_isQuitLockEnabled()

	Func libraryPaths 
		pTempObj = new QStringList
		pTempObj.pObject = QCoreApplication_libraryPaths()
		return pTempObj

	Func organizationDomain 
		return QCoreApplication_organizationDomain()

	Func organizationName 
		return QCoreApplication_organizationName()

	Func postEvent P1,P2,P3
		return QCoreApplication_postEvent(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)

	Func processEvents P1
		return QCoreApplication_processEvents(P1)

	Func processEvents_2 P1,P2
		return QCoreApplication_processEvents_2(P1,P2)

	Func removeLibraryPath P1
		return QCoreApplication_removeLibraryPath(P1)

	Func removePostedEvents P1,P2
		return QCoreApplication_removePostedEvents(GetObjectPointerFromRingObject(P1),P2)

	Func removeTranslator P1
		return QCoreApplication_removeTranslator(GetObjectPointerFromRingObject(P1))

	Func sendEvent P1,P2
		return QCoreApplication_sendEvent(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func sendPostedEvents P1,P2
		return QCoreApplication_sendPostedEvents(GetObjectPointerFromRingObject(P1),P2)

	Func setApplicationName P1
		return QCoreApplication_setApplicationName(P1)

	Func setApplicationVersion P1
		return QCoreApplication_setApplicationVersion(P1)

	Func setAttribute P1,P2
		return QCoreApplication_setAttribute(P1,P2)

	Func setEventDispatcher P1
		return QCoreApplication_setEventDispatcher(GetObjectPointerFromRingObject(P1))

	Func setLibraryPaths P1
		return QCoreApplication_setLibraryPaths(GetObjectPointerFromRingObject(P1))

	Func setOrganizationDomain P1
		return QCoreApplication_setOrganizationDomain(P1)

	Func setOrganizationName P1
		return QCoreApplication_setOrganizationName(P1)

	Func setQuitLockEnabled P1
		return QCoreApplication_setQuitLockEnabled(P1)

	Func startingUp 
		return QCoreApplication_startingUp()

	Func testAttribute P1
		return QCoreApplication_testAttribute(P1)

	Func translate P1,P2,P3,P4
		return QCoreApplication_translate(P1,P2,P3,P4)

Class QTextBrowser from QTextEdit

	pObject

	Func init P1
		pObject = QTextBrowser_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTextBrowser_delete(pObject)

	Func ObjectPointer
		return pObject

	Func backwardHistoryCount 
		return QTextBrowser_backwardHistoryCount(pObject)

	Func clearHistory 
		return QTextBrowser_clearHistory(pObject)

	Func forwardHistoryCount 
		return QTextBrowser_forwardHistoryCount(pObject)

	Func historyTitle P1
		return QTextBrowser_historyTitle(pObject,P1)

	Func historyUrl P1
		pTempObj = new QUrl
		pTempObj.pObject = QTextBrowser_historyUrl(pObject,P1)
		return pTempObj

	Func isBackwardAvailable 
		return QTextBrowser_isBackwardAvailable(pObject)

	Func isForwardAvailable 
		return QTextBrowser_isForwardAvailable(pObject)

	Func openExternalLinks 
		return QTextBrowser_openExternalLinks(pObject)

	Func openLinks 
		return QTextBrowser_openLinks(pObject)

	Func searchPaths 
		pTempObj = new QStringList
		pTempObj.pObject = QTextBrowser_searchPaths(pObject)
		return pTempObj

	Func setOpenExternalLinks P1
		return QTextBrowser_setOpenExternalLinks(pObject,P1)

	Func setOpenLinks P1
		return QTextBrowser_setOpenLinks(pObject,P1)

	Func setSearchPaths P1
		return QTextBrowser_setSearchPaths(pObject,GetObjectPointerFromRingObject(P1))

	Func source 
		pTempObj = new QUrl
		pTempObj.pObject = QTextBrowser_source(pObject)
		return pTempObj

	Func setanchorClickedEvent P1
		return QTextBrowser_setanchorClickedEvent(pObject,P1)

	Func setbackwardAvailableEvent P1
		return QTextBrowser_setbackwardAvailableEvent(pObject,P1)

	Func setforwardAvailableEvent P1
		return QTextBrowser_setforwardAvailableEvent(pObject,P1)

	Func sethighlightedEvent P1
		return QTextBrowser_sethighlightedEvent(pObject,P1)

	Func sethistoryChangedEvent P1
		return QTextBrowser_sethistoryChangedEvent(pObject,P1)

	Func setsourceChangedEvent P1
		return QTextBrowser_setsourceChangedEvent(pObject,P1)

	Func getanchorClickedEvent 
		return QTextBrowser_getanchorClickedEvent(pObject)

	Func getbackwardAvailableEvent 
		return QTextBrowser_getbackwardAvailableEvent(pObject)

	Func getforwardAvailableEvent 
		return QTextBrowser_getforwardAvailableEvent(pObject)

	Func gethighlightedEvent 
		return QTextBrowser_gethighlightedEvent(pObject)

	Func gethistoryChangedEvent 
		return QTextBrowser_gethistoryChangedEvent(pObject)

	Func getsourceChangedEvent 
		return QTextBrowser_getsourceChangedEvent(pObject)

Class QRegion

	pObject

	Func init 
		pObject = QRegion_new()
		return self

	Func delete
		pObject = QRegion_delete(pObject)

	Func ObjectPointer
		return pObject

	Func boundingRect 
		pTempObj = new QRect
		pTempObj.pObject = QRegion_boundingRect(pObject)
		return pTempObj

	Func contains P1
		return QRegion_contains(pObject,GetObjectPointerFromRingObject(P1))

	Func contains_2 P1
		return QRegion_contains_2(pObject,GetObjectPointerFromRingObject(P1))

	Func intersected P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_intersected(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func intersected_2 P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_intersected_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func intersects P1
		return QRegion_intersects(pObject,GetObjectPointerFromRingObject(P1))

	Func intersects_2 P1
		return QRegion_intersects_2(pObject,GetObjectPointerFromRingObject(P1))

	Func isEmpty 
		return QRegion_isEmpty(pObject)

	Func isNull 
		return QRegion_isNull(pObject)

	Func rectCount 
		return QRegion_rectCount(pObject)

	Func rects 
		return QRegion_rects(pObject)

	Func setRects P1,P2
		return QRegion_setRects(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func subtracted P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_subtracted(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func swap P1
		return QRegion_swap(pObject,GetObjectPointerFromRingObject(P1))

	Func translate P1,P2
		return QRegion_translate(pObject,P1,P2)

	Func translate_2 P1
		return QRegion_translate_2(pObject,GetObjectPointerFromRingObject(P1))

	Func translated P1,P2
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_translated(pObject,P1,P2)
		return pTempObj

	Func translated_2 P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_translated_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func united P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_united(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func united_2 P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_united_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func xored P1
		pTempObj = new QRegion
		pTempObj.pObject = QRegion_xored(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

Class QStackedWidget from QFrame

	pObject

	Func init P1
		pObject = QStackedWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QStackedWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addWidget P1
		return QStackedWidget_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func count 
		return QStackedWidget_count(pObject)

	Func currentIndex 
		return QStackedWidget_currentIndex(pObject)

	Func currentWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QStackedWidget_currentWidget(pObject)
		return pTempObj

	Func indexOf P1
		return QStackedWidget_indexOf(pObject,GetObjectPointerFromRingObject(P1))

	Func insertWidget P1,P2
		return QStackedWidget_insertWidget(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func removeWidget P1
		return QStackedWidget_removeWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func widget P1
		pTempObj = new QWidget
		pTempObj.pObject = QStackedWidget_widget(pObject,P1)
		return pTempObj

	Func setCurrentIndex P1
		return QStackedWidget_setCurrentIndex(pObject,P1)

	Func setCurrentWidget P1
		return QStackedWidget_setCurrentWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func setcurrentChangedEvent P1
		return QStackedWidget_setcurrentChangedEvent(pObject,P1)

	Func setwidgetRemovedEvent P1
		return QStackedWidget_setwidgetRemovedEvent(pObject,P1)

	Func getcurrentChangedEvent 
		return QStackedWidget_getcurrentChangedEvent(pObject)

	Func getwidgetRemovedEvent 
		return QStackedWidget_getwidgetRemovedEvent(pObject)

Class QCalendarWidget from QWidget

	pObject

	Func init P1
		pObject = QCalendarWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QCalendarWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func dateEditAcceptDelay 
		return QCalendarWidget_dateEditAcceptDelay(pObject)

	Func dateTextFormat 
		return QCalendarWidget_dateTextFormat(pObject)

	Func dateTextFormat_2 P1
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QCalendarWidget_dateTextFormat_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func firstDayOfWeek 
		return QCalendarWidget_firstDayOfWeek(pObject)

	Func headerTextFormat 
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QCalendarWidget_headerTextFormat(pObject)
		return pTempObj

	Func horizontalHeaderFormat 
		return QCalendarWidget_horizontalHeaderFormat(pObject)

	Func isDateEditEnabled 
		return QCalendarWidget_isDateEditEnabled(pObject)

	Func isGridVisible 
		return QCalendarWidget_isGridVisible(pObject)

	Func isNavigationBarVisible 
		return QCalendarWidget_isNavigationBarVisible(pObject)

	Func maximumDate 
		pTempObj = new QDate
		pTempObj.pObject = QCalendarWidget_maximumDate(pObject)
		return pTempObj

	Func minimumDate 
		pTempObj = new QDate
		pTempObj.pObject = QCalendarWidget_minimumDate(pObject)
		return pTempObj

	Func monthShown 
		return QCalendarWidget_monthShown(pObject)

	Func selectedDate 
		pTempObj = new QDate
		pTempObj.pObject = QCalendarWidget_selectedDate(pObject)
		return pTempObj

	Func selectionMode 
		return QCalendarWidget_selectionMode(pObject)

	Func setDateEditAcceptDelay P1
		return QCalendarWidget_setDateEditAcceptDelay(pObject,P1)

	Func setDateEditEnabled P1
		return QCalendarWidget_setDateEditEnabled(pObject,P1)

	Func setDateTextFormat P1,P2
		return QCalendarWidget_setDateTextFormat(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setFirstDayOfWeek P1
		return QCalendarWidget_setFirstDayOfWeek(pObject,GetObjectPointerFromRingObject(P1))

	Func setHeaderTextFormat P1
		return QCalendarWidget_setHeaderTextFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setHorizontalHeaderFormat P1
		return QCalendarWidget_setHorizontalHeaderFormat(pObject,P1)

	Func setMaximumDate P1
		return QCalendarWidget_setMaximumDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setMinimumDate P1
		return QCalendarWidget_setMinimumDate(pObject,GetObjectPointerFromRingObject(P1))

	Func setSelectionMode P1
		return QCalendarWidget_setSelectionMode(pObject,P1)

	Func setVerticalHeaderFormat P1
		return QCalendarWidget_setVerticalHeaderFormat(pObject,P1)

	Func setWeekdayTextFormat P1,P2
		return QCalendarWidget_setWeekdayTextFormat(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func verticalHeaderFormat 
		return QCalendarWidget_verticalHeaderFormat(pObject)

	Func weekdayTextFormat P1
		pTempObj = new QTextCharFormat
		pTempObj.pObject = QCalendarWidget_weekdayTextFormat(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func yearShown 
		return QCalendarWidget_yearShown(pObject)

	Func setCurrentPage P1,P2
		return QCalendarWidget_setCurrentPage(pObject,P1,P2)

	Func setDateRange P1,P2
		return QCalendarWidget_setDateRange(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func setGridVisible P1
		return QCalendarWidget_setGridVisible(pObject,P1)

	Func setNavigationBarVisible P1
		return QCalendarWidget_setNavigationBarVisible(pObject,P1)

	Func setSelectedDate P1
		return QCalendarWidget_setSelectedDate(pObject,GetObjectPointerFromRingObject(P1))

	Func showNextMonth 
		return QCalendarWidget_showNextMonth(pObject)

	Func showNextYear 
		return QCalendarWidget_showNextYear(pObject)

	Func showPreviousMonth 
		return QCalendarWidget_showPreviousMonth(pObject)

	Func showPreviousYear 
		return QCalendarWidget_showPreviousYear(pObject)

	Func showSelectedDate 
		return QCalendarWidget_showSelectedDate(pObject)

	Func showToday 
		return QCalendarWidget_showToday(pObject)

	Func setactivatedEvent P1
		return QCalendarWidget_setactivatedEvent(pObject,P1)

	Func setclickedEvent P1
		return QCalendarWidget_setclickedEvent(pObject,P1)

	Func setcurrentPageChangedEvent P1
		return QCalendarWidget_setcurrentPageChangedEvent(pObject,P1)

	Func setselectionChangedEvent P1
		return QCalendarWidget_setselectionChangedEvent(pObject,P1)

	Func getactivatedEvent 
		return QCalendarWidget_getactivatedEvent(pObject)

	Func getclickedEvent 
		return QCalendarWidget_getclickedEvent(pObject)

	Func getcurrentPageChangedEvent 
		return QCalendarWidget_getcurrentPageChangedEvent(pObject)

	Func getselectionChangedEvent 
		return QCalendarWidget_getselectionChangedEvent(pObject)

Class QOpenGLFunctions

	pObject

	Func init 
		pObject = QOpenGLFunctions_new()
		return self

	Func delete
		pObject = QOpenGLFunctions_delete(pObject)

	Func ObjectPointer
		return pObject

	Func glActiveTexture P1
		return QOpenGLFunctions_glActiveTexture(pObject,P1)

	Func glAttachShader P1,P2
		return QOpenGLFunctions_glAttachShader(pObject,P1,P2)

	Func glBindAttribLocation P1,P2,P3
		return QOpenGLFunctions_glBindAttribLocation(pObject,P1,P2,P3)

	Func glBindBuffer P1,P2
		return QOpenGLFunctions_glBindBuffer(pObject,P1,P2)

	Func glBindFramebuffer P1,P2
		return QOpenGLFunctions_glBindFramebuffer(pObject,P1,P2)

	Func glBindRenderbuffer P1,P2
		return QOpenGLFunctions_glBindRenderbuffer(pObject,P1,P2)

	Func glBindTexture P1,P2
		return QOpenGLFunctions_glBindTexture(pObject,P1,P2)

	Func glBlendColor P1,P2,P3,P4
		return QOpenGLFunctions_glBlendColor(pObject,P1,P2,P3,P4)

	Func glBlendEquation P1
		return QOpenGLFunctions_glBlendEquation(pObject,P1)

	Func glBlendEquationSeparate P1,P2
		return QOpenGLFunctions_glBlendEquationSeparate(pObject,P1,P2)

	Func glBlendFunc P1,P2
		return QOpenGLFunctions_glBlendFunc(pObject,P1,P2)

	Func glBlendFuncSeparate P1,P2,P3,P4
		return QOpenGLFunctions_glBlendFuncSeparate(pObject,P1,P2,P3,P4)

	Func glBufferData P1,P2,P3,P4
		return QOpenGLFunctions_glBufferData(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),P4)

	Func glBufferSubData P1,P2,P3,P4
		return QOpenGLFunctions_glBufferSubData(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glCheckFramebufferStatus P1
		return QOpenGLFunctions_glCheckFramebufferStatus(pObject,P1)

	Func glClear P1
		return QOpenGLFunctions_glClear(pObject,P1)

	Func glClearColor P1,P2,P3,P4
		return QOpenGLFunctions_glClearColor(pObject,P1,P2,P3,P4)

	Func glClearDepthf P1
		return QOpenGLFunctions_glClearDepthf(pObject,P1)

	Func glClearStencil P1
		return QOpenGLFunctions_glClearStencil(pObject,P1)

	Func glColorMask P1,P2,P3,P4
		return QOpenGLFunctions_glColorMask(pObject,P1,P2,P3,P4)

	Func glCompileShader P1
		return QOpenGLFunctions_glCompileShader(pObject,P1)

	Func glCompressedTexImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_glCompressedTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8))

	Func glCompressedTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_glCompressedTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glCopyTexImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_glCopyTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8)

	Func glCopyTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_glCopyTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8)

	Func glCreateProgram 
		return QOpenGLFunctions_glCreateProgram(pObject)

	Func glCreateShader P1
		return QOpenGLFunctions_glCreateShader(pObject,P1)

	Func glCullFace P1
		return QOpenGLFunctions_glCullFace(pObject,P1)

	Func glDeleteBuffers P1,P2
		return QOpenGLFunctions_glDeleteBuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteFramebuffers P1,P2
		return QOpenGLFunctions_glDeleteFramebuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteProgram P1
		return QOpenGLFunctions_glDeleteProgram(pObject,P1)

	Func glDeleteRenderbuffers P1,P2
		return QOpenGLFunctions_glDeleteRenderbuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteShader P1
		return QOpenGLFunctions_glDeleteShader(pObject,P1)

	Func glDeleteTextures P1,P2
		return QOpenGLFunctions_glDeleteTextures(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDepthFunc P1
		return QOpenGLFunctions_glDepthFunc(pObject,P1)

	Func glDepthMask P1
		return QOpenGLFunctions_glDepthMask(pObject,P1)

	Func glDepthRangef P1,P2
		return QOpenGLFunctions_glDepthRangef(pObject,P1,P2)

	Func glDetachShader P1,P2
		return QOpenGLFunctions_glDetachShader(pObject,P1,P2)

	Func glDisable P1
		return QOpenGLFunctions_glDisable(pObject,P1)

	Func glDisableVertexAttribArray P1
		return QOpenGLFunctions_glDisableVertexAttribArray(pObject,P1)

	Func glDrawArrays P1,P2,P3
		return QOpenGLFunctions_glDrawArrays(pObject,P1,P2,P3)

	Func glDrawElements P1,P2,P3,P4
		return QOpenGLFunctions_glDrawElements(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glEnable P1
		return QOpenGLFunctions_glEnable(pObject,P1)

	Func glEnableVertexAttribArray P1
		return QOpenGLFunctions_glEnableVertexAttribArray(pObject,P1)

	Func glFinish 
		return QOpenGLFunctions_glFinish(pObject)

	Func glFlush 
		return QOpenGLFunctions_glFlush(pObject)

	Func glFramebufferRenderbuffer P1,P2,P3,P4
		return QOpenGLFunctions_glFramebufferRenderbuffer(pObject,P1,P2,P3,P4)

	Func glFramebufferTexture2D P1,P2,P3,P4,P5
		return QOpenGLFunctions_glFramebufferTexture2D(pObject,P1,P2,P3,P4,P5)

	Func glFrontFace P1
		return QOpenGLFunctions_glFrontFace(pObject,P1)

	Func glGenBuffers P1,P2
		return QOpenGLFunctions_glGenBuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenFramebuffers P1,P2
		return QOpenGLFunctions_glGenFramebuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenRenderbuffers P1,P2
		return QOpenGLFunctions_glGenRenderbuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenTextures P1,P2
		return QOpenGLFunctions_glGenTextures(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenerateMipmap P1
		return QOpenGLFunctions_glGenerateMipmap(pObject,P1)

	Func glGetActiveAttrib P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_glGetActiveAttrib(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),P7)

	Func glGetActiveUniform P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_glGetActiveUniform(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),P7)

	Func glGetAttachedShaders P1,P2,P3,P4
		return QOpenGLFunctions_glGetAttachedShaders(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetAttribLocation P1,P2
		return QOpenGLFunctions_glGetAttribLocation(pObject,P1,P2)

	Func glGetBooleanv P1,P2
		return QOpenGLFunctions_glGetBooleanv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetBufferParameteriv P1,P2,P3
		return QOpenGLFunctions_glGetBufferParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetError 
		return QOpenGLFunctions_glGetError(pObject)

	Func glGetFloatv P1,P2
		return QOpenGLFunctions_glGetFloatv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetFramebufferAttachmentParameteriv P1,P2,P3,P4
		return QOpenGLFunctions_glGetFramebufferAttachmentParameteriv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetIntegerv P1,P2
		return QOpenGLFunctions_glGetIntegerv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetProgramInfoLog P1,P2,P3,P4
		return QOpenGLFunctions_glGetProgramInfoLog(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4)

	Func glGetProgramiv P1,P2,P3
		return QOpenGLFunctions_glGetProgramiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetRenderbufferParameteriv P1,P2,P3
		return QOpenGLFunctions_glGetRenderbufferParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetShaderInfoLog P1,P2,P3,P4
		return QOpenGLFunctions_glGetShaderInfoLog(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4)

	Func glGetShaderPrecisionFormat P1,P2,P3,P4
		return QOpenGLFunctions_glGetShaderPrecisionFormat(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetShaderSource P1,P2,P3,P4
		return QOpenGLFunctions_glGetShaderSource(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4)

	Func glGetShaderiv P1,P2,P3
		return QOpenGLFunctions_glGetShaderiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetString P1
		return QOpenGLFunctions_glGetString(pObject,P1)

	Func glGetTexParameterfv P1,P2,P3
		return QOpenGLFunctions_glGetTexParameterfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetTexParameteriv P1,P2,P3
		return QOpenGLFunctions_glGetTexParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetUniformLocation P1,P2
		return QOpenGLFunctions_glGetUniformLocation(pObject,P1,P2)

	Func glGetUniformfv P1,P2,P3
		return QOpenGLFunctions_glGetUniformfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetUniformiv P1,P2,P3
		return QOpenGLFunctions_glGetUniformiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribfv P1,P2,P3
		return QOpenGLFunctions_glGetVertexAttribfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribiv P1,P2,P3
		return QOpenGLFunctions_glGetVertexAttribiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glHint P1,P2
		return QOpenGLFunctions_glHint(pObject,P1,P2)

	Func glIsBuffer P1
		return QOpenGLFunctions_glIsBuffer(pObject,P1)

	Func glIsEnabled P1
		return QOpenGLFunctions_glIsEnabled(pObject,P1)

	Func glIsFramebuffer P1
		return QOpenGLFunctions_glIsFramebuffer(pObject,P1)

	Func glIsProgram P1
		return QOpenGLFunctions_glIsProgram(pObject,P1)

	Func glIsRenderbuffer P1
		return QOpenGLFunctions_glIsRenderbuffer(pObject,P1)

	Func glIsShader P1
		return QOpenGLFunctions_glIsShader(pObject,P1)

	Func glIsTexture P1
		return QOpenGLFunctions_glIsTexture(pObject,P1)

	Func glLineWidth P1
		return QOpenGLFunctions_glLineWidth(pObject,P1)

	Func glLinkProgram P1
		return QOpenGLFunctions_glLinkProgram(pObject,P1)

	Func glPixelStorei P1,P2
		return QOpenGLFunctions_glPixelStorei(pObject,P1,P2)

	Func glPolygonOffset P1,P2
		return QOpenGLFunctions_glPolygonOffset(pObject,P1,P2)

	Func glReadPixels P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_glReadPixels(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func glReleaseShaderCompiler 
		return QOpenGLFunctions_glReleaseShaderCompiler(pObject)

	Func glRenderbufferStorage P1,P2,P3,P4
		return QOpenGLFunctions_glRenderbufferStorage(pObject,P1,P2,P3,P4)

	Func glSampleCoverage P1,P2
		return QOpenGLFunctions_glSampleCoverage(pObject,P1,P2)

	Func glScissor P1,P2,P3,P4
		return QOpenGLFunctions_glScissor(pObject,P1,P2,P3,P4)

	Func glShaderBinary P1,P2,P3,P4,P5
		return QOpenGLFunctions_glShaderBinary(pObject,P1,GetObjectPointerFromRingObject(P2),P3,GetObjectPointerFromRingObject(P4),P5)

	Func glStencilFunc P1,P2,P3
		return QOpenGLFunctions_glStencilFunc(pObject,P1,P2,P3)

	Func glStencilFuncSeparate P1,P2,P3,P4
		return QOpenGLFunctions_glStencilFuncSeparate(pObject,P1,P2,P3,P4)

	Func glStencilMask P1
		return QOpenGLFunctions_glStencilMask(pObject,P1)

	Func glStencilMaskSeparate P1,P2
		return QOpenGLFunctions_glStencilMaskSeparate(pObject,P1,P2)

	Func glStencilOp P1,P2,P3
		return QOpenGLFunctions_glStencilOp(pObject,P1,P2,P3)

	Func glStencilOpSeparate P1,P2,P3,P4
		return QOpenGLFunctions_glStencilOpSeparate(pObject,P1,P2,P3,P4)

	Func glTexImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_glTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glTexParameterf P1,P2,P3
		return QOpenGLFunctions_glTexParameterf(pObject,P1,P2,P3)

	Func glTexParameterfv P1,P2,P3
		return QOpenGLFunctions_glTexParameterfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexParameteri P1,P2,P3
		return QOpenGLFunctions_glTexParameteri(pObject,P1,P2,P3)

	Func glTexParameteriv P1,P2,P3
		return QOpenGLFunctions_glTexParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_glTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glUniform1f P1,P2
		return QOpenGLFunctions_glUniform1f(pObject,P1,P2)

	Func glUniform1fv P1,P2,P3
		return QOpenGLFunctions_glUniform1fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform1i P1,P2
		return QOpenGLFunctions_glUniform1i(pObject,P1,P2)

	Func glUniform1iv P1,P2,P3
		return QOpenGLFunctions_glUniform1iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform2f P1,P2,P3
		return QOpenGLFunctions_glUniform2f(pObject,P1,P2,P3)

	Func glUniform2fv P1,P2,P3
		return QOpenGLFunctions_glUniform2fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform2i P1,P2,P3
		return QOpenGLFunctions_glUniform2i(pObject,P1,P2,P3)

	Func glUniform2iv P1,P2,P3
		return QOpenGLFunctions_glUniform2iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform3f P1,P2,P3,P4
		return QOpenGLFunctions_glUniform3f(pObject,P1,P2,P3,P4)

	Func glUniform3fv P1,P2,P3
		return QOpenGLFunctions_glUniform3fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform3i P1,P2,P3,P4
		return QOpenGLFunctions_glUniform3i(pObject,P1,P2,P3,P4)

	Func glUniform3iv P1,P2,P3
		return QOpenGLFunctions_glUniform3iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform4f P1,P2,P3,P4,P5
		return QOpenGLFunctions_glUniform4f(pObject,P1,P2,P3,P4,P5)

	Func glUniform4fv P1,P2,P3
		return QOpenGLFunctions_glUniform4fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform4i P1,P2,P3,P4,P5
		return QOpenGLFunctions_glUniform4i(pObject,P1,P2,P3,P4,P5)

	Func glUniform4iv P1,P2,P3
		return QOpenGLFunctions_glUniform4iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniformMatrix2fv P1,P2,P3,P4
		return QOpenGLFunctions_glUniformMatrix2fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix3fv P1,P2,P3,P4
		return QOpenGLFunctions_glUniformMatrix3fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix4fv P1,P2,P3,P4
		return QOpenGLFunctions_glUniformMatrix4fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUseProgram P1
		return QOpenGLFunctions_glUseProgram(pObject,P1)

	Func glValidateProgram P1
		return QOpenGLFunctions_glValidateProgram(pObject,P1)

	Func glVertexAttrib1f P1,P2
		return QOpenGLFunctions_glVertexAttrib1f(pObject,P1,P2)

	Func glVertexAttrib1fv P1,P2
		return QOpenGLFunctions_glVertexAttrib1fv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glVertexAttrib2f P1,P2,P3
		return QOpenGLFunctions_glVertexAttrib2f(pObject,P1,P2,P3)

	Func glVertexAttrib2fv P1,P2
		return QOpenGLFunctions_glVertexAttrib2fv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glVertexAttrib3f P1,P2,P3,P4
		return QOpenGLFunctions_glVertexAttrib3f(pObject,P1,P2,P3,P4)

	Func glVertexAttrib3fv P1,P2
		return QOpenGLFunctions_glVertexAttrib3fv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glVertexAttrib4f P1,P2,P3,P4,P5
		return QOpenGLFunctions_glVertexAttrib4f(pObject,P1,P2,P3,P4,P5)

	Func glVertexAttrib4fv P1,P2
		return QOpenGLFunctions_glVertexAttrib4fv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glVertexAttribPointer P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_glVertexAttribPointer(pObject,P1,P2,P3,P4,P5,GetObjectPointerFromRingObject(P6))

	Func glViewport P1,P2,P3,P4
		return QOpenGLFunctions_glViewport(pObject,P1,P2,P3,P4)

	Func hasOpenGLFeature P1
		return QOpenGLFunctions_hasOpenGLFeature(pObject,P1)

	Func initializeOpenGLFunctions 
		return QOpenGLFunctions_initializeOpenGLFunctions(pObject)

	Func openGLFeatures 
		return QOpenGLFunctions_openGLFeatures(pObject)

Class QOpenGLContext from QObject

	pObject

	Func init P1
		pObject = QOpenGLContext_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLContext_delete(pObject)

	Func ObjectPointer
		return pObject

	Func create 
		return QOpenGLContext_create(pObject)

	Func defaultFramebufferObject 
		return QOpenGLContext_defaultFramebufferObject(pObject)

	Func doneCurrent 
		return QOpenGLContext_doneCurrent(pObject)

	Func extensions 
		return QOpenGLContext_extensions(pObject)

	Func format 
		pTempObj = new QSurfaceFormat
		pTempObj.pObject = QOpenGLContext_format(pObject)
		return pTempObj

	Func functions 
		pTempObj = new QOpenGLFunctions
		pTempObj.pObject = QOpenGLContext_functions(pObject)
		return pTempObj

	Func getProcAddress P1
		return QOpenGLContext_getProcAddress(pObject,GetObjectPointerFromRingObject(P1))

	Func getProcAddress_2 P1
		return QOpenGLContext_getProcAddress_2(pObject,P1)

	Func hasExtension P1
		return QOpenGLContext_hasExtension(pObject,GetObjectPointerFromRingObject(P1))

	Func isOpenGLES 
		return QOpenGLContext_isOpenGLES(pObject)

	Func isValid 
		return QOpenGLContext_isValid(pObject)

	Func makeCurrent P1
		return QOpenGLContext_makeCurrent(pObject,GetObjectPointerFromRingObject(P1))

	Func nativeHandle 
		pTempObj = new QVariant
		pTempObj.pObject = QOpenGLContext_nativeHandle(pObject)
		return pTempObj

	Func screen 
		pTempObj = new QScreen
		pTempObj.pObject = QOpenGLContext_screen(pObject)
		return pTempObj

	Func setFormat P1
		return QOpenGLContext_setFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setNativeHandle P1
		return QOpenGLContext_setNativeHandle(pObject,GetObjectPointerFromRingObject(P1))

	Func setScreen P1
		return QOpenGLContext_setScreen(pObject,GetObjectPointerFromRingObject(P1))

	Func setShareContext P1
		return QOpenGLContext_setShareContext(pObject,GetObjectPointerFromRingObject(P1))

	Func shareContext 
		pTempObj = new QOpenGLContext
		pTempObj.pObject = QOpenGLContext_shareContext(pObject)
		return pTempObj

	Func shareGroup 
		return QOpenGLContext_shareGroup(pObject)

	Func surface 
		return QOpenGLContext_surface(pObject)

	Func swapBuffers P1
		return QOpenGLContext_swapBuffers(pObject,GetObjectPointerFromRingObject(P1))

	Func versionFunctions P1
		return QOpenGLContext_versionFunctions(pObject,GetObjectPointerFromRingObject(P1))

	Func versionFunctions_2 
		return QOpenGLContext_versionFunctions_2(pObject)

	Func areSharing P1,P2
		return QOpenGLContext_areSharing(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func currentContext 
		pTempObj = new QOpenGLContext
		pTempObj.pObject = QOpenGLContext_currentContext(pObject)
		return pTempObj

	Func globalShareContext 
		pTempObj = new QOpenGLContext
		pTempObj.pObject = QOpenGLContext_globalShareContext(pObject)
		return pTempObj

	Func openGLModuleHandle 
		return QOpenGLContext_openGLModuleHandle(pObject)

	Func openGLModuleType 
		return QOpenGLContext_openGLModuleType(pObject)

	Func supportsThreadedOpenGL 
		return QOpenGLContext_supportsThreadedOpenGL(pObject)

	Func opengl32 
		pTempObj = new QOpenGLFunctions_3_2_Core
		pTempObj.pObject = QOpenGLContext_opengl32(pObject)
		return pTempObj

Class QOpenGLFunctions_3_2_Core

	pObject

	Func init 
		pObject = QOpenGLFunctions_3_2_Core_new()
		return self

	Func delete
		pObject = QOpenGLFunctions_3_2_Core_delete(pObject)

	Func ObjectPointer
		return pObject

	Func glActiveTexture P1
		return QOpenGLFunctions_3_2_Core_glActiveTexture(pObject,P1)

	Func glAttachShader P1,P2
		return QOpenGLFunctions_3_2_Core_glAttachShader(pObject,P1,P2)

	Func glBeginConditionalRender P1,P2
		return QOpenGLFunctions_3_2_Core_glBeginConditionalRender(pObject,P1,P2)

	Func glBeginQuery P1,P2
		return QOpenGLFunctions_3_2_Core_glBeginQuery(pObject,P1,P2)

	Func glBeginTransformFeedback P1
		return QOpenGLFunctions_3_2_Core_glBeginTransformFeedback(pObject,P1)

	Func glBindAttribLocation P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glBindAttribLocation(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glBindBuffer P1,P2
		return QOpenGLFunctions_3_2_Core_glBindBuffer(pObject,P1,P2)

	Func glBindBufferBase P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glBindBufferBase(pObject,P1,P2,P3)

	Func glBindBufferRange P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glBindBufferRange(pObject,P1,P2,P3,P4,P5)

	Func glBindFragDataLocation P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glBindFragDataLocation(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glBindFramebuffer P1,P2
		return QOpenGLFunctions_3_2_Core_glBindFramebuffer(pObject,P1,P2)

	Func glBindRenderbuffer P1,P2
		return QOpenGLFunctions_3_2_Core_glBindRenderbuffer(pObject,P1,P2)

	Func glBindTexture P1,P2
		return QOpenGLFunctions_3_2_Core_glBindTexture(pObject,P1,P2)

	Func glBindVertexArray P1
		return QOpenGLFunctions_3_2_Core_glBindVertexArray(pObject,P1)

	Func glBlendColor P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glBlendColor(pObject,P1,P2,P3,P4)

	Func glBlendEquation P1
		return QOpenGLFunctions_3_2_Core_glBlendEquation(pObject,P1)

	Func glBlendEquationSeparate P1,P2
		return QOpenGLFunctions_3_2_Core_glBlendEquationSeparate(pObject,P1,P2)

	Func glBlendFunc P1,P2
		return QOpenGLFunctions_3_2_Core_glBlendFunc(pObject,P1,P2)

	Func glBlendFuncSeparate P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glBlendFuncSeparate(pObject,P1,P2,P3,P4)

	Func glBlitFramebuffer P1,P2,P3,P4,P5,P6,P7,P8,P9,P10
		return QOpenGLFunctions_3_2_Core_glBlitFramebuffer(pObject,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10)

	Func glBufferData P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glBufferData(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4)

	Func glBufferSubData P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glBufferSubData(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glCheckFramebufferStatus P1
		return QOpenGLFunctions_3_2_Core_glCheckFramebufferStatus(pObject,P1)

	Func glClampColor P1,P2
		return QOpenGLFunctions_3_2_Core_glClampColor(pObject,P1,P2)

	Func glClear P1
		return QOpenGLFunctions_3_2_Core_glClear(pObject,P1)

	Func glClearBufferfi P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glClearBufferfi(pObject,P1,P2,P3,P4)

	Func glClearBufferfv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glClearBufferfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glClearBufferiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glClearBufferiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glClearBufferuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glClearBufferuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glClearColor P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glClearColor(pObject,P1,P2,P3,P4)

	Func glClearDepth P1
		return QOpenGLFunctions_3_2_Core_glClearDepth(pObject,P1)

	Func glClearStencil P1
		return QOpenGLFunctions_3_2_Core_glClearStencil(pObject,P1)

	Func glClientWaitSync P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glClientWaitSync(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3))

	Func glColorMask P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glColorMask(pObject,P1,P2,P3,P4)

	Func glColorMaski P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glColorMaski(pObject,P1,P2,P3,P4,P5)

	Func glCompileShader P1
		return QOpenGLFunctions_3_2_Core_glCompileShader(pObject,P1)

	Func glCompressedTexImage1D P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glCompressedTexImage1D(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func glCompressedTexImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_3_2_Core_glCompressedTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8))

	Func glCompressedTexImage3D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_3_2_Core_glCompressedTexImage3D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glCompressedTexSubImage1D P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glCompressedTexSubImage1D(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func glCompressedTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_3_2_Core_glCompressedTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glCompressedTexSubImage3D P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11
		return QOpenGLFunctions_3_2_Core_glCompressedTexSubImage3D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,GetObjectPointerFromRingObject(P11))

	Func glCopyBufferSubData P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glCopyBufferSubData(pObject,P1,P2,P3,P4,P5)

	Func glCopyTexImage1D P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glCopyTexImage1D(pObject,P1,P2,P3,P4,P5,P6,P7)

	Func glCopyTexImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_3_2_Core_glCopyTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8)

	Func glCopyTexSubImage1D P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glCopyTexSubImage1D(pObject,P1,P2,P3,P4,P5,P6)

	Func glCopyTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_3_2_Core_glCopyTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8)

	Func glCopyTexSubImage3D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_3_2_Core_glCopyTexSubImage3D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,P9)

	Func glCreateProgram 
		return QOpenGLFunctions_3_2_Core_glCreateProgram(pObject)

	Func glCreateShader P1
		return QOpenGLFunctions_3_2_Core_glCreateShader(pObject,P1)

	Func glCullFace P1
		return QOpenGLFunctions_3_2_Core_glCullFace(pObject,P1)

	Func glDeleteBuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteBuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteFramebuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteFramebuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteProgram P1
		return QOpenGLFunctions_3_2_Core_glDeleteProgram(pObject,P1)

	Func glDeleteQueries P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteQueries(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteRenderbuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteRenderbuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteShader P1
		return QOpenGLFunctions_3_2_Core_glDeleteShader(pObject,P1)

	Func glDeleteSync P1
		return QOpenGLFunctions_3_2_Core_glDeleteSync(pObject,GetObjectPointerFromRingObject(P1))

	Func glDeleteTextures P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteTextures(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDeleteVertexArrays P1,P2
		return QOpenGLFunctions_3_2_Core_glDeleteVertexArrays(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDepthFunc P1
		return QOpenGLFunctions_3_2_Core_glDepthFunc(pObject,P1)

	Func glDepthMask P1
		return QOpenGLFunctions_3_2_Core_glDepthMask(pObject,P1)

	Func glDepthRange P1,P2
		return QOpenGLFunctions_3_2_Core_glDepthRange(pObject,P1,P2)

	Func glDetachShader P1,P2
		return QOpenGLFunctions_3_2_Core_glDetachShader(pObject,P1,P2)

	Func glDisable P1
		return QOpenGLFunctions_3_2_Core_glDisable(pObject,P1)

	Func glDisableVertexAttribArray P1
		return QOpenGLFunctions_3_2_Core_glDisableVertexAttribArray(pObject,P1)

	Func glDisablei P1,P2
		return QOpenGLFunctions_3_2_Core_glDisablei(pObject,P1,P2)

	Func glDrawArrays P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glDrawArrays(pObject,P1,P2,P3)

	Func glDrawArraysInstanced P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glDrawArraysInstanced(pObject,P1,P2,P3,P4)

	Func glDrawBuffer P1
		return QOpenGLFunctions_3_2_Core_glDrawBuffer(pObject,P1)

	Func glDrawBuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glDrawBuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glDrawElements P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glDrawElements(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glDrawElementsBaseVertex P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glDrawElementsBaseVertex(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),P5)

	Func glDrawElementsInstanced P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glDrawElementsInstanced(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),P5)

	Func glDrawElementsInstancedBaseVertex P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glDrawElementsInstancedBaseVertex(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),P5,P6)

	Func glDrawRangeElements P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glDrawRangeElements(pObject,P1,P2,P3,P4,P5,GetObjectPointerFromRingObject(P6))

	Func glDrawRangeElementsBaseVertex P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glDrawRangeElementsBaseVertex(pObject,P1,P2,P3,P4,P5,GetObjectPointerFromRingObject(P6),P7)

	Func glEnable P1
		return QOpenGLFunctions_3_2_Core_glEnable(pObject,P1)

	Func glEnableVertexAttribArray P1
		return QOpenGLFunctions_3_2_Core_glEnableVertexAttribArray(pObject,P1)

	Func glEnablei P1,P2
		return QOpenGLFunctions_3_2_Core_glEnablei(pObject,P1,P2)

	Func glEndConditionalRender 
		return QOpenGLFunctions_3_2_Core_glEndConditionalRender(pObject)

	Func glEndQuery P1
		return QOpenGLFunctions_3_2_Core_glEndQuery(pObject,P1)

	Func glEndTransformFeedback 
		return QOpenGLFunctions_3_2_Core_glEndTransformFeedback(pObject)

	Func glFenceSync P1,P2
		return QOpenGLFunctions_3_2_Core_glFenceSync(pObject,P1,P2)

	Func glFinish 
		return QOpenGLFunctions_3_2_Core_glFinish(pObject)

	Func glFlush 
		return QOpenGLFunctions_3_2_Core_glFlush(pObject)

	Func glFlushMappedBufferRange P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glFlushMappedBufferRange(pObject,P1,P2,P3)

	Func glFramebufferRenderbuffer P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glFramebufferRenderbuffer(pObject,P1,P2,P3,P4)

	Func glFramebufferTexture P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glFramebufferTexture(pObject,P1,P2,P3,P4)

	Func glFramebufferTexture1D P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glFramebufferTexture1D(pObject,P1,P2,P3,P4,P5)

	Func glFramebufferTexture2D P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glFramebufferTexture2D(pObject,P1,P2,P3,P4,P5)

	Func glFramebufferTexture3D P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glFramebufferTexture3D(pObject,P1,P2,P3,P4,P5,P6)

	Func glFramebufferTextureLayer P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glFramebufferTextureLayer(pObject,P1,P2,P3,P4,P5)

	Func glFrontFace P1
		return QOpenGLFunctions_3_2_Core_glFrontFace(pObject,P1)

	Func glGenBuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glGenBuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenFramebuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glGenFramebuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenQueries P1,P2
		return QOpenGLFunctions_3_2_Core_glGenQueries(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenRenderbuffers P1,P2
		return QOpenGLFunctions_3_2_Core_glGenRenderbuffers(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenTextures P1,P2
		return QOpenGLFunctions_3_2_Core_glGenTextures(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenVertexArrays P1,P2
		return QOpenGLFunctions_3_2_Core_glGenVertexArrays(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGenerateMipmap P1
		return QOpenGLFunctions_3_2_Core_glGenerateMipmap(pObject,P1)

	Func glGetActiveAttrib P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glGetActiveAttrib(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7))

	Func glGetActiveUniform P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glGetActiveUniform(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7))

	Func glGetActiveUniformBlockName P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glGetActiveUniformBlockName(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func glGetActiveUniformBlockiv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetActiveUniformBlockiv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetActiveUniformName P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glGetActiveUniformName(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func glGetActiveUniformsiv P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glGetActiveUniformsiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4,GetObjectPointerFromRingObject(P5))

	Func glGetAttachedShaders P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetAttachedShaders(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetAttribLocation P1,P2
		return QOpenGLFunctions_3_2_Core_glGetAttribLocation(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetBooleani_v P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetBooleani_v(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetBooleanv P1,P2
		return QOpenGLFunctions_3_2_Core_glGetBooleanv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetBufferParameteri64v P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetBufferParameteri64v(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetBufferParameteriv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetBufferParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetBufferSubData P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetBufferSubData(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetCompressedTexImage P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetCompressedTexImage(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetDoublev P1,P2
		return QOpenGLFunctions_3_2_Core_glGetDoublev(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetError 
		return QOpenGLFunctions_3_2_Core_glGetError(pObject)

	Func glGetFloatv P1,P2
		return QOpenGLFunctions_3_2_Core_glGetFloatv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetFragDataLocation P1,P2
		return QOpenGLFunctions_3_2_Core_glGetFragDataLocation(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetFramebufferAttachmentParameteriv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetFramebufferAttachmentParameteriv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetInteger64i_v P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetInteger64i_v(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetInteger64v P1,P2
		return QOpenGLFunctions_3_2_Core_glGetInteger64v(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetIntegeri_v P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetIntegeri_v(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetIntegerv P1,P2
		return QOpenGLFunctions_3_2_Core_glGetIntegerv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetMultisamplefv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetMultisamplefv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetProgramInfoLog P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetProgramInfoLog(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetProgramiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetProgramiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetQueryObjectiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetQueryObjectiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetQueryObjectuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetQueryObjectuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetQueryiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetQueryiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetRenderbufferParameteriv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetRenderbufferParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetShaderInfoLog P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetShaderInfoLog(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetShaderSource P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetShaderSource(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func glGetShaderiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetShaderiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetString P1
		return QOpenGLFunctions_3_2_Core_glGetString(pObject,P1)

	Func glGetStringi P1,P2
		return QOpenGLFunctions_3_2_Core_glGetStringi(pObject,P1,P2)

	Func glGetSynciv P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glGetSynciv(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func glGetTexImage P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glGetTexImage(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5))

	Func glGetTexLevelParameterfv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetTexLevelParameterfv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetTexLevelParameteriv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glGetTexLevelParameteriv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glGetTexParameterIiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetTexParameterIiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetTexParameterIuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetTexParameterIuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetTexParameterfv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetTexParameterfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetTexParameteriv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetTexParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetTransformFeedbackVarying P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glGetTransformFeedbackVarying(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7))

	Func glGetUniformBlockIndex P1,P2
		return QOpenGLFunctions_3_2_Core_glGetUniformBlockIndex(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetUniformLocation P1,P2
		return QOpenGLFunctions_3_2_Core_glGetUniformLocation(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glGetUniformfv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetUniformfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetUniformiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetUniformiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetUniformuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetUniformuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribIiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetVertexAttribIiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribIuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetVertexAttribIuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribdv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetVertexAttribdv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribfv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetVertexAttribfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glGetVertexAttribiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glGetVertexAttribiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glHint P1,P2
		return QOpenGLFunctions_3_2_Core_glHint(pObject,P1,P2)

	Func glIndexub P1
		return QOpenGLFunctions_3_2_Core_glIndexub(pObject,P1)

	Func glIndexubv P1
		return QOpenGLFunctions_3_2_Core_glIndexubv(pObject,GetObjectPointerFromRingObject(P1))

	Func glIsBuffer P1
		return QOpenGLFunctions_3_2_Core_glIsBuffer(pObject,P1)

	Func glIsEnabled P1
		return QOpenGLFunctions_3_2_Core_glIsEnabled(pObject,P1)

	Func glIsEnabledi P1,P2
		return QOpenGLFunctions_3_2_Core_glIsEnabledi(pObject,P1,P2)

	Func glIsFramebuffer P1
		return QOpenGLFunctions_3_2_Core_glIsFramebuffer(pObject,P1)

	Func glIsProgram P1
		return QOpenGLFunctions_3_2_Core_glIsProgram(pObject,P1)

	Func glIsQuery P1
		return QOpenGLFunctions_3_2_Core_glIsQuery(pObject,P1)

	Func glIsRenderbuffer P1
		return QOpenGLFunctions_3_2_Core_glIsRenderbuffer(pObject,P1)

	Func glIsShader P1
		return QOpenGLFunctions_3_2_Core_glIsShader(pObject,P1)

	Func glIsSync P1
		return QOpenGLFunctions_3_2_Core_glIsSync(pObject,GetObjectPointerFromRingObject(P1))

	Func glIsTexture P1
		return QOpenGLFunctions_3_2_Core_glIsTexture(pObject,P1)

	Func glIsVertexArray P1
		return QOpenGLFunctions_3_2_Core_glIsVertexArray(pObject,P1)

	Func glLineWidth P1
		return QOpenGLFunctions_3_2_Core_glLineWidth(pObject,P1)

	Func glLinkProgram P1
		return QOpenGLFunctions_3_2_Core_glLinkProgram(pObject,P1)

	Func glLogicOp P1
		return QOpenGLFunctions_3_2_Core_glLogicOp(pObject,P1)

	Func glMapBuffer P1,P2
		return QOpenGLFunctions_3_2_Core_glMapBuffer(pObject,P1,P2)

	Func glMapBufferRange P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glMapBufferRange(pObject,P1,P2,P3,P4)

	Func glMultiDrawArrays P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glMultiDrawArrays(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),P4)

	Func glPixelStoref P1,P2
		return QOpenGLFunctions_3_2_Core_glPixelStoref(pObject,P1,P2)

	Func glPixelStorei P1,P2
		return QOpenGLFunctions_3_2_Core_glPixelStorei(pObject,P1,P2)

	Func glPointParameterf P1,P2
		return QOpenGLFunctions_3_2_Core_glPointParameterf(pObject,P1,P2)

	Func glPointParameterfv P1,P2
		return QOpenGLFunctions_3_2_Core_glPointParameterfv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glPointParameteri P1,P2
		return QOpenGLFunctions_3_2_Core_glPointParameteri(pObject,P1,P2)

	Func glPointParameteriv P1,P2
		return QOpenGLFunctions_3_2_Core_glPointParameteriv(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func glPointSize P1
		return QOpenGLFunctions_3_2_Core_glPointSize(pObject,P1)

	Func glPolygonMode P1,P2
		return QOpenGLFunctions_3_2_Core_glPolygonMode(pObject,P1,P2)

	Func glPolygonOffset P1,P2
		return QOpenGLFunctions_3_2_Core_glPolygonOffset(pObject,P1,P2)

	Func glPrimitiveRestartIndex P1
		return QOpenGLFunctions_3_2_Core_glPrimitiveRestartIndex(pObject,P1)

	Func glProvokingVertex P1
		return QOpenGLFunctions_3_2_Core_glProvokingVertex(pObject,P1)

	Func glReadBuffer P1
		return QOpenGLFunctions_3_2_Core_glReadBuffer(pObject,P1)

	Func glReadPixels P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glReadPixels(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func glRenderbufferStorage P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glRenderbufferStorage(pObject,P1,P2,P3,P4)

	Func glRenderbufferStorageMultisample P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glRenderbufferStorageMultisample(pObject,P1,P2,P3,P4,P5)

	Func glSampleCoverage P1,P2
		return QOpenGLFunctions_3_2_Core_glSampleCoverage(pObject,P1,P2)

	Func glSampleMaski P1,P2
		return QOpenGLFunctions_3_2_Core_glSampleMaski(pObject,P1,P2)

	Func glScissor P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glScissor(pObject,P1,P2,P3,P4)

	Func glStencilFunc P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glStencilFunc(pObject,P1,P2,P3)

	Func glStencilFuncSeparate P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glStencilFuncSeparate(pObject,P1,P2,P3,P4)

	Func glStencilMask P1
		return QOpenGLFunctions_3_2_Core_glStencilMask(pObject,P1)

	Func glStencilMaskSeparate P1,P2
		return QOpenGLFunctions_3_2_Core_glStencilMaskSeparate(pObject,P1,P2)

	Func glStencilOp P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glStencilOp(pObject,P1,P2,P3)

	Func glStencilOpSeparate P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glStencilOpSeparate(pObject,P1,P2,P3,P4)

	Func glTexBuffer P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexBuffer(pObject,P1,P2,P3)

	Func glTexImage1D P1,P2,P3,P4,P5,P6,P7,P8
		return QOpenGLFunctions_3_2_Core_glTexImage1D(pObject,P1,P2,P3,P4,P5,P6,P7,GetObjectPointerFromRingObject(P8))

	Func glTexImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_3_2_Core_glTexImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glTexImage2DMultisample P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glTexImage2DMultisample(pObject,P1,P2,P3,P4,P5,P6)

	Func glTexImage3D P1,P2,P3,P4,P5,P6,P7,P8,P9,P10
		return QOpenGLFunctions_3_2_Core_glTexImage3D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,P9,GetObjectPointerFromRingObject(P10))

	Func glTexImage3DMultisample P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glTexImage3DMultisample(pObject,P1,P2,P3,P4,P5,P6,P7)

	Func glTexParameterIiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameterIiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexParameterIuiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameterIuiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexParameterf P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameterf(pObject,P1,P2,P3)

	Func glTexParameterfv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameterfv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexParameteri P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameteri(pObject,P1,P2,P3)

	Func glTexParameteriv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glTexParameteriv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glTexSubImage1D P1,P2,P3,P4,P5,P6,P7
		return QOpenGLFunctions_3_2_Core_glTexSubImage1D(pObject,P1,P2,P3,P4,P5,P6,GetObjectPointerFromRingObject(P7))

	Func glTexSubImage2D P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QOpenGLFunctions_3_2_Core_glTexSubImage2D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,GetObjectPointerFromRingObject(P9))

	Func glTexSubImage3D P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11
		return QOpenGLFunctions_3_2_Core_glTexSubImage3D(pObject,P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,GetObjectPointerFromRingObject(P11))

	Func glUniform1f P1,P2
		return QOpenGLFunctions_3_2_Core_glUniform1f(pObject,P1,P2)

	Func glUniform1fv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform1fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform1i P1,P2
		return QOpenGLFunctions_3_2_Core_glUniform1i(pObject,P1,P2)

	Func glUniform1iv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform1iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform1ui P1,P2
		return QOpenGLFunctions_3_2_Core_glUniform1ui(pObject,P1,P2)

	Func glUniform1uiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform1uiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform2f P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2f(pObject,P1,P2,P3)

	Func glUniform2fv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform2i P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2i(pObject,P1,P2,P3)

	Func glUniform2iv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform2ui P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2ui(pObject,P1,P2,P3)

	Func glUniform2uiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform2uiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform3f P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniform3f(pObject,P1,P2,P3,P4)

	Func glUniform3fv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform3fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform3i P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniform3i(pObject,P1,P2,P3,P4)

	Func glUniform3iv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform3iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform3ui P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniform3ui(pObject,P1,P2,P3,P4)

	Func glUniform3uiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform3uiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform4f P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glUniform4f(pObject,P1,P2,P3,P4,P5)

	Func glUniform4fv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform4fv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform4i P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glUniform4i(pObject,P1,P2,P3,P4,P5)

	Func glUniform4iv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform4iv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniform4ui P1,P2,P3,P4,P5
		return QOpenGLFunctions_3_2_Core_glUniform4ui(pObject,P1,P2,P3,P4,P5)

	Func glUniform4uiv P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniform4uiv(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func glUniformBlockBinding P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glUniformBlockBinding(pObject,P1,P2,P3)

	Func glUniformMatrix2fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix2fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix2x3fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix2x3fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix2x4fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix2x4fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix3fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix3fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix3x2fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix3x2fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix3x4fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix3x4fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix4fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix4fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix4x2fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix4x2fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUniformMatrix4x3fv P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glUniformMatrix4x3fv(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func glUnmapBuffer P1
		return QOpenGLFunctions_3_2_Core_glUnmapBuffer(pObject,P1)

	Func glUseProgram P1
		return QOpenGLFunctions_3_2_Core_glUseProgram(pObject,P1)

	Func glValidateProgram P1
		return QOpenGLFunctions_3_2_Core_glValidateProgram(pObject,P1)

	Func glVertexAttribPointer P1,P2,P3,P4,P5,P6
		return QOpenGLFunctions_3_2_Core_glVertexAttribPointer(pObject,P1,P2,P3,P4,P5,GetObjectPointerFromRingObject(P6))

	Func glViewport P1,P2,P3,P4
		return QOpenGLFunctions_3_2_Core_glViewport(pObject,P1,P2,P3,P4)

	Func glWaitSync P1,P2,P3
		return QOpenGLFunctions_3_2_Core_glWaitSync(pObject,GetObjectPointerFromRingObject(P1),P2,GetObjectPointerFromRingObject(P3))

Class QSurfaceFormat

	pObject

	Func init 
		pObject = QSurfaceFormat_new()
		return self

	Func delete
		pObject = QSurfaceFormat_delete(pObject)

	Func ObjectPointer
		return pObject

	Func alphaBufferSize 
		return QSurfaceFormat_alphaBufferSize(pObject)

	Func blueBufferSize 
		return QSurfaceFormat_blueBufferSize(pObject)

	Func depthBufferSize 
		return QSurfaceFormat_depthBufferSize(pObject)

	Func greenBufferSize 
		return QSurfaceFormat_greenBufferSize(pObject)

	Func hasAlpha 
		return QSurfaceFormat_hasAlpha(pObject)

	Func majorVersion 
		return QSurfaceFormat_majorVersion(pObject)

	Func minorVersion 
		return QSurfaceFormat_minorVersion(pObject)

	Func options 
		return QSurfaceFormat_options(pObject)

	Func profile 
		return QSurfaceFormat_profile(pObject)

	Func redBufferSize 
		return QSurfaceFormat_redBufferSize(pObject)

	Func renderableType 
		return QSurfaceFormat_renderableType(pObject)

	Func samples 
		return QSurfaceFormat_samples(pObject)

	Func setAlphaBufferSize P1
		return QSurfaceFormat_setAlphaBufferSize(pObject,P1)

	Func setBlueBufferSize P1
		return QSurfaceFormat_setBlueBufferSize(pObject,P1)

	Func setDepthBufferSize P1
		return QSurfaceFormat_setDepthBufferSize(pObject,P1)

	Func setGreenBufferSize P1
		return QSurfaceFormat_setGreenBufferSize(pObject,P1)

	Func setMajorVersion P1
		return QSurfaceFormat_setMajorVersion(pObject,P1)

	Func setMinorVersion P1
		return QSurfaceFormat_setMinorVersion(pObject,P1)

	Func setOption P1,P2
		return QSurfaceFormat_setOption(pObject,P1,P2)

	Func setOptions P1
		return QSurfaceFormat_setOptions(pObject,P1)

	Func setProfile P1
		return QSurfaceFormat_setProfile(pObject,P1)

	Func setRedBufferSize P1
		return QSurfaceFormat_setRedBufferSize(pObject,P1)

	Func setRenderableType P1
		return QSurfaceFormat_setRenderableType(pObject,P1)

	Func setSamples P1
		return QSurfaceFormat_setSamples(pObject,P1)

	Func setStencilBufferSize P1
		return QSurfaceFormat_setStencilBufferSize(pObject,P1)

	Func setStereo P1
		return QSurfaceFormat_setStereo(pObject,P1)

	Func setSwapBehavior P1
		return QSurfaceFormat_setSwapBehavior(pObject,P1)

	Func setSwapInterval P1
		return QSurfaceFormat_setSwapInterval(pObject,P1)

	Func setVersion P1,P2
		return QSurfaceFormat_setVersion(pObject,P1,P2)

	Func stencilBufferSize 
		return QSurfaceFormat_stencilBufferSize(pObject)

	Func stereo 
		return QSurfaceFormat_stereo(pObject)

	Func swapBehavior 
		return QSurfaceFormat_swapBehavior(pObject)

	Func swapInterval 
		return QSurfaceFormat_swapInterval(pObject)

	Func testOption P1
		return QSurfaceFormat_testOption(pObject,P1)

	Func defaultFormat 
		pTempObj = new QSurfaceFormat
		pTempObj.pObject = QSurfaceFormat_defaultFormat(pObject)
		return pTempObj

	Func setDefaultFormat P1
		return QSurfaceFormat_setDefaultFormat(pObject,GetObjectPointerFromRingObject(P1))

Class QOpenGLWidget from QWidget

	pObject

	Func init P1
		pObject = QOpenGLWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func geteventparameters 
		return QOpenGLWidget_geteventparameters(pObject)

	Func setInitEvent P1
		return QOpenGLWidget_setInitEvent(pObject,P1)

	Func getInitEvent 
		return QOpenGLWidget_getInitEvent(pObject)

	Func setPaintEvent P1
		return QOpenGLWidget_setPaintEvent(pObject,P1)

	Func getPaintEvent 
		return QOpenGLWidget_getPaintEvent(pObject)

	Func setResizeEvent P1
		return QOpenGLWidget_setResizeEvent(pObject,P1)

	Func getResizeEvent 
		return QOpenGLWidget_getResizeEvent(pObject)

	Func context 
		pTempObj = new QOpenGLContext
		pTempObj.pObject = QOpenGLWidget_context(pObject)
		return pTempObj

	Func defaultFramebufferObject 
		return QOpenGLWidget_defaultFramebufferObject(pObject)

	Func doneCurrent 
		return QOpenGLWidget_doneCurrent(pObject)

	Func format 
		pTempObj = new QSurfaceFormat
		pTempObj.pObject = QOpenGLWidget_format(pObject)
		return pTempObj

	Func grabFramebuffer 
		pTempObj = new QImage
		pTempObj.pObject = QOpenGLWidget_grabFramebuffer(pObject)
		return pTempObj

	Func isValid 
		return QOpenGLWidget_isValid(pObject)

	Func makeCurrent 
		return QOpenGLWidget_makeCurrent(pObject)

	Func setFormat P1
		return QOpenGLWidget_setFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setUpdateBehavior P1
		return QOpenGLWidget_setUpdateBehavior(pObject,P1)

	Func updateBehavior 
		return QOpenGLWidget_updateBehavior(pObject)

Class QOpenGLVersionProfile

	pObject

	Func init 
		pObject = QOpenGLVersionProfile_new()
		return self

	Func delete
		pObject = QOpenGLVersionProfile_delete(pObject)

	Func ObjectPointer
		return pObject

	Func hasProfiles 
		return QOpenGLVersionProfile_hasProfiles(pObject)

	Func isLegacyVersion 
		return QOpenGLVersionProfile_isLegacyVersion(pObject)

	Func isValid 
		return QOpenGLVersionProfile_isValid(pObject)

	Func profile 
		return QOpenGLVersionProfile_profile(pObject)

	Func setProfile P1
		return QOpenGLVersionProfile_setProfile(pObject,P1)

	Func setVersion P1,P2
		return QOpenGLVersionProfile_setVersion(pObject,P1,P2)

	Func version 
		return QOpenGLVersionProfile_version(pObject)

Class QVector2D

	pObject

	Func init P1,P2
		pObject = QVector2D_new(P1,P2)
		return self

	Func delete
		pObject = QVector2D_delete(pObject)

	Func ObjectPointer
		return pObject

	Func distanceToLine P1,P2
		return QVector2D_distanceToLine(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func distanceToPoint P1
		return QVector2D_distanceToPoint(pObject,GetObjectPointerFromRingObject(P1))

	Func isNull 
		return QVector2D_isNull(pObject)

	Func length 
		return QVector2D_length(pObject)

	Func lengthSquared 
		return QVector2D_lengthSquared(pObject)

	Func normalize 
		return QVector2D_normalize(pObject)

	Func normalized 
		pTempObj = new QVector2D
		pTempObj.pObject = QVector2D_normalized(pObject)
		return pTempObj

	Func setX P1
		return QVector2D_setX(pObject,P1)

	Func setY P1
		return QVector2D_setY(pObject,P1)

	Func toPoint 
		pTempObj = new QPoint
		pTempObj.pObject = QVector2D_toPoint(pObject)
		return pTempObj

	Func toPointF 
		pTempObj = new QPointF
		pTempObj.pObject = QVector2D_toPointF(pObject)
		return pTempObj

	Func toVector3D 
		pTempObj = new QVector3D
		pTempObj.pObject = QVector2D_toVector3D(pObject)
		return pTempObj

	Func toVector4D 
		pTempObj = new QVector4D
		pTempObj.pObject = QVector2D_toVector4D(pObject)
		return pTempObj

	Func x 
		return QVector2D_x(pObject)

	Func y 
		return QVector2D_y(pObject)

	Func dotProduct P1,P2
		return QVector2D_dotProduct(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

Class QVector3D

	pObject

	Func init P1,P2,P3
		pObject = QVector3D_new(P1,P2,P3)
		return self

	Func delete
		pObject = QVector3D_delete(pObject)

	Func ObjectPointer
		return pObject

	Func distanceToLine P1,P2
		return QVector3D_distanceToLine(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func distanceToPlane P1,P2
		return QVector3D_distanceToPlane(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func distanceToPlane_2 P1,P2,P3
		return QVector3D_distanceToPlane_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func distanceToPoint P1
		return QVector3D_distanceToPoint(pObject,GetObjectPointerFromRingObject(P1))

	Func isNull 
		return QVector3D_isNull(pObject)

	Func length 
		return QVector3D_length(pObject)

	Func lengthSquared 
		return QVector3D_lengthSquared(pObject)

	Func normalize 
		return QVector3D_normalize(pObject)

	Func normalized 
		pTempObj = new QVector3D
		pTempObj.pObject = QVector3D_normalized(pObject)
		return pTempObj

	Func setX P1
		return QVector3D_setX(pObject,P1)

	Func setY P1
		return QVector3D_setY(pObject,P1)

	Func setZ P1
		return QVector3D_setZ(pObject,P1)

	Func toPoint 
		pTempObj = new QPoint
		pTempObj.pObject = QVector3D_toPoint(pObject)
		return pTempObj

	Func toPointF 
		pTempObj = new QPointF
		pTempObj.pObject = QVector3D_toPointF(pObject)
		return pTempObj

	Func toVector2D 
		pTempObj = new QVector2D
		pTempObj.pObject = QVector3D_toVector2D(pObject)
		return pTempObj

	Func toVector4D 
		pTempObj = new QVector4D
		pTempObj.pObject = QVector3D_toVector4D(pObject)
		return pTempObj

	Func x 
		return QVector3D_x(pObject)

	Func y 
		return QVector3D_y(pObject)

	Func z 
		return QVector3D_z(pObject)

	Func crossProduct P1,P2
		pTempObj = new QVector3D
		pTempObj.pObject = QVector3D_crossProduct(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func dotProduct P1,P2
		return QVector3D_dotProduct(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func normal P1,P2
		pTempObj = new QVector3D
		pTempObj.pObject = QVector3D_normal(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func normal_2 P1,P2,P3
		pTempObj = new QVector3D
		pTempObj.pObject = QVector3D_normal_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))
		return pTempObj

Class QVector4D

	pObject

	Func init P1,P2,P3,P4
		pObject = QVector4D_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QVector4D_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isNull 
		return QVector4D_isNull(pObject)

	Func length 
		return QVector4D_length(pObject)

	Func lengthSquared 
		return QVector4D_lengthSquared(pObject)

	Func normalize 
		return QVector4D_normalize(pObject)

	Func normalized 
		pTempObj = new QVector4D
		pTempObj.pObject = QVector4D_normalized(pObject)
		return pTempObj

	Func setW P1
		return QVector4D_setW(pObject,P1)

	Func setX P1
		return QVector4D_setX(pObject,P1)

	Func setY P1
		return QVector4D_setY(pObject,P1)

	Func setZ P1
		return QVector4D_setZ(pObject,P1)

	Func toPoint 
		pTempObj = new QPoint
		pTempObj.pObject = QVector4D_toPoint(pObject)
		return pTempObj

	Func toPointF 
		pTempObj = new QPointF
		pTempObj.pObject = QVector4D_toPointF(pObject)
		return pTempObj

	Func toVector2D 
		pTempObj = new QVector2D
		pTempObj.pObject = QVector4D_toVector2D(pObject)
		return pTempObj

	Func toVector2DAffine 
		pTempObj = new QVector2D
		pTempObj.pObject = QVector4D_toVector2DAffine(pObject)
		return pTempObj

	Func toVector3D 
		pTempObj = new QVector3D
		pTempObj.pObject = QVector4D_toVector3D(pObject)
		return pTempObj

	Func toVector3DAffine 
		pTempObj = new QVector3D
		pTempObj.pObject = QVector4D_toVector3DAffine(pObject)
		return pTempObj

	Func w 
		return QVector4D_w(pObject)

	Func x 
		return QVector4D_x(pObject)

	Func y 
		return QVector4D_y(pObject)

	Func z 
		return QVector4D_z(pObject)

	Func dotProduct P1,P2
		return QVector4D_dotProduct(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

Class QQuaternion

	pObject

	Func init P1,P2,P3,P4
		pObject = QQuaternion_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QQuaternion_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isIdentity 
		return QQuaternion_isIdentity(pObject)

	Func isNull 
		return QQuaternion_isNull(pObject)

	Func length 
		return QQuaternion_length(pObject)

	Func lengthSquared 
		return QQuaternion_lengthSquared(pObject)

	Func normalize 
		return QQuaternion_normalize(pObject)

	Func normalized 
		pTempObj = new QQuaternion
		pTempObj.pObject = QQuaternion_normalized(pObject)
		return pTempObj

	Func rotatedVector P1
		pTempObj = new QVector3D
		pTempObj.pObject = QQuaternion_rotatedVector(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func scalar 
		return QQuaternion_scalar(pObject)

	Func setScalar P1
		return QQuaternion_setScalar(pObject,P1)

	Func setVector P1
		return QQuaternion_setVector(pObject,GetObjectPointerFromRingObject(P1))

	Func setVector_2 P1,P2,P3
		return QQuaternion_setVector_2(pObject,P1,P2,P3)

	Func setX P1
		return QQuaternion_setX(pObject,P1)

	Func setY P1
		return QQuaternion_setY(pObject,P1)

	Func setZ P1
		return QQuaternion_setZ(pObject,P1)

	Func toVector4D 
		pTempObj = new QVector4D
		pTempObj.pObject = QQuaternion_toVector4D(pObject)
		return pTempObj

	Func vector 
		pTempObj = new QVector3D
		pTempObj.pObject = QQuaternion_vector(pObject)
		return pTempObj

	Func x 
		return QQuaternion_x(pObject)

	Func y 
		return QQuaternion_y(pObject)

	Func z 
		return QQuaternion_z(pObject)

	Func fromAxisAndAngle P1,P2
		pTempObj = new QQuaternion
		pTempObj.pObject = QQuaternion_fromAxisAndAngle(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func fromAxisAndAngle_2 P1,P2,P3,P4
		pTempObj = new QQuaternion
		pTempObj.pObject = QQuaternion_fromAxisAndAngle_2(pObject,P1,P2,P3,P4)
		return pTempObj

	Func nlerp P1,P2,P3
		pTempObj = new QQuaternion
		pTempObj.pObject = QQuaternion_nlerp(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

	Func slerp P1,P2,P3
		pTempObj = new QQuaternion
		pTempObj.pObject = QQuaternion_slerp(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)
		return pTempObj

Class QMatrix4x4

	pObject

	Func init P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15,P16
		pObject = QMatrix4x4_new(P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15,P16)
		return self

	Func delete
		pObject = QMatrix4x4_delete(pObject)

	Func ObjectPointer
		return pObject

	Func column P1
		pTempObj = new QVector4D
		pTempObj.pObject = QMatrix4x4_column(pObject,P1)
		return pTempObj

	Func constData 
		return QMatrix4x4_constData(pObject)

	Func data 
		return QMatrix4x4_data(pObject)

	Func data_2 
		return QMatrix4x4_data_2(pObject)

	Func determinant 
		return QMatrix4x4_determinant(pObject)

	Func fill P1
		return QMatrix4x4_fill(pObject,P1)

	Func flipCoordinates 
		return QMatrix4x4_flipCoordinates(pObject)

	Func frustum P1,P2,P3,P4,P5,P6
		return QMatrix4x4_frustum(pObject,P1,P2,P3,P4,P5,P6)

	Func inverted P1
		pTempObj = new QMatrix4x4
		pTempObj.pObject = QMatrix4x4_inverted(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func isIdentity 
		return QMatrix4x4_isIdentity(pObject)

	Func lookAt P1,P2,P3
		return QMatrix4x4_lookAt(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func map P1
		pTempObj = new QPoint
		pTempObj.pObject = QMatrix4x4_map(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func map_2 P1
		pTempObj = new QPointF
		pTempObj.pObject = QMatrix4x4_map_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func map_3 P1
		pTempObj = new QVector3D
		pTempObj.pObject = QMatrix4x4_map_3(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func map_4 P1
		pTempObj = new QVector4D
		pTempObj.pObject = QMatrix4x4_map_4(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapRect P1
		pTempObj = new QRect
		pTempObj.pObject = QMatrix4x4_mapRect(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func mapRect_2 P1
		return QMatrix4x4_mapRect_2(pObject,GetObjectPointerFromRingObject(P1))

	Func mapVector P1
		pTempObj = new QVector3D
		pTempObj.pObject = QMatrix4x4_mapVector(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func normalMatrix 
		return QMatrix4x4_normalMatrix(pObject)

	Func optimize 
		return QMatrix4x4_optimize(pObject)

	Func ortho P1,P2,P3,P4,P5,P6
		return QMatrix4x4_ortho(pObject,P1,P2,P3,P4,P5,P6)

	Func ortho_2 P1
		return QMatrix4x4_ortho_2(pObject,GetObjectPointerFromRingObject(P1))

	Func ortho_3 P1
		return QMatrix4x4_ortho_3(pObject,GetObjectPointerFromRingObject(P1))

	Func perspective P1,P2,P3,P4
		return QMatrix4x4_perspective(pObject,P1,P2,P3,P4)

	Func rotate P1,P2
		return QMatrix4x4_rotate(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func rotate_2 P1
		return QMatrix4x4_rotate_2(pObject,GetObjectPointerFromRingObject(P1))

	Func rotate_3 P1,P2,P3,P4
		return QMatrix4x4_rotate_3(pObject,P1,P2,P3,P4)

	Func row P1
		pTempObj = new QVector4D
		pTempObj.pObject = QMatrix4x4_row(pObject,P1)
		return pTempObj

	Func scale P1
		return QMatrix4x4_scale(pObject,GetObjectPointerFromRingObject(P1))

	Func scale_2 P1,P2
		return QMatrix4x4_scale_2(pObject,P1,P2)

	Func scale_3 P1,P2,P3
		return QMatrix4x4_scale_3(pObject,P1,P2,P3)

	Func scale_4 P1
		return QMatrix4x4_scale_4(pObject,P1)

	Func setColumn P1,P2
		return QMatrix4x4_setColumn(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setRow P1,P2
		return QMatrix4x4_setRow(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setToIdentity 
		return QMatrix4x4_setToIdentity(pObject)

	Func toAffine 
		return QMatrix4x4_toAffine(pObject)

	Func toTransform 
		return QMatrix4x4_toTransform(pObject)

	Func toTransform_2 P1
		return QMatrix4x4_toTransform_2(pObject,P1)

	Func translate P1
		return QMatrix4x4_translate(pObject,GetObjectPointerFromRingObject(P1))

	Func translate_2 P1,P2
		return QMatrix4x4_translate_2(pObject,P1,P2)

	Func translate_3 P1,P2,P3
		return QMatrix4x4_translate_3(pObject,P1,P2,P3)

	Func transposed 
		pTempObj = new QMatrix4x4
		pTempObj.pObject = QMatrix4x4_transposed(pObject)
		return pTempObj

Class QOpenGLPaintDevice from QPaintDevice

	pObject

	Func init 
		pObject = QOpenGLPaintDevice_new()
		return self

	Func delete
		pObject = QOpenGLPaintDevice_delete(pObject)

	Func ObjectPointer
		return pObject

	Func context 
		pTempObj = new QOpenGLContext
		pTempObj.pObject = QOpenGLPaintDevice_context(pObject)
		return pTempObj

	Func dotsPerMeterX 
		return QOpenGLPaintDevice_dotsPerMeterX(pObject)

	Func dotsPerMeterY 
		return QOpenGLPaintDevice_dotsPerMeterY(pObject)

	Func ensureActiveTarget 
		return QOpenGLPaintDevice_ensureActiveTarget(pObject)

	Func paintFlipped 
		return QOpenGLPaintDevice_paintFlipped(pObject)

	Func setDevicePixelRatio P1
		return QOpenGLPaintDevice_setDevicePixelRatio(pObject,P1)

	Func setDotsPerMeterX P1
		return QOpenGLPaintDevice_setDotsPerMeterX(pObject,P1)

	Func setDotsPerMeterY P1
		return QOpenGLPaintDevice_setDotsPerMeterY(pObject,P1)

	Func setPaintFlipped P1
		return QOpenGLPaintDevice_setPaintFlipped(pObject,P1)

	Func setSize P1
		return QOpenGLPaintDevice_setSize(pObject,GetObjectPointerFromRingObject(P1))

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QOpenGLPaintDevice_size(pObject)
		return pTempObj

Class QPaintDevice
	Func colorCount 
		return QPaintDevice_colorCount()

	Func depth 
		return QPaintDevice_depth()

	Func devicePixelRatio 
		return QPaintDevice_devicePixelRatio()

	Func height 
		return QPaintDevice_height()

	Func heightMM 
		return QPaintDevice_heightMM()

	Func logicalDpiX 
		return QPaintDevice_logicalDpiX()

	Func logicalDpiY 
		return QPaintDevice_logicalDpiY()

	Func paintEngine 
		return QPaintDevice_paintEngine()

	Func paintingActive 
		return QPaintDevice_paintingActive()

	Func physicalDpiX 
		return QPaintDevice_physicalDpiX()

	Func physicalDpiY 
		return QPaintDevice_physicalDpiY()

	Func width 
		return QPaintDevice_width()

	Func widthMM 
		return QPaintDevice_widthMM()

Class QOpenGLTimerQuery

	pObject

	Func init P1
		pObject = QOpenGLTimerQuery_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLTimerQuery_delete(pObject)

	Func ObjectPointer
		return pObject

	Func begin 
		return QOpenGLTimerQuery_begin(pObject)

	Func create 
		return QOpenGLTimerQuery_create(pObject)

	Func destroy 
		return QOpenGLTimerQuery_destroy(pObject)

	Func endtimer 
		return QOpenGLTimerQuery_end(pObject)

	Func isCreated 
		return QOpenGLTimerQuery_isCreated(pObject)

	Func isResultAvailable 
		return QOpenGLTimerQuery_isResultAvailable(pObject)

	Func objectId 
		return QOpenGLTimerQuery_objectId(pObject)

	Func recordTimestamp 
		return QOpenGLTimerQuery_recordTimestamp(pObject)

	Func waitForResult 
		return QOpenGLTimerQuery_waitForResult(pObject)

	Func waitForTimestamp 
		return QOpenGLTimerQuery_waitForTimestamp(pObject)

Class QOpenGLDebugLogger

	pObject

	Func init P1
		pObject = QOpenGLDebugLogger_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLDebugLogger_delete(pObject)

	Func ObjectPointer
		return pObject

	Func disableMessages P1,P2,P3
		return QOpenGLDebugLogger_disableMessages(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func disableMessages_2 P1,P2,P3
		return QOpenGLDebugLogger_disableMessages_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func enableMessages P1,P2,P3
		return QOpenGLDebugLogger_enableMessages(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func enableMessages_2 P1,P2,P3
		return QOpenGLDebugLogger_enableMessages_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func initialize 
		return QOpenGLDebugLogger_initialize(pObject)

	Func isLogging 
		return QOpenGLDebugLogger_isLogging(pObject)

	Func loggedMessages 
		return QOpenGLDebugLogger_loggedMessages(pObject)

	Func loggingMode 
		return QOpenGLDebugLogger_loggingMode(pObject)

	Func maximumMessageLength 
		return QOpenGLDebugLogger_maximumMessageLength(pObject)

	Func popGroup 
		return QOpenGLDebugLogger_popGroup(pObject)

	Func pushGroup P1,P2,P3
		return QOpenGLDebugLogger_pushGroup(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func logMessage P1
		return QOpenGLDebugLogger_logMessage(pObject,GetObjectPointerFromRingObject(P1))

	Func startLogging P1
		return QOpenGLDebugLogger_startLogging(pObject,P1)

	Func stopLogging 
		return QOpenGLDebugLogger_stopLogging(pObject)

Class QOpenGLFramebufferObject

	pObject

	Func init P1,P2,P3
		pObject = QOpenGLFramebufferObject_new(P1,P2,P3)
		return self

	Func delete
		pObject = QOpenGLFramebufferObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func attachment 
		return QOpenGLFramebufferObject_attachment(pObject)

	Func bind 
		return QOpenGLFramebufferObject_bind(pObject)

	Func format 
		return QOpenGLFramebufferObject_format(pObject)

	Func handle 
		return QOpenGLFramebufferObject_handle(pObject)

	Func height 
		return QOpenGLFramebufferObject_height(pObject)

	Func isBound 
		return QOpenGLFramebufferObject_isBound(pObject)

	Func isValid 
		return QOpenGLFramebufferObject_isValid(pObject)

	Func release 
		return QOpenGLFramebufferObject_release(pObject)

	Func setAttachment P1
		return QOpenGLFramebufferObject_setAttachment(pObject,P1)

	Func size 
		pTempObj = new QSize
		pTempObj.pObject = QOpenGLFramebufferObject_size(pObject)
		return pTempObj

	Func texture 
		return QOpenGLFramebufferObject_texture(pObject)

	Func toImage_2 
		pTempObj = new QImage
		pTempObj.pObject = QOpenGLFramebufferObject_toImage_2(pObject)
		return pTempObj

	Func width 
		return QOpenGLFramebufferObject_width(pObject)

	Func bindDefault 
		return QOpenGLFramebufferObject_bindDefault(pObject)

	Func hasOpenGLFramebufferBlit 
		return QOpenGLFramebufferObject_hasOpenGLFramebufferBlit(pObject)

	Func hasOpenGLFramebufferObjects 
		return QOpenGLFramebufferObject_hasOpenGLFramebufferObjects(pObject)

Class QOpenGLVertexArrayObject

	pObject

	Func init P1
		pObject = QOpenGLVertexArrayObject_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLVertexArrayObject_delete(pObject)

	Func ObjectPointer
		return pObject

	Func bind 
		return QOpenGLVertexArrayObject_bind(pObject)

	Func create 
		return QOpenGLVertexArrayObject_create(pObject)

	Func destroy 
		return QOpenGLVertexArrayObject_destroy(pObject)

	Func isCreated 
		return QOpenGLVertexArrayObject_isCreated(pObject)

	Func objectId 
		return QOpenGLVertexArrayObject_objectId(pObject)

	Func release 
		return QOpenGLVertexArrayObject_release(pObject)

Class QOpenGLBuffer

	pObject

	Func init 
		pObject = QOpenGLBuffer_new()
		return self

	Func delete
		pObject = QOpenGLBuffer_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allocate P1,P2
		return QOpenGLBuffer_allocate(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func allocate_2 P1
		return QOpenGLBuffer_allocate_2(pObject,P1)

	Func bind 
		return QOpenGLBuffer_bind(pObject)

	Func bufferId 
		return QOpenGLBuffer_bufferId(pObject)

	Func create 
		return QOpenGLBuffer_create(pObject)

	Func destroy 
		return QOpenGLBuffer_destroy(pObject)

	Func isCreated 
		return QOpenGLBuffer_isCreated(pObject)

	Func map P1
		return QOpenGLBuffer_map(pObject,P1)

	Func read P1,P2,P3
		return QOpenGLBuffer_read(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func release 
		return QOpenGLBuffer_release(pObject)

	Func setUsagePattern P1
		return QOpenGLBuffer_setUsagePattern(pObject,P1)

	Func size 
		return QOpenGLBuffer_size(pObject)

	Func type 
		return QOpenGLBuffer_type(pObject)

	Func unmap 
		return QOpenGLBuffer_unmap(pObject)

	Func usagePattern 
		return QOpenGLBuffer_usagePattern(pObject)

	Func write P1,P2,P3
		return QOpenGLBuffer_write(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func release_2 P1
		return QOpenGLBuffer_release_2(pObject,P1)

Class QOpenGLShaderProgram

	pObject

	Func init P1
		pObject = QOpenGLShaderProgram_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QOpenGLShaderProgram_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addShader P1
		return QOpenGLShaderProgram_addShader(pObject,GetObjectPointerFromRingObject(P1))

	Func addShaderFromSourceCode P1,P2
		return QOpenGLShaderProgram_addShaderFromSourceCode(pObject,P1,P2)

	Func addShaderFromSourceCode_2 P1,P2
		return QOpenGLShaderProgram_addShaderFromSourceCode_2(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func addShaderFromSourceCode_3 P1,P2
		return QOpenGLShaderProgram_addShaderFromSourceCode_3(pObject,P1,P2)

	Func addShaderFromSourceFile P1,P2
		return QOpenGLShaderProgram_addShaderFromSourceFile(pObject,P1,P2)

	Func attributeLocation P1
		return QOpenGLShaderProgram_attributeLocation(pObject,P1)

	Func attributeLocation_2 P1
		return QOpenGLShaderProgram_attributeLocation_2(pObject,GetObjectPointerFromRingObject(P1))

	Func attributeLocation_3 P1
		return QOpenGLShaderProgram_attributeLocation_3(pObject,P1)

	Func bind 
		return QOpenGLShaderProgram_bind(pObject)

	Func bindAttributeLocation P1,P2
		return QOpenGLShaderProgram_bindAttributeLocation(pObject,P1,P2)

	Func bindAttributeLocation_2 P1,P2
		return QOpenGLShaderProgram_bindAttributeLocation_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func bindAttributeLocation_3 P1,P2
		return QOpenGLShaderProgram_bindAttributeLocation_3(pObject,P1,P2)

	Func defaultInnerTessellationLevels 
		return QOpenGLShaderProgram_defaultInnerTessellationLevels(pObject)

	Func defaultOuterTessellationLevels 
		return QOpenGLShaderProgram_defaultOuterTessellationLevels(pObject)

	Func disableAttributeArray P1
		return QOpenGLShaderProgram_disableAttributeArray(pObject,P1)

	Func disableAttributeArray_2 P1
		return QOpenGLShaderProgram_disableAttributeArray_2(pObject,P1)

	Func enableAttributeArray P1
		return QOpenGLShaderProgram_enableAttributeArray(pObject,P1)

	Func enableAttributeArray_2 P1
		return QOpenGLShaderProgram_enableAttributeArray_2(pObject,P1)

	Func isLinked 
		return QOpenGLShaderProgram_isLinked(pObject)

	Func link 
		return QOpenGLShaderProgram_link(pObject)

	Func log 
		return QOpenGLShaderProgram_log(pObject)

	Func maxGeometryOutputVertices 
		return QOpenGLShaderProgram_maxGeometryOutputVertices(pObject)

	Func patchVertexCount 
		return QOpenGLShaderProgram_patchVertexCount(pObject)

	Func programId 
		return QOpenGLShaderProgram_programId(pObject)

	Func release 
		return QOpenGLShaderProgram_release(pObject)

	Func removeAllShaders 
		return QOpenGLShaderProgram_removeAllShaders(pObject)

	Func removeShader P1
		return QOpenGLShaderProgram_removeShader(pObject,GetObjectPointerFromRingObject(P1))

	Func setAttributeArray P1,P2,P3,P4
		return QOpenGLShaderProgram_setAttributeArray(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setAttributeArray_2 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_2(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_3 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_3(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_4 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_4(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_5 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeArray_5(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4,P5)

	Func setAttributeArray_6 P1,P2,P3,P4
		return QOpenGLShaderProgram_setAttributeArray_6(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setAttributeArray_7 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_7(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_8 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_8(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_9 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeArray_9(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setAttributeArray_10 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeArray_10(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4,P5)

	Func setAttributeBuffer P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeBuffer(pObject,P1,P2,P3,P4,P5)

	Func setAttributeBuffer_2 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeBuffer_2(pObject,P1,P2,P3,P4,P5)

	Func setAttributeValue P1,P2
		return QOpenGLShaderProgram_setAttributeValue(pObject,P1,P2)

	Func setAttributeValue_2 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeValue_2(pObject,P1,P2,P3)

	Func setAttributeValue_3 P1,P2,P3,P4
		return QOpenGLShaderProgram_setAttributeValue_3(pObject,P1,P2,P3,P4)

	Func setAttributeValue_4 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeValue_4(pObject,P1,P2,P3,P4,P5)

	Func setAttributeValue_5 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_5(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_6 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_6(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_7 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_7(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_8 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_8(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_9 P1,P2,P3,P4
		return QOpenGLShaderProgram_setAttributeValue_9(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setAttributeValue_10 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_10(pObject,P1,P2)

	Func setAttributeValue_11 P1,P2,P3
		return QOpenGLShaderProgram_setAttributeValue_11(pObject,P1,P2,P3)

	Func setAttributeValue_12 P1,P2,P3,P4
		return QOpenGLShaderProgram_setAttributeValue_12(pObject,P1,P2,P3,P4)

	Func setAttributeValue_13 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setAttributeValue_13(pObject,P1,P2,P3,P4,P5)

	Func setAttributeValue_14 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_14(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_15 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_15(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setAttributeValue_16 P1,P2
		return QOpenGLShaderProgram_setAttributeValue_16(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setDefaultInnerTessellationLevels P1
		return QOpenGLShaderProgram_setDefaultInnerTessellationLevels(pObject,GetObjectPointerFromRingObject(P1))

	Func setDefaultOuterTessellationLevels P1
		return QOpenGLShaderProgram_setDefaultOuterTessellationLevels(pObject,GetObjectPointerFromRingObject(P1))

	Func setPatchVertexCount P1
		return QOpenGLShaderProgram_setPatchVertexCount(pObject,P1)

	Func setUniformValue P1,P2
		return QOpenGLShaderProgram_setUniformValue(pObject,P1,P2)

	Func setUniformValue_2 P1,P2
		return QOpenGLShaderProgram_setUniformValue_2(pObject,P1,P2)

	Func setUniformValue_3 P1,P2
		return QOpenGLShaderProgram_setUniformValue_3(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_4 P1,P2
		return QOpenGLShaderProgram_setUniformValue_4(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_5 P1,P2
		return QOpenGLShaderProgram_setUniformValue_5(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_6 P1,P2
		return QOpenGLShaderProgram_setUniformValue_6(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_7 P1,P2
		return QOpenGLShaderProgram_setUniformValue_7(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_8 P1,P2
		return QOpenGLShaderProgram_setUniformValue_8(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_9 P1,P2
		return QOpenGLShaderProgram_setUniformValue_9(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_10 P1,P2
		return QOpenGLShaderProgram_setUniformValue_10(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_11 P1,P2
		return QOpenGLShaderProgram_setUniformValue_11(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_12 P1,P2
		return QOpenGLShaderProgram_setUniformValue_12(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_13 P1,P2
		return QOpenGLShaderProgram_setUniformValue_13(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_14 P1,P2
		return QOpenGLShaderProgram_setUniformValue_14(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_15 P1,P2
		return QOpenGLShaderProgram_setUniformValue_15(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_16 P1,P2
		return QOpenGLShaderProgram_setUniformValue_16(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_20 P1,P2
		return QOpenGLShaderProgram_setUniformValue_20(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_21 P1,P2
		return QOpenGLShaderProgram_setUniformValue_21(pObject,P1,P2)

	Func setUniformValue_22 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValue_22(pObject,P1,P2,P3)

	Func setUniformValue_23 P1,P2,P3,P4
		return QOpenGLShaderProgram_setUniformValue_23(pObject,P1,P2,P3,P4)

	Func setUniformValue_24 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setUniformValue_24(pObject,P1,P2,P3,P4,P5)

	Func setUniformValue_25 P1,P2
		return QOpenGLShaderProgram_setUniformValue_25(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_26 P1,P2
		return QOpenGLShaderProgram_setUniformValue_26(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_27 P1,P2
		return QOpenGLShaderProgram_setUniformValue_27(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_28 P1,P2
		return QOpenGLShaderProgram_setUniformValue_28(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_29 P1,P2
		return QOpenGLShaderProgram_setUniformValue_29(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_30 P1,P2
		return QOpenGLShaderProgram_setUniformValue_30(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_31 P1,P2
		return QOpenGLShaderProgram_setUniformValue_31(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_32 P1,P2
		return QOpenGLShaderProgram_setUniformValue_32(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_33 P1,P2
		return QOpenGLShaderProgram_setUniformValue_33(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_34 P1,P2
		return QOpenGLShaderProgram_setUniformValue_34(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_35 P1,P2
		return QOpenGLShaderProgram_setUniformValue_35(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_36 P1,P2
		return QOpenGLShaderProgram_setUniformValue_36(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_37 P1,P2
		return QOpenGLShaderProgram_setUniformValue_37(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_38 P1,P2
		return QOpenGLShaderProgram_setUniformValue_38(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_39 P1,P2
		return QOpenGLShaderProgram_setUniformValue_39(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_40 P1,P2
		return QOpenGLShaderProgram_setUniformValue_40(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_41 P1,P2
		return QOpenGLShaderProgram_setUniformValue_41(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_45 P1,P2
		return QOpenGLShaderProgram_setUniformValue_45(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_46 P1,P2
		return QOpenGLShaderProgram_setUniformValue_46(pObject,P1,P2)

	Func setUniformValue_47 P1,P2
		return QOpenGLShaderProgram_setUniformValue_47(pObject,P1,P2)

	Func setUniformValue_48 P1,P2
		return QOpenGLShaderProgram_setUniformValue_48(pObject,P1,P2)

	Func setUniformValue_49 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValue_49(pObject,P1,P2,P3)

	Func setUniformValue_50 P1,P2,P3,P4
		return QOpenGLShaderProgram_setUniformValue_50(pObject,P1,P2,P3,P4)

	Func setUniformValue_51 P1,P2,P3,P4,P5
		return QOpenGLShaderProgram_setUniformValue_51(pObject,P1,P2,P3,P4,P5)

	Func setUniformValue_52 P1,P2
		return QOpenGLShaderProgram_setUniformValue_52(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_53 P1,P2
		return QOpenGLShaderProgram_setUniformValue_53(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValue_54 P1,P2
		return QOpenGLShaderProgram_setUniformValue_54(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setUniformValueArray P1,P2,P3,P4
		return QOpenGLShaderProgram_setUniformValueArray(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setUniformValueArray_2 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_2(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_3 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_3(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_4 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_4(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_5 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_5(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_6 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_6(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_7 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_7(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_8 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_8(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_9 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_9(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_10 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_10(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_11 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_11(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_12 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_12(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_13 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_13(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_14 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_14(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_15 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_15(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_16 P1,P2,P3,P4
		return QOpenGLShaderProgram_setUniformValueArray_16(pObject,P1,GetObjectPointerFromRingObject(P2),P3,P4)

	Func setUniformValueArray_17 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_17(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_18 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_18(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_19 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_19(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_20 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_20(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_21 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_21(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_22 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_22(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_23 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_23(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_24 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_24(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_25 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_25(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_26 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_26(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_27 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_27(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_28 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_28(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_29 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_29(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func setUniformValueArray_30 P1,P2,P3
		return QOpenGLShaderProgram_setUniformValueArray_30(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func shaders 
		return QOpenGLShaderProgram_shaders(pObject)

	Func uniformLocation P1
		return QOpenGLShaderProgram_uniformLocation(pObject,P1)

	Func uniformLocation_2 P1
		return QOpenGLShaderProgram_uniformLocation_2(pObject,GetObjectPointerFromRingObject(P1))

	Func uniformLocation_3 P1
		return QOpenGLShaderProgram_uniformLocation_3(pObject,P1)

	Func hasOpenGLShaderPrograms P1
		return QOpenGLShaderProgram_hasOpenGLShaderPrograms(pObject,GetObjectPointerFromRingObject(P1))

Class QOpenGLShader

	pObject

	Func init P1,P2
		pObject = QOpenGLShader_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QOpenGLShader_delete(pObject)

	Func ObjectPointer
		return pObject

	Func compileSourceCode P1
		return QOpenGLShader_compileSourceCode(pObject,P1)

	Func compileSourceCode_2 P1
		return QOpenGLShader_compileSourceCode_2(pObject,GetObjectPointerFromRingObject(P1))

	Func compileSourceCode_3 P1
		return QOpenGLShader_compileSourceCode_3(pObject,P1)

	Func compileSourceFile P1
		return QOpenGLShader_compileSourceFile(pObject,P1)

	Func isCompiled 
		return QOpenGLShader_isCompiled(pObject)

	Func log 
		return QOpenGLShader_log(pObject)

	Func shaderId 
		return QOpenGLShader_shaderId(pObject)

	Func shaderType 
		return QOpenGLShader_shaderType(pObject)

	Func sourceCode 
		pTempObj = new QByteArray
		pTempObj.pObject = QOpenGLShader_sourceCode(pObject)
		return pTempObj

	Func hasOpenGLShaders P1,P2
		return QOpenGLShader_hasOpenGLShaders(pObject,P1,GetObjectPointerFromRingObject(P2))

Class QOpenGLTexture

	pObject

	Func init P1
		pObject = QOpenGLTexture_new(P1)
		return self

	Func delete
		pObject = QOpenGLTexture_delete(pObject)

	Func ObjectPointer
		return pObject

	Func allocateStorage 
		return QOpenGLTexture_allocateStorage(pObject)

	Func bind 
		return QOpenGLTexture_bind(pObject)

	Func bind_2 P1,P2
		return QOpenGLTexture_bind_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func borderColor 
		pTempObj = new QColor
		pTempObj.pObject = QOpenGLTexture_borderColor(pObject)
		return pTempObj

	Func borderColor_2 P1
		return QOpenGLTexture_borderColor_2(pObject,GetObjectPointerFromRingObject(P1))

	Func borderColor_3 P1
		return QOpenGLTexture_borderColor_3(pObject,GetObjectPointerFromRingObject(P1))

	Func borderColor_4 P1
		return QOpenGLTexture_borderColor_4(pObject,GetObjectPointerFromRingObject(P1))

	Func create 
		return QOpenGLTexture_create(pObject)

	Func createTextureView P1,P2,P3,P4,P5,P6
		pTempObj = new QOpenGLTexture
		pTempObj.pObject = QOpenGLTexture_createTextureView(pObject,P1,P2,P3,P4,P5,P6)
		return pTempObj

	Func depth 
		return QOpenGLTexture_depth(pObject)

	Func depthStencilMode 
		return QOpenGLTexture_depthStencilMode(pObject)

	Func destroy 
		return QOpenGLTexture_destroy(pObject)

	Func faces 
		return QOpenGLTexture_faces(pObject)

	Func format 
		return QOpenGLTexture_format(pObject)

	Func generateMipMaps 
		return QOpenGLTexture_generateMipMaps(pObject)

	Func generateMipMaps_2 P1,P2
		return QOpenGLTexture_generateMipMaps_2(pObject,P1,P2)

	Func height 
		return QOpenGLTexture_height(pObject)

	Func isAutoMipMapGenerationEnabled 
		return QOpenGLTexture_isAutoMipMapGenerationEnabled(pObject)

	Func isBound 
		return QOpenGLTexture_isBound(pObject)

	Func isBound_2 P1
		return QOpenGLTexture_isBound_2(pObject,GetObjectPointerFromRingObject(P1))

	Func isCreated 
		return QOpenGLTexture_isCreated(pObject)

	Func isStorageAllocated 
		return QOpenGLTexture_isStorageAllocated(pObject)

	Func isTextureView 
		return QOpenGLTexture_isTextureView(pObject)

	Func layers 
		return QOpenGLTexture_layers(pObject)

	Func levelOfDetailRange 
		return QOpenGLTexture_levelOfDetailRange(pObject)

	Func levelofDetailBias 
		return QOpenGLTexture_levelofDetailBias(pObject)

	Func magnificationFilter 
		return QOpenGLTexture_magnificationFilter(pObject)

	Func maximumAnisotropy 
		return QOpenGLTexture_maximumAnisotropy(pObject)

	Func maximumLevelOfDetail 
		return QOpenGLTexture_maximumLevelOfDetail(pObject)

	Func maximumMipLevels 
		return QOpenGLTexture_maximumMipLevels(pObject)

	Func minificationFilter 
		return QOpenGLTexture_minificationFilter(pObject)

	Func minimumLevelOfDetail 
		return QOpenGLTexture_minimumLevelOfDetail(pObject)

	Func mipBaseLevel 
		return QOpenGLTexture_mipBaseLevel(pObject)

	Func mipLevels 
		return QOpenGLTexture_mipLevels(pObject)

	Func mipMaxLevel 
		return QOpenGLTexture_mipMaxLevel(pObject)

	Func release 
		return QOpenGLTexture_release(pObject)

	Func release_2 P1,P2
		return QOpenGLTexture_release_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setAutoMipMapGenerationEnabled P1
		return QOpenGLTexture_setAutoMipMapGenerationEnabled(pObject,P1)

	Func setBorderColor P1
		return QOpenGLTexture_setBorderColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setBorderColor_3 P1,P2,P3,P4
		return QOpenGLTexture_setBorderColor_3(pObject,P1,P2,P3,P4)

	Func setBorderColor_4 P1,P2,P3,P4
		return QOpenGLTexture_setBorderColor_4(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func setCompressedData P1,P2,P3,P4,P5,P6
		return QOpenGLTexture_setCompressedData(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6))

	Func setCompressedData_3 P1,P2,P3,P4,P5
		return QOpenGLTexture_setCompressedData_3(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func setCompressedData_4 P1,P2,P3,P4
		return QOpenGLTexture_setCompressedData_4(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func setCompressedData_5 P1,P2,P3
		return QOpenGLTexture_setCompressedData_5(pObject,P1,GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3))

	Func setData P1,P2,P3,P4,P5,P6,P7
		return QOpenGLTexture_setData(pObject,P1,P2,P3,P4,P5,GetObjectPointerFromRingObject(P6),GetObjectPointerFromRingObject(P7))

	Func setData_3 P1,P2,P3,P4,P5,P6
		return QOpenGLTexture_setData_3(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6))

	Func setData_4 P1,P2,P3,P4,P5
		return QOpenGLTexture_setData_4(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4),GetObjectPointerFromRingObject(P5))

	Func setData_5 P1,P2,P3,P4
		return QOpenGLTexture_setData_5(pObject,P1,P2,GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func setData_6 P1,P2
		return QOpenGLTexture_setData_6(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func setDepthStencilMode P1
		return QOpenGLTexture_setDepthStencilMode(pObject,P1)

	Func setFormat P1
		return QOpenGLTexture_setFormat(pObject,P1)

	Func setLayers P1
		return QOpenGLTexture_setLayers(pObject,P1)

	Func setLevelOfDetailRange P1,P2
		return QOpenGLTexture_setLevelOfDetailRange(pObject,P1,P2)

	Func setLevelofDetailBias P1
		return QOpenGLTexture_setLevelofDetailBias(pObject,P1)

	Func setMagnificationFilter P1
		return QOpenGLTexture_setMagnificationFilter(pObject,P1)

	Func setMaximumAnisotropy P1
		return QOpenGLTexture_setMaximumAnisotropy(pObject,P1)

	Func setMaximumLevelOfDetail P1
		return QOpenGLTexture_setMaximumLevelOfDetail(pObject,P1)

	Func setMinMagFilters P1,P2
		return QOpenGLTexture_setMinMagFilters(pObject,P1,P2)

	Func setMinificationFilter P1
		return QOpenGLTexture_setMinificationFilter(pObject,P1)

	Func setMinimumLevelOfDetail P1
		return QOpenGLTexture_setMinimumLevelOfDetail(pObject,P1)

	Func setMipBaseLevel P1
		return QOpenGLTexture_setMipBaseLevel(pObject,P1)

	Func setMipLevelRange P1,P2
		return QOpenGLTexture_setMipLevelRange(pObject,P1,P2)

	Func setMipLevels P1
		return QOpenGLTexture_setMipLevels(pObject,P1)

	Func setMipMaxLevel P1
		return QOpenGLTexture_setMipMaxLevel(pObject,P1)

	Func setSize P1,P2,P3
		return QOpenGLTexture_setSize(pObject,P1,P2,P3)

	Func setSwizzleMask P1,P2
		return QOpenGLTexture_setSwizzleMask(pObject,P1,P2)

	Func setSwizzleMask_2 P1,P2,P3,P4
		return QOpenGLTexture_setSwizzleMask_2(pObject,P1,P2,P3,P4)

	Func setWrapMode P1
		return QOpenGLTexture_setWrapMode(pObject,P1)

	Func setWrapMode_2 P1,P2
		return QOpenGLTexture_setWrapMode_2(pObject,P1,P2)

	Func swizzleMask P1
		return QOpenGLTexture_swizzleMask(pObject,P1)

	Func textureId 
		return QOpenGLTexture_textureId(pObject)

	Func width 
		return QOpenGLTexture_width(pObject)

	Func wrapMode P1
		return QOpenGLTexture_wrapMode(pObject,P1)

	Func boundTextureId P1
		return QOpenGLTexture_boundTextureId(pObject,P1)

	Func hasFeature P1
		return QOpenGLTexture_hasFeature(pObject,P1)

Class QTabBar from QWidget

	pObject

	Func init P1
		pObject = QTabBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTabBar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func addTab P1
		return QTabBar_addTab(pObject,P1)

	Func addTab_2 P1,P2
		return QTabBar_addTab_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func count 
		return QTabBar_count(pObject)

	Func currentIndex 
		return QTabBar_currentIndex(pObject)

	Func documentMode 
		return QTabBar_documentMode(pObject)

	Func drawBase 
		return QTabBar_drawBase(pObject)

	Func elideMode 
		return QTabBar_elideMode(pObject)

	Func expanding 
		return QTabBar_expanding(pObject)

	Func iconSize 
		pTempObj = new QSize
		pTempObj.pObject = QTabBar_iconSize(pObject)
		return pTempObj

	Func insertTab P1,P2
		return QTabBar_insertTab(pObject,P1,P2)

	Func insertTab_2 P1,P2,P3
		return QTabBar_insertTab_2(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func isMovable 
		return QTabBar_isMovable(pObject)

	Func isTabEnabled P1
		return QTabBar_isTabEnabled(pObject,P1)

	Func moveTab P1,P2
		return QTabBar_moveTab(pObject,P1,P2)

	Func removeTab P1
		return QTabBar_removeTab(pObject,P1)

	Func selectionBehaviorOnRemove 
		return QTabBar_selectionBehaviorOnRemove(pObject)

	Func setDocumentMode P1
		return QTabBar_setDocumentMode(pObject,P1)

	Func setDrawBase P1
		return QTabBar_setDrawBase(pObject,P1)

	Func setElideMode P1
		return QTabBar_setElideMode(pObject,P1)

	Func setExpanding P1
		return QTabBar_setExpanding(pObject,P1)

	Func setIconSize P1
		return QTabBar_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setMovable P1
		return QTabBar_setMovable(pObject,P1)

	Func setSelectionBehaviorOnRemove P1
		return QTabBar_setSelectionBehaviorOnRemove(pObject,P1)

	Func setShape P1
		return QTabBar_setShape(pObject,P1)

	Func setTabButton P1,P2,P3
		return QTabBar_setTabButton(pObject,P1,P2,GetObjectPointerFromRingObject(P3))

	Func setTabData P1,P2
		return QTabBar_setTabData(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setTabEnabled P1,P2
		return QTabBar_setTabEnabled(pObject,P1,P2)

	Func setTabIcon P1,P2
		return QTabBar_setTabIcon(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setTabText P1,P2
		return QTabBar_setTabText(pObject,P1,P2)

	Func setTabTextColor P1,P2
		return QTabBar_setTabTextColor(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setTabToolTip P1,P2
		return QTabBar_setTabToolTip(pObject,P1,P2)

	Func setTabWhatsThis P1,P2
		return QTabBar_setTabWhatsThis(pObject,P1,P2)

	Func setTabsClosable P1
		return QTabBar_setTabsClosable(pObject,P1)

	Func setUsesScrollButtons P1
		return QTabBar_setUsesScrollButtons(pObject,P1)

	Func shape 
		return QTabBar_shape(pObject)

	Func tabAt P1
		return QTabBar_tabAt(pObject,GetObjectPointerFromRingObject(P1))

	Func tabButton P1,P2
		pTempObj = new QWidget
		pTempObj.pObject = QTabBar_tabButton(pObject,P1,P2)
		return pTempObj

	Func tabData P1
		pTempObj = new QVariant
		pTempObj.pObject = QTabBar_tabData(pObject,P1)
		return pTempObj

	Func tabIcon P1
		pTempObj = new QIcon
		pTempObj.pObject = QTabBar_tabIcon(pObject,P1)
		return pTempObj

	Func tabRect P1
		pTempObj = new QRect
		pTempObj.pObject = QTabBar_tabRect(pObject,P1)
		return pTempObj

	Func tabText P1
		return QTabBar_tabText(pObject,P1)

	Func tabTextColor P1
		pTempObj = new QColor
		pTempObj.pObject = QTabBar_tabTextColor(pObject,P1)
		return pTempObj

	Func tabToolTip P1
		return QTabBar_tabToolTip(pObject,P1)

	Func tabWhatsThis P1
		return QTabBar_tabWhatsThis(pObject,P1)

	Func tabsClosable 
		return QTabBar_tabsClosable(pObject)

	Func usesScrollButtons 
		return QTabBar_usesScrollButtons(pObject)

	Func setCurrentIndex P1
		return QTabBar_setCurrentIndex(pObject,P1)

	Func setcurrentChangedEvent P1
		return QTabBar_setcurrentChangedEvent(pObject,P1)

	Func settabCloseRequestedEvent P1
		return QTabBar_settabCloseRequestedEvent(pObject,P1)

	Func settabMovedEvent P1
		return QTabBar_settabMovedEvent(pObject,P1)

	Func getcurrentChangedEvent 
		return QTabBar_getcurrentChangedEvent(pObject)

	Func gettabCloseRequestedEvent 
		return QTabBar_gettabCloseRequestedEvent(pObject)

	Func gettabMovedEvent 
		return QTabBar_gettabMovedEvent(pObject)

Class QFile from QFileDevice

	pObject

	Func init 
		pObject = QFile_new()
		return self

	Func delete
		pObject = QFile_delete(pObject)

	Func ObjectPointer
		return pObject

	Func copy P1
		return QFile_copy(pObject,P1)

	Func exists 
		return QFile_exists(pObject)

	Func link P1
		return QFile_link(pObject,P1)

	Func open P1,P2,P3
		return QFile_open(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func open_2 P1,P2,P3
		return QFile_open_2(pObject,P1,P2,P3)

	Func remove 
		return QFile_remove(pObject)

	Func rename P1
		return QFile_rename(pObject,P1)

	Func setFileName P1
		return QFile_setFileName(pObject,P1)

	Func symLinkTarget 
		return QFile_symLinkTarget(pObject)

	Func copy_2 P1,P2
		return QFile_copy_2(pObject,P1,P2)

	Func decodeName P1
		return QFile_decodeName(pObject,GetObjectPointerFromRingObject(P1))

	Func decodeName_2 P1
		return QFile_decodeName_2(pObject,P1)

	Func encodeName P1
		pTempObj = new QByteArray
		pTempObj.pObject = QFile_encodeName(pObject,P1)
		return pTempObj

	Func exists_2 P1
		return QFile_exists_2(pObject,P1)

	Func link_2 P1,P2
		return QFile_link_2(pObject,P1,P2)

	Func permissions P1
		return QFile_permissions(pObject,P1)

	Func remove_2 P1
		return QFile_remove_2(pObject,P1)

	Func rename_2 P1,P2
		return QFile_rename_2(pObject,P1,P2)

	Func resize P1,P2
		return QFile_resize(pObject,P1,P2)

	Func setPermissions P1,P2
		return QFile_setPermissions(pObject,P1,P2)

	Func symLinkTarget_2 P1
		return QFile_symLinkTarget_2(pObject,P1)

Class QFileDevice from QIODevice
	Func error 
		return QFileDevice_error()

	Func flush 
		return QFileDevice_flush()

	Func handle 
		return QFileDevice_handle()

	Func map P1,P2,P3
		return QFileDevice_map(P1,P2,P3)

	Func permissions 
		return QFileDevice_permissions()

	Func resize P1
		return QFileDevice_resize(P1)

	Func fileName 
		return QFileDevice_fileName()

	Func setPermissions P1
		return QFileDevice_setPermissions(P1)

	Func unmap P1
		return QFileDevice_unmap(GetObjectPointerFromRingObject(P1))

	Func unsetError 
		return QFileDevice_unsetError()

Class QStandardPaths
	Func displayName P1
		return QStandardPaths_displayName(P1)

	Func findExecutable P1,P2
		return QStandardPaths_findExecutable(P1,GetObjectPointerFromRingObject(P2))

	Func locate P1,P2,P3
		return QStandardPaths_locate(P1,P2,P3)

	Func locateAll P1,P2,P3
		pTempObj = new QStringList
		pTempObj.pObject = QStandardPaths_locateAll(P1,P2,P3)
		return pTempObj

	Func setTestModeEnabled P1
		return QStandardPaths_setTestModeEnabled(P1)

	Func standardLocations P1
		pTempObj = new QStringList
		pTempObj.pObject = QStandardPaths_standardLocations(P1)
		return pTempObj

	Func writableLocation P1
		return QStandardPaths_writableLocation(P1)

Class QQuickWidget from QWidget

	pObject

	Func init P1
		pObject = QQuickWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QQuickWidget_delete(pObject)

	Func ObjectPointer
		return pObject

	Func engine 
		return QQuickWidget_engine(pObject)

	Func errors 
		return QQuickWidget_errors(pObject)

	Func format 
		pTempObj = new QSurfaceFormat
		pTempObj.pObject = QQuickWidget_format(pObject)
		return pTempObj

	Func grabFramebuffer 
		pTempObj = new QImage
		pTempObj.pObject = QQuickWidget_grabFramebuffer(pObject)
		return pTempObj

	Func initialSize 
		pTempObj = new QSize
		pTempObj.pObject = QQuickWidget_initialSize(pObject)
		return pTempObj

	Func quickWindow 
		return QQuickWidget_quickWindow(pObject)

	Func resizeMode 
		return QQuickWidget_resizeMode(pObject)

	Func rootContext 
		return QQuickWidget_rootContext(pObject)

	Func rootObject 
		return QQuickWidget_rootObject(pObject)

	Func setClearColor P1
		return QQuickWidget_setClearColor(pObject,GetObjectPointerFromRingObject(P1))

	Func setFormat P1
		return QQuickWidget_setFormat(pObject,GetObjectPointerFromRingObject(P1))

	Func setResizeMode P1
		return QQuickWidget_setResizeMode(pObject,P1)

	Func source 
		pTempObj = new QUrl
		pTempObj.pObject = QQuickWidget_source(pObject)
		return pTempObj

	Func status 
		return QQuickWidget_status(pObject)

	Func setSource P1
		return QQuickWidget_setSource(pObject,GetObjectPointerFromRingObject(P1))

	Func setsceneGraphErrorEvent P1
		return QQuickWidget_setsceneGraphErrorEvent(pObject,P1)

	Func setstatusChangedEvent P1
		return QQuickWidget_setstatusChangedEvent(pObject,P1)

	Func getsceneGraphErrorEvent 
		return QQuickWidget_getsceneGraphErrorEvent(pObject)

	Func getstatusChangedEvent 
		return QQuickWidget_getstatusChangedEvent(pObject)

Class QQmlError

	pObject

	Func init 
		pObject = QQmlError_new()
		return self

	Func delete
		pObject = QQmlError_delete(pObject)

	Func ObjectPointer
		return pObject

	Func column 
		return QQmlError_column(pObject)

	Func description 
		return QQmlError_description(pObject)

	Func isValid 
		return QQmlError_isValid(pObject)

	Func line 
		return QQmlError_line(pObject)

	Func object 
		pTempObj = new QObject
		pTempObj.pObject = QQmlError_object(pObject)
		return pTempObj

	Func setColumn P1
		return QQmlError_setColumn(pObject,P1)

	Func setDescription P1
		return QQmlError_setDescription(pObject,P1)

	Func setLine P1
		return QQmlError_setLine(pObject,P1)

	Func setObject P1
		return QQmlError_setObject(pObject,GetObjectPointerFromRingObject(P1))

	Func setUrl P1
		return QQmlError_setUrl(pObject,GetObjectPointerFromRingObject(P1))

	Func toString 
		return QQmlError_toString(pObject)

	Func url 
		pTempObj = new QUrl
		pTempObj.pObject = QQmlError_url(pObject)
		return pTempObj

Class QPixmap2 from QPixmap

	pObject

	Func init P1,P2
		pObject = QPixmap2_new(P1,P2)
		return self

	Func delete
		pObject = QPixmap2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QIcon

	pObject

	Func init P1
		pObject = QIcon_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QIcon_delete(pObject)

	Func ObjectPointer
		return pObject

Class QSize

	pObject

	Func init P1,P2
		pObject = QSize_new(P1,P2)
		return self

	Func delete
		pObject = QSize_delete(pObject)

	Func ObjectPointer
		return pObject

Class QFrame2 from QFrame

	pObject

	Func init 
		pObject = QFrame2_new()
		return self

	Func delete
		pObject = QFrame2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QFrame3 from QFrame

	pObject

	Func init P1
		pObject = QFrame3_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QFrame3_delete(pObject)

	Func ObjectPointer
		return pObject

Class QDateEdit from QDateTimeEdit

	pObject

	Func init P1
		pObject = QDateEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDateEdit_delete(pObject)

	Func ObjectPointer
		return pObject

Class QPainter2 from QPainter

	pObject

	Func init P1
		pObject = QPainter2_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QPainter2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QKeySequence

	pObject

	Func init P1
		pObject = QKeySequence_new(P1)
		return self

	Func delete
		pObject = QKeySequence_delete(pObject)

	Func ObjectPointer
		return pObject

Class QXmlStreamEntityResolver

	pObject

	Func init 
		pObject = QXmlStreamEntityResolver_new()
		return self

	Func delete
		pObject = QXmlStreamEntityResolver_delete(pObject)

	Func ObjectPointer
		return pObject

Class QCameraViewfinder from QVideoWidget

	pObject

	Func init P1
		pObject = QCameraViewfinder_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QCameraViewfinder_delete(pObject)

	Func ObjectPointer
		return pObject

Class QCompleter2 from QCompleter

	pObject

	Func init P1,P2
		pObject = QCompleter2_new(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QCompleter2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QCompleter3 from QCompleter

	pObject

	Func init P1,P2
		pObject = QCompleter3_new(GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QCompleter3_delete(pObject)

	Func ObjectPointer
		return pObject

Class QAxObject from QAxBase

	pObject

	Func init P1
		pObject = QAxObject_new(P1)
		return self

	Func delete
		pObject = QAxObject_delete(pObject)

	Func ObjectPointer
		return pObject

Class QScrollBar from QAbstractSlider

	pObject

	Func init P1
		pObject = QScrollBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QScrollBar_delete(pObject)

	Func ObjectPointer
		return pObject

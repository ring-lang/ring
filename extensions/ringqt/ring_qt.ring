
Func GetObjectPointerFromRingObject pObj
     if isobject(pObj)
	if isattribute(pObj,'pObject')
		return pObj.pObject
	else 
		raise('Error, The parameter is not a GUI object!')
	ok
     ok	
     return pObj		

Class qApp


	Func exec 
		return qApp_exec()

	Func quit 
		return qApp_quit()

	Func processEvents 
		return qApp_processEvents()

Class qTest


	Func qsleep P1
		return qTest_qsleep(P1)

Class QObject

	pObject

	Func init 
		pObject = QObject_new()
		return self

	Func delete
		pObject = QObject_delete(pObject)

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
		return QObject_thread(pObject)

	Func deleteLater 
		return QObject_deleteLater(pObject)

Class QWidget from QObject

	pObject

	Func init 
		pObject = QWidget_new()
		return self

	Func delete
		pObject = QWidget_delete(pObject)

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
		return QWidget_childrenRegion(pObject)

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
		return QWidget_cursor(pObject)

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

	Func fontMetrics 
		return QWidget_fontMetrics(pObject)

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
		return QWidget_layout(pObject)

	Func layoutDirection 
		return QWidget_layoutDirection(pObject)

	Func locale 
		return QWidget_locale(pObject)

	Func mapFrom P1,P2
		return QWidget_mapFrom(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func mapFromGlobal P1
		return QWidget_mapFromGlobal(pObject,GetObjectPointerFromRingObject(P1))

	Func mapFromParent P1
		return QWidget_mapFromParent(pObject,GetObjectPointerFromRingObject(P1))

	Func mapTo P1,P2
		return QWidget_mapTo(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func mapToGlobal P1
		return QWidget_mapToGlobal(pObject,GetObjectPointerFromRingObject(P1))

	Func mapToParent P1
		return QWidget_mapToParent(pObject,GetObjectPointerFromRingObject(P1))

	Func mask 
		return QWidget_mask(pObject)

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
		return QWidget_pos(pObject)

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
		return QWidget_visibleRegion(pObject)

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

	Func setText P1
		return QPushButton_setText(pObject,P1)

	Func setClickEvent P1
		return QPushButton_setClickEvent(pObject,P1)

	Func setIcon P1
		return QPushButton_setIcon(pObject,GetObjectPointerFromRingObject(P1))

	Func setIconSize P1
		return QPushButton_setIconSize(pObject,GetObjectPointerFromRingObject(P1))

Class QPixmap

	pObject

	Func init P1
		pObject = QPixmap_new(P1)
		return self

	Func delete
		pObject = QPixmap_delete(pObject)

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

Class QLineEdit from QWidget

	pObject

	Func init P1
		pObject = QLineEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QLineEdit_delete(pObject)

	Func alignment 
		return QLineEdit_alignment(pObject)

	Func backspace 
		return QLineEdit_backspace(pObject)

	Func completer 
		return QLineEdit_completer(pObject)

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

Class QVBoxLayout

	pObject

	Func init 
		pObject = QVBoxLayout_new()
		return self

	Func delete
		pObject = QVBoxLayout_delete(pObject)

	Func addWidget P1
		return QVBoxLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func addLayout P1
		return QVBoxLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1))

Class QHBoxLayout

	pObject

	Func init 
		pObject = QHBoxLayout_new()
		return self

	Func delete
		pObject = QHBoxLayout_delete(pObject)

	Func addWidget P1
		return QHBoxLayout_addWidget(pObject,GetObjectPointerFromRingObject(P1))

	Func addLayout P1
		return QHBoxLayout_addLayout(pObject,GetObjectPointerFromRingObject(P1))

Class QTextEdit from QWidget

	pObject

	Func init P1
		pObject = QTextEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTextEdit_delete(pObject)

	Func acceptRichText 
		return QTextEdit_acceptRichText(pObject)

	Func alignment 
		return QTextEdit_alignment(pObject)

	Func anchorAt P1
		return QTextEdit_anchorAt(pObject,GetObjectPointerFromRingObject(P1))

	Func canPaste 
		return QTextEdit_canPaste(pObject)

	Func currentCharFormat 
		return QTextEdit_currentCharFormat(pObject)

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

Class QListWidget from QWidget

	pObject

	Func init P1
		pObject = QListWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QListWidget_delete(pObject)

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

Class QTreeView from QAbstractItemView

	pObject

	Func init P1
		pObject = QTreeView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTreeView_delete(pObject)

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

Class QDir

	pObject

	Func init 
		pObject = QDir_new()
		return self

	Func delete
		pObject = QDir_delete(pObject)

	Func currentPath 
		return QDir_currentPath(pObject)

	Func setNameFilters P1
		return QDir_setNameFilters(pObject,GetObjectPointerFromRingObject(P1))

Class QFileSystemModel

	pObject

	Func init 
		pObject = QFileSystemModel_new()
		return self

	Func delete
		pObject = QFileSystemModel_delete(pObject)

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
		return QFileSystemModel_lastModified(pObject,GetObjectPointerFromRingObject(P1))

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

Class QTreeWidget from QWidget

	pObject

	Func init P1
		pObject = QTreeWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTreeWidget_delete(pObject)

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

Class QTreeWidgetItem

	pObject

	Func init 
		pObject = QTreeWidgetItem_new()
		return self

	Func delete
		pObject = QTreeWidgetItem_delete(pObject)

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

	Func addItem P1,P2
		return QComboBox_addItem(pObject,P1,P2)

	Func completer 
		return QComboBox_completer(pObject)

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

	Func setactivatedEvent P1
		return QComboBox_setactivatedEvent(pObject,P1)

	Func setcurrentIndexChangedEvent P1
		return QComboBox_setcurrentIndexChangedEvent(pObject,P1)

	Func seteditTextChangedEvent P1
		return QComboBox_seteditTextChangedEvent(pObject,P1)

	Func sethighlightedEvent P1
		return QComboBox_sethighlightedEvent(pObject,P1)

Class QMenuBar from QWidget

	pObject

	Func init P1
		pObject = QMenuBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QMenuBar_delete(pObject)

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

	Func exec 
		pTempObj = new QAction
		pTempObj.pObject = QMenu_exec(pObject)
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

	Func addDockWidget P1,P2,P3
		return QMainWindow_addDockWidget(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func addToolBar P1
		pTempObj = new QToolBar
		pTempObj.pObject = QMainWindow_addToolBar(pObject,P1)
		return pTempObj

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

Class QTabWidget from QWidget

	pObject

	Func init P1
		pObject = QTabWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTabWidget_delete(pObject)

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

Class QTableWidgetItem

	pObject

	Func init P1
		pObject = QTableWidgetItem_new(P1)
		return self

	Func delete
		pObject = QTableWidgetItem_delete(pObject)

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

	Func addScrollBarWidget P1,P2
		return QAbstractScrollArea_addScrollBarWidget(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func cornerWidget 
		pTempObj = new QWidget
		pTempObj.pObject = QAbstractScrollArea_cornerWidget(pObject)
		return pTempObj

	Func horizontalScrollBar 
		return QAbstractScrollArea_horizontalScrollBar(pObject)

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
		return QAbstractScrollArea_verticalScrollBar(pObject)

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

Class QTableWidget from QAbstractItemView

	pObject

	Func init P1
		pObject = QTableWidget_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTableWidget_delete(pObject)

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

Class QProgressBar from QWidget

	pObject

	Func init P1
		pObject = QProgressBar_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QProgressBar_delete(pObject)

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

Class QSpinBox from QWidget

	pObject

	Func init P1
		pObject = QSpinBox_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QSpinBox_delete(pObject)

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

Class QAbstractSlider from QWidget

	pObject

	Func init P1
		pObject = QAbstractSlider_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractSlider_delete(pObject)

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

Class QDateTimeEdit from QAbstractSpinBox

	pObject

	Func init P1
		pObject = QDateTimeEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDateTimeEdit_delete(pObject)

	Func calendarPopup 
		return QDateTimeEdit_calendarPopup(pObject)

	Func calendarWidget 
		return QDateTimeEdit_calendarWidget(pObject)

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
		return QDateTimeEdit_dateTime(pObject)

	Func displayFormat 
		return QDateTimeEdit_displayFormat(pObject)

	Func displayedSections 
		return QDateTimeEdit_displayedSections(pObject)

	Func maximumDate 
		pTempObj = new QDate
		pTempObj.pObject = QDateTimeEdit_maximumDate(pObject)
		return pTempObj

	Func maximumDateTime 
		return QDateTimeEdit_maximumDateTime(pObject)

	Func maximumTime 
		pTempObj = new QTime
		pTempObj.pObject = QDateTimeEdit_maximumTime(pObject)
		return pTempObj

	Func minimumDate 
		pTempObj = new QDate
		pTempObj.pObject = QDateTimeEdit_minimumDate(pObject)
		return pTempObj

	Func minimumDateTime 
		return QDateTimeEdit_minimumDateTime(pObject)

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

Class QWebView from QWidget

	pObject

	Func init P1
		pObject = QWebView_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QWebView_delete(pObject)

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
		return QWebView_setZoomFactor(pObject,GetObjectPointerFromRingObject(P1))

	Func settings 
		pTempObj = new QWebSettings
		pTempObj.pObject = QWebView_settings(pObject)
		return pTempObj

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

Class QUrl

	pObject

	Func init P1
		pObject = QUrl_new(P1)
		return self

	Func delete
		pObject = QUrl_delete(pObject)

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

Class QAbstractButton from QWidget

	pObject

	Func init P1
		pObject = QAbstractButton_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAbstractButton_delete(pObject)

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

Class QButtonGroup

	pObject

	Func init P1
		pObject = QButtonGroup_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QButtonGroup_delete(pObject)

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

Class QMediaPlayer

	pObject

	Func init 
		pObject = QMediaPlayer_new()
		return self

	Func delete
		pObject = QMediaPlayer_delete(pObject)

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
		return QMediaPlayer_setPlaybackRate(pObject,GetObjectPointerFromRingObject(P1))

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

Class QAction

	pObject

	Func init P1
		pObject = QAction_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QAction_delete(pObject)

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

Class QEvent

	pObject

	Func init P1
		pObject = QEvent_new(P1)
		return self

	Func delete
		pObject = QEvent_delete(pObject)

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

Class QFileDialog from QWidget

	pObject

	Func init P1
		pObject = QFileDialog_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QFileDialog_delete(pObject)

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
		return QPainter_brushOrigin(pObject)

	Func clipBoundingRect 
		return QPainter_clipBoundingRect(pObject)

	Func clipPath 
		return QPainter_clipPath(pObject)

	Func clipRegion 
		return QPainter_clipRegion(pObject)

	Func combinedTransform 
		return QPainter_combinedTransform(pObject)

	Func compositionMode 
		return QPainter_compositionMode(pObject)

	Func device 
		return QPainter_device(pObject)

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

	Func drawImage P1,P2,P3,P4,P5,P6,P7,P8
		return QPainter_drawImage(pObject,P1,P2,GetObjectPointerFromRingObject(P3),P4,P5,P6,P7,P8)

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

	Func drawPixmap P1,P2,P3,P4,P5,P6,P7,P8,P9
		return QPainter_drawPixmap(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5),P6,P7,P8,P9)

	Func drawPoint P1,P2
		return QPainter_drawPoint(pObject,P1,P2)

	Func drawPoints P1,P2
		return QPainter_drawPoints(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawPolygon P1,P2,P3
		return QPainter_drawPolygon(pObject,GetObjectPointerFromRingObject(P1),P2,P3)

	Func drawPolyline P1,P2
		return QPainter_drawPolyline(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawRect P1,P2,P3,P4
		return QPainter_drawRect(pObject,P1,P2,P3,P4)

	Func drawRects P1,P2
		return QPainter_drawRects(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func drawRoundedRect P1,P2,P3,P4,P5,P6,P7
		return QPainter_drawRoundedRect(pObject,P1,P2,P3,P4,GetObjectPointerFromRingObject(P5),GetObjectPointerFromRingObject(P6),P7)

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
		return QPainter_fillRect(pObject,P1,P2,P3,P4,P5)

	Func font 
		pTempObj = new QFont
		pTempObj.pObject = QPainter_font(pObject)
		return pTempObj

	Func fontInfo 
		return QPainter_fontInfo(pObject)

	Func fontMetrics 
		return QPainter_fontMetrics(pObject)

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
		return QPainter_rotate(pObject,GetObjectPointerFromRingObject(P1))

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
		return QPainter_setOpacity(pObject,GetObjectPointerFromRingObject(P1))

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

Class QPicture

	pObject

	Func init 
		pObject = QPicture_new()
		return self

	Func delete
		pObject = QPicture_delete(pObject)

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

	Func color 
		pTempObj = new QColor
		pTempObj.pObject = QBrush_color(pObject)
		return pTempObj

	Func gradient 
		return QBrush_gradient(pObject)

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
		return QBrush_textureImage(pObject)

	Func transform 
		return QBrush_transform(pObject)

Class QByteArray

	pObject

	Func init 
		pObject = QByteArray_new()
		return self

	Func delete
		pObject = QByteArray_delete(pObject)

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

Class QIODevice

	pObject

	Func init 
		pObject = QIODevice_new()
		return self

	Func delete
		pObject = QIODevice_delete(pObject)

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

	Func setaboutToCloseEvent P1
		return QIODevice_setaboutToCloseEvent(pObject,P1)

	Func setbytesWrittenEvent P1
		return QIODevice_setbytesWrittenEvent(pObject,P1)

	Func setreadChannelFinishedEvent P1
		return QIODevice_setreadChannelFinishedEvent(pObject,P1)

	Func setreadyReadEvent P1
		return QIODevice_setreadyReadEvent(pObject,P1)

Class QAbstractSocket from QIODevice

	pObject

	Func init 
		pObject = QAbstractSocket_new()
		return self

	Func delete
		pObject = QAbstractSocket_delete(pObject)

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

Class QNetworkProxy

	pObject

	Func init 
		pObject = QNetworkProxy_new()
		return self

	Func delete
		pObject = QNetworkProxy_delete(pObject)

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

Class QTcpServer

	pObject

	Func init P1
		pObject = QTcpServer_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTcpServer_delete(pObject)

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

Class QHostAddress

	pObject

	Func init 
		pObject = QHostAddress_new()
		return self

	Func delete
		pObject = QHostAddress_delete(pObject)

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

	Func lookupHost P1,P2,P3
		return QHostInfo_lookupHost(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

Class QFileInfo

	pObject

	Func init 
		pObject = QFileInfo_new()
		return self

	Func delete
		pObject = QFileInfo_delete(pObject)

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
		return QFileInfo_created(pObject)

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
		return QFileInfo_lastModified(pObject)

	Func lastRead 
		return QFileInfo_lastRead(pObject)

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
		return QTextCursor_blockCharFormat(pObject)

	Func blockFormat 
		return QTextCursor_blockFormat(pObject)

	Func blockNumber 
		return QTextCursor_blockNumber(pObject)

	Func charFormat 
		return QTextCursor_charFormat(pObject)

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

	Func accept 
		return QAllEvents_accept(pObject)

	Func ignore 
		return QAllEvents_ignore(pObject)

	Func getKeyCode 
		return QAllEvents_getKeyCode(pObject)

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

Class QDesktopWidget from QWidget

	pObject

	Func init 
		pObject = QDesktopWidget_new()
		return self

	Func delete
		pObject = QDesktopWidget_delete(pObject)

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

	Func adjust P1,P2,P3,P4
		return QRect_adjust(pObject,P1,P2,P3,P4)

	Func adjusted P1,P2,P3,P4
		pTempObj = new QRect
		pTempObj.pObject = QRect_adjusted(pObject,P1,P2,P3,P4)
		return pTempObj

	Func bottom 
		return QRect_bottom(pObject)

	Func bottomLeft 
		return QRect_bottomLeft(pObject)

	Func bottomRight 
		return QRect_bottomRight(pObject)

	Func center 
		return QRect_center(pObject)

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
		return QRect_topLeft(pObject)

	Func topRight 
		return QRect_topRight(pObject)

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

	Func blockFormat 
		return QTextBlock_blockFormat(pObject)

	Func blockFormatIndex 
		return QTextBlock_blockFormatIndex(pObject)

	Func blockNumber 
		return QTextBlock_blockNumber(pObject)

	Func charFormat 
		return QTextBlock_charFormat(pObject)

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
		return QTextCodec_setCodecForLocale(P1)

Class QSqlDatabase

	pObject

	Func init 
		pObject = QSqlDatabase_new()
		return self

	Func delete
		pObject = QSqlDatabase_delete(pObject)

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

	Func dbmsType 
		return QSqlDriver_dbmsType(pObject)

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
		return QVariant_toDateTime(pObject)

	Func toDouble P1
		return QVariant_toDouble(pObject,GetObjectPointerFromRingObject(P1))

	Func toEasingCurve 
		return QVariant_toEasingCurve(pObject)

	Func toFloat P1
		return QVariant_toFloat(pObject,GetObjectPointerFromRingObject(P1))

	Func toInt P1
		return QVariant_toInt(pObject,GetObjectPointerFromRingObject(P1))

	Func toJsonArray 
		return QVariant_toJsonArray(pObject)

	Func toJsonDocument 
		return QVariant_toJsonDocument(pObject)

	Func toJsonObject 
		return QVariant_toJsonObject(pObject)

	Func toJsonValue 
		return QVariant_toJsonValue(pObject)

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

	Func toPersistentModelIndex 
		return QVariant_toPersistentModelIndex(pObject)

	Func toPoint 
		return QVariant_toPoint(pObject)

	Func toPointF 
		return QVariant_toPointF(pObject)

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
		return QVariant_toRegularExpression(pObject)

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
		return QVariant_toUuid(pObject)

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

	Func setfinishedEvent P1
		return QNetworkAccessManager_setfinishedEvent(pObject,P1)

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

	Func get P1
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

	Func put P1,P2
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

Class QNetworkReply from QIODevice

	pObject

	Func init 
		pObject = QNetworkReply_new()
		return self

	Func delete
		pObject = QNetworkReply_delete(pObject)

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

Class QIcon

	pObject

	Func init P1
		pObject = QIcon_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QIcon_delete(pObject)

Class QSize

	pObject

	Func init P1,P2
		pObject = QSize_new(P1,P2)
		return self

	Func delete
		pObject = QSize_delete(pObject)

Class QDateEdit from QDateTimeEdit

	pObject

	Func init P1
		pObject = QDateEdit_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QDateEdit_delete(pObject)

Class QHeaderView from QAbstractItemView

	pObject

	Func init P1,P2
		pObject = QHeaderView_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QHeaderView_delete(pObject)

Class QKeySequence

	pObject

	Func init P1
		pObject = QKeySequence_new(P1)
		return self

	Func delete
		pObject = QKeySequence_delete(pObject)


load "codegenlib.ring"

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

	Func setProperty_2 P1,P2
		return QObject_setProperty_2(pObject,P1,P2)

	Func setProperty_3 P1,P2
		return QObject_setProperty_3(pObject,P1,P2)

	Func setProperty_4 P1,P2
		return QObject_setProperty_4(pObject,P1,P2)

	Func setProperty_5 P1,P2
		return QObject_setProperty_5(pObject,P1,P2)

	Func setProperty_int P1,P2
		return QObject_setProperty_int(pObject,P1,P2)

	Func setProperty_float P1,P2
		return QObject_setProperty_float(pObject,P1,P2)

	Func setProperty_double P1,P2
		return QObject_setProperty_double(pObject,P1,P2)

	Func setProperty_string P1,P2
		return QObject_setProperty_string(pObject,P1,P2)

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
		pTempObj = new QChar
		pTempObj.pObject = QDir_separator(pObject)
		return pTempObj

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

	Func userInfo P1
		return QUrl_userInfo(pObject,P1)

	Func userName P1
		return QUrl_userName(pObject,P1)

	Func fromLocalFile P1
		pTempObj = new QUrl
		pTempObj.pObject = QUrl_fromLocalFile(pObject,P1)
		return pTempObj

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

	Func append_2 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_append_2(pObject,P1,P2)
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
		pTempObj.pObject = QByteArray_fill(pObject,P1,P2)
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
		pTempObj.pObject = QByteArray_leftJustified(pObject,P1,P2,P3)
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

	Func replace_2 P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_2(pObject,P1,P2,GetObjectPointerFromRingObject(P3))
		return pTempObj

	Func replace_3 P1,P2,P3
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_3(pObject,P1,P2,P3)
		return pTempObj

	Func replace_4 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_4(pObject,P1,P2)
		return pTempObj

	Func replace_5 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_5(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_6 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_6(pObject,P1,P2)
		return pTempObj

	Func replace_7 P1,P2,P3,P4
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_7(pObject,P1,P2,P3,P4)
		return pTempObj

	Func replace_8 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_8(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_9 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_9(pObject,GetObjectPointerFromRingObject(P1),P2)
		return pTempObj

	Func replace_10 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_10(pObject,P1,GetObjectPointerFromRingObject(P2))
		return pTempObj

	Func replace_11 P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_replace_11(pObject,P1,P2)
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
		pTempObj.pObject = QByteArray_rightJustified(pObject,P1,P2,P3)
		return pTempObj

	Func setNum P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setNum(pObject,P1,P2)
		return pTempObj

	Func setRawData P1,P2
		pTempObj = new QByteArray
		pTempObj.pObject = QByteArray_setRawData(pObject,P1,P2)
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
		pTempObj.pObject = QByteArray_toPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),P3)
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
		pTempObj.pObject = QByteArray_fromPercentEncoding(pObject,GetObjectPointerFromRingObject(P1),P2)
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
		return QIODevice_putChar(pObject,P1)

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
		return QIODevice_ungetChar(pObject,P1)

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

	Func takeAt P1
		return QStringList_takeAt(pObject,P1)

	Func takeFirst 
		return QStringList_takeFirst(pObject)

	Func takeLast 
		return QStringList_takeLast(pObject)

	Func value P1
		return QStringList_value(pObject,P1)

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

	Func second 
		return QTime_second(pObject)

	Func secsTo P1
		return QTime_secsTo(pObject,GetObjectPointerFromRingObject(P1))

	Func setHMS P1,P2,P3,P4
		return QTime_setHMS(pObject,P1,P2,P3,P4)

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

Class QTextCodec

	pObject


	Func codecForName P1
		return QTextCodec_codecForName(P1)

	Func setCodecForLocale P1
		return QTextCodec_setCodecForLocale(GetObjectPointerFromRingObject(P1))

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
		pTempObj = new QChar
		pTempObj.pObject = QVariant_toChar(pObject)
		return pTempObj

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
		pTempObj = new QLineF
		pTempObj.pObject = QVariant_toLineF(pObject)
		return pTempObj

	Func toLocale 
		pTempObj = new QLocale
		pTempObj.pObject = QVariant_toLocale(pObject)
		return pTempObj

	Func toLongLong P1
		return QVariant_toLongLong(pObject,GetObjectPointerFromRingObject(P1))

	Func toModelIndex 
		pTempObj = new QModelIndex
		pTempObj.pObject = QVariant_toModelIndex(pObject)
		return pTempObj

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
		pTempObj = new QRectF
		pTempObj.pObject = QVariant_toRectF(pObject)
		return pTempObj

	Func toRegExp 
		pTempObj = new QRegExp
		pTempObj.pObject = QVariant_toRegExp(pObject)
		return pTempObj

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

	Func setArray P1
		return QJsonDocument_setArray(pObject,GetObjectPointerFromRingObject(P1))

	Func setObject P1
		return QJsonDocument_setObject(pObject,GetObjectPointerFromRingObject(P1))

	Func toJson P1
		pTempObj = new QByteArray
		pTempObj.pObject = QJsonDocument_toJson(pObject,P1)
		return pTempObj

	Func toVariant 
		pTempObj = new QVariant
		pTempObj.pObject = QJsonDocument_toVariant(pObject)
		return pTempObj

	Func fromJson P1,P2
		pTempObj = new QJsonDocument
		pTempObj.pObject = QJsonDocument_fromJson(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))
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

Class QString2

	pObject

	Func init 
		pObject = QString2_new()
		return self

	Func delete
		pObject = QString2_delete(pObject)

	Func ObjectPointer
		return pObject

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

	Func append P1
		return QString2_append(pObject,P1)

	Func append_2 P1
		return QString2_append_2(pObject,GetObjectPointerFromRingObject(P1))

	Func toUtf8 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toUtf8(pObject)
		return pTempObj

	Func toLatin1 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toLatin1(pObject)
		return pTempObj

	Func toLocal8Bit 
		pTempObj = new QByteArray
		pTempObj.pObject = QString2_toLocal8Bit(pObject)
		return pTempObj

	Func unicode 
		pTempObj = new QChar
		pTempObj.pObject = QString2_unicode(pObject)
		return pTempObj

	Func number P1,P2
		return QString2_number(pObject,P1,P2)

	Func count 
		return QString2_count(pObject)

	Func left P1
		return QString2_left(pObject,P1)

	Func mid P1,P2
		return QString2_mid(pObject,P1,P2)

	Func right P1
		return QString2_right(pObject,P1)

	Func compare P1,P2
		return QString2_compare(pObject,P1,P2)

	Func contains P1,P2
		return QString2_contains(pObject,P1,P2)

	Func indexOf P1,P2,P3
		return QString2_indexOf(pObject,P1,P2,P3)

	Func lastIndexOf P1,P2,P3
		return QString2_lastIndexOf(pObject,P1,P2,P3)

	Func insert P1,P2
		return QString2_insert(pObject,P1,P2)

	Func isRightToLeft 
		return QString2_isRightToLeft(pObject)

	Func repeated P1
		return QString2_repeated(pObject,P1)

	Func replace P1,P2,P3
		return QString2_replace(pObject,P1,P2,P3)

	Func replace_2 P1,P2,P3
		return QString2_replace_2(pObject,P1,P2,P3)

	Func startsWith P1,P2
		return QString2_startsWith(pObject,P1,P2)

	Func endsWith P1,P2
		return QString2_endsWith(pObject,P1,P2)

	Func toHtmlEscaped 
		return QString2_toHtmlEscaped(pObject)

	Func clear 
		return QString2_clear(pObject)

	Func isNull 
		return QString2_isNull(pObject)

	Func resize P1
		return QString2_resize(pObject,P1)

	Func fill P1,P2
		return QString2_fill(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func localeAwareCompare P1
		return QString2_localeAwareCompare(pObject,P1)

	Func leftJustified P1,P2,P3
		return QString2_leftJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func rightJustified P1,P2,P3
		return QString2_rightJustified(pObject,P1,GetObjectPointerFromRingObject(P2),P3)

	Func section_1 P1,P2,P3,P4
		return QString2_section_1(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4))

	Func section_2 P1,P2,P3,P4
		return QString2_section_2(pObject,P1,P2,P3,GetObjectPointerFromRingObject(P4))

	Func section_3 P1,P2,P3,P4
		return QString2_section_3(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4))

	Func section_4 P1,P2,P3,P4
		return QString2_section_4(pObject,GetObjectPointerFromRingObject(P1),P2,P3,GetObjectPointerFromRingObject(P4))

	Func simplified 
		return QString2_simplified(pObject)

	Func toCaseFolded 
		return QString2_toCaseFolded(pObject)

	Func trimmed 
		return QString2_trimmed(pObject)

	Func truncate P1
		return QString2_truncate(pObject,P1)

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
		pTempObj = new QChar
		pTempObj.pObject = QStringRef_at(pObject,P1)
		return pTempObj

	Func clear 
		return QStringRef_clear(pObject)

	Func compare_2 P1,P2
		return QStringRef_compare_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func compare_3 P1,P2
		return QStringRef_compare_3(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func constData 
		pTempObj = new QChar
		pTempObj.pObject = QStringRef_constData(pObject)
		return pTempObj

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
		pTempObj = new QChar
		pTempObj.pObject = QStringRef_data(pObject)
		return pTempObj

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
		pTempObj = new QChar
		pTempObj.pObject = QStringRef_unicode(pObject)
		return pTempObj

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

Class QCoreApplication from QObject

	pObject


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

	Func open_3 P1
		return QFile_open_3(pObject,P1)

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

	pObject


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

	pObject


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

Class QMimeData from QObject

	pObject

	Func init 
		pObject = QMimeData_new()
		return self

	Func delete
		pObject = QMimeData_delete(pObject)

	Func ObjectPointer
		return pObject

	Func clear 
		return QMimeData_clear(pObject)

	Func colorData 
		pTempObj = new QVariant
		pTempObj.pObject = QMimeData_colorData(pObject)
		return pTempObj

	Func data P1
		pTempObj = new QByteArray
		pTempObj.pObject = QMimeData_data(pObject,P1)
		return pTempObj

	Func formats 
		pTempObj = new QStringList
		pTempObj.pObject = QMimeData_formats(pObject)
		return pTempObj

	Func hasColor 
		return QMimeData_hasColor(pObject)

	Func hasFormat P1
		return QMimeData_hasFormat(pObject,P1)

	Func hasHtml 
		return QMimeData_hasHtml(pObject)

	Func hasImage 
		return QMimeData_hasImage(pObject)

	Func hasText 
		return QMimeData_hasText(pObject)

	Func hasUrls 
		return QMimeData_hasUrls(pObject)

	Func html 
		return QMimeData_html(pObject)

	Func imageData 
		pTempObj = new QVariant
		pTempObj.pObject = QMimeData_imageData(pObject)
		return pTempObj

	Func removeFormat P1
		return QMimeData_removeFormat(pObject,P1)

	Func setColorData P1
		return QMimeData_setColorData(pObject,GetObjectPointerFromRingObject(P1))

	Func setData P1,P2
		return QMimeData_setData(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func setHtml P1
		return QMimeData_setHtml(pObject,P1)

	Func setImageData P1
		return QMimeData_setImageData(pObject,GetObjectPointerFromRingObject(P1))

	Func setText P1
		return QMimeData_setText(pObject,P1)

	Func setUrls P1
		return QMimeData_setUrls(pObject,GetObjectPointerFromRingObject(P1))

	Func text 
		return QMimeData_text(pObject)

	Func urls 
		return QMimeData_urls(pObject)

Class QChar

	pObject

	Func init P1
		pObject = QChar_new(P1)
		return self

	Func delete
		pObject = QChar_delete(pObject)

	Func ObjectPointer
		return pObject

	Func category 
		return QChar_category(pObject)

	Func cell 
		return QChar_cell(pObject)

	Func combiningClass 
		return QChar_combiningClass(pObject)

	Func decomposition 
		return QChar_decomposition(pObject)

	Func decompositionTag 
		return QChar_decompositionTag(pObject)

	Func digitValue 
		return QChar_digitValue(pObject)

	Func direction 
		return QChar_direction(pObject)

	Func hasMirrored 
		return QChar_hasMirrored(pObject)

	Func isDigit 
		return QChar_isDigit(pObject)

	Func isHighSurrogate 
		return QChar_isHighSurrogate(pObject)

	Func isLetter 
		return QChar_isLetter(pObject)

	Func isLetterOrNumber 
		return QChar_isLetterOrNumber(pObject)

	Func isLowSurrogate 
		return QChar_isLowSurrogate(pObject)

	Func isLower 
		return QChar_isLower(pObject)

	Func isMark 
		return QChar_isMark(pObject)

	Func isNonCharacter 
		return QChar_isNonCharacter(pObject)

	Func isNull 
		return QChar_isNull(pObject)

	Func isNumber 
		return QChar_isNumber(pObject)

	Func isPrint 
		return QChar_isPrint(pObject)

	Func isPunct 
		return QChar_isPunct(pObject)

	Func isSpace 
		return QChar_isSpace(pObject)

	Func isSurrogate 
		return QChar_isSurrogate(pObject)

	Func isSymbol 
		return QChar_isSymbol(pObject)

	Func isTitleCase 
		return QChar_isTitleCase(pObject)

	Func isUpper 
		return QChar_isUpper(pObject)

	Func mirroredChar 
		pTempObj = new QChar
		pTempObj.pObject = QChar_mirroredChar(pObject)
		return pTempObj

	Func row 
		return QChar_row(pObject)

	Func script 
		return QChar_script(pObject)

	Func toCaseFolded 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toCaseFolded(pObject)
		return pTempObj

	Func toLatin1 
		return QChar_toLatin1(pObject)

	Func toLower 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toLower(pObject)
		return pTempObj

	Func toTitleCase 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toTitleCase(pObject)
		return pTempObj

	Func toUpper 
		pTempObj = new QChar
		pTempObj.pObject = QChar_toUpper(pObject)
		return pTempObj

	Func unicode 
		return QChar_unicode(pObject)

	Func unicode_2 
		return QChar_unicode_2(pObject)

	Func unicodeVersion 
		return QChar_unicodeVersion(pObject)

	Func category_2 P1
		return QChar_category_2(pObject,P1)

	Func combiningClass_2 P1
		return QChar_combiningClass_2(pObject,P1)

	Func currentUnicodeVersion 
		return QChar_currentUnicodeVersion(pObject)

	Func decomposition_2 P1
		return QChar_decomposition_2(pObject,P1)

	Func decompositionTag_2 P1
		return QChar_decompositionTag_2(pObject,P1)

	Func digitValue_2 P1
		return QChar_digitValue_2(pObject,P1)

	Func direction_2 P1
		return QChar_direction_2(pObject,P1)

	Func fromLatin1 P1
		pTempObj = new QChar
		pTempObj.pObject = QChar_fromLatin1(pObject,P1)
		return pTempObj

	Func hasMirrored_2 P1
		return QChar_hasMirrored_2(pObject,P1)

	Func highSurrogate P1
		return QChar_highSurrogate(pObject,P1)

	Func isDigit_2 P1
		return QChar_isDigit_2(pObject,P1)

	Func isHighSurrogate_2 P1
		return QChar_isHighSurrogate_2(pObject,P1)

	Func isLetter_2 P1
		return QChar_isLetter_2(pObject,P1)

	Func isLetterOrNumber_2 P1
		return QChar_isLetterOrNumber_2(pObject,P1)

	Func isLowSurrogate_2 P1
		return QChar_isLowSurrogate_2(pObject,P1)

	Func isLower_2 P1
		return QChar_isLower_2(pObject,P1)

	Func isMark_2 P1
		return QChar_isMark_2(pObject,P1)

	Func isNonCharacter_2 P1
		return QChar_isNonCharacter_2(pObject,P1)

	Func isNumber_2 P1
		return QChar_isNumber_2(pObject,P1)

	Func isPrint_2 P1
		return QChar_isPrint_2(pObject,P1)

	Func isPunct_2 P1
		return QChar_isPunct_2(pObject,P1)

	Func isSpace_2 P1
		return QChar_isSpace_2(pObject,P1)

	Func isSurrogate_2 P1
		return QChar_isSurrogate_2(pObject,P1)

	Func isSymbol_2 P1
		return QChar_isSymbol_2(pObject,P1)

	Func isTitleCase_2 P1
		return QChar_isTitleCase_2(pObject,P1)

	Func isUpper_2 P1
		return QChar_isUpper_2(pObject,P1)

	Func lowSurrogate P1
		return QChar_lowSurrogate(pObject,P1)

	Func mirroredChar_2 P1
		return QChar_mirroredChar_2(pObject,P1)

	Func requiresSurrogates P1
		return QChar_requiresSurrogates(pObject,P1)

	Func script_2 P1
		return QChar_script_2(pObject,P1)

	Func surrogateToUcs4 P1,P2
		return QChar_surrogateToUcs4(pObject,P1,P2)

	Func surrogateToUcs4_2 P1,P2
		return QChar_surrogateToUcs4_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toCaseFolded_2 P1
		return QChar_toCaseFolded_2(pObject,P1)

	Func toLower_2 P1
		return QChar_toLower_2(pObject,P1)

	Func toTitleCase_2 P1
		return QChar_toTitleCase_2(pObject,P1)

	Func toUpper_2 P1
		return QChar_toUpper_2(pObject,P1)

	Func unicodeVersion_2 P1
		return QChar_unicodeVersion_2(pObject,P1)

Class QChildEvent from QEvent

	pObject

	Func init P1,P2
		pObject = QChildEvent_new(P1,GetObjectPointerFromRingObject(P2))
		return self

	Func delete
		pObject = QChildEvent_delete(pObject)

	Func ObjectPointer
		return pObject

	Func added 
		return QChildEvent_added(pObject)

	Func child 
		pTempObj = new QObject
		pTempObj.pObject = QChildEvent_child(pObject)
		return pTempObj

	Func polished 
		return QChildEvent_polished(pObject)

	Func removed 
		return QChildEvent_removed(pObject)

Class QTextStream

	pObject

	Func init 
		pObject = QTextStream_new()
		return self

	Func delete
		pObject = QTextStream_delete(pObject)

	Func ObjectPointer
		return pObject

	Func atEnd 
		return QTextStream_atEnd(pObject)

	Func autoDetectUnicode 
		return QTextStream_autoDetectUnicode(pObject)

	Func codec 
		return QTextStream_codec(pObject)

	Func device 
		pTempObj = new QIODevice
		pTempObj.pObject = QTextStream_device(pObject)
		return pTempObj

	Func fieldAlignment 
		return QTextStream_fieldAlignment(pObject)

	Func fieldWidth 
		return QTextStream_fieldWidth(pObject)

	Func flush 
		return QTextStream_flush(pObject)

	Func generateByteOrderMark 
		return QTextStream_generateByteOrderMark(pObject)

	Func integerBase 
		return QTextStream_integerBase(pObject)

	Func locale 
		pTempObj = new QLocale
		pTempObj.pObject = QTextStream_locale(pObject)
		return pTempObj

	Func numberFlags 
		return QTextStream_numberFlags(pObject)

	Func padChar 
		pTempObj = new QChar
		pTempObj.pObject = QTextStream_padChar(pObject)
		return pTempObj

	Func pos 
		return QTextStream_pos(pObject)

	Func read P1
		return QTextStream_read(pObject,P1)

	Func readAll 
		return QTextStream_readAll(pObject)

	Func readLine P1
		return QTextStream_readLine(pObject,P1)

	Func realNumberNotation 
		return QTextStream_realNumberNotation(pObject)

	Func realNumberPrecision 
		return QTextStream_realNumberPrecision(pObject)

	Func reset 
		return QTextStream_reset(pObject)

	Func resetStatus 
		return QTextStream_resetStatus(pObject)

	Func seek P1
		return QTextStream_seek(pObject,P1)

	Func setAutoDetectUnicode P1
		return QTextStream_setAutoDetectUnicode(pObject,P1)

	Func setCodec P1
		return QTextStream_setCodec(pObject,GetObjectPointerFromRingObject(P1))

	Func setCodec_2 P1
		return QTextStream_setCodec_2(pObject,P1)

	Func setDevice P1
		return QTextStream_setDevice(pObject,GetObjectPointerFromRingObject(P1))

	Func setFieldAlignment P1
		return QTextStream_setFieldAlignment(pObject,P1)

	Func setFieldWidth P1
		return QTextStream_setFieldWidth(pObject,P1)

	Func setGenerateByteOrderMark P1
		return QTextStream_setGenerateByteOrderMark(pObject,P1)

	Func setIntegerBase P1
		return QTextStream_setIntegerBase(pObject,P1)

	Func setLocale P1
		return QTextStream_setLocale(pObject,GetObjectPointerFromRingObject(P1))

	Func setNumberFlags P1
		return QTextStream_setNumberFlags(pObject,P1)

	Func setPadChar P1
		return QTextStream_setPadChar(pObject,GetObjectPointerFromRingObject(P1))

	Func setRealNumberNotation P1
		return QTextStream_setRealNumberNotation(pObject,P1)

	Func setRealNumberPrecision P1
		return QTextStream_setRealNumberPrecision(pObject,P1)

	Func setStatus P1
		return QTextStream_setStatus(pObject,P1)

	Func setString P1,P2
		return QTextStream_setString(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func skipWhiteSpace 
		return QTextStream_skipWhiteSpace(pObject)

	Func status 
		return QTextStream_status(pObject)

	Func string 
		return QTextStream_string(pObject)

Class QLocale

	pObject

	Func init P1
		pObject = QLocale_new(P1)
		return self

	Func delete
		pObject = QLocale_delete(pObject)

	Func ObjectPointer
		return pObject

	Func amText 
		return QLocale_amText(pObject)

	Func bcp47Name 
		return QLocale_bcp47Name(pObject)

	Func country 
		return QLocale_country(pObject)

	Func createSeparatedList P1
		return QLocale_createSeparatedList(pObject,GetObjectPointerFromRingObject(P1))

	Func currencySymbol P1
		return QLocale_currencySymbol(pObject,P1)

	Func dateFormat P1
		return QLocale_dateFormat(pObject,P1)

	Func dateTimeFormat P1
		return QLocale_dateTimeFormat(pObject,P1)

	Func dayName P1,P2
		return QLocale_dayName(pObject,P1,P2)

	Func decimalPoint 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_decimalPoint(pObject)
		return pTempObj

	Func exponential 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_exponential(pObject)
		return pTempObj

	Func firstDayOfWeek 
		return QLocale_firstDayOfWeek(pObject)

	Func groupSeparator 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_groupSeparator(pObject)
		return pTempObj

	Func language 
		return QLocale_language(pObject)

	Func measurementSystem 
		return QLocale_measurementSystem(pObject)

	Func monthName P1,P2
		return QLocale_monthName(pObject,P1,P2)

	Func name 
		return QLocale_name(pObject)

	Func nativeCountryName 
		return QLocale_nativeCountryName(pObject)

	Func nativeLanguageName 
		return QLocale_nativeLanguageName(pObject)

	Func negativeSign 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_negativeSign(pObject)
		return pTempObj

	Func numberOptions 
		return QLocale_numberOptions(pObject)

	Func percent 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_percent(pObject)
		return pTempObj

	Func pmText 
		return QLocale_pmText(pObject)

	Func positiveSign 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_positiveSign(pObject)
		return pTempObj

	Func quoteString P1,P2
		return QLocale_quoteString(pObject,P1,P2)

	Func quoteString_2 P1,P2
		return QLocale_quoteString_2(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func script 
		return QLocale_script(pObject)

	Func setNumberOptions P1
		return QLocale_setNumberOptions(pObject,P1)

	Func standaloneDayName P1,P2
		return QLocale_standaloneDayName(pObject,P1,P2)

	Func standaloneMonthName P1,P2
		return QLocale_standaloneMonthName(pObject,P1,P2)

	Func textDirection 
		return QLocale_textDirection(pObject)

	Func timeFormat P1
		return QLocale_timeFormat(pObject,P1)

	Func toDouble P1,P2
		return QLocale_toDouble(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toDouble_2 P1,P2
		return QLocale_toDouble_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toFloat P1,P2
		return QLocale_toFloat(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toFloat_2 P1,P2
		return QLocale_toFloat_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toInt P1,P2
		return QLocale_toInt(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toInt_2 P1,P2
		return QLocale_toInt_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toLongLong P1,P2
		return QLocale_toLongLong(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toLongLong_2 P1,P2
		return QLocale_toLongLong_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toLower P1
		return QLocale_toLower(pObject,P1)

	Func toShort P1,P2
		return QLocale_toShort(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toShort_2 P1,P2
		return QLocale_toShort_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toString P1
		return QLocale_toString(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_2 P1
		return QLocale_toString_2(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_4 P1
		return QLocale_toString_4(pObject,GetObjectPointerFromRingObject(P1))

	Func toString_5 P1
		return QLocale_toString_5(pObject,P1)

	Func toString_6 P1
		return QLocale_toString_6(pObject,P1)

	Func toString_7 P1
		return QLocale_toString_7(pObject,P1)

	Func toString_8 P1,P2,P3
		return QLocale_toString_8(pObject,P1,P2,P3)

	Func toString_9 P1,P2,P3
		return QLocale_toString_9(pObject,P1,P2,P3)

	Func toString_10 P1,P2
		return QLocale_toString_10(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_11 P1,P2
		return QLocale_toString_11(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_12 P1,P2
		return QLocale_toString_12(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_13 P1,P2
		return QLocale_toString_13(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_14 P1,P2
		return QLocale_toString_14(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toString_15 P1,P2
		return QLocale_toString_15(pObject,GetObjectPointerFromRingObject(P1),P2)

	Func toTime P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QLocale_toTime(pObject,P1,P2)
		return pTempObj

	Func toTime_2 P1,P2
		pTempObj = new QTime
		pTempObj.pObject = QLocale_toTime_2(pObject,P1,P2)
		return pTempObj

	Func toUInt P1,P2
		return QLocale_toUInt(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toUInt_2 P1,P2
		return QLocale_toUInt_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toULongLong P1,P2
		return QLocale_toULongLong(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toULongLong_2 P1,P2
		return QLocale_toULongLong_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toUShort P1,P2
		return QLocale_toUShort(pObject,P1,GetObjectPointerFromRingObject(P2))

	Func toUShort_2 P1,P2
		return QLocale_toUShort_2(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toUpper P1
		return QLocale_toUpper(pObject,P1)

	Func uiLanguages 
		pTempObj = new QStringList
		pTempObj.pObject = QLocale_uiLanguages(pObject)
		return pTempObj

	Func weekdays 
		return QLocale_weekdays(pObject)

	Func zeroDigit 
		pTempObj = new QChar
		pTempObj.pObject = QLocale_zeroDigit(pObject)
		return pTempObj

	Func c 
		pTempObj = new QLocale
		pTempObj.pObject = QLocale_c(pObject)
		return pTempObj

	Func countryToString P1
		return QLocale_countryToString(pObject,P1)

	Func languageToString P1
		return QLocale_languageToString(pObject,P1)

	Func matchingLocales P1,P2,P3
		return QLocale_matchingLocales(pObject,P1,P2,P3)

	Func scriptToString P1
		return QLocale_scriptToString(pObject,P1)

	Func setDefault P1
		return QLocale_setDefault(pObject,GetObjectPointerFromRingObject(P1))

	Func system 
		pTempObj = new QLocale
		pTempObj.pObject = QLocale_system(pObject)
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
		return QThread_setStackSize(pObject,P1)

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

Class QRectF

	pObject

	Func init P1,P2,P3,P4
		pObject = QRectF_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QRectF_delete(pObject)

	Func ObjectPointer
		return pObject

	Func adjust P1,P2,P3,P4
		return QRectF_adjust(pObject,P1,P2,P3,P4)

	Func adjusted P1,P2,P3,P4
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_adjusted(pObject,P1,P2,P3,P4)
		return pTempObj

	Func bottom 
		return QRectF_bottom(pObject)

	Func bottomLeft 
		pTempObj = new QPointF
		pTempObj.pObject = QRectF_bottomLeft(pObject)
		return pTempObj

	Func bottomRight 
		pTempObj = new QPointF
		pTempObj.pObject = QRectF_bottomRight(pObject)
		return pTempObj

	Func center 
		pTempObj = new QPointF
		pTempObj.pObject = QRectF_center(pObject)
		return pTempObj

	Func contains P1
		return QRectF_contains(pObject,GetObjectPointerFromRingObject(P1))

	Func contains_2 P1
		return QRectF_contains_2(pObject,GetObjectPointerFromRingObject(P1))

	Func contains_3 P1,P2
		return QRectF_contains_3(pObject,P1,P2)

	Func getCoords P1,P2,P3,P4
		return QRectF_getCoords(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func getRect P1,P2,P3,P4
		return QRectF_getRect(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2),GetObjectPointerFromRingObject(P3),GetObjectPointerFromRingObject(P4))

	Func height 
		return QRectF_height(pObject)

	Func intersected P1
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_intersected(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func intersects P1
		return QRectF_intersects(pObject,GetObjectPointerFromRingObject(P1))

	Func isEmpty 
		return QRectF_isEmpty(pObject)

	Func isNull 
		return QRectF_isNull(pObject)

	Func isValid 
		return QRectF_isValid(pObject)

	Func left 
		return QRectF_left(pObject)

	Func marginsAdded P1
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_marginsAdded(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func marginsRemoved P1
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_marginsRemoved(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func moveBottom P1
		return QRectF_moveBottom(pObject,P1)

	Func moveBottomLeft P1
		return QRectF_moveBottomLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func moveBottomRight P1
		return QRectF_moveBottomRight(pObject,GetObjectPointerFromRingObject(P1))

	Func moveCenter P1
		return QRectF_moveCenter(pObject,GetObjectPointerFromRingObject(P1))

	Func moveLeft P1
		return QRectF_moveLeft(pObject,P1)

	Func moveRight P1
		return QRectF_moveRight(pObject,P1)

	Func moveTo P1,P2
		return QRectF_moveTo(pObject,P1,P2)

	Func moveTo_2 P1
		return QRectF_moveTo_2(pObject,GetObjectPointerFromRingObject(P1))

	Func moveTop P1
		return QRectF_moveTop(pObject,P1)

	Func moveTopLeft P1
		return QRectF_moveTopLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func moveTopRight P1
		return QRectF_moveTopRight(pObject,GetObjectPointerFromRingObject(P1))

	Func normalized 
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_normalized(pObject)
		return pTempObj

	Func right 
		return QRectF_right(pObject)

	Func setBottom P1
		return QRectF_setBottom(pObject,P1)

	Func setBottomLeft P1
		return QRectF_setBottomLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func setBottomRight P1
		return QRectF_setBottomRight(pObject,GetObjectPointerFromRingObject(P1))

	Func setCoords P1,P2,P3,P4
		return QRectF_setCoords(pObject,P1,P2,P3,P4)

	Func setHeight P1
		return QRectF_setHeight(pObject,P1)

	Func setLeft P1
		return QRectF_setLeft(pObject,P1)

	Func setRect P1,P2,P3,P4
		return QRectF_setRect(pObject,P1,P2,P3,P4)

	Func setRight P1
		return QRectF_setRight(pObject,P1)

	Func setSize P1
		return QRectF_setSize(pObject,GetObjectPointerFromRingObject(P1))

	Func setTop P1
		return QRectF_setTop(pObject,P1)

	Func setTopLeft P1
		return QRectF_setTopLeft(pObject,GetObjectPointerFromRingObject(P1))

	Func setTopRight P1
		return QRectF_setTopRight(pObject,GetObjectPointerFromRingObject(P1))

	Func setWidth P1
		return QRectF_setWidth(pObject,P1)

	Func setX P1
		return QRectF_setX(pObject,P1)

	Func setY P1
		return QRectF_setY(pObject,P1)

	Func size 
		return QRectF_size(pObject)

	Func toAlignedRect 
		pTempObj = new QRect
		pTempObj.pObject = QRectF_toAlignedRect(pObject)
		return pTempObj

	Func toRect 
		pTempObj = new QRect
		pTempObj.pObject = QRectF_toRect(pObject)
		return pTempObj

	Func top 
		return QRectF_top(pObject)

	Func topLeft 
		pTempObj = new QPointF
		pTempObj.pObject = QRectF_topLeft(pObject)
		return pTempObj

	Func topRight 
		pTempObj = new QPointF
		pTempObj.pObject = QRectF_topRight(pObject)
		return pTempObj

	Func translate P1,P2
		return QRectF_translate(pObject,P1,P2)

	Func translate_2 P1
		return QRectF_translate_2(pObject,GetObjectPointerFromRingObject(P1))

	Func translated P1,P2
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_translated(pObject,P1,P2)
		return pTempObj

	Func translated_2 P1
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_translated_2(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func transposed 
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_transposed(pObject)
		return pTempObj

	Func united P1
		pTempObj = new QRectF
		pTempObj.pObject = QRectF_united(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func width 
		return QRectF_width(pObject)

	Func x 
		return QRectF_x(pObject)

	Func y 
		return QRectF_y(pObject)

Class QLineF

	pObject

	Func init P1,P2,P3,P4
		pObject = QLineF_new(P1,P2,P3,P4)
		return self

	Func delete
		pObject = QLineF_delete(pObject)

	Func ObjectPointer
		return pObject

	Func p1 
		pTempObj = new QPointF
		pTempObj.pObject = QLineF_p1(pObject)
		return pTempObj

	Func p2 
		pTempObj = new QPointF
		pTempObj.pObject = QLineF_p2(pObject)
		return pTempObj

	Func x1 
		return QLineF_x1(pObject)

	Func x2 
		return QLineF_x2(pObject)

	Func y1 
		return QLineF_y1(pObject)

	Func y2 
		return QLineF_y2(pObject)

	Func angle 
		return QLineF_angle(pObject)

	Func angleTo P1
		return QLineF_angleTo(pObject,GetObjectPointerFromRingObject(P1))

	Func center 
		pTempObj = new QPointF
		pTempObj.pObject = QLineF_center(pObject)
		return pTempObj

	Func dx 
		return QLineF_dx(pObject)

	Func dy 
		return QLineF_dy(pObject)

	Func intersects P1,P2
		return QLineF_intersects(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func isNull 
		return QLineF_isNull(pObject)

	Func length 
		return QLineF_length(pObject)

	Func normalVector 
		pTempObj = new QLineF
		pTempObj.pObject = QLineF_normalVector(pObject)
		return pTempObj

	Func pointAt P1
		pTempObj = new QPointF
		pTempObj.pObject = QLineF_pointAt(pObject,P1)
		return pTempObj

	Func setP1 P1
		return QLineF_setP1(pObject,GetObjectPointerFromRingObject(P1))

	Func setP2 P1
		return QLineF_setP2(pObject,GetObjectPointerFromRingObject(P1))

	Func setAngle P1
		return QLineF_setAngle(pObject,P1)

	Func setLength P1
		return QLineF_setLength(pObject,P1)

	Func setLine P1,P2,P3,P4
		return QLineF_setLine(pObject,P1,P2,P3,P4)

	Func setPoints P1,P2
		return QLineF_setPoints(pObject,GetObjectPointerFromRingObject(P1),GetObjectPointerFromRingObject(P2))

	Func toLine 
		return QLineF_toLine(pObject)

	Func translate P1
		return QLineF_translate(pObject,GetObjectPointerFromRingObject(P1))

	Func translate_2 P1,P2
		return QLineF_translate_2(pObject,P1,P2)

	Func translated P1
		pTempObj = new QLineF
		pTempObj.pObject = QLineF_translated(pObject,GetObjectPointerFromRingObject(P1))
		return pTempObj

	Func translated_2 P1,P2
		pTempObj = new QLineF
		pTempObj.pObject = QLineF_translated_2(pObject,P1,P2)
		return pTempObj

Class QRegExp

	pObject

	Func init 
		pObject = QRegExp_new()
		return self

	Func delete
		pObject = QRegExp_delete(pObject)

	Func ObjectPointer
		return pObject

	Func cap P1
		return QRegExp_cap(pObject,P1)

	Func captureCount 
		return QRegExp_captureCount(pObject)

	Func capturedTexts 
		pTempObj = new QStringList
		pTempObj.pObject = QRegExp_capturedTexts(pObject)
		return pTempObj

	Func caseSensitivity 
		return QRegExp_caseSensitivity(pObject)

	Func errorString 
		return QRegExp_errorString(pObject)

	Func exactMatch P1
		return QRegExp_exactMatch(pObject,P1)

	Func indexIn P1,P2,P3
		return QRegExp_indexIn(pObject,P1,P2,P3)

	Func isEmpty 
		return QRegExp_isEmpty(pObject)

	Func isMinimal 
		return QRegExp_isMinimal(pObject)

	Func isValid 
		return QRegExp_isValid(pObject)

	Func lastIndexIn P1,P2,P3
		return QRegExp_lastIndexIn(pObject,P1,P2,P3)

	Func matchedLength 
		return QRegExp_matchedLength(pObject)

	Func pattern 
		return QRegExp_pattern(pObject)

	Func patternSyntax 
		return QRegExp_patternSyntax(pObject)

	Func pos P1
		return QRegExp_pos(pObject,P1)

	Func setCaseSensitivity P1
		return QRegExp_setCaseSensitivity(pObject,P1)

	Func setMinimal P1
		return QRegExp_setMinimal(pObject,P1)

	Func setPattern P1
		return QRegExp_setPattern(pObject,P1)

	Func setPatternSyntax P1
		return QRegExp_setPatternSyntax(pObject,P1)

	Func swap P1
		return QRegExp_swap(pObject,GetObjectPointerFromRingObject(P1))

Class QModelIndex

	pObject

	Func init 
		pObject = QModelIndex_new()
		return self

	Func delete
		pObject = QModelIndex_delete(pObject)

	Func ObjectPointer
		return pObject

	Func column 
		return QModelIndex_column(pObject)

	Func data P1
		pTempObj = new QVariant
		pTempObj.pObject = QModelIndex_data(pObject,P1)
		return pTempObj

	Func flags 
		return QModelIndex_flags(pObject)

	Func internalId 
		return QModelIndex_internalId(pObject)

	Func internalPointer 
		return QModelIndex_internalPointer(pObject)

	Func isValid 
		return QModelIndex_isValid(pObject)

	Func model 
		return QModelIndex_model(pObject)

	Func parent 
		pTempObj = new QModelIndex
		pTempObj.pObject = QModelIndex_parent(pObject)
		return pTempObj

	Func row 
		return QModelIndex_row(pObject)

	Func sibling P1,P2
		pTempObj = new QModelIndex
		pTempObj.pObject = QModelIndex_sibling(pObject,P1,P2)
		return pTempObj

	Func siblingAtColumn P1
		pTempObj = new QModelIndex
		pTempObj.pObject = QModelIndex_siblingAtColumn(pObject,P1)
		return pTempObj

	Func siblingAtRow P1
		pTempObj = new QModelIndex
		pTempObj.pObject = QModelIndex_siblingAtRow(pObject,P1)
		return pTempObj

Class QVersionNumber

	pObject

	Func init 
		pObject = QVersionNumber_new()
		return self

	Func delete
		pObject = QVersionNumber_delete(pObject)

	Func ObjectPointer
		return pObject

	Func isNormalized 
		return QVersionNumber_isNormalized(pObject)

	Func isNull 
		return QVersionNumber_isNull(pObject)

	Func isPrefixOf P1
		return QVersionNumber_isPrefixOf(pObject,GetObjectPointerFromRingObject(P1))

	Func majorVersion 
		return QVersionNumber_majorVersion(pObject)

	Func microVersion 
		return QVersionNumber_microVersion(pObject)

	Func minorVersion 
		return QVersionNumber_minorVersion(pObject)

	Func normalized 
		pTempObj = new QVersionNumber
		pTempObj.pObject = QVersionNumber_normalized(pObject)
		return pTempObj

	Func segmentAt P1
		return QVersionNumber_segmentAt(pObject,P1)

	Func segmentCount 
		return QVersionNumber_segmentCount(pObject)

	Func segments 
		return QVersionNumber_segments(pObject)

	Func toString 
		return QVersionNumber_toString(pObject)

Class QLibraryInfo

	pObject


	Func isDebugBuild 
		return QLibraryInfo_isDebugBuild()

	Func version 
		pTempObj = new QVersionNumber
		pTempObj.pObject = QLibraryInfo_version()
		return pTempObj

Class QSize

	pObject

	Func init P1,P2
		pObject = QSize_new(P1,P2)
		return self

	Func delete
		pObject = QSize_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant2 from QVariant

	pObject

	Func init P1
		pObject = QVariant2_new(P1)
		return self

	Func delete
		pObject = QVariant2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant3 from QVariant

	pObject

	Func init P1
		pObject = QVariant3_new(P1)
		return self

	Func delete
		pObject = QVariant3_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant4 from QVariant

	pObject

	Func init P1
		pObject = QVariant4_new(P1)
		return self

	Func delete
		pObject = QVariant4_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariant5 from QVariant

	pObject

	Func init P1
		pObject = QVariant5_new(P1)
		return self

	Func delete
		pObject = QVariant5_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantInt from QVariant

	pObject

	Func init P1
		pObject = QVariantInt_new(P1)
		return self

	Func delete
		pObject = QVariantInt_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantFloat from QVariant

	pObject

	Func init P1
		pObject = QVariantFloat_new(P1)
		return self

	Func delete
		pObject = QVariantFloat_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantDouble from QVariant

	pObject

	Func init P1
		pObject = QVariantDouble_new(P1)
		return self

	Func delete
		pObject = QVariantDouble_delete(pObject)

	Func ObjectPointer
		return pObject

Class QVariantString from QVariant

	pObject

	Func init P1
		pObject = QVariantString_new(P1)
		return self

	Func delete
		pObject = QVariantString_delete(pObject)

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

Class QFile2 from QFile

	pObject

	Func init P1
		pObject = QFile2_new(P1)
		return self

	Func delete
		pObject = QFile2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QTextStream2 from QTextStream

	pObject

	Func init P1
		pObject = QTextStream2_new(GetObjectPointerFromRingObject(P1))
		return self

	Func delete
		pObject = QTextStream2_delete(pObject)

	Func ObjectPointer
		return pObject

Class QTextStream3 from QTextStream

	pObject

	Func init P1,P2
		pObject = QTextStream3_new(GetObjectPointerFromRingObject(P1),P2)
		return self

	Func delete
		pObject = QTextStream3_delete(pObject)

	Func ObjectPointer
		return pObject

Class QTextStream4 from QTextStream

	pObject

	Func init P1,P2
		pObject = QTextStream4_new(GetObjectPointerFromRingObject(P1),P2)
		return self

	Func delete
		pObject = QTextStream4_delete(pObject)

	Func ObjectPointer
		return pObject

Class QTextStream5 from QTextStream

	pObject

	Func init P1,P2
		pObject = QTextStream5_new(GetObjectPointerFromRingObject(P1),P2)
		return self

	Func delete
		pObject = QTextStream5_delete(pObject)

	Func ObjectPointer
		return pObject

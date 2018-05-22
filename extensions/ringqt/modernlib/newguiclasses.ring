GUILib = new GUILib

Class GUILib

	func objcmp o1,o2
		return ptrcmp(o1.pObject,o2.pObject)

	func findobj aList,o1,nColumn
		return find(aList,o1.pObject,nColumn)

/*
	This package 
	(1) Create new classes names (Better Names)
	(2) Index starts from 1 instead of 0 (More Natural)
*/

package System.GUI

	class App from qApp 

		func init 	# To allow using new App() 
			return self 

	class window from qWidget

	class mainwindow from qMainWindow

	class label from qLabel

	class PushButton from qPushButton

	class LineEdit from qLineEdit

	class TextEdit from qTextEdit

	class ListWidget from qListWidget

		func CurrentRow
			return Super.CurrentRow()+1

		func SetCurrentRow nIndex,nOptions
			return Super.SetCurrentRow(nIndex-1,nOptions)

		func item nIndex 
			return super.item(nIndex-1)

		func itemat nX,nY
			return super.itemAt(nX-1,nY-1)
	
		func row oItem
			return super.row(oItem)+1

		func TakeItem nIndex 
			return super.TakeItem(nIndex-1)		

	class checkbox from qCheckBox

	class slider from qSlider

	class progressbar from qProgressbar

	class SpinBox from qSpinBox

	class ComboBox from qComboBox

		func CurrentIndex
			return Super.CurrentIndex() + 1

		func SetCurrentIndex nIndex
			return Super.SetCurrentIndex(nIndex - 1)

		func FindData p1,p2,p3
			return Super.FindData(p1,p2,p3)+1

		func FindText p1,p2
			return Super.FindText(p1,p2)+1

		func InsertItem nIndex,p2,p3
			return Super.InsertItem(nIndex-1,p2,p3)	

		func ItemData nIndex,p2
			return Super.ItemData(nIndex-1,p2)

		func ItemIcon nIndex 
			return Super.ItemIcon(nIndex-1)

		func ItemText nIndex 
			return Super.ItemText(nIndex-1)

		func RemoveItem nIndex 
			return Super.RemoveItem(nIndex-1)

		func SetItemIcon nIndex,p2
			return Super.SetItemIcon(nIndex-1,p2)

		func SetItemText nIndex,p2
			return Super.SetItemText(nIndex-1,p2)

		func ModelColumn 
			return Super.ModelColumn()+1

		func SetModelColumn nIndex
			return Super.SetModelColumn(nIndex-1)		

	class DateTimeEdit from qDateTimeEdit

	class DateTime from qDateTime 

	class TableWidget from qTableWidget

		func column  p1
			return Super.column(p1) + 1

		func currentColumn 
			return Super.currentColumn() + 1

		func currentRow 
			return Super.currentRow() + 1

		func horizontalHeaderItem p1
			return Super.horizontalHeaderItem(p1-1)

		func item p1,p2
			return Super.Item(p1-1,p2-1)
	
		func itemat p1,p2
			return Super.ItemAt(p1-1,p2-1)

		func removeCellWidget p1,p2
			return Super.removeCellWidget(p1-1,p2-1)

		func row p1
			return Super.row(p1)+1

		func setCellWidget p1,p2,p3
			return Super.setCellWidget(p1-1,p2-1,p3)

		func setCurrentCell p1,p2
			return Super.setCurrentCell(p1-1,p2-1)

		func setColumnWidth P1,P2
			return Super.setColumnWidth(p1-1,p2)

		func setHorizontalHeaderItem p1,p2
			return Super.setHorizontalHeaderItem(p1-1,p2)

		func setItem p1,p2,p3
			return Super.setItem(p1-1,p2-1,p3)

		func setVerticalHeaderItem p1,p2
			return Super.setVerticalHeaderItem(p1-1,p2)

		func sortItems p1,p2
			return Super.sortItems(p1-1,p2)

		func takeHorizontalHeaderItem p1
			return Super.takeHorizontalHeaderItem(p1-1)

		func takeItem p1,p2
			return Super.takeItem(p1-1,p2-1)

		func takeVerticalHeaderItem p1
			return Super.takeVerticalHeaderItem(p1-1)

		func verticalHeaderItem p1
			return Super.verticalHeaderItem(p1-1)

		func visualColumn p1
			return Super.visualColumn(p1-1)

		func visualRow p1
			return Super.visualRow(p1-1)

		func insertColumn p1
			return Super.insertColumn(p1-1)

		func insertRow p1
			return Super.insertRow(p1-1)

		func removeColumn p1
			return Super.removeColumn(p1-1)

		func removeRow p1
			return Super.removeRow(p1-1)		

	class TableView from qTableView

	class TreeView from qTreeView		

	class TreeWidget from qTreeWidget

		func currentColumn 
			return Super.currentColumn() + 1

		func editItem p1,p2
			return Super.editItem(p1,p2-1)

		func indexOfTopLevelItem p1
			return Super.indexOfTopLevelItem(p1)+1

		func insertTopLevelItem p1,p2
			return Super.insertTopLevelItem(p1-1,p2)

		func itemAt p1,p2
			return Super.itemAt(p1-1,p2-1)

		func itemWidget p1,p2
			return Super.itemWidget(p1,p2-1)

		func openPersistentEditor p1,p2
			return Super.openPersistentEditor(p1,p2-1)
	
		func removeItemWidget p1,p2
			return Super.removeItemWidget(p1,p2-1)

		func setItemWidget p1,p2,p3
			return Super.setItemWidget(p1,p2-1,p3)

		func takeTopLevelItem p1
			return Super.takeTopLevelItem(p1-1)

		func topLevelItem p1
			return Super.topLevelItem(p1-1)		

	class RadioButton from qRadioButton

	class WebView from qWebView

	class Dial  from qDial

	class Frame from qFrame

	class Frame2 from qFrame2

	class Frame3 from qFrame3

	class LCDNumber from qLCDNumber

	class Timer from qTimer

	class vboxlayout from qVBoxLayout

	class hboxlayour from qHBoxLayout

	class TabWidget from qTabWidget

	class Statusbar from qStatusBar

	class ToolBar from qToolBar

	class MenuBar from qMenubar 

	class Menu from qMenu 

	class DockWidget from qDockWidget 

	class TableWidgetItem from qTableWidgetItem 

	class MediaPlayer from qMediaPlayer 

	class MediaPlaylist from qMediaPlaylist 

	class VideoWidget from qVideoWidget 

	class ButtonGroup from qButtonGroup 

	class AbstractButton from qAbstractButton 

	class Url  from qUrl  

	class AbstractSpinBox from qAbstractSpinBox 

	class AbstractSlider from qAbstractSlider 

	class AbstractItemView from qAbstractItemView 

	class AbstractScrollArea from qAbstractScrollArea 

	class Action from qAction 

	class Event from qEvent 

	class MessageBox from qMessageBox 

	class FileDialog from qFileDialog 

	class Painter from qPainter

	class Picture from qPicture 

	class Pen from qPen 

	class Color from qColor 

	class Printer from qPrinter 

	class Font from qFont 

	class Brush from qBrush 

	class ByteArray from qByteArray 

	class IODevice from qIODevice 

	class AbstractSocket from qAbstractSocket 

	class NetworkProxy from qNetworkProxy 

	class TcpSocket from qTcpSocket 

	class TcpServer from qTcpServer 

	class HostAddress from qHostAddress 

	class HostInfo from qHostInfo 

	class FileInfo from qFileInfo

	class DirModel from qDirModel 

	class FontDialog from qFontDialog

	class Dialog from qDialog 

	class TextCursor from qTextCursor

	class ColorDialog from qColorDialog 

	class StringList from qStringList 

	class KeySequence from qKeySequence 

	class InputDialog from qInputDialog

	class AllEvents from qAllEvents 

	class DesktopWidget from qDesktopWidget 

	class Rect from qRect 

	class TextDocument from qTextDocument 

	class TextBlock from qTextBlock 

	class Time from qTime 

	class ListWidgetItem from qListWidgetItem 

	class SystemTrayIcon from qSystemTrayIcon 

	class Date from qDate 

	class TextCodec from qTextCodec 

	class SqlDatabase from qSqlDatabase 

	class SqlDriver from qSqlDriver 

	class SqlQuery from qSqlQuery

	class SqlError from qSqlError 

	class SqlIndex from qSqlIndex

	class SqlRecord from qSqlRecord 

	class SqlField from qSqlField 

	class SqlDriverCreatorBase from qSqlDriverCreatorBase 

	class Variant from qVariant 

	class NetworkRequest from qNetworkRequest 

	class NetworkAccessManager from qNetworkAccessManager 

	class NetworkReply from qNetworkReply

	class PainterPath from qPainterPath 

	class Image from qImage 

	class XmlStreamReader from qXmlStreamReader 

	class XmlStreamWriter from qXmlStreamWriter 

	class XmlStreamNotationDeclaration from qXmlStreamNotationDeclaration 

	class XmlStreamNamespaceDeclaration from qXmlStreamNamespaceDeclaration 

	class XmlStreamEntityResolver from qXmlStreamEntityResolver 

	class XmlStreamEntityDeclaration from qXmlStreamEntityDeclaration 

	class XmlStreamAttributes from qXmlStreamAttributes 

	class XmlStreamAttribute from qXmlStreamAttribute 
	
	class Thread from qThread 

	class ThreadPool from qThreadPool

	class RegularExpression from qRegularExpression 

	class RegularExpressionMatch from qRegularExpressionMatch 

	class RegularExpressionMatchIterator from qRegularExpressionMatchIterator 

	class JsonArray from qJsonArray 

	class JsonDocument from qJsonDocument 

	class JsonObject from qJsonObject 

	class JsonParseError from qJsonParseError 

	class JsonValue from qJsonValue 

	class PlainTextEdit from qPlainTextEdit 

	class GridLayout from qGridLayout 

	class TextCharFormat from qTextCharFormat 

	class CameraViewfinder from qCameraViewfinder 

	class GraphicsVideoItem from qGraphicsVideoItem 

	class VideoWidgetControl from qVideoWidgetControl 

	class Camera from qCamera 

	class CameraImageCapture from qCameraImageCapture 

	class MediaObject from qMediaObject 

	class HeaderView from qHeaderView 

	class FontMetrics from qFontMetrics 

	class SplashScreen from qSplashScreen 

	class BoxLayout from qBoxLayout 

	class Layout from qLayout 

	class LinearGradient from qLinearGradient 

	class Gradient from qGradient  

	class FileSystemModel from qFileSystemModel 

	class Dir from qDir

	class Size from qSize 

	class Icon from qIcon 

	class Pixmap from qPixmap 

	class Bitmap from qBitmap 

	class Object from qObject 

	class Test from qTest 

	class SerialPort from qSerialPort

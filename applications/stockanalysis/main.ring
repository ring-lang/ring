# Author: Azzeddine Remmal

load "guilib.ring"
load "stdlib.ring"
load "backend.ring"
load "chart_widget.ring"

# Global Data Containers
aGlobalCurves = [[], []]
aGlobalTop7 = []
# Global Objects
win = null
oChartWidget = null
txtLog = null
comboInterval = null
comboRange = null
btnRun = null
btnExport = null
btnBrowse = null
txtTickerFile = null
App = null

# Constants for Styling
C_STYLE_DARK = "
    QWidget {
        background-color: #2b2b2b;
        color: #ffffff;
        font-family: 'Segoe UI', sans-serif;
        font-size: 14px;
    }
    QPushButton {
        background-color: #007acc;
        border: none;
        padding: 8px 16px;
        border-radius: 4px;
        color: white;
        font-weight: bold;
    }
    QPushButton:hover {
        background-color: #005999;
    }
    QPushButton:pressed {
        background-color: #004080;
    }
    QLineEdit, QComboBox {
        background-color: #3c3c3c;
        border: 1px solid #555;
        padding: 4px;
        border-radius: 3px;
        color: white;
    }
    QFrame {
        border: 1px solid #555;
        border-radius: 5px;
        margin-top: 10px;
        padding: 5px;
        background-color: #333;
    }
    QLabel {
        font-weight: bold;
        color: #cccccc;
    }
"

func main
    App = new QApp
        
	win = new QWidget() {
		setWinIcon(self,"appicon.png")
		setWindowTitle("Stock Analysis Pro - Ring Edition")
		resize(1000, 700)
		setStyleSheet(C_STYLE_DARK)

		# --- Layouts ---
		mainLayout = new QVBoxLayout()
		controlsLayout = new QHBoxLayout()
		contentLayout = new QHBoxLayout()

		# --- Controls Section ---
		groupControls = new QFrame( win,0) {
			setFrameShape(QFrame_StyledPanel)
			
			# Main layout for the frame (Vertical to hold Title + Controls)
			frameLayout = new QVBoxLayout() {
				
				# Title
				lblTitle = new QLabel( win) {
					setText("Configuration")
					setStyleSheet("color: #007acc; font-weight: bold;")
				}
				addWidget(lblTitle)

				# Controls Layout (Horizontal)
				controlsLayoutInner = new QHBoxLayout() {
					
					# Interval
					addWidget(new QLabel(win){setText("Interval:")})
					comboInterval = new QComboBox(win){
						alist = ["1mo", "1wk", "1d"]
						for x in aList additem(x,0) next
						}
					addWidget(comboInterval)

					# Range
					addWidget(new QLabel(win){setText("Range:")})
					comboRange = new QComboBox(win){
							alist = ["5y", "1y", "2y", "10y"]
						for x in aList additem(x,0) next
						}
					addWidget(comboRange)

					# Ticker File
					addWidget(new QLabel(win){setText("Ticker File:")})
					txtTickerFile = new QLineEdit(win){setText("quotes.ini")}
					addWidget(txtTickerFile)
					
					btnBrowse = new QPushButton(win){setText("Browse...")}
					btnBrowse.setClickEvent("browseFile(this)")
					addWidget(btnBrowse)

					# Run Button
					btnRun = new QPushButton(win){setText("Run Analysis")}
					btnRun.setStyleSheet("background-color: #28a745;")
					btnRun.setClickEvent("runAnalysis()")
					addWidget(btnRun)

					# Export Button
					btnExport = new QPushButton(win){setText("Export CSV")}
					btnExport.setStyleSheet("background-color: #d39e00;")
					btnExport.setClickEvent("exportCSV()")
					btnExport.setEnabled(false)
					addWidget(btnExport)
				}
				addLayout(controlsLayoutInner)
			}
			setLayout(frameLayout)
		}

		# --- Content Section ---
		
		# Left: Data/Log
		groupData = new QFrame(win,0) {
			setFrameShape(QFrame_StyledPanel)
			frameLayout = new QVBoxLayout() {
				lblTitle = new QLabel(win) {
					setText("Analysis Log")
					setStyleSheet("color: #007acc; font-weight: bold;")
				}
				addWidget(lblTitle)

				txtLog = new QTextEdit(win){setReadOnly(true)setText("Ready to start...")}
				addWidget(txtLog)
			}
			setLayout(frameLayout)
		}

		# Right: Chart Area
		groupChart = new QFrame(win, 0) {
			setFrameShape(QFrame_StyledPanel)
			frameLayout = new QVBoxLayout() {
				lblTitle = new QLabel(win) {
					setText("Performance Chart")
					setStyleSheet("color: #007acc; font-weight: bold;")
					setMaximumHeight(40)
				}
				addWidget(lblTitle)

				oChartWidget = new StockChart( win)
				addWidget(oChartWidget)
			}
			setLayout(frameLayout)
		}

		# Add widgets to layouts
		controlsLayout.addWidget(groupControls)
		
		contentLayout.addWidget(groupData)
		contentLayout.addWidget(groupChart)
		contentLayout.setStretch(0, 1) # Log takes 1 part
		contentLayout.setStretch(1, 2) # Chart takes 2 parts

		mainLayout.addLayout(controlsLayout)
		mainLayout.addLayout(contentLayout)

		setLayout(mainLayout)
		show()
	}

    App.exec()
    

func browseFile(win)
    new QFileDialog(win) {
        cFile = getOpenFileName(win, "Select Ticker File", ".", "INI Files (*.ini);;All Files (*.*)")
        if cFile != ""
            txtTickerFile.setText(cFile)
        ok
    }

func runAnalysis
    txtLog.setText("Starting analysis...")
    btnExport.setEnabled(false)
    
    cInterval = comboInterval.currentText()
    cRange = comboRange.currentText()
    cFile = txtTickerFile.text()
    
    if not fexists(cFile)
        txtLog.append("Error: File " + cFile + " not found.")
        return
    ok

    cContent = read(cFile)
    aLines = str2list(cContent)
    aStocks = []
    
    # Filter empty lines
    for line in aLines
        line = trim(line)
        if line != "" 
            aStocks + line 
        ok
    next

    txtLog.append("Loaded " + len(aStocks) + " stocks.")
    
    oFetcher = new StockFetcher
    oParser = new DataParser
    oStrategy = new StrategyEngine
    oSimulator = new PortfolioSimulator
    
    aResults = [] # List of [Symbol, Return, Series]
    aQQQSeries = []

    for cSymbol in aStocks
        txtLog.append("Fetching data for: " + cSymbol + "...")
        App.processEvents() # Keep UI responsive
        
        cJson = oFetcher.fetch(cSymbol, cInterval, cRange)
        aSeries = oParser.parse(cJson)
        
        if cSymbol = "QQQ"
            aQQQSeries = aSeries
        ok
        
        if len(aSeries) > 7
            nReturn = oStrategy.calculateMomentum(aSeries, 7)
            aResults + [cSymbol, nReturn, aSeries]
            txtLog.append(" -> Success. Return: " + (nReturn*100) + "%")
        else
            txtLog.append(" -> Failed or insufficient data.")
        ok
    next
    
    # Sort by Return (Descending)
    aResults = sort(aResults, 2) 
    aResults = reverse(aResults)
    
    txtLog.append("-----------------------------")
    txtLog.append("TOP PERFORMERS:")
    
    aGlobalTop7 = []
    nTop = min(7, len(aResults))
    for i = 1 to nTop
        item = aResults[i]
        txtLog.append(item[1] + ": " + (item[2]*100) + "%")
        aGlobalTop7 + item
    next
    
    # Simulation
    if len(aQQQSeries) = 0
        txtLog.append("Warning: QQQ not found for benchmark. Charting may be incomplete.")
    ok
    
    txtLog.append("Simulating Portfolio Performance...")
    aGlobalCurves = oSimulator.simulate(aGlobalTop7, aQQQSeries)
    
    oChartWidget.setData(aGlobalCurves[1], aGlobalCurves[2])
    
    txtLog.append("Analysis Complete. Chart Updated.")
    btnExport.setEnabled(true)

func exportCSV
    new QFileDialog(win) {
        cFile = getSaveFileName(win, "Save CSV", "AAA-CompareResult.csv", "CSV Files (*.csv)")
        if cFile != ""
            
            fp = fopen(cFile, "w")
            
            # Header
            fwrite(fp, "Index,Portfolio,QQQ" + nl)
            
            # Data
            aPort = aGlobalCurves[1]
            aQQQ = aGlobalCurves[2]
            nLen = min(len(aPort), len(aQQQ))
            
            for i = 1 to nLen
                fwrite(fp, "" + i + "," + aPort[i] + "," + aQQQ[i] + nl)
            next
            
            fclose(fp)
            txtLog.append("Successfully exported to: " + cFile)
        ok
    }

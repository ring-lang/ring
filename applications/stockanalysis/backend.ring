# Author: Azzeddine Remmal

load "libcurl.ring"
load "jsonlib.ring"
load "guilib.ring" 

class StockFetcher
    func fetch(cSymbol, cInterval, cRange)
        cUrl = "https://query1.finance.yahoo.com/v8/finance/chart/" + cSymbol + "?interval=" + cInterval + "&range=" + cRange
        cTempFile = "temp_" + cSymbol + ".json"
        
        # Build cURL command with User-Agent to bypass blocking
        # Using -s (silent), -A (browser spoofing), and -o (save to file)

		new qProcess(NULL) {
			aArg = new qStringList() {
				Append("-s")
				Append("-A")
				Append("Mozilla/5.0 (Windows NT 10.0; Win64; x64)")
				Append(cUrl)
				Append("-o")
				Append(cTempFile)
			}
			start("curl",aArg,QIODevice_ReadWrite)
		}
        
        cOutput = ""
        if fexists(cTempFile)
            cOutput = read(cTempFile)
            remove(cTempFile)
        ok
        
        return cOutput

class DataParser
    func parse(cJsonData)
        try
            oData = JSON2List(cJsonData)
            
            # Navigate JSON structure: chart -> result -> [0] -> indicators -> quote -> [0] -> adjclose
            # And: chart -> result -> [0] -> timestamp
            
            if not isList(oData) return [] ok
            if not oData["chart"]["result"] return [] ok
            
            result = oData["chart"]["result"][1] # Ring lists are 1-based
            
            if not result["timestamp"] return [] ok
            
            aTimestamps = result["timestamp"]
            aAdjClose = result["indicators"]["adjclose"][1]["adjclose"]
            
            # Combine into a list of [timestamp, close]
            aSeries = []
            nLen = len(aTimestamps)
            
            for i = 1 to nLen
                if isNumber(aAdjClose[i]) # Filter out nulls
                    aSeries + [ aTimestamps[i], aAdjClose[i] ]
                ok
            next
            
            return aSeries
        catch
            return []
        done

class StrategyEngine
    # Calculate 7-month return: (Current / T-7) - 1
    func calculateMomentum(aSeries, nMonths)
        nLen = len(aSeries)
        if nLen < nMonths + 1 return 0 ok # Not enough data
        
        nCurrent = aSeries[nLen][2] # Last close
        nPast = aSeries[nLen - nMonths][2] # Close nMonths ago
        
        if nPast = 0 return 0 ok
        
        return (nCurrent / nPast) - 1

class PortfolioSimulator
    func simulate(aTopStocksData, aQQQData)
        # aTopStocksData is a list of [Symbol, Return, Series]
        # aQQQData is the Series for QQQ
        
        # We need to align everything to the right (latest date)
        # Assuming all series are already roughly aligned by the Fetcher/Parser logic 
        # (which returns latest data at the end).
        # For simplicity, we'll take the minimum length of all series to ensure overlap.
        
        nMinLen = len(aQQQData)
        for item in aTopStocksData
            nLen = len(item[3]) # Series is at index 3
            if nLen < nMinLen
                nMinLen = nLen
            ok
        next
        
        if nMinLen < 1 return [[], []] ok
        
        aPortfolioCurve = []
        aQQQCurve = []
        
        # Calculate normalized curves (starting at 1.0)
        # We work backwards from the end
        
        for i = 0 to nMinLen - 1
            # Index from end: 1 means last element, 2 means second to last...
            # Ring lists are 1-based, so: len - i
            
            nSum = 0
            nCount = len(aTopStocksData)
            
            for item in aTopStocksData
                aSeries = item[3]
                nIndex = len(aSeries) - i
                nVal = aSeries[nIndex][2]
                nStartVal = aSeries[len(aSeries) - (nMinLen - 1)][2] # Value at start of simulation window
                
                nNormalized = nVal / nStartVal
                nSum = nSum + nNormalized
            next
            
            nPortfolioVal = nSum / nCount
            aPortfolioCurve + nPortfolioVal
            
            # QQQ
            nQQQIndex = len(aQQQData) - i
            nQQQVal = aQQQData[nQQQIndex][2]
            nQQQStart = aQQQData[len(aQQQData) - (nMinLen - 1)][2]
            
            nQQQNormalized = nQQQVal / nQQQStart
            aQQQCurve + nQQQNormalized
        next
        
        # The loops above built the lists backwards (latest to oldest). Reverse them.
        return [ reverse(aPortfolioCurve), reverse(aQQQCurve) ]


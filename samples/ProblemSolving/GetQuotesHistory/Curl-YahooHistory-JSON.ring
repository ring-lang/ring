// CURL-GET-Yahoo History Data for a Stock "AAPL" and Parse JSON returned data.
// Bert Mariani 2024-09-18

load "libcurl.ring"
load "stdlibcore.ring"
load "jsonlib.ring"

// Note: Ticker is "AAPL" in this $url
// $url = 'https://query1.finance.yahoo.com/v8/finance/chart/AAPL?metrics=high?&interval=1wk&range=1mo'

$url1 = 'https://query1.finance.yahoo.com/v8/finance/chart/'
$url2 = 'NVDA'                                                  // <<< Ticker
$url3 = '?metrics=high?&interval=1wk&range=1mo'

$url = $url1 + $url2 + $url3

//==================================================================

See "START - Yahoo History Chart "+nl

//========================================================================
// CURL INIT

    curl = curl_easy_init()              // START CURL INIT     
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.54.1" )   // FIX "Too many requests"       
    
//========================================================================
// CURL GET  $url ===>>>
      
    curl_easy_setopt(curl, CURLOPT_URL, $url);   ### <<<=== SetOpt + URL               
    cStr = curl_easy_perform_silent(curl)        ### <<<=== GET DATA ===>>> cStr
 
//===========================================================================
// SAVE the WEBPAGE DATA to cSTR  OR "sample.json" File,  for the READ to work.
	
    See "$url: "+ $url +nl+nl 
    See  cStr                                    // Debug 
    See  nl+nl+"===== cStr  FIN=========="+nl
     
    See nl+"===== JSON Yahoo History ====="+nl
    
//  See '===== Using: aList = JSON2List( read("sample.json")) ====='+nl    
//  aList = JSON2List( read("sample.json") )                              // Reads JSON File

    See "===== Using: aList = JSON2List( cStr ) ====="+nl+nl
    aList = JSON2List( cStr )                                             // Reads cStr
             
       
//  For [{  need [1]   vv                                                 // NOTE [{  requires[1]
//  {"chart": {"result":[{"meta":{"currency":"USD","symbol":"AAPL",
//  [:chart][:result][1][:meta][:symbol]
    
    ? "Sym:    " + aList[:chart][:result][1][:meta][:symbol]    
    ? "Name:   " + aList[:chart][:result][1][:meta][:shortName]  
    ? "High:   " + aList[:chart][:result][1][:meta][:regularMarketDayHigh]
    ? "Low:    " + aList[:chart][:result][1][:meta][:regularMarketDayLow]
    ? "Close:  " + aList[:chart][:result][1][:meta][:regularMarketPrice]
    ? "Volume: " + aList[:chart][:result][1][:meta][:regularMarketVolume]   

    ? " "
    ? "---History Open, High, Low, Close, Volume, AdjClose---------"
    ? "Open:   "  ? aList[:chart][:result][1][:indicators][:quote][1][:open]
    ? "High:   "  ? aList[:chart][:result][1][:indicators][:quote][1][:high]
    ? "Low:    "  ? aList[:chart][:result][1][:indicators][:quote][1][:low]
    ? "Close:  "  ? aList[:chart][:result][1][:indicators][:quote][1][:close]
    ? "Volume: "  ? aList[:chart][:result][1][:indicators][:quote][1][:volume]
    
    ? "AdjClose:" ? aList[:chart][:result][1][:indicators][:adjclose][1][:adjclose]
     
    ? " "
    ? "TimeStamp: "  ? aList[:chart][:result][1][:timestamp]
    
    //--------------------------------------------------
    // Convert EPOCH Seconds to Human Readable Date format
    
    for k = 1 to 6
          $EpochStart = aList[:chart][:result][1][:timestamp][k]
          See "Date:  "+ EpochToDate($EpochStart) +nl
    next  
  
    //=======================================    
    // Enter Char to CLOSE CMD Window

    abc = getchar()  
 
//=======================================
// Convert Epoch Secs to Human Readable Date

Func EpochToDate(EpochSecs)

   NbrDays   = EpochSecs / 86400                    // 1726776001
   DateHuman = AddDays( "01/01/1970", NbrDays )

 return DateHuman                                   // 19/09/2024
 
 
//////////////////////////////////////////////
///////////////////////////////////////////////

/*  

=================================
Yahoo History cStr <= JSON Data

$url = 'https://query1.finance.yahoo.com/v8/finance/chart/AAPL?metrics=high?&interval=1wk&range=1mo'

RAW cStr DATA

{"chart":{"result":[{"meta":{"currency":"USD","symbol":"AAPL","exchangeName":"NMS","fullExchangeName":"NasdaqGS","instrumentType":"EQUITY","firstTradeDate":345479400,"regularMarketTime":1726689602,"hasPrePostMarketData":true,"gmtoffset":-14400,"timezone":"EDT","exchangeTimezoneName":"America/New_York","regularMarketPrice":220.69,"fiftyTwoWeekHigh":222.7,"fiftyTwoWeekLow":217.54,"regularMarketDayHigh":222.7,"regularMarketDayLow":217.54,"regularMarketVolume":58797956,"longName":"Apple Inc.","shortName":"Apple Inc.","chartPreviousClose":216.79,"priceHint":2,"currentTradingPeriod":{"pre":{"timezone":"EDT","start":1726732800,"end":1726752600,"gmtoffset":-14400},"regular":{"timezone":"EDT","start":1726752600,"end":1726776000,"gmtoffset":-14400},"post":{"timezone":"EDT","start":1726776000,"end":1726790400,"gmtoffset":-14400}},"dataGranularity":"1wk","range":"5w","validRanges":["1d","5d","1mo","3mo","6mo","1y","2y","5y","10y","ytd","max"]},"timestamp":[1726459200,1726689602],"indicators":{"quote":[{"volume":[59788400,58797956],"open":[217.5500030517578,217.58999633789062],"low":[217.5399932861328,217.5399932861328],"high":[222.7100067138672,222.6999969482422],"close":[220.69000244140625,220.69000244140625]}],"adjclose":[{"adjclose":[220.69000244140625,220.69000244140625]}]}}],"error":null}}
 
//============================ 
FORMATED Data in WebPage 
 
{
    "chart": {
        "result": [
            {
                "meta": {
                    "currency": "USD",
                    "symbol": "AAPL",
                    "exchangeName": "NMS",
                    "fullExchangeName": "NasdaqGS",
                    "instrumentType": "EQUITY",
                    "firstTradeDate": 345479400,
                    "regularMarketTime": 1726776001,
                    "hasPrePostMarketData": true,
                    "gmtoffset": -14400,
                    "timezone": "EDT",
                    "exchangeTimezoneName": "America/New_York",
                    "regularMarketPrice": 228.87,
                    "fiftyTwoWeekHigh": 229.82,
                    "fiftyTwoWeekLow": 224.64,
                    "regularMarketDayHigh": 229.82,
                    "regularMarketDayLow": 224.64,
                    "regularMarketVolume": 66307649,
                    "longName": "Apple Inc.",
                    "shortName": "Apple Inc.",
                    "chartPreviousClose": 225.89,
                    "priceHint": 2,
                    "currentTradingPeriod": {
                        "pre": {
                            "timezone": "EDT",
                            "start": 1726732800,
                            "end": 1726752600,
                            "gmtoffset": -14400
                        },
                        "regular": {
                            "timezone": "EDT",
                            "start": 1726752600,
                            "end": 1726776000,
                            "gmtoffset": -14400
                        },
                        "post": {
                            "timezone": "EDT",
                            "start": 1726776000,
                            "end": 1726790400,
                            "gmtoffset": -14400
                        }
                    },
                    "dataGranularity": "1wk",
                    "range": "1mo",
                    "validRanges": [
                        "1d",
                        "5d",
                        "1mo",
                        "3mo",
                        "6mo",
                        "1y",
                        "2y",
                        "5y",
                        "10y",
                        "ytd",
                        "max"
                    ]
                },
                "timestamp": [
                    1724040000,
                    1724644800,
                    1725249600,
                    1725854400,
                    1726459200,
                    1726776001
                ],
                "indicators": {
                    "quote": [
                        {
                            "low": [
                                223.0399932861328,
                                223.88999938964844,
                                217.47999572753906,
                                216.7100067138672,
                                213.9199981689453,
                                224.63999938964844
                            ],
                            "open": [
                                225.72000122070312,
                                226.75999450683594,
                                228.5500030517578,
                                220.82000732421875,
                                216.5399932861328,
                                225.13999938964844
                            ],
                            "close": [
                                226.83999633789062,
                                229,
                                220.82000732421875,
                                222.5,
                                220.69000244140625,
                                228.8699951171875
                            ],
                            "high": [
                                228.33999633789062,
                                232.9199981689453,
                                229,
                                224.0399932861328,
                                222.7100067138672,
                                229.82000732421875
                            ],
                            "volume": [
                                188124900,
                                209486100,
                                179069200,
                                237622900,
                                164771600,
                                66307649
                            ]
                        }
                    ],
                    "adjclose": [
                        {
                            "adjclose": [
                                226.83999633789062,
                                229,
                                220.82000732421875,
                                222.5,
                                220.69000244140625,
                                228.8699951171875
                            ]
                        }
                    ]
                }
            }
        ],
        "error": null
    }
}

////////////////////////
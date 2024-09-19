load "jsonlib.ring"

cData = `
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
                    "regularMarketTime": 1726689602,
                    "hasPrePostMarketData": true,
                    "gmtoffset": -14400,
                    "timezone": "EDT",
                    "exchangeTimezoneName": "America/New_York",
                    "regularMarketPrice": 220.69,
                    "fiftyTwoWeekHigh": 222.7,
                    "fiftyTwoWeekLow": 217.54,
                    "regularMarketDayHigh": 222.7,
                    "regularMarketDayLow": 217.54,
                    "regularMarketVolume": 58797956,
                    "longName": "Apple Inc.",
                    "shortName": "Apple Inc.",
                    "chartPreviousClose": 221.72,
                    "priceHint": 2,
                    "currentTradingPeriod": {
                        "pre": {
                            "timezone": "EDT",
                            "end": 1726666200,
                            "start": 1726646400,
                            "gmtoffset": -14400
                        },
                        "regular": {
                            "timezone": "EDT",
                            "end": 1726689600,
                            "start": 1726666200,
                            "gmtoffset": -14400
                        },
                        "post": {
                            "timezone": "EDT",
                            "end": 1726704000,
                            "start": 1726689600,
                            "gmtoffset": -14400
                        }
                    },
                    "dataGranularity": "1wk",
                    "range": "5wk",
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
                    1723435200,
                    1724040000,
                    1724644800,
                    1725249600,
                    1725854400,
                    1726459200,
                    1726689602
                ],
                "indicators": {
                    "quote": [
                        {
                            "low": [
                                219.6999969482422,
                                223.0399932861328,
                                223.88999938964844,
                                217.47999572753906,
                                216.7100067138672,
                                213.9199981689453,
                                217.5399932861328
                            ],
                            "high": [
                                226.8300018310547,
                                228.33999633789062,
                                232.9199981689453,
                                229,
                                224.0399932861328,
                                217.22000122070312,
                                222.6999969482422
                            ],
                            "close": [
                                226.0500030517578,
                                226.83999633789062,
                                229,
                                220.82000732421875,
                                222.5,
                                216.7899932861328,
                                220.69000244140625
                            ],
                            "open": [
                                220.57000732421875,
                                225.72000122070312,
                                226.75999450683594,
                                228.5500030517578,
                                220.82000732421875,
                                216.5399932861328,
                                217.5500030517578
                            ],
                            "volume": [
                                132714800,
                                188124900,
                                209486100,
                                179069200,
                                237622900,
                                104876700,
                                58797956
                            ]
                        }
                    ],
                    "adjclose": [
                        {
                            "adjclose": [
                                225.7886505126953,
                                226.83999633789062,
                                229,
                                220.82000732421875,
                                222.5,
                                216.7899932861328,
                                220.69000244140625
                            ]
                        }
                    ]
                }
            }
        ],
        "error": null
    }
}
`

aList = JSON2List( cData )

? aList[:chart][:result][1][:meta][:symbol]
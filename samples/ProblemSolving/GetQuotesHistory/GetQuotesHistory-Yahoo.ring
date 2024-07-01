### http://ring-lang.net/
### Yahoo changed their interface 2017-05-15 to get historical quote data for a stock
### They now send a Cookie and Crumb and expect the Request to provide those values
load "internetlib.ring"
load "libcurl.ring"
load "Stdlib.ring"

###------------------------------
### Get Request

See nl "===== GET REQUEST ====="+ nl

### Part 1 --- Get Crumb and Cookie -----------------------------------------

curl = curl_easy_init()                                         ### >>> HANDLE >>> 01006BD0  CURL  0
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.54.1" )
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1)
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR,  "cookies.txt")
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt")
    curl_easy_setopt(curl, CURLOPT_URL, "https://finance.yahoo.com/quote/AMZN/history")

    ###  HTML Data >>> STDOUT Window,  Use curl_easy_perform_silent >>> String

cOutput = curl_easy_perform_silent(curl)    ### GO Get Data >>> String

###   Extract Crumb from data
### ,"CrumbStore":{"crumb":"abcdefghijk"},

        newStr1     = substr(cOutput, substr(cOutput, '"CrumbStore":{"crumb":"' ), 48 )
            nPosS   = substr(newStr1, ':"' ) ;  ### Start of crumb -2
            nPosE   = substr(newStr1, '"}' ) ;  ### End   of crumb
            nCount  = nPosE - nPosS -2          ### size  of crumb
        myCrumb     = substr(newStr1, nPosS +2, nCount)

        # See "myCrumb.: |"+ myCrumb +"|" +nl

### Extract Cookie from cookies.txt file
### .yahoo.com              TRUE    /   FALSE   1527878113  B   16abcdefghijklmnopq

        cFileName = "cookies.txt"
        cStr = Read(cFileName)

        myList = str2list(cStr)
        for line in myList
            if substr(line, "yahoo")
                lineList = split(line, char(09) )
                myCookie = lineList[7]
                # See "myCookie: |"+ myCookie +"|" +nl
            ok
        next

### Part 2 --- Send URL with Crumb, and Cookie -----------------------------------------

        #myCookie = "16...................q"
        #myCrumb  = "a.........y"

        $urlA   = "https://query1.finance.yahoo.com/v7/finance/download/"
        $urlB   = "?period1=1464726832&period2=1496262832&interval=1wk&events=history&crumb="+ myCrumb

        ### Send COOKIE & URL+Crumb to Yahoo to fetch 1st stock history data, 
        ### Cookie and AMZN

        $symbol = "AMZN"
        $url = $urlA + $symbol + $urlB
                  curl_easy_setopt(curl, CURLOPT_COOKIE, myCookie);
                  curl_easy_setopt(curl, CURLOPT_URL, $url);
        cOutput = curl_easy_perform_silent(curl)

        See nl +"====== Output: AMZN ======" + nl + nl
        see cOutput

        ### NVDA -- 2nd just URL+Crumb

        $symbol = "NVDA"
        $url = $urlA + $symbol + $urlB
                  curl_easy_setopt(curl, CURLOPT_URL, $url);
        cOutput = curl_easy_perform_silent(curl)

        See nl +"====== Output: NVDA ======" + nl + nl
        see cOutput


curl_easy_cleanup(curl)

See nl +"=========== END ==============="+ nl

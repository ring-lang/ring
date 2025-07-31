// Curl-HTML-Extract-RegEx-Csv-Json-List-File
// Bert Mariani 2025-07-28

// To install RingRegex using RingPM (To get the ringregex.ring)
// Run:  ringpm install ringregex

load "jsonlib.ring"
load "ringregex.ring"

//-----------------------------------------------
// URL of Site, plus Ticker
// Canada use tsx:  https://dividendhistory.org/payout/tsx/BMO/
// Need UpperCase for $ticker,  Canada stocks = /tsx/BMO

LimitExtractSize = 122   // How many dividends max to fetch

$tickerList = ['JPM','BMO','RY','WFC']

       See ">>>>> $TickerList >>>>>"+nl
       for entry in $tickerList
          See entry +"  "
       next	
	      See nl

$ticker = 'JPM'
$url1   = 'https://dividendhistory.org/payout/'
$url2   = '/'
$URL    =  $url1 + $ticker +$url2

//------------------------------------------------
// Patterns

FindStart  = '<th>Cash Amount</th>'
FindEnd    = '</td></tr></tbody></table></dividend-table>'

//--------------------------------------
// HTML Extract REGEX Pattern is 2 Passes

# Create RegEx object to match <tr> elements (including class attribute or empty class)
tr_regex = new RegEx(`<tr\s*(?:class="unconfirmed-div"|class)?>(.*?)</tr>`, 0)

# Create RegEx object to match <td> content (first three <td> elements)
td_regex = new RegEx(`<td>([^<]*?)</td>`, 0)

// regexPattern = new RegEx("<td>(\d{4}-\d{2}-\d{2})</td><td>(\d{4}-\d{2}-\d{2})</td><td>\$(\d+\.\d{2})</td><td>(?:<.*?>)?([^<]*)</td></tr>", 0)

// regexPattern = new RegEx("<td>(.*?)</td>", 0)

   //--- Verify HTML Pattern is Valid --- 
   if NOT tr_regex.isValid()
       ? "Error: Invalid regex pattern tr_regex - " + regex.getError()
       return
   ok  
 
   if NOT td_regex.isValid()
       ? "Error: Invalid regex pattern td_regex - " + regex.getError()
       return
   ok

//--------------------------------------
// Output Directory for Files

// --- Defne the directory path
cOutDir = 'Dividend'
dirPath =  cOutDir

    // --- Check if the directory exists
    if DirExists(dirPath)
        see nl+"Directory already exists: " + dirPath + nl
    else
        // --- Create the directory
        makeDir(dirPath)
        if DirExists(dirPath)
            see nl+"Directory created successfully: " + dirPath + nl
        else
            see nl+"Failed to create directory: " + dirPath + nl
        ok
    ok


//=======================================
//=======================================

See nl+"<<<<< START - DividendHistory <<<<<"+nl

for $ticker in $tickerList

    $ticker = upper($ticker)
    $ticker = subStr($ticker, 'TSX', 'tsx' )
    
    See nl+nl+"<<<<<>>>>> Get This $TICKER: "+$ticker +" <<<<<>>>>>"+nl 
    
    $URL =  $url1 + $ticker +$url2
    See "$URL: "+$URL +nl
    
    cData    = GetCurl($URL)             // 1
    
    Results  = HTMLExtract(cData)        // 2
    
    jData    = GetList2Jason(Results)    // 3
    
    aList    = GetJason2List(Results)    // 4
       
next



//==============================================
// 1 CURL Using Windows SystemCmd

Func GetCurl($URL)

See nl+"<<<<< 1 Func GetCurl($URL) <<<<<"+nl 
See $URL +nl

    cStr = SystemCmd("curl -s "+ $URL)

    if ( len(cStr) = 0 )  
       See nl+"NO INTERNET CONNECTION: " +nl +"CONNECT TO INTERNET AND TRY AGAIN: " +nl
       See "Press Enter to Exit"+ nl
       keyChar = GetChar()           
       return
    ok

//  See nl+"===== Start CURL Entire cStr "+$ticker +"====="+nl 
//  See cStr
//  See nl+"===== End End Entire cStr ====="+nl    
    
    //===========================================================================
    // Get Dividend Portion of HTML
      
    strPos    = substr(cStr,FindStart ) # start of div
    endPos    = substr(cStr,FindEnd )   # end   of div
    countChar = endPos - strPos
    

    cData = substr(cStr,strPos, countChar)  // --> Get subst start from pos to end

//  See nl+"===== Start CURL Extract cData ====="+nl 
//  See cData
//  See nl+"===== End CURL Extract cData ====="+nl    
 
 
return cData 

//==========================================
// 2 HTML EXTRACT cData Curl portion
//   Using Class and pattern

Func HTMLExtract(cData)

See nl+"<<<<< 2 Func HTMLExtract(cData) <<<<<"+nl
 
    ###--- Find All <tr> elements ---
tr_matches = tr_regex.findAll(cData)


    ###--- Initialize result list ---
results = []
limit   = 1   // For DEBUG nbr of records

    ###--- Process each <tr> ---
for tr_match in tr_matches

    tr_content = tr_match[2]  # Content of the <tr>
    
    ### Find first three <td> elements in this <tr>
    td_matches = td_regex.findAll(tr_content)
    
    ### Ensure we have at least 3 <td> elements
    if len(td_matches) >= 3
    
        ### Extract the first three <td> contents (start date, end date, amount)
        row_data = [td_matches[1][2], td_matches[2][2], td_matches[3][2]]
        add(results, row_data)
    ok
    
    if limit >= LimitExtractSize
       exit
    ok
    limit++  
    
next

    ### Print results in a structured format
    See nl+"===== Start HTML Extract "+$ticker +" cData as CSV ====="+nl

strLines = ""    
for row in results
    Line = ""+ row[1] +", "+ row[2] +", "+ row[3] +nl
    strLines += Line      // One Long string
    See Line
next

    output = cOutDir +'/'+ $ticker + ".csv"
    See nl+">>>>> Write outout: "+output +" >>>>>" +nl
    Write(output, strLines)
    
    See nl+"===== End HTML Extract cData portion Curl ====="+nl

return results

//===================================

//=====================================
// 3 List2Json or Results format  - Create JSON 
//   FIX 2025-07-24  Replace { to [  at start&end pos

Func GetList2Jason(cResults)

See nl+"<<<<< 3 GetList2Jason(cResults) <<<<<"+nl

aList = cResults

jsonData    = list2Json(aList)
jsonData[1] = '['                 // FIX first { to [
jsonData[ len(jsonData)] = ']'    // FIX last } to ]


   See nl+"===== Start JSON List2Json " +$ticker +" FIX { => [ start&end ====="+nl 
   See jsonData
   See nl+"===== End List2Json FIX } => ] start&end ====="+nl


    output = cOutDir +'/'+ $ticker + ".json"
    See nl+">>>>> Write outout: "+output " >>>>>" +nl
    Write(output, jsonData)

return jsonData

//======================================
// 4 Json2List format Create List label:value format
// Read Record in Records[1] 
// [td_matches[1][2], td_matches[2][2], td_matches[3][2]]

Func GetJason2List(Results)

See nl+"<<<<< 4 Func GetJason2List(Results) <<<<<"+nl

   See nl+"===== Start LIST "+$ticker +" format: label: data ====="+nl+nl
   
aList = []
Add( aList, "[")  // Opening [ for array
i = 1

for row in results

    // See "ROW: "+i +" "+ row[1] +" "+ row[2] +" "+ row[3] +nl

    exdate  = row[1]
    paydate = row[2]
    amount  = row[3]
     
    Line = ["[",
            :exdate  = exdate , 
            :paydate = paydate , 
            :amount  = amount ,
            "],"
           ]
           
    //-------------------
    Add(aList, Line) 
    
    //See "Line: "+i +" " See Line  See nl 
    i++
    
next
Add( aList, "]")   // Closing ] for array

   //---------------------------
   // Display aList[i] each line has: 3 label:value 

strList = ''
   for i = 2 to len(aList) -1  // Ignore start [ and end ]
       See ""+i +": "
       P21 = aList[i][2][1]  + ": "
       P22 = aList[i][2][2]  + ", " 

       P31 = aList[i][3][1]  + ": " 
       P32 = aList[i][3][2]  + ", " 

       P41 = aList[i][4][1]  + ": " 
       P42 = aList[i][4][2]  + nl
       
       Line = P21 + P22 + P31 + P32 +P41 + P42 
       See Line 
       
       strList += Line

   next  
   
   //------------------------------     
    output = cOutDir +'/'+ $ticker + ".list"
    See nl+">>>>> Write outout: "+output +" >>>>>" +nl
    Write(output, strList)
   //------------------------------
       
return aList

//============================
//============================

// aList5-2-1: exdate
// aList5-2-2: 2025-04-04
// aList5-3-1: paydate
// aList5-3-2: 2025-04-30
// aList5-4-1: amount
// aList5-4-2: $1.40
// 

//====================
//====================
/*
IGORE the <SPAN CLASS

<th>Cash Amount</th>
<th>% Change</th>
</tr>
</thead><tbody>

<tr class="unconfirmed-div">
<td>2026-01-06</td>
<td>2026-01-30</td>
<td>$1.40</td>
<td>unconfirmed/estimated</td>
</tr>

<tr class="unconfirmed-div">
<td>2025-10-03</td>
<td>2025-10-31</td>
<td>$1.40</td>
<td>unconfirmed/estimated</td>
</tr>

<tr class>
<td>2025-07-03</td>
<td>2025-07-31</td>
<td>$1.40</td>
<td></td>
</tr>

<tr class>
<td>2025-04-04</td>
<td>2025-04-30</td>
<td>$1.40</td>
<td>
<span class="percent-change percent-increase">
<i class="bi bi-arrow-up-circle-fill me-1" role="img" aria-label="Dividend Increase">
</i>12%
</span>
</td>
</tr>

<tr class>
<td>2025-01-06</td>
<td>2025-01-31</td>
<td>$1.25</td>
<td></td>
</tr>

<tr class>
<td>2024-10-04</td>
<td>2024-10-31</td>
<td>$1.25</td>
<td>
<span class="percent-change percent-increase">
<i class="bi bi-arrow-up-circle-fill me-1" role="img" aria-label="Dividend Increase">
</i>8.7%
</span>
</td>
</tr>

<tr class>
<td>2024-07-05</td>
<td>2024-07-31</td>
<td>$1.15</td>
<td></td>
</tr>

<tr class>
<td>2024-04-04</td>
<td>2024-04-30</td>
<td>$1.15</td>
<td>
<span class="percent-change percent-increase">
<i class="bi bi-arrow-up-circle-fill me-1" role="img" aria-label="Dividend Increase">
</i>9.52%
</span>
</td>
</tr>

<tr class>
<td>2024-01-04</td>
<td>2024-01-31</td>
<td>$1.05</td>
<td></td>
</tr>

<tr class>
<td>2023-10-05</td>
<td>2023-10-31</td>
<td>$1.05</td>
<td>
<span class="percent-change percent-increase"><i class="bi bi-arrow-up-circle-fill me-1" role="img" aria-label="Dividend Increase">
</i>5%
</span>
</td>
</tr>

<tr class>
<td>2023-07-05</td>
<td>2023-07-31</td>
<td>$1.00</td>
<td></td>
</tr>

<tr class>
<td>2023-04-05</td>




  

# Form/Window Controller - Source Code File

load "EpochTimeConverterView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:EpochTimeConverterController)
		exec()
	}
}

//=====================================================
// "PRIVATE FUNCTION NOT PART of VIEW RFORM"
// Covert EPOCH Seconds to HUMAN Time
// HumanDateTime: 28/10/2024 10:14:30
// 1-Epoch: Time Secs: 1730110470
// 1-Human: Date Time: 28/10/2024 10:14:30

Func EpochToDate(EpochSecs)
   NbrDays   = EpochSecs / 86400                    // 1726776001  Neg  -71730112804 = Year -304
   DateHuman = AddDays( "01/01/1970", NbrDays )     // 19/09/2024
   
   SecDay      = fabs( EpochSecs  %  86400 )        // 73988  Make Pos for MM,DD 
   
   FloorHour   = floor(SecDay  / 3600)              // 20.5522  -> 20 
   TotHourSec  = FloorHour * 3600                   // 20 * 3600 = 72000
   DiffHourSec = SecDay - TotHourSec                // 73988 - 72000 = 1988 
 
   FloorMin    = floor(DiffHourSec / 60)            // 1988 / 60 = 33.1333 -> 33
   TotMinSec   = FloorMin * 60                      // 33 * 60 = 1980
   FloorSec    = floor(DiffHourSec - TotMinSec )    // 1988 - 1980 = 8.10 -> 8
   
   if FloorHour < 10   FloorHour = "0" +FloorHour  ok
   if FloorMin  < 10   FloorMin  = "0" +FloorMin   ok
   if FloorSec  < 10   FloorSec  = "0" +FloorSec   ok
    
   TimeHuman = ""+ FloorHour +":"+ FloorMin +":"+ FloorSec
   
   HumanDateTime = DateHuman +" "+ TimeHuman         // 28/10/2024 10:14:30
   
return HumanDateTime  

//=====================================================
//=====================================================
// CLASS FUNCTIONS

class EpochTimeConverterController from windowsControllerParent

	oView = new EpochTimeConverterView



//================================================
// "FUNC Template by RFORM VIEW"

   // See "In Controller: Start EpochTimeConverter"+nl

//===============================================
// Controller: GoDateTimeToEpoch
// Epoch: 1729958222 26/10/2024  15:57:02

func GoDateTimeToEpoch
oView {

   //--------------------
   //See nl+"Controller: GoDateTimeToEpoch"+nl	

   this.GoCurrentTime()    // ===>>> USE  "this.FuncName() Brackets

   //----------------------------------
   // Read RForm Fields Human Time
   // Check correct input time format

   hDateYYYY = YYYYEdit.toPlainText()
   hDateMM   =   MMEdit.toPlainText()
   hDateDD   =   DDEdit.toPlainText()
   
   hTimeHour = HourEdit.toPlainText()
   hTimeMin  =  MinEdit.toPlainText() 
   hTimeSec  =  SecEdit.toPlainText()

   //----------------------------------------------
   // FILL IN Leading Zero

    if  hDateYYYY > 0     // Positive Year
        if  len(hDateYYYY) = 3  hDateYYYY = "0"   + hDateYYYY  ok  
        if  len(hDateYYYY) = 2  hDateYYYY = "00"  + hDateYYYY  ok  
        if  len(hDateYYYY) = 1  hDateYYYY = "000" + hDateYYYY  ok  
	
	elseif hDateYYYY = 0 
		sErrMsg = "Year is 0:  "+ hDateYYYY
		ErrorEdit.setText(sErrMsg)
		See "ErrMsg: "+ sErrMsg +nl
		return	
		
	else	               // Negative Year		
		sErrMsg = "Year is Negative:  "+ hDateYYYY
		ErrorEdit.setText(sErrMsg)
		See "ErrMsg: "+ sErrMsg +nl
		return
	ok		
	
    if  len(hDateMM)   = 1   hDateMM   = "0"  + hDateMM    ok  
    if  len(hDateDD)   = 1   hDateDD   = "0"  + hDateDD    ok  
    if  len(hTimeHour) = 1   hTimeHour = "0"  + hTimeHour  ok  
    if  len(hTimeMin)  = 1   hTimeMin  = "0"  + hTimeMin   ok  
    if  len(hTimeSec)  = 1   hTimeSec  = "0"  + hTimeSec   ok  

   //-----------------------------------------------
      ErrorEdit.setText(" ")
      sErrMsg = "."

   if !( (hDateYYYY >= -9999) AND (hDateYYYY <= 9999) )
      sErrMsg = "Year Not in Range -9999 to 9999:  "+ hDateYYYY 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( (hDateMM >= 1) AND (hDateMM <= 12) )
      sErrMsg = "Month Not in Range 1 to 12:  "+ hDateMM 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( (hDateDD >= 1) AND (hDateDD <= 31) )
      sErrMsg = "Day Not in Range 1 to 31:  "+ hDateDD 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( (hTimeHour >= 0) AND (hTimeHour <= 23) )
      sErrMsg = "Hour Not in Range 0 to 23:  "+ hTimeHour 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( (hTimeMin >= 0) AND (hTimeMin <= 59) )
      sErrMsg = "Minute Not in Range 0 to 59:  "+ hTimeMin 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( (hTimeSec >= 0) AND (hTimeSec <= 59) )
      sErrMsg = "Second Not in Range 0 to 59:  "+ hTimeSec 
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
   ok

   if !( sErrMsg = "." )
      return
   ok

   //--------------------------------------------------
   // Format Date Time Fields 
   // Human: Date Time: 28/10/2024 10:14:30
   // Epoch: Time Secs: 1730110470
   
   DateCombo = hDateDD   +'/'+ hDateMM  +'/'+ hDateYYYY
   TimeCombo = hTimeHour +':'+ hTimeMin +':'+ hTimeSec
   See "2-Human: Date Time: "+ DateCombo +" "+ TimeCombo +nl 
   
   EpochSec = EpochTime( DateCombo, TimeCombo )

   See "2-Epoch: Time Secs: "+ EpochSec +nl

  EpochEdit.setText( ""+EpochSec )
  
  //--------------------

}


//===============================================
// Controller: GoEpochToDateTime
// Epoch: Time Secs: 1729958747
// Human: Date Time: 26/10/2024 16:05:47

func GoEpochToDateTime
oView {

   //---------------------------
   //See nl+"Controller: GoEpochToDateTime"+nl


   this.GoCurrentTime()    // ===>>> USE  "this.FuncName() Brackets

   //--------------------------------------
   // Read the EpochEdit Fiels in RFORM
   EpochSec = EpochEdit.toPlainText()    //  1729958747

   ErrorEdit.setText(" ")
   if !( (EpochSec >= -99999999999) AND (EpochSec <= 99999999999) )
      sErrMsg = "Epoch seconds Not in Range -9999999999 to 9999999999:  "+ EpochSec
      ErrorEdit.setText(sErrMsg)
      See "ErrMsg: "+ sErrMsg +nl
      return
   ok

   DateTime = EpochToDate(EpochSec)        //  26/10/2024 16:05:47

   See "1-Epoch: Time Secs: "+ EpochSec +nl
   See "1-Human: Date Time: "+ DateTime +nl

   aDateTime = split( DateTime, ' ')
   aDate     = split(aDateTime[1], '/' )
   aTime     = split(aDateTime[2], ':' )
   
   YYYYEdit.setText( aDate[3] )     
     MMEdit.setText( aDate[2] )
     DDEdit.setText( aDate[1] )
	 
   HourEdit.setText( aTime[1] )
    MinEdit.setText( aTime[2] )
    SecEdit.setText( aTime[3] )
//--------------------------
		
}

//=========================================================
// Get CURRENT TIME
// NOTE RForm generated shows No Brackets after FuncName

func GoCurrentTime
oView {

   //---------------------------
17301140721730114072   // See nl+"Controller: GoCurrentTime"+nl

   //--------------------------------------
   // Current Date
   hDate    = Date()
   hTime    = Time()
   EpochSec = EpochTime( Date(), Time() )

   aDate = split(hDate, '/' )
   fDate = aDate[3] +'/'+ aDate[2] +'/'+ aDate[1]

      CurEpochTextEdit.setText(""+ EpochSec)
   CurDateTimeTextEdit.setText(fDate +"  "+ hTime)
			
}
 
//================================================
// Timer set at 1000
// Update Current Time: this.GoCurrentTime()	
// NEED "this" and "()" Inside Method Class

func GoTimer
oView {
   this.GoCurrentTime()	  	
}

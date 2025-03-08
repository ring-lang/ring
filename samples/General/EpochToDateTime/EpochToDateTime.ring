// Test the Func EpochToDate(EpochSecs)
// EpochSec: 1741378152 DateTime: 07/03/2025 20:09:12

EpochSecs =1741378152
DateTime = EpochToDate(EpochSecs)
See "EpochSec: "+EpochSecs +" DateTime: "+DateTime +nl

//=====================================================
// Covert EPOCH Seconds to HUMAN DateTime format
// HumanDateTime: 28/10/2024 10:14:30
// 1-Epoch: Time Secs: 1730110470
// 2-Human: Date Time: 28/10/2024 10:14:30

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

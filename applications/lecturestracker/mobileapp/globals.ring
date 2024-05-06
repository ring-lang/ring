/*
**
** Global Variables & Constants 
**
*/

aData             		= []		# Used for storing web request result (One Record)
aHistory	  		= []		# All records 
lDisplayMap      		= False

cAPIURL           		= "http://localhost:8080/"
cInsURL           		= cAPIURL + "ins"
cSubjectURL          		= cAPIURL + "subject"
cAttendancePercentageURL	= cAPIURL + "attendance"

cMapURL 	  		= "https://www.google.com/maps/?q="

C_LAT				= "24.7240726"
C_LONG				= "46.6245164"

# User Interface Constants 
C_TITLE		  		= "Lectures Tracker"  
C_GETDATA         		= "Get Data"
C_ATTENDANCEPERCENTAGE  	= "Attendance Percentage: "
C_SUBJECT            		= "Subject: "
C_INS             		= "Instructor: "
C_CONNECTING      		= "Connecting..."
C_OPENMAP	  		= "Open University Map"
C_DATECOL	  		= "Date"
C_TIMECOL	  		= "Time"
C_ATTENDANCEPERCENTAGECOL	= "Attendance"
C_INSCOL 	  		= "Instructor"
C_SUBJECTCOL	  		= "Subject"
C_CLEARHISTORY			= "Clear History"

# History Table 
C_DATECOLINHISTORY    		= 1
C_TIMECOLINHISTORY    		= 2
C_ATTENDANCECOLINHISTORY 	= 3
C_INSCOLINHISTORY     		= 4
C_SUBJECTCOLINHISTORY    	= 5

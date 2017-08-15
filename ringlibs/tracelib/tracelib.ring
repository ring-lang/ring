# The Ring Standard Library
# Trace Library
# 2016-2017, Mahmoud Fayed <msfclipper@yahoo.com>

# Trace Events
TRACEEVENT_NEWLINE 	= 1
TRACEEVENT_NEWFUNC 	= 2
TRACEEVENT_RETURN 	= 3
TRACEEVENT_ERROR 	= 4
TRACEEVENT_BEFORECFUNC 	= 5
TRACEEVENT_AFTERCFUNC 	= 6

# Trace Data
TRACEDATA_LINENUMBER  	= 1
TRACEDATA_FILENAME 	= 2
TRACEDATA_FUNCNAME 	= 3
TRACEDATA_METHODORFUNC 	= 4

# Method of Function
TRACEDATA_METHODORFUNC_METHOD 		= TRUE
TRACEDATA_METHODORFUNC_NOTMETHOD	= FALSE


func Trace cType
	switch trim(lower(cType))
	on :AllEvents
		ringvm_settrace("TraceLib_AllEvents()")
	on :Functions 
		ringvm_settrace("TraceLib_Functions()")
	on :PassError
		ringvm_settrace("TraceLib_PassError()")
	on :Debugger 
		ringvm_settrace("TraceLib_Debugger()")
	on :LineByLine
		ringvm_settrace("TraceLib_LineByLine()")
	off

func TraceLib_AllEvents
	if right(ringvm_tracedata()[TRACEDATA_FILENAME],13) = "tracelib.ring"
		return 
	ok
	see "====== The Trace function is Active ======" + nl +
	    "Trace Function Name : " + ringvm_TraceFunc() + nl +
	    "Trace Event : " 
	switch ringvm_TraceEvent()
		on TRACEEVENT_NEWLINE 		see "New Line" 
		on TRACEEVENT_NEWFUNC		see "New Function"
		on TRACEEVENT_RETURN		see "Return"
		on TRACEEVENT_ERROR		see "Error"
		on TRACEEVENT_BEFORECFUNC	see "Before C Function"
		on TRACEEVENT_AFTERCFUNC	see "After C Function"
	off
	see nl +
		"Line Number : " + ringvm_tracedata()[TRACEDATA_LINENUMBER] + nl +
		"File Name   : " + ringvm_tracedata()[TRACEDATA_FILENAME] + nl +
		"Function Name : " + ringvm_tracedata()[TRACEDATA_FUNCNAME] + nl +
		"Method or Function : " 
		if ringvm_tracedata()[TRACEDATA_METHODORFUNC] = TRACEDATA_METHODORFUNC_METHOD
			see "Method"
		else
			if ringvm_tracedata()[TRACEDATA_FUNCNAME] = NULL
				see "Command"
			else
				see "Function"
			ok
		ok		
		see nl + Copy("=",42) + nl

func TraceLib_Functions
	if right(ringvm_tracedata()[TRACEDATA_FILENAME],13) = "tracelib.ring"
		return 
	ok
	switch ringvm_TraceEvent() 
		on TRACEEVENT_NEWFUNC
			see "Open Func : " + 
			ringvm_TraceData()[TRACEDATA_FUNCNAME] + nl
		on TRACEEVENT_RETURN
			see "Return to Func : " + 
			ringvm_TraceData()[TRACEDATA_FUNCNAME] + nl
	off

func TraceLib_PassError
	if right(ringvm_tracedata()[TRACEDATA_FILENAME],13) = "tracelib.ring"
		return 
	ok
	switch ringvm_TraceEvent() 
		on  TRACEEVENT_ERROR
			see nl
			see "TraceLib : After Error !" + nl
			ringvm_passerror()
	off

func TraceLib_Debugger
	if right(ringvm_tracedata()[TRACEDATA_FILENAME],13) = "tracelib.ring"
		return 
	ok
	switch ringvm_TraceEvent() 
		on  TRACEEVENT_ERROR
			see nl+nl+Copy("=",50) + nl +
			"Interactive Debugger " + nl +
			"Command (Exit) : End Program" + nl +
			"Command (Cont) : Continue Execution" + nl +
			"We can execute Ring code" + nl +
			"See Locals() to print variable names" + nl +
			Copy("=",50) + nl 
			while true
				        see nl + "code:> "
					Try
					        give cCode
						if trim(lower(cCode)) = "exit" or
						   trim(lower(cCode)) = "bye"
							shutdown()
						ok	
						if trim(lower(cCode)) = "cont"
							ringvm_passerror()
							exit
						ok
						ringvm_EvalInScope(ringvm_scopescount()-1,cCode)
				        catch
				                see cCatchError
				        done
			end
	off

func TraceLib_LineByLine
	if right(ringvm_tracedata()[TRACEDATA_FILENAME],13) = "tracelib.ring" or
		ringvm_TraceEvent() != TRACEEVENT_NEWLINE
		return 
	ok
	aList = ringvm_tracedata()
	see "Before Line : " + aList[TRACEDATA_LINENUMBER] + nl +
	nl+nl+Copy("=",50) + nl +
	"Interactive Debugger - Execute Program Line by Line" + nl +
	"Command (Exit) : End Program" + nl +
	"Command (Cont) : Continue Execution" + nl +
	"We can execute Ring code" + nl +
	"See Locals() to print variable names" + nl +
	Copy("=",50) + nl 
	while true
	        see nl + "code:> "
		Try
		        give cCode
			if trim(lower(cCode)) = "exit" or
				trim(lower(cCode)) = "bye"
				shutdown()
			ok			
			if trim(lower(cCode)) = "cont"
				ringvm_passerror()
				exit
			ok
			ringvm_EvalInScope(ringvm_scopescount()-1,cCode)
	        catch
	                see cCatchError
	        done
	end

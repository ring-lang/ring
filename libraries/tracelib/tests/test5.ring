# The Ring Standard Library
# Trace Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

# Execute Program Line by Line

load "tracelib.ring"

ringvm_settrace("mytrace()")
test1()

func test1
	x = 10
	see :test1 + nl
	t = 12
	test2()
	see "After Error!" +nl
	see "t = " + t + nl
	
func mytrace
	aList = ringvm_tracedata()
	see "Before Line : " + aList[TRACEDATA_LINENUMBER] + nl +
	nl+nl+Copy("=",50) + nl +
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

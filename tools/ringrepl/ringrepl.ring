# Application  : Read-Eval-Print-Loop (REPL) - Console Application
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

? "The Ring programming language version " + version(True) 
? "REPL (Read-Eval-Print-Loop)" 
while true
        see nl + "ring:> "
        give cRingCode
	switch lower(trim(cRingCode)) {
		case "exit"
			shutdown()
		case "clear"
			if isWindows()
				system("cls")
			else 
				system("clear")
			ok
			loop
	}
        try
                eval(cRingCode)
        catch
                see cCatchError
        done
end

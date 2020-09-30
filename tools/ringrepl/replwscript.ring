# Application  : Read-Eval-Print-Loop (REPL) - GUI Application - Script
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

while true
        give cCode
        try
                eval(cCode)
        catch
                see cCatchError
        done
end

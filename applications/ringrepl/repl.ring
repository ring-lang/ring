# Application  : Read-Eval-Print-Loop (REPL) - Console Application
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

while true
        see nl + "ring:> "
        give cCode
        try
                eval(cCode)
        catch
                see cCatchError
        done
end

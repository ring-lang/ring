# Application  : Read-Eval-Print-Loop (REPL) - Console Application
# Author       : Mahmoud Fayed <msfclipper@yahoo.com>

See "The Ring programming language version " + version() + nl
See "REPL (Read-Eval-Print-Loop)" + nl
while true
        see nl + "ring:> "
        give cCode
        try
                eval(cCode)
        catch
                see cCatchError
        done
end

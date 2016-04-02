while true
        see nl + "code:> "
        give cCode
        try
                eval(cCode)
        catch
                see cCatchError
        done
end

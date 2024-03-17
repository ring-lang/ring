? number("123")
? number("123 123 123")
? number("0xa")
? number("123 0xa")
try
? number("what")
catch
? cCatchError
done

try
? number("123 what")
catch
? cCatchError
done

try
? number("123 0xa what")
catch
? cCatchError
done

? :done
# Written by Mounir IDRASSI

keyValue = hex2str("0011223344556677")
key = [:name="key", :value=keyValue]
See "keyValue length = " + Len(keyValue) + nl
See "key.value length = " + Len(key[:value]) + nl

if keyValue = key[:value] See "Test OK" + nl else See "Test Failed!!" + nl ok
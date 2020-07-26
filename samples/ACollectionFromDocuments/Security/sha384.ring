load "openssllib.ring"

see "sha384('hello') : " + sha384("hello") + nl +
    "sha384('apple') : " + sha384("apple") + nl +
    "sha384('hello world') : " + sha384("hello world") + nl

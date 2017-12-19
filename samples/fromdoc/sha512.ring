load "openssllib.ring"

see "sha512('hello') : " + sha512("hello") + nl +
    "sha512('apple') : " + sha512("apple") + nl +
    "sha512('hello world') : " + sha512("hello world") + nl

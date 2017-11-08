LoadLib("libring_pcre2.so")

match = pcre_match("[a-z]+", [1,2], "hello world")

see match

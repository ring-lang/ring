LoadLib("libring_pcre2.so")

match = pcre_match("[a-z]+", ["g", "i"], "Hello world")

see match

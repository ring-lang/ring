LoadLib("libring_pcre2.so")

match = pcre_match("[a-z]+", [], "Hello Ring")

see match

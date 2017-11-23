LoadLib("libring_murmurhash.so")

key = "Ring Language"

see "Print '" + key + "' as an integer value '" + murmurhash2(key, 0, 0) + "'" + nl
see "Print '" + key + "' as a hex value '" + murmurhash2(key, 0, 1) + "'" + nl

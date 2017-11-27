LoadLib("libring_murmurhash.so")

key = "Ring Language"

see "Print '" + key + "' as an integer value '" + murmurhash3_x64_128(key, 0, 0) + "'" + nl
see "Print '" + key + "' as a hex value '" + murmurhash3_x64_128(key, 0, 1) + "'" + nl

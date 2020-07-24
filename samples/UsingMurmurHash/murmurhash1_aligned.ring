load "murmurhashlib.ring"

key = "Ring Language"

see "Print '" + key + "' as an integer value '" + murmurhash1_aligned(key, 0, 0) + "'" + nl
see "Print '" + key + "' as a hex value '" + murmurhash1_aligned(key, 0, 1) + "'" + nl

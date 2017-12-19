load "murmurhashlib.ring"

key = "Ring Language"

see "Print '" + key + "' as an integer value '" see murmurhash3_x64_128(key, 0, 0) see "'" + nl
see "Print '" + key + "' as a hex value '" see murmurhash3_x64_128(key, 0, 1) see "'" + nl

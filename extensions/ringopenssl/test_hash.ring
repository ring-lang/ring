load "openssllib.ring"

// MD5
a = md5Init()

md5Update (a, "The quick brown fox ") and md5Update (a, "jumps over ") and md5Update (a, "the lazy dog")

digest_a = md5Final(a)
digest_b = md5("The quick brown fox jumps over the lazy dog")

digest = "9e107d9d372bb6826bd81d3542a419d6"

checkResults("MD5", digest_a, digest_b, digest)

// SHA1
a = sha1Init()
sha1Update (a, "The quick brown fox ") and sha1Update (a, "jumps over ") and sha1Update (a, "the lazy dog")

digest_a = sha1Final(a)
digest_b = sha1("The quick brown fox jumps over the lazy dog")
digest = "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12"

checkResults("SHA1", digest_a, digest_b, digest)

// SHA224
a = sha224Init()
sha224Update (a, "The quick brown fox ") and sha224Update (a, "jumps over ") and sha224Update (a, "the lazy dog")

digest_a = sha224Final(a)
digest_b = sha224("The quick brown fox jumps over the lazy dog")
digest = "730e109bd7a8a32b1cb9d9a09aa2325d2430587ddbc0c38bad911525"

checkResults("SHA224", digest_a, digest_b, digest)

// SHA256
a = sha256Init()
sha256Update (a, "The quick brown fox ") and sha256Update (a, "jumps over ") and sha256Update (a, "the lazy dog")

digest_a = sha256Final(a)
digest_b = sha256("The quick brown fox jumps over the lazy dog")
digest = "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592"

checkResults("SHA256", digest_a, digest_b, digest)

// SHA384
a = sha384Init()
sha384Update (a, "The quick brown fox ") and sha384Update (a, "jumps over ") and sha384Update (a, "the lazy dog")

digest_a = sha384Final(a)
digest_b = sha384("The quick brown fox jumps over the lazy dog")
digest = "ca737f1014a48f4c0b6dd43cb177b0afd9e5169367544c494011e3317dbf9a509cb1e5dc1e85a941bbee3d7f2afbc9b1"

checkResults("SHA384", digest_a, digest_b, digest)

// SHA512
a = sha512Init()
sha512Update (a, "The quick brown fox ") and sha512Update (a, "jumps over ") and sha512Update (a, "the lazy dog")

digest_a = sha512Final(a)
digest_b = sha512("The quick brown fox jumps over the lazy dog")
digest = "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb642e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6"

checkResults("SHA512", digest_a, digest_b, digest)

func checkResults(name, dgstMulti, dgstSingle, dgstEspected) {
	if dgstEspected != dgstMulti or dgstEspected != dgstSingle {
		? name + " Test failed!"
		? "    multi-part  = " + dgstMulti
		? "    single-part = " + dgstSingle
		? "    expected    = " + dgstEspected
	else
		? name + " Test OK"
	}
}


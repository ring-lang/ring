if iswindows()
	LoadLib("ring_openssl.dll")
but ismacosx()
	LoadLib("libring_openssl.dylib")
else
	LoadLib("libring_openssl.so")
ok

$OSSL_HASH_MD5    = 0
$OSSL_HASH_SHA1   = 1
$OSSL_HASH_SHA256 =	2
$OSSL_HASH_SHA384 =	3
$OSSL_HASH_SHA512 =	4

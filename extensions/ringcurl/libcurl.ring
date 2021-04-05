if iswindows()
	LoadLib("ring_libcurl.dll")
but ismacosx()
	LoadLib("libring_libcurl.dylib")
else
	LoadLib("libring_libcurl.so")
ok

Load "ring_libcurl.rh"

func curl_easy_setopt p1,p2,p3
	# Use CURLOPT_COPYPOSTFIELDS to avoid using deleted memory by LibCurl
		if p2 = CURLOPT_POSTFIELDS
			p2 = CURLOPT_COPYPOSTFIELDS
		ok
	if isnumber(p3)
		curl_easy_setopt_1(p1,p2,p3)
	but isstring(p3)
		curl_easy_setopt_2(p1,p2,p3)
	but ispointer(p3)
		if type(p3) = "void"
			curl_easy_setopt_3(p1,p2,p3)
		else
			curl_easy_setopt_4(p1,p2,p3)
		ok
	ok
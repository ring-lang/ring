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

func curl_getResponseCode p1
	return curl_simple_getinfo_2(p1, CURLINFO_RESPONSE_CODE)

func curl_getContentType p1
	return curl_simple_getinfo_1(p1, CURLINFO_CONTENT_TYPE)

func curl_getContentLength p1
	return curl_simple_getinfo_3(p1, CURLINFO_CONTENT_LENGTH_DOWNLOAD)

func curl_getEffectiveUrl p1
	return curl_simple_getinfo_1(p1, CURLINFO_EFFECTIVE_URL)

func curl_getRedirectUrl p1
	return curl_simple_getinfo_1(p1, CURLINFO_REDIRECT_URL)

func curl_getRedirectCount p1
	return curl_simple_getinfo_2(p1, CURLINFO_REDIRECT_COUNT)

func curl_getTotalTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_TOTAL_TIME)

func curl_getNameLookupTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_NAMELOOKUP_TIME)

func curl_getConnectTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_CONNECT_TIME)

func curl_getRequestSize p1
	return curl_simple_getinfo_2(p1, CURLINFO_REQUEST_SIZE)

func curl_getHeaderSize p1
	return curl_simple_getinfo_2(p1, CURLINFO_HEADER_SIZE)

func curl_getSpeedDownload p1
	return curl_simple_getinfo_3(p1, CURLINFO_SPEED_DOWNLOAD)

func curl_getSpeedUpload p1
	return curl_simple_getinfo_3(p1, CURLINFO_SPEED_UPLOAD)

func curl_getSSLVerifyResult p1
	return curl_simple_getinfo_2(p1, CURLINFO_SSL_VERIFYRESULT)

func curl_getPrimaryIP p1
	return curl_simple_getinfo_1(p1, CURLINFO_PRIMARY_IP)

func curl_getPrimaryPort p1
	return curl_simple_getinfo_2(p1, CURLINFO_PRIMARY_PORT)

func curl_getLocalIP p1
	return curl_simple_getinfo_1(p1, CURLINFO_LOCAL_IP)

func curl_getLocalPort p1
	return curl_simple_getinfo_2(p1, CURLINFO_LOCAL_PORT)

func curl_getContentLengthUpload p1
	return curl_simple_getinfo_3(p1, CURLINFO_CONTENT_LENGTH_UPLOAD)

func curl_getDownloadSize p1
	return curl_simple_getinfo_3(p1, CURLINFO_SIZE_DOWNLOAD)

func curl_getUploadSize p1
	return curl_simple_getinfo_3(p1, CURLINFO_SIZE_UPLOAD)

func curl_getFiletime p1
	return curl_simple_getinfo_2(p1, CURLINFO_FILETIME)

func curl_getAppConnectTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_APPCONNECT_TIME)

func curl_getContentLengthHeader p1
	return curl_simple_getinfo_3(p1, CURLINFO_CONTENT_LENGTH_DOWNLOAD)

func curl_getStartTransferTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_STARTTRANSFER_TIME)

func curl_getPreTransferTime p1
	return curl_simple_getinfo_3(p1, CURLINFO_PRETRANSFER_TIME)

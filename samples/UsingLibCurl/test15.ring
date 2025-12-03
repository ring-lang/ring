# libcurl error messages demo in Ring

load "libcurl.ring"

? "Testing curl_easy_strerror..." + nl
? "CURLE_OK (0): " + curl_easy_strerror(CURLE_OK)
? "CURLE_AGAIN (81): " + curl_easy_strerror(CURLE_AGAIN)
? "CURLE_COULDNT_CONNECT (7): " + curl_easy_strerror(7)

? "Testing curl_multi_strerror..." + nl
? "CURLM_OK (0): " + curl_multi_strerror(CURLM_OK)
? "CURLM_BAD_HANDLE (2): " + curl_multi_strerror(CURLM_BAD_HANDLE)
? "CURLM_OUT_OF_MEMORY (3): " + curl_multi_strerror(CURLM_OUT_OF_MEMORY)

? nl + "Done!"
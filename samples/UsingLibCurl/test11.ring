load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example - RingLibCurl Info Helper Functions"
? copy("-", 60)

curl = curl_easy_init()
    
curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt(curl, CURLOPT_USERAGENT, "RingLibCurl")
curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1)
curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0)
        
? "Performing request..."
response = curl_easy_perform_silent(curl)

? "RESPONSE CONTENT:"
? copy("-", 18)
? response
? copy("-", 18)
? "CONNECTION INFO:"

? "Response Code: " + curl_getResponseCode(curl)
? "Content Type: " + curl_getContentType(curl)
? "Content Length: " + curl_getContentLength(curl)
? "Effective URL: " + curl_getEffectiveUrl(curl)
? "Redirect URL: " + curl_getRedirectUrl(curl)
? "Redirect Count: " + curl_getRedirectCount(curl)

? copy("-", 18)
? "TIMING INFO:" 
? "Total Time: " + curl_getTotalTime(curl) + " seconds"
? "Name Lookup Time: " + curl_getNameLookupTime(curl) + " seconds"
? "Connect Time: " + curl_getConnectTime(curl) + " seconds"
? "App Connect Time: " + curl_getAppConnectTime(curl) + " seconds"
? "Pre-Transfer Time: " + curl_getPreTransferTime(curl) + " seconds"
? "Start Transfer Time: " + curl_getStartTransferTime(curl) + " seconds"

? copy("-", 18)
? "SIZE INFO:"
? "Request Size: " + curl_getRequestSize(curl) + " bytes"
? "Header Size: " + curl_getHeaderSize(curl) + " bytes"
? "Download Size: " + curl_getDownloadSize(curl) + " bytes"
? "Upload Size: " + curl_getUploadSize(curl) + " bytes"
? "Content Length Upload: " + curl_getContentLengthUpload(curl) + " bytes"
? "Content Length Header: " + curl_getContentLengthHeader(curl) + " bytes"

? copy("-", 18)
? "SPEED INFO:"
? "Download Speed: " + curl_getSpeedDownload(curl) + " bytes/second"
? "Upload Speed: " + curl_getSpeedUpload(curl) + " bytes/second"

? copy("-", 18)
? "SERVER INFO:"
? "Primary IP: " + curl_getPrimaryIP(curl)
? "Primary Port: " + curl_getPrimaryPort(curl)
? "Local IP: " + curl_getLocalIP(curl)
? "Local Port: " + curl_getLocalPort(curl)

? copy("-", 18)
? "SSL INFO:"

? "SSL Verify Result: " + curl_getSSLVerifyResult(curl)

? copy("-", 18)
? "FILE INFO:"
? "File Time: " + curl_getFiletime(curl)
? copy("-", 18) + nl

curl_easy_cleanup(curl)

? "Done!"
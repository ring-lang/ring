load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example (Using curl_simple_getinfo_2)"
? copy("-", 60)

curl = curl_easy_init()
    
curl_easy_setopt_2(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt_2(curl, CURLOPT_USERAGENT, "RingLibCurl")
        
response = curl_easy_perform_silent(curl)
? "Response Content:" + nl + response + nl

responseCode = curl_simple_getinfo_2(curl, CURLINFO_RESPONSE_CODE)

? "HTTP Response Code: " + responseCode

numConnects = curl_simple_getinfo_2(curl, CURLINFO_NUM_CONNECTS)
? "Number of connections: " + numConnects + nl
	
curl_easy_cleanup(curl)

? "Done!"
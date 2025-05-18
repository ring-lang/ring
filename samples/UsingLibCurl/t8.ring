load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example (Using curl_simple_getinfo_1)"
? copy("-", 60)

curl = curl_easy_init()

curl_easy_setopt_2(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt_2(curl, CURLOPT_USERAGENT, "RingLibCurl")

response = curl_easy_perform_silent(curl)
? "Response Content:" + nl + response + nl

effectiveUrl = curl_simple_getinfo_1(curl, CURLINFO_EFFECTIVE_URL)
? "Effective URL: " + effectiveUrl

contentType = curl_simple_getinfo_1(curl, CURLINFO_CONTENT_TYPE)
? "Content Type: " + contentType  + nl

curl_easy_cleanup(curl)

? "Done!"
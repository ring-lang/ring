load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example (Using curl_simple_getinfo_3)"
? copy("-", 60)

curl = curl_easy_init()

curl_easy_setopt_2(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt_2(curl, CURLOPT_USERAGENT, "RingLibCurl")

response = curl_easy_perform_silent(curl)
? "Response Content:" + nl + response + nl

result = curl_simple_getinfo_3(curl, CURLINFO_TOTAL_TIME)

? "Total time: " + result + " seconds" + nl

curl_easy_cleanup(curl)

? "Done!"
load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example (Using curl_easy_getinfo_2)"
? copy("-", 60)

curl = curl_easy_init()
    
curl_easy_setopt_2(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt_2(curl, CURLOPT_USERAGENT, "RingLibCurl")
        
response = curl_easy_perform_silent(curl)
? "Response Content:" + nl + response + nl
        
cMemory = space(8)
for i = 1 to 8
    cMemory[i] = char(0)
next
pCode = varptr(:cMemory, "long")

curl_easy_getinfo_2(curl, CURLINFO_RESPONSE_CODE, pCode)
        
responseCode = 0
for i = 1 to 4
    responseCode = responseCode | (ascii(cMemory[i]) << ((i-1)*8))
next
        
? "HTTP Response Code: " + responseCode
        
cMemory = space(8)
pCode = varptr(:cMemory, "long")

curl_easy_getinfo_2(curl, CURLINFO_NUM_CONNECTS, pCode)
        
numConnects = 0
for i = 1 to 4
    numConnects = numConnects | (ascii(cMemory[i]) << ((i-1)*8))
next
        
? "Number of connections: " + numConnects + nl
        
curl_easy_cleanup(curl)

? "Done!"
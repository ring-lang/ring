load "libcurl.ring"

? copy("-", 60)
? "RingLibCurl Example (Using curl_easy_getinfo_1)"
? copy("-", 60)

curl = curl_easy_init()

curl_easy_setopt_2(curl, CURLOPT_URL, "https://httpbin.org/get")
curl_easy_setopt_2(curl, CURLOPT_USERAGENT, "RingLibCurl")

response = curl_easy_perform_silent(curl)
? "Response Content:" + nl + response + nl

cMemoryUrl = space(8)
pUrl = varptr(:cMemoryUrl, "char")

curl_easy_getinfo_1(curl, CURLINFO_EFFECTIVE_URL, pUrl)

url = safePointer2String(pUrl)
? "Effective URL: " + url

cMemoryType = space(8)
pType = varptr(:cMemoryType, "char")

curl_easy_getinfo_1(curl, CURLINFO_CONTENT_TYPE, pType)

contentType = safePointer2String(pType)
? "Content Type: " + contentType + nl

curl_easy_cleanup(curl)

? "Done!"

# Function to safely convert a pointer to a string
func safePointer2String(pString)
    for bufSize = 64 to 2048 step 64
        result = pointer2string(pString, 0, bufSize)

        nullPos = 0
        for i = 1 to len(result)
            if ascii(result[i]) = 0
                nullPos = i
                exit
            ok
        next
        
        if nullPos > 0
            return left(result, nullPos-1)
        ok
    next
    
    return left(pointer2string(pString, 0, 256), 256)

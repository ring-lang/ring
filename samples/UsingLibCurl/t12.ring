load "libcurl.ring"

global_init = curl_global_init(CURL_GLOBAL_DEFAULT)

if global_init = 0
	see "curl_global_init() failed" + nl
	bye
ok

multi_handle = curl_multi_init()

if multi_handle = NULL
	see "curl_multi_init() failed" + nl
	bye
ok

easy_handle1 = curl_easy_init()
easy_handle2 = curl_easy_init()
easy_handle3 = curl_easy_init()

curl_easy_setopt_2(easy_handle1, CURLOPT_URL, "http://ip-api.com/json/")
curl_easy_setopt_2(easy_handle2, CURLOPT_URL, "https://api.ipapi.is/")
curl_easy_setopt_2(easy_handle3, CURLOPT_URL, "https://api.ipquery.io/")

curl_multi_add_handle(multi_handle, easy_handle1)
curl_multi_add_handle(multi_handle, easy_handle2)
curl_multi_add_handle(multi_handle, easy_handle3)

running_handles = 1

while running_handles > 0
	multi_perform_result = curl_multi_perform(multi_handle)
	running_handles = multi_perform_result[2]
	if running_handles > 0
		curl_multi_wait(multi_handle, 1000)
	ok
end

curl_multi_remove_handle(multi_handle, easy_handle1)
curl_multi_remove_handle(multi_handle, easy_handle2)
curl_multi_remove_handle(multi_handle, easy_handle3)

curl_easy_cleanup(easy_handle1)
curl_easy_cleanup(easy_handle2)
curl_easy_cleanup(easy_handle3)

curl_multi_cleanup(multi_handle)

curl_global_cleanup()

? nl + "Multi Perform test completed successfully!" + nl

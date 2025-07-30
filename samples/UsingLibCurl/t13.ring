load "libcurl.ring"

global_init = curl_global_init(CURL_GLOBAL_DEFAULT)

if global_init = 0
	see "curl_global_init() failed" + nl
	bye
ok

easy_handle = curl_easy_init()

if easy_handle = NULL
	see "curl_easy_init() failed" + nl
	bye
ok

curl_easy_setopt_2(easy_handle, CURLOPT_URL, "wss://echo.websocket.events")
curl_easy_setopt_1(easy_handle, CURLOPT_CONNECT_ONLY, 2)

curl_easy_perform(easy_handle)

see "WebSocket connection established." + nl

sent_result = curl_ws_send(easy_handle, "Hello, Ring!", 0, CURLWS_TEXT)
if sent_result[1] != CURLE_OK
	see "curl_ws_send() failed" + nl
else
	see "Sent 'Hello, Ring!' to the server." + nl
ok

recv_result = curl_ws_recv(easy_handle, 1024)
if recv_result[1] != CURLE_OK and recv_result[1] != CURLE_AGAIN
	see "curl_ws_recv() failed" + nl
else
	see "Received: " + recv_result[2] + nl
ok

curl_easy_cleanup(easy_handle)
curl_global_cleanup()

see "WebSocket test completed successfully!" + nl

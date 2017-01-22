load "libcurl.ring"

curl = curl_easy_init()

cPostthis = "page=4&Number1=4&Number2=5"
curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/ringapp/index.ring?page=3")
curl_easy_setopt(curl, CURLOPT_POSTFIELDS, cPostthis)

res = curl_easy_perform(curl)

curl_easy_cleanup(curl)


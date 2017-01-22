load "libcurl.ring"

curl = curl_easy_init()

curl_easy_setopt_1(curl, CURLOPT_FOLLOWLOCATION, 1)
curl_easy_setopt_2(curl, CURLOPT_URL, "http://ring-lang.sf.net")

res = curl_easy_perform(curl)

curl_easy_cleanup(curl)

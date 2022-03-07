/*
	According to my tests 
	Using the InternetLib which is based on LibCurl is faster than using the httplib
	Try: test3_test.ring
	Note: LibCurl is written in C, while httplib is written in C++
*/

load "httplib.ring"

new Client("localhost:8080") {
	? download("/one")
	? download("/two")
}

# cURL callbacks demo in Ring

load "libcurl.ring"

totalBytes = 0
chunkCount = 0
headerCount = 0
progressCalls = 0
uploadData = ""
uploadPos = 0
readCalls = 0

func main
	? copy("=", 50)
	? "Testing cURL Callbacks"
	? copy("=", 50)
	
	# Test 1: CURLOPT_WRITEFUNCTION
	test_write_callback()
	
	# Test 2: CURLOPT_HEADERFUNCTION
	test_header_callback()
	
	# Test 3: CURLOPT_XFERINFOFUNCTION (Progress callback)
	test_progress_callback()
	
	# Test 4: CURLOPT_READFUNCTION
	test_read_callback()
	
	? copy("=", 50)
	? "Done!"
	? copy("=", 50)


# Test 1: Write Callback - Receives response body data
func test_write_callback
	? "Test 1: CURLOPT_WRITEFUNCTION (Write Callback)"
	? copy("-", 50)
	
	# Reset counters
	totalBytes = 0
	chunkCount = 0
	
	curl = curl_easy_init()
	curl_easy_setopt(curl, CURLOPT_URL, "https://ring-lang.net")
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, :write_callback)
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1)
	curl_easy_perform(curl)
	curl_easy_cleanup(curl)
	
	? "Total chunks received: " + chunkCount
	? "Total bytes received: " + totalBytes

func write_callback
	cData = curl_get_data()
	chunkCount++
	totalBytes += len(cData)
	? "  Chunk #" + chunkCount + ": " + len(cData) + " bytes"

# Test 2: Header Callback - Receives HTTP headers
func test_header_callback
	? "Test 2: CURLOPT_HEADERFUNCTION (Header Callback)"
	? copy("-", 50)
	
	# Reset counter
	headerCount = 0
	
	curl = curl_easy_init()
	curl_easy_setopt(curl, CURLOPT_URL, "https://ring-lang.net")
	curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, :header_callback)
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1)
	curl_easy_setopt(curl, CURLOPT_NOBODY, 1)  # HEAD request for headers only
	curl_easy_perform(curl)
	curl_easy_cleanup(curl)
	
	? "Total headers received: " + headerCount

func header_callback
	cData = curl_get_data()
	headerCount++
	# Trim whitespace and show non-empty headers
	header = trim(cData)
	if len(header) > 0
		? "  Header #" + headerCount + ": " + header
	ok

# Test 3: Progress Callback - Monitors transfer progress
func test_progress_callback
	? "Test 3: CURLOPT_XFERINFOFUNCTION (Progress Callback)"
	? copy("-", 50)
	
	# Reset counter
	progressCalls = 0
	
	curl = curl_easy_init()
	curl_easy_setopt(curl, CURLOPT_URL, "https://ring-lang.net")
	curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, :progress_callback)
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1)
	curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0)  # Enable progress
	curl_easy_perform(curl)
	curl_easy_cleanup(curl)
	
	? "Total progress callbacks: " + progressCalls

func progress_callback
	progressCalls++
	aInfo = curl_get_progress_info()
	dltotal = aInfo[1]
	dlnow = aInfo[2]
	ultotal = aInfo[3]
	ulnow = aInfo[4]
	
	# Show progress every 10 calls to avoid spam
	if progressCalls % 10 = 0 or dltotal > 0
		? "  Progress: DL=" + dlnow + "/" + dltotal + 
			" UL=" + ulnow + "/" + ultotal
	ok
	
	# Return 0 to continue, non-zero to abort
	curl_set_progress_result(0)

# Test 4: Read Callback - Provides data for upload
func test_read_callback
	? "Test 4: CURLOPT_READFUNCTION (Read Callback)"
	? copy("-", 50)
	
	# Reset and prepare test data to upload
	uploadData = "This is test data from Ring libcurl read callback!"
	uploadPos = 0
	readCalls = 0
	
	curl = curl_easy_init()
	# Using httpbin.org for testing POST
	curl_easy_setopt(curl, CURLOPT_URL, "https://postman-echo.com/put")
	curl_easy_setopt(curl, CURLOPT_UPLOAD, 1)
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, :read_callback)
	curl_easy_setopt(curl, CURLOPT_INFILESIZE, len(uploadData))
	
	# Capture response
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, :read_test_write_callback)
	
	? "Uploading data: '" + uploadData + "'"
	curl_easy_perform(curl)
	curl_easy_cleanup(curl)
	
	? "Total read callbacks: " + readCalls

func read_callback
	readCalls++
	
	# Calculate how much data is left to send
	remaining = len(uploadData) - uploadPos
	
	if remaining > 0
		# Send data in chunks (simulate streaming)
		chunkSize = 16  # Send 16 bytes at a time
		if remaining < chunkSize
			chunkSize = remaining
		ok
		
		# Get the chunk to send
		chunk = substr(uploadData, uploadPos + 1, chunkSize)
		uploadPos += chunkSize
		
		? "  Read callback #" + readCalls + ": Sending " + 
			chunkSize + " bytes (pos: " + uploadPos + "/" + len(uploadData) + ")"
		
		# Provide the data to curl
		curl_set_read_data(chunk)
	else
		? "  Read callback #" + readCalls + ": Upload complete (EOF)"
		# Return empty string to signal EOF
		curl_set_read_data("")
	ok

func read_test_write_callback
	# Capture the response data
	cData = curl_get_data()
	# Show the response data
	? cData
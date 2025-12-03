# OpenRouter API Request demo in Ring
# Using RingLibCurl and JSONLib

load "libcurl.ring"
load "jsonlib.ring"

cBuffer = ""

func main
	cAPIKey = "YOUR_OPENROUTER_API_KEY" # Get your API key from https://openrouter.ai/settings/keys
	
	if cAPIKey = "YOUR_OPENROUTER_API_KEY"
		? "Please replace `YOUR_OPENROUTER_API_KEY` with your actual API key!"
		? "You can get your API key from 'https://openrouter.ai/settings/keys'"
		return
	ok

	url = "https://openrouter.ai/api/v1/chat/completions" # OpenRouter API endpoint
	cModel = "x-ai/grok-4.1-fast:free" # Choose a model from https://openrouter.ai/models

	cJson = `{
		"model": "` + cModel + `",
		"messages": [
			{
				"role": "user",
				"content": "Do you know the Ring Programming Language?"
			}
		],
		"reasoning": {
			"enabled": true
		},
		"stream": true
	}`

	curl = curl_easy_init()
	
	if isWindows()
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0)
	ok

	curl_easy_setopt(curl, CURLOPT_URL, url)
	
	# Headers
	list = curl_slist_append(NULL, "Content-Type: application/json")
	list = curl_slist_append(list, "Authorization: Bearer " + cAPIKey)
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list)

	# Post Data
	curl_easy_setopt(curl, CURLOPT_POST, 1)
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, cJson)

	# Callback for streaming
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, :mycallback)

	? "Sending OpenRouter request..." + nl
	curl_easy_perform(curl)
	curl_easy_cleanup(curl)

func mycallback
	cData = curl_get_data()
	cBuffer += cData
	
	while substr(cBuffer, nl) > 0
		nPos = substr(cBuffer, nl)
		line = left(cBuffer, nPos - 1)
		cBuffer = substr(cBuffer, nPos + 1)
		
		line = trim(line)
		
		# Skip empty lines and [DONE] messages
		if line = "" or substr(line, "data: [DONE]") > 0
			loop
		ok
		
		# Extract JSON from "data: {...}"
		if substr(line, "data: ") > 0
			jsonStr = substr(line, "data: ", "")
			jsonStr = trim(jsonStr)
			
			if jsonStr != ""
				try
					data = json2list(jsonStr)
					# Check if content exists before accessing it
					if islist(data) and len(data["choices"]) > 0
						choice = data["choices"][1]
						if isstring(choice["delta"]["content"])
							see choice["delta"]["content"]
						ok
						# Check for reasoning content if available (some models use reasoning_content)
						if choice["delta"]["reasoning_content"] != NULL
							 see choice["delta"]["reasoning_content"]
						ok
					ok
				catch
					? cCatchError
				done
			ok
		ok
	end
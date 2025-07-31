# Discord Bot in Ring using libcurl WebSockets, multi interface, and threads.
# Connects to Discord Gateway, handles events, and responds to messages.
# Author: Youssef Saeed (ysdragon) <youssefelkholey@gmail.com>

# Load necessary libraries
load "libcurl.ring"
load "stdlibcore.ring"
load "jsonlib.ring"
load "threads.ring"
load "constants.ring"

# Global variables for Discord connection state
nHeartbeatInterval = 0           # Heartbeat interval (seconds)
nLastHeartbeatTime = 0           # Last heartbeat timestamp
nLastSequence = NULL             # Last received sequence number
lIsConnected = FALSE             # Connection status
gFrameBuffer = NULL              # Buffer for reassembling fragmented WebSocket frames

#Global Handles and Thread Safety
pCurl = NULL                     # Main cURL easy handle for WebSocket
pMulti = NULL                    # cURL multi handle for async operations
gBotMutex = new_mtx_t()          # Mutex for synchronizing shared state

# Main Bot Logic
# Entry point: initializes cURL, connects to Discord Gateway, and starts event loop thread.
func main
	see "Starting Discord Bot with libcurl.ring and threads..." + nl
	curl_global_init(CURL_GLOBAL_DEFAULT)     # Initialize cURL library
	mtx_init(gBotMutex, mtx_plain)            # Initialize mutex for thread safety

	pCurl = curl_easy_init()                  # Create cURL easy handle
	pMulti = curl_multi_init()                # Create cURL multi handle

	if pCurl = NULL or pMulti = NULL
		see "Fatal: Could not initialize cURL handles." + nl
		bye
	ok

	curl_multi_add_handle(pMulti, pCurl)      # Add easy handle to multi handle

	see "Configuring WebSocket connection to: " + GATEWAY_URL + nl
	curl_easy_setopt(pCurl, CURLOPT_URL, GATEWAY_URL)         # Set Discord Gateway URL
	curl_easy_setopt(pCurl, CURLOPT_CONNECT_ONLY, 2)          # Enable connect-only mode for WebSocket

	# Perform the initial connection and handshake with Discord Gateway
	nStillRunning = 1
	while nStillRunning > 0
		aPerformResult = curl_multi_perform(pMulti)
		if aPerformResult[1] != CURLM_OK
			see "[FATAL] Handshake perform failed. Code: " + aPerformResult[1] + nl
			cleanup()
			bye
		ok
		nStillRunning = aPerformResult[2]
	end

	see "[INFO] WebSocket handshake successful! Waiting for HELLO..." + nl
	lIsConnected = true
	
	# Spawn a thread for the WebSocket event loop (handles all Discord events)
	see "[INFO] Spawning WebSocket event loop thread..." + nl
	pThread = new_thrd_t()
	thrd_create(pThread, websocket_event_loop(pCurl, pMulti))

	nThreadResult = 0
	thrd_join(pThread, :nThreadResult)        # Wait for event loop thread to finish
	see "[INFO] Event loop thread has finished." + nl

	cleanup()                                # Clean up resources on exit

# Thread's Main Function: Handles all incoming/outgoing WebSocket traffic and Discord events
func websocket_event_loop(pCurlPtr, pMultiPtr)
	# Local copies of cURL handles for this thread
	pLocalCurl = pCurlPtr
	pLocalMulti = pMultiPtr
	 
	lLocalIsConnected = true
	 
	while lLocalIsConnected
		curl_multi_perform(pLocalMulti)   # Perform async network operations

		# Receive WebSocket data (large buffer for Discord frames)
		aRecvData = curl_ws_recv(pLocalCurl, 65536)
		nRecvResult = aRecvData[1]

		if nRecvResult = CURLE_OK
			# Append received chunk to the global buffer (thread-safe)
			mtx_lock(gBotMutex)
			gFrameBuffer += aRecvData[2]
			mtx_unlock(gBotMutex)
			
			pMeta = aRecvData[4]
			nBytesLeft = pMeta[4]

			# Only process the frame if it's complete (bytesleft is 0)
			if nBytesLeft = 0
				mtx_lock(gBotMutex)
				cPayloadToProcess = gFrameBuffer
				gFrameBuffer = "" # Clear buffer for next message
				mtx_unlock(gBotMutex)

				if len(cPayloadToProcess) > 0
					handle_gateway_frame(pLocalCurl, cPayloadToProcess)  # Parse and handle Discord event
				ok
			ok
		but nRecvResult != CURLE_AGAIN
			# Connection error: mark as disconnected and exit loop
			see "[FATAL] Main loop connection error. Code: " + nRecvResult + nl
			mtx_lock(gBotMutex)
			lIsConnected = false
			mtx_unlock(gBotMutex)
		ok
		
		check_multi_messages(pLocalMulti)  # Check for completed transfers/errors

		# Heartbeat logic: send heartbeat at required interval
		mtx_lock(gBotMutex)
		if lIsConnected and nHeartbeatInterval > 0 and (epochtime(date(), time()) - nLastHeartbeatTime) >= nHeartbeatInterval
			mtx_unlock(gBotMutex)
			send_heartbeat(pLocalCurl)
		else
			mtx_unlock(gBotMutex)
		ok
		
		curl_multi_wait(pLocalMulti, 100)  # Wait for network events
		
		# Update local connection status from global state
		mtx_lock(gBotMutex)
		lLocalIsConnected = lIsConnected
		mtx_unlock(gBotMutex)
	end
	
	see "[THREAD] Exiting event loop." + nl
	thrd_exit(0)


# Helper Functions

# Cleanup resources and handles before exiting
func cleanup()
	see "Bot shutting down." + nl
	if pMulti != NULL and pCurl != NULL
		curl_multi_remove_handle(pMulti, pCurl)
	ok
	if pCurl != NULL
		curl_easy_cleanup(pCurl) 
	ok
	if pMulti != NULL
		curl_multi_cleanup(pMulti)
	ok
	curl_global_cleanup()
	mtx_destroy(gBotMutex)


# Check for completed cURL transfers and handle errors
func check_multi_messages(pMulti)
	while true
		aMessage = curl_multi_info_read(pMulti)
		if len(aMessage) <= 1
			break
		ok
		if aMessage[1] = CURLMSG_DONE and aMessage[3] != CURLE_OK
			see "[FATAL] Unexpected termination. CURLcode: " + aMessage[3] + nl
			mtx_lock(gBotMutex) 
			lIsConnected = false
			mtx_unlock(gBotMutex)
		ok
	end

# Parse and handle a single Discord Gateway frame (JSON event)
func handle_gateway_frame(pCurl, cJsonPayload)
	try
		aPayload = json2list(cJsonPayload)
	catch
		see "[WARN] Failed to parse JSON: " + cJsonPayload + nl
		return
	done

	# Update sequence number and extract opcode
	mtx_lock(gBotMutex)
	if isnumber(aPayload["s"])
		nLastSequence = aPayload["s"]
	ok
	nOpcode = aPayload["op"]
	mtx_unlock(gBotMutex)

	# Handle Discord Gateway opcodes/events
	switch nOpcode
		on DISCORD_OP_HELLO
			# Received HELLO: set heartbeat interval and identify
			mtx_lock(gBotMutex)
			nHeartbeatInterval = number(aPayload[:d][:heartbeat_interval]) / 1000
			mtx_unlock(gBotMutex)
			see "[INFO] Received HELLO. Heartbeat interval: " + nHeartbeatInterval + " seconds." + nl
			identify(pCurl)
			send_heartbeat(pCurl)

		on DISCORD_OP_HEARTBEAT_ACK
			# Heartbeat acknowledged by Discord
			see "[DEBUG] Heartbeat Acknowledged." + nl

		on DISCORD_OP_DISPATCH
			# Handle specific Discord events (READY, MESSAGE_CREATE, etc.)
			cEventName = aPayload["t"]
			aEventData = aPayload["d"]
			if cEventName = "READY"
				see "[INFO] Bot is READY! Logged in as: " + aEventData["user"]["username"] + nl
			but cEventName = "MESSAGE_CREATE"
				handle_message_create(pCurl, aEventData)
			ok
			
		on DISCORD_OP_RECONNECT
			# Discord requests reconnect: mark as disconnected
			see "[INFO] Server requested reconnect. Closing connection." + nl
			mtx_lock(gBotMutex)
			lIsConnected = false
			mtx_unlock(gBotMutex)
	off

# Send a heartbeat frame to Discord Gateway to keep the connection alive
func send_heartbeat(pCurl)
	mtx_lock(gBotMutex)
	nLastHeartbeatTime = epochtime(date(), time())
	cPayload = list2json([ :op = DISCORD_OP_HEARTBEAT, :d = nLastSequence ])
	mtx_unlock(gBotMutex)
	
	see "[INFO] Sending Heartbeat (Sequence: " + nLastSequence + ")..." + nl
	aResult = curl_ws_send(pCurl, cPayload, 0, CURLWS_TEXT)
	if aResult[1] != CURLE_OK
		see "[WARN] Failed to send heartbeat." + nl
	ok

# Send IDENTIFY payload to Discord to authenticate the bot session
func identify(pCurl)
	see "[INFO] Sending IDENTIFY payload..." + nl
	aPayload = [
		:op = DISCORD_OP_IDENTIFY,
		:d = [ 
			:token = BOT_TOKEN,
			:intents = 33281,
			:properties = [ :os = "linux", :browser = "ring-libcurl", :device = "ring-libcurl" ] 
		]
	]
	aResult = curl_ws_send(pCurl, list2json(aPayload), 0, CURLWS_TEXT)
	if aResult[1] != CURLE_OK
		see "[WARN] Failed to send identify payload." + nl
	ok

# Handle a MESSAGE_CREATE event from Discord (respond to user messages)
func handle_message_create(pCurl, aMessage)
	# Ignore messages from bots (including itself) or commands not starting with '!'
	if islist(aMessage["author"]) and not isNull(aMessage["author"]["bot"]) or substr(aMessage["content"], 1, 1) != "!"
		return
	ok

	cContent = aMessage["content"]
	cChannelId = aMessage["channel_id"]
	cAuthorId = aMessage["author"]["id"]
	
	switch cContent
		on "!hello"
			see "[COMMAND] Received !hello from " + aMessage["author"]["username"] + nl
			send_reply(cChannelId, cAuthorId, "Hello from a Ring bot!")
		on "!ring"
			see "[COMMAND] Received !ring from " + aMessage["author"]["username"] + nl
			cMessage = "Hello, I'm a bot made with Ring!\nRing is awesome!"
			send_reply(cChannelId, cAuthorId, cMessage)
		on "!version"
			see "[COMMAND] Received !version from " + aMessage["author"]["username"] + nl
			cVersion = "Ring version: " + version(1)
			send_reply(cChannelId, cAuthorId, cVersion)
		other
			send_reply(cChannelId, cAuthorId, "Unknown command!")
			see "[COMMAND] Unrecognized command: " + cContent + " from " + aMessage["author"]["username"] + nl
	off

# Send a reply message to a Discord channel, mentioning the user
func send_reply(cChannelId, cUserId, cMessage)
	see "[ACTION] Sending reply to user " + cUserId + " in channel " + cChannelId + nl
	pCurlSend = curl_easy_init()
	cUrl = "https://discord.com/api/v10/channels/" + cChannelId + "/messages"
	cAuth = "Authorization: Bot " + BOT_TOKEN
	cType = "Content-Type: application/json"
	aHeaders = curl_slist_append(NULL, cAuth)
	aHeaders = curl_slist_append(aHeaders, cType)
	cMention = "<@" + cUserId + ">"
	cBody = list2json([
		:content = cMention + " " + cMessage,
		:allowed_mentions = [:parse = [],
			:users = [
				cUserId
			]
		]
	])
	curl_easy_setopt(pCurlSend, CURLOPT_URL, cUrl)
	curl_easy_setopt(pCurlSend, CURLOPT_HTTPHEADER, aHeaders)
	curl_easy_setopt(pCurlSend, CURLOPT_POST, 1)
	curl_easy_setopt(pCurlSend, CURLOPT_POSTFIELDS, cBody)
	curl_easy_setopt(pCurlSend, CURLOPT_TIMEOUT, 10)
	curl_easy_perform_silent(pCurlSend)
	curl_easy_cleanup(pCurlSend)
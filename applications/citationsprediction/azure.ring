#=====================================================#
# Citations Prediction Application
# 2022, Mahmoud Fayed <msfclipper@yahoo.com>
# Form/Window Controller - Source Code File
#=====================================================#

load "stdlibcore.ring"
load "libcurl.ring"
load "jsonlib.ring"

if isMainSourceFile() { 
	oAzure = new Azure
	{
		? setPaperTitle("test")
		? setPaperAbstract("test")
		? setPaperAuthors("test")
	}
} 

class azure

	cURL
	cApiKey
	cTemplate
	cOutput
	cPara

	func setPaperTitle cTitle { 
		cPara = cTitle
		predictUsingTitle()
		predict()
		if  NOT trim(cOutput) = NULL { 
			try { 
				aList = json2list(cOutput)
				return process(aList[1][2][1][2][1]["Scored Label Mean"])
			Catch 
			} 
		} 
		return "Can't connect to the Model to predict Total Citations using Title"
	} 

	func setPaperAbstract cAbstract { 
		cPara = cAbstract
		predictUsingAbstract()
		predict()
		if  NOT trim(cOutput) = NULL { 
			try { 
				aList = json2list(cOutput)
				return process(aList[1][2][1][2][1]["Scored Labels"])
			Catch 
			} 
		} 
		return "Can't connect to the Model to predict Total Citations using Abstract"
	} 

	func setPaperAuthors cAuthors { 
		cPara = cAuthors
		predictUsingAuthors()
		predict()
		if  NOT trim(cOutput) = NULL { 
			try { 
				aList = json2list(cOutput)
				return process(aList[1][2][1][2][1]["Scored Labels"])
			Catch 
			} 
		} 
		return "Can't connect to the Model to predict Total Citations using Authors"
	} 

	func process cString { 
		if isString(cString) { 
			nPos = substr(cString,".")
			if nPos  { 
				cString = left(cString,nPos-1)
			}
		}
		return cString 
	} 

	func predictUsingTitle  { 
		cURL = "https://ussouthcentral.services.azureml.net/workspaces/17231e072b8a49e5b5cfd5d9483e6702/services/b76cb195e9ee4870a94712ccad4c39f8/execute?api-version=2.0&format=swagger"
		cApiKey = "4ciwKcVE1KTJQLpByspeTRYgcHBsYeWT+RY62K/gL1TT0rTfPxf1wl9SkCBhQhgP8kKi5QB6bz5KqUoTzeZk9Q=="
		cTemplate = '{"Inputs": {"input1": [{"TI": "#{f1}", "TC": ""}]}, "GlobalParameters": {}}'
	} 

	func predictUsingAbstract  { 
		cURL = "https://ussouthcentral.services.azureml.net/workspaces/17231e072b8a49e5b5cfd5d9483e6702/services/7a2245fcebdc402b93584690af1381d6/execute?api-version=2.0&format=swagger"
		cApiKey = "9bbvRgUmuZ7hxv2VwCuB+KB2HNhii/dEnaJP0ynEIRi2GnPkYToGAW+iawp5bJRnGerGVzWLdX9ECX1N7IUoCA=="
		cTemplate = '{"Inputs": {"input1": [{"AB": "#{f1}", "TC": ""}]}, "GlobalParameters": {}}'
	} 

	func predictUsingAuthors  { 
		cURL = "https://ussouthcentral.services.azureml.net/workspaces/17231e072b8a49e5b5cfd5d9483e6702/services/2841ddcc04a2472ba67390c3c6859a3a/execute?api-version=2.0&format=swagger"
		cApiKey = "LUPTeiOiWUjhvvXuz6XcRjfmDl1yw77Jb85JherIvZBzTP8VKR9TM28MZcpdJSCCwvg1W8YRLRS864DF6bxX6Q=="
		cTemplate = '{"Inputs": {"input1": [{"AU": "#{f1}", "TC": ""}]}, "GlobalParameters": {}}'
	} 

	func predict  { 
		cPara  = substr(cPara,'"',"")
		cBody = substr(cTemplate,"#{f1}",cPara)
		pCurl = curl_easy_init()
		curl_easy_setopt(pCurl, CURLOPT_USERAGENT, "curl/7.54.1" )
		curl_easy_setopt(pCurl,CURLOPT_POST,1)
		curl_easy_setopt(pCurl,CURLOPT_USERAGENT,"Ring")
		curl_easy_setopt(pCurl,CURLOPT_SSL_VERIFYPEER,FALSE)
		curl_easy_setopt(pCurl,CURLOPT_SSL_VERIFYHOST,2)
		# Header
		pCurlList = curl_slist_append(null,"accept-encoding: identity")
		pCurlList = curl_slist_append(pCurlList,"authorization: Bearer "+cApiKey)
		pCurlList = curl_slist_append(pCurlList,"connection: close")
		pCurlList = curl_slist_append(pCurlList,"content-length: "+len(cBody))
		pCurlList = curl_slist_append(pCurlList,"content-type: application/json")
		curl_easy_setopt(pCurl,CURLOPT_HTTPHEADER,pCurlList)
		# Website
		curl_easy_setopt(pCurl,CURLOPT_URL,cURL)
		# Body
		curl_easy_setopt(pCurl,CURLOPT_POSTFIELDS,cBody)
		cOutput = curl_easy_perform_silent(pCurl)
	} 

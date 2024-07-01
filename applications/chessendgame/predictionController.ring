load "libcurl.ring"
load "predictionView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:predictionController)
		exec()
	}
}

class predictionController from windowsControllerParent

	oView = new predictionView

	oView { 
		txtWKF.setText("a")
		txtWKR.setText("1")
		txtWRF.setText("b")
		txtWRR.setText("3")
		txtBKF.setText("c")
		txtBKR.setText("2")
		listAlgorithm.setCurrentRow(1,QItemSelectionModel_Select)
	}


	my_URL	my_api_key

	func predict
		switch oView.listAlgorithm.CurrentRow()
		on 1
			predictDecisionForest()
		on 2
			predictDecisionJungle()
		on 3
			predictMulticlassNeuralNetwork()
		on 4
			predictLogisticRegression()
		off
		predictGameResult()

	func predictDecisionForest

		my_URL = "https://ussouthcentral.services.azureml.net/workspaces/ed4a059d4bdd45da81d441bcd146f8f5/services/2d4f4c8aaf5046579e95c53a5967638e/execute?api-version=2.0&format=swagger"
		my_api_key = '3UmdB2F2xfOvH9PdO98ewAMdady7f36HRimoqt6fsxTn3sjpEKQhN9zT75LPocOhn7rBayF/lFRVh0qXAS6OMQ==' 

	func predictDecisionJungle

		my_URL = "https://ussouthcentral.services.azureml.net/workspaces/ed4a059d4bdd45da81d441bcd146f8f5/services/2010be66531940ee887edef97c06208b/execute?api-version=2.0&format=swagger"
		my_api_key = 'amKBSrusAWGSHNft86lhmXuLoCnjDEm55HXgdHsPUj3z+h6PcYD6vGk5yS7Jkdnljq3TEP39fNFoovwDL2gwcg==' 


	func predictMulticlassNeuralNetwork

		my_URL = "https://ussouthcentral.services.azureml.net/workspaces/ed4a059d4bdd45da81d441bcd146f8f5/services/55d686ab00804cabaebb72a231a4b56c/execute?api-version=2.0&format=swagger"
		my_api_key = 'GPLQWdLPeo1QkQeFQpHjcrUOYMpIBeXxGu8HQ3KxT5kFJbqpSsfXj79diJBN2f/CuQFo2sHHpW4Mv+BghZv2lA==' 


	func predictLogisticRegression

		my_URL = "https://ussouthcentral.services.azureml.net/workspaces/ed4a059d4bdd45da81d441bcd146f8f5/services/0f79b953e2ae48dd8868195abdb5a787/execute?api-version=2.0&format=swagger"
		my_api_key = 'yB5mc3WNBXLv7wKdAdD9MsXul5TluVszOOif8A8u0P7R+akPzhyjogCCqu4iHYxNAPx8q+pA5nyqv7lC0Jm9ug==' 


	func predictGameResult

		my_body = `{"Inputs": {"input1": [{"WhiteKingFile": "#{f1}", "WhiteKingRank": "#{f2}", "WhiteRockFile": "#{f3}", "WhiteRockRank": "#{f4}", "BlackKingFile": "#{f5}", "BlackKingRank": "#{f6}", "GameResult": ""}]}, "GlobalParameters": {}}`

		oView {
			my_body = substr(my_body,"#{f1}",txtWKF.text())
			my_body = substr(my_body,"#{f2}",txtWKR.text())
			my_body = substr(my_body,"#{f3}",txtWRF.text())
			my_body = substr(my_body,"#{f4}",txtWRR.text())
			my_body = substr(my_body,"#{f5}",txtBKF.text())
			my_body = substr(my_body,"#{f6}",txtBKR.text())
		}
	
		curl = curl_easy_init()   
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.54.1" )
	
		curl_easy_setopt(curl, CURLOPT_POST, 1)
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "Ring")
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE)
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2)
	
		# Header
		mylist = curl_slist_append(null,'accept-encoding: identity')
		mylist = curl_slist_append(mylist,'authorization: Bearer ' + my_api_key )
		mylist = curl_slist_append(mylist,'connection: close')
		mylist = curl_slist_append(mylist,'content-length: ' + len(my_body) )
		mylist = curl_slist_append(mylist,'content-type: application/json')
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, mylist)
	
		# Website
		curl_easy_setopt(curl, CURLOPT_URL, my_URL)
	
		# Body
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, my_body)
	
		cOutput = curl_easy_perform_silent(curl)   

		oView.txtOutput.setText(cOutput)

	func closeWindow 
		oView.win.close()

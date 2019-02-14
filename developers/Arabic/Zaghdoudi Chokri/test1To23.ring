/**
*Application : Quiz (Lesson 1 to 23)
*Auteur      : Chokri
*Date        : 13/02/2019
*/
# ==========================================================================

	# Aplication console qui demande au utilisateur son Login
	
	load "stdlib.ring"
	cAujourdhuit = date()
	cTemps = time()
	print("Nous sommes le " + cAujourdhuit + "\nIl est " + cTemps + "\n")

	# Tablea contien des mot résérvés
	aRWrds = ["Tuto","Tata","Tati"]

	see "Choisissez une option: " + nl + 
		"(1) Connexion " + nl + 
		"(2) Annuler " + nl
	give cOption

	while True
		switch cOption
	
			on "1"
				print("Entrer votre nom utilisateur: \n") cLogin = getstring()
				if isnull(cLogin) ? "Un nom utilisateur est requie !" 
				
					elseif len(cLogin) <= 3 
					? "Le login doit être plus que 3 char !"

					elseif find(aRWrds,cLogin) != 0 
					print("Le login #{cLogin} existe déja !\n")

					else print("Votre login est: #{cLogin}\n") bye
				
				ok
			
			on "2" 
				? "Programme terminé !" bye
	
			other shutdown()
		end
	
	end

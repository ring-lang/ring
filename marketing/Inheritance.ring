# Inheritance(Héritage الوراثة)
# https://www.youtube.com/watch?v=u1LCo6UQv6o&list=PLHIfW1KZRIfl6KzfLziFl650MmThnQ0jT&index=106

func main
	new employee{

		id = 3 nom = "Sami"
		adresse = "Tunisie" salaire = 700

		printId() printNom() printAdresse()

		? copy("=",7)

		printDatas()

		? copy("=",7)

		see "Salaire:" printSalaire()
	}
	new doctor{

		? copy("=",10)
		nom = "Dr.Mahoumd"
		adresse = "Egypt"
		salaire = 1600
		doctoralId = "17016"
		printNom() printAdresse()  
		see "Salaire:" printSalaire()
		printDoctoralId()
	}	
end

class doctor from employee # Sub class from class employee

	doctoralId

	func printDoctoralId ? "DNo:" + doctoralId
	func setDoctoralId value doctoralId = value
	func getDoctoralId
end

class employee from person # Sub class from class person
			   # Supper direct for class doctor
	salaire

	func printSalaire ? salaire

	func setSalaire value salaire = value
	func getSalaire return salaire
end

class person # Supper direct for class employee
	     # Supper indirect for class doctor

	id nom adresse

	func printId ? id
	func printNom ? nom
	func printAdresse ? adresse
	func printDatas  
		? "ID:" + id + "; " + "Nom:" + nom + "; " +
			"Adresse:" + adresse
	end

	func setId value id = value
	func setNom value nom = value
	func setAdresse value adresse = value

	func getId return id
	func getNom return nom
	func getAdresse return adresse

end

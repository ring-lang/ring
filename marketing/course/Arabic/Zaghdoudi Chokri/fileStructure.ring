/**Construction du fichier
 *Instructions(Statements)
	- Charger une bibliothèque
	- Fait appel à un fichier
	- Ecrire des codes(hors fonction)...
 *Déclarion des fonctions s'ils éxistent(hors class)
 *Déclaration des classes sans paquet(packages) (S'ils éxistent)
 *Déclaration des paquets(packages - s'ils éxistent) avec des classes
*/

# Instructions(Statements)
? "Salut la Tunisie!"
? "Nous sommes dans les cours de la programmation Ring :)"
? copy("=",25)

# Déclarion des fonctions
func main # S'éxécute automatiquement
	new cls1{
		f1()
	}
	new cls2{
		f1()
	}
	? copy("=",25)
	new school.subjet{
		getType()
	}
	new academy.student{
		getType()
	}
	? copy("=",25)
	fonc1()
end

func fonc1 ? "Fonction1 dans la zone des fonctions(hors class)"

func fonc2 ? "Fonction2 dans la zone des fonctions(hors class)"

# Déclaration des classes sans paquet
class cls1

	func f1 ? "Fonction f1 de la classe cls1(hors paquet)"
	func f2 ? "Fonction f2 de la classe cls1(hors paquet)"
end

class cls2

	v = "Je suis la classe cls2(hors paquet)"

	func f1 ? v
end

# Déclaration des paquets
package school{

	class subjet func  getType ? "Je suis la methode 'getType' " +
				     "dans la classe subjet, " +
				     "dans le paquet 'school'"

	class student func getType ? "School>>Student"

	class doctor  func getType ? "School>>Doctor"
}

package academy{

	class student func getType ? "Je suis la methode 'getType' " +
				     "dans la classe student, " +
				     "dans le paquet 'academy'"

	class doctor  func getType ? "Academy>>Doctor"
}
/*
Toute classe ajoutée sous un paquet sera appartient à 
	celui ci. Même si le paquet utilise les accolades 
	où le mot clé end.
Any class added under a package will belong to this one.
	Even if the package uses the braces or the 
	keyword end.
*/

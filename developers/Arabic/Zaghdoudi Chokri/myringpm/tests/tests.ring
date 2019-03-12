/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

aTests = [
	[ :name = "Test Affichage du nom du programme",
	  :Command = "ringpm"],

	[ :name = "Test Installation du premier package",
	  :Command = "ringpm install firstpackage"],
	[ :name = "Test Lister apres lintallation du premier package",
	  :Command = "ringpm list"],

	[ :name = "Test Installation du deuxieme package",
	  :Command = "ringpm install secondpackage"],
	[ :name = "Test Lister apres lintallation du deuxieme package",
	  :Command = "ringpm list"],

	[ :name = "Test Installation du troixieme package",
	  :Command = "ringpm install thirdpackage"],
	[ :name = "Test Lister apres lintallation du troixieme package",
	  :Command = "ringpm list"],

	[ :name = "Test Suppresioon du premier package",
	  :Command = "ringpm remove firstpackage"],
	[ :name = "Test Lister apres suppression du premier package",
	  :Command = "ringpm list"],

	[ :name = "Test Suppresioon du deuxieme package",
	  :Command = "ringpm remove secondpackage"],
	[ :name = "Test Lister apres suppression du deuxieme package",
	  :Command = "ringpm list"],

	[ :name = "Test Suppresioon du troixieme package",
	  :Command = "ringpm remove thirdpackage"],
	[ :name = "Test Lister apres suppression du troixieme package",
	  :Command = "ringpm list"]
]

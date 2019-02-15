/**
*Application :   Cours Ring
*Auteur      :   Chokri
*Date        :   15/02/2019
*/
#=====================================================================

					# Les fichiers
					//dir (Fonction qui apporte tous les fichier dans un dossier)
					aDossier = dir("C:/Ring/developpers/Arabic/Zaghdoudi Chokri") //Tableau contient tous les fichiers dans un dossier
					
					x =1
					? "Il ya " + len(aDossier) + " fichiers dans le dossier:"
					for aFichier in aDossier
						if right(aFichier[1],5) = ".ring" && aFichier[1]  != "." && aFichier[1] != ".."
							? "Fichier n° " + x +": " + aFichier[1]   //Affiche les noms des fichiers
							x++
						ok

						if aFichier[1] = "test1.ring" see nl ? read(aFichier[1]) ok

					next
					aDossier = null x = null

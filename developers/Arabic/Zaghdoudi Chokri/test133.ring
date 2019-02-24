/**
*Application :   Cours Ring 
*Auteur      :   Chokri
*Date        :   23/02/2019
*/
#=====================================================
			
			/*
				-Functions/Methods Scope
				-Type Hints  //Ajouter un type au variable
				-Trace Library (Debuggin)

				Quan on déclare une fonction ou une methode
				Le language ----> search ----> Methods ----> Ring Functions ----> std Functions
			*/

			# Type Hints
			load "typehints.ring"

			? total(5,2)

			number func total(number x,number y){
				if isnumber(x) and isnumber(y)
					return x+y
				ok
				return "Erreur !"
			}

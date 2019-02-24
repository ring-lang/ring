/**
*Application :   Cours Ring 
*Auteur      :   Chokri
*Date        :   23/02/2019
*/
#=====================================================
			
			# Variables Scope (مجال روءية المتغيرات) 
			/*
				# Plafond 3 Scopes
				1) Global Scope
				2) Object Scope
				3) Local Scope
				# Lexical Scoping ( Scope variable Based on location )
			*/
			/*
				-Functions/Methods Scope
				-Type Hints  //Ajouter un type au variable
				-Trace Library (Debuggin)

				Quan on déclare une fonction ou une methode
				Le language ----> search ----> Methods ----> Ring Functions ----> std Functions
			*/

			# Functions/Methods Scope
			? copy("Salut ",3)  //std function existe dans le language

			new MaClass{ test() }

			func copy cStr,nCount //Annule la fonction copy() précédente et la modifie
				for t = 1 to nCount
					? cStr
				next 

			class MaClass
				func copy cStr,nCount
				func test
					new local{
						copy("Ring",3)
					}

			class local
					
			
			

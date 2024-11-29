# Written by Mansour Ayouni and shared in Ring Group
# Updated by Fayed

# Inspecting the object directly

o1 = new stzSection(1,5)
? o1.Content()

# Using the good function

? SectionOK(1,5)
#--> [1, 5]

# Using the bad method
oBug = new advancedBug
? oBug.SectionBug(1,5)

#--> Nothing happens, no feedback at all!

func SectionOK(n1, n2)
	oSection = new stzSection(n1, n2)
	aContent = oSection.Content()

	return aContent

class advancedBug

	func SectionBug(n1, n2)
		oSection = new stzSection(n1, n2)
		return oSection.Content()

class stzSection
	@aContent

	def init(n1, n2)
		@aContent = [n1, n2]

	def Content()
		return @aContent

# "Test class for Enumerations and Constant"
# "Author: Charles Michael Farías"
# "Memory's Fast (2026) La Pampa - Argentina"
# "eMail: carlosmiguelfarias@gmail.com"

# "(*) Based in example in \samples\language\constants\constantslib (C)"

Load "EnumConstant.ring"
import Objects
import EnumConstant

def main
	array4test = ["One", "Two", "Three", "Four", "Five", "Six"]
	array4testcheck = ["One", "Two", "Trieste", "France"]
	map4test = [:Seven = :Three, :Eight = :Tigers, :Nine = :eat,
				:Ten = :Wheat, :Eleven = :their, :Twelve = :Plates]
	map4testcheck = [:Seven = :Three, :Eight = :Tigers, :Nine = :eat,
				:Ten = :Wheat, :Eleven = :their, :Twelve = :Plates]
	string4test = "ten twenty thirty forty fifty sixty seventy eighty ninety"
	string4testcheck = "ten twenty three fortest"

	gaClass2Check = [
		:ConstantEnumeration = ["Constant-Enumation", :WithAttributes, NULL,
			[:one11, :two22, :triger33, :six66]],
		:constants = ["Constants", :WithAttributesValues, NULL,
			[:one, :two, :triger, :six]],
		:constants4array = ["Constants from Array", :constants4array, array4test,
			array4testcheck],
		:constants4string = ["Constants from String", :constants4string, string4test,
			string4testcheck],
		:constants4map = ["Constants from Map", :constants4map, map4test,
			map4testcheck],
		:enumeration = ["Enum Base", :Romans, NULL, [:I, :III, :X, :L]],
		:enum4array = ["Enum from Array", :enum4array, array4test,
			array4testcheck],
		:enum4string = ["Enum from String", :enum4string, string4test,
			string4testcheck]
	]
	cSeparator = copy("=", 32)
	cUnderLine = copy("_", 32)
	? "Performs Tests Enumerations & Constant"
	foreach aClass in gaClass2Check
		? cSeparator
		cTest4Class = aClass[1]
		puts("Test for: #{cTest4Class}")
		cTitleClass = aClass[2][1]
		cClass2Test = aClass[2][2]
		cParametersClass = aClass[2][3]
		vValues2Test = aClass[2][4]
		puts("Title: #{cTitleClass}")
		puts("SubClass: #{cClass2Test}")
		if type(cParametersClass) = 'LIST' v = '<LIST>'
		else v = cParametersClass endif
		puts("Params: #{v}")
		if type(vValues2Test) = 'LIST' v = '<LIST>'
		else v = vValues2Test
		endif
		puts("Values: #{v}")
		if isNull(cParametersClass)
			c2t = new from cClass2Test()	? "Created without parameters"
		else
			c2t = new from cClass2Test(cParametersClass)	? "Created with parameters"
		endif
		? cUnderLine	? "Start Test"
		c2t.I_See_Attributes(False)
		put "How many items? " ? c2t.howMany()
		? cUnderLine		? "Show elements in a forward loop"
		c2t.clearAllMsg()
		c2t.firstItem()
		do
			item = c2t.currentKey()
			? c2t.seeOne(item)
			c2t.nextItem()
		again not c2t.atEnd()
		put "Atención: "	? c2t.lastAttention()
		? cUnderLine		? "Show elements in a backward loop"
		c2t.clearAllMsg()
		c2t.lastItem()
		do
			item = c2t.currentKey()
			? c2t.seeOne(item)
			c2t.previousItem()
		again not c2t.atTop()
		put "Atención: "	? c2t.lastAttention()
		? cUnderLine		? "Test methods items, itemsvalues and howmany"
		li = c2t.items()
		liv = c2t.itemsValues()
		for x = 1 to c2t.howMany()
			puts("#{li[x]} - \t#{liv[x][1]} - \t#{liv[x][2]")
		endfor
		switch c2t.typeOf()
			case "Constant"
				? cUnderLine		? "Test method values"
				for element in c2t.values()
					put element + " - "
				endfor
				? ""
				? cUnderLine		? "Test method valuesMap"
				for element in c2t.valuesMap()
					put element[1] + ": " ? element[2] 
				endfor
				? ""
				? cUnderLine		? "Test method constantMap"
				for element in c2t.constantsMap()
					put element[1] + ": " ? element[2] 
				endfor
				? ""
			case "Enumeration"
				? "Enumeration has'nt methods constantMap, values and valuesMap"
			else
				? "Base Class has'nt methods constantMap, values and valuesMap"
		endswitch
	endfor
	? cSeparator ? "End Performs Tests Enumerations & Constants"

# "Class for be used in test"
class WithAttributes: ConstantEnumeration
	One11 Two22 Three33 Four44 Five55 Six66


class Romans: enumeration
	I II III IV V VI


class WithAttributesValues: Constants
	One = "One"		Two = "Two"		Three = "Three"
	Four = "Four"	Five = "Five"	Six = "Six"
	111 = "bad"

# "class for Enumerations and Constant"
# "Author: Charles Michael Farías"
# "Memory's Fast (2026) La Pampa - Argentina"
# "eMail: carlosmiguelfarias@gmail.com"

# "(*) Based in example in \samples\language\constants\constantslib (C)"

Load "stdlibcore.ring"
Load "mf_objlib.ring"
import EnumConstant
import Objects

package EnumConstant
	# "Package for Enumerations and Constants"

class ConstantEnumeration: Object
	# "Class base for enumerations and constants"
	# "This is the root of all class of the package"
	# "For proper functioning of this class and its derivatives, ... "
	# "... they must be created by adding parentheses after the name, ..."
	# "... to force the execution of the init method."
	# "In some cases, appropriate parameters (strings, lists or maps) ..."
	# "... should be added as required."

	def Init
		# "Initializes Constants or Enumerations"
		# "Private attributes are omitted here, validates names attributes..."
		# "... and public attributes are protected from being changed"
		# ":return -> NULL"
		super.init()
		foreach cAttr in Attributes(self)
			if _IsRefused(cAttr)	
				continue						
			endif
			wrongName(cAttr, _INIT)				# "Checks valid name"
			add(_aAttr, cAttr)					# "Load the list of public attributes"
			mn = "set" + cAttr
			if isMethod(self, mn)
				continue					# "omits repeated methods"
			endif
			# "Here, a set<attribute name> method is added that prevents ..."
			# "... modifying the value of <attribute name> and generates ..."
			# "... an appropriate error. (*)"
			addMethod(self, mn,
						def _dummy
							{setErrorMethod(_CANT_CHANGE, _INIT)
							 raise(lastError())})
		endfor

	def atEnd()
		# "Returns true if it is on last element, otherwise false."
		# ":return boolean"
		if _nPos > howMany()
			return True
		endif
		return False

	def atTop()
		# "Returns true if it is on last element, otherwise false."
		# ":return boolean"
		if _nPos < 1
			return True
		endif
		return False

	def currentItem()
		# "Returns the name and value of the element where ..."
		# "... the internal index is positioned.."
		# ":return -> list with [<item-name>, <item-value>]"
		return itemXPos(_nPos)

	def currentKey()
		# "Returns the name of the element where ..."
		# "... the internal index is positioned.."
		# ":return -> string with <item-name>"
		if not isBetween(_nPos, 1, howMany())
			_nPos = 1
		endif
		return _aAttr[_nPos]

	def firstItem
		# "Returns name and value of the first defined item."
		# ":return -> list with [<item-name>, <item-value>]"
		return itemxPos(1)

	def lastItem
		# "Returns name and value of the last defined item."
		# ":return -> list with [<item-name>, <item-value>]"
		return itemxPos(howMany())

	def nextItem
		# "Returns name and value of the next defined item."
		# "If reached the end of the list, return the firs item"
		# ":return -> list with [<item-name>, <item-value>]"
		_nPos++
		if _nPos > howMany()
			setAttention("Reached the end of the list")
			return _OUT_OF_RANGE
		endif
		clearMsgAtn()
		return itemXPos(_nPos)

	def previousItem
		# "Returns name and value of the previous defined item."
		# "If it made it to the top of the list, return the firs item"
		# ":return -> list with [<item-name>, <item-value>]"
		_nPos--
		if _nPos < 1
			setAttention("It made it to the top of the list.")
			return _OUT_OF_RANGE
		endif
		clearMsgAtn()
		return itemXPos(_nPos)

	def has cAttr
		# "Returns True if a public attribute with that name exists."
		# "Otherwise, it returns False and sets an appropriate attention message."
		# ":param cAttr -> Name of the element to check if it is contained"
		# ":return -> boolean and set "
		if find(_aAttr, cAttr) > 0
			clearMsgAtn()
			return True
		endif
		setAttention(print2Str("#{_NOT_FOUND} named ´#{cAttr}´"))
		return False

	def howMany
		# "Returns the number of elements (constants or enumerations)."
		return len(_aAttr)

	def index cAttr
		# "Returns the ordinal position of the constant/enumeration in the class."
		# "... if a public attribute with that name exists."
		# "Otherwise, it returns 0 (zero) and sets an appropriate attention message."
		# ":param cAttr -> Name of the item to find"
		clearMsgAtn()
		nPos = find(_aAttr, cAttr)
		if nPos = 0
			setAttention(print2Str("#{_NOT_FOUND} named ´#{cAttr}´"))
		endif
		return nPos

	def itemXPos nItem
		# "Returns the name and value of an item, according to ..."
		# "... its ordinal position in the list of items.."
		# ":param nItem -> position of item to return"
		# ":return -> list with [<item-name>, <item-value>]"
		if isBetween(nItem, 1, howMany())
			_nPos = nItem
			clearMsgAtn()
			return [_aAttr[nItem], value(_aAttr[nItem])]
		endif
		setAttention(print2Str("#{_NOT_FOUND} at [#{nItem} position"))
		return _OUT_OF_RANGE

	def items
		# "Returns items list of elements (each constant or enumeration)."
		# ":return -> list with [<item-name>, ...]"
		return _aAttr

	def itemsValues
		# "Returns items map of elements (name: value). Not sorted"
		_makeMapAttr()
		return _mAttr

	def typeOf
		# "Returns type of this class <Constant>, <Enumeration> or <UnDefined>"
		return _TYPE

	def value cAttr
		# "Returns the value of an element (constant or enumeration) ..."
		# "if a public attribute with that name exists."
		# "Otherwise, it returns NULL and sets an appropriate attention message."
		# ":param cAttr -> Name of the item to find"
		if has(cAttr)
			return getAttribute(self, cAttr)
		endif
		setAttention(_NOT_FOUND + " named ´" + cAttr + "´.")
		return NULL

	def wrongName cAttr, cMethod
		# "If name attribute is invalid, raise a error"
		# "The name of an element composed solely of digits is not accessible ..."
		# "... using the notation <object>.<name>. My tests generate an error. ..."
		# "The test for alphanumeric characters must be adapted for characters that ..."
		# "... could conflict with operators and other elements of the Ring language."
		# ":param cAttr -> Name to validate"
		# ":param cMethod -> Name method from where it is called"
		if isDigit(cAttr) or not isAlNum(cAttr)
			setErrorMethod("Incompatible Attribute Name:" + seeOne(cAttr),
							cMethod + ".wrongName()")
			raise(lastError())					# "invalid name raise error"
		endif

	private
		# "CONSTANTs"
		_CANT_CHANGE = print2Str("Can't changed #{_TYPE}")
		_INIT = "init"	# "It is used in various places of these classes."
		_NOT_FOUND = print2Str("#{_class} hasn't these #{_TYPE}")
		_OUT_OF_RANGE = ["<Out of Range>", "<NULL>"]
		_TYPE = "UnDefined"	# "Gives a name to the attribute (constant or enum)."

		# "VARIABLEs"
		_aAttr = []		# "List of attributes publics (not sorted)"
		_bmAttr = False	# "Public attributes map loaded"
		_mAttr = []		# "Attributes publics map ([name: value])"
		_nPos = 1		# "Actual position of the items in the list."

		def _makeMapAttr
			# "Make (load) attributes publics map. On demand. First Time"
			if _bmAttr return endif			# "Attributes list loaded"
			_mAttr = []
			for i = 1 to howMany()
				add(_mAttr, itemXpos(i))
			endfor
			_bmAttr = True

		def _IsRefused cAttr
			if isPrivateAttribute(self, cAttr)	# "omits private and ..."
				or find(_aAttr, cAttr) > 0		# "... repeated attributes"
				return True
			endif
			return False


class Constants: ConstantEnumeration
	# "Class base for constants"
	# "This is the root of all constants class"

	def init
		super.init()

	def constantsMap
		# "Returns [name: value] map sorted alphabetic"
		_makeConstantsMap()
		return _mConstants

	def values
		# "Returns values list sorted alphabetic"
		_makeValuesList()
		return _aValues

	def valuesMap
		# "Returns [value: name] map sorted alphabetic"
		_makeValuesMap()
		return _mValues

	private
		_TYPE = "Constant"

		_aValues = []			# "List of values order alphabetic"
		_bmConstants = False	# "Public [name: value] map loaded"
		_bmValues = False		# "Public [value: name] map loaded"
		_baValues = False		# "Values list loaded"
		_mConstants = []		# "[name: value] map (sorted alphabetic)"
		_mValues = []			# "[value: name] map (sorted alphabetic)"		_mValues = []		# "[value: name] map ([value: name])"

		def _makeConstantsMap
			# "Make (load) constant map sorted [name: value]."
			# "On demand. First Time."
			# ":return -> NULL it's a procedure"
			if _bmConstants return endif	# "Constants map loaded"
			_makeMapAttr()
			_mConstants = sort(_mAttr, 1)
			_bmConstants = True

		def _makeValuesList
			# "Make (load) values list sorted."
			# "On demand. First Time. (omits duplicate values)"
			# ":return -> NULL it's a procedure"
			if _baValues return endif		# "Values list loaded"
			_lTemp = []
			foreach cAttr in _aAttr
				val = getAttribute(self, cAttr)
				if find(_ltemp, val) > 0
					continue				# "omits duplicate values"
				endif
				add(_lTemp, val)
			endfor
			_aValues = sort(_lTemp)
			_baValues = True

		def _makeValuesMap
			# "Make (load) [value: name] map sorted alphabetic."
			# "On demand. First Time. (omits duplicate values)"
			# ":return -> NULL it's a procedure"
			if _bmValues return endif		# "Values map loaded"
			_lTemp = []
			foreach cAttr in _aAttr
				val = getAttribute(self, cAttr)
				if find(_ltemp, val, 1) > 0
					continue				# "omits duplicate values"
				endif
				add(_lTemp, [val, cAttr])
			endfor
			_bmValues = True
			_mValues = sort(_lTemp, 1)


class Constants4Array: Constants

	def Init aAttr
		# "Initializes Constants created from an array"
		# "The array must be one-dimensional. Each element is added as an attribute."
		# "Each element must be a string with a valid attribute name ..."
		# "... see the wrongName() method."
		# "Each (attribute) is assigned a value equal to the string passed."
		# ":param aAttr -> Array with names for constants"
		_checkArray(aAttr, _INIT)			# "If not a list, raise error"
		_checkIfIsSet(aAttr, _INIT)			# "Check ifaAttr is a Set (without duplicated)"
		foreach item in aAttr
			if isString(item)
				addAttribute(self, item)
				setAttribute(self, item, item)
			else
				setErrorMethod("Requires each element of the array to be a string", _INIT)
				raise(lastError())
			endif
		endfor
		super.init()


class Constants4Map: Constants
	def Init mAttr
		# "Initializes Constants created from an map [name: value]"
		# "The array must be two-dimensional. Each element is added as an attribute."
		# "The first column of the array must be a valid name for an attribute class, ..."
		# "... the second column can contain any type of value (string, number, list, object)."
		# ":param mAttr -> Array with two dimensions or map [name: value] for constants"
		_CheckMap(mAttr, _INIT)
		foreach item in mAttr
			addAttribute(self, item[1])
			setAttribute(self, item[1], item[2])
		endfor
		super.init()


class Constants4String: Constants4array

	def Init cAttr
		# "Initializes Constants created from an string with names of attributes"
		# "Each word is added as an attribute."
		# ":param cAttr -> String of words separated by spaces, commas, ..."
		# "...				hyphens, periods and/or slashes."
		if not isString(cAttr)				# "If is not a string, raise error"
			setErrorMethod("Requires that the parameter be a string", _INIT)
			raise(lastError())
		endif
		super.init(splitMany(cAttr, " ,-./"))


class Enumeration: ConstantEnumeration
	# "Class base for enumeration"
	# "This is the root of all enumerations class"
	def init
		# "Initializes Enumerations"
		# "Private attributes are omitted here, and validates attributes names..."
		# "... to avoid numbering unusable (private) attributes or incorrect names."
		num = 0
		foreach cAttr in Attributes(self)
			if _IsRefused(cAttr)
				continue
			endif
			wrongName(cAttr, _INIT)				# "Checks valid name"
			num++
			setAttribute(self, cAttr, num)		# "Assign a number to attribute"
		endfor
		super.init()

	private
		_TYPE = "Enumeration"


class Enum4Array: Enumeration

	def Init aAttr
		# "Initializes Enumeration created from an array"
		# "The array must be one-dimensional. Each element is added as an attribute."
		# "Each element must be a string with a valid attribute name ..."
		# "... see the wrongName() method."
		# "Each (attribute) will be numbered in the parent class.."
		# ":param aAttr -> Array with names for enumertion"
		if not isList(aAttr)				# "If not a list, raise error"
			setErrorMethod("Requires that the parameter be an array", _INIT)
			raise(lastError())
		endif
		_checkIfIsSet(aAttr, _INIT)
		foreach item in aAttr
			if isString(item)
				try							# "Captures errors when adding attributes"
					addAttribute(self, item)
					setAttribute(self, item, item)
				catch
					setErrorMethod(cCatchError, _INIT)
					raise(lastError())
				endtry
			else
				setErrorMethod("Requires each element of the array to be a string", _INIT)
				raise(lastError())
			endif
		endfor
		super.init()


class Enum4String: Enum4Array

	def Init cAttr
		# "Initializes Enumeration created from an string with names of attributes"
		# "Each word is added as an attribute."
		# ":param cAttr -> String of words separated by spaces, commas, ..."
		# "...				hyphens, periods and/or slashes."
		if not isString(cAttr)				# "If is not a string, raise error"
			setErrorMethod("Requires that the parameter be a string", _INIT)
			raise(lastError())
		endif
		super.init(splitMany(cAttr, " ,-./"))

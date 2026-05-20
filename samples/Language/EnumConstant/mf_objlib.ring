# "class for Objects Base"
# "Author: Charles Michael Farías"
# "Memory's Fast (2026) La Pampa - Argentina"

package Objects

class Object
	# "Base Class for all objects"
	# ":return -> NULL"
	def init
		if _parent = _class
			_parent_class = _class
		else
			_parent_class = print2str("#{_parent}.#{_class}")
		endif

	def clearAllMsg
		# "Set messages stack to empty and messages to NULL"
		# ":return -> NULL -> This works as a procedure"
		_aMsg = []
		clearMsgAtn()
		clearMsgErr()

	def clearMsgAtn
		# "Set last attention message to NULL"
		# ":return -> NULL -> This works as a procedure"
		_cMsgAtn = NULL

	def clearMsgErr
		# "Set last error message to NULL"
		# ":return -> NULL -> This works as a procedure"
		_cMsgErr = NULL

	def hasAttention
		# "True if it has an attention message, otherwise False"
		# ":return -> boolean"
		return not isNUll(_cMsgAtn)

	def hasError
		# "True if it has an error message, otherwise False"
		# ":return -> boolean"
		return not isNUll(_cMsgErr)

	def I_See
		# "Allow see how stay attributes and methods of class"
		# ":display -> list of [<name attr>, value] and list of methods"
		# ":return -> NULL -> This works as a procedure"
		? capitalized(parentclassName(self))
		? "Attributes"
		foreach item in Attributes(self)
			? "- " + seeOne(item)
		endfor
		? "Methods"
		? Methods(self)

	def I_See_Attributes bIncludePrivate
		if bIncludePrivate
			aAttr = atributes(self)
		else
			aAttr = _aAttr
		endif
		foreach item in aAttr
			? "- " + seeOne(item)
		endfor

	def lastAttention
		# "Returns last attention message"
		# ":return -> string"
		return _cMsgAtn

	def lastError
		# "Returns last error message"
		# ":return -> string"
		return _cMsgErr

	def seeOne item
		# "Allow see how stay one attribute"
		# ":param item -> attribute name for obtains data descriptive"
		# ":return -> string with <name attr>, value, <isPrivate> of a attribute"
		try
			vVal = getAttribute(self, item)
			# "Replaces the attribute value when it is not a number or a string."
			cType = type(vVal)
			if isNull(vVal)
				vVal = "<empty>" cType = "NULL" 
			elseif isNumber(vVal)
				if vVal = True vVal = :True
				elseif vVal = False vVal = :False
				else vVal = string(vVal)
				endif
			elseif not isString(vVal)
				if isList(vVal) or isObject(vVal) or isFunction(vVal) vVal = "..." endif
			endif
			if isPrivateAttribute(self, item) cPrivate = "<X>" else cPrivate = "<O>" endif
			return print2str("#{item}: #{cType} = #{vVal} -> #{cPrivate}")
		catch
			return print2str("#{item}: #{cType} = #{cCatchError}")
		endtry
	
	def seeStackMessages
		# "Returns a list of attention and error messages."
		# ":return -> list"
		return _aMsg

	def setAttention cMsg
		# "Set last attention message and append it to message stack"
		# ":param cMsg -> text of the attention message to save"
		# ":return -> NULL -> This works as a procedure"
		_cMsgAtn = cMsg + "."
		Add(_aMsg, _cMsgAtn)

	def setAttentionMethod cMsg, cMethod
		# "Set last attention message of a method and append it to message stack"
		# ":param cMsg -> text of the error message to save"
		# ":param cMethod -> Name of the method where the attention message originated."
		# ":return -> NULL -> This works as a procedure"
		_cMsgAtn = print2str("Attention at #{_parent_class}.#{cMethod}: #{cMsg}.")
		Add(_aMsg, _cMsgAtn)

	def setError cMsg
		# "Set last error message and append it to message stack"
		# ":param cMsg -> text of the attention message to save"
		# ":return -> NULL -> This works as a procedure"
		_cMsgErr = cMsg + "."
		Add(_aMsg, _cMsgErr)

	def setErrorMethod cMsg, cMethod
		# "Set last error message of a method and append it to message stack"
		# ":param cMsg -> text of the attention message to save"
		# ":param cMethod -> Name of the method where the error message originated."
		# ":return -> NULL -> This works as a procedure"
		? cMsg	? cMethod	? _parent_class ? "ta bien?"
		if isNull(cMsg) cMsg = "Omitted!" endif
		if isNull(cMethod) cMsg = "Where?" endif	
		_cMsgErr = print2str("Error at #{_parent_class}.#{cMethod}: #{cMsg}.")
		Add(_aMsg, _cMsgErr)

	private
		_class = className(self)
		_cMsgAtn = NULL						# "Last Message Attention Sended"
		_cMsgErr = NULL						# "Last Message Error Detected"
		_aMsg = []							# "List Messages Attention"
		_MUST_BE = print2Str("Requires that the parameter be ")
		_parent = parentClassName(self)
		_parent_class = className(self)

		def _checkArray toValidate, cMethod
			# "Validate if is an array"
			# ":param toValidate -> item to validate" 
			# ":param cMethod -> method where required"
			clearMsgErr()
			if not isList(toValidate)		# "If not a list, raise error"
				setErrorMethod(_MUST_BE + "an Array", cMethod)
				raise(lastError())
			endif

		def _checkIfIsSet toValidate, cMethod	
			# "Check aAttr is a Set of strings or numbers (without duplicated)"
			# ":param toValidate -> item to validate" 
			# ":param cMethod -> method where required"
			clearMsgErr()
			aSet = []
			foreach item in toValidate
				if isString(item) or isNumber(item)
					if find(aSet, item) > 0	# "If is duplicate, raise error"
						setErrorMethod(_MUST_BE + "unique value for a Set", cMethod)
						raise(lastError())
					endif
					add(aSet, item)
				else
					setErrorMethod(_MUST_BE + "String or Number for a Set", cMethod)
					raise(lastError())
				endif
			endfor

		def _checkMap toValidate, cMethod
			# "Validate if is an map. Keys duplicate are not allowed."
			# ":param toValidate -> map to validate" 
			# ":param cMethod -> method where required"
			clearMsgErr()
			if not isList(toValidate)		# "If not a list, raise error"
				setErrorMethod(_MUST_BE + "a map", cMethod)
				raise(lastError())
			endif
			aToValidate = []
			foreach item in toValidate
				# "If any item is not a list, raise error"
				if not isList(item) or len(item) != 2
					setErrorMethod(_MUST_BE + "a item <:name, value>", cMethod)
					raise(lastError())
				endif
				add(aToValidate, item[1])
			endfor
			_checkIfIsSet(aToValidate, cMethod + "._checkMap")			

		def _checkString cString, cMethod
			# "Validate if is a string"
			# ":param toValidate -> string to validate" 
			# ":param cMethod -> method where required"
			clearMsgErr()
			if not isString(cString)		# "If not a string, raise error"
				setErrorMethod("Requires that the parameter be a string", cMethod)
				raise(lastError())
			endif

Load "aString.ring"

Ex = new ExpressionBuilder

func Select(cond, ifTrue, ifFalse)
	If cond 
		return ifTrue
	else
		return ifFalse
	end
EndFunc

class ExpressionBuilder
	Edge = "^"
	NotEdge = "&"
	AL = "ال"
	Shaddah = "ّ"
	Any = "?"
	Sokon = "ْ"
	Shaddah = "ّ"
	Fat7ah = "َ"
	TanweenFat7 = "ً"
	Dammah = "ُ"
	TanweenDamm = "ٌ"
	Kasrah = "ِ"
	TanweenKasr = "ٍ"
	AlephHmz = "أ"
	Aleph = "ا"
	AlephLeen = "ى"
	AlephMaksor = "إ"
	HamzetMadd = "آ"
	Waw = "و"
	Yaa = "ي"
	Lam = "ل"
	Hamzah = "ء"
	Faa = "ف"
	Haa = "ه"
	Noon = "ن"
	Taa5 = "ة"
	Taa = "ت"
	Shamsiah = ["ت", "ث", "د", "ذ", "ر", "ز", "س", "ش", "ص", "ض", "ط", "ظ", "ن"]


	Func Any(charCount)
		if charCount < 1
			raise("charCount must be > 0")
		elseif charCount > 10
			raise("charCount must be < 10")
		elseif charCount = 1
			return "?"
		else
			return "?[" + charCount + "]" 
		end
	EndFunc

	func Var(varNum)
		if varNum < 1
			raise("varNum must be > 0")
		elseif varNum > 10
			raise("varNum must be < 10")
		else
			return "#" + varNum
		end
	EndFunc

	func Expand(VarNum)
		if varNum < 1
			raise("varNum must be > 0")
		elseif varNum > 10
			raise("varNum must be < 10")
		else
			return "#" + varNum + Sokon + "#" + varNum
		end
	EndFunc

	func Maybe(str)
		if islist(str)
			L = len(str)
			if L = 0
				raise("str can't be empty")
			else
				result = new aString
				for i = 1 to L
					result.Append("~(")
					result.Append(str[i])
					result.Append(")")
				next
				return result.Text
			end
		elseIf str = ""
			raise("str can't be empty")
		else
			return "~(" + str + ")"
		end
	EndFunc

	func OneOf(list)
		if isstring(list)
			return "[" + list + "]"
		elseif not islist(list)
			raise("Expected a list of strings.")
		end

		L = len(list)
		if l = 0 
			raise("Expected a list of strings.")
		end

		pat = "[" + list[1]
		for i = 2 to L
			pat = pat + "," + list[i]
		next

		return pat + "]"
	EndFunc

	func Validate(charCount, funcName)
		if charCount < 1
			raise("charCount must be > 0")
		elseif charCount > 10
			raise("charCount must be < 10")
		elseIf funcName = ""
			raise("funcName can't be empty")
		else
			return "$" + funcName + "(" + charCount + ")" 
		end
	EndFunc

	func LookForward(charCount, funcName)
		if charCount < 1
			raise("charCount must be > 0")
		elseif charCount > 10
			raise("charCount must be < 10")
		elseIf funcName = ""
			raise("funcName can't be empty")
		else
			return "@" + funcName + "(" + charCount + ")" 
		end
	EndFunc

	Func LookBack(charCount, funcName)
		if charCount < 1
			raise("charCount must be > 0")
		elseif charCount > 10
			raise("charCount must be < 10")
		elseIf funcName = ""
			raise("funcName can't be empty")
		else
			return "@" + funcName + "(-" + charCount + ")" 
		end
	EndFunc
EndClass

Class Expression	

   func init(searchExpr, onlyOnce)
		matchExpr = new aString(searchExpr)

		if matchExpr[1] = "&"
			notStartEdge = 1
			startEdge = 0		
		else
			notStartEdge = 0
			startEdge = Select(matchExpr[1] = "^" , 1, 0)
		end

		lastHrf = matchExpr[matchExpr.Length]
		if lastHrf = "&"
			notEndEdge = 1
			endEdge = 0
		else
			notEndEdge = 0
			endEdge = Select(lastHrf = "^" , 1, 0)
		end

		onece = onlyOnce or startEdge or endEdge

		startOffset = startEdge + notStartEdge
		endOffset = EndEdge + notEndEdge
		expr = matchExpr.Mid(1 + startOffset, matchExpr.length - startOffset - endOffset)

		pattern = ParsePattern(expr)

		L = len(pattern)
		for i = 1 to L
			if isAString(pattern[i])
				checkPoint = pattern[i][1]
				exit
			end

			MinLeadingLen = MinLeadingLen + partsLen[i][1]
			MaxLeadingLen = MaxLeadingLen + partsLen[i][2]
		next
	EndFunc

	Func Replace(str, replaceExpr)
		repExpr = new aString(replaceExpr)
		repExpr = repExpr.Remove("-")
		strLen = Str.Length
		
		newS = str
		offset = 0
		retVal = false

		if startEdge
			matchStart = 1
		else      
			matchStart = GetNextStartPos(str, 1 + notStartEdge)
		end

		while matchStart
			vars = []
			matchEnd = Match(str, matchStart, pattern, vars)
			if matchEnd = 0
				matchEnd = matchStart
			elseIf not (endEdge and matchEnd < strLen) and not (notEndEdge and matchEnd = strLen)		
				L = newS.Length
				DoReplace(newS, repExpr, vars, matchStart + offset, matchEnd -  matchStart + 1)
				offset += newS.Length - L
				retVal = true
				if onece exit end
			end
			if startEdge or matchEnd >= strlen Exit end
			matchStart = GetNextStartPos(str, matchEnd + 1)
		EndWhile

		str = newS
		return retVal
	EndFunc
		
	private
	onece
	pattern
	notStartEdge
	startEdge	
	notEndEdge
	endEdge
	checkPoint = ""
	partsLen = []
	MinLeadingLen = 0
	MaxLeadingLen = 0

	Func ParsePattern(matchExpr)
		pattern = []
		pos = 1
		L = matchExpr.length
	
		for i = 1 to L	
			switch matchExpr[i] 
			 case "?" //Variable
				if i > pos 
					pattern + matchExpr.Mid(pos, i - pos)
				end
	
				if i = L or matchExpr[i + 1] != "["
					pattern + 1
					partsLen + [1, 1]

				elseIf i + 3 > L
					raise("bad expression. Expected `[#]` at pos " + string(i + 1))

				else
					n = number(matchExpr[i + 2])
					if n = 0 or matchExpr[i + 3] != "]"
						raise("Bad expression. Expected `[#]` at pos " + string(i + 1))
					end
					
					pattern + n
					partsLen + [n, n]
					i += 3
				end
				pos = i + 1
	
			 case "$" // Validation function
				i = ParseFunction(matchExpr, pattern, i, pos, "$")
				pos = i + 1

			 case "@" // Look forward function
				i = ParseFunction(matchExpr, pattern, i, pos, "@")
				pos = i + 1

			 case "~" // Maybe
				if i > pos 
					pattern + matchExpr.Mid(pos, i - pos)
				end
				
				j = matchExpr.IndexOf(")", i)
				If j = 0 or j < i + 3 or j > L or matchExpr[i + 1] != "("
					raise("Bad expression. Expected `~(str)` at pos " + string(i + 1))
				else
					maybeStr = matchExpr.Mid(i + 2, j - i - 2)
					pattern + ["~", maybeStr]
					partsLen + [0, maybeStr.Length]
					i = j
				end
				pos = i + 1
				
			 case "[" // string list
				if i > pos 
					pattern + matchExpr.Mid(pos, i - pos)
				end

				j = matchExpr.IndexOf("]", i)
				If j = 0
					raise("Bad expression. Expected `[list]` at pos " + string(i + 1))
				else
					list = matchExpr.Mid(i + 1, j - i - 1).Split(",")				
					listLen = len(list)
					if listLen = 0
						raise("Bad expression. Expected `[list]` at pos " + string(i + 1))
					end
					
					pattern + ["[", list]
					minL = 1000
					maxL = 0
					for i = 1 to listLen
						itemLen = list[i].Length
						if (itemLen < minL) minL = itemLen end
						If (itemLen > maxL) maxL = itemLen end
					next
					partsLen + [minL, maxL]
					i = j
				end
				pos = i + 1	
			
			 case "\" //Escape next char function and consider normal
				if (i < L)	i++  end
			end
		Next
		
		if i > pos
			pattern + matchExpr.Mid(pos, i - pos)
		end
		return pattern
	EndFunc
	
	Func ParseFunction(matchExpr, pattern, i, pos, symbol)
		L = matchExpr.length
		if i > pos 
			pattern + matchExpr.Mid(pos, i - pos)
		end
				
		j = matchExpr.IndexOf("(", i)
		If j = 0 or j = i + 1 or j + 2 > L
			raise("Bad expression. Expected `func(#)` at pos " + string(i + 1))
		else
			c = matchExpr[j + 1]
			if c = "-"
				n = 3
				if j + 3 > L or matchExpr[j + 3] != ")"
					raise("Bad expression. Expected `func(#)` at pos " + string(i + 1))
				end
				charCount = - number(matchExpr[j + 2])
			elseif matchExpr[j + 2] != ")"
				raise("Bad expression. Expected `func(#)` at pos " + string(i + 1))
			else
				n = 2
				charCount = number(c)
			end
			
			if charCount = 0
				raise("Bad expression. Expected `[#]` at pos " + string(i + 1))
			end

			i++
			funcName = lower(matchExpr.MidStr(i, j - i))
			pattern + [symbol, funcName, charCount]
			if symbol = "$"
				partsLen + [charCount, charCount]
			else
				partsLen + [0, 0]
			end
			i = j + n
		end
		return i
	EndFunc

	func GetNextStartPos(str, currentPos)
		if checkPoint = ""
			return currentPos
		else
			pos = currentPos
			strlen = str.Length - notEndEdge

			while pos <= strlen
				i = str.Indexof(checkPoint, pos)
				if i = 0 
					return 0
				elseIf i - MaxLeadingLen >= currentPos
					return i - MaxLeadingLen					
				elseIf i - MinLeadingLen >= currentPos
					return currentPos
				else
					pos = pos + 1
				end
			EndWhile
			return 0
		end
	EndFunc

	Func Match(str, pos, pattern, vars) 
		L = len(pattern)
		strlen = str.Length
		
		For i = 1 to L
			part = pattern[i]
			if isNumber(part) //Variable length
				if pos + part - 1 > strLen return 0 end
				vars + str.Mid(pos, part)
				pos += part

			elseif islist(part) 
				switch part[1] 
					case "~" // Maybe
						maybeStr = part[2]
						charCount = maybeStr.length
						if pos + charCount - 1 > strLen //Not found. Stay at your pos amd continue matching
							vars + ""
							Loop
						end

						chrs = str.Mid(pos, charCount)
						if chrs = maybeStr
							vars + chrs
							pos += charCount
						else //Not found. Stay at your pos amd continue matching
							vars + ""
						end

					case "[" // String list
						list = part[2]
						listLen = len(list)
						found = false
						for k = 1 to listLen
							item = list[k]
							charCount = item.Length
							if pos + charCount - 1 > strLen loop end
							if str.ContainsAt(item, pos)
								vars + item
							 	pos += charCount
								found = true
								exit
							end
						next	
						if not found return 0 end

					case "$" //Validation function
						charCount = part[3]
						if pos + charCount - 1 > strLen return 0 end
						ValidationFunc = part[2]
						chrs = str.Mid(pos, charCount)
						if Call ValidationFunc(chrs)
							vars + chrs
							pos += charCount
						else
							return 0
						end

					case "@" //LookAhead function		
						if part[3] > 0
							charCount = Min(part[3], strLen - pos + 1)
							if charCount = 0
								chrs = new aString("")
							else							
								chrs = str.Mid(pos, charCount)
							end
						else
							startPos = Max(pos + part[3], 1)
							charCount = pos - startPos
							if charCount = 0
								chrs = new aString("")
							else								
								chrs = str.Mid(startPos, charCount)
							end
						end

						LookAheadFunc = part[2]
						if Call LookAheadFunc(chrs)
							vars + chrs
							// Keep current pos. This is just a look forward
						else
							return 0
						end
				EndSwitch

			else // string
				charCount = part.Length 	
				if pos + charCount - 1 > strLen return 0 end
				if not str.ContainsAt(part, pos) return 0 end
			 	pos += charCount
			end
		next

		return pos - 1
	EndFunc
	
	
	func DoReplace(str, repExpr, vars, matchStart, matchCount)
		pos = 0
		repStr = new aString
		startAt = 1
		L = len(repExpr)
		varsLen = len(vars)
	
		while true
			pos = repExpr.IndexOf("#", pos + 1)
			if pos = 0 
				exit 
			elseIf pos = L
				raise("Bad expression. Expected a number at pos " + string(pos + 1))
	      end
	
			n = number(repExpr[pos + 1])
			if n = 0 
				raise("Bad expression. Expected a number at pos " + string(pos + 1))
			elseIf n > varsLen
				raise("`#" + n + "` > vars defiend in search pattern.")
			end
	
			repStr.AppendFrom(repExpr, startAt, pos - startAt)
			repStr.Append(vars[n])
			startAt = pos + 2
		end
		
		if startAt <= L
			repStr.AppendFrom(repExpr, startAt, L - startAt + 1)
		end

		str = str.ReplaceAt(matchStart, matchCount, repStr)
	EndFunc
EndClass

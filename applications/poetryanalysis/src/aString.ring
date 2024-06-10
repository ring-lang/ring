Load "aLetters.ring"

Func IsAString(obj)
	If type(obj) = "OBJECT" and classname(obj) = "astring"
		return true
   else
		return false
   end
EndFunc

Func Join(arr, sep)
	L = len(arr)
	If L = 0 return "" end
	str = ""

	for i = 1 to L - 1
		if isaString(arr[i])
			str += arr[i].Text + sep
		else
			str += "" + arr[i] + sep
		EndIf
	next
	
	if isaString(arr[L])
		str += arr[L].Text
	else
		str += "" + arr[L]
	EndIf
	
	return str
EndFunc

	
Class aString
	Length
	Text
	
   func init(str)
		Append(str)
	EndFunc
	
	func GetLength()
      return len(LstText)
	EndFunc

	func setText(str)
		LstText = []
		Append(str)
	EndFunc

	func getText()   
		return SubStr(1, len(LstText))
	EndFunc

	func ToString()
		return getText()
	EndFunc

	func Clear()
		LstText = []
	EndFunc

	func Delete(startAt, charCount)
		AssertPos("startAt", startAt)
		L = len(LstText)

		for i = 1 to charCount			
			del(LstText, startAt)
			L--
			if startAt > L return end
		next
	EndFunc
	
	func ShrinkTo(newLength)
		if newLength < 1
			LstText = []
		else
			L = len(LstText)
			if newLength < L
				for i = L to newLength + 1 step -1
					del(LstText, i)
				next
			end
		end
	EndFunc

	func Append(str)
		if IsAString(str)
			L = str.Length
			For i = 1 to L
				LstText + str.LstText[i]
			next
		elseIf isList(str)
			L = len(str)
			for i = 1 to L
				Append(str[i])
			next
		else
			if not isString(str)
				str = string(str)
			end
			L = len(str)
			For i = 1 to L
			   c = str[i]
			   if ascii(c) < 128
			      LstText + c
			   else
			      i++
			      LstText + (C + str[i])
			   end
			next
		end
	EndFunc

	func AppendFrom(str, stratAt, charCount)
		if IsAString(str)
			newStr = str
		else			
			newStr = new aString(str)
		end
		
		endAt = stratAt + charCount -1
		For i = stratAt to endAt
			LstText + newStr.LstText[i]
		next
	EndFunc

	func Right(charCount)
      if charCount = 0 return new aString end
      AssertPos("charCount", charCount)
		newS = 	new aString
		L = len(LstText)
		CopyTo(newS.LstText	,  L - charCount + 1, L)
	   return newS
	EndFunc

	func RightStr(charCount)
      if charCount = 0 return "" end
      AssertPos("charCount", charCount)
		L = len(LstText)
	   return SubStr(L - charCount + 1, charCount)
	EndFunc

	func Left(charCount)
      if charCount = 0 return new aString end
		AssertPos("charCount", charCount)
		newS = 	new aString
		CopyTo(newS.LstText	, 1, charCount)
	   return newS
	EndFunc
	
	func LeftStr(charCount)
       if charCount = 0 return "" end
       AssertPos("charCount", charCount)
	    return SubStr(1, charCount)
	EndFunc

   func RemoveFirst(charCount)
			return Right(Len(LstText) - charCount)
	EndFunc

   func RemoveFirstStr(charCount)
        return RightStr(Len(LstText) - charCount)
	EndFunc

   func RemoveLast(charCount)
        return Left(Len(LstText) - charCount)
	EndFunc

   func RemoveLastStr(charCount)
       return LeftStr(Len(LstText) - charCount)
	EndFunc

	 Func RemoveAt(startAt, charCount)
			L = Len(LstText)
 			st2 = startAt + charCount
			if StartAt = 1
				return Right(L - charCount)
         elseif st2 > L
				return Left(startAt - 1)				
			else
				newS = new aString
				CopyTo(newS.LstText, 1, startAt - 1)
				CopyTo(newS.LstText, st2, L)
				return newS
			end
	EndFunc

	 Func RemoveAtStr(startAt, charCount)
			L = Len(LstText)
 			st2 = startAt + charCount
			if StartAt = 1
				return SubStr(charCount + 1, L - charCount)
         elseif st2 > L
				return SubStr(1, startAt - 1)				
			else
				newS = new aString
				CopyTo(newS.LstText, 1, startAt - 1)
				CopyTo(newS.LstText, st2, L - st2 + 1)
				return newS.SubStr(1, L - charCount)
			end
	EndFunc

   Func Remove(str)
		if str = "" or len(lstText) = 0 return self end

      If IsAString(str)
         s = str
      else
         s = new aString(str)
      end

		n = len(s.LstText)
      L = Len(LstText)
      pos = 1
      newS = new aString

      while True
         i =  indexOf(s, pos)	
         if i = 0 
            CopyTo(newS.LstText, pos, L)               
            return newS 
         end

         if i > pos { CopyTo(newS.LstText, pos, i - 1)}
         pos = i + n
         if pos > L return newS end
      end
	EndFunc

    Func RemoveStr(str)
      return Remove(str).Text
	EndFunc

	func ReplaceAt(startAt, charCount, repWith)
			newS = new aString
			L = Len(LstText)
 			st2 = startAt + charCount

			if StartAt = 1
				newS.Append(repWith)
				CopyTo(newS.LstText, St2, L)
         elseif st2 > L
				CopyTo(newS.LstText, 1, startAt - 1)
				newS.Append(repWith)				
			else
				CopyTo(newS.LstText, 1, startAt - 1)
				newS.Append(repWith)
				CopyTo(newS.LstText, st2, L)
			end	
	
			return newS
	EndFunc

	func ReplaceAtStr(startAt, charCount, repWith)		
		return ReplaceAt(startAt, charCount, repWith).Text
	EndFunc

   func Insert(str, pos)
      If IsAString(str)
         s = str
      else
         s = new aString(str)
      end
            
      L = Len(LstText)
		newS = new aString

      if pos = L + 1 
         newS.LstText = LstText
         newS.Append(s) 
      elseif pos = 1
         newS.Append(s)
         CopyTo(newS.LstText, 1, L)
      else
         AssertPos("pos", pos)
         CopyTo(newS.LstText, 1, pos -1) 
         newS.Append(s)
         CopyTo(newS.LstText, pos, L)
		end
		return newS
	EndFunc

   func InsertStr(str, pos)
		return Insert(str, pos).Text
	EndFunc

   func SetCharAt(index, chr)
		AssertPos("index", index)
      if IsAString(chr) 
			if chr.Length != 1 
				Raise("you can set exactly one char only.") 
			end
			LstText[index] = chr.LstText[1]
		else
			L = len(chr)
			if L = 0 or L > 2 or ascii(chr[1]) < 128 
				Raise("you can set exactly one char only.") 
			end
			LstText[index] = chr
		End
	EndFunc

	func Mid(startAt, charCount)
		 AssertPos("startAt", startAt)
		 AssertPos("charCount", charCount)
		 if startAt + charCount - 1 > Len(LstText)
          raise("The sub string exceeds the str length")
		 end
		 newS = new aString
		 CopyTo(newS.LstText, startAt, startAt + charCount - 1)
	    return newS
	EndFunc

	func MidStr(startAt, charCount)
		 AssertPos("startAt", startAt)
		 AssertPos("charCount", charCount)
		 if startAt + charCount - 1 > len(LstText)
          raise("The sub string exceeds the str length")
		 end
		 return SubStr(startAt, charCount)
	EndFunc

	func IndexOf(str, startAt)
		if str = "" or len(lstText) = 0 return 0 end

      if IsAString(str) 
          s = str
      else
          s = new aString(str)
      end
		n = len(s.LstText)
		L = Len(LstText)
		if n > L or n = 0 return 0 end

		AssertPos("startAt", startAt)     

		L = L - n + 1
		For i = startAt to L
			found = 0
			For j = 1 to n
				if LstText[i + j - 1] = s.LstText[j]
					found += 1
				else
					Exit
				end
			Next

			if found = n return i end
		Next
		return 0
	EndFunc

	func IndexOfAny(lstStr, startAt)
		L = len(lstStr)
		for i = 1 to L
			result = IndexOf(lstStr[i], startAt)
			if result return result end
		next
		return 0
	EndFunc

	func StartsWith(str)
		return ContainsAt(str, 1)
	EndFunc
	
	func EndsWith(str)
		return ContainsAt(str, -1)
	EndFunc

	func EndsWithAny(strList)
		L = len(strList)
		for i = 1 to L
			if ContainsAt(strList[i], -1) return true end
		next

		return False
	EndFunc

	func ContainsAt(str, startAt)
		L = Len(LstText)
		if str = "" or L = 0 return false end

      if IsAString(str) 
          s = str
      else
          s = new aString(str)
      end
		n = len(s.LstText)
		
		if n > L or n = 0 return false end
		if startAt = -1
			startAt = L - n + 1
		else
			AssertPos("startAt", startAt)
		end
		
		if startAt + n - 1 > L return false end

		For i = 1 to n
			if s.LstText[i] != LstText[startAt]
				return false
			end
			startAt++
		Next
		return true
	EndFunc
	func Split(sep)
		return DoSplit(sep, 1)
	EndFunc

	func SplitStr(sep)
		return DoSplit(sep, 0)
	EndFunc

	func operator(op, param)
		switch op
			case "[]"
	          if not type(param) = "NUMBER"
					 param = Number(param)
					 If isNull(param)
					    raise("Index must be a number")
					 end
				 end
		 		 AssertPos("index", param)
				 return LstText[param]

			case "len"
				return len(LstText)

			case "+"
				newS = new aString
				newS.LstText = LstText
            newS.append(param)
				return newS

        case "="
           return CompareTo(param) = 0

        case "!="
            return CompareTo(param) != 0

        case "<"
           return CompareTo(param) < 0

        case "<="
            return CompareTo(param) < 1

        case ">"
           return CompareTo(param) > 0

        case ">="
            return CompareTo(param) > -1
		end
	EndFunc

	func CompareTo(str)
      if IsAString(str) 
          s = str
      else
          s = new aString(str)
      end
		L1 = Len(LstText)
		L2 = len(s.LstText)
		L = min(L1, L2)
		For i = 1 to L
				v = strcmp(LstText[i], s.LstText[i])
				if v != 0 return v end
		Next
		if L1 = L2 
			return 0
		elseIf L1 > L2
			return 1
		else
			return -1
		end
	EndFunc

	Func ReadNumberAt(startAt)
		AssertPos("startAt", startAt)

		L = len(LstText)
		For pos = startAt to L

			if not isDigit(LstText[pos]) exit end
		next
		
		n = pos - startAt
		if n = 0
			return ""
		else
			return number(SubStr(startAt, n))
		end
	EndFunc

	Func IsNumeric()
		L = len(LstText)
		if L = 0
			return False
		else
			point = 0
			for i = 1 to L
				c = LstText[i]
				if len(c) = 2
					return false
				elseIf c = "-"
					If i > 1 or L = 1 Return False End
				elseIf c = "."
					if point > 0 or i = L return false end
					point = 1
				else
					n = ascii(c)
					if n < 48 or n > 57 return false end
				end
			next
		end
		return True
	EndFunc

#---------Arabic Methods---------------	
	Func RemoveTashkeel()
	   newS = new aString
	   L = Len(LstText)
	
	   For i = 1 to L 
			 a = LstText[i]
	       If not IsTashkeel(a)
	          newS.Append(a)
	       end
	   Next
	   Return newS
	EndFunc
	
	Func AddTashKeel(fromWazn)
		if IsAString(fromWazn)
			Wazn = fromWazn
		else
			Wazn = new AString(fromWazn)
		end

	   word = new AString
	   AbsWazn = Wazn.RemoveTashkeel()
	   L = Len(Wazn.LstText)
	   L2 = Len(LstText)
	
	   start = 1
		n = 1
	   For i = 2 To L
			tsh = Wazn.LstText[i]
		  If IsTashkeel(tsh)
				if n > 0
				  s = mid(start, n)
				  n = 0
		        word.append(s)	           
		        start += Len(s.LstText)
				end
	        Word.append(tsh)
			  if start > L2 Exit End
   	  else
				n += 1	
	     End
	  Next
	
	  If L2 > start
	    word.append(Right(L - start + 1))
	  end

	  Return Word
	EndFunc

	Func GetLines()
        Lines = []
        line = new aString
        Lf = char(10)
        Cr = char(13)
		  L = Len(LstText)
        For i = 1 to L
            c = LstText[i]
            If c != Lf and c != Cr and c != "="
              line.Append(c)
            Elseif len(line.LstText) > 0 
              If Line.HasAnyAChr()
                 lines + Line
              end
              line.LstText = []
            End
        Next

		  If len(line.LstText) > 0
           If Line.HasAnyAChr()
              lines + Line
           end
        End
        return lines
	EndFunc

	Func GetWords()
        words = []
        word = new aString
		  L = Len(LstText)
        For i = 1 to L
            c = LstText[i]
            If IsAChar(c)
              word.Append(c)
            ElseIf c != Letters.Kashida and len(word.LstText) > 0
              words + word
              word.LstText = []
            End
        Next

		  If len(word.LstText) > 0
           words + word
        End
        return words
	EndFunc


	func HasAnyAChr()
        L = Len(LstText)
        For i = 1 to L
           if IsAChar(LstText[i]) return true end
        next
        return false
	EndFunc

private
   LstText = []
	
	func SetLength()
	EndFunc

	func CopyTo(lst2, startAt, stopAt)

		for i = startAt to stopAt
			lst2 + LstText[i]
		next
	EndFunc

	func SubStr(startAt, charCount)
      L = 0
		L1 = startAt + charCount - 1
      for i = startAt to L1
			L += len(LstText[i])
      next
		if L = 0 return "" end

		_str = space(L)
		idx = 0

		for j = startAt To L1
			x = LstText[j]
			L2 = len(x)
			for i = 1 to L2
				idx++
				_str[idx] = x[i]
			next
      next
		return _str
	EndFunc

	func AssertPos(paramName, value)
       if value < 1
          raise(paramName + " must be > 0")
	    end

       if value > Len(LstText)
          raise(paramName + " must not exceed the string Length")
	    end
	EndFunc


	func DoSplit(sep, returnAString)
		if sep = ""
			raise("Empty separator is not accepted.")
		elseIf isAString(sep)
			_sep = sep
		else
			_sep = new aString(sep)
		end

		list = []
		L = len(lstText)
		if L = 0 return list end
		pos1 = 1
		sepLen = len(_sep.lstText)

		while pos1 <= L
			pos2 = IndexOf(_sep, pos1)
			if pos2 = 0	
				if returnAString			
					list + Mid(pos1, L - pos1 + 1)
				else
					list + SubStr(pos1, L - pos1 + 1)
				end
				return list
			elseif pos2 > pos1
				if returnAString
					list + Mid(pos1, pos2 - pos1)
				else
					list + SubStr(pos1, pos2 - pos1)
				end
			end

			pos1 = pos2 + sepLen

		EndWhile
	EndFunc

EndClass

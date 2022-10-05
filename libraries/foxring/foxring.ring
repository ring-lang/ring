/*
 *
 *	frAbs()				Returns the absolute value of the specified numeric expression.
 *	frAddBs()			Adds a backslash (if needed) to a path expression.
 *	frALines()			Creates an Array with the content of the specified string. 
 *	frAllTrim()			Removes all leading and trailing spaces of the specified string. 
 *	frAsc()				Returns the ANSI value for the leftmost character in a character expression.
 *	frAt()				Searches a character expression for the occurrence of another character expression.
 *	frAtC()				Searches a character expression for the occurrence of another character expression without 
 *						regard for the case of these two expressions.
 *	frBetween()			Determines whether the value of an expression is inclusively between the values of two 
 *						expressions of the same type.
 *	frCDoW() 			Returns the day of the week from a given Date or DateTime expression.
 *	frCDoWShort() 			Returns the day of the week in a short mode from a given Date or DateTime expression.
 *	frChr()				Returns the character associated with the specified numeric ANSI code.
 *	frCMonth() 			Returns the name of the month from a given Date or DateTime expression.
 *	frCMonthShort() 		Returns the name of the month in a short mode from a given Date or DateTime expression.
 *	frCToD()			Converts a character expression to a date expression.
 * 	frDate()			Returns the current system date, which is controlled by the operating system, or creates a date.
 *	frDateTime()			Returns the current system date and time, which is controlled by the operating system, or creates a date time value.
 *	frDay() 			Returns the numeric day of the month for a given Date or DateTime expression.
 *	frDoW() 			Returns a numeric day of the week value from a Date or DateTime expression.
 *	frDToC()			Returns a character string as a date format from a Date or a DateTime expression.
 *	frEmpty()			Determines whether an expression evaluates to empty.
 *	frFile()			Checks if a file exists on disk.
 *	frFileToStr()			Returns the contents of a file as a character string.
 *	frForceExt()			Returns a string with the old file name extension replaced by a new extension.
 *	frForcePath()			Returns a file name with a new path name substituted for the old one.
 *  	frIif()   			Returns one of two values depending on the value of a logical expression.
 *	frInList()			Determines whether an expression matches another expression in a list.
 *	frInt()				Evaluates a numeric expression and returns the integer portion of the expression.
 *	frJustDrive()			Returns the drive letter from a complete path.
 *	frJustExt()			Returns the characters of a file extension from a complete path.
 *	frJustFName()			Returns the file name portion of a complete path and file name.
 *	frJustPath()			Returns the path portion of a complete path and file name.
 *	frJustStem()			Returns the stem name (the file name before the extension) from a complete path and file name.
 *	frLen()				Determines the number of characters in a character expression, indicating the length of the expression.
 *	frListToString()		Creates a string with the string elements of an Array.
 *	frLTrim()			Removes all leading spaces or parsing characters from the specified character expression.
 *	frMonth() 			Returns the number of the month for a given Date or DateTime expression.
 *	frPadL()			Returns a string from an expression, padded with spaces or characters to a specified length on the left side.
 *	frPadR()			Returns a string from an expression, padded with spaces or characters to a specified length on the right side.
 *	frProper()			Returns from a character expression a string capitalized as appropriate for proper names.
 *	frReplicate()			Returns a character string that contains a specified character expression repeated a specified number of times.
 *	frRTrim()			Removes all trailing spaces or parsing characters from the specified character expression.
 *	frSetCentury()			Returns the current value of the century format and sets a new one when specified.
 *	frSetDate()			Returns the current value of the date format and sets a new one when specified.
 *	frSetIfEmpty()			Set a Value into a variable if the variable value is empty, null or zero.
 *	frSetSeparatorTo()		Specifies the character for the numeric place separator.
 *	frSpace()			Returns a character string composed of a specified number of spaces.
 *	frStr()				Returns the character equivalent of a numeric expression.
 *	frStringToList()		Creates a List with the content of the specified string.
 *	frStrTran()			Searches a character expression for a second character expression and replaces each occurrence with a third 
 *						character expression.
 *	frStuff()			Returns a new character string replaced by a specified number of characters in a character expression with 
 *						another character expression.
 *	frSubStr()			Returns a character string from the given character expression, starting at a specified position in the character 
 *						expression and continuing for a specified number of characters.			
 * 	frTransform()			Returns a character string from an expression in a format determined by a format code.
 *	frVal()				Returns a numeric value from a character expression composed of numbers.
 *	frVarType()			Returns the data type of an expression.
 *	frWeek()				Returns a number of the week in the year from a Date or DateTime expression. 			
 *	frYear() 			Returns the year from the specified Date or DateTime expression.
 *
 */

 
 
 
 
 
	/*
	 * Syntax			: 
	 * Description		: 
	 * Arguments   		: 
	 *					: 
	 * Returns			: 
	 * Remarks			: 
	 * Author	 		:
	 * History			:
	 */
	
class frFunctions {

	_version 				= "1.0.147"

	_character_type 			= "C"
	_numeric_type 				= "N"	
	_date_type 				= "D"
	_datetime_type 				= "T"
	_list_type 				= "A"
	_object_type 				= "O"
	_undefined_type 			= "U"
	
	_decimal_point 				= "."		
	_empty_char 				= ""
	_space 					= " "
	_back_slash 				= "\"
	_separator 				= ","

	_on 					= "ON"
	_off 					= "OFF"
	
	_ring_character_type 			= "STRING"
	_ring_numeric_type 			= "NUMBER"
	_ring_list_type 			= "LIST"
	_ring_object_type 			= "OBJECT"

	_dateform_american 			= "mm/dd/yy"
	_dateform_ansi 				= "yy.mm.dd"
	_dateform_british_french		= "dd/mm/yy"
	_dateform_british 			= "dd/mm/yy"
	_dateform_french			= "dd/mm/yy"
	_dateform_german 			= "dd.mm.yy"
	_dateform_italian			= "dd-mm-yy"
	_dateform_japan				= "yy/mm/dd"
	_dateform_taiwan			= "yy/mm/dd"
	_dateform_usa				= "mm-dd-yy"
	_dateform_mdy				= "mm/dd/yy"
	_dateform_dmy				= "dd/mm/yy"
	_dateform_ymd				= "yy/mm/dd"

	_date_american 				= "AMERICAN"
	_date_ansi 				= "ANSI"
	_date_british_french			= "BRITISH/FRENCH"
	_date_british 				= "BRITISH"
	_date_french 				= "FRENCH"
	_date_german 				= "GERMAN"
	_date_italian				= "ITALIAN"
	_date_japan				= "JAPAN"
	_date_taiwan				= "TAIWAN"
	_date_usa				= "USA"
	_date_mdy				= "MDY"
	_date_dmy				= "DMY"
	_date_ymd				= "YMD"

	_set_separator 				= _separator
	_set_century				= _off
	_set_century_to				= -1
	_set_century_rollover			= 48
	_set_date 		 		= _date_dmy
	_set_dateformat				= _dateform_dmy

	
	/*
	 * Syntax			: lnReturnValue = frDoW(tdExpression|ttExpresion, nFirstDayOfWeek)
	 * Description		: Returns a numeric day of the week value from a Date or DateTime expression.
	 * 					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 *					: <nFirstDayOfWeek>
	 *					: Not implemented yet
	 *					:
	 * Returns			: <lnReturnValue>
	 *					: Returns a numeric value corresponding with the day of week according with the following table:
	 *					:
	 *					: Monday			1
	 *					: Tuesday		2
	 *					: Wednesday		3
	 *					: Thursday		4
	 *					: Friday			5
	 *					: Saturday		6
	 *					: Sunday			7
	 *					:
	 * Author			: Jar C 02.10.2018
	 */
	func frDoW(tdDate, tnFDoW) {


		// Jar 02.10.2018 
		// At moment tnFDow isn't used
		tnFDoW = this.frSetIfEmpty(tnFDoW, 2)		

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.nDayOfWeek
	}
	
	/*
	 * Syntax			: lcReturnValue = frCDow(tdDate|ttDateTime, tnFirstDayOffWeek)
	 * Description		: Returns the day of the week from a given Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 *					: <nFirstDayOfWeek>
	 *					: Not implemented yet
	 *					:
	 * Returns			: <lcReturnValue>
	 *					: Returns the name of the day of the week 
	 *					:
	 *					:
	 * Author	 		: Jar C 02.10.2018
	 * History			:
	 */
	func frCDoW(tdDate, tnFDoW) {

		// Jar 02.10.2018 
		// At moment tnFDow isn't used
		tnFDoW = this.frSetIfEmpty(tnFDoW, 2)		

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.cDayOfWeek
	}

	/*
	 * Syntax			: lcReturnValue = frCDowShort(tdDate|ttDateTime, tnFirstDayOffWeek)
	 * Description		: Returns the day of the week in a short mode from a given Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 *					: <nFirstDayOfWeek>
	 *					: Not implemented yet
	 *					:
	 * Returns			: <lnReturnValue>
	 *					: Returns the short name of the day of the week 
	 *					:
	 * Author	 		: Jar C 02.10.2018
	 * History			:
	 */
	func frCDoWShort(tdDate, tnFDoW) {

		// Jar 02.10.2018 
		// At moment tnFDow isn't used
		tnFDoW = this.frSetIfEmpty(tnFDoW, 2)		
		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.cShortDayOfWeek
	}
	
	
	/*
	 * Syntax			: lnReturnValue = frDay(tdDate|ttDateTime) 
	 * Description		: Returns the numeric day of the month for a given Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: 
	 * Remarks			: 
	 * Author	 		: Jar C 06.11.2018
	 * History			:
	 */
	func frDay(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.nDay
	}

	
	/*
	 * Syntax			: lnReturnValue = frMonth(tdDate|ttDateTime)
	 * Description		: Returns the number of the month for a given Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: 
	 * Remarks			: 
	 * Author	 		: Jar C 06.11.2018
	 * History			:
	 */
	func frMonth(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.nMonth
	}


	/*
	 * Syntax			: lcReturnValue = frCMonth(tdDate|ttDateTime)
	 * Description		: Returns the name of the month from a given date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: 
	 * Remarks			: 
	 * Author	 		: Jar C 06.11.2018
	 * History			:
	 */
	func frCMonth(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.cMonth
	}


	/*
	 * Syntax			: lcReturnValue = frCMonthShort(tdDate|ttDateTime)
	 * Description		: Returns the name of the month in a short mode from a given Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: 
	 * Remarks			: 
	 * Author	 		: Jar C 06.11.2018
	 * History			:
	 */
	func frCMonthShort(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.cShortMonth
	}


	/*
	 * Syntax			: lnReturnValue = frWeek(tdDate|ttDateTime)
	 * Description		: Returns a number of the week in the year from a Date or DateTime expression. 			
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: lnReturnValue
	 *					: Returns the number of the week in the year.
	 * Remarks			: 
	 * Author	 		: Jar C 07.11.2018
	 * History			: 
	 */
	func frWeek(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.nWeek
	}

	/*
	 * Syntax			: lnReturnValue = frYear(tdDate|ttDateTime)
	 * Description		: Returns the year from the specified Date or DateTime expression.
	 *					:
	 * Arguments			: <tdExpression|ttExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: lnReturnValue
	 * Remarks			: 
	 * Author	 		: Jar C 06.11.2018
	 * History			:
	 */
	func frYear(tdDate) {

		oDt = this._GetDateObject(tdDate.nYear, tdDate.nMonth, tdDate.nDay)
		return oDt.nYear
	}



	
	/*
	 * Syntax		: lnReturnValue = frAbs(tnExpression)
	 * Description		: Returns the absolute value of the specified numeric expression.
	 * 			:
	 * Arguments		: <tnExpression>
	 *			: Specifies the numeric expression whose absolute value frAbs() returns.
	 *			:
	 * Returns		: <lnReturnValue>
	 *			: Returns the absolute value of the specified numeric expression.
	 *			:
	 * Author		: Jar C 18.02.2018
	 */
	 
	func frAbs(tnExpression) {
	 	return fAbs(tnExpression)
	}
	
	

	/*
	 * Syntax		: lnReturnValue = frAsc(tcExpression)
	 * Description		: Returns the ANSI value for the leftmost character in a character expression.
	 * 			:
	 * Arguments		: <tcExpression>
	 *			: Specifies the character expression containing the character whose ANSI value frAsc() 
	 *			: returns. Any characters after the first character in tcExpression are ignored by frAsc().
	 *			:
	 * Returns		: <lnReturnValue>
	 *			: returns the position of the character in the character table of the current code page. 
	 *			: Every character has a unique ANSI value in the range from 0 to 255.
	 *			:
	 * Author		: Jar C 04.02.2018
	 *			: Jar U 01.03.2018 Updated to return 0 when tcExpression is an empty string. 
	 */
	 
	func frAsc(tcExpression) {
		if tcExpression = this._empty_char {
			lnReturnValue = 0
		else
			lnReturnValue = Ascii(Left(tcExpression, 1))
		}
	 	return lnReturnValue
	}
	
	/*
	 * Syntax		: lcReturnValue = frAddBs(tcPath)
	 * Description		: Adds a backslash (if needed) to a path expression.
	 *			:
	 * Arguments   		: <tcPath>
	 *			: Specifies the path name to which to add the backslash.
	 *			:
	 * Returns		: <lcReturnValue> The path with the backslash.
	 *			:
	 * Author	 	: Jar C 15.09.2017
	 */

	func frAddBs(tcPath) {
		return this.frStrTran(tcPath + this._back_slash, this.frReplicate(this._back_slash, 2), this._back_slash)
	}

	/*
	 * Syntax		: lnPos = frAt(tcToSearch, tcString, tnOccurrence)
	 * Description		: Searches a character expression for the occurrence of another character expression. 
	 *			: The search performed by .frAt() is case-sensitive.
	 *			:
	 * Arguments   		: <tcToSearch>
	 *			: Specifies the character expression to search for in <tcString>.
	 *			:
	 *			: <tcString> 
	 *			: Specifies the character expression to search for <tcToSearch>. 
	 *			:
	 *			: <tnOccurrence> 
	 *			: Specifies which occurrence, first, second, third, and so on, of <tcToSearch> to search for 
	 *			: in <tcString>. 
	 *			: By default, .frAt() searches for the first occurrence of <tcToSearch> (tnOccurrence = 1). 
	 *			: 
	 * Returns		: Numeric. .frAt() returns an integer indicating the position of the first character for a 
	 *			: character expression or memo field within another character expression or memo field, 
	 *			: beginning from the leftmost character. If the expression or field is not found, or if 
	 *			: <tnOccurrence> is greater than the number of times <tcToSearch> occurs in  <tcString>, frAt() 
	 *			: returns 0.
	 *			:
	 * Author	 	: Jar c 19.12.2017
	 */

	func frAt(tcToSearch, tcString, tnOccurrence) {
	
		tnOccurrence 	= this.frSetIfEmpty(tnOccurrence, 1)
		lnRet 		= 0
		lnCounted 	= 0
		
		for n = 1 to tnOccurrence {
			lnRet = SubStr(tcString, tcToSearch)
			if lnRet > 0 {
				tcString = SubStr(tcString, lnRet + 1)
				if n < tnOccurrence {
					lnCounted += lnRet
				}
			else
				lnCounted = 0
			}
		}
		
		return lnCounted + lnRet
	}


	/*
	 * Syntax		: lnPos = frAtC(tcToSearch, tcString, tnOccurrence)
	 * Description		: Searches a character expression for the occurrence of another character expression 
	 *			: without regard for the case of these two expressions.
	 *			:
	 * Arguments   		: <tcToSearch>
	 *			: Specifies the character expression to search for in <tcString>.
	 *			:
	 *			: <tcString> 
	 *			: Specifies the character expression to search for <tcToSearch>. 
	 *			:
	 *			: <tnOccurrence> 
	 *			: Specifies which occurrence, first, second, third, and so on, of <tcToSearch> to search for
	 *			: in tcString. 
	 *			: By default, .frAtC() searches for the first occurrence of <tcToSearch> (tnOccurrence = 1). 
	 *			: 
	 * Returns		: Numeric. .frAtC() returns an integer indicating the position of the first character for a 
	 *			: character expression or memo field within another character expression or memo field, 
	 *			: beginning from the leftmost character. If the expression or field is not found, or if 
	 *			: <tnOccurrence> is greater than the number of times <tcToSearch> occurs in <tcString>, frAtC()
	 *			: returns 0.
	 *			:
	 * Author	 	: Jar c 04.02.2018
	 */

	func frAtC(tcToSearch, tcString, tnOccurrence) {
		return this.frAt(Lower(tcToSearch), Lower(tcString), tnOccurrence)
	}

	/*
	 * Syntax		: lcReturnValue = frChr(tnExpression)
	 * Description		: Returns the character associated with the specified numeric ANSI code.
	 *			:
	 * Arguments		: <tnExpression>
	 *			: Specifies a number between 0 and 255 whose equivalent ANSI character frChr() returns.
	 *			:
	 * Returns		: <lcReturnValue>
	 *			: Returns a single character corresponding to the numeric position of the character in the
	 *			: character table of the current code page.
	 * 			:
	 * Remarks		: tnExpression must be between 0 and 255
	 *			:
	 * Author		: Jar C 02.02.2018
	 */
	
	func frChr(tnExpression) {
	 	return Char(tnExpression)
	}



	/*
	 * Syntax			: ldDate = frCToD(tcExpression)
	 * Description		: Converts a character expression to a date expression.
	 * 					:
	 * Arguments			: <tcExpression>
	 *					: Specifies a Date or a DateTime expression.
	 *					:
	 * Returns			: <ldDate>
	 *					: Returns a date data type
	 *					:
	 * Author			: Jar C 30.05.2019
	 */

	func frCToD(tcDate) {
		
		lcDate = ""
		lcDateSeparator = this.frSubStr(this._set_dateformat, 3, 1)
		lnDayPosition = this._getDayPosition()
		lnLenDate = len(tcDate)
		laDate = []
		lnDatePos = 1
		for i = 1 to lnLenDate {
			lcDigit = this.frSubStr(tcDate, i, 1)
			if IsDigit(lcDigit) {
				lcChr = lcDigit
			else
				lcChr = lcDateSeparator
			}
			lcDate = lcDate + lcChr
		}
		
		lnElements = this.frALines(laDate, lcDate, lcDateSeparator)
		if lnDayPosition = 2 {
			lnMonth = this.frVal(laDate[1])
			lnDay = this.frVal(laDate[2])
			lnYear = this.frVal(laDate[3])
		else
			if lnDayPosition = 3 {
				lnYear = this.frVal(laDate[1])
				lnMonth = this.frVal(laDate[2])
				lnDay = this.frVal(laDate[3])
			else
				lnDay = this.frVal(laDate[1])
				lnMonth = this.frVal(laDate[2])
				lnYear = this.frVal(laDate[3])
			}
		}
		
		return this.frDate(lnYear, lnMonth, lnDay)

	}


	/*
	 * Syntax		: lcReturnValue = frDate(tnYear, tnMonth, tnDay)
	 * Description	: Returns the current system date, which is controlled by the operating system, or creates a date.
	 * 				:
	 * Arguments		: <tnYear>
	 *				: Specifies the year to return by the function.
	 *				:
	 *				: <tnMonth>
	 *				: Specifies the month to return by the function.
	 *				:
	 *				: <tnDay>
	 *				: Specifies the day to return by the function.
	 *				:
	 *				: When we specify Null arguments the function returns the current system date.
	 *				:
	 * Returns		: <ldReturnValue>
	 *				: Returns a date with the current specified date format.
	 *				:
	 * Author		: Jar C 16.05.2018
	 */
	func frDate(tnYear, tnMonth, tnDay) {

		ldDate = new DateClass(tnYear, tnMonth, tnDay)
		return ldDate
		
	}

	/*
	 * Syntax		: lcReturnValue = frDateTime(tnYear, tnMonth, tnDay, tnHours, tnMinutes, tnSeconds)
	 * Description	: Returns the current system date and time, which is controlled by the operating system, or creates a date time value.
	 * 			:
	 * Arguments		: <tnYear>
	 *			: Specifies the year to return by the function.
	 *			:
	 *			: <tnMonth>
	 *			: Specifies the month to return by the function.
	 *			:
	 *			: <tnDay>
	 *			: Specifies the day to return by the function.
	 *			:
	 *			: When we specify Null arguments the function returns the current system date.
	 *			:
	 * Returns		: <lcReturnValue>
	 *			: Returns a date with the current specified date format.
	 *			:
	 * Author		: Jar C 29.11.2018
	 */
	func frDateTime(tnYear, tnMonth, tnDay, tnHours, tnMinutes, tnSeconds) {

		ldDateTime = new DateTimeClass(tnYear, tnMonth, tnDay, tnHours, tnMinutes, tnSeconds)
		return ldDateTime
		
	}


	/*
	 * Syntax		: lcReturnValue = frDToC(tdExpression|ttExpresion, tnOutputFormat)
	 * Description		: Returns a character string as a date format from a Date or a DateTime expression.
	 * 			:
	 * Arguments		: <tdExpression|ttExpression>
	 *			: Specifies a Date or a DateTime expression.
	 *			:
	 *			: <tnOutputFormat>
	 *			: When 1 returns always the "yyyymmdd" format.
	 *			:
	 * Returns		: <lcReturnValue>
	 *			: Returns a string with the date according with the Output format
	 *			:
	 * Author		: Jar C 17.12.2018
	 */
	func frDToC(tuExpression, tuOutput) {
	
		lcRet = ""
		lcExpressionType = this.frVarType(tuExpression) 
		if lcExpressionType = this._date_type or lcExpressionType = this._datetime_type {
			if not this.frEmpty(tuOutput) {
				lcRet = this.frTransform(tuExpression.nYear, "@L 9999") + 
						this.frTransform(tuExpression.nMonth, "@L 99") +
						this.frTransform(tuExpression.nDay, "@L 99")
			else
				lcRet = this._DateFormat(tuExpression.nYear, tuExpression.nMonth, tuExpression.nDay)
			}
		}
		return lcRet
	}
	 





	/*
	 * Syntax		: llReturnValue = frEmpty(tuExpression)
	 * Description	: Determines whether an expression evaluates to empty.
	 *				:
	 * Arguments   	: <tuExpression>
	 *				: Specifies the expression that EMPTY() evaluates. You can specify an expression with Character, 
	 *				: Numeric, or logical type.
	 *				:
	 * Returns		: <llReturnValue> Logical
	 *				:
	 * Author	 	: Jar C 06.09.2017
	 */
	func frEmpty(tuExpression) {
	
		llRet = False
	
		if IsNull(tuExpression) {
			llRet = True
		else
			lcExpressionType = this.frVarType(tuExpression)
			
			if lcExpressionType = this._character_type {
				if IsSpace(tuExpression) {
					llRet = True
				}
			else
				if lcExpressionType = this._numeric_type {
					if tuExpression = 0 {
						llRet = True
					}
				}
			}
		}
		
		return llRet
	}



	/*
	 * Syntax		: llReturnValue = frFile(tcFileName, tnFlag)
	 * Description		: Checks if the specified file exists on disk.
	 *			:
	 * Arguments   		: <tcFileName>
	 *			: Specifies the name of the file to check. tcFileName must include 
	 *			: the file extension. You can include a path with the file name to 
	 *			: search for a file in a directory or on a drive other than the current
	 *			: directory or drive. 
	 *			: 
	 *			: <tnFlag> 
	 *			: tnFlag was included for future compatibility.
	 *			: In this version, It always returns true whenever the file exists on disk.
	 *			:
	 * Returns		: <llReturnValue> Logical
	 *			: True if file exists on disk.
	 *			: False if file doesn't exist on disk.
	 *			:
	 * Author	 	: Jar C 18.02.2018
	 */

	func frFile(tcFileName, tnFlag) {

		// Jar 18.02.2018 
		// At moment tnFlag isn't used

		return Fexists(tcFileName)	
	}


	/*
	 * Syntax		: lcReturnValue = frFileToStr(tcFileName)
	 * Description		: Returns the contents of a file as a character string.
	 *			:
	 * Arguments		: <tcFileName>
	 * 			: Specifies the name of the file whose contents are returned as a character 
	 *			: string. If the file is in a directory other than the current default directory, 
	 *			: include a path with the file name.
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: A character string with the content of the specified file.
	 *			:
	 * Author	 	: Jar C 18.02.2018
	 */

	func frFileToStr(tcFileName) {
		return read(tcFileName)
	}


	/*
	 * Syntax		: lcReturnValue = frStr(tnValue, tnLen, tnDec)
	 * Description		: Returns the character equivalent of a numeric expression.
	 *			:
	 * Arguments	   	: <tnValue>
	 *			: Specifies the numeric expression to evaluate.
	 *			: 
	 *			: <tnLen>
	 *			: Specifies the length of the character string returned. If tnLen is 0, tnLen defaults to 10 characters. 
	 *			: If tnLen < 0 returns one string with same length as the number.
	 *			: Note  
	 *			: If the expression contains a decimal point, the length includes one character for the decimal point and one character 
 	 *			: for each digit in the character string.
	 *			: 
	 *			: <tnDec> 
	 *			: Specifies the number of decimal places in the character string returned. To specify the number of decimal places using 
	 *			: tnDec, you must include nLength. If nDecimalPlaces is omitted, the number of decimal places defaults to zero (0). 
	 *			: 
	 * Returns		: Character data type. frStr() returns a character string equivalent to the specified numeric expression. 
	 *			: 
	 *			: Depending on certain conditions, frStr() can return the following: 
	 *			: If you specify fewer decimal places than exist in tnValue, the return value is rounded up. To round results to the nearest 
	 *			: decimal place instead of upward, include the ROUND( ) function. For more information, see ROUND( ) Function.
	 *			: If nExpression is an integer, and nLength is less than the number of digits in nExpression, frStr( ) returns a string of 
	 *			: asterisks, indicating numeric overflow.
	 *			: If nExpression contains a decimal point, and nLength is equal to or less than the number of digits to the left of the decimal
	 *			: point, frStr( ) returns a string of asterisks, indicating numeric overflow.
	 *			: If nLength is greater than the length of the value evaluated by nExpression, frStr( ) returns a character string padded with
	 * 			: leading spaces.
	 *			: If nExpression has Numeric or Float type, and nLength is less than the number of digits in nExpression, and , frStr( ) 
	 *			: returns a value using scientific notation. 
	 *			: 
	 * Author	 	: Jar 05.12.2017
	 */

	func frStr(tnValue, tnLen, tnDec) {

		lcZeroAsString = "0"
		lcDecimalPoint = this._decimal_point
		laList = []
		lnElements = this.frALines(laList, String(tnValue), lcDecimalPoint)

		if lnElements = 1 {
			Add(laList, lcZeroAsString)
		}
	
		if tnDec > 0 {
			laList[2] = Left(laList[2] + Copy(lcZeroAsString, tnDec), tnDec)
			lcRet = laList[1] + lcDecimalPoint + laList[2]
		else
			lcRet = laList[1]
		}

		if tnLen < 0 {
			lcRet = Trim(lcRet)	
		else
			tnLen = this.frSetIfEmpty(tnLen, 10)
			lcRet = Right(Copy(this._space, tnLen) + lcRet, tnLen)
		}

		return lcRet 
	}	

	/*
	 * Syntax		: tuReturnValue = frSetIfEmpty(tuValue, tuNewValue)
	 * Description		: Set a Value into a variable if the variable value is empty, null or zero.
	 *			:
	 * Arguments   		: <tuValue>
	 *			: The value to evaluate.
	 *			:
	 *			: <tuNewValue>
	 *			: The value to set if tuValue is empty.
	 *			:
	 * Returns		: tuNewValue if tuValue is empty, otherwise returns the original value.
	 *			:
	 * Remarks		: This function doesn't exist in VFP.
	 *			:
	 * Author	 	: Jar C 12.09.2017
	 */

	func frSetIfEmpty(tuValue, tuNewValue) {

		if this.frEmpty(tuValue) {
			tuValue = tuNewValue
		}
		return tuValue
	}

	/*
	 * Syntax		: lcReturnValue = frSpace(tnSpaces)
	 * Description		: Returns a character string composed of a specified number of spaces.
	 *			:
	 * Arguments   		: <tnSpaces>
	 *			: Specifies the number of spaces that frSpace() returns.
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: Character
	 *			:
	 * Author	 	: Jar C 07.01.2018
	 */

	func frSpace(tnSpaces) {
		return Copy(this._space, tnSpaces)
	}

	/*
	 * Syntax		: llReturnValue = frInList(tuExpression, taList)
	 * Description		: Determines whether an expression matches another expression in a set of expressions.
	 *			:
	 * Arguments   		: <tuExpression>
	 *			: Specifies the expression frInList() searches for in the List.
	 *			:
	 *			: <taList>
	 *			: Specifies the List of expressions to search. You must include at least one element in the list.
	 *			: The expressions in the list of expressions needn't to be of the same data type. 
	 *			:
	 * Returns		: <luReturnValue> Null or logical value.
	 *			:
	 * Author	 	: Jar C 12.01.2018
	 */

	func frInList(tuExpression, taList) {

		if tuExpression = Null {
			llReturn = Null
		else
			llReturn = False
			
			for x in taList {
			
				if Type(tuExpression) = Type(x) {
					if tuExpression = x {
						llReturn = True
					}
				}
			}
		}
		return llReturn 
	}
	
	
	/*
	 * Syntax		: lcReturnValue = frForcePath(tcFileName, tcPath)
	 * Description		: Returns a file name with a new path name substituted for the old one.
	 *			:
	 * Arguments   		: <tcFileName>
	 *			: Specifies the file name (with or without a path or extension), which will get a new path.
	 *			:
	 *			: <tcPath>
	 *			: Specifies the new path for tcFileName.
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: Returns a file name with a new path name substituted for the old one.
	 *			:
	 * Author	 	: Jar C 08.02.2018
	 */
	func frForcePath(tcFileName, tcPath) {
		return this.frAddBs(this.frJustPath(tcPath)) + this.frJustFName(tcFileName)
	}
	

	/*
	 * Syntax		: lcReturnValue = frAllTrim(tcExpression, tcCharacter)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar 09.09.2017
	 */

	func frAllTrim(tcExpression, tcCharacter) {
	
		tcCharacter = this.frSetIfEmpty(tcCharacter, this._space)
	
		return this.frRTrim(this.frLTrim(tcExpression, tcCharacter), tcCharacter)
	}

	/*
	 * Syntax		: lcRet = frLTrim(tcExpression, tcCharacter)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 05.09.2016
	 */

	func frLTrim(tcExpression, tcCharacter) {

		lcRet = this._empty_char
		if not this.frEmpty(tcExpression) {

			lnLenExpression = Len(tcExpression)
			tcCharacter = this.frSetIfEmpty(tcCharacter, this._space)
			if lnLenExpression > 0 {
				for i = 1 to lnLenExpression {
					if SubStr(tcExpression, i, 1) != tcCharacter {
						for n = i to lnLenExpression {
							lcRet += SubStr(tcExpression, n, 1)
						}
						exit
					}
				}
			}	
		}
			
		return lcRet
	}	

	/*
	 * Syntax		: lcReturnValue = frJustDrive(tcPath)
	 * Description		: Returns the drive letter from a complete path.
	 *			:
	 * Arguments   		: <tcPath>
	 *			: Specifies the complete path name for which you want only the drive.
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: Returns the drive letter from a complete path.
	 *			:
	 * Author	 	: Jar C 08.02.2018
	 */
	func frJustDrive(tcPath) {
	
		lcReturnValue = this._empty_char
		if this.frSubStr(tcPath, 2, 1) = ":" {
			lcReturnValue = left(tcPath, 2)
		}
		return lcReturnValue
	}


	
	/*
	 * Syntax		: lcReturnValue = frJustExt(tcPath)
	 * Description		: Returns the characters of a file extension from a complete path.
	 *			:
	 * Arguments   		: <tcPath>
	 *			: Specifies the name, which may include the full path, of the file for which you want only the extension. 
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: Returns the drive characters of a file extension from a complete path.
	 *			:
	 * Author	 	: Jar C 08.02.2018
	 */
	func frJustExt(tcPath) {
	
		lcReturnValue = this._empty_char
		lnPos = this.frAt(".", tcPath, Null)
		if this.frBetween(lnPos, 0, Len(tcPath)) {
			lcReturnValue = this.frSubStr(tcPath, lnPos + 1, 0)
		}
		return lcReturnValue
	}
	

	/*
	 * Syntax		: lcReturnValue = frJustStem(tcPath)
	 * Description		: Returns the stem name (the file name before the extension) from a complete path and file name.
	 *			:
	 * Arguments   		: <tcPath>
	 *			: Specifies the name (including path) of the file for which you want only the stem. 
	 *			:
	 * Returns		: <lcReturnValue> 
	 *			: Returns the stem name of a file from a complete path.
	 *			:
	 * Author	 	: Jar C 08.02.2018
	 */
	func frJustStem(tcPath) {
	
		lcFileName = this.frJustFName(tcPath)
		lcExtension = "." + this.frJustExt(tcPath)
		
		return this.frStrTran(lcFileName, lcExtension, this._empty_char)
	}

	/*
	 * Syntax		: lcRet = frRTrim(tcExpression, tcCharacter)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar 05.09.2017
	 */

	func frRTrim(tcExpression, tcCharacter) {

		lcRet = this._empty_char
		if not this.frEmpty(tcExpression) {

			lnLenExpression = Len(tcExpression)
			tcCharacter = this.frSetIfEmpty(tcCharacter, this._space)
			if lnLenExpression > 0 {
				for i = lnLenExpression to 1 step -1 {
					if SubStr(tcExpression, i, 1) != tcCharacter {
						for n = 1 to i {
							lcRet += SubStr(tcExpression, n, 1)
						}
						exit
					}
				}
			}
		}
			
		return lcRet
	}

	/*
	 * Syntax		: tcReturnValue = frJustPath(tcExpression)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 08.10.2017
	 */

	func frJustPath(tcExpression) {

		laList = []
		lnElements = this.frALines(laList, tcExpression, this._back_slash)
		lcRet = this._empty_char
	
		for i = 1 to lnElements - 1 {
			lcRet = lcRet + laList[i] + this._back_slash
		}	
	
		return Left(lcRet, Len(lcRet) - 1)
	}	

	/*
	 * Syntax		: tcReturnValue = frForceExt(tcFileName, tcNewExtension)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 08.09.2017
	 */

	func frForceExt(tcFileName, tcNewExtension) {

		laList = []
		lcSeparator = "."
		this.frALines(laList, tcFileName, lcSeparator)
	
		return laList[1] + lcSeparator + tcNewExtension
	}

	/*
	 * Syntax		: tnReturnValue = frALines(taList, tcExpression, tcSeparator)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 07.09.2017
	 */

	func frALines(taList, tcExpression, tcSeparator) {

		taList = Str2List(SubStr(tcExpression, tcSeparator, nl))
	
		return Len(taList)
	}

	/*
	 * Syntax		: tcReturnValue = frJustFName(tcExpression)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 08.10.2017
	 */

	func frJustFName(tcExpression) {	

		laList = []
		lnElements = this.frALines(laList, tcExpression, this._back_slash)

		return laList[lnElements]
	}

	/*
	 * Syntax		: tcReturnValue = frPadL(tcString, tnLen, tcChar)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 06.12.2017
	 */

	func frPadL(tcString, tnLen, tcChar) {
		return Right(Copy(this.frSetIfEmpty(tcChar, this._space), tnLen) + tcString, tnLen)
	}

	/*
	 * Syntax		: tcReturnValue = frPadR(tcString, tnLen, tcChar)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 18.12.2017
	 */

	func frPadR(tcString, tnLen, tcChar) {
		return Left(tcString + Copy(this.frSetIfEmpty(tcChar, this._space), tnLen), tnLen)
	}


	/*
	 * Syntax		: tcReturnValue = frProper(tcExpression)
	 * Description		: Returns from a character expression a string capitalized as appropriate for proper names.
	 *			:
	 * Arguments		: <tcExpression>
	 *			: Specifies the character expression from which frProper() returns a capitalized character string.
	 *			:
	 * Returns		: <tcReturnValue> 
	 *			:
	 * Author		: Jar C 04.05.2017
	 */
	
	func frProper(tcExpression) {
		lcLetters = "abcdefghijklmnopqrstuvxywz"
		tcExpression = Lower(tcExpression)
		for lcLetter in lcLetters {
			tcExpression = SubStr(tcExpression, this._space + lcLetter, this._space + Upper(lcLetter))
		}
		tcExpression = Upper(Left(tcExpression, 1)) + SubStr(tcExpression, 2)
	
		return tcExpression
	}


	/*
	 * Syntax		: tcReturnValue = frReplicate(tcString, tnTimes)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 07.09.2017
	 */

	func frReplicate(tcString, tnTimes) {
		return Copy(tcString, tnTimes)
	}

	/*
	 * Syntax		: tnReturnValue = frLen(tcString)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 11.10.2017
	 */

	func frLen(tcString) {
		return Len(tcString)
	}


	
	/*
	 * Syntax		: tcReturnValue = frStuff(tcExpression, tnStartRep, tnCharRep, tcToReplace)
	 * Description		: Returns a new character string replaced by a specified number of characters in a character 
	 *			: expression with another character expression.
	 *			:
	 * Arguments   		: <tcExpression>
	 *			: Specify the character expression in which the replacement occurs.
	 *			: 
	 *			: <tnStartRep>
	 *			: Specify the position in <tcExpression> where the replacement begins.
	 *			: 
	 *			: <tnCharRep>
	 *			: Specifies the number of characters to be replaced. If <tnCharRep> is 0, the replacement string 
	 *			: <tcToReplace> is inserted into <tcExpression>.
	 *			: 
	 *			: <tcToReplace>
	 *			: Specifies the replacement character expression. If <tcToReplace> is an empty string, the number of 
	 *			: characters specified by <tnCharRep> are removed from <tcExpression>.
	 *			:
	 * Returns		: Character 
	 *			: 
	 * Author	 	: Jar C 04.04.2018
	 */
	 
	func frStuff(tcExpression, tnStartRep, tnCharRep, tcToReplace) {
	
		lcStart = Left(tcExpression, tnStartRep - 1)
		lcEnd = SubStr(tcExpression, tnStartRep + tnCharRep)
	
		return lcStart + tcToReplace + lcEnd
	}


	/*
	 * Syntax		: tcReturnValue = frSubStr(tcString, tnInitialPosition, tnNumberBytes)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 05.11.2017
	 */

	func frSubStr(tcString, tnInitialPosition, tnNumberBytes) {
	
		lcRet = this._empty_char
		if this.frEmpty(tnNumberBytes) {
			lcRet = SubStr(tcString, tnInitialPosition)
		else
			lcRet = SubStr(tcString, tnInitialPosition, tnNumberBytes)
		}
		
		return lcRet
	}

	/*
	 * Syntax		: tcReturnValue = frStrTran(tcString, tcOldString, tcNewString)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			: 
	 * Author	 	: Jar C 12.09.2017
	 */

	func frStrTran(tcString, tcOldString, tcNewString) {
		return SubStr(tcString, tcOldString, tcNewString)
	}

	/*
	 * Syntax		: lcRet = frListToString(taList)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			:
	 * Remarks		: This function doesn't exist in VFP.
	 *			:
	 * Author	 	: Jar C 04.11.2017
	 */

	func frListToString(taList) {
		
		lcRet = this._empty_char
		for lcX in taList {
			lcRet += lcX
		}
		return lcRet
	}		

	/*
	 * Syntax		: lnInt = frInt(tnExpression)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			:
	 * Author	 	: Jar C 23.01.2018
	 */

	func frInt(tnExpression) {
		return this.frVal(this.frStr(tnExpression, 16, Null))
	}

	/*
	 * Syntax		: laList = frStringToList(tcExpression)
	 * Description		: 
	 *			:
	 * Arguments   		: 
	 *			: 
	 * Returns		: 
	 *			:
	 * Remarks		: This function doesn't exist in VFP.
	 *			:
	 * Author	 	: Jar C 07.09.2017
	 */

	func frStringToList(tcExpression) {
		laList = []
		for lcX in tcExpression {
			Add(laList, lcX)
		}
		return laList
	}

	/*
	 * Syntax		: luReturnValue = frIIf(tlExpression, tuReturnIfTrue, tuReturnIfFalse)
	 * Description		: Returns one of two values depending on the value of a logical expression.
	 *			:
	 * Arguments   		: <tlExpression>
	 *			: Specifies the logical expression that frIIf() evaluates.
	 *			:
	 *			: <tuReturnTrue>, <tuReturnFalse>
	 *			: If tlExpression evaluates to True, tuReturnIfTrue is returned and tuReturnIfFalse is not evaluated. 
	 *			: If tlExpression evaluates to False or Null, tuReturnIfFalse is returned and tuReturnIfTrue is not evaluated.
	 *			: 
	 * Returns		: <luReturnValue> Defined by <tuReturnIfTrue> or <tuReturnIfFalse>
	 *			: 
	 * Author	 	: Jar C 05.10.2017
	 */

	func frIIf(tlExpression, tuReturnIfTrue, tuReturnIfFalse) {
	
		if IsNull(tlExpression) {
			tuReturnValue = tuReturnIfFalse
		else
			if tlExpression {
				tuReturnValue = tuReturnIfTrue
			else
				tuReturnValue = tuReturnIfFalse
			}
		}
		return tuReturnValue
	}

	
	

	/*
	 * Syntax		: luReturnValue = frVal(tcExpression)
	 * Description		: Returns a numeric value from a character expression composed of numbers
	 *			:
	 * Arguments   		: <tcExpression>
	 *			: Specifies a character expression composed of up to 16 numbers.
	 *			:
	 * Returns		: <tnValue>
	 *			: Return a numeric value. 
	 *			: 
	 * Author	 	: Jar C 05.10.2017
	 */

	func frVal(tcExpression) {
		return Number(this.frAllTrim(tcExpression, Null))
	}



	/*
	 * Syntax		: luReturnValue = frBetween(tuTestValue, tuLowValue, tuHighValue)
	 * Description		: Determines whether the value of an expression is inclusively between the 
	 *			: values of two expressions of the same type.
	 *			:
	 * Arguments   		: <tuTestValue>
	 *			: Specifies an expression to evaluate.
	 *			:
	 *			: <tuLowValue>
	 *			: Specifies the lower value in the range.
	 *			:
	 *			: <tuHighValue>
	 *			: Specifies the higher value in the range.
	 *			:
	 * Returns		: <luReturnValue>
	 *			: Returns a logical order null value. 
	 *			: 
	 * Author	 	: Jar C 29.01.2018
	 */

	func frBetween(tuTestValue, tuLowValue, tuHighValue) {

		llOk = True
		if IsNull(tuTestValue) or IsNull(tuLowValue) or IsNull(tuHighValue) {
			luRet = Null
			llOk = False
		}
		
		if llOk {
			if tuTestValue >= tuLowValue and tuTestValue <= tuHighValue {
				luRet = True
			else
				luRet = False
			}
		}
		
		return luRet
    	}

	
	/*
	 * Syntax		: lcReturnValue = frSetCentury(tcStatus)
	 * Description		: Returns the current value of the century format and sets a new one when specified.
	 * 			:
	 * Arguments		: <tcStatus>
	 *			: Specifies the century status. 
	 *			:
	 *			: "OFF" (Default) Shows the year with only two digits.
	 *			:
	 *			: "ON" Shows the year in a four-digits format.
	 *			:
	 * Returns		: <lcReturnValue>
	 *			: Returns the current value of the century format.
	 *			:
	 * Author		: Jar C 16.05.2018
	 */
	func frSetCentury(tcStatus) {
	
		lcRet = this.frIIf(this._set_century = this._on, this._on, this._off)
		laStatus = [this._on, this._off]
		if not this.frEmpty(tcStatus) {
			if this.frInList(upper(tcStatus), laStatus) {
				this._set_century = upper(tcStatus)
			}
		}
		return lcRet
	}


	/*
	 * Syntax		: lcReturnValue = frSetDate(tcDateFormat)
	 * Description		: Returns the current value of the date format and sets a new one when specified.
	 * 			:
	 * Arguments		: <tcDateFormat>
	 *			: Specifies the date format 
	 *			: Here are the settings and the resulting date formats:
	 *			:
	 *			: 
	 *			: 	Setting  			Format  
	 *			: --------------------------------------------------
	 *			: 	AMERICAN			mm/dd/yy
 	 *			: 	ANSI				yy.mm.dd
 	 *			: 	BRITISH/FRENCH			dd/mm/yy
	 *			: 	BRITISH				dd/mm/yy
	 *			: 	FRENCH				dd/mm/yy
	 *			: 	GERMAN				dd.mm.yy
	 *			: 	ITALIAN				dd-mm-yy
	 *			: 	JAPAN				yy/mm/dd
	 *			: 	TAIWAN				yy/mm/dd
	 *			: 	USA				mm-dd-yy
	 *			: 	MDY				mm/dd/yy
	 *			: 	DMY				dd/mm/yy
	 *			: 	YMD				yy/mm/dd
	 *			: --------------------------------------------------
	 *			:
	 * Returns		: <lcReturnValue>
	 *			: Returns the current value of the date format.
	 *			:
	 * Author		: Jar C 16.05.2018
	 */
	func frSetDate(tcDateFormat) {

		laFormats = [this._date_american, this._date_ansi, this._date_british_french, this._date_british, 
					this._date_french, this._date_german, this._date_italian, this._date_japan, 
					this._date_taiwan, this._date_usa, this._date_mdy, this._date_dmy, this._date_ymd]

		lcRet = this._set_date
		if not this.frEmpty(tcDateFormat) {
			if this.frInList(upper(tcDateFormat), laFormats) {
				this._set_date = upper(tcDateFormat)
				this._set_dateformat = this._getDateFormat()
			}
		}
		return lcRet
	}

	

	/*
	 * Syntax		: frSetSeparatorTo(tuExpression)
	 * Description		: Specifies the character for the numeric place separator.
	 *			:
	 * Arguments   		: <tuExpression>
	 *			: Specifies the character for the numeric place separator. 
	 *			:
	 *			: Use frSetSeparatorTo() to change the numeric place separator from default, for example space " " or a comma ",".
	 *			: Issue frSetSeparatorTo(Null) to reset the value to its default.
	 *			:
	 * Returns		: None
	 *			:  
	 * Author	 	: Jar C 30.01.2018
	 */

	func frSetSeparatorTo(tuExpression) {

		if IsNull(tuExpression) {
			this._set_separator = this._separator
		}
		
		if this.frVarType(tuExpression) = this._character_type {
			this._set_separator = tuExpression
		}
    	}
	
	

	/*
	 * Syntax		: tcReturnValue = frTransform(tuExpression, tcFormatCodes)
	 * Description		: Returns a character string from an expression in a format determined by a format code.
	 *			:
	 * Arguments   		: <tuExpression>
	 *			: Specifies the expression to format.
	 *			:
	 *			: <tcFormatCodes>		
	 *			: Specifies one or more format codes that determine how to format the expression. 
	 *			: 
	 *			: Note
	 *			: The following table lists the available format codes for tcFormatCodes.
	 *			: 
	 *			:  ---------------------------------------------------------------------------------------
	 *			:	Format Code	Description
	 *			:  ---------------------------------------------------------------------------------------
	 *			: 	@!			Converts an entire character string to uppercase.
	 *			:  	@T 			Trims leading and trailing spaces from character values.
	 *			: 	@B			Left-justifies Numeric data within the display region.
	 *			: 	@L			Pads numeric and string data with leading zeros.
	 *			:	@C			Appends CR to positive numeric values to indicate a credit.
	 *			:	@X			Appends DB to negative numeric values to indicate a debit.
	 *			:  ---------------------------------------------------------------------------------------
	 *			: 
	 * Returns		: <tcReturnValue>
	 *			: 
	 * Author	 	: Jar C 08.01.2018
	 *			: Jar U 02.02.2018 Added "@L" function
	 *			: Jar U 04.02.2018 Added "@X" function and some comments.
	 */

	func frTransform(tuExpression, tcFormatCodes) {
	
		tcReturnValue = this._empty_char
		if IsNull(tcFormatCodes) {
			tcReturnValue = this._empty_char + tuExpression
		else
			if tcFormatCodes = this._empty_char {
				tcReturnValue = this._empty_char + tuExpression
			else
				lcFunction = this._empty_char
				lcFormat = this._empty_char
				llOk = True
				if Left(tcFormatCodes, 1) != "@" {
					lcFormat = tcFormatCodes
				else
					lnPos = this.frAt(this._space, tcFormatCodes, 1)
					if lnPos = 0 {
						lcFunction = tcFormatCodes
						lcFormat = ""
					else
						lcFunction = left(tcFormatCodes, lnPos - 1)
						lcFormat = this.frSubStr(tcFormatCodes, lnPos + 1, 0)
					}
				}
				
				if this.frVarType(tuExpression) = this._character_type and llOk {
				
					laPictureCodes = ["9", "X", "!", "x", "A", "a", "#"]
				
					if Len(this.frAllTrim(lcFunction, Null)) = 2 {
						// @!			Converts an entire character string to uppercase.
						if llOk and Left(lcFunction, 2) = "@!" {
							llOk = False
							tcReturnValue = this._process_format_for_string(Upper(tuExpression), lcFormat, laPictureCodes)
						}
						// @T 			Trims leading and trailing spaces from character values.
						if llOk and Left(lcFunction, 2) = "@T" {
							llOk = False
								
							/*
							 * This was the original code but the compiler returns an error. 
							 * However the problem was solved with two lines of code instead one.
							 *
							 * tcReturnValue = this._process_format_for_string(this.frAllTrim(tuExpression, Null), lcFormat, laPictureCodes)
							 */
							lcValue = this.frAllTrim(tuExpression, Null)
							tcReturnValue = this._process_format_for_string(lcValue, lcFormat, laPictureCodes)
						}
						// @L			Pads numeric and string data with leading zeros.
						if llOk and Left(lcFunction, 2) = "@L" {
							llOk = False
							lcValue = this.frAllTrim(tuExpression, Null)
							tcReturnValue = this.frPadL(this.frAllTrim(this._process_format_for_string(lcValue, lcFormat, laPictureCodes), 
												Null), Len(lcFormat), "0")
						}
					else
						if Len(this.frAllTrim(lcFunction, Null)) = 3 {
						
						}
					}
				else
					if this.frVarType(tuExpression) = this._numeric_type and llOk {
		
						lnOriginalExpression = tuExpression
						laPictureCodes = ["9", "#"]		
						tuExpression = this._empty_char + tuExpression
						
						if Len(this.frAllTrim(lcFunction, Null)) = 2 {
							// @B			Left-justifies Numeric data within the display region.
							if llOk and Left(lcFunction, 2) = "@B" {
								llOk = False
								lcValue = this.frAllTrim(tuExpression, Null)
								lcValue = this.frPadR(lcValue, 16, Null)
								tcReturnValue = this._process_format_for_numeric(lcValue, lcFormat, laPictureCodes)
							}
							// @C			Appends CR to positive numeric values to indicate a credit.
							if llOk and Left(lcFunction, 2) = "@C" {
								llOk = False
								lcValue = this.frAllTrim(tuExpression, Null)
								lcValue = this.frPadL(lcValue, 19, Null)
								tcReturnValue = this._process_format_for_numeric(lcValue, lcFormat, laPictureCodes)
								if lnOriginalExpression > 0 {
									tcReturnValue += " CR"
								}
							}
							// @X			Appends DB to negative numeric values to indicate a debit.
							if llOk and Left(lcFunction, 2) = "@X" {
								llOk = False
								lcValue = this.frAllTrim(tuExpression, Null)
								lcValue = this.frPadL(lcValue, 19, Null)
								tcReturnValue = this._process_format_for_numeric(lcValue, lcFormat, laPictureCodes)
								if lnOriginalExpression < 0 {
									tcReturnValue += " DB"
								}
							}
							// @L			Pads numeric and string data with leading zeros.	
							if llOk and Left(lcFunction, 2) = "@L" {
								llOk = False
								lcValue = this.frAllTrim(tuExpression, Null)
								lcValue = this.frPadR(lcValue, 16, Null)
								tcReturnValue = this.frPadL(this.frAllTrim(this._process_format_for_numeric(lcValue, lcFormat, laPictureCodes), 
																Null), Len(lcFormat), "0")
							}
							
						}
						
						if Len(this.frAllTrim(lcFunction, Null)) = 0 {
							lcValue = this.frAllTrim(tuExpression, Null)
							lcValue = this.frPadL(lcValue, 19, Null)
							tcReturnValue = this._process_format_for_numeric(lcValue, lcFormat, laPictureCodes)
						}

						if Len(this.frAllTrim(lcFunction, Null)) = 3 {
							
						}
					}
				}
			}
		}
		return tcReturnValue
	}


	/*
	 * Syntax		: lcRet = frVarType(tuExpression)
	 * Description		: Returns the data type of an expression.
	 *			:
	 * Arguments   		: <tuExpression>
	 *			: Specifies the expression for which the data type is returned. frVartype() returns a
	 *			: single character indicating the data type of the expression. 
	 *			: The following table lists the characters that frVarType() returns for each data type.
	 *			:
	 *			: -------------------	---------------------------------------------------------------
	 *			: Return Value		Data Type
	 *			: -------------------	---------------------------------------------------------------
	 *			: C			Character
	 *			: N			Numeric
	 *			: A			List 
	 *			: O			Object 
	 *			: U			Undefined type
	 *			: -------------------	---------------------------------------------------------------
	 *			:
	 * Returns		: Character 
	 *			: 
	 * Author	 	: Jar C 01.09.2017
	 */

	func frVarType(tuExpression) {

		lcRet = this._undefined_type
		lcExpressionType = Type(tuExpression)

		if lcExpressionType = this._ring_character_type {
			lcRet = this._character_type
		else
			if lcExpressionType = this._ring_numeric_type {
				lcRet = this._numeric_type
			else
				if lcExpressionType = this._ring_list_type {
					lcRet = this._list_type
				else
					if lcExpressionType = this._ring_object_type {
					
						// if it's a object we need to check if it's date or datetime object
						if this._IsPorperty(tuExpression, "cClassType") {
							lcRet = tuExpression.cClassType
						else
							lcRet = this._object_type
						}
					
					}
				}
			}
		}
	
		return lcRet
	}	


	func _dateFormat(tnYear, tnMonth, tnDay) {
	
		lcFormat = "@L 99"
		lcMonth = this.frTransform(tnMonth, lcFormat)
		lcDay = this.frTransform(tnDay, lcFormat)

		if tnYear > 99 {
			lcYear = this.frTransform(tnYear, "@L 9999")
		else	
			lcYear = this.frTransform(tnYear, lcFormat)
		}
		
		if this._set_century = this._off {
			lcYear = right(lcYear, 2)
		else
			if len(lcYear) < 4 {
				lcYear = left("" + TimeList()[19], 2) + lcYear
			}
		}
	
		lcDateSeparator = this.frSubStr(this._set_dateformat, 3, 1)
		lnDayPosition = this._getDayPosition()

		/*
		if left(this._set_dateformat, 1) = "m" {
			lcRet = lcMonth + lcDateSeparator + lcDay + lcDateSeparator + lcYear
		else
			if left(this._set_dateformat, 1) = "y" {
				lcRet = lcYear + lcDateSeparator + lcMonth + lcDateSeparator + lcDay
			else
				lcRet = lcDay + lcDateSeparator + lcMonth + lcDateSeparator + lcYear
			}
		}
		*/
		
		if lnDayPosition = 2 {
			lcRet = lcMonth + lcDateSeparator + lcDay + lcDateSeparator + lcYear
		else
			if lnDayPosition = 3 {
				lcRet = lcYear + lcDateSeparator + lcMonth + lcDateSeparator + lcDay
			else
				lcRet = lcDay + lcDateSeparator + lcMonth + lcDateSeparator + lcYear
			}
		}
		
		return lcRet
	}


	/*
	 * private functions and properties for this class
	 */

	private
	
	func _getDayPosition() {
		if left(this._set_dateformat, 1) = "m" {
			lnRet = 2
		else
			if left(this._set_dateformat, 1) = "y" {
				lnRet = 3
			else
				lcRet = 1
			}
		}

		return lcRet
	
	}

	
	
	
	func _IsPorperty(toObject, tcPropertyName) {
	
		llRet = false
		if isobject(toObject) {
			laList = attributes(toObject)
			for name in laList {
				if lower(name) = lower(tcPropertyName) {
					llRet = true
					exit
				}
			}
		}
		return llRet
	}
	
	
	
	
	
	
	
	func _process_format_for_string(tcValue, tcFormat, taValidChars)
	
		lcRet = tcValue
		if Len(tcFormat) > 0 {
			lcRet = ""
			lnPos = 1
			for v in tcFormat {
				if this.frInList(v, taValidChars) {
					lcChar = this.frSubStr(tcValue, lnPos, 1)
					if v = "!" {
						lcChar = Upper(lcChar)
					}
				else
					lcChar = v
				}
				lcRet += lcChar
				lnPos++
				if lnPos > Len(tcValue) {
					exit
				}
			}
		}
		
		return lcRet

		
	func _process_format_for_numeric(tcValue, tcFormat, taValidChars)
	
		lcRet = tcValue
		if Len(tcFormat) > 0 {
			lcRet = ""
			lnValueDecimalPoint = this.frAt(this._decimal_point, tcValue, 1)
			lnMaskDecimalPoint = this.frAt(this._decimal_point, tcFormat, 1)
			
			/*
			 * Handle decimal portion of number
			 */
			lcDecimalRet = this._empty_char
			lcDecimalMask = this._empty_char
			lcDecimalValue = this._empty_char
			if lnMaskDecimalPoint > 0 {
				lcDecimalMask = this.frSubstr(tcFormat, lnMaskDecimalPoint, Null)
				lcIntMask = Left(tcFormat, lnMaskDecimalPoint - 1)
				lcDecimalValue = this.frReplicate("0", Len(lcDecimalMask))
			else	
				lcIntMask = tcFormat
			}
			
			if lnValueDecimalPoint > 0 {
				lcDecimalValue = this.frSubStr(tcValue, lnValueDecimalPoint, Null) + this.frReplicate("0", 19)
				lcDecimalValue = Left(lcDecimalValue, Len(lcDecimalMask))
				lcIntValue = Left(tcValue, lnValueDecimalPoint - 1)
			else
				lcIntValue = tcValue
			}
			
			/*
			 * Handle integer portion of number
			 */
			lnMaxChars = Len(lcIntValue)
			lcRet = this._empty_char
			for i = lnMaxChars to 1 step -1 {
				lcN = this.frSubStr(lcIntValue, i, 1)
				lcM = this.frSubstr(lcIntMask, i, 1)
				if IsDigit(lcN) {
					if this.frInList(lcM, taValidChars) {
						lcRet = lcN + lcRet
					else
						if lcM = this._separator {
							lcRet = lcN + this._set_separator + lcRet
						}
					}	
				else
					if lcN = this._space {
						lcRet = lcN + lcRet
					}
				}
			}
			lcRet += lcDecimalValue 
		}
		
		return lcRet

	
	func _GetDateObject(tnYear, tnMonth, tnDay) {
		oDt = new DateClass(tnYear, tnMonth, tnDay)
		return oDt
	}

	func _getDateFormat() {

		lcRet = this._dateform_dmy
		llOk = false

		if not llOk and this._set_date = this._date_american {
			llOk = true
			lcRet = this._dateform_american
		}
		if not llOk and this._set_date = this._date_ansi {
			llOk = true
			lcRet = this._dateform_ansi
		}
		if not llOk and this._set_date = this._date_british_french {
			llOk = true
			lcRet = this._dateform_british_french
		}
		if not llOk and this._set_date = this._date_british {
			llOk = true
			lcRet = this._dateform_british
		}
		if not llOk and this._set_date = this._date_french {
			llOk = true
			lcRet = this._dateform_french
		}
		if not llOk and this._set_date = this._date_german {
			llOk = true
			lcRet = this._dateform_german
		}
		if not llOk and this._set_date = this._date_italian {
			llOk = true
			lcRet = this._dateform_italian
		}
		if not llOk and this._set_date = this._date_japan {
			llOk = true
			lcRet = this._dateform_japan
		}
		if not llOk and this._set_date = this._date_taiwan {
			llOk = true
			lcRet = this._dateform_taiwan
		}
		if not llOk and this._set_date = this._date_usa {
			llOk = true
			lcRet = this._dateform_usa
		}
		if not llOk and this._set_date = this._date_mdy {
			llOk = true
			lcRet = this._dateform_mdy
		}
		if not llOk and this._set_date = this._date_dmy {
			llOk = true
			lcRet = this._dateform_dmy
		}
		if not llOk and this._set_date = this._date_ymd {
			llOk = true
			lcRet = this._dateform_ymd
		}

		return lcRet

	} 	

}


class DateClass {

	oFr = new frFunctions


	nYear = 0
	nMonth = 0
	nDay = 0
	cValue = ""
	cClassType = oFr._date_type

	_aDaysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
	_aDaysBeforeMonth = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	
	cMonth1 = "January"
	cMonth2 = "February"
	cMonth3 = "March"
	cMonth4 = "April"
	cMonth5 = "May"
	cMonth6 = "June"
	cMonth7 = "July"
	cMonth8 = "August"
	cMonth9 = "September"
	cMonth10 = "October"
	cMonth11 = "November"
	cMonth12 = "December"
	
	cMonthShort1 = "Jan"
	cMonthShort2 = "Feb"
	cMonthShort3 = "Mar"
	cMonthShort4 = "Apr"
	cMonthShort5 = "May"
	cMonthShort6 = "Jun"
	cMonthShort7 = "Jul"
	cMonthShort8 = "Aug"
	cMonthShort9 = "Sep"
	cMonthShort10 = "Oct"
	cMonthShort11 = "Nov"
	cMonthShort12 = "Dec"
	
	cDOWeek1 = "Monday"
	cDOWeek2 = "Tuesday"
	cDOWeek3 = "Wednesday"
	cDOWeek4 = "Thursday"
	cDOWeek5 = "Friday"
	cDOWeek6 = "Saturday"
	cDOWeek7 = "Sunday"
	
	cDOWeekShort1 = "Mon"
	cDOWeekShort2 = "Tue"
	cDOWeekShort3 = "Wed"
	cDOWeekShort4 = "Thu"
	cDOWeekShort5 = "Fri"
	cDOWeekShort6 = "Sat"
	cDOWeekShort7 = "Sun"
	
	
	
	aMonth = [this.cMonth1, this.cMonth2, this.cMonth3, this.cMonth4, this.cMonth5, this.cMonth6, 
				this.cMonth7, this.cMonth8, this.cMonth9, this.cMonth10, this.cMonth11, this.cMonth12]
	
	aMonthShort = [this.cMonthShort1, this.cMonthShort2, this.cMonthShort3, 
					this.cMonthShort4, this.cMonthShort5, this.cMonthShort6, 
					this.cMonthShort7, this.cMonthShort8, this.cMonthShort9, 
					this.cMonthShort10, this.cMonthShort11, this.cMonthShort12]

	aDoW = [this.cDOWeek1, this.cDOWeek2, this.cDOWeek3, this.cDOWeek4, this.cDOWeek5, this.cDOWeek6, this.cDOWeek7]
	aDoWShort = [this.cDOWeekShort1, this.cDOWeekShort2, this.cDOWeekShort3, this.cDOWeekShort4, this.cDOWeekShort5, 
					this.cDOWeekShort6, this.cDOWeekShort7]

	cMonth = ""
	cShortMonth = ""
	nWeek = 0
	nDayOfWeek = 0
	cDayOfWeek = ""
	cShortDayOfWeek = ""
	
	
	func init(tnYear, tnMonth, tnDay) {
		
		this._SetDaysBeforeMonth()
	
		if isNull(tnYear) { 

			tnYear = this.oFr.frSetIfEmpty(tnYear, TimeList()[19])
			tnMonth = this.oFr.frSetIfEmpty(tnMonth, TimeList()[10])
			tnDay = this.oFr.frSetIfEmpty(tnDay, TimeList()[6])

		}
		
		tnYear = this._SetAsInt(tnYear)
		tnMonth = this._SetAsInt(tnMonth)
		tnDay = this._SetAsInt(tnDay)

		this.nYear = tnYear
		this.nMonth = tnMonth
		this.nDay = tnDay

		this.cValue = this.oFr._DateFormat(tnYear, tnMonth, tnDay)
		this.cMonth = this.Month()
		this.cShortMonth = this.ShortMonth()
		this.nDayOfWeek = this.DayOfWeek()
		this.cDayOfWeek = this.cDayOfWeek(Null)
		this.cShortDayOfWeek = this.cDayOfWeek(True)
		this.nWeek = this.Week()
		
	}

	
	func GetDataType() {
		return this.cClassType
	}

	/*
	 * Returns the month of the date
	 */
	func Month() {

		if this.oFr.frBetween(this.nMonth, 1, 12) {
			lcRet = this.aMonth[this.nMonth]
		else	
			lcRet = ""
		}
	
		return lcRet
	}
	

	func Week() {
	
		return floor((this._DaysBeforeMonth(this.nYear, this.nMonth) + this.nDay - this.DayOfWeek() + 10) / 7)

	}
	
	
	
	
	
	func ShortMonth() {

		if this.oFr.frBetween(this.nMonth, 1, 12) {
			lcRet = this.aMonthShort[this.nMonth]
		else	
			lcRet = ""
		}
	
		return lcRet
	}



    // Return day of the week, where Monday = 1 ... Sunday = 7"
	func DayOfWeek() {

		return ((this._DateToDecimal(this.nYear, this.nMonth, this.nDay) + 6) % 7) + 1
	}

	/*
	 * Return day of the week Monday ...... Sunday 
	 * Case tlType <> True return the abbreviation
	 */
	func cDayOfWeek(tlType) {
	
		tlType = this.oFr.frSetIfEmpty(tlType, False)
		if tlType {
			lcRet = this.aDoWShort[this.DayOfWeek()]
		else
			lcRet = this.aDoW[this.DayOfWeek()]
		}

		return lcRet
	}
	
	
	func operator(tcOperator, tcValue) {
	
		returnValue = self
		
		return returnValue
		
	}

	
	func _SetDaysBeforeMonth() {
		
		lnDaysBefore = 0
		for i = 1 to 12 {
			this._aDaysBeforeMonth[i] = lnDaysBefore
			lnDaysBefore += this._aDaysInMonth[i]
		}
	}
	

	// Transforms a value in an Int value (character or numeric)
	func _SetAsInt(tuValue) {
	
		if this.oFr.frVarType(tuValue) = this.oFr._character_type {
			lnRet = this.oFr.frVal(tuValue)
		else	
			lnRet = tuValue
		}
		
		return this.oFr.frInt(lnRet)
	}
	
	
	
	// Returns the number of days before January 1st of year
	func _DaysBeforeYear(tnYear) {
		lnYearBefore = tnYear - 1
		
		return (lnYearBefore * 365) + floor(lnYearBefore / 4) - 
					floor(lnYearBefore / 100) + floor(lnYearBefore / 400)
	}

	// Returns true if leap year
	func _IsYearLeap(tnYear) {
		return tnYear % 4 = 0 and (tnYear % 100 != 0 or tnYear % 400 = 0)
	}

	
	// Returns number of days in year 366 if it's a leap year other 365
	func _NumberDaysInYear(tnYear) {
		lnRet = 365
		if this._IsYearLeap(tnYear) {
			lnRet = 366
		}
		return lnRet
	}
	
	// Return the Number of days in a month
	func _NumberDaysInMonth(tnYear, tnMonth) {
		lnRet = this._aDaysInMonth[tnMonth]
		if tnMonth = 2 and this._IsYearLeap(tnYear) {
			lnRet = 29
		}
		return lnRet
	}
	
	// Return the number of days in year preceding first day of month
	func _DaysBeforeMonth(tnYear, tnMonth) {
	
		lnToAdd = 0
		if tnMonth > 2 and this._IsYearLeap(tnYear) {
			lnToAdd = 1
		}

		return this._aDaysBeforeMonth[tnMonth] + lnToAdd
	}
	
	func _DateToDecimal(tnYear, tnMonth, tnDay) {
	
		if this.oFr.frBetween(tnMonth, 1, 12) {
			if this.oFr.frBetween(tnDay, 1, this._NumberDaysInMonth(tnYear, tnMonth)) {
				lnRet = this._DaysBeforeYear(tnYear) + this._DaysBeforeMonth(tnYear, tnMonth) + tnDay
			else
				z = error
			}
		else
			z = error
		}
		
		return lnRet
	}

}



class DateTimeClass from DateClass {

	nHours = 0
	nMinutes = 0
	nSeconds = 0
	

	func init(tnYear, tnMonth, tnDay, tnHours, tnMinutes, tnSeconds) {
	
		this.cClassType = this.oFr._datetime_type 

		super.init(tnYear, tnMonth, tnDay)

		if isNull(tnHours) { 

			tnHours = this.oFr.frSetIfEmpty(tnHours, TimeList()[7])
			tnMinutes = this.oFr.frSetIfEmpty(tnMinutes, TimeList()[11])
			tnSeconds = this.oFr.frSetIfEmpty(tnSeconds, TimeList()[13])

		}
		
		tnHours = this._SetAsInt(tnHours)
		tnMinutes = this._SetAsInt(tnMinutes)
		tnSeconds = this._SetAsInt(tnSeconds)

		this.nHours = tnHours
		this.nMinutes = tnMinutes
		this.nSeconds = tnSeconds

		this.cValue = this.oFr._DateFormat(this.nYear, this.nMonth, this.nDay) + " " + 
						this.oFr.frTransform(tnHours, "@L 99") + ":" +
						this.oFr.frTransform(tnMinutes, "@L 99") + ":" +
						this.oFr.frTransform(tnSeconds, "@L 99") 
		

		}
}

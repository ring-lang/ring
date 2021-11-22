/* Imported, modified, and debugged by: Majdi Sobain <MajdiSobain@Gmail.com> 2016
			Modifications have comments started with *** or *****
			Debugging was on Dev-C++ 5.11 and MSVC++ 10.0

	All credit goes to the author <Stuart Konen> and his CodeProject article on : 
	http://www.codeproject.com/Articles/8953/Registry-Wrapper-Class-CRegistry
-------------------------------------------------------------------------------------	
	
// --- FILE INFORMATION -----------------------------

  CRegistry.cpp								*** All of filenames and headers have been renamed
  Classes: CRegEntry and CRegistry			*** for better cosmetic appearance in ring source files

  Author:  Stuart Konen
  Email:   skonen@gmail.com

  Date:	   12/1/2004 (MM/DD/YYYY)
  Version: 1.00

  (-!-) If you're going to use these classes please do not 
  remove these comments... To use these classes, simply #include
  Registry.h . In MFC you should also turn off precompiled headers
  for this file, in VC++ this can be done by navigating to:

  Project->Settings->Project Name->CRegistry.cpp->C/C++->Precompiled Headers

*///----------------------------------------------------

#include "creg_registry.h"

#pragma warning (disable : 4706)


/* ===================================================
 *	CONSTRUCTOR
 * =================================================*/

CRegEntry::CRegEntry(CRegistry *Owner) {

	// *** assert(Owner);                 // To help ignore creating an object without owner (Owner = NULL)
	InitData(Owner);
}



/* ===================================================
 *  CRegEntry::InitData(CRegistry *Owner)
 *
 *  Initializes the entries default values and sets the entries
 *  owner (CRegistry). This is only called during construction.
 */

void CRegEntry::InitData(CRegistry *Owner) {
	
	dwDWORD = iType = 0; 
	lpszName = lpszStr = NULL;
	
	__bStored = false;
	__bConvertable = true;
	if (Owner) __cregOwner = Owner;	
}



/* *** ===================================================
 *  CRegEntry::SetOwner(CRegistry *Owner)
 *
 *  This method help in transfering the entry from one owner (CRegistry) to another
 *  *** This method has been updated to help real transfer(copy), not just the name
 */

void CRegEntry::SetOwner(CRegistry* Owner) {

	switch (iType) {
						
			case REG_DWORD:	{
				DWORD dwvalue = (DWORD) __cregOwner[0][lpszName];
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName] = ( (dwvalue) ? dwvalue : 0 );
				break;
							}
			case REG_SZ: {
				LPCTSTR szvalue = __cregOwner[0][lpszName];
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName] = ( (szvalue) ? szvalue : TEXT("") );
				break;		
						 }
			case REG_MULTI_SZ: {
				LPCTSTR szvalue = new _TCHAR[_MAX_REG_VALUE];
				__cregOwner[0][lpszName].GetMulti((LPTSTR) szvalue);
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName].SetMulti(szvalue, MultiLength()); 	
				break;	
							   }
			case REG_BINARY: {
				size_t n = vBytes.size();
				LPBYTE pbvalue = new BYTE[n];
				__cregOwner[0][lpszName].GetBinary(pbvalue, n);
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName].SetBinary(pbvalue, n);
				break;		
							 }
			case REG_EXPAND_SZ: {
				LPTSTR eszvalue = new _TCHAR[_MAX_REG_VALUE];
				eszvalue = __cregOwner[0][lpszName].GetExpandSZ();
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName].SetExpandSZ(eszvalue);
				break;
								}
			case REG_QWORD: {
				UINT64 value;
				value = __cregOwner[0][lpszName].GetQWORD();
				assert(Owner);
				__cregOwner = Owner;
				__cregOwner[0][lpszName].SetQWORD(value);
				break;
							}
		} 
}



/* ===================================================
 *  CRegEntry::ForceStr()
 *
 *  Forces the memory allocation for the entry's string value, if it
 *  has not already been allocated.
 */

void CRegEntry::ForceStr() {
	if (lpszStr == NULL) { lpszStr = new _TCHAR[_MAX_REG_VALUE]; lpszStr[0] = 0; }	
}


/* *** ===================================================
 *  CRegEntry::SetName(CRegEntry* creg, LPCSTR name)
 *
 *  *** This is newly created method to help change the name of the given entry
 *  *** This method refect the change directly into the registry
 */

void CRegEntry::SetName(LPCSTR name) {
	// *** its very important to insure that name is not empty 
	// *** I will do that in the wrapper ring_vmwincreg.cpp for more control

	switch (iType) {
						
			case REG_DWORD:	{
				DWORD dwvalue = (DWORD) __cregOwner[0][lpszName];
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName] = ( (dwvalue) ? dwvalue : 0 );
				break;
							}
			case REG_SZ: {
				LPCTSTR value = __cregOwner[0][lpszName];
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName] = ( (value) ? value : TEXT("") );
				break;		
						 }
			case REG_MULTI_SZ: {
				LPCTSTR szvalue = new _TCHAR[_MAX_REG_VALUE];
				__cregOwner[0][lpszName].GetMulti((LPTSTR) szvalue);
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName].SetMulti(szvalue, MultiLength()); 	
				break;	
							   }
			case REG_BINARY: {
				size_t n = vBytes.size();
				LPBYTE pbvalue = new BYTE[n];
				__cregOwner[0][lpszName].GetBinary(pbvalue, n);
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName].SetBinary(pbvalue, n);
				break;		
							 }
			case REG_EXPAND_SZ: {
				LPTSTR eszvalue = new _TCHAR[_MAX_REG_VALUE];
				eszvalue = __cregOwner[0][lpszName].GetExpandSZ();
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName].SetExpandSZ(eszvalue);
				break;
								}
			case REG_QWORD: {
				UINT64 value;
				value = __cregOwner[0][lpszName].GetQWORD();
				this->Delete();
				this->lpszName = (LPTSTR) name;
				__cregOwner[0][lpszName].SetQWORD(value);
				break;
							}
		} 
}


/* ===================================================
 *  CRegEntry::operator=(LPCTSTR lpszValue)
 *
 *  OPERATOR: Assigns a const character array to the open
 *  registry value. The registry value type will be REG_SZ.
 */

CRegEntry& CRegEntry::operator=(LPCTSTR lpszValue) {

	size_t	nValueLen = (_tcslen(lpszValue) + 1)*sizeof(TCHAR);
	
	assert(nValueLen <= _MAX_REG_VALUE); 
	
	ForceStr();	iType = REG_SZ;	

	_tcsncpy(lpszStr, lpszValue, nValueLen > _MAX_REG_VALUE ? _MAX_REG_VALUE : nValueLen);

	REGENTRY_ALLOWCONV(true)
	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID( KEY_SET_VALUE ))

		RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_SZ, (LPBYTE)lpszValue, nValueLen);
	REGENTRY_TRYCLOSE;

	__bStored = true;

	return *this;
}



/* ===================================================
 *  CRegEntry::operator=(LPDWORD lpdwValue)
 *
 *  OPERATOR: Assigns a DWORD to the open registry value.
 *  The registry value type will be REG_DWORD.
 */

CRegEntry& CRegEntry::operator=(LPDWORD lpdwValue) {
	
	iType = REG_DWORD;
	memcpy(&dwDWORD, lpdwValue, sizeof( DWORD ));
		
	REGENTRY_ALLOWCONV(true)
	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID( KEY_SET_VALUE ))

		RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_DWORD, (LPBYTE)&dwDWORD, sizeof( DWORD ));
	REGENTRY_TRYCLOSE;

	__bStored = true;
	
	return *this;
}



/* ===================================================
 *  CRegEntry::operator=(CRegEntry& cregValue)
 *
 *  OPERATOR: Copys value information from the specified
 *	registry entry (CRegEntry) into this entry.
 */

CRegEntry& CRegEntry::operator=(CRegEntry& cregValue) {

	if (this == &cregValue)
		return *this;
	
	if (lpszName == NULL) {

		size_t nNameLen = _tcslen(cregValue.lpszName) + 1;
		lpszName = new _TCHAR[nNameLen]; _tcsncpy(lpszName, cregValue.lpszName, nNameLen);
	}
	
	switch ((iType = cregValue.iType)) {

		case REG_SZ:
			return (*this = (ForceStr(), cregValue.lpszStr));
			break;

		case REG_MULTI_SZ: {
			LPTSTR lpszBuf = new _TCHAR[_MAX_REG_VALUE];
			SetMulti(cregValue.GetMulti(lpszBuf), cregValue.MultiLength()); 
			delete [] lpszBuf; return *this;
			}
			break;
		case REG_BINARY: {
			size_t n = cregValue.vBytes.size(); LPBYTE buf = new BYTE[n];
			cregValue.GetBinary(buf, n); SetBinary(buf, n);
			delete [] buf; return *this;
			}
			break;
		case REG_EXPAND_SZ: {
			SetExpandSZ(cregValue.GetExpandSZ());
			return *this;
							}
			break;
		case REG_QWORD: {
			SetQWORD(cregValue.GetQWORD());
			return *this;
							}
			break;
		default:
			return (*this = cregValue.dwDWORD);
	}
}



/* ===================================================
 *  CRegEntry::operator LPTSTR()
 *
 *  OPERATOR: Converts (if required) and returns the open registry
 *  value as a null terminated string.
 */

CRegEntry::operator LPTSTR() {

	/* If caching is disabled, refresh the entries */
	REGENTRY_REFRESH_IF_NOCACHE

	assert(__bConvertable); // Check for conversion implementation

	ForceStr();

	switch (iType) {

		case REG_DWORD:
			_stprintf(lpszStr, _T("%lu"), dwDWORD);
			break;
		case REG_MULTI_SZ:
			GetMulti(lpszStr);
			break;
		case REG_BINARY: {
			_tcsncpy(lpszStr, (const _TCHAR*)&vBytes[0], vBytes.size());
			lpszStr[vBytes.size()] = 0;
						 }
			break;
		case REG_EXPAND_SZ:
			GetExpandSZ(true);		// lpszStr will be prepared and then returned
			break;
		case REG_QWORD:
			// Return lpszStr as it actually contains the value
			break;
	}
	return lpszStr;
}



/* ===================================================
 *  CRegEntry::operator DWORD()
 *
 *  OPERATOR: Converts (if required) and returns the open registry
 *  value as an unsigned 32-bit integer (unsigned long).
 */

CRegEntry::operator DWORD() {

	/* If caching is disabled, refresh the entries */
	REGENTRY_REFRESH_IF_NOCACHE
	
	assert(__bConvertable); // Check for conversion implementation

	REGENTRY_BINARYTOSTRING

		return (REGENTRY_SZ_SAFE ? _tcstoul(lpszStr, NULL, NULL) : dwDWORD);
}



/* ===================================================
 * *** newly added to substitute the automatically created one by 
 *     REGENTRY_CONV_NUMERIC_STORAGETYPE MACRO
 *
 *  OPERATOR: Assigns a double to the open registry value.
 *  The registry value type will be REG_SZ.
 */

CRegEntry& CRegEntry::operator=(double Value) {

	_R_BUF(23);    // *** 23 is because the upper limit of numbers in ring is 15 digit or point {pluse} .000000 of
	               // *** _stprintf_s in case all of 15 are numbers {plus} terminal 0 (Numeric Overflow! Error)

	_stprintf_s(buffer, (23 * sizeof(TCHAR)) ,_T("%f"), Value);

	for (int i = ( ( _tcslen(buffer) -1 ) * sizeof(TCHAR) ); i >= 0; i-- ) {
		if ( !strcmp( &buffer[(i-1)] , (LPCTSTR) ".0" ) ) {
			break;				// *** This peice of code made to save such 18.000000 number to be just 18.0
		} 
		if ( !strcmp( &buffer[i], (LPCTSTR) "0" ) ) { 
			buffer[i] = 0;
			buffer[i+1] = -2;
		} else { 
			/* if ( !strcmp( &buffer[i] , (LPCTSTR) "." ) ) {
				buffer[i] = 0;
				buffer[i+1] = -2;		// *** This peice of code made to save such 18.000000 number to be just 18
			} */
			break; 
		} 
	}

	return (*this = (LPCTSTR)(buffer)); 

}



/* ===================================================
 * *** newly added to substitute the automatically created one by 
 *     REGENTRY_CONV_NUMERIC_STORAGETYPE MACRO
 *
 *  CRegEntry::operator double()
 *
 *  OPERATOR: Converts (if required) and returns the open registry
 *  value as a double.
 */

CRegEntry::operator double() {

	REGENTRY_BINARYTOSTRING 
		
	return (REGENTRY_SZ_SAFE ? _tcstod(lpszStr, NULL) :(iType == REG_DWORD ? (double)dwDWORD : 0));

}



/* ===================================================
 *  CRegEntry::GetBinary(LPBYTE lpbValue, size_t nLen)
 *
 *	Sets the registry value to a binary value (REG_BINARY)
 *
 *  Important Params:
 *
 *		LPBYTE lpbDest: Pointer to the byte array to store *
 *		size_t nLen:	Elements contained within the byte array.
 */

void CRegEntry::SetBinary(LPBYTE lpbValue, size_t nLen) {
	
	// *** if (!nLen) { assert(nLen); return; }  // needed to be deactivated to create empty binary value
	
	iType = REG_BINARY;	

	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID ( KEY_SET_VALUE ) )

		RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_BINARY, lpbValue, nLen);
	REGENTRY_TRYCLOSE;
	
	__bStored = true;
	
	if (vBytes.size() < nLen) vBytes.reserve(nLen);
	vBytes.clear();
		
	// *** change vBytes check to avoid fill the bytes list if there is no value in reality
	while (vBytes.size() < nLen) { vBytes.push_back(lpbValue[vBytes.size()]); }
	
}



/* ===================================================
 * *** updated Exists function to query even those values of unkown
 *     types to this class
 *
 *  bool CRegEntry::Exists()
 *
 *  Checks whether the value entry exists or not.
 *
 * Note: This function updated to return the result of RegQueryValueEx
 */

DWORD CRegEntry::Exists () {
	DWORD Res;
	assert( REGENTRY_KEYVALID ( KEY_QUERY_VALUE ) );

	/* This piece of code used if we want to return ONLY (True) or (False)
	if ( RegQueryValueEx(__cregOwner->hKey, lpszName, NULL, NULL, NULL, NULL); == ERROR_SUCCESS ) {
		REGENTRY_TRYCLOSE ;
		return true;
	} else { 
		REGENTRY_TRYCLOSE ;
		return false; 
	} */
	
	Res = RegQueryValueEx(__cregOwner->hKey, lpszName, NULL, NULL, NULL, NULL);
	__cregOwner->AutoClose();

	return Res;
	
}



/* ===================================================
 * *** unsigned char CRegEntry::Type()
 *
 *  newly added function that returns the type of the entry as a number.
 *
 * Note: This function if succeed will return the type but if not it will return the error code Summated to 12
 */

DWORD CRegEntry::Type() {
	LONG res;
	DWORD type;

	assert( REGENTRY_KEYVALID ( KEY_QUERY_VALUE ) );

	res = RegQueryValueEx(__cregOwner->hKey, lpszName, NULL, &type, NULL, NULL);

	REGENTRY_TRYCLOSE ;

	if ( res == ERROR_SUCCESS ) {
		return type;
	} else { 
		return res + 12; 
	}

}



/* ===================================================
 *  CRegEntry::GetBinary(LPBYTE lpbDest, size_t nMaxLen)
 *
 *	Gets the binary value of a value stored as REG_BINARY
 *
 *  Important Params:
 *
 *		LPBYTE lpbDest: Pointer to the byte array to fill
 *		size_t nMaxLen: The maximum bytes to copy to lpbDest
 *
 *	Notes: This will only work for values that were saved
 *	using the binary registry type specification (REG_BINARY)
 */

void CRegEntry::GetBinary(LPBYTE lpbDest, size_t nMaxLen) {

	assert(IsBinary()); // Must be stored as Binary
	
	REGENTRY_REFRESH_IF_NOCACHE
	
	/* *** adding this check to ignore retrieving data if nMazLen is 0 */
	if (nMaxLen > 0)

	if ((size_t)(&vBytes.back() - &vBytes.at(0)+1) == vBytes.size()*sizeof(BYTE))
		memcpy(lpbDest, (LPBYTE)&vBytes.at(0), vBytes.size() > nMaxLen ? nMaxLen : vBytes.size());
	else
		for (size_t n=0; n < vBytes.size() && n < nMaxLen; n++)
			lpbDest[n] = vBytes[n];		
}



/* ===================================================
 *	CRegEntry::GetBinaryLength() 
 *
 *	Returns the size of the binary value in bytes.
 */

size_t CRegEntry::GetBinaryLength() {
	
	assert(IsBinary());

	REGENTRY_REFRESH_IF_NOCACHE
	return vBytes.size();
}



/* ===================================================
 *  CRegEntry::SetMulti(LPCTSTR lpszValue, size_t nLen, bool bInternal)
 *
 *	Stores an array of null-terminated string, terminated by two null characters.
 *	For Example: First String\0Second\Third\0\0
 *
 *  Important Params:
 *
 *		LPCTSTR lpszValue:	The string consisting of the null-terminated string array
 *		size_t  nLen:		The number of characters in the string, including null characters
 *
 *	Note: For inserting individual null-terminated strings into the array, 
 *	use MultiAdd or MultiSetAt.
 */

void CRegEntry::SetMulti(LPCTSTR lpszValue, size_t nLen, bool bInternal) {

	size_t nCur = 0, nPrev = 0, nShortLen = nLen;

	/* When this is internal, there is no need to repopulate the vector. */
	if (bInternal) goto SkipNoInternal;

	iType = REG_MULTI_SZ; vMultiString.clear();	
	if (nLen <= 2) goto SkipNoInternal; // The string is empty : \0\0
	if (*(lpszValue + nShortLen-1) == '\0')
		nShortLen--;	

	/* Populate a vector with each string part for easy and quick access */
	while ((nCur = (int)(_tcschr(lpszValue+nPrev, '\0')-lpszValue)) < nShortLen) {		
		vMultiString.push_back(lpszValue+nPrev);
		nPrev = nCur+1;
	}

	SkipNoInternal:

	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID ( KEY_SET_VALUE ) )
		
		RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_MULTI_SZ, (LPBYTE)lpszValue, nLen*sizeof(TCHAR));
	REGENTRY_TRYCLOSE;

	__bStored = true;
}



/* ===================================================
 *  CRegEntry::MultiLength(bool bInternal = false)
 *
 *	Returns the number of characters (including null) stored 
 *	in the full string. Don't confuse this with MultiCount()
 *	which returns the number of strings stored in the array.
 */

size_t CRegEntry::MultiLength(bool bInternal /*false*/) {
/***	nLen Definition seperation from for loop as it was like this:
 ***	for (size_t nLen = 0, nIndex = 0; nIndex < vMultiString.size(); nIndex++)		*/
	size_t nLen = 0;

	//Ensure correct values with no cache
	if (!bInternal) REGENTRY_REFRESH_IF_NOCACHE

	for (size_t nIndex = 0; nIndex < vMultiString.size(); nIndex++)
		nLen += vMultiString[nIndex].length() + 1;

	return nLen ? nLen+1 : 0;
}



/* ===================================================
 *  CRegEntry::MultiCount()
 *
 *	Returns the number of strings located within the array.
 */

size_t CRegEntry::MultiCount() {

	// Ensure correct values with no cache
	REGENTRY_REFRESH_IF_NOCACHE

	return vMultiString.size();
}



/* ===================================================
 *  CRegEntry::MultiRemoveAt(size_t nIndex)
 *
 *	Simply removes the string stored at the zero-based index of nIndex
 */

void CRegEntry::MultiRemoveAt(size_t nIndex) {

	// Ensure correct values with no cache
	REGENTRY_REFRESH_IF_NOCACHE

	assert(nIndex < vMultiString.size());
		
	vMultiString.erase(vMultiString.begin()+nIndex);

	// Update the registry
	REGENTRY_UPDATE_MULTISTRING

}



/* ===================================================
 *  CRegEntry::MultiSetAt(size_t nIndex, LPCTSTR lpszVal)
 *
 *	Alters the value of a string in the array located at
 *  the 0 based index of nIndex. The new value is lpszVal.
 *	The index must be within the bounds of the array, with
 *	the exception of being == the number of elements in
 *	which case calling this function is equal to calling
 *	MultiAdd.
 */

void CRegEntry::MultiSetAt(size_t nIndex, LPCTSTR lpszVal) {

	// Ensure correct values with no cache
	REGENTRY_REFRESH_IF_NOCACHE

	// *** assert(nIndex > vMultiString.size()) ; 
	assert(nIndex <= vMultiString.size()) ; 
	
	iType = REG_MULTI_SZ;

	// Add a new string element if == elements+1
	if (nIndex == vMultiString.size())	
		vMultiString.push_back(lpszVal);
	else
		vMultiString[nIndex] = lpszVal;
	
	// Update the registry
	REGENTRY_UPDATE_MULTISTRING
}



/* ===================================================
 *  CRegEntry::MultiGetAt(size_t nIndex)
 *
 *	Returns a constant pointer to the string located in
 *	the array at the zero-based index of nIndex. Note that
 *	the return value is not an STL string.
 */

LPCTSTR CRegEntry::MultiGetAt(size_t nIndex) {

	// Ensure correct values with no cache
	REGENTRY_REFRESH_IF_NOCACHE	

	assert(nIndex < vMultiString.size() && IsMultiString());

	return vMultiString[nIndex].c_str();
}



/* ===================================================
 *  CRegEntry::GetMulti(LPCTSTR lpszDest, size_t nMax)
 *
 *	Copys the entire null-terminated array string to lpszDest.
 *	For Example: First String\0Second\Third\0\0
 *
 *  Important Params:
 *
 *		LPCTSTR lpszDest:	Pointer to the character array to fill.
 *		size_t  nMax:		The maximum characters to read, including null-characters
 *
 *	Note: By default nMax is set to _MAX_REG_VALUE, you can retrieve
 *	the length of the entire string by calling MultiLength().
 */

LPTSTR CRegEntry::GetMulti(LPTSTR lpszDest, size_t nMax) {

	LPCTSTR strBuf;
	size_t nCur = 0, nLen = 0;
	
	if (!lpszDest) lpszDest = new TCHAR[_MAX_REG_VALUE]; // *** added to help call this function without params

	assert(IsMultiString());
	// *** if (!IsMultiString()) return &(lpszDest[0] = 0);

	/* If caching is disabled, refresh the entries */
	REGENTRY_REFRESH_IF_NOCACHE	
	
	for (size_t n=0; n < vMultiString.size() && nCur < nMax; n++) {

		strBuf = vMultiString[n].c_str(); 
		nLen = vMultiString[n].length()+1;

		_tcsncpy(lpszDest + nCur, strBuf, (nLen >= nMax ? (nMax-nCur) : nLen) * sizeof(_TCHAR));
		nCur += nLen;
	}

	/* Add the final null termination */
	*(lpszDest + nCur) = 0;
	
	return lpszDest;
}



/* ===================================================
 *  *** newly added function 
 *
 *  CRegEntry::GetExpandSZ(bool Expandable)
 *
 *	retrive the value (NULL terminated string) of REG_EXPAND_SZ type directly from registry
 *	
 */

LPTSTR CRegEntry::GetExpandSZ(bool Expandable) {

	assert(IsExpandSZ());

	REGENTRY_REFRESH_IF_NOCACHE
	
	if (Expandable) {

		HANDLE dToken;
		LPTSTR tmpStr = new TCHAR[(_tcslen(lpszStr) *sizeof(TCHAR))];
		DWORD vSize = _MAX_REG_VALUE * 16; 
		
		_tcscpy(tmpStr, lpszStr);
		
		lpszStr = new TCHAR[vSize];

		ExpandEnvironmentStrings(tmpStr, lpszStr, vSize);
		
	} else { 
		__cregOwner->Refresh();		// Refresh lpszStr if it contains the expanded form
	} 

	REGENTRY_TRYCLOSE ;

	return lpszStr;
}



/* ===================================================
 *  *** newly added function 
 *
 *  CRegEntry::SetExpandSZ(LPTSTR value)
 *
 *	set a value (NULL terminated string) of REG_EXPAND_SZ type directly to registry
 * 
 *	Note : this function also retreive the important information about the value in the time of loading
 */

DWORD CRegEntry::SetExpandSZ(LPTSTR value) {
	DWORD svalue = ( _tcslen(value) + 1 ) * sizeof(TCHAR);

	assert(svalue <= _MAX_REG_VALUE);

	lpszStr = new TCHAR[_MAX_REG_VALUE];
	_tcscpy(lpszStr, value);

	iType = REG_EXPAND_SZ;

	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID( KEY_SET_VALUE )) {

		svalue = RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_EXPAND_SZ, (LPBYTE) value, svalue);		

	}

	__bStored = true;

	REGENTRY_TRYCLOSE;
	
	return svalue;
}



/* ===================================================
 *  *** newly added function 
 *
 *  CRegEntry::SetQWORD(bool Expandable)
 *
 *	set a value of REG_QWORD (unsigned long long) type directly to registry
 *	
 */

DWORD CRegEntry::SetQWORD(UINT64 value) {
	lpszStr = new TCHAR[21];		// limit of largest value of QWORD range (20) + NULL termination
	DWORD lRes = 0;

	iType = REG_QWORD;

	_stprintf(lpszStr, _T("%llu"), value);

	if (REGENTRY_NOTLOADING && REGENTRY_KEYVALID( KEY_SET_VALUE )) {

		lRes = RegSetValueEx(__cregOwner->hKey, lpszName, NULL, REG_QWORD, (LPBYTE) &value, sizeof ( UINT64 ));		

	}

	__bStored = true;

	REGENTRY_TRYCLOSE;
	
	return lRes;
}



/* ===================================================
 *  *** newly added function 
 *
 *  UINT64 CRegEntry::GetQWORD() 
 *
 *	retrive the value of REG_QWORD type directly from registry
 *	
 */

UINT64 CRegEntry::GetQWORD() {
	UINT64 value = 0;
	DWORD size = sizeof(UINT64);

	assert(IsQWORD());

	REGENTRY_REFRESH_IF_NOCACHE

	value = _tcstoui64(lpszStr, NULL, 10);

	REGENTRY_TRYCLOSE ;

	return value;
}




/* ===================================================
 *  CRegEntry::Delete()
 *
 *	Removes the value from the open registry key, returns
 *  true on success and false on failure.
 */

bool CRegEntry::Delete() {

	__bStored = false;

	if (REGENTRY_KEYVALID (KEY_SET_VALUE) ) {
		RegDeleteValue(__cregOwner->hKey, lpszName) ;
		__cregOwner->AutoClose();
		return true;
	}
	return false;
}



// BEGIN CREGISTRY FUNCTIONS
 

/* ===================================================
 *  CRegistry CONSTRUCTOR
 *
 *  Flags:
 *
 *	CREG_CREATE (default) - When attempting to open a key that 
 *  does not exist, create it.
 *
 *	CREG_AUTOOPEN - Close the open registry key handle
 *	after an action has been performed with it. Opens the
 *	key whenever another action needs to be performed.
 *
 * ===================================================*/

CRegistry::CRegistry(DWORD flags,bool Acc64Tree) {	
	InitData();	
	Enable64Tree = Acc64Tree;
	__dwFlags = flags; 
}



/* ===================================================
 *  CRegistry::InitData() 
 *  Initializes the variables related to key locations to NULL.
 */

void CRegistry::InitData() { 
	_lpszSubKey = NULL;
	_hRootKey = hKey = NULL;
}



/* ===================================================
 *  CRegistry::operator []( LPCTSTR lpszVName)
 *
 *  OPERATOR: This will return the Registry Entry (CRegEntry) associated
 *  with the given value name. If the value name does not exist in
 *  the open key, it will be created.
 *
 *  Note: If the value name is created, it is only stored in the actual
 *  registry when the entry's value has been set.
 */

CRegEntry& CRegistry::operator []( LPCTSTR lpszVName) {

	size_t nValueNameLen = _tcslen(lpszVName) + 1;
	
	assert(nValueNameLen <= _MAX_REG_VALUE);
	
	for (int i = _reEntries.size()-1; i >=0; i--) {
		if (!_tcsicmp(lpszVName, _reEntries[i]->lpszName))
			return *_reEntries[i];
	}
	
	/* Entry not found */	
	_reEntries.push_back(new CRegEntry(this));	
	_reEntries.back()->lpszName = new _TCHAR[nValueNameLen];
	_tcsncpy(_reEntries.back()->lpszName, lpszVName, (nValueNameLen > _MAX_REG_VALUE ? _MAX_REG_VALUE : nValueNameLen));	

	return *_reEntries.back();
}



/* ===================================================
 *  CRegistry::KeyExists()
 *
 *	Returns true if the key exists and returns false if the key
 *	does not exist or could not be opened. This may be called
 *	as a static function.
 *
 *	Example: 
 *	CRegistry::KeyExists("Software\\Something", HKEY_LOCAL_MACHINE);
 */
/*	***	Make This function return WinAPI result to show msg for errors	*/
LONG CRegistry::KeyExists(LPCTSTR lpszRegPath, HKEY hRootKey) {
	
	CRegistry cregTemp( NULL );
	
	/*** Changing the return value according to the change in the return value of CRegistry::Open function
	 *** to be suitable with ring integration
	 *** return cregTemp.Open(lpszRegPath, hRootKey, KEY_QUERY_VALUE, true); */
	
	return cregTemp.Open(lpszRegPath, hRootKey, KEY_QUERY_VALUE, true);
}



/* ===================================================
 *  CRegistry::SubKeyExists()
 *
 *	Returns true if the subkey exists within the currently
 *	open key and false if not.
 */
/*	***	Make This function return WinAPI result to show msg for errors	*/
LONG CRegistry::SubKeyExists(LPCTSTR lpszSub) {
	
	LONG lResult;
	DWORD dwAccess;
	HKEY hTemp;

	if ((__dwFlags & CREG_AUTOOPEN && !AutoOpen(KEY_QUERY_VALUE)) || hKey == NULL) {
		assert(hKey);
		return false;
	}

	dwAccess = KEY_QUERY_VALUE;

	/*** To Access alternative 64 bit windows registry tree as All ring applications are of 32 bit	*/ 
	if (Enable64Tree == true) dwAccess |= KEY_WOW64_64KEY;

	lResult = RegOpenKeyEx(hKey, lpszSub, 0, dwAccess, &hTemp);

	if (lResult == ERROR_SUCCESS) RegCloseKey(hTemp);
	if (__dwFlags & CREG_AUTOOPEN) AutoClose();
	
	return lResult;
}



/* ===================================================
 *  *** newly added function 
 *
 *  void CRegistry::SetFlags(DWORD flags)
 *
 *	This method has been added to be able to reset flags even after object definition
 *
 */

void CRegistry::SetFlags(DWORD flags){
	if ( __dwFlags >= CREG_AUTOOPEN && (__dwFlags & ~CREG_AUTOOPEN) == flags ) {
		__dwFlags = flags; 
		Open(_lpszSubKey,_hRootKey); // Open the key if there's switch from auto open
	} else {
		__dwFlags = flags; 
		if(hKey) Open(_lpszSubKey,_hRootKey); // ReOpen the key with these new flags if it is already opened
	}
}	



/* ===================================================
 *  *** newly added function 
 *
 *  bool CRegistry::AcceptedFlags(DWORD flags)
 *
 *	This function to check acceptance of entered flags and returns True or False
 *
 */

bool CRegistry::AcceptedFlags(DWORD flags){
	if (  (flags == 0) || (flags == CREG_CREATE) || (flags == CREG_AUTOOPEN) || (flags == CREG_NOCACHE) || (flags == (CREG_CREATE | CREG_AUTOOPEN)) || (flags == (CREG_CREATE | CREG_NOCACHE)) || (flags == (CREG_AUTOOPEN | CREG_NOCACHE)) || (flags == (CREG_CREATE | CREG_AUTOOPEN | CREG_NOCACHE))  )
	{ return true; }
	else
	{ return false; }
}



/* ===================================================
 *  CRegistry::Open(LPCTSTR lpszRegPath, HKEY hRootKey, bool bAuto)
 *
 *  Opens the key in which values will be read and stored, if the key
 *  is not already existent in the registry, it will be created (if the
 *  CREG_CREATE) flag is present while constructing the class.
 *
 *  Upon opening the registry key, all of the REG_DWORD and REG_SZ values
 *  are loaded into a new corresponding CRegEntry for future access.
 *
 *  Important Params:
 *
 *		LPCTSTR lpszRegPath - A NULL terminated const character array containing,
 *		the location of the subkey.
 *		For example: "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
 *
 *		HKEY hRootKey - An open key handle to the root key. By default
 *		this value is set as HKEY_LOCAL_MACHINE.
 *		Another Example: HKEY_CURRENT_USER
 *
 *	Returns true on success and false on failure.
 */

/***	Change the type of Open function to be able to return the result of
 ***	RegCreateKeyEx and RegOpenKeyEx	*/
LONG CRegistry::Open(LPCTSTR lpszRegPath, HKEY hRootKey, DWORD dwAccess, bool bAuto) {

	bool bNew = true;
	
	/* If the key is being auto opened, skip directly to opening */
	if (bAuto) goto SkipNoAuto;	

	/* The key is being opened manually, if the key location differs
	from the last opened location, clear the current entries and
	store the path information for future auto opening and key
	deletion using DeleteKey() */	

	if (_lpszSubKey){
		if (_tcsicmp(lpszRegPath, _lpszSubKey)) {				
			
			/* If new key, clear any currently stored entries */
			for (size_t n=0; n<_reEntries.size(); n++)
				delete _reEntries[n];

			_reEntries.clear();
			delete [] _lpszSubKey;

		} else bNew = false;
	}

	if (bNew) {
	
		/* Store path information for auto opening */
		_lpszSubKey = new _TCHAR[_tcslen(lpszRegPath)+1];
		_tcscpy(_lpszSubKey, lpszRegPath);
	}
	
	_hRootKey = hRootKey;
	
	
	SkipNoAuto:
	
	/* This is where the key is actually opened (if all goes well).
	If the key does not exist and the CREG_CREATE flag is present,
	it will be created... Any currently opened key will be closed
	before opening another one. After opening the key, Refresh() is
	called and the key's values	are stored in memory for future use. */
	
	if (hKey != NULL) Close();


	/* If auto opening is set and this is a manual opening
	set the appropriate access rights */

	if (__dwFlags & CREG_AUTOOPEN && !bAuto) {
		dwAccess = __dwFlags & CREG_CREATE ? KEY_CREATE_SUB_KEY | KEY_QUERY_VALUE : KEY_QUERY_VALUE;
	}


	/* When key creation is enabled and auto opening is disabled,
	include key creation in the access rights */

	else if ( !(__dwFlags & CREG_AUTOOPEN) && __dwFlags & CREG_CREATE)
		dwAccess |= KEY_CREATE_SUB_KEY;

	/*	*** To Access alternative 64 bit windows registry tree as All ring applications are of 32 bit	*/ 
	if (Enable64Tree == true) dwAccess |= KEY_WOW64_64KEY;

	/* Open or create the sub key, and return the result: */
	LONG lResult = (__dwFlags & CREG_CREATE ? RegCreateKeyEx(hRootKey, lpszRegPath, 0, NULL, REG_OPTION_NON_VOLATILE, dwAccess, NULL, &hKey, NULL) 
	: RegOpenKeyEx(hRootKey, lpszRegPath, 0, dwAccess, &hKey));
	
	/*** Return Value Should be the same return value from RegCreateKeyEx or RegOpenKeyEx to
	 *** deal with their error messages with ring VM
	 *** return (lResult == ERROR_SUCCESS ? (bAuto ? true : Refresh()) : false); */
	
	if (lResult == ERROR_SUCCESS && bAuto == false ) Refresh();

	return lResult;
}



/* ===================================================
 *  CRegistry::AutoOpen()
 *  
 *	If the CREG_AUTOOPEN flag is true, this function is called whenever
 *	an action needs to be performed involving the registry key.
 *
 *	DWORD dwAccess controls the access required for key use.
 */

bool CRegistry::AutoOpen(DWORD dwAccess) {

	assert(_lpszSubKey != NULL);	
	
	/* ***	Adding conditional check with ERROR_SUCCESS	because Open() return changed to lResult */
	return (hKey == NULL && __dwFlags & CREG_AUTOOPEN ? (Open(_lpszSubKey, _hRootKey, dwAccess, true) == ERROR_SUCCESS) : true);
}



/* ===================================================
 *  CRegistry::AutoClose()
 *  
 *	If the CREG_AUTOOPEN flag is true, this function is called whenever
 *	an action has been performed on an open registry key and the key is no longer
 *	being accessed.
 */

void CRegistry::AutoClose() {

	if (__dwFlags & CREG_AUTOOPEN) Close();
}



/* ===================================================
 *  CRegistry::Refresh()
 *  
 *	Enumerates all the REG_SZ, REG_BINARY and REG_DWORD values within the open
 *	registry key and stores them in a CRegEntry class for future
 *  access. Returns true on success and false on failure.
 */

bool CRegistry::Refresh() {

	DWORD	dwBufferSize;
	DWORD	dwType;
	DWORD	dwNameLen;
	DWORD	dwValueCount;
	LPBYTE  lpbBuffer;

	DWORD	dwPrevFlags = __dwFlags;

	_TCHAR	cValueName[_MAX_PATH];	

	
	if ((__dwFlags & CREG_AUTOOPEN && !AutoOpen(KEY_QUERY_VALUE)) || hKey == NULL)
		return false;

	if (NOT_ES(RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL, &dwValueCount, NULL, NULL, NULL, NULL)))
		return false;

	lpbBuffer = new BYTE[_MAX_REG_VALUE];


	/* Halt auto opening and set loading flag */	
	__dwFlags = (__dwFlags | CREG_LOADING) & ~CREG_AUTOOPEN;
	

	if (dwValueCount > _reEntries.size())
		_reEntries.reserve(dwValueCount);

	for( DWORD dwIndex = 0; dwIndex < dwValueCount; dwIndex++) {

		dwNameLen = sizeof(cValueName); dwBufferSize = _MAX_REG_VALUE;	
		cValueName[0] = 0;

		if (NOT_ES(RegEnumValue(hKey, dwIndex, cValueName, &dwNameLen, NULL, &dwType, lpbBuffer, &dwBufferSize)))
			continue;

		switch (dwType) {
						
			case REG_DWORD:												
				this[0][cValueName] = (LPDWORD)lpbBuffer;				
				break;
				
			case REG_SZ:
				this[0][cValueName] = (LPCTSTR)lpbBuffer;
				break;				

			case REG_MULTI_SZ:
				this[0][cValueName].SetMulti((LPCTSTR)lpbBuffer, dwBufferSize/sizeof(TCHAR));				
				break;	

			case REG_BINARY:
				this[0][cValueName].SetBinary(lpbBuffer, (size_t)dwBufferSize);
				break;				
			case REG_EXPAND_SZ:
				this[0][cValueName].SetExpandSZ((LPTSTR) lpbBuffer);
				break;
			case REG_QWORD:
				this[0][cValueName].SetQWORD((UINT64) *lpbBuffer);
				break;
		}
	}

	if ((__dwFlags = dwPrevFlags) & CREG_AUTOOPEN) AutoClose();
	delete [] lpbBuffer;

	return true;
}



/* ===================================================
 *  CRegistry::DeleteKey()
 *  
 *	Deletes the key which is currently opened, including any
 *  subkeys and values it may contain.
 *
 *  NOTE: Use extreme caution when calling this function
 */

void CRegistry::DeleteKey() {
	assert(_hRootKey && _tcslen(_lpszSubKey));		// *** This check has been added to query HKEY handle
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	
	if (GetVersionEx(&osvi) && osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
		//DeleteKey(_hRootKey, _lpszSubKey);
		OpenParentnDelete(_hRootKey, _lpszSubKey);

	else	// Give it a try :)

		OpenParentnDelete(_hRootKey, _lpszSubKey);
		
		// *** not useful in case of Registry Redirection
		//RegDeleteKey(_hRootKey, _lpszSubKey);

	Close();

}



/* ===================================================
 *	CRegistry::DeleteKey(HKEY hPrimaryKey, LPCTSTR lpszSubKey)
 *  
 *	Private member function which is called by DeleteKey()
 *	This function is designed for NT based systems as it recursively
 *	deletes any subkeys present.
 */
/* *** Disabled because of using alternative OpenParentnDelete() function */
void CRegistry::DeleteKey(HKEY hPrimaryKey, LPCTSTR lpszSubKey) {

	DWORD dwKeyLen;
	FILETIME ftTemp;
	HKEY hTempKey;
	DWORD dwAccess;

	LONG   lResult = ERROR_SUCCESS;

	LPTSTR lpszKey = new _TCHAR[_MAX_PATH];	

	if (!_tcslen(lpszSubKey) || !hPrimaryKey) { assert(hPrimaryKey != NULL); goto cleanup; }

	dwAccess = KEY_ENUMERATE_SUB_KEYS | KEY_WRITE;

	if (IS_ES(RegOpenKeyEx(hPrimaryKey, lpszSubKey, 0, dwAccess, &hTempKey))){
		
		while (IS_ES(lResult)) {
			
			dwKeyLen = _MAX_PATH;

			lResult	 = RegEnumKeyEx(hTempKey, 0, lpszKey, &dwKeyLen, NULL, NULL, NULL, &ftTemp);

			if (lResult == ERROR_SUCCESS) DeleteKey(hTempKey, lpszKey);
			else if (lResult == ERROR_NO_MORE_ITEMS) {

				// *** not useful in case of Registry Redirection
				RegDeleteKey(hPrimaryKey, lpszSubKey);
			}
		}
		RegCloseKey(hTempKey); hTempKey = NULL;
	}

cleanup: delete [] lpszKey;		
		
}



/* ===================================================
 *	CRegistry::OpenParentnDelete(HKEY Rootkey, LPTSTR SubKEy)
 *  
 *	*** newly created function to use keys delete alternatives
 *      compatible with Win XP that can overcome Registry 
 *      Redirection problem
 */

void CRegistry::OpenParentnDelete(HKEY Rootkey, LPTSTR SubKEy) {
	LPTSTR ParentSubKey = new TCHAR[MAX_REG_KEY];
	LPTSTR sSubKey = new TCHAR[MAX_REG_KEY];

	Close();

	assert(_tcslen(SubKEy));

	for (int i = _tcslen(SubKEy)-1; i >= 0; i--) {
		if ( i == 0 ) {
			_tcscpy(sSubKey, SubKEy);
			Open(TEXT(""), _hRootKey, KEY_WRITE, true); // *** true added to avoid reset access rights in case of CREG_AUTOOPEN flag usage
			SHDeleteKey(hKey, sSubKey);
			Close();
			break;
		}
		if ( _lpszSubKey[i] == '\\' ) {
			_tcsncpy(ParentSubKey, SubKEy, i);
			ParentSubKey[i] = 0;
			_tcscpy(sSubKey, (SubKEy+i+1));
			Open(ParentSubKey, _hRootKey, KEY_WRITE, true); // *** true added to avoid reset access rights in case of CREG_AUTOOPEN flag usage
			SHDeleteKey(hKey, sSubKey);
			Close();
			break;
		}
	}

}



/* ===================================================
 *  CRegistry::Close()
 *
 *  If a key is currently open, it will be closed. This should
 *  be called when you no longer need to access the registry key
 *  and the CREG_AUTOOPEN flag is not true. However, Close() is 
 *  called on class deconstruction so it is not required.
 */

void CRegistry::Close() {

	if (hKey != NULL) { RegCloseKey(hKey); hKey = NULL; }

}


/*****=============================================================
 *  CRegistry::IsVirtualized()
 *
 *  This function has been newly added to help increase awareness
 *  of Registry Virtualization in case its enabled
 */

signed char CRegistry::IsVirtualized() {
	tstring lpszsubk = _lpszSubKey;
	TCHAR subkey[_MAX_REG_VALUE];
	if ( (_hRootKey) && (_lpszSubKey) ) {
		if (_hRootKey == HKEY_LOCAL_MACHINE){
			tstring lwsoftware = lpszsubk.substr(0,8).c_str();
			std::transform(lwsoftware.begin(), lwsoftware.end(), lwsoftware.begin(), ::tolower);
			if ( (_tcslen(_lpszSubKey) > 7) && (!_tcscmp(TEXT("software"), lwsoftware.c_str())) ) {
				CRegistry tst(0);
				if (!Enable64Tree) {
					_tcscpy(subkey, TEXT("Software\\Classes\\VirtualStore\\MACHINE\\SOFTWARE\\Wow6432Node\\"));
					if ( lpszsubk.length() > 8 ) {
						_tcscat(subkey,lpszsubk.substr(9, std::string::npos).c_str());
					} 
				} else {
					_tcscpy(subkey, TEXT("Software\\Classes\\VirtualStore\\MACHINE\\"));
					_tcscat(subkey,_lpszSubKey);
				}
				this[0][TEXT("VirtualizationCheck")] = TEXT("1");
				this->Close();	// Close the current opened key to allow test(tst class) to open it
				if (tst.Open(subkey, HKEY_CURRENT_USER) == ERROR_SUCCESS) {
					tst.SetFlags(CREG_CREATE); 
					if (!_tcscmp((LPTSTR) tst[TEXT("VirtualizationCheck")],TEXT("1"))){
						tst.Close();
						this->Open(_lpszSubKey, _hRootKey); // Reopen and delete after check
						this[0][TEXT("VirtualizationCheck")].Delete();
						return 1;
					} else {
						tst.Close();
						this->Open(_lpszSubKey, _hRootKey); // Reopen and delete after check
						this[0][TEXT("VirtualizationCheck")].Delete();
						return 0;
					}
				} else { 
					tst.Close();
					this->Open(_lpszSubKey, _hRootKey); // Reopen and delete after check
					this[0][TEXT("VirtualizationCheck")].Delete();
					return 0; 
				}
			}
		}
	} else return 0;
	return -1;
}



/*****=============================================================
 *  CRegistry::SubKeysCount()
 *
 *  This function has been newly added to get subkeys count
 *  
 */

int CRegistry::SubKeysCount(){
	DWORD Subkeys;

	if ( __dwFlags & CREG_AUTOOPEN ) AutoOpen(KEY_QUERY_VALUE);

	assert(hKey);

	if ( ERROR_SUCCESS == RegQueryInfoKey(hKey,NULL,NULL,NULL, &Subkeys, NULL, NULL, NULL, NULL, NULL, NULL, NULL) ) {
		AutoClose();
		return Subkeys;
	} else {
		AutoClose();
		return -1;
	}
}



/*****=============================================================
 *  CRegistry::GetSubKeyAt()
 *
 *  This function has been newly added to get a subkey at a specific index
 *  
 */

LPTSTR CRegistry::GetSubKeyAt(int index, LPTSTR Subkey, int sksize) {
	TCHAR Skey[MAX_REG_KEY];
	DWORD SKlength = sizeof(Skey);
	DWORD res = 0;

	assert(SubKeysCount());
	
	Open(_lpszSubKey, _hRootKey, KEY_READ, true /*similar to call AutoOpen()*/); 

	res = RegEnumKeyEx(hKey, index, Skey, &SKlength, NULL, NULL, NULL, NULL);

	SetFlags(__dwFlags); // Reopen the key with normal flags

	if ( ERROR_SUCCESS == res ) {
		sprintf_s(Subkey, sksize, _T("%s"), Skey);
		return Subkey;
	} else {
		LPTSTR err = new TCHAR[50];
		TCHAR errnum[5];
		_tcscpy(err, _T("ERROR (ID "));
		_tcscat(err, _ultot(res, errnum, 10));
		_tcscat(err, _T(") : INABILITY TO RETRIEVE THE SUBKEY NAME"));
		return err;
	}
}


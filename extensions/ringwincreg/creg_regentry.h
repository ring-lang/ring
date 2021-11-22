/* Imported, modified, and debugged by: Majdi Sobain <MajdiSobain@Gmail.com> 2016
			Modifications have comments started with *** or *****
			Debugging was on Dev-C++ 5.11 and MSVC++ 10.0

	All credit goes to the author <Stuart Konen> and his CodeProject article on : 
	http://www.codeproject.com/Articles/8953/Registry-Wrapper-Class-CRegistry
-------------------------------------------------------------------------------------*/	

// CRegEntry: interface for the CRegEntry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_CREG_REGENTRY_H_INCLUDED)
#define _CREG_REGENTRY_H_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRegistry;

class CRegEntry
{
public:

	CRegEntry(CRegistry* Owner = NULL);		
	virtual ~CRegEntry() { if (lpszName) delete [] lpszName; if (lpszStr) delete [] lpszStr; };

	/* -----------------------------------------*
	 *	Operators								*
	 * -----------------------------------------*/
	
	CRegEntry&	operator =( CRegEntry& cregValue );
	CRegEntry&	operator =( LPCTSTR lpszValue );
	CRegEntry&	operator =( LPDWORD lpdwValue );	
	CRegEntry&	operator =( DWORD dwValue ) { return (*this = &dwValue); }
				operator LPTSTR();
				operator DWORD();

	
	// Data types without implemented conversions
	// NOTE: I realize these will only check asserts
	// when a value is set and retrieved during the
	// same session. But it is better than no check.

	REGENTRY_NONCONV_STORAGETYPE(POINT);
	REGENTRY_NONCONV_STORAGETYPE(RECT);
	
	// Numeric types with conversions
	// If you'd like to add more, follow this form:
	// data type, max string length + 1, format specification, from string, from DWORD
	REGENTRY_CONV_NUMERIC_STORAGETYPE(__int64, 28, %I64d, _ttoi64(lpszStr), (__int64)dwDWORD)

	// *** REGENTRY_CONV_NUMERIC_STORAGETYPE(double, 18, %f, _tcstod(lpszStr, NULL), (double)dwDWORD)	
	CRegEntry&	operator=( double Value );
				operator double();

	REGENTRY_CONV_NUMERIC_STORAGETYPE(bool, 2, %d, (_ttoi(lpszStr) != 0), (dwDWORD != 0))

	REGENTRY_CONV_NUMERIC_STORAGETYPE(int, 12, %d, _ttoi(lpszStr), (int)dwDWORD)

	REGENTRY_CONV_NUMERIC_STORAGETYPE(UINT, 11, %d, (UINT)_tcstoul(lpszStr, NULL, NULL), (UINT)dwDWORD)

	// Types with conversions: type to/from string, type from unsigned long
	REGENTRY_CONV_STORAGETYPE(tstring, _R_BUF(_MAX_REG_VALUE); strcpy_safe((LPTSTR) buffer,Value.c_str()); ,
	lpszStr, _ultoa_safe(dwDWORD, lpszStr), _T("")) 
		

	/* -----------------------------------------*
	 *	Member Variables and Functions			*
	 * -----------------------------------------*/
	LPTSTR		lpszName;	// The value name
	UINT		iType;		// Value data type
	
	void		InitData(CRegistry* Owner = NULL);	
	void		ForceStr();
	bool		Delete();	

	// *** This newly added method help in change the entry's name
	void		SetName(LPCSTR name);

	/* The following six functions handle REG_MULTI_SZ support: */
	void		SetMulti(LPCTSTR lpszValue, size_t nLen, bool bInternal = false);	
	void		MultiRemoveAt(size_t nIndex);
	void		MultiSetAt(size_t nIndex, LPCTSTR lpszVal);
	LPTSTR		GetMulti(LPTSTR lpszDest = NULL , size_t nMax = _MAX_REG_VALUE); // *** Make lpszDest optional 
		
	LPCTSTR		MultiGetAt(size_t nIndex);	
	size_t		MultiLength(bool bInternal = false); 
	size_t		MultiCount(); 
		
	void		SetBinary(LPBYTE lpbValue, size_t nLen);	
	void		GetBinary(LPBYTE lpbDest, size_t nMaxLen); 
	size_t		GetBinaryLength(); 
	/* *** newly added function to get specific byte item in vBytes */
	BYTE		GetBinaryAt(size_t index) { assert(IsBinary()); return vBytes.at(index); }
	bool		Convertible() { return __bConvertable; }

	// *** updated this method to help adding this entry to the new owner
	void		SetOwner(CRegistry* Owner) ; 

	// *** This function has been newly created
	__inline	bool HasOwner () { return (__cregOwner) ? true : false;}
	
	template <class T>void SetStruct(T &type) { SetBinary((LPBYTE) &type, sizeof(T)); }
	template <class T>void GetStruct(T &type) { GetBinary((LPBYTE) &type, sizeof(T)); }

	/*	***	The next lines ended by //*** has been redefined with explicit data types	*/	
	__inline	bool IsString()		{ return (iType == REG_SZ); }						// ***
	__inline	bool IsDWORD()		{ return (iType == REG_DWORD); }					// ***
	__inline	bool IsBinary()		{ return (iType == REG_BINARY); }					// ***	
	__inline	bool IsMultiString() { return (iType == REG_MULTI_SZ); }				// ***
	/* newly added due to adding their types */
	__inline	bool IsExpandSZ()	{ return (iType == REG_EXPAND_SZ); }
	__inline	bool IsQWORD()		{ return (iType == REG_QWORD); }

	/* *** newly added function that returns the type of the entry as number   */
	DWORD		Type();
	
	/* *** New functions for REG_EXTAND_SZ */
	DWORD  SetExpandSZ(LPTSTR value);
	LPTSTR GetExpandSZ(bool Expandable = false);

	/* *** New functions for REG_QWORD  */
	DWORD		SetQWORD(UINT64 value);
	UINT64		GetQWORD();

	__inline	bool IsStored()		{ return __bStored; }								// ***
	/* *** This function updated to return the result of RegQueryValueEx   */
	DWORD		Exists();	// *** { return __bStored; }								// ***

	__inline	void MultiClear()	{ SetMulti( _T("\0"), 2); }							// ***

	__inline	void MultiAdd(LPCTSTR lpszVal) { MultiSetAt(MultiCount(), lpszVal); }	// ***

protected:

	CRegistry*	__cregOwner;
	bool		__bConvertable;
	bool		__bStored;

private:

	/* Create a variable for each prominent data type */

	DWORD		dwDWORD;
	LPTSTR		lpszStr;
		
	std::vector<BYTE> vBytes;
	std::vector<tstring> vMultiString; 
};


#endif

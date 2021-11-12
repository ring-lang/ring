/* Imported, modified, and debugged by: Majdi Sobain <MajdiSobain@Gmail.com> 2016
			Modifications have comments started with *** or *****
			Debugging was on Dev-C++ 5.11 and MSVC++ 10.0

	All credit goes to the author <Stuart Konen> and his CodeProject article on : 
	http://www.codeproject.com/Articles/8953/Registry-Wrapper-Class-CRegistry
-------------------------------------------------------------------------------------*/	

#if !defined(_CREG_REGISTRY_H_INCLUDED)
#define _CREG_REGISTRY_H_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* Silence STL warnings */

#pragma warning (disable : 4786)
#pragma warning (disable : 4514)
#pragma warning (push, 3)

/*	*** UNICODE is not currently supported in RING 
#ifdef _UNICODE
#if !defined(UNICODE)
#define UNICODE 
#endif
#endif
*/
#ifdef UNICODE
#pragma push_macro("UNICODE")
#undef UNICODE
#endif


#include <windows.h>
#include <math.h>
#include <TCHAR.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>		//*** for std::transform
#include <assert.h>
#include <Shlwapi.h>		//*** for SHDeleteKey() function




/* ====================================
 * Begin Preprocessor Definitions
 *
 * - Ugly, but well worth it.
 * ==================================== */


#ifdef UNICODE			// *** Change _UNICODE to UNICODE 
typedef std::wstring tstring;
#else
typedef	std::string tstring;
#endif



/* CRegistry Open Flags */

#define CREG_CREATE		1
#define CREG_AUTOOPEN	2
#define CREG_NOCACHE	4

/* CRegistry behaviour flags */

#define CREG_LOADING	8


#define _MAX_REG_VALUE	2048	// Maximum Value length, this may be increased
#define MAX_REG_KEY		255		//*** newly added

#define NOT_ES(func)			func != ERROR_SUCCESS
#define IS_ES(func)				func == ERROR_SUCCESS
#define _R_BUF(size)			_TCHAR buffer[size] 

#define REGENTRY_AUTO			__cregOwner->GetFlags() & CREG_AUTOOPEN
#define REGENTRY_TRYCLOSE		if (REGENTRY_AUTO) __cregOwner->AutoClose()
#define REGENTRY_SZ_SAFE		iType == REG_SZ || iType == REG_BINARY
#define REGENTRY_ALLOWCONV(b)	__bConvertable = b;


#define REGENTRY_REFRESH_IF_NOCACHE \
	if (__cregOwner->GetFlags() & CREG_NOCACHE && \
		REGENTRY_NOTLOADING && REGENTRY_KEYVALID( KEY_QUERY_VALUE ))\
		__cregOwner->Refresh();


#define REGENTRY_UPDATE_MULTISTRING \
	LPTSTR lpszBuffer = new _TCHAR[_MAX_REG_VALUE];	\
	REGENTRY_SETLOADING(+); GetMulti(lpszBuffer); REGENTRY_SETLOADING(-); \
	SetMulti(lpszBuffer, MultiLength(true), true); \
	delete [] lpszBuffer;

	
#define REGENTRY_KEYVALID(auto_access) \
	lpszName && ((REGENTRY_AUTO && __cregOwner->AutoOpen(auto_access)) || (!(REGENTRY_AUTO) && __cregOwner->hKey != NULL))

#define REGENTRY_NOTLOADING \
	!(__cregOwner->GetFlags() & CREG_LOADING)


/*** This definition has been caught as an error during debugging on Dev-C++ so
 *** has been clarified by separation of the macro into two well  
 *** formatted [REGENTRY_SETLOADINGp()] and [REGENTRY_SETLOADINGm()] with modification in the macros of call.  

#define REGENTRY_SETLOADINGp() \
	__cregOwner->__dwFlags += CREG_LOADING 
	
#define REGENTRY_SETLOADINGm() \
	__cregOwner->__dwFlags -= CREG_LOADING 

		@@ Disabled because the last compilation was on MSVC @@
*/
#define REGENTRY_SETLOADING(op) \
	__cregOwner->__dwFlags op= CREG_LOADING


#define REGENTRY_BINARYTOSTRING \
	if (iType == REG_BINARY) { ForceStr(); lpszStr = *this; } 

#define REGENTRY_NONCONV_STORAGETYPE(type) \
	CRegEntry& operator =( type &Value ){ REGENTRY_ALLOWCONV(false) SetStruct(Value); return *this; }  \
	operator type(){ type Return; GetStruct(Return); return Return; }

#define REGENTRY_CONV_STORAGETYPE(type, to_sz, from_sz, from_dw, no_result) \
	CRegEntry& operator =( type Value ) { to_sz return (*this = (LPCTSTR)(buffer)); } \
	operator type(){ REGENTRY_BINARYTOSTRING return (REGENTRY_SZ_SAFE ? from_sz :(iType == REG_DWORD ? from_dw : no_result)); } 

// *** change _stprintf to _stprintf_s 
#define REGENTRY_CONV_NUMERIC_STORAGETYPE(type, maxlen, form, from_sz, from_dw) \
	REGENTRY_CONV_STORAGETYPE(type, _R_BUF(maxlen); _stprintf_s(buffer, (maxlen * sizeof(TCHAR)) ,_T(#form), Value);, from_sz, from_dw, 0)

// *** newly created Macro for safe usage of its unsafe alternative (_tcscpy)
#define strcpy_safe(buf, srcval) (_tcsncpy_s(buf, _tcslen(buf) /2, srcval, _tcslen(buf)) == 0 ) ? buf : NULL 
// *** newly created Macro for safe usage of its unsafe alternative (_ultoa)
#define _ultoa_safe(srclong,deststr) (_ultot_s(srclong, deststr, _tcslen(deststr), 10) == 0 ) ? deststr : NULL 

/* ====================================
 * Include CRegEntry Class Definition
 * ==================================== */

#include "creg_regentry.h"

/* ====================================
 * Begin CRegistry Class Definition
 * ==================================== */

using namespace std;

class CRegistry {

public:
	
	CRegistry	(DWORD flags = CREG_CREATE, bool Acc64Tree = false);	
	virtual		~CRegistry() { Close(); for (int i=0; i < (int) _reEntries.size(); ++i) delete _reEntries[i]; delete [] _lpszSubKey; }

	CRegEntry&	operator[](LPCTSTR lpszVName); 

	// *** added code that will clear the entries list from non saved entries
	// *** n from size_t into int
	CRegEntry*	GetAt(size_t n) { ClearUnsaved(); assert(Count() > 0 && (int) n < Count()); return _reEntries.at(n); }

	/***	Change the type of Open function to be able to return the result of
	 ***	RegCreateKeyEx and RegOpenKeyEx	*/ 
	LONG		Open(LPCTSTR lpszRegPath, HKEY hRootKey = HKEY_LOCAL_MACHINE,
				DWORD dwAccess = KEY_QUERY_VALUE | KEY_SET_VALUE , bool bAuto = false);
	
	bool		AutoOpen(DWORD dwAccess);
	void		AutoClose();
	void		Close();
	bool		Refresh();	

	// *** remove static from declaration of KeyExists
	LONG		KeyExists(LPCTSTR lpszRegPath, HKEY hRootKey = HKEY_LOCAL_MACHINE);
	LONG		SubKeyExists(LPCTSTR lpszSub);	
	
	void		DeleteKey();

	// *** new added to help delete keys in XP compatibility
	void		OpenParentnDelete(HKEY Rootkey, LPTSTR SubKEy);

	/*	***	The next lines ended by //*** has been redefined with explicit data types	*/	
	__inline	DWORD GetFlags()	{	return __dwFlags; }			//***

	// *** added code that will clear the entries list from non saved entries
	__inline	int Count()		{ ClearUnsaved(); return _reEntries.size(); }		//***

	// *** Newly added function to clear _reEntries from unsaved entries
	void		ClearUnsaved() { for (int x =_reEntries.size() -1; x >= 0; x--) { if(!_reEntries.at(x)->IsStored()) _reEntries.erase(_reEntries.begin()+x); } }

	/*	***	This method has been added to be able to reset flags even after object definition	*/
	void SetFlags(DWORD flags);	
	
	// *** newly added function to check acceptance of entered flags
	bool AcceptedFlags(DWORD Flags);

	// *** used to get Root hKey from out side the class
	__inline	HKEY GetHRoot() { return _hRootKey; }
	// *** used to get the Subkey from out side the class
	__inline	LPTSTR GetSubKey() { return _lpszSubKey; }

	/*	***	This method has been added to be able to access 64 bit windows registry tree even after object definition	*/
	__inline	void Access64Tree(bool Acc64Tree)	{ Enable64Tree = Acc64Tree; if(hKey) Open(_lpszSubKey,_hRootKey); }	

	// ***	This Function has been added to help detect virtualization
	signed char		IsVirtualized();

	// ***	This is a new function to return subkeys count
	int			SubKeysCount();

	// ***	newly created function to return a subkey at specific index
	LPTSTR		GetSubKeyAt(int index, LPTSTR Subkey, int sksize);


	HKEY		hKey;		/* Registry key handle */

protected:
	
	DWORD		__dwFlags;
	bool		Enable64Tree;		//*** added to help in Access 64 bit tree

	friend		void CRegEntry::MultiSetAt(size_t nIndex, LPCTSTR lpszVal);
	friend		void CRegEntry::MultiRemoveAt(size_t nIndex);

	// *** newly added here to let it access _reEntries
	friend		void CRegEntry::SetOwner(CRegistry* Owner);

private:

	void		InitData();	

	void		DeleteKey(HKEY hPrimaryKey, LPCTSTR lpszSubKey);

	HKEY		_hRootKey;

	LPTSTR		_lpszSubKey;

	std::vector<CRegEntry *> _reEntries;
};

#pragma warning(pop)

#endif

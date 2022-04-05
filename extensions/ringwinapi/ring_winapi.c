/* 
Extension Name : Ring WIN APIs
Ext. Purpose : Its an easy bridge for ring developers to use WIN APIs
               Its just a transparent mirror that should bring all of WIN API functionality into RING
			   
Ext. Rules : There are some rules that have been followed in here to make this library neat, clean and understandable
1) Locally used functions should be defined at the beginning at the section of "Locally used functions"
2) There are two types of this library functions as follow:
	1 - Totally WIN API mirroring Functions : these needs to be named following their Original names preceded by 'r' as "rShellExecute()"
		This will make it easier for developers to seek the documentation of their original functions
	2 - Functions that has special purpose depending on WIN APIs like "rwaElevate()"
		This type of functions is better to be preceded by 'rwa' (short for RING WIN APIs) as this will
		make it kind of native and in the same time distinguish it from the other type of functions
3) There's no rule in specifying locally used functions names but it will be nice to have some native touch
4) Each non local function has to be registered using the function of registration at the end of this library (This is an essential ring extensions rule)

                Enjoy :)

									Copyright (c) 2016-2017
*/


#include "ring.h"
#include "windows.h"
#include "WinBase.h"
#include <stdio.h>
#include <ctype.h>
#include "Sddl.h"		// added to get User SID by ConvertSidToStringSid()


/*
===================================================================================== 
							Locally used functions
		Note: These functions have to be at the beginning of this library
=====================================================================================
*/


/*
Function Name : rwaGetErrorMsg
Func. Purpose : Return System error message
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
LPSTR rwaGetErrorMsg(LONG ErrorId , LPTSTR pMsg, size_t pMsgsize){
    LPSTR pBuffer = NULL;
	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                  NULL, 
                  ErrorId,
				  // if next para set to zero the msg will be according to the user's locale
                  MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                  (LPSTR)&pBuffer, 
                  0, 
                  NULL);
    if (pBuffer)
    {
		sprintf_s(pMsg, pMsgsize, "Error ID (%d) : %s", ErrorId, pBuffer);
		HeapFree(GetProcessHeap(), 0, pBuffer);
     }
    else
    {
		sprintf_s(pMsg, pMsgsize, "Format message failed with : %d", GetLastError());
    } 
	return pMsg;
}


/*
Function Name : IsRunAsAdmin
Func. Purpose : Return (1) if current program is elevated, (0) if not, or (-1) if there's error during checking
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : Created with help from SpaceWorm's post at http://www.cplusplus.com/forum/windows/101207/
*/
char IsRunAsAdmin(){
	BOOL fIsRunAsAdmin = FALSE;
	DWORD dwError = ERROR_SUCCESS;
	PSID pAdministratorsGroup = NULL;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;

  
    if (!AllocateAndInitializeSid(
        &NtAuthority, 
        2, 
        SECURITY_BUILTIN_DOMAIN_RID, 
        DOMAIN_ALIAS_RID_ADMINS, 
        0, 0, 0, 0, 0, 0, 
        &pAdministratorsGroup))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

    if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

Cleanup:

    if (pAdministratorsGroup)
    {
        FreeSid(pAdministratorsGroup);
        pAdministratorsGroup = NULL;
    }

    if (ERROR_SUCCESS != dwError)
    {
		return -1;
    }
	
	if (fIsRunAsAdmin) {return 1;} else {return 0;}
}

/* 
===================================================================================== 
=====================================================================================
*/



//------------------------------------------------------------------------------------



/*===================================================================================
                             Library Functions
===================================================================================*/


/*
Function Name : rwaIsRunAsAdmin
Func. Purpose : Check whether this process (ring.exe) is running as administrator or not
Func. Params  : () Nothing
Func. Return  : True or False
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
RING_FUNC(ring_winapi_rwaisrunasadmin) {
	
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR("Error: No parameters are needed in this method");
		return ;
	}

	switch (IsRunAsAdmin()) {
		case 1:
			RING_API_RETNUMBER(1);
			break;
		case 0:
			RING_API_RETNUMBER(0);
			break;
		case -1: {
			char errmsg[200];
			RING_API_ERROR(rwaGetErrorMsg(GetLastError(),errmsg,200));
			break;
			}
	}

	return ;
}



/*
Function Name : rwaElevate
Func. Purpose : Elevate to ask administrator rights for the process
Func. Params  : Either (String exepath) for running a particular app as administrator
				/Or/   (String exepath, String params) to run a particular app with some parameters
Func. Return  : Nothing
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : Created with help from SpaceWorm's post at http://www.cplusplus.com/forum/windows/101207/
*/
RING_FUNC(ring_winapi_rwaelevate) {
	if ( RING_API_PARACOUNT != 1 && RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR("Error: Bad parameter count, this function expects one\\two parameters");
		return ;
	}
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISSTRING(1) ) {
			SHELLEXECUTEINFOA sei = { sizeof(sei) };
			char appPath[200];
			char entAppPath[200];
			sei.lpVerb = "runas";
			sei.lpFile = RING_API_GETSTRING(1);
			sei.hwnd = NULL;
			sei.nShow = SW_NORMAL;
			
			// ---------------------------retrieve and unify paths-----------------------------
			GetModuleFileName(NULL,appPath,200);
			strcpy(entAppPath, RING_API_GETSTRING(1));
			for (int i=0; i < strlen(appPath); i++) appPath[i] = tolower(appPath[i]);
			for (int i=0; i < strlen(entAppPath); i++) entAppPath[i] = tolower(entAppPath[i]);
			for (int i=0; i < strlen(appPath); i++) if (appPath[i] == '/' ) appPath[i] = '\\';
			for (int i=0; i < strlen(entAppPath); i++) if (entAppPath[i] == '/') entAppPath[i] = '\\';
			
			if ( (!strcmp(entAppPath, appPath) && !IsRunAsAdmin()) || strcmp(entAppPath, appPath) ) {
				if (!ShellExecuteExA(&sei)) {
					char errmsg[200];
					RING_API_ERROR(rwaGetErrorMsg(GetLastError(),errmsg,200));
				}
			}
		} else RING_API_ERROR(RING_API_BADPARATYPE);
	} else {
		if ( RING_API_ISSTRING(1) && RING_API_ISSTRING(2) ) {
			SHELLEXECUTEINFOA sei = { sizeof(sei) };
			char appPath[200];
			char entAppPath[200];
			char lcFileName[200];
			char entFilePath[200];
			sei.lpVerb = "runas";
			sei.lpFile = RING_API_GETSTRING(1);
			sei.lpParameters = RING_API_GETSTRING(2);
			sei.hwnd = NULL;
			sei.nShow = SW_NORMAL;
			
			// ---------------------------retrieve and unify paths-----------------------------
			GetModuleFileName(NULL,appPath,200);
			strcpy(entAppPath, RING_API_GETSTRING(1));
			strcpy(lcFileName, ((VM *) pPointer)->cFileName);
			strcpy(entFilePath, RING_API_GETSTRING(2));
			for (int i=0; i < strlen(appPath); i++) appPath[i] = tolower(appPath[i]);
			for (int i=0; i < strlen(appPath); i++) if (appPath[i] == '/' ) appPath[i] = '\\';
			for (int i=0; i < strlen(entAppPath); i++) entAppPath[i] = tolower(entAppPath[i]);
			for (int i=0; i < strlen(entAppPath); i++) if (entAppPath[i] == '/' ) entAppPath[i] = '\\';
			for (int i=0; i < strlen(lcFileName); i++) lcFileName[i] = tolower(lcFileName[i]);
			for (int i=0; i < strlen(lcFileName); i++) if (lcFileName[i] == '/') lcFileName[i] = '\\';
			for (int i=0; i < strlen(entFilePath); i++) entFilePath[i] = tolower(entFilePath[i]);
			for (int i=0; i < strlen(entFilePath); i++) if (entFilePath[i] == '/') entFilePath[i] = '\\';
			
			if ( (!strcmp(entAppPath, appPath) && !strcmp(entFilePath, lcFileName) && !IsRunAsAdmin()) || strcmp(entAppPath, appPath) || strcmp(entFilePath, lcFileName) ) {
				if (!ShellExecuteExA(&sei)) {
					char errmsg[200];
					RING_API_ERROR(rwaGetErrorMsg(GetLastError(),errmsg,200));
				}
			}
		} else RING_API_ERROR(RING_API_BADPARATYPE);
	}
	return;
}



/*
Function Name : rShellExecute
Func. Purpose : Execute\Open an application or file with specific action
Func. Params  : (HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd)
Func. Return  : the value that returned by ShellExecute() function
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
RING_FUNC(ring_winapi_rshellexecute) {
	HWND hwnd = NULL;
	LPCSTR lpOperation = NULL;
	LPCSTR lpFile = NULL;
	LPCSTR lpParameters = NULL;
	LPCSTR lpDirectory = NULL;
	INT nShowCmd = 0;
	int lresult;
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR("Error: Bad parameter count, this function expects six parameters");
		return ;
	}
	if ( !RING_API_ISSTRING(1) && !RING_API_ISPOINTER(1) ) {
		RING_API_ERROR("Error: The first (hwnd) parameter should be either HWND pointer or NULL");
		return ;
	} else {
		if ( RING_API_ISSTRING(1) ) {
			if ( strcmp(RING_API_GETSTRING(1), "") ) {
				RING_API_ERROR("Error: The first (hwnd) parameter should be either HWND pointer or NULL");
				return ;
			}
		}
		if ( RING_API_ISPOINTER(1) ) {
			hwnd = (HWND) RING_API_GETCPOINTER(1, "HWND");
		}
	}
	if ( !RING_API_ISSTRING(2) ) {
		RING_API_ERROR("Error: The second (lpOperation) parameter should be String or NULL");
		return ;
	} else {
		if ( strcmp(RING_API_GETSTRING(2), "") ) lpOperation = RING_API_GETSTRING(2);
	}
	if ( !RING_API_ISSTRING(3) ) {
		RING_API_ERROR("Error: The third (lpFile) parameter should be String or NULL");
		return ;
	} else {
		if ( strcmp(RING_API_GETSTRING(3), "") ) lpFile = RING_API_GETSTRING(3);
	}
	if ( !RING_API_ISSTRING(4) ) {
		RING_API_ERROR("Error: The fourth (lpParameters) parameter should be String or NULL");
		return ;
	} else {
		if ( strcmp(RING_API_GETSTRING(4), "") ) lpParameters = RING_API_GETSTRING(4);
	}
	if ( !RING_API_ISSTRING(5) ) {
		RING_API_ERROR("Error: The fifth (lpDirectory) parameter should be String or NULL");
		return ;
	} else {
		if ( strcmp(RING_API_GETSTRING(5), "") ) lpDirectory = RING_API_GETSTRING(5);
	}
	if ( !RING_API_ISNUMBER(6) ) {
		RING_API_ERROR("Error: The sixth (nShowCmd) parameter should be numerical flag");
		return ;
	} else nShowCmd = RING_API_GETNUMBER(6);
	lresult = (int) ShellExecuteA(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd);
	RING_API_RETNUMBER(lresult);
	return;
}



/*
Function Name : rwaIsWow64Process
Func. Purpose : Check whether this process (ring.exe) is a Wow64 process or not
Func. Params  : () Nothing
Func. Return  : (1) if True or (0) if False or (-1) if function failed
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
RING_FUNC(ring_winapi_rwaiswow64process) {
	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	LPFN_ISWOW64PROCESS fnIsWow64Process;
	PBOOL IsWOW = (PBOOL) malloc(sizeof(BOOL));
	assert(IsWOW);
	
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR("Error: No parameters are needed in this method");
		return ;
	}
	
	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress( // To check availability of the function in Target Windows
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");	
	if (NULL != fnIsWow64Process) {
		if (fnIsWow64Process(GetCurrentProcess(),IsWOW)) { 
			if (IsWOW[0]) {
				free(IsWOW); 
				RING_API_RETNUMBER(1);
				return; 
			} else {
				free(IsWOW); 
				RING_API_RETNUMBER(0);
				return; 
			}
		} else {
			free(IsWOW); 
			RING_API_RETNUMBER(-1);
			return; 
		}
	} else {
		free(IsWOW); 
		RING_API_RETNUMBER(-1);
		return;
	}
}



/*
Function Name : rwaUserSID
Func. Purpose : Return User SID
Func. Params  : Either (HANDLE handle) of a process /Or/ () Nothing for the current process
Func. Return  : User SID in a string format
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : Created with help from Rose's post at http://www.codeexperts.com/showthread.php?1220-Getting-a-user-SID-in-term-of-string-from-a-process-handle-process-id
*/
RING_FUNC(ring_winapi_rwausersid) { 
	DWORD res;
	HANDLE hTokenHandle = NULL ;
	HANDLE hProcess = NULL;
	if ( RING_API_PARACOUNT > 1 ) {
		RING_API_ERROR("Error: This function expects no or one parameter");
		return ;
	}
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISPOINTER(1) ) {
			hProcess = (HANDLE) RING_API_GETCPOINTER(1, "HANDLE");
			if (!hProcess) {
				RING_API_ERROR("Error: No valid process handle");
				return;
			}
		} else {
			RING_API_ERROR("Error: No valid process handle");
			return;
		}
	} else hProcess = GetCurrentProcess();
	res = OpenProcessToken(hProcess, TOKEN_QUERY, &hTokenHandle);
	if (SUCCEEDED(res))
	{
		PTOKEN_USER pUserToken = NULL ;
		DWORD dwRequiredLength = 0 ;
		GetTokenInformation(hTokenHandle, TokenUser, pUserToken, 0, &dwRequiredLength);
		pUserToken = (PTOKEN_USER) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwRequiredLength) ;
		if(NULL != pUserToken)
		{
			res = GetTokenInformation(hTokenHandle, TokenUser, pUserToken, dwRequiredLength, &dwRequiredLength);
			if (SUCCEEDED(res))
			{
				LPTSTR pszSID;
				ConvertSidToStringSidA(pUserToken->User.Sid, &pszSID) ;
				RING_API_RETSTRING(pszSID);
				LocalFree(pszSID) ;
			}
			HeapFree(GetProcessHeap(), 0, pUserToken) ;
		}
		else {
			CloseHandle(hTokenHandle);
			RING_API_ERROR("Error: Unable to allocate pUserToken");
		}

		CloseHandle(hTokenHandle) ;
	}

	if (!SUCCEEDED(res)) {
		char errmsg[200];
		RING_API_ERROR(rwaGetErrorMsg(GetLastError(), errmsg, 200));
	}
	return;
}



/*
Function Name : rwaUserName
Func. Purpose : Return user name according to the passed process
				Note: if no parameter passed it will retrieve current user name
Func. Params  : Either (HANDLE handle) of a process /Or/ () Nothing for the current process
Func. Return  : User name in a string format
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/windows/desktop/aa379166(v=vs.85).aspx
Minimum supported Win client\server : XP(Desktop_apps)\Server2003(Desktop_apps)
*/
RING_FUNC(ring_winapi_rwausername) {
	DWORD res;
	HANDLE hTokenHandle = NULL;
	HANDLE hProcess = NULL;
	if (RING_API_PARACOUNT > 1) {
		RING_API_ERROR("Error: This function expects no or one parameter");
		return;
	}
	if (RING_API_PARACOUNT == 1) {
		if (RING_API_ISPOINTER(1)) {
			hProcess = (HANDLE)RING_API_GETCPOINTER(1, "HANDLE");
			if (!hProcess) {
				RING_API_ERROR("Error: No valid process handle");
				return;
			}
		}
		else {
			RING_API_ERROR("Error: No valid process handle");
			return;
		}
	}
	else hProcess = GetCurrentProcess();
	res = OpenProcessToken(hProcess, TOKEN_QUERY, &hTokenHandle);
	if (SUCCEEDED(res))
	{
		PTOKEN_USER pUserToken = NULL;
		DWORD dwRequiredLength = 0;
		GetTokenInformation(hTokenHandle, TokenUser, pUserToken, 0, &dwRequiredLength);
		pUserToken = (PTOKEN_USER)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwRequiredLength);
		if (NULL != pUserToken)
		{
			res = GetTokenInformation(hTokenHandle, TokenUser, pUserToken, dwRequiredLength, &dwRequiredLength);
			if (SUCCEEDED(res))
			{
				LPTSTR AccountN;
				PSID_NAME_USE peUse = (PSID_NAME_USE)calloc(1, sizeof(SID_NAME_USE));
				LPDWORD AccNlen = (LPDWORD)calloc(1, sizeof(DWORD far));
				LPDWORD DomLen = (LPDWORD)calloc(1, sizeof(DWORD far));
				LookupAccountSid(NULL, (PSID)pUserToken->User.Sid, NULL, AccNlen, NULL, DomLen, peUse);
				AccountN = (LPTSTR)malloc((DWORD)AccNlen + 1);
				res = LookupAccountSid(NULL, (PSID)pUserToken->User.Sid, AccountN, AccNlen, NULL, DomLen, peUse);
				if (SUCCEEDED(res)){
						RING_API_RETSTRING(AccountN);
				} 
				free(AccNlen);
				free(DomLen);
				free(peUse);
				free(AccountN);
			}
			HeapFree(GetProcessHeap(), 0, pUserToken);
		}
		else {
			CloseHandle(hTokenHandle);
			RING_API_ERROR("Error: Unable to allocate pUserToken");
		}

		CloseHandle(hTokenHandle);
	}

	if (!SUCCEEDED(res)) {
		char errmsg[200];
		RING_API_ERROR(rwaGetErrorMsg(GetLastError(), errmsg, 200));
	}
	return;

}



/*
Function Name : rwaSysErrorMsg
Func. Purpose : Return the string error message from the passed error code
Func. Params  : Either (Number ID) to return a message in English
				/Or/ (Number ID, BOOL allowlocale) to return a message in the user locale
Func. Return  : Error message
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
RING_FUNC(ring_winapi_rwasyserrormsg) {
	BOOL allowlocale = FALSE;
	DWORD ErrId;
    LPSTR pBuffer = NULL;
	BOOL lresult;
	if ( RING_API_PARACOUNT != 1 && RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR("Error: Bad parameter count, this function expects one\\two parameters");
		return ;
	}
	if ( RING_API_PARACOUNT == 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
			if ( RING_API_GETNUMBER(1) < 0 ) {
				RING_API_ERROR("Error: Error ID is not correct");
				return;
			}
			ErrId = RING_API_GETNUMBER(1);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	} else {
		if ( RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) ) {
			if ( RING_API_GETNUMBER(1) < 0 ) {
				RING_API_ERROR("Error: Error ID is not correct");
				return;
			}
			ErrId = RING_API_GETNUMBER(1);
			allowlocale = RING_API_GETNUMBER(2);
		} else {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	}
	if (allowlocale) {
		lresult = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL, 
						ErrId,
						0,
						(LPSTR)&pBuffer, 
						0, 
						NULL);
	} else {
		lresult = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL, 
						ErrId,
						MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
						(LPSTR)&pBuffer, 
						0, 
						NULL);
	}
	if ( lresult ) {
		RING_API_RETSTRING(pBuffer);
	} else {
		RING_API_ERROR("Error : FormatMessage() function ended with unexpected result");
	}
	HeapFree(GetProcessHeap(), 0, pBuffer);
	return;
}



/*
Function Name : rGetLastError
Func. Purpose : Return the last error code
Func. Params  : ---
Func. Return  : Error code
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/ms679360.aspx
Minimum supported Win client\server\phone : XP\Server2003\Phone8
*/
RING_FUNC(ring_winapi_rgetlasterror) {
	if (RING_API_PARACOUNT != 0) {
		RING_API_ERROR("Error: Bad parameter count, this function does not accept parameters");
		return;
	}

	RING_API_RETNUMBER((DWORD) GetLastError());
}



/*
Function Name : rWow64EnableWow64FsRedirection
Func. Purpose : Enable or Disable file system redirection under Wow64 environment
Func. Params  : True for enabling and False for disabling
Func. Return  : True if succeed or False if not
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/aa365744.aspx
Minimum supported Win client\server : Vista(Desktop_apps)\Server2003(Desktop_apps)
*/
RING_FUNC(ring_winapi_rwow64enablewow64fsredirection) {
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR("Error: Bad parameter count, this function accepts one parameter only");
		return;
	}

	if (!RING_API_ISNUMBER(1)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	RING_API_RETNUMBER((int)Wow64EnableWow64FsRedirection((BOOL) RING_API_GETNUMBER(1)));

}



/*
Function Name : rwaDisableWow64FsRedirection
Func. Purpose : Disable file system redirection under Wow64 environment (More reliable)
Func. Params  : ---
Func. Return  : Pointer to data that should be passed to rwaRevertWow64FsRedirection() function
				if you want to re-enable redirection
				Note: This function must not be used with rWow64EnableWow64FsRedirection() function
					at the same time
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/aa365743.aspx
Minimum supported Win client\server :  XP_Pro_x64(Desktop_apps)\Server2003SP1(Desktop_apps)
*/
RING_FUNC(ring_winapi_rwadisablewow64fsredirection) {
	PVOID OldValue = NULL;

	if (RING_API_PARACOUNT != 0) {
		RING_API_ERROR("Error: Bad parameter count, this function does not accept parameters");
		return;
	}

	if (Wow64DisableWow64FsRedirection(&OldValue))
	{
		RING_API_RETCPOINTER(OldValue, "PVOID");
	}
	else {
		RING_API_ERROR("Error: rwaDisableWow64FsRedirection unexpected error");
		return;
	}	

}



/*
Function Name : rwaRevertWow64FsRedirection
Func. Purpose : Re-enable file system redirection that was disabled by rwaDisableWow64FsRedirection()
Func. Params  : Pointer to data that has been created by rwaDisableWow64FsRedirection()
Func. Return  : True if revert file system redirection succeed or False if not
				Note: This function must not be used with rWow64EnableWow64FsRedirection() function
					at the same time
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/aa365743.aspx
Minimum supported Win client\server :  XP_Pro_x64(Desktop_apps)\Server2003SP1(Desktop_apps)
*/
RING_FUNC(ring_winapi_rwarevertwow64fsredirection) {
	PVOID OldValue = NULL;

	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR("Error: Bad parameter count, this function accepts one parameter only");
		return;
	}

	if (!RING_API_ISCPOINTER(1)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	OldValue = (PVOID) RING_API_GETCPOINTER(1, "PVOID");
	
	if (Wow64RevertWow64FsRedirection(OldValue)){
		RING_API_RETNUMBER(1);
	} else {
		RING_API_RETNUMBER(0);
	}

	CloseHandle(OldValue);
}



/*
Function Name : rwaEnvirVarString
Func. Purpose : Return the string value of system environment variables
Func. Params  : string contains a system environment variables
Func. Return  : String value of system environment variables
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
Func. Source  : https://msdn.microsoft.com/en-us/library/windows/desktop/ms724265(v=vs.85).aspx
Minimum supported Win client\server : Win2000Pro(Desktop_apps)\Server2000(Desktop_apps)
*/
RING_FUNC(ring_winapi_rwaenvirvarstring) {
	DWORD res; 
	LPTSTR exStr = (LPTSTR)malloc(200*sizeof(TCHAR));
	if (RING_API_PARACOUNT != 1) {
		RING_API_ERROR("Error: Bad parameter count, this function accepts one parameter");
		return;
	}

	if (!RING_API_ISSTRING(1)) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	res = ExpandEnvironmentStrings(RING_API_GETSTRING(1), exStr, 200);
	if (res > 200)
	{
		exStr = (LPTSTR)malloc ((res + 1)*sizeof(TCHAR));
		res = ExpandEnvironmentStrings(RING_API_GETSTRING(1), exStr, res +1);
	}

	if (SUCCEEDED(res)) {
		RING_API_RETSTRING(exStr);
		free(exStr);
	}
	else {
		char errmsg[200];
		free(exStr);
		RING_API_ERROR(rwaGetErrorMsg(GetLastError(), errmsg, 200));
	}
	
}


/*
=================================================================================================
			This Function Is Needed for Registration Of This Library 
			Functions Into Ring
			Note: This function has to be at the bottom of this library				
=================================================================================================
*/
RING_API void ringlib_init ( RingState *pRingState ) {
	RING_API_REGISTER("rwaisrunasadmin", ring_winapi_rwaisrunasadmin);
	RING_API_REGISTER("rwaelevate", ring_winapi_rwaelevate);
	RING_API_REGISTER("rwasyserrormsg", ring_winapi_rwasyserrormsg);
	RING_API_REGISTER("rshellexecute", ring_winapi_rshellexecute);
	RING_API_REGISTER("rwaiswow64process", ring_winapi_rwaiswow64process);
	RING_API_REGISTER("rwausersid", ring_winapi_rwausersid);
	RING_API_REGISTER("rwausername", ring_winapi_rwausername);
	RING_API_REGISTER("rgetlasterror", ring_winapi_rgetlasterror);
	RING_API_REGISTER("rwow64enablewow64fsredirection", ring_winapi_rwow64enablewow64fsredirection);
	RING_API_REGISTER("rwadisablewow64fsredirection", ring_winapi_rwadisablewow64fsredirection);
	RING_API_REGISTER("rwarevertwow64fsredirection", ring_winapi_rwarevertwow64fsredirection);
	RING_API_REGISTER("rwaenvirvarstring", ring_winapi_rwaenvirvarstring);

}

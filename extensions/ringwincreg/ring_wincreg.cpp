/* Copyright (c) 2016 Majdi Sobain <MajdiSobain@Gmail.com> */

extern "C" {
#include "ring.h"
}

#include "creg_registry.h"
#include "ring_wincreg.h"

#define AUTOOPEN_CHECK ( p->GetFlags() & CREG_AUTOOPEN ? true : (p->hKey) )
#define EntryExistsM(entryname) EntryExists(pPointer, p, entryname)

extern "C" {

RING_LIBINIT
{
	RING_API_REGISTER("cregopenkey",ring_vm_creg_cregopenkey);
	RING_API_REGISTER("cregclosekey",ring_vm_creg_cregclosekey);
	RING_API_REGISTER("cregdeletekey",ring_vm_creg_cregdeletekey);
	RING_API_REGISTER("cregkeyexists",ring_vm_creg_cregkeyexists);
	RING_API_REGISTER("cregsubkeyexists",ring_vm_creg_cregsubkeyexists);
	RING_API_REGISTER("cregsetflags",ring_vm_creg_cregsetflags);
	RING_API_REGISTER("cregentriescount",ring_vm_creg_cregentriescount);
	RING_API_REGISTER("creggetflags",ring_vm_creg_creggetflags);
	RING_API_REGISTER("cregaccess64tree",ring_vm_creg_cregaccess64tree);
	RING_API_REGISTER("cregisvirtualized",ring_vm_creg_cregisvirtualized);
	RING_API_REGISTER("cregsubkeyscount",ring_vm_creg_cregsubkeyscount);
	RING_API_REGISTER("creggetsubkeyat",ring_vm_creg_creggetsubkeyat);
	RING_API_REGISTER("cregrefresh",ring_vm_creg_cregrefresh);
	RING_API_REGISTER("creggetat",ring_vm_creg_creggetat);
	RING_API_REGISTER("creggetname",ring_vm_creg_creggetname);
	RING_API_REGISTER("cregcopy",ring_vm_creg_cregcopy);
	RING_API_REGISTER("cregrename",ring_vm_creg_cregrename);
	RING_API_REGISTER("cregsetvalue",ring_vm_creg_cregsetvalue);
	RING_API_REGISTER("creggetvalue",ring_vm_creg_creggetvalue);
	RING_API_REGISTER("cregdelete",ring_vm_creg_cregdelete);
	RING_API_REGISTER("cregsetmulti",ring_vm_creg_cregsetmulti);
	RING_API_REGISTER("cregmultiremoveat",ring_vm_creg_cregmultiremoveat);
	RING_API_REGISTER("cregmultisetat",ring_vm_creg_cregmultisetat);
	RING_API_REGISTER("cregmultiadd",ring_vm_creg_cregmultiadd);
	RING_API_REGISTER("cregmultigetat",ring_vm_creg_cregmultigetat);
	RING_API_REGISTER("cregmulticount",ring_vm_creg_cregmulticount);
	RING_API_REGISTER("cregmulticlear",ring_vm_creg_cregmulticlear);
	RING_API_REGISTER("creggetexpandsz",ring_vm_creg_creggetexpandsz);
	RING_API_REGISTER("cregsetexpandsz",ring_vm_creg_cregsetexpandsz);
	RING_API_REGISTER("creggetexpandedsz",ring_vm_creg_creggetexpandedsz);
	RING_API_REGISTER("cregsetqword",ring_vm_creg_cregsetqword);
	RING_API_REGISTER("creggetqword",ring_vm_creg_creggetqword);
	RING_API_REGISTER("creggetbinary",ring_vm_creg_creggetbinary);
	RING_API_REGISTER("cregsetbinary",ring_vm_creg_cregsetbinary);
	RING_API_REGISTER("cregbinarylength",ring_vm_creg_cregbinarylength);
	RING_API_REGISTER("cregisstring",ring_vm_creg_cregisstring);
	RING_API_REGISTER("cregisdword",ring_vm_creg_cregisdword);
	RING_API_REGISTER("cregismultistring",ring_vm_creg_cregismultistring);
	RING_API_REGISTER("cregisbinary",ring_vm_creg_cregisbinary);
	RING_API_REGISTER("cregisexpandsz",ring_vm_creg_cregisexpandsz);
	RING_API_REGISTER("cregisqword",ring_vm_creg_cregisqword);
	RING_API_REGISTER("cregexists",ring_vm_creg_cregexists);
	RING_API_REGISTER("cregtype",ring_vm_creg_cregtype);
	
}

// CRegistry cregopenkey ( RootHkey index /*like HKEY_CURRENT_USER*/ , string keyname , \optional int flags, \optional boolean access64tree )
void ring_vm_creg_cregopenkey(void *pPointer){
	CRegistry *pCR = new CRegistry;
	HKEY hkey;
	LONG lResult;
	if (RING_API_PARACOUNT > 1 ) {
		if ( RING_API_ISNUMBER(1) ) {
		switch ((int) RING_API_GETNUMBER(1)){
			case 1:
				hkey = HKEY_CLASSES_ROOT;
				break;
			case 2:
				hkey = HKEY_CURRENT_USER;
				break;
			case 3:
				hkey = HKEY_LOCAL_MACHINE;
				break;
			case 4:
				hkey = HKEY_USERS;
				break;
			case 5:
				hkey = HKEY_CURRENT_CONFIG;
				break;
			default:
				RING_API_ERROR("Incorrect HKEY index");
				return;
			}
		} else {
			RING_API_ERROR("Error : Bad HKEY root");
		return;
		}
	} else {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	switch RING_API_PARACOUNT {
	case 2:
		if ( !RING_API_ISSTRING(2) ) {
			RING_API_ERROR("Error : Bad sub key path");
			return ;
		}
		break;
	case 3:
		if ( RING_API_ISSTRING(2) && RING_API_ISNUMBER(3) ) {
			if ( pCR->AcceptedFlags((int) RING_API_GETNUMBER(3)) ) {
				pCR->SetFlags((int) RING_API_GETNUMBER(3));
			} else RING_API_ERROR("Error : Bad flags configuration");
		} else {
			RING_API_ERROR("Error : Bad sub key path or bad flag type");
			return ;
		}
		break;
	case 4:
		if ( RING_API_ISSTRING(2) && RING_API_ISNUMBER(3)  && RING_API_ISNUMBER(4) ) {
			if ( pCR->AcceptedFlags((int) RING_API_GETNUMBER(3)) ) {
				pCR->SetFlags((int) RING_API_GETNUMBER(3));
			} else RING_API_ERROR("Error : Bad flags configuration");
			pCR->Access64Tree((int) RING_API_GETNUMBER(4));
		} else {
			RING_API_ERROR("Error : Bad sub key path, bad flag type, or bad Wow64 True/False value");
			return ;
		}
		break;
	default:
		RING_API_ERROR("This function expects two, three, or four parameters");
		return ;
	}
	lResult = pCR->Open(RING_API_GETSTRING(2), hkey);
	if ( lResult == ERROR_SUCCESS ) {
		RING_API_RETCPOINTER(pCR, "CRegistry");
		return;
	} else {
		TCHAR msgBuf[200];
		RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
		return;
	}
}

// void cregclosekey ( CRegistry keyhandle )
void ring_vm_creg_cregclosekey(void *pPointer) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry");
		if ( (p) && AUTOOPEN_CHECK ) { p->Close();} else {RING_API_ERROR("Error : invalid CRegistry key handle");}
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle");
	}
}

// void cregdeletekey ( CRegistry keyhandle )
void ring_vm_creg_cregdeletekey(void *pPointer) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry");
		if (p) {
			if ( (p->GetHRoot()) && strlen(p->GetSubKey()) ) {
				p->DeleteKey();
			} else RING_API_ERROR("Error : Connot delete. Invalid HKEY or Subkey path");
		} else {RING_API_ERROR("Error : invalid CRegistry key handle");}
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle");
	}
}

// boolean cregkeyexist ( RootHkey /*like HKEY_CURRENT_USER*/ , string keyname ) 
void ring_vm_creg_cregkeyexists( void *pPointer) {
	CRegistry creg;
	HKEY hkey;
	LONG lResult;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISNUMBER(1) && RING_API_ISSTRING(2) ) {
		switch ( (int) RING_API_GETNUMBER(1) ) {
			case 1:
				hkey = HKEY_CLASSES_ROOT;
				break;
			case 2:
				hkey = HKEY_CURRENT_USER;
				break;
			case 3:
				hkey = HKEY_LOCAL_MACHINE;
				break;
			case 4:
				hkey = HKEY_USERS;
				break;
			case 5:
				hkey = HKEY_CURRENT_CONFIG;
				break;
			default:
				RING_API_ERROR("Incorrect HKEY index");
				return;
			}
		lResult = creg.KeyExists(RING_API_GETSTRING(2), hkey);
		if (lResult == ERROR_SUCCESS) {
			RING_API_RETNUMBER(1);
			return;
		} else if (lResult == 2) {
			RING_API_RETNUMBER(0);
		} else {
			TCHAR msgBuf[200];
			RING_API_RETNUMBER(0);
			RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
		}
	} else {
		RING_API_ERROR("Error : Bad HKEY root or sub key path");
	}
}

// boolean cregsubkeyexist ( CRegistry keyhandle , string subkeyname )
void ring_vm_creg_cregsubkeyexists(void *pPointer) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		LONG lResult;
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			lResult = p->SubKeyExists(RING_API_GETSTRING(2));
			if (lResult == ERROR_SUCCESS) {
				RING_API_RETNUMBER(1);
				return;
			} else if (lResult == 2) {
				RING_API_RETNUMBER(0);
			} else {
				TCHAR msgBuf[200];
				RING_API_RETNUMBER(0);
				RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
			}
		} else { RING_API_ERROR("Error : invalid CRegistry key handle"); }
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle or bad sub key name/path");
	}
}

// void cregsetflags ( CRegistry keyhandle , int flags )
void ring_vm_creg_cregsetflags( void *pPointer) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( p->AcceptedFlags((int) RING_API_GETNUMBER(2)) ) {
				p->SetFlags((int) RING_API_GETNUMBER(2));
			} else RING_API_ERROR("Error : Bad flags configuration");
		} else RING_API_ERROR("Error : invalid CRegistry key handle");
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle or bad flag type");
	}
}

// int cregentriescount ( CRegistry keyhandle )
void ring_vm_creg_cregentriescount( void *pPointer) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p->Count());
		} else RING_API_ERROR("Error : invalid CRegistry key handle");
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle");
	}
}

// int creggetflags ( CRegistry keyhandle )
void ring_vm_creg_creggetflags( void *pPointer) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p->GetFlags());
		} else RING_API_ERROR("Error : invalid CRegistry key handle");
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle");
	}
}

// void cregaccess64tree ( CRegistry keyhandle , boolean access)
void ring_vm_creg_cregaccess64tree( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			p->Access64Tree((int) RING_API_GETNUMBER(2));
		} else RING_API_ERROR("Error : invalid CRegistry key handle");
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle or Wow64 tree access value");
	}
}

// boolean cregisvirtualized (CRegistry key)
// int cregisvirtualized (CRegistry key, bool detailed)
void ring_vm_creg_cregisvirtualized( void *pPointer ) {
	if ( RING_API_PARACOUNT == 0 || RING_API_PARACOUNT > 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_PARACOUNT == 2 ){
		if ( RING_API_ISPOINTER(1) &&  RING_API_ISNUMBER(2)) {
			CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
			if ( (p) && AUTOOPEN_CHECK ) {
				if ( (int) RING_API_GETNUMBER(2) != 0 ) {
					RING_API_RETNUMBER((int) p[0].IsVirtualized()); 
				} else {
					if ((int) p[0].IsVirtualized() == 1) {
						RING_API_RETNUMBER((int) p[0].IsVirtualized());
					} else {
						RING_API_RETNUMBER(((int) p[0].IsVirtualized()) * 0);
					} 
				}
			} else RING_API_ERROR("Error : Bad CRegistry Key handle");
		} else {
			RING_API_ERROR("Error : Bad CRegistry Key handle Or not numerical 2nd para");
		}
	} else {
		if ( RING_API_ISPOINTER(1) ) {
			CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
			if ( (p) && AUTOOPEN_CHECK ) {
				if ((int) p[0].IsVirtualized() == 1) {
					RING_API_RETNUMBER((int) p[0].IsVirtualized());
				} else {
					RING_API_RETNUMBER(((int) p[0].IsVirtualized()) * 0);
				} 
			} else RING_API_ERROR("Error : Bad CRegistry Key handle");
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	}	
}

// int cregsubkeyscount ( CRegistry keyhandle , int valueindex )
void ring_vm_creg_cregsubkeyscount( void *pPointer ) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p->SubKeysCount());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle");
	}
}

// String creggetsubkeyat ( CRegistry keyhandle , int valueindex )
void ring_vm_creg_creggetsubkeyat( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (int) RING_API_GETNUMBER(2) > 0 && (int) RING_API_GETNUMBER(2) < p->SubKeysCount() +1 ) {
			if ( (p) && AUTOOPEN_CHECK ) {
				char subkey[MAX_REG_KEY];
				RING_API_RETSTRING(p->GetSubKeyAt((int) RING_API_GETNUMBER(2) -1, subkey, MAX_REG_KEY));
			} else RING_API_ERROR("Error : Bad CRegistry Key handle");
		} else { RING_API_ERROR("Error : Invalid sub key index or there is no sub keys in this key"); }
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle or sub key index type");
	}
}

// boolean cregrefresh ( CRegistry keyhandle )
void ring_vm_creg_cregrefresh( void *pPointer ) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p->Refresh());
		} else RING_API_ERROR("Error : invalid CRegistry key handle");
	} else {
		RING_API_ERROR("Error : invalid CRegistry key handle");
	}
}

// CRegEntry* creggetat ( CRegistry keyhandle , int valueindex )
void ring_vm_creg_creggetat( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (int) RING_API_GETNUMBER(2) > 0 && (int) RING_API_GETNUMBER(2) < p->Count() +1 ) {
			if ( (p) && AUTOOPEN_CHECK ) {
				RING_API_RETCPOINTER(p->GetAt((int) RING_API_GETNUMBER(2) -1), "CRegEntry");
			} else RING_API_ERROR("Error : Bad CRegistry Key handle");
		} else { RING_API_ERROR("Invalid registry entry index"); }
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle or entry index type");
	}
}

// string creggetname ( CRegEntry entry )
void ring_vm_creg_creggetname( void *pPointer ) {
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		CRegEntry *p = (CRegEntry *) RING_API_GETCPOINTER(1, "CRegEntry") ;
		if ( (p) && p->HasOwner() ) { RING_API_RETSTRING(p->lpszName); }
		else { RING_API_ERROR("Error : Bad entry handle"); }
	} else {
		RING_API_ERROR("Error : Bad entry handle");
	}
}

// void cregcopy ( CRegEntry Entry , CRegistry Dest )\
// void cregcopy ( CRegistry Source , String valuename, CRegistry Dist )
void ring_vm_creg_cregcopy( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 && RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR("Error: Bad parameter count, this function expects two\\three parameters");
		return ;
	}
	if ( RING_API_PARACOUNT == 2 ) {
		if ( RING_API_ISPOINTER(1) && RING_API_ISPOINTER(2) ) {
			CRegEntry *pe = (CRegEntry *) RING_API_GETCPOINTER(1, "CRegEntry") ;
			CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(2, "CRegistry") ;
			if ( ( (pe) && pe->HasOwner() ) &&  ( (p) && AUTOOPEN_CHECK ) ) { pe->SetOwner(p); }
			else { RING_API_ERROR("Error : Bad entry handle or OwnerKey handle"); }
		} else {
			RING_API_ERROR("Error : Bad handles, this function expects good entry and destination Key handles");
		}
	} else {
		if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISPOINTER(3) ) {
			CRegistry *ps = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
			CRegistry *pd = (CRegistry *) RING_API_GETCPOINTER(3, "CRegistry") ;
			if ( ((ps) && ( ps->GetFlags() & CREG_AUTOOPEN ? true : (ps->hKey) )) &&  ((pd) && ( pd->GetFlags() & CREG_AUTOOPEN ? true : (pd->hKey) )) ) { 
				ps[0][RING_API_GETSTRING(2)].SetOwner(pd); 
			} else { RING_API_ERROR("Error : Bad CRegistry source or destination Key handle"); }
		} else {
			RING_API_ERROR("Error : Bad source or destination Key handles or entry name type");
		}
	}
}

// void cregrename ( CRegistry keyhandle , string valuename , string newname)
void ring_vm_creg_cregrename( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) { 
			if (RING_API_GETSTRINGSIZE(2) > 0 && RING_API_GETSTRINGSIZE(3) > 0 ) { 
				if ( EntryExistsM(RING_API_GETSTRING(2)) ) {
					p[0][RING_API_GETSTRING(2)].SetName(RING_API_GETSTRING(3));
				} else { RING_API_ERROR("Error : Couldn't find the entry"); }
			} else { RING_API_ERROR("Error : Entry name could not be empty. Empty names reserved for default entries"); }
		} else { RING_API_ERROR("Error : Bad CRegistry Key handle"); }
	} else {
		RING_API_ERROR("Bad parameters entered this function expects ( OwnerKey , oldEntryName, newEntryName )");
	}
}

// void cregsetvalue ( CRegistry keyhandle , string valuename , string\int value )
void ring_vm_creg_cregsetvalue( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && ( RING_API_ISNUMBER(3) || RING_API_ISSTRING(3) )) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( RING_API_ISNUMBER(3) ) {
				if ( floor(RING_API_GETNUMBER(3)) == RING_API_GETNUMBER(3) ) {
					if ( RING_API_GETNUMBER(3) >= 0 && RING_API_GETNUMBER(3) <= 4294967295 ) {
						p[0][RING_API_GETSTRING(2)] = (DWORD) RING_API_GETNUMBER(3);
					} else {
						p[0][RING_API_GETSTRING(2)] = RING_API_GETNUMBER(3);
					}
				} else {
					p[0][RING_API_GETSTRING(2)] = RING_API_GETNUMBER(3);
				}
			} else p[0][RING_API_GETSTRING(2)] = RING_API_GETSTRING(3);
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name, or value type");
	}
}

// string creggetvalue ( CRegistry keyhandle , string valuename )
void ring_vm_creg_creggetvalue( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( p[0][RING_API_GETSTRING(2)].IsDWORD() ) {
				RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)]);
			} else if ( p[0][RING_API_GETSTRING(2)].IsString() ) {
				RING_API_RETSTRING(p[0][RING_API_GETSTRING(2)]);
			} else {
				RING_API_ERROR("Error : This function can return REG_SZ and REG_DWORD values only");
			}
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : this function expects key handle and entry name");
	}
}

// void cregdelete ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregdelete( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			p[0][RING_API_GETSTRING(2)].Delete();
		} else { RING_API_ERROR("Error : Bad CRegistry Key handle"); }
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle or entry name type");
	}
}

// void cregsetmulti ( cpointer , string valuename , string value )
void ring_vm_creg_cregsetmulti( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && ( p->hKey ) ) {
			size_t size = 0 ;
			if (RING_API_GETSTRINGSIZE(3) != 0) size = RING_API_GETSTRINGSIZE(3) + 2 ;
			p[0][RING_API_GETSTRING(2)].SetMulti(RING_API_GETSTRING(3), size); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, or value type");
	}
}

// void cregmultiremoveat ( CRegistry keyhandle , string valuename , int index )
void ring_vm_creg_cregmultiremoveat( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				if ( RING_API_GETNUMBER(3) > 0 && RING_API_GETNUMBER(3) < p[0][RING_API_GETSTRING(2)].MultiCount() +1 ) {
					p[0][RING_API_GETSTRING(2)].MultiRemoveAt((int) RING_API_GETNUMBER(3) -1); 
				} else RING_API_ERROR("Error : invalid index of this MultiString"); 
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name, or multistring index type");
	}
}

// void cregmultisetat ( CRegistry keyhandle , string valuename , int index , string value)
void ring_vm_creg_cregmultisetat( void *pPointer ) {
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3) && RING_API_ISSTRING(4) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				if ( RING_API_GETNUMBER(3) > 0 && RING_API_GETNUMBER(3) < p[0][RING_API_GETSTRING(2)].MultiCount() +2 ) {
					p[0][RING_API_GETSTRING(2)].MultiSetAt((int) RING_API_GETNUMBER(3) -1 , RING_API_GETSTRING(4));
				} else RING_API_ERROR("Error : invalid index of this MultiString"); 
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");  
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, multistring index type, or value type");
	}
}

// void cregmultiadd ( CRegistry keyhandle , string valuename , string value)
void ring_vm_creg_cregmultiadd( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				p[0][RING_API_GETSTRING(2)].MultiAdd(RING_API_GETSTRING(3)); 
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");  
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, or value type");
	}
}

// string cregmultigetat ( CRegistry keyhandle , string valuename , int index )
void ring_vm_creg_cregmultigetat( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				if ( RING_API_GETNUMBER(3) > 0 && RING_API_GETNUMBER(3) < p[0][RING_API_GETSTRING(2)].MultiCount() +1 ) {
					RING_API_RETSTRING(p[0][RING_API_GETSTRING(2)].MultiGetAt((int) RING_API_GETNUMBER(3) -1)); 
				} else RING_API_ERROR("Error : invalid index of this MultiString"); 
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name, or multistring index type");
	}
}

// int cregmulticount ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregmulticount( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].MultiCount());
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// void cregmulticlear ( cpointer , string valuename )
void ring_vm_creg_cregmulticlear( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsMultiString() ) {
				p[0][RING_API_GETSTRING(2)].MultiClear();
			} else RING_API_ERROR("Error : Not found any MultiString entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle or entry name type");
	}
}

// string creggetexpandsz( CRegistry keyhandle , string valuename )
void ring_vm_creg_creggetexpandsz( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsExpandSZ() ) {
				RING_API_RETSTRING(p[0][RING_API_GETSTRING(2)].GetExpandSZ());
			} else RING_API_ERROR("Error : Not found any REG_EXPAND_SZ entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// void cregsetexpandsz( CRegistry keyhandle , string valuename , string value )
void ring_vm_creg_cregsetexpandsz( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			DWORD lResult = p[0][RING_API_GETSTRING(2)].SetExpandSZ(RING_API_GETSTRING(3));
			if ( lResult != ERROR_SUCCESS ) {
				TCHAR msgBuf[200];
				RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
			}
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, or value type");
	}
}

// string creggetexpandedsz( CRegistry keyhandle , string valuename )
void ring_vm_creg_creggetexpandedsz( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsExpandSZ() ) {
				RING_API_RETSTRING((LPTSTR) p[0][RING_API_GETSTRING(2)]);
			} else RING_API_ERROR("Error : Not found any REG_EXPAND_SZ entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// void cregsetqword( CRegistry keyhandle , string valuename , number\string value )
void ring_vm_creg_cregsetqword( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && (RING_API_ISSTRING(3) || RING_API_ISNUMBER(3)) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			DWORD lResult = 0; 
			if (RING_API_ISNUMBER(3)) {
				lResult = p[0][RING_API_GETSTRING(2)].SetQWORD((UINT64) RING_API_GETNUMBER(3));
			} else {
				if (isnum(RING_API_GETSTRING(3))) {
					lResult = p[0][RING_API_GETSTRING(2)].SetQWORD(_tcstoui64(RING_API_GETSTRING(3), NULL, 10));
				} else RING_API_ERROR("Error : invalid entered QWORD string value"); 
			}
			if ( lResult != ERROR_SUCCESS ) {
				TCHAR msgBuf[200];
				RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
			}
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, value type");
	}
}

// string creggetqword( CRegistry keyhandle , string valuename )
void ring_vm_creg_creggetqword( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsQWORD() ) {
				UINT64 value = p[0][RING_API_GETSTRING(2)].GetQWORD();
				if ( value < 9999999999999910 ) {
					RING_API_RETNUMBER(value);
				} else {
					RING_API_RETSTRING((LPTSTR) p[0][RING_API_GETSTRING(2)]);
				}
			} else RING_API_ERROR("Error : Not found any REG_QWORD entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// string creggetbinary( CRegistry keyhandle , string valuename )
void ring_vm_creg_creggetbinary( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsBinary() ) {
				LPTSTR value = new TCHAR[( p[0][RING_API_GETSTRING(2)].GetBinaryLength() *3 )];
				value[0] = 0;
				for (size_t i = 0; i < p[0][RING_API_GETSTRING(2)].GetBinaryLength(); i++) {
					LPTSTR tmp = new TCHAR[3];
					_stprintf_s(tmp, 3, "%02x", p[0][RING_API_GETSTRING(2)].GetBinaryAt(i));
					_tcscat(value, tmp);
					if ( i+1 != p[0][RING_API_GETSTRING(2)].GetBinaryLength() ) 
						_tcscat(value, _T(","));
				}
				RING_API_RETSTRING(value);
			} else RING_API_ERROR("Error : Not found any REG_QWORD entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// void cregsetbinary( CRegistry keyhandle , string valuename , string value )
void ring_vm_creg_cregsetbinary( void *pPointer ) {
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			LPTSTR value = RING_API_GETSTRING(3);
			size_t sbsize ;
			LPBYTE lpbvalue;
			if (_tcslen(value) == 0) { sbsize = 0; }
			else if (_tcslen(value)%3 == 2) { sbsize = (_tcslen(value) +1)/3; } 
			else { RING_API_ERROR("Error : Unexpected binary string length"); }
			lpbvalue= new BYTE[sbsize]; 
			for (size_t i = 0; i < sbsize ; i++) {
				LPTSTR tmp = new TCHAR[3];
				_tcsncpy(tmp, value + (i*3) , 2);
				for (size_t c = 0; c < (_tcslen(tmp) < 3 ? _tcslen(tmp) : 2); c++) { 
					if ( _tcslen(tmp) == 1 ) RING_API_ERROR("Error : Unexpected binary string length");
					if ( !isxdigit((int) tmp[c]) ) RING_API_ERROR("Error : Invalid binary string character");
				}
				lpbvalue[i] = (BYTE) _tcstol(tmp, NULL, 16);
				delete[] tmp;
			}
			p[0][RING_API_GETSTRING(2)].SetBinary(lpbvalue, sbsize);
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, entry name type, or value type");
	}
}

// int cregbinarylength( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregbinarylength( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( EntryExistsM(RING_API_GETSTRING(2)) && p[0][RING_API_GETSTRING(2)].IsBinary() ) {
				RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].GetBinaryLength());
			} else RING_API_ERROR("Error : Not found any REG_QWORD entry with this name!!"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregisstring ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregisstring( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsString());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregisdword ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregisdword( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsDWORD());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregismultistring ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregismultistring( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsMultiString());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregisbinary ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregisbinary( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsBinary());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregisexpandsz ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregisexpandsz( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsExpandSZ());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregisqword ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregisqword( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].IsQWORD());
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// boolean cregexists ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregexists( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			DWORD lResult= p[0][RING_API_GETSTRING(2)].Exists();
			switch (lResult) {
				case ERROR_SUCCESS:
					RING_API_RETNUMBER(1);
					break;
				case ERROR_FILE_NOT_FOUND:
					RING_API_RETNUMBER(0);
					break;
				default:
					TCHAR msgBuf[200];
					RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
			}
			return ;
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}

// int cregtype ( CRegistry keyhandle , string valuename )
void ring_vm_creg_cregtype( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			DWORD lResult= p[0][RING_API_GETSTRING(2)].Type();
			if ( lResult < 12 ) {
				RING_API_RETNUMBER(lResult);
			} else {
				TCHAR msgBuf[200];
				RING_API_ERROR(GetErrorMsg(lResult - 12, msgBuf, 200));
			}
			return ;
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");
	} else {
		RING_API_ERROR("Error : Bad CRegistry Key handle, or entry name type");
	}
}



BOOL EntryExists(void *pPointer, CRegistry* key, LPTSTR entry) {
	DWORD lResult= key[0][entry].Exists();
			switch (lResult) {
				case ERROR_SUCCESS:
					return true;
					break;
				case ERROR_FILE_NOT_FOUND:
					return false;
					break;
				default:
					TCHAR msgBuf[200];
					RING_API_ERROR(GetErrorMsg(lResult, msgBuf, 200));
					return false;
			}
}

unsigned char isnum(LPCSTR str) {
	bool n = true;
	for (int i=0;i< _tcslen(str);i++) {
		if ( (isdigit(str[i])) || (str[i] == '.' &&  n == true)) {
			if (str[i] == '.') n = false;
		} else return 0;
	}
	return 1;
}

LPTSTR GetFormattedMessage(LONG ErrId){
    LPTSTR pBuffer = NULL;
    FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                  NULL, 
                  ErrId,
				  // if next para set to zero the msg will be according to system language
                  MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                  (LPTSTR)&pBuffer, 
                  0, 
                  NULL);
    return pBuffer;
}

LPTSTR GetErrorMsg(LONG ErrorId , LPTSTR pMsg, size_t pMsgsize){
    LPTSTR pBuffer = NULL;
	pBuffer = GetFormattedMessage(ErrorId);
    if (pBuffer)
    {
		sprintf_s(pMsg, pMsgsize, "Error ID (%d) : %s", ErrorId, pBuffer);
		LocalFree(pBuffer);
     }
    else
    {
		sprintf_s(pMsg, pMsgsize, "Format message failed with : %d", GetLastError());
    } 
	return pMsg;
}




/* 

============================================================================================

					THIS IS THE GARBAGE PART OF THIS EXTENSION ^_^

============================================================================================



------------------------------------------------------------------------
Functions Names : CRegGetMulti, CRegMultiLength

Their job : Get value, and the whole length of MultiString values

Cause of deactivation : There're some problems arose when trying to deal with them remotely from RING
						Because we can not deal with all string length including null terminates so that
						they become useless. 
						Insteed we have some other fucntions that deal with each member of MultiString 
						entries perfectly. 

Idea for reactivation : should replce null termination into another character so that we can port them
						to RING easly then when returned put them in their places
						


-------------------------------------------------------------------------
-------------------------------- THE CODE -------------------------------
-------------------------------------------------------------------------



// string creggetmulti ( cpointer , string valuename )
void ring_vm_creg_creggetmulti( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( RING_API_GETSTRINGSIZE(2) > 0 ) {
				RING_API_RETSTRING(p[0][RING_API_GETSTRING(2)].GetMulti());
			} else RING_API_ERROR("Error : The default entry is not a MultiString"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle");  
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}


// int cregmultilength ( cpointer , string valuename )
void ring_vm_creg_cregmultilength( void *pPointer ) {
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		CRegistry *p = (CRegistry *) RING_API_GETCPOINTER(1, "CRegistry") ;
		if ( (p) && AUTOOPEN_CHECK ) {
			if ( RING_API_GETSTRINGSIZE(2) > 0 ) {
				RING_API_RETNUMBER(p[0][RING_API_GETSTRING(2)].MultiLength());
			} else RING_API_ERROR("Error : The default entry is not a MultiString"); 
		} else RING_API_ERROR("Error : Bad CRegistry Key handle"); 
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}
-------------------------------------------------------------------------
-------------------------------------------------------------------------



-------------------------------------------------------------------------
Functions Name : 

It's job : 

Cause of deactivation : 

Idea for reactivation : 
						

-------------------------------------------------------------------------
-------------------------------- THE CODE -------------------------------
-------------------------------------------------------------------------


*/


}

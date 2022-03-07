/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#ifdef _WIN32
    #include <windows.h>
#endif
/* General Functions */

int ring_general_fexists ( const char *cFileName )
{
    FILE *fp  ;
    fp = fopen(cFileName , "r" );
    if ( fp ) {
        fclose( fp ) ;
        return 1 ;
    }
    return 0 ;
}

int ring_general_currentdir ( char *cDirPath )
{
    int nSize  ;
    nSize = RING_PATHSIZE ;
    if ( !GetCurrentDir(cDirPath, nSize) ) {
        return errno ;
    }
    cDirPath[nSize-1] = '\0' ;
    return 0 ;
}

int ring_general_exefilename ( char *cDirPath )
{
    unsigned int nSize  ;
    nSize = RING_PATHSIZE ;
    #ifdef _WIN32
        /* Windows only */
        GetModuleFileName(NULL,cDirPath,nSize);
    #elif __MACH__
        /* Mac OS X */
        _NSGetExecutablePath(cDirPath,&nSize);
        char *cCorrectPath = realpath(cDirPath,NULL) ;
        if ( cCorrectPath != NULL ) {
            strncpy(cDirPath,cCorrectPath,nSize) ;
            free(cCorrectPath) ;
        }
    #elif __linux__
        /* readlink() doesn't null terminate */
        memset(cDirPath,0,nSize);
        if ( ! readlink("/proc/self/exe",cDirPath,nSize) ) {
            return 0 ;
        }
    #endif
    return 1 ;
}

int ring_general_chdir ( const char *cDir )
{
    #ifdef _WIN32
        /* Windows only */
        #ifdef __BORLANDC__
            /* Borland C/C++ */
            return chdir(cDir) ;
        #else
            /* Modern Compilers Like Visual C/C++ */
            return _chdir(cDir) ;
        #endif
    #else
        return chdir(cDir) ;
    #endif
}

void ring_general_exefolder ( char *cDirPath )
{
    char cDir[RING_PATHSIZE]  ;
    char cDir2[RING_PATHSIZE]  ;
    int x,x2,nSize  ;
    ring_general_exefilename(cDir);
    nSize = strlen( cDir ) ;
    strcpy(cDir2,"");
    for ( x = nSize-1 ; x >= 0 ; x-- ) {
        if ( (cDir[x] == '\\') || (cDir[x] == '/') ) {
            for ( x2 = x ; x2 >= 0 ; x2-- ) {
                cDir2[x2] = cDir[x2] ;
            }
            cDir2[x+1] = '\0' ;
            break ;
        }
    }
    strcpy(cDirPath,cDir2);
}

void ring_general_switchtofilefolder ( char *cFileName )
{
    char cFileName2[RING_PATHSIZE]  ;
    strcpy(cFileName2,cFileName);
    if ( ring_general_justfilepath(cFileName2) ) {
        ring_general_chdir(cFileName2);
        /* Remove The Path from the file Name - Keep the File Name Only */
        ring_general_justfilename(cFileName);
        return ;
    }
}

int ring_general_justfilepath ( char *cFileName )
{
    int x,nSize  ;
    nSize = strlen( cFileName ) ;
    for ( x = nSize-1 ; x >= 0 ; x-- ) {
        if ( (cFileName[x] == '\\') || (cFileName[x] == '/') ) {
            cFileName[x+1] = '\0' ;
            return 1 ;
        }
    }
    return 0 ;
}

void ring_general_justfilename ( char *cFileName )
{
    int x,nSize,r  ;
    nSize = strlen( cFileName ) ;
    for ( x = nSize-1 ; x >= 0 ; x-- ) {
        if ( (cFileName[x] == '\\') || (cFileName[x] == '/') ) {
            r = 0 ;
            for ( x = x+1 ; x <= nSize+1 ; x++ ) {
                cFileName[r] = cFileName[x] ;
                r++ ;
            }
            break ;
        }
    }
}

int ring_general_issourcefile ( const char *cStr )
{
    int x  ;
    x = strlen(cStr) - 1 ;
    if ( x >= 5 ) {
        if ( tolower(cStr[x]) == 'g' && tolower(cStr[x-1]) == 'n' && tolower(cStr[x-2]) == 'i' && tolower(cStr[x-3]) == 'r' && cStr[x-4] == '.' ) {
            return 1 ;
        }
    }
    return 0 ;
}

int ring_general_isobjectfile ( const char *cStr )
{
    int x  ;
    x = strlen(cStr) - 1 ;
    if ( x > 6 ) {
        if ( tolower(cStr[x]) == 'o' && tolower(cStr[x-1]) == 'g' && tolower(cStr[x-2]) == 'n' && tolower(cStr[x-3]) == 'i' && tolower(cStr[x-4]) == 'r' && cStr[x-5] == '.' ) {
            return 1 ;
        }
    }
    return 0 ;
}

RING_API void ring_general_printline ( void )
{
    puts("===========================================================================");
}

void ring_general_showtime ( void )
{
    time_t timer  ;
    char buffer[50]  ;
    struct tm*tm_info  ;
    clock_t myclock  ;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer,50,"Date  : %Y/%m/%d Time : %H:%M:%S", tm_info);
    printf( "\n" ) ;
    ring_general_printline();
    puts(buffer);
    myclock = clock();
    printf( "Clock : %ld \n", myclock ) ;
    ring_general_printline();
}

RING_FILE ring_custom_fopen ( const char*cFileName, const char*cMode )
{
    #ifdef _WIN32
        /* Code For MS-Windows */
        RING_FILE fp  ;
        int nLen1,nLen2,nFileNameSize,nModeSize  ;
        wchar_t cPath[MAX_PATH]  ;
        wchar_t cWMode[MAX_PATH]  ;
        /* Set Variables */
        nLen1 = 0 ;
        nLen2 = 0 ;
        nFileNameSize = strlen(cFileName) ;
        nModeSize = strlen(cMode) ;
        if ( (nFileNameSize == 0) || (nModeSize==0) ) {
            return NULL ;
        }
        nLen1 = MultiByteToWideChar(CP_UTF8, 0, cFileName, nFileNameSize, cPath, nFileNameSize) ;
        if ( nLen1 >= MAX_PATH ) {
            return NULL ;
        }
        cPath[nLen1] = L'\0' ;
        nLen2 = MultiByteToWideChar(CP_UTF8, 0, cMode, nModeSize, cWMode, nModeSize) ;
        if ( nLen2 >= MAX_PATH ) {
            return NULL ;
        }
        cWMode[nLen2] = L'\0' ;
        fp = _wfopen(cPath, cWMode);
        return fp ;
    #else
        return RING_OPENFILE(cFileName, cMode) ;
    #endif
}

void ring_general_addosfileseparator ( char *cFileName )
{
    #ifdef _WIN32
        strcat(cFileName,"\\");
    #else
        strcat(cFileName,"/");
    #endif
}

int ring_general_folderexistinfilename ( const char *cFolderName,const char *cFileName )
{
    int x  ;
    if ( strlen(cFolderName) < strlen(cFileName) ) {
        #ifdef _WIN32
            for ( x = 0 ; (unsigned) x < strlen(cFolderName) ; x++ ) {
                if ( ( tolower(cFolderName[x]) != tolower(cFileName[x]) ) ) {
                    return 0 ;
                }
            }
        #else
            for ( x = 0 ; (unsigned) x < strlen(cFolderName) ; x++ ) {
                if ( cFolderName[x] != cFileName[x] ) {
                    return 0 ;
                }
            }
        #endif
        return 1 ;
    }
    return 0 ;
}

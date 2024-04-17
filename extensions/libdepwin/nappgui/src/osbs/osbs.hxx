/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osbs.hxx
 * https://nappgui.com/en/osbs/osbs.html
 *
 */

/* Osbs library (Operating System Basic Services) */

#ifndef __OSBS_HXX__
#define __OSBS_HXX__

#include <sewer/sewer.hxx>
#include "osbs.def"

typedef enum _platform_t
{
    ekWINDOWS = 1,
    ekMACOS,
    ekLINUX,
    ekIOS
} platform_t;

typedef enum _device_t
{
    ekDESKTOP = 1,
    ekPHONE,
    ekTABLET
} device_t;

typedef enum _win_t
{
    ekWIN_9x = 1,
    ekWIN_NT4,
    ekWIN_2K,
    ekWIN_XP,
    ekWIN_XP1,
    ekWIN_XP2,
    ekWIN_XP3,
    ekWIN_VI,
    ekWIN_VI1,
    ekWIN_VI2,
    ekWIN_7,
    ekWIN_71,
    ekWIN_8,
    ekWIN_81,
    ekWIN_10,
    ekWIN_NO
} win_t;

typedef enum _endian_t
{
    ekLITEND = 1,
    ekBIGEND
} endian_t;

typedef enum _week_day_t
{
    ekSUNDAY,
    ekMONDAY,
    ekTUESDAY,
    ekWEDNESDAY,
    ekTHURSDAY,
    ekFRIDAY,
    ekSATURDAY
} week_day_t;

typedef enum _month_t
{
    ekJANUARY = 1,
    ekFEBRUARY,
    ekMARCH,
    ekAPRIL,
    ekMAY,
    ekJUNE,
    ekJULY,
    ekAUGUST,
    ekSEPTEMBER,
    ekOCTOBER,
    ekNOVEMBER,
    ekDECEMBER
} month_t;

typedef enum _file_type_t
{
    ekARCHIVE = 1,
    ekDIRECTORY,
    ekOTHERFILE
} file_type_t;

typedef enum _file_mode_t
{
    ekREAD = 1,
    ekWRITE,
    ekAPPEND
} file_mode_t;

typedef enum _file_seek_t
{
    ekSEEKSET = 1,
    ekSEEKCUR,
    ekSEEKEND
} file_seek_t;

typedef enum _ferror_t
{
    ekFEXISTS = 1,
    ekFNOPATH,
    ekFNOFILE,
    ekFBIGNAME,
    ekFNOFILES,
    ekFNOEMPTY,
    ekFNOACCESS,
    ekFLOCK,
    ekFBIG,
    ekFSEEKNEG,
    ekFUNDEF,
    ekFOK
} ferror_t;

typedef enum _perror_t
{
    ekPPIPE = 1,
    ekPEXEC,
    ekPOK
} perror_t;

typedef enum _serror_t
{
    ekSNONET = 1,
    ekSNOHOST,
    ekSTIMEOUT,
    ekSSTREAM,
    ekSUNDEF,
    ekSOK
} serror_t;

typedef struct _date_t Date;
typedef struct _dir_t Dir;
typedef struct _file_t File;
typedef struct _mutex_t Mutex;
typedef struct _process_t Proc;
typedef struct _dlib_t DLib;
typedef struct _thread_t Thread;
typedef struct _socket_t Socket;

typedef uint32_t (*FPtr_thread_main)(void *data);
#define FUNC_CHECK_THREAD_MAIN(func, type) \
    (void)((uint32_t(*)(type *))func == func)

typedef void (*FPtr_libproc)(void);

struct _date_t
{
    int16_t year;
    uint8_t month;
    uint8_t wday;
    uint8_t mday;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};

#endif

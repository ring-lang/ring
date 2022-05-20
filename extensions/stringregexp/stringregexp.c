 /* 
-----------------------------------------------------------------------------------
 
            stringregexp Vers ..................: 0.1
            Author .............................: Stefano Cerbioni
            mail ...............................: stfn77@gmail.com	
            Script Function ....................: regular expression
 
-----------------------------------------------------------------------------------
 */ 

#include "ring.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>
#include <regex.h>
#include <pcre.h>

// FOR PCRE -----------------------------------------------
#define OVECCOUNT 30    /* should be a multiple of 3 */
#define EBUFLEN 128            
#define BUFLEN 1024   
// --------------------------------------------------------

char *str;


void match_all(regex_t *p, char *sz) {
    regmatch_t whole_match;
    int match = 0;
    size_t offset = 0;
    size_t length = strlen(sz);
    char result[BUFSIZ];
    int len;
	
/* Initial memory allocation */
   str = (char *) malloc(15);
   //strcpy(str, "tutorialspoint");
   //printf("String = %s,  Address = %u\n", str, str);

    while (regexec(p, sz + offset, 1, &whole_match, 0) == 0) {
        match = 1;
        len = whole_match.rm_eo - whole_match.rm_so;
        memcpy(result, sz + whole_match.rm_so, len);
        result[len] = 0;
        //printf("Match: %s\n", result);
		str = (char *) realloc(str,(len+1));
		strcat(str, result);
        strcat(str, "-");

        offset += whole_match.rm_eo + 1; // increase the starting offset
        if (offset > length) {
            break;
        }
    }
    if (! match) {
        printf("\"%s\" does not contain a match\n", sz);
    }

}

RING_FUNC(ring_stringregexp)
{

	// Check Parameters Count
		if (RING_API_PARACOUNT != 4) {
			RING_API_ERROR(RING_API_MISS1PARA);
			return;
		}
	// Check Parameters Type
		if ( ! RING_API_ISSTRING(1) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
	   if ( ! RING_API_ISSTRING(2) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
		if ( ! RING_API_ISSTRING(3) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
        if ( ! RING_API_ISSTRING(4) ) {
			RING_API_ERROR(RING_API_BADPARATYPE);
			return;
		}
        
    const char *StyleRgXp = RING_API_GETSTRING(1);
    const char *TesTsSubj = RING_API_GETSTRING(2);
    const char *PatterN = RING_API_GETSTRING(3);
    const char *ArraYDimSScanF = RING_API_GETSTRING(4);

    //  -----------------------------------------------------------------------------------
    //  ---------------------------- REGEXP IN C STYLE ------------------------------------
    //  -----------------------------------------------------------------------------------

    if( strcmp(StyleRgXp, "c") == 0){
    int r;
    regex_t p;
    r = regcomp(&p, PatterN , 0); //"[[:alnum:]]*k[[:alnum:]]*"
    if (r != 0) {
        //printf("regcomp failed\n");
		RING_API_RETSTRING("regcomp failed\n");
    }
    match_all(&p, (char *)TesTsSubj); //"mikko mikko"

   
	regfree(&p);
	RING_API_RETSTRING(str);
	free(str);
    }
    //  -----------------------------------------------------------------------------------
    //  ---------------------------- REGEXP IN PERL STYLE ---------------------------------
    //  -----------------------------------------------------------------------------------

    if ( strcmp(StyleRgXp, "p") == 0) {
        pcre *re;
        const char *error;
        int erroffset;
        int ovector[OVECCOUNT];
        int rc, i;
        char *substring_start ;
        re = pcre_compile(PatterN, 0, &error, &erroffset, NULL);
        if (re == NULL) {
                printf("PCRE compilation failed at offset %d: %s/n", erroffset, error);
        }


        // MATCH FIRST OCCURRENCE ******************************************************************
        rc = pcre_exec(re, NULL, TesTsSubj, strlen(TesTsSubj), 0, 0, ovector, OVECCOUNT);
        if (rc < 0) {
                if (rc == PCRE_ERROR_NOMATCH) substring_start =("Sorry, no match .../n"); //printf("Sorry, no match .../n");
                else   substring_start = ("Matching error %d/n");// printf("Matching error %d/n", rc);
        }
        for (i = 1; i < rc; i++) {
                substring_start = ((char *)TesTsSubj) + ovector[2*i];
                int substring_length = ovector[2*i+1] - ovector[2*i];
               substring_start[substring_length] = '\0';
        }
        RING_API_RETSTRING(substring_start);    
        // ******************************************************************************************       
    }
    
    //  -----------------------------------------------------------------------------------
    //  ---------------------------- REGEXP IN SSCANF STYLE -------------------------------
    //  -----------------------------------------------------------------------------------
    if ( strcmp(StyleRgXp, "s") == 0) {
        if (strcmp(ArraYDimSScanF, "0") != 0) {
            int IndeX = atoi(ArraYDimSScanF);
            char temp[IndeX];
            int len = 0, id = 0, result = 0;
             //result = sscanf(STR, "%*[^:]:%d,%*[^,],%d,%[^\r]", &id, &len, temp);
            result = sscanf(TesTsSubj, PatterN, &id, &len, temp);

            if (result == 3) {
                  RING_API_RETSTRING(temp);
            } else {
                  RING_API_RETSTRING("match failed.");
               }
        }
    }

}

RING_API void ringlib_init(RingState *pRingState)
{ 
    ring_vm_funcregister("stringregexp",ring_stringregexp);
}

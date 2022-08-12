#include "ring.h"

#include "regex.h"
#include "ring_regex.h"



RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("regexmatch",ring_vm_ring_regex_match);
	
}


void ring_vm_ring_regex_match( void *pPointer )
{

	int    status =0;
    regex_t    re;

	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

    
    if (regcomp(&re, RING_API_GETSTRING(2), REG_EXTENDED|REG_NOSUB) != 0) {
        RING_API_RETNUMBER(0);     
        	return ;
    }
   status = regexec(&re, RING_API_GETSTRING(1), (size_t) 0, NULL, 0);

    regfree(&re);
     if (status != 0 ) {
         RING_API_RETNUMBER(0);     
           	return ;
    }
   
  RING_API_RETNUMBER(1);

}

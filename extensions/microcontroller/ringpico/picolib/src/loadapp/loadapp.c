// RingPico Extension - Loading Ring Application
// 2024, Mahmoud Fayed

#include "pico/stdlib.h"

#include "ring.h" 

// The files ringappcode.h and ringappcode.c will be generated from Ring source code
#include "ringappcode.h" 
#include "ringappcode.c"

int main( void )
{
	RingState *pRingState;  
	pRingState = ring_state_new();  
	pRingState->pRingFilesList  = ring_list_new_gc(pRingState,RING_ZERO);  
	pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);  
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,"pico.ringo");  
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,"pico.ringo");  
	loadRingCode(pRingState);  
	ring_objfile_updateclassespointers(pRingState);  
	ring_state_runprogram(pRingState);  
	ring_state_delete(pRingState);  
	return RING_ZERO;  
}


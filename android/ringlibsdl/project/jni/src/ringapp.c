#include "SDL.h"
#include "ring.h"

int main(int argc, char *argv[])
{
 	RingState *pState = ring_state_new();  	
	ring_state_runfile(pState,"start.ring");
	ring_state_delete(pState);
	return 0;
}
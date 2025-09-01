/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ringext_h
#define ringext_h
/* Constants */
#define RING_VM_LISTFUNCS 1
#define RING_VM_REFMETA 1
#define RING_VM_INFO 1
#define RING_VM_MATH 1
#define RING_VM_FILE 1
#define RING_VM_OS 1
#define RING_VM_DLL 1
/* Compiler - Scanner - Reading Files Functions */
#include "SDL.h"
#define RING_FILE            SDL_RWops *
#define RING_OPENFILE(x,y)   SDL_RWFromFile(x,y)
#define RING_CLOSEFILE(x)    SDL_RWclose(x)
#define RING_READCHAR(x,y,z) z = SDL_RWread(x,&y,1,1) 
#endif

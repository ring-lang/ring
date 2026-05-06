/* Copyright (c) 2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

#ifdef __GNUC__

void ring_vm_computedgoto(VM *pVM) {
	static void *const dispatch[] = {
		[ICO_PUSHC] = &&L_ICO_PUSHC,
		[ICO_PUSHNL] = &&L_ICO_PUSHNL,
		[ICO_PUSH2N] = &&L_ICO_PUSH2N,
		[ICO_PUSHN] = &&L_ICO_PUSHN,
		[ICO_PUSHV] = &&L_ICO_PUSHV,
		[ICO_LOADADDRESS] = &&L_ICO_LOADADDRESS,
		[ICO_ASSIGNMENT] = &&L_ICO_ASSIGNMENT,
		[ICO_INC] = &&L_ICO_INC,
		[ICO_LOADAPUSHV] = &&L_ICO_LOADAPUSHV,
		[ICO_NEWLINE] = &&L_ICO_NEWLINE,
		[ICO_FREESTACK] = &&L_ICO_FREESTACK,
		[ICO_FILENAME] = &&L_ICO_FILENAME,
		[ICO_FREELOADASCOPE] = &&L_ICO_FREELOADASCOPE,
		[ICO_JUMP] = &&L_ICO_JUMP,
		[ICO_JUMPZERO] = &&L_ICO_JUMPZERO,
		[ICO_JUMPFOR] = &&L_ICO_JUMPFOR,
		[ICO_JUMPONE] = &&L_ICO_JUMPONE,
		[ICO_JUMPZERO2] = &&L_ICO_JUMPZERO2,
		[ICO_JUMPONE2] = &&L_ICO_JUMPONE2,
		[ICO_PUSHNULLTHENJUMP] = &&L_ICO_PUSHNULLTHENJUMP,
		[ICO_PUSHNTHENJUMP] = &&L_ICO_PUSHNTHENJUMP,
		[ICO_LESSEQUAL] = &&L_ICO_LESSEQUAL,
		[ICO_EQUAL] = &&L_ICO_EQUAL,
		[ICO_LESS] = &&L_ICO_LESS,
		[ICO_GREATER] = &&L_ICO_GREATER,
		[ICO_GREATEREQUAL] = &&L_ICO_GREATEREQUAL,
		[ICO_NOTEQUAL] = &&L_ICO_NOTEQUAL,
		[ICO_SUM] = &&L_ICO_SUM,
		[ICO_SUB] = &&L_ICO_SUB,
		[ICO_MUL] = &&L_ICO_MUL,
		[ICO_DIV] = &&L_ICO_DIV,
		[ICO_MOD] = &&L_ICO_MOD,
		[ICO_NEG] = &&L_ICO_NEG,
		[ICO_PLUSPLUS] = &&L_ICO_PLUSPLUS,
		[ICO_MINUSMINUS] = &&L_ICO_MINUSMINUS,
		[ICO_POW] = &&L_ICO_POW,
		[ICO_SUMN] = &&L_ICO_SUMN,
		[ICO_SUBN] = &&L_ICO_SUBN,
		[ICO_MULN] = &&L_ICO_MULN,
		[ICO_DIVN] = &&L_ICO_DIVN,
		[ICO_MODN] = &&L_ICO_MODN,
		[ICO_POWN] = &&L_ICO_POWN,
		[ICO_AND] = &&L_ICO_AND,
		[ICO_OR] = &&L_ICO_OR,
		[ICO_NOT] = &&L_ICO_NOT,
		[ICO_LISTSTART] = &&L_ICO_LISTSTART,
		[ICO_LISTITEM] = &&L_ICO_LISTITEM,
		[ICO_LISTITEMN] = &&L_ICO_LISTITEMN,
		[ICO_LISTITEMC] = &&L_ICO_LISTITEMC,
		[ICO_LISTEND] = &&L_ICO_LISTEND,
		[ICO_LOADINDEXADDRESS] = &&L_ICO_LOADINDEXADDRESS,
		[ICO_LOADFUNC] = &&L_ICO_LOADFUNC,
		[ICO_CALL] = &&L_ICO_CALL,
		[ICO_RETURN] = &&L_ICO_RETURN,
		[ICO_RETURNN] = &&L_ICO_RETURNN,
		[ICO_RETNULL] = &&L_ICO_RETNULL,
		[ICO_RETFROMEVAL] = &&L_ICO_RETFROMEVAL,
		[ICO_RETITEMREF] = &&L_ICO_RETITEMREF,
		[ICO_NEWFUNC] = &&L_ICO_NEWFUNC,
		[ICO_BLOCKFLAG] = &&L_ICO_BLOCKFLAG,
		[ICO_ANONYMOUS] = &&L_ICO_ANONYMOUS,
		[ICO_BYE] = &&L_ICO_BYE,
		[ICO_EXITMARK] = &&L_ICO_EXITMARK,
		[ICO_POPEXITMARK] = &&L_ICO_POPEXITMARK,
		[ICO_EXIT] = &&L_ICO_EXIT,
		[ICO_LOOP] = &&L_ICO_LOOP,
		[ICO_PUSHP] = &&L_ICO_PUSHP,
		[ICO_INCP] = &&L_ICO_INCP,
		[ICO_PUSHPV] = &&L_ICO_PUSHPV,
		[ICO_INCJUMP] = &&L_ICO_INCJUMP,
		[ICO_INCPJUMP] = &&L_ICO_INCPJUMP,
		[ICO_LOADFUNCP] = &&L_ICO_LOADFUNCP,
		[ICO_PUSHPLOCAL] = &&L_ICO_PUSHPLOCAL,
		[ICO_PUSHARG] = &&L_ICO_PUSHARG,
		[ICO_INCLPJUMP] = &&L_ICO_INCLPJUMP,
		[ICO_INCPJUMPSTEP1] = &&L_ICO_INCPJUMPSTEP1,
		[ICO_INCLPJUMPSTEP1] = &&L_ICO_INCLPJUMPSTEP1,
		[ICO_LEN] = &&L_ICO_LEN,
		[ICO_SETOPCODE] = &&L_ICO_SETOPCODE,
		[ICO_CHECKBRACEMETHOD] = &&L_ICO_CHECKBRACEMETHOD,
		[ICO_TRY] = &&L_ICO_TRY,
		[ICO_DONE] = &&L_ICO_DONE,
		[ICO_DUPLICATE] = &&L_ICO_DUPLICATE,
		[ICO_RANGE] = &&L_ICO_RANGE,
		[ICO_NEWOBJ] = &&L_ICO_NEWOBJ,
		[ICO_SETSCOPE] = &&L_ICO_SETSCOPE,
		[ICO_LOADSUBADDRESS] = &&L_ICO_LOADSUBADDRESS,
		[ICO_LOADMETHOD] = &&L_ICO_LOADMETHOD,
		[ICO_LOADMETHODP] = &&L_ICO_LOADMETHODP,
		[ICO_LOADBRACEMETHODP] = &&L_ICO_LOADBRACEMETHODP,
		[ICO_AFTERCALLMETHOD] = &&L_ICO_AFTERCALLMETHOD,
		[ICO_AFTERCALLMETHOD2] = &&L_ICO_AFTERCALLMETHOD2,
		[ICO_NEWCLASS] = &&L_ICO_NEWCLASS,
		[ICO_BRACESTART] = &&L_ICO_BRACESTART,
		[ICO_BRACEEND] = &&L_ICO_BRACEEND,
		[ICO_IMPORT] = &&L_ICO_IMPORT,
		[ICO_PRIVATE] = &&L_ICO_PRIVATE,
		[ICO_SETPROPERTY] = &&L_ICO_SETPROPERTY,
		[ICO_CALLCLASSINIT] = &&L_ICO_CALLCLASSINIT,
		[ICO_BITAND] = &&L_ICO_BITAND,
		[ICO_BITOR] = &&L_ICO_BITOR,
		[ICO_BITXOR] = &&L_ICO_BITXOR,
		[ICO_BITNOT] = &&L_ICO_BITNOT,
		[ICO_BITSHL] = &&L_ICO_BITSHL,
		[ICO_BITSHR] = &&L_ICO_BITSHR,
		[ICO_STEPNUMBER] = &&L_ICO_STEPNUMBER,
		[ICO_STEPFROMREG] = &&L_ICO_STEPFROMREG,
		[ICO_POPSTEP] = &&L_ICO_POPSTEP,
		[ICO_LOADAFIRST] = &&L_ICO_LOADAFIRST,
		[ICO_NEWGLOBALSCOPE] = &&L_ICO_NEWGLOBALSCOPE,
		[ICO_ENDGLOBALSCOPE] = &&L_ICO_ENDGLOBALSCOPE,
		[ICO_SETGLOBALSCOPE] = &&L_ICO_SETGLOBALSCOPE,
		[ICO_FREETEMPLISTS] = &&L_ICO_FREETEMPLISTS,
		[ICO_OPTIONALLOOP] = &&L_ICO_OPTIONALLOOP,
		[ICO_SETREFERENCE] = &&L_ICO_SETREFERENCE,
		[ICO_KILLREFERENCE] = &&L_ICO_KILLREFERENCE,
		[ICO_ASSIGNMENTPOINTER] = &&L_ICO_ASSIGNMENTPOINTER,
		[ICO_BEFOREEQUAL] = &&L_ICO_BEFOREEQUAL,
	};
	#define NEXT() do { \
		if (pVM->nPC > RING_VM_INSTRUCTIONSCOUNT) return; \
		pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1; \
		pVM->nOPCode = RING_VM_IR_OPCODE; \
		pVM->nPC++; \
		if (pVM->nSP > RING_VM_STACK_CHECKOVERFLOW) { ring_vm_error(pVM, RING_VM_ERROR_STACKOVERFLOW); } \
		void *tgt = dispatch[pVM->nOPCode]; \
		if (tgt) goto *tgt; else goto L_default; \
	} while (0)

	/* Prime the fetch for the first instruction, then jump in. */
	NEXT();

	L_ICO_PUSHC:
		RING_VM_STACK_PUSHC;
		NEXT();
	L_ICO_PUSHNL:
		RING_VM_STACK_PUSHNL;
		NEXT();
	L_ICO_PUSH2N:
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG1));
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG2));
		NEXT();
	L_ICO_PUSHN:
		RING_VM_STACK_PUSHNVALUE(RING_VM_IR_READDVALUE(RING_VM_IR_REG1));
		NEXT();
	L_ICO_PUSHV:
		ring_vm_pushv(pVM);
		NEXT();
	L_ICO_LOADADDRESS:
		ring_vm_loadaddress(pVM);
		NEXT();
	L_ICO_ASSIGNMENT:
		ring_vm_assignment(pVM);
		NEXT();
	L_ICO_INC:
		ring_vm_inc(pVM);
		NEXT();
	L_ICO_LOADAPUSHV:
		ring_vm_loadapushv(pVM);
		NEXT();
	L_ICO_NEWLINE:
		ring_vm_newline(pVM);
		NEXT();
	L_ICO_FREESTACK:
		ring_vm_freestack(pVM);
		NEXT();
	L_ICO_FILENAME:
		ring_vm_setfilename(pVM);
		NEXT();
	L_ICO_FREELOADASCOPE:
		ring_vm_freeloadaddressscope(pVM);
		NEXT();
	L_ICO_JUMP:
		RING_VM_JUMP;
		NEXT();
	L_ICO_JUMPZERO:
		ring_vm_jumpzero(pVM);
		NEXT();
	L_ICO_JUMPFOR:
		ring_vm_jumpfor(pVM);
		NEXT();
	L_ICO_JUMPONE:
		ring_vm_jumpone(pVM);
		NEXT();
	L_ICO_JUMPZERO2:
		ring_vm_jumpzero2(pVM);
		NEXT();
	L_ICO_JUMPONE2:
		ring_vm_jumpone2(pVM);
		NEXT();
	L_ICO_PUSHNULLTHENJUMP:
		RING_VM_PUSHNULLTHENJUMP;
		NEXT();
	L_ICO_PUSHNTHENJUMP:
		RING_VM_PUSHNTHENJUMP;
		NEXT();
	L_ICO_LESSEQUAL:
		ring_vm_lessequal(pVM);
		NEXT();
	L_ICO_EQUAL:
		ring_vm_equal(pVM);
		NEXT();
	L_ICO_LESS:
		ring_vm_less(pVM);
		NEXT();
	L_ICO_GREATER:
		ring_vm_greater(pVM);
		NEXT();
	L_ICO_GREATEREQUAL:
		ring_vm_greaterequal(pVM);
		NEXT();
	L_ICO_NOTEQUAL:
		ring_vm_notequal(pVM);
		NEXT();
	L_ICO_SUM:
		ring_vm_sum(pVM);
		NEXT();
	L_ICO_SUB:
		ring_vm_sub(pVM);
		NEXT();
	L_ICO_MUL:
		ring_vm_mul(pVM);
		NEXT();
	L_ICO_DIV:
		ring_vm_div(pVM);
		NEXT();
	L_ICO_MOD:
		ring_vm_mod(pVM);
		NEXT();
	L_ICO_NEG:
		ring_vm_neg(pVM);
		NEXT();
	L_ICO_PLUSPLUS:
		ring_vm_plusplus(pVM);
		NEXT();
	L_ICO_MINUSMINUS:
		ring_vm_minusminus(pVM);
		NEXT();
	L_ICO_POW:
		ring_vm_pow(pVM);
		NEXT();
	L_ICO_SUMN:
		ring_vm_sumn(pVM);
		NEXT();
	L_ICO_SUBN:
		ring_vm_subn(pVM);
		NEXT();
	L_ICO_MULN:
		ring_vm_muln(pVM);
		NEXT();
	L_ICO_DIVN:
		ring_vm_divn(pVM);
		NEXT();
	L_ICO_MODN:
		ring_vm_modn(pVM);
		NEXT();
	L_ICO_POWN:
		ring_vm_pown(pVM);
		NEXT();
	L_ICO_AND:
		ring_vm_and(pVM);
		NEXT();
	L_ICO_OR:
		ring_vm_or(pVM);
		NEXT();
	L_ICO_NOT:
		ring_vm_not(pVM);
		NEXT();
	L_ICO_LISTSTART:
		ring_vm_liststart(pVM);
		NEXT();
	L_ICO_LISTITEM:
		ring_vm_listitem(pVM);
		NEXT();
	L_ICO_LISTITEMN:
		ring_vm_listitemn(pVM);
		NEXT();
	L_ICO_LISTITEMC:
		ring_vm_listitemc(pVM);
		NEXT();
	L_ICO_LISTEND:
		ring_vm_listend(pVM);
		NEXT();
	L_ICO_LOADINDEXADDRESS:
		ring_vm_loadindexaddress(pVM);
		NEXT();
	L_ICO_LOADFUNC:
		ring_vm_loadfunc(pVM);
		NEXT();
	L_ICO_CALL:
		ring_vm_call(pVM);
		NEXT();
	L_ICO_RETURN:
		ring_vm_return(pVM);
		NEXT();
	L_ICO_RETURNN:
		ring_vm_returnn(pVM);
		NEXT();
	L_ICO_RETNULL:
		ring_vm_returnnull(pVM);
		NEXT();
	L_ICO_RETFROMEVAL:
		ring_vm_returneval(pVM);
		NEXT();
	L_ICO_RETITEMREF:
		ring_vm_retitemref(pVM);
		NEXT();
	L_ICO_NEWFUNC:
		ring_vm_newfunc(pVM);
		NEXT();
	L_ICO_BLOCKFLAG:
		ring_vm_blockflag(pVM);
		NEXT();
	L_ICO_ANONYMOUS:
		ring_vm_anonymous(pVM);
		NEXT();
	L_ICO_BYE:
		ring_vm_bye(pVM);
		NEXT();
	L_ICO_EXITMARK:
		ring_vm_exitmark(pVM);
		NEXT();
	L_ICO_POPEXITMARK:
		ring_vm_popexitmark(pVM);
		NEXT();
	L_ICO_EXIT:
		ring_vm_exit(pVM, RING_COMMANDTYPE_EXIT);
		NEXT();
	L_ICO_LOOP:
		ring_vm_exit(pVM, RING_COMMANDTYPE_LOOP);
		NEXT();
	L_ICO_PUSHP:
		ring_vm_pushp(pVM);
		NEXT();
	L_ICO_INCP:
		ring_vm_incp(pVM);
		NEXT();
	L_ICO_PUSHPV:
		ring_vm_pushpv(pVM);
		NEXT();
	L_ICO_INCJUMP:
		ring_vm_incjump(pVM);
		NEXT();
	L_ICO_INCPJUMP:
		ring_vm_incpjump(pVM);
		NEXT();
	L_ICO_LOADFUNCP:
		ring_vm_loadfuncp(pVM);
		NEXT();
	L_ICO_PUSHPLOCAL:
		ring_vm_pushplocal(pVM);
		NEXT();
	L_ICO_PUSHARG:
		ring_vm_pusharg(pVM);
		NEXT();
	L_ICO_INCLPJUMP:
		ring_vm_inclpjump(pVM);
		NEXT();
	L_ICO_INCPJUMPSTEP1:
		ring_vm_incpjumpstep1(pVM);
		NEXT();
	L_ICO_INCLPJUMPSTEP1:
		ring_vm_inclpjumpstep1(pVM);
		NEXT();
	L_ICO_LEN:
		ring_vm_len(pVM);
		NEXT();
	L_ICO_SETOPCODE:
		ring_vm_setopcode(pVM);
		NEXT();
	L_ICO_CHECKBRACEMETHOD:
		ring_vm_oop_checkbracemethod(pVM);
		NEXT();
	L_ICO_TRY:
		ring_vm_try(pVM);
		NEXT();
	L_ICO_DONE:
		ring_vm_done(pVM);
		NEXT();
	L_ICO_DUPLICATE:
		ring_vm_stackdup(pVM);
		NEXT();
	L_ICO_RANGE:
		ring_vm_range(pVM);
		NEXT();
	L_ICO_NEWOBJ:
		ring_vm_oop_newobj(pVM);
		NEXT();
	L_ICO_SETSCOPE:
		ring_vm_oop_setscope(pVM);
		NEXT();
	L_ICO_LOADSUBADDRESS:
		ring_vm_oop_property(pVM);
		NEXT();
	L_ICO_LOADMETHOD:
		ring_vm_oop_loadmethod(pVM);
		NEXT();
	L_ICO_LOADMETHODP:
		ring_vm_oop_loadmethodp(pVM);
		NEXT();
	L_ICO_LOADBRACEMETHODP:
		ring_vm_oop_loadbracemethodp(pVM);
		NEXT();
	L_ICO_AFTERCALLMETHOD:
		ring_vm_oop_aftercallmethod(pVM);
		NEXT();
	L_ICO_AFTERCALLMETHOD2:
		ring_vm_oop_aftercallmethod(pVM);
		NEXT();
	L_ICO_NEWCLASS:
		ring_vm_oop_newclass(pVM);
		NEXT();
	L_ICO_BRACESTART:
		ring_vm_oop_bracestart(pVM);
		NEXT();
	L_ICO_BRACEEND:
		ring_vm_oop_braceend(pVM);
		NEXT();
	L_ICO_IMPORT:
		ring_vm_oop_import(pVM);
		NEXT();
	L_ICO_PRIVATE:
		pVM->lPrivateFlag = 1;
		NEXT();
	L_ICO_SETPROPERTY:
		ring_vm_oop_setproperty(pVM);
		NEXT();
	L_ICO_CALLCLASSINIT:
		ring_vm_oop_callclassinit(pVM);
		NEXT();
	L_ICO_BITAND:
		ring_vm_bitand(pVM);
		NEXT();
	L_ICO_BITOR:
		ring_vm_bitor(pVM);
		NEXT();
	L_ICO_BITXOR:
		ring_vm_bitxor(pVM);
		NEXT();
	L_ICO_BITNOT:
		ring_vm_bitnot(pVM);
		NEXT();
	L_ICO_BITSHL:
		ring_vm_bitshl(pVM);
		NEXT();
	L_ICO_BITSHR:
		ring_vm_bitshr(pVM);
		NEXT();
	L_ICO_STEPNUMBER:
		ring_vm_stepnumber(pVM);
		NEXT();
	L_ICO_STEPFROMREG:
		ring_vm_stepfromreg(pVM);
		NEXT();
	L_ICO_POPSTEP:
		ring_vm_popstep(pVM);
		NEXT();
	L_ICO_LOADAFIRST:
		ring_vm_loadaddressfirst(pVM);
		NEXT();
	L_ICO_NEWGLOBALSCOPE:
		ring_vm_newglobalscope(pVM);
		NEXT();
	L_ICO_ENDGLOBALSCOPE:
		ring_vm_endglobalscope(pVM);
		NEXT();
	L_ICO_SETGLOBALSCOPE:
		ring_vm_setglobalscope(pVM);
		NEXT();
	L_ICO_FREETEMPLISTS:
		ring_vm_freetemplistsins(pVM);
		NEXT();
	L_ICO_OPTIONALLOOP:
		ring_vm_optionalloop(pVM);
		NEXT();
	L_ICO_SETREFERENCE:
		ring_vm_setreference(pVM);
		NEXT();
	L_ICO_KILLREFERENCE:
		ring_vm_gc_killreference(pVM);
		NEXT();
	L_ICO_ASSIGNMENTPOINTER:
		ring_vm_assignmentpointer(pVM);
		NEXT();
	L_ICO_BEFOREEQUAL:
		pVM->nBeforeEqual = RING_VM_IR_READI;
		NEXT();
	L_default:
		NEXT();
	#undef NEXT
}

#endif
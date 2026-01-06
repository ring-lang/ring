# The Ring Natural Library
# 2017-2026, Mahmoud Fayed <msfclipper@yahoo.com>

NATLIB_TEMPVAR = 0

func NatLibCallerGetVar oObj,cVar

	nScope = oObj.nCallerScope
	oObj.lEnableBraceExprEval = False
	oObj {
		ringvm_evalinscope(nScope, "NATLIB_TEMPVAR = " + cVar)
	}
	oObj.lEnableBraceExprEval = True

	if NATLIB_TEMPVAR = :NLNV { return cVar }

	return NATLIB_TEMPVAR

func NatLibCallerSetVar oObj,cVar,cValue
	NATLIB_TEMPVAR = cValue
	nScope = oObj.nCallerScope
	oObj.lEnableBraceExprEval = False
	oObj {
		ringvm_evalinscope(nScope, cVar + " = NATLIB_TEMPVAR")
	}
	oObj.lEnableBraceExprEval = True

func NatLibExecute obj,cCode
	obj {
		eval(cCode)
	}
	return obj.vCommandOutput

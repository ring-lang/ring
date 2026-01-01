# The Ring Natural Library
# 2017-2026, Mahmoud Fayed <msfclipper@yahoo.com>

NATLIB_TEMPVAR = 0

func GetVariableValueFromCallerScope oObj,nScope,cCode

	oObj.lEnableBraceExprEval = False
	oObj {
		ringvm_evalinscope(nScope, "NATLIB_TEMPVAR = " + cCode)
	}
	oObj.lEnableBraceExprEval = True

	if NATLIB_TEMPVAR = :NLNV { return cCode }

	return NATLIB_TEMPVAR

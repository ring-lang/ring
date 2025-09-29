/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

Scanner *ring_scanner_new(RingState *pRingState) {
	Scanner *pScanner;
	pScanner = (Scanner *)ring_state_malloc(pRingState, sizeof(Scanner));
	pScanner->pRingState = pRingState;
	pScanner->cState = SCANNER_STATE_GENERAL;
	pScanner->pActiveToken = ring_string_new_gc(pRingState, RING_CSTR_EMPTY);
	pScanner->pTokens = ring_list_new_gc(pRingState, RING_ZERO);
	pScanner->nLinesCount = RING_ONE;
	pScanner->nFloatMark = SCANNER_FLOATMARK_START;
	pScanner->nMLComment = RING_ZERO;
	pScanner->nTokenIndex = RING_ZERO;
	pScanner->lHashComments = RING_TRUE;
	pScanner->lMultiCharOperators = RING_FALSE;
	pScanner->lEnableTokensOutput = RING_TRUE;
	ring_scanner_keywords(pScanner);
	ring_scanner_operators(pScanner);
	return pScanner;
}

Scanner *ring_scanner_delete(Scanner *pScanner) {
	pScanner->pKeywords = ring_list_delete_gc(pScanner->pRingState, pScanner->pKeywords);
	pScanner->pOperators = ring_list_delete_gc(pScanner->pRingState, pScanner->pOperators);
	pScanner->pTokens = ring_list_delete_gc(pScanner->pRingState, pScanner->pTokens);
	pScanner->pActiveToken = ring_string_delete_gc(pScanner->pRingState, pScanner->pActiveToken);
	ring_state_free(pScanner->pRingState, pScanner);
	return NULL;
}

void ring_scanner_readchar(Scanner *pScanner, char c) {
	char cStr[RING_CHARBUF];
	List *pList;
	String *pString;
	int nTokenIndex;
	/* Set Variables */
	cStr[0] = c;
	cStr[1] = '\0';
	switch (pScanner->cState) {
	case SCANNER_STATE_GENERAL:
		/* Check Unicode File */
		if (ring_list_getsize(pScanner->pTokens) == 0) {
			/* UTF8 */
			if (strcmp(ring_string_get(pScanner->pActiveToken), "\xEF\xBB\xBF") == 0) {
				ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
				/* Don't use reading so the new character can be scanned */
			}
		}
		/* Check Space/Tab/New Line */
		if (c != ' ' && c != '\n' && c != ';' && c != '\t' && c != '\"' && c != '\'' && c != '\r' && c != '`') {
			if (ring_scanner_isoperator(pScanner, cStr)) {
				nTokenIndex = pScanner->nTokenIndex;
				ring_scanner_checktoken(pScanner);
				ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
				/* Check Operator Then Operator */
				if (pScanner->lMultiCharOperators &&
				    (ring_scanner_lasttokentype(pScanner) == SCANNER_TOKEN_OPERATOR)) {
					/* Check Multiline Comment */
					if (strcmp(cStr, "*") == 0) {
						pList = ring_list_getlist(pScanner->pTokens,
									  ring_list_getsize(pScanner->pTokens));
						if (strcmp(ring_list_getstring(pList, RING_SCANNER_TOKENVALUE), "/") ==
						    0) {
							ring_list_deleteitem_gc(pScanner->pRingState, pScanner->pTokens,
										ring_list_getsize(pScanner->pTokens));
							pScanner->cState = SCANNER_STATE_MLCOMMENT;
							ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken,
									   "/*");
							return;
						}
					}
					/* Check comment using // */
					if (strcmp(cStr, "/") == 0) {
						if (strcmp("/", ring_scanner_lasttokenvalue(pScanner)) == 0) {
							RING_SCANNER_DELETELASTTOKEN;
							pScanner->cState = SCANNER_STATE_COMMENT;
							ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken,
									   "//");
							return;
						}
					}
					/* Check Multi-character Operators */
					nTokenIndex = ring_scanner_checkmulticharoperator(pScanner, cStr, nTokenIndex);
				}
				pScanner->nTokenIndex = nTokenIndex;
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_OPERATOR);
				pScanner->lMultiCharOperators = RING_TRUE;
			} else {
				ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
				pScanner->lMultiCharOperators = RING_FALSE;
			}
		} else {
			if (ring_scanner_isoperator(pScanner, ring_string_get(pScanner->pActiveToken))) {
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_OPERATOR);
				pScanner->lMultiCharOperators = RING_TRUE;
			} else {
				ring_scanner_checktoken(pScanner);
				pScanner->lMultiCharOperators = RING_FALSE;
			}
		}
		/* Switch State */
		if (c == '"') {
			pScanner->cState = SCANNER_STATE_LITERAL;
			pScanner->cLiteral = '"';
			pScanner->nLiteralLine = pScanner->nLinesCount;
		} else if (c == '\'') {
			pScanner->cState = SCANNER_STATE_LITERAL;
			pScanner->cLiteral = '\'';
			pScanner->nLiteralLine = pScanner->nLinesCount;
		} else if (c == '`') {
			pScanner->cState = SCANNER_STATE_LITERAL;
			pScanner->cLiteral = '`';
			pScanner->nLiteralLine = pScanner->nLinesCount;
		} else if ((c == '#') && pScanner->lHashComments) {
			pScanner->cState = SCANNER_STATE_COMMENT;
		}
		break;
	case SCANNER_STATE_LITERAL:
		/* Switch State */
		if (c == pScanner->cLiteral) {
			pScanner->cState = SCANNER_STATE_GENERAL;
			ring_scanner_addtoken(pScanner, SCANNER_TOKEN_LITERAL);
		} else {
			ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
		}
		break;
	case SCANNER_STATE_COMMENT:
		/* Switch State */
		if (c == '\n') {
			pScanner->cState = SCANNER_STATE_GENERAL;
			if (pScanner->pRingState->lCommentsAsTokens) {
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_COMMENT);
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
		} else {
			if (pScanner->pRingState->lCommentsAsTokens) {
				ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
			}
		}
		break;
	case SCANNER_STATE_MLCOMMENT:
		/* Check Multiline Comment */
		if (pScanner->pRingState->lCommentsAsTokens) {
			ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
		}
		switch (pScanner->nMLComment) {
		case 0:
			if (strcmp(cStr, "*") == 0) {
				pScanner->nMLComment = 1;
				return;
			}
			break;
		case 1:
			if (strcmp(cStr, "/") == 0) {
				pScanner->cState = SCANNER_STATE_GENERAL;
				if (pScanner->pRingState->lCommentsAsTokens) {
					ring_scanner_addtoken(pScanner, SCANNER_TOKEN_COMMENT);
				}
				/* The next step is important to avoid storing * as identifier! */
				ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			}
			if (strcmp(cStr, "*") != 0) {
				/* We can repeat stars */
				pScanner->nMLComment = 0;
			}
			return;
		}
		break;
	case SCANNER_STATE_CHANGEKEYWORD:
		/* Switch State */
		if (c == '\n') {
			pScanner->cState = SCANNER_STATE_GENERAL;
			ring_scanner_changekeyword(pScanner);
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
		} else if (c == '#' || ring_scanner_isoperator(pScanner, cStr)) {
			pScanner->cState = SCANNER_STATE_GENERAL;
			ring_scanner_changekeyword(pScanner);
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			/* Read the character again (Don't ignore the operator) */
			ring_scanner_readchar(pScanner, c);
		} else if ((c == ' ') || (c == '\t')) {
			ring_scanner_readtwoparameters(pScanner, cStr);
		} else {
			ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
		}
		break;
	case SCANNER_STATE_CHANGEOPERATOR:
		/* Switch State */
		if (c == '\n') {
			pScanner->cState = SCANNER_STATE_GENERAL;
			ring_scanner_changeoperator(pScanner);
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
		} else if ((c == ' ') || (c == '\t')) {
			ring_scanner_readtwoparameters(pScanner, cStr);
		} else {
			ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
		}
		break;
	case SCANNER_STATE_LOADSYNTAX:
		/* Switch State */
		if (c == '\n') {
			pScanner->cState = SCANNER_STATE_GENERAL;
			ring_scanner_loadsyntax(pScanner);
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
		} else {
			ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
		}
		break;
	}
	if (c == '\n') {
		pScanner->nLinesCount++;
	}
	if ((c == ';' || c == '\n') && (pScanner->cState == SCANNER_STATE_GENERAL)) {
		if ((ring_scanner_lasttokentype(pScanner) != SCANNER_TOKEN_ENDLINE)) {
			ring_string_setfromint_gc(pScanner->pRingState, pScanner->pActiveToken, pScanner->nLinesCount);
			ring_scanner_addtoken(pScanner, SCANNER_TOKEN_ENDLINE);
		} else {
			pList = ring_list_getlist(pScanner->pTokens, ring_list_getsize(pScanner->pTokens));
			pString = ring_string_new_gc(pScanner->pRingState, RING_CSTR_EMPTY);
			ring_string_setfromint_gc(pScanner->pRingState, pString, pScanner->nLinesCount);
			ring_list_setstring_gc(pScanner->pRingState, pList, RING_SCANNER_TOKENVALUE,
					       ring_string_get(pString));
			ring_string_delete_gc(pScanner->pRingState, pString);
		}
	}
}

void ring_scanner_keywords(Scanner *pScanner) {
	char cKeyword[RING_SMALLBUF];
	unsigned int x;
	pScanner->pKeywords = ring_list_new_gc(pScanner->pRingState, RING_ZERO);
	for (x = 0; x < RING_SCANNER_KEYWORDSCOUNT; x++) {
		sprintf(cKeyword, "%s", RING_KEYWORDS[x]);
		ring_general_lower(cKeyword);
		ring_list_addstring_gc(pScanner->pRingState, pScanner->pKeywords, cKeyword);
	}
	ring_list_genhashtable_gc(pScanner->pRingState, pScanner->pKeywords);
}

void ring_scanner_addtoken(Scanner *pScanner, unsigned int nType) {
	List *pList;
	if (!pScanner->lEnableTokensOutput) {
		ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
		return;
	}
	pList = ring_list_newlist_gc(pScanner->pRingState, pScanner->pTokens);
	/* Add Token Type */
	ring_list_addint_gc(pScanner->pRingState, pList, nType);
	/* Add Token Text */
	ring_list_addstring_gc(pScanner->pRingState, pList, ring_scanner_processtoken(pScanner, nType));
	/* Add Token Index */
	ring_list_addint_gc(pScanner->pRingState, pList, pScanner->nTokenIndex);
	pScanner->nTokenIndex = 0;
	ring_scanner_floatmark(pScanner, nType);
	ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
}

void ring_scanner_checktoken(Scanner *pScanner) {
	unsigned int nResult;
	char cStr[RING_SMALLBUF];
	char *cActiveStr;
	List *pList;
	/*
	**  This function determine if the TOKEN is a Keyword or Identifier or Number
	**  Not Case Sensitive
	*/
	if (pScanner->pRingState->lNotCaseSensitive) {
		ring_string_tolower(pScanner->pActiveToken);
		cActiveStr = ring_string_get(pScanner->pActiveToken);
		nResult = ring_hashtable_findnumber_gc(pScanner->pRingState,
						       ring_list_gethashtable(pScanner->pKeywords), cActiveStr);
	} else {
		cActiveStr = ring_string_strdup_gc(pScanner->pRingState, ring_string_get(pScanner->pActiveToken));
		cActiveStr = ring_general_lower(cActiveStr);
		nResult = ring_hashtable_findnumber_gc(pScanner->pRingState,
						       ring_list_gethashtable(pScanner->pKeywords), cActiveStr);
		ring_state_free(pScanner->pRingState, cActiveStr);
	}
	if (nResult > 0) {
		if (nResult < RING_SCANNER_CHANGERINGKEYWORD) {
			sprintf(cStr, "%d", nResult);
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
			ring_scanner_addtoken(pScanner, SCANNER_TOKEN_KEYWORD);
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				pList = ring_list_getlist(pScanner->pTokens, ring_list_getsize(pScanner->pTokens));
				ring_list_addstring_gc(pScanner->pRingState, pList,
						       ring_list_getstring(pScanner->pKeywords, nResult));
			}
		} else if (nResult == RING_SCANNER_CHANGERINGKEYWORD) {
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, "ChangeRingKeyword");
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			pScanner->cState = SCANNER_STATE_CHANGEKEYWORD;
		} else if (nResult == RING_SCANNER_CHANGERINGOPERATOR) {
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, "ChangeRingOperator");
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			pScanner->cState = SCANNER_STATE_CHANGEOPERATOR;
		} else if (nResult == RING_SCANNER_LOADSYNTAX) {
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, "LoadSyntax");
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			pScanner->cState = SCANNER_STATE_LOADSYNTAX;
		} else if (nResult == RING_SCANNER_ENABLEHASHCOMMENTS) {
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, "EnableHashComments");
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			pScanner->lHashComments = 1;
		} else if (nResult == RING_SCANNER_DISABLEHASHCOMMENTS) {
			if (pScanner->pRingState->lScannerCommandsAsTokens) {
				ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, "DisableHashComments");
			}
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
			pScanner->lHashComments = 0;
		}
	} else {
		/* Add Identifier */
		if (strcmp(ring_string_get(pScanner->pActiveToken), RING_CSTR_EMPTY) != 0) {
			if (ring_scanner_isnumber(pScanner->pActiveToken) == 0) {
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_IDENTIFIER);
			} else {
				ring_scanner_processnumber(pScanner->pActiveToken);
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_NUMBER);
			}
		}
	}
}

unsigned int ring_scanner_isnumber(String *pStr) {
	unsigned int x, x2, lHex;
	char *cStr;
	unsigned int nLen;
	lHex = RING_FALSE;
	cStr = ring_string_get(pStr);
	nLen = ring_string_size(pStr);
	for (x = 0; x < nLen; x++) {
		/* Accept Hexadecimal values */
		if ((x == 0) && (nLen > 2)) {
			if (cStr[0] == '0') {
				x2 = x;
				/* Support Many Zeros */
				while ((cStr[x2] == '0') && x2 < nLen - 1) {
					x2++;
				}
				/* Support 0x */
				if ((cStr[x2] == 'x') || (cStr[x2] == 'X')) {
					lHex = RING_TRUE;
					x = x2 + 1;
					continue;
				}
			}
		}
		if (lHex) {
			/* Support A-F & a-f */
			if ((cStr[x] >= 97 && cStr[x] <= 102) || (cStr[x] >= 65 && cStr[x] <= 70)) {
				continue;
			}
		}
		/* Accept _ in the number */
		if ((cStr[x] == '_') && (x > 0) && (x < nLen - 1)) {
			continue;
		}
		/* Accept f in the end of the number */
		if ((x > 0) && (x == nLen - 1) && ((cStr[x] == 'f') || (cStr[x] == 'F'))) {
			return RING_TRUE;
		}
		if ((cStr[x] < 48 || cStr[x] > 57)) {
			return RING_FALSE;
		}
	}
	return RING_TRUE;
}

void ring_scanner_processnumber(String *pTokenString) {
	unsigned int nLen, nWriteIndex, nReadIndex, lHex, lHexDetection, lLeadingZeros;
	char *cStr;
	char c;
	cStr = ring_string_get(pTokenString);
	nLen = ring_string_size(pTokenString);
	nWriteIndex = RING_ZERO;
	nReadIndex = RING_ZERO;
	lHex = RING_FALSE;
	lHexDetection = RING_TRUE;
	lLeadingZeros = RING_TRUE;
	while (nReadIndex < nLen) {
		c = cStr[nReadIndex++];
		if (c == '_') {
			continue;
		}
		if (lHexDetection) {
			if (c == '0') {
				/* Stay in llHexDetection state */
			} else if ((c == 'x' || c == 'X') && lLeadingZeros) {
				lHex = RING_TRUE;
			} else {
				lHexDetection = RING_FALSE;
				lLeadingZeros = RING_FALSE;
			}
		}
		if (!lHex && ((c == 'f' || c == 'F') && (nReadIndex == nLen))) {
			continue;
		}
		cStr[nWriteIndex++] = c;
	}
	cStr[nWriteIndex] = '\0';
}

unsigned int ring_scanner_checklasttoken(Scanner *pScanner) {
	if (ring_list_getsize(pScanner->pTokens) == 0) {
		if (pScanner->cState == SCANNER_STATE_COMMENT) {
			if (pScanner->pRingState->lCommentsAsTokens) {
				ring_scanner_addtoken(pScanner, SCANNER_TOKEN_COMMENT);
			}
			return RING_TRUE;
		}
	}
	if (pScanner->cState == SCANNER_STATE_LITERAL) {
		if (pScanner->pRingState->lOnlyTokens) {
			pScanner->pRingState->nScannerError = 1;
			return RING_FALSE;
		}
		ring_state_cgiheader(pScanner->pRingState);
		printf("Error (S1) In file: %s \n",
		       ring_list_getstring(pScanner->pRingState->pRingFilesList,
					   ring_list_getsize(pScanner->pRingState->pRingFilesList)));
		printf("In Line (%d) Literal not closed \n", pScanner->nLiteralLine);
		if (ring_list_getsize(pScanner->pRingState->pRingFilesList) > 1) {
			printf("Called from other source code file");
		}
		return RING_FALSE;
	} else if (pScanner->cState == SCANNER_STATE_GENERAL) {
		ring_scanner_checktoken(pScanner);
	} else if ((pScanner->cState == SCANNER_STATE_COMMENT) || (pScanner->cState == SCANNER_STATE_MLCOMMENT)) {
		if (pScanner->pRingState->lCommentsAsTokens) {
			ring_scanner_addtoken(pScanner, SCANNER_TOKEN_COMMENT);
		}
	} else if (pScanner->cState == SCANNER_STATE_LOADSYNTAX) {
		pScanner->cState = SCANNER_STATE_GENERAL;
		ring_scanner_loadsyntax(pScanner);
		ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
	}
	return RING_TRUE;
}

unsigned int ring_scanner_isoperator(Scanner *pScanner, const char *cStr) {
	unsigned int nPos;
	nPos = ring_hashtable_findnumber_gc(pScanner->pRingState, ring_list_gethashtable(pScanner->pOperators), cStr);
	if (nPos > 0) {
		pScanner->nTokenIndex = nPos;
		return RING_TRUE;
	}
	return RING_FALSE;
}

void ring_scanner_operators(Scanner *pScanner) {
	unsigned int x;
	pScanner->pOperators = ring_list_new_gc(pScanner->pRingState, RING_ZERO);
	for (x = 0; x < RING_SCANNER_OPERATORSCOUNT; x++) {
		ring_list_addstring_gc(pScanner->pRingState, pScanner->pOperators, RING_OPERATORS[x]);
	}
	ring_list_genhashtable_gc(pScanner->pRingState, pScanner->pOperators);
}

unsigned int ring_scanner_lasttokentype(Scanner *pScanner) {
	unsigned int x;
	List *pList;
	x = ring_list_getsize(pScanner->pTokens);
	if (x > 0) {
		pList = ring_list_getlist(pScanner->pTokens, x);
		return ring_list_getint(pList, RING_SCANNER_TOKENTYPE);
	}
	return SCANNER_TOKEN_NOTOKEN;
}

const char *ring_scanner_lasttokenvalue(Scanner *pScanner) {
	unsigned int x;
	List *pList;
	x = ring_list_getsize(pScanner->pTokens);
	if (x > 0) {
		pList = ring_list_getlist(pScanner->pTokens, x);
		return (const char *)ring_list_getstring(pList, RING_SCANNER_TOKENVALUE);
	}
	return RING_CSTR_EMPTY;
}

void ring_scanner_floatmark(Scanner *pScanner, unsigned int nType) {
	List *pList;
	String *pString;
	switch (pScanner->nFloatMark) {
	case SCANNER_FLOATMARK_START:
		if (nType == SCANNER_TOKEN_NUMBER) {
			pScanner->nFloatMark = SCANNER_FLOATMARK_NUMBER;
		}
		break;
	case SCANNER_FLOATMARK_NUMBER:
		if ((nType == SCANNER_TOKEN_OPERATOR) && (strcmp(ring_string_get(pScanner->pActiveToken), ".") == 0)) {
			pScanner->nFloatMark = SCANNER_FLOATMARK_NUMBERDOT;
		} else {
			pScanner->nFloatMark = SCANNER_FLOATMARK_START;
		}
		break;
	case SCANNER_FLOATMARK_NUMBERDOT:
		if (nType == SCANNER_TOKEN_NUMBER) {
			pList = ring_list_getlist(pScanner->pTokens, ring_list_getsize(pScanner->pTokens));
			pString = ring_string_new_gc(pScanner->pRingState,
						     ring_list_getstring(pList, RING_SCANNER_TOKENVALUE));
			ring_list_deleteitem_gc(pScanner->pRingState, pScanner->pTokens,
						ring_list_getsize(pScanner->pTokens));
			ring_list_deleteitem_gc(pScanner->pRingState, pScanner->pTokens,
						ring_list_getsize(pScanner->pTokens));
			pList = ring_list_getlist(pScanner->pTokens, ring_list_getsize(pScanner->pTokens));
			ring_string_add_gc(pScanner->pRingState,
					   ring_item_getstring(ring_list_getitem_gc(pScanner->pRingState, pList,
										    RING_SCANNER_TOKENVALUE)),
					   ".");
			ring_string_add_gc(pScanner->pRingState,
					   ring_item_getstring(ring_list_getitem_gc(pScanner->pRingState, pList,
										    RING_SCANNER_TOKENVALUE)),
					   ring_string_get(pString));
			ring_string_delete_gc(pScanner->pRingState, pString);
		}
		pScanner->nFloatMark = SCANNER_FLOATMARK_START;
		break;
	}
}

void ring_scanner_endofline(Scanner *pScanner) {
	/* Add Token "End of Line" to the end of any program */
	if (ring_scanner_lasttokentype(pScanner) != SCANNER_TOKEN_ENDLINE) {
		ring_string_setfromint_gc(pScanner->pRingState, pScanner->pActiveToken, pScanner->nLinesCount);
		ring_scanner_addtoken(pScanner, SCANNER_TOKEN_ENDLINE);
	}
}

void ring_scanner_printtokens(Scanner *pScanner) {
	unsigned int x, nType, nPos;
	List *pList;
	char *cString;
	ring_general_printline();
	puts("Tokens - Generated by the Scanner");
	ring_general_printline();
	printf("\n");
	for (x = 1; x <= ring_list_getsize(pScanner->pTokens); x++) {
		pList = ring_list_getlist(pScanner->pTokens, x);
		nType = ring_list_getint(pList, RING_SCANNER_TOKENTYPE);
		cString = ring_list_getstring(pList, RING_SCANNER_TOKENVALUE);
		switch (nType) {
		case SCANNER_TOKEN_KEYWORD:
			nPos = atoi(cString);
			printf("%10s : %s \n", "Keyword", RING_KEYWORDS[nPos - 1]);
			break;
		case SCANNER_TOKEN_OPERATOR:
			printf("%10s : %s \n", "Operator", cString);
			break;
		case SCANNER_TOKEN_NUMBER:
			printf("%10s : %s \n", "Number", cString);
			break;
		case SCANNER_TOKEN_IDENTIFIER:
			printf("%10s : %s \n", "Identifier", cString);
			break;
		case SCANNER_TOKEN_LITERAL:
			printf("%10s : %s \n", "Literal", cString);
			break;
		case SCANNER_TOKEN_ENDLINE:
			printf("%10s\n", "EndLine");
			break;
		}
	}
	printf("\n");
	ring_general_printline();
}

void ring_scanner_changekeyword(Scanner *pScanner) {
	char *cStr;
	unsigned int x, nResult;
	String *word1, *word2, *activeword;
	char cStr2[RING_CHARBUF];
	cStr2[1] = '\0';
	/* Create Strings */
	word1 = ring_string_new_gc(pScanner->pRingState, RING_CSTR_EMPTY);
	word2 = ring_string_new_gc(pScanner->pRingState, RING_CSTR_EMPTY);
	cStr = ring_string_get(pScanner->pActiveToken);
	activeword = word1;
	for (x = 0; x < ring_string_size(pScanner->pActiveToken); x++) {
		if ((cStr[x] == ' ') || (cStr[x] == '\t') || (cStr[x] == '\r')) {
			if ((activeword == word1) && (ring_string_size(activeword) >= 1)) {
				activeword = word2;
			}
		} else {
			cStr2[0] = cStr[x];
			ring_string_add_gc(pScanner->pRingState, activeword, cStr2);
		}
	}
	/* To Lower Case */
	ring_general_lower(ring_string_get(word1));
	ring_general_lower(ring_string_get(word2));
	if (pScanner->pRingState->lScannerCommandsAsTokens) {
		ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, ring_string_get(word1));
		ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, ring_string_get(word2));
	}
	/* Change Keyword */
	if ((strcmp(ring_string_get(word1), RING_CSTR_EMPTY) == 0) ||
	    (strcmp(ring_string_get(word2), RING_CSTR_EMPTY) == 0)) {
		puts(RING_WARNING_CHANGEKEYWORDPARA);
	} else {
		nResult = ring_hashtable_findnumber_gc(
		    pScanner->pRingState, ring_list_gethashtable(pScanner->pKeywords), ring_string_get(word1));
		if (nResult > 0) {
			ring_list_setstring_gc(pScanner->pRingState, pScanner->pKeywords, nResult,
					       ring_string_get(word2));
			ring_list_genhashtable_gc(pScanner->pRingState, pScanner->pKeywords);
		} else {
			puts(RING_WARNING_KEYWORDNOTFOUND);
			printf("Keyword :  %s\n", ring_string_get(word1));
		}
	}
	/* Delete Strings */
	ring_string_delete_gc(pScanner->pRingState, word1);
	ring_string_delete_gc(pScanner->pRingState, word2);
}

void ring_scanner_changeoperator(Scanner *pScanner) {
	char *cStr;
	unsigned int x, nResult;
	String *word1, *word2, *activeword;
	char cStr2[RING_CHARBUF];
	cStr2[1] = '\0';
	/* Create Strings */
	word1 = ring_string_new_gc(pScanner->pRingState, RING_CSTR_EMPTY);
	word2 = ring_string_new_gc(pScanner->pRingState, RING_CSTR_EMPTY);
	cStr = ring_string_get(pScanner->pActiveToken);
	activeword = word1;
	for (x = 0; x < ring_string_size(pScanner->pActiveToken); x++) {
		if ((cStr[x] == ' ') || (cStr[x] == '\t') || (cStr[x] == '\r')) {
			if ((activeword == word1) && (ring_string_size(activeword) >= 1)) {
				activeword = word2;
			}
		} else {
			cStr2[0] = cStr[x];
			ring_string_add_gc(pScanner->pRingState, activeword, cStr2);
		}
	}
	/* To Lower Case */
	ring_general_lower(ring_string_get(word1));
	ring_general_lower(ring_string_get(word2));
	if (pScanner->pRingState->lScannerCommandsAsTokens) {
		ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, ring_string_get(word1));
		ring_scanner_registertoken(pScanner, SCANNER_TOKEN_IDENTIFIER, ring_string_get(word2));
	}
	/* Change Operator */
	if ((strcmp(ring_string_get(word1), RING_CSTR_EMPTY) == 0) ||
	    (strcmp(ring_string_get(word2), RING_CSTR_EMPTY) == 0)) {
		puts(RING_WARNING_CHANGEOPERATORPARA);
	} else {
		nResult = ring_hashtable_findnumber_gc(
		    pScanner->pRingState, ring_list_gethashtable(pScanner->pOperators), ring_string_get(word1));
		if (nResult > 0) {
			ring_list_setstring_gc(pScanner->pRingState, pScanner->pOperators, nResult,
					       ring_string_get(word2));
			ring_list_genhashtable_gc(pScanner->pRingState, pScanner->pOperators);
		} else {
			puts(RING_WARNING_OPERATORNOTFOUND);
			printf("Operator :  %s\n", ring_string_get(word1));
		}
	}
	/* Delete Strings */
	ring_string_delete_gc(pScanner->pRingState, word1);
	ring_string_delete_gc(pScanner->pRingState, word2);
}

void ring_scanner_loadsyntax(Scanner *pScanner) {
	char *cFileName;
	RING_FILE fp;
	/* Must be signed char to work fine on Android, because it uses -1 as NULL instead of Zero */
	signed char c;
	unsigned int x, nSize, nLine, lEnableTokensOutput;
	char cFileName2[RING_PATHSIZE];
	lEnableTokensOutput = pScanner->lEnableTokensOutput;
	cFileName = ring_string_get(pScanner->pActiveToken);
	/* Remove Spaces and " " from file name */
	x = 0;
	while (((cFileName[x] == ' ') || (cFileName[x] == '"') || (cFileName[x] == '\r')) && (x <= strlen(cFileName))) {
		cFileName++;
	}
	x = strlen(cFileName);
	while (((cFileName[x - 1] == ' ') || (cFileName[x - 1] == '"') || (cFileName[x - 1] == '\r')) && (x >= 1)) {
		cFileName[x - 1] = '\0';
		x--;
	}
	if (pScanner->pRingState->lScannerCommandsAsTokens) {
		ring_scanner_registertoken(pScanner, SCANNER_TOKEN_LITERAL, cFileName);
		pScanner->lEnableTokensOutput = RING_FALSE;
	}
	/* Support File Location in Ring/bin Folder */
	strcpy(cFileName2, cFileName);
	if (ring_general_fexists(cFileName) == 0) {
		ring_general_exefolder(cFileName2);
		strcat(cFileName2, cFileName);
		if (ring_general_fexists(cFileName2) == 0) {
			/* Support ring/bin/load folder */
			ring_general_exefolder(cFileName2);
			strcat(cFileName2, "load/");
			strcat(cFileName2, cFileName);
			if (ring_general_fexists(cFileName2) == 0) {
				strcpy(cFileName, cFileName2);
			}
		}
	}
	if (ring_general_fexists(cFileName2) == 0) {
		printf("\nFile: %s doesn't exist!\n", cFileName);
		return;
	}
	fp = RING_OPENFILE(cFileName2, "r");
	if (fp == NULL) {
		printf("\n%s %s \n", RING_CANTOPENFILE, cFileName);
		return;
	}
	nSize = 1;
	ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, RING_CSTR_EMPTY);
	nLine = pScanner->nLinesCount;
	/* Set the Line Number (To be 1) */
	ring_scanner_setandgenendofline(pScanner, RING_ONE);
	RING_READCHAR(fp, c, nSize);
	while ((c != EOF) && (nSize != 0)) {
		ring_scanner_readchar(pScanner, c);
		RING_READCHAR(fp, c, nSize);
	}
	RING_CLOSEFILE(fp);
	ring_scanner_readchar(pScanner, '\n');
	/* Restore the Line Number (After loading the file) */
	ring_scanner_setandgenendofline(pScanner, nLine);
	pScanner->lEnableTokensOutput = lEnableTokensOutput;
}

void ring_scanner_setandgenendofline(Scanner *pScanner, unsigned int nLine) {
	pScanner->nLinesCount = nLine;
	ring_string_setfromint_gc(pScanner->pRingState, pScanner->pActiveToken, pScanner->nLinesCount);
	ring_scanner_addtoken(pScanner, SCANNER_TOKEN_ENDLINE);
}

void ring_scanner_readtwoparameters(Scanner *pScanner, const char *cStr) {
	unsigned int x, nSize, nSpaces;
	char *cString;
	cString = ring_string_get(pScanner->pActiveToken);
	nSize = strlen(cString);
	if (nSize > 0) {
		if ((cString[nSize - 1] != ' ') && (cString[nSize - 1] != '\t')) {
			nSpaces = 0;
			for (x = 0; x < nSize; x++) {
				if ((cString[x] == ' ') || (cString[x] == '\t')) {
					nSpaces++;
				}
			}
			if (nSpaces == 0) {
				ring_string_add_gc(pScanner->pRingState, pScanner->pActiveToken, cStr);
			} else {
				/* Consider it the end of the instruction */
				if (pScanner->cState == SCANNER_STATE_CHANGEKEYWORD) {
					pScanner->cState = SCANNER_STATE_GENERAL;
					ring_scanner_changekeyword(pScanner);
					ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken,
							   RING_CSTR_EMPTY);
				} else if (pScanner->cState == SCANNER_STATE_CHANGEOPERATOR) {
					pScanner->cState = SCANNER_STATE_GENERAL;
					ring_scanner_changeoperator(pScanner);
					ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken,
							   RING_CSTR_EMPTY);
				}
			}
		}
	}
}

const char *ring_scanner_processtoken(Scanner *pScanner, unsigned int nType) {
	char *pStart, *pChar;
	unsigned int t, nPos, nSize, lXExist;
	pStart = ring_string_get(pScanner->pActiveToken);
	if (nType == SCANNER_TOKEN_NUMBER) {
		/* Remove Many Zeros in the Start */
		pChar = pStart;
		nSize = strlen(pChar);
		nPos = 0;
		if (nSize > 0) {
			if (pChar[0] == '0') {
				lXExist = 0;
				for (t = 1; t < nSize; t++) {
					if ((pChar[t - 1] == '0') && (pChar[t] == '0')) {
						nPos++;
					}
					if ((pChar[t] == 'x') || (pChar[t] == 'X')) {
						lXExist = 1;
						break;
					}
				}
				if (lXExist) {
					pStart += nPos;
				}
			}
		}
	}
	return pStart;
}

unsigned int ring_scanner_checkmulticharoperator(Scanner *pScanner, const char *cStr, unsigned int nTokenIndex) {
	unsigned int x, lOperatorFound;
	const char *cLastToken;
	/* Check Multi-character operators */
	lOperatorFound = 0;
	cLastToken = ring_scanner_lasttokenvalue(pScanner);
	for (x = 0; OP_MULTI[x].cOperator != NULL; x++) {
		if ((strcmp(cStr, OP_MULTI[x].cOperator) == 0) && (strcmp(cLastToken, OP_MULTI[x].cOperator) == 0)) {
			RING_SCANNER_DELETELASTTOKEN;
			ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken, OP_MULTI[x].cSecond);
			nTokenIndex = OP_MULTI[x].nToken;
			lOperatorFound = 1;
			break;
		}
	}
	/* Check Operator then Equal */
	if (!lOperatorFound && (strcmp(cStr, "=") == 0)) {
		cLastToken = ring_scanner_lasttokenvalue(pScanner);
		for (x = 0; OP_COMPOUND[x].cOperator != NULL; x++) {
			if (strcmp(cLastToken, OP_COMPOUND[x].cOperator) == 0) {
				RING_SCANNER_DELETELASTTOKEN;
				ring_string_set_gc(pScanner->pRingState, pScanner->pActiveToken,
						   OP_COMPOUND[x].cSecond);
				nTokenIndex = OP_COMPOUND[x].nToken;
				break;
			}
		}
	}
	return nTokenIndex;
}

const char *ring_scanner_getkeywordtext(RingState *pRingState, const char *cStr) {
	return RING_KEYWORDS[atoi(cStr) - 1];
}

const char *ring_scanner_getmulticharoperatortext(RingState *pRingState, unsigned int nOperator) {
	unsigned int x;
	for (x = 0; OP_COMPOUND[x].cOperator != NULL; x++) {
		if (OP_COMPOUND[x].nToken == nOperator) {
			return OP_COMPOUND[x].cSecond;
		}
	}
	for (x = 0; OP_MULTI[x].cOperator != NULL; x++) {
		if (OP_MULTI[x].nToken == nOperator) {
			return OP_MULTI[x].cSecond;
		}
	}
	return NULL;
}

void ring_scanner_addreturn(RingState *pRingState) {
	List *pList;
	/* Add return to the end of the program */
	pList = ring_list_newlist_gc(pRingState, pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState, pList, ICO_RETNULL);
}

void ring_scanner_addreturn2(RingState *pRingState) {
	List *pList;
	/* Add return to the end of the program */
	pList = ring_list_newlist_gc(pRingState, pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState, pList, ICO_RETURN);
}

void ring_scanner_addreturn3(RingState *pRingState, unsigned int aPara[2]) {
	List *pList;
	/* Push Empty String */
	pList = ring_list_newlist_gc(pRingState, pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState, pList, ICO_PUSHC);
	ring_list_addstring_gc(pRingState, pList, RING_CSTR_EMPTY);
	/* Add return from eval to the end of the eval() code */
	pList = ring_list_newlist_gc(pRingState, pRingState->pRingGenCode);
	ring_list_addint_gc(pRingState, pList, ICO_RETFROMEVAL);
	ring_list_addint_gc(pRingState, pList, aPara[0]);
	ring_list_addint_gc(pRingState, pList, aPara[1]);
}

void ring_scanner_registertoken(Scanner *pScanner, unsigned int nType, const char *cValue) {
	List *pList;
	if (!pScanner->lEnableTokensOutput) {
		return;
	}
	pList = ring_list_newlist_gc(pScanner->pRingState, pScanner->pTokens);
	/* Add Token Type */
	ring_list_addint_gc(pScanner->pRingState, pList, nType);
	/* Add Token Text */
	ring_list_addstring_gc(pScanner->pRingState, pList, cValue);
	/* Add Token Index */
	ring_list_addint_gc(pScanner->pRingState, pList, pScanner->nTokenIndex);
}

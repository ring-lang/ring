/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Grammar 
*/

int ring_parser_expr ( Parser *pParser )
{
    int x,nMark  ;
    List *pMark  ;
    /* Expr --> LogicNot { and|or LogicNot } */
    if ( ring_parser_logicnot(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Expr --> LogicNot");
        #endif
        while ( ring_parser_iskeyword(pParser,K_AND) || ring_parser_isoperator(pParser,"&&")  || ring_parser_iskeyword(pParser,K_OR) || ring_parser_isoperator(pParser,"||") ) {
            if ( ring_parser_iskeyword(pParser,K_AND) || ring_parser_isoperator(pParser,"&&") ) {
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_JUMPZERO2);
                pMark = ring_parser_icg_getactiveoperation(pParser);
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_logicnot(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_AND);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                nMark = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark,nMark);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Expr --> LogicNot");
                        puts("Rule : Expr --> Expr 'And' Expr");
                    }
                #endif
            }
            else {
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_JUMPONE2);
                pMark = ring_parser_icg_getactiveoperation(pParser);
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_logicnot(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Expr --> LogicNot");
                        puts("Rule : Expr --> Expr 'Or' Expr");
                    }
                #endif
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_OR);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                nMark = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark,nMark);
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_logicnot ( Parser *pParser )
{
    int x  ;
    /* LogicNot --> Not EqualOrNot */
    if ( ring_parser_iskeyword(pParser,K_NOT) || ring_parser_isoperator2(pParser,OP_NOT) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        x = ring_parser_equalornot(pParser);
        #if RING_PARSERTRACE
            if ( x == 1 ) {
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : LogicNot -> 'not' EqualOrNot ");
            }
        #endif
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_NOT);
        /* Generate Location for nPC for Operator Overloading */
        ring_parser_icg_newoperandint(pParser,0);
        return x ;
    }
    x = ring_parser_equalornot(pParser);
    #if RING_PARSERTRACE
        if ( x == 1 ) {
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : LogicNot -> EqualOrNot ");
        }
    #endif
    return x ;
}

int ring_parser_equalornot ( Parser *pParser )
{
    int x  ;
    /* EqualOrNot --> Compare { =|!= Compare } */
    if ( ring_parser_compare(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : EqualOrNot --> Compare");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_EQUAL) || ring_parser_isoperator2(pParser,OP_NOT) ) {
            if ( ring_parser_isoperator2(pParser,OP_NOT) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
                    ring_parser_nexttoken(pParser);
                    RING_PARSER_IGNORENEWLINE ;
                    x = ring_parser_compare(pParser);
                    if ( x == 0 ) {
                        return 0 ;
                    }
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_NOTEQUAL);
                    /* Generate Location for nPC for Operator Overloading */
                    ring_parser_icg_newoperandint(pParser,0);
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        {
                            puts("Rule : EqualOrNot --> Compare");
                            puts("Rule : EqualOrNot --> EqualOrNot '!=' EqualOrNot");
                        }
                    #endif
                }
                else {
                    ring_parser_error(pParser,RING_PARSER_ERROR_EXPROPERATOR);
                    return 0 ;
                }
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_compare(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_EQUAL);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : EqualOrNot --> Compare");
                        puts("Rule : EqualOrNot --> EqualOrNot '=' EqualOrNot");
                    }
                #endif
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_compare ( Parser *pParser )
{
    int x,nEqual  ;
    /* Compare --> BitORXOR { <|>|<=|>= BITORXOR } */
    if ( ring_parser_bitorxor(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Compare --> BitOrXOR");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_LESS) || ring_parser_isoperator2(pParser,OP_GREATER) ) {
            nEqual = 0 ;
            if ( ring_parser_isoperator2(pParser,OP_LESS) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
                    nEqual = 1 ;
                    ring_parser_nexttoken(pParser);
                }
                x = ring_parser_bitorxor(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                if ( nEqual == 0 ) {
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_LESS);
                    /* Generate Location for nPC for Operator Overloading */
                    ring_parser_icg_newoperandint(pParser,0);
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        {
                            puts("Rule : Compare --> BitOrXOR");
                            puts("Rule : Compare --> Compare '<' Compare");
                        }
                    #endif
                }
                else {
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_LESSEQUAL);
                    /* Generate Location for nPC for Operator Overloading */
                    ring_parser_icg_newoperandint(pParser,0);
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        {
                            puts("Rule : Compare --> BitOrXOR");
                            puts("Rule : Compare --> Compare '<=' Compare");
                        }
                    #endif
                }
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
                    nEqual = 1 ;
                    ring_parser_nexttoken(pParser);
                    RING_PARSER_IGNORENEWLINE ;
                }
                x = ring_parser_bitorxor(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                if ( nEqual == 0 ) {
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_GREATER);
                    /* Generate Location for nPC for Operator Overloading */
                    ring_parser_icg_newoperandint(pParser,0);
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        {
                            puts("Rule : Compare --> BitOrXOR");
                            puts("Rule : Compare --> Compare '>' Compare");
                        }
                    #endif
                }
                else {
                    /* Generate Code */
                    ring_parser_icg_newoperation(pParser,ICO_GREATEREQUAL);
                    /* Generate Location for nPC for Operator Overloading */
                    ring_parser_icg_newoperandint(pParser,0);
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        {
                            puts("Rule : Compare --> BitOrXOR");
                            puts("Rule : Compare --> Compare '>=' Compare");
                        }
                    #endif
                }
            }
            /* Check <> */
            if ( x == 0 ) {
                return 0 ;
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_bitorxor ( Parser *pParser )
{
    int x  ;
    /* BitOrXOR --> BitAnd { | | ^ BitAnd } */
    if ( ring_parser_bitand(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : BitOrXOR -->  BitAnd");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_BITOR) || ring_parser_isoperator2(pParser,OP_XOR) ) {
            if ( ring_parser_isoperator2(pParser,OP_BITOR) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_bitand(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_BITOR);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : BitOrXOR --> BitAnd");
                        puts("Rule : BitOrXOR --> BitOrXOR '|' BitOrXOR");
                    }
                #endif
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_bitand(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_BITXOR);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : BitOrXOR --> BitAnd");
                        puts("Rule : BitOrXOR --> BitOrXOR '^' BitOrXOR");
                    }
                #endif
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_bitand ( Parser *pParser )
{
    int x  ;
    /* BitAnd --> BitShift { & BitShift } */
    if ( ring_parser_bitshift(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : BitAnd --> BitShift");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_BITAND) ) {
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
            x = ring_parser_bitshift(pParser);
            if ( x == 0 ) {
                return 0 ;
            }
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_BITAND);
            /* Generate Location for nPC for Operator Overloading */
            ring_parser_icg_newoperandint(pParser,0);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                {
                    puts("Rule : BitAnd --> BitShift");
                    puts("Rule : BitAnd --> BitAnd '&' BitAnd");
                }
            #endif
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_bitshift ( Parser *pParser )
{
    int x  ;
    /* BitShift --> Arith { << | >>  Arith } */
    if ( ring_parser_arithmetic(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : BitShift --> Arithmetic");
        #endif
        while ( ring_parser_isoperator(pParser,"<<") || ring_parser_isoperator(pParser,">>") ) {
            if ( ring_parser_isoperator(pParser,"<<") ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_arithmetic(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_BITSHL);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : BitShift --> Arithmetic");
                        puts("Rule : BitShift --> BitShift '<<' BitShift");
                    }
                #endif
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_arithmetic(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_BITSHR);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : BitShift --> Arithmetic");
                        puts("Rule : BitShift --> BitShift '>>' BitShift");
                    }
                #endif
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_arithmetic ( Parser *pParser )
{
    int x  ;
    /* Arithmetic --> Term { +|- Term } */
    if ( ring_parser_term(pParser) ) {
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Arithmetic --> Term");
        #endif
        x = 1 ;
        while ( ring_parser_isoperator2(pParser,OP_PLUS) || ring_parser_isoperator2(pParser,OP_MINUS) ) {
            if ( ring_parser_isoperator2(pParser,OP_PLUS) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_term(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_SUM);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Arithmetic --> Term");
                        puts("Rule : Arithmetic --> Arithmetic + Arithmetic");
                    }
                #endif
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_term(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_SUB);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Arithmetic --> Term");
                        puts("Rule : Arithmetic --> Arithmetic - Arithmetic");
                    }
                #endif
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_term ( Parser *pParser )
{
    int x  ;
    /* Term --> Range { *|/|% Range } */
    if ( ring_parser_range(pParser) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Term --> Range");
        #endif
        while ( ring_parser_isoperator2(pParser,OP_MUL) || ring_parser_isoperator2(pParser,OP_DIV) || ring_parser_isoperator2(pParser,OP_REM) ) {
            if ( ring_parser_isoperator2(pParser,OP_MUL) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Term --> Range");
                        puts("Rule : Term --> Term * Term ");
                    }
                #endif
                x = ring_parser_range(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_MUL);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
            }
            else if ( ring_parser_isoperator2(pParser,OP_REM) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_range(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_MOD);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Term --> Range");
                        puts("Rule : Term --> Term % Term ");
                    }
                #endif
            }
            else {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_range(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_DIV);
                /* Generate Location for nPC for Operator Overloading */
                ring_parser_icg_newoperandint(pParser,0);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    {
                        puts("Rule : Term --> Range");
                        puts("Rule : Term --> Term / Term ");
                    }
                #endif
            }
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_range ( Parser *pParser )
{
    int x,nFlag  ;
    /* Range --> Factor : Factor */
    if ( ring_parser_factor(pParser,&nFlag) ) {
        x = 1 ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            {
                if (nFlag) 
                
                puts("Rule : Factor --> Identifier [ {Mixer} | Assignment | PlusPlus | MinusMinus]");
                puts("Rule : Range --> Factor");
            }
        #endif
        if ( ring_parser_isoperator2(pParser,OP_RANGE) ) {
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
            x = ring_parser_factor(pParser,&nFlag);
            if ( x == 0 ) {
                return 0 ;
            }
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_RANGE);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                {
                    if (nFlag) 
                    
                    puts("Rule : Factor --> Identifier [ {Mixer} | Assignment | PlusPlus | MinusMinus]");
                    puts(" Range --> Factor");
                    puts(" Range --> Range : Range ");
                }
            #endif
        }
        return x ;
    }
    return 0 ;
}

int ring_parser_factor ( Parser *pParser,int *nFlag )
{
    int x,x2,x3,nLastOperation,nCount,nNOOP,nToken,nMark,nFlag2,nThisOrSelfLoadA  ;
    List *pLoadAPos, *pList, *pMark,*pAssignmentPointerPos  ;
    char lSetProperty,lequal,nBeforeEqual  ;
    char cFuncName[100]  ;
    char cKeyword[100]  ;
    /* Set Identifier Flag - is 1 when we have Factor -->Identifier */
    *nFlag = 0 ;
    pAssignmentPointerPos = NULL ;
    /* Factor --> Identifier  {mixer} [ '=' Expr ] */
    if ( ring_parser_isidentifier(pParser) ) {
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
        ring_parser_icg_newoperand(pParser,pParser->TokenText);
        /* Generate Location for nPC of Getter */
        ring_parser_icg_newoperandint(pParser,0);
        /* Check Loading Self or This */
        if ( strcmp(pParser->TokenText,"self") == 0 || strcmp(pParser->TokenText ,"this") == 0 ) {
            pParser->nThisOrSelfLoadA = 1 ;
        }
        else {
            pParser->nThisOrSelfLoadA = 0 ;
        }
        ring_parser_nexttoken(pParser);
        /* Set Identifier Flag */
        *nFlag = 1 ;
        nToken = RING_PARSER_CURRENTTOKEN ;
        RING_PARSER_PASSNEWLINE ;
        /* Back if we don't have { */
        if ( (RING_PARSER_CURRENTTOKEN > nToken ) ) {
            if ( ! ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
                ring_parser_settoken(pParser,nToken);
            }
        }
        /* Array Index & Object Dot */
        x = ring_parser_mixer(pParser);
        if ( x == 0 ) {
            return 0 ;
        }
        /*
        **  [ [ = Expr  ] 
        **  Save State before changes by Check Operator 
        */
        nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
        pList = ring_parser_icg_getactiveoperation(pParser) ;
        /* Check Operator */
        lequal = 1 ;
        if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
            nBeforeEqual = 0 ;
        }
        else if ( ring_parser_isoperator(pParser,"+=") ) {
            nBeforeEqual = 1 ;
        }
        else if ( ring_parser_isoperator(pParser,"-=") ) {
            nBeforeEqual = 2 ;
        }
        else if ( ring_parser_isoperator(pParser,"*=") ) {
            nBeforeEqual = 3 ;
        }
        else if ( ring_parser_isoperator(pParser,"/=") ) {
            nBeforeEqual = 4 ;
        }
        else if ( ring_parser_isoperator(pParser,"%=") ) {
            nBeforeEqual = 5 ;
        }
        else if ( ring_parser_isoperator(pParser,"&=") ) {
            nBeforeEqual = 6 ;
        }
        else if ( ring_parser_isoperator(pParser,"|=") ) {
            nBeforeEqual = 7 ;
        }
        else if ( ring_parser_isoperator(pParser,"^=") ) {
            nBeforeEqual = 8 ;
        }
        else if ( ring_parser_isoperator(pParser,"<<=") ) {
            nBeforeEqual = 9 ;
        }
        else if ( ring_parser_isoperator(pParser,">>=") ) {
            nBeforeEqual = 10 ;
        }
        else {
            lequal = 0 ;
            nBeforeEqual = 0 ;
        }
        if ( (lequal == 1 ) && (pParser->nAssignmentFlag == 1) ) {
            ring_parser_nexttoken(pParser);
            /* Check if the Assignment after object attribute name */
            nThisOrSelfLoadA = pParser->nThisOrSelfLoadA ;
            pLoadAPos = NULL ;
            if ( nLastOperation == ICO_LOADSUBADDRESS ) {
                lSetProperty = 1 ;
            }
            else {
                lSetProperty = 0 ;
                /* When the assignment is after LoadAddress */
                if ( nLastOperation == ICO_LOADADDRESS ) {
                    pLoadAPos = pList ;
                }
            }
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
            pAssignmentPointerPos = ring_parser_icg_getactiveoperation(pParser) ;
            RING_PARSER_IGNORENEWLINE ;
            pParser->nNewObject = 0 ;
            x = ring_parser_expr(pParser);
            /* Check New Object and this.property or self.property to disable set property */
            if ( pParser->nNewObject && lSetProperty && nThisOrSelfLoadA ) {
                lSetProperty = 0 ;
            }
            #if RING_PARSERTRACE
                if ( x == 1 ) {
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : Assignment -> '=' Expr ");
                }
            #endif
            /* Generate Code */
            if ( pParser->nNewObject==0 ) {
                /*
                **  We don't need assignment after ListEnd, because lists directly stored in the Variable 
                **  We do this when we are not inside Brace 
                */
                nNOOP = 0 ;
                if ( (ring_parser_icg_getlastoperation(pParser) == ICO_LISTEND) && (pParser->nBraceFlag == 0) ) {
                    if ( lSetProperty == 0 ) {
                        return x ;
                    }
                    /* Disable Assignment Pointer */
                    ring_parser_icg_addoperandint(pParser,pAssignmentPointerPos,0);
                }
                else if ( (ring_parser_icg_getlastoperation(pParser) == ICO_LISTEND) && (pParser->nBraceFlag >= 1) ) {
                    nNOOP = 1 ;
                    /*
                    **  No Assignment is required but we add ICO_NOOP instead 
                    **  ICO_NOOP can be converted to Set Property when we access object attributes inside {} 
                    */
                    if ( lSetProperty == 1 ) {
                        /* Disable Assignment Pointer */
                        ring_parser_icg_addoperandint(pParser,pAssignmentPointerPos,0);
                    }
                }
                /*
                **  Before Equal 
                **  Generate Code 
                */
                ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
                ring_parser_icg_newoperandint(pParser,nBeforeEqual);
                if ( lSetProperty == 0 ) {
                    if ( nNOOP == 0 ) {
                        ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
                    }
                    else {
                        ring_parser_icg_newoperation(pParser,ICO_NOOP);
                    }
                }
                else {
                    ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
                }
                /*
                **  Generate Locations for Setproperty before/after Flag & nPC of Setter 
                **  Locations is done also for Assignment because assignment can be changed to SetProperty by the VM 
                */
                ring_parser_icg_newoperandint(pParser,0);
                ring_parser_icg_newoperandint(pParser,0);
                /* Add Assignment position to the LoadAddress Instruction */
                if ( pLoadAPos != NULL ) {
                    ring_parser_icg_addoperandint(pParser,pLoadAPos,ring_parser_icg_instructionscount(pParser));
                }
            }
            else {
                /* In this case we have (New Object) */
                pParser->nNewObject = 0 ;
                /*
                **  Before Equal 
                **  Generate Code 
                */
                ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
                ring_parser_icg_newoperandint(pParser,nBeforeEqual);
                if ( lSetProperty == 0 ) {
                    ring_parser_icg_newoperation(pParser,ICO_NOOP);
                }
                else {
                    ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
                    /* Disable Assignment Pointer */
                    ring_parser_icg_addoperandint(pParser,pAssignmentPointerPos,0);
                }
                /*
                **  Generate Locations for Setproperty before/after Flag & nPC of Setter 
                **  Locations is done also for Assignment because assignment can be changed to SetProperty by the VM 
                */
                ring_parser_icg_newoperandint(pParser,0);
                ring_parser_icg_newoperandint(pParser,0);
                /* Add Assignment position to the LoadAddress Instruction */
                if ( pLoadAPos != NULL ) {
                    ring_parser_icg_addoperandint(pParser,pLoadAPos,ring_parser_icg_instructionscount(pParser));
                }
            }
            return x ;
        }
        /* ++ & -- */
        if ( ring_parser_ppmm(pParser) ) {
            return 1 ;
        }
        /* Generate Code */
        if ( (ring_parser_icg_getlastoperation(pParser) != ICO_CALL) && (ring_parser_icg_getlastoperation(pParser) != ICO_BRACEEND) ) {
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
        }
        return 1 ;
    }
    /* Factor --> Number */
    if ( ring_parser_isnumber(pParser) ) {
        /* Generate Code */
        if ( strlen(pParser->TokenText) <= RING_PARSER_NUMBERLENGTH ) {
            ring_parser_icg_newoperation(pParser,ICO_PUSHN);
            ring_parser_icg_newoperanddouble(pParser,atof(pParser->TokenText));
        }
        else {
            ring_parser_error(pParser,RING_PARSER_ERROR_NUMERICOVERFLOW);
            ring_parser_nexttoken(pParser);
            return 0 ;
        }
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> Number");
        #endif
        ring_parser_nexttoken(pParser);
        /* If we have condition - pass new lines */
        if ( pParser->nControlStructureExpr ) {
            RING_PARSER_IGNORENEWLINE ;
        }
        /* ++ and -- */
        if ( ring_parser_ppmm(pParser) ) {
            return 1 ;
        }
        /* Check using '(' after number */
        if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
            ring_parser_error(pParser,RING_PARSER_ERROR_USINGBRACTAFTERNUM);
            return 0 ;
        }
        return 1 ;
    }
    /* Factor --> Literal */
    if ( ring_parser_isliteral(pParser) ) {
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PUSHC);
        ring_parser_icg_newoperand(pParser,pParser->TokenText);
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> Literal");
        #endif
        ring_parser_nexttoken(pParser);
        /* If we have condition - pass new lines */
        if ( pParser->nControlStructureExpr ) {
            RING_PARSER_IGNORENEWLINE ;
        }
        return 1 ;
    }
    /* Factor --> Literal --> ':' Identifier */
    if ( ring_parser_isoperator2(pParser,OP_RANGE) ) {
        ring_parser_nexttoken(pParser);
        if ( ring_parser_isidentifier(pParser) || ring_parser_isanykeyword(pParser) || ring_parser_isnumber(pParser) ) {
            nCount = ring_parser_icg_instructionscount(pParser);
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_PUSHC);
            if ( ring_parser_isanykeyword(pParser) ) {
                strcpy(cKeyword,ring_scanner_getkeywordtext(pParser->TokenText));
                ring_string_lower(cKeyword);
                ring_parser_icg_newoperand(pParser,cKeyword);
            }
            else {
                ring_parser_icg_newoperand(pParser,pParser->TokenText);
            }
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                {
                    puts("Rule : Literal --> ':' Identifier ['=' Expr]");
                    puts("Rule : Factor --> Literal");
                }
            #endif
            ring_parser_nexttoken(pParser);
            /* Hash --> '=' Expression */
            if ( ring_parser_isoperator2(pParser,OP_EQUAL) ) {
                ring_parser_nexttoken(pParser);
                /* Generate Code */
                ring_parser_icg_insertoperation(pParser,nCount,ICO_LISTSTART);
                ring_parser_icg_insertoperation(pParser,nCount+2,ICO_LISTITEM);
                /* Go to last operation, because insert change the active operation */
                RING_PARSER_ICG_GOTOLASTOP ;
                if ( ring_parser_expr(pParser) ) {
                    /* Generate Code */
                    if ( ring_parser_icg_getlastoperation(pParser) != ICO_LISTEND ) {
                        ring_parser_icg_newoperation(pParser,ICO_LISTITEM);
                    }
                    ring_parser_icg_newoperation(pParser,ICO_LISTEND);
                    return 1 ;
                }
                return 0 ;
            }
            return 1 ;
        }
    }
    /* Factor --> Negative (-) Factor */
    if ( ring_parser_isoperator2(pParser,OP_MINUS) ) {
        ring_parser_nexttoken(pParser);
        x = ring_parser_factor(pParser,&nFlag2);
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_NEG);
        /* Generate Location for nPC for Operator Overloading */
        ring_parser_icg_newoperandint(pParser,0);
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> '-' Factor");
        #endif
        return x ;
    }
    else if ( ring_parser_isoperator2(pParser,OP_BITNOT) ) {
        /* bitnot (~) Expr */
        ring_parser_nexttoken(pParser);
        x = ring_parser_expr(pParser);
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_BITNOT);
        /* Generate Location for nPC for Operator Overloading */
        ring_parser_icg_newoperandint(pParser,0);
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> '~' Expr");
        #endif
        return x ;
    }
    /* Factor --> & */
    else if ( ring_parser_isoperator2(pParser,OP_BITAND) ) {
        ring_parser_nexttoken(pParser);
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_RETITEMREF);
        if ( ring_parser_expr(pParser) ) {
            return 1 ;
        }
    }
    /* Factor --> ( Expr ) */
    if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
        ring_parser_nexttoken(pParser);
        if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Factor --> '()'");
            #endif
            return 1 ;
        }
        x = pParser->nAssignmentFlag ;
        pParser->nAssignmentFlag = 0 ;
        if ( ring_parser_expr(pParser) ) {
            pParser->nAssignmentFlag = x ;
            if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_IGNORENEWLINE ;
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : Factor --> '(' Expr ')'");
                #endif
                /* '(' Expression ')' then Dot Operator to access an object */
                if ( ring_parser_isoperator2(pParser,OP_DOT) ) {
                    /* Remove PUSHV */
                    if ( ring_parser_icg_getlastoperation(pParser)  == ICO_PUSHV ) {
                        ring_parser_icg_deletelastoperation(pParser);
                    }
                    x = ring_parser_mixer(pParser);
                    if ( x == 0 ) {
                        return 0 ;
                    }
                    /* Add PUSHV */
                    ring_parser_icg_newoperation(pParser,ICO_PUSHV);
                }
                return 1 ;
            }
            else {
                ring_parser_error(pParser,RING_PARSER_ERROR_MISSPARENTHESES);
                return 0 ;
            }
        }
        return 0 ;
    }
    /* Factor --> List */
    if ( ring_parser_isoperator2(pParser,OP_LOPEN) ) {
        x = ring_parser_list(pParser) ;
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> List");
        #endif
        return x ;
    }
    /* Factor --> New Identifier */
    if ( ring_parser_iskeyword(pParser,K_NEW) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_NEWOBJ);
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Factor --> New Identifier {'.' Identifier }  ");
        #endif
        if ( ring_parser_namedotname(pParser) ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_SETSCOPE);
            RING_PARSER_IGNORENEWLINE ;
            if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
                x = ring_parser_mixer(pParser);
                pParser->nNewObject = 1 ;
                return x ;
            }
            else if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
                /*
                **  Calling the init method using { } 
                **  Generate Code (Start Brace) 
                */
                ring_parser_icg_newoperation(pParser,ICO_PUSHV);
                ring_parser_icg_newoperation(pParser,ICO_BRACESTART);
                ring_parser_icg_newoperation(pParser,ICO_CALLCLASSINIT);
                ring_parser_icg_newoperandint(pParser,1);
                /* Generate Code ( Call Function ) */
                ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
                ring_parser_icg_newoperand(pParser,"init");
                /* Generate Location for nPC of Getter */
                ring_parser_icg_newoperandint(pParser,0);
                /* Function Parameters */
                pParser->nFuncCallOnly = 1 ;
                ring_parser_mixer(pParser);
                pParser->nFuncCallOnly = 0 ;
                /* Generate Code (End Brace) */
                ring_parser_icg_newoperation(pParser,ICO_CALLCLASSINIT);
                ring_parser_icg_newoperandint(pParser,0);
                RING_PARSER_IGNORENEWLINE ;
                x = ring_parser_mixer(pParser);
                ring_parser_icg_newoperation(pParser,ICO_BRACEEND);
                pParser->nNewObject = 1 ;
                return x ;
            }
            pParser->nNewObject = 1 ;
            /*
            **  Generate Code 
            **  PUSHV enable using braces to access the object 
            */
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            return 1 ;
        }
    }
    /* Factor --> Anonymous Function */
    if ( ring_parser_iskeyword(pParser,K_FUNC) || ring_parser_iskeyword(pParser,K_FUNCTION) || ring_parser_iskeyword(pParser,K_DEF) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_PASSNEWLINE ;
        /*
        **  Generate Code 
        **  Push Function Name, then jump after the function code 
        */
        ring_parser_icg_newoperation(pParser,ICO_PUSHC);
        /* Note : the function name must be in lower case */
        sprintf( cFuncName , "_ring_anonymous_func_%d" , RING_PARSER_OPERATIONID ) ;
        ring_parser_icg_newoperand(pParser,cFuncName);
        ring_parser_icg_newoperation(pParser,ICO_JUMP);
        pMark = ring_parser_icg_getactiveoperation(pParser);
        /* Define the Function - as public (not related to any class) */
        pList = ring_list_newlist_gc(pParser->pRingState,pParser->pRingState->pRingFunctionsMap);
        ring_list_addstring_gc(pParser->pRingState,pList,cFuncName);
        /* Note +1 because instruction ICO_NEWFUNC will come next */
        ring_list_addint_gc(pParser->pRingState,pList,RING_PARSER_OPERATIONID+1);
        ring_list_addstring_gc(pParser->pRingState,pList,ring_list_getstring(pParser->pRingState->pRingFilesStack,ring_list_getsize(pParser->pRingState->pRingFilesStack)));
        ring_list_addint_gc(pParser->pRingState,pList,0);
        ring_parser_icg_newoperation(pParser,ICO_NEWFUNC);
        ring_parser_icg_newoperand(pParser,cFuncName);
        /* Get Function Parameters */
        if ( ring_parser_isidentifier(pParser) || ring_parser_isoperator2(pParser,OP_FOPEN) ) {
            if (! ring_parser_paralist(pParser)) return 0 ;
        }
        RING_PARSER_PASSNEWLINE ;
        /* Get Function Code */
        if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) ) {
            ring_parser_nexttoken(pParser);
            x = pParser->nAssignmentFlag ;
            x2 = pParser->nNewObject ;
            x3 = pParser->nBraceFlag ;
            pParser->nAssignmentFlag = 1 ;
            pParser->nBraceFlag = 0 ;
            RING_PARSER_ACCEPTSTATEMENTS ;
            pParser->nAssignmentFlag = x ;
            pParser->nNewObject = x2 ;
            pParser->nBraceFlag = x3 ;
            if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
                ring_parser_nexttoken(pParser);
                /* Generate Code */
                ring_parser_icg_newoperation(pParser,ICO_RETNULL);
                nMark = ring_parser_icg_newlabel(pParser);
                ring_parser_icg_addoperandint(pParser,pMark,nMark);
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : AnonymousFunction --> Func ParaList '{' Statement '}'");
                #endif
                return 1 ;
            }
        }
    }
    /* Factor --> Call Identifier ( parameters ) */
    if ( ring_parser_iskeyword(pParser,K_CALL) ) {
        ring_parser_nexttoken(pParser);
        if ( ring_parser_isidentifier(pParser) ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
            ring_parser_icg_newoperand(pParser,pParser->TokenText);
            /* Generate Location for nPC of Getter */
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_nexttoken(pParser);
            /* Object Attributes */
            if ( ring_parser_objattributes(pParser) == 0 ) {
                return 0 ;
            }
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            ring_parser_icg_newoperation(pParser,ICO_ANONYMOUS);
            if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
                return ring_parser_mixer(pParser) ;
            }
            else {
                return 0 ;
            }
        }
        else {
            return 0 ;
        }
    }
    return 0 ;
}

int ring_parser_mixer ( Parser *pParser )
{
    int x,nCallMethod,nStatus,nFlag,nNew  ;
    /*
    **  { . Identifier } 
    **  Object Attributes 
    */
    if ( ring_parser_objattributes(pParser) == 0 ) {
        return 0 ;
    }
    /* [Index]  to access array element, Index = Expression */
    if ( ring_parser_isoperator2(pParser,OP_LOPEN) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        if ( ring_parser_expr(pParser) ) {
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_LOADINDEXADDRESS);
            /* Add 0 For Operator Overloading */
            ring_parser_icg_newoperandint(pParser,0);
            if ( ring_parser_isoperator2(pParser,OP_LCLOSE) ) {
                ring_parser_nexttoken(pParser);
                RING_PARSER_PASSNEWLINE ;
                #if RING_PARSERTRACE
                    RING_STATE_CHECKPRINTRULES 
                    
                    puts("Rule : Mixer -> '[' Expr ']' ");
                #endif
                x = ring_parser_mixer(pParser);
                if ( x == 0 ) {
                    return 0 ;
                }
            }
            else {
                ring_parser_error(pParser,RING_PARSER_ERROR_MISSBRACKETS);
                return 0 ;
            }
        }
        else {
            return 0 ;
        }
    }
    /* |  [ ( [ Expr { , Expr } ] ) ]  ] */
    if ( ring_parser_isoperator2(pParser,OP_FOPEN) ) {
        /* Generate Code */
        nCallMethod = 0 ;
        if ( ring_parser_icg_getlastoperation(pParser) == ICO_LOADADDRESS ) {
            ring_parser_icg_setlastoperation(pParser,ICO_LOADFUNC);
            /* Delete Locations for Getter */
            ring_list_deleteitem_gc(pParser->pRingState,ring_parser_icg_getactiveoperation(pParser),3);
        }
        else if ( ring_parser_icg_getlastoperation(pParser) == ICO_LOADSUBADDRESS ) {
            ring_parser_icg_setlastoperation(pParser,ICO_LOADMETHOD);
            /* Delete Locations for Setter/Getter */
            ring_list_deleteitem_gc(pParser->pRingState,ring_parser_icg_getactiveoperation(pParser),4);
            ring_list_deleteitem_gc(pParser->pRingState,ring_parser_icg_getactiveoperation(pParser),3);
            nCallMethod = 1 ;
        }
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
            ring_parser_nexttoken(pParser);
            /* Generate Code */
            ring_parser_gencall(pParser,nCallMethod);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Mixer -> '(' [Expr { ',' Expr} ] ')' ");
            #endif
            RING_PARSER_IGNORENEWLINE ;
            x = ring_parser_mixer(pParser);
            return x ;
        }
        while ( 1 ) {
            nFlag = pParser->nAssignmentFlag ;
            nNew = pParser->nNewObject ;
            pParser->nAssignmentFlag = 0 ;
            if ( ring_parser_expr(pParser) ) {
                pParser->nAssignmentFlag = nFlag ;
                pParser->nNewObject = nNew ;
                RING_PARSER_IGNORENEWLINE ;
                if ( ring_parser_isoperator2(pParser,OP_COMMA) ) {
                    ring_parser_nexttoken(pParser);
                }
                else if ( ring_parser_isoperator2(pParser,OP_FCLOSE) ) {
                    #if RING_PARSERTRACE
                        RING_STATE_CHECKPRINTRULES 
                        
                        puts("Rule : Mixer -> '(' [Expr { ',' Expr} ] ')' ");
                    #endif
                    ring_parser_nexttoken(pParser);
                    /* Generate Code */
                    ring_parser_gencall(pParser,nCallMethod);
                    RING_PARSER_IGNORENEWLINE ;
                    x = ring_parser_mixer(pParser);
                    return x ;
                }
                else {
                    ring_parser_error(pParser,RING_PARSER_ERROR_MISSPARENTHESES);
                    return 0 ;
                }
            }
            else {
                return 0 ;
            }
            RING_PARSER_IGNORENEWLINE ;
        }
    }
    /* Function Call Only */
    if ( pParser->nFuncCallOnly == 1 ) {
        return 1 ;
    }
    /* '{' {Statement} '}' */
    if ( ring_parser_isoperator2(pParser,OP_BRACEOPEN) && pParser->nControlStructureExpr == 0 ) {
        pParser->nBraceFlag++ ;
        /* Generate Code */
        ring_parser_icg_newoperation(pParser,ICO_PUSHV);
        ring_parser_icg_newoperation(pParser,ICO_BRACESTART);
        #if RING_PARSERTRACE
            RING_STATE_CHECKPRINTRULES 
            
            puts("Rule : Mixer --> '{' {Statement} BraceEnd");
        #endif
        /* if ismethod(self,"bracestart") bracestart() ok */
        ring_parser_gencallbracemethod(pParser,"bracestart");
        ring_parser_nexttoken(pParser);
        nStatus = pParser->nAssignmentFlag ;
        pParser->nAssignmentFlag = 1 ;
        RING_PARSER_ACCEPTSTATEMENTS ;
        pParser->nAssignmentFlag = nStatus ;
        if ( ring_parser_isoperator2(pParser,OP_BRACECLOSE) ) {
            pParser->nBraceFlag-- ;
            /*
            **  Generate Code 
            **  if ismethod(self,"braceend") braceend() ok 
            */
            ring_parser_gencallbracemethod(pParser,"braceend");
            ring_parser_icg_newoperation(pParser,ICO_BRACEEND);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : BraceEnd --> '}' ");
            #endif
            ring_parser_nexttoken(pParser);
            x = ring_parser_mixer(pParser);
            return x ;
        }
        else {
            ring_parser_error(pParser,RING_PARSER_ERROR_BRACESNOTCLOSED);
        }
    }
    /* This function return 1 because the mixer is optional and comes after identifier */
    return 1 ;
}

void ring_parser_gencall ( Parser *pParser,int nCallMethod )
{
    /* Generate Code */
    ring_parser_icg_newoperation(pParser,ICO_CALL);
    if ( nCallMethod == 1 ) {
        /* Add 0 For Operator Overloading */
        ring_parser_icg_newoperandint(pParser,0);
        /* Add 1 so the call instruction move list from aBeforeObjState to pObjState */
        ring_parser_icg_newoperandint(pParser,1);
        ring_parser_icg_newoperation(pParser,ICO_AFTERCALLMETHOD);
    }
    else {
        /* Add 0 For Operator Overloading */
        ring_parser_icg_newoperandint(pParser,0);
        /*
        **  The No Operation Instruction may be converted to AfterCallMethod during runtime 
        **  This happens when we call method like functions inside object { } 
        */
        ring_parser_icg_newoperation(pParser,ICO_NOOP);
    }
}

int ring_parser_ppmm ( Parser *pParser )
{
    int nLastOperation,nMark,nMode,nValue  ;
    List *pMark  ;
    nLastOperation = ring_parser_icg_getlastoperation(pParser) ;
    pMark = ring_parser_icg_getactiveoperation(pParser);
    /* ++ & -- */
    if ( ring_parser_isoperator(pParser,"++") ) {
        ring_parser_nexttoken(pParser);
        switch ( nLastOperation ) {
            case ICO_LOADADDRESS :
                nMode = 3 ;
                if ( pParser->nBraceFlag ) {
                    nMode = 1 ;
                    nValue = 1.0 ;
                }
                break ;
            case ICO_LOADSUBADDRESS :
                nMode = 2 ;
                nValue = 1.0 ;
                break ;
            default :
                nMode = 3 ;
        }
    }
    else if ( ring_parser_isoperator(pParser,"--") ) {
        ring_parser_nexttoken(pParser);
        switch ( nLastOperation ) {
            case ICO_LOADADDRESS :
                nMode = 4 ;
                if ( pParser->nBraceFlag ) {
                    nMode = 1 ;
                    nValue = -1.0 ;
                }
                break ;
            case ICO_LOADSUBADDRESS :
                nMode = 2 ;
                nValue = -1.0 ;
                break ;
            default :
                nMode = 4 ;
        }
    }
    else {
        return 0 ;
    }
    /* Code Generation */
    switch ( nMode ) {
        case 1 :
            /* Code Generation */
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
            /* Duplicate the address two times, one for the assignment (x = x+1) and one to keep the value on the */
            ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
            ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            ring_parser_icg_newoperation(pParser,ICO_PUSHN);
            ring_parser_icg_newoperanddouble(pParser,nValue);
            ring_parser_icg_newoperation(pParser,ICO_SUM);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
            ring_parser_icg_newoperandint(pParser,0);
            nMark = ring_parser_icg_newlabel(pParser);
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENT);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_addoperandint(pParser,pMark,nMark);
            /* Keep the value on the Stack (Maybe required in expressions) */
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            break ;
        case 2 :
            /* Code Generation */
            ring_parser_icg_newoperation(pParser,ICO_ASSIGNMENTPOINTER);
            /* Duplicate the address two times, One for the assignment (x=x+1) and one to  keep the value on the */
            ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
            ring_parser_icg_newoperation(pParser,ICO_DUPLICATE);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            ring_parser_icg_newoperation(pParser,ICO_PUSHN);
            ring_parser_icg_newoperanddouble(pParser,nValue);
            ring_parser_icg_newoperation(pParser,ICO_SUM);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_BEFOREEQUAL);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperation(pParser,ICO_SETPROPERTY);
            ring_parser_icg_newoperandint(pParser,0);
            ring_parser_icg_newoperandint(pParser,0);
            /* Keep the Value on the Stack (Maybe required in expressions) */
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            break ;
        case 3 :
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_PLUSPLUS);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : PlusPlus --> '++'");
            #endif
            break ;
        case 4 :
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_MINUSMINUS);
            ring_parser_icg_newoperation(pParser,ICO_PUSHV);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : MinusMinus --> '--'");
            #endif
            break ;
    }
    return 1 ;
}

void ring_parser_gencallbracemethod ( Parser *pParser,const char *cMethod )
{
    int nMark1  ;
    List *pMark  ;
    /* if ismethod(self,cMethod) cMethod() ok */
    ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
    ring_parser_icg_newoperand(pParser,"ismethod");
    ring_parser_icg_newoperation(pParser,ICO_LOADADDRESS);
    ring_parser_icg_newoperand(pParser,"self");
    ring_parser_icg_newoperandint(pParser,0);
    ring_parser_icg_newoperation(pParser,ICO_PUSHV);
    ring_parser_icg_newoperation(pParser,ICO_PUSHC);
    ring_parser_icg_newoperand(pParser,cMethod);
    ring_parser_icg_newoperation(pParser,ICO_CALL);
    ring_parser_icg_newoperation(pParser,ICO_NOOP);
    ring_parser_icg_newoperation(pParser,ICO_PUSHV);
    /* Jump */
    ring_parser_icg_newoperation(pParser,ICO_JUMPZERO);
    pMark = ring_parser_icg_getactiveoperation(pParser);
    ring_parser_icg_newoperation(pParser,ICO_LOADFUNC);
    ring_parser_icg_newoperand(pParser,cMethod);
    ring_parser_icg_newoperation(pParser,ICO_CALL);
    ring_parser_icg_newoperation(pParser,ICO_NOOP);
    ring_parser_icg_newoperation(pParser,ICO_PUSHV);
    ring_parser_icg_newoperation(pParser,ICO_FREESTACK);
    nMark1 = ring_parser_icg_newlabel(pParser);
    ring_parser_icg_addoperandint(pParser,pMark,nMark1);
}

int ring_parser_objattributes ( Parser *pParser )
{
    /* { . Identifier } */
    while ( ring_parser_isoperator2(pParser,OP_DOT) ) {
        ring_parser_nexttoken(pParser);
        RING_PARSER_IGNORENEWLINE ;
        /* we support literal to be able to call methods contains operators in the name */
        if ( ring_parser_isidentifier(pParser) || ring_parser_isliteral(pParser) ) {
            /* Prevent Accessing the self reference from outside the object */
            if ( strcmp(pParser->TokenText,"self") == 0 ) {
                ring_parser_error(pParser,RING_PARSER_ERROR_ACCESSSELFREF);
                return 0 ;
            }
            /* Generate Code */
            ring_parser_icg_newoperation(pParser,ICO_LOADSUBADDRESS);
            ring_parser_icg_newoperand(pParser,pParser->TokenText);
            /* Generate Location for nPC of Getter - When we access object attribute using { } */
            ring_parser_icg_newoperandint(pParser,0);
            #if RING_PARSERTRACE
                RING_STATE_CHECKPRINTRULES 
                
                puts("Rule : Mixer -> '.' Identifier ");
            #endif
            ring_parser_nexttoken(pParser);
            RING_PARSER_IGNORENEWLINE ;
        }
        else {
            return 0 ;
        }
    }
    return 1 ;
}

/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "ring_test.h"
/* Main Function */

int main ( int argc, char *argv[] )
{
    ring_section("Hello!");
    printf( "These are some old tests that I was using in the early days of development \n" ) ;
    printf( "This was before we have a Compiler and a VM that we can run \n" ) ;
    printf( "Now we have a group of tests in ring/language/test folder \n" ) ;
    printf( "Also we keep this file if you want to do some experiments! \n" ) ;
    ring_section("Start of tests");
    ring_testallunits();
    ring_section("End of tests");
    getchar();
}
/* Functions */

void ring_testallunits ( void )
{
    /* Test */
    ring_section("Strings");
    ring_string_test();
    ring_section("Lists");
    ring_list_test();
    ring_section("HashTable");
    ring_hashtable_test();
}

void ring_section ( const char *cTitle )
{
    ring_general_printline();
    printf( "%s\n",cTitle ) ;
    ring_general_printline();
}

void ring_string_test ( void )
{
    #define nMaxValue 10
    String *mystr[nMaxValue]  ;
    int x  ;
    String *pString  ;
    for ( x = 0 ; x < nMaxValue ; x++ ) {
        mystr[x] = ring_string_new("Wow Really i like the c language so much");
        ring_string_print(mystr[x]);
    }
    for ( x = 0 ; x < nMaxValue ; x++ ) {
        mystr[x] = ring_string_delete(mystr[x]);
    }
    /* Test String Add */
    pString = ring_string_new("Hello ");
    ring_string_add(pString,"World");
    printf( "\nTest String Add , Output = %s\n",ring_string_get(pString) ) ;
    ring_string_add(pString," Welcome to the C programming language");
    printf( "\nTest String Add , Output = %s\n",ring_string_get(pString) ) ;
    ring_string_delete(pString);
    /* Test String to Lower */
    pString = ring_string_new("Welcome to my StrinG");
    printf( "Test string to lower \n" ) ;
    printf( "%s\n",ring_string_tolower(pString) ) ;
    ring_string_delete(pString);
}

void ring_list_test ( void )
{
    List *pList,*pList2  ;
    int x  ;
    Item *pItem  ;
    String *pString  ;
    char mystr[20]  ;
    printf( "Create new list, size = 10 \n" ) ;
    pList = ring_list_new(10);
    printf( "List(1) size %d    \n", ring_list_getsize(pList) ) ;
    printf( "Create empty list \n" ) ;
    pList2 = ring_list_new(0);
    printf( "adding 15 items to the list \n" ) ;
    for ( x = 1 ; x <= 15 ; x++ ) {
        printf( "x : %d  \n" , x ) ;
        ring_list_newitem(pList2);
    }
    printf( "List(2) size %d    \n", ring_list_getsize(pList2) ) ;
    for ( x = 1 ; x <= 10 ; x++ ) {
        /* Work on items */
        pItem = ring_list_getitem(pList2,x);
        ring_item_settype(pItem,ITEMTYPE_STRING);
        pString = ring_item_getstring(pItem);
        sprintf( mystr , "The Item Number %d" , x ) ;
        ring_string_set(pString,mystr);
        ring_string_print(pString);
    }
    for ( x = 11 ; x <= 15 ; x++ ) {
        /* Work on items */
        pItem = ring_list_getitem(pList2,x);
        ring_item_settype(pItem,ITEMTYPE_NUMBER);
    }
    /* Delete Items */
    printf( "Delete item number 5 \n" ) ;
    ring_list_deleteitem(pList2,5);
    pItem = ring_list_getitem(pList2,5);
    pString = ring_item_getstring(pItem);
    ring_string_print(pString);
    printf( "Delete item number 1 \n" ) ;
    /* Print Item */
    ring_list_deleteitem(pList2,1);
    pItem = ring_list_getitem(pList2,1);
    pString = ring_item_getstring(pItem);
    ring_string_print(pString);
    printf( "Delete item number %d \n",ring_list_getsize(pList2) ) ;
    /* Print Item */
    ring_list_deleteitem(pList2,ring_list_getsize(pList2));
    printf( "get item number %d \n",ring_list_getsize(pList2) ) ;
    /* Delete Lists */
    printf( "Deleting List 1 \n" ) ;
    ring_list_delete(pList);
    printf( "Deleting List 2 \n" ) ;
    ring_list_delete(pList2);
    /* Create/Delete Large List */
    printf( "Create List of 1000000 Items  \n" ) ;
    pList = ring_list_new(1000000);
    printf( "Before Loop  \n" ) ;
    for ( x = 1 ; x <= 1000000 ; x++ ) {
        ring_list_setstring(pList,x,"empty item");
    }
    printf( "Done  \n" ) ;
    printf( "Deleting List 1 \n" ) ;
    ring_list_delete(pList);
    /* Create Nested Lists */
    printf( "List = {'first item',{'item (2) item(1)','item(2) item(2)'},'lastitem' , 50 , Pointer to int } \n  " ) ;
    pList = ring_list_new(5);
    /* Set Item 1 */
    pItem = ring_list_getitem(pList,1);
    ring_item_settype(pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    ring_string_set(pString,mystr);
    ring_string_print(pString);
    /* Set Item 2 */
    pItem = ring_list_getitem(pList,2);
    ring_item_settype(pItem,ITEMTYPE_LIST);
    pList2 = ring_item_getlist(pItem);
    ring_list_newitem(pList2);
    ring_list_newitem(pList2);
    /* Work on items */
    pItem = ring_list_getitem(pList2,1);
    ring_item_settype(pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    sprintf( mystr , "Item (2) Item (1) "  ) ;
    ring_string_set(pString,mystr);
    ring_string_print(pString);
    /* Work on items */
    pItem = ring_list_getitem(pList2,2);
    ring_item_settype(pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    sprintf( mystr , "Item (2) Item (2) "  ) ;
    ring_string_set(pString,mystr);
    ring_string_print(pString);
    /* Set Item 3 */
    pItem = ring_list_getitem(pList,3);
    ring_item_settype(pItem,ITEMTYPE_STRING);
    pString = ring_item_getstring(pItem);
    sprintf( mystr , "last item"  ) ;
    ring_string_set(pString,mystr);
    ring_string_print(pString);
    /* set item 4 */
    pItem = ring_list_getitem(pList,4);
    ring_item_settype(pItem,ITEMTYPE_NUMBER);
    /* set item 5 */
    pItem = ring_list_getitem(pList,5);
    ring_item_settype(pItem,ITEMTYPE_POINTER);
    printf( "Printing list \n  " ) ;
    ring_list_print(pList);
    /* Copy List */
    printf( "\n Copy List1 to List 2 \n  " ) ;
    pList2 = ring_list_new(0);
    ring_list_copy(pList2,pList);
    printf( "\n Printing List 2 \n  " ) ;
    ring_list_print(pList2);
    ring_list_delete(pList2);
    ring_list_delete(pList);
    /* Use list_setstring & list_getstring */
    printf( "\n use ring_list_setstring and ring_list_getstring  \n" ) ;
    pList = ring_list_new(3);
    ring_list_setstring(pList,1,"one");
    ring_list_setstring(pList,2,"two");
    ring_list_setstring(pList,3,"three");
    for ( x = 1 ; x <= 3 ; x++ ) {
        printf( "Item Number %d = %s  \n",x,ring_list_getstring(pList,x) ) ;
    }
    ring_list_delete(pList);
    /* using list_addstring */
    printf( "using ring_list_addstring  \n" ) ;
    pList = ring_list_new(0);
    ring_list_addstring(pList,"item 1");
    ring_list_addstring(pList,"item 2");
    ring_list_addstring(pList,"item 3");
    ring_list_addstring(pList,"item 4");
    ring_list_addstring(pList,"item 5");
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        printf( "Item Number %d = %s  \n",x,ring_list_getstring(pList,x) ) ;
    }
    /* Test Get item */
    printf( "Item Number 1 = %s  \n",ring_list_getstring(pList,1) ) ;
    printf( "Item Number 5 = %s  \n",ring_list_getstring(pList,5) ) ;
    printf( "Item Number 4 = %s  \n",ring_list_getstring(pList,4) ) ;
    printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
    printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
    printf( "Item Number 2 = %s  \n",ring_list_getstring(pList,2) ) ;
    printf( "Item Number 3 = %s  \n",ring_list_getstring(pList,3) ) ;
    ring_list_delete(pList);
    /* Function Pointers */
    pList = ring_list_new(0);
    ring_list_addfuncpointer(pList,ring_list_testfuncpointer);
    puts(" *** Test Function Pointer *** ");
    ring_list_callfuncpointer(pList,1,pList);
    ring_list_delete(pList);
}

void ring_list_testfuncpointer ( void *pPointer )
{
    List *pList  ;
    pList = (List *) pPointer ;
    puts(" Message from a function called by function pointer  ");
    printf( "List Size %d  \n",pList->nSize ) ;
}

void ring_hashtable_test ( void )
{
    HashTable *pHashTable  ;
    char cStr[20]  ;
    int x  ;
    puts("\nRing - HashTable Test");
    pHashTable = ring_hashtable_new();
    puts("\nCreate HashTable Items ");
    /* Add Items */
    ring_hashtable_newnumber(pHashTable,"one",1);
    ring_hashtable_newnumber(pHashTable,"two",2);
    ring_hashtable_newnumber(pHashTable,"three",3);
    ring_hashtable_newnumber(pHashTable,"four",4);
    ring_hashtable_newnumber(pHashTable,"five",5);
    ring_hashtable_newnumber(pHashTable,"six",6);
    ring_hashtable_newnumber(pHashTable,"seven",7);
    ring_hashtable_newnumber(pHashTable,"eight",8);
    ring_hashtable_newnumber(pHashTable,"nine",9);
    ring_hashtable_newnumber(pHashTable,"ten",10);
    ring_hashtable_newpointer(pHashTable,"mypointer",cStr);
    for ( x = 1 ; x <= 100 ; x++ ) {
        sprintf( cStr , "test%d" , x ) ;
        ring_hashtable_newnumber(pHashTable,cStr,x);
    }
    puts("\nPrint HashTable Items ");
    ring_hashtable_print(pHashTable);
    puts("\nFind Items ");
    printf( "\n Item : one - nIndex : %d",ring_hashtable_findnumber(pHashTable,"one") ) ;
    printf( "\n Item : five - nIndex : %d",ring_hashtable_findnumber(pHashTable,"five") ) ;
    printf( "\n Item : two - nIndex : %d",ring_hashtable_findnumber(pHashTable,"two") ) ;
    printf( "\n Item : four - nIndex : %d",ring_hashtable_findnumber(pHashTable,"four") ) ;
    printf( "\n Item : three - nIndex : %d",ring_hashtable_findnumber(pHashTable,"three") ) ;
    ring_hashtable_deleteitem(pHashTable,"three");
    printf( "\n Item : three After Delete - nIndex : %d",ring_hashtable_findnumber(pHashTable,"three") ) ;
    printf( "\n Item : mypointer - pointer : %s ",(char *) ring_hashtable_findpointer(pHashTable,"mypointer") ) ;
    puts("\nDelete HashTable ");
    ring_hashtable_delete(pHashTable);
    puts("\nEnd of HashTable Test ");
}

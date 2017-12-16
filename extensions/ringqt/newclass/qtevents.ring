# Generate C++ Classes for RingQt Events
# To execute : ring qtevents.ring
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

aclasses = [
		[	:name = "GPushButton" ,
			:realname = "QPushButton" ,
			:events = [
					[ 	:signal = "clicked()" ,
						:slot = "clickedSlot()" ,
						:event = "Click"
					]
				  ]
		] 

	    ]

Func Main

	# DocFuncs() bye
	for aClass in aClasses
		GenHeader(aClass)	GenSource(aClass)
	next

Func DocFuncs
	for aClass in aClasses
		see copy("=",50)  + nl
		see aClass[:realname] + " Class " + nl +copy("=",50) +nl
		aEvents  = aClass[:events]
		for aEvent in aEvents
			cEvent = aEvent[:event]
			see "Set" + upper(left(cEvent,1))+substr(cEvent,2)+"Event()" + nl
		next		
		see copy("=",50)  + nl	
	next
	

Func GenHeader aClass

	# Start of code string
	cCode = `
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef <T_HEADER>
#define <T_HEADER>
#include <QApplication>
#include <<T_REALCLASSNAME>>
extern "C" {
#include "ring.h"
}

class <T_CLASSNAME> : public <T_REALCLASSNAME>
{

  Q_OBJECT

  public:

    VM *pVM;

    List *pParaList;

<T_EVENTSATTRIBUTES>

<T_CLASSNAMEMETHOD>(<T_INITPARA>parent,VM *pVM );

<T_CLASSNAMEMETHOD2>();

<T_GETEVENTPARAMETERS>

<T_SETEVENTS>

<T_GETEVENTS>

  public slots:

<T_SLOTS>
};

#endif

`	# End of Code String

	cSpace = copy(" ",4)

	# Set the header name
	cCode = substr(cCode,"<T_HEADER>", upper(aClass[:name])+"_H")

	# Set the class name and the parent class name
	cCode = substr(cCode,"<T_CLASSNAME>", aClass[:name])
	cCode = substr(cCode,"<T_CLASSNAMEMETHOD>", cSpace+aClass[:name])
	cCode = substr(cCode,"<T_CLASSNAMEMETHOD2>", cSpace+"~"+aClass[:name])
	cCode = substr(cCode,"<T_GETEVENTPARAMETERS>", cSpace+"void geteventparameters(void) ;")
	cCode = substr(cCode,"<T_REALCLASSNAME>", aClass[:realname])

	if aClass[:initpara] != NULL
		cCode = substr(cCode,"<T_INITPARA>", aClass[:initpara])
	else
		cCode = substr(cCode,"<T_INITPARA>", "QWidget *")
	ok

	aEvents = aClass[:events]
	cEventsAttributes = "" cSetEvents = ""  cGetEvents = "" cEventsSlots = ""

	for aEvent in aEvents
		# Events Attributes
		cEventsAttributes += cSpace+"char c"+aEvent[:event]+"Event[100];"+nl
		# Set Events
		cSetEvents += cSpace+"void set"+aEvent[:event]+"Event(const char *cStr);"+nl
		# Get Events
		cGetEvents += cSpace+"const char *get"+aEvent[:event]+"Event(void);"+nl
		# Events Slots

		cSlot = aEvent[:slot]
		if aEvent[:slotparafunction] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparafunction]+")")
		ok

		cEventsSlots += cSpace+"void "+cSlot+";"+nl
	Next

	cCode = substr(cCode,"<T_EVENTSATTRIBUTES>", cEventsAttributes)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_GETEVENTS>", cGetEvents)
	cCode = substr(cCode,"<T_SLOTS>", cEventsSlots)

	cFileName = lower(aClass[:name]) + ".h"
	writefile(cFileName,cCode)

Func GenSource aClass

# Start of code string
	cCode = `
/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
extern "C" {
#include "ring.h"
}
#include "<T_HEADER>.h"

<T_CLASSNAME>::<T_CLASSNAME>(<T_INITPARA>parent,VM *pVM)  : <T_REALCLASSNAME>(<T_INITPARAPARENT>parent)
{
	this->pVM = pVM;
	this->pParaList = ring_list_new(0);
<T_CLEAREVENTS>
<T_CONNECT>
}

<T_CLASSNAME>::~<T_CLASSNAME>()
{
	ring_list_delete(this->pParaList);
}

void <T_CLASSNAME>::geteventparameters(void)
{
	void *pPointer;
	pPointer = this->pVM;
	RING_API_RETLIST(this->pParaList);
}


<T_SETEVENTS>
<T_GETEVENTS>
<T_SLOTS>
`	# End of Code String

	# Set the class name and the parent class name
	cCode = substr(cCode,"<T_HEADER>", lower(aClass[:name]))
	cCode = substr(cCode,"<T_CLASSNAME>", aClass[:name])
	cCode = substr(cCode,"<T_REALCLASSNAME>", aClass[:realname])

	if aClass[:initpara] != NULL
		cCode = substr(cCode,"<T_INITPARA>", aClass[:initpara])
	else
		cCode = substr(cCode,"<T_INITPARA>", "QWidget *")
	ok

	if aClass[:initparaparent] != NULL
		cCode = substr(cCode,"<T_INITPARAPARENT>", aClass[:initparaparent])
	else
		cCode = substr(cCode,"<T_INITPARAPARENT>", "")
	ok

	aEvents = aClass[:events]
	cClearEvents = "" cConnect = ""  cSetEvents = " " cGetEvents = " " cSlots = ""

	for aEvent in aEvents

		# Clear Events
		cClearEvents += char(9) + 'strcpy(this->c'+aEvent[:event]+'Event,"");'+nl

		# Connect
		cSlot = aEvent[:slot]
		if aEvent[:slotparaconnect] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparaconnect]+")")
		ok

		cConnect += char(9) + "QObject::connect(this, SIGNAL("+aEvent[:signal]+
				"),this, SLOT("+cSlot+"));"+nl
		# Set Events
		cSetEvents += "
void "+aClass[:name]+"::set"+aEvent[:event]+"Event(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->c"+aEvent[:event]+"Event,cStr);
}" + nl

		# Get Events
		cGetEvents += "
const char *"+aClass[:name]+"::get"+aEvent[:event]+"Event(void)
{
	return this->c"+aEvent[:event]+"Event;
}" + nl

		# Slots
		cSlots += '
void '+aClass[:name]+'::'


		cSlot = aEvent[:slot]
		if aEvent[:slotparafunction] != NULL
			cSlot = substr(cSlot,"()","("+aEvent[:slotparafunction]+")")
		ok

		cSlots += cSlot

		cSlots +='
{
	if (strcmp(this->c'+aEvent[:event]+'Event,"")==0)
		return ;
'
		cSlots += aEvent[:slotparacode]

		cSlots +='
	ring_vm_runcode(this->pVM,this->c'+aEvent[:event]+'Event);
}
'


	Next

	cCode = substr(cCode,"<T_CLEAREVENTS>", cClearEvents)
	cCode = substr(cCode,"<T_CONNECT>", cConnect)
	cCode = substr(cCode,"<T_SETEVENTS>", cSetEvents)
	cCode = substr(cCode,"<T_GETEVENTS>", cGetEvents)
	cCode = substr(cCode,"<T_SLOTS>", cSlots)

	cFileName = lower(aClass[:name]) + ".cpp"
	writefile(cFileName,cCode)

Func WriteFile cFileName,cCode
	See "Writing file : " + cFileName + nl +
	    "Size : " + len(cCode) + " Bytes" + nl
	aCode = str2list(cCode)
	fp = fopen(cFileName,"wb")
	for cLine in aCode
		fwrite(fp,cLine+char(13)+char(10))
	next
	fclose(fp)


Func SlotParaGetNumber 
	return "
		ring_list_deleteallitems(this->pParaList);
		ring_list_adddouble(this->pParaList, (double) p1 ) ;	
	"

Func SlotParaGetPointer cType
	return "
		ring_list_deleteallitems(this->pParaList);
		ring_list_addcpointer(this->pParaList, p1, "+'"'+cType+'"'+" ) ;	
	"
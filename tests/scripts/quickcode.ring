cStr = "ContextMenu
DragEnter
DragLeave
DragMove
Drop
Enter
FocusIn
FocusOut
KeyRelease
Leave
NonClientAreaMouseButtonDblClick
NonClientAreaMouseButtonPress
NonClientAreaMouseButtonRelease
NonClientAreaMouseMove
Move
Resize
WindowActivate
WindowBlocked
WindowDeactivate
WindowStateChange
WindowUnblocked"

aList = str2list(cStr)

/*
for x in aList
	See 'strcpy(this->c'+x+'Event,"");'+nl
next
*/

/*
for x in aList
cCode = '
        else if ((event->type() == QEvent::Close) && (strcmp(this->cCloseEvent,"")!=0) ) {
		this->callCloseEvent();
 		return true;
    	}'
cCode = substr(cCode,"Close",x)
see cCode
next
*/

for x in aList
cCode = '
void GAllEvents::setCloseEvent(const char *cStr)
{
	if (strlen(cStr)<100)
		strcpy(this->cCloseEvent,cStr);
}

void GAllEvents::callCloseEvent(void)
{
	if (strcmp(this->cCloseEvent,"")==0)
		return ;
	ring_vm_runcode(this->pVM,this->cCloseEvent);
}'
cCode = substr(cCode,"Close",x)
see cCode
next

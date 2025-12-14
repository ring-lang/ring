ChangeRingKeyword RingVM_ErrorHandler myErrorHandler
ChangeRingKeyword RingVM_SEE          myPrint

1/0

? "BOOM!"

func myErrorHandler
	
	? "I don't care about errors!"
	? "I will act as they doesn't exist"
	ringvm_passerror()

func myPrint vValue
	
	if vValue = nl ring_see(nl) return ok
	ring_see( "-*{" )
	ring_see( vValue )
	ring_see( "}*-" )

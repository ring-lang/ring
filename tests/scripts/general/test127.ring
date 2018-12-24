? "Start the test!" 

pState = ring_state_init()

ring_state_runcode(pState," ? 'Let us try having an error' ? x")

ring_state_delete(pState)

? ""
? "End of test!"
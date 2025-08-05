? "Start"

pState = ring_state_init()

ring_state_runcode(pState,"? 'Hello from sub Ring VM'")

? "Main - Before Shutdown() in Sub VM"
ring_state_runcode(pState,"? 'Sub - before Shutdown()' shutdown() ? 'Sub - After Shutdown()' ")
? "Main - After Shutdown() in Sub VM"

ring_state_delete(pState) 

? "Done"
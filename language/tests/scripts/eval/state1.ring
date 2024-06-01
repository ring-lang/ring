pState = ring_state_init()
ring_state_runcode(pState,"? 'HELLO WORLD'")
ring_state_runcode(pState,"for t=1 to 10 ? t if t=3 ? :three ok next")
ring_state_delete(pState)

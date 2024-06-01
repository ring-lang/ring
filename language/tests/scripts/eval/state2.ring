pState = ring_state_init()
ring_state_runcode(pState,"? 'HELLO WORLD' class point x y z")
ring_state_runcode(pState,"new point {x=10 y=20 z=30 ? self}")
ring_state_delete(pState)

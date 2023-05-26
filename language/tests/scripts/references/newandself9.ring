new point {
	x=10 y=20 z=30 
	myobj = ref(Self)
	self {
		myobj {
			self {
				? x
				myobj {
					? y
					self {
						? z
						myobj {
							? self
						}
					}
				}
			}
		}
	}
}

class point
	x y z
	myobj
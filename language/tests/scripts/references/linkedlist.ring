n1 = new node { data="one"   }
n2 = new node { data="two"   }
n3 = new node { data="three" }
n4 = new node { data="four"  }
n5 = new node { data="five"  }

n1.pNext = ref(n2)
n2.pNext = ref(n3)
n3.pNext = ref(n4)
n4.pNext = ref(n5)

n5.pPrev = ref(n4)
n4.pPrev = ref(n3)
n3.pPrev = ref(n2)
n2.pPrev = ref(n1)

n3.toTheEnd()
? Copy("=",20)
n3.toTheStart()

class node

	data

	pPrev pNext

	pCurrent

	func toTheEnd

		? data
		pCurrent = pNext
		while isObject(pCurrent)
			? pCurrent.data
			pCurrent = pCurrent.pNext
		end

	func toTheStart

		? data
		pCurrent = pPrev
		while isObject(pCurrent)
			? pCurrent.data
			pCurrent = pCurrent.pPrev
		end
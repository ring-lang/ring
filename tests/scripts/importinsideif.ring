load "stdlib.ring"
package test

if ismainsourcefile() {
	import test
	new one { test() }
}


class one
	func test
		see :wow
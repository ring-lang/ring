load "typehints.ring"

import mypackage 

test()  { main([:one,:two,:three]) }

myclass func test() {
	see "Testing User Types!" + nl
	return new myclass
}

package mypackage {
	public class myclass {
		public static void func main(list args) {
			see "welcome" + nl
			see args
		}
	}
}

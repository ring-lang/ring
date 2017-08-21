load "typehints.ring"

import mypackage 
new myclass { main([]) }

test()

myclass func test() {
	see "Testing User Types!" + nl
}

package mypackage {

	public class myclass {

		public static void func main(list args) {

			see "welcome" + nl
		}

	}

}

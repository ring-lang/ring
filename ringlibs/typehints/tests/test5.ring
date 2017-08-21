load "typehints.ring"

import mypackage 

test()

myclass func test() {
	see "Testing User Types!" + nl
	return new myclass { main([]) }
}

package mypackage {

	public class myclass {

		public static void func main(list args) {

			see "welcome" + nl
		}

	}

}

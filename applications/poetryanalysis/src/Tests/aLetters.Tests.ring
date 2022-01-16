load "..\aLetters.ring"
load "Tests.ring"

Test_IsTashkeel()
Test_IsALetter()
Test_IsAChar()

Func Test_IsTashKeel()
  SetTestTarget("IsTashKeel")
  AssertEqual(1, IsTashKeel(Letters.Sokon), True)
  AssertEqual(2, IsTashKeel(Letters.Aleph), false)
  AssertEqual(3, IsTashKeel(Letters.Kashida), false)
  PassedTest()


Func Test_IsALetter()
  SetTestTarget("IsALetter")
  AssertEqual(1, IsALetter(Letters.Fat7ah), False)
  AssertEqual(2, IsALetter(Letters.Yaa), True)
  AssertEqual(3, IsALetter(Letters.Kashida), False)
  AssertEqual(4, IsALetter(" "), False)
  AssertEqual(5, IsALetter(","), False)
  AssertEqual(6, IsALetter("a"), False)
  PassedTest()


Func Test_IsAChar()
  SetTestTarget("IsAChar")
  AssertEqual(1, IsAChar(Letters.Kasrah), True)
  AssertEqual(2, IsAChar(Letters.AlephLeen), True)
  AssertEqual(3, IsAChar(Letters.Kashida), false)
  AssertEqual(4, IsAChar(" "), False)
  AssertEqual(5, IsAChar(","), False)
  AssertEqual(6, IsAChar("a"), False)
  PassedTest()


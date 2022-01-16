Load "..\aString.ring"
Load "Tests.ring"
# String Class Tests


str = new aString("")
ExpectedValue = "تجربة"
ActualValue = ""

Test_aString_Init()
Test_aString_Text()
Test_aString_ToString()
Test_aString_Length()
Test_aString_Append()
Test_aString_Plus()
Test_aString_Left()
Test_aString_Right()
Test_aString_Mid()
Test_aString_Indexer() 
Test_aString_RemoveTashkeel()
Test_aString_AddTashkeel()
Test_aString_GetWords()
Test_aString_GetLines()
Test_aString_Equals()
Test_aString_Comparison()
Test_aString_IndexOf()
Test_aString_RemoveFirst()
Test_aString_RemoveLast()
Test_aString_Insert()
Test_aString_Remove()
Test_aString_ReadNumberAt()
Test_aString_Split()
Test_aString_ContainsAt()
Test_aString_IsNumeric()

func Assert(testNum)
	AssertEqual(testNum, ExpectedValue, ActualValue)

func Test_aString_Init()
	SetTestTarget("aString.Init")

	str = new aString(ExpectedValue)
	ActualValue = str.text
	Assert(1)

	str2 = new aString(str)
	ActualValue = str2.text 
	Assert(2)
	
	PassedTest()


func Test_aString_Text()
	SetTestTarget("aString.Text")

	str.text = ExpectedValue
	ActualValue = str.text
	Assert(1)
	
	str.text = new aString(ExpectedValue)
	ActualValue = str.Text
	Assert(2)
	
	PassedTest()

	
func Test_aString_ToString()
	SetTestTarget("aString.ToString")

	str.text = ExpectedValue
	ActualValue = str.ToString()
	Assert(1)
	
	PassedTest()


func Test_aString_Length()
	SetTestTarget("aString.Length")

	str.text = ExpectedValue
	AssertEqual(1, len(ExpectedValue), str.Length * 2)
	
	AssertError(func(){str.Length = 0}, 2, "property is not read only")
	PassedTest()

	
func Test_aString_Append() 
	SetTestTarget("aString.Append")

	str.text = ExpectedValue
	str.append(" 1")
	ActualValue = str.text
	AssertEqual(1, ExpectedValue + " 1", ActualValue)
	
	str3 = new aString("1")
	str.append(str3)
	ActualValue = str.text
	AssertEqual(2, ExpectedValue + " 11", ActualValue)
	
	PassedTest()


func Test_aString_Plus()
	SetTestTarget("aString.Plus")

	str.text = ExpectedValue
	str2 = str + " 1"
	AssertEqual(1, ExpectedValue + " 1", str2.text)
	
	str3 = new aString(" 1")
	str2 = str + str3
	AssertEqual(2, ExpectedValue + " 1", str2.text)
	
	str2 = str + " رقم" + str3
	AssertEqual(3, ExpectedValue + " رقم 1", str2.text)
	
	str2 = str + str3 + "1"
	AssertEqual(4, ExpectedValue + " 11", str2.text)
	
	PassedTest()



func Test_aString_Left() 
	SetTestTarget("aString.Left")

	str.text = ExpectedValue
	AssertEqual(1, str.Left(2).Text, "تج")
	AssertEqual(2, str.LeftStr(1), "ت")
	
	PassedTest()


func Test_aString_Right()
	SetTestTarget("aString.Right")
	
	str.text = ExpectedValue
	AssertEqual(1, str.Right(2).Text, "بة")
	AssertEqual(2, str.RightStr(1), "ة")
	
	PassedTest()



func Test_aString_Mid()
	SetTestTarget("aString.Mid")
	
	str.text = ExpectedValue
	ActualValue = str.Mid(2, 2).Text
	AssertEqual(1, ActualValue, "جر")
	

	AssertError(func(){str.Mid(0, 1).Text}, 2, "index < 1")
	AssertError(func(){str.Mid(6, 1).Text}, 3, "index > Length")	
	AssertError(func(){str.Mid(2, 5).Text}, 4, "index + count > Length + 1")
	
	ActualValue = str.MidStr(1, 3)
	AssertEqual(5, ActualValue, "تجر")
	AssertError(func(){str.MidStr(1, 0)}, 6, "count < 1")
	AssertError(func(){str.MidStr(1, 6)}, 7, "count > Length")
	
	PassedTest()
 

func Test_aString_Indexer() 
	SetTestTarget("sString.Indexer")
	
	str.text = ExpectedValue
	AssertEqual(1, str[2], "ج")
	AssertError(func(){str[0]}, 2, "index < 1")
	AssertError(func(){str[6]}, 3, "index > Length")
	AssertError(func(){str["a"]}, 3, "index is not a number")
	AssertEqual(5,  str["2"], "ج")
	
	PassedTest()

func Test_aString_RemoveTashkeel()
	SetTestTarget("aString.RemoveTashkeel")

	str.text = "مُحَمََّدٌ"
	ActualValue = str.RemoveTashkeel()
	AssertEqual(1, ActualValue.Text, "محمد")
	PassedTest()
	
func Test_aString_AddTashkeel()
	SetTestTarget("String.AddTashkeel")
	
	str.text = "محمد"
	ActualValue = str.AddTashkeel("مُفَعَّلٌ")
	AssertEqual(1, ActualValue.Text, "مُحَمَّدٌ")
	
	ActualValue = str.AddTashkeel("مُسْتَفْعِلٌ")
	AssertEqual(2, ActualValue.Text, "مُحْمَدْ")
	
	ActualValue = str.AddTashkeel("مُفَ")
	AssertEqual(3, ActualValue.Text, "مُحَمد")
	
	PassedTest()

func Test_aString_GetWords()
	SetTestTarget("aString.GetWords")
	str.Text = "بسـمِ  اللهِ: الرحمنِ، الرحيم"
	words = str.GetWords()

   AssertEqual(1, Len(words), 4)
	AssertEqual(2, words[1].Text, "بسمِ")
	AssertEqual(3, words[2].Text, "اللهِ")
	AssertEqual(4, words[3].Text, "الرحمنِ")
	AssertEqual(5, words[4].Text, "الرحيم")

	PassedTest()

func Test_aString_GetLines()
	SetTestTarget("aString.GetLines")
	str.Text = "
سطر 1
سطر 2

سطر 3=سطر 4
   
 * سطر 5
 s ss s
"

	lines = str.Getlines()
   AssertEqual(1, Len(lines), 5)
	AssertEqual(2, lines[1].Text, "سطر 1")
	AssertEqual(3, lines[2].Text, "سطر 2")
	AssertEqual(4, lines[3].Text, "سطر 3")
	AssertEqual(5, lines[4].Text, "سطر 4")
	AssertEqual(6, lines[5].Text, " * سطر 5")

   words = lines[5].GetWords()
   AssertEqual(1, Len(words), 1)
	AssertEqual(6, words[1].Text, "سطر")
	PassedTest()


func Test_aString_Equals()
	SetTestTarget("aString.=")
    str.Text = "تجربة"
    AssertEqual(1, str = "تجربة", true)
    AssertEqual(2, str = new aString("تجربة"), true)
    AssertEqual(3, str = "1تجربة", false)
    AssertEqual(4, str = new aString("تجربة1"), false)
    PassedTest()

	 SetTestTarget("aString.!=")
    AssertEqual(1, str != "تجربة", false)
    AssertEqual(2, str != new aString("تجربة"), false)
    AssertEqual(3, str != "1تجربة", true)
    AssertEqual(4, str != new aString("تجربة1"), true)
    PassedTest()

func Test_aString_Comparison()
	SetTestTarget("aString.<=>")
    str.Text = "محمد"
    AssertEqual(1, str > "أحمد", true)
    AssertEqual(2, str > new aString("أحمد"), true)
    AssertEqual(3, str < "أحمد", false)
    AssertEqual(4, str < new aString("أحمد"), false)
    AssertEqual(5, str >= "محمد", true)
    AssertEqual(6, str >= new aString("محمد"), true)
    AssertEqual(7, str <= "محمد", true)
    AssertEqual(8, str <= new aString("محمد"), true)
    PassedTest()

func Test_aString_IndexOf()
	SetTestTarget("aString.IndexOf")
    str.Text = "محمد"
    pos =  str.IndexOf("م", 1)
    AssertEqual(1, pos, 1)
    pos =  str.IndexOf("م", 2)
    AssertEqual(2, pos, 3)
    pos =  str.IndexOf("م", 4)
    AssertEqual(3, pos, 0)
    pos =  str.IndexOf("حم", 1)
    AssertEqual(4, pos, 2)
    pos =  str.IndexOf("مم", 1)
    AssertEqual(5, pos, 0)
    PassedTest()

func Test_aString_RemoveFirst()
	SetTestTarget("aString.RemoveFirst")
    str.Text = "عشرة طلاب"
    AssertEqual(1, str.RemoveFirst(5).Text, "طلاب")
    AssertEqual(2, str.RemoveFirstStr(5), "طلاب")
    PassedTest()

func Test_aString_RemoveLast()
	SetTestTarget("aString.RemoveLast")
    AssertEqual(1, str.RemoveLast(5).Text, "عشرة")
    AssertEqual(2, str.RemoveLastStr(5), "عشرة")
    PassedTest()

Func Test_aString_Insert()
  SetTestTarget("aString.Insert")
  str.Text = "محمد"
  AssertEqual(1, str.Insert("و", 4).Text, "محمود")
  AssertEqual(2, str.Insert("و", 1).Text, "ومحمد")
  AssertEqual(3, str.Insert(Letters.Sokon, 5).Text, "محمدْ")

  AssertEqual(4, str.InsertStr("و", 4), "محمود")
  AssertEqual(5, str.InsertStr("و", 1), "ومحمد")
  AssertEqual(6, str.InsertStr(Letters.Sokon, 5), "محمدْ")
  PassedTest()


Func Test_aString_Remove()
  SetTestTarget("aString.Remove")
  str.Text = "محمد"
  AssertEqual(1, str.Remove("م").Text, "حد")
  AssertEqual(2, str.RemoveStr("ح"), "ممد")
  PassedTest()


Func Test_aString_ReadNumberAt()
  SetTestTarget("aString.ReadNumberAt")
  str.Text = "فصل رقم 12:"
  AssertEqual(1, str.ReadNumberAt(2), "")
  AssertEqual(2, str.ReadNumberAt(4), "")
  AssertEqual(3, str.ReadNumberAt(9), 12)
  AssertEqual(4, str.ReadNumberAt(10), 2)
  PassedTest()


func Test_aString_Split()
  SetTestTarget("aString.Split")
  str.Text = "محمد، أحمد، ، محمود"
  names = str.Split("، ")
  AssertEqual(1, len(names), 3)
  AssertEqual(2, names[1].Text, "محمد")
  AssertEqual(3, names[2].Text, "أحمد")
  AssertEqual(4, names[3].Text, "محمود")

  SetTestTarget("aString.SplitStr")
  str.Text = "محمد،أحمد،،محمود"
  names = str.SplitStr("،")
  AssertEqual(1, len(names), 3)
  AssertEqual(2, names[1], "محمد")
  AssertEqual(3, names[2], "أحمد")
  AssertEqual(4, names[3], "محمود")
  PassedTest()
EndFunc

func Test_aString_ContainsAt()
  SetTestTarget("aString.ContainsAt")
  str.Text = "محمد،محمد"
  AssertEqual(1, str.ContainsAt("محمد", 1), true)
  AssertEqual(2, str.ContainsAt("محمد", 2), false)
  AssertEqual(3, str.ContainsAt("محمد", 6), true)
  AssertEqual(4, str.ContainsAt("محمد", 7), false)

  PassedTest()
EndFunc

Func Test_aString_IsNumeric()
  SetTestTarget("aString.IsNumeric")
  AssertEqual(1, (new aString("152")).IsNumeric(), true)
  AssertEqual(2, (new aString("-152")).IsNumeric(), true)
  AssertEqual(3, (new aString("-")).IsNumeric(), false)
  AssertEqual(4, (new aString("15-2")).IsNumeric(), false)
  AssertEqual(5, (new aString(".152")).IsNumeric(), true)
  AssertEqual(6, (new aString("0.152")).IsNumeric(), true)
  AssertEqual(7, (new aString("-.152")).IsNumeric(), true)
  AssertEqual(8, (new aString("-0.152")).IsNumeric(), true)
  AssertEqual(9, (new aString(".")).IsNumeric(), false)
  AssertEqual(10, (new aString("1.5.2")).IsNumeric(), false)
  AssertEqual(11, (new aString("152.")).IsNumeric(), false)
  PassedTest()
EndFunc

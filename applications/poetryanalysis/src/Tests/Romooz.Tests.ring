Load "..\Romooz.ring"
load "Tests.ring"

TestToString()
TestEshbaa3()

r = new Romooz([
	new aString("محبْبُلْ"),
	new aString("عربيْيتِ"),
	new aString("قالُلْ"),
	new aString("آن"),
	new aString("صرْنَسْ"),
	new aString("تثْناءَنْ"),
	new aString("وفي"),
	new aString("لِسْتثْناءتْ"),
	new aString("تفرْرد"),
	new aString("وفِتْ"),
	new aString("تفرْردتْ"),
	new aString("تميْيز"),
	new aString("لشرْقيْيلْ"),
	new aString("هوى"),
	new aString("فوفْفقْهمْ"),
	new aString("يا"),
	new aString("ألْلاهُو"),
	new aString("ومْنُنِلْ"),
	new aString("لاهُمْمَ"),
	new aString("على"),
	new aString("منِهْ"),
	new aString("تدَوْ"),
	new aString("وآتَوُزْ"),
	new aString("زكاتَ"),
	new aString("وآووْ"),
	new aString("أيْتامَنْ"),
	new aString("وقالو"),
	new aString("حقْقَنْ"),
	new aString("بلْفلاحْ")
], false)


TestHoroof()
TestHoroofFunc()
TestHarakaat()
TestGetOrgHarakaat()


Func TestToString()
	SetTestTarget("ToString")
	r = new Romooz([
			new aString("مثال"),
			new aString("عملي")
		], false)

	AssertEqual(1, r.ToString(), "||0||||0")
	PassedTest()


Func TestEshbaa3()
	SetTestTarget("Eshbaa3")
	r = new Romooz([new aString("مثالْ")], true)
	AssertListEquals(1, r.Harakaat, "||00")
	AssertListEquals(2, r.Horoof, "مثالْ")
	AssertEqual(3, r.Horoof[4], "لْ")


	r = new Romooz([new aString("مثالا")], true)
	AssertListEquals(4, r.Harakaat, "||0|0")
	AssertListEquals(5, r.Horoof, "مثالا")
	AssertEqual(6, r.Horoof[5], "ا")

	r = new Romooz([new aString("مثالُ")], true)
	AssertListEquals(7, r.Harakaat, "||0|0")
	AssertListEquals(8, r.Horoof, "مثالُو")
	AssertEqual(9, r.Horoof[5], "و")

	r = new Romooz([new aString("مثالِ")], true)
	AssertListEquals(10, r.Harakaat, "||0|0")
	AssertListEquals(11, r.Horoof, "مثالِي")
	AssertEqual(12, r.Horoof[5], "ي")

	r = new Romooz([new aString("مثالَ")], true)
	AssertListEquals(13, r.Harakaat, "||0|0")
	AssertListEquals(14, r.Horoof, "مثالَا")
	AssertEqual(15, r.Horoof[5], "ا")

	PassedTest()


func TestHoroof()
	SetTestTarget("Horoof")
	h = r.Horoof
	n = 1
	AssertEqual(n, h[n], "م")
	n++
	AssertEqual(n, h[n], "ح")
	n++
	AssertEqual(n, h[n], "بْ")
	n++
	AssertEqual(n, h[n], "بُ")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ع")
	n++
	AssertEqual(n, h[n], "ر")
	n++
	AssertEqual(n, h[n], "ب")
	n++
	AssertEqual(n, h[n], "يْ")
	n++
	AssertEqual(n, h[n], "ي")
	n++
	AssertEqual(n, h[n], "تِ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ق")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "لُ")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "آ")
	n++
	AssertEqual(n, h[n], "")
	n++
	AssertEqual(n, h[n], "ن")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ص")
	n++
	AssertEqual(n, h[n], "رْ")
	n++
	AssertEqual(n, h[n], "نَ")
	n++
	AssertEqual(n, h[n], "سْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "ثْ")
	n++
	AssertEqual(n, h[n], "ن")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "ءَ")
	n++
	AssertEqual(n, h[n], "نْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "ي")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "لِ")
	n++
	AssertEqual(n, h[n], "سْ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "ثْ")
	n++
	AssertEqual(n, h[n], "ن")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "ء")
	n++
	AssertEqual(n, h[n], "تْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "رْ")
	n++
	AssertEqual(n, h[n], "ر")
	n++
	AssertEqual(n, h[n], "د")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "فِ")
	n++
	AssertEqual(n, h[n], "تْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "رْ")
	n++
	AssertEqual(n, h[n], "ر")
	n++
	AssertEqual(n, h[n], "د")
	n++
	AssertEqual(n, h[n], "تْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "م")
	n++
	AssertEqual(n, h[n], "يْ")
	n++
	AssertEqual(n, h[n], "ي")
	n++
	AssertEqual(n, h[n], "ز")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "ش")
	n++
	AssertEqual(n, h[n], "رْ")
	n++
	AssertEqual(n, h[n], "ق")
	n++
	AssertEqual(n, h[n], "يْ")
	n++
	AssertEqual(n, h[n], "ي")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ه")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "ى")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "فْ")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "قْ")
	n++
	AssertEqual(n, h[n], "ه")
	n++
	AssertEqual(n, h[n], "مْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ي")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "أ")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "هُ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "مْ")
	n++
	AssertEqual(n, h[n], "نُ")
	n++
	AssertEqual(n, h[n], "نِ")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "هُ")
	n++
	AssertEqual(n, h[n], "مْ")
	n++
	AssertEqual(n, h[n], "مَ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ع")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "ى")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "م")
	n++
	AssertEqual(n, h[n], "نِ")
	n++
	AssertEqual(n, h[n], "هْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "دَ")
	n++
	AssertEqual(n, h[n], "وْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "آ")
	n++
	AssertEqual(n, h[n], "")
	n++
	AssertEqual(n, h[n], "تَ")
	n++
	AssertEqual(n, h[n], "وُ")
	n++
	AssertEqual(n, h[n], "زْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ز")
	n++
	AssertEqual(n, h[n], "ك")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "تَ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "آ")
	n++
	AssertEqual(n, h[n], "")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "وْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "أ")
	n++
	AssertEqual(n, h[n], "يْ")
	n++
	AssertEqual(n, h[n], "ت")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "مَ")
	n++
	AssertEqual(n, h[n], "نْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], "ق")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "و")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ح")
	n++
	AssertEqual(n, h[n], "قْ")
	n++
	AssertEqual(n, h[n], "قَ")
	n++
	AssertEqual(n, h[n], "نْ")
	n++
	AssertEqual(n, h[n], " ")
	n++
	AssertEqual(n, h[n], "ب")
	n++
	AssertEqual(n, h[n], "لْ")
	n++
	AssertEqual(n, h[n], "ف")
	n++
	AssertEqual(n, h[n], "ل")
	n++
	AssertEqual(n, h[n], "ا")
	n++
	AssertEqual(n, h[n], "حْ")
	PassedTest()


func TestHoroofFunc()
	SetTestTarget("Horoof()")
	h = r.Horoof([5, 4, 4, 4, 5, 4, 5, 4, 4, 4, 4, 6, 4, 4, 7, 7, 4, 4, 5, 4, 4, 6, 6, 4, 5, 4, 7, 4, 6])
	AssertEqual(1, h[1], "محبْبُلْ")
	AssertEqual(2, h[2], "عربيْ")
	AssertEqual(3, h[3], "يتِ قا")
	AssertEqual(4, h[4], "لُلْ آ")
	AssertEqual(5, h[5], "ن صرْنَسْ")
	AssertEqual(6, h[6], "تثْنا")
	AssertEqual(7, h[7], "ءَنْ وفي")
	AssertEqual(8, h[8], "لِسْتثْ")
	AssertEqual(9, h[9], "ناءتْ")
	AssertEqual(10, h[10], "تفرْر")
	AssertEqual(11, h[11], "د وفِتْ")
	AssertEqual(12, h[12], "تفرْردتْ")
	AssertEqual(13, h[13], "تميْي")
	AssertEqual(14, h[14], "ز لشرْ")
	AssertEqual(15, h[15], "قيْيلْ هوى")
	AssertEqual(16, h[16], "فوفْفقْهمْ")
	AssertEqual(17, h[17], "يا ألْ")
	AssertEqual(18, h[18], "لاهُو")
	AssertEqual(19, h[19], "ومْنُنِلْ")
	AssertEqual(20, h[20], "لاهُمْ")
	AssertEqual(21, h[21], "مَ على")
	AssertEqual(22, h[22], "منِهْ تدَوْ")
	AssertEqual(23, h[23], "وآتَوُزْ")
	AssertEqual(24, h[24], "زكاتَ")
	AssertEqual(25, h[25], "وآووْ")
	AssertEqual(26, h[26], "أيْتا")
	AssertEqual(27, h[27], "مَنْ وقالو")
	AssertEqual(28, h[28], "حقْقَنْ")
	AssertEqual(29, h[29], "بلْفلاحْ")
	PassedTest()
	

func TestHarakaat()
	SetTestTarget("Harakaat()")
	h = r.Harakaat([5, 4, 4, 4, 5, 4, 5, 4, 4, 4, 4, 6, 4, 4, 7, 7, 4, 4, 5, 4, 4, 6, 6, 4, 5, 4, 7, 4, 6])
	AssertEqual(1, h[1], "||0|0")
	AssertEqual(2, h[2], "|||0")
	AssertEqual(3, h[3], "|| |0")
	AssertEqual(4, h[4], "|0 |0")
	AssertEqual(5, h[5], "| |0|0")
	AssertEqual(6, h[6], "|0|0")
	AssertEqual(7, h[7], "|0 ||0")
	AssertEqual(8, h[8], "|0|0")
	AssertEqual(9, h[9], "|0|0")
	AssertEqual(10, h[10], "||0|")
	AssertEqual(11, h[11], "| ||0")
	AssertEqual(12, h[12], "||0||0")
	AssertEqual(13, h[13], "||0|")
	AssertEqual(14, h[14], "| ||0")
	AssertEqual(15, h[15], "|0|0 ||0")
	AssertEqual(16, h[16], "||0|0|0")
	AssertEqual(17, h[17], "|0 |0")
	AssertEqual(18, h[18], "|0|0")
	AssertEqual(19, h[19], "|0||0")
	AssertEqual(20, h[20], "|0|0")
	AssertEqual(21, h[21], "| ||0")
	AssertEqual(22, h[22], "||0 ||0")
	AssertEqual(23, h[23], "||0||0")
	AssertEqual(24, h[24], "||0|")
	AssertEqual(25, h[25], "||0|0")
	AssertEqual(26, h[26], "|0|0")
	AssertEqual(27, h[27], "|0 ||0|0")
	AssertEqual(28, h[28], "|0|0")
	AssertEqual(29, h[29], "|0||00")
	PassedTest()

func TestGetOrgHarakaat()
	SetTestTarget("GetOrgHarakaat")
	h = r.GetOrgHarakaat()
	AssertEqual(1, h[1], "||0|0")
	AssertEqual(2, h[2], "|||0||")
	AssertEqual(3, h[3], "|0|0")
	AssertEqual(4, h[4], "|0|")
	AssertEqual(5, h[5], "|0|0")
	AssertEqual(6, h[6], "|0|0|0")
	AssertEqual(7, h[7], "||0")
	AssertEqual(8, h[8], "|0|0|0|0")
	AssertEqual(9, h[9], "||0||")
	AssertEqual(10, h[10], "||0")
	AssertEqual(11, h[11], "||0||0")
	AssertEqual(12, h[12], "||0||")
	AssertEqual(13, h[13], "||0|0|0")
	AssertEqual(14, h[14], "||0")
	AssertEqual(15, h[15], "||0|0|0")
	AssertEqual(16, h[16], "|0")
	AssertEqual(17, h[17], "|0|0|0")
	AssertEqual(18, h[18], "|0||0")
	AssertEqual(19, h[19], "|0|0|")
	AssertEqual(20, h[20], "||0")
	AssertEqual(21, h[21], "||0")
	AssertEqual(22, h[22], "||0")
	AssertEqual(23, h[23], "||0||0")
	AssertEqual(24, h[24], "||0|")
	AssertEqual(25, h[25], "||0|0")
	AssertEqual(26, h[26], "|0|0|0")
	AssertEqual(27, h[27], "||0|0")
	AssertEqual(28, h[28], "|0|0")
	AssertEqual(29, h[29], "|0||00")
	PassedTest()


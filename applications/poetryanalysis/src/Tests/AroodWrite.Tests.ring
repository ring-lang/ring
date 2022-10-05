Load "..\AroodWrite.ring"
load "Tests.ring"

TestingAroodWrite = true
t = clock()

Test_AroodWrite()
Test_DoAroodWrite()

Func Test_AroodWrite()
	SetTestTarget("AroodWrite")
	words = [
		new aString("محبو"), 
		new aString("العربيةِ"),
		new aString("قالُوا"),
		new aString("الآن"),
		new aString("صرنَا"),
		new aString("استثناءًا"),
		new aString("وفي"),
		new aString("الاستثناء"),
		new aString("التّفرّد"),
		new aString("وفي"),
		new aString("التّفرّد"),
		new aString("التّميّز"),
		new aString("لشرقيّ"),
		new aString("الهوى"),
		new aString("فوفّقهمْ"),
		new aString("يا"),
		new aString("الْلاهُ"),
		new aString("وامنُنْ"),
		new aString("الْلاهُمْمَ"),
		new aString("على"),
		new aString("منْ"),
		new aString("اهتدَوا"),
		new aString("وآتَوا"),
		new aString("الزكاةَ"),
		new aString("وآووْا"),
		new aString("أيتامًا"),
		new aString("وقالوا"),
		new aString("حقًّا"),
		new aString("بالْفلاح")
	]

	AroodWrite(words)
	AssertEqual(1, words[1].Text, "محبُلْ")
	AssertEqual(2, words[2].Text, "عربيتِ")
	AssertEqual(3, words[3].Text, "قالُلْ")
	AssertEqual(4, words[4].Text, "آن")
	AssertEqual(5, words[5].Text, "صرنَسْ")
	AssertEqual(6, words[6].Text, "تثناءَنْ")
	AssertEqual(7, words[7].Text, "وفي")
	AssertEqual(8, words[8].Text, "لِسْتثناءتْ")
	AssertEqual(9, words[9].Text, "تفرْرد")
	AssertEqual(10, words[10].Text, "وفِتْ")
	AssertEqual(11, words[11].Text, "تفرْردتْ")
	AssertEqual(12, words[12].Text, "تميْيز")
	AssertEqual(13, words[13].Text, "لشرقيْيلْ")
	AssertEqual(14, words[14].Text, "هوى")
	AssertEqual(15, words[15].Text, "فوفْفقهمْ")
	AssertEqual(16, words[16].Text, "يا")
	AssertEqual(17, words[17].Text, "ألْلاهُو")
	AssertEqual(18, words[18].Text, "وامنُنِلْ")
	AssertEqual(19, words[19].Text, "لاهُمْمَ")
	AssertEqual(20, words[20].Text, "على")
	AssertEqual(21, words[21].Text, "منِهْ")
	AssertEqual(22, words[22].Text, "تدَوْ")
	AssertEqual(23, words[23].Text, "وآتَوُزْ")
	AssertEqual(24, words[24].Text, "زكاتَ")
	AssertEqual(25, words[25].Text, "وآووْ")
	AssertEqual(26, words[26].Text, "أيتامَنْ")
	AssertEqual(27, words[27].Text, "وقالو")
	AssertEqual(28, words[28].Text, "حقْقَنْ")
	AssertEqual(29, words[29].Text, "بلْفلاح")
	PassedTest()



Func Test_DoAroodWrite()

	SetTestTarget("DoAroodWrite")

	AssertEqual(1, DoAroodWrite(New aString("محمد"), 1).Text, "محمد")
	AssertEqual(2, DoAroodWrite(New aString("و"), 1).Text, "وَ")
	AssertEqual(3, DoAroodWrite(New aString("قلبهُ"), 1).Text, "قلبهُو")
	AssertEqual(4, DoAroodWrite(New aString("قلبهِ"), 1).Text, "قلبهِي")
	AssertEqual(5, DoAroodWrite(New aString("أنا"), 1).Text, "أنا")
	AssertEqual(6, DoAroodWrite(New aString("أناْ"), 1).Text, "أنَ")
	
	AssertEqual(7, DoAroodWrite(New aString("الشّمس"), 1).Text, "أشْشمس")
	AssertEqual(8, DoAroodWrite(New aString("الشّمس"), 2).Text, "اشْشمس")
	AssertEqual(9, DoAroodWrite(New aString("والشّمس"), 1).Text, "وشْشمس")
	AssertEqual(10, DoAroodWrite(New aString("الْشّمس"), 1).Text, "أشْشمس")
	AssertEqual(11, DoAroodWrite(New aString("الْشّمس"), 2).Text, "اشْشمس")
	AssertEqual(12, DoAroodWrite(New aString("وبالْشّمس"), 2).Text, "وبشْشمس")
	AssertEqual(13, DoAroodWrite(New aString("والشمس"), 1).Text, "والشمس")
	AssertEqual(14, DoAroodWrite(New aString("والْشمس"), 1).Text, "وشْشمس")
	
	AssertEqual(15, DoAroodWrite(New aString("الشمس"), 1).Text, "أشْشمس")
	AssertEqual(16, DoAroodWrite(New aString("الشمس"), 2).Text, "اشْشمس")
	AssertEqual(19, DoAroodWrite(New aString("الْشمس"), 1).Text, "أشْشمس")
	AssertEqual(20, DoAroodWrite(New aString("الْشمس"), 2).Text, "اشْشمس")
	
	AssertEqual(21, DoAroodWrite(New aString("التمس"), 1).Text, "ألْتمس")
	AssertEqual(22, DoAroodWrite(New aString("التمس"), 2).Text, "الْتمس")
	AssertEqual(23, DoAroodWrite(New aString("الْتمس"), 1).Text, "ألْتمس")
	AssertEqual(24, DoAroodWrite(New aString("الْتمس"), 2).Text, "الْتمس")
	
	AssertEqual(21, DoAroodWrite(New aString("القمر"), 1).Text, "ألْقمر")
	AssertEqual(22, DoAroodWrite(New aString("القمر"), 2).Text, "الْقمر")
	AssertEqual(23, DoAroodWrite(New aString("الْقمر"), 1).Text, "ألْقمر")
	AssertEqual(24, DoAroodWrite(New aString("الْقمر"), 2).Text, "الْقمر")
	
	AssertEqual(25, DoAroodWrite(New aString("والقمر"), 1).Text, "والقمر")
	AssertEqual(26, DoAroodWrite(New aString("والقمر"), 2).Text, "والقمر")
	AssertEqual(27, DoAroodWrite(New aString("والْقمر"), 1).Text, "ولْقمر")
	AssertEqual(28, DoAroodWrite(New aString("والْقمر"), 2).Text, "ولْقمر")
	
	
	AssertEqual(29, DoAroodWrite(New aString("اصمت"), 1).Text, "إصْمت")
	AssertEqual(30, DoAroodWrite(New aString("اصمت"), 2).Text, "اصْمت")
	AssertEqual(31, DoAroodWrite(New aString("اصْمت"), 1).Text, "إصْمت")
	AssertEqual(32, DoAroodWrite(New aString("اصْمت"), 2).Text, "اصْمت")
	
	AssertEqual(33, DoAroodWrite(New aString("واصمت"), 1).Text, "واصمت")
	AssertEqual(34, DoAroodWrite(New aString("واصمت"), 2).Text, "واصمت")
	AssertEqual(35, DoAroodWrite(New aString("واصْمت"), 1).Text, "وصْمت")
	AssertEqual(36, DoAroodWrite(New aString("واصْمت"), 2).Text, "وصْمت")
	
	AssertEqual(37, DoAroodWrite(New aString("لِلشّمس"), 1).Text, "لشْشمس")
	AssertEqual(38, DoAroodWrite(New aString("للْشمس"), 2).Text, "لشْشمس")
	AssertEqual(39, DoAroodWrite(New aString("ولَلشّمس"), 1).Text, "ولشْشمس")
	AssertEqual(40, DoAroodWrite(New aString("للْشمس"), 1).Text, "لشْشمس")
	AssertEqual(41, DoAroodWrite(New aString("لِلْشّمس"), 2).Text, "لشْشمس")
	AssertEqual(42, DoAroodWrite(New aString("أفللْشّمس"), 2).Text, "أفلشْشمس")
	
	AssertEqual(43, DoAroodWrite(New aString("الشمس"), 1).Text, "أشْشمس")
	AssertEqual(44, DoAroodWrite(New aString("للشمس"), 1).Text, "لشْشمس")
	AssertEqual(45, DoAroodWrite(New aString("للِشمس"), 1).Text, "للِشمس")
	
	AssertEqual(46, DoAroodWrite(New aString("للقمر"), 1).Text, "للْقمر")
	AssertEqual(47, DoAroodWrite(New aString("وللقمر"), 1).Text, "وللْقمر")
	AssertEqual(48, DoAroodWrite(New aString("أوللقمر"), 1).Text, "أوللْقمر")
	AssertEqual(49, DoAroodWrite(New aString("للطْفك"), 1).Text, "للطْفك")
	AssertEqual(50, DoAroodWrite(New aString("وللعّيب"), 1).Text, "وللعْعيب")
	AssertEqual(51, DoAroodWrite(New aString("أوللَيلى"), 1).Text, "أوللَيْلى")
	AssertEqual(52, DoAroodWrite(New aString("للِصّة"), 1).Text, "للِصْصت")
	AssertEqual(53, DoAroodWrite(New aString("للصّبر"), 1).Text, "لصْصبر")
	
	AssertEqual(54, DoAroodWrite(New aString("ذهبوا"), 1).Text, "ذهبو")
	AssertEqual(55, DoAroodWrite(New aString("ذهبُوا"), 1).Text, "ذهبُو")
	AssertEqual(56, DoAroodWrite(New aString("نمَوَا"), 1).Text, "نمَوَا")
	AssertEqual(57, DoAroodWrite(New aString("نمَوا"), 1).Text, "نمَوْ")
	AssertEqual(58, DoAroodWrite(New aString("نموْا"), 1).Text, "نموْ")
	AssertEqual(59, DoAroodWrite(New aString("عدْوا"), 1).Text, "عدْوَا")
	
	AssertEqual(60, DoAroodWrite(New aString("عدُّوا"), 1).Text, "عدْدُو")
	AssertEqual(61, DoAroodWrite(New aString("شدّاد"), 1).Text, "شدْداد")
	AssertEqual(62, DoAroodWrite(New aString("والدنا"), 1).Text, "والدنا")
	AssertEqual(63, DoAroodWrite(New aString("مادّةْ"), 1).Text, "مدْدهْ")
	
	AssertEqual(64, DoAroodWrite(New aString("اتّبع"), 1).Text, "إتْتبع")
	AssertEqual(65, DoAroodWrite(New aString("اتّبع"), 2).Text, "اتْتبع")
	AssertEqual(66, DoAroodWrite(New aString("واتّبع"), 1).Text, "وتْتبع")
	AssertEqual(67, DoAroodWrite(New aString("ادَفع"), 1).Text, "إدَفع")
	AssertEqual(68, DoAroodWrite(New aString("ادَفع"), 2).Text, "ادَفع")
	AssertEqual(69, DoAroodWrite(New aString("ادّخر"), 1).Text, "إدْدخر")
	AssertEqual(70, DoAroodWrite(New aString("وادّخر"), 1).Text, "ودْدخر")
	
	AssertEqual(70, DoAroodWrite(New aString("مسعى"), 1).Text, "مسعى")
	AssertEqual(71, DoAroodWrite(New aString("مسعًى"), 1).Text, "مسعَنْ")
	AssertEqual(72, DoAroodWrite(New aString("مسعىً"), 1).Text, "مسعَنْ")
	AssertEqual(73, DoAroodWrite(New aString("شيئا"), 1).Text, "شيئا")
	AssertEqual(74, DoAroodWrite(New aString("شيئًا"), 1).Text, "شيئَنْ")
	AssertEqual(75, DoAroodWrite(New aString("شيئاً"), 1).Text, "شيئَنْ")
	AssertEqual(76, DoAroodWrite(New aString("وعدًا"), 1).Text, "وعدَنْ")
	AssertEqual(77, DoAroodWrite(New aString("وعدٌ"), 1).Text, "وعدُنْ")
	AssertEqual(78, DoAroodWrite(New aString("وعدٍ"), 1).Text, "وعدِنْ")
	AssertEqual(79, DoAroodWrite(New aString("نموًّا"), 1).Text, "نموْوَنْ")
	AssertEqual(80, DoAroodWrite(New aString("نموّاً"), 1).Text, "نموْوَنْ")
	AssertEqual(81, DoAroodWrite(New aString("نمواً"), 1).Text, "نموَنْ")
	AssertEqual(82, DoAroodWrite(New aString("نموًا"), 1).Text, "نموَنْ")
	AssertEqual(83, DoAroodWrite(New aString("نموَا"), 1).Text, "نموَا")
	AssertEqual(84, DoAroodWrite(New aString("عدوًا"), 1).Text, "عدوَنْ")
	AssertEqual(85, DoAroodWrite(New aString("عدواً"), 1).Text, "عدوَنْ")
	AssertEqual(86, DoAroodWrite(New aString("عدوًّا"), 1).Text, "عدوْوَنْ")
	AssertEqual(87, DoAroodWrite(New aString("عدوّاً"), 1).Text, "عدوْوَنْ")
	AssertEqual(88, DoAroodWrite(New aString("يسعَوا"), 1).Text, "يسعَوْ")

	AssertEqual(89, DoAroodWrite(New aString("الاستفتاء"), 2).Text, "لِسْتفتاء")
	AssertEqual(90, DoAroodWrite(New aString("الاسْتفتاء"), 2).Text, "لِسْتفتاء")
	AssertEqual(91, DoAroodWrite(New aString("الاستفتاء"), 1).Text, "ألِسْتفتاء")
	AssertEqual(92, DoAroodWrite(New aString("الاسْتفتاء"), 1).Text, "ألِسْتفتاء")
	AssertEqual(93, DoAroodWrite(New aString("كالْاسْتفتاء"), 1).Text, "كلِسْتفتاء")

	AssertEqual(94, DoAroodWrite(New aString("وبالْاسْتفتاء"), 2).Text, "وبلِسْتفتاء")
	AssertEqual(95, DoAroodWrite(New aString("للاستفتاء"), 1).Text, "للِسْتفتاء")
	AssertEqual(96, DoAroodWrite(New aString("للاسْتفتاء"), 1).Text, "للِسْتفتاء")
	AssertEqual(97, DoAroodWrite(New aString("وللاسْتفتاء"), 1).Text, "وللِسْتفتاء")
	AssertEqual(98, DoAroodWrite(New aString("والاهْ"), 2).Text, "والاهْ")

	AssertEqual(99, DoAroodWrite(New aString("رحلةْ"), 2).Text, "رحلهْ")
	AssertEqual(100, DoAroodWrite(New aString("رحلة"), 2).Text, "رحلت")
	AssertEqual(101, DoAroodWrite(New aString("الرحلةِ"), 2).Text, "ارْرحلتِ")
	AssertEqual(102, DoAroodWrite(New aString("رحلةٌ"), 2).Text, "رحلتُنْ")

	AssertEqual(103, DoAroodWrite(New aString("التهم"), 1).Text, "ألْتهم")
	AssertEqual(104, DoAroodWrite(New aString("التّهم"), 1).Text, "أتْتهم")

	AssertEqual(104, DoAroodWrite(New aString("لَيالي"), 1).Text, "لَيالي")
	AssertEqual(105, DoAroodWrite(New aString("مشرقَي"), 1).Text, "مشرقَيْ")
	AssertEqual(105, DoAroodWrite(New aString("مشرقِي"), 1).Text, "مشرقِي")
	AssertEqual(106, DoAroodWrite(New aString("مشرقي"), 1).Text, "مشرقي")

	AssertEqual(107, DoAroodWrite(New aString("ناس"), 1).Text, "ناس")
	AssertEqual(108, DoAroodWrite(New aString("وناس"), 1).Text, "وناس")
	AssertEqual(109, DoAroodWrite(New aString("ونّاس"), 1).Text, "ونْناس")
	AssertEqual(110, DoAroodWrite(New aString("الناس"), 1).Text, "أنْناس")
	AssertEqual(111, DoAroodWrite(New aString("والناس"), 1).Text, "والناس")
	AssertEqual(112, DoAroodWrite(New aString("والنّاس"), 1).Text, "ونْناس")
	AssertEqual(113, DoAroodWrite(New aString("ناسٍ"), 1).Text, "ناسِنْ")
	AssertEqual(114, DoAroodWrite(New aString("ناسٌ"), 1).Text, "ناسُنْ")
	AssertEqual(115, DoAroodWrite(New aString("فاس"), 1).Text, "فاس")
	AssertEqual(116, DoAroodWrite(New aString("فاسك"), 1).Text, "فاسك")
	AssertEqual(117, DoAroodWrite(New aString("فاسْ"), 1).Text, "فاسْ")
	AssertEqual(118, DoAroodWrite(New aString("فاسْق"), 1).Text, "فسْق")
	AssertEqual(119, DoAroodWrite(New aString("قالْ"), 1).Text, "قالْ")
	AssertEqual(120, DoAroodWrite(New aString("وقالْ"), 1).Text, "وقالْ")
	AssertEqual(121, DoAroodWrite(New aString("شماليّ"), 1).Text, "شماليْي")
	AssertEqual(122, DoAroodWrite(New aString("اسع"), 1).Text, "إسْع")

	PassedTest()
	? (clock() - t)
	

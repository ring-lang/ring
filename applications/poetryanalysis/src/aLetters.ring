Letters = new LetterNames

Func IsTashkeel(hrf)
    return strcmp(hrf,"ً") >= 0 and strcmp(hrf,"ْ") <= 0 


Func IsALetter(hrf)
    return (strcmp(hrf, "ء") >= 0 and strcmp(hrf, "غ") <= 0 ) or
              (strcmp(hrf, "ف") >= 0 and strcmp(hrf, "ي") <= 0 )
   

Func IsAChar(hrf)
   return IsALetter(hrf) or IsTashkeel(hrf)


class LetterNames
	Kashida = "ـ"
	Sokon = "ْ"
	Shaddah = "ّ"
	Fat7ah = "َ"
	TanweenFat7 = "ً"
	Dammah = "ُ"
	TanweenDamm = "ٌ"
	Kasrah = "ِ"
	TanweenKasr = "ٍ"
	AlephHmz = "أ"
	Aleph = "ا"
	AlephLeen = "ى"
	AlephMaksor = "إ"
	HamzetMadd = "آ"
	Waw = "و"
	Yaa = "ي"
	Lam = "ل"
	Hamzah = "ء"
	Haa = "ه"
	Noon = "ن"
	Shamsiah = ["ت", "ث", "د", "ذ", "ر", "ز", "س", "ش", "ص", "ض", "ط", "ظ", "ن"]

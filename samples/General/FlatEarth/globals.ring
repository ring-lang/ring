# Globals
# المتغيرات العامة

newline = nl

MonaLisa     = null
daVinci      = null
Canvas       = null
ControlPanel = null
myApp        = null
win          = null
oTimer       = null

# أبعاد قابلة للتغيير مع حجم النافذة
W  = 600
H  = 700
CX = 300
CY = 350
ER = 270

# تتبع حجم النافذة للكشف عن التغيير
nLastWinW = 900
nLastWinH = 700

nSunAngle  = 0.0
nMoonAngle = 60.0
nDay       = 79
nMonth     = 1
nYear      = 2026
nSunOrbit  = SUN_ORBIT
nMoonOrbit = MOON_ORBIT
bPaused    = False
nSpeed     = 0.25
btnSpeed   = null

# Moon phase tracking
nMoonPhase = 0  # 0-100 (0=new moon, 50=full moon, 100=new moon)
nMoonDay   = 1   # Day in lunar month (1-30)
nLunarYear = 1447  # Islamic lunar year
# نظام اللغات: 1=English, 2=Arabic, 3=French
nLang    = 1
btnLang      = null
lblTitlePanel  = null
lblDateInfo    = null
lblOrbitInfo   = null
lblMoonPhaseHd = null
lblSelSeason   = null
lblNavigation  = null
lblControls    = null
lblTimeHd      = null
lblClock       = null
lblLocHd       = null
lblCoords      = null
txtLocation    = null

# الموقع الجغرافي الافتراضي (أدرار، الجزائر)
cCityName   = "Adrar, Algeria"
nLatitude   = 27.87
nLongitude  = -0.29

# ترجمات اللغات الثلاث
# [English, Arabic, French]
LANG_TITLE        = ["Flat Earth - Sun & Moon", "الأرض المسطحة - الشمس والقمر", "Terre Plate - Soleil & Lune"]
LANG_CONTROL      = ["Control Panel", "لوحة التحكم", "Panneau de contrôle"]
LANG_DATE_INFO    = ["Date Information:", "معلومات التاريخ:", "Informations de date:"]
LANG_ORBIT_INFO_H = ["Orbit Information:", "معلومات المدار:", "Informations orbitales:"]
LANG_MOON_PHASE_H = ["Moon Phase:", "مرحلة القمر:", "Phase lunaire:"]
LANG_SEL_SEASON_H = ["Select Season:", "اختر الفصل:", "Choisir la saison:"]
LANG_NAV_H        = ["Navigation:", "التنقل:", "Navigation:"]
LANG_CONTROLS_H   = ["Controls:", "التحكم:", "Contrôles:"]
LANG_DATE_INFO    = ["Date Information", "معلومات التاريخ", "Informations de date"]
LANG_DAY          = ["Day", "اليوم", "Jour"]
LANG_MONTH        = ["Month", "الشهر", "Mois"]
LANG_YEAR         = ["Year", "السنة", "Année"]
LANG_SEASON_LBL   = ["Season", "الفصل", "Saison"]
LANG_ORBIT_INFO   = ["Orbit Information", "معلومات المدار", "Informations orbitales"]
LANG_SUN_ORBIT    = ["Sun Orbit", "مدار الشمس", "Orbite solaire"]
LANG_MOON_ORBIT   = ["Moon Orbit", "مدار القمر", "Orbite lunaire"]
LANG_MOON_PHASE   = ["Moon Phase", "مرحلة القمر", "Phase lunaire"]
LANG_PHASE        = ["Phase", "المرحلة", "Phase"]
LANG_LUNAR_DAY    = ["Lunar Day", "اليوم القمري", "Jour lunaire"]
LANG_LUNAR_DATE   = ["Lunar Date", "التاريخ الهجري", "Date lunaire"]
LANG_SEL_SEASON   = ["Select Season", "اختر الفصل", "Choisir la saison"]
LANG_NAV          = ["Navigation", "التنقل", "Navigation"]
LANG_PREV_DAY     = ["Prev Day", "اليوم السابق", "Jour préc."]
LANG_NEXT_DAY     = ["Next Day", "اليوم التالي", "Jour suiv."]
LANG_PREV_MONTH   = ["Prev Month", "الشهر السابق", "Mois préc."]
LANG_NEXT_MONTH   = ["Next Month", "الشهر التالي", "Mois suiv."]
LANG_CONTROLS     = ["Controls", "التحكم", "Contrôles"]
LANG_DAY_NIGHT_ON = ["Day/Night: ON", "ليل/نهار: شغال", "Jour/Nuit: ON"]
LANG_DAY_NIGHT_OFF= ["Day/Night: OFF", "ليل/نهار: مطفأ", "Jour/Nuit: OFF"]
LANG_ORBIT_ON     = ["Orbit Info: ON", "المدار: شغال", "Orbite: ON"]
LANG_ORBIT_OFF    = ["Orbit Info: OFF", "المدار: مطفأ", "Orbite: OFF"]
LANG_MOON_SLOW    = ["Moon: Slow", "القمر: بطيء", "Lune: Lente"]
LANG_MOON_MED     = ["Moon: Medium", "القمر: متوسط", "Lune: Moyenne"]
LANG_MOON_FAST    = ["Moon: Fast", "القمر: سريع", "Lune: Rapide"]
LANG_PAUSE        = ["Pause", "إيقاف", "Pause"]
LANG_RESUME       = ["Resume", "استئناف", "Reprendre"]
LANG_RESET        = ["Reset", "إعادة", "Réinitialiser"]
LANG_SPEED        = ["Speed", "السرعة", "Vitesse"]
LANG_LANG_BTN     = ["AR | FR", "EN | FR", "EN | AR"]

# أسماء الفصول بالثلاث لغات [EN, AR, FR]
SEASONS_EN = ["Winter", "Spring", "Summer", "Autumn"]
SEASONS_AR = ["شتاء", "ربيع", "صيف", "خريف"]
SEASONS_FR = ["Hiver", "Printemps", "Été", "Automne"]

# أسماء الأشهر الميلادية
MONTHS_EN = ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]
MONTHS_AR = ["يناير","فبراير","مارس","أبريل","مايو","يونيو","يوليو","أغسطس","سبتمبر","أكتوبر","نوفمبر","ديسمبر"]
MONTHS_FR = ["Jan","Fév","Mar","Avr","Mai","Jun","Jul","Aoû","Sep","Oct","Nov","Déc"]

# مراحل القمر
PHASE_NEW       = ["New Moon", "محاق", "Nouvelle lune"]
PHASE_WAX_CRES  = ["Waxing Crescent", "هلال متزايد", "Croissant montant"]
PHASE_FIRST_Q   = ["First Quarter", "تربيع أول", "Premier quartier"]
PHASE_FULL      = ["Full Moon", "بدر", "Pleine lune"]
PHASE_LAST_Q    = ["Last Quarter", "تربيع آخر", "Dernier quartier"]
PHASE_WAN_CRES  = ["Waning Crescent", "هلال متناقص", "Croissant décroissant"]

# أسماء الأشهر الهجرية
LUNAR_MONTHS_EN = ["Muharram","Safar","Rabi I","Rabi II","Jumada I","Jumada II","Rajab","Sha'ban","Ramadan","Shawwal","Dhu al-Qi'dah","Dhu al-Hijjah"]
LUNAR_MONTHS_AR = ["محرم","صفر","ربيع الأول","ربيع الآخر","جمادى الأولى","جمادى الآخرة","رجب","شعبان","رمضان","شوال","ذو القعدة","ذو الحجة"]
LUNAR_MONTHS_FR = ["Mouharram","Safar","Rabi I","Rabi II","Joumada I","Joumada II","Rajab","Chaabane","Ramadan","Chawwal","Dhou al-Qi'da","Dhou al-Hijja"]

# أسماء القارات على الخريطة
MAP_LABELS_EN = ["N.Pole","Antarctica","Africa","Europe","Asia","N.America","S.America","Australia","Greenland","Sun","Moon"]
MAP_LABELS_AR = ["القطب الشمالي","أنتاركتيكا","أفريقيا","أوروبا","آسيا","أ.الشمالية","أ.الجنوبية","أستراليا","غرينلاند","الشمس","القمر"]
MAP_LABELS_FR = ["Pôle Nord","Antarctique","Afrique","Europe","Asie","Am. Nord","Am. Sud","Australie","Groenland","Soleil","Lune"]

# شريط العنوان أسفل الخريطة
FOOTER_EN = ["Flat Earth Model - Sun & Moon Motion", "North Pole = center | Antarctica = outer ring"]
FOOTER_AR = ["نموذج الأرض المسطحة - حركة الشمس والقمر", "القطب الشمالي = المركز | أنتاركتيكا = الحلقة الخارجية"]
FOOTER_FR = ["Modèle Terre Plate - Mouvement Soleil & Lune", "Pôle Nord = centre | Antarctique = anneau extérieur"]
bShowDayNight = True  # Show day/night motion
bShowOrbitInfo = True  # Show orbit information
nMoonSpeedFactor = 0.1  # Moon speed factor (0.1 = slower, 1.0 = realistic)
btnDayNight = null
btnOrbitInfo = null
btnMoonSpeed = null
btnMoonInfo = null

# Moon info labels
lblMoonPhase = null
lblMoonDay = null
lblLunarMonth = null
lblSolarDate = null

# Control Panel Variables
lblDay     = null
lblMonth   = null
lblYear    = null
lblSeason  = null
lblSunOrbit = null
lblMoonOrbit = null
btnPause   = null
btnReset   = null
btnPrevDay = null
btnNextDay = null
btnPrevMonth = null
btnNextMonth = null
cbSeason   = null

aStars = [
    [40,20],[105,60],[185,38],[315,15],[475,32],[615,20],[708,68],
    [768,135],[752,238],[762,388],[722,538],[682,638],[588,712],
    [438,752],[288,732],[142,702],[52,642],[12,488],[22,342],[15,192],
    [98,148],[248,98],[398,28],[558,88],[698,168],[758,308],
    [28,418],[78,578],[198,678],[378,768],[548,758],[698,698]
]

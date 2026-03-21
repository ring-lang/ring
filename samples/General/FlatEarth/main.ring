/*
	Application 	: # Flat Earth - Sun & Moon Motion (Main File)
# Flat Earth Model - Sun & Moon Motion (Main File) | نموذج الأرض المسطحة | Modèle Terre Plate - Mouvement Soleil & Lune				
			# Ring Language - lightguilib / qPainter / qPixmap2

	Author		: Khaled ABID
	Date		: 2026.03.20	01.10.1447
*/

load "stdlibcore.ring"
load "lightguilib.ring"

# Load sub-files | تحميل الملفات الفرعية | Charger les sous-fichiers
load "constants.ring"
load "globals.ring"
load "colors.ring"
load "pens_brushes_fonts.ring"
load "functions.ring"

### ── qApp ───────────────────────────────────────────────────────────────────

myApp = new qApp
{
    win = new qWidget()
    {
        setWindowTitle("Flat Earth - Sun & Moon Motion | الأرض المسطحة - حركة الشمس والقمر")
        setGeometry(50, 30, 900, 800)
        setMinimumSize(700, 600)

        # Main Canvas | لوحة الرسم الرئيسية | Canevas principal
        Canvas = new qLabel(win)
        {
            MonaLisa = new qPixMap2(600, 700)
            daVinci  = new qPainter()
            {
                begin(MonaLisa)
            }
            setPixMap(MonaLisa)
            setGeometry(0, 0, 600, 700)
        }

        # Control Panel | لوحة التحكم | Panneau de contrôle
        ControlPanel = new qWidget()
        {
            setParent(win)
            setGeometry(600, 0, 300, 800)
            setStyleSheet("background-color: #0a0a20; color: #ffffff;")

            # --- y=10 : Title ---
            lblTitlePanel = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Control Panel")
                setGeometry(20, 10, 260, 30)
                setStyleSheet("font-size: 16px; font-weight: bold; color: #ffd700;")
            }

            # --- y=50 : Date Information ---
            lblDateInfo = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Date Information:")
                setGeometry(20, 50, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            lblDay = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Day: 1")
                setGeometry(20, 78, 125, 22)
                setStyleSheet("font-size: 12px; color: #ffffff;")
            }

            lblMonth = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Month: 1")
                setGeometry(155, 78, 125, 22)
                setStyleSheet("font-size: 12px; color: #ffffff;")
            }

            lblYear = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Year: 2024")
                setGeometry(20, 103, 125, 22)
                setStyleSheet("font-size: 12px; color: #ffffff;")
            }

            lblSeason = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Season: Winter (شتاء)")
                setGeometry(155, 103, 125, 22)
                setStyleSheet("font-size: 12px; color: #ffd700;")
            }

            # --- y=133 : Orbit Information ---
            lblOrbitInfo = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Orbit Information:")
                setGeometry(20, 133, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            lblSunOrbit = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Sun Orbit: 120")
                setGeometry(20, 161, 125, 22)
                setStyleSheet("font-size: 12px; color: #ffd700;")
            }

            lblMoonOrbit = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Moon Orbit: 190")
                setGeometry(155, 161, 125, 22)
                setStyleSheet("font-size: 12px; color: #c0c0c0;")
            }

            # --- y=191 : Moon Phase ---
            lblMoonPhaseHd = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Moon Phase:")
                setGeometry(20, 191, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            lblMoonPhase = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Phase: New Moon")
                setGeometry(20, 219, 260, 22)
                setStyleSheet("font-size: 12px; color: #ffd700;")
            }

            lblMoonDay = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Lunar Day: 1")
                setGeometry(20, 244, 260, 22)
                setStyleSheet("font-size: 12px; color: #ffffff;")
            }

            lblLunarMonth = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Lunar Date: 1 Muharram (محرم) 1447 H")
                setGeometry(20, 269, 260, 22)
                setStyleSheet("font-size: 12px; color: #c0c0c0;")
            }

            # --- y=299 : Select Season ---
            lblSelSeason = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Select Season:")
                setGeometry(20, 299, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            cbSeason = new qComboBox(ControlPanel)
            {
                setParent(ControlPanel)
                setGeometry(20, 327, 260, 28)
                setStyleSheet("background-color: #1a1a30; color: #ffffff;")
                addItem("Winter (شتاء)", null)
                addItem("Spring (ربيع)", null)
                addItem("Summer (صيف)", null)
                addItem("Autumn (خريف)", null)
                setCurrentIndex(0)
                setCurrentIndexChangedEvent("SetSeason(cbSeason.currentIndex())")
            }

            # --- y=363 : Navigation ---
            lblNavigation = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Navigation:")
                setGeometry(20, 363, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            btnPrevDay = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Previous Day")
                setGeometry(20, 391, 125, 28)
                setStyleSheet("background-color: #2a2a40; color: #ffffff;")
                setClickEvent("PrevDay()")
            }

            btnNextDay = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Next Day")
                setGeometry(155, 391, 125, 28)
                setStyleSheet("background-color: #2a2a40; color: #ffffff;")
                setClickEvent("NextDay()")
            }

            btnPrevMonth = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Prev Month")
                setGeometry(20, 423, 125, 28)
                setStyleSheet("background-color: #2a2a40; color: #ffffff;")
                setClickEvent("PrevMonth()")
            }

            btnNextMonth = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Next Month")
                setGeometry(155, 423, 125, 28)
                setStyleSheet("background-color: #2a2a40; color: #ffffff;")
                setClickEvent("NextMonth()")
            }

            # --- y=459 : Controls ---
            lblControls = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Controls:")
                setGeometry(20, 459, 260, 25)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            btnDayNight = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Day/Night: ON")
                setGeometry(20, 487, 125, 28)
                setStyleSheet("background-color: #2a5a2a; color: #ffffff;")
                setClickEvent("ToggleDayNight()")
            }

            btnOrbitInfo = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Orbit Info: ON")
                setGeometry(155, 487, 125, 28)
                setStyleSheet("background-color: #2a5a2a; color: #ffffff;")
                setClickEvent("ToggleOrbitInfo()")
            }

            btnMoonSpeed = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Moon: Slow")
                setGeometry(20, 519, 125, 28)
                setStyleSheet("background-color: #5a5a2a; color: #ffffff;")
                setClickEvent("ToggleMoonSpeed()")
            }

            btnPause = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Pause")
                setGeometry(155, 519, 125, 28)
                setStyleSheet("background-color: #3a3a50; color: #ffffff;")
                setClickEvent("TogglePause()")
            }

            btnReset = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Reset")
                setGeometry(20, 551, 125, 28)
                setStyleSheet("background-color: #3a3a50; color: #ffffff;")
                setClickEvent("ResetToDay1()")
            }

            btnSpeed = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Speed: 0.25x")
                setGeometry(155, 551, 125, 28)
                setStyleSheet("background-color: #ff6b35; color: #ffffff;")
                setClickEvent("ToggleSpeed()")
            }

            # --- y=587 : Language ---
            LangLabel = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Language | اللغة | Langue:")
                setGeometry(20, 587, 260, 22)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            btnLang = new qPushButton(ControlPanel)
            {
                setParent(ControlPanel)
                setText("AR | FR")
                setGeometry(20, 612, 260, 32)
                setStyleSheet("background-color: #1a3a5a; color: #ffd700; font-size: 13px; font-weight: bold;")
                setClickEvent("ToggleLanguage()")
            }

            # --- y=652 : Time & Location ---
            lblTimeHd = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Time & Location | الوقت والموقع:")
                setGeometry(20, 652, 260, 22)
                setStyleSheet("font-size: 13px; font-weight: bold; color: #87ceeb;")
            }

            lblClock = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("00:00:00")
                setGeometry(20, 677, 260, 28)
                setStyleSheet("font-size: 14px; font-weight: bold; color: #00ff88; background-color: #0a1a0a; padding: 2px 8px;")
            }

            lblLocHd = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Location | الموقع:")
                setGeometry(20, 712, 260, 20)
                setStyleSheet("font-size: 11px; color: #87ceeb;")
            }

            txtLocation = new qLineEdit(ControlPanel)
            {
                setParent(ControlPanel)
                setGeometry(20, 735, 260, 26)
                setStyleSheet("background-color: #1a1a30; color: #ffffff; border: 1px solid #3a3a60; padding: 2px 6px;")
                setText("Adrar, Algeria")
                setPlaceholderText("Enter your city...")
                setEditingFinishedEvent("UpdateLocation()")
            }

            lblCoords = new qLabel(ControlPanel)
            {
                setParent(ControlPanel)
                setText("Lat: 31.62° N  |  Lon: -2.22° W")
                setGeometry(20, 764, 260, 20)
                setStyleSheet("font-size: 10px; color: #888888;")
            }
        }

        oTimer = new qTimer(win)
        {
            setTimeOutEvent("animate()")
            setInterval(40)
            start()
        }

        show()
    }

    UpdateControlPanel()
    UpdateClock()
    UpdateLocation()
    DrawScene()
    exec()
}

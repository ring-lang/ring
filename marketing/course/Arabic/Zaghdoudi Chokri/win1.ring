
load "guilib.ring"

monApp = new QApp {

	# Déclaration
	fonts = [
		:frm = new QFont("Tahoma",14,0,0),
		:lbl = new QFont("Tahoma",11,70,0),
		:txt = new QFont("Tahoma",12,40,0),
		:btn = new QFont("Tahoma",12,70,0)
	]
	css = [
		:txt = "background-color:#aeaeae;
			color:#141414;
			border: 1px solid #33BCFF;
			border-radius:3px;"
	]
	
	cDate = "Nous sommes le: " + date()
	cTime = "Il est " + timeList()[7] + ":" + timelist()[11]
	
	frm = new QWidget() {
		
		# Fonctionnalités principale de la fênêtre
		setWindowTitle("Ma fenêtre 1")
		setGeometry(170,100,700,500)
		setfont(fonts[:frm])
		setstylesheet("
			background-color:#4682B4;
			color:#FFF;
		")
		setwinicon(frm,substr(currentdir(),"\","/")+"/transportation-rings.png")

		# Ajouter des composants
		oLbnHeader = new QLabel(frm) {
			setText("Forme Des Employées - "+cDate+". "+cTime)
			setgeometry(0,3,700,34)
			setFont(new QFont("Impact",14,0,false))
			setAlignment(Qt_AlignHCenter)
		}
		oLbl1 = new QLabel(frm) {
			setText("Label 1:")
			setGeometry(20,50,60,25)
			setfont(fonts[:lbl])
		}
		oLbl2 = new qlabel(frm) {
                        setGeometry(520,430,160,30)
                        setopenexternallinks(true)
                        settext('<a href="https://ring-lang.sourceforge.io/">Ring language</a>')
			setfont(fonts[:lbl])
			setalignment(Qt_AlignHCenter)
                }
		oTxt1 = new QLineEdit(frm) {
			setGeometry(100,50,180,25)
			setfont(fonts[:txt])
			setstylesheet(css[:txt])
		}
		abtns = [
			new qpushbutton(frm) { settext("Nouveau") } ,
                        new qpushbutton(frm) { settext("Modifier") } ,
                        new qpushbutton(frm) { settext("Chercher") } ,
                        new qpushbutton(frm) { 
				settext("Supprimer")
				setclickevent("pressed()") 
			} ,
                        new qpushbutton(frm) { 
				settext("Quitter") setfont(fonts[:btn])
                                setclickevent("monAPP.quit()") 
			}
                ]
                tool1 = new qtoolbar(frm) {
                        for x in abtns 
				addwidget(x) 
				addseparator()
				x.setfont(fonts[:btn]) 
			next
                        setmovable(true)
                        setGeometry(0,460,700,30)
                        setFloatable(true)
                }
		
                CheckBox = new qcheckbox(frm) {
                        setGeometry(100,100,300,30)
                        settext("J'accepte les termes et les conditions")
                       	setfont(fonts[:txt])
 			setclickedEvent("HandleClickEvent()")
                }

		# Afficher la fenêtre
		show()
	}

	# Exécution de l'application
	exec()
}

func HandleClickEvent

    if CheckBox.isChecked() = 1
	CheckBox.settext("Acceptés")
    else
        CheckBox.settext("Non acceptés")
    ok

func pressed
	for x in abtns 
		if x.text() = "Supprimer"
			x.setstylesheet("color:red") 
			x.setText("Êtes-vous sûr!") ok
	next

# Project : CalmoSoft Matching Game
# Date    : 10/04/2020-08:16:58
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"
load "matchinglist.ring"

limit = 3
row1 = -2
row2 = -2
numCountry = 0
numcapital = 0
lenMatching = len(MatchingList)
C_FONTSIZE = 15

Countries = list(lenMatching)
Capitals = list(lenMatching)
SortCountries = list(lenMatching)
SortCapitals = list(lenMatching)
Button1 = list(lenMatching)
Button2 = list(lenMatching)
Button3 = list(limit)
Button4 = list(limit)
Button5 = list(limit)
Button6 = list(limit)
userCountry = []
userCapital = []

for n = 1 to lenMatching
    Countries[n] = MatchingList[n][1]
    Capitals[n] = MatchingList[n][2]
next

SortCountries = sort(Countries)
SortCapitals = sort(Capitals)

randCountry = []

rnd1 = 1:lenMatching
rndCountry = RandomList(rnd1)
for n = 1 to limit
    add(randCountry,rndCountry[n])
next
  
randCapital = RandomList(randCountry)

oApp = New QApp {

       win = new qWidget() {
                 resize(700,900)
                 setwindowtitle("Matching Game")

       for x = 1 to len(Countries)
           Button1[x] = new qPushButton(win) {
                        setgeometry(100,100+(x-1)*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        settext(SortCountries[x])
           } 
       next

       for x = 1 to len(Capitals)
           Button2[x] = new qPushButton(win) {
                        setgeometry(400,100+(x-1)*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        settext(SortCapitals[x])
           } 
       next

       for x = 1 to limit
           Button3[x] = new qPushButton(win) {
                        setgeometry(100,390+x*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        setclickevent("countryClick(" + string(x) + ")")
                        settext(Countries[rndCountry[x]])
           } 
       next

       for x = 1 to limit
           Button4[x] = new qPushButton(win) {
                        setgeometry(400,390+x*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        setclickevent("capitalClick(" + string(x) + ")")
                        settext(Capitals[randCapital[x]])
           } 
       next

       for x = 1 to limit
           Button5[x] = new qPushButton(win) {
                        setgeometry(100,650+(x-1)*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
           } 
       next


       for x = 1 to limit
           Button6[x] = new qPushButton(win) {
                        setgeometry(400,650+(x-1)*40,200,40)
                        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
           } 
       next

     labelCountries = new QLabel(win) {
                          setgeometry(100,60,120,20)
                          setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                          settext("Countries:")
     }

     labelCapitals = new QLabel(win) {
                         setgeometry(400,60,120,20)
                         setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                         settext("Capitals:")
     }

     labelSort = new QLabel(win) {
                     setgeometry(200,380,650,20 )
                     setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                     settext("Countries and Capitals to sort:")
     }

     labelUserSort = new QLabel(win) {
                         setgeometry(300,600,450,20)
                         setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                         settext("Your Sort:")
     }

     buttonCheckSort = new QPushButton(win) {
                           setgeometry(100,820,150,30)
                           setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                           settext("Check Sort")
                           setClickEvent("checkSort()")
     }

     buttonExit = new QPushButton(win) {
                      setgeometry(450,820,150,30)
                      setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                      settext("Exit")
                      setClickEvent("pQuit()")
     }

     buttonNewGame = new QPushButton(win) {
                     setgeometry(275,820,150,30)
                     setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                     settext("New Game")
                     setClickEvent("newGame()")
     }


     show()
     }
     exec()
}

func newGame()

       for x = 1 to limit
           Button5[x].settext("")
       next


       for x = 1 to limit
           Button6[x].settext("")
       next

func pQuit()
     win.close()

func RandomList(aInput)
     aOutput = []
     while len(aInput) > 1
           nIndex = random(len(aInput)-1)
           nIndex = nIndex + 1
           aOutput + aInput[nIndex]
           del(aInput,nIndex)
     end
     aOutput + aInput[1]
     return aOutput

func countryClick(nr1)
     numCountry = numCountry + 1
     if numCountry <= limit
        country = Countries[rndCountry[nr1]]
        Button5[numCountry].settext(country)
        add(userCountry,country)
     else
        return
     ok

func capitalClick(nr2)
     numCapital = numCapital + 1
     if numCapital <= limit
        capital = Capitals[randCapital[nr2]]
        Button6[numCapital].settext(capital)
        add(userCapital,capital)
     else
        return
     ok

func checkSort()
     flag = 1
     if (numCountry != limit) or (numCapital != limit)
         MsgBox("Bad Sort!") 
         return       
     ok
     for n = 1 to limit
         num = find(Countries, userCountry[n])
         if Capitals[num] = userCapital[n]
            flag = 1
         else
            flag = 0
            exit
         ok
     next
     if flag = 1
        MsgBox("Good Sort!")
     else
        MsgBox("Bad Sort!")
     ok

Func MsgBox(cText) 
     mb = new qMessageBox(win) 
	  {
	      setWindowTitle('Matching Game')
	      setText(cText)
              setStandardButtons(QMessageBox_OK)
              result = exec() 
          }
          return
    


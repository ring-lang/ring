Load "guilib.ring"

/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Video-Music-Play.ring
 +     Date         : 2017-07-12
 +     Author       : Bert Mariani
 *                      : Gal Zsolt (~ CalmoSoft ~)
 +     Purpose      : Play Video and Music for in User directories
 +---------------------------------------------------------------------------------------------------------
 +
 +---------------------------------------------------------------------
 +     NEED NEED  NEED *** REQUIRED FILES ***
 +
 +     Codec MUST be already loaded  <<<==
 +     http://www.codecguide.com/download_k-lite_codec_pack_basic.htm
 +
 +     stock.jpg  for Initial Image
 +     stock.mp3  for Initial Music
 +     icons.zip  for Button-Icons -- Play,Pause,Stop,Back,Fwd,Mute.Volume,Vol-Low,Vol-High
 +---------------------------------------------------------------------
*/
dirList   = []   ### Search /Users directories
musicList = []   ### List of Music and Videos found.

fileType  = [".avi", ".mp4", ".mpg", ".mkv", ".wmv", ".mp3", ".wav", ".aac", ".ogg", ".wma", ".flac" ]

FileToPlay = "stock.mp3"
ImageFile  = "stock.jpg"

###-------------------------
### For qListWidget
nbrOfItems    = 1
curItemNbr    = 1
curValue      = "abcdefgh"

SelectedValue = "mnopqrst"
SelectedRow   = 1


###---------------------------------
### Fetch User directory and name
### Limitation: Multibyte name (Japanese
### name, e.g. 野口雨情) is not supported yet.
### 
### Test data: https://en.wikipedia.org/wiki/List_of_Japanese_people

    System("whoami > output.txt")        ### Output User Name data to file
        cYou = read("output.txt")
        cYou = chomp(cYou)
        See "Whoami: "+ cYou +"|"+ nl

    if IsMacOSX()

        ### MAC
        ### /Users/christiane  - whoami
        ### christiane
        ### /Users/christiane/Music  Movies

        youName = cYou
        dirName = "/Users/" + youName

        UserNameDirMusic  = dirName + "/Music/"
        UserNameDirVideos = dirName + "/Movies/"
        UserIcons = CurrentDir() +"/"

    but IsLinux()

        ### LINUX
        ### umberto@umberto ~ $ whoami
        ### umberto
        ### /home/umberto/Videos

        youName = cYou
        dirName = "/home/" + youName

        UserNameDirMusic  = dirName + "/Music/"
        UserNameDirVideos = dirName + "/Videos/"
        UserIcons = CurrentDir() +"/"

    else
        ### WINDOWS
        ### desktop-umberto\umberto

        cLast = 0
        for i = 1 to len(cYou)
            if cYou[i] = "\" ; cLast = i ;  ok
        next

        dirName = substr(cYou, 1, cLast)
        youName = substr(cYou, cLast+1)

        UserNameDirMusic  = "C:\Users\" + youName + "\Music\"
        UserNameDirVideos = "C:\Users\" + youName + "\Videos\"
        UserIcons = CurrentDir() +"\"

    ok

    See UserNameDirMusic  +nl
    See UserNameDirVideos +nl


###------------------------------------------------------
### DRAW MAIN PAGE - CHART  size 1000 x 750
### Place Buttons, Labels, CheckBoxes in their place
###-----------------------------------------------------


###-------------------------------
### Window Size
    WinLeft   = 80                  ### 80    Window position on screen
    WinTop    = 80                  ### 80    Window position on screen
    WinWidth  = 1200                ### 1000  Window Size - Horizontal-X WinWidth
    WinHeight = 750                 ### 750   Window Size - Vertical-Y WinHeight
    WinRight  = WinLeft + WinWidth  ### 1080
    WinBottom = WinTop  + WinHeight ### 830

###----------------------------
### Label1 RIGHT Box Size
    BoxLeft   = 80                  ###  Start corner   Label1 Box Start Position inside WIN1
    BoxTop    = 40                  ###  Start corner
    BoxWidth  = WinWidth  -160      ###  End   corner   Label1 Box Size
    BoxHeight = WinHeight -100      ###  End   corner


###-------------------------------------------
### imageStock Size for growing image

    imageW = 400 ;  imageH = 400 ; GrowBy = 8
    volume = 100

###-------------------------------------------


###==============================================
### QAPP - WIN1
###
### Position of Buttons, DropDown, Actions
###==============================================

MyApp = New qapp
{

    win1 = new qMainWindow()
    {
            ###----------------------------------------------
            ### Position and Size on Screen

            setWinIcon(self,"play.png")
            setwindowtitle("Video and Music Player")
            setgeometry( WinLeft, WinTop, WinWidth, WinHeight)

            ###--------------------------------------------
            ### FILTERS

            myfilter = new qallevents(win1)

                ###------------------------------------------
                ### ReSizeEvent ... Call WhereAreWe function

                myfilter.setResizeEvent( "WhereAreWe()")

            installeventfilter(myfilter)

            ###---------------------------
            ### Draw within this WIN BOX

            label1 = new qlabel(win1)
            {
                setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
                settext("")   ### ("RightBox")
            }


       ###-------------------------
       ### BMP Background
       ### WinWidth   WinHeight


            // This draws GREEN BOX background
            // videowidget = new qVideoWidget(win1)    ### Video Box
            // {
            //    setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
            //    setstylesheet("background-color: green")
            // }

            player = new qMediaPlayer()
            {   ###------------------------
                ### Initial startup music

                if Fexists(FileToPlay)
                    setMedia(new qurl(FiletoPlay))
                else
                    msg = "FileToPlay: -- "+ FileToPlay  +" -- required. Use Music MP3 of your choice"
                    SendMsg(msg)
                ok
            
               videowidget = new qVideoWidget(win1)    ### Insert here -- Video Box
               setVideoOutput(videowidget)
               play()
            }


            LabelMan = new qLabel(win1)
            {
                setgeometry(10,20,80,20)
                settext(theTime())          ### ==>> func
            }


            TimerDuration = new qTimer(win1)
            {
                setinterval(1000)
                settimeoutevent("pTimeDuration()")  ### ==>> func
                start()
            }


            BarMan = new qProgressBar(win1)
            {
                BarWidth = 300
                setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight + 28, BarWidth, 10)        ###  Position X Y, Length, Thickness
                setvalue(1)                     ###  Percent filled
            }

            if Fexists(ImageFile)

                imageStock = new qlabel(win1)
                {
                    image = new qpixmap(ImageFile)
                    AspectRatio = image.width() / image.height()

                    imageW = 400
                    imageH = imageH / AspectRatio

                    setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Size-V, Aspect, Transform

                    PosLeft = (BoxWidth  - imageW ) / 2
                    PosTop  = (BoxHeight - imageH ) / 2
                    setGeometry(PosLeft,PosTop,imageW,imageH)

                }

                TimerMan = new qTimer(win1)
                {
                    setinterval(100)
                    settimeoutevent("pTime()")  ### ==>> func
                    start()
                }

            else
                msg = "ImageFile: -- "+ ImageFile +" -- required. Use an Image JPG of your choice"
                SendMsg(msg)
            ok

            ###===========================================================
            ###===========================================================

            btnVertPos = 20
            btnSize    = 20

            oFont = new qFont("arial",10,0,0)
            setFont( oFont)

            btnPlay = new qpushbutton(win1)    {
                    setGeometry(80, btnVertPos,80,btnSize)
                    settext("Play")
                    seticon(new qicon(new qpixmap(UserIcons +"Play.png")))
                    setclickevent( "player.Play()")
            }

            btnPause = new qpushbutton(win1)    {
                    setGeometry(160,btnVertPos,80,btnSize)
                    settext("Pause")
                    seticon(new qicon(new qpixmap(UserIcons +"Pause.png")))
                    setclickevent( "player.Pause()")
            }


            btnStop = new qpushbutton(win1)    {
                    setGeometry(240,btnVertPos,80,btnSize)
                    settext("Stop")
                    seticon(new qicon(new qpixmap(UserIcons +"Stop.png")))
                    setclickevent( "player.Stop()")
            }


            btnBack = new qpushbutton(win1)    {
                    setGeometry(320,btnVertPos,80,btnSize)
                    settext("Back")
                    seticon(new qicon(new qpixmap(UserIcons +"Backward.png")))
                    setclickevent( "pBackward()")
            }


            btnDur = new qpushbutton(win1)    {
                    setGeometry(400,btnVertPos,140,btnSize)
                    settext("Duration")
                    setclickevent( "pDuration()")
            }

            btnFwd = new qpushbutton(win1)    {
                    setGeometry(540,btnVertPos,80,btnSize)
                    settext("Fwd")
                    seticon(new qicon(new qpixmap(UserIcons +"Forward.png")))
                    setclickevent( "pForward()")
            }

            SliderMan = new qSlider(win1)
            {
                setgeometry(620,btnVertPos+3,140,btnSize-6)
                setOrientation(1)
                setstylesheet("color:red;background-color:cyan;")
                setMinimum(0)
                setMaximum(100)
                setValue(0)
                setsliderReleasedEvent("pSliderReleased()")    ### Released - on Drag -
                setvalueChangedEvent("pSliderTriggered()")       ### Changed  - on Click -
            }

            btnMute = new qpushbutton(win1)    {
                    setGeometry(760,btnVertPos,60,btnSize)
                    settext("Mute")
                    seticon(new qicon(new qpixmap(UserIcons +"Mute.png")))
                    setclickevent( "pMute()")
            }

            btnVolume = new qpushbutton(win1)    {
                setGeometry(820,btnVertPos,60,btnSize)
                settext("V:100")
                seticon(new qicon(new qpixmap(UserIcons +"Volume.png")))
                ### setclickevent( "pVolume()")
            }

            VolumeDec = new qpushbutton(win1)
            {
                setgeometry(880,btnVertPos,60,btnSize)
                settext("Low")
                seticon(new qicon(new qpixmap(UserIcons +"VolumeLow.png")))
                setclickevent( "PVolumeDec()")
            }

            VolumeInc = new qpushbutton(win1)
            {
                setgeometry(940,btnVertPos,60,btnSize)
                settext("High")
                seticon(new qicon(new qpixmap(UserIcons +"VolumeHigh.png")))
                setclickevent( "pVolumeInc()")
            }

            ###===========================================================
            ###===========================================================

            menu1 = new qmenubar(win1)
            {
                sub1 = addmenu("File")
                sub1 {
                        oAction = new qAction(win1)
                        {
                            settext("Music")
                            setstatustip("Open Music File")
                            setclickevent("pMusic()")
                        }
                        addaction(oAction)

                        oAction = new qAction(win1)
                        {
                            settext("Videos")
                            setstatustip("Open Video File")
                            setclickevent("pVideos()")
                        }
                        addaction(oAction)

                        addseparator()

                        oAction = new qaction(win1)
                        oAction.settext("Exit")
                        oAction.setclickevent("myapp.quit()")
                        addaction(oAction)
                     }

            }

            status1 = new qstatusbar(win1)
            {
                showmessage("Ready!",0)
            }

            setmenubar(menu1)
            setmousetracking(true)
            setstatusbar(status1)

            setStyleSheet(" color: black;
                            selection-color: black;
                            selection-background-color:white ;
                         ")


            ###===========================================================
            ###===========================================================

        show()  ### WIN 1

    }

    ###===========================================================
    ###===========================================================

    exec()
}



###=====================================================================================================
###=====================================================================================================

###=====================================================================================================
### FUNCTIONS
###=====================================================================================================




###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
    Rec = win1.framegeometry()

    WinWidth  = Rec.width()             ### 1000 Current Values
    WinHeight = Rec.height()            ### 750

    WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
    WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
    WinRight  = Rec.right()

    BoxWidth  = WinWidth  -160          ###  End   corner   Label1 Box Size
    BoxHeight = WinHeight -80           ###  End   corner

    WinBaseY  = BoxHeight -50           ### WinBaseY Line Bottom  where Price=0

    ###----------------------------------------------------------
    ### Change Box Size

    label1.setgeometry( BoxLeft, BoxTop, BoxWidth, BoxHeight )

    videowidget.setgeometry(BoxLeft +00, BoxTop, BoxWidth, BoxHeight)
    //videowidget.setstylesheet("background-color: green")   //GREEN BOX

return


###=====================================================================================================
###=====================================================================================================
###=====================================================================================================


###-----------------------------------
### Function TimerMan

Func pTime

    ###-----------------
    ### IMAGE


    if imageH >= BoxHeight - 20
        TimerMan.stop()          ### GrowBy
    ok

    imageW += GrowBy
    imageH  = imageW / AspectRatio

    imageStock.setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Size-V, Aspect, Transform

    PosLeft = (WinWidth  - imageW ) / 2
    PosTop  = (WinHeight - imageH ) / 2
    imageStock.setGeometry(PosLeft,PosTop,imageW,imageH)


    ###-----------------------------
    ### PROGRESS BAR and Time

    ### LabelMan.settext(theTime())     ### ==>> func

    Inc   = ceil( 100 / (BoxHeight / GrowBy) )
    Ruler = ceil( (imageH / BoxHeight) * 100 )

    if BarMan.value() >= 98        ### ProgressBar start over.
        BarMan.setvalue(0)
        BarMan.hide()
        LabelMan.hide()


    ok

    BarMan{ setvalue(Ruler) }

return

###-----------------------------------
###  Display Time

Func theTime()
    # See "Time: "+ Time() +nl
    # return "Time: "+ Time()
return  Time()

###-----------------------------------
### Pops every 4 second

Func pTimeDuration()
    Duration()   ### Update Position and duration, BarMan
return

###-----------------------------------


###========================================================
###========================================================
###========================================================

###--------------------

Func Duration()

    cDurValue  = player.duration()
    cPosValue  = player.position()

    cDurTime   = ConvertMilliSec(cDurValue)
    cPosTime   = ConvertMilliSec(cPosValue)

    DurPos = ""+ cPosTime +" / "+ cDurTime
    btnDur.setText(DurPos)

    if cDurValue = 0 ; cDurValue = 100 ; ok    ### Divide by Zero
    Ratio = ceil(cPosValue / cDurValue * 100)

    BarWidth = 300
    BarMan.setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight + 28, BarWidth, 10)
    BarMan.setvalue(Ratio)
    BarMan.show()

    LabelMan.setgeometry( ((WinWidth - BarWidth) / 2) - 120, BoxHeight +23, 120, 20)
    LabelMan.settext(DurPos)
    LabelMan.show()

return

###-------------------------

Func ConvertMilliSec(milliseconds)
    TotalSec = milliseconds / 1000
    Hour     = floor( TotalSec / 3600 )
    Min      = floor( TotalSec / 60 ) - (Hour * 60)
    Sec      = floor( TotalSec % 60 )

    if Hour < 10 ; Hour = "0" + Hour ; ok
    if Min  < 10 ; Min  = "0" + Min  ; ok
    if Sec  < 10 ; Sec  = "0" + Sec  ; ok

    Clock = "" + Hour+":"+ Min +":"+ Sec
    ### See "TotalSec: "+ TotalSec +" >>> "+ Hour +"-"+ Min +"-"+ Sec +" >>> "+ Clock +nl

return Clock

###---------------------

Func pForward

    p1 = player.position() + ( 20 * 1000)

    if p1 > player.duration() ; p1 = 0 ;  ok  ### Loop
    player.setposition(p1)

    ### See "Pfwd: "+ (player.position() /1000 /60) +nl
    Duration()
return

###---------------------

Func pBackward
    p1 = player.position() - ( 20 * 1000)

    if p1 < 0  ; p1 = 0 ; ok
    player.setposition(p1)

    #See "Pbak: "+ (player.position() /1000 /60) +nl
    Duration()
return

###====================================================================
###====================================================================

###-----------------------------
### Slider Dragged and Released

Func pSliderReleased()

   number = SliderMan.value()
   #See "SlideReleased: "+ SliderMan.value() +nl

   cDurValue  = player.duration()
   p1 = cDurValue * number / 100

   player.setposition(p1)
   Duration()

return

###-----------------------------------------------
### Slider Clicked to the Left or Right of Marker

Func pSliderTriggered()

   number = SliderMan.value()
   #See "SlideTriggered: "+ SliderMan.value() +nl

   cDurValue  = player.duration()
   p1 = cDurValue * number / 100

   player.setposition(p1)
   Duration()

###=====================================================================
###=====================================================================

Func pMusic
    new qFileDialog(win1)
    {
        cName = getopenfilename(win1,"Open Music file", UserNameDirMusic, "Music Files(*.mp3 *.mp3 *.wav *.aac *.ogg *.wma *.flac) ;; All Files(*.*) ")
        win1.setwindowtitle(cName)
    }
    FileToPlay = cName
    #See FileToPlay +nl

        imageStock.show()

    player.setMedia( new qurl(FileToplay) )
    player.play()
    SliderMan.setValue(0)
    TimerDuration.start()

return

###------------------

Func pVideos

    new qFileDialog(win1)
    {
        cName = getopenfilename(win1,"Open Video file", UserNameDirVideos, "Video Files(*.avi *.mp4 *.mpg *.mkv *.wmv) ;; Music Files(*mp3) ;; All Files(*.*) ") ###
        win1.setwindowtitle(cName)
    }
    FileToPlay = cName
    #See FileToPlay +nl

        imageStock.hide()  ### clear()

    player.setMedia( new qurl(FileToplay) )
    player.play()
    SliderMan.setValue(0)
    TimerDuration.start()

return

###======================================================================
###======================================================================

###-----------------------------------
### Popup message box

Func SendMsg(msg)

    new qmessagebox(win1)
    {
        setwindowtitle("MessageBox")
        settext(msg )
        setstylesheet("background-color : Yellow")
        show()
    }
return

return

###-----------------------------------
### Remove NewLine chars

Func chomp(cStr)
   cStr = substr(cStr, char(10), "" )
   cStr = substr(cStr, char(13), "" )
return cStr

###-----------------------------------

Func pMute()
    if player.isMuted()
       player.setMuted(false)
    else
       player.setMuted(true)
    ok
return

###-----------------------------------

Func pVolume()
   ### Do nothing. This button is really a Label with an Icon
return

###-----------------------------------
###-----------------------------------

Func pVolumeDec()
    if volume > 0
       volume = volume - 10
       btnVolume.settext("V:" + volume)
       player.setVolume(volume)
    ok
return

###-----------------------------------

Func pVolumeInc()
    if volume < 100
       volume = volume + 10
       btnVolume.settext("V:" + volume)
       player.setVolume(volume)
    ok
return

###--------------------------------------------------------------
### FileType for Music and Video in  C:\Users\name\Music  Videos
###
### fileType = [".avi", ".mp4", ".mpg", ".mkv", ".wmv", ".mp3", ".wav", ".aac", ".ogg", ".wma", ".flac" ]
### UserPath = "C:\Users\Umberto\Videos"    ### <<<== Search this path


###===================================
### Search for Video and Music files
### SearchVideoMusic(UserPath)

Func SearchVideoMusic(UserPath)

    ChDir(UserPath)
    listDir( CurrentDir() )

    for searchDir in dirList      ### search dirList for Music and Videos files
        listDir(searchDir)
    next

    # see nl +nl +"Number of Music: " +len(musicList) +nl +nl
    # see musicList
    # See nl +"Finished" +nl

###==============================
### Find Files in Directory

Func ListDir(dirName)

    ChDir(dirName)

    Try
        myListSub = Dir( CurrentDir() )
    Catch
        ### See "ListDir Catch! " + CurrentDir() +" --- "+ cCatchError +nl      ### <<< Error, Couldn't open the directory
        return
    Done

    for x in myListSub
        if x[2]
            thisDir = x[1]

            if thisDir[1] = "."      ### Ignore dot.name
                # do nothing
            else
                # see nl +"Dir: " + thisDir + nl
                Add( dirList, (CurrentDir() +"\"+  thisDir))  ### <<<== Dir Walk
            ok
        else
            thisFile = x[1]

            ###-------------------------------
            ### Add Music or Video file type

            for thisType in fileType
                if ( substr(thisFile, thisType) )             ### <<<== Type of File from List
                     # see "         File: " + thisFile + nl
                     Add(musicList, (CurrentDir() +"\"+  thisFile))
                ok
            next
        ok
    next
return


###---------------------------------------------------------
### Direction 1=Down 2=Up
### Swap Current Selection with Next Row Down/Up

Func pInsert(Direction)

    list1
    {
        ###---------------
        ### Remove Item

        takeItem(SelectedRow)
        curItemNbr = currentRow()

        if Direction = 1
            if curItemNbr < nbrOfItems -1
                curItemNbr++  ### Down
            ok
        else
            if curItemNbr > 0
               #curItemNbr--  ### Up
            ok
        ok

        ###----------------
        ### Insert Item

        insertItem(curItemNbr, SelectedValue);
        setCurrentRow( curItemNbr, 3)

        nbrOfItems = count()
        curItemNbr = currentRow()
        curValue   = item(list1.currentRow()).text()
    }

return

##============================================================

func pPlay
        curValue   = list1.item(list1.currentRow()).text()
        player.setMedia( new qurl(curValue) )
        player.play()
        return

###===============================================
###===============================================

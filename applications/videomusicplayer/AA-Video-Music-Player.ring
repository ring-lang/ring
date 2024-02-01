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
 +     icons.zip  for Button-Icons -- Play,Pause,Stop,Back,Fwd,Mute.Volume,Vol-Low,Vol-High,PlayList
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


###-------------------------------------------------
### For PlayList
###             SearchVideoMusic(UserPath)
###             UserPath = "C:\Users\Umberto\Music"    ### <<<== Search this path for fileType
###             UserPath = "C:\Users\Umberto\Videos"   ### <<<== Search this path for fileType

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

            ###--------------------------------------
            ### PlayList plays sequential media files


            playlist = new qMediaPlayList()
            {

            /*
                SearchVideoMusic(UserNameDirMusic)
                SearchVideoMusic(UserNameDirVideos)

                for mediaFile in musicList

                    mediaFile = substr(mediaFile, "C:\", "/" )
                    mediaFile = substr(mediaFile, "\"  , "/" )
                    See "MediaFile: |"+ mediaFile +"|" +nl

                    addMedia(new qurl(mediaFile))
                next


                setCurrentIndex(1)
            */
            }



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

            btnPlayList = new qpushbutton(win1)
            {
                setgeometry(1000,btnVertPos,80,btnSize)
                settext("PlayList")
                seticon(new qicon(new qpixmap(UserIcons +"PlayList.png")))
                setclickevent( "pPlayList()")
            }


            ###===========================================================
            ###===========================================================

            menu1 = new qmenubar(win1)
            {
                sub1 = addmenu("Menu-File")
                sub1 {
                        oAction = new qAction(win1)
                        {
                            settext("Music")
                            setcheckable(true)
                            setchecked(true)
                            setstatustip("Open Music File")
                            setclickevent("pMusic()")
                        }
                        addaction(oAction)

                        oAction = new qAction(win1)
                        {
                            settext("Videos")
                            setcheckable(true)
                            setchecked(true)
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

                sub2 = addmenu("PlayList")
                sub2 {
                        oAction = new qAction(win1)
                        {
                            settext("ShowPlayList")
                            setcheckable(true)
                            setchecked(true)
                            setstatustip("Show PlayList")
                            setclickevent("pShowPlayList()")
                        }
                        addaction(oAction)

                        oAction = new qAction(win1)
                        {
                            settext("ImportPlayList")
                            setcheckable(true)
                            setchecked(true)
                            setstatustip("Import PlayList")
                            setclickevent("pImportPlayList()")
                        }
                        addaction(oAction)

                        oAction = new qAction(win1)
                        {
                            settext("SavePlayList")
                            setcheckable(true)
                            setchecked(true)
                            setstatustip("Save PlayList")
                            setclickevent("pSavePlayList()")
                        }
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


    win2 = new qWidget()
    {

        setGeometry(50,50,700,500)

        btnPosX   = 50
        btnHeight = 30

         btnSize    = 30

		oFont = new qFont("arial",11,0,0)
		setFont( oFont)
	
        ###---------------------------------------
        ### listWidget for Playlist manipulation

        list1 = new qListWidget(win2)
        {
            setGeometry(btnPosX, 50, 600, 300)

            UserPath =  UserNameDirMusic
            SearchVideoMusic(UserPath)

            UserPath =  UserNameDirVideos
            SearchVideoMusic(UserPath)

            for fileToAdd in musicList
                fileToAdd = substr(fileToAdd, "C:\", "/" )
                fileToAdd = substr(fileToAdd, "C:/", "/" )
                fileToAdd = substr(fileToAdd, "\"  , "/" )
                additem(fileToAdd)
                playList.addmedia(new qurl(fileToAdd)) 
            next

                setcurrentrow(0,3)      ### Row 0, HiLite 3 - Select-Grey
                win2.setwindowtitle("Items Count : " + count() )
        }

        btnSelect = new qpushbutton(win2)
        {
            setGeometry( btnPosX,320,600,btnHeight)
            settext("MOVE: Select and Click")
			seticon(new qicon(new qpixmap(UserIcons +"Select.png")))
            setclickevent("pSelect()")
        }

        btnDelete = new qpushbutton(win2)
        {
            setGeometry( btnPosX, 360,100,btnHeight)
            settext("Delete Item")
			seticon(new qicon(new qpixmap(UserIcons +"Delete.png")))
            setclickevent("pDelete()")
        }

        btnMoveUp = new qpushbutton(win2)
        {
            setGeometry( btnPosX+100, 360,100,btnHeight)
            settext("Move Up")
			seticon(new qicon(new qpixmap(UserIcons +"Up.png")))
            setclickevent("pMoveUp()")
        }

        btnMoveDown = new qpushbutton(win2)
        {
            setGeometry(btnPosX+200, 360,100,btnHeight)
            settext("Move Down")
			seticon(new qicon(new qpixmap(UserIcons +"Down.png")))
            setclickevent("pMoveDown()")
        }


        btnAdd = new qpushbutton(win2)
        {
            setGeometry(btnPosX+300, 360,100,btnHeight)
            settext("Add Media")
			seticon(new qicon(new qpixmap(UserIcons +"Add.png")))
            setclickevent("pAddMedia()")
        }

        btnDone = new qpushbutton(win2)
        {
            setGeometry(btnPosX+400, 360,100,btnHeight)
            settext("Done")
			seticon(new qicon(new qpixmap(UserIcons +"Done.png")))
            setclickevent("pDone()")
        }

        btnPlay = new qpushbutton(win2)
        {
            setGeometry(btnPosX+500, 360,100,btnHeight)
            settext("Play Item")
			seticon(new qicon(new qpixmap(UserIcons +"Music.png")))
            setclickevent("pPlay()")
        }

        ### show()   ### Do not show listWidget WIN2 at startup
    }

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

###----------------------------------

Func pPlayList

    win2.show()

    /*
        if BarMan.value() = 100
           player.setPlaylist(playlist)
           player.play()
        ok
    */

    player.setPlaylist(playlist)
    player.play()

###===========================================================
##============================================================

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


##============================================================
##============================================================
##============================================================

Func pShowPlayList()
    win2.show()
return

###============================================================
### Read xxx.play = PlayList into "list1 = qWListWidget"

Func pImportPlayList()

    ###-------------------------------------------
    ### Open Dialog - User picks the fileName.play

    new qFileDialog(win2)
    {
        cFileName = getOpenFileName(win2,"Open PlayList", UserPath, "PlayList Files(*.play) ")
    }


    ###--------------------------------------------
    ### Clear playlist so new items can be loaded
    ### Delete all Items from "list1 = listWidget"

    playlist.clear()

    nbrOfItems = list1.count() -1
    list1
    {
        for i = 0 to nbrOfItems
            takeItem(currentrow() )
            #See "itemCount: "+ count() +nl
        next
    }
    ###-----------------------------------------------------------------------
    ### Extract Items from file and Insert to "list1 = listWidget" Items

    readData = read(cFileName)
    lineList = str2List(readData)

    list1
    {
        for fileToAdd in lineList
            fileToAdd = substr(fileToAdd, "C:\", "/" )
            fileToAdd = substr(fileToAdd, "C:/", "/" )
            fileToAdd = substr(fileToAdd, "\"  , "/" )
            additem(fileToAdd)
            playList.addmedia(new qurl(fileToAdd))  
        next

        setcurrentrow(0,3)      ### Row 0, HiLite 3 - Select-Grey
        win2.setwindowtitle("Items Count : " + count() )
    }

    pShowPlayList()

return

###-----------------------------------------------
### PlayList is in the "list1 = qWListWidget"

Func pSavePlayList()

    ###------------------------------------------------
    ### Save Dialog - User picks the file name xxx.play

    new qFileDialog(win2)
    {
        cFileName = getSaveFileName(win2,"Save PlayList", UserPath, "PlayList Files(*.play) ")
    }

    ###----------------------------------------
    ### Extract the "list1 = listWidget" Items

    fp = fopen(cFileName, "wb")

    list1
    {
        for i = 0 to count() -1
            item = list1.item(i).text();

            fwrite(fp, item)
            fwrite(fp, nl)
        next
    }

    fclose(fp)

return


##============================================================
##============================================================

func pDelete()

    ### Remove from PlayList
    list1
    {
        takeItem(currentrow())

        nbrOfItems = count()
        curItemNbr = currentRow()
        curValue   = item(list1.currentRow()).text()
    }

    win2.setWindowTitle("DELETED: " + nbrOfItems +" Cur: " + curItemNbr +" : " + curValue )

###----------------------------------------
### Select highlighted item in PlayList
### Save as SelectedRow and SelectedValue

func pSelect()

    list1
    {
        nbrOfItems    = count()
        curItemNbr    = currentRow()
        curValue      = item(list1.currentRow()).text()

        ###----------------------_
        ### Item Selected to Move

        SelectedValue = item(list1.currentRow()).text()
        SelectedRow   = currentRow()
    }

    btnSelect.setText( "SELECTED: "+ curItemNbr + " : " + curValue )
    win2.setWindowTitle( "SELECTED: " + nbrOfItems +" Cur: " + curItemNbr + " : " + curValue )

return

###======================================================
### Move item in PlayList Down = Increment Row number

Func pMoveDown()

    pSelect()
    list1
    {
        nbrOfItems    = count()
        curItemNbr    = currentRow()
        curValue      = item(list1.currentRow()).text()

        if curItemNbr < nbrOfItems -1
            curItemNbr++
        ok

        setCurrentRow( curItemNbr, 3)
        curValue      = item(list1.currentRow()).text()

    }

    pInsert(1) ### 1=Down 2=Up

return

###-------------------------------------------------
### Move item in PlayList Up = Decrement Row number

Func pMoveUp()

    pSelect()
    list1
    {
        nbrOfItems    = count()
        curItemNbr    = currentRow()
        curValue      = item(list1.currentRow()).text()

        if curItemNbr > 0
           curItemNbr--
        ok

        setCurrentRow( curItemNbr, 3)
        curValue      = item(list1.currentRow()).text()
    }

    pInsert(2)

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

    win2.setWindowTitle("INSERTED: " + nbrOfItems +" Cur: " + curItemNbr +" : " + curValue )

return

###===============================================


func pAddMedia()
    new qFileDialog(win2)
    {
        cName = getOpenFileName(win2,"Open File", UserPath, "Music Files(*.mp3 *.wav *.aac *.ogg *.wma *.flac *.avi *.mp4 *.mpg *.mkv *.wmv) ;; All Files(*.*) ")
        win2.setwindowtitle(cName)
    }

   fileToAdd = cName
   fileToAdd = substr(fileToAdd, "C:\", "/" )
   fileToAdd = substr(fileToAdd, "C:/", "/" )
   fileToAdd = substr(fileToAdd, "\"  , "/" )

    list1
    {
        nbrOfItems = count()
        curItemNbr = currentRow()
        curValue   = item(list1.currentRow()).text()

        insertItem(currentrow(), fileToAdd);
        setCurrentRow( curItemNbr, 3)
    }

    add(musiclist, fileToAdd)

    win2.setWindowTitle( "ADD-Items: " + nbrOfItems +" Cur: " + curItemNbr + " : " + curValue )

return


##============================================================


###--------------------------------------------
### Done. Copy list1 = new qListWidget(win2)
###         playlist = new qMediaPlaylist()

Func pDone()

    list1
    {
        for i = 0 to count() -1
            item = list1.item(i).text();
            #See "Done itemWidget: "+ i  +"/"+ count() +" -- "+ item +nl

            playlist.addMedia(new qurl(item))
        next
    }

    win2.hide()    ### HIDE the listWidget WIN2


return


func pPlay
        curValue   = list1.item(list1.currentRow()).text()
        player.setMedia( new qurl(curValue) )
        player.play()
        return



###===============================================
###===============================================

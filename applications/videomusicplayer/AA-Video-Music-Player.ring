Load "guilib.ring"

/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Video-Music-Play.ring
 +     Date         : 2017-07-12
 +     Author       : Bert Mariani
 +     Purpose      : Play Video and Music for in User directories
 +---------------------------------------------------------------------------------------------------------
 +
 +---------------------------------------------------------------------
 +     NEED NEED  NEED *** REQUIRED FILES ***
 +
 +     Codex MUST be already loaded  <<<==
 +     http://www.codecguide.com/download_k-lite_codec_pack_basic.htm
 +
 +     stock.jpg  for Initial Image
 +     stock.mp3  for Initial Music
 +     mute.png   for Button-Icon -- Mute
 +---------------------------------------------------------------------
*/
dirList   = []   ### Search /Users directories
musicList = []   ### List of Music and Videos found.



fileType  = [".avi", ".mp4", ".mpg", ".mkv", ".wmv", ".mp3", ".wav", ".aac", ".ogg", ".wma", ".flac" ]

FileToPlay = "stock.mp3"
ImageFile  = "stock.jpg"

###---------------------------------
### Fetch User directoty and name

    System("whoami > output.txt")        ### Output User Name  data to file
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
        UserIcons = dirName + "/Icons/"
        
    but IsLinux()  
        
        ### LINUX
        ### umberto@umberto ~ $ whoami
        ### umberto
        ### /home/umberto/Videos

        youName = cYou
        dirName = "/home/" + youName

        UserNameDirMusic  = dirName + "/Music/"
        UserNameDirVideos = dirName + "/Videos/"
        UserIcons = dirName + "/Icons/"
        
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
        UserIcons = "C:\Users\" + youName + "\Icons\"

    ok

    See UserNameDirMusic  +nl
    See UserNameDirVideos +nl


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

            if Fexists(ImageFile)  
            
                imageStock = new qlabel(win1)
                {
                    image = new qpixmap(ImageFile)
                    AspectRatio = image.width() / image.height()

                    imageW = 400
                    imageH = imageH / AspectRatio

                    setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Siz-V, Aspect, Transform

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

            videowidget = new qVideoWidget(win1)    ### Video Box
            {
                setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
                setstylesheet("background-color: green")
            }
            
            player = new QMediaPlayer()
            {   ###------------------------
                ### Initial startup music
                
                if Fexists(FileToPlay)
                    setMedia(new qurl(FiletoPlay))     
                else
                    msg = "FileToPlay: -- "+ FileToPlay  +" -- required. Use Music MP3 of your choice"
                    SendMsg(msg)
                ok
               
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
                setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight + 25, BarWidth, 10)        ###  Position X Y, Length, Thickness
                setvalue(1)                     ###  Percent filled
            }


            ###---------------------------------------
            ### PlayList plats sequential mmedia files


            playlist = new QMediaPlaylist() 
            {
            
                SearchVideoMusic(UserNameDirMusic)  
                SearchVideoMusic(UserNameDirVideos)
                
                for mediaFile in musicList

                    mediaFile = substr(mediaFile, "C:\", "/" )
                    mediaFile = substr(mediaFile, "\"  , "/" )
                    See "MediaFile: |"+ mediaFile +"|" +nl
                    
                    addMedia(new qurl(mediaFile))
                next
                
                setCurrentIndex(1) 
            }  



            ###===========================================================
            ###===========================================================
            
            btnVertPos = 20
            btnSize    = 20

            btnPlay = new qpushbutton(win1)    {
                    setGeometry(80, btnVertPos,100,btnSize)
                    settext("Play")
                    seticon(new qicon(new qpixmap(UserIcons + "play.png")))
                    setclickevent( "player.play()")
            }

            btnPause = new qpushbutton(win1)    {
                    setGeometry(180,btnVertPos,100,btnSize)
                    settext("Pause")
                    seticon(new qicon(new qpixmap(UserIcons + "pause.png")))
                    setclickevent( "player.pause()")
            }


            btnStop = new qpushbutton(win1)    {
                    setGeometry(280,btnVertPos,100,btnSize)
                    settext("Stop")
                    seticon(new qicon(new qpixmap(UserIcons + "stop.png")))
                    setclickevent( "player.stop()")
            }


            btnBack = new qpushbutton(win1)    {
                    setGeometry(380,btnVertPos,100,btnSize)
                    settext("<<< Back")
                    seticon(new qicon(new qpixmap(UserIcons + "backward.png")))
                    setclickevent( "Backward()")
            }


            btnDur = new qpushbutton(win1)    {
                    setGeometry(480,btnVertPos,130,btnSize)
                    settext("Duration")
                    setclickevent( "Duration()")
            }

            btnFwd = new qpushbutton(win1)    {
                    setGeometry(610,btnVertPos,100,btnSize)
                    settext("Fwd >>>")
                    seticon(new qicon(new qpixmap(UserIcons + "forward.png")))
                    setclickevent( "Forward()")
            }           

            SliderMan = new qSlider(win1) 
            {
                setgeometry(710,btnVertPos,140,btnSize)  
                setOrientation(1)
                setstylesheet("color:black;background-color:#00ffff;")
                setMinimum(0)
                setMaximum(100)
                setValue(0)  
                setsliderReleasedEvent("SliderReleased()")    ### Released - on Drag -
                setvalueChangedEvent("SliderTriggered()")       ### Changed  - on Click -
            }

            btnMute = new qpushbutton(win1)    {
                    setGeometry(850,btnVertPos,50,btnSize)
                    settext("Mute")
                    seticon(new qicon(new qpixmap(UserIcons + "mute.png")))
                    setclickevent( "mute()")
            }

            btnVolume = new qpushbutton(win1)    {
                setGeometry(900,btnVertPos,60,btnSize)
                settext("Vol: 100")
                setclickevent( "volume()")
            }

            VolumeDec = new qpushbutton(win1)
            {
                setgeometry(950,btnVertPos,50,btnSize)
                settext("<<<") 
                setclickevent( "volumeDec()")
            }

            VolumeInc = new qpushbutton(win1)
            {
                setgeometry(1000,btnVertPos,50,btnSize)
                settext(">>>") 
                setclickevent( "volumeInc()")
            }

            btnPlayList = new qpushbutton(win1)
            {
                setgeometry(1050,btnVertPos,50,btnSize)
                settext("Play List") 
                setclickevent( "playList()")
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


        ###--------------------------------------------------------
        ###See "Show-setup " +nl

        show()

    }

    #See "Exec-setup " +nl
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
    videowidget.setstylesheet("background-color: green")

return


###=====================================================================================================
###=====================================================================================================
###=====================================================================================================


###-----------------------------------
### Fuction TimerMan

Func pTime

    ###-----------------
    ### IMAGE


    if imageW >= BoxWidth - GrowBy
        TimerMan.stop()          ### GrowBy
    ok

    imageW += GrowBy
    imageH  = imageW / AspectRatio

    imageStock.setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Siz-V, Aspect, Transform

    PosLeft = (WinWidth  - imageW ) / 2
    PosTop  = (WinHeight - imageH ) / 2
    imageStock.setGeometry(PosLeft,PosTop,imageW,imageH)


    ###-----------------------------
    ### PROGRESS BAR and Time

    LabelMan.settext(theTime())     ### ==>> func

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
    #See "Time: "+ Time() +nl
    #return "Time: "+ Time()
return  Time()

###-----------------------------------
### Pops every 4 second

Func pTimeDuration()
    Duration()   ### Update Postion and duration, BarMan
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
    BarMan.setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight+25, BarWidth, 10) 
    BarMan.setvalue(Ratio)
    BarMan.show()
     
    LabelMan.setgeometry( ((WinWidth - BarWidth) / 2) - 120, BoxHeight+20, 120, 20) 
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

Func Forward

    p1 = player.position() + ( 20 * 1000)

    if p1 > player.duration() ; p1 = 0 ;  ok  ### Loop
    player.setposition(p1)

    #See "Pfwd: "+ (player.position() /1000 /60) +nl
    Duration()
return

###---------------------

Func Backward
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

Func SliderReleased()

   number = SliderMan.value()
   #See "SlideReleased: "+ SliderMan.value() +nl

   cDurValue  = player.duration()
   p1 = cDurValue * number / 100

   player.setposition(p1)
   Duration()

return

###-----------------------------------------------
### Slider Clicked to the Left or Right of Marker

Func SliderTriggered()

   number = SliderMan.value()
   #See "SlideTriggered: "+ SliderMan.value() +nl

   cDurValue  = player.duration()
   p1 = cDurValue * number / 100

   player.setposition(p1)
   Duration()

###=====================================================================
###=====================================================================

Func pMusic
    new qfiledialog(win1)
    {
        cName = getopenfilename(win1,"Open Music file", UserNameDirMusic, "Music Files(*.mp3 *.mp3 *.wav *.aac *.ogg *.wma *.flac) ;; All Files(*.*) ")
        win1.setwindowtitle(cName)
    }
    FileToPlay = cName
    See FileToPlay +nl

    if Fexists(ImageFile)
        imageStock.show()
    ok
    
    player.setMedia( new qurl(FileToplay) )
    player.play() 
    SliderMan.setValue(0)        
    TimerDuration.start()

return

###------------------

Func pVideos

    new qfiledialog(win1)
    {
        cName = getopenfilename(win1,"Open Video file", UserNameDirVideos, "Video Files(*.avi *.mp4 *.mpg *.mkv *.wmv) ;; Music Files(*mp3) ;; All Files(*.*) ") ###
        win1.setwindowtitle(cName)
    }
    FileToPlay = cName
    See FileToPlay +nl

    if Fexists(ImageFile)
        imageStock.hide()  ### clear()
    ok
    
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

Func mute()
    if player.isMuted()
       player.setMuted(false)
    else  
       player.setMuted(true)
    ok
return

###-----------------------------------

Func volumeDec()
    if volume > 0
       volume = volume - 10
       btnVolume.settext("Vol: " + volume)
       player.setVolume(volume)
    ok
return

###-----------------------------------

Func volumeInc()
    if volume < 100
       volume = volume + 10
       btnVolume.settext("Vol: " + volume)
       player.setVolume(volume)
    ok
return           

###----------------------------------

Func playList
    if BarMan.value() = 100
       player.setPlaylist(playlist) 
       See playlist
       player.play()
    ok

###===========================================================
##============================================================
    
###--------------------------------------------------------------
### FileType for Music and Video in  CL\Users\name\Music  Videos
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

    
    see nl +nl +"Number of Music: " +len(musicList) +nl +nl
    see musicList
    See nl +"Finished" +nl

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

###===============================================
###===============================================  

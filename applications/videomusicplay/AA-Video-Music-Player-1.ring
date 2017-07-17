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
 +---------------------------------------------------------------------
*/

FileToPlay = "stock.mp3"
ImageFile  = "stock.jpg"

### fileType  = [".avi", ".mp4", ".mpg", ".mkv", ".wmv", ".mp3", ".wav", ".aac", ".ogg", ".wma", ".flac" ]

###---------------------------------
### Fetch User directoty and name

System("whoami > output.txt")        ### Output User Name  data to file
cYou = read("output.txt")
cYou = chomp(cYou)
See "Whoami: "+ cYou +"|"+ nl

if IsLinux()  ### Returns 1 for Linux
    
    ### umberto@umberto ~ $ whoami
    ### umberto
    ### /home/umberto/Videos

    youName = cYou
    dirName = "/home/" + youName

    UserNameDirMusic  = dirName + "/Music/"
    UserNameDirVideos = dirName + "/Videos/"

else
    ### Windows
    ### desktop-umberto\umberto

    cLast = 0
    for i = 1 to len(cYou)
        if cYou[i] = "\" ; cLast = i ;  ok
    next
    
    dirName = substr(cYou, 1, cLast)
    youName = substr(cYou, cLast+1)

    UserNameDirMusic  = "C:\Users\" + youName + "\Music\"
    UserNameDirVideos = "C:\Users\" + youName + "\Videos\"
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
    BoxHeight = WinHeight -100       ###  End   corner


###-------------------------------------------
### imageStock Size for growing image

    imageW = 400 ;  imageH = 400 ; GrowBy = 8

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

            LabelMan = new qLabel(win1)
            {
                setgeometry(00,20,80,20)
                settext(theTime())          ### ==>> func
            }

            TimerMan = new qTimer(win1)
            {
                setinterval(100)
                settimeoutevent("pTime()")  ### ==>> func
                start()
            }


            TimerDuration = new qTimer(win1)
            {
                setinterval(1000)
                settimeoutevent("pTimeDuration()")  ### ==>> func
                #start()
            }


            BarMan = new qProgressBar(win1)
            {   
                BarWidth = 300
                setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight + 25, BarWidth, 10)        ###  Position X Y, Length, Thickness
                setvalue(25)                     ###  Percent filled
            }


            SliderMan = new qSlider(win1) 
            {
                setgeometry(710,20,140,20)  ###(10, BoxHeight + 25, 100, 20)
                setOrientation(1)
                setstylesheet("color:black;background-color:#00ffff;")
                setMinimum(0)
                setMaximum(100)
                setValue(1)  
                setsliderReleasedEvent("SliderReleased()")
            }
    
            ###----------------------------------

            videowidget = new qVideoWidget(win1)    ### Video Box
            {
                setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
                setstylesheet("background-color: green")
            }

            player = new QMediaPlayer()
            {
                setMedia(new qurl(FiletoPlay))     ### Initial startup music
                setVideoOutput(videowidget)
                play()
            }



           ###===========================================================
           ###===========================================================


                btnPlay = new qpushbutton(win1)    {
                        setGeometry(80,10,100,30)
                        settext("Play")
                        setclickevent( "player.play()")
                }

                btnPause = new qpushbutton(win1)    {
                        setGeometry(180,10,100,30)
                        settext("Pause")
                        setclickevent( "player.pause()")
                }


                btnStop = new qpushbutton(win1)    {
                        setGeometry(280,10,100,30)
                        settext("Stop")
                        setclickevent( "player.stop()")
                }


                btnBack = new qpushbutton(win1)    {
                        setGeometry(380,10,100,30)
                        settext("<<< Back")
                        setclickevent( "Backward()")
                }

                btnFwd = new qpushbutton(win1)    {
                        setGeometry(480,10,100,30)
                        settext("Fwd >>>")
                        setclickevent( "Forward()")
                }

                btnDur = new qpushbutton(win1)    {
                        setGeometry(580,10,130,30)
                        settext("Duration")
                        setclickevent( "Duration()")
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
                        background: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 );
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
    
    if cDurValue = 0 ; cDurValue = 100 ; ok
    Ratio = ceil(cPosValue / cDurValue * 100)


    BarWidth = 300
    BarMan.setGeometry( ((WinWidth - BarWidth) / 2), BoxHeight+25, BarWidth, 10) 
    BarMan.setvalue(Ratio)
    BarMan.show()
     
    LabelMan.setgeometry( ((WinWidth - BarWidth) / 2) - 120, BoxHeight+20, 120, 20) 
    LabelMan.settext(DurPos) 
    LabelMan.show()

    SliderMan.setvalue(Ratio)


    if Ratio = 100
       TimerDuration.stop()
    ok
    
    #player.setVolume(95)
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

Func SliderReleased()

   number = SliderMan.value()
   #See "SlideReleased: "+ SliderMan.value() +nl

   cDurValue  = player.duration()
   p1 = cDurValue * number / 100

   #See "cDur: "+ cDurValue +" p1 "+ p1 +nl

   player.setposition(p1)
   Duration()

return


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

    imageStock.show()
    
    player.setMedia( new qurl(FileToplay) )
    player.play() 
        
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

    imageStock.hide()  ### clear()

    player.setMedia( new qurl(FileToplay) )
    player.play()   

    TimerDuration.start()
return

###======================================================================
###======================================================================

###-----------------------------------
### Popup message box

Func SendMsg(msg)
    MessageBox( msg )
return

###-----------------------------------
### Remove NewLine chars

Func chomp(cStr)
   cStr = substr(cStr, char(10), "" )
   cStr = substr(cStr, char(13), "" )   
return cStr

###----------------------------------


























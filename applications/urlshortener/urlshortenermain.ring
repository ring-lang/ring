load "guilib.ring"
load "stdlibcore.ring"
load "sqlitelib.ring"
load "urlshortenersqliteclass.ring"
load "urlshortenersqlbuilderclass.ring"
load "urlshortenerdeclarations.ring"
load "urlshortenereventfunctions.ring"
load "urlshortenerfunctions.ring"
load "urlshortenerxmlhandlers.ring"

/*
 * Author: John Storm 
 * AT: siensystem@gmail.com
 * For the Ring Programming Language
 */

/* Sample URL: 
 * https://github.com/ring-lang/ring
 * Returns: https://goo.gl/xeCf9G
 */

/*
 * Reference: https://developers.google.com/url-shortener/v1/
 * Insert: https://developers.google.com/url-shortener/v1/url/insert
 * Get: https://developers.google.com/url-shortener/v1/url/get
 * List: https://developers.google.com/url-shortener/v1/url/list
 */

/*
 * ----- Globals -----
 * NetWorkAccessManager
 * SqlBuilder
 */
chdir(currentdir())
qnetacessmgr = new qnetworkaccessmanager(new qobject())
sqlbuilder = new mysqlbuilder{
	table = dbtable[:history]
	content = dbcontent
}
 // start
mywin = new qapp{
	/*
	 * Create a container MainWindow
	 */
	mymainwindow = new qmainwindow(){
		/*
		 * Set the MainWindow Icon & Title
		 */
		setwindowicon(new qicon(new qpixmap(app[:windowicon])))
		setwindowtitle(app[:windowtitle])
		/*
		 * Set MainWindow Fixed Width and Height
		 */
		setfixedwidth(windowscreen[:width])
		setfixedheight(windowscreen[:height])
		/*
		 * Create a Menu for our MainWindow
		 */
		mymenu = new qmenubar(mymainwindow){
			/*
			 * Setup the Help Menu Option with About selection option
			 */
			submenu = addmenu(menu[:help]){
				action = new qaction(mymainwindow){
					settext(menuaction[:about] + " " + app[:windowtitle])
					setclickevent(events[:fabout])
				}
				addaction(action)
			}
		}
		/*
		 * Create and set the status bar status bar
		 */
		statusbar = new qstatusbar(mymainwindow){
			setsizegripenabled(false)
		}
		setstatusbar(statusbar)
		/*
		 * Create a tab page with contents for URL Shortening facilities
		 */
		urlshortenpage = new qwidget() {
			/*
			 * Input Label
			 */
			longurllabel = new qlabel(urlshortenpage){settext(qlabels[:url2short])}
			/*
			 * Edit/Input Field
			 */
			longurledit = new qlineedit(urlshortenpage){}
			/*
			 * Submit button
			 */
			longurlsubmit = new qpushbutton(urlshortenpage){settext(bactions[:shorten]) setclickevent(events[:fshortenurl])}
			/*
			 * Response label
			 */
			shorturllabel = new qlabel(urlshortenpage){settext(qlabels[:shorturl])}
			/*
			 * Response field set with default options
			 */
			qtextedit1 = new qtextedit(urlshortenpage){}
			qtextedit1.setreadonly(true)
			qtextedit1.settextinteractionflags(4|8)
			/*
			 * Load the history to the edit field, if set
			 */
			value = xmlopenread(filenames[:settingsfilename], xmlcontent[:settingselement])
			if value = "on"
				fgethistoryui()
				statusbar.showmessage(statusbarmessages[:stateready], 0)
			ok
			/*
			 * Setup and set a Layout for urlshortenpage
			 */
			layout1 = new qvboxlayout() {
				addwidget(longurllabel)
				addwidget(longurledit)
				addwidget(longurlsubmit)
				addwidget(shorturllabel)
				addwidget(qtextedit1)
			}
			setlayout(layout1)
		}
		/*
		 * Create another tab page with contents for history information
		 */
		historypage = new qwidget() {
			/*
			 * Create a Table to hold history items
			 */
			table = new qtablewidget(historypage) {
				/*
				 * Set the behavior, table headers, default widths, etc
				 */
				setselectionbehavior(QAbstractItemView_SelectRows)
				setsortingenabled(true)
				strlist = new qstringlist()
				strlist.append(tables[:headershorturl])
				strlist.append(tables[:headerlongurl])
				setcolumncount(strlist.size())
				sethorizontalheaderlabels(strlist)
				setcolumnwidth(0, windowscreen[:width]/3)
				setcolumnwidth(1, windowscreen[:width]/2)
				/*
				 *  Load the History from File
				 */
				fgethistory()
			}
			/*
			 * Submit button
			 */
			clearhistorysubmit = new qpushbutton(historypage){settext(bactions[:clear]) setclickevent(events[:fclearhistory])}
			/*
			 * Setup and set a Layout for historypage
			 */
			layout1 = new qvboxlayout() {
				addwidget(table)
				addwidget(clearhistorysubmit)
			}
			setlayout(layout1)
		}
		/*
		 * Create another page of the tabs for settings
		 */
		 settingspage = new qwidget(){
			/*
			 * Info on where to obtain the API key
			 */
			apikeyinfolabel = new qlabel(settingspage){settext(links[:googleapikeyurl]) setopenexternallinks(true)}
			/*
			 * Input Label
			 */
			apikeylabel = new qlabel(settingspage){settext(qlabels[:apikey])}
			/*
			 * Edit/Input Field, load APIkey
			 * Check that the key exists and load it if so
			 */
			apikeyedit = new qlineedit(settingspage){
				if len(trim(fgetapikey())) = 0
					settext("")
				else
					settext(trim(fgetapikey()))
				ok
			}
			/*
			 * Option to allow the history to load on open into shortened list
			 */
			loadhistorycheckbox = new qcheckbox(settingspage){
				value = xmlopenread(filenames[:settingsfilename], xmlcontent[:settingselement])
				if value = "on"
					setcheckstate(2)
				ok
				settext(checkboxes[:loadhistoption])
				setclickedevent(events[:setloaduicontent])
            }
			/*
			 * Submit button
			 */
			apikeysubmit = new qpushbutton(settingspage){settext(bactions[:storekey]) setclickevent(events[:fsetapikey])}
			/*
			 * Setup and set a Layout for our widget Window
			 */
			layout1 = new qvboxlayout() {
				addwidget(apikeyinfolabel)
				addwidget(loadhistorycheckbox)
				addwidget(apikeylabel)
				addwidget(apikeyedit)
				addwidget(apikeysubmit)
			}
			setlayout(layout1)
		 }
		/*
		 *  Create a MainWindow Widget which will handle all UI elements
		 *  This Widget is empty as the tab widget inserts all pages into it
		 */
		mywidget = new qwidget() {
		}
		/*
		 * Create a TAB widget to hold our functionality
		 */
		tab1 = new qtabwidget(mywidget) {
			inserttab(0, urlshortenpage, bactions[:shorten])
			inserttab(1, historypage, bactions[:history])
			inserttab(2, settingspage, bactions[:settings])
			setfixedsize(windowscreen[:width], windowscreen[:height]-35)
			/*
			 * Ensure that we force user to enter a apiKey when not specified
			 */
			if len(trim(fgetapikey())) = 0
				settabenabled(0, false)
				settabenabled(1, false)
				statusbar.showmessage(statusbarmessages[:providekey], 0)
			ok
		}
		/*
		 * Set the Widget as the Central window to our Main Window
		 */
		setcentralwidget(mywidget)
		/*
		 * Set the MENU for the main window
		 */
		setmenubar(mymenu)
		show()
	}
exec()
}

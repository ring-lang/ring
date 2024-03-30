# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	load "hassounaLib.ring"
	t = new FormTools( oView.win )
	t.center()

	func btnFillTree_Click(){
		myTree = oView.TreeWidget1
		myTree.SetColumnCount(1)
		dev = new qTreeWidgetItem(){ SetText(0,"Development") }

		web = new qTreeWidgetItem(){ SetText(0,"Web Developer") }
		web_emp1 = new qTreeWidgetItem(){ SetText(0,"Ahmed Samy") }
		web_emp2 = new qTreeWidgetItem(){ SetText(0,"Kareem Samy") }
		web_emp3 = new qTreeWidgetItem(){ SetText(0,"Ahmed Maher") }
		web.AddChild(web_emp1)
		web.AddChild(web_emp2)
		web.AddChild(web_emp3)

		mob = new qTreeWidgetItem(){ SetText(0,"Mobile Developer") }
		mob_emp1 = new qTreeWidgetItem(){ SetText(0,"Mahmoud Fayed") }
		mob_emp2 = new qTreeWidgetItem(){ SetText(0,"Adel Sabour") }
		mob_emp3 = new qTreeWidgetItem(){ SetText(0,"Amr ElSayed") }
		mob.AddChild(mob_emp1)
		mob.AddChild(mob_emp2)
		mob.AddChild(mob_emp3)

		dev.AddChild(web)
		dev.AddChild(mob)
		
		MyTree.AddTopLevelItem(dev)
	}


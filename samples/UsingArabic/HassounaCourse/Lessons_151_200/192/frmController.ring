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

		marketing = new qTreeWidgetItem(){ SetText(0,"Marketing") }

		sale = new qTreeWidgetItem(){ SetText(0,"sale") }
		sale_emp1 = new qTreeWidgetItem(){ SetText(0,"Alaa Tamer") }
		sale_emp2 = new qTreeWidgetItem(){ SetText(0,"Kareem Tamer") }
		sale_emp3 = new qTreeWidgetItem(){ SetText(0,"Alaa Maher") }
		sale.AddChild(sale_emp1)
		sale.AddChild(sale_emp2)
		sale.AddChild(sale_emp3)

		market = new qTreeWidgetItem(){ SetText(0,"marketing") }
		market_emp1 = new qTreeWidgetItem(){ SetText(0,"Hamed Fayed") }
		market_emp2 = new qTreeWidgetItem(){ SetText(0,"Adel Ahmed") }
		market_emp3 = new qTreeWidgetItem(){ SetText(0,"Amr Adel") }
		market.AddChild(market_emp1)
		market.AddChild(market_emp2)
		market.AddChild(market_emp3)
		
		marketing.AddChild(market)
		marketing.AddChild(sale)

		MyTree.AddTopLevelItem(dev)
		MyTree.AddTopLevelItem(marketing)

	}

	func btnEdit_Click(){
		NewText = oView.txtEdit.Text()
		oView.TreeWidget1.CurrentItem().setText(0,NewText)
	}

	func AddToList(){
		curItem = oView.TreeWidget1.CurrentItem()
		oView.ListWidget1.AddItem( curItem.Text(0) )
#		#t.msgBox( curItem.parent().Text(0) )
	}



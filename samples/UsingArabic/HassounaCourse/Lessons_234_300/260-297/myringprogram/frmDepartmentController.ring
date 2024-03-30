# Form/Window Controller - Source Code File

load "frmDepartmentView.ring"
load "hassounalib.ring"
load "mysql_hassouna.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmDepartmentController)
		exec()
	}
}

class frmDepartmentController from windowsControllerParent

	oView = new frmDepartmentView
	t = new FormTools(oView.win)
	t.center()
	t.icon("red_ring.png")
	oView.txtDeptNo.setReadOnly(1)
	oView.cbxAutoSearch.setChecked(1)

	db_name = "myringprogram"
	mysql_connect_now()
	fill_data()
	clear_data()

	oView.tbl.setColumnWidth(1,120)
	oView.tbl.setColumnWidth(2,350)
	oView.tbl.setColumnWidth(3,220)

	oView.oFilter = new qAllEvents(oView.win)
	oView.oFilter.setCloseEvent( Method(:form_close) )
	oView.win.installEventFilter( oView.oFilter )

	oView.tbl.SetItemSelectionchangedevent( Method(:select_data) )

	func fill_data()
		mysql_fill_table( oView.tbl , "select * from department" )

	func select_data()
		curRow = oView.tbl.CurrentRow()
		deptno = oView.tbl.Item( curRow , 1 ).Text()
		deptname = oView.tbl.Item( curRow , 2 ).Text()
		deptloc = oView.tbl.Item( curRow , 3 ).Text()
		oView.txtDeptNo.setText( deptNO )
		oView.txtDeptName.setText(deptname)
		oView.txtDeptLoc.setText(deptloc)
		oView.btnAdd.setEnabled(0)
		oView.btnEdit.setEnabled(1)
		oView.btnDel.setEnabled(1)

	func clear_data()
		oView.txtDeptName.setText("")
		oView.txtDeptLoc.setText("")
		autoNum = mysql_auto_number("department","department_id")
		oView.txtDeptNo.setText( autoNum )
		oView.btnAdd.setEnabled(1)
		oView.btnEdit.setEnabled(0)
		oView.btnDel.setEnabled(0)
		oView.txtDeptName.setFocus(1)

	func add_dept()
		if trim(oView.txtdeptno.text())=""
			t.msgbox("Department number is empty!")
			bye
		ok
		if trim(oView.txtdeptname.text())=""
			t.msgbox("Department name is empty!")
			oView.txtdeptname.setFocus(1)
			bye
		ok
		if trim(oView.txtdeptloc.text())=""
			t.msgbox("Department location is empty!")
			oView.txtdeptloc.setFocus(1)
			bye
		ok
		deptno = oView.txtDeptNo.Text()
		deptname = oView.txtDeptName.Text()
		deptloc = oView.txtDeptLoc.Text()
		strInsert = "insert into department values(" + deptno + ",'" + deptname + "','" + deptloc + "')"
		mysql_run( strinsert )
		fill_data()
		clear_data()

	func edit_dept()
		if trim(oView.txtdeptno.text())=""
			t.msgbox("Department number is empty!")
			bye
		ok
		if trim(oView.txtdeptname.text())=""
			t.msgbox("Department name is empty!")
			bye
		ok
		if trim(oView.txtdeptloc.text())=""
			t.msgbox("Department location is empty!")
			bye
		ok
		deptno = oView.txtDeptno.Text()
		deptname = oView.txtdeptname.text()
		deptloc = oView.txtdeptloc.text()
		strUpdate = "update department set department_name='"+deptname+"' , department_location='"+deptloc+"' where department_id=" + deptno
		mysql_run(strupdate)
		fill_data()
		clear_data()

	func del_dept()
		if t.msgBoxYesNo("Do you want to delete?") 
		   strDel = "delete from department where department_id=" + oView.txtdeptno.text()
		   mysql_run(strdel)
		   fill_data()
		   clear_data()
		ok

	func find_dept() 
		deptno = t.inputboxInt("Enter department number:")
		strSel = "select * from department where department_id=" + deptno
		if len(mysql_get(strSel))=1
		   t.msgbox("This number not found!")
		else
		   mysql_fill_table(oView.tbl,strsel)
		ok

	func search_dept()
		strSearch = oView.txtSearch.Text()
		strSelect = "
		   select * from department
		   where department_name like'%" + strSearch + "%' or 
		   department_location   like'%" + strSearch + "%' 
		"
		if len(mysql_get(strSelect))=1 bye ok
		mysql_fill_table( oView.tbl , strSelect )

	func search_dept2()
		if oView.cbxAutoSearch.IsChecked()
			search_dept()
		ok

	func show_result_count()
		oView.lblCount.setText( "Result: " + string( oView.tbl.RowCount() ) )

	func form_close()
		mysql_close_now()

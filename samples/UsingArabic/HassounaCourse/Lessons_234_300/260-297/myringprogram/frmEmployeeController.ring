# Form/Window Controller - Source Code File

load "frmEmployeeView.ring"
load "hassounalib.ring"
load "mysql_hassouna.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmEmployeeController)
		exec()
	}
}

class frmEmployeeController from windowsControllerParent

	oView = new frmEmployeeView
	t = new FormTools(oView.win)
	t.center()
	t.icon("red_ring.png")
	oView.cbxAutoSearch.setChecked(1)

	db_name = 'myringprogram'
	mysql_connect_now()
	fill_data()
	mysql_fill_combobox( oView.cbxDept , "department" , "department_name" )
	oView.txtEmpNO.setReadOnly(1)
	clear_data()

	oView.tbl.setColumnWidth(1,100)
	oView.tbl.setColumnWidth(2,250)
	oView.tbl.setColumnWidth(3,100)
	oView.tbl.setColumnWidth(4,90)
	oView.tbl.setColumnWidth(5,90)
	oView.tbl.setColumnWidth(6,220)

	oView.oFilter = new qAllEvents(oView.win)
	oView.oFilter.setCloseEvent( Method(:close_form) )
	oView.win.installeventfilter(oView.oFilter)

	func show_result_count()
		oView.lblCount.SetText( "Result: " + string(oView.tbl.RowCount() ) )

	func search_emp()
		strSearch = oView.txtSearch.Text()
		strSelect = "
		   select * from employee_data where 
		   employee_name   like'%" + strSearch + "%' or 
		   address         like'%" + strSearch + "%' or 
		   salary          like'%" + strSearch + "%' or 
		   department_name like'%" + strSearch + "%'
		"
		if len(mysql_get(strSelect))=1 bye ok
		mysql_fill_table(oView.tbl , strSelect)

	func search_emp2()
		if oView.cbxAutoSearch.IsChecked() search_emp() ok

	func find_emp() 
		empno = t.inputboxInt("Enter employee number:")
		strSel = "select * from employee_data where employee_id=" + empno
		if len(mysql_get(strSel))=1
		   t.msgbox("This number not found!")
		else
		   mysql_fill_table( oView.tbl , strsel )
		ok

	func del_emp()
		if t.msgboxYesNo("Do you want to delete?")
		   strDel = "delete from employee where employee_id=" + oView.txtEmpNo.Text()
		   mysql_run(strDel)
		   fill_data()
		   clear_data()
		ok

	func edit_emp()
		if trim( oview.txtempno.text() ) = ''
		   t.msgbox("Employee ID is Empty!")
		   bye
		ok
		if trim( oView.txtEmpName.Text() ) = ""
		   t.msgbox("Employee Name is Empty!")
		   oview.txtempname.setfocus(1)
		   bye
		ok
		if trim( oView.txtAddress.Text() ) = ""
		   t.msgbox("Employee Address is Empty!")
		   oview.txtAddress.setfocus(1)
		   bye
		ok
		empno   = oView.txtEmpno.Text()
		empname = oView.txtEmpName.Text()
		address = oView.txtAddress.Text()
		salary  = oView.txtSalary.Value()
		selectForDeptNO = "select department_id from department where department_name='" + oView.cbxDept.CurrentText() + "'"
		deptno  = mysql_get(selectForDeptNO)[2][1]
		strUpdate = "
		   update employee set 
		   employee_name = '" + empname + "' , 
		   address       = '" + address + "' , 
		   salary        =" + salary + "    , 
		   department_id =" + deptno + "    
		   where employee_id =" + empno + " 
		"
		mysql_run(strUpdate)
		fill_data()
		clear_data()

	func add_emp()
		if trim( oview.txtempno.text() ) = ''
		   t.msgbox("Employee ID is Empty!")
		   bye
		ok
		if trim( oView.txtEmpName.Text() ) = ""
		   t.msgbox("Employee Name is Empty!")
		   oview.txtempname.setfocus(1)
		   bye
		ok
		if trim( oView.txtAddress.Text() ) = ""
		   t.msgbox("Employee Address is Empty!")
		   oview.txtAddress.setfocus(1)
		   bye
		ok
		empno   = oView.txtEmpno.Text()
		empname = oView.txtEmpName.Text()
		address = oView.txtAddress.Text()
		salary  = oView.txtSalary.Value()
		selectForDeptNO = "select department_id from department where department_name='" + oView.cbxDept.CurrentText() + "'"
		deptno  = mysql_get(selectForDeptNO)[2][1]
		mysql_run("insert into employee values(" + empno + ",'" + empname + "','" + address + "'," + salary + "," + deptno + ")")
		fill_data()
		clear_data()


	func select_data()
		curRow = oView.tbl.CurrentRow()
		empno = oView.tbl.Item( curRow , 1 ).Text()
		empname = oView.tbl.Item( curRow , 2 ).Text()
		address = oView.tbl.Item( curRow , 3 ).Text()
		salary = oView.tbl.Item( curRow , 4 ).Text()
		dept = oView.tbl.Item( curRow , 6 ).Text()
		oView.txtEmpNo.SetText( empno )
		oView.txtEmpName.SetText( empname )
		oView.txtAddress.SetText( address )
		oView.txtSalary.SetValue( number(salary) )
		oview.cbxDept.setCurrentIndex( oView.cbxdept.findtext( dept , 0) )
		oView.btnAdd.setEnabled(0)
		oView.btnEdit.setEnabled(1)
		oView.btnDel.setEnabled(1)
		

	func fill_data()
		mysql_fill_table( oView.tbl , "select * from employee_data" )

	func clear_data()
		oView.txtEmpName.SetText("")
		oView.txtAddress.setText("")
		oView.txtEmpNo.setText( mysql_auto_number('employee','employee_id') )
		oView.btnAdd.setEnabled(1)
		oView.btnEdit.setEnabled(0)
		oView.btnDel.setEnabled(0)
		oView.txtEmpName.setFocus(1)



	func close_form() 
		mysql_close_now()



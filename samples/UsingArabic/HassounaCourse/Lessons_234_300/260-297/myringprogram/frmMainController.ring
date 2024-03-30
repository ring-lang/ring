# Form/Window Controller - Source Code File

load "frmMainView.ring"
load "hassounalib.ring"
load "mysql_hassouna.ring"
load "frmProgramController.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmMainController)
		exec()
	}
}

class frmMainController from windowsControllerParent

	oView = new frmMainView
	t = new FormTools(oView.win)
	t.center()
	t.icon("red_ring.png")

	func createdb()
		mysql_connect_now()
		mysql_run("
		 CREATE DATABASE IF NOT EXISTS myringprogram 
		 DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci
		")
		mysql_close_now()
		t.msgbox("Done...")

	func createtables()
		db_name = "myringprogram"
		mysql_connect_now()

		mysql_run("
		 CREATE TABLE IF NOT EXISTS myusers
		 (
		 	username varchar(50) primary key,
		 	password varchar(50)
		 )
		")
		r = mysql_get("select count(*) from myusers")
		if r[2][1] = 0
		   mysql_run("insert into myusers values('admin','admin')")
		ok

		mysql_run("
		 CREATE TABLE IF NOT EXISTS department
		 (
		 	department_id int primary key,
		 	department_name varchar(100),
		 	department_location varchar(100)
		 )
		")

		mysql_run("
		 CREATE TABLE IF NOT EXISTS employee
		 (
		 	employee_id int primary key,
		 	employee_name varchar(100),
		 	address varchar(150),
		 	salary int,
			department_id int,
			foreign key(department_id) references department(department_id)
		 )
		")

		mysql_run("
		 create view IF NOT EXISTS employee_data as 
		 select employee_id, employee_name, address, salary, 
		 	   employee.department_id, department_name 
		 from employee , department 
		 where employee.department_id = department.department_id 
		")

		mysql_close_now()
		t.msgbox("Done...")

	func openprogram()
		strUser = t.inputbox("Enter Username")
		strPass = t.inputBoxPass("Enter Password")
		db_name = "myringprogram"
		mysql_connect_now()
		r = mysql_get("select count(*) from myusers where username='" + strUser + "' and password='" + strPass + "' ")
		if r[2][1] = 1
			t.win().close()
			openWindow(:frmProgramController)
		else
			t.msgbox("Username or password incorrect")
		ok
		mysql_close_now()

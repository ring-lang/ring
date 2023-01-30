#====================================================================#
# Application: Quiz Marks
# Author     : Mahmoud Fayed
# Date       : 2023-01-29
#====================================================================#
#
# We have a Quiz that contains 100 questions (True/False)
#
# 			-={ Input  }=-
#
# 	(1) The correct answer (aCorrect)
# 	(2) Also, We provide the Students answer (aStudents)
#
# 			-={ Output }=-
#
# 	(1) Student Score  (of 100)
#	(2) Students Marks (of 10)
#	(3) Detect the Wrong Answers 
#	(4) CSV File contains the results
#
#====================================================================#

#====================================================================#
# 		      Load the Application Data 
#====================================================================#

load "data/data.ring"

#====================================================================#
#                    Display General Information
#====================================================================#

load "data/uilib.ring"
line()
? " Students  Count : " + len(aStudents)
? " Questions Count : " + C_QUESTIONSCOUNT
line()

#====================================================================#
# 			Prepare Results (Marks)
#====================================================================#

aMarks = [["Student ID","Wrong Answers","Score of 100","Marks of 10"]]
for student in aStudents
	aMark = [student[1]]
	See " " + student[1] + " - ( " 
	aAnswer = student[2]
	nSum = 0
	cWrong = ""
	for t=1 to C_QUESTIONSCOUNT
		if aAnswer[t] = aCorrect[t]
			nSum++
		else 
			see "Q" + t + " "
			cWrong += "Q" + t + " "
		ok
	next
	aMark + cWrong
	cScore = "" + nSum + " of " + len(aAnswer)
	aMark + cScore
	nMark = (nSum/10)
	aMark + nMark
	? ") - " + cScore + " - " + nMark + " of 10 "
	aMarks + aMark
next
line()

#====================================================================#
# 			Create the CSV File
#====================================================================#

load "csvlib.ring"
write("marks.csv",list2csv(aMarks))

#====================================================================#
# 		Adding a GUI using RingQt & GUILib
#====================================================================#

load "guilib.ring"
import System.GUI

new App {
	w = new Window() {
		setWindowTitle("Quiz Marks") resize(800,600)
		t = new TableWidget(w) { addList(aMarks) }
		b = new PushButton(w) { 
			setText("Close") setClickEvent("w.close()")
		}
		l = new VBoxLayout() { addWidget(t) addwidget(b) }
		setLayout(l) show()
	}
	exec()
}

#====================================================================#
#---/\/R\/I\/N\/G\/\/I\/S\/\/F\/U\/N\/\/|_-_|\/E\/N\/J\/O\/Y\/!\/\---#
#====================================================================#
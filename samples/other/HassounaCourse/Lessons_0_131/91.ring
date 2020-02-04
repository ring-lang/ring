
std1 = new school.s1.student
std1.getType()

std2 = new s1.student
std2.getType()

package s1{
	class student func getType see "S1>>Student" + nl
}

package school.s1{
	class student func getType see "School.S1>>Student" + nl
	class doctor func getType see "School.S1>>Doctor" + nl
}

package academy{
	class student func getType see "Academy>>Student" + nl
	class doctor func getType see "Academy>>Doctor" + nl
}



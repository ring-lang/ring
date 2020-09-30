
s1 = new school.student
s1.getType()

s2 = new academy.student
s2.getType()

d1 = new academy.doctor
d1.getType()


package school{
	class student func getType see "School>>Student" + nl
	class doctor func getType see "School>>Doctor" + nl
}

package academy{
	class student func getType see "Academy>>Student" + nl
	class doctor func getType see "Academy>>Doctor" + nl
}


/*
s1 = new student
s1.getType()

class student func getType see "student" + nl
class doctor func getTYpe see "doctor" + nl
*/


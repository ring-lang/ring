import academy
import school

func main
	sub1 = new subject
	sub1.getType()
	
	std1 = new student
	std1.getType()
	
	std2 = new school.student
	std2.getType()
end

package school{
	class subject func getType see "School>>Subject" + nl
	class student func getType see "School>>Student" + nl
	class doctor func getType see "School>>Doctor" + nl
}

package academy{
	class student func getType see "Academy>>Student" + nl
	class doctor func getType see "Academy>>Doctor" + nl
}



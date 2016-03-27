see "welcome " + nl
oPerson = new Person

oPerson.cName = "Mahmoud"
oPerson.cCountry = "Egypt"
oPerson.oContact.eMail = "test@email.com"
oPerson.oContact.cPhone = "123456789"
oPerson.oContact.cWebsite = "www.mywebsite.com"

see "Name : " + oPerson.cName + nl
see "Country : " + oPerson.cCountry + nl
see "Email : " + oPerson.oContact.eMail + nl
see "Phone : " + oPerson.oContact.cPhone + nl
see "Website : " + oPerson.oContact.cWebsite + nl
see "First Job : " + oPerson.oContact.aJobs[1] + nl
see "Jobs List : " see oPerson.oContact.aJobs
see "Jobs count : " + len(oPerson.oContact.aJobs) + nl
see "other : " + oPerson.oContact.oEmp.cOther + nl
see "other : " + oPerson.oContact.aJobs[5].cOther + nl
v = oPerson.oContact.aJobs[4]
see len(v) + nl
v = oPerson.oContact.aJobs[5]
see "Jobs : " + v.cJobName + nl
see oPerson.oContact.aJobs[5].cjobname + nl
see oPerson.oContact.aJobs[6].vgood + nl

class person
	cName = ""
	cCountry = ""
	oContact = new Contact

class contact
	eMail = ""
	cPhone = ""
	cWebsite = ""
	aJobs = ["Researcher","Developer","Programmer","",new Employee,""]
	aJobs[4] = ["one","two"]
	oEmp = new employee
	aJobs[6] = oEmp

class employee
	cJobName = "a"
	cother = "nice"
	vgood = 3.14
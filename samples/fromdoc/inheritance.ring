Func main
        e1 = new Employee {
                Name = "test"
                age = 20
                job = "programmer"
                salary = 20000000
                print()
        }


Class Human
        Name Age
        func print
                see "Name : " + name + nl + "Age  : " + age + nl

Class Employee from Human
        Job Salary
        func print
                super.print()
                see "Job  : " + job + nl + "Salary : " + salary + nl

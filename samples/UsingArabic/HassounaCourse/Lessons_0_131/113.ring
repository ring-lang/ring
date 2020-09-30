
sayHello([])
sayHello([:name="Ahmed"])
sayHello([:fname="Amr" , :lname="Omar" ])
sayHello([:lname="Hassouna" , :fname="Amr" , :mname="Ali"])

func sayHello(all){
	if len(all)=0
		see "Hello Person" + nl
	but all[:fname] !=null and all[:mname] !=null and  all[:lname] !=null
		see "Hello " + all[:fname] + ' ' + all[:mname] + ' ' + all[:lname] + nl
	but all[:fname] !=null and all[:lname] !=null
		see "Hello " + all[:fname] + ' ' + all[:lname] + nl
	but all[:name] != null
		see "Hello " + all[:name] + nl
	ok
}

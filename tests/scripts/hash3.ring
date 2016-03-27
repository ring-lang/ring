o1 = 
[ 
	:x = 10, 
	:y = 20, 
	:z = 30,
	:o2 = [ :color = :red, :backcolor = :white ] ,
	:o3 = [ :name = :mahmoud, 
		:job = :programmer,
		:o4 = [ :one = 1 , :two = 2 , :three = 3 ]	
	      ] 
]

see o1[:x] + nl 
see o1[:y] + nl 
see o1[:z] + nl 
see o1[:o2][:color] + nl
see o1[:o2][:backcolor] + nl 
see o1[:o3][:name] + nl 
see o1[:o3][:job] + nl 
see o1[:o3][:o4][:one] + nl 
see o1[:o3][:o4][:two] + nl 
see o1[:o3][:o4][:three] + nl 

New Person { Name = "Mahmoud" Address = "Egypt" Phone = 1234567 print() }
Class Person Name Address Phone func print see Name + nl + Address + nl + Phone





load "stdlib.ring"
Package MyLanguage.Natural

class execute

        func Getexecute
                StartCommand()
                CommandData()[:name] = :Execute
                CommandData()[:nExpr] = 0
                CommandData()[:aExpr] = []

        func BraceExprEval_execute nValue
                if isCommand() and CommandData()[:name] = :execute {
                        if isnumber(nValue) {
                                CommandData()[:nExpr]++
                                CommandData()[:aExpr] + nValue
                                if CommandData()[:nExpr] =2{
					if expr(1)=expr(2){
                                       		 open()
					}
                                }
                        }
                }


        func AddAttributes_Execute
                AddAttribute(self,:execute)
	func open	
		 	nLines=[]
		fp = fopen("test7.ring","r")
			while not feof(fp)
				Lines=Readline(fp)
				oString = new string(Lines)
				if oString.startswith("goto") 
					while not feof(fp)
						Lines=Readline(fp)
						nLines+Lines
						oString = new string(Lines)
						if oString.startswith("theend") 
							theend=0
							eval(list2str(nLines))		
							exit 2  					
						ok
					end
				ok				
			end
		fclose(fp)
	

		


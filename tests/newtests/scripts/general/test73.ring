Company  = [ :Symbol  = "" ,  :Name = "" , :Group  = "" ]
Symbol = "JACK"  # <<< First
CurCmp = Company  # <<< Copy by value
#Symbol = "JACK"   # <<< Second
CurCmp[:Symbol]= "AMZN"
CurCmp[:Name] = "Amazon"
CurCmp[:Group]  = "Cloud"
See "Class-Company-CurCmp: " + CurCmp[:Symbol] +" | "+  CurCmp[:Name] +" | "+ CurCmp[:Group] +" | "+  nl
See "Label-String-Symbol : " + Symbol +nl +nl
            
                

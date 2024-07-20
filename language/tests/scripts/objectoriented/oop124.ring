o = new myclass
? :start
try
	addmethod(o,:mymethod, func { ? :good })
	o.mymethod()
catch
	? cCatchError
done
? :end


class myclass
	func mymethod
		? :hello
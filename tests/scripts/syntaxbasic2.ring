ChangeRingKeyword  func function
ChangeRingKeyword  see  print
ChangeRingKeyword  ok   endif
ChangeRingKeyword  next endfor
ChangeRingKeyword  end  endwhile

x = 10
while x > 0
	print "x = " + x + nl
	for t = 1 to 10
		if t = 3
			print "number three" + nl
		endif
	endfor	

x--
endwhile

test() 

function test
	print "message from test" + nl

ChangeRingKeyword  function func
ChangeRingKeyword  print see
ChangeRingKeyword  endif ok
ChangeRingKeyword  endfor next
ChangeRingKeyword  endwhile end
Try 
	testmode(6)
catch
	see "avoid raise!"
done

testmode(-1)

func testmode nMode

	if nMode < 0 or nMode > 5
		raise("Error : nMode not in the range 1:4")
	ok
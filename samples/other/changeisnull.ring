NULL = "anything"
if isNull(NULL) {  ?"It's null" else? "It's not null" }

func isNULL(value)
	if value = NULL or value = "" or value = "NULL"
		return true
	ok
	return false
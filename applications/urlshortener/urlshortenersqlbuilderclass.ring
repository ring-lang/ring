/*
 * Simplification for all queries, for a more natural construction
 */
 class mysqlbuilder
	table
	content
	/*
	 *  Returns all data
	 */
	func getallhistory()
		sql = mselect + mspace + "*" + mspace + mfrom + mspace + table + mend
		return trim(sql)
	/*
	 * Returns count for the table
	 */
	func gethistorycount()
		sql = mselect + mspace + mcount + mspace + mfrom + mspace + table + mend
		return trim(sql)
	/*
	 * Deletes all items from the table
	 * TODO: id 
	 */
	func deleteallhistory()
		sql = mdelete + mspace + mfrom + mspace + table + mspace + mwhere + mspace + "id" + mspace + "!= 0" + mend
		return trim(sql)
	/*
	 * Inserts a new item into the database
	 */
	func insertshortened(id, shorturl, longurl)
		cont = getcontdef()
		values = "(" + id + ",'" + shorturl + "','" + longurl + "')"
		sql = minsertinto + mspace + table + cont + mspace + mvalues + values + mend
		return trim(sql)
	/*
	 * Creates a table from Content
	 */
	func createdbtable()
		cont = getcontroot()
		sql = mcreate + mspace + mtable + mspace + mifnotexists + mspace + table + cont + mend
		return trim(sql)
	/*
	 * Private builder strings
	 */
	private
		mspace = " "
		mprimarykey = "INT PRIMARY KEY"
		mselect = "SELECT"
		mfrom = "FROM"
		minsertinto = "INSERT INTO"
		mend = ";"
		mcount = "COUNT(*)"
		mdelete = "DELETE"
		mwhere = "WHERE"
		mvalues = "VALUES"
		mcreate = "CREATE"
		mnotnull = "NOT NULL"
		mtable = "TABLE"
		mifnotexists = "IF NOT EXISTS"
		/*
		 * Root definitions 
		 * TODO: sizes, type
		 */
		func getcontroot()
			cont = "("
			size = len(content)
			for x in content
				if x[2] = "id"
					cont += "id " + mprimarykey + mspace + 	mnotnull
				elseif x[2] = "longurl"
					cont += "longurl " + "VACHAR(2048)" + mspace + mnotnull
				elseif x[2] = "shorturl"
					cont += "shorturl " + "VACHAR(45)" + mspace + mnotnull
				ok
				if size > 1
					cont += ","
					size -= 1
				ok
			next
			cont += ")"
			return cont
		/*
		 * Definitions or Table headers
		 */
		func getcontdef()
			cont = "("
			size = len(content)
			for x in content
				cont += x[2]
				if size > 1
					cont += ","
					size -= 1
				ok
			next
			cont += ")"
			return cont
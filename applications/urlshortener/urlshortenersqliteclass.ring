/*
 * SQLite Wrapper class to minimize calls
 */
class mysqlite
	file
	/*
	 * Execute() wrapps sqlite_open and sqlite_execute()
	 */
	func execute(sql)
		try
			sqlite_open(sqliteio, file)
		catch
			print(ccatcherror)
		done
		return sqlite_execute(sqliteio, sql)
	/*
	 * Close() wraps sqlite_close()
	 */
	func close()
		sqlite_close(sqliteio)
	/*
	 * Initialize the IO device
	 */
	private
		sqliteio = sqlite_init()
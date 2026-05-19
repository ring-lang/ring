# Example 2: Parameterized Queries (SQL Injection Safe)
# Uses sqlite_execute with a 3rd list parameter for bound values

load "sqlitelib.ring"

oSQLite = sqlite_init()
sqlite_open(oSQLite, ":memory:")

# Create table
sqlite_execute(oSQLite, "CREATE TABLE users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER)")

# Safe inserts using parameterized queries
sqlite_execute(oSQLite, "INSERT INTO users (name, age) VALUES (?, ?)", ["Alice", 30])
sqlite_execute(oSQLite, "INSERT INTO users (name, age) VALUES (?, ?)", ["Bob", 25])
sqlite_execute(oSQLite, "INSERT INTO users (name, age) VALUES (?, ?)", ["Charlie", 35])

# Parameterized SELECT with number
aResult = sqlite_execute(oSQLite, "SELECT * FROM users WHERE age > ?", [28])
? "Users with age > 28:"
for x in aResult
	? x[:name]
next

# Parameterized SELECT with string
aResult = sqlite_execute(oSQLite, "SELECT * FROM users WHERE name = ?", ["Bob"])
? nl + "User named Bob:"
for x in aResult
	? x[:name] + " - age: " + x[:age]
next

# SQL injection is safely handled - the input is treated as a literal string
aResult = sqlite_execute(oSQLite, "SELECT * FROM users WHERE name = ?", ["' OR '1'='1"])
? nl + "Injection attempt result (0 rows):"
? "Row count: " + len(aResult)

sqlite_close(oSQLite)

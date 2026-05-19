# Example 3: NULL Values, last_insert_rowid, and Error Handling

load "sqlitelib.ring"

oSQLite = sqlite_init()
sqlite_open(oSQLite, ":memory:")

sqlite_execute(oSQLite, "CREATE TABLE products (id INTEGER PRIMARY KEY, name TEXT, price REAL)")

# Insert with NULL value
sqlite_execute(oSQLite, "INSERT INTO products (name, price) VALUES (?, ?)", ["Widget", NULL])
sqlite_execute(oSQLite, "INSERT INTO products (name, price) VALUES (?, ?)", ["Gadget", 9.99])

# Get last insert rowid via SQL
aResult = sqlite_execute(oSQLite, "SELECT last_insert_rowid() as rid")
? "Last inserted rowid: " + aResult[1][1][2]

# Update with parameterized query
sqlite_execute(oSQLite, "UPDATE products SET price = ? WHERE name = ?", [4.99, "Widget"])

# Display all products
aResult = sqlite_execute(oSQLite, "SELECT * FROM products")
? nl + "All products:"
for x in aResult
	? x[:name] + " - price: " + x[:price]
next

# Delete with parameterized query
sqlite_execute(oSQLite, "DELETE FROM products WHERE name = ?", ["Gadget"])

aResult = sqlite_execute(oSQLite, "SELECT * FROM products")
? nl + "After deleting Gadget:"
for x in aResult
	? x[:name] + " - price: " + x[:price]
next

# Error handling using sqlite_errmsg()
# Attempt an invalid SQL statement
sqlite_execute(oSQLite, "SELECT * FROM nonexistent_table")
? nl + "Error message: " + sqlite_errmsg(oSQLite)

sqlite_close(oSQLite)

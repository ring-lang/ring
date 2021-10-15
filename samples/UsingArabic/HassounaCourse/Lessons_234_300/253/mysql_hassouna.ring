load "mysqllib.ring"
load "guilib.ring"

db_host = 'localhost'
db_name = ''
db_user = 'root'
db_pass = ''
db_con  = NULL

func mysql_connect_now()
   db_con = mysql_init()
   if mysql_connect( db_con , db_host , db_user , db_pass , db_name ) = 0
      see "Can't connect" + NL
      see "Error: " + mysql_error(db_con) + NL
      mysql_close(db_con)
      return 0
      bye
   ok
   return 1

func mysql_close_now()
   mysql_close(db_con)

func mysql_run( sql_statement )
   if IsNULL( db_con )
      see "You are not conteccted. Use mysql_connect_now()" + NL
      bye
   ok
   mysql_query( db_con , "SET CHARACTER SET utf8" )
   if mysql_query( db_con , sql_statement )
      see mysql_error(db_con) + NL
   ok



func mysql_get( select_statement )
   if IsNULL( db_con )
      see "You are not conteccted. Use mysql_connect_now()" + NL
      bye
   ok
   mysql_query( db_con , "SET CHARACTER SET utf8" )
   if mysql_query( db_con , select_statement )
      see mysql_error( db_con ) + NL
   else
      return mysql_result2( db_con )
   ok


func mysql_auto_number( table_name , column_name )
   max_stmt = "select max(" + column_name + ")+1 from " + table_name
   r = mysql_get( max_stmt )
   if r[2][1] = NULL
      return "1"
   else
      return r[2][1]
   ok

func mysql_fill_table( table , select )
   if lower( type(table) ) != "object"
      see "Error: Use object only."
      bye
   ok
   if lower( classname(table) ) != "tablewidget"
      see "Error: Use tablewidget only."
      bye
   ok
   r = mysql_get(select)
   table.setColumnCount( len( r[1] ) )
   table.setRowCount( len(r)-1 )
   table.setSelectionbehavior(1)

   for x=1 to len(r[1])
      cell = new qTableWidgetItem( r[1][x] )
      table.setHorizontalheaderitem( x , cell )
   next

   cell = new qTableWidgetItem( "1         " )
   table.setVerticalheaderitem( 1 , cell )
   table.setEdittriggers(0)

   for row=2 to len(r)
      for col=1 to len(r[row])
         cell = new qTablewidgetitem( r[row][col] )
         table.setItem( row-1 , col , cell )
      next
   next


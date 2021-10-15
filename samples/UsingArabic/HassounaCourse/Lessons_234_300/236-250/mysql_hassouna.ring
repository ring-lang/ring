load "mysqllib.ring"

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
   if mysql_connect_now()
      mysql_query( db_con , "SET CHARACTER SET utf8" )
      if mysql_query( db_con , sql_statement )
         see mysql_error(db_con) + NL
      ok
      mysql_close_now()
   ok

func mysql_get( select_statement )
   if mysql_connect_now()
      mysql_query( db_con , "SET CHARACTER SET utf8" )
      if mysql_query( db_con , select_statement )
         see mysql_error( db_con ) + NL
      else
         return mysql_result2( db_con )
      ok
      mysql_close_now()
   ok

func mysql_auto_number( table_name , column_name )
   max_stmt = "select max(" + column_name + ")+1 from " + table_name
   r = mysql_get( max_stmt )
   if r[2][1] = NULL
      return "1"
   else
      return r[2][1]
   ok



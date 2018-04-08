#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 14.01.2018                  
####################################


load "odbclib.ring"

# --------------Connect/Disconnect 
# --------------Execute Query (SQL)
# --------------Transaction (Commit) 
#-------------- Save/Restore binary data (images)

oODBC = odbc_init()

? odbc_drivers(oODBC)

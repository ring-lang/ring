# We must have error here because of using 1/0
# The test to check that we don't have substr() and trim()
# In the runtime error message

see trim(substr("test",1,1/0))
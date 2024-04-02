load "stdlibcore.ring"
load "threads.ring"


res = 0
# the initial balance is 0
balance = 0
# mutex variable
mutex = new_mtx_t()
# the deposit amounts... the correct total afterwards should be 500
deposit1 = 300
deposit2 = 200

func main
	  # output the balance before the deposits
	   before = read_balance()
	  ?"Before: " + before
	  # we'll create two threads to conduct a deposit using the deposit function
	  thread1 = new_thrd_t()
	  thread2 = new_thrd_t()
	  # initialize the mutex
	  mtx_init(mutex, res)
	  # create threads to run the deposit function with these deposit amounts
	  thrd_create(thread1,"deposit(deposit1)")
	  thrd_create(thread2,"deposit(deposit2)")
	  # join the threads
	  thrd_join(thread1, :res)
	  thrd_join(thread2, :res)
	  # destroy the mutex
	  destroy_mtx_t(mutex)
	  # output the balance after the deposits
	  after = read_balance()
	  ? "After :" + after
	
# A simple Bank account function  that allows us to read and write 
# a bank account balance.

# We'll include "stdlib.ring" so we can use the sleep() function to simulate 
# a delay in reading and writing the balance due to network traffic.  This is
# the sort of issue that can cause race conditions in the "real world".
# returns the balance (after a simulated 1/4 seond delay)
func read_balance()
	  sleep(0.25)
	  return balance

# write the new balance (after as simulated 1/4 second delay)
func write_balance(new_balance)
	  sleep(0.25)
	  balance = new_balance

func deposit(amount)

 	  # The first thread this reaches this statement will acquire the lock, and
	  # the second thread will then wait here until the lock is unlocked.  the 
	  # first thread that reaches this look will execute the statements below 
	  # and then reach the unlock statement, at which point the second thread 
	  # will then itself be able to acquire the lock and begin to execute 
	  # this section of code.  We call this section of code between the lock 
	  # and unlock a critcal section, as we are accessing and modifying shared 
	  # state between threads.  If we do not use a lock to "guard" this critical 
	  # section of code from being entered by multiple threads at the same time, 
	  # we will have a race condition.  As the function is executed by two 
	  # threads over the same period of time, the statements executed will 
	  # interleave leading to incorrect results.  Comment out the lock and 
	  # unlock function calls to see the effect.  See the visualization below 
	  # of how the code executes with a race condition present vs with our mutex
	  # code below.
	  
	  mtx_lock(mutex)
	  # retrieve the bank balance
	  account_balance = read_balance()
	  # make the update locally
	  account_balance += amount
	  # write the new bank balance
	  write_balance(account_balance)
	  # unlock to make the critical section available to other threads
	  mtx_unlock(mutex)
	

#  What is a race condition? 
#
#  A race condition occurs when a program depends on the 
#  timing of one or more events to function correctly.
#
#  A race condition typically occurs when multiple threads
#  access a shared variable (or state) at the same time.
#
#
#  What is a mutex?
#
#  A mutex is a synchronization primitive that enforces 
#  limits on access to a shared resource when we have 
#  multiple threads of execution.
#
#  
#
#  Race Condition Visualization
# 
#
#  Thread #1             Thread #2              Bank Balance
#     
#  Read Balance  <----------------------------------- 0
#  balance = 0 
#                        Read Balance  <------------- 0
#                        balance = 0
#
#  Deposit +300
#  balance = 300
#                        Deposit +200 
#                        balance  = 200
#
#  Write Balance  ----------------------------------> 300
#  balance = 300
#                        Write Balance  ------------> 200
#                        balance = 200
#
#
#
#  Mutex Version Execution Visualization
#
#
#
#  Thread #1             Thread #2              Bank Balance
#
#                        **  LOCK  **
#       
#  WAIT @ LOCK           Read Balance  <------------- 0
#       |                balance = 0
#       |
#       |                Deposit +200 
#       |                balance  = 200
#       |
#       |                Write Balance  ------------> 200
#       |                balance = 200
#       |
#   LOCK FREE            ** UNLOCK **
# 
#  **  LOCK  ** 
#
#  Read Balance  <----------------------------------- 200
#  balance = 0 
#
#  Deposit +300
#  balance = 500
#
#  Write Balance  ----------------------------------> 500
#  balance = 500
#
#  ** UNLOCK **
#

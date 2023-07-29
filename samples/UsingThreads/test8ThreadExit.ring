# Thread_Exit
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023
# Description:return result from thread
load "stdlib.ring"
load "threads.ring"



func main
    res = 0
    thread = new_thrd_t()
    if thrd_create(thread, "roll_dice()") != 1
				? "Failed to create thread"
        return 
    ok
    # thrd_exit(0)
    if thrd_join(thread, :res) != 1
				? "Failed to join thread"
        return 
    ok
    ? "thrd_exit Result : " + res
    
  

func roll_dice() 
    value = random(100) + 1
    result = value
    sleep(2)
    ? "Thread result : " + value
    thrd_exit(result)


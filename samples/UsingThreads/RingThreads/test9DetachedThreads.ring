# Detached Thread
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023
# Description:
load "stdlib.ring"
load "threads.ring"




THREAD_NUM  = 2
aThreads = list(THREAD_NUM)
res= 0


func main
    
    for i = 1 to THREAD_NUM
				aThreads[i] = new_thrd_t()
        if thrd_create(aThreads[i],"routine()") != 1
            ? "Failed to create thread"
        ok
        thrd_detach(aThreads[i])
    next

    for i = 1 to THREAD_NUM
        if thrd_join(aThreads[i], :res) != 1
            ? "Failed to join thread"
        ok
    next

    thrd_exit(0)


func routine()
    sleep(2)
    ? "Finished execution ."

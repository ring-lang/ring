# Detached Thread
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023

load "stdlibcore.ring"
load "threads.ring"

THREAD_NUM  = 2
aThreads    = list(THREAD_NUM)
res         = 0

func main
    
    for i = 1 to THREAD_NUM
				aThreads[i] = new_thrd_t()
        thrd_create(aThreads[i],"routine()")
        thrd_detach(aThreads[i])
    next

    for i = 1 to THREAD_NUM
        thrd_join(aThreads[i], :res) 
    next

    thrd_exit(0)

func routine

    sleep(2)
    ? "Finished execution ."

# Thread Pools
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023
# Description: Thread Pools With Function

load "stdlib.ring"
load "threads.ring"

nTaskCount = 1  
THREAD_NUM = 4
aTaskQueue = list(256)
aThreads = list(THREAD_NUM)
mutexQueue = new_mtx_t()
condQueue = new_cnd_t()
res = 0
oTask = null

func main 
    oTask = new Task
    mtx_init(mutexQueue, res)
    cnd_init(condQueue)
		
		for i = 1 to THREAD_NUM
				aThreads[i] = new_thrd_t()
        if thrd_create(aThreads[i], "startThread()") != 1
            ? "Failed to create the thread"
        ok
    next
		for i = 1 to 100
        oTask{
						arg1 = random(100)+1
					  arg2 = random(100)+1
		        if i % 2 = 0  
						    taskFunction = :sum
						else 
		            taskFunction = :product
						ok
         }
        submitTask(oTask)
    next
    for i = 1 to THREAD_NUM
        if thrd_join(aThreads[i], :res) != 1
           ? "Failed to join the thread"
        ok
    next
		
    destroy_mtx_t(mutexQueue)
    destroy_cnd_t(condQueue)
  
func sum(a,b) 
    sleep(0.2)
    sum = a + b
    see "Sum of "+ a +" and "+ b +" is :" + sum  + nl
		
func product(a, b)
    sleep(0.2)
    prod = a * b
    see "Product "+ a +" and "+ b +" is :" + prod + nl


func executeTask(Task) 
    Task.StartTask(Task.arg1, Task.arg2)
     sleep(1)

func submitTask(Task)
    mtx_lock(mutexQueue)
    aTaskQueue[nTaskCount] = Task
    nTaskCount++
    mtx_unlock(mutexQueue)
    cnd_signal(condQueue)
	

func startThread()

    while True
        mtx_lock(mutexQueue)
        while nTaskCount = 1
            cnd_wait(condQueue, mutexQueue)
        end

        Task = aTaskQueue[1]
        for i = 1 to nTaskCount 
            aTaskQueue[i] = aTaskQueue[i + 1]
        next
        nTaskCount--
        mtx_unlock(mutexQueue)
        executeTask(Task)
    end

class Task 
    arg1 arg2 taskFunction

func StartTask(ar1, ar2)
	call taskFunction(ar1, ar2)

# Thread Pools
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023
# Description: Thread Pools With Function

load "stdlibcore.ring"
load "threads.ring"

lDebug     = false
nTaskCount = 1  
THREAD_NUM = 4
aTaskQueue = list(1024)
aThreads   = list(THREAD_NUM)
mutexQueue = new_mtx_t()
condQueue  = new_cnd_t()

func main 

    oTask = new Task
    mtx_init(mutexQueue, false)
    cnd_init(condQueue)
		
    for i = 1 to THREAD_NUM
        aThreads[i] = new_thrd_t()
        if thrd_create(aThreads[i], "startThread("+i+")") != 1
            if lDebug ? nl+"Failed to create the thread" ok
        else 
            if lDebug ? nl+"Creating thread: " + i ok
            thrd_detach(aThreads[i])
        ok
    next

    for i = 1 to 100
        oTask{
            arg1 = random(100)
            arg2 = random(100)
            if i % 2 = 0  
                taskFunction = :sum
            else 
                taskFunction = :product
            ok
        }
        submitTask(oTask)
    next

    oTask.taskFunction = :bye
    for i = 1 to THREAD_NUM
        submitTask(oTask)
    next

    give wait

    destroy_mtx_t(mutexQueue)
    destroy_cnd_t(condQueue)

    ? nl+"Thanks!"
  
func sum(a,b) 

    sum = a + b
    ? nl+"Sum of "+ a +" and "+ b +" is :" + sum  
		
func product(a, b)

    prod = a * b
    ? nl+"Product "+ a +" and "+ b +" is :" + prod 

func executeTask(Task) 

    Task.StartTask(Task.arg1, Task.arg2)

func submitTask(Task)

    mtx_lock(mutexQueue)
    aTaskQueue[nTaskCount] = Task
    nTaskCount++
    mtx_unlock(mutexQueue)
    cnd_signal(condQueue)
	

func startThread(nThread)

    if lDebug ? nl+"Start Thread: " + nThread ok

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

	if Task.taskFunction = :bye 
            if lDebug ? nl+"Terminate Thread: "+ nThread ok
	    exit 
	ok

        mtx_unlock(mutexQueue)

	if lDebug ? nl+"Execute Task by Thread: " + nThread ok
        executeTask(Task)
        sleep(0.01)

    end

    if lDebug ? nl+"End of thread: " + nThread ok

class Task 

    arg1 arg2 taskFunction

    func StartTask(ar1, ar2)
        call taskFunction(ar1, ar2)

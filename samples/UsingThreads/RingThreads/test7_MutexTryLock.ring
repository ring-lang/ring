# Mutex Trylock.
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023

load "stdlibcore.ring"
load "threads.ring"

# chefs = threads
# stove = shared data (+mutex)

aThreads    = list(10)
aStoveMutex = list(4)
aStoveFuel  = [100, 100, 100, 100]
res         = 0

func main
   
    for i = 1 to 4
        aStoveMutex[i] = new_mtx_t()
        mtx_init(aStoveMutex[i], res)
    next
    for i = 1 to 10
        aThreads[i] = new_thrd_t()
        thrd_create(aThreads[i],"routine()") 
    next

    for i = 1 to 10
        if thrd_join(aThreads[i], :res) != 1
            see "Failed to join thread" + nl
        ok
    next

func routine

    for i = 1 to 4
        if mtx_trylock(aStoveMutex[i]) = 1
            nFuelNeeded = random(30)
            if aStoveFuel[i] - nFuelNeeded < 0
                see "No more fuel... going home" + nl
            else 
                aStoveFuel[i] -= nFuelNeeded
                sleep(0.5)
                see "Fuel left :" ? aStoveFuel[i] +nl
            ok
            mtx_unlock(aStoveMutex[i])
            exit
        else 
            if i = 3
                see "No stove available yet, waiting..." + nl
                sleep(0.30)
                i = 1
            ok
        ok
    next

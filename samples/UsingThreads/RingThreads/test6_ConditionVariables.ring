# Condition Variables
# Author: Azzeddine Remmal (azzeddine.remmal@gmail.com)
# Date: 29-07-2023

load "stdlibcore.ring"
load "threads.ring"

aThreads  = list(2)
mutexFuel = new_mtx_t()
condFuel  = new_cnd_t()
fuel      = 0
res       = 0

func main
    
    mtx_init(mutexFuel, res)
    cnd_init(condFuel)
    for i = 1 to 2
        aThreads[i] = new_thrd_t()
        if i = 1
            thrd_create(aThreads[i],"fuel_filling()") 
        else
            thrd_create(aThreads[i],"car()")
        ok
    next

    for i = 1 to 2
        thrd_join(aThreads[i], :res) 
    next

func fuel_filling

    for i = 1 to 5
        mtx_lock(mutexFuel)
        fuel += 15
        see "Filled fuel..." + fuel + nl
        mtx_unlock(mutexFuel)
        cnd_signal(condFuel)
        sleep(1)
    next

func car

    mtx_lock(mutexFuel)
    while fuel < 40
        see "No fuel. Waiting..." + nl
        cnd_wait(condFuel, mutexFuel)
        # Equivalent to:
        # mtx_unlock(mutexFuel)
        # wait for signal on condFuel
        # mtx_lock(mutexFuel)
    end
    fuel -= 40
    see "Got fuel. Now left:" + fuel + nl
    mtx_unlock(mutexFuel)
func main

    subject   = new Subject
    observer1 = new ObserverA
    observer2 = new ObserverB

    subject.addObserver(observer1)
    subject.addObserver(observer2)

    subject.setValue(42)
    subject.setValue(99)

    subject.removeObserver(observer1)

    subject.setValue(101)

class Subject

    oObservers = []
    value      = 0

    func addObserver(observer)
        add(oObservers, ref(observer))

    func removeObserver(observer)
        nPos = find(oObservers,observer)
        if nPos 
            del(oObservers,nPos)
        ok

    func notify()
        for i = 1 to len(oObservers)
            oObservers[i].update(value)
        next

    func setValue(newValue)
        value = newValue
        notify()

class Observer

    func update(value)

        ? "Observer updated with value: " + value

class ObserverA from Observer

    func update(value)

        ? "ObserverA received value: " + value

class ObserverB from Observer

    func update(value)

        ? "ObserverB received value: " + value

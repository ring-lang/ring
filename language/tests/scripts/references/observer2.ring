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

    aObservers = []
    value      = 0

    func addObserver(observer)
        add(aObservers, ref(observer))

    func removeObserver(observer)
        nPos = find(aObservers,observer)
        if nPos 
            del(aObservers,nPos)
        ok

    func notify()
        for oObj in aObservers
            oObj.update(value)
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

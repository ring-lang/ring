func main 

    subject  = new Subject
    observer1 = new Observer("Observer 1 updated")
    observer2 = new Observer("Observer 2 updated")

    subject.attach(observer1)
    subject.attach(observer2)
    subject.notify()
    ? copy("*",18)

    subject.detach(observer1)
    subject.notify()

class Subject

    observers = []

    func attach(observer)
        observers + ref(observer)

    func detach observer 
	for t=1 to len(observers)
            if observers[t]=observer del(observers,t) exit ok
        next

    func notify
        for observer in observers
            observer.update()
        next

class Observer

    cMsg = "Observer updated"

    func init(cMessage)
        cMsg = cMessage

    func update
        ? cMsg
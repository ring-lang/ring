func main

    component = new Component
    decorator = new Decorator(component)
    decorator.operation()

class Component

    func operation()

        ? "Component operation"

class Decorator

    oComponent

    func init newComponent

        oComponent = ref(newComponent)

    func operation()

        oComponent.operation()
        ? "Decorator operation"

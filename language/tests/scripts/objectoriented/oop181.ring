# Based on a report by Youssef Saeed

? :start

new bst {
    insert(50)
    insert(30)
    insert(70)
    insert(20)
    insert(40)
    insert(60)
    insert(80)
    insert(10)
    insert(35)
    insert(45)
    insert(25)
}

? :done

class bst
    oRoot
    func insert nValue
        oRoot = insertNode(oRoot, nValue)
    func insertNode oNode, nValue
        if isNull(oNode)
            oNode = new bstNode
            oNode.value = nValue
            return oNode
        ok
        if nValue < oNode.value
            oNode.left = insertNode(oNode.left, nValue)
        elseif nValue > oNode.value
            oNode.right = insertNode(oNode.right, nValue)
        ok
        return oNode

class bstNode
    value left right
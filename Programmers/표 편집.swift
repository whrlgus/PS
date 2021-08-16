import Foundation

class Node {
    var prev: Node?
    var next: Node?
    let index: Int
    
    init(_ index: Int) {
        self.index = index
    }
}

func move(_ head: inout Node, amount: Int, toNext: Bool) {
    var cnt = amount
    while cnt > 0 {
        head = toNext ? head.next! : head.prev!
        cnt -= 1
    }
}

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var head = Node(0)
    var curr = head
    (1..<n).forEach { index in
        let next = Node(index)
        curr.next = next
        next.prev = curr
        curr = next
    }
    
    move(&head, amount: k, toNext: true)
    
    var result = Array(repeating: "O", count: n), stack = [Node]()
    cmd.forEach { command in
        let tmp = command.components(separatedBy: " ")
        switch tmp[0] {
        case "U", "D": move(&head, amount: Int(tmp[1])!, toNext: tmp[0] == "D")
        case "C":
            let curr = head
            head = curr.next ?? curr.prev!
            result[curr.index] = "X"
            curr.prev?.next = curr.next
            curr.next?.prev = curr.prev
            stack.append(curr)
        case "Z" :
            let curr = stack.removeLast()
            result[curr.index] = "O"
            curr.prev?.next = curr
            curr.next?.prev = curr
        default:break
        }
    }
    
    return result.joined()
}

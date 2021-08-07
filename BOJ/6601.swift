import Foundation

typealias Pos = (Int, Int)
let di = [-2, -2, -1, -1, 1, 1, 2, 2]
let dj = [-1, 1, -2, 2, -2, 2, -1, 1]

func getPos(_ val: String) -> (Int, Int) {
    let row = val.first!.asciiValue! - Character("a").asciiValue!
    let col = val.last!.asciiValue! - Character("1").asciiValue!
    return (Int(row), Int(col))
}

func findMinDist(_ a: Pos, _ b: Pos) -> Int {
    var chk = Array(repeating: Array(repeating: false, count: 8), count: 8)
    var queue = [a], dist = 0
    chk[a.0][a.1]=true
    while !queue.isEmpty {
        var count = queue.count
        while count > 0 {
            let curr = queue.first!
            queue = Array(queue.dropFirst())
            if curr == b {
                return dist
            }
            
            for idx in 0..<8 {
                let ni = curr.0 + di[idx]
                let nj = curr.1 + dj[idx]
                if (0..<8).contains(ni) && (0..<8).contains(nj) && !chk[ni][nj] {
                    queue.append((ni, nj))
                    chk[ni][nj]=true
                }
            }
            count -= 1
        }
        dist += 1
    }
    
    return -1
}

while let points = readLine()?.components(separatedBy: " ") {
    let n = findMinDist(getPos(points[0]), getPos(points[1]))
    print("To get from \(points[0]) to \(points[1]) takes \(n) knight moves.")
}



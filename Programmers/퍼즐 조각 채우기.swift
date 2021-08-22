import Foundation

typealias Pos = (Int, Int)
var n = 0
var b = [[Int]]()
var t = [[Int]]()
var cntB = [Int: Int]()
var cntT = [Int: Int]()
var visited = [[Int]]()
var ans = 0
let d = [(0, 1), (1, 0), (-1, 0), (0, -1)]

extension MutableCollection where Element: MutableCollection, Index == Int, Element.Index == Int {
    subscript(index: Pos) -> Element.Element {
        get { self[index.0][index.1] }
        set { self[index.0][index.1] = newValue }
    }
}

func +(_ left: Pos, _ right: Pos) -> Pos {
    return (left.0 + right.0, left.1 + right.1)
}

func isInBoundary(_ pos: Pos) -> Bool {
    return pos.0 >= 0 && pos.0 < n && pos.1 >= 0 && pos.1 < n
}

@discardableResult
func fill(_ arr: inout [[Int]], _ pos: Pos, _ val: Int) -> Int {
    var ret = 1
    arr[pos] = val
    for o in d {
        let np = pos + o
        if isInBoundary(np), arr[np] != -1, arr[np] != val {
            ret += fill(&arr, np, val)
        }
    }
    return ret
}

func check(_ bPos: (Int, Int), _ tPos:(Int, Int)) -> Bool {
    visited[bPos] = 1
    for o in d {
        let nbp = bPos + o, ntp = tPos + o
        guard isInBoundary(nbp), b[nbp] != -1, visited[nbp] == 0 else { continue }
        guard isInBoundary(ntp), t[ntp] != -1, check(nbp, ntp) else { return false }
    }
    return true
}

func assignNumber(_ arr: inout [[Int]]) -> [Int: Int] {
    var ret = [Int: Int]()
    var num = 1
    for i in 0..<n {
        for j in 0..<n where arr[i][j] == 0 {
            ret[num] = fill(&arr, (i, j), num)
            num += 1
        }
    }
    return ret
}

func foo(_ pos: Pos) -> Bool {
    var set = Set<Int>()
    for i in 0..<n {
        for j in 0..<n where !set.contains(t[i][j]) {
            fill(&visited, pos, 0)
            set.insert(t[i][j])
            if check(pos, (i, j)), cntB[b[pos]] == cntT[t[i][j]] {
                ans += fill(&t, (i, j), -1)
                return true
            }
        }
    }
    return false
}

func rotateTable() {
    let tmp = t
    for i in 0..<n {
        let k = n - i - 1
        tmp[i].enumerated().forEach { t[$0][k] = $1 }
    }
}

func solution(_ game_board:[[Int]], _ table:[[Int]]) -> Int {
    n = game_board.count
    b = game_board.map { $0.map { $0^1 - 1} }
    visited = b
    t = table.map { $0.map { $0 - 1} }
    cntB = assignNumber(&b)
    cntT = assignNumber(&t)
    
    var set = Set<Int>()
    for i in 0..<n {
        for j in 0..<n where b[i][j] != -1 && !set.contains(b[i][j]) {
            set.insert(b[i][j])
            for _ in 0..<4 {
                if foo((i,j)) { break }
                rotateTable()
            }
        }
    }
    
    return ans
}

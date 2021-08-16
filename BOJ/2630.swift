import Foundation

func isEqual(_ i: Int, _ j: Int, _ n: Int) -> Bool {
    for r in i..<i+n {
        for c in j..<j+n {
            if p[r][c] != p[i][j] {
                return false
            }
        }
    }
    return true
}

func sol(_ i: Int, _ j: Int, _ n: Int) {
    if isEqual(i, j, n) {
        ans[p[i][j]] += 1
    } else {
        let m = n / 2
        sol(i, j, m)
        sol(i + m, j, m)
        sol(i, j + m, m)
        sol(i + m, j + m, m)
    }
}


let n = Int(readLine()!)!
let p = (0..<n).map { _ in readLine()!.components(separatedBy: " ").map({ Int($0)! }) }
var ans = [0, 0]
sol(0, 0, n)
print(ans[0], ans[1], separator: "\n")

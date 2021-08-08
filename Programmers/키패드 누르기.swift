import Foundation

let keys = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [-1, 0, -1]]

func solution(_ numbers:[Int], _ hand:String) -> String {
    var pos = [Int: (Int, Int)]()
    for (row, arr) in keys.enumerated() {
        for (col, num) in arr.enumerated() {
            pos[num] = (row, col)
        }
    }
    
    let h = hand == "left" ? "L" : "R"
    var left = (3, 0), right = (3, 2), ret = ""
    for num in numbers {
        guard
            let col = pos[num]?.1,
            let row = pos[num]?.0
        else { break }
        
        if col == 0 {
            ret += "L"
            left = (row, col)
        } else if col == 2 {
            ret += "R"
            right = (row, col)
        } else {
            let ld = abs(left.0 - row) + abs(left.1 - col)
            let rd = abs(right.0 - row) + abs(right.1 - col)
            if ld == rd {
                ret += h
                if h == "L" {
                    left = (row, col)
                } else {
                    right = (row, col)
                }
            } else if ld < rd {
                ret += "L"
                left = (row, col)
            } else {
                ret += "R"
                right = (row, col)
            }
        }
    }
    
    return ret
}

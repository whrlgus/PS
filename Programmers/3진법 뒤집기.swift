import Foundation

func solution(_ n:Int) -> Int {
    var val = n, arr = [Int]()
    while val != 0 {
        arr.append(val % 3)
        val /= 3
    }
    
    var ret = 0, mul = 1
    for num in arr.reversed() {
        ret += mul * num
        mul *= 3
    }
    
    return ret
}

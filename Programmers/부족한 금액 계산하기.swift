import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    let val = Int64(count)
    let tmp = val * (val + 1) / 2
    let result = Int64(price) * tmp - Int64(money)
    return result < 0 ? 0 : result
}

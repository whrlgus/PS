import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var zeroCnt = 0, equalCnt = 0
    for num in lottos {
        if win_nums.contains(num) {
            equalCnt += 1
        }
        if num == 0 {
            zeroCnt += 1
        }
    }
    var mx = 7 - equalCnt - zeroCnt, mn = 7 - equalCnt
    return [min(mx, 6), min(mn, 6)]
}

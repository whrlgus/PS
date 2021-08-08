import Foundation

let words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

func solution(_ s:String) -> Int {
    var ret = s
    for (idx, word) in words.enumerated() {
        while let range = ret.range(of: word) {
            ret.replaceSubrange(range, with: "\(idx)")
        }
    }
    return Int(ret) ?? 0
}

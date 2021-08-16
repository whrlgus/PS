import Foundation

func solution(_ scores:[[Int]]) -> String {
    var result = ""
    let count = scores.count
    for col in 0..<count{
        var sum = 0, mn = 100, mx = 0
        for row in 0..<count {
            let score = scores[row][col]
            sum += score
            if row == col { continue }
            mn = min(mn, score)
            mx = max(mx, score)
        }
        
        let myScore = scores[col][col], avg: Double
        if myScore < mn && myScore > mx {
            avg = Double(sum - myScore) / Double(count - 1)
        } else {
            avg = Double(sum) / Double(count)
        }
        
        let grade: String
        switch avg {
        case 90...100: grade = "A"
        case 80..<90: grade = "B"
        case 70..<80: grade = "C"
        case 50..<70: grade = "D"
        default: grade = "F"
        }
        result += grade
    }
    return result
}

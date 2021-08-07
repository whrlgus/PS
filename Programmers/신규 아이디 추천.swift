import Foundation

func solution(_ new_id:String) -> String {
    var result = new_id
    result = result.lowercased()
    result = result.filter { "-_.".contains($0) || $0.isNumber || $0.isLetter }
    result = result.reduce("") {
        if $0.last == $1 && $1 == Character(".") {
            return $0
        } else {
            return $0 + String($1)
        }
    }
    if result.first == Character(".") {
        result.removeFirst()
    }
    if result.last == Character(".") {
        result.removeLast()
    }
    if result.isEmpty {
        result = "a"
    }
    result = String(result.prefix(15))
    if result.last == Character(".") {
        result.removeLast()
    }
    if let last = result.last {
        result += String(repeating: last, count: max(0, 3 - result.count))
    }
    
    return result
}



let input = readLine()!.split{$0 == " "}.map{Int($0)!}
let (n, m) = (input[0], input[1])
var p = [Int]()
for _ in 1...m { p.append(Int(readLine()!)!) }
p.sort()

var minPrice = 0, maxProfit = 0
for i in 0..<m {
	let profit = min(n, m - i) * p[i]
	if maxProfit < profit {
		maxProfit = profit
		minPrice = p[i]
	}
}
print("\(minPrice) \(maxProfit)")

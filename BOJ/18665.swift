import Foundation

func sol(){
	let n = Int64(readLine()!)!
	var ans = [(Int64, Int64)]()
	func wow(_ num: Int64){
		var x = Int64(sqrt(Double(num)))
		if x * x != num { x += 1 }
		let y = x * x - num
		
		if x > 2 { wow(x) }
		if y > 2 { wow(y) }
		for i in 0..<ans.count{
			if ans[i].0 == x && ans[i].1 == y { return }
		}
		ans.append((x,y))
		print("\(x) \(y)")
	}
	wow(n)
}
//sol()

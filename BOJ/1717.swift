func sol() {
	let read = {readLine()!.split{$0 == " "}.map{Int($0)!}}
	let nm = read()
	var p = Array(repeating: -1, count: nm[0] + 1)
	
	func find(_ x: Int) -> Int {
		if p[x] < 0 { return x }
		p[x] = find(p[x])
		return p[x]
	}
	
	for _ in 1...nm[1] {
		let t = read()
		let ra = find(t[1]), rb = find(t[2])
		if t[0] == 0 {
			if ra != rb { p[ra] = rb }
		} else {
			print(ra == rb ? "YES" : "NO")
		}
	}
}
//sol()

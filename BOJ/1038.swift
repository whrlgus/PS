func sol() {
	let n = Int(readLine()!)!
	var s = [Int64](), a: [Int64] = Array(0...9)
	func dfs(_ i: Int, _ val: Int64) {
		if i < 0 {
			s.append(val)
			return
		}
		dfs(i - 1, val)
		dfs(i - 1, val * 10 + a[i])
	}
	dfs(9, 0)
	print(n > 1022 ? -1 : s.sorted()[n + 1] )
}
//sol()

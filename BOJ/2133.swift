func sol() {
	let N = Int(readLine()!)!
	var s = Array(repeating: Array(repeating: -1, count: 8), count: N + 1)
	func count(_ n: Int, _ k: Int) -> Int {
		if n < 0 { return 0 }
		if n == 0 { return k == 0 ? 1 : 0 }
		if s[n][k] != -1 { return s[n][k] }
		
		if k == 0 { s[n][k] = count(n - 2, 0) + count(n - 1, 1) + count(n - 1, 4) }
		else if k == 1 { s[n][k] = count(n - 1, 0) + count(n - 1, 6) }
		else if k == 3 { s[n][k] = count(n - 1, 4) }
		else if k == 4 { s[n][k] = count(n - 1, 0) + count(n - 1, 3) }
		else if k == 6 { s[n][k] = count(n - 1, 1) }
		else { s[n][k] = count(n - 1, 0) }
		
		return s[n][k]
	}
	print(count(N, 0))
}
//sol()

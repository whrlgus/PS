var n = 123456 * 2, a = Array(repeating: true, count: n + 1), i = 2
while i * i <= n {
	if a[i] {
		var j = i + i
		while j <= n {
			a[j] = false
			j += i
		}
	}
	i += 1
}

n /= 2
var b = [0, 1, 1]
for i in 3...n {
	var cnt = b.last!
	if a[i] { cnt -= 1 }
	if a[2 * i - 1] { cnt += 1 }
	if a[2 * i] { cnt += 1 }
	b.append(cnt)
}

while true {
	n = Int(readLine()!)!
	if n == 0 { break }
	print(b[n])
}

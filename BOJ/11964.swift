let input = readLine()!.split{$0 == " "}.map{Int($0)!}
let (t, a, b) = (input[0], input[1], input[2])

var s = Array(repeating: false, count: 2 * t + 1)
s[0] = true
for i in 0...t {
	if s[i] {
		s[i / 2] = true
		s[i + a] = true
		s[i + b] = true
	}
}

var ans = 0
for i in 0...t {
	if s[i] {
		s[i + a] = true
		s[i + b] = true
		ans = i
	}
}

print(ans)

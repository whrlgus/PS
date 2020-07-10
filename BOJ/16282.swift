let n = Int(readLine()!)!
var a = 7, b = 4, cnt = 1
while n > a {
	a = 2 * (a + b) + 1
	b *= 2
	cnt += 1
}
print(cnt)

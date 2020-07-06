func sol(){
	let nk=readLine()!.split(separator: " ").map{Int($0)!},n=nk[0]
	let a=readLine()!.split(separator: " ").map{Int($0)!}
	
	var s=Array(repeating: Array(repeating: 200, count: n), count: n)
	for i in 0..<n{s[i][i]=0}
	for d in 1..<n{
		for i in 0..<n-d{
			let j=i+d
			for k in i..<j{
				s[i][j]=min(s[i][j],s[i][k]+s[k+1][j]+(a[i]==a[k+1] ? 0:1))
			}
		}
	}
	print(s[0][n-1])
}
//sol()

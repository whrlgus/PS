func sol(){
	let nmk=readLine()!.split(separator: " ").map{Int($0)!},n=nmk[0],m=nmk[1],k=nmk[2],INF = Int(-3e6)
	var a=Array(repeating: [(Int,Int)](), count: n+1),s=Array(repeating: Array(repeating: -1, count: m), count: n+1)
	for _ in 1...k{
		let info=readLine()!.split(separator: " ").map{Int($0)!}
		if info[1]>info[0] {a[info[1]].append((info[0],info[2]))}
	}
	
	func maxSum(_ i:Int,_ j:Int)->Int{
		if j<0{return INF}
		if i==1{return 0}
		if s[i][j] != -1{return s[i][j]}
		s[i][j]=INF
		for k in 0..<a[i].count{
			s[i][j]=max(s[i][j],maxSum(a[i][k].0, j-1)+a[i][k].1)
		}
		return s[i][j]
	}
	print(maxSum(n, m-1))
}
//sol()

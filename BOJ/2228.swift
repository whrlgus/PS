func sol(){
	let nm=readLine()!.split(separator: " ").map{Int($0)!},n=nm[0],m=nm[1],INF = -3276800
	var a=[Int](),s=Array(repeating: Array(repeating: -1, count: m), count: n)
	for _ in 1...n{
		a.append(Int(readLine()!)!)
	}
	
	var c=a
	for i in 1..<n{
		c[i]=max(c[i-1]+a[i],a[i])
	}
	
	func maxSum(_ i:Int, _ j:Int)->Int{
		if i<2&&j>0{return INF}
		if j==0{return c[i]}
		if s[i][j] != -1{return s[i][j]}
		s[i][j]=maxSum(i-1, j)
		for k in 0...i-2{
			s[i][j]=max(s[i][j],maxSum(k, j-1))
		}
		s[i][j]+=a[i]
		return s[i][j]
	}
	
	var ans=INF
	for i in 0..<n{
		ans=max(ans,maxSum(i, m-1))
	}
	print(ans)
}
//sol()



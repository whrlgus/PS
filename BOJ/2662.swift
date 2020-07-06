func sol(){
	let nm=readLine()!.split(separator: " ").map{Int($0)!},n=nm[0],m=nm[1]
	
	var a=Array(repeating: Array(repeating: 0, count: n+1), count: m+1)
	for _ in 1...n{
		let input=readLine()!.split(separator: " ").map{Int($0)!}
		for i in 1...m{
			a[i][input[0]]=input[i]
		}
	}
	
	var s=Array(repeating: Array(repeating: Array(repeating: -1, count: 2), count: n+1), count: m+1)
	func maxProfit(_ i:Int,_ remains:Int)->Int{
		if i>m{return 0}

		var ret=s[i][remains][0]
		if ret != -1{return ret}
		
		ret=0
		for money in 0...remains{
			let tmp=maxProfit(i+1, remains-money)+a[i][money]
			if ret<tmp{
				ret=tmp
				s[i][remains][1]=money
			}
		}
		s[i][remains][0]=ret
		return ret
	}
	
	print(maxProfit(0,n))
	
	var remains=n
	for i in 1...m{
		var mxVal=0,money=0
		for j in 0...remains{
			if mxVal<s[i][j][0]{
				mxVal=s[i][j][0]
				money=s[i][j][1]
			}
		}
		remains-=money
		print(money,terminator:" ")
	}
	
}
//sol()




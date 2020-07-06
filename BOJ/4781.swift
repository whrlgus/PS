func sol(){
	while true{
		let nm=readLine()!.split(separator: " "),n=Int(nm[0])!,m=Int(Double(nm[1])!*100+0.5)
		if n==0&&m==0{break}
		var s=Array(repeating: 0, count: m+1)
		for _ in 0..<n{
			let cp=readLine()!.split(separator: " "),c=Int(cp[0])!,p=Int(Double(cp[1])!*100+0.5)
			var i=p
			while i<=m{
				s[i]=max(s[i],s[i-p]+c)
				i+=1
			}
		}
		print(s[m])
	}
}
//sol()

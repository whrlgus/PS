func sol(){
	let n=Int(readLine()!)!,MOD=Int(1e6)
	var s=Array(repeating: Array(repeating: Array(repeating: Array(repeating: -1, count: 3), count: 2), count: 3), count: n)
	func count(_ i:Int, _ op:Int, _ lCnt:Int, _ aSeqCnt:Int)->Int{
		if lCnt==2||aSeqCnt==3{return 0}
		if i==n-1{return 1}
		
		var tmp=s[i][op][lCnt][aSeqCnt]
		if tmp != -1{return tmp}
		
		let j=i+1
		tmp=(count(j,0,lCnt,0)+count(j,1,lCnt+1,0)+count(j,2,lCnt,aSeqCnt+1))%MOD
		s[i][op][lCnt][aSeqCnt]=tmp
		return tmp
	}
	print((count(0,0,0,0)+count(0,1,1,0)+count(0,2,0,1))%MOD)
}
//sol()

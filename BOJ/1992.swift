func sol_1992(){
	let n=Int(readLine()!)!
	var a=[[Character]]()
	for _ in 1...n{
		a.append(Array(readLine()!))
	}
	
	func allEqual(_ si:Int,_ sj:Int,_ n:Int)->Bool{
		for i in si..<si+n{
			for j in sj..<sj+n{
				if a[si][sj] != a[i][j]{
					return false
				}
			}
		}
		return true
	}
	
	func compress(_ si:Int,_ sj:Int,_ n:Int){
		if allEqual(si, sj, n){
			print(a[si][sj],terminator:"")
		}else{
			print("(",terminator:"")
			let m=n/2
			compress(si, sj, m)
			compress(si, sj+m, m)
			compress(si+m, sj, m)
			compress(si+m, sj+m, m)
			print(")",terminator:"")
		}
	}
	compress(0,0,n)
}
//sol_1992()

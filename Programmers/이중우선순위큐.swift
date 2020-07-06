import Foundation

func solution(_ operations:[String]) -> [Int] {
	var a=[Int]()
	
	func insert(_ x:Int){
		var l=0,r=a.count-1
		while l<=r{
			let m=(l+r)/2
			if x<a[m]{r=m-1}
			else{l=m+1}
		}
		a.insert(x, at: l)
	}
	
	for i in 0..<operations.count{
		let tmp=operations[i].split(separator: " "),x=Int(tmp[1])!
		if tmp[0]=="I"{
			if a.isEmpty{a.append(x)}
			else {insert(x)}
		}else if !a.isEmpty{
			if x==1{a.removeLast()}
			else{a.removeFirst()}
		}
	}
	
	return a.isEmpty ? [0,0] : [a[0],a[a.count-1]]
}

import Foundation

func solution(_ cookie:[Int]) -> Int {
	if cookie.count==1{
		return 0
	}
	var s=[0]
	for cnt in cookie{
		s.append(s.last!+cnt)
	}
	
	func isExist(_ val: Int, _ start: Int) -> Bool{
		let offset=s[start-1]
		var l=start,r=cookie.count
		while(l<=r){
			let m=(l+r)/2, tmp=s[m]-offset
			if tmp==val{return true}
			if tmp<val{l=m+1}
			else{r=m-1}
		}
		return false
	}
	
	var ans=0
	for l in 1..<cookie.count{
		for m in l...cookie.count{
			let val=s[m]-s[l-1]
			if val>s[cookie.count]-s[m]{break}
			if val<ans{continue}
			if isExist(val,m+1){ans=max(ans,val)}
		}
	}
	
	return ans
}

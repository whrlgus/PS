import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
	var p=Array(repeating: -1, count: n)
	func find(_ x:Int)->Int{
		if p[x]<0{return x}
		p[x]=find(p[x])
		return p[x]
	}
	
	let s=costs.sorted{$0[2]<$1[2]}
	var cnt=0,ans=0
	for i in 0..<s.count{
		let ra=find(s[i][0]),rb=find(s[i][1])
		if ra==rb{continue}
		p[ra]=rb
		ans+=s[i][2]
		cnt+=1
		if cnt==n{break}
	}
    return ans
}

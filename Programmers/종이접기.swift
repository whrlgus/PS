import Foundation

func solution(_ n:Int) -> [Int] {
	var ans=[Int]()
	for _ in 1...n{
		ans.append(0)
		var i=ans.count-2
		while i>=0{
			ans.append(ans[i]^1)
			i-=1
		}
	}
    return ans
}

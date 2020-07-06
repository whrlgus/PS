import Foundation

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int{
	var answer = 0, prev=0
	let range=Double(2*w+1)
	for curr in stations{
		let tmp=curr-w-1-prev
		if tmp>0{
			answer += Int(ceil(Double(tmp)/range))
		}
		prev = curr+w
	}
	let tmp=n-prev
	if tmp>0{
		answer += Int(ceil(Double(tmp)/range))
	}
    return answer
}

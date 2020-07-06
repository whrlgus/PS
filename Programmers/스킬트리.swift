import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
	let dic = Dictionary(uniqueKeysWithValues: skill.enumerated().map{($1,$0)})
	var ans = 0
	for s in skill_trees{
		var poss = 1, prev = -1
		for c in s{
			if let curr = dic[c]{
				if curr - 1 != prev{
					poss = 0
					break
				}
				prev = curr
			}
		}
		ans += poss
	}
    return ans
}

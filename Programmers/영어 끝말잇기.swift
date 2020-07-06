import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
	var prev=words[0].last, m:Set<String>=[words[0]]
	for i in 1..<words.count{
		if words[i].first != prev || m.contains(words[i]){
			return [i%n+1,i/n+1]
		}
		prev=words[i].last
		m.insert(words[i])
	}
    return [0,0]
}

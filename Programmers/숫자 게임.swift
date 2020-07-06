import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
	let sb=b.sorted()
	var ans=0, i=0
	for val in a.sorted(){
		while i<b.count, sb[i]<=val{i+=1}
		if i==b.count{break}
		ans+=1
		i+=1
	}
    return ans
}

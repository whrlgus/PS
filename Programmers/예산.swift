import Foundation

func solution(_ d:[Int], _ budget:Int) -> Int {
	var cnt=0, remains=budget
	for money in d.sorted(){
		if money>remains{
			break
		}
		cnt+=1
		remains-=money
	}
    return cnt
}

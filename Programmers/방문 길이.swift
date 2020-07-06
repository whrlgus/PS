import Foundation

func solution(_ dirs:String) -> Int {
	var vis=Array(repeating: Array(repeating: false, count: 11*11), count: 11*11), prev=5*11+5, ans=0
	let offset:[Character:Int]=["U":-11,"D":11,"R":1,"L":-1]
	for dir in Array(dirs){
		if prev%11==0&&dir=="L"||prev%11==10&&dir=="R"||prev/11==0&&dir=="U"||prev/11==10&&dir=="D"{
			continue
		}
		let curr=prev+offset[dir]!
		if !vis[prev][curr]{
			ans+=1
			vis[prev][curr]=true
			vis[curr][prev]=true
		}
		prev=curr
	}
	
    return ans
}

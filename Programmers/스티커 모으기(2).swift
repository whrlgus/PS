import Foundation

func solution(_ sticker:[Int]) -> Int{
	if sticker.count==1{
		return sticker.first!
	}
	
	var s=[[],[sticker[0],0]]
	for i in 1..<sticker.count-1{
		s.append([max(s[i][1],s[i][0]),s[i][0]+sticker[i+1]])
	}
	let mxS=s[sticker.count-1][0]
	
	var t=[[],[0,sticker[1]]]
	for i in 1..<sticker.count-1{
		t.append([max(t[i][1],t[i][0]),t[i][0]+sticker[i+1]])
	}
	let mxT=max(t[sticker.count-1][0],t[sticker.count-1][1])
	
	return max(mxS,mxT)
}

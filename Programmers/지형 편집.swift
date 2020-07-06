import Foundation

func solution(_ land:[[Int]], _ p:Int, _ q:Int) -> Int64 {
	var h=[Int]()
	for i in 0..<land.count{
		for j in 0..<land.count{
			h.append(land[i][j])
		}
	}
	h.sort(by: <)
	
	var price:Int64=0
	for i in 1..<h.count{
		price+=Int64(h[i]-h[0])*Int64(q)
	}
	
	var ans=price
	for i in 1..<h.count{
		price+=Int64(p)*Int64(i)*Int64(h[i]-h[i-1])
		price-=Int64(q)*Int64(h.count-i)*Int64(h[i]-h[i-1])
		ans=min(ans,price)
	}
	return ans
}

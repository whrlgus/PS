import Foundation

func gcd(_ a:Int, _ b:Int) -> Int{
	return b==0 ? a : gcd(b, a%b)
}

func solution(_ w:Int, _ h:Int) -> Int64{
	let n=gcd(w, h),a=Double(h)/Double(w)
	var cnt=0
	for i in 1...w/n{
		cnt+=Int(ceil(a*Double(i))-floor(a*Double(i-1)))
	}
    return Int64(w*h-n*cnt)
}

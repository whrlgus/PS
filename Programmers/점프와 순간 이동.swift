import Foundation

func solution(_ n:Int) -> Int{
    var ans=0,val=n
	while val>0{
		if val%2==0{
			val/=2
		}else{
			val-=1
			ans+=1
		}
	}
    return ans
}

import Foundation

func solution(_ distance:Int, _ rocks:[Int], _ n:Int) -> Int {
    let sortedRocks=rocks.sorted()

    func getMin(greaterThan lim:Int)->Int?{
        var prev=0,cnt=0,mn=distance
		for i in 0..<sortedRocks.count{
            let diff=sortedRocks[i]-prev
            if diff<=lim{
                if cnt==n{return nil}
                cnt+=1
            }else{
                mn=min(mn,diff)
                prev=sortedRocks[i]
            }
        }
        return mn
    }

    var l=0,r=distance+1,ans=0
    while l<r{
        let m=(l+r)/2
        if let mn=getMin(greaterThan: m){
            ans=max(ans,mn)
            l=m+1
        }else{
            r=m
        }
    }

    return ans
}

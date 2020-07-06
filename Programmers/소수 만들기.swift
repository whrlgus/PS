import Foundation

func findPrimeNumber() -> [Bool]{
	let n=3000
	var ret=Array(repeating: true, count: n),i=2
	ret[1]=false
	i=2
	while i*i<n{
		if ret[i]{
			var j=i*2
			while j<n{
				ret[j]=false
				j+=i
			}
		}
		i+=1
	}
	return ret
}

func solution(_ nums:[Int]) -> Int {
	let isPrime=findPrimeNumber()
	var answer = 0
	for i in 0...nums.count-3{
		for j in i+1...nums.count-2{
			for k in j+1...nums.count-1{
				if isPrime[nums[i]+nums[j]+nums[k]]{
					answer+=1
				}
			}
		}
	}
	return answer
}

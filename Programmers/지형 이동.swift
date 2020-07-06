import Foundation
typealias Info = (Int,Int,Int)
var heap=[(-1,-1,-1),(0,0,0)]

func push_heap(_ info:Info){
	var i=heap.count
	heap.append(info)
	while i>1{
		let j=i>>1
		if heap[j].0>heap[i].0{
			heap.swapAt(j, i)
		}else{
			break
		}
		i=j
	}
}

func pop_heap() -> Info{
	heap.swapAt(1, heap.count-1)
	let ret=heap.removeLast()
	var i=1
	while true{
		var j=i<<1,idx=0
		if j<heap.count,heap[i].0>heap[j].0{
			idx=j
		}
		if j+1<heap.count,heap[i].0>heap[j+1].0,heap[j].0>heap[j+1].0{
			idx=j+1
		}
		if idx<1{
			break
		}
		heap.swapAt(i, idx)
		i=idx
	}
	return ret
}

func solution(_ land:[[Int]], _ height:Int) -> Int {
	let di=[0,0,1,-1],dj=[1,-1,0,0],n=land.count
	var vis=Array(repeating: Array(repeating: false, count: n), count:n)
	
	func dfs(_ i:Int, _ j:Int){
		vis[i][j]=true
		for d in 0...3{
			let ni=i+di[d],nj=j+dj[d]
			if ni>=0,nj>=0,ni<n,nj<n,!vis[ni][nj]{
				let diff=abs(land[i][j]-land[ni][nj])
				if diff>height{
					push_heap((diff,ni,nj))
				}else{
					dfs(ni, nj)
				}
			}
		}
	}
	
	var ans=0
	while(heap.count>1){
		let info=pop_heap()
		if vis[info.1][info.2]{continue}
		ans+=info.0
		dfs(info.1, info.2)
	}
    return ans
}

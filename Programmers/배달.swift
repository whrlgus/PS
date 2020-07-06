import Foundation

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    let INF=500001
	var dist=Array(repeating: Array(repeating: INF, count: N+1), count: N+1)
	for e in road {
		if dist[e[0]][e[1]] > e[2]{
			dist[e[0]][e[1]]=e[2]
			dist[e[1]][e[0]]=e[2]
		}
	}
	for i in 1...N{
		dist[i][i]=0
	}
	for k in 1...N{
		for i in 1...N{
			for j in 1...N{
				if dist[i][k] != INF,dist[k][j] != INF{
					dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j])
				}
			}
		}
	}
	
	var ans=0
	for i in 1...N{
		if dist[1][i] <= k{
			ans+=1
		}
	}
    return ans
}

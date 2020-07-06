import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
	var top=[Int]()
	for c in 0..<board[0].count{
		var pos=board.count
		for r in 0..<board.count{
			if board[r][c] > 0{
				pos=r
				break;
			}
		}
		top.append(pos)
	}
	
	var ans=0,basket=[Int]()
	for i in 0..<moves.count{
		let c=moves[i]-1
		if top[c]==board.count{continue}
		let curr=board[top[c]][c], prev=basket.last
		top[c]+=1

		if prev != nil,prev==curr{
			basket.removeLast()
			ans+=2
		}
		else{basket.append(curr)}
	}
    return ans
}

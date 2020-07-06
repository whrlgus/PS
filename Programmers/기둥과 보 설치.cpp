#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int N,s[101][101][2];

bool canBuild(int x, int y, int a){
	if(!a){	// 기둥
		if(y==0||s[x][y-1][0]||					// 바닥 or 다른 기둥 위
		   s[x][y][1]||(x>0&&s[x-1][y][1]))		// 보의 한쪽 끝 위
		   return true;
	}else{	// 보
		if(s[x][y-1][0]||s[x+1][y-1][0]||		// 기둥 위
		   (x>0&&s[x-1][y][1]&&s[x+1][y][1]))	// 양쪽 끝 보
			return true;
	}
	return false;
}

bool canRemove(int x, int y, int a){
	if(!a){	// 기둥
		if((x>0&&s[x-1][y+1][1]&&!canBuild(x-1,y+1,1))||	// 왼쪽 위 보
		   (s[x][y+1][1]&&!canBuild(x,y+1,1))||				// 위 보
		   (s[x][y+1][0]&&!canBuild(x,y+1,0)))				// 위 기둥
			return false;
	}else{	// 보
		if((s[x][y][0]&&!canBuild(x,y,0))||					// 위 기둥
		   (s[x+1][y][0]&&!canBuild(x+1,y,0))||				// 오른쫀 위 기둥
		   (x>0&&s[x-1][y][1]&&!canBuild(x-1,y,1))||		// 왼쪽 보
		   (s[x+1][y][1]&&!canBuild(x+1,y,1)))				// 오른쪽 보
			return false;
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N=n;
	for(auto &f:build_frame){
		int x=f[0],y=f[1],a=f[2],b=f[3];
		s[x][y][a]^=1;
		if((b&&!canBuild(x,y,a))||!canRemove(x,y,a))s[x][y][a]^=1;
	}
	
    vector<vector<int>> answer;
	f(x,0,n)f(y,0,n)f(a,0,1)if(s[x][y][a])answer.push_back({x,y,a});
    return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solution(5, {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}});
	return 0;
}

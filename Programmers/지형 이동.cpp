#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

vector<vector<int>> l;
struct info{
	int diff,i,j;
	bool operator<(const info &oth)const{
		return diff>oth.diff;
	}
};
priority_queue<info> q;
int n,h,di[]={0,0,1,-1},dj[]={1,-1,0,0};
bool vis[300][300];

void dfs(int i, int j){
	vis[i][j]=true;
	f(d,0,4){
		int ni=i+di[d],nj=j+dj[d];
		if(ni>=0&&nj>=0&&ni<n&&nj<n&&!vis[ni][nj]){
			int diff=abs(l[i][j]-l[ni][nj]);
			if(diff>h)q.push({diff,ni,nj});
			else dfs(ni,nj);
		}
	}
}

int solution(vector<vector<int>> land, int height) {
	land.swap(l);
	n=l.size();
	h=height;
	q.push({0,0,0});
	int ans=0;
	while(!q.empty()){
		int diff=q.top().diff,i=q.top().i,j=q.top().j;q.pop();
		if(vis[i][j])continue;
		ans+=diff;
		dfs(i,j);
	}
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout<<solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1);
	return 0;
}

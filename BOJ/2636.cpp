#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,a[101][101],ans[2],di[]={0,0,1,-1},dj[]={1,-1,0,0};
bool vis[101][101];
queue<pair<int,int>> q;

void pushPos(int i,int j){
	f(d,0,3){
		int ni=i+di[d],nj=j+dj[d];
		if(ni<0||nj<0||ni>n||nj>m||vis[ni][nj])continue;
		vis[ni][nj]=true;
		if(a[ni][nj])q.push({ni,nj});
		else pushPos(ni, nj);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,1,n)f(j,1,m)cin>>a[i][j];
	vis[0][0]=true;
	pushPos(0, 0);
	
	while(!q.empty()){
		ans[1]=q.size();
		f(k,1,ans[1]){
			int i=q.front().first,j=q.front().second;q.pop();
			a[i][j]=0;
			pushPos(i, j);
		}
		++ans[0];
	}
	cout<<ans[0]<<'\n'<<ans[1];
	return 0;
}

#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int r,c,di[]={0,0,1,-1},dj[]={1,-1,0,0};
char m[52][52];
bool vis[51][51];
struct pos{int i, j;};

int maxDist(int si, int sj){
	memset(vis,false,sizeof(vis));
	vis[si][sj]=true;
	queue<pos> q;
	q.push({si,sj});
	int ret=0;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int i=q.front().i,j=q.front().j;q.pop();
			f(d,0,3){
				int ni=i+di[d],nj=j+dj[d];
				if(ni>0&&nj>0&&ni<=r&&nj<=c&&m[ni][nj]=='L'&&!vis[ni][nj]){
					vis[ni][nj]=true;
					q.push({ni,nj});
				}
			}
		}
		++ret;
	}
	return ret-1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>r>>c;
	f(i,1,r)cin>>&m[i][1];
	
	int ans=0;
	f(i,1,r)f(j,1,c)if(m[i][j]=='L'){
		if(m[i-1][j]=='L'&&m[i+1][j]=='L'||m[i][j-1]=='L'&&m[i][j+1]=='L')continue;
		ans=max(ans,maxDist(i,j));
	}
	cout<<ans;
	
	return 0;
}

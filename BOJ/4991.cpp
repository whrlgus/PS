#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
struct pos{int i,j;}vertex[12];
int w,h,ans,idx,s[12][12],di[]={0,0,1,-1},dj[]={1,-1,0,0};
char m[22][22];
bool vis[21][21],noPath;

void calcDist(int u,int cnt){
	memset(vis,false,sizeof(vis));
	vis[vertex[u].i][vertex[u].j]=true;
	queue<pos> q;
	q.push(vertex[u]);
	int dist=1;
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int i=q.front().i,j=q.front().j;q.pop();
			f(d,0,3){
				int ni=i+di[d],nj=j+dj[d];
				if(ni<1||nj<1||ni>h||nj>w||vis[ni][nj]||!m[ni][nj])continue;
				vis[ni][nj]=true;
				if('0'<=m[ni][nj]&&m[ni][nj]<='9'){
					s[u][m[ni][nj]-'0'+1]=dist;
					if(--cnt==0)return;
				}
				if(m[ni][nj]!='x')q.push({ni,nj});
			}
		}
		++dist;
	}
	noPath=true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(cin>>w>>h,w&&h){
		idx=0;
		memset(m[h+1],0,w+1);
		noPath=false;
		
		f(i,1,h){
			cin>>&m[i][1];
			f(j,1,w){
				if(m[i][j]=='o')vertex[0]={i,j};
				else if(m[i][j]=='*'){
					m[i][j]='0'+idx;
					vertex[++idx]={i,j};
				}
			}
		}
		
		if(idx==0){
			cout<<0<<'\n';
			continue;
		}
		
		calcDist(0,idx);
		f(i,1,idx)calcDist(i,idx-1);
		
		if(noPath){
			cout<<-1<<'\n';
			continue;
		}
		
		vector<int> v;
		f(i,1,idx)v.push_back(i);
		int ans=4000;
		do{
			int dist=s[0][v[0]];
			f(i,1,idx-1)dist+=s[v[i-1]][v[i]];
			ans=min(ans,dist);
		}while(next_permutation(v.begin(), v.end()));
		cout<<ans<<'\n';
	}
	return 0;
}

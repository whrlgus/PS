#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXN=1e4+1;
int n,m,p[MAXN],cnt;
vector<pair<int,int>> adj[MAXN];
bool vis[MAXN];

int dfs(int a){
	if(p[a]!=-1)return p[a];
	for(auto &ele:adj[a])
		p[a]=max(p[a],dfs(ele.first)+ele.second);
	return p[a];
}

void count(int a,int c){
	if(vis[a])return;
	vis[a]=true;
	for(auto &ele:adj[a])if(c==p[ele.first]+ele.second){
		++cnt;
		count(ele.first,c-ele.second);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		adj[b].push_back({a,c});
	}
	int s,e;cin>>s>>e;
	
	memset(p,-1,sizeof(p));
	p[s]=0;
	cout<<dfs(e)<<'\n';
	count(e,p[e]);
	cout<<cnt;
	return 0;
}

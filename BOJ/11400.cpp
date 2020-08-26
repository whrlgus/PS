#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

const int MAXV=100001;
int v,e,tin[MAXV],low[MAXV],cnt;
bool vis[MAXV];
vector<int> edge[MAXV];

set<pair<int,int>> bridges;

void dfs(int v, int p){
	tin[v]=low[v]=++cnt;
	vis[v]=true;
	
	for(int to:edge[v])if(to!=p){
		if(vis[to])low[v]=min(low[v],tin[to]);
		else{
			dfs(to,v);
			low[v]=min(low[v],low[to]);
			if(tin[v]<low[to])v<to?bridges.insert({v,to}):bridges.insert({to,v});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>v>>e;
	while(e--){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	dfs(1,0);
	cout<<bridges.size()<<'\n';
	for(auto &bridge:bridges)cout<<bridge.first<<' '<<bridge.second<<'\n';
	return 0;
}

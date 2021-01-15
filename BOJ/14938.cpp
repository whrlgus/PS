#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MXN=101,INF=1500;
int n,m,r,t[MXN],d[MXN];
vector<pair<int,int>> edge[MXN];
bool vis[MXN];

int sol(int start){
	f(i,1,n)d[i]=INF,vis[i]=false;
	
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	d[start]=0;
	int tmp=0;
	while(!pq.empty()){
		int u=pq.top().second,dist=-pq.top().first;pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		if(++tmp==n)break;
		for(auto &ele:edge[u]){
			int v=ele.first,nd=dist+ele.second;
			if(d[v]>nd){
				d[v]=nd;
				pq.push({-nd,v});
			}
		}
	}
	
	int cnt=0;
	f(i,1,n)if(d[i]<=m)cnt+=t[i];
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>r;
	f(i,1,n)cin>>t[i];
	f(i,1,r){
		int a,b,l;cin>>a>>b>>l;
		edge[a].push_back({b,l});
		edge[b].push_back({a,l});
	}
	
	int ans=0;
	f(i,1,n)ans=max(ans,sol(i));
	cout<<ans;
	return 0;
}

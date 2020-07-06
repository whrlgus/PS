#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int INF=8e5;
struct info{
	int u,w;
	bool operator<(const info& oth)const{
		return w>oth.w;
	}
};
vector<info> edge[801];
int n,e,a[3],s[3][801];
bool vis[801];

void dijkstra(int idx){
	f(i,1,n)s[idx][i]=INF,vis[i]=false;
	s[idx][a[idx]]=0;
	priority_queue<info> pq;
	pq.push({a[idx],0});
	while(!pq.empty()){
		int u=pq.top().u;pq.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(auto &ref:edge[u]){
			int v=ref.u,w=ref.w,dist=s[idx][u]+w;
			if(!vis[v]&&s[idx][v]>dist){
				s[idx][v]=dist;
				pq.push({v,dist});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>e;
	while(e--){
		int u,v,w;cin>>u>>v>>w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	a[0]=1;
	cin>>a[1]>>a[2];
	
	f(i,0,2)dijkstra(i);
	if(s[0][a[1]]==INF||s[1][a[2]]==INF||s[2][n]==INF)cout<<-1;
	else cout<<s[1][a[2]]+min(s[0][a[1]]+s[2][n],s[0][a[2]]+s[1][n]);
	
	return 0;
}

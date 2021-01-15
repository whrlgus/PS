#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MXN=2001,INF=2e6;
int n,m,t,s,g,h,cand[101],dist[MXN],p[MXN],dst;
bool vis[MXN];
vector<pair<int,int>> edge[MXN];


void setMinDist(){
	priority_queue<pair<int,int>> pq;
	pq.push({0,s});
	dist[s]=0;
	int cnt=0;
	while(!pq.empty()){
		int u=pq.top().second,d=-pq.top().first;pq.pop();
		if(vis[u])continue;
		
		vis[u]=true;
		if(++cnt==n)return;
		
		for(auto &ele:edge[u])if(!vis[ele.first]){
			int v=ele.first,nd=d+ele.second;
			if(dist[v]>nd){
				dist[v]=nd;
				pq.push({-nd,v});
			}
		}
	}
}

void visit(int u,int pass){
	if(p[u]!=-1&&p[u]>=pass)return;
	p[u]=pass;
	for(auto &ele:edge[u]){
		int v=ele.first;
		if(dist[v]!=dist[u]+ele.second)continue;
		visit(v,pass|((u==g||u==h)&&(v==g||v==h)));
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>t>>s>>g>>h;
		f(i,1,n)edge[i].clear(),dist[i]=INF,vis[i]=false,p[i]=-1;
		while(m--){
			int a,b,d;cin>>a>>b>>d;
			edge[a].push_back({b,d});
			edge[b].push_back({a,d});
		}
		f(i,1,t)cin>>cand[i];
		
		setMinDist();
		visit(s,0);
		
		sort(cand+1,cand+t+1);
		f(i,1,t)if(p[cand[i]]==1)cout<<cand[i]<<' ';
		cout<<'\n';
	}
	return 0;
}

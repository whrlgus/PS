#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,d[1001],p[1001];
vector<pair<int,int>> adj[1001];
bool vis[1001];

void dijk(){
	f(i,1,n)d[i]=1e7;
	priority_queue<pair<int,int>> pq;
	pq.push({0,2});
	d[2]=0;
	while(!pq.empty()){
		auto tmp=pq.top();pq.pop();
		
		if(vis[tmp.second])continue;
		vis[tmp.second]=true;
		
		for(auto &ele:adj[tmp.second]){
			int nd=ele.first-tmp.first;
			if(d[ele.second]>nd){
				pq.push({-nd,ele.second});
				d[ele.second]=nd;
			}
		}
	}
}

int sol(int u){
	int &ref=p[u];
	if(p[u]>-1)return ref;
	ref=0;
	for(auto &ele:adj[u])if(d[u]>d[ele.second])ref+=sol(ele.second);
	return ref;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	f(i,1,m){
		int a,b,c;cin>>a>>b>>c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	
	dijk();
	
	memset(p,-1,sizeof(p));
	p[2]=1;
	cout<<sol(1);
	
	return 0;
}

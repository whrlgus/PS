#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

int n,m,a,b,mnDist,d[1001],prior[1001];
vector<pair<int,int>> edge[1001];

struct comp{
	bool operator()(const int a, const int b){
		return d[a]>d[b];
	}
};

void dijk(){
	f(i,1,n)d[i]=1e8;
	d[a]=0;
	priority_queue<int,vector<int>,comp> q;
	q.push(a);
	while(!q.empty()){
		int u=q.top();q.pop();
		if(u==b)return;
		for(auto &tmp:edge[u]){
			int nd=tmp.second+d[u];
			if(d[tmp.first]>nd){
				d[tmp.first]=nd;
				q.push(tmp.first);
				prior[tmp.first]=u;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		int u,v,w;cin>>u>>v>>w;
		edge[u].push_back({v,w});
	}
	cin>>a>>b;
	dijk();
	cout<<d[b]<<'\n';
	vector<int> path;
	while(b!=a){
		path.push_back(b);
		b=prior[b];
	}
	path.push_back(a);
	reverse(path.begin(),path.end());
	cout<<path.size()<<'\n';
	for(int tmp:path)cout<<tmp<<' ';
	
	return 0;
}

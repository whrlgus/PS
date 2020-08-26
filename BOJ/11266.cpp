#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MAXN=10001;
int v,e,cnt,tin[MAXN],low[MAXN];
bool vis[MAXN];
vector<int> edge[MAXN];
set<int> ap;

void sol(int a, int p){
	tin[a]=low[a]=++cnt;
	vis[a]=true;
	int children=0;
	for(int b:edge[a])if(b!=p){
		if(vis[b])low[a]=min(low[a],tin[b]);
		else{
			sol(b,a);
			low[a]=min(low[a],low[b]);
			if(low[b]>=tin[a]&&p!=-1)ap.insert(a);
			++children;
		}
	}
	if(p==-1&&children>1)ap.insert(a);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>v>>e;
	while(e--){
		int a,b;cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	f(i,1,v)if(!vis[i])sol(i,-1);
	cout<<ap.size()<<'\n';
	for(int a:ap)cout<<a<<' ';
	
	return 0;
}

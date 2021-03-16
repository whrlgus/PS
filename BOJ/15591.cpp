#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<r;++i)
using namespace std;

typedef pair<int,int> pii;
int N,Q,K;
bool vis[5001];
vector<pii> edge[5001];

int sol(int v,int k){
	vis[v]=true;
	int ret=1;
	for(auto &ele:edge[v])if(!vis[ele.first]){
		int mn=min(k,ele.second);
		if(mn>=K)ret+=sol(ele.first,mn);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N>>Q;
	f(i,1,N){
		int p,q,r;cin>>p>>q>>r;
		edge[p].push_back({q,r});
		edge[q].push_back({p,r});
	}
	
	while(Q--){
		int v;cin>>K>>v;
		memset(vis,false,sizeof(vis));
		cout<<sol(v,1e9)-1<<'\n';
	}
	return 0;
}


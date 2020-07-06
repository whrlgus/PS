#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
const int MAXN=1e5+1;
int n,r,q,u,v,s[MAXN];
vector<int> edge[MAXN];
bool vis[MAXN];

int sol(int i){
	vis[i]=true;
	for(int j:edge[i])if(!vis[j])s[i]+=sol(j);
	return s[i]+=1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>r>>q;
	f(i,2,n){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	sol(r);
	while(q--){
		cin>>u;
		cout<<s[u]<<'\n';
	}
	return 0;
}

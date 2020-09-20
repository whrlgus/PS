#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
using namespace std;

const int MX=1e5+1;
int n,m,ans[MX],p[MX];
bool vis[MX]={true};

int foo(int u){
	if(vis[u])return ans[u];
	vis[u]=true;
	return ans[u]+=foo(p[u]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f(i,1,n)cin>>p[i];
	while(m--){
		int i,w;cin>>i>>w;
		ans[i]+=w;
	}
	
	f(i,1,n)cout<<foo(i)<<' ';
	return 0;
}
